#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
        this->publishingYear=publishingYear;
        
    }

    Book(const Book &book)
    {
        
        this->title = book.getTitle();
        this->authors = book.getAuthors();
        this->publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors)
    {
        
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        
        return this->title;
    }

    char* getAuthors() const
    {
        
        return this->authors;
    }

    int getPublishingYear() const
    {
        
        return publishingYear;
    }

    ~Book()
    {
        
        delete[] title;
        delete[] authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};


int main(){
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    book1.printBook();
    return 0;
}
class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         */
    }

    Book(const char *title, const char *authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
         
         this->publishingYear = publishingYear;
         
        this->title = new char[strlen(title)+1];
         strcpy(this->title, title);
         
        this->authors = new char[strlen(authors)+1];
         strcpy(this->authors, authors);
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        
         delete[] title;
         delete[] authors;
    }

    friend bool checkAuthor(Book book, const char* author)
    {
        /*
         * STUDENT ANSWER
         * TODO: returns true if the author is on the book's authors list, otherwise it returns false
         */ 
         int a =strlen(book.authors);
        for (int i=0; i<a;i++){
            if (book.authors[i+1]== ',' ||book.authors[i+1]== '\0' ) {
                int c=1;
                int j= i;
                int t= strlen(author)-1;
                while(j>=0 && t >=0 && book.authors[j-1]!=','){
                    if(book.authors[j] != author[t]){
                        c=0; 
                        break;
                    }
                    j--;
                    t--;
                }
                if(c == 1 && t < 0){
                    if  (j<0 || book.authors[j-1]==',' ) return true;
                }
            }
        }
         return false;
    }
};
/*#include <iostream>
#include <fstream>

int add(int a, int b) {
    return a + b;
}
int minus(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    return a / b;
}
void calculate(int a, int b, int opt)
{
    int (*myfunc)(int, int);
      
    // STUDENT ANSWER BEGIN
    if(opt == 0){
        myfunc=add;
    }
    else if(opt == 1){
        myfunc=minus;
    }
    else if(opt == 2){
        myfunc=multiply;
    }
    else {
        myfunc=divide;
    }

    // STUDENT ANSWER END

    int ans = (*myfunc)(a, b);
    printf("Output of calculation is %d.\n", ans);
}
int main() {
    calculate(1,2,0);
    return 0;
}
*/
/*#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    Book(const char *title, const char *authors, int publishingYear)
    {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
        this->publishingYear=publishingYear;
    }
    
    ~Book()
    {
        delete[] title;
        delete[] authors;
    }
    
    friend class Printer;
};

class Printer
{
public:
    static void printBook(const Book book)
    {
    cout << book.title << '\n';
    for (char* str = book.authors; *str; )
		if (*str == ',')
			for (cout << '\n', ++str; *str && isspace(*str); ++str);
		else
			cout << *str++;
    cout<<"\n";
	cout << book.publishingYear << '\n';
        
    }
};

int main(){
    Book book1("Giai tich 1", "Nguyen Dinh Huy, Nguyen Thi Xuan Anh", 2000);
    Printer::printBook(book1);
    return 0;
}*/

//#include <iostream>
//#include <math.h>
//using namespace std;

/*void ascendingSort(int a[], int n) {
    int temp;
    for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp  =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void descendingSort(int a[], int n) {
    int temp;
    for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				temp  =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void mySort(int a[], int n, void (*sort)(int[], int)) {
	if(sort == ascendingSort){
        sort = ascendingSort;
        sort(a,n);
    }
    else{
        sort = descendingSort;
        sort(a,n);
    }
}

int main() {
    int n = 5;
    int a[5] = { 1, 2, 3, 4, 5 };
    void (*sortAlgorithm)(int[], int) = descendingSort;
    mySort(a, n, sortAlgorithm);
    for (int i = 0; i < n; ++i) {
	printf("%d ", a[i]);
    }
    return 0;
}*/
/*enum Color
{
    red,
    green,
    blue
};
enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }

    virtual void printType() = 0;
    friend class ToyBox;
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price)
    {
        this->price = price;
        this->color = color;
    }

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price)
    {
        this->price = price;
        this->size = size;
    }

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy* toyBox[5];
    int numberOfItems;

public:
    ToyBox()
    {
        *toyBox = nullptr; 
        numberOfItems = 0;
    }
    
    int addItem(const CarToy& carToy)
    {
        if (numberOfItems>=5){
            return -1;
        }
        Toy* car = (Toy*)(&carToy);
        toyBox[numberOfItems] = car;
        numberOfItems++;
        return numberOfItems;
    }
    
    int addItem(const PuzzleToy& puzzleToy)
    {
        if (numberOfItems>=5){
            return -1;
        }
        Toy* puzzle = (Toy*)(&puzzleToy);
        toyBox[numberOfItems] = puzzle;
        numberOfItems++;
        return numberOfItems;
    }
    
    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }
};
int main(){
    CarToy car(20000,red);
    PuzzleToy puzzle(30000,small);

    ToyBox box;
    box.addItem(car);
    box.addItem(puzzle);
    box.printBox();
    return 0;
}*/