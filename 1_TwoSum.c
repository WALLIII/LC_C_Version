int cmp(const int *a, const int *b){
    return *(int *)a-*(int *)b;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int a1=0, a2=0;
    int p1=0, p2=numsSize-1;
    while(p1 < p2){
        int tmpSum=nums[p1]+nums[p2];
        if(tmpSum > target){
            p2--;
        }
        else if(tmpSum < target){
            p1++;
        }
        else{
            a1=nums[p1];
            a2=nums[p2];
            
            break;
        }
    }
    int* ret = malloc(sizeof(int) * 2);
    ret[0]=a1;
    ret[1]=a2;
    return ret;
}