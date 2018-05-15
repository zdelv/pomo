#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

namespace chrono = std::chrono;
using clock_type = std::chrono::system_clock;
using ms = std::chrono::milliseconds;

// Trying to follow a rule of *
class Pomo 
{
    private:
        std::shared_ptr<clock_type::time_point> currentTime;

        bool active;
        
    public:
        Pomo();

        ~Pomo();

        Pomo operator=(const Pomo&);

        Pomo operator()(const Pomo&);

        void printTime() { std::cout << chrono::system_clock::to_time_t(*currentTime) << std::endl; };

        void updateTime();

        void updateTime(clock_type::time_point& time);

        void pauseTime();
};

Pomo::Pomo()
{
    currentTime = std::make_shared<clock_type::time_point>(clock_type::now());
    active = 1;
}

Pomo::~Pomo()
{

}

void Pomo::updateTime()
{
    *currentTime = clock_type::now();
}

void Pomo::updateTime(clock_type::time_point& time)
{
    *currentTime = time;   
}

void Pomo::pauseTime()
{
    active = 0;
}
