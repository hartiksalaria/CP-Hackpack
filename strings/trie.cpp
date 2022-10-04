#include "bits/stdc++.h"
using namespace std;
#define int long long int

#ifdef LOCAL
#include "debug.h"
#else
#define debug(x)
#endif

class Node {
   public:
    char data;
    bool isTerminal;
    vector<Node *> child;

    Node(char d) {
        data = d;
        isTerminal = false;
        child.assign(26, NULL);
    }
};

class Trie {
   public:
    Node *root;

    Trie() {
        root = new Node('\0');
    }

    void insert(string &word) {
        Node *t = root;
        for (char &ch : word) {
            if (!t->child[ch - 'a']) {
                Node *tmp = new Node(ch);
                t->child[ch - 'a'] = tmp;
            }
            t = t->child[ch - 'a'];
        }

        t->isTerminal = true;
    }

    bool search(string &word) {
        Node *t = root;
        for (char &ch : word) {
            if (t->child[ch - 'a'])
                t = t->child[ch - 'a'];
            else
                return false;
        }
        return t->isTerminal;
    }
};

int32_t main() {
    Trie t;

    vector<string> s = {"hello", "he", "apple", "apes", "news"};

    for (string word : s)
        t.insert(word);

    string tmp = "hel";

    cout << t.search(tmp);

    return 0;
}