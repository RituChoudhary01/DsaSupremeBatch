#include<iostream>
using namespace std;
/*
pattern printing
Q1.FULL Pyramid
 n=5
     * 
    * * 
   * * * 
  * * * * 
 * * * * * 
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        // space print
        for(int col = 0 ;col<n-row; col++){
            cout<<" ";
        }
        // * print
        for(int col=0;col<=row;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
*/


/*
Q2.Inverted full pyramid
n=5
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
    int main(){
    int n;
    cin>>n;
    for(int row=0; row<n; row=row+1) {
		//spaces
		for(int col=0; col<row; col = col + 1) {
			cout << " ";
		}
       //stars
		for(int col=0; col<n-row; col = col + 1) {
			cout << "* ";
		}
		cout << endl;
	 }
    return 0;
    }
 */

/*
Q3.Solid Diamond
n=5;
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
    
    int main(){
    int n;
    cin>>n;
    // full pyramid
	 for(int row=0; row<n; row= row+1) {
		//space
	 for(int col=0; col<n-row-1; col = col + 1) {
			cout <<" ";
		}
        //stars
	 for(int col=0; col <row+1; col = col + 1) {
			cout << "* ";
		}
		cout << endl;
	}
	//inverted full pyramid
	for(int row=0; row<n; row=row+1) {
		//spaces
		for(int col=0; col<row; col = col + 1) {
			cout << " ";
		}
        //stars
	for(int col=0; col<n-row; col = col + 1) {
			cout << "* ";
		}
		cout << endl;
	}
    return 0;
}
*/

/*
Q4.Hollow Diamond
n=5
    *
   * *
  *   *
 *     *
*       *
*       *
 *     *
  *   *
   * *
    *

    int main(){
    int n;
    cin>>n;
      for(int row=0; row<n; row=row+1){
		//spaces
		for(int col=0;col<n-row-1; col = col + 1){
			cout << " ";
		}
        //stars
		 for(int col=0; col<2*row+1; col = col + 1){
			//if first character or if last character
			if(col == 0 || col == 2*row) {
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
     cout << endl;
	}
     for(int row=0; row<n; row=row+1){
		//spaces
		for(int col=0; col<row; col=col+1){
			cout <<" ";
		}
          for(int col=0; col<2*(n-row)-1; col = col + 1){
			//if first or last character
			if(col == 0 || col == 2*(n-row)-2 ) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
   }
}
*/

/*
Flipped Solid Diamond
Q5. n=5;
* * * * * * * * * * * * 
* * * * *     * * * * * 
* * * *         * * * * 
* * *             * * * 
* *                 * * 
*                     * 
*                     * 
* *                 * * 
* * *             * * * 
* * * *         * * * * 
* * * * *     * * * * * 
* * * * * * * * * * * * 

int main(){
int n;
cin>>n;
// first half part
for(int row=0;row<=n;row++){
    for(int col=0;col<=n-row;col++){
             cout<<"* ";
    }
    // spaces
    for(int space = 0;space<2*row;space++){
        cout<<"  ";
    }
    for(int col=0;col<=n-row;col++){
             cout<<"* ";
    }
    cout<<endl;
}
// left half part
    for(int row=0;row<=n;row++){
      for(int col=0;col<=row;col++){
             cout<<"* ";
    }
    // spaces
    for(int space = 0;space<2*(n-row);space++){
        cout<<"  ";
    }
    for(int col=0;col<=row;col++){
             cout<<"* ";
    }
    cout<<endl;
}
    return 0;
}
*/


/*
Fancy pattern
Q6.n=5
1
2*2
3*3*3
4*4*4*4
5*5*5*5*5
5*5*5*5*5
4*4*4*4
3*3*3
2*2
1

int main(){
    int n;
    cin>>n;
    // first half part
    for(int row = 0;row<n;row++){
        for(int col = 0;col<=row;col++){
            if(col==row){
                cout<<row+1;
            }
            else{
                cout<<row+1<<"*";
            }
        }
        cout<<endl;
    }
    // left haft part
    for(int row = 0;row < n;row++){
        for(int col = 0; col<=n-row-1; col++){
            if(col==n-row-1){
                cout<<n-row;
            }
            else{
                cout<<n-row<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}
*/

/*
Q7.Alphabet Palindrome Pyramid
n=5;
A 
A B A 
A B C B A 
A B C D C B A 
A B C D E D C B A 

    int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        char ch = 'A';
        // print half col;
       for(int col=0;col<=row;col++){
         cout<<ch++<<" ";
        }
        ch--;
        //print remaning half col;
        for(int col = 0;col<row;col++){
            cout<<--ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/
