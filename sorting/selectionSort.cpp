#include <iostream>
#include <vector>
using namespace std;

class selectionSort
{
public:
    vector<int> selectionsort(vector<int> input)
    {
        int n = input.size();
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i; j < n; j++)
            {
                if (input[j] < input[min])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                int temp = input[i];
                input[i] = input[min];
                input[min] = temp;
            }
        }
        return input;
    }
};

int main(int argc, char const *argv[])
{
    selectionSort list;
    vector<int> ans = list.selectionsort({1, 0, -1,10,-10});
    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}
