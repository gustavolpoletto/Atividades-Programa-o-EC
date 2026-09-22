#include <stdio.h>
#include <stdlib.h>

void printArr(int* a, int s){
    for (int i = 0 ; i < s ; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void doPascal(int rep, int* nums, int numsSize){
    if (rep == 0) return;
    int* newNums = malloc((numsSize + 1) * sizeof(int));
    newNums[0] = 1; newNums[numsSize] = 1;
    for(int i = 1 ; i < numsSize; i++){
        newNums[i] = nums[i - 1] + nums[i];
    }
    printArr(newNums , numsSize + 1);
    doPascal(rep- 1, newNums, numsSize+ 1);

}    

void pascal(int rep){
    int* n = malloc(2 * sizeof(int));
    n[0] = 1;
    n[1] = 1;
    printArr(n , 2);
    doPascal(rep - 1, n, 2);
    return;
}

int main(){
    int* n = malloc(2 * sizeof(int));
    n[0] = 1;
    n[1] = 1;
    pascal(12);
}