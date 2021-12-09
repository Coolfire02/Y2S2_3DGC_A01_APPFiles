/**
 RecoilEffect
 By: Toh Da Jun
 Date: Sep 2021
 */
#pragma once

// Include CCameraEffects
#include "CameraEffects.h"

// Include CCamera
#include "../Camera.h"

#include "../Entities/Player3D.h"

class RecoilEffect : public CCameraEffects
{
public:
	// Constructor
	RecoilEffect(void);
	// Destructor
	virtual ~RecoilEffect(void);

	// Initialise this class instance
	bool Init(void);

	// Override the SetStatus() from CEntity3D
	virtual void SetStatus(const bool bStatus);

	// Update this class instance
	virtual bool Update(const double dElapsedTime);

	// PreRender
	virtual void PreRender(void);
	// Render
	virtual void Render(void);
	// PostRender
	virtual void PostRender(void);

	void ProcessShot();
	void SetRecoilAttributes(float yAcceleration = 5.f, float xAcceleration = 1.f, float yRecoilMax = 2.0f, float xRecoilMax = 0.2f);

	// Boolean flag to indicate if this class is to be updated
	bool bToBeUpdated;

protected:
	// The handle to the camera instance
	CPlayer3D* cPlayer;

	float yRecoilAcceleration;
	float xRecoilAcceleration;

	float xRecoilMax;
	float yRecoilMax;

	float yRecoilMag;
	float xRecoilMag;

	double lastShot;
	double elapsed;
	float coolOffPeriod;

	bool bPrepareToStop;

};
