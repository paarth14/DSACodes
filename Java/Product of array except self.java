/*
Problem: Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] product = new int[nums.length];
       product[0] = 1;
        for(int i=1;i<nums.length;i++)
        {
            product[i] = product[i-1]*nums[i-1];//calculating product of numbers on left side of number
        }
        int right = 1;
        for(int j=nums.length-1;j>=0;j--)
        {
            product[j]*= right;//calculating product of numbers on right side of number
            right*=nums[j];
        }
        return product;
    }
}
