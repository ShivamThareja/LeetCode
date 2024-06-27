https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/

```C
int mostWordsFound(char** sentences, int sentencesSize) {
    int max = 0;
    int curspaces;
    for (int i = 0; i < sentencesSize; i++) {
        for (int j = 0; sentences[i][j] != '\0'; j++) {
            if (sentences[i][j] == ' ') {
                curspaces++;
            }
        }
        max = max > curspaces + 1 ? max : curspaces + 1;
        curspaces = 0;
    }
    return max;
}
```
