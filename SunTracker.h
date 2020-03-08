#pragma once

#include "Sun.h"
#include "Cloud.h"

class SunTracker
{
	Sun sun;
	Cloud cloud;

	double getAlphaAngle();
	double getBetaAngle();

public:

	SunTracker(double cloud_width, double cloud_y, double cloud_speed, double cloud_x);

	bool isDangerous();
	void toModelMinute();

};

