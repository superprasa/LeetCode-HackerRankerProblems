
#include "LeetCode.h"
using namespace std;


    double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
         vector<int> merged;
       for(int k = 0; k < nums1.size() + nums2.size(); ++k) {
        if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])) {
            merged.push_back(nums1[i++]);
        } else {
            merged.push_back(nums2[j++]);
        }
    }
    int n=merged.size();
        if(n%2==1)
        return merged[n/2];
        else{
          return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
    }
    