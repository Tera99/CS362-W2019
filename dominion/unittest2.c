/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
**************************************/
/*************************************
unittest2.c
testing supplyCount function
**************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("Begining Unit Test 2\n");
  printf("~~~~~Testing supplyCount function~~~~~\n");
  //initialize variables
  int myCard = 0;
  struct gameState myState;
  myState.supplyCount[myCard] = 0;
  int result;
  //call supplyCount function
  result = supplyCount(myCard, &myState);
  printf("The test result is: %d\n", result);

  printf("~~~~~End testing supplyCount function~~~~~\n");
  printf("End Unit Test 2\n");
  return 0;
}
