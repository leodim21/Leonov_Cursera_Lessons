
#define IN_ARRAY_SIZE   40
#define STAT_ARRAY_SIZE 4

#define MEAN_STAT_BYTE     0
#define MAXIMUM_STAT_BYTE  1
#define MINIMUM_STAT_BYTE  2
#define MEDIAN_STAT_BYTE   3

#include "stats.h"

unsigned char stat_array[STAT_ARRAY_SIZE] = { 0, 0, 0, 0 };

unsigned char in_array[IN_ARRAY_SIZE] =  { 1, 4, 0, 2, 5, 3, 10,50, 
                                           4, 2, 2, 1, 4, 43,31,34,
                                           12,13,45,22,11,33,5, 7,
                                           9, 8, 7, 6, 5, 4, 3, 0,
                                           11,12,13,14,16,14,20,2 };

int main() {
   // printf() displays the string inside quotation
   print_array(in_array, IN_ARRAY_SIZE);

   stat_array[MEAN_STAT_BYTE]    = find_mean( in_array, IN_ARRAY_SIZE );
   stat_array[MAXIMUM_STAT_BYTE] = find_maximum( in_array, IN_ARRAY_SIZE );
   stat_array[MINIMUM_STAT_BYTE] = find_minimum( in_array, IN_ARRAY_SIZE );
   stat_array[MEDIAN_STAT_BYTE]  = find_median ( in_array, IN_ARRAY_SIZE );

   printf("sorted ");
   print_array(in_array, IN_ARRAY_SIZE);
   print_statistics(stat_array, STAT_ARRAY_SIZE);
   return 0;
}

void print_statistics(unsigned char *data_stat, unsigned int size)
{
   printf("Statistics:\n");
   printf( "maximum: | %d |\n", stat_array[MAXIMUM_STAT_BYTE] );
   printf( "minimum: | %d |\n", stat_array[MINIMUM_STAT_BYTE] );
   printf( "median:  | %d |\n", stat_array[MEDIAN_STAT_BYTE] );
   printf( "mean:    | %d |\n", stat_array[MEAN_STAT_BYTE] );
}

void print_array(unsigned char *data, unsigned int size)
{
   printf("input array: |");
   for(int i = 0; i < size; i++)
   {
      printf(" %d |", data[i]);
   }
   printf("\n");
}

unsigned char find_median(unsigned char *data, unsigned int size)
{
   sort_array(data, size);
   return data[size/2 - 1];
}
unsigned char find_mean(unsigned char *data, unsigned int size)
{
   int data_sum = 0;
   for(int i = 0; i < size; i++)
   {
      data_sum += data[i];
   }
   return data_sum/size;
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