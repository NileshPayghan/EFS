///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: jan-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Author:Nilesh payghan
*/

#include<iostream>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

#define ENCRYPT 'Z'

void decryptArray(char* arr){
	
	char* temp=arr;
	while(*temp!='\0'){

		//if same character is occured then leave it 
		//take it as it is otherwise it will encrypt the remaining characters
		if(*temp!=ENCRYPT)
			*temp=(*temp)^ENCRYPT;
		
		temp++;
	}//while

}

bool decryptFile(char* filename,char* destfile){
	
	//validation of file names
	if(filename==NULL || destfile==NULL){
		return false;
	}

	int fd=0;
	int fd1=0;
	char arr[20];

	fd=open(filename,O_RDONLY);
	if(fd==-1){
		cout<<"File is not found:"<<endl;
		return false;
	}
	fd1=open(destfile,O_RDWR);
	if(fd1==-1){
		fd1=creat(destfile,0777);
		if(fd1==-1){
			return false;
		}
	}
	int rd;
	while((rd=read(fd,arr,sizeof(arr)))!=0)
	{
		decryptArray(arr);
		write(fd1,arr,rd);
	}
	cout<<"Data is encrypting:"<<endl;
return true;
}

int main(){

	char filename[30];
	char destfile[30];
	bool flag=false;
	cout<<"Enter the encrypted file name:";
	cin>>filename;
	cout<<"Enter destination filename to store data:";
	cin>>destfile;

	flag=decryptFile(filename,destfile);

	if(flag==false){
		cout<<"File is not encrypted"<<endl;
	}
	else
		cout<<"File is ecnrypted:";

	return 0;
}