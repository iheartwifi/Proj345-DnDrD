//! @file 
//! @brief IMplementation file for the ItemContainer class  
//!

#include "ItemContainer.h"
#include <iostream>
#include <string>
#include<vector>
#include "Item.h"
#include <fstream>
using namespace std;

//! default constructor
ItemContainer::ItemContainer()
{
	c_name = "";
	//c_type = C_NONE;
	v_items = vector<Item>();
}

//constructor with param
/*
ItemContainer::ItemContainer(string cont_name, cType cont_type, vector<Item> vector_items)
{
	c_name = cont_name;
	c_type = cont_type;
	v_items = vector_items;
}
*/
ItemContainer::ItemContainer(string cont_name, vector<Item> vector_items)
{
	c_name = cont_name;
	v_items = vector_items;
}

//get vector of items
vector<Item> ItemContainer::getItems()
{
	return v_items;
}

//! method to add an item to the item container
void ItemContainer::addItem(Item anitem)
{
	v_items.push_back(anitem);
}

//! method to remove the last item in the item container
void ItemContainer::removeItem()
{
	v_items.pop_back();
}

//place an item at specific index
void ItemContainer::setItem(int index, Item it)
{
	v_items[index] = it;
}

//get an single item
Item ItemContainer::getItem(int i)
{
		return v_items[i];
}

//get name
string ItemContainer::getName()
{
	return c_name;
}

//get type
/*
cType ItemContainer::getType()
{
	return c_type;
}
*/

//set name
void ItemContainer::setName(string cont_name)
{
	c_name = cont_name;
}

//set type
/*
void ItemContainer::setType(cType c_type)
{
	c_type = c_type;
}
*/

//set a vector of items
void ItemContainer::setItems(vector<Item> vitems)
{
	v_items = vitems;
}

//to_string
void ItemContainer::to_string()
{
	cout << "\nItemContainer_Name: " << c_name << endl;
	//cout << "ItemContainer_Type: " << c_type << endl;
	for (int i = 0; i < v_items.size(); i++)
	{
		cout << "\nItem [" << i << "]" << endl;
		v_items[i].to_string();
	}
}

//save Container
void ItemContainer::saveContainer(string filename)
{
	ofstream save;
	save.open("ItemContainer/"+filename + ".txt");

	save << c_name << endl;
	
	for (int i = 0; i < v_items.size(); i++)
	{
		save << v_items[i].getName() << endl;
	}
		
	save.close();
	cout << "Saving container..." << endl << endl;
}

//load Container
void ItemContainer::loadContainer(string filename)
{
	string buffer, itemname;
	Item it;
	ifstream load;
	load.open("ItemContainer/"+filename + ".txt");

	getline(load, c_name);
	

	while (load >> itemname)
	{		
		it.loadItem(itemname);
		v_items.push_back(it);
	}

	load.close();
	cout << "Loading container..." << endl << endl;
}

//take all item from a container
void ItemContainer::takeAll(ItemContainer chest)
{
	for (int i = 0; i < chest.v_items.size(); i++)
	{
		v_items.push_back(chest.v_items[i]);
		
	}
}
