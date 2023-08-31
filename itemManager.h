#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "item.h"

class ItemManager
{
public:
	bool checkID(string& ID1);
	bool IDexist(string& ID2);
	int AddItem(Item* item);
	void ViewItem();
	int editIName(string& itemID, string& itemName);
	int editIPrice(string& itemID, double& itemPrice);
	int editIIngredients(string& itemID, string& itemIngredients);
	int editIType(string& itemID, string& itemType);
	int DeleteItem(string& ID);
};


#endif
