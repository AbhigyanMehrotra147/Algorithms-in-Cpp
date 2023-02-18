#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string stringPartition(string S, int a, int b)
    {
        int first;
        int second;
        int len = S.length();
        string ans;
        for (int i = 0; i < len; i += 1)
        {
            first = stoi(S.substr(0, i + 1));
            if (first % a == 0)
            {
                second = stoi(S.substr(i + 1, len - (i + 1)));
                if (second % b == 0)
                {
                    ans = S.substr(0, i + 1) + " " + S.substr(i + 1, len - (i + 1));
                    return ans;
                }
            }
        }
        ans = "-1";
        return ans;
    }
};
int main()
{
    Solution s1;
    string s2 = s1.stringPartition("1234", 2, 19);
    cout << s2;
    return 0;
}