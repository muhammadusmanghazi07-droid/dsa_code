#include <iostream>
using namespace std;

class arraylist
{
public:
    int size;
    int capacity;
    string *arr;

    bool isempty();
    bool isfull();
    bool invalid(int index);

    arraylist(int cap);
    ~arraylist();

    void add(string val);
    void insert(int position, string val);
    void remove(int position);

    int find(string val);
    string get(int position);
    void update(int position, string val);

    void clear();
    void resize(int newcapacity);
    void sort(bool flag);
    void reverse();

    void display();
};


int main()
{
    arraylist list(5);

    // ADD
    list.add("usman");
    list.add("talha");
    list.add("adnan");
    list.add("imran");
    list.add("baseer");

    list.display();

    // ADD MORE - resize will happen
    list.add("ali");
    list.add("ahmad");

    cout << endl;
    list.display();

    // INSERT
    list.insert(1, "ishaq");

    cout << endl;
    list.display();

    // REMOVE
    list.remove(0);

    cout << endl;
    list.display();

    // FIND
    cout << endl;
    cout << "Position of adnan: "
         << list.find("adnan") << endl;

    // GET
    cout << "Element at position 2: "
         << list.get(2) << endl;

    // UPDATE
    list.update(2, "updated");

    cout << endl;
    cout << "After update:" << endl;
    list.display();

    // SORT ASCENDING
    list.sort(false);

    cout << endl;
    cout << "Ascending order:" << endl;
    list.display();

    // SORT DESCENDING
    list.sort(true);

    cout << endl;
    cout << "Descending order:" << endl;
    list.display();

    // REVERSE
    list.reverse();

    cout << endl;
    cout << "After reverse:" << endl;
    list.display();

    // REMOVE FOR SHRINK
    list.remove(0);
    list.remove(0);
    list.remove(0);
    list.remove(0);

    cout << endl;
    cout << "After removing:" << endl;
    list.display();

    // CLEAR
    list.clear();

    cout << endl;
    cout << "After clear:" << endl;
    list.display();

    return 0;
}


// ================= FUNCTIONS =================


// ISEMPTY
bool arraylist::isempty()
{
    return (size == 0);
}


// ISFULL
bool arraylist::isfull()
{
    return (size == capacity);
}


// INVALID
bool arraylist::invalid(int index)
{
    return (index < 0 || index >= size);
}


// CONSTRUCTOR
arraylist::arraylist(int cap)
{
    size = 0;
    capacity = cap;

    arr = new string[capacity];
}


// RESIZE
void arraylist::resize(int newcapacity)
{
    string *newarr = new string[newcapacity];

    for(int i = 0; i < size; i++)
    {
        *(newarr + i) = *(arr + i);
    }

    delete[] arr;

    arr = newarr;

    capacity = newcapacity;
}


// ADD
void arraylist::add(string val)
{
    if(isfull())
    {
        resize(capacity + 10);
    }

    *(arr + size) = val;

    size++;
}


// INSERT
void arraylist::insert(int position, string val)
{
    if(position < 0 || position > size)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if(isfull())
    {
        resize(capacity + 10);
    }

    for(int i = size; i > position; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }

    *(arr + position) = val;

    size++;
}


// REMOVE
void arraylist::remove(int position)
{
    if(invalid(position))
    {
        cout << "Invalid position" << endl;
        return;
    }

    for(int i = position; i < size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }

    size--;

    if(size < capacity / 2)
    {
        resize(size);
    }
}


// FIND
int arraylist::find(string val)
{
    for(int i = 0; i < size; i++)
    {
        if(*(arr + i) == val)
        {
            return i;
        }
    }

    return -1;
}


// GET
string arraylist::get(int position)
{
    if(invalid(position))
    {
        cout << "Invalid position" << endl;
        return "";
    }

    return *(arr + position);
}


// UPDATE
void arraylist::update(int position, string val)
{
    if(invalid(position))
    {
        cout << "Invalid position" << endl;
        return;
    }

    *(arr + position) = val;
}


// CLEAR
void arraylist::clear()
{
    size = 0;
}


// SORT
// flag = false -> ascending
// flag = true  -> descending

void arraylist::sort(bool flag)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            // ASCENDING
            if(flag == false)
            {
                if(*(arr + i) > *(arr + j))
                {
                    string temp = *(arr + i);

                    *(arr + i) = *(arr + j);

                    *(arr + j) = temp;
                }
            }

            // DESCENDING
            else
            {
                if(*(arr + i) < *(arr + j))
                {
                    string temp = *(arr + i);

                    *(arr + i) = *(arr + j);

                    *(arr + j) = temp;
                }
            }
        }
    }
}


// REVERSE
void arraylist::reverse()
{
    for(int i = 0, j = size - 1; i < j; i++, j--)
    {
        string temp = *(arr + i);

        *(arr + i) = *(arr + j);

        *(arr + j) = temp;
    }
}


// DISPLAY
void arraylist::display()
{
    if(isempty())
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "List: ";

    for(int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }

    cout << endl;

    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity << endl;
}


// DESTRUCTOR
arraylist::~arraylist()
{
    delete[] arr;
}