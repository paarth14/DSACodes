// Java program for Heapsort

public class Heapsort
{
	public void sort(int arr[])
	{
		int n = arr.length;

		// Build heap
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		// One by one extract elements from heap
		for (int i=n-1; i>=0; i--)
		{
			int temp = arr[0];// Move current root to end
			arr[0] = arr[i];
			arr[i] = temp;

			// call max heapify on the heap
			heapify(arr, i, 0);
		}
	}

	// To heapify a subtree rooted with node i which is an index in  array arr[]. 
  // n is size of heap
	void heapify(int arr[], int n, int i)
	{
		int largest = i; // Initialize largest as root
		int l = 2*i + 1; // left child
		int r = 2*i + 2; // right child

		// If left child is larger than root
		if (l < n && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than the largest so far
		if (r < n && arr[r] > arr[largest])
			largest = r;

		// If largest is not root
		if (largest != i)
		{
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;

			// Recursively heapify the affected subtree
			heapify(arr, n, largest);
		}
	}

	//Function to print sorted array
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}


	public static void main(String args[])
	{
		int arr[] = {22, 1, 33, 15, 6, 7};
		int n = arr.length;

		Heapsort object = new Heapsort();
		object.sort(arr);

		System.out.println("The sorted array is: ");
		printArray(arr);
	}
}
