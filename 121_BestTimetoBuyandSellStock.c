#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int maxProfit(int* prices, int pricesSize){
    int currMin=prices[0];
    int globalMax=INT_MIN;
    for(int i=0;i<pricesSize; ++i){
        if((prices[i]-currMin)>globalMax){
            globalMax=prices[i]-currMin;
        }
        if(prices[i] < currMin){
            currMin=prices[i];
        }
        printf("%d  %d  %d\n",prices[i], currMin, globalMax);
    }
    return globalMax;
}
int main(){
    int a[6]={7,1,5,3,6,4};
    int res=maxProfit(a, 6);
    printf("%d", res);
    // for (int i = 0; i < 6; ++i)
    // {
    //     printf("%d ", a[i]);
    // }
}
