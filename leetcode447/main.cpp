#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int ret = 0;
        unordered_map<double, int> m;
        for (int i = 0; i < n; ++i)
        {
            m.clear();
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                ++m[distance(points[j], points[i])];
            }
            for (auto x : m)
            {
                if (x.second >= 2)
                {
                    ret += x.second * (x.second - 1);
                }
            }
        }
        return ret;
    }
private:
    double distance(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
    }
};




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
