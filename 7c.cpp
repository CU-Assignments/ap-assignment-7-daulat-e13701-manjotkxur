#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> lastIndex(26, 0);  // Store last occurrence index of each character
    vector<bool> visited(26, false); // To check if a character is already in stack
    stack<char> stk;  // Monotonic stack for result
    
    // Store the last occurrence index of each character
    for (int i = 0; i < s.size(); i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        // If the character is already in the result, skip it
        if (visited[ch - 'a']) continue;

        // Maintain lexicographical order by popping larger characters if they appear later
        while (!stk.empty() && stk.top() > ch && lastIndex[stk.top() - 'a'] > i) {
            visited[stk.top() - 'a'] = false;
            stk.pop();
        }

        // Push current character to stack
        stk.push(ch);
        visited[ch - 'a'] = true;
    }

    // Build the result string from the stack
    string result;
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }

    return result;
}

int main() {
    string s = "bcabc";
    cout << "Smallest lexicographical string: " << removeDuplicateLetters(s) << endl;
    return 0;
}
