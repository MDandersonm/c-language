#include <iostream>
//���
int main100() {

	//std: ���ӽ����̽� 
	//cout: std��� ���ӽ����̽��ȿ� ����ִ� ��ü
	//endl:  �ٹٲ��Ҷ� ���� ��ü

	//using namespace std; //�̷��� ������ std:: ���� �����ϴ�.
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

//�Է�
int main102() {

	int a;
	int b;
	std::cin >> a >> b;
	std::cout << a <<" + " << b << " = " << a+b << std::endl;
	return 0;
}




//���ڿ�
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


//���۷��� ����
void main104() {
	int a(10);//	int a=10;
	int &b = a; //���۷�������b�� �����ǰ� b�� a�� ����Ų��.
	b = 15; //b�� ���� a�� �ٲ� �� �ִ�.
	cout << b << endl;//a�� ���� ��µȴ�
	
	//int &c;// ���� // ������ ���ÿ� ����Ű�� ������ ������� �� ���ٿ� int a(20); �̷��� �־����.
	//���۷��������� �޸𸮻� ����� ������ �ִ� ���� ����ų �� �ִ�.(���, �Լ��Ǹ��ϰ�, ���� ����ų���� ����.)


}


//���۷��������� �� ������ ��
void main105() {
	int a(10);//	int a=10;
	int b = a; // �Ϲ� ������ ���� �� ����
	b = 15;  //�� ��, ���Ե� ���� ���� �����Ϳʹ� �������Դϴ�. ��, ���� �����Ͱ� ����Ǿ �� ������ ���� ������ ���� �ʽ��ϴ�.
	cout << a << endl;//a�� ���� ��µȴ�
	cout << b << endl;//b�� ���� ��µȴ�

}

//r-value ����
void main106() {
	int a(10);//	int a=10;
	//int& b = a+1;
	int&& b = a + 1;//����
	cout << a << endl;//a�� ���� ��µȴ�
	cout << b << endl;//b�� ���� ��µȴ�

}


//���۷��������� �̿��� for��
int main001() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int &i : arr) {//���۷��������� �����ؾ� arr�� �� ĭ�� �ٲܼ�����.
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
