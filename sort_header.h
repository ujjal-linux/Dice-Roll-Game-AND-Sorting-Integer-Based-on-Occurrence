/** 
 *  @file    sort_header.h
 *  @author  Ujjal Sikdar (ujjal.sikdar@gmail.com)
 *  @date    10/09/2017  
 *  @version 1.0 
 *  
 *  @brief US -1, PC, Header file for sorting number based on Occurence  
 *
 *  @section DESCRIPTION
 *
 *	An array of integers, arr, of size N is defined as {a 0 , a 1 , ..., a N‐1 }.
 *
 *	Complete the customSort function declared in your editor. It must take arr as a parameter, sort its
 *	elements in order of ascending frequency, and then print each element of the sorted array as a
 *	new line of output. If 2 or more elements have the same frequency, this subset of elements should
 *	be sorted in non‐decreasing order.
 *
 *	Input Format
 *	The locked stub code in the editor handles reading input from stdin, assembling it into an array of
 *	integers ﴾arr﴿, and calling the sort function. The first line of input contains an integer, N ﴾the
 *	number of elements﴿. Each line i of the N subsequent lines describes array element arr[i].
 *
 * 	Constraints
 *	1 ≤ N ≤ 2 × 10 5
 * 	1 ≤ a i ≤ 10 6
 *
 *	Output Format
 *	Your customSort function should print the sorted ﴾in order of non‐decreasing frequency﴿ elements
 *	of array arr. If 2 or more elements have the same frequency, this subset of elements should be
 *	sorted in non‐decreasing order. Each element must be printed on a new line.
 *  
 *  This is a Header File which declare all the variable  
 *  and Function required for the Sorting number .
 *  User input are provided for the input number 
 *  The result is stored in sorted way based on the Occurence  
 *  
 */

#ifndef SORTED_BASED_ONCCURENCE_H_INCLUDED
#define SORTED_BASED_ONCCURENCE_H_INCLUDED

#include <functional>
#include <string.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

template < typename A, typename B >

using wrapped_pair = std::pair< std::reference_wrapper<A>, std::reference_wrapper<B> > ;

struct cmp_wrapped_pair

{
	template < typename A, typename B > bool operator() ( const A& a, const B& b ) const
	{
		return a.first.get() < b.first.get() ||
			( !( b.first.get() < a.first.get() ) && a.second.get() < b.second.get() ) ;
	}
};

class Sort_Based_on_Occurence
{
      
       public : 
        
        /* Member variables declared here */
        std::vector<unsigned int> myvector;
        std::map<unsigned int,unsigned int> mymap;

        /* Utility function for the sorting of the number based on the Occurence */
	template < typename MAP_TYPE >
	auto sorted_based_on_occurence( const MAP_TYPE& map ) // auto: function return type deduction is C++14
        {

             using KEY = typename MAP_TYPE::key_type ;
             using VALUE = typename MAP_TYPE::mapped_type ;
             std::multiset< wrapped_pair< const VALUE, const KEY >, cmp_wrapped_pair > sortedarray ;
             for( auto& pair : map ) sortedarray.emplace( pair.second, pair.first ) ;
             return sortedarray ;
        }

        /* Display funtion for various Data structure  */
	void display_myvector(std::vector <unsigned int> &myvector);
	void display_mymap(std::map<unsigned int,unsigned int> & mymap);
	void insert_map(std::vector<unsigned int> myvector,std::map<unsigned int,unsigned int>&mymap);

        /* constructor and Destructor */
        Sort_Based_on_Occurence();
        ~Sort_Based_on_Occurence();

       private : 
        /* Restriction on copy , assignment operator etc..  */
       Sort_Based_on_Occurence(const Sort_Based_on_Occurence &);
       Sort_Based_on_Occurence operator = (const Sort_Based_on_Occurence &);
};

#endif 
