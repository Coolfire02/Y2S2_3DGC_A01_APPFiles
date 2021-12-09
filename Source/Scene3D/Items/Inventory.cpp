#include "Inventory.h"

#include <iostream>
using namespace std;

Item* Inventory::addItem(Item* item)
{
	for (auto& loopitem : items)
	{
		if (loopitem->getItemType() == item->getItemType())
		{
			loopitem->changeQuantityBy(item->getQuantity());
			delete item;
			return loopitem;
		}
	}
	//Else couldnt find same item type
	items.push_back(item);
}

int Inventory::getQuantity(Item::ITEM_TYPE type)
{
	for (auto& loopitem : items)
	{
		if (loopitem->getItemType() == type)
		{
			return loopitem->getQuantity();
		}
	}
	return 0;
}

Item* Inventory::getItem(Item::ITEM_TYPE type)
{
	for (auto& loopitem : items)
	{
		if (loopitem->getItemType() == type)
		{
			return loopitem;
		}
	}
	return NULL;
}

Item* Inventory::getHeldItem()
{
	return nullptr;
}

void Inventory::selectItem(Item::ITEM_TYPE item)
{
	

}

void Inventory::Update()
{

}

Inventory::Inventory()
{
	index = 0;
}

Inventory::~Inventory()
{

}
