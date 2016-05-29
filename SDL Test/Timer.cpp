#include <chrono>

#include "Timer.h"



Timer::Timer(long long updateTimeMicros) {
	updateTime = std::chrono::duration<long long, std::micro>(updateTimeMicros);
	update = false;
	ResetTimer();
}


Timer::~Timer() {
}

bool Timer::GetUpdate() {
	CheckTime();
	if (std::chrono::duration_cast<std::chrono::microseconds>(lastChecked - lastUpdate).count() >= updateTime.count()) {
		lastUpdate += updateTime;
		update = true;
	}
	return update;
}

void Timer::DismissUpdate() {
	update = false;
}

void Timer::ResetTimer() {
	CheckTime();
	lastUpdate = lastChecked;
}

void Timer::CheckTime() {
	lastChecked = std::chrono::high_resolution_clock::now();
}