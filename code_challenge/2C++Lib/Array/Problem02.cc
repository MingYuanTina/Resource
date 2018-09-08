// Question: 283 Move Zeroes
	// Given an array nums, write a function to move all 0's to the end of 
	// it while maintaining the relative order of the non-zero elements.
// Example
	// Given nums = [0, 1, 0, 3, 12]
	// After calling your function
	// nums should be [1, 3, 12, 0, 0]
// Note
	// You must do this in-place without 
	// making a copy of the array
	// Minimize the total number of operations
// General Strategy
	// Shift 0 to the end and keep shift rest to the front
		// When it's zero, push to the end and shift left
		// When it's non-zero, update index
	// Time Complexity: O(kn), k is the number of zero

// JavaScript Version
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 **/
// var moveZeroes = function(nums) {
//     var i = 0;
//     var count = 0;
//     while (count < nums.length){
//         if (nums[i] === 0){
//             nums.splice(i,1);
//             nums.push(0);
//         } else {
//             i++;   
//         }
//         count+=1;
//     }
// };
