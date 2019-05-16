#include "list.h"

bool thisFile = false;
bool Dash = false;
bool addDash = false;


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
  }
}


void List::insert(char c, int dd){
//  Node *testLine = new Node('-', NULL);

  Node *ptr =m_head;
  Node *lineSeperator;
  Node *lineBreaker= new Node('\n', NULL);
  if(dd == 1)
    lineSeperator=new Node('-', lineBreaker);
  else
    lineSeperator=lineBreaker;
  if(m_head==NULL){
    m_head = new Node(c, lineSeperator);
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

void List::print(bool inV)
{
  std::ofstream myfile;
  myfile.open ("output.txt", std::ios_base::app);
  Node *ptr = m_head;
  while(ptr!=NULL)
  {
    if(inV)
      printw( "%s", &(ptr->m_c) );
    std::string str(&(ptr->m_c));
    myfile << str;
    ptr =ptr->m_next;
  }
  myfile.close();
}

void listLine::insertLine(char string[100], int gS){
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
  if(string[0] == 'v')
    vi = 'c';
  if (string[0] == '\0' && Dash == true)
  {
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
  if(inView){
    EString.print(1);
    bString.print(1);
    gString.print(1);
    dString.print(1);
    aString.print(1);
    eString.print(1);
  }
  else{
    EString.print(0);
    bString.print(0);
    gString.print(0);
    dString.print(0);
    aString.print(0);
    eString.print(0);
  }
}

void listLine::addToView(){
  inView = true;
}

void listLine::removeFromView(){
  inView = false;
}

megaList::~megaList() 
{
  listLineNode *ptr = m_head;
  while(ptr != NULL)
  {
    listLineNode *temp;
    temp = ptr;
    ptr = ptr->m_next;
    delete temp;
  }
}

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
    //This is the difference between reading from a file and inserting from the program
    ll->insertLine(string, curString());
  }
  else
    ll->insert(string);
  if(m_head == NULL && m_tail == NULL){
    ll->addToView();
    viewCount();
    m_head = new listLineNode(ll, NULL);
    view_head = m_head;
    m_head->m_next = NULL;
    m_head->m_prev = NULL;
    m_tail = m_head;
  }
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
      if(numInView < 7){
        ll->addToView();
        viewCount();
	view_tail = ptr->m_next;
      }
      m_tail = ptr->m_next;
      m_tail->m_prev = ptr;
    }
  }
  if(thisFile)
    incCurString();
}

void megaList::print(){
  //Need to edit this to only print the last 7 tblines, maybe doubly linked list?
  //If you use DLL Then start from tail and go up 7, then print until tail.
//  std::ofstream myfile;
//  myfile.open ("output.txt", std::ios_base::app);
  listLineNode* ptr = m_head;
  while(ptr!=NULL){
    ptr->m_lLine->print();
    ptr = ptr->m_next;
  }
//  myfile.close();
}

void megaList::fileInsert(){
//  remove( "test.txt" );
  std::string line;
  std::ifstream myfile ("output.txt");
  std::ofstream ofile;
//  ofile.open ("test.txt", std::ios_base::app);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        thisFile = true;
	char string[100];
	int i;
	for(i=0; i < line.size();i++){
	  string[i] = line[i];
	}
	for(;i<100;i++){
	  string[i] = '$';
	}
	insert(string, true); 
    }
    myfile.close();
    thisFile = false;
  }

  ofile.close();

}

void megaList::viewCount(){
  numInView++;
}

void megaList::deleteSingle(){
  m_tail->m_lLine->deleteSingle();
}

void listLine::deleteSingle(){
  EString.deleteSingle();
  bString.deleteSingle();
  gString.deleteSingle();
  dString.deleteSingle();
  aString.deleteSingle();
  eString.deleteSingle();
}

void List::deleteSingle(){
  Node* ptr = m_head;
  Node* ptr2 = m_head;
  int count = 0;
  while(ptr->m_next!=NULL){
    ptr = ptr->m_next;
    if(count > 1)
      ptr2=ptr2->m_next;
    count++;
  }
  if(count > 2){
    ptr2->m_next = NULL;
    delete(ptr);
    insertF('\n');
  }
}

void megaList::shiftDown(){
  if(view_tail->m_next != NULL){
    view_tail = view_tail->m_next;
    view_tail->m_lLine->addToView();
    view_head->m_lLine->removeFromView();
    view_head = view_head->m_next;
  }
  //sleep(1);
}

void megaList::shiftUp(){
  if(view_head->m_prev!=NULL){
    view_head = view_head->m_prev;
    view_head->m_lLine->addToView();
    view_tail->m_lLine->removeFromView();
    view_tail = view_tail->m_prev;
  }
//  sleep(1);
}

void megaList::snapToBottom(){
  while(view_tail->m_next != NULL){
    shiftDown();
  }
}

void megaList::snapToTop(){
  while(view_head->m_prev != NULL){
    shiftUp();
  }
}
