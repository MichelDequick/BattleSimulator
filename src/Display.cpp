#include "Display.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>



Display::Display( Map * map)
{
    this->map = map;
    Display::windowInitialize();
}

void Display::windowInitialize( void )
{
    SetConsoleTitle("Battle Simulator");
}

void Display::startScreen( void )
{
    system("cls");
    cout << "Recommended console window settings: Width=122 Height:45 Font: Lucida Console" << endl;
    Display::emptyLines( 19 );
    Display::logo();
    Display::emptyLines( 20 );
    cout << "Press a  key to start" << endl;
}

void Display::logo( void )
{
    cout << " ______  _______ _______ _______        _______      _______ _____ _______ _     _        _______ _______  _____   ______" << endl;
    cout << " |_____] |_____|    |       |    |      |______      |______   |   |  |  | |     | |      |_____|    |    |     | |_____/" << endl;
    cout << " |_____] |     |    |       |    |_____ |______      ______| __|__ |  |  | |_____| |_____ |     |    |    |_____| |    \\_" << endl;
}

void Display::playerLogo( int player )
{
    if(player == 1)
    {
        cout << "                                           ___  __                    ___" << endl;
        cout << "                                          / _ \\/ /__ ___ _____ ____  <  /" << endl;
        cout << "                                         / ___/ / _ `/ // / -_) __/  / / " << endl;
        cout << "                                        /_/  /_/\\_,_/\\_, /\\__/_/    /_/  " << endl;
        cout << "                                                    /___/                " << endl;
    }
    else if(player == 2)
    {
        cout << "                                           ___  __                    ___ " << endl;
        cout << "                                          / _ \\/ /__ ___ _____ ____  |_  |" << endl;
        cout << "                                         / ___/ / _ `/ // / -_) __/ / __/ " << endl;
        cout << "                                        /_/  /_/\\_,_/\\_, /\\__/_/   /____/ " << endl;
        cout << "                                                    /___/                 " << endl;
    }
}

void Display::winLogo( void )
{
        cout << "                                             _       __          " << endl;
        cout << "                                            | |     / /___  ____ " << endl;
        cout << "                                            | | /| / / __ \\/ __ \\" << endl;
        cout << "                                            | |/ |/ / /_/ / / / /" << endl;
        cout << "                                            |__/|__/\\____/_/ /_/ " << endl;
}

void Display::emptyLines( int lines )
{
    for( int n = 0; n < lines; n++ )
    {
        cout << endl;
    }
}


void Display::gameScreen( int player, std::string message )
{
    if( player != 0 ){ this->player = player; }
    if( message != "" ){ this->message = message; }

    system("cls");
    Display::logo();
    Display::emptyLines( 1 );
    if( this->player ==  1 ){ cout << PLAYER_SELECTED << " Player 1                                                    " << PLAYER_NOT_SELECTED << " Player2" << endl; }
    else{ cout << PLAYER_NOT_SELECTED << " Player 1                                                    " << PLAYER_SELECTED << " Player2" << endl; }

    cout << map->toString() << endl;
    cout << "Message:" << endl;
    cout << ">" << this->message << endl;

}

void Display::playerScreen( int player )
{
    system("cls");
    Display::logo();
    Display::emptyLines( 15 );
    Display::playerLogo( player );
}

void Display::buyScreen( int player, int credits, std::string message )
{
    //if( player != 0 ){ this->player = player; }

    system("cls");
    Display::logo();
    Display::emptyLines( 5 );
    Display::playerLogo( player );
    Display::emptyLines( 2 );
    cout << "                                                Credits: " << credits << endl;
    Display::emptyLines( 1 );
    cout << "                                 U | Unit     | Price | Health | Damage | Rage * |" << endl;
    cout << "                                   |__________|_______|________|________|________|" << endl;
    cout << "                                 I | Infantry |   100 |     10 |     10 |     5% |" << endl;
    cout << "                                 T |     Tank |  1000 |    100 |    100 |     2% |" << endl;
    cout << "                                 S |   Sniper |   150 |      5 |     20 |     0% |" << endl;
    cout << "                                 R |    Rambo |  2000 |     20 |    200 |    10% |" << endl;
    Display::emptyLines( 18 );
    cout << message << endl;

}

void Display::winScreen( int player )
{
    system("cls");
    Display::logo();
    Display::emptyLines( 10 );
    Display::playerLogo( player );
    Display::emptyLines( 5 );
    Display::winLogo();
}
