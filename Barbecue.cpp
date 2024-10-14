#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Barbecue {
public:
    int eliminate(int n, vector<int>& voter, vector<int>& excluded) {
        vector<int> votesReceived(n, 0);  // Track votes received by each member
        vector<int> votesGiven(n, 0);     // Track votes given by each member

        // Tally votes received and given
        for (int i = 0; i < voter.size(); ++i) {
            votesReceived[excluded[i]]++;  // Increment votes received for excluded member
            votesGiven[voter[i]]++;        // Increment votes given by the voter
        }

        // Find the member with the most votes against them
        int maxVotes = -1;
        int result = -1;
        for (int i = 0; i < n; ++i) {
            if (votesReceived[i] > maxVotes) {
                maxVotes = votesReceived[i];
                result = i;
            } else if (votesReceived[i] == maxVotes) {
                // If there is a tie, check who gave more votes
                if (votesGiven[i] > votesGiven[result]) {
                    result = i;
                } else if (votesGiven[i] == votesGiven[result] && i < result) {
                    // If the tie persists, choose the member with the smallest index
                    result = i;
                }
            }
        }

        return result;
    }
};

int main() {
    Barbecue bbq;

    // Test cases
    vector<int> voter1 = {0, 1, 2, 2};
    vector<int> excluded1 = {2, 2, 0, 1};
    cout << bbq.eliminate(3, voter1, excluded1) << endl;  // Output: 2

    vector<int> voter2 = {0, 2, 2};
    vector<int> excluded2 = {2, 0, 1};
    cout << bbq.eliminate(3, voter2, excluded2) << endl;  // Output: 2

    vector<int> voter3 = {0, 1};
    vector<int> excluded3 = {1, 0};
    cout << bbq.eliminate(2, voter3, excluded3) << endl;  // Output: 0

    vector<int> voter4 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                          2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
                          18, 19, 19, 19, 19};
    vector<int> excluded4 = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
                             17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
                             13, 14, 15, 16, 17, 1, 2, 3};
    cout << bbq.eliminate(20, voter4, excluded4) << endl;  // Output: 2

    vector<int> voter5 = {4, 3, 1, 0};
    vector<int> excluded5 = {2, 2, 3, 3};
    cout << bbq.eliminate(5, voter5, excluded5) << endl;  // Output: 3

    vector<int> voter6 = {};
    vector<int> excluded6 = {};
    cout << bbq.eliminate(5, voter6, excluded6) << endl;  // Output: 0

    return 0;
}
