#include <stdlib.h>
#include <stdio.h>

// int a[6], qsort(a, 3, sizeof(a[0]), cmp);
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; //这是从小到大排序，若是从大到小改成： return *(int *)b-*(int *)a;
}
