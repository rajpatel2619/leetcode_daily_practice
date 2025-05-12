class MyCircularQueue {
public:
    vector<int> arr;
    int cap;
    int f;
    int r;
    int s;
    MyCircularQueue(int k) {
        arr.resize(k);
        f = 0;
        s = 0;
        r = -1;
        cap = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        r = (r+1)%cap;
        arr[r] = value;
        s++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        f = (f+1)%cap;
        s--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[r];
    }
    
    bool isEmpty() {
        return s==0;
    }
    
    bool isFull() {
        return s==cap;
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