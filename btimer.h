class Btimer
{
    public:
		
       Btimer(int);
       int threadFunction( void*data);
       static int thread_func_wrapper(void *data);
};
