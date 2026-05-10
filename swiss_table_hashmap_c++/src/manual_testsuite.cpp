#include <cassert>
#include <iostream>
#include <string>
#include <type_traits>

// Test Suite generated with Deepseek Expert

template<typename HashMapType = open_addressing_hash_map<std::string, int>>
void run_tests() {
    std::cout << "Running tests..." << std::endl;
    
    // Test 1: Basic insertion and size
    {
        HashMapType map;
        assert(map.size() == 0);
        assert(map.insert("key1", 100) == true);
        assert(map.size() == 1);
        assert(map.insert("key2", 200) == true);
        assert(map.size() == 2);
        std::cout << "Test 1 passed: Basic insertion and size" << std::endl;
    }
    
    // Test 2: Insert duplicate key
    {
        HashMapType map;
        map.insert("key1", 100);
        assert(map.insert("key1", 999) == false);  // Should fail for duplicate
        assert(map.size() == 1);
        int* val = map.get("key1");
        assert(val != nullptr);
        assert(*val == 100);  // Original value should remain
        std::cout << "Test 2 passed: Duplicate key insertion" << std::endl;
    }
    
    // Test 3: Get existing and non-existing keys
    {
        HashMapType map;
        map.insert("key1", 100);
        map.insert("key2", 200);
        
        int* val1 = map.get("key1");
        assert(val1 != nullptr);
        assert(*val1 == 100);
        
        int* val2 = map.get("key2");
        assert(val2 != nullptr);
        assert(*val2 == 200);
        
        int* val3 = map.get("nonexistent");
        assert(val3 == nullptr);
        
        std::cout << "Test 3 passed: Get operations" << std::endl;
    }
    
    // Test 4: Remove existing key
    {
        HashMapType map;
        map.insert("key1", 100);
        map.insert("key2", 200);
        assert(map.size() == 2);
        
        map.remove("key1");
        assert(map.size() == 1);
        assert(map.get("key1") == nullptr);
        assert(map.get("key2") != nullptr);
        
        std::cout << "Test 4 passed: Remove existing key" << std::endl;
    }
    
    // Test 5: Remove non-existing key
    {
        HashMapType map;
        map.insert("key1", 100);
        map.remove("nonexistent");  // Should not crash
        assert(map.size() == 1);
        assert(map.get("key1") != nullptr);
        
        std::cout << "Test 5 passed: Remove non-existing key" << std::endl;
    }
    
    // Test 6: Clear map
    {
        HashMapType map;
        map.insert("key1", 100);
        map.insert("key2", 200);
        map.insert("key3", 300);
        assert(map.size() == 3);
        
        bool result = map.clear();
        assert(result == true);
        assert(map.size() == 0);
        assert(map.get("key1") == nullptr);
        assert(map.get("key2") == nullptr);
        assert(map.get("key3") == nullptr);
        
        std::cout << "Test 6 passed: Clear map" << std::endl;
    }
    
    // Test 7: Insert after clear
    {
        HashMapType map;
        map.insert("key1", 100);
        map.clear();
        
        assert(map.insert("key1", 200) == true);  // Should work after clear
        assert(map.size() == 1);
        int* val = map.get("key1");
        assert(val != nullptr);
        assert(*val == 200);
        
        std::cout << "Test 7 passed: Insert after clear" << std::endl;
    }
    
    // Test 8: Resize to larger capacity
    {
        HashMapType map;
        for (int i = 0; i < 10; i++) {
            assert(map.insert(std::to_string(i), i) == true);
        }
        assert(map.size() == 10);
        
        bool result = map.resize(20);
        assert(result == true);
        assert(map.size() == 10);  // Size should remain same
        
        // Verify all elements still accessible
        for (int i = 0; i < 10; i++) {
            int* val = map.get(std::to_string(i));
            assert(val != nullptr);
            assert(*val == i);
        }
        
        std::cout << "Test 8 passed: Resize to larger capacity" << std::endl;
    }
    
    // Test 9: Resize to smaller capacity
    {
        HashMapType map;
        map.insert("key1", 100);
        map.insert("key2", 200);
        
        bool result = map.resize(1);  // Smaller than number of elements
        assert(result == false);  // Should fail
        assert(map.size() == 2);  // Size should remain unchanged
        
        std::cout << "Test 9 passed: Resize to smaller capacity fails" << std::endl;
    }
    
    // Test 10: Resize to same capacity
    {
        HashMapType map;
        map.insert("key1", 100);
        map.insert("key2", 200);
        
        bool result = map.resize(16);  // Assuming default capacity
        assert(result == true);  // Should succeed
        assert(map.size() == 2);
        
        std::cout << "Test 10 passed: Resize to valid capacity" << std::endl;
    }
    
    // Test 11: Multiple removes and reinserts
    {
        HashMapType map;
        map.insert("a", 1);
        map.insert("b", 2);
        map.insert("c", 3);
        
        map.remove("b");
        map.insert("b", 22);  // Reinsert with new value
        assert(map.size() == 3);
        
        int* val = map.get("b");
        assert(val != nullptr);
        assert(*val == 22);
        
        std::cout << "Test 11 passed: Remove and reinsert" << std::endl;
    }
    
    // Test 12: Large number of insertions
    {
        HashMapType map;
        const int NUM_ITEMS = 1000;
        
        for (int i = 0; i < NUM_ITEMS; i++) {
            assert(map.insert(std::to_string(i), i * 10) == true);
        }
        assert(map.size() == NUM_ITEMS);
        
        // Verify random access
        for (int i = 0; i < NUM_ITEMS; i += 100) {
            int* val = map.get(std::to_string(i));
            assert(val != nullptr);
            assert(*val == i * 10);
        }
        
        std::cout << "Test 12 passed: Large number of insertions" << std::endl;
    }
    
    // Test 13: Edge case - empty string key
    {
        HashMapType map;
        assert(map.insert("", 42) == true);
        assert(map.size() == 1);
        
        int* val = map.get("");
        assert(val != nullptr);
        assert(*val == 42);
        
        map.remove("");
        assert(map.size() == 0);
        assert(map.get("") == nullptr);
        
        std::cout << "Test 13 passed: Empty string key" << std::endl;
    }
    
    // Test 14: Value update via pointer
    {
        HashMapType map;
        map.insert("key", 100);
        
        int* val = map.get("key");
        assert(val != nullptr);
        *val = 999;  // Modify value through pointer
        
        int* updated_val = map.get("key");
        assert(updated_val != nullptr);
        assert(*updated_val == 999);
        
        std::cout << "Test 14 passed: Value modification via pointer" << std::endl;
    }
    
    // Test 15: Remove from empty map
    {
        HashMapType map;
        assert(map.size() == 0);
        map.remove("nonexistent");  // Should not crash
        assert(map.size() == 0);
        
        std::cout << "Test 15 passed: Remove from empty map" << std::endl;
    }
    
    // Test 16: Resize empty map
    {
        HashMapType map;
        assert(map.size() == 0);
        assert(map.resize(32) == true);
        assert(map.size() == 0);
        assert(map.insert("key", 100) == true);
        assert(map.size() == 1);
        
        std::cout << "Test 16 passed: Resize empty map" << std::endl;
    }
    
    // Test 17: Collision handling
    {
        HashMapType map;
        // Insert many items to force collisions
        for (int i = 0; i < 100; i++) {
            assert(map.insert("key" + std::to_string(i), i) == true);
        }
        
        // All should be retrievable
        for (int i = 0; i < 100; i++) {
            int* val = map.get("key" + std::to_string(i));
            assert(val != nullptr);
            assert(*val == i);
        }
        
        std::cout << "Test 17 passed: Collision handling" << std::endl;
    }
    
    // Test 18: Stress test with clear and resize
    {
        HashMapType map;
        
        // Fill the map
        for (int i = 0; i < 50; i++) {
            map.insert(std::to_string(i), i);
        }
        
        // Resize
        assert(map.resize(100) == true);
        assert(map.size() == 50);
        
        // Clear
        map.clear();
        assert(map.size() == 0);
        
        // Refill
        for (int i = 0; i < 50; i++) {
            map.insert(std::to_string(i), i * 2);
        }
        assert(map.size() == 50);
        
        // Verify new values
        for (int i = 0; i < 50; i++) {
            int* val = map.get(std::to_string(i));
            assert(val != nullptr);
            assert(*val == i * 2);
        }
        
        std::cout << "Test 18 passed: Stress test with clear and resize" << std::endl;
    }
    
    std::cout << "\nAll tests passed successfully!" << std::endl;
}
