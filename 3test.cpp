#include<vector>
#include<iostream>
#include<curses.h>
#include <cstring>
#include <string>
//If the string is longer than the allocated amount for the data then 
//cut the string and move it to the next node
//To have the greatest amount of control possible make a class that
//contains the single char and the location of that char. That way
//it can be easily the char in that location can easily be replaced or deleted.
//Replacing/deleting chords will be hard (Maybe not since they will all be under the same 
//index



/* BATTLE PLAN
   Each Line will be a Linked List of single chars. There will only be 6 Linked Lists
   so new lines will be an illusion. The LLs are needed to be able to access the very first
   Node in the list and traverse. 
*/


                                                                                                                                                     
//Each line will be 150 spaces long bookended with |




class List{
  public:
    List();
    ~List();
    void insert(char c);
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
  Node *ptr = m_head;
  while(ptr!=NULL)
  {
    printw( "%s", &(ptr->m_c) );
    ptr =ptr->m_next;
  }
  printw( "\n");
  //delete ptr;
}

//Goal insert and print for all 6 lines through megaList

class listLine{
  public:
    listLine(){};
    void insert(char string[100]);
    void print();
  private:
    List EString;
    List bString;
    List gString;
    List dString;
    List aString;
    List eString;
};

void listLine::insert(char string[100]){
  char which;
  for(int i=0;i<100;i++){
    if(string[i] == '$')
      break;
    if(string[i] == 'e'){
      eString.insert(string[i+1]);
      aString.insert('-');
      dString.insert('-');
      gString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'a'){
      aString.insert(string[i+1]);
      eString.insert('-');
      dString.insert('-');
      gString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'd'){
      dString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      gString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'g'){
      gString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      dString.insert('-');
      bString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'b'){
      bString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      dString.insert('-');
      gString.insert('-');
      EString.insert('-');
    }
    if(string[i] == 'E'){
      EString.insert(string[i+1]);
      eString.insert('-');
      aString.insert('-');
      dString.insert('-');
      gString.insert('-');
      bString.insert('-');
    }
  }
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

void megaList::insert(char string[100]){
  listLine *ll = new listLine();
  ll->insert(string);
  if(m_head == NULL)
    m_head = new listLineNode(ll, NULL);
  else
    m_head->m_lLine->insert(string);
}

void megaList::print(){
  listLineNode* ptr = m_head;
  while(ptr!=NULL){
    ptr->m_lLine->print();
    ptr = ptr->m_next;
  }
}

int main()
{
  initscr();
  (void)echo();
  char test[100];
//  List listE;
//  List liste;
  megaList meg;
  for(int i=0;i<100;i++){
    test[i] = '$';
  }

  addstr( "> " );
  getnstr(test, sizeof( test ) -1);
  while(true){
  clear();
  refresh();
  meg.insert(test);
  meg.print();
  /*
  liste.insert(test[0]);
  liste.print();
  listE.insert(test[1]);
  listE.print();
  */
  //printw( "%s\n", test);
  
  refresh();
  addstr( "test> " );
  for(int i=0;i<100;i++){
    test[i] = '$';
  }
  getnstr(test, sizeof( test ) -1);
  }
  endwin();
  return 0;
}  
