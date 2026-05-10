#include <cstdint>

template <typename K, typename Enable = void>
struct HftHash;

std::size_t bit_mix(uint64_t x) {
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= x >> 33;
    return static_cast<std::size_t>(x);
}

template <typename K>
struct HftHash<K, std::enable_if_t<std::is_integral_v<K>>> {
    std::size_t operator()(K key) const noexcept {
        size_t x = static_cast<uint64_t>(key);
        return bit_mix(x);
    }
};

template<typename K>
struct HftHash<K, std::enable_if_t<std::is_pointer_v<K>>> {
    std::size_t operator()(K key) const noexcept {
        size_t x = reinterpret_cast<uint64_t>(key);
        x = ( x >> 3 ) | ( x << 61) ;
        return bit_mix(x);
    }
};


template<typename K, typename V>
class hash_table {
public:
    V* get(K& key) {
        
    }

    void remove(K& key) {
        
    }

    bool insert(K& key, V& value) {
        return false;
    }

    int size() {
        
    }

    bool clear() {
        
    }

    bool resize(int new_capacity) {
        
//  std::vector<K> keys() const;
//  std::vector<V> values() const;

private:

};
