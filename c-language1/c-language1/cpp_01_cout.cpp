#include <iostream>
//출력
int main100() {

	//std: 네임스페이스 
	//cout: std라는 네임스페이스안에 들어있는 객체
	//endl:  줄바꿈할때 쓰는 객체

	//using namespace std; //이렇게 적으면 std:: 생략 가능하다.
	std::cout << "Hello world" << std::endl;
	return 0;
}

int main101() {

	int a = 10;
	double b = 3.14;
	char c = 'd';
	std::cout << a<<b<<"hello"<<c << std::endl;
	return 0;
}

//입력
int main102() {

	int a;
	int b;
	std::cin >> a >> b;
	std::cout << a <<" + " << b << " = " << a+b << std::endl;
	return 0;
}




//문자열
#include <string>
using namespace std;
int main103() {
	string a;
	a = "abvfg";
	//cin >> a;
	cout << a;
	cout << a.length() << endl;

	return 0;
}


//레퍼런스 변수
void main104() {
	int a(10);//	int a=10;
	int &b = a; //레퍼런스변수b가 생성되고 b는 a를 가리킨다.
	b = 15; //b를 통해 a를 바꿀 수 있다.
	cout << b << endl;//a의 값이 출력된다
	
	//int &c;// 오류 // 생성과 동시에 가리키는 변수를 적어야함 즉 윗줄에 int a(20); 이런게 있어야함.
	//레퍼런스변수는 메모리상에 저장된 공간이 있는 값만 가리킬 수 있다.(상수, 함수의리턴값, 식을 가리킬수는 없다.)


}


//레퍼런스변수와 값 복사의 비교
void main105() {
	int a(10);//	int a=10;
	int b = a; // 일반 변수에 대한 값 복사
	b = 15;  //이 때, 대입된 값은 원본 데이터와는 독립적입니다. 즉, 원본 데이터가 변경되어도 이 변수의 값은 영향을 받지 않습니다.
	cout << a << endl;//a의 값이 출력된다
	cout << b << endl;//b의 값이 출력된다

}

//r-value 참조
void main106() {
	int a(10);//	int a=10;
	//int& b = a+1;
	int&& b = a + 1;//가능
	cout << a << endl;//a의 값이 출력된다
	cout << b << endl;//b의 값이 출력된다

}


//레퍼런스변수를 이용한 for문
int main001() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int &i : arr) {//레퍼런스변수로 선언해야 arr의 각 칸을 바꿀수있음.
		i++;
	}
	for (int i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}

class Time {
public:
	int h;
	int m;
	int s;

	Time() {
		h = 0;
		m = 0;
		s = 0;
	}
	Time(int s) {
		h = 0;
		m = 0;
		this->s = s;
	}
};
