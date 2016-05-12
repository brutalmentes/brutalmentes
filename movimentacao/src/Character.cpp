#include "../lib/Character.h"


Character::Character(Texture *texture) {
	this->texture = texture;
}

int Character::getPosX() {
	return this->texture->getPosX();
}

int Character::getPosY() {
	return this->texture->getPosY();
}

void Character::setPosX(int posX) {
	this->texture->setPosX(posX);
}

void Character::setPosY(int posY) {
	this->texture->setPosY(posY);
}

Texture* Character::getTexture() {
	return this->texture;
}