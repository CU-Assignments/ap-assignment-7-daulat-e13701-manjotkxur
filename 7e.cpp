#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end()); // Sort greed factors
    sort(s.begin(), s.end()); // Sort cookie sizes

    int i = 0, j = 0, count = 0;

    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) { // Cookie can satisfy the child
            count++;
            i++; // Move to next child
        }
        j++; // Move to next cookie
    }

    return count;
}

int main() {
    vector<int> g = {1, 2, 3};  // Children's greed factors
    vector<int> s = {1, 1};     // Cookie sizes

    cout << "Maximum number of content children: " << findContentChildren(g, s) << endl;
    return 0;
}
