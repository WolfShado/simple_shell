#ifndef SHELL_H
#define SHELL_H

/* header that calls printf */
#include <stdio.h> 
/* header to  fork/execve*/
#include <unistd.h> 
/*header  that calls I/O */
#include <stdlib.h>
/* header of strtok*/
#include <string.h>
/* header to standard def */
#include <stddef.h>
/* header to call for  errno and perror */
#include <errno.h>
/* header for type pid */
#include <sys/types.h>
/* header  wait */
#include <sys/wait.h>
/* header to  use of stat function */
#include <sys/stat.h> 
/* header to signal management */
#include <signal.h> 
/* header for open files*/
#include <fcntl.h> 

/*======= MACROS ========*/

/* msg help and prompt */
#include "macros.h"

/*====== STRUCTURES ======*/

/**
 * struct info- struct for the program's data
 * @program_nameexecutable's name.
 * @input_line: ptr to the input read for _getline.
 * @command_name: ptr to the first command typed by the user.
 * @exec_counter: excecuted comands nbm.
 * @file_descriptor: input of commands file descriptor.
 * @tokens: ptr to array of tokenized input.
 * @env: environ copy.
 * @alias_list: ptrs's array with aliases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - builtins's structure
 * @builtin: builtin's name
 * @function: builtin's associated functions
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


/*-------- MAIN FUNCTIONS --------*/

/******  shell.c  ******/

/* Program's info  struct initializer */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/*  infinite loop maker that shows the prompt*/
void sisifo(char *prompt, data_of_program *data);

/*prompt printer in a new line */
void handle_ctrl_c(int opr UNUSED);


/********  _getline.c  *******/

/* std input one line reader */
int _getline(data_of_program *data);

/* line spliter if the logical operators exist */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


/****** expansions.c *******/

/* var expander */
void expand_variables(data_of_program *data);

/*  aliases expander */
void expand_alias(data_of_program *data);

/* strg append to the end of the buffer*/
int buffer_add(char *buffer, char *str_to_add);


/***** str_tok.c ******/

/* string separator  in tokens using a designed delimiter */
void tokenize(data_of_program *data);

/* ptr creator to a part of a string */
char *_strtok(char *line, char *delim);


/*********** execute.c ************/

/* entire path command executer */
int execute(data_of_program *data);


/****** builtins_list.c *********/

/*executes it if it matchs a builtin */
int builtins_list(data_of_program *data);


/****** find_in_path.c ******/

/*  path's dir array creator */
char **tokenize_path(data_of_program *data);

/* program in path searcher */
int find_program(data_of_program *data);


/*-------- MEMORY MANAGEMENT HELPER -------*/

/******* helpers_free.c ********/

/* Free mem for dir */
void free_array_of_pointers(char **directories);

/* Free the fields needed each loop */
void free_recurrent_data(data_of_program *data);

/* Free all data fields  */
void free_all_data(data_of_program *data);


/*-------- BUILTINS --------*/

/******** builtins_more.c ********/

/* Close shell */
int builtin_exit(data_of_program *data);

/*  current dir changer */
int builtin_cd(data_of_program *data);

/*  work dir set */
int set_work_directory(data_of_program *data, char *new_dir);

/*  help info shower */
int builtin_help(data_of_program *data);

/* set/unset/show alias */
int builtin_alias(data_of_program *data);


/****** builtins_env.c *******/

/* env shower where the shell runs */
int builtin_env(data_of_program *data);

/* create/override a var of env */
int builtin_set_env(data_of_program *data);

/* delete a vaR IN env */
int builtin_unset_env(data_of_program *data);


/*---------- FOR ENVIRONMENT VARIABLES MANAGEMENT HELPERS ---------*/

/******** env_management.c ********/

/* Gets the value of the env var */
char *env_get_key(char *name, data_of_program *data);

/* value of the env var overwriter */
int env_set_key(char *key, char *value, data_of_program *data);

/*  key remover from the env */
int env_remove_key(char *key, data_of_program *data);

/* current env printer */
void print_environ(data_of_program *data);


/*-------- PRINTING HELPERS ----------*/

/******* helpers_print.c *********/

/* Prints a string in the standar output */
int _print(char *string);

/* Prints a string in the standar error */
int _printe(char *string);

/* Prints a string in the standar error */
int _print_error(int errorcode, data_of_program *data);


/*---------- STRINGS MANAGEMENT -----------*/

/******* helpers_string.c **********/

/* nbr of chars in string  counter */
int str_length(char *string);

/* string duplicator */
char *str_duplicate(char *string);

/* strings comparator */
int str_compare(char *string1, char *string2, int number);

/* Concatenates two strings */
char *str_concat(char *string1, char *string2);

/* string reverse */
void str_reverse(char *string);


/****** helpers_numbers.c *******/

/* int to string Caster */
void long_to_string(long number, char *string, int base);

/* string to nbr converter */
int _atoi(char *s);

/* count  char coincidences in string */
int count_characters(char *string, char *character);


/****** alias_management.c *******/

/* Alias list printing */
int print_alias(data_of_program *data, char *alias);

/* have Alias name */
char *get_alias(data_of_program *data, char *alias);

/* Alias name's Set */
int set_alias(char *alias_string, data_of_program *data);

#endif
