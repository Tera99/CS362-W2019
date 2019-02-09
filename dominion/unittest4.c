/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
**************************************/
/*************************************
unittest4.c
testing updateCoins function
**************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("~~~~~Begining Unit Test 4~~~~~\n");
  printf("~~~~~Testing updateCoins function~~~~~\n");
  //declare variables
  int myPlayer = 0;
  int myBonus = 0;
  struct gameState myState;
  //clear the struct with memset
  memset(&myState, 0, sizeof(myState));

  //try calling the function, should return 0
  int result = updateCoins(myPlayer, &myState, myBonus);
  printf("Test 1 - empty game: ");
  if (result == 0){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //coins in hand left over from previous turn
  myState.coins = 10;
  int result2 = updateCoins(myPlayer, &myState, myBonus);
  printf("Test 2 - leftover coins: ");
  if (result2 == 0){
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  //test copper
  memset(&myState, 0, sizeof(myState));
  myState.handCount[myPlayer] = 10;
  int i;
  //fill the player hand with coppers
  for (i = 0; i < 10; i++){
    myState.hand[myPlayer][i] = copper;
  }
  updateCoins(myPlayer, &myState, myBonus);
  int result3 = myState.coins;
  printf("Test 3 - coppers: %d\n", result3);

  //test silver
  memset(&myState, 0, sizeof(myState));
  myState.handCount[myPlayer] = 10;
  //fill the player hand with silver
  for (i = 0; i < 10; i++){
    myState.hand[myPlayer][i] = silver;
  }
  updateCoins(myPlayer, &myState, myBonus);
  int result4 = myState.coins;
  printf("Test 4 - silver: %d\n", result4);

  //test gold
  memset(&myState, 0, sizeof(myState));
  myState.handCount[myPlayer] = 10;
  //fill the player hand with gold
  for (i = 0; i < 10; i++){
    myState.hand[myPlayer][i] = gold;
  }
  updateCoins(myPlayer, &myState, myBonus);
  int result5 = myState.coins;
  printf("Test 5 - gold: %d\n", result5);

  //test copper + silver + gold
  memset(&myState, 0, sizeof(myState));
  myState.handCount[myPlayer] = 30;
  //fill the player hand with coppers
  for (i = 0; i < 10; i++){
    myState.hand[myPlayer][i] = copper;
  }
  for (i = 10; i < 20; i++){
    myState.hand[myPlayer][i] = silver;
  }
  for (i = 20; i < 30; i++){
    myState.hand[myPlayer][i] = gold;
  }
  updateCoins(myPlayer, &myState, myBonus);
  int result6 = myState.coins;
  printf("Test 6 - copper, silver, and gold: %d\n", result6);

  //test bonus
  memset(&myState, 0, sizeof(myState));
  updateCoins(myPlayer, &myState, 10);
  int result7 = myState.coins;
  printf("Test 7 - bonus: %d\n", result7);

  printf("~~~~~End testing updateCoins function~~~~~\n");
  printf("~~~~~End Unit Test 4~~~~~\n");
  return 0;
}
