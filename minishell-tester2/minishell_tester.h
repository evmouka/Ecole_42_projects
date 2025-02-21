#ifndef MINISHELL_TESTER_H
# define MINISHELL_TESTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

typedef struct s_test {
    char *name;
    char *command;
} t_test;

// Function declarations
char *get_bash_output(char *command, int *exit_code);
char *get_minishell_output(char *command, int *exit_code);
char *execute_command(char *command, int *exit_code);
int run_test(t_test test);
t_test *load_test_from_file(const char *filename, int *test_count);
void free_test_array(t_test *tests, int count);

#endif