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

	SunTracker(Sun& _sun, Cloud& _cloud);

	bool isDangerousAngle();
	void toModelMinute();

};

