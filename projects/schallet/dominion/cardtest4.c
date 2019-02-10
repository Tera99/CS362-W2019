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
  int nextPlayer = currentPlayer + 1;
  if (nextPlayer > numPlayers-1){
    nextPlayer = 0;
  }
  //hand
  int result8 = myState.handCount[nextPlayer];
  int result9 = myState2.handCount[nextPlayer];
  printf("Test 5 - opponent hand: ");
  if (result8 == result9){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //discard
  int result10 = myState.discardCount[nextPlayer];
  int result11 = myState2.discardCount[nextPlayer];
  printf("Test 6 - opponent discard: ");
  if ((result11 - result10) == 1){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //deck
  int result12 = myState.deckCount[nextPlayer];
  int result13 = myState2.deckCount[nextPlayer];
  printf("Test 7 - opponent deck: ");
  if (result12 == result13){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //scores
  //current player should be the same
  int result14 = scoreFor(currentPlayer, &myState);
  int result15 = scoreFor(currentPlayer, &myState2);
  printf("Test 8 - curent player score: ");
  if (result14 == result15){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //opponent should have -1
  int result16 = scoreFor(nextPlayer, &myState);
  int result17 = scoreFor(nextPlayer, &myState2);
  printf("Test 9 - opponent score: ");
  if ((result17 - result16) == -1){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }





  printf("~~~~~End testing sea_hag~~~~~\n");
  printf("~~~~~End Card Test 4~~~~~\n");
  return 0;
}
