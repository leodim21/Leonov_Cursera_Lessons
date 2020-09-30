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

#ifndef __TES1_H__
#define __TES1_H__

/*********************************************************************
 * @fn      print_statistics
 *
 * @brief   print statistic data as maximum, minimum, mean and mediana.
 *
 * @param   data_stat - pointer to statistic data array
 * 
 * @param   size - size of data array
 *
 * @return  none
 */
void print_statistics(unsigned char *data_stat, unsigned int size);

/*********************************************************************
 * @fn      print_array
 *
 * @brief   print data from array.
 *
 * @param   data - pointer to data array
 * 
 * @param   size - size of data array
 *
 * @return  none
 */
void print_array(unsigned char *data, unsigned int size);

/*********************************************************************
 * @fn      find_median
 *
 * @brief   Calculate median from data array
 *
 * @param   data - pointer to data array
 * 
 * @param   size - size of data array
 *
 * @return  median as unsigned char
 */
unsigned char find_median(unsigned char *data, unsigned int size);

/*********************************************************************
 * @fn      find_mean
 *
 * @brief   Calculate mean from data array
 *
 * @param   data - pointer to data array
 * 
 * @param   size - size of data array
 *
 * @return  mean as unsigned char
 */
unsigned char find_mean(unsigned char *data, unsigned int size);

/*********************************************************************
 * @fn      find_maximum
 *
 * @brief   Calculate maximum from data array
 *
 * @param   data - pointer to data array
 * 
 * @param   size - size of data array
 *
 * @return  maximum as unsigned char
 */
unsigned char find_maximum(unsigned char *data, unsigned int size);

/*********************************************************************
 * @fn      find_minimum
 *
 * @brief   Calculate maximum from data array
 *
 * @param   data - pointer to data array
 * 
 * @param   size - size of data array
 *
 * @return  minimum as unsigned char
 */
unsigned char find_minimum(unsigned char *data, unsigned int size);

/*********************************************************************
 * @fn      sort_array
 *
 * @brief   sort data array.
 *
 * @param   data - pointer to data array
 * 
 * @param   size - size of data array
 *
 * @return  none
 */
void sort_array(unsigned char *data, unsigned int size);

#endif