#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <optional>

enum class Token : char
{
    Empty = '-',
    X = 'X',
    O = 'O'
};

class GameState
{
    std::vector<Token> tokens;

public:
    GameState();

    Token GetToken(int x, int y);
    Token GetToken(int id);

    bool SetToken(int x, int y, Token token);
    bool SetToken(int id, Token token);

    std::optional<Token> CheckWin();
    std::optional<Token> CheckWinRow(int a, int b, int c);

    bool IsFull();

    std::string ToString();
};
