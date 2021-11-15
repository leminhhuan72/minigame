#ifndef _PEOPLE_H_
#define _PEOPLE_H_

class CPEOPLE {
	int mX, mY;
	bool mState; //Trạng thái sống chết
public:
	CPEOPLE();
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
