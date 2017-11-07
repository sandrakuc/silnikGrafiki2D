#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

class Engine
{
    public:
        Engine();
        virtual ~Engine();
        int initiall();
        int initiall(int mode);
        static Engine *getInstance();
        int errMsg();
    protected:

    private:
        static Engine *single;

};


#endif // ENGINE_H_INCLUDED
