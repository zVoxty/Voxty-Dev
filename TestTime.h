#pragma once
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>

class Timer
{
private:
	std::clock_t c_start = std::clock();
	std::chrono::time_point<std::chrono::steady_clock> t_start;
	std::chrono::time_point<std::chrono::steady_clock> t_end;
	std::string stringify(double x)
	{
		std::ostringstream o;
		if (!(o << x))
		{
			return "INVALID CONVERSION";
		}
		return o.str();
	}
public:
	void Start()
	{
		t_start = std::chrono::high_resolution_clock::now();
	}
	void Stop()
	{
		t_end = std::chrono::high_resolution_clock::now();
	}
	std::string GetMsElapsedAsString()
	{
		std::string timestring;
		double msElapsed = std::chrono::duration<double, std::milli>(t_end - t_start).count();
		timestring = stringify(msElapsed);
		return timestring;
	}
	double GetMsElapsedAsDouble()
	{
		double msElapsed = std::chrono::duration<double, std::milli>(t_end - t_start).count();
		return msElapsed;
	}
};