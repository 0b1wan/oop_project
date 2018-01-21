//
//  game.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#include "game.hpp"

Game::Game(int r, int c)
{
    grid_c = c;
    grid_r = r;
    total_Heros = 0;
    theGrid = new class Grid(r, c);
}

void Game::begin()
{

    add_Hero_Warrior(0,0, "Jesus", 9);
    add_Hero_Sorcerer(0,0);
    add_Hero_Paladin(0,0);

    add_Monster_Dragon(3, 3, "Josh" , 5);
    theGrid->add_Market(1, 1);
    theGrid->add_Market(4, 3);
    theGrid->add_Market(3, 4);
    theGrid->add_NonAccessible(4, 4);

    cout << " Welcome to the Game! " << endl << endl;
    cout << " This is how the world looks right now... " << endl;
    theGrid->showMap();

    cout << " Your heros are on square [0,0] each showing his health percentage after the Character Type. " << endl;
    cout << " You begin the Game with 3 different Hero types..." << endl;
    cout << " A warrior, a sorcerer and paladin..." << endl;
    cout << " Each type has different attribute advantages as he levels up." << endl << endl;
    cout << " Try to take some action..." << endl;
    showPossibleActions();


}

/********** ADD HEROS **********/



int Game::add_Hero_Warrior(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Warrior* mywarrior = new class Warrior(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mywarrior->r_co = r;
    mywarrior->c_co = c;
    theHeros.push_back(mywarrior);
    theGrid->square[r][c]->heros.push_back(mywarrior);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Paladin(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Paladin* mypaladin = new class Paladin(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mypaladin->r_co = r;
    mypaladin->c_co = c;
    theHeros.push_back(mypaladin);
    theGrid->square[r][c]->heros.push_back(mypaladin);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Sorcerer(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Sorcerer* mysorcerer = new class Sorcerer(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mysorcerer->r_co = r;
    mysorcerer->c_co = c;
    theHeros.push_back(mysorcerer);
    theGrid->square[r][c]->heros.push_back(mysorcerer);
    total_Heros++;
    return 0;
}





/********** ADD MONSTERS **********/



int Game::add_Monster_Dragon(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Dragon* myDragon = new class Dragon(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myDragon);
    return 0;
}


int Game::add_Monster_Spirit(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Spirit* mySpirit = new class Spirit(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(mySpirit);
    return 0;
}


int Game::add_Monster_Exosceleton(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Exosceleton* myExosceleton = new class Exosceleton(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myExosceleton);
    return 0;
}



void Game::move_heros(string direction)
{
    if ((direction == "up" ) && (theHeros[0]->r_co > 0))
    {
        theGrid->square[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->r_co--;
            theGrid->square[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
            cout << " Moved " << direction << ". Team now at pos [" << theHeros[0]->r_co << "," << theHeros[0]->c_co << "]" << endl;
    }
    else if ((direction == "down") && (theHeros[0]->r_co < grid_r-1))
    {
        theGrid->square[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->r_co++;
            theGrid->square[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
            cout << " Moved " << direction << ". Team now at pos [" << theHeros[0]->r_co << "," << theHeros[0]->c_co << "]" << endl;
    }
    else if ((direction == "left") && (theHeros[0]->c_co > 0))
    {
        theGrid->square[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->c_co--;
            theGrid->square[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
        cout << " Moved " << direction << ". Team now at pos [" << theHeros[0]->r_co << "," << theHeros[0]->c_co << "]" << endl;
    }
    else if ((direction == "right") && (theHeros[0]->c_co < grid_c-1))
    {
        theGrid->square[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->c_co++;
            theGrid->square[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
        cout << " Moved " << direction << ". Team now at pos [" << theHeros[0]->r_co << "," << theHeros[0]->c_co << "]" << endl;
    }
    else
        cout << " Moving " << direction << " not allowed. Map edge." << endl;
}

void Game::askToMoveHeros()
{

    char input;
    do {
        cout << " Input Direction: (w, a, s, d) \n > ";
        cin >> input;
    } while (input != 'w' && input != 'a' && input != 'd' && input != 's');

    switch (input) {
        case 'w':
            move_heros("up");
            break;

        case 's':
            move_heros("down");
            break;

        case 'a':
            move_heros("left");
            break;

        case 'd':
            move_heros("right");
            break;

        default:
            break;
    }
    
}



void Game::showPossibleActions()
{
    cout << endl;
    cout << "      What would you like to do?       " << endl;
    cout << " /------------------------------------\\" << endl;
    cout << " |                                    |" << endl;
    cout << " |  1. Move team --------> Hotkey: m  |" << endl;
    cout << " |  2. Fight Monster ----> Hotkey: f  |" << endl;
    cout << " |  3. Go to Market -----> Hotkey: b  |" << endl;
    cout << " |  4. Exit -------------> Hotkey: q  |" << endl;
    cout << " |                                    |" << endl;
    cout <<" \\------------------------------------/" << endl;

    char input;
    do {
        cout << "\n  : ";
        cin >> input;
        if (input != 'm' && input != 'f' && input != 'b' && input != 'q')
            cout << "  Invalid input. Try one of the 4 hotkeys..." << endl;
        else
            break;
    } while (1);

    cout << endl;
    switch (input) {
        case 'm':
            askToMoveHeros();
            break;

        case 'f':
            break;

        case 'b':
            break;

        case 'q':
            cout << " Thanks for playing!" << endl << endl;
            cout << " Game terminated." << endl << endl;
            exit(0);

        default:
            break;
    }
    
}






