#include <iostream>
#include <chrono>
#include <thread>
#include "systemSleep.h"

void sleep()
{
	std::chrono::duration<int, std::milli> timespan(100);
	std::this_thread::sleep_for(timespan);
}