/** 
 *  @file    dice.cpp
 *  @author  Ujjal Sikdar (ujjal.sikdar@gmail.com)
 *  @date    10/09/2017  
 *  @version 1.0 
 *  
 *  @brief US -1, PC, Dice Rolling Game source file
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
 *  This is a implementation File and here all the utility function are implemented.
 *  Random number generato is seeded with initial seed of time stamp for random number
 *  generation.
 *  Function has been implement for the total Score calculation and store the final value 
 *  in container "set" for the "n" number of simulation.
 *  FILE based stree test can be implement for harness.
 *  Further Optimization can be done for larger number. 
 *
 */

#include "dice.h"

/* implementation of the function */

/*
 *  Constructor implementation  with initialization of no_of_player,total_score,srand for 
 *  random generation of the number
 *  @param : no_of_Dices,no_of_iteration for simulation 
 *  @return: Not Applicatble
 *
*/
Dice::Dice (unsigned int no_of_dices,unsigned long no_of_iteration) : 
           no_of_dice(no_of_dices),total_score(0),no_of_iteration(no_of_iteration)
{	
        /*Random number seed initialization  */
        srand((unsigned)time(NULL));

	/*Implementation and iniliatziation of the member variables */
	dice_roll_vector.clear(); //resize based on the no_of_player
	dice_result.clear();
        
        /* Initialize the result with default Values */
        for(unsigned int i=0;i<=(no_of_dice *6);i++)
          dice_result.insert(std::make_pair(i,0));

       /* Set up the logging system for syslog for debug message */
       setlogmask(LOG_UPTO (LOG_NOTICE));
       openlog("ujjal", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL0);
};


/*
 *  Destructor implementation : Please release all the dynamic memory if allocated based
 *  Dependecny logic. 
 *  @param : Not Applicatble 
 *  @return: Not Applicatble
 *
*/
Dice :: ~Dice()
{
    /*Free up any dynamic allocator if memory is allocated based on the usage/logic*/
    /* check if the file is opened and then try to write */
    if (myfile.is_open())
    {
      myfile << "=========================== Log Finished ================================\n";
    }
    /* close the syslog system for logging */
    closelog();
}


/* RollDice function to get the random number generation */
/*
 *  rollDice : Function to generate Random number 
 *             between 1 & 6 based on logic
 *  @param : None 
 *  @return: "int" ==>  The random number which is generate 
 *
*/
unsigned int Dice :: rolldice()
{
    /* Seed has done and now the get the random number generation between 1-6 for dice */
    return rand()%6 +1;
}


/* Function to enable the logging into file */
/*
 *  log_into_file : Function to write operation into file  
 *                  for debugging and other case.
 *  @param        : "std::string" ==> File name to open & store 
 *  @return       : "int" ==>  The random number which is generate 
 *
*/
void Dice :: log_into_file(std::string string_or_filename)
{
   /*check and then Open the file and enable the flag */
   if (myfile.is_open())
   {
     myfile << string_or_filename;
   }else
   {
      enable_logging_file = true;
      string_or_filename+=".txt";
      myfile.open (string_or_filename.c_str());
      myfile << "=========================== Log Enable ================================\n";
   }
}


/*Implementation of the play one iteration of the game to store the value */
/*
 *  play_one_iteration : Function to Play one iteration
 *                         with "n" number of dice. 
 *  @param : "int" ==> Number of Dice to be played. 
 *  @return: "int" ==> Total Score for one game is returned 
 *                      which is stored in ResukltNone 
 *
*/
unsigned int Dice :: play_one_iteration(unsigned int noofDice=5)
{
       unsigned int lowest =6;
       bool found_3_in_rolled_dice = false;
       static unsigned int simulation=0;
       /* Log the value if logging is enable */
       if (enable_logging_file )
       {
          myfile << "\nSimulation No : " << ++simulation << "\n";
       }
       while(noofDice)
       {

          lowest = 6;
          found_3_in_rolled_dice = false; 
          /*First get the rolled dice random number generate and store the value */
          for(unsigned int i=0;i<noofDice;++i)
            dice_roll_vector.push_back(rolldice());

          /* Log the value if logging is enable */
          if (enable_logging_file )
          {
             std::string output;
             for(auto i : dice_roll_vector)
             {
               output +=std::to_string(i)+ " , ";
             };
             myfile << output <<std::endl;
	  }
          
          /*Now check the value is 3 or different and then find the lowest number */
          std::vector<unsigned int>::iterator itr=dice_roll_vector.begin();
          for(;itr!= dice_roll_vector.end();++itr)
          {
             /* Check the value if this is "3" make lowest to "0" and then add the total */
             if( Rolled_Value_is_3 == *itr)
             {
                lowest = 0; 
                found_3_in_rolled_dice = true;
                --noofDice;//This many times the dice will be removed.
             }
             else /* Find the lowest value in the array */
             {
                if(*itr <= lowest && !found_3_in_rolled_dice)
                 {
                    /*Store the lowest value */
                    lowest = *itr;
                 }         
                 
             }
          }

          /* no of dice will be less one if other then 3 found in dice roll */
          if(!found_3_in_rolled_dice)
             --noofDice;

          /* Total the sum with the lowest score and store it */
          this->total_score = this->total_score + lowest;

          /*Clear the vector for the another dice roll itereator after removing the dice */
          dice_roll_vector.clear();
          
       }
       /* Log the value if logging is enable */
       if (enable_logging_file )
       {
          std::string output;
          output+=" Total-Score is "+std::to_string(total_score);
          myfile << output << std::endl;
          myfile << "----------------------------------------" << std::endl;
       }
     return total_score; // Here return value is not required but kept for optimization  
}

/*Implementation of the game for n iteration and storing of the result */
/*
 *  play_game : Function to Play "n" iteration
 *                         with "n" number of dice.
 *		Result are stored in container after verification
 * 
 *  @param : NONE 
 *  @return: "int" ==> This is not required as of now but can be used for future use. 
 *
*/

unsigned int Dice :: play_game()
{
        /* Play the game for the number of time */
        for(unsigned long i=0 ; i < no_of_iteration ;i++)
        {
 		unsigned int total_score_value = play_one_iteration(no_of_dice);
                /* Insert the Total Score in the result vector and if found 
                 * increase the number of frequencey and store the value */
       		auto itr_result = find_if(dice_result.begin(),dice_result.end(),
                  [=](const std::pair <unsigned int,unsigned int> &p){ return (p.first == total_score_value);});
       		if(itr_result != dice_result.end())
      		{
           		dice_result.erase(itr_result);
           		dice_result.insert(std::make_pair(itr_result->first,itr_result->second +1));
       		}
       		/* Make the total score to "0" now for the next term */
       		total_score=0;

        }
        return 0;
}

/*Implementation of the display function for the result.*/
/*
 *   display_result : Function to display the result of the
 *                    Simulation after playing 
 *                    with "n" number of dice.
 *		      Result are stored in container after 
 *                    verification
 *  @param : NONE 
 *  @return: NONE 
 *
*/
void Dice :: display_result()
{
        std::string output;
        output += "\n========================================================";
        output += "\n Number of Dices used   : " + std::to_string(no_of_dice);
        output += "\n Number of Simulations  : " + std::to_string(no_of_iteration);
        output += "\n========================================================\n";

        /* Write to the file if enable */
        if(enable_logging_file)
           myfile << output;
        
        std::cout << output;
        /*std::cout << std::endl << "========================================================" << std::endl;
	std::cout << " Number of Simulations  : " << no_of_iteration << std::endl << std::endl; 
        std::cout << " Number of Dices used   : " << no_of_dice <<  std::endl;
        std::cout << std::endl << "========================================================" << std::endl;*/
        
        for(auto i : dice_result)
        {
             std::ostringstream oss;
             std::string string_output("Total    ");
             string_output=string_output + std::to_string(i.first) + "	Occurs	"
		+std::to_string((double ((double)i.second/(double)no_of_iteration)))+"% 	"
		+"Occured    "+std::to_string(i.second )+"\tTimes";
             std::cout<<string_output<<std::endl;
             /* Write to the file if enable */
             if(enable_logging_file)
                myfile << string_output << "\n";
        }
        std::cout << std::endl << "========================================================" << std::endl;
        /* Write to the file if enable */
        if(enable_logging_file)
          myfile << "========================================================\n";
}




