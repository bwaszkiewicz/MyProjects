#include "MainLoop.h"
#include <vld.h>

int main()
{
srand(time(nullptr));
try {
	MainLoop Game;
	Game.loop();
}
catch (NoIconButtonTextureException){ }
catch (NoTextButtonFontException){ }
catch (DataAccessViolationException){ }
catch (InvalidBuildingTypeException){ }
catch (InvalidUnitTypeException){ }
catch (InvalidResourcesTypeException) { }
catch (NoShapeMapLoadFontException) { }
catch (InvalidEventIDException) { }
catch (NoBuildingsWindowFrameException) { }
catch (NoEventBarFontException) { }
catch (NoIconTextureException) { }
catch (NoTextInputFontException) { }
catch (InvalidEventTierException) { }
catch (...)
{
	std::cout << "Nieznany blad" << std::endl;
}
}