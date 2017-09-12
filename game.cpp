/** 
 *  @file    game.cpp
 *  @author  Ujjal Sikdar (ujjal.sikdar@gmail.com)
 *  @date    10/09/2017  
 *  @version 1.0 
 *  
 *  @brief US -1, PC, Dice Rolling Game Main file
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
 *  This is main file where the game will be played. The Game is started with object of 
 *  Dice and using the object all the game step are played.
 *  
 */


#include "util_file.h"
#include <limits>
  

/* Implement the main function for the game functionalities */
int main()
{
       /* Variables and user input screem */ 
       unsigned int choice;
       bool flag=true;

       while(flag)
       {       
          /*clear the screen */
          clear_screen();

          std::string str_input; 
          str_input += "\n \n \n \t \tWelcome to the console : \n \n \n ";
          str_input += "\t \tPlease find the below option : \n\n";
          str_input += "\t \t..................................\n\n";
          str_input += "\t \tPress '1' for Dice Game : \n\n";
          str_input += "\t \tPress '2' for Sorting number based on Occurence : \n\n";
          str_input += "\t \tPress any other Number  to exit : \n\n";
          str_input += "\t \t..................................\n\n\n";
          str_input += "\t \t Enter Your Choice : ";

          /* Now accept the choice from the user */
          std ::cout << str_input ;
          std ::cin >> choice;
          if (!cin)
          {
               cout << "\n Invalid input detected \n \n " ;
               // clear error state in cin:
               cin.clear() ;
               cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
               cout << "\n Press Enter for Main Menu .........";
               cin.get();
               continue;
           }
           else if ( !isspace(cin.peek()) )
           {
               cout << "\n Invalid input detected \n \n " ;
               cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
               cout << "\n Press Enter for Main Menu .........";
               cin.get();
               continue;
           }

      
          /* Now call the function depends on the choice given */
          switch (choice) 
          {
             case 1 :
          	    {
          		/* play the Dice Roll Game */
               		Play_Dice_Game();
                        std::cout << "\nPress ENTER to continue..." << std::flush;
			std::cin.get();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			std::cout<< std::flush;
               		break;
          	    }
             case 2 :
                    {
                        /* play the Sorting Number  */
                        Do_Sorting_based_on_occurence();
                        std::cout << "\nPress ENTER to continue..." << std::flush;
			std::cin.get();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<< std::flush;
                        break;  
                    }
             default : 
		std::cout << " \n \n Exiting from  program ................."\
				"\n\n\t\tBYE for Now \n\n\n";
                exit(0);
           }
       }
       return 0;
}
