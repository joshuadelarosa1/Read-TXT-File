#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "fileAnalysis.h"

// this is where main will be and you will test your code
// idea one: just general count the amount of times a word is in a file, and
// how many words is in the file (could also do general stuff like avg
// word length and longest/shorted word
// -> use this for bee movie or a song from someone

int
main(int argc, char * argv[]){

  char str[MAX_STR_LEN+1];
  word_t * word_list = NULL;
  int total_words = 0;

  if(argc != 2){
    printf("Insufficent number of files.\n Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  FILE * stream = fopen(argv[1], "r");

  if(stream == NULL){
    printf("Error reading file: %s\n Error: %s\n", argv[1], (strerror(errno)));
    return EXIT_FAILURE;
  }

  printf("This is a program that will: \n");

  int ch, i = 0;
  
  while((ch = fgetc(stream)) != EOF){
    
    if(isalpha(ch) && i < MAX_STR_LEN+1){
      str[i] = ch;
      i++;
    }
    else if (ch == ' ' || ch == '\n'){
      str[i] = '\0';
      if(str[0] != '\0'){
	add_word(&word_list, str);
	i = 0;
	total_words++;
      }
    }
    else if(isalpha(ch) == 0)
      continue;
  }


  double avg = avg_word_len(&word_list, total_words);
  printf("The average length of the words is: %lf\n", avg);
  printf("The total number of words is: %d\n", total_words);

  longest_word(&word_list);
  shortest_word(&word_list);

  if(fclose(stream)){
    printf("Error closing file: %s\n Error: %s\n", argv[1], strerror(errno));
    return EXIT_FAILURE;
  }

  return 0;
}


/* stuff that I was testing out before:

for while loop while scanning things:
char * temp = malloc((strlen(str) * sizeof(char)));
    strcpy(temp, str);
    
    word_t * hey;
    strcpy(hey->str, temp);
    printf("%s", hey->str); */
/*
char ch;
  while((ch = fgets(str, MAX_STR_LEN, stream)) != NULL){
    
    int i = 0;
      
    do{
      if(isalpha(ch) && ch != '\n' && i < MAX_STR_LEN){
	str[i] = ch;
	i++;
      }
      else
	continue;
    }while(ch != ' ');
    
    add_word(&word_list, str);
    total_words++;
  }
*/

/*
int ch;
while((ch = fgetc(stream)) != EOF){
  while(ch != ' '){
    if(isalpha(ch)){
      str[i++] = ch;
    }
    else {
      continue;
    }
  }

  add_word(&word_list, str);
 }
*/
/*
  char bad_string[MAX_STR_LEN+1];
  strcpy(bad_string, "-");
  
  while(fscanf(stream, "%s", str) != EOF){
    if(strcmp(str, bad_string) == 0){
      continue;
    }
    
    else{
      add_word(&word_list, str);
      total_words++;
    }
    }
  int ch, i = 0;
  while((ch = fgetc(stream)) != EOF){

    if(i < MAX_STR_LEN && isspace(ch) != 0 && isalpha(ch)){
      str[i++] = ch;
      else
	

    //add_word(&word_list, str);
    } */

