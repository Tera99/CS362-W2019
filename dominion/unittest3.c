/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
unittest3.c
testing scoreFor function
**************************************/
/*************************************
unittest3.c
testing scoreFor function
**************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
  printf("~~~~~Begining Unit Test 3~~~~~\n");
  printf("~~~~~ Testing scoreFor function ~~~~~\n");
  //initialize needed variables
  int myPlayer = 0;
  struct gameState myState;
  //clear the struct with memset
  memset(&myState, 0, sizeof(myState));

  //try calling scoreFor
  int result = scoreFor(myPlayer, &myState);
  if (result == 0){
    printf("Test 1 - empty deck: PASSED\n");
  } else {
    printf("Test 1 - empty deck: FAILED\n");
  }
  //test hand
  myState.hand[myPlayer][0] = estate;
  myState.hand[myPlayer][1] = duchy;
  myState.hand[myPlayer][2] = province;
  myState.hand[myPlayer][3] = great_hall;
  myState.hand[myPlayer][4] = curse;
  myState.handCount[myPlayer] = 5;
  int result2 = scoreFor(myPlayer, &myState);
  printf("Test 2 - hand, expected: 10 - result: %d :", result2);
  if (result2 == 10){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //clear game state
  memset(&myState, 0, sizeof(myState));
  //test discard
  myState.discard[myPlayer][0] = estate;
  myState.discard[myPlayer][1] = duchy;
  myState.discard[myPlayer][2] = province;
  myState.discard[myPlayer][3] = great_hall;
  myState.discard[myPlayer][4] = curse;
  myState.discardCount[myPlayer] = 5;
  int result3 = scoreFor(myPlayer, &myState);
  printf("Test 3 - discard, expected: 10 - result: %d :", result3);
  if (result3 == 10){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //clear game state
  memset(&myState, 0, sizeof(myState));
  //test deck
  myState.deck[myPlayer][0] = estate;
  myState.deck[myPlayer][1] = duchy;
  myState.deck[myPlayer][2] = province;
  myState.deck[myPlayer][3] = great_hall;
  myState.deck[myPlayer][4] = curse;
  myState.deckCount[myPlayer] = 5;
  int result4 = scoreFor(myPlayer, &myState);
  printf("Test 4 - deck, expected: 10 - result: %d :", result4);
  if (result4 == 10){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //test hand + discard + decks
  //add cards to all three at once
  //clear game state
  memset(&myState, 0, sizeof(myState));
  //add to hand
  myState.hand[myPlayer][0] = estate;
  myState.hand[myPlayer][1] = duchy;
  myState.hand[myPlayer][2] = province;
  myState.hand[myPlayer][3] = great_hall;
  myState.hand[myPlayer][4] = curse;
  myState.handCount[myPlayer] = 5;
  //add to discard
  myState.discard[myPlayer][0] = estate;
  myState.discard[myPlayer][1] = duchy;
  myState.discard[myPlayer][2] = province;
  myState.discard[myPlayer][3] = great_hall;
  myState.discard[myPlayer][4] = curse;
  myState.discardCount[myPlayer] = 5;
  //add to deck
  myState.deck[myPlayer][0] = estate;
  myState.deck[myPlayer][1] = duchy;
  myState.deck[myPlayer][2] = province;
  myState.deck[myPlayer][3] = great_hall;
  myState.deck[myPlayer][4] = curse;
  myState.deckCount[myPlayer] = 5;
  //print result
  int result5 = scoreFor(myPlayer, &myState);
  printf("Test 5 - hand + discard + deck, expected: 30 - result: %d :", result5);
  if (result4 == 30){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }



  printf("~~~~~ End testing scoreFor function ~~~~~\n");
  printf("~~~~~End Unit Test 3~~~~~\n");
  return 0;
}
