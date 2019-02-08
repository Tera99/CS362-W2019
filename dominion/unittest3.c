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
  myState.hand[myPlayer][1] = dutchy;
  myState.hand[myPlayer][2] = province;
  myState.hand[myPlayer][3] = great_hall;
  myState.hand[myPlayer][4] = curse;
  myState.handCount[0] = 5;
  result = scoreFor(myPlayer, &myState);
  printf("Test result: %d\n", result);

  printf("~~~~~ End testing scoreFor function ~~~~~\n");
  printf("~~~~~End Unit Test 3~~~~~\n");
  return 0;
}
