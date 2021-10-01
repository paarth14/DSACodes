#include <iostream.h>
#include <conio.h>
class person
{
    char name[100],gender[10];
    int age;
    public:
	void getdata()
	{
	    cout<<"Name: ";
	    cin>>name;
	    cout<<"Age: ";
	    cin>>age;
	    cout<<"Gender: ";
	    cin>>gender;
	}
	void display()
	{
	    cout<<"Name: "<<name<<endl;
	    cout<<"Age: "<<age<<endl;
	    cout<<"Gender: "<<gender<<endl;
	}
};
class student: public person
{
    char institute[100], level[20];
    public:
	void getdata()
	{
	    person::getdata();
	    cout<<"Name of College/School: ";
	    cin>>institute;
	    cout<<"Year: ";
	    cin>>level;
	}
	void display()
	{
	    person::display();
	    cout<<"Name of College/School: "<<institute<<endl;
	    cout<<"Year: "<<level<<endl;
	}
};
class employee: public person
{
    char company[100];
    float salary;
    public:
	void getdata()
	{
	    person::getdata();
	    cout<<"Name of Company: ";
	    cin>>company;
	    cout<<"Salary: Rs.";
	    cin>>salary;
	}
	void display()
	{
	    person::display();
	    cout<<"Name of Company: "<<company<<endl;
	    cout<<"Salary: Rs."<<salary<<endl;
	}
};
int main()
{
    clrscr();
    student s;
    employee e;
    cout<<"Student"<<endl;
    cout<<"Enter data"<<endl;
    s.getdata();
    cout<<endl<<"Displaying data"<<endl;
    s.display();
    cout<<endl<<"Employee"<<endl;
    cout<<"Enter data"<<endl;
    e.getdata();
    cout<<endl<<"Displaying data"<<endl;
    e.display();
    getch();
    return 0;
}
