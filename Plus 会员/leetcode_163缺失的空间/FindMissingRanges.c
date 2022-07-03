/*
leetcode_163缺失的空间
给定一个排序的整数数组 nums ，其中元素的范围在 闭区间 [lower, upper] 当中，返回不包含在数组中的缺失区间。

示例：

输入: nums = [0, 1, 3, 50, 75], lower = 0 和 upper = 99,
输出: ["2", "4->49", "51->74", "76->99"]
 * */

#include <malloc.h>
#include <stdio.h>

char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize){
    char** ans = malloc(sizeof(char*) * (numsSize + 1));
    for (int i = 0; i < numsSize + 1; i++) {
        ans[i] = malloc(sizeof(char) * 100);
    }
    *returnSize = 0;
    if (numsSize == 0) {
        if (upper == lower) {
            sprintf(ans[(*returnSize)++], "%d\0", upper);
        } else {
            sprintf(ans[(*returnSize)++], "%d->%d\0", lower, upper);
        }
        return ans;
    } else {
        if (nums[0] - lower == 1) {
            sprintf(ans[(*returnSize)++], "%d\0", lower);
        }
        if (nums[0] - lower > 1) {
            sprintf(ans[(*returnSize)++], "%d->%d\0", lower, nums[0] - 1);
        }
        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i + 1] - nums[i] == 2) {
                sprintf(ans[(*returnSize)++], "%d\0", nums[i] + 1);
            }
            if (nums[i + 1] - nums[i] > 2) {
                sprintf(ans[(*returnSize)++], "%d->%d\0", nums[i] + 1, nums[i + 1] - 1);
            }
        }
        if (upper - nums[numsSize - 1] == 1) {
            sprintf(ans[(*returnSize)++], "%d\0", upper);
        }
        if (upper - nums[numsSize - 1] > 1) {
            sprintf(ans[(*returnSize)++], "%d->%d\0", nums[numsSize - 1] + 1, upper);
        }
        return ans;
    }
}

/*
 * 解题思路
1、考虑数组为空情况
2、考虑lower和数组头部比较
3、考虑中间数组元素之间比较
4、考虑upper和数组尾部比较
5、考虑整形运算越界情况
 * */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 考虑整形越界问题

char ** findMissingRanges_2(int* nums, int numsSize, int lower, int upper, int* returnSize){

    char** res =(char**)calloc(numsSize+2,sizeof(char*));

    for(int i=0;i< numsSize+2; i++){
        res[i] =(char*)calloc(24, sizeof(char));
    }
    int count = 0;
    //考虑数组为空情况
    if(numsSize == 0){
        if(lower == upper) {
            sprintf(res[count++],"%d",lower);
        }else {
            sprintf(res[count++],"%d->%d",lower,upper);
        }
        *returnSize = count;
        return res;
    }

    //头部
    if((long)nums[0]-1 == lower) {
        sprintf(res[count++],"%d",lower);
    }else if((long)nums[0]-2 >= lower) {
        sprintf(res[count++],"%d->%d",lower,nums[0]-1);
    }
    //中间
    for(int i=1;i<numsSize;i++){
        if((long)nums[i]-2 == nums[i-1]) {
            sprintf(res[count++],"%d",nums[i-1]+1);
        }else if((long)nums[i]-2 > nums[i-1]) {
            sprintf(res[count++],"%d->%d",nums[i-1]+1,nums[i]-1);
        }
    }
    //尾部
    if(nums[numsSize-1] == (long)upper - 1) {
        sprintf(res[count++],"%d",upper);
    }else if((long)upper-2 >= nums[numsSize-1]) {
        sprintf(res[count++],"%d->%d",nums[numsSize-1]+1,upper);
    }

    *returnSize = count;
    return res;
}


int main() {
    // 老问题；怎么运行测试用例
    int nums[] = {0, 1, 3, 50, 75};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int lower = 0;
    int upper = 99;
    // int* nums, int numsSize, int lower, int upper, int* returnSize
    int returnSize[100];
    char ** res = findMissingRanges(nums, numsSize, lower, upper, returnSize);
    // C语言怎么数组二维指针？？
}
