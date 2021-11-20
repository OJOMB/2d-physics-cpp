#include "Application.h"
#include "Physics/Particle.h"
#include "Physics/Constants.h"

#define TICK_INTERVAL 30;

static Uint32 next_time;

Particle* particle;

bool Application::IsRunning()
{
    return running;
}

// Setup function (executed once in the beginning of the simulation)
Uint32 Application::Setup()
{
    running = Graphics::OpenWindow();

    particle = new Particle(200, 200, 1.);

    return SDL_GetTicks() + TICK_INTERVAL;
}

// Input processing
void Application::Input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
            break;
        }
    }
}

// Update function (called several times per second to update objects)
Uint32 Application::Update(Uint32 nextTime)
{
    particle->velocity = Vec2(1.,1.);

    particle->position += particle->velocity;

    // control framerate by checking ticks and delaying if it's too soon to finish updating
    SDL_Delay(TimeLeft(nextTime));

    return nextTime + TICK_INTERVAL;
}

// Render function (called several times per second to draw objects)
void Application::Render()
{
    Graphics::ClearScreen(0xFF056263);
    Graphics::DrawFillCircle(
        particle->position.x, particle->position.y, 5, 0xFFFFFFFF
    );
    Graphics::RenderFrame();
}

// Destroy function to delete objects and close the window
void Application::Destroy()
{
    // TODO: destroy all objects in the scene

    Graphics::CloseWindow();
}

Uint32 Application::TimeLeft(Uint32 nextTime)
{
    Uint32 now = SDL_GetTicks();
    if(nextTime <= now)
        return 0;

    return nextTime - now;
}