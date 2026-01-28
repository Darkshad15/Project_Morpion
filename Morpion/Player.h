#pragma once
#include "Opponent.h"
#include "GameState.h"


class Player : public Opponent, public GameState
{

private:
	Token token;

public:

	Player(Token playerToken) : token(playerToken){}

	void Play(GameState *state) override;
	bool SetToken(int id);


	Token GetToken() const { return token; }

};

