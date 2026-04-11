#include <atomic>
#include <utility>
#include <memory>


template<typename T>
class QueueScheduler {

    std::atomic<unsigned> writeIndex;
    std::atomic<unsigned> readIndex;
    std::unique_ptr<std::pair<unsigned, T>> elements;

    bool try_push(T&& value) {
        auto my_entry = writeIndex.fetch_add(1);
        elements[my_entry].first = std::move(value);
        // No code, does not mean no-time.
        // scheduler will hit here, and
        // block the queue progress.
        elements[my_entry].second = my_entry ;
        return true;
    }

    bool try_pop(T& value) {
        auto my_entry = readIndex.fetch_add(1);
        while (elements[my_entry].second != my_entry); // spin and wait, maybe with pause();
        value = std::move(elements[my_entry].first);
        return true;
    }
};