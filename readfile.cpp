#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main(){

	int fd;
	char arr[20];
	char data[30];
	cout<<"Enter name of file:";
	cin>>arr;

	fd=open(arr,O_RDONLY);
	if(fd==-1){
		cout<<"File not found:"<<endl;
		return -1;
	}
	int rd;
	while((rd=read(fd,data,sizeof(data)))!=0){
		cout<<data;
	}

	return 0;
}