#include <iostream>
#include <string>
using namespace std;
class Find_and_Replace
{
public:
    string sentance = "";
    int length;
    int count = 0;
    Find_and_Replace()
    {
        cout << endl;
        cin.ignore();
        getline(cin, sentance);
        length = sentance.length();
    }
    int count_instance(int i, string sub_str)
    {
        i = sentance.find(sub_str, i);
        if (i == string::npos)
        {
            return length;
        }
        count += 1;
        return i;
    }
    int count_all_instances(string sub_str)
    {
        int len_sub_str = sub_str.length();
        int i = 0;
        while (i < length)
        {
            i = count_instance(i, sub_str) + len_sub_str;
        }
        return count;
    }
    int count_overlapping_also(string sub_str)
    {
        int i = 0;
        while (i < length)
        {
            i = count_instance(i, sub_str) + 1;
        }
        return count;
    }
    string replace_word(string one, string two, int index, int end)
    {
        string ans = one.replace(index, end, two);
        return ans;
    }
};
int main()
{
    Find_and_Replace Fr;
    int count = Fr.count_overlapping_also("ana");
    cout << count << endl;
    string er = Fr.replace_word("Abhigyan", "manyu", 4, 7);
    cout << er << endl;
    er = er.erase(4, er.length() - 4);
    cout << er << endl;
    return 0;
}