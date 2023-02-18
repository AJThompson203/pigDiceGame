// Specification B2 - Source File Header
//  pig.cpp
//  Anthony Thompson, CISP 400
//  1/23/23
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Declaration of the functions that I am using, all are named in self
// explanatory manner
void ProgramGreeting();
void ruleExplanation();
int D6();
int player_user_rolls(int player_total_points, string userName);
int cpu_auto_rolls(int cpu_total_points);
int randomNumber(int low_dice_roll_in, int high_dice_roll_int);
void hiScoreOutput(int hiScore, int player_total_points);

/* int dice_face, min_dice_face = 1, max_dice_face = 6, dice_face__;
  int counter = 0;
*/

int main() {
  // Specification C1 - Fixed Seed
  // int randomNum = rand() % 6+1;
  srand(time(NULL));
  string userName;
  int turn_points;
  int cpu_total_points;
  int player_total_points;
  bool game_end_boolean = false;
  int hiScore;
  
  // the integer pointer = adress of
  int *ptr_to_hiScore = new int;
  *ptr_to_hiScore = 0;
  if (NULL == ptr_to_hiScore) {
    cout << "failed pointer" << endl;
  }
  // Specification C4 - ProgramGreeting
  ProgramGreeting();

  // menu prompt function to the user
  cout << "lets begin!" << endl ;
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
    } else {
      cout << "" << endl;
      // Specification B1 - Display Turn Stats
      cout << userName << "'s toal score: " << player_total_points << endl;
      cout << "CPU's total score: " << cpu_total_points << endl;
      cout << "" << endl;
      cout << "It is the CPU's turn : " << endl;
      turn_points = cpu_auto_rolls(cpu_total_points);

      cpu_total_points = cpu_total_points + turn_points;

      if (cpu_total_points >= 100)
        game_end_boolean = true;
      cout << "Roll again?";
      cout << "" << endl;
    }

  } // bracket for game_end_boolean

  cout << userName << "'s total score is: " << player_total_points << endl;
  cout << "CPU's total score is: " << cpu_total_points << endl;

  if (player_total_points >= 100) {
    cout << userName << " wins! Congratulations!";
  } else {
    cout << "CPU won Pig Dice this time.." << endl;
    cout << "" << endl;
  }

  cout << "" << endl;
  cout << "" << endl;
  // Specification B4 – Display hiScore
  cout << "Your high score was " << player_total_points << endl;
  cout << "Do you think you can score higher?" << endl;
  cout << "Hint: try and keep rolling on your last turn!";

// Specification B3 - hiScore on Heap  
  hiScore = player_total_points;
  if (player_total_points >= *ptr_to_hiScore) {
    *ptr_to_hiScore = player_total_points;
  }
  return 0;
} // brakcet for main()

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
int D6() { return (rand() % 6) + 1; }

// this function returns an integer that can be used for the turn points for the
// player
int player_user_rolls(int player_total_points, string userName) {
  int turn_points = 0;
  int make_a_move;
  int dice_face_for_turn;

  cout << "Please make your first move: " << endl;
  cin >> make_a_move;
  // Specification A4 - Input Validation
  while (make_a_move == 1) {
    // int dice face is calling the D6()
    dice_face_for_turn = D6();
    cout << userName << " rolled a " << dice_face_for_turn << "." << endl;
    // if the D6() roll is a 1, the turn points are set to 0
    if (dice_face_for_turn == 1) {
      make_a_move = 2;
      turn_points = 0;
    } else {
      turn_points = dice_face_for_turn + turn_points;
      cout << userName << "'s score for this turn is: " << turn_points << endl;
      cout << "" << endl;
      // input if the user wants to roll or hold
      cout << "Enter 1 to ROLL again " << endl;
      cout << "Enter 2 to HOLD: " << endl;
      cout << "Enter 3 to QUIT" << endl;
      cin >> make_a_move;
    }
  }
  cout << userName << "'s turn score is: " << turn_points << endl;
  return turn_points;
}

// code for randomNumber() function
/* while (counter == 0) {
    dice_face = 0;
    dice_face__ = randomNumber(min_dice_face,max_dice_face);
    cout << " dice roll: " << dice_face__ << endl;
  counter++;
//
  if (dice_face__ !== 1 || dice_face__ !== 2 || 3 || 4 || 5 || 6) {
    cout << "Error with code"
  }

}
*/

/*
Make a simple AI with a random number. Each tun decide what
the computer will do by rolling a 6 sided die, a D6: on 1-3 hold, on
a 4-6 roll again.
*/

int cpu_auto_rolls(int cpu_total_points) {
  int turn_points = 0;
  int dice_face_for_turn;
  bool cpu_finish_boolean = false;

  while (!cpu_finish_boolean) {
    // check later that this can recall the function without error = rollDie();
    dice_face_for_turn = D6();
    cout << "CPU Rolled: " << dice_face_for_turn << endl;

    if (dice_face_for_turn == 1 || dice_face_for_turn == 2 ||
        dice_face_for_turn == 3) {
      turn_points = turn_points + dice_face_for_turn;
      cpu_finish_boolean = true;
    } else if (dice_face_for_turn == 4 || dice_face_for_turn == 5 ||
               dice_face_for_turn == 6) {
      turn_points = 0;
      cpu_finish_boolean = true;
    }
    cout << "CPU's Turn Score: " << turn_points << endl;
    cout << "" << endl;
  }
  return turn_points;
}



// Specification A2 - RandomNumber() function
/*

int randomNumber(int low_dice_roll_in, int high_dice_roll_int){
    return rand() % ((high_dice_roll_int - low_dice_roll_in) + 1) +
low_dice_roll_in;
}

*/
/*


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
  
lets begin!

What is your name?
Tony
Tony, Do you know how to play the pig game? (y/n)
n
This pig dice game allows the player to roll a 6 sided die against the CPU

You will have 3 options when it is your turn:
1. ROLL
2. HOLD
3. QUIT

If you ROLL a 2, 3, 4, 5 or 6 on the die, those cooresponding numbers are added as points to your turn points

if you ROLL a 1, you will lose your turn points for the turn and the CPU will begin their turn
At any point during your turn, you may HOLD.
A HOLD will add all of your turn points to your total score

The first player to 100 points wins.
Make your first move. [1, 2, or 3]
1. Roll
2. Hold
3. Quit

Please make your first move: 
1
Tony rolled a 4.
Tony's score for this turn is: 4

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 6.
Tony's score for this turn is: 10

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 4.
Tony's score for this turn is: 14

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
2
Tony's turn score is: 14

Tony's toal score: 14
CPU's total score: 0

It is the CPU's turn : 
CPU Rolled: 1
CPU's Turn Score: 1

Roll again?
Please make your first move: 
1
Tony rolled a 1.
Tony's turn score is: 0

Tony's toal score: 14
CPU's total score: 1

It is the CPU's turn : 
CPU Rolled: 4
CPU's Turn Score: 0

Roll again?
Please make your first move: 
1
Tony rolled a 5.
Tony's score for this turn is: 5

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 2.
Tony's score for this turn is: 7

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 2.
Tony's score for this turn is: 9

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
2
Tony's turn score is: 9

Tony's toal score: 23
CPU's total score: 1

It is the CPU's turn : 
CPU Rolled: 1
CPU's Turn Score: 1

Roll again?
Please make your first move: 
1
Tony rolled a 2.
Tony's score for this turn is: 2

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 1.
Tony's turn score is: 0

Tony's toal score: 23
CPU's total score: 2

It is the CPU's turn : 
CPU Rolled: 1
CPU's Turn Score: 1

Roll again?
Please make your first move: 
1
Tony rolled a 5.
Tony's score for this turn is: 5

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 3.
Tony's score for this turn is: 8

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 3.
Tony's score for this turn is: 11

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 4.
Tony's score for this turn is: 15

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
2
Tony's turn score is: 15

Tony's toal score: 38
CPU's total score: 3

It is the CPU's turn : 
CPU Rolled: 1
CPU's Turn Score: 1

Roll again?
Please make your first move: 
1
Tony rolled a 4.
Tony's score for this turn is: 4

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 4.
Tony's score for this turn is: 8

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 3.
Tony's score for this turn is: 11

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 3.
Tony's score for this turn is: 14

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 6.
Tony's score for this turn is: 20

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 4.
Tony's score for this turn is: 24

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
2
Tony's turn score is: 24

Tony's toal score: 62
CPU's total score: 4

It is the CPU's turn : 
CPU Rolled: 1
CPU's Turn Score: 1

Roll again?
Please make your first move: 
1
Tony rolled a 5.
Tony's score for this turn is: 5

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 5.
Tony's score for this turn is: 10

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 3.
Tony's score for this turn is: 13

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 1.
Tony's turn score is: 0

Tony's toal score: 62
CPU's total score: 5

It is the CPU's turn : 
CPU Rolled: 1
CPU's Turn Score: 1

Roll again?
Please make your first move: 
1
Tony rolled a 4.
Tony's score for this turn is: 4

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 2.
Tony's score for this turn is: 6

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 6.
Tony's score for this turn is: 12

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 6.
Tony's score for this turn is: 18

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
2
Tony's turn score is: 18

Tony's toal score: 80
CPU's total score: 6

It is the CPU's turn : 
CPU Rolled: 1
CPU's Turn Score: 1

Roll again?
Please make your first move: 
1
Tony rolled a 4.
Tony's score for this turn is: 4

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 3.
Tony's score for this turn is: 7

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 3.
Tony's score for this turn is: 10

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 5.
Tony's score for this turn is: 15

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
2
Tony's turn score is: 15

Tony's toal score: 95
CPU's total score: 7

It is the CPU's turn : 
CPU Rolled: 2
CPU's Turn Score: 2

Roll again?
Please make your first move: 
1
Tony rolled a 4.
Tony's score for this turn is: 4

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 6.
Tony's score for this turn is: 10

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
1
Tony rolled a 6.
Tony's score for this turn is: 16

Enter 1 to ROLL again 
Enter 2 to HOLD: 
Enter 3 to QUIT
2
Tony's turn score is: 16
Tony's total score is: 111
CPU's total score is: 9
Tony wins! Congratulations!

Your high score was 111
Do you think you can score higher?
Hint: try and keep rolling on your last turn!


*/