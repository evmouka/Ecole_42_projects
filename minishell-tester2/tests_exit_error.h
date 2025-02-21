#ifndef TEST_EXIT_ERROR_H
# define TEST_EXIT_ERROR_H

# include "minishell_tester.h"

static t_test g_tests_exit_error[] = {
    // Exit Tests
    {"Exit with String", "exit banana"},
    {"Exit with Number", "exit 50"},
    {"Exit with Quoted Number", "exit \"50\""},

    // Error Handling and Exit Status
    {"Non-Existent Directory CD First", "cd Weyooooo"},
    {"Non-Existent Directory CD Second", "echo $?"},
    {"Random Command First", "random_cmd"},
    {"Random Command Second", "echo $?"},
    {"Non-Executable File", "./file_that_is_not_an_executable"},
    {"Command Not Found First", "notarealcommand"},
    {"Command Not Found Second", "echo $?"},
    {"Permission Denied First", "touch test.sh"},
    {"Permission Denied Second", "chmod 000 test.sh"},
    {"Permission Denied Third", "./test.sh"},
    {"Permission Denied Fourth", "rm -f test.sh"},
};

# define NUM_TESTS_EXIT_ERROR (sizeof(g_tests_exit_error) / sizeof(t_test))

#endif