#include <stdio.h>
#include <stdlib.h>

void validatePar(char *arr, int *res, int length) {
    int openCounter = 0;
    int closedCounter = 0;
    if (arr[0] == ')' || arr[length-1] == '(') {
        return;
    }
    for (int i = 0; i < length; i++) {
        if (arr[i] == '(') {
            openCounter++;
        } else if (arr[i] == ')') {
            closedCounter++;
        }
        if (closedCounter > openCounter) {
            return;
        }
    }
    *res = *res + 1;
    return;
}

void generatePar(int openPCounter, int closedPCounter, int counter, int initialN, char *arr, int *res) {
    if (counter == initialN) {
        arr[counter] = '\0';
        printf("%s\n", arr);
        validatePar(arr, res, initialN);
        return;
    }
    if (openPCounter < initialN / 2) {
        arr[counter] = '(';
        generatePar(openPCounter+1, closedPCounter, counter+1, initialN, arr, res);
    }
    if (closedPCounter < initialN / 2) {
        arr[counter] = ')';
        generatePar(openPCounter, closedPCounter+1, counter+1, initialN, arr, res);
    }
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int *res = calloc(1, sizeof(int));
    if (n % 2 == 0) {
        char *arr = calloc(n + 1, sizeof(char));
        generatePar(0, 0, 0, n, arr, res);
        free(arr);
    }
    printf("res: %d\n", *res);
    free(res);
    return 0;
}

/*
Well formed strings of parentheses
A well formed string of parentheses is defined by the following (recursive) rules:
• The empty string is well formed.
• If s is a well formed string, then (s) is a well formed string.
• If s and t are well formed strings, then their concatenation st is a well formed string.
For example, "((()))" and "()()()" are well formed strings, while "(()", ")(()" and
"(" are not well formed strings.
There are exactly 5 well formed strings that have length 6: "((()))", "(()())", "(())()",
"()(())", and "()()()".
The input of this problem consists of a non-negative integer n (where 1 ≤ n ≤ 30). Your
program should output the number of well formed strings of parentheses that have length n.
Examples:
input: 6, output: 5
input: 3, output: 0
input: 10, output: 42
*/
