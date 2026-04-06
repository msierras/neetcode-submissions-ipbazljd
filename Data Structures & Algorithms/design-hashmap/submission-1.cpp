class MyHashMap {
private:
    struct ListNode {
        int key, val;      // key-value pair stored in each node
        ListNode* next;    // pointer to next node in the linked list

        // Constructor (also used for dummy nodes)
        ListNode(int key = -1, int val = -1)
            : key(key), val(val), next(nullptr) {}
    };

    // Vector where each index is a bucket (each bucket is a linked list)
    vector<ListNode*> map;

    // Hash function: maps a key to a bucket index
    int hash(int key) {
        return key % map.size();
    }

public:
    MyHashMap() {
        // Create 1000 buckets
        map.resize(1000);

        // Initialize each bucket with a dummy head node
        // Dummy nodes simplify insertion and deletion (no special head cases)
        for (auto& bucket : map) {
            bucket = new ListNode(0);
        }
    }

    void put(int key, int value) {
        // Start at the dummy node of the correct bucket
        ListNode* cur = map[hash(key)];

        // Traverse the linked list
        while (cur->next) {
            // Check if the key already exists in the NEXT node
            if (cur->next->key == key) {
                // If found, update the value
                cur->next->val = value;
                return;
            }
            // Move forward in the list
            cur = cur->next;
        }

        // If key was not found, insert a new node at the end
        // We use cur->next because cur is the previous node
        cur->next = new ListNode(key, value);
    }

    int get(int key) {
        // Start at the first REAL node (skip dummy node)
        ListNode* cur = map[hash(key)]->next;

        // Traverse the linked list
        while (cur) {
            // If key is found, return its value
            if (cur->key == key) {
                return cur->val;
            }
            // Move to next node
            cur = cur->next;
        }

        // If key does not exist in the map
        return -1;
    }

    void remove(int key) {
        // Start at the dummy node so we can modify links safely
        ListNode* cur = map[hash(key)];

        // Traverse the linked list
        while (cur->next) {
            // Look ahead to check if the NEXT node is the one to delete
            if (cur->next->key == key) {
                // Store node to delete
                ListNode* tmp = cur->next;

                // Skip the node (unlink it from the list)
                cur->next = cur->next->next;

                // Free memory
                delete tmp;
                return;
            }
            // Move forward in the list
            cur = cur->next;
        }
    }
};