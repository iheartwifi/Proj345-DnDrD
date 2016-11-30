#include "InventoryPanel.h"

#include "ItemContainer.h"
#include <iostream>
#include <string>
#include<vector>
#include "Item.h"
#include <fstream>
using namespace std;

//! default constructor
InventoryPanel::InventoryPanel() : ItemContainer()
{
	
	c_name = "";
	
	v_items = vector<Item>(7);
	
}

//constructor with param
InventoryPanel::InventoryPanel(string IP_name, vector<Item> vitems) : ItemContainer(IP_name, vitems)
{}


// equip(ItemContainer)
void InventoryPanel::equip(int index, ItemContainer &ic)
{
	switch (ic.getItems()[index].getType())
	{
	case HELMET:
	{
		Item temp;
		temp = v_items[0];
		v_items[0] = ic.getItems()[index];
		ic.setItem(index, temp);
		break;
	}

	case ARMOR:
	{
		Item temp;
		temp = v_items[1];
		v_items[1] = ic.getItems()[index];
		ic.setItem(index, temp);
		break;
	}

	case RING:
	{
		Item temp;
		temp = v_items[2];
		v_items[2] = ic.getItems()[index];
		ic.setItem(index, temp);
		break;
	}

	case BELT:
	{
		Item temp;
		temp = v_items[3];
		v_items[3] = ic.getItems()[index];
		ic.setItem(index, temp);
		break;
	}

	case BOOTS:
	{
		Item temp;
		temp = v_items[4];
		v_items[4] = ic.getItems()[index];
		ic.setItem(index, temp);
		break;
	}

	case WEAPON:
	{
		Item temp;
		temp = v_items[5];
		v_items[5] = ic.getItems()[index];
		ic.setItem(index, temp);
		break;
	}

	case SHIELD:
	{
		Item temp;
		temp = v_items[6];
		v_items[6] = ic.getItems()[index];
		ic.setItem(index, temp);
		break;
	};
		
	default:
		break;
	}
}

bool InventoryPanel::validateIP()
{
	bool b = true;
	if (v_items.size() <= 7)
	{
		for (int i=0; i < v_items.size(); i++)
		{
			for (int j = i + 1; j < v_items.size() - 1; j++)
			{
				if (v_items[j].getType() == v_items[i].getType())
				{
					b = false;
					break;
				}
			}

		}

	}
	else if (v_items.size() > 7)
		b = false;

	return b;
}

void InventoryPanel::loadContainer(string filename)
{
    string buffer, itemname;
    Item it;
    ifstream load;
    load.open("InventoryPanel/"+filename + ".txt");
    
    getline(load, c_name);
    
    
    while (load >> itemname)
    {
        it.loadItem(itemname);
        v_items.push_back(it);
    }
    
    load.close();
    cout << "Loading container..." << endl << endl;
}

void InventoryPanel::saveIP(string filename)
{
	if (validateIP() == true)
	{
		saveContainer(filename);
	}
	else
		cout << "InventoryPanel is not valid!!! Failed to save.... " << endl;
}
