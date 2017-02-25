#pragma once
#include <iostream>
class EstadoJuego
{
public:

	EstadoJuego()
	{
	}
	virtual void draw() = 0;
	virtual void onClick() = 0;
	virtual void update() = 0;
	virtual void onOver() = 0;
	virtual void onKeyUp(char k) = 0;
	virtual void reproduceFx(std::string fx, float x, float y, float wet) = 0;
	virtual void reproduceMusica(std::string music, bool fade) = 0;
	virtual void paraMusica(std::string music, bool fade) = 0;
	virtual void reproduceAmb(std::string amb, bool fade) = 0;
	virtual void paraAmb(std::string amb, bool fade) = 0;
	virtual ~EstadoJuego()
	{
	}
};

