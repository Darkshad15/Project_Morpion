#include <iostream>
#include "GameState.h"
#include "Player.h"
#include "IA.h"


int main()
{
	GameState *state = new GameState();
	Player *Player1 = new Player(Token::X);
	IA *ia = new IA(Token::O);


	while (state)
	{

		int id;
		std::cout<< "Donner moi un ID entre 1-9 pour l'emplacement :" << std::endl;
		std::cin >> id;

		state->SetToken(id-1, Player1->GetToken());

		std::cout << state->ToString() << std::endl;
		if (state->CheckWin() || state->IsFull())
		{
			std::cout << "WIN" << std::endl;
		}
	}

	delete Player1;
	delete ia;
	delete state;

}
