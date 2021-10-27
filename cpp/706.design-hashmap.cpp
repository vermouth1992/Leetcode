/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 *
 * https://leetcode.com/problems/design-hashmap/description/
 *
 * algorithms
 * Easy (63.97%)
 * Total Accepted:    229K
 * Total Submissions: 359K
 * Testcase Example:  '["MyHashMap","put","put","get","get","put","get","remove","get"]\n' +
  '[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]'
 *
 * Design a HashMap without using any built-in hash table libraries.
 * 
 * Implement the MyHashMap class:
 * 
 * 
 * MyHashMap() initializes the object with an empty map.
 * void put(int key, int value) inserts a (key, value) pair into the HashMap.
 * If the key already exists in the map, update the corresponding value.
 * int get(int key) returns the value to which the specified key is mapped, or
 * -1 if this map contains no mapping for the key.
 * void remove(key) removes the key and its corresponding value if the map
 * contains the mapping for the key.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
 * [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
 * Output
 * [null, null, null, 1, -1, null, 1, null, -1]
 * 
 * Explanation
 * MyHashMap myHashMap = new MyHashMap();
 * myHashMap.put(1, 1); // The map is now [[1,1]]
 * myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
 * myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
 * myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1],
 * [2,2]]
 * myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the
 * existing value)
 * myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
 * myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
 * myHashMap.get(2);    // return -1 (i.e., not found), The map is now
 * [[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= key, value <= 10^6
 * At most 10^4 calls will be made to put, get, and remove.
 * 
 * 
 */

#include "common.hpp"

class MyHashMap {
public:
    MyHashMap() {
        // create an array of pointers
        m_storage = new Node*[initial_capacity];
        m_capacity = initial_capacity;
        m_size = 0;
        // create a sentinel node for each bucket
        for (int i = 0; i < initial_capacity; i++) {
            m_storage[i] = new Node();
        }
    }
    
    void put(int key, int value) {
        // assume the hashcode of int is simply itself.
        int index = key % this->capacity();
        // the first one can't be null
        Node *curr = m_storage[index];
        // it is necessary to traverse the list to check duplicate
        while (curr->next != nullptr)
        {
            curr = curr->next;
            // the (key, value) pair already exists!
            if (curr->key == key) {
                curr->val = value;
                return;
            }
        }
        Node *new_node = new Node(key, value);
        // insert the new node
        curr->next = new_node;
        m_size += 1;

        // potential resize
        if (this->size() > this->capacity() * load_factor) {
            this->resize();
        }
    }
    
    int get(int key) {
        int index = key % this->capacity();
        // the first one can't be null
        Node *curr = m_storage[index];
        while (curr->next != nullptr)
        {
            curr = curr->next;
            // the (key, value) pair already exists!
            if (curr->key == key) return curr->val;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % this->capacity();
        // the first one can't be null
        Node *curr = m_storage[index];
        Node * prev;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
            // the (key, value) pair exists!
            if (curr->key == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        }
    }

private:

    void resize() {
        size_t new_capacity = m_capacity * expand_factor;
        Node **temp_storage = new Node*[new_capacity];
        for (int i = 0; i < new_capacity; i++) {
            temp_storage[i] = new Node();
        }

        for (int i = 0; i < m_capacity; i++) {
            Node *old_sentinel = m_storage[i];
            while (old_sentinel->next != nullptr) {
                Node *temp = old_sentinel->next;
                // step 1: remove temp from the old list
                old_sentinel->next = temp->next;
                // step 2: insert temp into the new list. No need to renew
                int new_index = temp->key % new_capacity;
                Node *new_sentinel = temp_storage[new_index];
                temp->next = new_sentinel->next;
                new_sentinel->next = temp;
            }
            delete old_sentinel;
        }
        // delete the old storage
        delete[] m_storage;

        m_storage = temp_storage;
        m_capacity = new_capacity;
    }

    size_t size() const {
        return m_size;
    }

    size_t capacity() const {
        return m_capacity;
    }

    struct Node {
        int key;
        int val;
        Node *next;
        Node() : Node(0, 0) {}
        Node(int key, int val): key(key), val(val), next(nullptr) {}
    };

    const double load_factor = 0.75;
    const size_t initial_capacity = 16;
    const double expand_factor = 1.5;

    Node **m_storage;
    size_t m_size;
    size_t m_capacity;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
