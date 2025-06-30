#ifndef TEST_CASES_H
# define TEST_CASES_H

# include "minishell_tester.h"

static t_test g_tests[] = {
    // Basic commands
    {"Echo Test", "echo Hello World"},
    {"PWD Test", "pwd"},
    {"LS Test", "ls -la"},
    
    // Pipes
    {"Simple Pipe Test", "echo hello | cat"},
    {"Complex Pipe Test", "ls -l | grep test | wc -l"},
    
    // Redirections
    {"Output Redirection", "echo hello > test.txt ; cat test.txt ; rm test.txt"},
    {"Input Redirection", "echo 'hello world' > test.txt ; cat < test.txt ; rm test.txt"},
    {"Append Redirection", "echo hello > test.txt ; echo world >> test.txt ; cat test.txt ; rm test.txt"},
    
    // Environment variables
    {"Environment Test", "env | grep PATH"},
    {"Export Test", "export TEST=hello ; echo $TEST"},
    
    // Quotes
    {"Simple Quotes", "echo 'Hello    World'"},
    {"Double Quotes", "echo \"Hello    World\""},
    {"Mixed Quotes", "echo \"'Hello'    'World'\""},
    
    // Built-ins
    {"CD Test", "cd .. ; pwd ; cd -"},
    {"Echo with -n", "echo -n hello"},
    {"Unset Test", "export TEST=hello ; unset TEST ; echo $TEST"}
};

# define NUM_TESTS (sizeof(g_tests) / sizeof(t_test))

#endif