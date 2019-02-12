#include<vector>
#include<iostream>
#include<curses.h>
#include <cstring>
#include <string>

int main()
  {
  std::vector<char*> vec;
  char users_name[ 100 ] = "ZZZ";
//  char test[100];

  initscr();
  (void)echo();
  vec.push_back(users_name);

  while(true){
  char *test = new char[50];
  clear();
  addstr( "test> " );
  refresh();
//  getnstr( users_name, sizeof( users_name ) - 1 );
  getnstr( test, sizeof( test ) -1);
  vec.push_back(test);

  /* Here is where we clear the screen.                  */
  /* (Remember, when using Curses, no change will appear */
  /* on the screen until <b>refresh</b>() is called.     */
  clear();

 // for(int i=0;i<vec.size();i++){
//  printw( "Greetings and salutations %s!\n", vec[i]);
  printw( "Size: %d\n", vec.size() ); 
 // }
  for (std::vector <char*>::const_iterator it = vec.begin(); it != vec.end(); it++)
    printw( "XXX: %s\n", *it ); 

  refresh();

  printw( "\n\n\nPress ENTER to quit." );
  refresh();
  getnstr( test, sizeof( test) - 1 );
  }

  endwin();
  return 0;
  }  
