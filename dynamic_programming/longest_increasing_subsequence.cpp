/**
 * @file
 * @brief Calculate the length of the [longest increasing
 * subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) in
 * an array
 *
 * @details
 * In computer science, the longest increasing subsequence problem is to find a
 * subsequence of a given sequence in which the subsequence's elements are in
 * sorted order, lowest to highest, and in which the subsequence is as long as
 * possible. This subsequence is not necessarily contiguous, or unique. Longest
 * increasing subsequences are studied in the context of various disciplines
 * related to mathematics, including algorithmics, random matrix theory,
 * representation theory, and physics. The longest increasing subsequence
 * problem is solvable in time O(n log n), where n denotes the length of the
 * input sequence.
 *
 * @author [Krishna Vedala](https://github.com/kvedala)
 * @author [David Leal](https://github.com/Panquesito7)
 * @author [Mann Patel](https://github.com/manncodes)
 */


#include <cassert>   /// for assert
#include <climits>   /// for std::max
#include <iostream>  /// for IO operations
#include <vector>    /// for std::vector

/**
 * @brief Calculate the longest increasing subsequence for the specified numbers
 * @param a the array used to calculate the longest increasing subsequence
 * @param n the size used for the arrays
 * @returns the length of the longest increasing
 * subsequence in the `a` array of size `n`
 */

/**
 * @namespace dynamic_programming
 * @brief Dynamic Programming algorithms
 */
namespace dynamic_programming {
/**
 * @namespace Knapsack
 * @brief Implementation of 0-1 Knapsack problem
 */
namespace longest_increasing_subsequence {

int LIS(const std::vector<uint64_t> &a, const uint32_t &n) {
    std::vector<int> lis(n);
    for (int i = 0; i < n; ++i) {
        lis[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = std::max(res, lis[i]);
    }
    return res;
}

} // namespace longest_increasing_subsequence
} // namespace dynamic_programming


/**
 * @brief Function to stress test above algorithm n=30,000
 * @return void
 */
void stresstest(){
    int answer = 0;
    freopen("stress_test_file.txt", "r", stdin);
    uint32_t n;
    std::cin >> n;
    std::vector<uint64_t> a(n);
    for(auto&i: a){
        std::cin >> i;
    }
    int result = dynamic_programming::longest_increasing_subsequence::LIS(a, a.size());
    std::cin >> answer;
    assert(result == answer);
    std::cout <<"Stress test implementation passed!"<< std::endl;
}

/**
 * @brief Function to test above algorithm
 * @returns void
 */
void test(){
    std::vector<uint64_t> a = {15,21,2,3,4,5,8,4,1,1};
    uint32_t n  = a.size();
    int result = dynamic_programming::longest_increasing_subsequence::LIS(a, n);
    assert(result == 5);  ///< Longest  increasing subsequence is {2,3,4,5,8}.
    std::cout << "Test implementation passed!" << std::endl;
}

/**
 * @brief Main function
 * @param argc commandline argument count (ignored)
 * @param argv commandline array of arguments (ignored)
 * @returns 0 on exit
 */
int main(int argc, char const *argv[]) {
    test();
    stresstest();
    return 0;
}