/**
 RecoilEffect
 By: Toh Da Jun
 Date: Sep 2021
 */
#include "RecoilEffect.h"

 // Include GLEW
#ifndef GLEW_STATIC
#define GLEW_STATIC
#include <GL/glew.h>
#endif

// Include math.h
#include <math.h>

#include <iostream>
using namespace std;

/**
 @brief Default Constructor
 */
RecoilEffect::RecoilEffect(void)
	: cPlayer(NULL)
	, bToBeUpdated(false)
{

}

/**
 @brief Destructor
 */
RecoilEffect::~RecoilEffect(void)
{
	cPlayer = NULL;
}

void RecoilEffect::SetRecoilAttributes(float yAcceleration, float xAcceleration, float yRecoilMax, float xRecoilMax)
{
	this->yRecoilAcceleration = yAcceleration;
	this->xRecoilAcceleration = xAcceleration;
	this->yRecoilMax = yRecoilMax;
	this->xRecoilMax = xRecoilMax;
}

/**
 @brief Initialise this class instance
 @return true is successfully initialised this class instance, else false
 */
bool RecoilEffect::Init(void)
{
	// Call the parent's Init()
	CCameraEffects::Init();

	// Set the type
	SetType(CEntity3D::TYPE::OTHERS);

	this->yRecoilAcceleration = 5;
	this->xRecoilAcceleration = 2;
	this->yRecoilMax = 3.0f;
	this->xRecoilMax = 0.7f;

	

	yRecoilMag = xRecoilMag = 0.f;
	lastShot = 0.0;
	elapsed = 0.0;

	//How long before recoil resets gradually
	coolOffPeriod = 0.1f;

	// Store the camera's instance to this handle
	cPlayer = CPlayer3D::GetInstance();

	transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

	return true;
}

/**
 @brief Override the SetStatus() from CEntity3D
 @param bStatus A const bool variable containing the new status
 */
void RecoilEffect::SetStatus(const bool bStatus)
{
	if (bStatus == true)
	{
		// If bStatus is true, then just assign to this->bStatus
		this->bStatus = bStatus;
	}
	else
	{
		// If bStatus is true, then just assign to this->bStatus
		bPrepareToStop = true;
	}
}

void RecoilEffect::ProcessShot()
{
	lastShot = elapsed;
	//When one shot is triggered here, update all the values

	yRecoilMag += yRecoilAcceleration;
	xRecoilMag += xRecoilAcceleration;

	if (xRecoilMag > xRecoilMax)
		xRecoilMag = xRecoilMax;
	if (yRecoilMag > yRecoilMax)
		yRecoilMag = yRecoilMax;

	float xAdd = xRecoilMag;
	if (rand() % 2 == 0) xAdd = -xAdd;

	float yAdd = yRecoilMag;
	if (rand() % 10 >= 8) yAdd = -yAdd;

	cPlayer->ProcessRotate(xAdd,yAdd);
	
}

/**
 @brief Update the elapsed time
 @param dt A const double variable containing the elapsed time since the last frame
 @return A bool variable
 */
bool RecoilEffect::Update(const double dElapsedTime)
{
	elapsed += dElapsedTime;
	if ((!bStatus) || (!bToBeUpdated))
		return false;

	if (lastShot + coolOffPeriod < elapsed)
	{
		yRecoilMag -= yRecoilMag * dElapsedTime;
		xRecoilMag -= xRecoilMag * dElapsedTime;

		
	}

	// Update fAngle
	

	// Set to false since we have already updated camera shake
	bToBeUpdated = false;


	return true;
}


/**
 @brief PreRender Set up the OpenGL display environment before rendering
 */
void RecoilEffect::PreRender(void)
{
	if (!bStatus)
		return;
}

/**
 @brief Render this instance
 */
void RecoilEffect::Render(void)
{
	if (!bStatus)
		return;
}

/**
 @brief PostRender Set up the OpenGL display environment after rendering.
 */
void RecoilEffect::PostRender(void)
{
	if (!bStatus)
		return;
}
