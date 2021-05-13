#include "Film.h"
#include <iostream>
using namespace std;

Film::Film()
{
	this->ID = 0;
	this->name = new char[50];
	this->isAvailable = false;
	this->price = 0;
	this->duration = 0;
	this->production_year = 0;
	this->age_recommendation = 0;
	this->producer = new char[20];
	this->genre = new char[20];
}

Film::Film(int ID, char* name, bool isAvailable, float price, int duration, int production_year, int age_recommendation, char* producer, char* genre)
{
	this->ID = ID;

	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name); i++)
		this->name[i] = name[i];
	this->name[strlen(name)] = '\0';

	this->isAvailable = isAvailable;
	this->price = price;
	this->duration = duration;
	this->production_year = production_year;
	this->age_recommendation = age_recommendation;
	
	this->producer = new char[strlen(producer) + 1];
	for (int i = 0; i < strlen(producer); i++)
		this->producer[i] = producer[i];
	this->producer[strlen(producer)] = '\0';

	this->genre = new char[strlen(genre) + 1];
	for (int i = 0; i < strlen(genre); i++)
		this->genre[i] = genre[i];
	this->genre[strlen(genre)] = '\0';
}

Film::Film(const Film& other)
{
	this->ID = other.ID;

	this->name = new char[strlen(other.name) + 1]; // \0
	for (int i = 0; i < strlen(other.name); i++)
		this->name[i] = other.name[i];
	this->name[strlen(other.name)] = '\0';


	this->isAvailable = other.isAvailable;
	this->price = other.price;
	this->duration = other.duration;
	this->production_year = other.production_year;
	this->age_recommendation = other.age_recommendation;

	this->producer = new char[strlen(other.producer) + 1]; // \0
	for (int i = 0; i < strlen(other.producer); i++)
		this->producer[i] = other.producer[i];
	this->producer[strlen(other.producer)] = '\0';

	this->genre = new char[strlen(other.genre) + 1]; // \0
	for (int i = 0; i < strlen(other.genre); i++)
		this->genre[i] = other.genre[i];
	this->genre[strlen(other.genre)] = '\0';

}

Film::~Film()
{
	delete[] name;
	delete[] producer;
	delete[] genre;
}

//getters

int Film::getID() const{ return ID; }
char* Film::getName() const { return name; }
bool Film::getValability() const { return isAvailable; }
float Film::getPrice() const { return price; }
int Film::getDuration() const { return duration; }
int Film::getProductionYear() const { return production_year; }
int Film::getAgeRecommendation() const { return age_recommendation; }
char* Film::getProducer() const { return producer; }
char* Film::getGenre() const { return genre; }


//setters
void Film::setID(int ID){ this->ID = ID; }
void Film::setName(char* name) { this->name = name; }
void Film::setValability(bool isAvailable) { this->isAvailable = isAvailable; }
void Film::setPrice(float price) { this->price = price; }
void Film::setProductionYear(int production_year) { this->production_year = production_year; }
void Film::setDuration(int duration) { this->duration = duration; }
void Film::setAgeRecommendation(int age_recommendation) { this->age_recommendation = age_recommendation; }
void Film::setProducer(char* producer) { this->producer = producer; }
void Film::setGenre(char* genre) { this->genre = genre; }

ostream& operator<<(ostream& os, Film& t)
{
	os << t.ID << t.name << t.isAvailable << t.price << t.production_year << t.duration << t.age_recommendation << t.producer << t.genre;
	os << endl;
	return os;
}

istream& operator>>(istream& is, Film& t)
{
	is >> t.ID >> t.name >> t.isAvailable >> t.price >> t.production_year >> t.duration >> t.age_recommendation >> t.producer >> t.genre;

	return is;
}
