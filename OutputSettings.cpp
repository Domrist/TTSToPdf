#include "OutputSettings.h"



bool OutputSettings::isValid() const
{
	return true;
	if (cardH == 0 || cardW == 0)
	{
		return false;
	}

	return true;
}
