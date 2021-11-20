#ifndef APPLICATION_H
#define APPLICATION_H

#include "./Graphics.h"

class Application {
    private:
        bool running = false;

        Uint32 TimeLeft(Uint32);

    public:
        Application() = default;
        ~Application() = default;
        bool IsRunning();
        Uint32 Setup();
        void Input();
        Uint32 Update(Uint32);
        void Render();
        void Destroy();
};

#endif