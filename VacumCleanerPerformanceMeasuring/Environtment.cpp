#include "Environtment.h"
#include <stdlib.h>

#define SMALL_CHILDREN


Environtment::Environtment()
{
	size_height = 1;
	size_width = 2;
}

Environtment::Environtment(int height, int width)
{
	size_height = height;
	size_width = width;
}

int Environtment::getWidth()		// Get Width of Environtment
{
	return size_width;
}

int Environtment::getHeight()	// Get Height of Environtment
{
	return size_height;
}

bool Environtment::operator()(int x, int y)		// Get Dirt Status
{
	return dirtPlace[x][y];
}
void Environtment::setDirt(int x, int y, bool v)	// Manipulate dirt status
{
	dirtPlace[x][y] = v;
}

bool Environtment::isClean()
{
	for (int i = 0; i < size_width; i++) {
		for (int j = 0; j < size_height; j++) {
			if (dirtPlace[i][j] == true)
				return false;
		}
	}

	return true;
}

void Environtment::change() {
#ifdef SMALL_CHILDREN
	for (int i = 0; i < size_width; i++) {
		for (int j = 0; j < size_height; j++) {
			if (dirtPlace[i][j] == false) {
				int random = rand() % 100;
				if (random < 10)
					dirtPlace[i][j] = true;
			}
		}
	}
#endif
}

Environtment::~Environtment()
{
}
