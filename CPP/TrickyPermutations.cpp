#include<iostream>
#include<algorithm>
using namespace std;
string st[100000];
int counter = 0;
void printPermutations(string ques,string asf){
	if(ques.length () == 0)
        {
            st[counter++] = asf;
            return;
        }
	for(int i=0;i<ques.length();i++){
		char ch = ques[i];
		string qrleft = ques.substr(0,i);
		string qrright = ques.substr(i+1);
		string roq = qrleft + qrright;
		printPermutations(roq, asf + ch);
	}
}
int main() {
	string str;
	cin>>str;
    sort(str.begin(), str.end());
	printPermutations(str,"");
	sort(st,st+counter);
    string temp="";
    for(int i=0;i<counter;i++)
        if(temp!=st[i])
		{
			cout<<st[i]<<endl;
			temp = st[i];
		}
	return 0;
}
