/*In this challenge, write a program that takes in three arguments, a start temperature (in Celsius), an end temperature (in Celsius) and a step size. Print out a table that goes from the start temperature to the end temperature, in steps of the step size; you do not actually need to print the final end temperature if the step size does not exactly match. You should perform input validation: do not accept start temperatures less than a lower limit (which your code should specify as a constant) or higher than an upper limit (which your code should also specify). You should not allow a step size greater than the difference in temperatures. */





#include <stdio.h>
#include <stdlib.h>


float c_f_conv(float cel)
{
	float fahr = cel*1.8+32;
	return fahr;
}


int main(int argc, char *argv[])
{
	// arg 1 is start temp
	// arg 2 is end temp
	// arg 3 is step size
	//printf("Enter lower limit: ");
	//scanf("%d",&lower); // scanf requires pointer to memory location to place data
	
	// Convert arguments to ints
	float lower = atof(argv[1]);
	float upper = atof(argv[2]);
	float step = atof(argv[3]);
	//printf("\n%d",lower);
	

	float dif = upper - lower;
	float fahr;
	printf("\tCelsius\t\tFahrenheit\n");
	for(int i =0; i <=dif; i=i+step)
	{
		fahr = c_f_conv(lower+i);
		printf("\t%f\t%f\n",lower+i, fahr);
	}

}
