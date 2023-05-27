#include <iostream>
#include <vector>
using namespace std;
class insertionSort
{
public:
    vector<int> InsertionSort(vector<int> nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int temp = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > temp)
            {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = temp;
        }
        return nums;
    }
};
int main()
{
    insertionSort test;
    vector<int> ans = test.InsertionSort({1, 4, 3, 2});
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
