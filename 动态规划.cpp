#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>>dp(s.length() + 1, vector<uint64_t>(t.length() + 1, 0));
        for (int i = 0; i <= s.length(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= t.length(); i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= t.length(); j++) {
                if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.length()][t.length()];
    }
};
//class Solution {
//public:
//    bool isSubsequence(string s, string t) {
//        if (s.length() > t.length())return false;
//        vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1, 0));
//        int res = 0;
//        for (int i = 1; i <= s.length(); i++)
//        {
//            for (int j = 1; j <= t.length(); j++) {
//                if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
//                else dp[i][j] = dp[i][j - 1];
//                res = max(res, dp[i][j]);
//            }
//        }
//        return res == s.length();
//    }
//};
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        vector<int>dp(nums.size() + 1, 0);
//        dp[0] = nums[0];
//        int res = dp[0];
//        for (int i = 1; i < nums.size(); i++) {
//            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//            res = max(res, dp[i]);
//        }
//        return res;
//    }
//};
//class Solution {
//public:
//    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//        vector<vector<int>>dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
//        int res = 0;
//        for (int i = 1; i <= nums1.size(); i++) {
//            for (int j = 1; j <= nums2.size(); j++) {
//                if (nums1[i - 1] == nums2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
//                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                res = max(res, dp[i][j]);
//            }
//        }
//        return res;
//    }
//};