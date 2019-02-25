//randomtestcard2.c
/************************************
** randomtestcard2.c
** CS362 winter 2019
** Assignment 4
** Terezie (Tera) Schaller
*************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("~~~~~Begining Card 2 Random Testing~~~~~\n");
  printf("~~~~~Random Testing: sea_hag effect~~~~~\n");
  printf("Test 1: positive control, call sea_hag effect\n");
  //need a valid game in progress to call sea_hagEffect
  int numPlayers = 2;
  int k[10] = {adventurer, embargo, village, minion, mine,
    cutpurse,sea_hag, tribute, smithy, council_room};
  int seed = 1000;
  int result;
  //create and initialize a game state
  struct gameState myState;
  memset(&myState, 0, sizeof(myState));
  initializeGame(numPlayers, k, seed, &myState);

  //call villageEffect, should return zero
  result = sea_hagEffect(&myState);
  printf("Test result: %d\n", result);
  if (result == 0){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }
  //end posiive control

  //randomized testing

  //randomize Testing
  //randomize # players and seed to initializeGame
  srand(time(0));
  int randPlayer;
  int gameSeed;
  //repeat 100 times:
  //start game with 2-4 players
  //rand() % 3 + 2
  //seed InitializeGame with 1-1000
  //rand() % 1000
  int i;
  int testFail = 0;
  int passedTests = 0;
  for (i = 0; i < 100; i++){
    testFail = 0;
    randPlayer = rand() % 3 + 2;
    gameSeed = rand() % 1000;
    //initialize game state
    memset(&myState, 0, sizeof(myState));
    memset(&myState2, 0, sizeof(myState));
    initializeGame(randPlayer, k, gameSeed, &myState);
    //copy initialized game state for testing
    memcpy(&myState2, &myState, sizeof(struct gameState));
    //run vsea_hagEffect on second game state, compare states in tests
    result1 = sea_hagEffect(&myState2);
    if (result1 != 0){
      printf("Test 1: return sea_hagEffect: FAILED - ");
      printf("players: %d, ", randPlayer);
      printf("seed: %d\n", gameSeed);
      testFail = 1;
    }




  } //end of for loop


}



//end randomtestcard2.c
