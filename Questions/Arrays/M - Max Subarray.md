https://leetcode.com/problems/maximum-subarray/description/
```C
int maxSubArray(int* nums, int numsSize) {
    int largest = nums[0];
    int sum;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
                largest = sum > largest ? sum : largest;
            }
        }
    }
    return largest;
}
```
