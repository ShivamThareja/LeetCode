https://leetcode.com/problems/valid-palindrome/
```C
bool isPalindrome(char* s) {
    int len = strlen(s);
    char* checkthis = malloc(sizeof(char));
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(s[i])) {
            checkthis[count] = tolower(s[i]);
            count++;
            checkthis = realloc(checkthis, (count + 1) * sizeof(char));
        }
    }
    checkthis[count] = '\0';
    bool isPalindrome = true;
    for (int i = 0; i < count / 2; i++) {
        if (checkthis[i] != checkthis[count - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}
```
In leetcode this ques gives memory exceeded error, I need to think of a way to do this without creating another character pointer.

Better space complexity
```C
bool isPalindrome(const char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left]))
            left++;
        while (left < right && !isalnum(s[right]))
            right--;

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
```