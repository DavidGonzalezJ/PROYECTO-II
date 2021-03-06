#pragma once
#include "ObjetoJuego.h"
#include "SDL.h"
#include "TexturasSDL.h"
#include "juegoPG.h"
#include <map>
#include "Componente.h"
class ObjetoPG :
	public ObjetoJuego
{
public:
	virtual ~ObjetoPG();

	//M�todos
	virtual bool dentro(int x, int y)const;
	virtual void draw();
	virtual void lateDraw();
	virtual bool onClick();
	virtual bool onOver();

	virtual void update(int delta);
	virtual void start();
	virtual void lateUpdate(int delta);
	virtual bool isAble(){ return activo; }
	virtual void awake();
	virtual void sleep();
	virtual void swAble(); 
	virtual void newComponente(Componente* comp, std:: string const & name);
	virtual void deleteComponente(std::string const & name);
	virtual bool encuentraComponente(std::string const & name);
	virtual void setRect(int incrX, int incrY){ rect.x += incrX; rect.y += incrY; }
	virtual void setAbsRect(int incrX, int incrY){ absRect.x += incrX; absRect.y += incrY; }
	virtual void setRectWH(int width, int height) { rect.w = width; rect.h = height; }
	virtual SDL_Rect getRect(){ return rect; }
	virtual SDL_Rect getAbsRect(){ return absRect; }
	virtual juegoPG* getPJuego(){ return pJuego; }
	virtual  SDL_Rect getColisionBox(){ return rect; };
	virtual void setColRect(int incrX, int incrY){};
	virtual Componente* dameComponente(std::string const &s){
		if (encuentraComponente(s)) return mapaComponentes.at(s);
		else return nullptr;
	}
	bool esDetectable(){ return detectable; }
	//Animacion-------------------------------------------
	virtual void changeAnimV(int fila) { anim.y = anim.h * fila; } // coloca la 'j'
	virtual void changeAnimV(int fila, bool principio) { anim.y = anim.h * fila; if (principio) anim.x = 0; }
	virtual void changeAnimH( ) { anim.x += anim.w; if ( anim.x >= anim.w * 4) anim.x = 0; } // coloca la 'i'
	virtual void changeAnimH(bool loop) {if (!loop && anim.x + anim.w < anim.w * 4) anim.x += anim.w;} // coloca la 'i'
	virtual void changeAnimHB() {
		if (!vuelta && anim.x + anim.w < anim.w * 4) anim.x += anim.w;
		else if (!vuelta && anim.x + anim.w >= anim.w * 4) vuelta = true;
		else if (vuelta  && anim.x - anim.w > 0) anim.x -= anim.w;
		else if (vuelta && anim.x - anim.w <= 0) vuelta = false;
	}
	virtual Texturas_t getEnumText()const { return et; }
	bool interactuable=false;
	bool desaparece = true;
	bool obstaculo = false;
	bool escondite = false;
	bool enemigo = false;
	bool herido = false;
	bool atacando = false;
	bool vuelta = false;
	int IndiceAnim;

	std::string destructor;
	std::vector<std::string> nombre;
	std::vector<std::string> receta;
	ObjetoPG(juegoPG * juego, int px, int py);
	void esconderse(){
		bool aux = detectable;
		setAlpha(0);
		detectable = false;
		if (aux != detectable)pJuego->getEstadoActual()->reproduceFx("Maleza", 0, 0, 0);
	}
	void salirEscondite(){
		bool aux = detectable;
		setAlpha(255);
		detectable = true;
		if (aux != detectable)pJuego->getEstadoActual()->reproduceFx("Maleza", 0, 0, 0);
	}
	void setVelocity(float x, float y){
		if (x >= 0 ) velocity.x = x; 
		if (y >= 0) velocity.y = y;
	};
	SDL_Rect velocity;

	virtual void scaleRect(int x){ 
		rect.w *= x; rect.h *= x; 
	}
	void setTerreno(int tr){ terreno = tr;}
	int getTerreno() { return terreno; }
protected: 
	void setAlpha(int x){
		if (x >= 0 && x <= 255){
			alpha = x;
		}
	}
	int alpha;
	//Atributos-------------------------------------------
	bool activo;
	bool detectable;
	std::map <std::string, Componente*> mapaComponentes; 
	juegoPG * pJuego;
	Texturas_t et;
	SDL_Rect rect;
	SDL_Rect absRect;
	SDL_Rect aux; //Rect auxiliar para cual quier cuenta con rectangulos (Se usa para la camara)	
	SDL_Rect anim;
	int terreno;
};

