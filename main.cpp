#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
#include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<TreeNode *> genTrees(int start, int end) {
    vector<TreeNode *> res;
    if (start > end) {
      return vector<TreeNode *>{nullptr};
    }

    if (start == end) {
      return vector<TreeNode *>{new TreeNode(start)};
    }

    for (int i = start; i <= end; i++) {
      vector<TreeNode *> left = genTrees(start, i - 1);
      vector<TreeNode *> right = genTrees(i + 1, end);

      for (auto l : left) {
        for (auto r : right) {
          res.push_back(new TreeNode(i, l, r));
        }
      }
    }
    return res;
  }
  vector<TreeNode *> generateTrees(int n) { return genTrees(1, n); }
};

void test1() {
  cout << boolalpha;
  vector<int> arr{1, 2, 3};

  cout << "1 ? " << Solution().generateTrees(3) << endl;
}

void test2() {}

void test3() {}

// rm -f a.out; g++ -std=c++11 main.cpp ../driver.cpp; ./a.out
