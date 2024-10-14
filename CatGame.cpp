#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class CatGame {
public:
    int getNumber(vector<int>& coordinates, int X) {
        int n = coordinates.size();
        // Sort the coordinates to make it easier to reason about movements
        sort(coordinates.begin(), coordinates.end());

        // Initialize the minimum difference to a large value
        int minDifference = INT_MAX;

        // Try all combinations of extreme values:
        // 1. Leftmost cat at coordinates[0] can move left or right
        // 2. Rightmost cat at coordinates[n-1] can move left or right
        for (int leftOption : {coordinates[0] - X, coordinates[0] + X}) {
            for (int rightOption : {coordinates[n - 1] - X, coordinates[n - 1] + X}) {
                // Calculate the range for this combination of movements
                int minPosition = leftOption;
                int maxPosition = rightOption;

                // Update the minimum difference
                minDifference = min(minDifference, maxPosition - minPosition);
            }
        }

        return minDifference;
    }
};

int main() {
    CatGame game;

    // Test cases
    cout << game.getNumber(vector<int>{-3, 0, 1}, 3) << endl;       // Output: 3
    cout << game.getNumber(vector<int>{4, 7, -7}, 5) << endl;       // Output: 4
    cout << game.getNumber(vector<int>{-100000000, 100000000}, 100000000) << endl; // Output: 0
    cout << game.getNumber(vector<int>{3, 7, 4, 6, -10, 7, 10, 9, -5}, 7) << endl; // Output: 7
    cout << game.getNumber(vector<int>{-4, 0, 4, 0}, 4) << endl;    // Output: 4
    cout << game.getNumber(vector<int>{7}, 0) << endl;              // Output: 0

    return 0;
}
