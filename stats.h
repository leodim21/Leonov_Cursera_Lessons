#ifndef __TES1_H__
#define __TES1_H__

#include <stdio.h>

void print_statistics(unsigned char *data_stat, unsigned int size);
void print_array(unsigned char *data, unsigned int size);
unsigned char find_median(unsigned char *data, unsigned int size);
unsigned char find_mean(unsigned char *data, unsigned int size);
unsigned char find_maximum(unsigned char *data, unsigned int size);
unsigned char find_minimum(unsigned char *data, unsigned int size);
void sort_array(unsigned char *data, unsigned int size);

#endif