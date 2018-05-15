#include "pomo.h"

//
// A Pomodoro timer written in C++
// By: zdelv
// Splits work into 25 minute intervals, with 3-5 minute break
// in between. There is also a longer break after 4-5 work intervals
// The length of or number of intervals is changable via commandline
// or conf file (.config/pomo/pomo.conf)
//
// Also has the ability to output in a manner perfect for polybar
//


void print_time_point(std::chrono::system_clock::time_point& point)
{
    std::cout << std::chrono::system_clock::to_time_t(point) << std::endl;
}

void print_duration(std::chrono::system_clock::duration& duration)
{
    std::cout << std::chrono::duration_cast<ms>(duration).count() << std::endl;
}

int main() {

    Pomo timer;


    auto timenow = std::chrono::system_clock::now();

    std::this_thread::sleep_for(ms(500));

    auto timesecond = std::chrono::system_clock::now();

    timer.printTime();

    auto timeduration = timesecond - timenow;

    print_duration(timeduration);
    print_time_point(timenow);
}
