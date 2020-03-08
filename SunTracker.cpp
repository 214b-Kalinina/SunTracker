#include "SunTracker.h"
#include "Sun.h"
#include "Cloud.h"

#include <math.h>


SunTracker::SunTracker(double cloud_width, double cloud_y, double cloud_speed, double cloud_x)
{
	this->sun = Sun();
	this->cloud = Cloud(cloud_width, cloud_y, cloud_speed, cloud_x);
}


double SunTracker::getAlphaAngle()
{
	double currentX = cloud.getX();
	double currentY = cloud.getY();

	double alpha = atan(currentY / currentX);

	alpha = (alpha < 0) ? -alpha : alpha;

	return alpha;
}


double SunTracker::getBetaAngle()
{
	double currentX = cloud.getX();
	double currentY = cloud.getY();
	double width = cloud.getWidth();

	double beta = atan(currentY / (currentX - width));

	beta = (beta < 0) ? -beta : beta;

	return beta;
}


bool SunTracker::isDangerous() 
{
	return (sun.getAngle() > getAlphaAngle()) && (sun.getAngle() < getBetaAngle());
}


void SunTracker::toModelMinute() 
{
	sun.toModelMinute();
	cloud.toModelMinute();
}


