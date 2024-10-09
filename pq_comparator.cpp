class comp{
    public:
    bool operator()(int a,int b){
        return a>b;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        
        priority_queue<int,vector<int>,comp> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
