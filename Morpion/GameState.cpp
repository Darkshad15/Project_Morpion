#include "GameState.h"

GameState::GameState() : tokens(9, Token::Empty)
{
}

Token GameState::GetToken(int x, int y)
{
    return GetToken(3 * y + x);
}

Token GameState::GetToken(int id)
{
    if (id >= 9 || id < 0)
    {
        throw std::out_of_range("Index out of range");
    }

    return tokens[id];
}

bool GameState::SetToken(int x, int y, Token token)
{
    return SetToken(3 * y + x, token);
}

bool GameState::SetToken(int id, Token token)
{
    if (id >= 9 || id < 0)
    {
        throw std::out_of_range("Index out of range");
    }

    if (GetToken(id) != Token::Empty)
        return false;

    tokens[id] = token;

    return true;
}

std::optional<Token> GameState::CheckWin()
{
    int cellsCombination[8][3]
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},

        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},

        {0, 4, 8},
        {2, 4, 6},
    };

    for (auto combination : cellsCombination)
    {
        if (std::optional<Token> winner = CheckWinRow(combination[0], combination[1], combination[2]))
            return winner;
    }
}

std::optional<Token> GameState::CheckWinRow(int a, int b, int c)
{
    if (tokens[a] == tokens[b] && tokens[a] == tokens[c])
    {
        if (tokens[a] == Token::Empty)
            return std::optional<Token>();

        return std::optional<Token>(tokens[a]);
    }

    return std::optional<Token>();
}

bool GameState::IsFull()
{
    for (Token token : tokens)
    {
        if (token == Token::Empty)
            return false;
    }

    return true;
}

std::string GameState::ToString()
{
    std::string result;

    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            result += static_cast<char>(GetToken(x, y));
        }

        result += '\n';
    }

    return result;
}
