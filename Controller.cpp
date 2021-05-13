#include "Controller.h"
#include <iostream>

Controller::Controller(Repository& r)
{
	m_repo = r;
}


void Controller::initialize()
{
	std::string CSVfile = "Films.csv";
	m_repo.loadFromCSV(CSVfile);
}

void Controller::writeToCSV()
{
	string CSVfile = "Films.csv";
	m_repo.writeToCSV(CSVfile);
}

void Controller::addController(Film* a)
{
	m_repo.addRepo(a);
	m_undoStack.push(std::make_pair(ActionType::ADD, a));
}

void Controller::deleteController(int id)
{
	Film* a = m_repo.deleteRepo(id);
	if (a)
		m_undoStack.push(std::make_pair(ActionType::REMOVE, a));
}


void Controller::displayByPriceController(int price)
{
	m_repo.displayPrice(std::cout, price);
}

void Controller::displayByProductionYearController(int production_year)
{
	m_repo.displayProductionYear(std::cout, production_year);
}

void Controller::displayByGenreController(char *genre)
{
	m_repo.displayGenre(std::cout, genre);
}

void Controller::displayAll()
{
	m_repo.displayAll(std::cout);
}
