#include <iostream>
#include <vector>
using namespace std;

// Define the Solution class
class Solution {
public:
    // Merge function to merge num2 into num1
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i = m - 1;           // Last index of initialized part of num1
        int j = n - 1;           // Last index of num2
        int k = m + n - 1;       // Last index of num1 (total size)

        // Merge from the back to avoid overwriting values in num1
        while (i >= 0 && j >= 0) {
            if (num1[i] > num2[j]) {
                num1[k] = num1[i];
                i--;
            } else {
                num1[k] = num2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in num2, copy them
        while (j >= 0) {
            num1[k] = num2[j];
            j--;
            k--;
        }
    }
};

int main() {
    // Create an object of Solution
    Solution s;

    // Example input: num1 has extra space at the end
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};
    int m = 3; // Number of initialized elements in num1
    int n = 3; // Number of elements in num2

    // Call the merge function
    s.merge(num1, m, num2, n);

    // Print the merged array
    cout << "Merged Array: ";
    for (int val : num1) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

