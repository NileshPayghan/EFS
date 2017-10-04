///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: jan-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Author: Nilesh payghan

First we need to create an original file with some data and 
give it name and create also destination file without data  in  it
so that we can add encrypted data in it.

give the both the exsting file names to this executable 

if the destination file is not present then it will create automatically with given name

*/
#include<iostream>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

#define ENCRYPT 'Z'

void encryptArray(char* arr){
	
	char* temp=arr;
	while(*temp!='\0'){

		//if same character is occured then leave it 
		//take it as it is otherwise it will encrypt the remaining characters
		if(*temp!=ENCRYPT)
			*temp=(*temp)^ENCRYPT;
		temp++;
	}//while
}

bool encryptFile(char* filename,char* destfile){
	
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
		encryptArray(arr);
		write(fd1,arr,rd);
	}
	cout<<"Data is encrypting:"<<endl;
return true;
}

int main(){

	char filename[30];
	char destfile[30];
	bool flag=false;
	cout<<"Enter the file name:";
	cin>>filename;
	cout<<"Enter destination filename:";
	cin>>destfile;

	flag=encryptFile(filename,destfile);

	if(flag==false){
		cout<<"File is not encrypted"<<endl;
	}
	else
		cout<<"File is ecnrypted:";

	return 0;
}