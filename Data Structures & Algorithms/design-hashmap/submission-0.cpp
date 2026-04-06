class MyHashMap {
private:
    struct ListNode {
        int key, val;
        ListNode* next;

        ListNode(int key = -1, int val = -1)
            : key(key), val(val), next(nullptr) {}
    };

    // Vector where each index represents a bucket
    vector<ListNode*> map;

    // Our hash function 
    int hash(int key) {
        return key % map.size();
    }

public:
    MyHashMap() {
        map.resize(1000);
        for (auto& bucket : map) {
            bucket = new ListNode(0);
        }
    }

    void put(int key, int value) {
        ListNode* cur = map[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }
            // Move to the next node in the linked list
            cur = cur->next;
        }
        cur->next = new ListNode(key, value);
    }

    int get(int key) {
        ListNode* cur = map[hash(key)]->next;
        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }
            // Move to the next node in the linked list
            cur = cur->next;
        }
        return -1;
    }

    void remove(int key) {
        ListNode* cur = map[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                return;
            }
            // Move to the next node in the linked list
            cur = cur->next;
        }
    }
};