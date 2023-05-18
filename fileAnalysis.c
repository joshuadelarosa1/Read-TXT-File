#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "fileAnalysis.h"

// this is where you will implement functions

void
add_word(word_t ** word, char str[]){

  word_t * new_word = (word_t *) malloc(sizeof(word_t));
  word_t * previous_word;
  
  if(new_word == NULL){
    printf("Unable to make memory for word. Error: %s", strerror(errno));
    return;
  }

  if(*word == NULL){
    new_word->next = *word;
    *word = new_word;
    strcpy(new_word->str, str);
    new_word->word_len = strlen(str);
  }
  
  else{
    for(word_t * current = *word; current != NULL; current = current->next){
      if(current->next == NULL){
	previous_word = current;
      } // if ends
    } // for ends
    
    previous_word->next = new_word;
    strcpy(new_word->str, str);
    new_word->word_len = strlen(str);
  } // else ends

  //printf("%s\n", new_word->str);
}
// add_word

double
avg_word_len(word_t ** word, int total_words){

  double sum = 0;
  
  for(word_t * current = *word; current != NULL; current = current->next){
    sum += current->word_len;
  }

  double avg = sum / total_words;
  return avg;
}
//avg_word_len

void
find_word(word_t ** word, char item[]){

  printf("Please enter the word you are trying to find, not including any non-alphabetic characters or spaces, and within 50 characters.\n");


}

void
longest_word(word_t ** word){

  word_t * current_longest;
  current_longest->word_len = 0;

  for(word_t * current = *word; current != NULL; current = current->next){
    if(current->word_len >= current_longest->word_len){
      current_longest = current;
    }
  }

  printf("The last longest word is: %s, and is %d letter(s) long.\n", current_longest->str, current_longest->word_len);
}

void
shortest_word(word_t ** word){

  word_t * current_shortest;
  current_shortest->word_len = 1;

  for(word_t * current = *word; current != NULL; current = current->next){
    if(current->word_len <= current_shortest->word_len){
      current_shortest = current;
    }
  }

  printf("The last shortest word is: %s, and is %d letter(s) long.\n", current_shortest->str, current_shortest->word_len);
}
