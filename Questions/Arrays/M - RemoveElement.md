https://leetcode.com/problems/remove-element/

**2 Pointer Approach**
Move two indexes, one always moves, one moves only when it is on an element it doesnt wanna remove.
```C
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int j = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}
```
\
**Can also be done by recursion...**