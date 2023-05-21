#include <iostream>
#include <queue>
#include <string>

bool contains(std::queue<std::string>& q, const std::string& str)
{
    bool flag = false;
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        std::string temp = q.front();
        q.pop();
        if (temp == str)
        {
            flag = true;
        }
        q.push(temp);
    }
    return flag;
}

int main()
{
    std::queue<std::string> queue;

    queue.push("A");
    queue.push("B");
    queue.push("C");
    queue.push("D");

    bool result = contains(queue, "C");
    std::cout << std::boolalpha << result << std::endl; // Output: true

    result = contains(queue, "E");
    std::cout << std::boolalpha << result << std::endl; // Output: false

    while (!queue.empty())
    {
        std::cout << queue.front() << std::endl;
        queue.pop();
    }

    return 0;
}
