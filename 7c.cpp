#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> memo; // Memoization map

bool isScrambleUtil(string s1, string s2) {
    if (s1 == s2) return true; // Base case: strings are equal
    if (s1.length() != s2.length()) return false; // Length mismatch
    
    string key = s1 + "_" + s2;
    if (memo.find(key) != memo.end()) return memo[key];

    int n = s1.length();
    
    // Pruning: Check if both strings have the same frequency of characters
    string temp1 = s1, temp2 = s2;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    if (temp1 != temp2) return memo[key] = false;

    // Try every split position
    for (int i = 1; i < n; i++) {
        // Case 1: Without swapping
        if (isScrambleUtil(s1.substr(0, i), s2.substr(0, i)) &&
            isScrambleUtil(s1.substr(i), s2.substr(i))) {
            return memo[key] = true;
        }
        // Case 2: With swapping
        if (isScrambleUtil(s1.substr(0, i), s2.substr(n - i)) &&
            isScrambleUtil(s1.substr(i), s2.substr(0, n - i))) {
            return memo[key] = true;
        }
    }

    return memo[key] = false;
}

bool isScramble(string s1, string s2) {
    memo.clear();
    return isScrambleUtil(s1, s2);
}

int main() {
    string s1 = "great", s2 = "rgeat";
    cout << (isScramble(s1, s2) ? "True" : "False") << endl;
    return 0;
}
