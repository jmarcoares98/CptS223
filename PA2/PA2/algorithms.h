#include <iostream>
#include <vector>

int maxSubSum1(const std::vector<int> &a);
int maxSubSum2(const std::vector<int> &a);
int maxSubSum3(const std::vector<int> &a);
int maxSubSum4(const std::vector<int> &a);
int maxSumRec(const std::vector<int> &a, int left, int right);
int max3(int sumLeft, int sumRight, int sumBorder);