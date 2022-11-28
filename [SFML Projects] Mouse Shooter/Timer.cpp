#include"Timer.h"

void Timer::initVariables()
{
	this->Timer_Max = 60.f;
	this->Timer_Min = 0.f;
	this->Timer_Tick = 1.f;
	this->Timer_Current = 0.f;

	this->Total_Time = 0;
}

Timer::Timer()
{
	this->initVariables();
}

Timer::~Timer()
{

}

//Modifiers

void Timer::setTimerToZero()
{
	this->Timer_Current = 0.f;
}

void Timer::setTimerToMin()
{
	this->Timer_Current = this->Timer_Min;
}

void Timer::setTimerMax(float max)
{
	this->Timer_Max = max;
}

void Timer::setTimerMin(float min)
{
	this->Timer_Min = min;
}

void Timer::setTickTime(float tick)
{
	this->Timer_Tick = tick;
}

//Accessors

const float& Timer::getTimerMax() const
{
	return this->Timer_Max;
}

const float& Timer::getTimerMin() const
{
	return this->Timer_Min;
}

const float& Timer::getCurrentTime() const
{
	return this->Timer_Current;
}

const float& Timer::getTickTime() const
{
	return this->Timer_Tick;
}

//Gets the total amount of time the application countet
const float& Timer::getTotalTime() const
{
	return this->Total_Time * this->Timer_Max + this->Timer_Current;
}

//Updating

//Increases Timer_Current by Timer_Tick
void Timer::updateTicking()
{
	this->Timer_Current += this->Timer_Tick;
}

//If Timer_Current is bigger or equal to Timer_Max return true, else false.
bool Timer::updateReachMax()
{
	if (this->Timer_Current >= this->Timer_Max)
		return true;
	else
		return false;
}

//Increase total time periods countet by one.
void Timer::updateTotalTime()
{
	this->Total_Time++;
}

void Timer::updateTimer()
{
	if (this->updateReachMax())
	{
		this->setTimerToMin();
		this->updateTotalTime();
	}
	else
	{
		this->updateTicking();
	}
}

void Timer::update()
{
	this->updateTimer();
}
