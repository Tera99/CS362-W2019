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
  //int myCard3 = 3;
  struct gameState myState;
  myState.supplyCount[myCard] = 0;
  //report results of tests
  int result, result1, result2, result3, result4;
  char report1[10];
  char report2[10];
  char report3[10];
  char report4[10];
  char report5[10];

  //call supplyCount function
  result = supplyCount(myCard, &myState);
  if (result==0){
    strcpy (report1, "PASSED");
  } else {
    strcpy (report1, "FAILED");
  }

  //test 2 - add some cards to the deck, including larger numbers than would be
  //needed in a normal game
  myState.supplyCount[myCard1] = 25;
  myState.supplyCount[myCard2] = 100;
  result1 = supplyCount(myCard1, &myState);
  result2 = supplyCount(myCard2, &myState);
  if (result1==25){
    strcpy (report2, "PASSED");
  } else {
    strcpy (report2, "FAILED");
  }

  if (result2 == 100){
    strcpy (report3, "PASSED");
  } else {
    strcpy (report3, "FAILED");
  }

  //subtract cards from the deck
  myState.supplyCount[myCard1]--;
  result3 = supplyCount(myCard1, &myState);
  if (result3 == 24){
    strcpy (report4, "PASSED");
  } else {
    strcpy (report4, "FAILED");
  }

  //negative number of cards??
  myState.supplyCount[myCard]--;
  result4 = supplyCount(myCard, &myState);
  if (result4 == -1){
    strcpy (report5, "PASSED");
  } else {
    strcpy (report5, "FAILED");
  }

  //print test reports
  printf("Test 1 - empty supply: %s\n", report1);
  printf("Test 2 - add cards: %s\n", report2);
  printf("Test 3 - large number of cards: %s\n", report3);
  printf("Test 4 - subtract cards: %s\n", report4);
  printf("Test 5 - negative number of cards: %s\n", report5);

  printf("~~~~~End testing supplyCount function~~~~~\n");
  printf("~~~~~End Unit Test 2~~~~~\n");
  return 0;
}
