#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "fileAnalysis.h"

// file with implemented functions

// pre-conditions: must take a double pointer of the word_t type (this is
// a list of words). must also take a character array to hold the string
// for the word, and it must not surpass MAX_STR_LEN.
//
// post-conditions: this will add a word to a list of words
// that are of the type word_t
void
add_word(word_t ** word, char str[]){

  //allocating memory for new_word and creating temp pointer for previous_word
  word_t * new_word = (word_t *) malloc(sizeof(word_t));
  word_t * previous_word;

  //if the memory is unable to be allocated for new_word (list is full)
  if(new_word == NULL){
    printf("Unable to make memory for word. Error: %s", strerror(errno));
    return;
  }

  //if it is the first word in the list & initializing the word
  if(*word == NULL){
    new_word->next = *word;
    *word = new_word;
    strcpy(new_word->str, str);
    new_word->word_len = strlen(str);
  }

  //anything besides the first word in a list
  else{
    //for goes until the current is NULL
    for(word_t * current = *word; current != NULL; current = current->next){
      if(current->next == NULL){
	previous_word = current;
      }
    }

    //initializing the word
    previous_word->next = new_word;
    strcpy(new_word->str, str);
    new_word->word_len = strlen(str);
  }
}
// add_word ends

// pre-conditions: takes in a list of words that of type word_t, and
// the total amount of words in that list that is an int
//
// post-conditions: will find and return the average length of the
// words inputed from the list as a double
double
avg_word_len(word_t ** word, int total_words){

  //initalizing values
  double sum = 0;

  //stops when current is NULL, finding the sum of all the word lengths
  for(word_t * current = *word; current != NULL; current = current->next){
    sum += current->word_len;
  }

  //finding average and returning it back to main
  double avg = sum / total_words;
  return avg;
}
//avg_word_len ends

// pre-conditions: takes in a list of words that are of type word_t,
// the user must enter a word that contains no non-alphabetic characters,
// spaces, and is under 50 characters (MAX_STR_LEN)
//
// post-conditions: this will find the number of times that the given word
// is in a file, it will return true if done succesfully, and EXIT_FAILURE
// if not
bool
find_word(word_t ** word){

  //initializing values
  char item[MAX_STR_LEN+1];
  int count = 0;

  //informing the user of what to do
  printf("Please enter the word under 50 characters you are trying to find.\n");
  printf("Do not include any non-alphabetic characters or spaces.\n");

  //scanning for string from the user
  int result = scanf("%s", item);

  //checking if the user entered correct number of inputs
  if(result != 1){
    perror("You did not enter the correct amount of inputs.\n");
    return EXIT_FAILURE;
  }

  //checking if user entered correct length of string
  if(strlen(item) > 50){
    perror("You entered a word that is above 50 characters. Try again.\n");
    return EXIT_FAILURE;
  }

  //stops when current is NULL, finding the amount of times the word is
  // in the file
  for(word_t * current = *word; current != NULL; current = current->next){
    if(strcmp(current->str, item) == 0){
      count++;
    }
  }

  //printing results
  if(count != 0){
    printf("We found your word! You word was in the file %d time(s).\n", count);
  }
  else
    printf("There were no occurences of your word in this text document.\n");

  return true;
}
//find word ends

// pre conditions: longest_word takes in the list of words of type
// word_t
//
// post conditions: this function will find the most recent longest word from
// the list, print it, and give the length of the word
void
longest_word(word_t ** word){

  //making space for a current_longest and initializing its size
  word_t * current_longest = (word_t *) malloc(sizeof(word_t));
  current_longest->word_len = 0;

  //for ends when current is NULL, finding the longest word
  for(word_t * current = *word; current != NULL; current = current->next){
    if(current->word_len >= current_longest->word_len){
      current_longest = current;
    }
  }

  //printing the results
  printf("The last longest word is: %s, and is %d letter(s) long.\n", current_longest->str, current_longest->word_len);

  //freeing the space from current_longest
  free(current_longest);
}
//longest_word ends

// pre conditions: none
//
// post conditions: prints menu of choices for user
void
print_menu(void){

  printf("\n");
  printf("Please choose from the following options.\n");
  printf("1. Find the average length of all the words\n");
  printf("2. Find total amount of words\n");
  printf("3. Find longest word\n");
  printf("4. Find shortest word\n");
  printf("5. Find how many times a specific word appears\n");
  printf("6. Exit the program\n");
}
//print_menu ends

// pre conditions: shortest_word takes in the list of words of type
// word_t
//
// post conditions: this function will find the most recent shortest word from
// the list, print it, and give the length of the word
void
shortest_word(word_t ** word){

  //making space for current_shortest and initializing its size
  word_t * current_shortest = (word_t *) malloc(sizeof(word_t));
  current_shortest->word_len = 1;

  //for ends when current is NULL, finding the shortest word
  for(word_t * current = *word; current != NULL; current = current->next){
    if(current->word_len <= current_shortest->word_len){
      current_shortest = current;
    }
  }

  //printing results to the user
  printf("The last shortest word is: %s, and is %d letter(s) long.\n", current_shortest->str, current_shortest->word_len);

  //freeing space from current_shortest
  free(current_shortest);
}
//shortest_word ends

//Help recieved from: Professor Barbara Johnson & King C Programming Textbook
