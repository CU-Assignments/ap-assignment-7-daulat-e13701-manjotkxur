#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // Minimum price to buy
    int maxProfit = 0;       // Maximum profit
    
    for (int price : prices) {
        minPrice = min(minPrice, price);  // Update minimum price
        maxProfit = max(maxProfit, price - minPrice);  // Update max profit
    }
    
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}
