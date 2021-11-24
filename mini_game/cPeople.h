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
	
	bool isFinish();
	bool isDead();
	~people();
	string type_name();
};

#endif // !1
