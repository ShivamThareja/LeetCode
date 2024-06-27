https://leetcode.com/problems/running-sum-of-1d-array/description/
```C
int* runningSum(int* nums, int numsSize, int* returnSize){
    *returnSize  = numsSize;
    int *rsums = malloc(*returnSize * sizeof(int));
    int currsum = 0;
    for(int i = 0; i < numsSize; i++){
        currsum += nums[i];
        rsums[i] = currsum;
    }
    return rsums;
}
```

Instead of using 2 for loops, can use one sum integer which stores the sums up till now and.