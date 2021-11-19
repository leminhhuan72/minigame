#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "Point.h"
#include <vector>
#include "pixel.h"
#include <string>
using namespace std;
class Entity {
	/*
	this class is an abstract class for all entities ( people and objects) in the screen 
	
	*/
protected:
	Point location; 
	vector<Pixel> pixels; 
public: 
	Entity() = default ;
	Entity(Point location);
	virtual ~Entity();
	bool collide(shared_ptr<Entity> other);
	virtual void load_icon(bool isFlipped = false);
	virtual string type_name() = 0;
	friend class Window;
	virtual void export_to_file(ofstream& out) = 0;
};

#endif 