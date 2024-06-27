https://leetcode.com/problems/reverse-vowels-of-a-string

```C
int isVowel(char ch) {
    char vowels[] = "aeiouAEIOU";
    return (strchr(vowels, ch) != NULL);
}

char* reverseVowels(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    int iV = 0, jV = 0;
    char tmp;

    while (i <= j) {
        iV = isVowel(s[i]);
        jV = isVowel(s[j]);

        if(iV && jV){
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            iV = 0;
            jV = 0;
        }

        i += iV ? 0 : 1;
        j -= jV ? 0 : 1;

    }
    return s;
}
```