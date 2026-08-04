class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 0;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int num : nums)
        {
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size() < size)
            pq.push(val);
        else if(val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};
