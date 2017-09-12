/** 
 *  @file    sort_source.cpp
 *  @author  Ujjal Sikdar (ujjal.sikdar@gmail.com)
 *  @date    10/09/2017  
 *  @version 1.0 
 *  
 *  @brief US -1, PC, Source file for sorting number based on Occurence  
 *
 *  @section DESCRIPTION
 *
 *      An array of integers, arr, of size N is defined as {a 0 , a 1 , ..., a N‐1 }.
 *
 *      Complete the customSort function declared in your editor. It must take arr as a parameter, sort its
 *      elements in order of ascending frequency, and then print each element of the sorted array as a
 *      new line of output. If 2 or more elements have the same frequency, this subset of elements should
 *      be sorted in non‐decreasing order.
 *
 *      Input Format
 *      The locked stub code in the editor handles reading input from stdin, assembling it into an array of
 *      integers ﴾arr﴿, and calling the sort function. The first line of input contains an integer, N ﴾the
 *      number of elements﴿. Each line i of the N subsequent lines describes array element arr[i].
 *
 *      Constraints
 *      1 ≤ N ≤ 2 × 10 5
 *      1 ≤ a i ≤ 10 6
 *
 *      Output Format
 *      Your customSort function should print the sorted ﴾in order of non‐decreasing frequency﴿ elements
 *      of array arr. If 2 or more elements have the same frequency, this subset of elements should be
 *      sorted in non‐decreasing order. Each element must be printed on a new line.
 *  
 *  This is a Header File which accept input and implements  
 *  Function required for the Sorting number.
 *  User input are provided for the input number 
 *  The result is stored in sorted way based on the Occurence  
 *  
 */




#include "sort_header.h"

/* Implement the Constructor */
Sort_Based_on_Occurence :: Sort_Based_on_Occurence() 
{
     /*Initialize all the variables here */
}


/*Implement the Destructor */
Sort_Based_on_Occurence :: ~Sort_Based_on_Occurence()
{
   /*Destroy all the variables what is declared or defined either dynamic or static */
}

/*Implement the Display fucntion of the vector */
void Sort_Based_on_Occurence :: display_myvector(std::vector <unsigned int> &myvector)
{
    for(auto i:myvector)
       std::cout<< i << " ";
}

/*Implement the Display fucntion of the vector */
void Sort_Based_on_Occurence ::display_mymap(std::map<unsigned int,unsigned int> & mymap)
{
    for(auto i: mymap)
        std::cout<<i.first <<"  " <<i.second<<endl;
}

/*Implement the insertion of the function for Occurence finding */
void Sort_Based_on_Occurence:: insert_map(std::vector<unsigned int> myvector,std::map<unsigned int,unsigned int>&mymap)
{
    for(auto i : myvector)
    {
       if(mymap.count(i) >=1)
           mymap[i]=mymap[i]+1;
       else
           mymap[i]=1;
    }
}





