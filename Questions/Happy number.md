https://leetcode.com/problems/happy-number/

Usinng recursion, but gives time limit error.
```C
bool isHappy(int n) {
    if (n == 1) {
        return true;
    } else if (n == 2 || n == 3 || n == 4) {
        return false;
    } else {
        int ss;
        while (n != 0) {
            n /= 10;
            ss += (n % 10) * (n % 10);
        }
        return isHappy(ss);
    }
}
```