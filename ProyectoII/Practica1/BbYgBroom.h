#pragma once
#include "ObjetoPG.h"
#include "ColisionBox.h"

class BbYgBroom :
	public ObjetoPG
{
public:
	BbYgBroom(juegoPG * juego, int px, int py);
	virtual ~BbYgBroom();
	virtual void draw();
	virtual  SDL_Rect getColisionBox() { return static_cast<ColisionBox*> (mapaComponentes.at("ColisionBox"))->getRectBox(); }
};

