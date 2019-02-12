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

/*
class List{
  public:
    List();
    ~List();
    bool insert(Video *video);
    void print();
  private:
    class Node{
      public:
      Node(char* m_arr[1], Node *next)
      {m_video = video; m_next = next;}
      char *m_arr[1];
      Node *m_next;
    };
    Node *m_head;
    int size=0;
}; 
*/


//GOAL: Create one line of tab with LL
/*
void printTitleScreen(){
   clear();
    std::vector <std::string> hello;
    hello = {"t", "h", "e"};
//    hello = {"#   #  #####  #      #       #####\n","#   #  #      #      #       #   #\n","#####  #####  #      #       #   #","#   #  #      #      #       #   #\n","#   #  #####  #####  #####   ####\n#" };

    for (std::vector <std::string>::const_iterator it = hello.begin(); it != hello.end(); it++)
    {
        std::string temp = *it;
        printw ( "%s \n", temp.c_str() );
    }
    refresh();
,---.'|                                                                                             ,/   .`|                    
|   | :                        ,---,       ___                                                    ,`   .'  :                    
:   : |     ,--,             ,--.' |     ,--.'|_                ,--,                            ;    ;     /           ,---,    
|   ' :   ,--.'|             |  |  :     |  | :,'       ,---, ,--.'|         ,---,            .'___,/    ,'          ,---.'|    
;   ; '   |  |,     ,----._,.:  :  :     :  : ' :   ,-+-. /  ||  |,      ,-+-. /  |  ,----._,.|    :     |           |   | :    
'   | |__ `--'_    /   /  ' /:  |  |,--.;__,'  /   ,--.'|'   |`--'_     ,--.'|'   | /   /  ' /;    |.';  ;  ,--.--.  :   : :    
|   | :.'|,' ,'|  |   :     ||  :  '   |  |   |   |   |  ,"' |,' ,'|   |   |  ,"' ||   :     |`----'  |  | /       \ :     |,-. 
'   :    ;'  | |  |   | .\  .|  |   /' :__,'| :   |   | /  | |'  | |   |   | /  | ||   | .\  .    '   :  ;.--.  .-. ||   : '  | 
|   |  ./ |  | :  .   ; ';  |'  :  | | | '  : |__ |   | |  | ||  | :   |   | |  | |.   ; ';  |    |   |  ' \__\/: . .|   |  / : 
;   : ;   '  : |__'   .   . ||  |  ' | : |  | '.'||   | |  |/ '  : |__ |   | |  |/ '   .   . |    '   :  | ," .--.; |'   : |: | 
|   ,/    |  | '.'|`---`-'| ||  :  :_:,' ;  :    ;|   | |--'  |  | '.'||   | |--'   `---`-'| |    ;   |.' /  /  ,.  ||   | '/ : 
'---'     ;  :    ;.'__/\_: ||  | ,'     |  ,   / |   |/      ;  :    ;|   |/       .'__/\_: |    '---'  ;  :   .'   \   :    | 
          |  ,   / |   :    :`--''        ---`-'  '---'       |  ,   / '---'        |   :    :           |  ,     .-./    \  /  
           ---`-'   \   \  /                                   ---`-'                \   \  /             `--`---'   `-'----'   
                     `--`-'                                                           `--`-'                                    
}
*/


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
  if(m_head==NULL){
    m_head = new Node(c, NULL);
    //printw("%s\n", &(m_head->m_c));
  }
  else{
    while(ptr->m_next != NULL){
      ptr = ptr->m_next;
    }
    ptr->m_next = new Node(c, NULL);
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
    printw( "%s ", &(ptr->m_c) );
    ptr =ptr->m_next;
  }
  printw( "\n");
  //delete ptr;
}

int main()
{
  initscr();
  (void)echo();
  char test[100];
  List listE;
  List liste;
  for(int i=0;i<100;i++){
    test[i] = '$';
  }

  addstr( "> " );
  getnstr(test, sizeof( test ) -1);
  while(true){
  clear();
  refresh();
  liste.insert(test[0]);
  liste.print();
  listE.insert(test[1]);
  listE.print();
  //printw( "%s\n", test);
  
  refresh();
  addstr( "test> " );
  getnstr(test, sizeof( test ) -1);
  }
  endwin();
  return 0;
}  
