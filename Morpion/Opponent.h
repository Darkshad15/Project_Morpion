#pragma once
#include "GameState.h"

class Opponent
{
public:

    virtual void Play(GameState *state) = 0;

};

