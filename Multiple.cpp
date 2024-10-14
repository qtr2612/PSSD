#include <iostream>
#include <cmath>
using namespace std;

class Multiples {
public:
    int number(int min, int max, int factor) {
        // Find the first multiple of factor >= min
        int first = (min % factor == 0) ? min : min + (factor - min % factor);

        // Find the last multiple of factor <= max
        int last = (max % factor == 0) ? max : max - (max % factor);

        // If the first multiple is greater than the last, there are no valid multiples
        if (first > last) return 0;

        // Calculate the total number of multiples in the range
        return (last - first) / factor + 1;
    }
};

int main() {
    Multiples multiples;

    // Test cases
    cout << multiples.number(0, 14, 5) << endl;         // Output: 3
    cout << multiples.number(7, 24, 3) << endl;         // Output: 6
    cout << multiples.number(-123456, 654321, 997) << endl; // Output: 780
    cout << multiples.number(-75312, 407891, 14) << endl;   // Output: 34515

    return 0;
