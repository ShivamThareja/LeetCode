https://leetcode.com/problems/power-of-two/description/

Bitwise approach
```C
bool isPowerOfTwo(int n) {
    if(n <= 0){
        return false;
    }
    int ones = 0;
    while(n){
        if(n & 1 == 1){
            ones++;
        }
        n>>=1;
    }
    if(ones == 1){
        return true;
    }
    return false;
}
```

Recursive Approach
```C
bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    } else if (n == 1) {
        return true;
    } else if (n % 2 == 0) {
        return isPowerOfTwo(n / 2);
    } else {
        return false;
    }
}
```