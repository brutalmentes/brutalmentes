#include "Texture.h"
class Bar
{
private:
	Texture *texture;

 public:
 Bar();
 ~Bar();
 Texture* getTexture();
 void setWidth(int width);
 void setHeight(int height);

 int getWidth();
};
