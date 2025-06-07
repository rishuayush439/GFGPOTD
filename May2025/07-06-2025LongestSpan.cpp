/*  Question:Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) 
where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2)
    {
        int n = a1.size();
        vector<int> diff(n);
        
        for (int i = 0; i < n; i++)
            diff[i] = a1[i] - a2[i];

        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0, maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum += diff[i];

            if (prefixSum == 0)
                maxLen = i + 1;

            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end())
            {
                maxLen = max(maxLen, i - prefixSumIndex[prefixSum]);
            }
            else
            {

                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};

int main()
{
    vector<int> a1 = {0, 1, 0, 1, 1, 1, 1};
    vector<int> a2 = {1, 1, 1, 1, 1, 0, 1};

    Solution sol;
    cout << "Longest common span: " << sol.longestCommonSum(a1, a2) << endl;
    return 0;
}
