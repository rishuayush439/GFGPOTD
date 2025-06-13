
class Solution
{
public:
    int kokoEat(vector<int> &arr, int k)
    {
        int left = 1, right = *max_element(arr.begin(), arr.end());
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int hours = 0;

            // Compute total hours needed for current rate mid
            for (int bananas : arr)
            {
                hours += (bananas + mid - 1) / mid; // Equivalent to ceil(bananas/mid)
            }

            if (hours <= k)
                right = mid; // Try a smaller rate
            else
                left = mid + 1; // Increase rate
        }
        return left;
    }
};