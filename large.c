#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

const char *expr;
char current_char;

// Function to advance to the next character
void advance() {
    current_char = *expr++;
}

// Function to skip whitespace
void skip_whitespace() {
    while (isspace(current_char)) {
        advance();
    }
}

// Function to parse numbers
int parse_number() {
    int result = 0;
    while (isdigit(current_char)) {
        result = (result << 3) + (result << 1) + (current_char - '0');  // replaced *10
        advance();
    }
    return result;
}


// Forward declarations
int parse_expression();

// Function to parse factors (numbers or parenthesized expressions)
int parse_factor() {
    skip_whitespace();
    if (current_char == '(') {
        advance(); // consume '('
        int result = parse_expression();
        if (current_char == ')') {
            advance(); // consume ')'
        } else {
            printf("Error: Expected ')'\n");
            exit(1);
        }
        return result;
    } else if (isdigit(current_char)) {
        return parse_number();
    } else {
        printf("Error: Unexpected character '%c'\n", current_char);
        exit(1);
    }
}

// Function to parse terms (factors separated by '*' or '/')
int parse_term() {
    int result = parse_factor();
    skip_whitespace();
    if (current_char == '*') {
        advance();
        result *= parse_term();
    } else if (current_char == '/') {
        advance();
        int divisor = parse_term();
        if (divisor == 0) {
            printf("Error: Division by zero\n");
            exit(1);
        }
        result /= divisor;
    }
    return result;
}

// Function to parse expressions (terms separated by '+' or '-')
int parse_expression() {
    int result = parse_term();
    skip_whitespace();
    if (current_char == '+') {
        advance();
        result += parse_expression();
    } else if (current_char == '-') {
        advance();
        result -= parse_expression();
    }
    return result;
}

int main() {
    char input[256];
    printf("Enter an arithmetic expression: ");
    if (fgets(input, sizeof(input) + 1, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    expr = input;
    advance(); // Initialize current_char
    int result = parse_expression();
    skip_whitespace();
    if (current_char != '\0' && current_char != '\n') {
        printf("Error: Unexpected character '%c'\n", current_char);
        return 1;
    }
    printf("Result: %d\n", result);
    return 0;
}
