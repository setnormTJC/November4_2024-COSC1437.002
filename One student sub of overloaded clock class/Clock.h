#pragma once
#include <iostream>
#include <iomanip>
//#include <stdexcept>

class Clock
{
	int hours = 0,
		minutes = 0,
		seconds = 0;

public:
	void printFull()
	{
		std::cout << std::right << std::setw(2) << std::setfill(' ') << hours << ":";
		std::cout << std::right << std::setw(2) << std::setfill('0') << minutes << ":";
		std::cout << std::right << std::setw(2) << std::setfill('0') << seconds;
		std::cout << std::endl;
	}
	void setTime(int new_hour, int new_min, int new_sec)
	{
		hours = new_hour;
		minutes = new_min;
		seconds = new_sec;
	}
	void increment(char pos)
	{
		if (pos == 's')
			seconds++;
		if (pos == 'm')
			minutes++;
		if (pos == 'h')
			hours++;

		if (pos == 'h' || pos == 'm' || pos == 's')
		{
			if (seconds > 59)
			{
				seconds = 0;
				minutes++;
			}
			if (minutes > 59)
			{
				minutes = 0;
				hours++;
			}
			if (hours > 23)
			{
				hours = 0;
			}
		}
		else
			//throw std::invalid_argument("Unspecified indicator when incrementing a `Clock` object.");
			std::cout << "[ERROR] Unspecified indicator of \"" << pos << "\" when incrementing a `Clock` object (ignoring)\n";
	}

	// operators
	bool operator < (Clock other_clock) // less then
	{
		int sum_left = this->hours + this->minutes + this->seconds;
		int sum_right = other_clock.hours + other_clock.minutes + other_clock.seconds;

		if (sum_left < sum_right)
			return true;
		else
			return false;
	}
	bool operator <= (Clock other_clock) // less then or equal to
	{
		int sum_left = this->hours + this->minutes + this->seconds;
		int sum_right = other_clock.hours + other_clock.minutes + other_clock.seconds;

		if (sum_left <= sum_right)
			return true;
		else
			return false;
	}
	bool operator > (Clock other_clock) // greater then
	{
		int sum_left = this->hours + this->minutes + this->seconds;
		int sum_right = other_clock.hours + other_clock.minutes + other_clock.seconds;

		if (sum_left > sum_right)
			return true;
		else
			return false;
	}
	bool operator >= (Clock other_clock) // greater then or equal to
	{
		int sum_left = this->hours + this->minutes + this->seconds;
		int sum_right = other_clock.hours + other_clock.minutes + other_clock.seconds;

		if (sum_left >= sum_right)
			return true;
		else
			return false;
	}
	bool operator == (Clock other_clock) // equal to
	{
		int sum_left = this->hours + this->minutes + this->seconds;
		int sum_right = other_clock.hours + other_clock.minutes + other_clock.seconds;

		if (sum_left == sum_right)
			return true;
		else
			return false;
	}
	Clock& operator ++ () // pre-increment
	{
		this->increment('s');
		return *this;
	}
	Clock operator ++ (int) // post increment
	{
		Clock temp = *this;
		this->increment('s');
		return temp;
	}
	friend std::ostream& operator << (std::ostream& out, Clock in_clock) // output
	{
		out << std::right << std::setw(2) << std::setfill(' ') << in_clock.hours << ":"
			<< std::right << std::setw(2) << std::setfill('0') << in_clock.minutes << ":"
			<< std::right << std::setw(2) << std::setfill('0') << in_clock.seconds;
		return out;
	}

	// constructors
	Clock() = delete;
	Clock(int in_hour, int in_min, int in_sec)
	{
		hours = in_hour;
		minutes = in_min;
		seconds = in_sec;
	}
};