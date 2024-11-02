#include <iostream>
#include "TempClass_Array.h"  

int main() {
    Array<int> myArray(5, 5) ;
    cout << "Initial array: ";
    myArray.print();

    cout << "Current size: " << myArray.GetSize() << endl;

    myArray.SetSize(7, 2);
    cout << "Array after resizing to 7 (growth step 2): ";
    myArray.print();

    cout << "Upper bound: " << myArray.GetUpperBound() << endl;

    cout << "Is Empty: " << boolalpha << myArray.IsEmpty() << endl;

    myArray.Add(10);
    myArray.Add(20);
    cout << "Array after adding elements 10 and 20: ";
    myArray.print();

    myArray.InsertAt(3, 99);
    cout << "Elements after insertion at index 3: ";
    myArray.print();

    myArray.RemoveAt(2);
    cout << "Elements after removal at index 2: ";
    myArray.print();

    myArray.SetAt(4, 50);
    cout << "Elements after setting value 50 at index 4: ";
    myArray.print();

    cout << "Element at index 4: " << myArray.GetAt(4) << endl;

    myArray.Add(60);
    cout << "Array after adding element 60: ";
    myArray.print();

    myArray.RemoveAll();
    cout << "Size after removing all elements: " << myArray.GetSize() << endl;
    cout << "Array after removing all elements: ";
    myArray.print();

    Array<int> anotherArray(3, 2);
    anotherArray.Add(5);
    anotherArray.Add(15);
    anotherArray.Add(25);
    cout << "Another array: ";
    anotherArray.print();

    myArray.Append(anotherArray);
    cout << "myArray after appending anotherArray: ";
    myArray.print();

    Array<int> thirdArray = myArray;
    cout << "thirdArray after assignment from myArray: ";
    thirdArray.print();

    cout << "Address of data in thirdArray: " << thirdArray.GetData() << endl;

    
}
