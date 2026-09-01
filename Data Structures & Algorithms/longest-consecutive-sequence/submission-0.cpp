class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x:nums)
        {
            s.insert(x);
        }
        int longest=0;
        for(int x:s)
        {
            if(s.count(x-1)==0)
            {
                int curr=x;
               int  length=1;
                while(s.count(curr+1))
                {
                    length++;
                    curr++;
                }
            
         longest=max(longest,length);
            }}
        return longest;
    }
};
