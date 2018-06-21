#define FMT_HEADER_ONLY
#include <cxxopts.hpp>
#include <fmt/format.h>
#include <thread>
#include <chrono>
#include <memory>
#include <mutex>

namespace chrono = std::chrono;
using namespace std::literals::chrono_literals;
using clock_type = std::chrono::system_clock;
using ms = std::chrono::milliseconds;
using sec = std::chrono::seconds;

class TimeP 
{
    private:
        std::unique_lock<std::mutex> timepMutex;

    public:
        clock_type::time_point timePoint;

        TimeP();
};

class Pomo 
{
    private:
        std::mutex timeMutex;
        clock_type::time_point currentTime;
        clock_type::time_point timeStart;

        std::thread PomoThread;
        bool timerActive;

        int workLength;
        int breakLength;
        int breakAmount;

    public:
        Pomo();
        ~Pomo();

        Pomo operator=(const Pomo&);
        Pomo operator()(const Pomo&);

        Pomo(Pomo&& obj);

        void time();
        void printTime();
        void updateTime();
        void updateTime(const clock_type::time_point& time);
        void pauseTime();
};

Pomo::Pomo()
    : currentTime(clock_type::time_point(clock_type::now())), timeStart(currentTime), PomoThread(&Pomo::time, this), timerActive(true)
{
}

Pomo::~Pomo()
{
    PomoThread.join();
}

void Pomo::printTime()
{
    std::lock_guard<std::mutex> lock(timeMutex); 
    fmt::print("{}", clock_type::to_time_t(currentTime));
}

void Pomo::updateTime()
{
    std::lock_guard<std::mutex> lock(timeMutex);
    currentTime = clock_type::now();
}

void Pomo::updateTime(const clock_type::time_point& time)
{
    std::lock_guard<std::mutex> lock(timeMutex);
    currentTime = time;   
}

void Pomo::pauseTime()
{
    timerActive = false;
}

void Pomo::time()
{
    while (true)
    {
        std::this_thread::sleep_for(sec(1));   
        updateTime();
    }
}

// Templated to accept multiple different duration casts
template<class T>
void print_duration(const std::chrono::duration<T>& duration)
{
    fmt::print("Test {}\n", 1.23);
    std::cout << duration.count() << std::endl;
}

void print_time_point(const std::chrono::system_clock::time_point& point)
{
    std::cout << std::chrono::system_clock::to_time_t(point) << std::endl;
}
