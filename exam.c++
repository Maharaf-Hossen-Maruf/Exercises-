
#include<bits/stdc++.h>
using namespace std;

class Student {
	public:
	string name;
	char section;
	int roll;



	// void print_mark(int m,string pas){
	// 	cout<<m<<" "<<pas<<endl;
	// }
	void set_marks(int marks){
		english_marks=marks;
		
		// print_mark(english_marks,pass);
	}

	void setter(string pass){
		password=pass;
	}

	protected:
	int english_marks;

	private:
	string password;
};

int main(){
	int n;
	cin>>n;
	Student  a[n];
	// a[0].set_marks(20,"marud");
	// // a.setter("maruf");
	for (int i = 0; i < n; i++)
	{
		int eng_mark;
		string pass;


		cin>>a[i].name;
		cin>>a[i].section;
		cin>>a[i].roll;
		cin>>eng_mark;
		cin>>pass;

		a[i].set_marks(eng_mark);
		a[i].setter(pass);

	}
	for (int i = 0; i < n; i++)
	{
		cout<<a[i].name<<endl;
		cout<<a[i].section<<endl;
		cout<<a[i].roll<<endl;
		
		printf("\n");
	}
	
	return 0;
}


