template<typename K, typename V>
class open_addr_hash_map {
public:
    open_addr_hash_map() : open_addr_hash_map(_default_capacity) {}
    open_addr_hash_map(int capacity) : _backing_array(capacity) {}

    V get(K key, V default_value) {
        size_t slot = get_slot(key);
        
        for (auto it = _backing_array.begin() + slot; it != _backing_array.end(); it++) {
            if (it->key == key) {
                return it->value;
            }
        }

        return default_value;
    }


    void delete_key(K key) {

        size_t slot = get_slot(key);

        for (auto it = _backing_array.begin() + slot; it != _backing_array.end(); it++) {
            if (it->key == key) {
                it->is_filled = false;
                break;
            }
        }
    }


    bool store(K key, V value) {

        size_t slot = get_slot(key);

        bool updated_value = false;
        add: for (auto it = _backing_array.begin() + slot; it != _backing_array.end(); it++) {
            if (it->key == key) {
                it->value = value;
                updated_value = true;
            }
            
            if (!(it->is_filled)) {
                *it = array_entry{true, key, value};
                updated_value = true;
            }

            if (updated_value) break;
        }
        
        if (updated_value) return true;
        else {
            _backing_array.resize(_backing_array.capacity() * 2);
            goto add;
        }
        
        return false;
    }


private:
    static constexpr int _default_capacity = 1;

    struct array_entry {
         bool is_filled;
         K key;
         V value;
    };
    
    std::hash<K> hasher;
    std::vector<array_entry> _backing_array;

    size_t get_slot(K key) {
        return hasher(key) % _backing_array.capacity();
    }
};
