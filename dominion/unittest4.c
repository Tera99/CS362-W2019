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
  myState.handcount[myPlayer] = 10;
  int i;
  //fill the player hand with coppers
  for (i = 0; i < 10, i++){
    myState.hand[myPlayer][i] = copper;
  }
  int result3 = updateCoins(myPlayer, &myState, myBonus);
  printf("Test 3 - coppers: %d\n", result3);

  //test silver

  //test gold

  //test bonus

  //test copper + silver + gold + bonus

  printf("~~~~~End testing updateCoins function~~~~~\n");
  printf("~~~~~End Unit Test 4~~~~~\n");
  return 0;
}
