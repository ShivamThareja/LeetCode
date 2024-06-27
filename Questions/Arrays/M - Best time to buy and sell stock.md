https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Obvious way
```C
int maxProfit(int* prices, int pricesSize) {
    int buy = prices[0];
    int sell = prices[0];
    int profit = 0;
    int maxprofit = 0;
    for(int i = 0; i < pricesSize; i++){
        buy = prices[i];
        for(int j = i + 1; j < pricesSize; j++){
            sell = prices[j];
            profit = profit < (sell - buy) ? (sell - buy) : profit;
        }
    }

    return profit < 0 ? 0 : profit;
}
```

Better way
```C
int maxProfit(int* prices, int pricesSize) {
    int maxSell = 0;
    int maxProfit = 0;
    int buy, currProfit;
    for(int i = pricesSize - 1; i >= 0; i--){
        maxSell = prices[i] > maxSell ? prices[i] : maxSell;
        buy = prices[i];
        currProfit = maxSell - prices[i];
        maxProfit = maxProfit < currProfit ? currProfit : maxProfit;
    }

    return maxProfit < 0 ? 0 : maxProfit;
}
```
Start from last, the biggest number encountered from last will be the best selling option, track it.
For each prices[i] then subtract prices[i] from maxSell to get profit, out of all the profits, keep track of maxProfit. In the end while returning, if macProfit < 0, return 0 instead.