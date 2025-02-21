#ifndef TESTS_VAR_REDIR_H
# define TESTS_VAR_REDIR_H

# include "minishell_tester.h"

static t_test g_tests_var_redir[] = {
    // Advanced Variable and Command Tests
    {"Export Custom LS", "export ls=\"ls -l\""},
    {"Run Custom LS", "$ls"},
    {"Echo Exported Variable", "echo $ls"},
    {"Command Variable Expansion First", "export var=at"},
    {"Command Variable Expansion Second", "c$var Makefile"},
    {"Recursive Var Export First", "export loop='bonjour$loop'"},
    {"Recursive Var Export Second", "echo $loop"},

    // Redirection and Pipe Complex Cases
    {"Incomplete Redirection", "cat Makefile >"},
    {"Pipe Chain", "cat | cat | cat | ls"},
    {"Pipe with Exit First", "ls"},
    {"Pipe with Exit Second", "exit"},
    {"Redirect Multiple Files First", "echo test"},
    {"Redirect Multiple Files Second", "> file1 file2"},
    {"Redirect Nonexistent Command First", "Non_exist_cmd"},
    {"Redirect Nonexistent Command Second", "> salut"},
};

# define NUM_TESTS_VAR_REDIR (sizeof(g_tests_var_redir) / sizeof(t_test))

#endif