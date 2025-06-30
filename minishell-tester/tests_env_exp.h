#ifndef TESTS_ENV_EXP_H
# define TESTS_ENV_EXP_H

# include "minishell_tester.h"

static t_test g_tests_env_exp[] = {
    // ENV and Export Tests
    {"ENV Command", "env"},
    {"ENV with Extra Arg", "env Weeiirrddd"},
    {"ENV Grep OLDPWD", "env | grep OLDPWD"},
    {"Unset ENV First", "unset HOME"},
    {"Unset ENV Second", "unset PATH"},
    {"Unset ENV Third", "unset USER"},
    {"Unset ENV Fourth", "env"},
    {"Export Empty ENV", "export"},
    {"Export Single Var", "export test1"},
    {"Export Empty Var", "export test2="},
    {"Export First Step", "export var"},
    {"Export Second Step", "export var=hoi"},
    {"Export Third Step", "export"},
    {"Export with Environment Var", "export test3=$HOME"},
    {"Export Complex Vars First", "export MY_VAR=\"Hello, World!\""},
    {"Export Complex Vars Second", "env | grep MY_VAR"},
    {"Export Update Var First", "export MY_VAR=\"Hello, World!\""},
    {"Export Update Var Second", "export MY_VAR=\"new value\""},
    {"Export Update Var Third", "env | grep MY_VAR"},
};

# define NUM_TESTS_ENV_EXP (sizeof(g_tests_env_exp) / sizeof(t_test))

#endif