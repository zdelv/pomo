#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <thread>

using ms = std::chrono::milliseconds;

void print_time_point(std::chrono::system_clock::time_point& point)
{
    std::cout << std::chrono::system_clock::to_time_t(point) << std::endl;
}

void print_duration(std::chrono::system_clock::duration& duration)
{
    std::cout << std::chrono::duration_cast<ms>(duration).count() << std::endl;
}

int main() {
    auto timenow = std::chrono::system_clock::now();

    std::this_thread::sleep_for(ms(500));

    auto timesecond = std::chrono::system_clock::now();

    auto timeduration = timesecond - timenow;

    print_duration(timeduration);
    print_time_point(timenow);

}
