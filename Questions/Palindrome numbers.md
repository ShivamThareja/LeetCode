https://leetcode.com/problems/palindrome-number/description/

```C
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    bool p = true;

    int tmp = x;
    int rev = 0;

    while(tmp){
        rev = rev*10 + tmp%10;
        tmp/=10;
    }

    if(rev != x){
        p = false;
    }

    return p;
}
```
