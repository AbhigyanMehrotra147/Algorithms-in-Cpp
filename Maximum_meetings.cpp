#include <utility>
#include <vector>
using namespace std;
class Solution
{
public:
    // Function to find the maximum number of meetings that can

    bool check_start_end(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second < p2.first;
    }
    bool check_second(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second < p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> Meetings;
        for (int i = 0; i < n; i += 1)
        {
            pair<int, int> p(start[i], end[i]);
            Meetings.push_back(p);
        }
        sort(Meetings.begin(), Meetings.end());
        /*for(int i = 0;i<n;i+=1)
        {
            cout << Meetings[i].first << " " << Meetings[i].second << endl;
        }*/
        // cout << endl;
        vector<pair<int, int>> Attend;
        int i = 0;
        int j = i + 1;
        while (i < n - 1 && j < n)
        {
            if (check_start_end(Meetings[i], Meetings[j]))
            {
                Attend.push_back(Meetings[i]);
                i = j;
                j = j + 1;
                continue;
            }
            if (check_second(Meetings[i], Meetings[j]))
            {
                j = j + 1;
                continue;
            }
            i = j;
            j += 1;
            ;
        }
        Attend.push_back(Meetings[i]);
        /*for(int i = 0;i<Attend.size();i+=1)
        {
            cout << Attend[i].first << " " << Attend[i].second << endl;
        }*/
        return Attend.size();
    }
};