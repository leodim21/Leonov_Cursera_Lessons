/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <A C-programming code which sorts the array and calculates statistical parameters of a character array
 		- Median
		- Mean
		- Maximum Number
		- Minimum Number
		>
 *
 *
 * @author <Dima Leonov>
 * @date <12th September 2020>
 *
 */
#define IN_ARRAY_SIZE   40
#define STAT_ARRAY_SIZE 4

#define MEAN_STAT_BYTE     0
#define MAXIMUM_STAT_BYTE  1
#define MINIMUM_STAT_BYTE  2
#define MEDIAN_STAT_BYTE   3

#include "stats.h"
#include "platform.h"

unsigned char stat_array[STAT_ARRAY_SIZE] = { 0, 0, 0, 0 };

  unsigned char in_array[IN_ARRAY_SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                          114, 88,   45,  76, 123,  87,  25,  23,
                                          200, 122, 150, 90,   92,  87, 177, 244,
                                          201,   6,  12,  60,   8,   2,   5,  67,
                                            7,  87, 250, 230,  99,   3, 100,  90 };


void print_statistics(unsigned char *data_stat, unsigned int size)
{
   PRINTF("Statistics:\n");
   PRINTF( "maximum: | %d |\n", stat_array[MAXIMUM_STAT_BYTE] );
   PRINTF( "minimum: | %d |\n", stat_array[MINIMUM_STAT_BYTE] );
   PRINTF( "median:  | %d |\n", stat_array[MEDIAN_STAT_BYTE] );
   PRINTF( "mean:    | %d |\n", stat_array[MEAN_STAT_BYTE] );
}

void print_array(unsigned char *data, unsigned int size)
{
   #ifdef VERBOSE
   PRINTF("input array: |");
   #endif
   for(int i = 0; i < size; i++)
   {
      #ifdef VERBOSE
      PRINTF(" %d |", data[i]);
      #endif
   }
   #ifdef VERBOSE
   PRINTF("\n");
   #endif
}

unsigned char find_median(unsigned char *data, unsigned int size)
{
   sort_array(data, size);
   return data[size/2];
}
unsigned char find_mean(unsigned char *data, unsigned int size)
{
   int data_sum = data[0];
   for(int i = 1; i < size; i++)
   {
      data_sum += data[i];
   }
   return (data_sum/size);
}
unsigned char find_maximum(unsigned char *data, unsigned int size)
{
   unsigned char tmp = data[0];
   for(int i = 1; i < size; i++)
   {
       if( tmp < data[i] ) tmp = data[i];
   }
   return tmp;
}
unsigned char find_minimum(unsigned char *data, unsigned int size)
{
   unsigned char tmp = data[0];
   for(int i = 1; i < size; i++)
   {
       if( tmp > data[i] ) tmp = data[i];
   }
   return tmp;
}
void sort_array(unsigned char *data, unsigned int size)
{
   int newElement, location;
 
    for (unsigned int i = 1; i < size; i++)
    {
        newElement = data[i];
        location = i - 1;
        while(location >= 0 && data[location] < newElement)
        {
            data[location+1] = data[location];
            location = location - 1;
        }
        data[location+1] = newElement;
    }
}