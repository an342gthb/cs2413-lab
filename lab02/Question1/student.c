// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    char stack[strlen(s)/2];
    int top=-1;

    if(strlen(s)%2 !=0 || s == NULL){
        return false;
    }
    
    for(int i = 0; i<((int)strlen(s)); i++){
        char current = s[i];
        if(current == '(' || current == '[' || current == '{'){
            if(top<(int)(strlen(s)/2)-1){
                stack[++top] = s[i];
            }
            else{
                return false;
            }
        }
        else{
            if(top==-1)
                return false;
            char top2 = stack[top];
            if((current == ')' && top2 == '(')
                || (current == ']' && top2 == '[')
                || (current == '}' && top2 == '{')){
                    top--;
                }
                else{
                    return false;
                }
        }
    }

    return (top==-1);
    //return false; // placeholder
}
