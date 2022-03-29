#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath>
using namespace std;

int num=0, n;	//以num儲存數過的數 

void go(int a);
int stoi(string);
bool err(string);

int main(){
	
	int x, step;
	string sn;
	
	cout << setfill('=') << setw(43) << "=" << endl;
	cout << "\t\t作者 黃少辰 " << endl;
	cout << setfill('=') << setw(43) << "=" << endl;
	cout << "\t       <<數數字遊戲>>" << endl;
	cout << "規則 : 從 1 數到 n , 一次最多數 x 個 , 數到 n 的就輸了" << endl;
	cout << "註：n最大為999" << endl;
		
	cout << "輸入n(0<n<1000):";
	cin  >> sn;
	
	while(err(sn)){
		cout << "錯誤，請重新輸入:";
		cin >> sn;
	}
	
	n=stoi(sn);
	
	cout << "輸入x(0<x<n):";
	cin >> sn;
	
	while (err(sn)||stoi(sn)>=n){
		cout << "錯誤，請重新輸入:";
		cin >> sn;
	}
	
	x=stoi(sn);
	
	for (int i=0;i<5;i++){	//wait a bit
		cout << " .";
		Sleep(200);
	}
	
	cout << endl << "遊戲開始!" << endl;
	Sleep(2000);
	system("cls");	//清除螢幕 
	
	if((n-1)%(x+1)==0)
		cout << "你先請!" << endl ;
		
	else{
		cout << "電腦先!" << endl;
		Sleep(200);
		step=(n-1)%(x+1);
		cout << "com:" << step << endl;
		go(step);
	}
	
	
	while (1){
		
		cout << "請輸入步數" << endl << "you:";
		cin >> sn;
		
		while (err(sn)||stoi(sn)>x){
			cout << "錯誤，請重新輸入" << endl << "you:";
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
	
	if(s.length()>3)	//大於3位數 
		return true;
	
	for(int i=0;i<s.length();i++){	//檢查是否為純數字 
		if(!isdigit(s.at(i))){
			return true;
			break;
		}
	}
	
	if(stoi(s)==0)	//不能等於0 
		return true;
		
	return false;
}
