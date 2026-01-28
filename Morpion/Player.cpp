#include "Player.h"
#include "GameState.h"
#include <iostream>


void Player::Play(GameState *state) {

}

bool Player::SetToken(int id)
{
	return GameState::SetToken(id,Player::GetToken());
}


