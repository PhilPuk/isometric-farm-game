#pragma once

#include<iostream>
#include<map>
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

/*
* Class Info:
* Used for behavior in time periods.
* Can count total time.
*/

class Timer
{
private:
	float Timer_Max;
	float Timer_Min;
	float Timer_Tick;
	float Timer_Current;

	long Total_Time;

	void initVariables();
public:
	Timer();
	virtual~Timer();

	//Modifiers

	void setTimerToZero();
	//Sets the Timer_Current to Timer_Min
	void setTimerToMin();
	void setTimerMax(float max);
	//Replaces the Timer_Min value with the parameter
	void setTimerMin(float min);
	void setTickTime(float tick);

	//Accessors

	const float& getTimerMax() const;
	const float& getTimerMin() const;
	const float& getCurrentTime() const;
	const float& getTickTime() const;
	const float& getTotalTime() const;

	//Updating

	void updateTicking();
	bool updateReachMax();
	void updateTotalTime();
	void updateTimer();
	void update();
};