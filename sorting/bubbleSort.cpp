#include <iostream>
#include <vector>
using namespace std;
class bubbleSort
{
public:
    vector<int> sortedList(vector<int> inputList)
    {
        int n = inputList.size();
        for (int i = 0; i < n - 1; i++)
        {
            bool flag = false;
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (inputList[j] > inputList[j + 1])
                {
                    flag = true;
                    int temp = inputList[j];
                    inputList[j] = inputList[j + 1];
                    inputList[j + 1] = temp;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        return inputList;
    }
};

int main(int argc, char const *argv[])
{
    bubbleSort test;
    vector<int> ans = test.sortedList({1, 2, 3, 4});
    for (int num : ans)
    {
        cout << num << " ";
    }
    return 0;
}
