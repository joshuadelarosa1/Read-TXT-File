#ifndef __fileAnalysis__h
#define __fileAnalysis__h

// declarations of functions and structs

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

bool
find_word(word_t ** word);

void
longest_word(word_t ** word);

void
print_menu(void);

void
shortest_word(word_t ** word);

#endif

//Help recieved from: Professor Barbara Johnson & King C Programming Textbook

