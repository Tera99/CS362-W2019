/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
**************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("Begining Unit Test 1\n");
  printf("~~~~~Testing whoseTurn function~~~~~\n")
  //set up the variables and call the function
  //create a gameState and call whoseTurn on it
  int result;
  struct gameState myState;

  result = whoseTurn(&myState);

  printf("result of whoseTurn: %d", result);

  printf("~~~~~End testing whoseTurn function~~~~~\n")
  printf("End Unit Test 1\n");
  return 0;
}
