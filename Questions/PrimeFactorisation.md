```C
void primefac(int n) {
  if (n == 1) {
    printf("%d\n", 1);
    return;
  }

  int i = 2;
  while (1) {
    if (n % i == 0) {
      printf("%d\n", i);
      return primefac(n / i);
    }
    i++;
  }
}
```