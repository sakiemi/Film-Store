// not finished - still working on it

#include "Buyable.h"

//getters

int Buyable::getWarrinty() const { return warranty; }
int Buyable::getReturnPeriod() const { return return_period; }

//setters

void Buyable::setWarranty(int warranty) { this->warranty = warranty; }
void Buyable::setReturnPeriod(int return_period) { this->return_period = return_period; }