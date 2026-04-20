#include <functional>
#include <cstdint>


// Used the MurmurHash3 suggested by Gemini
template <typename K, typename Enable = void>
struct HftHash;

template <typename K>
struct HftHash<K, std::enable_if_t<std::is_integral_v<K>>> {
    std::size_t operator()(K key) const noexcept {
        size_t x = static_cast<uint64_t>(key);

        x ^= x >> 33;
        x *= 0xff51afd7ed558ccdULL;
        x ^= x >> 33;
        x *= 0xc4ceb9fe1a85ec53ULL;
        x ^= x >> 33;
        
        return static_cast<std::size_t>(x);
    }
};

template<typename K>
struct HftHash<K, std::enable_if_t<std::is_pointer_v<K>>> {
    std::size_t operator()(K key) const noexcept {
        size_t x = reinterpret_cast<uint64_t>(key);

        x = ( x >> 3 ) | ( x << 61) ;
        
        x ^= x >> 33;
        x *= 0xff51afd7ed558ccdULL;
        x ^= x >> 33;
        x *= 0xc4ceb9fe1a85ec53ULL;
        x ^= x >> 33;
        
        return static_cast<std::size_t>(x);
    }
}

template<typename K, typename V>
class open_addr_hash_map {
public:
    open_addr_hash_map() : open_addr_hash_map(_default_capacity) {}
    open_addr_hash_map(int capacity) : _backing_array(capacity) {}

    V get(K key, V default_value) {
        size_t slot = get_slot(key);
        
        for (auto it = _backing_array.begin() + slot; it != _backing_array.end(); it++) {
            if (it->state == entry_state::FILLED && it->key == key) {
                return it->value;
            }
        }

        return default_value;
    }


    void delete_key(K key) {

        size_t slot = get_slot(key);

        for (auto it = _backing_array.begin() + slot; it != _backing_array.end(); it++) {
            if ( it->state == entry_state::FILLED && it->key == key) {
                it->is_filled = entry_state::DELETED;
                break;
            }
        }
    }


    bool store(K key, V value) {

        size_t slot = get_slot(key);

        bool updated_value = false;
        add: for (auto it = _backing_array.begin() + slot; it != _backing_array.end(); it++) {
            if ( it->state == entry_state::FILLED && it->key == key) {
                it->value = value;
                updated_value = true;
            }
            
            if (it->state != entry_state::FILLED ) {
                *it = hash_map_entry{entry_state::FILLED, key, value};
                updated_value = true;
            }

            if (updated_value) break;
        }
        
        if (updated_value) return true;
        else {
            _backing_array.resize(_backing_array.capacity() * 1.5);
            goto add;
        }
        
        return false;
    }


private:
    static constexpr int _default_capacity = 1;

    enum entry_state {
        EMPTY,
        FILLED,
        DELETED
    };

    struct hash_map_entry {
         entry_state state;
         K key;
         V value;
    };
    
    HftHash<K> hasher;
    std::vector<hash_map_entry> _backing_array;

    size_t get_slot(K key) {
        return hasher(key) % _backing_array.capacity();
    }
};
