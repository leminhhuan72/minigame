
#ifndef _BIRD_H_
#define _BIRD_H_
#include "Objects.h"
class bird: public Objects {
	
	
public:
	bird();
	bird(Point loca, Point dir);
	bird(Point loca, Point direction, int tick_passed);
	~bird();
	string type_name();
	int obs_type();
	void die();
};

#endif // !1
