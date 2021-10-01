import java.util.Scanner;
class Node
{
 int data;
 Node next;
 Node(int data)
 {
	this.data=data;
	this.next=null;
	}
	public int getdata()
	{
		return data;
	}
}
public class LinkedListFunctions 
{
	public static Node create(Node start)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Enter data :");
		int r=in.nextInt();
		
		start = new Node(r);
		return start;
	}
	public static void display(Node start)
	{
		Node n=start;
		if(n==null)
		{
			System.out.println("Linked List is Empty");
		}
		else
		{
			int i=0;
			System.out.println("Position Number\tdata");
			do
			{
				System.out.println(i++ + "\t\t"+n.getdata());
				n=n.next;
			}
			while(n!=null);
		}
	}
	//Insertion at the beginning
	public static Node InsBeg(Node start)
	{
		if(start==null)
		{
			start=create(start);
			return start;
		}
		else
		{
			Scanner in = new Scanner(System.in);
			System.out.print("Enter data :");
			int r=in.nextInt();
			Node n = new Node(r);
			n.next=start;
			return n;
		}
	}
	//insertion at the end
	public static Node InsLast(Node start)
	{
		if(start==null)
		{
			start=create(start);
			return start;
		}
		else
		{
			Scanner in = new Scanner(System.in);
			System.out.print("Enter data :");
			int r=in.nextInt();
			
			Node t= start;
			while(t.next!=null)
			{
				t=t.next;
			}
			Node n = new Node(r);
			t.next=n;
			return start;
		}
	}
	//deletion at the beginning
	public static Node DelBeg(Node start)
	{
			Node n=start;
			n=n.next;
			System.out.println("Deletion Successful");
			return n;
		}
	//deletion at the last
	public static Node DelEnd(Node start)
	{
		Node n=start;
		if(n.next==null)
		{
			System.out.println("Deletion Successful");
			return null;
		}
		else
		{
			while(n.next.next!=null)
			{
				n=n.next;
			}
			n.next=null;
			System.out.println("Deletion Successful");
			return start;
		}
	}
	public static Node InsAtAnyPosn(Node start)
	{
		Scanner in  = new Scanner(System.in);
		System.out.print("Enter the Postion number to insert Node at :");
		int p=in.nextInt();
		if(p==0)
		{
			return InsBeg(start);
		}
		else
		{
			Node n = start;
			for(int i=0; i<p-1; i++)
			{
			n=n.next;
			}
			System.out.print("data:");
			int r=in.nextInt();
			Node t = new Node(r);
			t.next=n.next;
			n.next=t;
			return start;
		}
	}
	public static int search(Node start)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the data to be searched: ");
		int se=in.nextInt();
		boolean k=false;
		Node n=start;
		int i=0;
		while(n!=null)
		{
			if(n.getdata()==se)
			{
				k=true;
				break;
			}
			else
			{
				i++;
				n=n.next;
			}
		}
		if(k)
		{
			System.out.println(n.getdata()+" is present");
		}
		else
		{
			System.out.println("Search Element not found");
		}
		return i;
	}
	public static Node DelAny(Node start)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the element to be deleted: ");
		int se=in.nextInt();
		int p= search(start);
		if(p==0)
		{
			return DelBeg(start);
		}
		else
		{
			Node n = start;
			for(int i=0; i<p-1; i++)
				n=n.next;
					
			
				Node t=n;
				t=t.next;
				n.next=t.next;
				System.out.println("Deletion Successful");
			
			return start;
		}
	}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Node start=null;
		Scanner sc = new Scanner(System.in);
		while(true)
		{	
			System.out.println("****MENU*****");
			System.out.println("0:Exit");
			System.out.println("1:Creation");
			System.out.println("2:Display");
			System.out.println("3:Insert in Begining");
			System.out.println("4:Insert at the end");
			System.out.println("5:Delete at the beg");
			System.out.println("6:Delete at the last");
			System.out.println("7:search element");
			System.out.println("8:Delete any key");
			System.out.println("9:Insert at any posn");
			System.out.println("Enter the choice");
			int choice=sc.nextInt();
			int no;
			switch(choice)
			{
				case 0:
					System.out.println("Exiting The Program");
					sc.close();
					System.exit(0);
				case 1:
					start=create(start);
					break;
				case 2:
					display(start);
					break;
				case 3:
					start=InsBeg(start);
					break;
				case 4:
					start=InsLast(start);
					break;
				case 5:
					start=DelBeg(start);
					break;
				case 6:
					start=DelEnd(start);
					break;
				case 7:
					no=search(start);
					break;
				case 8:
					start= DelAny(start);
					break;
				case 9:
					start= InsAtAnyPosn(start);
					break;
                    default:
						break;
			}
		}

	}

}

