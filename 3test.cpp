#include<vector>
#include<iostream>
#include<curses.h>
#include<cstring>
#include<string>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//Linked list structure allows for fully dynamic capability
//You can insert & delete between individual tabs as well as tablines, and also
//easily edit tabs and tablines

/* Goal Queue
RIGHT NOW: the output is appended to the file, but the output is the full tab everytime so you need to clear the file everytime(??) 
this will be a tricky problem when you are working with saving. I think the idea of reading in the file is that it will create the whole Linked List
structure out of what is read in. THE OVERALL GOAL IS FOR THE FILE TO MATCH EXACTLY WHAT IS ON THE SCREEN OF THE LAST SESSION.

Implement Double Digit Tabs 

WORKING ON:Implement Chords

Implement DLL for printing last 7 (or fewer) tablines (fixes spacing issues);

Implement Enter/Backspace for adding empty spaces and deleting columns respectively.

Implement Arrow keys to move the view of the 7 tablines (assuming there are more than 7)

Implement File output

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


class List{
  public:
    List();
    ~List();
    void insert(char c);
    void insertEnd();
    void print();
  private:
    class Node{
      public:
      Node(char c, Node *next)
      {m_c = c; m_next = next;}
      char m_c;
      Node *m_next;
    };
    Node *m_head;
};

List::List(){
  m_head = NULL;
  this->insert('|');
}

void List::insert(char c)
{                       
  Node *ptr =m_head;
  Node *lineSeperator=new Node('-', NULL);
  if(m_head==NULL){
    m_head = new Node(c, lineSeperator);
    //printw("%s\n", &(m_head->m_c));
  }
  else{
    while(ptr->m_next != NULL){
      ptr = ptr->m_next;
    }
    ptr->m_next = new Node(c, lineSeperator);
    //printw("%s\n", &(ptr->m_next->m_c));
  }
//  printw( "XXX: %c\n", ptr->m_c );
}

void List::insertEnd()
{                       
  Node *ptr =m_head;
  if(m_head==NULL){
    m_head = new Node('|', NULL);
    //printw("%s\n", &(m_head->m_c));
  }
  else{
    while(ptr->m_next != NULL){
      ptr = ptr->m_next;
    }
    ptr->m_next = new Node('|', NULL);
    //printw("%s\n", &(ptr->m_next->m_c));
  }
//  printw( "XXX: %c\n", ptr->m_c );
}

//Could cause issues
List::~List() 
{
  Node *ptr = m_head;
  while(ptr != NULL)
  {
    Node *temp;
    temp = ptr;
    ptr = ptr->m_next;
    delete temp;
  }
}

void List::print()
{
  std::ofstream myfile;
  myfile.open ("output.txt", std::ios_base::app);
  Node *ptr = m_head;
  while(ptr!=NULL)
  {
    printw( "%s", &(ptr->m_c) );
    std::string str(&(ptr->m_c));
    myfile << str;
    ptr =ptr->m_next;
  }
  printw( "\n");
  myfile << "\n";
  myfile.close();
  //delete ptr;
}

//Goal insert and print for all 6 lines through megaList

class listLine{
  public:
    listLine(){full = false;}
    void insert(char string[100]);
    void insertChord(char chord[22]);
    void print();
    bool isFull();
  private:
    bool full;
    List EString;
    List bString;
    List gString;
    List dString;
    List aString;
    List eString;
};

bool listLine::isFull(){
  return full;
}

void listLine::insert(char string[100]){
  char which;
  /*
  if(string[0] == '$'){
      eString.insert('-');
      aString.insert('-');
      dString.insert('-');
      gString.insert('-');
      bString.insert('-');
      EString.insert('-');
  }
  */
  for(int i=0;i<100;i++){
    if(string[i] == '$')
      break;
    if(string[i] == 'e' && isdigit(string[i+1])){
      eString.insert(string[i+1]);
      aString.insert('-');
      dString.insert('-');
      gString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'a' && isdigit(string[i+1])){
      aString.insert(string[i+1]);
      eString.insert('-');
      dString.insert('-');
      gString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'd' && isdigit(string[i+1])){
      dString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      gString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'g' && isdigit(string[i+1])){
      gString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      dString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'b' && isdigit(string[i+1])){
      bString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      dString.insert('-');
      gString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'E' && isdigit(string[i+1])){
      EString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      dString.insert('-');
      gString.insert('-');
      bString.insert('-');
    }
    if(string[i] == 'X'){
      EString.insertEnd();
      eString.insertEnd();
      aString.insertEnd();
      dString.insertEnd();
      gString.insertEnd();
      bString.insertEnd();
      full = true;
    }
    if(string[i] == 'c' && string[i+1] == 'h'){
//      int n = 2;
      int p = 0;
      char chord[22];
      for(int c = 0; c < 20; c++){
	chord[c] = '$';
      }
      while(string[i] != '|' && string[i] != '$'){
        chord[p] = string[i];	
	p = p + 1;
	i = i + 1;
      }
      insertChord(chord);
//      break;
    }
  }
}

void listLine::insertChord(char chord[22]){
  int e = 0;
  int a = 0;
  int d = 0;
  int g = 0;
  int b = 0;
  int E = 0;
  //printw("%s: ", chord);
  for(int i=0;i<22;i++){
    if(chord[i] == '$')
      break;
    if(chord[i] == 'e' && isdigit(chord[i+1]) && e == 0){
      eString.insert(chord[i+1]);
      e = 1;
    }
    if(chord[i] == 'a' && isdigit(chord[i+1]) && a == 0){
      aString.insert(chord[i+1]);
      a = 1;
    }
    if(chord[i] == 'd' && isdigit(chord[i+1]) && d == 0){
      dString.insert(chord[i+1]);
      d = 1;
    }
    if(chord[i] == 'g' && isdigit(chord[i+1]) && g == 0){
      gString.insert(chord[i+1]);
      g = 1;
    }
    if(chord[i] == 'b' && isdigit(chord[i+1]) && b == 0){
      bString.insert(chord[i+1]);
      b = 1;
    }
    if(chord[i] == 'E' && isdigit(chord[i+1]) && E == 0){
      EString.insert(chord[i+1]);
      E = 1;
    }
  }
  if(e == 0)
    eString.insert('-');
  if(a == 0)
    aString.insert('-');
  if(d == 0)
    dString.insert('-');
  if(g == 0)
    gString.insert('-');
  if(b == 0)
    bString.insert('-');
  if(E == 0)
    EString.insert('-');
}

void listLine::print(){
  EString.print();
  bString.print();
  gString.print();
  dString.print();
  aString.print();
  eString.print();
}

class megaList{
  public:
    megaList(){m_head = NULL;}
    void insert(char string[100]);
    void print();
  private:
    class listLineNode{
      public:
	listLineNode(listLine *lLine, listLineNode *next)
	{m_lLine = lLine; m_next = next;}
	listLine *m_lLine;
	listLineNode *m_next;
	
    };
    listLineNode *m_head;
};

/**
 * Determines which list line node to insert into
 * Note: It is likely a call to insert is made twice, but
 * It's inserted into different list nodes, so this is not a problem. 
 */

void megaList::insert(char string[100]){
  listLine *ll = new listLine();
  ll->insert(string);
  if(m_head == NULL)
    m_head = new listLineNode(ll, NULL);
  else{
    listLineNode *ptr = m_head;
    while(ptr->m_next != NULL && ptr->m_lLine->isFull() == true){
      ptr = ptr->m_next;
    }
    if(ptr->m_lLine->isFull() == false){
      ptr->m_lLine->insert(string);
    }
    else{
      ptr->m_next  = new listLineNode(ll, NULL);
    }
  }
}

void megaList::print(){
  //Need to edit this to only print the last 7 tblines, maybe doubly linked list?
  //If you use DLL Then start from tail and go up 7, then print until tail.
  std::ofstream myfile;
  myfile.open ("output.txt", std::ios_base::app);
  listLineNode* ptr = m_head;
  while(ptr!=NULL){
    ptr->m_lLine->print();
    printw("\n");
    myfile << "\n";
    ptr = ptr->m_next;
  }
  myfile.close();
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

  //addstr( "lightningTab> " );
  printtitle();


  getnstr(test, sizeof( test ) -1);
  while(true){
  clear();
  refresh();
  meg.insert(test);
  meg.print();
  
  refresh();
  addstr( "lightningTab> " );
  for(int i=0;i<100;i++){
    test[i] = '$';
  }
  getnstr(test, sizeof( test ) -1);
  }
  endwin();
  return 0;
}  
