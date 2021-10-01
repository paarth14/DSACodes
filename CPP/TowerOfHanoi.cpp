#include<iostream>
using namespace std;
void towerOfHanoi(int n,char src,char help,char dest){
  // base case
	if(n==0)
		return;
	// recursive case
	towerOfHanoi(n-1,src,dest,help);
	cout<<"Moving ring "<<n<<" from " <<src<<" to "<<dest<<endl;
	towerOfHanoi(n-1,help,src,dest);
}
int main() {
	int n;
	cin>>n;
  // we need to move discs from A to B with the help of C
	towerOfHanoi(n,'A','C','B');
	return 0;
}
