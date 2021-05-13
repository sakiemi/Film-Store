
#include "Repository.h"
#include <algorithm>
#include <functional>

using namespace std;

void Repository::addRepo(Film* t)
{
	m_repo.push_back(t);
}

Film* Repository::deleteRepo(int id)
{
	Film* t = nullptr;
	auto index = find_if(m_repo.begin(), m_repo.end(), [id](Film* t)->bool {
		return t->getID() == id;
		});
	if (index != m_repo.end())
	{
		t = *index;
		m_repo.erase(index);
	}
	return t;
}

ostream& Repository::display(ostream& os, Film* toy)
{
	return os << toy->getID() << " " << toy->getName() << " " << toy->getValability() << " " << toy->getPrice() << " " << toy->getDuration()
		<< " " << toy->getProductionYear() << " " << toy->getAgeRecommendation() << " " << toy->getProducer() << " " << toy->getGenre() << endl;
}

ostream& Repository::displayAll(ostream& os)
{
	for (auto i = 0; i < m_repo.size(); i++)
	{
		display(os, m_repo[i]);
	}
	return os;
}

ostream& Repository::displayPrice(ostream& os, int price)
{
	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (m_repo[i]->getPrice() <= price)
		{
			display(os, m_repo[i]);
		}
	}
	return os;

}

ostream& Repository::displayProductionYear(ostream& os, int production_year)
{
	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (m_repo[i]->getProductionYear() >= production_year)
		{
			display(os, m_repo[i]);
		}
	}
	return os;
}

ostream& Repository::displayGenre(ostream& os, char *genre)
{
	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (m_repo[i]->getGenre() == genre)
		{
			display(os, m_repo[i]);
		}
	}
	return os;
}
