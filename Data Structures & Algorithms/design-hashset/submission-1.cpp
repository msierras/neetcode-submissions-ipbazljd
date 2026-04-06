class MyHashSet {
private:
    struct ListNode {
        int key;
        ListNode* next;
        ListNode(int k) : key(k), next(nullptr) {}
    };

    // Vector where each index represents a bucket
    // Each bucket is a linked list that stores keys that hash to that index
    vector<ListNode*> set;

    // Hash function maps a key to a bucket index using modulo
    int hash(int key) {
        return key % set.size();
    }

public:
    MyHashSet() {

        set.resize(10000);
        
        // Initialize each bucket with a dummy head node to simplify insertion and deletion
        for (auto& bucket : set) {
            bucket = new ListNode(0);
        }
    }

    void add(int key) {
        
        // cur points to the dummy head of the bucket corresponding to this key
        ListNode* cur = set[hash(key)];
        
        // While there is a next node
        while (cur->next) {
            // If the key already exists, return
            if (cur->next->key == key) {
                return;
            }
            // Move to the next node in the linked list
            cur = cur->next;
        }
        // Otherwise, append a new node with the key 
        cur->next = new ListNode(key);
    }

    void remove(int key) {
        // cur points to the dummy head of the bucket corresponding to this key
        ListNode* cur = set[hash(key)];
        
        // While there is a next node 
        while (cur->next) {
            // If the key exists 
            if (cur->next->key == key) {
                // Remove the node by skipping it in the linked list and freeing memory
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return;
            }
            // Move to the next node in the linked list
            cur = cur->next;
        }
    }

    bool contains(int key) {
        // cur points to the dummy head of the bucket corresponding to this key
        ListNode* cur = set[hash(key)];
        
        // While there is a next node 
        while (cur->next) {
            // If the key exists 
            if (cur->next->key == key) {
                return true;
            }
            // Move to the next node in the linked list
            cur = cur->next;
        }
        // If the node with the matching key is never found return false 
        return false;
    }
};