#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color
YELLOW='\033[1;33m'

# Function to test basic cases
test_basic() {
    printf "${BLUE}Testing basic error cases...${NC}\n"

    # Array of test cases that should return "Error"
    error_cases=(
        # Empty/Invalid
        '""'
        '" "'
        '"     "'

        # Invalid Numbers
        '"abc"'
        '"1 abc"'
        '"abc 2"'
        '"1 2 abc"'
        '"1 2 3abc"'
        '"abc1"'
        '"1abc2"'

        # Signs
        '"+"'
        '"-"'
        '" + "'
        '" - "'
        '"+a"'
        '"-a"'
        '"1 + "'
        '"1 - "'
        '"1 2+"'
        '"1 2-"'
        '"++1"'
        '"--1"'
        '"1+1"'
        '"1-1"'

        # INT MAX/MIN
        '"2147483648"'
        '"-2147483649"'
        '"1 2147483648"'
        '"1 -2147483649"'

        # Duplicates
        '"1 1"'
        '"1 2 1"'
        '"1 2 2"'
        '"-000 +000 000"'
        '"0 -0"'

        # Special Characters
        '"*"'
        '"1 * 2"'
        '"@"'
        '"#"'
        '"1,2,3"'
        '"1 | 2"'
        '"1 \\ 2"'
    )

    for test in "${error_cases[@]}"; do
        printf "Testing: %s " "$test"
        result=$(eval "./push_swap $test" 2>&1)
        if [ "$result" = "Error" ]; then
            printf "${GREEN}[OK]${NC}\n"
        else
            printf "${RED}[KO] - Expected 'Error', got '%s'${NC}\n" "$result"
        fi
    done
}

# Function to test valid cases and count operations
test_valid() {
    printf "\n${BLUE}Testing valid cases and counting operations...${NC}\n"

    # Test cases with maximum allowed operations
    declare -A valid_cases=(
        ["2 1"]="3"                    # 2 numbers: max 3 ops
        ["1 3 2"]="3"                  # 3 numbers: max 3 ops
        ["2 3 1 4"]="8"               # 4 numbers: max 8 ops
        ["1 5 2 4 3"]="12"            # 5 numbers: max 12 ops
    )

    for test in "${!valid_cases[@]}"; do
        printf "Testing: \"%s\" " "$test"
        ops_count=$(./push_swap $test | wc -l | tr -d ' ')
        if [ "$ops_count" -le "${valid_cases[$test]}" ]; then
            printf "${GREEN}[OK]${NC} - %s operations\n" "$ops_count"
        else
            printf "${RED}[KO]${NC} - %s operations (max: %s)\n" "$ops_count" "${valid_cases[$test]}"
        fi
    done
}

# Function to test sorting correctness
test_sorting() {
    printf "\n${BLUE}Testing sorting correctness...${NC}\n"

    test_sort() {
        local numbers=$1
        local name=$2
        printf "Testing %s: " "$name"

        # Get the sorted result
        result=$(./push_swap $numbers | ./checker_linux $numbers 2>&1)

        if [ "$result" = "OK" ]; then
            printf "${GREEN}[OK]${NC}\n"
        else
            printf "${RED}[KO] - Not properly sorted${NC}\n"
        fi
    }

    # Test different cases
    test_sort "2 1" "simple swap"
    test_sort "1 3 2" "three numbers"
    test_sort "5 4 3 2 1" "reverse sorted"
    test_sort "1 2 3 4 5" "already sorted"
}

# Function to test large sets
test_large() {
    printf "\n${BLUE}Testing large sets...${NC}\n"

    test_large_set() {
        local size=$1
        local max_ops=$2
        printf "Testing %d numbers: " "$size"

        # Generate random numbers
        numbers=$(seq 1 $size | sort -R | tr '\n' ' ')
        ops_count=$(./push_swap $numbers | wc -l | tr -d ' ')

        if [ "$ops_count" -le "$max_ops" ]; then
            printf "${GREEN}[OK]${NC} - %s operations\n" "$ops_count"
        else
            printf "${RED}[KO]${NC} - %s operations (max: %s)\n" "$ops_count" "$max_ops"
        fi
    }

    test_large_set 100 700    # 100 numbers: max 700 operations
    test_large_set 500 5500   # 500 numbers: max 5500 operations
}

# Function to test memory leaks
test_leaks() {
    printf "\n${BLUE}Testing memory leaks...${NC}\n"

    leak_test_cases=(
        '"1 2 3"'
        '"abc"'
        '"1 abc"'
        '"2147483648"'
        '"-2147483649"'
        '"1 2 1"'
        '"+"'
        '"-"'
        '" + "'
        '" - "'
    )

    for test in "${leak_test_cases[@]}"; do
        printf "Testing leaks for: %s " "$test"
        leak_output=$(eval "valgrind --leak-check=full --show-leak-kinds=all ./push_swap $test 2>&1")
        if echo "$leak_output" | grep -q "All heap blocks were freed"; then
            printf "${GREEN}[OK]${NC}\n"
        else
            printf "${RED}[KO] - Memory leak detected${NC}\n"
            echo "$leak_output" | grep "in use at exit"
        fi
    done
}

# Main execution
printf "${YELLOW}Starting Push_Swap Tests${NC}\n\n"

# Run all tests
test_basic
test_valid
test_sorting
test_large
test_leaks

printf "\n${YELLOW}All tests completed!${NC}\n"
