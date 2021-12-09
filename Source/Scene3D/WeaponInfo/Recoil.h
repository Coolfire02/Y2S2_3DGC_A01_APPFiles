#pragma once

// Include GLM
#include <includes/glm.hpp>

#include "../Camera.h"

#include "../CameraEffects/CameraEffectsManager.h"


class Recoil
{
	CCameraEffectsManager* cem_manager;



public:
	void ProcessShot();
	void Update(double dt);
	void Init();

	Recoil(float yAcceleration = 0.5f, float xAcceleration = 0.1f, float yRecoilMax = 2.0f, float xRecoilMax = 0.2f);
	~Recoil();

};

