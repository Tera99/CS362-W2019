/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
**************************************/
/*************************************
cardtest1.c
testing adventurerEffect function
**************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("~~~~~Begining Card Test 1~~~~~\n");
  printf("~~~~~Testing adventurerEffect function~~~~~\n");

  //initialize a blank game state
  int result;
  struct gameState myState;
  //clear the struct with memset
  memset(&myState, 0, sizeof(myState));

  //call adventurerEffect, should return zero
  result = adventurerEffect(&myState);
  printf("Test result: %d\n", result);


  printf("~~~~~End testing adventurerEffect function~~~~~\n");
  printf("~~~~~End Unit Test 1~~~~~\n");
  return 0;
}
