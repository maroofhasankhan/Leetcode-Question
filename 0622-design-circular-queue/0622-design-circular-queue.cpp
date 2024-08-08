class Node{
public:

    int val;
    Node* next;

    Node(int val){
        this->val=val;

    }  
    Node(int val,Node* next) {
        this->val=val;
        this->next=next;
    } 
};
class MyCircularQueue {
public:
    Node *head=nullptr,*tail=nullptr;
    int size=0, k;
    MyCircularQueue(int k) {
       this->k=k;
    }
    
    bool enQueue(int value) {
        if(size==k)return false;
        size++;
        if(head==nullptr){
        Node* node= new Node(value);
            head=node;
            node->next=head;
            tail=head;
        }
        else{
            tail->next=new Node(value,head);
            tail=tail->next;
        }
        return true;
    }
    
    bool deQueue() {
        if(head==nullptr){
            return false;
        }
        else if(head==tail){
            delete head;
            head=tail=nullptr;
        }
        else{
            Node* temp=head->next;
            delete head;
            head=tail->next=temp;
        }
        size--;
        return true;
    }
    
    int Front() {
        if(!head)return -1;
        return head->val;
    }
    
    int Rear() {
        if(!head)return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(!head){return true;}
        return false;
    }
    
    bool isFull() {
        if(size==k){return true;}
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */