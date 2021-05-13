#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

using namespace std;

class Film
{
public:
	Film();
	Film(int ID, char* name, bool isAvailable, float price, int duration, int production_year, int age_recommendation, char* producer, char* genre);
	Film(const Film& other);
	virtual ~Film();
	 
	//getters
	int getID() const;
	char* getName() const;
	bool getValability() const;
	float getPrice() const;
	int getDuration() const;
	int getProductionYear() const;
	int getAgeRecommendation() const;
	char* getProducer() const;
	char* getGenre() const;

	//setters
	void setID(int ID);
	void setName(char* name);
	void setValability(bool isAvailable);
	void setPrice(float price);
	void setDuration(int duration);
	void setProductionYear(int production_year);
	void setAgeRecommendation(int age_recommendation);
	void setProducer(char* producer);
	void setGenre(char* genre);

	friend ostream& operator<<(ostream& os, Film&);
	friend istream& operator>>(istream& is, Film&);

private:
	int ID;
	char* name;
	bool isAvailable; 
	float price;
	int duration; //in minute
	int production_year;
	int age_recommendation; //min age the store recommends for someone to be able to watch the movie
	char* producer;
	char* genre;
};