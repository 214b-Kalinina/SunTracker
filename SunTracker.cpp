#include "SunTracker.h"
#include "Sun.h"
#include "Cloud.h"

#include <math.h>


SunTracker::SunTracker(Sun& _sun, Cloud& _cloud)
{
	this->sun = _sun;
	this->cloud = _cloud;
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


bool SunTracker::isDangerousAngle() 
{
	return (sun.getAngle() > getAlphaAngle()) && (sun.getAngle() < getBetaAngle());
}


void SunTracker::toModelMinute() 
{
	sun.toModelMinute();
	cloud.toModelMinute();
}


