#ifndef _PEOPLE_H_
#define _PEOPLE_H_
#include "Entity.h"
class people: public Entity{
	bool isDead; //Trạng thái sống chết
public:
	people();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};

#endif // !1
