#!/bin/bash

# print in yellow
yellow=`tput setaf 3`
green=`tput setaf 2`
red=`tput setaf 1`
reset=`tput sgr0`

echo "${yellow}-------- BASIC TESTS --------${reset}"

echo "${yellow}Test 1: 5 philosophers${reset}"
# Test normal operation
./philo 5 800 200 200 10
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}Test 2: Should die quickly${reset}"
# Test death scenario
./philo 4 310 200 100   # Should see a death message
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}Test 3: Single philosopher${reset}"
# Test single philosopher
./philo 1 800 200 200 10
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}Test 4: 5 philosophers with meal limit${reset}"
# Test with meal limit
./philo 5 800 200 200 7  # Should stop after each philosopher eats 7 times
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}-------- EDGE CASES --------${reset}"

echo "${yellow}Test 5: Very small values${reset}"
./philo 2 60 60 60  # Philosophers should die quickly
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}Test 6: Large number of philosophers${reset}"
./philo 100 800 200 200  # Testing with many philosophers
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}Test 7: Zero meals required${reset}"
./philo 5 800 200 200 0  # Should exit immediately
sleep 2
pkill -f philo >/dev/null 2>&1

echo "${yellow}-------- STARVATION TESTING --------${reset}"

echo "${yellow}Test 8: time_to_eat + time_to_sleep > time_to_die${reset}"
./philo 5 100 200 200  # Philosophers should die
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}-------- RACE CONDITION TESTING --------${reset}"

echo "${yellow}Test 9: Small differences between time values${reset}"
./philo 5 200 190 190  # Check for timing issues
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}-------- DEADLOCK PREVENTION --------${reset}"

echo "${yellow}Test 10: Even number of philosophers${reset}"
./philo 4 800 200 200
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${yellow}Test 11: Odd number of philosophers${reset}"
./philo 5 800 200 200
sleep 5
pkill -f philo >/dev/null 2>&1

echo "${green}All tests completed!${reset}"
echo "${yellow}Don't forget to also check:${reset}"
echo "- Memory leaks with valgrind"
echo "- Data races with ThreadSanitizer"
echo "- Code compliance with the 42 norm"