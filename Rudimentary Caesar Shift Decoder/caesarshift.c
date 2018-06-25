//includes all of the necessary preprocessor headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pre-condition: a jumbled up, all capital letter string with no punctuation or spaces
int main()
{
    int counter = 0;//used in for loop
    //initializes two cstring arrays
    char input[100];
    char lowercase[100];
    printf("Please enter encoded message:\n");

    scanf("%s", input);//gets message

    strcpy(lowercase,input);//copies the contents of input into the lowercase array
    int len = strlen(lowercase);//this finds the length of the lowercase array. used in for loop
    char numchar;
    //initializes all caps to lowercase characters
    for(counter = 0;counter <= len;counter++)//for loop that adds 1 to the counter each time it executes, and will end when counter is bigger than the lenght of the array
    {

        numchar = lowercase[counter] + 32;
        //these two if loops makes sure the null terminator doesnt get changed and stays the same
        if (numchar <=122)
        {
            if (numchar >= 97)
            {
                        lowercase[counter] = numchar;//sends the lowercase letter back into the array
            }
        }
    }
    //initializers for the menu
    int noshift = 0;
    int isgibberish = 1;
    //creates a 'before list to compare so that it doesnt infinitely cycle through using shifts
    char before[100];
    strcpy(before,lowercase);
    //Menu that will keep on bumping up the cipher letters by one letter until the user thinks it makes sense or until it goes back to its original message
    while (isgibberish== 1)
     {
        for(counter = 0;counter <= len;counter++)//for loop that adds 3 to the counter each time it executes, and will end when counter is bigger than the lenght of the array
        {

            numchar = lowercase[counter] +3;//adds one to the value of the character
            //these two nested if loops makes sure the null terminator doesnt get changed and stays the same
            if (numchar <=123)
            {
                if ( numchar >= 97)
                {
                    lowercase[counter] = numchar;//enters the new character back into the array
                }
            }
            //makes sure it loops back around to beginning
            if (numchar == 126)
            {
                numchar = 100;
                lowercase[counter] = numchar;
            }
            //makes sure it loops back around to beginning
            if (numchar == 125)
            {
                numchar = 99;
                lowercase[counter] = numchar;
            }
            //makes sure it loops back around to beginning
            if (numchar == 124)
            {
                numchar = 98;
                lowercase[counter] = numchar;
            }
            //makes sure it loops back around to beginning
            if (numchar == 123)
            {
                numchar = 97;
                lowercase[counter] = numchar;
            }
        }
         //This makes sure it stops cycleing through the shifts, so it doesnt start to repeat all over again
        if (before[0] ==  lowercase[0])
        {
            isgibberish = 0;
            noshift = 1;
        }


        //asks the user to enter in whether or not the message is still gibberish
        if (isgibberish == 1)
        {
            printf("\nIs this gibberish?(1 for yes/ 0 for no):\n\n%s\n\n", lowercase);
            scanf("%d", &isgibberish);
        }

        //protects against people choosing incorrect numerical choice
        while (isgibberish != 0 && isgibberish != 1)
        {
            printf("\nSorry, incorrect choice. please enter 1 for yes or 0 for no.\n");
            printf("\nIs this gibberish?(1 for yes/ 0 for no):\n\n%s\n\n", lowercase);
            scanf("%d\n", &isgibberish);
        }
     }
     //displays the decoded message
    if (noshift == 0)
        {
            printf("\nHere is the decrypted message:\n\n%s\n\n", lowercase);
        }
    //tells user if there is no shift
    if (noshift == 1)
        {
            printf("\nThere was no Caesar shift for this message. Could not be decoded\n");
        }
    return 0;
}
//Post-condition: an all lowercase letter string with no punctuation or spaces that is coherent, or a message saying that it could not be decrypted

