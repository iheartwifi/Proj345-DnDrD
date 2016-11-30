#ifndef InventoryPanel_h
#define InventoryPanel_h

#include <iostream>
#include <string>
#include<vector>
#include "Item.h"
#include "ItemContainer.h"
using namespace std;

class InventoryPanel: public ItemContainer
{
public:
	//constructors
	InventoryPanel();	
	InventoryPanel(string, vector<Item>);

	//equip item
	void equip(int, ItemContainer&);

	

	//validate IP
	bool validateIP();

	//save IP
	void saveIP(string);
    void loadContainer(string);

	
};


#endif
