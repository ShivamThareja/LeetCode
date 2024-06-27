https://leetcode.com/problems/reverse-words-in-a-string/

I chatgpted the solution
```C
char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[0] = '\0';

    int end = len - 1;
    int start;

    while (end >= 0) {
        // Skip trailing spaces
        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        if (end < 0)
            break;

        // Find the start of the word
        start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }

        // Copy the word to the result
        int word_len = end - start;
        if (result[0] != '\0') {
            strcat(result, " ");
        }
        strncat(result, s + start + 1, word_len);

        // Move to the next word
        end = start - 1;
    }

    return result;
}
```
We start from the end of the string and move backwards.
We skip any trailing spaces.
When we encounter a non-space character, we mark it as the end of a word.
We continue moving backwards until we find a space or reach the beginning of the string, which marks the start of the word.
We copy this word to our result string, adding a space before it if it's not the first word.
We repeat this process until we've processed the entire input string.