#include <stdio.h>
#include <string.h>
#include <unistd.h>

main()
{
    //create a variable to store the string typed from the command
    char cmd[100];

    //get the current working directory
    char cwd[200];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("Error with getting the current working directory.");
        return 1;
    }

    //print "Enter a linux command" and get the result
    printf("CS4440 Shell:%s$ ", cwd);
    fgets(cmd, 100, stdin);

    //get a pointer to the position for the newline char
    char *pos;

    //if the return of the first occurence of the character is not a null pointer, set the value at the pointers address to be the terminating char
    if ((pos=strchr(cmd, '\n')) != NULL)
        *pos = '\0';

    //set our delimeter to be the whitespace
    char delim[] = " ";

    // get a pointer to the first instance of the delimeter
    char* ptr = strtok(cmd, delim);

    //define our argv to be an array of pointers;
    char* argv[11];

    //initialize a word count to 0
    int count = 0;

    //while our strtok pointer is not null, set our argv at the number of words to equal to the string represented by the break inbetween the terminating character
    while (ptr != NULL) {
        argv[count] = ptr;

        //get our new pointer value from strtok's last remembered terminator point to the next delimeter
        ptr = strtok(NULL, delim);

        //increase the count
        count++;
    }
    
    //set the final argv pointer to point to NULL, this makes our array of pointers null terminated
    argv[count] = NULL;

    //call execvp with the args
    execvp(argv[0], argv);

    //have an error condition
    printf("You will only get here if you have an error\n");
}