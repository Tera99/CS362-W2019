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
  printf("~~~~~Testing cardEffect(sea_hag) function~~~~~\n");

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

  /*
  //call villageEffect, should return zero
  result = sea_hagEffect(&myState);
  printf("Test result: %d\n", result);
  */

  //call cardEffect - sea_hag
  result = cardEffect(sea_hag, choice1, choice2, choice3, &myState2, myHandPos, &bonus);
  printf("Test 1 - call cardEffect(sea_hag): ");
  if (result == 0){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //test drawing a card
  //hand - difference should be zero
  int currentPlayer = whoseTurn(&myState2);
  int result2 = myState.handCount[currentPlayer];
  int result3 = myState2.handCount[currentPlayer];
  printf("Test 2 - num cards in hand: ");
  if (result3 == result2){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //discard pile
  int result4 = myState.discardCount[currentPlayer];
  int result5 = myState2.discardCount[currentPlayer];
  printf("Test 3 - num cards in discard pile: ");
  if (result5 == result4){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //deck
  int result6 = myState.deckCount[currentPlayer];
  int result7 = myState2.deckCount[currentPlayer];
  printf("Test 4 - num cards in deck: ");
  if (result7 == result6){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //test other player 




  printf("~~~~~End testing sea_hagEffect function~~~~~\n");
  printf("~~~~~End Card Test 4~~~~~\n");
  return 0;
}
