///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: jan-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio_ext.h>
using namespace std;

int main(){
	char ch='A';
	char key;
	cout<<"Enter public/private key character:";
	cin>>key;
	
	char result=ch^key;

	cout<<"Encrypted Character: "<<result<<endl;

	result=result^key;

	cout<<"Decrypted Character: "<<result<<endl;


	return 0;
}
