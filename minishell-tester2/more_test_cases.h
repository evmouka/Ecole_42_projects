#ifndef MORE_TEST_CASES_H
# define MORE_TEST_CASES_H

# include "minishell_tester.h"

static t_test g_more_tests[] = {
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

    // Environment Variable Manipulation
    {"Unset PATH First", "unset PATH"},
    {"Unset PATH Second", "echo $PATH"},
    {"Unset PATH Third", "ls"},
    {"Unset Specific Var", "unset var"},

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

# define NUM_MORE_TESTS (sizeof(g_more_tests) / sizeof(t_test))

#endif