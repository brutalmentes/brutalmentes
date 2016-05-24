#include <iostream>

#include "object.h"
#include "launch.h"
#include "fisica.h"
#include "btimer.h"

int main(){

// Quando o jogo come�ar
Btimer *tempo = new Btimer();
Physics *fisica = new Physics();

// Para associar objeto a um movimento
Object *objeto = new Object(10,10);
// Seta for�a e �ngulo do objeto corrente
Launch *launch = new Launch(3,45);
objeto->setinitialspeed(launch->getnextspeedx(),launch->initialspeedy());

// Executa movimento
// A posi��o do objeto � atualizada automaticamente com o tempo
fisica->start(objeto,launch,tempo);

// Ao detectar colis�o, parar o movimento
// Substituir o for pela detec��o
for (int i=0;i<100000000;i++){}
fisica->stop();


//Quando o jogo terminar
fisica->~Physics();
tempo->~Btimer();

return 0;
}
