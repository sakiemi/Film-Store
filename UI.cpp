#include "UI.h"
#include "Controller.h"
#include <iostream>
#include <string.h>
#include <cstdio>


constexpr auto MAX_NAME_LEN = 60;
constexpr auto MAX_BRAND_LEN = 60;
constexpr auto MAX_COLOR_LEN = 60;

using namespace std;

UI::UI(Controller& c) : m_controller{ c }
{}


void UI::addUI()
{
	int ID;
	char name[MAX_NAME_LEN], producer[MAX_BRAND_LEN], genre[MAX_COLOR_LEN];
	int production_year, duration, age_recommendation;
	float price;
	bool isAvailable;

	cout << "Please give the ID of the film: ";
	cin >> ID;
	char c;
	c = getchar();

	cout << "Please give the name of the film: ";
	cin.getline(name, MAX_NAME_LEN);

	cout << "Please give the valability of the film: \n 1- available \n 0- not available ";
	cin >> isAvailable;

	cout << "Please give the price of the film: ";
	cin >> price;

	cout << "Please give the duration on the film: ";
	cin >> duration;

	cout << "Please give the production year of the film: ";
	cin >> production_year;

	cout << "Please give the age recommendation of the film: ";
	cin >> age_recommendation;
	c = getchar();

	cout << "Please give the producer of the film: ";
	cin.getline(producer, MAX_BRAND_LEN);

	cout << "Please give the genre of the film: ";
	cin.getline(genre, MAX_COLOR_LEN);

	ofstream myFile;
	myFile.open("Films.csv");

	myFile << ID << "," << name << "," << isAvailable << "," << price <<duration << ","
		   << production_year << "," << age_recommendation << "," << producer << "," << genre << endl;
	

	cout << "Film was added succesfully!" << endl << endl;
	Film* a = new Film{ID, name, isAvailable, price, duration, production_year, age_recommendation, producer, genre};
	m_controller.addController(a);
}

void UI::deleteUI()
{
	int id;
	cout << "Please enter the id: ";
	cin >> id;
	m_controller.deleteController(id);

	cout << "The film was successfully deleted!" << endl;
}
void UI::displayAllUI()
{
	m_controller.displayAll();
}

void UI::displayByPriceUI()
{
	int price;
	cout << "Please give a price: ";
	cin >> price;
	m_controller.displayByPriceController(price);
	
	cout << "These are the films with prices bigger than: "<< price <<endl;
}

void UI::displayByProductionYearUI()
{
	int production_year;
	cout << "Please give a production year: ";
	cin >> production_year;
	m_controller.displayByProductionYearController(production_year);
}

void UI::displayByGenreUI()
{
	char genre[MAX_BRAND_LEN];
	cout << "Please give a genre: ";
	cin.getline(genre, MAX_BRAND_LEN);
	m_controller.displayByGenreController(genre);
}

void UI::showUI()
{
	char option;
	do {
		cout << "Please choose one of the following operations:" << endl;
		cout << "1 to add a product" << endl;
		cout << "2 to delete a product" << endl;
		cout << "3 to view the products" << endl;
		cout << "4 to display the films by a given production year" << endl;
		cout << "5 to display the films by a given price" << endl;
		cout << "6 to display the film by a given genre" << endl;
		cout << "7 to exit" << endl;

		cin >> option;
		switch (option)
		{
		default:
			break;
		case '1':
			addUI();
			break;
		case '2':
			deleteUI();
			break;
		case '3':
			m_controller.displayAll();
			break;
		case '4':
			displayByPriceUI();
			break;
		case '5':
			displayByProductionYearUI();
			break;
		case '6':
			displayByGenreUI();
			break;
		case '7':
			exit(0);
			break;
		}
	} while (true);
}