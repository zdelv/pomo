#include "pomo.h"

//
// A Pomodoro timer written in C++
// By: zdelv
// Splits work into 25 minute intervals, with 3-5 minute break
// in between. There is also a longer break after 4-5 work intervals
// The length of or number of intervals is changable via commandline
// or conf file (.config/pomo/pomo.conf)
//

int main() {

    /* Pomo timer; */

    /* timer.printTime(); */

    auto timeNow = std::chrono::system_clock::now();
    auto timeStart = timeNow;
    std::string notifyOutput;
    // Might not be needed anymore if using rvalues
    /* std::chrono::duration<float> timeDuration; */
    /* timeDuration = std::chrono::duration_cast<sec>(timeNow - timeStart); */
    /* print_duration(timeDuration); */

    while (true)
    {
        timeNow = std::chrono::system_clock::now();
        print_duration(std::chrono::duration_cast<sec>(timeNow - timeStart));

        /* std::cout << (clock_type::to_time_t(timeNow)) << "\n"; */
        std::this_thread::sleep_for(1s);

        /* std::this_thread::sleep_for(sec(2)); */   
        /* timer.printTime(); */
        notifyOutput.clear();
    }
}
