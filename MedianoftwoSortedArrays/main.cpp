#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        double max_sz = std::max(nums1.size(), nums2.size());
        double min_sz = std::min(nums1.size(), nums2.size());
        double accumulator = 0;
        double total_sz = max_sz + min_sz;
        for (size_t i = 0; i < max_sz; i++) {
            if(nums1.size() > i)
                accumulator += nums1[i];
            if(nums2.size() > i)
                accumulator += nums2[i];
        }
        return accumulator / (total_sz);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
