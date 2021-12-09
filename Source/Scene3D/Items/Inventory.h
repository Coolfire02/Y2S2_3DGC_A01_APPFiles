#pragma once

// Include SingletonTemplate
#include "DesignPatterns\SingletonTemplate.h"

// Include GLM
#include <includes/glm.hpp>
#include <includes/gtc/matrix_transform.hpp>
#include <includes/gtc/type_ptr.hpp>

#include "Items/Item.h"

#include <vector>



// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Inventory : public CSingletonTemplate<Inventory>
{
	friend class CSingletonTemplate<Inventory>;

public:
	Item* addItem(Item* item);
	int getQuantity(Item::ITEM_TYPE type);
	Item* getItem(Item::ITEM_TYPE);

	Item* getHeldItem();
	void selectItem(Item::ITEM_TYPE item);
	


	void Update();

	

protected:
	std::vector<Item*> items;
	int index;

	Inventory();
	~Inventory();
};
