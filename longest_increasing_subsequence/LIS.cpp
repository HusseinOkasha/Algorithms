
// problem link: https://leetcode.com/problems/longest-increasing-subsequence/
// problem solution video : https://www.youtube.com/watch?v=mouCn3CFpgg&t=1227s

#include <bits/stdc++.h>
using namespace std;


// this is a DP solution with time complexity O(n^2) and space complexity O(N)
int lengthOfLIS(vector<int>& nums) {
    vector<int>lis(nums.size(),1);
    int max=0;
    for (int i=1; i<nums.size();i++){
        for (int j=0; j<i ;j++){
            if (nums[j] < nums[i] && lis[i]<=lis[j]){
                lis[i]=lis[j]+1;
            }
        }
    }
    for (int i=0; i<nums.size(); i++){
        if (max < lis[i]){
            max=lis[i];
        }
    }

    return max ;
}
// =====================================================================================================================



int main() {
    vector<int>v={3,5,6,2,5,4,19,5,6,7,12};
    cout << "ans: "  << lengthOfLIS(v) << endl ;

    return 0;
}
