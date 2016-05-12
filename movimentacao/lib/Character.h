#ifndef CHARACTER_H
#define CHARACTER_H

#include "Texture.h"
#include "share.h"

class Character{
	public:
		Character(Texture* texture);

		int getPosX();

		int getPosY();

		void setPosX(int posX);

		void setPosY(int posY);

		Texture* getTexture();
	private:
		Texture* texture;
};

#endif