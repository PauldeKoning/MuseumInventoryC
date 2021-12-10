#pragma once
#include <string>
#include "Inspection.h"
class Item
{
private:
	std::string name;
	std::string description;
	std::string date;
	std::string region;
	Inspection inspection;
public:
	Item(std::string name, std::string description, std::string date, std::string region, Inspection inspection)
	{
		this->name = name;
		this->description = description;
		this->date = date;
		this->region = region;
		this->inspection = inspection;
	}

	Item(std::string name, std::string description, std::string date, std::string region)
	{
		this->name = name;
		this->description = description;
		this->date = date;
		this->region = region;
		this->inspection = new Inspection;
	}

	virtual std::string getName()
	{
		return this->name;
	};

	virtual void setName(std::string name)
	{
		this->name = name;
	};


	virtual std::string getDescription()
	{
		return this->description;
	};

	virtual void setDescription(std::string description)
	{
		this->description = description;
	};


	virtual std::string getDate()
	{
		return this->date;
	};

	virtual void setDate(std::string date)
	{
		this->date = date;
	};

	virtual std::string getRegion()
	{
		return this->region;
	};

	virtual void setRegion()
	{
		this->region = region;
	};


	virtual Inspection getInspection()
	{
		return this->inspection;
	};

	virtual void setInspection(Inspection inspection)
	{
		this->inspection = inspection;
	};
};

