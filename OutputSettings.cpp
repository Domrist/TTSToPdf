#include "OutputSettings.h"



void OutputSettings::setOrientation(int a_orientation)
{
	// do some stuff
}



bool OutputSettings::isValid() const
{
	return true;
	if (_cardH == 0 || _cardW == 0)
	{
		return false;
	}

	return true;
}
