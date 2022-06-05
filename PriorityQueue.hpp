#include <iostream>

using namespace std;

template <typename T>
class Queue
{

private:
  struct Item
  {
    T value;
    Item *next;
  };

  Item *first;
  Item *last;
  int _size;

  void copyItems(const Item *item, Item *(&first), Item *(&last), int &_size)
  {
    if (item == NULL)
    {
      first = NULL;
      last = NULL;
      _size = 0;
      return;
    }
    first = new Item();
    first->value = item->value;
    last = first;
    _size = 1;
    while (item->next != NULL)
    {
      last->next = new Item();
      last = last->next;
      item = item->next;
      last->value = item->value;
      _size++;
    }
    last->next = NULL;
  }

  void deleteItems(Item *item)
  {
    while (item != NULL)
    {
      Item *aux = item;
      item = item->next;
      delete aux;
    }
  }

public:
  Queue()
  {
    first = last = NULL;
    _size = 0;
  }

  Queue(Queue &q)
  {
    copyItems(q.first, first, last, _size);
  }

  ~Queue()
  {
    deleteItems(first);
    _size = 0;
  }

  Queue &operator=(const Queue &q)
  {
    if (this != &q)
    {
      deleteItems(first);
      copyItems(q.first, first, last, _size);
    }
    return *this;
  }

  T front()
  {
    if (first == NULL)
    {
      cerr << "Error: front on empty queue" << endl;
      exit(0);
    }
    return first->value;
  }

  void pop()
  {
    if (first == NULL)
    {
      cerr << "Error: pop on empty queue" << endl;
      exit(0);
    }
    Item *aux = first;
    first = first->next;
    delete aux;
    _size--;
    if (first == NULL)
      last = NULL;
  }
  //Pre: -
  //Post: la cua està ordenada de menor a major, hi el size aumenta en 1.
  void push(T value)
  {
    Item *i = new Item;
    i->value = value;
    Item *i2 = this->first;
    if (i2 == NULL) //si la cua està buida
    {
      i->next = NULL;
      this->first = i;
    }
    else if (value < i2->value) //si l'element a insertar és menor al primer
    {
      i->next = i2;
      this->first = i;
    }
    else //cas contrari
    {
      /* Inv: cada element i2 i-êsim es major a value */
      while (i2 != NULL)
      {
        if (i2->next == NULL)//si és el final de la cua
        {
          i->next = NULL;
          i2->next = i;
          break;
        }
        else if (value < i2->next->value)// si l'element a insertar és menor al següent
        {
          i->next = i2->next;
          i2->next = i;
          break;
        }
        i2 = i2->next;
      }
    }
    ++_size;
    // PROGRAM THIS METHOD
  }

  int size()
  {
    return _size;
  }

  template <typename U>
  friend ostream &operator<<(ostream &os, Queue<U> &q);

  template <typename U>
  friend istream &operator>>(istream &is, Queue<U> &q);
};

template <typename U>
ostream &operator<<(ostream &os, Queue<U> &q)
{
  os << "Mida -> " << q._size << endl;
  for (typename Queue<U>::Item *item = q.first; item != NULL; item = item->next)
    os << " " << item->value;
  return os;
}

template <typename U>
istream &operator>>(istream &is, Queue<U> &q)
{
  int size;
  is >> size;
  if (size == 0)
  {
    q = Queue<U>();
    return is;
  }
  for (int i = 0; i < size; ++i)
  {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}
