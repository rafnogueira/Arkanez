
#ifndef INPUT_H
#define INPUT_H

#include "Globals.h"

class Input
{
public:
    Input();
    ~Input();
     void HandleInput(SDL_Event *e, bool pressed);
private:

};


#endif // INPUT_H
