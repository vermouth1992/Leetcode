#include<unordered_map>
#include<iostream>

class Node {
public:
    Node * prev;
    Node * next;
    int key;
    int value;

    Node(Node *prev, Node *next, int key, int value): prev(prev), next(next), key(key), value(value) {}
    Node(int key, int value): Node(nullptr, nullptr, key, value) {}
    Node(): Node(nullptr, nullptr, -1, -1) {}
};


class LRUCache {
private:
    Node *sentinal_front;  // most recently used node
    Node *sentinal_back;   // least recently used node
    std::unordered_map<int, Node*> keyValue;
    int capacity;

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node *node) {
        node->prev = sentinal_front;
        node->next = sentinal_front->next;
        sentinal_front->next = node;
        node->next->prev = node;
    }

    void moveToFront(Node *node) {
        removeNode(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity) {
        this->sentinal_front = new Node();
        this->sentinal_back = new Node();
        this->sentinal_front->next = this->sentinal_back;
        this->sentinal_back->prev = this->sentinal_front;
        this->capacity = capacity;
    }

    ~LRUCache() {
        Node *node = this->sentinal_front;
        while (node != nullptr)
        {
            Node *nextNode = node->next;
            delete node;
            node = nextNode;
        }
    }
    
    int get(int key) {
        auto it = keyValue.find(key);
        if (it == keyValue.end()) {
            return -1;
        } else {
            Node *node = it->second;
            moveToFront(node);
            return node->value;
        }
    }

    void printList() {
        Node *node = this->sentinal_front->next;
        while (node != this->sentinal_back)
        {
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
    
    void put(int key, int value) {
        auto it = keyValue.find(key);
        if (it == keyValue.end()) {
            // if reaches capacity, remove the LRU node
            if (keyValue.size() == this->capacity) {
                Node *node = sentinal_back->prev;
                removeNode(node);
                keyValue.erase(node->key);
                delete node;
            }

            // create a node, add to the map and list front
            Node *node = new Node(key, value);
            addToFront(node);
            keyValue[key] = node;
            
        } else {
            // set the value and move the node to the front
            Node *node = it->second;
            node->value = value;
            moveToFront(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache obj = LRUCache(2);
    obj.put(1, 1);
    obj.put(2, 2);
    obj.printList();
    std::cout << obj.get(1) << std::endl;
    obj.printList();
    obj.put(3, 3);
    obj.printList();
    std::cout << obj.get(2) << std::endl;
    obj.printList();
    obj.put(4, 4);
    obj.printList();
    std::cout << obj.get(1) << std::endl;
    obj.printList();
    std::cout << obj.get(3) << std::endl;
    obj.printList();
    std::cout << obj.get(4) << std::endl;
    obj.printList();

}