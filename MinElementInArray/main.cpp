/**
 * @file main.cpp
 * @author Arun Kumar Devarajulu
 * @brief C++ Program to find the least number in a vector of integers
 * @copyright Copyright 2020 Arun Kumar Devarajulu. All rights reserved
 * @date February 3, 2020
 */

#include <iostream>
#include <vector>

/**
 * @brief Class for finding minimum element in a rotated
 * input array
 */
class Solution {
public:
    /**
     * @brief Static member function to find out the minimum
     * element in a vector of integers. The initial minimum
     * value is assumed as INT_MAX and the value is iteratively
     * compared with all elements of the vector in one sweep.
     * The best least minimum value is returned after the
     * comparison.
     * @param nums is the vector of integers
     * @return least number in the vector
     */
    static int findMin(std::vector<int>& nums) {
        int min = INT_MAX;
        for(auto &item : nums) {
            if (item < min)
                min = item;
        }
        return min;
    }
};

int main() {
    std::vector<int> numbers {1, 55, 77, 32, 22, 12, 999};
    std::cout << Solution::findMin((numbers)) << std::endl;
    return 0;
}
