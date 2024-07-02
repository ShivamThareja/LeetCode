https://leetcode.com/problems/next-greater-element-i/description/

normal soln
```C
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* ans = malloc(nums1Size * sizeof(int));
    for(int i = 0; i < nums1Size; i++){
        int j = 0;
        for(j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j]) break;
        }
        for(; j < nums2Size; j++){
            if(nums2[j] > nums1[i]){
                ans[i] = nums2[j];
                break;
            }
        }
        if(j == nums2Size) ans[i] = -1;
    }
    return ans;
}
```