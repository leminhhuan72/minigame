#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include "cAnimal.h"
class CVEHICLE {
	int mX, mY;
	
public:
	CVEHICLE();
	virtual void Move(int, int) = 0;

	
};

#endif // !1
