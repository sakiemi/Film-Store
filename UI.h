#pragma once

#include "Stiva.h"
#include "Film.h"
#include "Buyable.h"
#include "Rentable.h"
#include "Controller.h"

#include <iostream>
#include <fstream>
using namespace std;

class UI
{
public:
	UI(Controller&);
	void addUI();
	void deleteUI();
	void displayAllUI();
	void displayByGenreUI();
	void displayByProductionYearUI();
	void displayByPriceUI();
	void redoUI();
	void undoUI();
	void showUI();

private:
	Controller m_controller;
};

