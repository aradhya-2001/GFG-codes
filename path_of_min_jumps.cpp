#include <bits/stdc++.h>
using namespace std;

vector<int> jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0x3f3f3f3f);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int reach = i + nums[i];
        int ans = dp[i];
        for (int jump = i + 1; jump <= reach && jump < n; jump++)
        {
            int next = dp[jump];
            ans = min(ans, next + 1);
            dp[i] = ans;
        }
    }
    return dp;
}

class PathData
{
public:
    int i;
    int totalJumps; // nums[i]
    int minJump;    // this will be dp[i] that is min jump from i to n-1

    PathData(int i, int tj, int mj)
    {
        this->i = i;
        totalJumps = tj;
        minJump = mj;
    }
};

string pathPrint(vector<int> &nums, vector<int> &dp) // bfs
{
    int n = dp.size();
    PathData obj0(0, nums[0], dp[0]);
    string ans = "0";
    queue<PathData> q;
    q.push(obj0);

    while (!q.empty())
    {
        PathData node = q.front();
        q.pop();
        int reach = node.i + node.totalJumps;
        int cnt = 0;
        for (int i = node.i + 1; i < n && i <= reach; i++)
        {

            if (dp[i] == node.minJump - 1) // from i, jumps require to reach end (n-1) is dp[i]. But dp[i] = next+1 (from jump function). So we are finding next i.e. the index (number) who has min distance from n-1. Ex in decision tree next of i=0 is i=1 not i=2.
            {
                cnt++;
                if (cnt > 1)
                {

                }
               
                ans += to_string(i);
                PathData obj(i, nums[i], dp[i]);
                q.push(obj);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
    vector<int> dp = jump(nums);
    string path = pathPrint(nums, dp);
    // cout << ans;
    // for(int x: ans) cout<<x<<" ";
   
}