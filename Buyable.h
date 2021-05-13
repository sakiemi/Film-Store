#pragma once

#include "Film.h"

class Buyable : public Film
{
public:
	Buyable() : Film()
	{
		this->warranty = 0;
		this->return_period = 0;
	}

	Buyable(int ID, char* name, bool isAvailable, float price, int duration, int production_year, int age_recommendation, char* producer, char* genre, int warranty, int return_period) : Film(ID, name, isAvailable, price, duration, production_year, age_recommendation, producer, genre)
	{
		this->warranty = warranty;
		this->return_period = return_period;
	}

	//getters
	int getWarrinty() const;
	int getReturnPeriod() const;

	//setters
	void setWarranty(int warranty);
	void setReturnPeriod(int return_period);


private:
	int warranty; //in zile
	int return_period; //in cate zile se poate returna filmul;
};
