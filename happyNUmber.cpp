#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to calculate the sum of squares of digits of a number
    int DigitsumSquare(int N){
        int sq = 0;
        while(N){
            int digit = N % 10;
            sq += digit * digit;
            N = N / 10;
        }
        return sq;
    }

    // Optimized function to check if the number is a Happy Number using Floyd's Cycle Detection Algorithm
    int isHappy(int N){
        int slow = N, fast = N;

        // Tortoise and Hare technique
        do {
            slow = DigitsumSquare(slow);          // Move slow pointer one step
            fast = DigitsumSquare(DigitsumSquare(fast));  // Move fast pointer two steps
            
            if (fast == 1) return 1;  // If fast reaches 1, the number is happy
        } while (slow != fast);  // If slow meets fast, there is a cycle

        return 0;  // If there is a cycle, the number is not happy
    }
};

// Driver code
int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int N;
        cin >> N;  // Input number
        Solution ob;
        cout << ob.isHappy(N) << endl;  // Output whether the number is happy or not
    }
    return 0;
}
