#include "GameManager.h"

GameManager::GameManager()
{
    gameCore();
}

GameManager::~GameManager()
{
    //dtor
}

void GameManager::MainMenu(){
        cout << "\t\t Spware! \n";
        cout << "____________________________\n";
        cout << "Main Menu : \n";
        cout << "\t1) NewGame \n";
        cout << "\t2) Exit \n";
        cout << "____________________________\n";
        cout << "Your Option : ";
        cin >> _userInputOption;
}

void GameManager::NewGameIntro(){
    ClearScreen;
    cout("Hello traveler ! \n")
    Sleep05s;
    cout("I'm glad to see you here ! \n");
    Sleep05s;
    cout("What is your name ?: \n");
    cin >> player._playerName;
    cout << "Nice to meet you " << player._playerName << " !\n";
    Sleep1s;
    cout("You will be a part of a nice adventure !\n");
    Sleep1s;
    cout("On the top of screen you will see your statistics ! \n");
    Sleep1s;
    cout("Enjoy your adventure ! \n")
    Sleep(5000);
    ClearScreen;
}

void GameManager::FetchMenu(){
    MainMenu();
    switch(_userInputOption){
    case 1:
        NewGameIntro();
        player.PlayerSession();
        break;
    case 2:
        GameOn = false;
        ClearScreen;
        break;
    default:
        errors.UserOptionError();
        break;
    }
}

int GameManager::GenerateEvent(){
    int numberOfEvents = _events.size();
}

void GameManager::Setup(){
    int numberOfEvents = 5;
    for(int i = 0; i < 5; i++){
        _events.push_back(i);
    }
}

void GameManager::gameCore(){
    while(GameOn == true){
        Setup();
        FetchMenu();
    }
}
