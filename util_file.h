/** 
 *  @file    util_file.h
 *  @author  Ujjal Sikdar (ujjal.sikdar@gmail.com)
 *  @date    10/09/2017  
 *  @version 1.0 
 *  
 *  @brief US -1, PC, utility function  file
 *
 *  @section DESCRIPTION
 *  
 *  This is main file where the  all the utility function are implemented here  
 *  This can be extended for various functionalities and new feature in future
 *  
 */

#include "dice.h"
#include "sort_header.h"



/* Function to clear the screen 
*  This function has to be extended for all the platform 
*
*  @param : NONE 
*
*  @return : NONE 
*/
void clear_screen()
{
     /*Windows system */
#ifdef __WIN32
       system("cls");
#else
     /*Linux will work ,posix will work but MAC need to adapt ,I don't have MAC */
       system("clear");
#endif
}


/* Function for input  the integer data
*  This function also check for the validation  
*
*  @param : NONE 
*
*  @return : NONE 
*/
int getInt()
{
     int x=0;
     bool flag =false;

     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
     
     while (!flag)
     {
       if (!(cin >> x))
       {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout << "Please input a proper 'whole Positive number' number: " << endl;
         continue;
       }
       else if ( !isspace(cin.peek()) )
       {   
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
         cout << "Please input a proper 'whole Positive number' number: " << endl;
         continue;
       }
      
       if ( 0 > x )
       {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout << "Please input a proper 'whole Positive number' number: " << endl;
         continue;
       }
       else
          flag=true;	
     }
     return (x);
}


/* Function to Play the Dice Game  
*  This function has to be extended for all the platform 
*
*  @param : NONE 
*
*  @return : NONE 
*/
void Play_Dice_Game ()
{
        unsigned int no_of_player_input=0,no_of_iteration=0;
        char enable_log;
        std::string filename;
        std::string time_spent;
     
        /*clear the Screen */
        clear_screen();

        /* Input for the number of player/Dice */
        std::cout << "\n Enter the number of Dices you want to play with: ";
        no_of_player_input = getInt();

        /* Input for the number of Simulation */
        std::cout << "\n Enter the number of Simulation you want : " ;
        no_of_iteration = getInt();

        /* Input for the Logging enable in File/Syslog */
        std::cout << "\n Do you want to enable the log ? (press Y/y for [Yes] OR anykey for [NO]) : " ;
        std::cin >> enable_log;


        /* Calculate the time now */
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

         /* start logging into syslog from now */
         syslog(LOG_NOTICE, "Program started by Use for Dice Game  %d", getuid ());

        /* Create the Game Object to play around */
        Dice game(no_of_player_input,no_of_iteration);

        /* Enable the log in File/Syslog */
        if(enable_log == 'Y' || enable_log =='y')
        {
                /* Input for the Logging File name  */
                std::cout << "\n Please Enter the file-name for logging [ ] : " ;
                std::cin >> filename;
                game.log_into_file(filename);
        }

        /* Start the game using the object created */
        game.play_game();

        /* Calculate after the result */
        std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

        /* Display the result for the Simulation */
        game.display_result();

        time_spent+= "Total Simulation took  "
            + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>
                           (end - begin).count()/(Conver_microSec_to_Second))
            + " Seconds\n";
        std::cout<<time_spent;
        /*Write the log in file if enable */
        if(enable_log == 'Y' || enable_log =='y')
        {
           game.log_into_file(time_spent);
        }

        syslog(LOG_NOTICE, "Program Finished  by User for Dice Game %d", getuid ());

};


/* Function to do the Sorting based on the Occurence   
*  This function has to be extended for all the platform 
*
*  @param : NONE 
*
*  @return : NONE 
*/
void Do_Sorting_based_on_occurence()
{
    unsigned int input;
    bool inputIsValid = false ;
    Sort_Based_on_Occurence sort_object;
    
    /*clear the Screen */
    clear_screen();
   
    syslog(LOG_NOTICE, "Program started by Use for Sorting Program   %d", getuid ());
    
    cout << "Enter any number between 1 to 10 \n [0 to end ] && "
            "[ANY OTHER NUMBER,Negative Integer ,character  WILL BE DISCAREDED ] : \n " ;
    while ( !inputIsValid )
    {
         cin >> input ;
         if (!cin)
         {       
             cout << "\n Invalid input detected [Rest valid integere are discarded after error one ]. \n \n " ;
             cout << "\n Enter any number between 1 to 10 [0 to end] : " ;
             // clear error state in cin:
             cin.clear() ;
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
         }
	 else if ( !isspace(cin.peek()) )
         {   
             cout << "\n Invalid input detected [Rest valid integere are discarded after error one ]. \n \n " ;
             cout << "\nEnter any number between 1 to 10 [0 to end] : " ;
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
         }
         else
         {
             if (input >= 10)
	        continue;
	     if(0 == input)
	        break;
	     else
                sort_object.myvector.push_back (input);
	}
    }

    /* Display the Vector which is populated */
    std::cout << "===================================================== \n";
    std::cout << "The stored value are : \n";
    sort_object.display_myvector(sort_object.myvector);

   /*Insert all the element into map with number of occuranc*/
   sort_object.insert_map(sort_object.myvector,sort_object.mymap);

   /*This is the final step to check */
   sort_object.myvector.clear();

   /* print a sorted (values, then keys) snapshot of the map */
   for( const auto& pair : sort_object.sorted_based_on_occurence(sort_object.mymap) )
    {
        for(unsigned int i=0;i<pair.first.get();i++)
         {
             sort_object.myvector.push_back(pair.second.get());
         }
    }                                       
   std::cout << "\n===================================================== \n";
   std::cout << " \n The Final Result Sorted  based on Occurence :  " << " \n ";
   sort_object.display_myvector(sort_object.myvector);
   std::cout << "\n===================================================== \n";
   syslog(LOG_NOTICE, "Program Finished  by User for Sorting Program  %d", getuid ());
}


                                                    
