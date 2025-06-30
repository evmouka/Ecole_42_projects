#ifndef ADVANCED_TEST_CASES_H
# define ADVANCED_TEST_CASES_H

# include "minishell_tester.h"

static t_test g_advanced_tests[] = {
    // Complex pipe chains
    {"Triple Pipe", "cat /etc/passwd | grep root | wc -l"},
    {"Quad Pipe", "ls -la | grep .c | wc -l | cat"},
    
    // Multiple redirections
    {"Multiple Redirects", "echo hello > f1 > f2 > f3 ; cat f3 ; rm f1 f2 f3"},
    {"Mixed Redirects", "echo input > f1 ; cat < f1 >> f2 ; cat f2 ; rm f1 f2"},
    
    // Error handling
    {"Command Not Found", "notarealcommand"},
    {"Permission Denied", "touch test.sh ; chmod 000 test.sh ; ./test.sh ; rm -f test.sh"},
    
    // Complex quotes
    {"Nested Quotes", "echo \"this is 'a test' of \\\"quotes\\\"\""},
    {"Empty Quotes", "echo \"\" '' \"   \" '   '"}
};

# define NUM_ADVANCED_TESTS (sizeof(g_advanced_tests) / sizeof(t_test))

#endif