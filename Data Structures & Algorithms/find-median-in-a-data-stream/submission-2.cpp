class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!min_heap.empty() && num > min_heap.top()){
            min_heap.push(num);
        }else{
            max_heap.push(num);
        }

        if(min_heap.size()+1 < max_heap.size()){
            int tmp = max_heap.top();
            max_heap.pop();
            min_heap.push(tmp);
        }

        if(min_heap.size() > max_heap.size()+1){
            int tmp = min_heap.top();
            min_heap.pop();
            max_heap.push(tmp);
        }
    }
    
    double findMedian() {
        if(min_heap.size() > max_heap.size()){
            return min_heap.top();
        }else if(min_heap.size() < max_heap.size()){
            return max_heap.top();
        }else if(min_heap.size() == max_heap.size()){
            double sum = max_heap.top()+min_heap.top();
            return sum/2;
        }
    }
};
