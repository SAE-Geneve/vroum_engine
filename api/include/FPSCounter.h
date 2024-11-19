#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <SDL2/SDL.h>

class FPSCounter
{
public:
    FPSCounter();

    void Update();
    void Reset();
    float GetFPS() const;
  float GetDeltatime() {return delta_time_;}

private:
    Uint32 lastTime;
    Uint32 frameCount;
    float delta_time_;
    float fps;
};

#endif // FPSCOUNTER_H
