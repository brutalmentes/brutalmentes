#ifndef CHARACTER_H
#define CHARACTER_H

#include "Texture.h"
#include "Circle.h"
#include <list>

class Character{
	public:
		Character();

		void setTexture(Texture *texture);

		int getPosX();

		int getPosY();

		virtual void setPosX(int posX);

		virtual void setPosY(int posY);

		int getHealth();

		void setHealth(int);

		void decHealth();

		int getLevel();

		Texture* getTexture();

		void setOrientation(Orientation orientation);

		std::list<Circle> getCollisionList();	
	protected:
		std::list<Circle> collisionList;
		Texture* texture;
		int health;
		int level;
};

#endif
