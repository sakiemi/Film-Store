#include "UI.h"
#include "Controller.h"
#include "Repository.h"



int main() {
	
	Repository repo;
	Controller controller{ repo };
	UI ui{ controller };

	ui.showUI();

	return 0;
}

