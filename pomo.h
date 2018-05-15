#include <iostream>
#include <thread>
#include <chrono>

namespace chrono = std::chrono;
using clock_type = std::chrono::system_clock;
using ms = std::chrono::milliseconds;

// Trying to follow a rule of *
class Pomo 
{
    private:
        chrono::time_point<ms> currentTime;

        
    public:
        Pomo();

        ~Pomo();

        Pomo operator=(const Pomo&);

        void printTime() { std::cout << chrono::system_clock::to_time_t(currentTime) << std::endl; };

};
