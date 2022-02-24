#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
#define int long long int

#ifndef ONLINE_JUDGE
  #include "debug.h"
#else
  #define debug(x)
#endif


class Node {

public:

  char data;
  bool isTerminal;
  map <char, Node *> mp;

  Node(char d) {

    data = d;
    isTerminal = false;

  }

};


class Trie {


public:

  Node *root;
  Trie()  {

      root = new Node('\0');

  }

  void insert(string word) {


    Node *t = root;
    for(char ch:word) {


      if(t->mp.count(ch) == 0)  {

        Node *tmp = new Node(ch);
        t->mp[ch] = tmp;

      }

      t = t->mp[ch];
      
    }

    t->isTerminal = true;

  }



bool search(string word)  {


    Node *t = root;

    for(char ch:word) {

      if(t->mp.count(ch))
        t = t->mp[ch];
      else 
        return false;

    }

    return t->isTerminal;

  }

};


int32_t main()  {

    Trie t;
    
    vector <string> s = {"hello", "he", "apple", "apes", "news"};

    for(string word:s)
      t.insert(word);

    cout << t.search("hel"); 

    return 0;
}