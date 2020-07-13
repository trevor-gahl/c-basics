#include <stdio.h>
#include <stdlib.h>

void usage(char *program_name){
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]){
    int i, count;

    if(argc < 3){        // If less than 3 args are used
        usage(argv[0]);  // Display usage and exit
    }

    count = atoi(argv[2]); // Convert second arg to int
    printf("Repeating %d times...\n",count);
    
    for(i=0; i<count; i++){
        printf("%3d - %s\n", i, argv[1]); // Print the first arg
    }
}
