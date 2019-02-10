#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//REFERENCES
//https://stackoverflow.com/questions/20026727/how-to-convert-integers-to-characters-in-c
//http://www.asciitable.com
//https://www.geeksforgeeks.org/arrays-in-c-cpp/
//https://www.geeksforgeeks.org/generating-random-number-range-c/

char inputChar()
{
    // TODO: rewrite this function
    //figure out the range of numbers based on testme()
    int arr[] = {32, 40, 41, 91, 93, 97, 123, 120, 125};

    //generate random number from 0 to 8
    int index = rand() % 9;

    //convert integer into a character and return
    return (char) arr[index];
}

char *inputString()
{
    // TODO: rewrite this function
    //create a random string
    int size = 6;
    int arr[] = {101, 114, 115, 116};
    static char random[6];
    random[size-1] = '\0';

    int i;
    int rando_index;
    for(i=0; i < size-1; i++){
      rando_index = rand() % 5;
      random[i] = arr[rando_index];
    }

    return random;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
                                            //ascii decimal
    if (c == '[' && state == 0) state = 1; //91
    if (c == '(' && state == 1) state = 2; //40
    if (c == '{' && state == 2) state = 3; //123
    if (c == ' '&& state == 3) state = 4;  //32
    if (c == 'a' && state == 4) state = 5; //97
    if (c == 'x' && state == 5) state = 6; //120
    if (c == '}' && state == 6) state = 7; //125
    if (c == ')' && state == 7) state = 8; //41
    if (c == ']' && state == 8) state = 9; //93
    if (s[0] == 'r' && s[1] == 'e' //114  //101
       && s[2] == 's' && s[3] == 'e' //115  //101
       && s[4] == 't' && s[5] == '\0' //116 //0
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
