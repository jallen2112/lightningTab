#ifndef LIST_H
#define LIST_H

#include<vector>
#include<unistd.h>
#include<iostream>
#include<curses.h>
#include<cstring>
#include<string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

extern bool thisFile;
extern bool Dash;
extern bool addDash;
extern char vi;


class List{
  public:
    List();
    ~List();
    void insert(char c, int dd);
    void insertEnd(bool b);
    void insertLine(char string[100]);
    void print(bool inV);
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

class listLine{
  public:
    listLine(){full = false;inView = false;}
    void insert(char string[100]);
    void insertChord(char chord[22]);
    void print();
    bool isFull();
    void insertLine(char string[100], int gS);
    void addToView();
    void removeFromView();
  private:
    bool full;
    bool inView;
    List EString;
    List bString;
    List gString;
    List dString;
    List aString;
    List eString;
};

class megaList{
  public:
    megaList(){m_head=NULL;m_tail=NULL;cS=1;numInView=0;view_head=NULL;view_tail=NULL;}
    ~megaList();
    void insert(char string[100], bool file);
    void print();
    void fileInsert();
    int curString();
    void incCurString();
    void shiftDown();
    void shiftUp();
    void viewCount();
  private:
    class listLineNode{
      public:
        listLineNode(listLine *lLine, listLineNode *next)
        {m_lLine = lLine; m_next = next;}
        listLine *m_lLine;
        listLineNode *m_next;
	listLineNode *m_prev;

    };
    listLineNode *m_head;
    listLineNode *m_tail;
    listLineNode *view_head;
    listLineNode *view_tail;
    int cS;
    int numInView;
};

#endif
