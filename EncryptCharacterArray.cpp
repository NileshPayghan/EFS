///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: jan-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
This will takes an character array from the user and a single
character key from the user then encrypt this character array using 
that single key

*/

#include<iostream>
#include<stdio_ext.h>
#define ENCRYPT 'Z'
using namespace std;

void EncryptCharacterArray(char* data){
	if(data==NULL){
		return;
	}
	char*temp=data;
	while(*temp!='\0'){
		if(*temp!=ENCRYPT)
			*temp=((*temp)^ENCRYPT);
		temp++;
	}
}

void DecryptCharacterArray(char* data){
	if(data==NULL){
		return;
	}
	char* temp=data;
	while(*temp!='\0'){
		if(*temp!=ENCRYPT)
			*temp=((*temp)^ENCRYPT);
		temp++;
	}

}

int main(){
	char data[100]={'\0'};
	char key;

	cout<<"Enter data to Encrypt:";
	cin>>data;


	//cout<<"Enter public/private key character:";
	//cin>>key;

	EncryptCharacterArray(data);

	
	cout<<"Encrypted data:"<<endl;
	cout<<data<<endl;

	DecryptCharacterArray(data);	
	cout<<"decrypt data:"<<endl;
	cout<<data<<endl;


	//cout<<"Encrypted array"<<endl;
	//cout<<encrypt;


}
