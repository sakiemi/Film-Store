#pragma once
#include "Repository.h"
#include <stack>

enum class ActionType {
	ADD,
	REMOVE
};

using namespace std;
class Controller
{
public:
	Controller(Repository& r);

	void initialize();
	void writeToCSV();


	void addController(Film* t);
	void deleteController(int id);
	void displayByGenreController(char *genre);
	void displayByPriceController(int price);
	void displayByProductionYearController(int production_year);

	void displayAll();

private:
	Repository m_repo;
	std::stack<pair<ActionType, Film*>> m_undoStack;
	std::stack<pair<ActionType, Film*>> m_redoStack;
};

