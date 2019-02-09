/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
**************************************/
/*************************************
cardtest2.c
testing smithyEffect function
REFERENCES
Lecture material: https://oregonstate.instructure.com/courses/1706563/files/73152166?module_item_id=18416505
http://man7.org/linux/man-pages/man3/memcpy.3.html
**************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("~~~~~Begining Card Test 2~~~~~\n");
  printf("~~~~~Testing smithyEffect function~~~~~\n");
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

  //call smithyEffect, should return zero
  /*
  result = smithyEffect(&myState, myHandPos);
  printf("Test result: %d\n", result);
  */

  //call cardEffect - smithy
  result = cardEffect(smithy, choice1, choice2, choice3, &myState2, myHandPos, &bonus);
  printf("Test result: %d\n", result);

  //test that player hand has correct number of cards in hand
  int currentPlayer = whoseTurn(&myState2);
  int result2 = myState.handCount[currentPlayer];
  int result3 = myState2.handCount[currentPlayer];
  printf("result2 %d, result3 %d\n", result2, result3);

  //check that other player's hand not affected
  int nextPlayer = currentPlayer + 1;
  if (nextPlayer > numPlayers-1){
    nextPlayer = 0;
  }
  printf("currentPlayer: %d\n", currentPlayer);
  printf("nextPlayer: %d\n", nextPlayer);
  int result4 = myState.handCount[nextPlayer];
  int result5 = myState2.handCount[nextPlayer];
  printf("result4: %d, result5 %d\n", result4, result5);

  printf("~~~~~End testing smithyEffect function~~~~~\n");
  printf("~~~~~End Card Test 2~~~~~\n");
  return 0;
}
