https://leetcode.com/problems/number-of-good-pairs/
```C
int numIdenticalPairs(int* nums, int numsSize) {
    int gp = 0;

    // BRUTE FORCE
    // for(int i = 0; i < numsSize; i++){
    //     for(int j = i + 1; j < numsSize; j++){
    //         if(nums[i] == nums[j]){
    //             gp++;
    //         }
    //     }
    // }

    int arr[101] = {0};
    // Count each number occuring how many times.
    for(int i = 0; i < numsSize; i++){
        arr[nums[i]] += 1;    
    }
    for(int i = 1; i < 101; i++){
        gp += arr[i] * (arr[i] - 1) / 2;
		// Using permuations and combinations nC2 gives us n(n-1) / 2
    }

    return gp;
}
```