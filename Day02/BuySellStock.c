//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < pricesSize; i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];  //Better day to buy
        }
        else if(prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;  //Better profit
        }
    }
    return maxProfit;
}

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]); //Tells size of Array

    int result = maxProfit(prices, n);

    printf("Maximum Profit = %d\n", result);

    return 0;
}