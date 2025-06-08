class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result = "";
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';

            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
        }
        return result;
    }

    bool isSum(string s1, string s2, string rem)
    {
        if (rem.empty())
            return true;

        string sumStr = addStrings(s1, s2);

        if (rem.find(sumStr) != 0)
            return false;

        return isSum(s2, sumStr, rem.substr(sumStr.size()));
    }

    bool isSumString(string &s)
    {
        int n = s.size();

        for (int i = 1; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i);
                string rem = s.substr(j);

                if ((s1[0] == '0' && s1.size() > 1) || (s2[0] == '0' && s2.size() > 1))
                    continue;

                if (isSum(s1, s2, rem))
                    return true;
            }
        }

        return false;
    }
};