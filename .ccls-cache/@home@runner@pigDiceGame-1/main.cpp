// Specification B2 - Source File Header
//  pig.cpp
//  Anthony Thompson, CISP 400
//  1/23/23
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Declaration of the functions that I am using, all are named in self explanatory manner
void ProgramGreeting();
void ruleExplanation();
int D6();
int player_user_rolls(int player_total_points, string userName);
int cpu_auto_rolls(int cpu_total_points);

int main() {
// Specification C1 - Fixed Seed
  srand(time(NULL));
  string userName;
  int turn_points;
  int cpu_total_points;
  int player_total_points;
  bool game_end_boolean = false;
// Specification C4 - ProgramGreeting
  ProgramGreeting();

  // menu prompt function to the user
    cout << "lets begin!" << endl;
    cout << '\n';
    cout << "What is your name?" << endl;
  
// Specification C2 - Student Name
  getline(cin, userName);
    cout << userName << ", Do you know how to play the pig game? (y/n)" << endl;
  ruleExplanation();
// Specification C3 - Numeric Menu
    cout << "Make your first move. [1, 2, or 3]" << endl;
    cout << "1. Roll" << endl;
    cout << "2. Hold" << endl;
    cout << "3. Quit" << endl;
    cout << "" << endl;
  
  while (!game_end_boolean) {
  // get user input for their desired action.
    turn_points = player_user_rolls(player_total_points, userName);
    
    player_total_points = turn_points + player_total_points;
    
    if (player_total_points >= 100) {
      game_end_boolean = true;
      }
    else {
      cout << "" << endl;
// Specification B1 - Display Turn Stats
      cout << userName << "'s toal score: " << player_total_points << endl; 
      cout << "CPU's total score: " << cpu_total_points << endl;
      cout << "" << endl;
      cout << "It is the CPU's turn : "<<endl;
      turn_points = cpu_auto_rolls(cpu_total_points);

      cpu_total_points = cpu_total_points + turn_points;
      
      if (cpu_total_points >= 100)
        game_end_boolean = true;
      }
    
  } // bracket for game_end_boolean 

  cout << userName << "'s total score is: " << player_total_points << endl;
  cout << "CPU's total score is: " << cpu_total_points << endl;

  if (player_total_points >= 100) {
    cout << userName << " wins! Congratulations!";
  }
  else {
    cout << "CPU won Pig Dice this time.." << endl;
    cout << "" << endl; 
    cout << "try again?" << endl;
  }
  
return 0;
} //brakcet for main()

// Specification C4 - ProgramGreeting
void ProgramGreeting() {
  cout << R"(
   _     _____ _     _     ____                  
/ \ /|/  __// \   / \   /  _ \                 
| |_|||  \  | |   | |   | / \|                 
| | |||  /_ | |_/\| |_/\| \_/|                 
\_/ \|\____\\____/\____/\____/                 
                                               
                                               
                                               
        _____   _____                          
        \____\  \____\                         
_____                   _____   _____          
\____\                  \____\  \____\         
                   _                           
                  /.\                          
                  \ _\_                        
                  /|/ /                        
                  \__/\                        
                                               
 _      _____ _     ____  ____  _      _____ _ 
/ \  /|/  __// \   /   _\/  _ \/ \__/|/  __// \
| |  |||  \  | |   |  /  | / \|| |\/|||  \  | |
| |/\|||  /_ | |_/\|  \_ | \_/|| |  |||  /_ \_/
\_/  \|\____\\____/\____/\____/\_/  \|\____\(_)  
  )" << '\n';
}
void ruleExplanation() {
  char yesNo;
  cin >> yesNo;
  if (yesNo == 'y' || yesNo == 'Y') {
    cout << "Great, lets get your dice and start rolling!" << endl;
  } else {
    cout << "This pig dice game allows the player to roll a 6 sided die "
            "against the CPU"
         << endl;
    cout << "" << endl;
    cout << "You will have 3 options when it is your turn:" << endl;
    cout << "1. ROLL" << endl;
    cout << "2. HOLD" << endl;
    cout << "3. QUIT" << endl;
    cout << "" << endl;
    cout << "If you ROLL a 2, 3, 4, 5 or 6 on the die, those cooresponding "
            "numbers are added as points to your turn points"
         << endl;
    cout << "" << endl;
    cout << "if you ROLL a 1, you will lose your turn points for the turn and "
            "the CPU will begin their turn"
         << endl;
    cout << "At any point during your turn, you may HOLD." << endl;
    cout << "A HOLD will add all of your turn points to your total score"
         << endl;
    cout << "" << endl;
    cout << "The first player to 100 points wins." << endl;
  }
}

// Specification A2 - RandomNumber() function
int D6() {
return (rand()%6) + 1;  
}

//this function returns an integer that can be used for the turn points for the player
int player_user_rolls (int player_total_points, string userName) {
int turn_points = 0;
int make_a_move;
int dice_face_for_turn;

  cin >> make_a_move;
while(make_a_move == 1) {
// int dice face is calling the D6()
  dice_face_for_turn = D6();
    cout << userName << " rolled a " << dice_face_for_turn << "." << endl;
//if the D6() roll is a 1, the turn points are set to 0  
      if (dice_face_for_turn == 1) {
        make_a_move = 2;
        turn_points = 0;
      }
        else { 
          turn_points = dice_face_for_turn + turn_points; 
          cout << userName << "'s score for this turn is: "<< turn_points << endl;
          cout << "" << endl;
// input if the user wants to roll or hold
          cout << "Enter 1 to ROLL again " << endl;
          cout << "Enter 2 to HOLD: ";
          cout << "" << endl;
            cin >> make_a_move;
        }
}
cout << userName << "'s turn score is: " << turn_points << endl;
  
return turn_points;
}


/* 
Make a simple AI with a random number. Each tun decide what 
the computer will do by rolling a 6 sided die, a D6: on 1-3 hold, on
a 4-6 roll again.
*/

int cpu_auto_rolls(int cpu_total_points) {
int turn_points = 0; int dice_face_for_turn;
bool cpu_finish_boolean= false;
  
  while(!cpu_finish_boolean) {
//check later that this can recall the function without error = rollDie();
    dice_face_for_turn = D6();
    cout << "CPU Rolled: " << dice_face_for_turn << endl;
  
  if (dice_face_for_turn == 1 || dice_face_for_turn == 2 || dice_face_for_turn == 3) {
    turn_points = turn_points + dice_face_for_turn;
    cpu_finish_boolean = true;
  } 
    else if (dice_face_for_turn==4 || dice_face_for_turn == 5 || dice_face_for_turn == 6) {
      turn_points = 0;
      cpu_finish_boolean=true;
      }
      cout <<"CPU's Turn Score: " << turn_points << endl;
      cout << "" << endl;
}
return turn_points;
}  
