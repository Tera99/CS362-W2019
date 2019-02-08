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
  printf("Test result: %d\n", result);

  //test hand
  myState.hand[myPlayer][0] = estate;
  myState.hand[myPlayer][1] = duchy;
  myState.hand[myPlayer][2] = province;
  myState.hand[myPlayer][3] = great_hall;
  myState.hand[myPlayer][4] = curse;
  myState.handCount[myPlayer] = 5;
  int result2 = scoreFor(myPlayer, &myState);
  printf("Test result: %d\n", result2);

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
  printf("Test result: %d\n", result3);

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
  printf("Test result: %d\n", result4);

  printf("~~~~~ End testing scoreFor function ~~~~~\n");
  printf("~~~~~End Unit Test 3~~~~~\n");
  return 0;
}
