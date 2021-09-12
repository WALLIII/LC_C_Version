#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; //这是从小到大排序，若是从大到小改成： return *(int *)b-*(int *)a;
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    if (m <= 0)
    {
        nums1 = nums2;
        return;
    }
    if (n <= 0)
    {
        return;
    }
    // qsort(nums1, m, sizeof(nums1[0]), cmp);
    // qsort(nums2, n, sizeof(nums2[0]),cmp);
    int p1 = m - 1, p2 = n - 1, pend = nums1Size - 1;
    while (p1 >= 0 && p2 >= 0)
    {
        if (nums1[p1] >= nums2[p2])
        {
            nums1[pend] = nums1[p1];
            printf("p1: %d ", p1);
            p1--;
        }
        else if (nums1[p1] < nums2[p2])
        {
            nums1[pend] = nums2[p2];
            printf("p2: %d ", p2);
            p2--;
        }
        // printf("pend: %d\n", pend);
        pend--;
    }
    while (p1 >= 0)
    {
        nums1[pend] = nums1[p1];
        p1--;
        pend--;
    }
    while (p2 >= 0)
    {
        nums1[pend] = nums2[p2];
        p2--;
        pend--;
    }
    return;
}

int main()
{
    int nums1[6] = {1, 2, 3, 0, 0, 0}, nums2[3] = {2, 5, 6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", nums1[i]);
    }
}