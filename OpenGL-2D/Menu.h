#pragma once

class Menu {

	int m_state;

public:
	Menu();
	~Menu();

	int getState();
	void setState(int state);

};
