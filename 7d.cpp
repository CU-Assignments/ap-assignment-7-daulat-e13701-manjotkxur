#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();

    for (int i = 0; i < size; i++) {
        if (flowerbed[i] == 0) {
            bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1; // Plant a flower
                n--;

                if (n == 0) return true; // No more flowers to plant
            }
        }
    }
    
    return n <= 0;
}

int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    cout << "Can plant " << n << " flowers? " << (canPlaceFlowers(flowerbed, n) ? "True" : "False") << endl;
    return 0;
}
