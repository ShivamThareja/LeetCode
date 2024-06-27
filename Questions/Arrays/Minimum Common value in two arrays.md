https://leetcode.com/problems/minimum-common-value

This gives TL error
```C
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }
        }
    }
    return -1;
}
```


Better solutuion
```C
int binSearch(int* arr, int key, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (low < high) {
        return arr[mid] > key ? binSearch(arr, key, low, mid - 1)
                              : binSearch(arr, key, mid + 1, high);
    }
    return -1;
}

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* toloop = nums1[0] > nums2[0] ? nums1 : nums2;
    int looptimes = nums1[0] > nums2[0] ? nums1Size : nums2Size;
    int* tosearch = nums1[0] > nums2[0] ? nums2 : nums1;
    int searchTillIdx = (nums1[0] > nums2[0] ? nums2Size : nums1Size) - 1;
    int low = 0;
    int high = searchTillIdx;
    for (int i = 0; i < looptimes; i++) {
        if (binSearch(tosearch, toloop[i], low, high) != -1) {
            return toloop[i];
        }
    }
    return -1;
}
```