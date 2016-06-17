#include "Texture.h"
class Bar
{
private:
	Texture *textures[4]; 
/*	Texture *textureGreen;
        Texture *textureYellow;
	Texture *textureOrange;
	Texture *textureRed;
*/	
 public:
 Bar();
 ~Bar();
 Texture* getTexture(int);
 void setWidth(int id, int width);
 void setHeight(int id ,int height);
 int getWidth(int id);
};
