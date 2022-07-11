#include <iostream>
#include <bits/stdc++.h>
#include <vector>

//----------------------------------------------------------------
// Not done

int main()
{
    int N = 5;
    std::vector<int> r = {3, 5, 1, 2, 0};

    std::sort(r.begin(), r.end(), [](int &a, int &b)
    {
        return a < b;
    });

    int count = 0;

    while (true)
    {
        int nums[3];
        for (int i = 0; i < 3; i++)
        {
            int j = 0;
            while (r[j] == 0)
            {
                j++;
            }
            nums[i] = j;
        }
        std::sort(nums, nums + sizeof(nums)/sizeof(nums[0]), [](int a, int b) { return r[a] < r[b]; });
        for (int i = 0; i < 3; i++)
        {
            nums[i] -= nums[2];
        }
    }

    std::cout << count;

    return 0;
}