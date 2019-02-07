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
  printf("~~~~~Begining Card Test 4~~~~~\n");
  printf("~~~~~Testing sea_hagEffect function~~~~~\n");

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

  //call villageEffect, should return zero
  result = sea_hagEffect(&myState);
  printf("Test result: %d\n", result);


  printf("~~~~~End testing sea_hagEffect function~~~~~\n");
  printf("~~~~~End Card Test 4~~~~~\n");
  return 0;
}
