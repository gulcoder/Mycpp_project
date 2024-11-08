#include <iostream>
#include <vector>
using namespace std;

class Item {
    public:
    string title;
    string author;
    int year;
    bool is_borrowed;

    Item(string title, string author, int year)
        : title(title), author(author), year(year), is_borrowed(false) {}

    virtual void display_info()=0; 
};

class Book : public Item{
    public:
    int pages;

    Book(string title, string author, int year, int pages)
    : Item(title, author, year), pages(pages){}

    void display_info()override{
        cout<<"Book: " << title<<endl;
        cout<<"Author: " << author<<endl;
        cout<<"Year: " << year<< endl;
        cout<<"Pages: "<< pages<< endl;
    }
};

class Magazine : public Item{
    public:
    int issue;

    Magazine(string title, string author, int year, int issue)
    : Item(title, author, year), issue(issue){}

    void display_info()override{
        cout <<"Magazine: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Year: "<< year<<endl;
        cout<<"Issue: "<<issue<<endl;
    }
};

class LibraryUser{
    public:
    string name;
    vector<Item*> borrowed_items;

    LibraryUser(string name) : name(name){}

    void borrow(Item* item){
        borrowed_items.push_back(item);
        item-> is_borrowed = true;
        cout << name<< "borrowed: " <<item->title<<endl;
    }

    void return_item(Item* item){
        for(int i=0; i<borrowed_items.size(); ++i){
            if(borrowed_items[i]==item){
                borrowed_items.erase(borrowed_items.begin()+i);
                item-> is_borrowed = false;
                cout<<name<<"returned: "<< item->title<<endl;
            
            }
           
    cout<<"Item not found in the items"<<endl;
            
        }

    }

    void list_borrowed_items(){
        for(int i=0; i<borrowed_items.size(); ++i){
            borrowed_items[i]->display_info();
        }
    }
};

class Library{
    public:
    vector<Item*> items;
    vector <LibraryUser*> users; 

    void add_item(Item* item)
    {
        items.push_back(item);
    }

    void remove_item(Item*item){
        bool found = false;
        for (int i=0; i<items.size(); ++i){
            if(items[i] == item){
                items.erase(items.begin()+i);
                cout << item->title<< "removed"<<endl;
                found=true;
                break;
                
            }
           
    cout << "item not found"<<endl;
            
        }
    }

    void register_user(LibraryUser* user){
        users.push_back(user);
        cout << user->name<< endl;
    }
    void borrow_item(LibraryUser* user, Item*item){
        if(!item->is_borrowed){
            user->borrow(item);
        }
        else {
            cout << item->title<< "is already borrowed."<<endl;
        }
    }

    void return_item(LibraryUser* user, Item* item){
        user-> return_item(item);
    }

    void list_items(){
        cout <<"list items: "<<endl;
        for(int i=0; i<items.size(); ++i){
            items[i]->display_info();
        }
    }

    void list_available_items(){
        cout << "Available items: "<<endl;
        for(int i=0; i<items.size(); ++i){
            if(!items[i]->is_borrowed){
                items[i]->display_info();
            }
        }
    }


    void list_all_users(){
        for(int i=0; i<users.size(); ++i){
            cout << users[i]->name<<endl;
        }
    }
};

int main() {

    Library myLibrary;

    Book* book1 = new Book("C++ Programming", "Bjarne Stroustrup", 1985, 1000);
    Book* book2 = new Book("The C Programming Language", "Brian W. Kernighan", 1978, 300);
    Magazine* magazine1 = new Magazine("Tech Today", "John Doe", 2023, 5);
    Magazine* magazine2 = new Magazine("Science Weekly", "Jane Smith", 2023, 10);

    myLibrary.add_item(book1);
    myLibrary.add_item(book2);
    myLibrary.add_item(magazine1);
    myLibrary.add_item(magazine2);

    LibraryUser* user1 = new LibraryUser("Alice");
    LibraryUser* user2 = new LibraryUser("Bob");

    myLibrary.register_user(user1);
    myLibrary.register_user(user2);

    myLibrary.list_items();

    myLibrary.list_all_users();

    myLibrary.borrow_item(user1, book1); 
    myLibrary.borrow_item(user2, magazine1); 

    myLibrary.list_available_items();

    myLibrary.return_item(user1, book1); 
    myLibrary.return_item(user2, magazine1); 

    myLibrary.list_available_items();
   
    myLibrary.remove_item(book2); 

    myLibrary.list_items();

    delete book1;
    delete book2;
    delete magazine1;
    delete magazine2;
    delete user1;
    delete user2;

    return 0;
}