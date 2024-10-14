#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class SimpleDuplicateRemover {
public:
    vector<int> process(const vector<int>& sequence) {
        unordered_set<int> seen; // Track elements already added
        vector<int> result;

        // Traverse the sequence from right to left
        for (int i = sequence.size() - 1; i >= 0; --i) {
            if (seen.find(sequence[i]) == seen.end()) {
                // If it's the first time we encounter this element, add it to the result
                result.push_back(sequence[i]);
                seen.insert(sequence[i]);
            }
        }

        // Reverse the result to restore the original order
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    SimpleDuplicateRemover remover;

    // Test cases
    vector<int> result1 = remover.process({1, 5, 5, 1, 6, 1});
    vector<int> result2 = remover.process({2, 4, 2, 4, 4});
    vector<int> result3 = remover.process({6, 6, 6, 6, 6, 6});
    vector<int> result4 = remover.process({1, 2, 3, 4, 2, 2, 3});
    vector<int> result5 = remover.process({100, 100, 100, 99, 99, 99, 100, 100, 100});

    // Print results
    auto print = [](const vector<int>& vec) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    };

    print(result1); // Output: 5 6 1
    print(result2); // Output: 2 4
    print(result3); // Output: 6
    print(result4); // Output: 1 4 2 3
    print(result5); // Output: 99 100

    return 0;
}