#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath>
using namespace std;

int num=0, n;	//�Hnum�x�s�ƹL���� 

void go(int a);
int stoi(string);
bool err(string);

int main(){
	
	int x, step;
	string sn;
	
	cout << setfill('=') << setw(43) << "=" << endl;
	cout << "\t\t�@�� ���֨� " << endl;
	cout << setfill('=') << setw(43) << "=" << endl;
	cout << "\t       <<�ƼƦr�C��>>" << endl;
	cout << "�W�h : �q 1 �ƨ� n , �@���̦h�� x �� , �ƨ� n ���N��F" << endl;
	cout << "���Gn�̤j��999" << endl;
		
	cout << "��Jn(0<n<1000):";
	cin  >> sn;
	
	while(err(sn)){
		cout << "���~�A�Э��s��J:";
		cin >> sn;
	}
	
	n=stoi(sn);
	
	cout << "��Jx(0<x<n):";
	cin >> sn;
	
	while (err(sn)||stoi(sn)>=n){
		cout << "���~�A�Э��s��J:";
		cin >> sn;
	}
	
	x=stoi(sn);
	
	for (int i=0;i<5;i++){	//wait a bit
		cout << " .";
		Sleep(200);
	}
	
	cout << endl << "�C���}�l!" << endl;
	Sleep(2000);
	system("cls");	//�M���ù� 
	
	if((n-1)%(x+1)==0)
		cout << "�A����!" << endl ;
		
	else{
		cout << "�q����!" << endl;
		Sleep(200);
		step=(n-1)%(x+1);
		cout << "com:" << step << endl;
		go(step);
	}
	
	
	while (1){
		
		cout << "�п�J�B��" << endl << "you:";
		cin >> sn;
		
		while (err(sn)||stoi(sn)>x){
			cout << "���~�A�Э��s��J" << endl << "you:";
			cin >> sn;
		}
		
		step=stoi(sn);
		
		go(step);
		if (num==n){
			cout << "  -YOU LOSE-" << endl << endl;
			break;
		}
		

		step=x+1-step;
		Sleep(200);
		cout << "com:" << step << endl;
		go(step);
		
	}
	system("PAUSE");
}

void go(int a){
	
	for (int i=1;i<=a;i++){
		num++;
		cout << num <<" ";
		
		if (a<32) Sleep(50);
		else if (a<200)	Sleep(5);
		else if (a<1000) Sleep(0);
		
		if (num==n)	break;
	}
	cout << endl << endl;
}

int stoi(string s){	//string to int
	
	int tmp=0;
	
	for(int i=s.length()-1;i>=0;i--)
		tmp+=(s.at(i)-'0')*pow(10,s.length()-1-i);
	
	return tmp;
}

bool err(string s){	//check for error
	
	if(s.length()>3)	//�j��3��� 
		return true;
	
	for(int i=0;i<s.length();i++){	//�ˬd�O�_���¼Ʀr 
		if(!isdigit(s.at(i))){
			return true;
			break;
		}
	}
	
	if(stoi(s)==0)	//���൥��0 
		return true;
		
	return false;
}
