// 字符串排序
// https://www.nowcoder.com/question/next?pid=21910835&qid=894528&tid=35770036

#include <iostream>
#include <vector>
#include <string>
#include <string.h> //strcmp所在函數
#include <algorithm>
#include <iomanip>

using namespace std;

// 字符串比較大小 重載函數

// 字符串比較大小
int cmp(string a, string b, int inda = 0, int indb = 0)
{

    if (a.length() == inda && b.length() == indb)
        return 0;
    else if (a.length() == inda && b.length() != indb)
        return 1; // a比b小
    else if (b.length() == inda && a.length() != indb)
        return -1;

    if (a[inda] < b[indb])
        return 1;
    else if (a[inda] > b[indb])
        return -1;

    return cmp(a, b, inda + 1, indb + 1);
}

// 1-快速排序
int quickPivot(vector<string> strs, int lo, int hi)
{
    // int pivot = lo;
    string pivotStr = strs[lo];
    while (lo < hi)
    {
        // 從右往左找小的
        while (lo < hi && cmp(strs[hi], pivotStr) > 0)
        {
            hi--; // 直到hi的串小於pivot
        }
        strs[lo] = strs[hi];
        while (lo < hi && cmp(strs[lo], pivotStr) < 0)
        {
            lo++; // 直到lo的串大於pivot
        }
        strs[hi] = strs[lo];
    }
    strs[lo] = pivotStr;
    return lo;
}

void quickSort(vector<string> &strs, int lo, int hi)
{
    // 分割，快排
    int pivot = quickPivot(strs, 0, strs.size() - 1);
    quickSort(strs, 0, pivot);
    quickSort(strs, pivot + 1, hi);
}

// 2-歸併排序
vector<string> merge(vector<string> strs1, vector<string> strs2)
{
    vector<string> ans;
    int ind1 = 0, ind2 = 0;
    while (ind1 < strs1.size() || ind2 < strs2.size())
    {
        // 如果A為空，或者 A不空且A值大於B值，則彈入B
        if (ind1 == strs1.size() || (ind1 < strs1.size() && cmp(strs1[ind1], strs2[ind2]) < 0))
        {
            ans.push_back(strs2[ind2++]);
        }
        else
        {
            // 否則壓入A
            ans.push_back(strs1[ind1++]);
        }
    }

    return ans;
}

// 雙閉區間
vector<string> mergeSort(vector<string> strs, int lo, int hi)
{
    // 分治
    int pivot = lo + (hi - lo) >> 1;
    vector<string> left = mergeSort(strs, lo, pivot);
    vector<string> right = mergeSort(strs, pivot + 1, hi);

    // 合並
    return merge(left, right);
}

vector<string> mergeSort(vector<string> strs)
{
    // 分治
    int pivot = strs.size() >> 1;
    vector<string> left = mergeSort(strs, 0, pivot);
    vector<string> right = mergeSort(strs, pivot + 1, strs.size() - 1);

    // 合並
    return merge(left, right);
}

int main2()
{
    string s1 = "abs";
    string s2 = "abd";
    cout << cmp(s1, s2) << endl;
    char buf1[] = "abs";
    // char *buf11 = "abs";
    char buf2[] = "abd";
    // char *buf22 = "abd";

    cout << strcmp(buf1, buf2) << endl;
}

int main3()
{
    vector<string> strs;
    // char s;
    // string word;
    // while (cin >> s)
    // {
    //     if (s == '\n')
    //         break;
    //     else if (s != ',')
    //         word.push_back(s);
    //     else
    //         strs.push_back(word);
    // }

    strs = {"", "a", "b", "ab", "aab", "abc"};
    for (auto ele : strs)
    {
        cout << ele << "\t";
    }

    cout << endl
         << "-------" << endl;

    // quickSort(strs,0,strs.size()-1);

    vector<string> ans = mergeSort(strs);

    cout << "::" << ans.size() << endl;

    for (auto ele : ans)
    {
        cout << ele << "\t";
    }

    return 0;
}

int main()
{
    string a = "abs";
    string b = "ab";
    bool f= a>b;
    cout << f << endl;
}