#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Core.h"
#include "Error.h"
#include "Player.h"

class GameManager
{
    friend Player;

    public:
        GameManager();
        virtual ~GameManager();
        bool GameOn = true;

        void gameCore();
        void MainMenu();
        void FetchMenu();
        void Setup();
        void NewGameIntro();
        int GenerateEvent();

    protected:

    private:
        vector<int>_events;
        Player player;
        Error errors;
        int _userInputOption;
};

#endif // GAMEMANAGER_H
