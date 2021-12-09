#pragma once

#include <string>
#include "../Library/Source/Primitives/Entity3D.h"

// Include GLM
#include <includes/glm.hpp>
#include <includes/gtc/matrix_transform.hpp>
#include <includes/gtc/type_ptr.hpp>

// Include CShaderManager
#include "RenderControl/ShaderManager.h"


class Item : public CEntity3D
{
public:
	enum ITEM_TYPE
	{
		PRIMARY_WEAPON,
		SECONDARY_WEAPON,
		LANDMINE,
		GRENADE,
	};

	int getQuantity();
	void setQuantity(int amt);
	void changeQuantityBy(int change);

	ITEM_TYPE getItemType();
	void setDisplayName(std::string display);
	std::string getDisplayName();

	// PreRender
	virtual void PreRender(void);
	// Render
	virtual void Render(void);
	// PostRender
	virtual void PostRender(void);

	Item(ITEM_TYPE type, std::string displayName);
	Item();
	bool Init();
	~Item();

private:
	std::string displayName;
	ITEM_TYPE itemType;
	int quantity;

	// For Renderings
	unsigned int iIndicesSize;
};
