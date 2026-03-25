// brute force
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    int n = vec.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (vec[i] + vec[j] + vec[k] == 0)
                {
                    vector<int> trip = {vec[i], vec[j], vec[k]};
                    sort(trip.begin(), trip.end());
                    if (s.find(trip) == s.end())
                    {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        int sum = 0; // to calculate sum of this triplet
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " "; // print each element
            sum += ans[i][j];         // add to sum
        }
    }
}
