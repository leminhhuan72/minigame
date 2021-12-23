#pragma once

#include "pixel.h"
#include <vector>
#include <string>
#include <memory>

class Entity {
public:
	Entity();
	Entity(Point loca);
	virtual ~Entity();
	bool collide(std::shared_ptr<Entity> other);
	virtual void load_icon(bool isFlipped = false);
	virtual std::string type_name() = 0;
	friend class Window;
	virtual void export_to_file(std::ofstream& fo) = 0;
protected:
	Point location = { 0, 0 };
	std::vector<Pixel> pixels;
};
