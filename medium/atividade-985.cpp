/*

You are given an integer array nums and an array queries where queries[i] = [vali, indexi].
(ANNOTATION)
-> nums = [b] and queries = [[x,y][z,a]]

For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.
(ANNOTATION)
-> answer = []
-> for (i = 0; i <= length(queries); i++)
{
    int sum = 0
    nums[queries][i][1]] = nums[queries[i][1]] + queries[i][0]
    for (int j = 0; j <= length(nums); j++)
    {
        if (nums[j] % 2 == 0)
        {
            sum += nums[j]
        }
    }
    answer.push_back(sum)
    print(sum)
}

Return an integer array answer where answer[i] is the answer to the ith query.
(ANNOTATION)
-> print(answer)

*/


/*

Example 1:
Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]

Explanation: At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.

Example 2:
Input: nums = [1], queries = [[4,0]]
Output: [0]

*/

#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<int> answer;
        
        for (int i = 0; i < queries.size(); i++)
        {
            int sum = 0;
            nums[queries[i][1]] = nums[queries[i][1]] + queries[i][0];
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] % 2 == 0)
                {
                    sum += nums[j];
                }
            }
            answer.push_back(sum);
        }
        return answer;
    }
};

int main()
{
    Solution sol;
    
    std::vector<int> nums = {1, 2, 3, 4};

    // Vetor de consultas
    std::vector<std::vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};

    std::vector<int> result = sol.sumEvenAfterQueries(nums, queries);
    std::cout<<"[ ";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout<<result[i]<<' ';
    }
    std::cout<<']'<<std::endl;
    return 0;
}

// Error 1: Vector is not a template
// Solution: adding "std::" symbol before <vector> command
