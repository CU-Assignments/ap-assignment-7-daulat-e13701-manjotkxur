#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0; // Invalid case
    
    int n = s.size();
    vector<int> dp(n + 1, 0);
    
    dp[0] = 1; // Empty string has one decoding
    dp[1] = 1; // Single non-zero digit has one decoding

    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1]; // Single-digit decode
        }

        int twoDigit = stoi(s.substr(i - 2, 2)); // Last two digits
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2]; // Two-digit decode
        }
    }
    
    return dp[n];
}

int main() {
    string s = "226";
    cout << "Number of ways to decode: " << numDecodings(s) << endl;
    return 0;
}
