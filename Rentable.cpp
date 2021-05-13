

#include "Rentable.h"

//getters
char* Rentable::getFilmState() const { return film_state; }
float Rentable::getDamagePenalty() const { return damage_penalty; }
int Rentable::getMinRentPeriod() const { return min_rent_period; }
int Rentable::getMaxRentPeriod() const { return max_rent_period; }

//setters
void Rentable::setFilmState(char* film_state) { this->film_state = film_state; }
void Rentable::setDamagePenalty(float damage_penalty) { this->damage_penalty = damage_penalty; }
void Rentable::setMinRentPeriod(int min_rent_period) { this->min_rent_period = min_rent_period; }
void Rentable::setMaxRentPeriod(int max_rent_period) { this->max_rent_period = max_rent_period; }
