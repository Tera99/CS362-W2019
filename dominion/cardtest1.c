/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
**************************************/
/*************************************
cardtest1.c
testing adventurerEffect function
REFERENCES
Lecture material: https://oregonstate.instructure.com/courses/1706563/files/73152166?module_item_id=18416505
**************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("~~~~~Begining Card Test 1~~~~~\n");
  printf("~~~~~Testing cardEffect(adventurer) function~~~~~\n");

  //initialize a blank game state
  int result;
  int myHandPos = 0;
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int bonus = 0;
  struct gameState myState;
  struct gameState myState2;
  //clear the struct with memset
  memset(&myState, 0, sizeof(myState));
  memset(&myState2, 0, sizeof(myState));

  //need a valid game in progress to call adventurerEffect
  //or else it segfaults
  int numPlayers = 2;
  int k[10] = {adventurer, embargo, village, minion, mine,
    cutpurse,sea_hag, tribute, smithy, council_room};
  int seed = 1000;

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &myState);
  //copy game state for testing
  memcpy(&myState2, &myState, sizeof(struct gameState));

  //call adventurerEffect, should return zero
  /*
  result = adventurerEffect(&myState);
  printf("Test result: %d\n", result);
  */

  //call cardEffect - adventurer
  result = cardEffect(adventurer, choice1, choice2, choice3, &myState2, myHandPos, &bonus);
  printf("Test 1 - call cardEffect(adventurer): ");
  if (result == 0){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //check that hand has increase by 2 card
  int currentPlayer = whoseTurn(&myState2);
  int result2 = myState.handCount[currentPlayer];
  int result3 = myState2.handCount[currentPlayer];
  printf("Test 2 - gained 2 treasure to hand: ");
  if ((result3 - result2) == 2){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //check that coinage has increased by at least 2
  printf("Test 3 - treasure to correct coinage: ");
  printf("FAILED\n");
  //See bug report. This needs to be tested but is nothandled by code at all
  //update this test after refactoring

  //check that deck has decreased
  int result4 = myState.deckCount[currentPlayer];
  int result5 = myState2.deckCount[currentPlayer];
  printf("Test 4 - deck decreased")
  if ((result5 - result4) >= 2){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }



  printf("~~~~~End testing adventurer~~~~~\n");
  printf("~~~~~End Unit Test 1~~~~~\n");
  return 0;
}
