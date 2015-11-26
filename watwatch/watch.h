//Watch.h
//Used for time-related functions

#ifndef WATCH_H
#define WATCH_H

#include "misc.h"
#include "values.h"

//Declarations
void initWatch();
void drawWatch();
void updateTime();
void updateTimer();
void getWatch();
void timer(int s);
void checkAlarm();
void setAlarm(struct date d);
void startStopWatch();
void pauseStopWatch();
void stopStopWatch();
void resetStopWatch();
int getStopWatch();
void drawTimer();
void drawAlarm();
void drawStopWatch();

//Current date
struct date current;

//Alarms
#define MAX_ALARMS 100
struct date alarms[MAX_ALARMS];
int alarmSize = 0;

//Timers
#define MAX_TIMERS 100
int timers[MAX_TIMERS];
int timerSize = 0;


//Timer Data
int s_Timer=0;
int m_Timer=0;
int h_Timer=0;

char secDisplay[2];
char minDisplay[2];
char hourDisplay[2];
//Stopwatch
int stopwatch = 0;
bool stopwatchRunning = false;

//Initialization function
//Only called once
void initWatch() {
	current = getDate();
	return;
}

//Draws current function, continuously called
//DRAW_DELAY
void drawWatch() {
        //Display Title
        OrbitOledSetCursor(4 , 1);
        OrbitOledPutString("Title: ");

        //Displaying steps number
        itoa(h_Timer, hourDisplay, 10);
        OrbitOledSetCursor(7, 1);
        OrbitOledPutString(hourDisplay);

        OrbitOledSetCursor(11,1);
        OrbitOledPutString(":");

        itoa(m_Timer, minDisplay, 10);
        OrbitOledSetCursor(13, 1);
        OrbitOledPutString(minDisplay);

        OrbitOledSetCursor(15,1);
        OrbitOledPutString(":");

        itoa(s_Timer,secDisplay,10);
        OrbitOledSetCursor(15,1);
        OrbitOledPutString(secDisplay);

	char *time;
	sprintf("%d:%d:%d", time, current.hour, current.minute, current.second);
	OrbitOledSetCursor(1, 2);
	OrbitOledPutString(time);
}

//Checks and updates current time, continuously called
void updateTime() {
	current = getDate();
}

//Draw timer
void drawTimer() {

}

//Draw alarm
void drawAlarm() {

}

//Update Timer, continuously called
//TIMER_DELAY
void updateTimer() {
	int i;
	for(i = 0; i < timerSize; i++) {
		timers[i] --;
	}
	return;
}

//Creates a new timer with s seconds left
void timer(int s) {
	if(timerSize < MAX_TIMERS) {
		timers[timerSize] = s;
		timerSize++;
	}
	else {
		//SUM TING WONG
		//REALLY WONG
		//REALLY REALLY WONG
		//REALLY REALLY REALLY WONG
		//RILEY WONG
	}
  return;
}

//Check alarm, continuously called
//TIME_DELAY
void checkAlarm() {
	int i;
	for(i = 0; i < alarmSize; i++) {
		if(timeElapsedMs(alarms[i], getDate()) >= 0) {
			//RING RING RING RING RING BANANA PHONE
			//TODO: Flash LEDs
		}
	}
	return;
}

void setAlarm(struct date d) {
	if(alarmSize + 1 < MAX_ALARMS) {
		alarms[alarmSize + 1] = d;
		alarmSize++;
	}
	else {
		//SUM TING WONG
		//REALLY WONG
		//REALLY REALLY WONG
		//REALLY REALLY REALLY WONG
		//RILEY WONG

		//How do you make more than MAX_ALARMS alarms???
	}
	return;
}

//startStopWatch, starts the stopwatch
void startStopWatch() {
	stopwatchRunning = true;
	//TODO: Continuously call stopwatch
}

//resetStopWatch, resets the stopwatch
void resetStopWatch() {
	stopwatch = 0;
	stopwatchRunning = false;
}

//pauseStopWatch, pauses the stopwatch
void pauseStopWatch() {
	stopwatchRunning = false;
}

//runStopWatch, runs the stopwatch
//STOPWATCH_DELAY
void runStopWatch() {
	if(stopwatchRunning) {
		stopwatch++;
	}
}

//getStopWatch, gets the current stopwatch value, ms
int getStopWatch() {
	return stopwatch;
}

void drawStopWatch(){
	const int START_X = 1;
	const int START_Y = 2;
	int time = getStopWatch();
	int hours = time / 3600000;
	int minutes = (time % 3600000) / 60000;
	int seconds = (time % 60000) / 1000;
	int ms = time % 1000;
	char *str;
	OrbitOledSetCursor(START_X, START_Y);
	if (hours){
		sprintf("%d:%d:%d:%d", str, hours, minutes, seconds, ms);
	}else if (minutes){
		sprintf("%d:%d:%d", str, minutes, seconds, ms);
	}else if (seconds){
		sprintf("%d:%d", str, seconds, ms);
	}else{
		sprintf("%d", str, ms);
	}
	OrbitOledPutString(str);
}

#endif // WATCH_H
