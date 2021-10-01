#include<iostream>
#include<string>

using namespace std;

class Person{
	private:
		string name;
		int age;
		string gender;
		
	public:
		Person(){
			name="";
			age=30;
			gender="NA";
		}	
		
		~Person(){
			
		}
		
		Person(string name,int age,string gender){
			this->name=name;
			this->age=age;
			this->gender=gender;
		}
		
		
		void getData(string name,int age,string gender){
			this->name=name;
			this->age=age;
			this->gender=gender;
		}
		
		void displayData(){
			cout<<this->name<<endl;
			cout<<this->age<<endl;
			cout<<this->gender<<endl;
		}
		
		inline string getName(){
			return this->name;
		}
		
		inline int getAge(){
			return this->age;
		}
		
		inline string getGender(){
			return this->gender;
		}
};


class Student : public Person{
	private:
		string dept;
		int year;
		
	public:
		Student(){
			dept="cst";
			year=2;
		}	
		
		~Student(){
			
		}
		
		Student(string name,int age,string gender,string dept,int year) : Person{name,age,gender} {
			this->dept=dept;
			this->year=year;
			//getData(name,age,gender);
		}
		
		Student(Student &old) : Person{old.getName(),old.getAge(),old.getGender()}{
			this->dept=old.dept;
			this->year=old.year;
			//this->getData(old.getName(),old.getAge(),old.getGender());
		}
		
		void displayData(){
			Person :: displayData();
			cout<<"Department:"<<this->dept<<endl;
			cout<<"Year of study:"<<this->year<<endl;
		}
};


class Professor : public Person{
	private:
		string dept;
		int courseLoad;
		int salary;
		
	public:
		Professor(){
			dept="cst";
			courseLoad=5;
			salary=100000;
		}	
		
		~Professor(){
			
		}
		
		Professor(string name,int age,string gender,string dept,int courseLoad,int salary) : Person{name,age,gender} {
			this->dept=dept;
			this->courseLoad=courseLoad;
			this->salary=salary;
			//getData(name,age,gender);
		}
		
		Professor(Professor &old) : Person{old.getName(),old.getAge(),old.getGender()}{
			this->dept=old.dept;
			this->courseLoad=old.courseLoad;
			this->salary=salary;
			//this->getData(old.getName(),old.getAge(),old.getGender());
		}
		
		void displayData(){
			Person :: displayData();
			cout<<"Department:"<<this->dept<<endl;
			cout<<"Course Load:"<<this->courseLoad<<endl;
			cout<<"Salary:"<<this->salary<<endl;
		}
};


class Clerk : public Person{
	private:
		int workLoad;
		int salary;
		
	public:
		Clerk(){
			workLoad=8;
			salary=100000;
		}	
		
		~Clerk(){
			
		}
		
		Clerk (string name,int age,string gender,int workLoad,int salary) : Person{name,age,gender} {
			this->workLoad=workLoad;
			this->salary=salary;
			//getData(name,age,gender);
		}
		
		Clerk(Clerk &old) : Person{old.getName(),old.getAge(),old.getGender()}{
			this->workLoad=old.workLoad;
			this->salary=salary;
			//this->getData(old.getName(),old.getAge(),old.getGender());
		}
		
		void displayData(){
			Person :: displayData();
			cout<<"Course Load:"<<this->workLoad<<endl;
			cout<<"Salary:"<<this->salary<<endl;
		}
};


int main(){
	Student ob1("Ahel",20,"Male","CST",2);
	ob1.displayData();
	cout<<"\n";
	Student &ob2(ob1);
	ob2.displayData();	
	cout<<"\n";
	Professor ob3("MH",50,"Male","CST",5,120000);
	ob3.displayData();
	Clerk ob4("Ahel",20,"Male",2,20000);
	ob4.displayData();
}
