//ID : 22k-4080

#include <iostream>
using namespace std;

class Bookstore {
    private:
        string title; 
        string author; 
    public:
        Bookstore(string t, string a) {
            title = t;
            author = a;
        }

        Bookstore(const Bookstore &bst) {
            title = bst.title;
            author = bst.author;
        }

        ~Bookstore() {
            cout << "Bookstore object destroyed" << endl;
        }

        // A method to display the book details
        void display() {
            cout << "Title of Book: " << title << endl;
            cout << "Author Name: " << author << endl;
        }
};

int main() {
    Bookstore b1("Shoe Dog", "Phil Knight");
    b1.display();
    
    cout<<"\nCopy Object: \n";
    Bookstore b2(b1);
    b2.display();
	cout<<endl;
	cout<<"\nAll program done now destruction: \n";
    return 0;
}

