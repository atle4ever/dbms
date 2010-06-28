#ifndef __TIMER_H__
#define __TIMER_H__

#include <sys/time.h>

//----------------------------------------------------------
// Timer
//----------------------------------------------------------

class Timer {
public:
	Timer() { reset(); }
	void reset() {
		elapsed = 0;
		paused = true;
	}
	void start() {
		gettimeofday(&s, 0);
		paused = false;
	}
	suseconds_t stop() {
		if (!paused) {
			timeval e;
			gettimeofday(&e, 0);
			elapsed += (e.tv_sec - s.tv_sec) * 1000000
					+ e.tv_usec - s.tv_usec;
			paused = true;
		}
		return elapsed;
	}
private:
	timeval s;
	suseconds_t elapsed;
	bool paused;
};

#endif // __TIMER_H__
