#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[small])
                small = j;
        }
        T temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

template <class T>
int linearSearch(T arr[], int size, T key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

class LibraryItem
{
public:
    virtual void display() = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
private:
    string title;
    string author;
    int pages;

public:
    Book(string t = "", string a = "", int p = 0)
    {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle()
    {
        return title;
    }

    int getPages()
    {
        return pages;
    }

    void display()
    {
        cout << "Book: " << title << ", Author: " << author
             << ", Pages: " << pages << endl;
    }
};

class Newspaper : public LibraryItem
{
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n = "", string d = "", string e = "")
    {
        name = n;
        date = d;
        edition = e;
    }

    string getName()
    {
        return name;
    }

    string getEdition()
    {
        return edition;
    }

    void display()
    {
        cout << "Newspaper: " << name << ", Date: " << date
             << ", Edition: " << edition << endl;
    }
};

class Library
{
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:
    void addBook(Book book)
    {
        books.push_back(book);
    }

    void addNewspaper(Newspaper newspaper)
    {
        newspapers.push_back(newspaper);
    }

    void displayCollection()
    {
        for (int i = 0; i < (int)books.size(); i++)
            books[i].display();

        for (int i = 0; i < (int)newspapers.size(); i++)
            newspapers[i].display();
    }

    void sortBooksByPages()
    {
        for (int i = 0; i < (int)books.size() - 1; i++)
        {
            int small = i;
            for (int j = i + 1; j < (int)books.size(); j++)
            {
                if (books[j].getPages() < books[small].getPages())
                    small = j;
            }
            Book temp = books[i];
            books[i] = books[small];
            books[small] = temp;
        }
    }

    void sortNewspapersByEdition()
    {
        for (int i = 0; i < (int)newspapers.size() - 1; i++)
        {
            int small = i;
            for (int j = i + 1; j < (int)newspapers.size(); j++)
            {
                if (newspapers[j].getEdition() < newspapers[small].getEdition())
                    small = j;
            }
            Newspaper temp = newspapers[i];
            newspapers[i] = newspapers[small];
            newspapers[small] = temp;
        }
    }

    Book* searchBookByTitle(string title)
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getTitle() == title)
                return &books[i];
        }
        return NULL;
    }

    Newspaper* searchNewspaperByName(string name)
    {
        for (int i = 0; i < (int)newspapers.size(); i++)
        {
            if (newspapers[i].getName() == name)
                return &newspapers[i];
        }
        return NULL;
    }
};

int main()
{
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook != NULL)
    {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else
        cout << "\nBook not found.\n";

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper != NULL)
    {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else
        cout << "\nNewspaper not found.\n";

    return 0;
}
