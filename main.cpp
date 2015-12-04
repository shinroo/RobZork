#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <algorithm>

using namespace std;

/*##########################################################################################################################*/

//Global variables:

//location variables
int PosX;
int PosY;

//boolean variables
bool InCombat; //if this variable is true, the user has encountered a foe
bool GameOver; //if this variable is true, then the game is over
bool ArtifactOne; //if this variable is true and the artifacttwo is also true, the game is over
bool ArtifactTwo;
bool Alive; //if this variable is false then the game is over

//string variables
string Monster;

//world array
string World[50][50];

//array holding types of terrains
string Terrain[5] = {
                   "You are in a forest. \n",
                   "You are near a stream. \n",
                   "You are on a hill. \n",
                   "You are in a field. \n",
                   "You are in a valley. \n",
       };

/*##########################################################################################################################*/

// check if the game is over
bool CheckGameOver(bool ArtifactOne, bool ArtifactTwo){
                        if ((ArtifactOne == true) && (ArtifactTwo == true)){ // if the user has both artifacts;
                                         GameOver = true;
                                         return true;
                                         }
                        else{
                             return false;
                             }
     }     

/*##########################################################################################################################*/

//Generating world function

void GenerateWorld(){
                     int x = 0;
                     int y = 0;
                     
                     for (x = 0; x < 50; x++){ // for loop running through all x values
                         
                         for (y = 0; y < 50; y++){ // for loop running through all y values
                             
                             if ((x == 0) || (x == 49) || (y == 0) || (y == 49)){ 
                                    World[x][y] = "You are on a beach. \n";
                                    }
                             else {
                                  int random = rand() % 5; 
                                  World[x][y] = Terrain[random]; //if the player is not on an edge, pick a random terrain type
                                  }
                                  
                                    
                             }
                         } 
                         return;    
                         }
                         
/*##########################################################################################################################*/

//function to check if there is a monster or artifact at your location

void CheckMonsterArtifact(){
                    int choice = (rand() % 50) + 1;
                    
                    switch (choice){
                           default: {
                                    cout<<"The area seems to be empty. \n";
                                    return;
                                    }
                           case 1: {
                                cout<<"You come across a bandit! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "bandit";
                                return;
                                }
                           case 5: {
                                cout<<"You come across a bandit! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "bandit";
                                return;
                                }
                           case 14: {
                                cout<<"You come across a goblin! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "goblin";
                                return;
                                }
                           case 19: {
                                cout<<"You come across a troll! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "troll";
                                return;
                                }
                           case 21: {
                                cout<<"You come across a bandit! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "bandit";
                                return;
                                }
                           case 25: {
                                cout<<"You come across a bandit! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "bandit";
                                return;
                                }
                           case 24: {
                                cout<<"You come across a goblin! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "goblin";
                                return;
                                }
                           case 29: {
                                cout<<"You come across a troll! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "troll";
                                return;
                                }
                           case 30: {
                                cout<<"You come across a troll! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "troll";
                                return;
                                }
                           case 31: {
                                cout<<"You come across a bandit! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "bandit";
                                return;
                                }
                           case 35: {
                                cout<<"You come across a bandit! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "bandit";
                                return;
                                }
                           case 34: {
                                cout<<"You come across a goblin! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "goblin";
                                return;
                                }
                           case 39: {
                                cout<<"You come across a troll! \n";
                                cout<<"(You cannot move until you defeat your enemy.)\n";
                                InCombat = true;
                                Monster = "troll";
                                return;
                                }
                           case 48: { // 1 in 50 chance of finding an artifact
                                if (ArtifactOne == true){
                                                ArtifactTwo = true;
                                                }
                                else {
                                     ArtifactOne = true;
                                     }
                                cout<<"You have found an artifact! \n"
                                    <<"You have seen the monsters carry artifacts similar to these... \n";
                                }
                           }
     }
/*##########################################################################################################################*/

//function to interpret user input

void Interpret(string one, string two){
     
     
                      //convering parameters to lowercase
                      int n; // counter variable

		      //i got the idea for this code from the internet
                      char c; 
                       for ( n=0 ; one[n]!='\0' ; n++)
                       {
                          c = one[n];
                          one[n] = (tolower(c));
                         
                          }
                      
                      /* 
                         For some reason if you were to use one[n] as a char in the tolower() function
                         it does not work which is why I had to assign it to a char and then assign it
                         back
                      */
                          
                      for ( n=0 ; two[n]!='\0' ; n++)
                       {
                          c = two[n];
                          two[n] = (tolower(c));
                         
                          }
                      
                     if (InCombat == false){
                                    
                      //code for moving
                      if ((one == "go") || (one == "move") || (one == "travel") || (one == "walk")){ //check whether the first word refers to movement
                      
                               //if the second word mentions north increment the Y position
                                    if ((two == "north") || (two == "northwards")){
                                            if  (PosY == 0){ //if you are on the edge of the map
                                              cout<<"You can't go that way. \n";  
                                                }
                                            else{
                                              cout<<"You travel north.\n";
                                              PosY--;
                                              cout << World[PosX][PosY] <<"\n";
                                              CheckMonsterArtifact();
                                                 }
                                              return;
                                              }
                               //if the second word mentions south decrement the Y position
                                    if ((two == "south") || (two == "southwards")){
                                            if  (PosY == 49){ //if you are on the edge of the map
                                              cout<<"You can't go that way. \n";  
                                                }
                                            else{
                                              cout<<"You travel south.\n";
                                              PosY++;
                                              cout << World[PosX][PosY] <<"\n";
                                              CheckMonsterArtifact();
                                                 }
                                              return;
                                              }
                               //if the second word mentions west increment the X position
                                    if ((two == "west") || (two == "westwards")){
                                            if  (PosX == 0){ //if you are on the edge of the map
                                              cout<<"You can't go that way. \n";  
                                                }
                                            else{
                                              cout<<"You travel west.\n";
                                              PosX--;
                                              cout << World[PosX][PosY] <<"\n";
                                              CheckMonsterArtifact();
                                                 }
                                              return;
                                              }
                                              
                               //if the second word mentions east decrement the X position
                                    if ((two == "east") || (two == "eastwards")){
                                            if  (PosX == 49){ //if you are on the edge of the map
                                              cout<<"You can't go that way. \n";  
                                                }
                                            else{
                                              cout<<"You travel east.\n";
                                              PosX++;
                                              cout << World[PosX][PosY] <<"\n";
                                              CheckMonsterArtifact();
                                                 }
                                              return;
                                              }
                                              
                                    return;
                                 } // end of movement
                             }
                            else{
                                 //if the user is in combat
                                    if ((one == "hit") || (one == "kill") || (one == "attack") || (one == "cut") || (one == "slice") || (one == "slay")){
                                            
                                            if ((two == Monster) || (two == "enemy") || (two == "foe")){
                                               int choice = (rand() % 10) + 1;
                                               
                                               if ((choice == 1) || (choice == 5)){
                                                           Alive = false;
                                                           }        
                                               else{
                                                    cout << "You slay your enemy ferociously!\n";
                                                    InCombat = false;
                                                    }
                                                     }
                                            }
                                       
                             } // end of combat
                             return;
                      } // end of function

     
/*##########################################################################################################################*/

int main(int argc, char *argv[])
{
    //initialize the position variables
    PosX = 0;
    PosY = 0;
    
    //initialize the boolean variables
    InCombat = false;
    GameOver = false;
    ArtifactOne = false;
    ArtifactTwo = false;
    Alive = true;
    
    //create the string variables to hold user input
    string One;
    string Two;
    
    //Generate the world with GenerateWorld() function
    GenerateWorld();
    
    cout << "\n Developed by Robert Focke - 2013 \n\n";

    //introduce plot
    cout << "You wake up on an island but you have no memory of how you got there.\n";
    cout << "Find out why you are on this island all alone... what was that sound... \n\n";
    
    
    //Give the user their original position
    cout << World[PosX][PosY] <<"\n";
    
    
    //continuously get user input until the game is over
    do{         
           cout << ">> Line 1: ";
           cin >> One ;
           if (One.find(" ") == std::string::npos){
                          cout << ">> Line 2: ";
                          }
           else{
                cout << "\n";     
                }
           cin >> Two ;
           Interpret(One,Two);
           if (Alive == true){
                     
           if (CheckGameOver(ArtifactOne, ArtifactTwo) == true){
                             cout << "After touching the last artifact your memories of what happened return to you. \n"
                                  << "You were involved in a plane crash and you are the sole survivor. \n"
                                  << "Well done on surviving :) \n";
                                  
                             cout << "GAME OVER";
                             }
                             
                             }
           else {
                cout << "You have been killed by an enemy :(";
                break;
                }
           cout << "\n";
        
        }while (GameOver == false);
           
    system("PAUSE");
    return EXIT_SUCCESS;
}
