#include "algorithms.h"

//Cubic maximum contiguous subsequence sum algoristhm
//code from appendix
int maxSubSum1(const std::vector<int> &a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i; j < a.size(); j++)
		{
			int thisSum = 0;

			for (int k = i; k <= j; k++)
				thisSum += a[k];

			if (thisSum > maxSum)
			{
				maxSum = thisSum;
			}

		}
	}

	return maxSum;
}

//Quadratic maximum contiguous subsequence sum algorithm
//code from appendix
int maxSubSum2(const std::vector<int> &a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); i++)
	{
		int thisSum = 0;
		for (int j = i; j < a.size(); j++)
		{
			thisSum += a[j];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

//Driver for divide and conquer maximum contiguos subsequence sum algorithm
//code from the appendix
int maxSubSum3(const std::vector<int> &a)
{
	return maxSumRec(a, 0, a.size() - 1);
}

//Linear-time maximum contiguous subsequence sum algorithm
//code from appendix
int maxSubSum4(const std::vector<int> &a)
{
	int maxSum = 0, thisSum = 0;

	for (int j = 0; j < a.size(); j++)
	{
		thisSum += a[j];

		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	
	return maxSum;
}

//Recursive maximum contigious subsequence sum algorithm.
//Finds maximum sum in subarray spanning a[left..right].
//Does not attempt to mantain actual best sequence.
//code from the appendix
int maxSumRec(const std::vector<int> &a, int left, int right)
{
	//Base case
	if (left == right) 
	{
		if (a[left] > 0) 
		{
			return a[left];
		}
		else 
		{
			return 0;
		}
	}

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;

	for (int i = center; i >= left; --i) 
	{
		leftBorderSum += a[i];

		if (leftBorderSum > maxLeftBorderSum) 
		{
			maxLeftBorderSum = leftBorderSum;
		}
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;

	for (int j = center + 1; j <= right; ++j) 
	{
		rightBorderSum += a[j];

		if (rightBorderSum > maxRightBorderSum) 
		{
			maxRightBorderSum = rightBorderSum;
		}
	}
	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
	maxRightBorderSum = 0, rightBorderSum = 0;
}

//code interpreted from the email link
//http://www.cplusplus.com/forum/beginner/62895/
int max3(int sumLeft, int sumRight, int sumBorder)
{
	if (sumLeft > sumRight)
	{
		if (sumLeft > sumBorder)
		{
			return sumLeft;
		}
	}
		
	if (sumRight > sumLeft)
	{
		if (sumRight > sumBorder)
		{
			return sumRight;
		}
	}

	if (sumBorder > sumRight)
	{
		if (sumBorder > sumLeft)
		{
			return sumBorder;
		}
	}
}