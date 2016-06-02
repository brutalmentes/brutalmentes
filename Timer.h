#ifndef TIMER_H
#define TIMER_H

//Para usar, inicializar um objeto da classe Timer
//start() inicializa o contador do relogio
//getTicks() retorna o tempo de relogio(dividir por 1000.f) -> para imprimir pode usar getTicks().str().c_str()
//stop() para o relogio e reseta pra 0
//pause() pausa o relogio
//unpause() despausa o relogio
//isStarted() verifica se esta rodando
//isPause() verifica se esta pausado


class Timer
{
    public:
        //Inicializa Timer
		Timer();

		//Operacoes de relogio
		void start();
		void stop();
		void pause();
		void unpause();

		//retorna o tempo do timer
		Uint32 getTicks();

		//verifica status do relogio
		bool isStarted();
		bool isPaused();

    private:
		//Clock de quando o relogio iniciou
		Uint32 mStartTicks;

		//tempo quando pausado
		Uint32 mPausedTicks;

		//Status do timer
		bool mPaused;
		bool mStarted;
};


#endif
