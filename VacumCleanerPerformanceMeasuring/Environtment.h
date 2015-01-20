#pragma once

#ifndef _CLASS_ENVIRONTMENT_
#define _CLASS_ENVIRONTMENT_
class Environtment
{
public:
	Environtment();
	Environtment(int, int);

	int getWidth();		// Get Width of Environtment
	int getHeight();	// Get Height of Environtment

	bool operator()(int, int);		// Get Dirt Status
	void setDirt(int, int, bool);	// Manipulate dirt status
	
	bool isClean();

	void change(); // The environtment beahiour every step

	~Environtment();
private:
	int size_width, size_height;
	bool dirtPlace[100][100];
};

#endif

