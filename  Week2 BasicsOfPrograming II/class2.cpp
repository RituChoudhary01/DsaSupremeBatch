#include<iostream>
using namespace std;
int count = 234;
/*
Patter print 
Q1.Numeric full Pyramid
n=5
    1
   232
  34543
 4567654
567898765

int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        // spaces
        for(int space = 0;space<n-row-1;space++){
            cout<<" ";
        }
        // first half part of number of col
        for(int col=0;col<=row;col++){
            cout<<row+col+1;
        }
        //reverse counting
		int start = 2*row;
		for(int col=0; col <row; col = col + 1) {
			cout << start;
			start = start - 1;
		}
        cout<<endl;
    }
    return 0;
}
*/

/*
Q2.Numeric Hellow Pyramid
n=5
    1
   1 2
  1   3
 1     4
1 2 3 4 5

int main(){
      int n;
	cin >>n;


	for(int row=0; row<n; row = row + 1) {
		//spaces
		for(int col=0; col < n-row-1; col = col +1) {
			cout << " ";
		}

		//numerbers with spaces in between
		int start = 1;
		for(int col =0; col < 2*row+1; col = col + 1) {
			//first row or last row 
			if(row == 0 || row == n-1) {
				if(col %2 == 0) {
					//even
					cout << start;
					start = start + 1;
				}
				else {
					//odd
					cout << " ";
				}
			}
			else {
				//first col
				if(col == 0) {
					cout << 1;
				}
				else if(col == 2*row){
					cout << row+1;
				}
				else {
					cout <<" ";
				}
			}
		}
		cout << endl;
	}
}
*/
/*
Bitwise oprator
AND
OR
NOT
XOR
    bool a = false;
	bool b = true;

	a = (~a);
	a = ~(a);
	cout << (~a) << endl;
	cout <<  (a | b) ;
 	cout << (a^b) ;
    cout << (5 & 10 ) << endl;
    // left shift
    // right shift
    int a = 5;
	a = a>>1;
	a = a<<1;
	a = a<<4;
	a = a>>2;
	// post and pre increment/Drecement
	int a = 6;
	int c = a++ + 1;

	cout << c;

	int a = 11;
	cout << a++;

	cout<< endl << a << endl;
	 int a = 5;
	cout << (++a) * (++a) << endl;
	int b = 3;
	cout<<b--<<endl;
	cout<<--b<<endl;
 
    cout<<--b*(b--)+(++a)*b<<endl;
     //   operator precedence 

	// break and continue keyword
	for(int i=0;i<n;i++){
	cout<<"Hi"<<endl;
	   break;
	}

	for(int i=0;i<n;i++){
	if(i==2){
	continue;
	}
	cout<<"Hi"<<endl;
  }

    //   variable scope
  
	//decalaration
	int a;
	//initialisation
	int b = 5;
	//updation
	 b = 10;
	cout << count << endl;

	if(true) {
		int b = 15;
		int count = 421;

		cout << b << endl;
		cout << count << endl;
	}

	cout << b << endl;

	// switch case
	int val;
	cout << "Enter the value " << endl;

	cin >> val;

	switch(val) {
		case 1: cout << "Love ";
		break;
		case 2: cout << "Babbar";
		break;
		case 3: cout << "Ramesh";
		break;
		case 4: cout << "Rahul";
		break;
		default: cout << "Suresh";
	}
*/