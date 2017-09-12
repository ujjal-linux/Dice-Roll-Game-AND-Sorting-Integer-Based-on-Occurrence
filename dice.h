/** 
 *  @file    dice.h
 *  @author  Ujjal Sikdar (ujjal.sikdar@gmail.com)
 *  @date    10/09/2017  
 *  @version 1.0 
 *  
 *  @brief US -1, PC, Dice Rolling Game Header file
 *
 *  @section DESCRIPTION
 *  
 *  There is a game that is played with "n" dice. The objective of the game is to
 *  obtain the lowest possible score. To that end, the rules of the game are as
 *  foll-owsA:ll dice are thrown on a board.
 *      - If there are any 3’s, all the 3’s are taken off the board and a score of 0 is
 *         awarded for this roll.
 *      - If there are not any 3’s, the lowest die is taken off the board and the value
 *         of that lowest die is awarded for this roll.
 *      - The remaining dice are now re-thrown and the same procedure as above is
 *         followed until there are no dice left on the board.
 *      - The total score for the game is the sum of all the rolls. 
 *
 *
 *  This is a Header File which declare all the variable  
 *  and Function required for the Dice Rolling Game.
 *  User input are provided for the number of Dice to play
 *  and also for the no of Simulation as desired.
 *  The result is stored in sorted way based on the total score. 
 *  
 */

#ifndef DICE_ROLLING_H_INCLUDED
#define DICE_ROLLING_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>

using namespace std;

/* Define all the magic number here */
#define  Rolled_Value_is_3 3
#define  Conver_microSec_to_Second 1000000.0
/* Magic Number declarion finished */

/* Class defination for the Rolling Dice Game  */
class Dice 
{
   public :

   //Constructor with argument for no of dice
   Dice(unsigned int no_of_dice,unsigned long no_of_iteration);
  
   //Destructor 
   ~Dice();
 
   /* Public function for the game */
   unsigned int play_game();
 
   /* Public function to display the result */
   void display_result();

   /* Public function to enable the logs in file */
   void log_into_file(std::string filename);
   
   /*Function which are not exposed outside */
   private : 

   /* Default Constructor */
   Dice();

   /* Copy Constructor */
   Dice(const Dice &);

   /* Assignment Operator */
   Dice & operator = (Dice  &);
   
   /* RollDice function to get the random number generation */
   unsigned int rolldice();
   
   /* Public function for the operation */
   unsigned int play_one_iteration(unsigned int noofdice);

   /*Data structure for the No of Dice */
   unsigned int no_of_dice;

   //Data structure for single iteration 
   unsigned int total_score;
    
   /*Data structure for the No of iteration */
   unsigned long no_of_iteration;
   
   //Data structure to store the dice_result;
   std::set<std::pair<unsigned int,unsigned int> > dice_result;

   //Data Structure to store the no of dice to be played and rolled diced value
   std::vector<unsigned int>dice_roll_vector;
  
   /* File hanlding for the Debugging */
   ofstream myfile;
   bool enable_logging_file;
 
};

#endif
