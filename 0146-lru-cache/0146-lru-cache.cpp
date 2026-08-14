class LRUCache {
    public:
    
    class Node{
        public:
        int val,key;
        Node* prev;
        Node* next;

        Node(int key,int val):key(key),val(val),prev(NULL),next(NULL){}
    };

    
    
public:
int cap;
    unordered_map<int,Node*> mp;
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);

    void deleteNode(Node* node){
        Node* next=node->next;
        Node* prev=node->prev;
        prev->next=next;
        next->prev=prev;

        
    }

    void insertNode(Node* node){
        Node* next=head->next;
        head->next=node;
        node->prev=head;
        node->next=next;
        next->prev=node;
    };
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;

    }
    
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* node=mp[key];
        deleteNode(node);
        insertNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){
        Node* node=mp[key];
        deleteNode(node);
        node->val=value;
        insertNode(node);
        return;
       }

       if(mp.size()==cap){
        Node* node=tail->prev;
        int oldkey=node->key;
        deleteNode(node);
        mp.erase(oldkey);

        delete node;
       }

       Node* node =new Node(key,value);

       insertNode(node);
       mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */