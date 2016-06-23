#include "Health.h"

Health::Health()
{
 this->health=100;
}


void Health::decHealth()
{
 
  this->health-=10;

}

void Health::incHealth()
{
 
  this->health+=10;
}

float Health::getHealth()
{

 return this->health;
}

float Health::getLevel()
{

 return 0.1;
}




