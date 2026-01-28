#include "IA.h"
#include "GameState.h"

void IA::Play(GameState *state)
{

}


bool IA::SetToken(int id)
{
    return	GameState::SetToken(id, IA::GetToken());
}
