#include<iostream>
#include<string>
#include<vector>
#include <curses.h>
#include<stdlib.h>
using namespace std;

void resetStrings(string* e, string* a, string* d, string* b, string* g, string* E);

int main(){

bool run = true;
char users_name[ 100 ];
vector<string> evec;
vector<string> avec;
vector<string> dvec;
vector<string> gvec;
vector<string> bvec;
vector<string> Evec;
string tab; 
string estring = "| - ";
string astring = "| - ";
string dstring = "| - ";
string gstring = "| - ";
string bstring = "| - ";
string Estring = "| - ";
//initscr();
//(void)echo();
  while(run){
  cin >> tab;
 // printw( "Greetings and salutations %s!\n", users_name );
 // printw( "Greetings and salutations %s!\n", users_name );
 // getnstr( users_name, sizeof( users_name ) - 1 );
 // clear();
  if(tab[0] == 'e'){
    estring = " " + to_string(stoi(to_string(tab[1])) - 48) + " ";
  }
  if(tab[0] == 'a'){
    astring = " " + to_string(stoi(to_string(tab[1])) - 48) + " ";
  }
  if(tab[0] == 'd'){
    dstring = " " + to_string(stoi(to_string(tab[1])) - 48) + " ";
  }
  if(tab[0] == 'g'){
    gstring = " " + to_string(stoi(to_string(tab[1])) - 48) + " ";
  }
  if(tab[0] == 'b'){
    bstring = " " + to_string(stoi(to_string(tab[1])) - 48) + " ";
  }
  if(tab[0] == 'E'){
    Estring = " " + to_string(stoi(to_string(tab[1])) - 48) + " ";
  }
  evec.push_back(estring);
  avec.push_back(astring);
  dvec.push_back(dstring);
  gvec.push_back(gstring);
  bvec.push_back(bstring);
  Evec.push_back(Estring);
  for(int i =0; i<Evec.size();i++){
    cout << Evec[i] ;
  }
  cout << endl;
  for(int i =0; i<bvec.size();i++){
    cout << bvec[i] ;
  }
  cout << endl;
  for(int i =0; i<gvec.size();i++){
    cout << gvec[i] ;
  }
  cout << endl;
  for(int i =0; i<dvec.size();i++){
    cout << dvec[i] ;
  }
  cout << endl;
  for(int i =0; i<avec.size();i++){
    cout << avec[i] ;
  }
  cout << endl;
  for(int i =0; i<evec.size();i++){
    cout << evec[i];
  }
  cout << endl;
  
  /*
  cout << Estring  << endl;
  cout << bstring << endl;
  cout << gstring << endl;
  cout << dstring  << endl;
  cout << astring  << endl;
  cout << estring  << endl;
  */

  if(tab == "exit")
    run = false;
  resetStrings(&estring, &astring, &dstring, &gstring, &bstring, &Estring);
  }
  return 0;	
}

void resetStrings(string* e, string* a, string* d, string* b, string* g, string* E){
  *e = " - ";
  *a = " - ";
  *d = " - ";
  *b = " - ";
  *g = " - ";
  *E = " - ";
}
