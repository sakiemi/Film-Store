#pragma once
#include "Film.h"
#include <vector>
#include <fstream>
#include <iostream>

class Repository
{
public:
	void addRepo(Film* t);
	Film* deleteRepo(int id);

	ostream& display(ostream& os, Film* film);

	ostream& displayAll(ostream& os);
	ostream& displayPrice(ostream& os, int price);
	ostream& displayGenre(ostream& os, char *genre);
	ostream& displayProductionYear(ostream& os, int production_year);

	void loadFromCSV(const string& csvFilepath)
	{

		ifstream f;
		f.open(csvFilepath);


		if (!f.is_open())     //if the file can't be opened(doesn't exist) then it creates it
		{
			ofstream g;
			g.open(csvFilepath);
			//f.open(csvFilepath);
		}
		else
		{

			while (!f.eof())       //reads the data from the CSV file and keeps it in the repo
			{
				Film* arch = new Film;
				f >> *arch;
				m_repo.push_back(arch);
			}
		}

		f.close();
	}

	void writeToCSV(string csvFilepath)
	{

		ofstream g;
		g.open(csvFilepath);

		if (m_repo.size() > 0)
		{
			g << *m_repo[0];
			for (int i = 1; i < m_repo.size(); i++)       //overwrites the CSV file with the current repository data
			{
				g << endl << *m_repo[i];
			}
		}
		else
			g << "";

		g.close();

	}


private:
	vector<Film*> m_repo;
};

