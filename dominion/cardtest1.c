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
  struct gameState myState;
  //clear the struct with memset
  memset(&myState, 0, sizeof(myState));

  //need a valid game in progress to call adventurerEffect
  //or else it segfaults
  int numPlayers = 2;
  int k[10] = {adventurer, embargo, village, minion, mine,
    cutpurse,sea_hag, tribute, smithy, council_room};
  int seed = 1000;

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &myState);

  //call adventurerEffect, should return zero
  result = adventurerEffect(&myState);
  printf("Test result: %d\n", result);


  printf("~~~~~End testing adventurer~~~~~\n");
  printf("~~~~~End Unit Test 1~~~~~\n");
  return 0;
}
