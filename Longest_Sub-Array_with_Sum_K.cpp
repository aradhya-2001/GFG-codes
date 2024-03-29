#include<bits/stdc++.h>
using namespace std;

    // below algo is like leet 713 (Subarray Product Less Than K) - sliding window. This sol is more faster but would work only if the input array had only non -ve nos i.e. 0's or +vs's. 
    // int lenOfLongSubarr(int nums[],  int n, int k) 
    // {
    //     int l = 0, r = 0;
    //     int sum = 0, maxLen = 0  ;
    //     while(r < n)
    //     {
    //         sum += nums[r];
    //         while(l <= r && sum > k) 
    //         {
    //             sum -= nums[l]
    //             l++;
    //         } 
    //         if(sum == k) 
    //         {
    //             int len = r - l + 1;
    //             maxLen = max(maxLen, len);
    //         } 
    //         r++;
    //      }
    //      return maxLen;
    //  }
    // below is slower than above one but works for all nos i.e. +ve, -ve and 0.
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        int sum = 0;
        unordered_map<int, int>mp;
        //mp[0] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
        //     if(mp.count(sum)) continue;  
        //     earlier i was doing above instead of last if. The probelm here is: 
        //     |-------|------|---------------------------------------|----------|
        //     |       <------>                                                  |                               
        //     |       <---------------------------------------------->          |
        //  arr[0]  sum-k    sum                                     sum       arr[n]
         
        //  here sum is found in arr 2 times. Length of subarr btw the 1st sum and sum-k is smaller than the 2nd time. According to our logic when we encountered sum 1st time we will put in map and note the len but when 2nd sum is encountered we are not noting down the len btw sum and sum-k (which is longer than the 1st one) and simply skipping it.   
            
            
            if(sum == k)             // could have ignored this if written mp[0] = -1. Then below if worked for both cases. 
            {
                int len = i + 1;
                ans = max(ans, len);
            }
            
            if(mp.count(sum - k)) 
            {
                // cout<<i<<endl;
                int len = i - mp[sum - k];
                ans = max(ans, len);
            }
            
            if(mp.count(sum) == 0) // [2,0,0,3] ,k=3 (striver vid)
            mp[sum] = i;
        }
        return ans;
    } 

};