
// problem link: https://leetcode.com/problems/longest-increasing-subsequence/
// solution video: https://www.youtube.com/watch?v=TocJOW6vx_I&t=185
// time complexity O(NlogN).
// space complexity O(N).
/*
    idea: is that if the coming element is less than the last element in v then we take it because it will increase our
    chances in increasing the sequence, also this will not affect the current length as we remove one and add one like:
    -1+1=0 no difference
 */


#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&v , int key){
    int l=0 ,r=v.size()-1 , mid =0;
    while (l<=r){

        mid=(l+r)/2;
        if (v[mid]==key ){
            return mid;
        }
        else if ( key < v[mid]){
            r=mid-1;
        }
        else if (key > v[mid]){
            l=mid+1;
        }


    }

    return mid ;

}

int lengthOfLIS(vector<int>& nums) {
    int index=0;
    vector<int>v;
    if (nums.size()==0){
        return 0;
    }
    v.push_back(nums[0]);
    for (int i=1 ; i<nums.size();i++){
        if (v.back() < nums[i] ){
            v.push_back(nums[i]);
        }
        else {
            index=binarySearch(v,nums[i]);
            if (v[index]< nums[i]){
                index++;
            }
            // cout << nums[i] << " ,Index: " << index << endl ;
            v[index]=nums[i];
        }

    }

    return v.size() ;

}



int main() {
    vector<int>v={3,5,6,2,5,4,19,5,6,7,12};
    cout << "ans: "  << lengthOfLIS(v) << endl ;

    return 0;
}
