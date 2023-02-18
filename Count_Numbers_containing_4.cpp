#include <iostream>
#include <vector>
using namespace std;
class Count_Numbers_4
{
public:
    int countNumberswith4(int N)
    {
        if (N < 4)
            return 0;
        int count = 1;
        vector<bool> has_four(10, false);
        has_four[4] = true;
        for (int i = 10; i <= N; i += 1)
        {
            if (has_four[i / 10] || has_four[i % 10])
            {
                count += 1;
                has_four.push_back(true);
                continue;
            }
            has_four.push_back(false);
        }
        return count;
    }
};