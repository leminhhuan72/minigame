#include "obstacle.h"
#include "car.h"
#include "bird.h"
#include "bus.h"
#include "truck.h"
#include "dinosaur.h"

Obstacle::Obstacle()
{
}
Obstacle::Obstacle(Point loca, Point direction) :Entity(loca), direction(direction)
{
}

Obstacle::Obstacle(Point loca, Point direction, int tick_passed):Entity(loca), direction(direction), tick_passed(tick_passed)
{
}

Obstacle::~Obstacle()
{

}

void Obstacle::do_tick()
{
	move();
}

std::shared_ptr<Obstacle> Obstacle::Create(ObstacleType type, Point loca_obs, Point dir)
{
	switch (type) {
	case OT_Car: return std::make_shared<Car>(loca_obs, dir);
	case OT_Bus: return std::make_shared<Bus>(loca_obs, dir);
	case OT_Truck: return std::make_shared<Truck>(loca_obs, dir);
	case OT_Bird: return std::make_shared<Bird>(loca_obs, dir);
	case OT_Dinasour: return std::make_shared<Dinosaur>(loca_obs, dir);
	}
	return std::shared_ptr<Obstacle>();
}

void Obstacle::move()
{
	location += direction;
}

bool Obstacle::is_far_enough(Point p, int distance)
{
	if (abs(location.y - p.y) >= distance) return true;
	return false;
}

void Obstacle::export_to_file(std::ofstream & fo)
{
	fo << tick_passed << std::endl;
	fo << obs_type() << " ";
	location.export_to_file(fo);
	direction.export_to_file(fo);
}

std::shared_ptr<Obstacle> Obstacle::obs_import_from_file(std::ifstream & fi)
{
	int type, tick_passed;
	Point dir, loca_obs;
	fi >> tick_passed;
	fi >> type;
	loca_obs.import_from_file(fi);
	dir.import_from_file(fi);
	return Create(static_cast<ObstacleType>(type), loca_obs, dir);
}

