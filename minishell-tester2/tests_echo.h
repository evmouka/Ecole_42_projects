#ifndef TESTS_ECHO_H
# define TESTS_ECHO_H

# include "minishell_tester.h"

static t_test g_tests_echo[] = {
    // Echo Tests
    {"Echo Empty", "echo"},
    {"Echo Non-Existing Var", "echo $NonExistingVar"},
    {"Echo PATH", "echo $PATH"},
    {"Echo Home Symbol", "echo ~"},
    {"Echo Multiple -n", "echo -n -n -nnnn -nnnnm"},
    {"Echo Mixed -n", "echo -n -nnn hello -n"},
    {"Echo Var Complex", "echo $USER"},
    {"Echo Multiple Var Types", "echo '$USER'"},
    {"Echo Double Quote Var", "echo \"$USER\""},
    {"Echo Multiple Vars", "echo $? \"$?\" '$?'"},
    {"Echo Quoted Combination", "echo \"cat lol.c | cat :lol.c\""},
    {"Echo Nested Quotes", "echo \"hi there\"'general kenobi'"},
    {"Echo Prefix -n", "-n echo"},
    {"Echo Postfix -n", "echo hello -n"},
    {"Echo Empty Quotes", "echo \"\" '' \"   \" '   '"},
    {"Echo Quotes with Escaping", "echo \"this is 'a test' of \\\"quotes\\\"\""},
    {"Echo Nested Quotes Variant", "echo ' ' ' ' hello world ' ' ' '"},
};

# define NUM_TESTS_ECHO (sizeof(g_tests_echo) / sizeof(t_test))

#endif