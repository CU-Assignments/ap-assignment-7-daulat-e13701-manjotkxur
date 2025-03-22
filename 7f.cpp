#include <iostream>
#include <vector>

using namespace std;

vector<int> threeEqualParts(vector<int>& arr) {
    int totalOnes = 0;
    for (int num : arr) totalOnes += num;

    if (totalOnes % 3 != 0) return {-1, -1};  // Can't split evenly

    if (totalOnes == 0) return {0, (int)arr.size() - 1};  // All zeros case

    int onesPerPart = totalOnes / 3;
    int first = -1, second = -1, third = -1, onesCount = 0;

    // Locate the start index of each partition
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            onesCount++;
            if (onesCount == 1) first = i;
            else if (onesCount == onesPerPart + 1) second = i;
            else if (onesCount == 2 * onesPerPart + 1) third = i;
        }
    }

    // Ensure the three parts are identical
    while (third < arr.size()) {
        if (arr[first] == arr[second] && arr[second] == arr[third]) {
            first++, second++, third++;
        } else {
            return {-1, -1};
        }
    }

    return {first - 1, second};  // Return partition points
}

int main() {
    vector<int> arr = {1, 0, 1, 0, 1, 0};
    vector<int> result = threeEqualParts(arr);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
