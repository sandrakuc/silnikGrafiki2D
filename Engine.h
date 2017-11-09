#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

class Engine
{
    public:
        int w, h;
        Engine();
        virtual ~Engine();
        BITMAP *initiall(BITMAP *buffer);
        BITMAP *initiall(int mode, BITMAP *buffer);
        static Engine *getInstance();
        int errMsg();
        void blockingKeyboardUsing(BITMAP *buffer);
        void nonBlockingKeyboardUsing();
        void mainLoop(Engine *engine, BITMAP *buffer);
    protected:

    private:
        static Engine *single;

};


#endif // ENGINE_H_INCLUDED
