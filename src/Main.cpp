#include "Application.h"

int main(int argc, char *args[])
{
    Application app;

    Uint32 nextTime = app.Setup();

    while (app.IsRunning())
    {
        app.Input();
        nextTime = app.Update(nextTime);
        app.Render();
    }

    app.Destroy();

    return 0;
}