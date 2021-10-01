#include<iostream>
using namespace std;
string replacePI(string str){
	if(str.length()<=1)
		return str;

	// recursive case
	if(str.substr(0,2)=="pi")
		return "3.14"+replacePI(str.substr(2));
	else
		return str[0] + replacePI(str.substr(1));
}
int main() {
	int testCases;
	cin>>testCases;
	while(testCases--)
	{
		string str;
		cin>>str;
		cout<<replacePI(str)<<endl;
	}
	return 0;
}
