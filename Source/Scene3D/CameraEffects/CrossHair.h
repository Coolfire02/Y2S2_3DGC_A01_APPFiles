/**
 CCrossHair
 By: Toh Da Jun
 Date: Sep 2021
 */
#pragma once

// Include CCameraEffects
#include "CameraEffects.h"

class CCrossHair : public CCameraEffects
{
public:

	enum CROSSHAIR_TYPE
	{
		PISTOL_CROSSHAIR,
		RIFLE_CROSSHAIR,
		SNIPER_SCOPE,
		NONE
	};

	bool SetCrosshair(CROSSHAIR_TYPE type);

	CROSSHAIR_TYPE crosshairtype;

	// Constructor
	CCrossHair(void);
	// Destructor
	virtual ~CCrossHair(void);

	// Initialise this class instance
	bool Init(void);

	// Update this class instance
	virtual bool Update(const double dElapsedTime);
};
