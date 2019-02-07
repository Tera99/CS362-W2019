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
  printf("Test results: %d\n", result);

  printf("~~~~~End testing updateCoins function~~~~~\n");
  printf("~~~~~End Unit Test 4~~~~~\n");
  return 0;
}
