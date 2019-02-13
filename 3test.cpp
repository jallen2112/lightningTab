#include<vector>
#include<iostream>
#include<curses.h>
#include<cstring>
#include<string>
#include<fstream>


//Linked list structure allows for fully dynamic capability
//You can insert between individual tabs as well as tab lines, and also
//easily edit tabs and tablines

/* Goal Queue
RIGHT NOW: the output is appended to the file, but the output is the full tab everytime so you need to clear the file everytime(??) 
this will be a tricky problem when you are working with saving. I think the idea of reading in the file is that it will create the whole Linked List
structure out of what is read in. THE OVERALL GOAL IS FOR THE FILE TO MATCH EXACTLY WHAT IS ON THE SCREEN OF THE LAST SESSION.

Implement Double Digit Tabs 

Implement Chords

Implement Title Screen

Implement File output

Implement editing system for lines

Implement editing system for tablines

Implement Tab cut off after 150 chars

Fix bugs that occur when you enter non digits

Take care of Memory Leaks

Implement File input

Implement error checking for incorrect strings

*/


//Each line will be 150 spaces long bookended with |




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
    if(string[i] == 'X'){
      EString.insertEnd();
      eString.insertEnd();
      aString.insertEnd();
      dString.insertEnd();
      gString.insertEnd();
      bString.insertEnd();
      full = true;
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
  else{
    //Find the first ptr where isFull = false;
    //If you reach null then create a new listLine node at the end
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

  addstr( "lightningTab> " );
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
