#include <chrono>
#include <iostream>
#include <thread>
int main()
{
    using namespace std::chrono_literals;
    // 每隔0.5s 死循环打印
    while (true)
    {
        std::cout << "Hello, World!" << std::endl;
        std::this_thread::sleep_for(0.5s);
    }
    return 0;
}