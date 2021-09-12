#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
int maxSubArray(int *nums, int numsSize)
{
    if (numsSize <= 0)
        return INT_MIN;
    int maxSum = nums[0];
    int currMax = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        if (currMax < 0)
        {
            currMax = nums[i];
        }
        else
        {
            currMax += nums[i];
        }
        maxSum = maxSum < currMax ? currMax : maxSum;
    }
    return maxSum;
}