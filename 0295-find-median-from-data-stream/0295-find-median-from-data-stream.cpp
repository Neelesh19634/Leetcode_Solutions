class MedianFinder {
    private:
    priority_queue<int> maxa;
    priority_queue<int,vector<int>,greater<int>> mina;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxa.push(num);
        mina.push(maxa.top());
        maxa.pop();
        if(mina.size()>maxa.size()) maxa.push(mina.top()),mina.pop();

    }
    
    double findMedian() {
        if(maxa.size()==mina.size()) return (maxa.top()+mina.top())/2.0;

        return maxa.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */