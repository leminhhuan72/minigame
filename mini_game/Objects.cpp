#include "Objects.h"
Obstacle::Obstacle()
{
}
Obstacle::Obstacle(Point loca, Point direction) :Entity(loca), direction(direction)
{
}

Obstacle::Obstacle(Point loca, Point direction, int tick_passed) : Entity(loca), direction(direction), tick_passed(tick_passed)
{
}

Obstacle::~Obstacle()
{

}