
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    int n = vec.size();
    set<vector<int>> uniquetrip;
    for (int i = 0; i < n; i++)
    {
        int target = -vec[i];
        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            int third = target - vec[j];
            if (s.find(third) != s.end())
            {
                vector<int> trip = {vec[i], vec[j], third};
                sort(trip.begin(), trip.end());
                uniquetrip.insert(trip);
            }
            s.insert(vec[j]);
        }
    }
    for (auto &trip : uniquetrip)
    {
        for (int x : trip)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
