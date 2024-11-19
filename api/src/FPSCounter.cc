#include "FPSCounter.h"

FPSCounter::FPSCounter()
    : lastTime(SDL_GetTicks()), frameCount(0), fps(0.0f)
{
}

void FPSCounter::Update()
{
    frameCount++;
    Uint32 currentTime = SDL_GetTicks();
    delta_time_ = currentTime - lastTime;

    if (delta_time_ > 1000) {
        fps = frameCount / (delta_time_ / 1000.0f);
        frameCount = 0;
        lastTime = currentTime;
    }
}

void FPSCounter::Reset()
{
    lastTime = SDL_GetTicks();
    frameCount = 0;
    fps = 0.0f;
}

float FPSCounter::GetFPS() const
{
    return fps;
}
