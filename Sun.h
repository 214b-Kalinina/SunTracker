#pragma once

class Sun
{
	double radius;
	double angle;

public:
	Sun();
	Sun(double radius);

	double getAngle();
	double getRadius();
	void toModelMinute();

};

