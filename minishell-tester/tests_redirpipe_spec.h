#ifndef TESTS_REDIRPIPE_SPEC_H
# define TESTS_REDIRPIPE_SPEC_H

# include "minishell_tester.h"

static t_test g_tests_redirpipe_spec[] = {
    // Redirect and Pipe Combinations
    {"Redirect and Pipe First", "ls -la"},
    {"Redirect and Pipe Second", "> output.txt"},
    {"Redirect and Pipe Third", "| cat output.txt"},
    {"Multiple Redirects First", "echo test"},
    {"Multiple Redirects Second", "> file"},
    {"Multiple Redirects Third", "test1"},
    {"Append Redirection First", "echo 2"},
    {"Append Redirection Second", ">> out1"},
    {"Append Redirection Third", "> out2"},
    {"Input Output Combination", "cat < test"},

    // Special Characters and Edge Cases
    {"Dollar Sign Alone", "$"},
    {"Dynamic Path Execution First", "export path=\"/bin\""},
    {"Dynamic Path Execution Second", "$path/ls -l"}
};

# define NUM_TESTS_REDIRPIPE_SPEC (sizeof(g_tests_redirpipe_spec) / sizeof(t_test))

#endif