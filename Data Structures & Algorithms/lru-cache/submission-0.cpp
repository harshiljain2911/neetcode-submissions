class LRUCache {
public:

    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->val = value;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    int capacity;

    // Add node immediately after head
    // Node becomes MRU
    void addToFront(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove any node from DLL
    void removeNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Move existing node to MRU position
    void moveToFront(Node* node) {

        removeNode(node);
        addToFront(node);
    }

    // Remove LRU node
    Node* removeLRU() {

        Node* node = tail->prev;

        removeNode(node);

        return node;
    }

    LRUCache(int capacity) {

        this->capacity = capacity;

        // Dummy head and tail
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Recently used → move to MRU
        moveToFront(node);

        return node->val;
    }

    void put(int key, int value) {

        // Case 1: key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->val = value;

            // This key was just used → make it MRU
            moveToFront(node);

            return;
        }

        // Case 2: new key
        Node* node = new Node(key, value);

        addToFront(node);
        mp[key] = node;

        // Capacity exceeded
        if (mp.size() > capacity) {

            Node* lru = removeLRU();

            mp.erase(lru->key);

            delete lru;
        }
    }
};