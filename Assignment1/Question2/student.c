#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     // TODO: implement
     int count = 0;
     int possible = 0;

     for(int i = 0; i<numsSize; i++){
          if(count==0)
               possible = nums[i];
          if(nums[i] == possible)
               count++;
          else
               count--;

     }
     return possible;

}
