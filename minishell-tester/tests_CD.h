#ifndef TESTS_CD_H
# define TESTS_CD_H

# include "minishell_tester.h"

static t_test g_tests_cd[] = {
    // CD Tests
    {"CD Root Directory", "cd ../../../../../.."},
    {"CD Home", "cd ~"},
    {"CD Empty", "cd"},
    {"CD Desktop", "cd ~/Desktop"},
    {"Unset HOME CD First", "unset HOME"},
    {"Unset HOME CD Second", "cd ~"},
    {"Export HOME CD First", "export HOME=/Users/user42"},
    {"Export HOME CD Second", "cd ~"},
    {"CD Invalid Directory", "cd Eyooooo"},
    {"CD Previous Directory Multiple First", "cd -"},
    {"CD Previous Directory Multiple Second", "cd -"},
    {"CD with Extra Args", "cd .."},
    {"Complex CD with Removal First", "mkdir a"},
    {"Complex CD with Removal Second", "mkdir a/b"},
    {"Complex CD with Removal Third", "cd a/b"},
    {"Complex CD with Removal Fourth", "rm -r ../../a"},
    {"Complex CD with Removal Fifth", "cd .."},
};

# define NUM_TESTS_CD (sizeof(g_tests_cd) / sizeof(t_test))

#endif