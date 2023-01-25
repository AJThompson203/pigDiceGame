// Specification B2 - Source File Header
//  pig.cpp
//  Anthony Thompson, CISP 400
//  1/23/23
#include <cstdlib>
#include <iostream>
using namespace std;

void ProgramGreeting();
void ruleExplanation();
void srand(int seed);
int main() {
  string userName;
  int make_a_move;
  int dice_face_for_turn = 0;
  int turn_points = 0;
  int total_points = 0;

  // beginning asci greeting function
  ProgramGreeting();

  // menu prompt function to the user
  cout << "lets begin!" << endl;
  cout << '\n';
  cout << "What is your name?" << endl;
  // getting the userName to refer to the player, trying to make it feel more
  // personable
  getline(cin, userName);
  // ideally they will press no, but for someone who plays a second or third
  // time they may not want the screen clutter
  cout << userName << ", Do you know how to play the pig game? (y/n)" << endl;
  ruleExplanation();

  // Specification C3 - Numeric Menu
  cout << "Make your first move. [1, 2, or 3]" << endl;
  cout << "1. Roll" << endl;
  cout << "2. Hold" << endl;
  cout << "3. Quit" << endl;
  // get user input for their desired action.
  cin >> make_a_move;
  while (make_a_move == 1) {
    dice_face_for_turn = rand() % 6 + 1;
    cout << "you rolled a " << dice_face_for_turn << "." << endl;
    if (dice_face_for_turn != 1) {
      turn_points = (turn_points + dice_face_for_turn);
      // Specification B1 - Display Turn Stats
      cout << "Turn Points: " << turn_points << endl;
      cout << "Total score for " << userName << ": " << total_points << endl;
      cin >> make_a_move;
    } else {
      cout << "Rolling a " << dice_face_for_turn
           << " means you lose your turn and the CPU will roll" << endl;
      break;
    }
  }

  return 0;
}
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
 