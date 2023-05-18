#ifndef __fileAnalysis__h
#define __fileAnalysis__h

// this is where you will declare functions or structs

#define MAX_STR_LEN 50

typedef struct word word_t;

struct word{
  char str[MAX_STR_LEN];
  int word_len;
  word_t * next;
};

void
add_word(word_t ** word, char str[]);

double
avg_word_len(word_t ** word, int total_words);

void
find_word(word_t ** word, char item[]);

void
longest_word(word_t ** word);

void
shortest_word(word_t ** word);

#endif
