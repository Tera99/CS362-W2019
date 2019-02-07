/*************************************
Terezie (Tera) Schaller
Assignment 3
Unit tests for dominion.c
**************************************/
/************************************
unittest1.c
function tested: whoseTurn
3 tests
test 1 : sets the turn to 0
test 2 : increments game state turn
test 3 : returns turn state to zero
REFERENCES
https://stackoverflow.com/questions/44012865/error-invalid-type-argument-of-have-struct-xmplrpc-binding
*************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
  printf("~~~~~Begining Unit Test 1~~~~~\n");
  printf("~~~~~Testing whoseTurn function~~~~~\n");
  //initialize variables
  int result, result2, result3;
  char report[10];
  char report2[10];
  char report3[10];
  struct gameState myState;
  myState.whoseTurn = 0;

  //call whoseTurn on new gameState
  result = whoseTurn(&myState);
  if (result==0){
    strcpy(report, "PASSED");
  } else {
    strcpy(report, "FAILED");
  }

  //increment whose turn
  myState.whoseTurn++;
  result2 = whoseTurn(&myState);
  if (result2==1){
    strcpy(report2, "PASSED");
  } else {
    strcpy(report2, "FAILED");
  }

  //reset whose turn to zero
  myState.whoseTurn = 0;
  result3 = whoseTurn(&myState);
  if (result3==0){
    strcpy(report3, "PASSED");
  } else {
    strcpy(report3, "FAILED");
  }

  //provide user with unambiguos results
  printf("Test 1: %s\n", report);
  printf("Test 2: %s\n", report2);
  printf("Test 3: %s\n", report3);


  printf("~~~~~End testing whoseTurn function~~~~~\n");
  printf("~~~~~End Unit Test 1~~~~~\n");
  return 0;
}
