class Trie
{
public:
  Trie *child[26];
  bool isEnd;

  Trie()
  {
    // implement Trie
    isEnd = false;
    for (int i = 0; i < 26; i++)
    {
      child[i] = nullptr;
    }
  }

  void insert(string &word)
  {
    Trie *curr = this;
    for (char ch : word)
    {
      int i = ch - 'a';
      if (curr->child[i] == nullptr)
      {
        curr->child[i] = new Trie();
      }
      curr = curr->child[i];
    }
    curr->isEnd = true;
  }

  bool search(string &word)
  {
    // search word in the Trie
    Trie *curr = this;
    for (char ch : word)
    {
      int i = ch - 'a';
      if (curr->child[i] == nullptr)
      {
        return false;
      }
      curr = curr->child[i];
    }
    return curr->isEnd;
  }

  bool isPrefix(string &word)
  {
    // search prefix word in the Trie
    Trie *curr = this;
    for (char ch : word)
    {
      int i = ch - 'a';
      if (curr->child[i] == nullptr)
      {
        return false;
      }
      curr = curr->child[i];
    }
    return true;
  }
};
