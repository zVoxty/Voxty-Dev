#ifndef PLAYER_H
#define PLAYER_H

#include "Core.h"
#include "Error.h"

class GameManager;

class Player
{
    public:
        Player();
        virtual ~Player();

        void ShowPlayerStatistics();
        void PlayerSession();
        void FetchPlayerOptions();
        void Traveling();

        bool PlayerSessionToggle;

    protected:

    friend GameManager;

    private:
        string _playerName;
        int _playerHealth;
        int _userInputOption;
        Error errors;
};

#endif // PLAYER_H
