#pragma once
#include "Opponent.h"
#include "GameState.h"


class IA : public Opponent, public GameState
{
private:

	Token token;

public:
	IA(Token iaToken) : token(iaToken) {}

    void Play(GameState *state) override;

	bool SetToken(int id);
	Token GetToken() const { return token; }
};

