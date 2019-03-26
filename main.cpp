#include "list.h"
char vi  = 'c';


//Linked list structure allows for fully dynamic capability
//You can insert & delete between individual tabs as well as tablines, and also
//easily edit tabs and tablines

/* Goal Queue


Implement DLL for printing last 7 (or fewer) tablines (fixes spacing issues);

Implement Enter/Backspace for adding empty spaces and deleting columns respectively.

Implement Arrow keys to move the view of the 7 tablines (assuming there are more than 7)

Implement editing system for lines

Implement editing system for tablines

Implement Tab cut off after 150 chars

Implement repeat feature

Fix bugs that occur when you enter non digits

Take care of Memory Leaks

Implement File input

Implement error checking for incorrect strings

Implement common chord patterns as a single command(G, C, E, etc..)

Implement a feature that allows users to define their own custom chords. 

Implement a robust title screen
*/


//Each line will be 150 spaces long bookended with |

void printtitle(){
//  printw("%s", "WELCOME TO ");
  printw("%s", " _     _____ _____  _   _ _____ _   _ _____ _   _ _____   _____ ___  ______ \n");
  printw("%s", "| |   |_   _|  __ \\| | | |_   _| \\ | |_   _| \\ | |  __ \\ |_   _/ _ \\ | ___ \\ \n");
  printw("%s", "| |     | | | |  \\/| |_| | | | |  \\| | | | |  \\| | |  \\/   | |/ /_\\ \\| |_/ / \n"); 
  printw("%s", "| |     | | | | __ |  _  | | | | . ` | | | | . ` | | __    | ||  _  || ___ \\ \n"); 
  printw("%s", "| |_____| |_| |_\\ \\| | | | | | | |\\  |_| |_| |\\  | |_\\ \\   | || | | || |_/ / \n");
  printw("%s", "\\_____/\\___/ \\____/\\_| |_/ \\_/ \\_| \\_/\\___/\\_| \\_/\\____/   \\_/\\_| |_/\\____/  \n\n");
  printw("%s", "PRESS ENTER TO CONTINUE\n");
}


int main()
{
  initscr();
  (void)echo();
  char test[100];
  megaList meg;
  for(int i=0;i<100;i++){
    test[i] = '$';
  }
  keypad(stdscr, TRUE);

  //addstr( "lightningTab> " );
  printtitle();

  getnstr(test, sizeof( test ) -1);
  meg.fileInsert();
  while(true){
  clear();
  refresh();
  meg.insert(test, false);
  remove( "output.txt" );
  meg.print();
  
  refresh();
  if(vi == 'i')
    addstr( "lightningTab[I]> " );
  else
    addstr( "lightningTab[V]> " );
  for(int i=0;i<100;i++){
    test[i] = '$';
  }
  switch(vi){
    case 'i':
      getnstr(test, sizeof( test ) -1);
      break;
    case 'c':
      int input = getch();
      if(input == 'i')
	vi = 'i';
      if(input == 'd')
	sleep(1);
      if(input == 'j')
	meg.shiftDown();
      if(input == 'k')
	meg.shiftUp();
      break;
  }
  Dash = true;
  }
  endwin();
  return 0;
}  
