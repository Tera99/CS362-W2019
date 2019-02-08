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
  printf("~~~~~Begining Unit Test 2~~~~~\n");
  printf("~~~~~Testing supplyCount function~~~~~\n");
  //initialize variables
  int myCard = 0;
  int myCard1 = 1;
  int myCard2 = 2;
  struct gameState myState;
  myState.supplyCount[myCard] = 0;
  int result, result1, result2;
  //call supplyCount function
  result = supplyCount(myCard, &myState);

  printf("Test 0 result is: %d\n", result);

  //test 2 - add some cards to the deck
  myState.supplyCount[myCard1] = 25;
  myState.supplyCount[myCard2] = 100;

  result1 = supplyCount(myCard1, &myState);
  result2 = supplyCount(myCard2, &myState);

  printf("Test 1 result: %d\n", result1);
  printf("Test 2 result: %d\n", result2);

  //subtract cards from the deck

  //negative number of cards??

  //extremely large number of a card

  //check the last type of card

  printf("~~~~~End testing supplyCount function~~~~~\n");
  printf("~~~~~End Unit Test 2~~~~~\n");
  return 0;
}
