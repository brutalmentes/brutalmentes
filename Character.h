#ifndef CHARACTER_H
#define CHARACTER_H

#include "Texture.h"

class Character{
	public:
		Character();

		void setTexture(Texture *texture);

		int getPosX();

		int getPosY();

		void setPosX(int posX);

		void setPosY(int posY);

		Texture* getTexture();
	protected:
		Texture* texture;
};

#endif