#pragma once
#include <iostream>

class item
{
private:

	int SKU;
	std::string description;
	double price;
	std::string UOM;
	int quantityOnHand;
	int leadTime;

public:



	item(int num, std::string desc, double p, std::string units, int quantity)
	{
		SKU = num;
		description = desc;
		price = p;
		UOM = units;
		quantityOnHand = quantity;
	}

	item(int num, std::string desc, double p,std::string units)
	{
		SKU = num;
		description = desc;
		price = p;
		UOM = units;
		quantityOnHand = 0;
	}

	item()
	{
		SKU = 0;
		description = "";
		price = 0.0;
		UOM = "";
		quantityOnHand = 0;
	}

	std::string getPartInfo()
	{
		std::string info;
		info = "SKU: " + SKU;
		info += " Description: " + description;
		return info;
	}

	int getSKU()
	{
		return SKU;
	}
	double getPrice()
	{
		return price;
	}

	bool inStock()
	{
		if (quantityOnHand > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator< (const item& a)
	{
		return (SKU< a.SKU);
	}

	bool operator> (const item& a)
	{
		return (SKU > a.SKU);
	}

	bool operator== (const item& b)
	{
		return (SKU == b.SKU);
	}
};
