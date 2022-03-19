#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 1000
#define NUMBERS_PER_LINE 50
#define int_type uint64_t

bool is_next_prime(int_type integer, int_type primes[])
{

    int i = 0;
    for(;;)
    {
        ++i; //first prime is 2
        if(primes[i]*primes[i] >= integer){return true;}
        if(integer%primes[i] == 0){return false;}
    }    
}

void print_buffer(int_type prime_array[], int count)
{
    for(int i = 0; i < count; ++i)
    {
        printf("%i, ", prime_array[i]);
        if((i+1)%NUMBERS_PER_LINE == 0){printf("\n");}
    }
}

int main()
{
    int_type num_array[MAX_LEN];
    int_type prime_array[MAX_LEN];
    int prime_arr_pos;
    int i,j,n;

    // add primes < 6
    prime_array[0] = 2;
    prime_array[1] = 3;
    prime_array[2] = 5;
    prime_arr_pos = 2;

    // Generate all prime candidates
    // O(n)
    i = 0,n = 1;
    while(i < MAX_LEN)
    {
        num_array[i] = 6*n + 1;
        num_array[i+1] = 6*n + 5;
        i+=2;
        n++;
    }

    // Test if candidate is prime
    i = 0;
    while(i < MAX_LEN) // O(n)
    {
        if(is_next_prime(num_array[i],prime_array))
        {
            prime_array[++prime_arr_pos] = num_array[i];
        }
        ++i;
    }

    // Print primes
    print_buffer(prime_array, prime_arr_pos);
    return 0;
}
