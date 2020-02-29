#pragma once

class Cloud
{
	double width;
	double y;
	double speed;
	double x;

public:
	Cloud();
	Cloud(double width, double y, double speed, double x);

	double getWidth();
	double getY();
	double getSpeed();
	double getX();
	void toModelMinute();

};
