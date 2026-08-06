#pragma once



struct OutputSettings
{
	bool isValid() const;

	double cardW{40};
	double cardH{60};

	int cardCountMaxX{10};
	int cardCountMaxY{7};

	int rowCountPerPage{3};
	int columnCountPerPage{3};

	int margin{0};

	bool isPortraitOrientation{true};
};
