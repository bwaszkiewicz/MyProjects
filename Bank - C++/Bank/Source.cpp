//#include <vld.h>
#include "Menu.h"
#include "DatabaseLoader.h"

int main() {
	srand(time(0));
	Database Data;
	DatabaseLoader Loader(Data, CurrentMode);
	Loader.Initialize();
	Menu oMenu(Data);
	oMenu.ChangingMenu();
}