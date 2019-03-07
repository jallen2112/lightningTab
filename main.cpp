#include<vector>
#include <unistd.h>
#include<iostream>
#include<curses.h>
#include<cstring>
#include<string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

bool thisFile = false;
bool Dash = false;
bool addDash = false;
//Linked list structure allows for fully dynamic capability
//You can insert & delete between individual tabs as well as tablines, and also
//easily edit tabs and tablines

/* Goal Queue

RIGHT NOW: Everytime you load the from the file it's flipped.

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


class List{
  public:
    List();
    ~List();
    void insert(char c, int dd);
    void insertEnd(bool b);
    void insertLine(char string[100]);
    void print();
    void insertF(char c);
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
  if(!thisFile)
    this->insert('|', 1);
}

void List::insertLine(char string[100]){
  int i = 0;
  while(string[i]!='$'){
    insertF(string[i]);
    i++;
  }
  insertF('\n');
}

void List::insertF(char c){
  Node *ptr = m_head;
  if(m_head == NULL)
    m_head = new Node(c, NULL); 
  else{
    while(ptr->m_next != NULL){
      ptr = ptr->m_next;
    }
    ptr->m_next = new Node(c, NULL);
    /*
    if(dd == 1)
      ptr->m_next = new Node('-', lineBreaker);
    else
      ptr->m_next = new Node('\n', NULL);
      */
  }
}


void List::insert(char c, int dd){
  Node *testLine = new Node('-', NULL);

  Node *ptr =m_head;
  Node *lineSeperator;
  Node *lineBreaker= new Node('\n', NULL);
  if(dd == 1)
    lineSeperator=new Node('-', lineBreaker);
  else
    lineSeperator=lineBreaker;
  if(m_head==NULL){
    m_head = new Node(c, lineSeperator);
    /*
    if(thisFile)
      m_head = new Node(c, lineSeperator);
    else
      m_head = new Node('|', testLine);
      */
  }
  else{
    while(ptr->m_next != NULL && ptr->m_c != '\n'){
      ptr = ptr->m_next;
    }
    ptr->m_c = c;
    if(dd == 1 && !addDash)
      ptr->m_next = new Node('-', lineBreaker);
    else
      ptr->m_next = new Node('\n', NULL);
  }
}

void List::insertEnd(bool b)
{                       
  Node *endList = new Node('\n', NULL);
  Node *ptr =m_head;
  if(m_head==NULL){
    m_head = new Node('|', NULL);
  }
  else{
    while(ptr->m_c != '\n'){
      ptr = ptr->m_next;
    }
    ptr->m_c = '|';
    if(b == true)
      ptr->m_next = new Node('\n', endList);
    else
      ptr->m_next = new Node('\n', NULL);
  }
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
  myfile.close();
}


class listLine{
  public:
    listLine(){full = false;}
    void insert(char string[100]);
    void insertChord(char chord[22]);
    void print();
    bool isFull();
    void insertLine(char string[100], int gS);
  private:
    bool full;
    List EString;
    List bString;
    List gString;
    List dString;
    List aString;
    List eString;
};

void listLine::insertLine(char string[100], int gS){
//  std::cout << "ECHO: " << gS<< std::endl;
  std::cout << "Case: " << gS << std::endl;
//  std::cout << "String: " << string << std::endl;
  //sleep(2);
  switch(gS){
    case 1:
      EString.insertLine(string);
      break;
    case 2:
      bString.insertLine(string);
      break;
    case 3:
      gString.insertLine(string);
      break;
    case 4:
      dString.insertLine(string);
      break;
    case 5:
      aString.insertLine(string);
      break;
    case 6:
      eString.insertLine(string);
      break;
    case 7:
      /*
      char newline[100];
      for(int i=0;i<100;i++){
	if(i==0)
	  newline[i] = '\n';
	else
	  newline[i] = '$';
      }
      */
      eString.insertLine(string);
      full = true;
      break;
  }
}

bool listLine::isFull(){
  return full;
}

void listLine::insert(char string[100]){
  char which;
//  std::cout << "MYSTRING: " << string << std::endl;
  if (string[0] == '\0' && Dash == true)
  {
 //   std::cout << "EMPTY: " << string << std::endl;
      addDash = true;
      eString.insert('-', 1);
      aString.insert('-', 1);
      dString.insert('-', 1);
      gString.insert('-', 1);
      bString.insert('-', 1);
      EString.insert('-', 1);
      addDash = false;

    // your code here
  }

//  sleep(2);
  for(int i=0;i<100;i++){
    int dd = 1;
    if(string[i] == '$')
      break;
    if(string[i] == 'e' && isdigit(string[i+1])){
      if(isdigit(string[i+2]))
	dd = 2;
      eString.insert(string[i+1], dd);
      aString.insert('-', dd);
      dString.insert('-', dd);
      gString.insert('-', dd);
      bString.insert('-', dd);
      EString.insert('-', dd);
      if(dd == 2){
        eString.insert(string[i+2], 1);
        aString.insert('-', 1);
        dString.insert('-', 1);
        gString.insert('-', 1);
        bString.insert('-', 1);
        EString.insert('-', 1);
      }
    }
    if(string[i] == 'a' && isdigit(string[i+1])){
      if(isdigit(string[i+2]))
	dd = 2;
      aString.insert(string[i+1], dd);
      eString.insert('-', dd);
      dString.insert('-', dd);
      gString.insert('-', dd);
      bString.insert('-', dd);
      EString.insert('-', dd);
      if(dd == 2){
        aString.insert(string[i+2], 1);
        eString.insert('-', 1);
        dString.insert('-', 1);
        gString.insert('-', 1);
        bString.insert('-', 1);
        EString.insert('-', 1);
      }
    }
    if(string[i] == 'd' && isdigit(string[i+1])){
      if(isdigit(string[i+2]))
	dd = 2;
      dString.insert(string[i+1], dd);
      eString.insert('-', dd);
      aString.insert('-', dd);
      gString.insert('-', dd);
      bString.insert('-', dd);
      EString.insert('-', dd);
      if(dd == 2){
        dString.insert(string[i+2], 1);
        eString.insert('-', 1);
        aString.insert('-', 1);
        gString.insert('-', 1);
        bString.insert('-', 1);
        EString.insert('-', 1);
      }
    }
    if(string[i] == 'g' && isdigit(string[i+1])){
      if(isdigit(string[i+2]))
	dd = 2;
      gString.insert(string[i+1], dd);
      eString.insert('-', dd);
      aString.insert('-', dd);
      dString.insert('-', dd);
      bString.insert('-', dd);
      EString.insert('-', dd);
      if(dd == 2){
        gString.insert(string[i+2], 1);
        eString.insert('-', 1);
        aString.insert('-', 1);
        dString.insert('-', 1);
        bString.insert('-', 1);
        EString.insert('-', 1);
      }
    }
    if(string[i] == 'b' && isdigit(string[i+1])){
      if(isdigit(string[i+2]))
	dd = 2;
      bString.insert(string[i+1], dd);
      eString.insert('-' , dd);
      aString.insert('-', dd);
      dString.insert('-', dd);
      gString.insert('-', dd);
      EString.insert('-', dd);
      if(dd == 2){
        bString.insert(string[i+2], 1);
        eString.insert('-', 1);
        aString.insert('-', 1);
        dString.insert('-', 1);
        gString.insert('-', 1);
        EString.insert('-', 1);
      }
    }
    if(string[i] == 'E' && isdigit(string[i+1])){
      if(isdigit(string[i+2]))
	dd = 2;
      EString.insert(string[i+1], dd);
      eString.insert('-', dd);
      aString.insert('-', dd);
      dString.insert('-', dd);
      gString.insert('-', dd);
      bString.insert('-', dd);
      if(dd == 2){
        EString.insert(string[i+2], 1);
        eString.insert('-', 1);
        aString.insert('-', 1);
        dString.insert('-', 1);
        gString.insert('-', 1);
        bString.insert('-', 1);
      }
    }
    if(string[i] == 'X'){
      EString.insertEnd(false);
      eString.insertEnd(true);
      aString.insertEnd(false);
      dString.insertEnd(false);
      gString.insertEnd(false);
      bString.insertEnd(false);
      full = true;
    }
    if(string[i] == 'c' && string[i+1] == 'h'){
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

  int doubleDigit = 0;
  for(int i=0;i<22;i++){
    int dd = 1;
    if(chord[i] == '$')
      break;
    if(chord[i] == 'e' && isdigit(chord[i+1]) && e == 0){
      if(isdigit(chord[i+2]))
	dd = 2;
      eString.insert(chord[i+1], dd);
      if(dd == 2)
	eString.insert(chord[i+2], dd);
      e = 1;
    }
    if(chord[i] == 'a' && isdigit(chord[i+1]) && a == 0){
      if(isdigit(chord[i+2]))
	dd = 2;
      aString.insert(chord[i+1], dd);
      if(dd == 2)
	aString.insert(chord[i+2], dd);
      a = 1;
    }
    if(chord[i] == 'd' && isdigit(chord[i+1]) && d == 0){
      if(isdigit(chord[i+2]))
	dd = 2;
      dString.insert(chord[i+1], dd);
      if(dd == 2)
	dString.insert(chord[i+2], dd);
      d = 1;
    }
    if(chord[i] == 'g' && isdigit(chord[i+1]) && g == 0){
      if(isdigit(chord[i+2]))
	dd = 2;
      gString.insert(chord[i+1], dd);
      if(dd == 2)
	gString.insert(chord[i+2], dd);
      g = 1;
    }
    if(chord[i] == 'b' && isdigit(chord[i+1]) && b == 0){
      if(isdigit(chord[i+2]))
	dd = 2;
      bString.insert(chord[i+1], dd);
      if(dd == 2)
	bString.insert(chord[i+2], dd);
      b = 1;
    }
    if(chord[i] == 'E' && isdigit(chord[i+1]) && E == 0){
      if(isdigit(chord[i+2]))
	dd = 2;
      EString.insert(chord[i+1], dd);
      if(dd == 2)
	EString.insert(chord[i+2], dd);
      E = 1;
    }
    if(dd == 2)
      doubleDigit = 1;
  }
  if(e == 0)
    eString.insert('-', 1);
  if(a == 0)
    aString.insert('-', 1);
  if(d == 0)
    dString.insert('-', 1);
  if(g == 0)
    gString.insert('-', 1);
  if(b == 0)
    bString.insert('-', 1);
  if(E == 0)
    EString.insert('-', 1);
  if(doubleDigit){
    eString.insert('-', 1);
    aString.insert('-', 1);
    dString.insert('-', 1);
    gString.insert('-', 1);
    bString.insert('-', 1);
    EString.insert('-', 1);
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
    megaList(){m_head = NULL;cS=1;}
    void insert(char string[100], bool file);
    void print();
    void fileInsert();
    void fileInsertLL(char c);
    int curString(); 
    void incCurString();
  private:
    class listLineNode{
      public:
	listLineNode(listLine *lLine, listLineNode *next)
	{m_lLine = lLine; m_next = next;}
	listLine *m_lLine;
	listLineNode *m_next;
	
    };
    listLineNode *m_head;
    int cS;
};

int megaList::curString(){
  return cS; 
}

void megaList::incCurString(){
  cS++;
  if(cS > 7)
    cS = 1;
}

/**
 * Determines which list line node to insert into
 * Note: It is likely a call to insert is made twice, but
 * It's inserted into different list nodes, so this is not a problem. 
 */

void megaList::insert(char string[100], bool file){
  listLine *ll = new listLine();
  if(file){
    //Call a listline function. Give as parameter the string that it's supposed to insert into (from megaList variable), and the string 
    //it will insert on that line
//    std::cout << "lol" << std::endl;
    ll->insertLine(string, curString());
    std::cout << "LMFAO: " << std::endl;
  }
  else
    ll->insert(string);
  if(m_head == NULL)
    m_head = new listLineNode(ll, NULL);
  else{
    listLineNode *ptr = m_head;
    while(ptr->m_next != NULL && ptr->m_lLine->isFull() == true){
      ptr = ptr->m_next;
    }
    if(ptr->m_lLine->isFull() == false){
      if(file){
	ptr->m_lLine->insertLine(string, curString());
      }
      else 
        ptr->m_lLine->insert(string);
    }
    else{
      ptr->m_next  = new listLineNode(ll, NULL);
    }
  }
  if(thisFile)
    incCurString();
}

void megaList::print(){
  //Need to edit this to only print the last 7 tblines, maybe doubly linked list?
  //If you use DLL Then start from tail and go up 7, then print until tail.
  std::ofstream myfile;
  myfile.open ("output.txt", std::ios_base::app);
  listLineNode* ptr = m_head;
  while(ptr!=NULL){
    ptr->m_lLine->print();
    ptr = ptr->m_next;
  }
  myfile.close();
}

void megaList::fileInsert(){
  remove( "test.txt" );
  std::string line;
  std::ifstream myfile ("output.txt");
  std::ofstream ofile;
  ofile.open ("test.txt", std::ios_base::app);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        thisFile = true;
//        std::cout << "WTF" << std::endl;
	std::cout << "STRING: " << line << std::endl;
	//sleep(1);
//      for(int i=0; i<line.size();i++){
	char string[100];
	int i;
	for(i=0; i < line.size();i++){
	  string[i] = line[i];
	}
	for(;i<100;i++){
	  string[i] = '$';
	}
	insert(string, true); 
	//ofile << string;
	//Create a custom inuput for file reading.
//        ofile << line[i];
      //}
//      ofile << '\n';
      //add extra newline every 6 lines
      //JUST PASS IN THE STRING?
    }
    myfile.close();
    thisFile = false;
  }

  ofile.close();

}

void megaList::fileInsertLL(char c){
  //Find the first open LL. Modify the insert function that you have to return the next free listline.
  //Then you can call different versions of insert on that listline object.
  //
  //When reading from a file, to insert you will need to insert on a rotation between strings since
  //each line passed in will be a full line of tabs with one string. In the megalist class make a variable that will
  //let you know which string you are on and write a function to cycle this variable around.
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
  meg.fileInsert();
  while(true){
  clear();
  refresh();
  meg.insert(test, false);
  remove( "output.txt" );
  meg.print();
  
  refresh();
  addstr( "lightningTab> " );
  for(int i=0;i<100;i++){
    test[i] = '$';
  }
  getnstr(test, sizeof( test ) -1);
  Dash = true;
  }
  endwin();
  return 0;
}  
