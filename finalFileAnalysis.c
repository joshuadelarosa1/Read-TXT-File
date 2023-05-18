#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "fileAnalysis.h"

int
main(int argc, char * argv[]){

  //initializing values, making new word_list and setting to NULL
  char str[MAX_STR_LEN+1];
  word_t * word_list = NULL;
  int total_words = 0;
  int input = 0;
  double avg = 0.0;

  //checking to make sure the user entered correct number of arguments
  if(argc != 2){
    printf("Insufficent number of files.\n Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  //opening file
  FILE * stream = fopen(argv[1], "r");

  //checking to see if the file is readable
  if(stream == NULL){
    printf("Error reading file: %s\n Error: %s\n", argv[1], (strerror(errno)));
    return EXIT_FAILURE;
  }

  //explaining the purpose of the program
  printf("This is a program that will analyze different aspects of an inputed text file. \n");
  printf("It can find the average length of words, total words, longest & shortest word,\n");
  printf("and also how many times a specific word appears.\n");

  //initalizing values for while loop
  int ch, i = 0;

  //while loop ends when it reaches the EOF character
  while((ch = fgetc(stream)) != EOF){

    //reading in characters and saving it to str
    if(isalpha(ch) && i < MAX_STR_LEN+1){
      str[i] = ch;
      i++;
    }
    //whenever a newline or space is reached, saving characters
    else if (ch == ' ' || ch == '\n'){
      //terminating the string
      str[i] = '\0';
      //guard to make sure the string isn't empty (not a word) & adding word
      if(str[0] != '\0'){
	add_word(&word_list, str);
	i = 0;
	total_words++;
      }
    }
    //ignoring characters that are not alphabetic
    else if(isalpha(ch) == 0)
      continue;
  }

  // allowing the user to decide what info they want
  do{
    //printing menu & resetting input
    input = 0;
    print_menu();
    int result = scanf("%d", &input);

    //making sure user inputs something
    if(result != 1){
      perror("You did not enter the correct amount of inputs or inputed something incorrectly. Try again.\n");
      return EXIT_FAILURE;
    }

    //switch for user to choose information
    switch(input){
    case 1:
      avg = avg_word_len(&word_list, total_words);
      printf("The average length of the words is: %lf\n", avg);
      break;
    case 2:
      printf("The total number of words is: %d\n", total_words);
      break;
    case 3:
      longest_word(&word_list);
      break;
    case 4:
      shortest_word(&word_list);
      break;
    case 5:
      find_word(&word_list);
      break;
    case 6:
      printf("You have exited the program.\n");
      break;
    default:
      printf("You did not enter a correct input.\n");
      printf("Please choose a number between 1 and 5 inclusive, or exit the\n");
      printf("program by choosing 6.\n");
      break;
    }
    
  }while(input != 6);
  
  //closing the file, and printing an error if it fails
  if(fclose(stream)){
    printf("Error closing file: %s\n Error: %s\n", argv[1], strerror(errno));
    return EXIT_FAILURE;
  }

  return 0;
}
//main ends

//Help recieved from: Professor Barbara Johnson & King C Programming Textbook

