/*
Find the majority element in the array. A majority element in an array A[] of 
size n is an element that appears more than n/2 times (and hence there is at most one such element). 
Input : A[]={3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Input : A[] = {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
*/

#include <iostream>
#include <algorithm>

int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4} ;
//int arr[] = {3, 3, 4, 2, 4, 4, 2, 4} ;
const int size = sizeof(arr)/sizeof(int) ;
int brr[size];

int check_presence( int ) ;

int main()
{   

//Solution 1
//Time Complexity: O(n^3) , Space Complexity: O(n) 

    int freq, flag = 0 , k=-1;
    for ( int i=0 ; i<size ; i++ )
    {
        freq = 0 ;
        if( !check_presence( arr[i] )  )
        {
            brr[++k] = arr[i] ; 
            for (  int j=0 ; j<size ; j++ )
            {
                if( arr[j] == arr[i] )
                freq ++;
            }
            if( freq > size/2)
            {
                flag = 1  ;
                std :: cout << "Majority Element is: " << arr[i] ;
                break ;
            }
        }

    }
    if( flag == 0 )
        std :: cout << "No Majority Element Present" ; 

std :: cout << "\n" ;

//Solution 2
//Time Complexity: O(n^2) , Space Complexity: O(1) 

    int count = 0 , max_count = 0 , i=-1 ;
    flag = 0  ; 

    std :: sort ( arr , arr + size ) ; 

    while ( ++ i < size )
    {
        for( int j=i ; j<size ; j++ )
        {
            if( arr[j] == arr[i] )
            {
                count ++ ;
                max_count = std :: max ( max_count , count ) ;
                if( max_count > size/2 )
                {
                    flag = 1 ;
                    std :: cout << "Majority Element is: " << arr[i] ;
                    break ;
                }

            }
            i=j ;
            break ;
        }
        if ( flag == 1 )
            break;
    }
    if( flag == 0 )
        std :: cout << "No Majority Element Present";

std :: cout << "\n" ;

//Solution 3
//Time Complexity: O(n) , Space Complexity: O(1)

    int crr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4} ;

    int candidate = -1 , votes = 0 ;
    for ( int i=0 ; i<size ; i++ )
    {
        if( votes == 0 )
        {
            candidate = crr[i] ;
            votes = 1; 
        }
        else 
        {
            if ( candidate == crr[i] )
                votes ++;
            else
                votes --;
        }
    }

    count = 0 ;
    for ( int i=0 ; i<size ; i++ )
    {
        if( crr[i] == candidate )
            count ++ ; 
    }

    if( count > size/2 )
        std :: cout << "Majority Element is: " << crr[i] ;
    else 
         std :: cout << "No Majority Element Present" ;

}

int check_presence( int ele ) 
{
    for( int i=0 ; i< size ; i++ )
    {
        if ( ele == brr[i] )
            return 1 ;
    }
    return 0 ;
}


