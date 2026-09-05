#include <iostream>
using namespace std;

class arrlist
{
public:
    int size;
    int capacity;
    int *arr;

    // Constructor
    arrlist(int cap);

    // Function prototypes
    bool isempty();
    bool isfull();
    bool invalid(int index);
    void plus_one();
    void display();

    // Destructor
    ~arrlist();
};


// ==================== MAIN FUNCTION ====================

int main()
{
    int c;

    // User se capacity lena
    cout << "Enter the list capacity: ";
    cin >> c;

    cout << endl;

    // List object create karna
    arrlist list(c);

    // Number mein 1 add karna
    list.plus_one();

    // Result display karna
    list.display();

    return 0;
}


// ==================== CONSTRUCTOR ====================

arrlist::arrlist(int cap)
{
    // User se list ka size lena
    cout << "Enter the size of array: ";
    cin >> size;

    // Capacity ko store karna
    capacity = cap;

    // Dynamic array create karna
    arr = new int[capacity];

    // Check karna ke size capacity se zyada to nahi
    if (size > capacity)
    {
        cout << "Size is greater than capacity, invalid syntax"
             << endl;

        size = 0;
    }
    else
    {
        // User se digits input lena
        cout << "Enter the digits: ";

        for (int i = 0; i < size; i++)
        {
            cin >> *(arr + i);
        }
    }
}


// ==================== ISEMPTY ====================

bool arrlist::isempty()
{
    // Agar size 0 hai to list empty hai
    return (size == 0);
}


// ==================== ISFULL ====================

bool arrlist::isfull()
{
    // Agar size capacity ke equal hai
    // to list full hai
    return (size == capacity);
}


// ==================== INVALID ====================

bool arrlist::invalid(int index)
{
    // Check karna ke index valid hai ya nahi
    return (index < 0 || index >= size);
}


// ==================== PLUS ONE ====================

void arrlist::plus_one()
{
    // Last digit se first digit ki taraf jana
    for (int i = size - 1; i >= 0; i--)
    {
        // Agar digit 9 se chota hai
        if (*(arr + i) < 9)
        {
            // Sirf is digit mein 1 add karo
            *(arr + i) += 1;

            // Kaam complete
            return;
        }

        // Agar digit 9 hai to usko 0 karo
        *(arr + i) = 0;

        // Agar first digit par aa gaye
        if (arr + i == arr + 0)
        {
            // Extra digit ke liye capacity check karo
            if (size == capacity)
            {
                cout << "No space for extra digit." << endl;
                return;
            }

            // Saare elements ko right shift karo
            for (int j = size; j > 0; j--)
            {
                *(arr + j) = *(arr + j - 1);
            }

            // First position par 1 rakho
            *(arr + 0) = 1;

            // Size increase karo
            size++;

            // Kaam complete
            return;
        }
    }
}


// ==================== DISPLAY ====================

void arrlist::display()
{
    cout << "All values of list: ";

    // List ke saare elements display karna
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }

    cout << endl;
}


// ==================== DESTRUCTOR ====================

arrlist::~arrlist()
{
    // Dynamic memory ko free karna
    delete[] arr;

    cout << "Memory is deallocated." << endl;
}