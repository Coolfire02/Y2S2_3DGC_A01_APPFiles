/**
 CCrossHair
 By: Toh Da Jun
 Date: Sep 2021
 */
#include "CrossHair.h"

 // Include GLEW
#ifndef GLEW_STATIC
#define GLEW_STATIC
#include <GL/glew.h>
#endif

// Include ShaderManager
#include "RenderControl/ShaderManager.h"

// Include ImageLoader
#include "System\ImageLoader.h"

// Include MeshBuilder
#include "Primitives/MeshBuilder.h"

#include <iostream>
using namespace std;

/**
 @brief Default Constructor
 */
CCrossHair::CCrossHair(void)
{
}

/**
 @brief Destructor
 */
CCrossHair::~CCrossHair(void)
{
}

/**
 @brief Initialise this class instance
 @return true is successfully initialised this class instance, else false
 */
bool CCrossHair::Init(void)
{
	// Call the parent's Init()
	CCameraEffects::Init();

	// Set the type
	SetType(CEntity3D::TYPE::OTHERS);

	transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

	float fAspectRatio = (float)cSettings->iWindowWidth / (float)cSettings->iWindowHeight;

	// Generate and bind the VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Generate the mesh
	mesh = CMeshBuilder::GenerateQuad(glm::vec4(1, 1, 1, 1), 0.1f, fAspectRatio*0.1);

	// load and create a texture 
	iTextureID = 0;

	bStatus = true;

	return true;
}

bool CCrossHair::SetCrosshair(CROSSHAIR_TYPE type)
{
	if (type != crosshairtype)
	{
		cout << "Set crosshair" << endl;
		crosshairtype = type;

		switch (type)
		{
		case PISTOL_CROSSHAIR:
			iTextureID = CImageLoader::GetInstance()->LoadTextureGetID("Image/GUI/CameraEffects_CrossHair_Pistol.tga", true);
			break;
		case RIFLE_CROSSHAIR:
			iTextureID = CImageLoader::GetInstance()->LoadTextureGetID("Image/GUI/CameraEffects_CrossHair_Rifle.tga", true);
			break;
		case SNIPER_SCOPE:
			iTextureID = CImageLoader::GetInstance()->LoadTextureGetID("Image/GUI/CameraEffects_CrossHair.tga", true);
			break;
		default:
			iTextureID = 0;
		}

		return true;
	}

	return false;
}

/**
 @brief Update the elapsed time
 @param dt A const double variable containing the elapsed time since the last frame
 @return A bool variable
 */
bool CCrossHair::Update(const double dElapsedTime)
{
	return true;
}
