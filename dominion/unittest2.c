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
  //report2 results of tests
  int result, result1, result2;
  char[10] report1, report2, report3;
  //call supplyCount function
  result = supplyCount(myCard, &myState);
  if (result==0){
    strcpy (report1, "PASSED");
  } else {
    strcpy (report1, "FAILED");
  }

  //test 2 - add some cards to the deck
  myState.supplyCount[myCard1] = 25;
  myState.supplyCount[myCard2] = 100;
  result1 = supplyCount(myCard1, &myState);
  result2 = supplyCount(myCard2, &myState);
  if (result1==25){
    strcpy (report2, "PASSED");
  } else {
    strcpy (report2, "FAILED");
  }

  if (result2==100){
    strcpy (report3, "PASSED");
  } else {
    strcpy (report3, "FAILED");
  }



/*
  printf("Test 0 result is: %d\n", result);
  printf("Test 1 result: %d\n", result1);
  printf("Test 2 result: %d\n", result2);
*/

  //subtract cards from the deck

  //negative number of cards??

  //extremely large number of a card

  //check the last type of card

  //print test reports
  printf("Test 1 - empty supply: %s\n", report);
  printf("Test 2 - add cards: %s\n", report2);
  printf("Test 3 - large number of cards: %s\n", report3);

  printf("~~~~~End testing supplyCount function~~~~~\n");
  printf("~~~~~End Unit Test 2~~~~~\n");
  return 0;
}
