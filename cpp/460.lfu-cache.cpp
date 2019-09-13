/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (29.94%)
 * Total Accepted:    46.6K
 * Total Submissions: 155.7K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 * 
 * Note that the number of times an item is used is the number of calls to the
 * get and put functions for that item since it was inserted. This number is
 * set to zero when the item is removed.
 * 
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * 
 * 
 * Example:
 * 
 * 
 * LFUCache cache = new LFUCache(2);
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.get(3);       // returns 3.
 * cache.put(4, 4);    // evicts key 1.
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */

/*
 * Use a list of list of Node to store value. Each level of list maintains a frequency level and the inner
 * list maintains LRU.
 * For get operation, if key is not in the map, return -1. Else, find the node, remove the node from current
 * inner list. Add to the next level inner list or create one. O(1).
 * For put operation, if key is in the map, do the same as get. Else, create a node in frequency 1 inner list.
 */

#include<unordered_map>

struct PivotNode;

struct Node {
    Node * prev;
    Node * next;
    int key;
    int value;
    PivotNode *pivotNode;

    Node(Node *prev, Node *next, int key, int value, PivotNode *pivotNode): 
                prev(prev), next(next), key(key), value(value), pivotNode(pivotNode) {}
    Node(int key, int value, PivotNode *pivotNode): Node(nullptr, nullptr, key, value, pivotNode) {}
    Node(PivotNode *pivotNode): Node(nullptr, nullptr, -1, -1, pivotNode) {}
};

struct PivotNode {
    PivotNode *next;
    PivotNode *prev;
    int frequency;
    Node *sentinal_front;
    Node *sentinal_back;

    PivotNode(int frequency) {
        this->frequency = frequency;
        this->sentinal_front = new Node(this);
        this->sentinal_back = new Node(this);
        this->sentinal_front->next = this->sentinal_back;
        this->sentinal_back->prev = this->sentinal_front;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~PivotNode() {
        
    }

    bool isEmpty() {
        return sentinal_front->next == sentinal_back;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node *node) {
        node->prev = sentinal_front;
        node->next = sentinal_front->next;
        sentinal_front->next = node;
        node->next->prev = node;
        node->pivotNode = this;
    }

    void insertAfter(PivotNode *pivotNode) {
        pivotNode->next = this->next;
        pivotNode->prev = this;
        pivotNode->next->prev = pivotNode;
        this->next = pivotNode;
    }

    Node* getBack() {
        return this->sentinal_back->prev;
    }
};




class LFUCache {
private:
    PivotNode *sentinal;
    PivotNode *back;
    std::unordered_map<int, Node*> keyValue;
    int capacity;

    void removePivotNode(PivotNode *pivotNode) {
        pivotNode->prev->next = pivotNode->next;
        pivotNode->next->prev = pivotNode->prev;
        delete pivotNode;
    }

    void moveToNextLevel(Node *node) {
        // move the node to the next level pivotNode
        PivotNode *pivotNode = node->pivotNode;
        pivotNode->removeNode(node);
        PivotNode *nextPivotNode = pivotNode->next;

        if (nextPivotNode->frequency != pivotNode->frequency + 1) {
            nextPivotNode = new PivotNode(pivotNode->frequency + 1);
            pivotNode->insertAfter(nextPivotNode);
        }

        nextPivotNode->addToFront(node);
        
        if (pivotNode->isEmpty()) {
            removePivotNode(pivotNode);
        }
    }

public:
    LFUCache(int capacity) {
        this->sentinal = new PivotNode(0);
        this->back = new PivotNode(-1);
        this->sentinal->next = this->back;
        this->back->prev = this->sentinal;
        this->capacity = capacity;
    }

    ~LFUCache() {

    }
    
    int get(int key) {
        auto it = keyValue.find(key);
        if (it == keyValue.end()) {
            return -1;
        } else {
            Node *node = it->second;
            moveToNextLevel(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        if (this->capacity <= 0) return;
        
        auto it = keyValue.find(key);
        if (it == keyValue.end()) {
            // if reaches capacity, remove the LRU node
            if (keyValue.size() == this->capacity) {
                // remove LFU node
                PivotNode *firstLevel = sentinal->next;
                Node *leastFrequentUsedNode = firstLevel->getBack();
                firstLevel->removeNode(leastFrequentUsedNode);
                keyValue.erase(leastFrequentUsedNode->key);
                delete leastFrequentUsedNode;
                if (firstLevel->isEmpty()) {
                    removePivotNode(firstLevel);
                }
            }

            // create a new node and put in the level 1 pivotNode
            Node *node = new Node(key, value, nullptr);
            if (sentinal->next->frequency != 1) {
                PivotNode *firstLevel = new PivotNode(1);
                firstLevel->addToFront(node);
                sentinal->insertAfter(firstLevel);
            } else {
                sentinal->next->addToFront(node);
            }
            keyValue[key] = node;
        } else {
            Node *node = it->second;
            node->value = value;
            moveToNextLevel(node);

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
