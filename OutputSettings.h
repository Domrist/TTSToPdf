#pragma once



class OutputSettings
{
public:

	void setOrientation(int a_orientation);
	bool isValid() const;

private:

	double _cardW{0};
	double _cardH{0};

	int _margin{0};

	bool _isPortraitOrientation{true};
};
