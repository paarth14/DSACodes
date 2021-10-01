public class Student {
	
	//attributes or properties
	String name;
	int age;
	String address;
	
	//constructor
	//constructor is needed to create a new student object each time we create the student class
	//special type of method to initialize any object
	//no return
	public Student(String name, int age, String address) {
		this.name =  name;
		this.age =  age;
		this.address =  address;
	}
	
//	setters, can give any name but naming convention will name them as setters
//  this keyword means current objects
	public void setName(String name) {
		this.name = name;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	
	public void setAddress(String address) {
		this.address =  address;
	}
	
// getters, we can get using the getters
   public String getName() {
	   return name;
   }
   
   public int getAge() {
	   return age;
   }
   
   public String getAddress() {
	   return address;
   }
   
   @Override
   public String toString() {
	   return ("Student name is " + this.getName() + 
			   ", age is: " + this.getAge() + " and address is: " + this.getAddress());
   }
	
	public static void main(String[] args) {
		Student john =  new Student("John", 25, "23 East, California");
		
		System.out.println(john.getName());
		System.out.println(john.getAge());
		System.out.println(john.getAddress());
	}
}