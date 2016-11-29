//! @file 
//! @brief Header file for the Item class  
//!
#ifndef Item_h
#define Item_h

#include <string>
using namespace std;

enum iType
{
	I_NONE = 0,
	HELMET = 1,
	ARMOR = 2,
	SHIELD = 3,
	RING = 4,
	BELT = 5,
	BOOTS = 6,
	WEAPON = 7
};

//! class for the implementation of items wearable by a character
class Item
{
    friend std::ostream& operator<<(std::ostream& os, Item const& item);
    friend std::istream& operator>>(std::istream& is, Item & item);
    
public:
	// Default constructor
	Item();
	// Constructor
	Item(string, iType, int, int, int, int, int, int, int, int, int);
	
	//getters
	iType getType();
	string getName();

	//getters for abilityscores and modifiers
	int getStr();
	int getDex();
	int getCon();
	int getIntel();
	int getWis();
	int getCha();
	int getArmor();
	int getAtk();
	int getDmg();
	int* getEnhances();

	//setters
	void setName(string);
	void setType(iType);

	//setters for abilityscores and modifiers
	void setStr(int);
	void setDex(int);
	void setCon(int);
	void setIntel(int);
	void setWis(int);
	void setCha(int);
	void setArmor(int);
	void setAtk(int);
	void setDmg(int);
	
	//to_string;
	void to_string();

	//saving an item to a file
	void saveItem(string);

	//loading an item from a file
	void loadItem(string);

	//validate item
	bool validateItem();


private:
	string i_name;
	iType i_type;
	int i_enhances[9];
};
#endif

