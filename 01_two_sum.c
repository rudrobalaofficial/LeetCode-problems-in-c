#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

   
    int hashMap[100000] = {0};

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

      
        if (hashMap[complement] != 0) {
           
            result[0] = hashMap[complement] - 1;
            result[1] = i;
            break;
        }

        
        hashMap[nums[i]] = i + 1;
    }

    return result;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    printf("%d, %d\n", result[0], result[1]);

    free(result); 

    return 0;
}

