https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

```C
int maxDepth(char* s) {
    int level = 0;
    int mlevel = 0;
    for(int i = 0; i < strlen(s) - 1; i++){
        if(s[i] == '('){
            level++;
        }
        if(s[i] == ')'){
            level--;
        }
        mlevel = mlevel < level ? level : mlevel;
    }
    return mlevel;
}
```