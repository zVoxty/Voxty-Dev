#include "Player.h"

Player::Player()
{
    _playerHealth = 100;
}

Player::~Player()
{
    //dtor
}

void Player::Traveling(){
    ShowPlayerStatistics();
}

void Player::ShowPlayerStatistics(){
    ClearScreen;
    cout << "\t Statistics of " << _playerName << " :\n";
    cout("_____________________________\n");
    cout << "Health : " << _playerHealth << endl;
    cout("_____________________________\n\n");
}

void Player::PlayerSession(){
    while(PlayerSessionToggle == true){
        FetchPlayerOptions();
    }
}

void Player::FetchPlayerOptions(){
    ShowPlayerStatistics();

    cout << "Options : \n";
    cout << "1) Go in adventure . \n";
    cout << "2) Exit. \n";
    cout("_____________________________\n");
    cout << "Your option : ";
    cin >> _userInputOption;

    switch(_userInputOption){
    case 1:
        Traveling();
        Sleep2s;
        break;
    case 2:
        PlayerSessionToggle = false;
        ClearScreen;
        break;
    default:
        errors.UserOptionError();
        break;
    }
}
