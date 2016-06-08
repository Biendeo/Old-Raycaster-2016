#include <chrono>

#pragma once
class Timer {
	public:
	Timer(long long updateTimeMicros);
	~Timer();
	bool GetUpdate();
	void DismissUpdate();
	void ResetTimer();

	protected:
	bool update;
	std::chrono::microseconds updateTime;
	std::chrono::steady_clock::time_point lastChecked;
	std::chrono::steady_clock::time_point lastUpdate;

	void CheckTime();
};

