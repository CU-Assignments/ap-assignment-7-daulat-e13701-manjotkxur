#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);  // Each child gets at least 1 candy

    // Left-to-right: Ensure right child gets more candy if they have a higher rating
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right-to-left: Ensure left child gets more candy if they have a higher rating
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Sum up the total candies needed
    int totalCandies = 0;
    for (int c : candies) {
        totalCandies += c;
    }

    return totalCandies;
}

int main() {
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies required: " << candy(ratings) << endl;
    return 0;
}
