#pragma once

#include "Film.h"

class Rentable : public Film
{
public:
	Rentable() : Film()
	{
		this->film_state = new char[50];
		this->min_rent_period = 0;
		this->max_rent_period = 0;
		this->damage_penalty = 0;
	}

	Rentable(int ID, char* name, bool isAvailable, float price, int duration, int production_year, int age_recommendation, char* producer, char* genre, char* film_state, int min_rent_period, int max_rent_period, float damage_penalty) : Film(ID, name, isAvailable, price, duration, production_year, age_recommendation, producer, genre)
	{
		char empty[] = "no state";

		this->film_state = new char[strlen(film_state) + 1];
		for (int i = 0; i < strlen(film_state); i++)
			this->film_state[i] = film_state[i];
		this->film_state[strlen(film_state)] = '\0';

		memcpy(this->film_state, empty, strlen(empty) + 1);

		this->min_rent_period = min_rent_period;
		this->max_rent_period = max_rent_period;
		this->damage_penalty = damage_penalty;
	}

	//getters
	char* getFilmState() const;
	int getMinRentPeriod() const;
	int getMaxRentPeriod() const;
	float getDamagePenalty() const;

	//setters
	void setFilmState(char* film_state);
	void setMinRentPeriod(int min_rent_period);
	void setMaxRentPeriod(int max_rent_period);
	void setDamagePenalty(float damage_penalty);

private:
	char* film_state; // in ce stare se afla filmul la momentul inchirierii
	int min_rent_period; //in zile
	int max_rent_period; //in zile
	float damage_penalty; //suma care trebuie platita in cazul in care clientul strica filmul pe perioada inchirierii
};
