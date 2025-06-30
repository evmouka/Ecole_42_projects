#ifndef TESTS_QUOTE_PATH_H
# define TESTS_QUOTE_PATH_H

# include "minishell_tester.h"

static t_test g_tests_quote_path[] = {
    // Quotes and Variable Expansion
    {"Complex Quote Nesting", "echo ' ' \"hello world\" ' '"},
    {"Nested Quote Expansion", "echo \"'$USER'\""},
    {"Complex Var Expansion First", "export var=\" truc\""},
    {"Complex Var Expansion Second", "echo $var | cat -e"},
    {"Var Export with Spaces First", "export test=\" foo bar \""},
    {"Var Export with Spaces Second", "echo $test"},

    // Path and Executable Tests
    {"Full Path LS", "/bin/ls"},
    {"Full Path LS Options", "/bin/ls -ga"},
    {"Dynamic Command First", "export cmd=\"ls\""},
    {"Dynamic Command Second", "$cmd -la"},
};

# define NUM_TESTS_QUOTE_PATH (sizeof(g_tests_quote_path) / sizeof(t_test))

#endif