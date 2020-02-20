#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        std::string reversed;
        for (auto it = s.rbegin(); it < s.rend(); it++) {
            reversed += *it;
        }
        bool reset = false;
        std::string::iterator start, end, prev_start, prev_end, l_start, l_end;

        start = s.begin();
        std::cout << &start << "\n";
        end = s.begin();
        prev_start = s.begin();
        prev_end = s.begin();
        size_t length = std::distance(s.begin(), s.begin());
        auto r_walk = s.rbegin();

        for (auto it = s.begin(); it < s.end(); it++) {
            //std::cout << *it << *r_walk << "\n";
            if (*it != *r_walk) {
                //std::cout << *it << "\n";
                reset = false;
            }
            if (start == s.begin() && end == s.begin() && *it == *r_walk) {
                std::advance(start, std::distance(s.begin(), it));
                std::cout << std::distance(s.begin(), it) << "\n";
                std::cout << &start << " " << &*it << "\n";
                reset = true;
            }
            if (start != s.begin() && reset) {
                //std::cout << std::boolalpha << reset << "\n";
                end = it;
            }
            if (!reset) {
                std::cout << "called\n";
                //std::cout << &start << "\n";
                if (std::distance(start, end) > length) {
                    length = std::distance(start, end);
                    std::cout << length << "\n";
                    l_start = prev_start;
                    l_end = prev_end;
                }
                prev_start = start;
                prev_end = end;
                start = s.begin();
                end = s.begin();
            }
            if (r_walk <= s.rend())
                r_walk++;
        }
        std::string op;
        for (auto it = l_start; it < l_end; it++) {
            op += *it;
        }
        return op;
    }
};

int main() {
    Solution solver;
    std::cout << solver.longestPalindrome("ccdxdccc") << "\n";
    return 0;
}
