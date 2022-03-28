https://www.geeksforgeeks.org/print-subsequences-string/

https://youtu.be/Yg5a2FxU4Fo

// For string:
// Every letter has two options whether it will be part of the subset or it will be not.
// Using decision tree method(Aditya verma):

#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op){
    if(ip.size()==0){
        cout<<op<<" ";
        return;
    }
    
    string op1 = op;         // we create two output strings  (we are making a copy, ie not changing in original so I guess backtracking is not required)
    string op2 = op;
    
    op2.push_back(ip[0]);    // in second output we want to include first character from the input, In first we dont want so we do nothing
    ip.erase(ip.begin()+0);  // in input we keep on erasing the first character
    
    solve(ip, op1);          // recursive calls
    solve(ip, op2);
    return;
}

int main(){
    string ip;
    cin>>ip;
    string op=" ";
    
    solve(ip, op);

    return 0;
}

// Method 2: GFG (Just the changes are directly made inside the recursive calls)
void solve(string ip, string op){
    if(ip.size()==0){
        cout<<op<<" ";
        return;
    }
        
    solve(ip.substr(1), op);          // recursive calls  (Including input substring from first index to last)
    solve(ip.substr(1), op+ip[0]);
    return;
}



// To print unique subsets
// Eg the string is aab: " ", a, b, ab, aab
// is to be printed

map<string,int> m;

void subset(string ip,string op,){
	if((int)ip.size()==0){
		m[op]++;             // only these two lines I added additionally checking whether string was present before or not.  
		if(m[op]==1)         // If not then print. Rest is full same code as before just declare map and pass by reference.
		    cout<<op<<"\n";
        return;
	}

	string op1=op,op2=op;

	op2.push_back(ip[0]);
	ip.erase(ip.begin()+0);

	subset(ip,op1,m);
	subset(ip,op2,m);
}
