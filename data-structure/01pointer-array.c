#include <stdio.h>

void main01() {
	//���ڹ迭
	char s1[10] = "string";//s1�� "string"�� s�� ����Ű�� �ּ�
	for (int i = 0;s1[i]; i++) {
		printf("%c",s1[i]);
	};
	printf("\n--------------------\n");
	
	//2�����迭
	char string1[3][10] = { "Dreams","come","true!" };
	printf("%p\n", string1[0]);//"Dreams�� ù���� D�� �ּ�
	printf("%s\n", string1[0]);//"Dreams�� ù���� D�� �ּҸ� �־��ְ� %s�� �ϸ� ���ڿ��� ��µǳ�?
	printf("%c\n", *string1[0]);// 'D'
	printf("%c\n", string1[0][1]); //'r'��.     �ּҰ� �����°� �ƴ�. ����ü�� ����
	printf("\n--------------------\n");


	//2�����迭 { } �� ��� ���� ����� ���̰� ����.
	char string2[3][10] = { {"Dreams"},{"come"},{"true!"} };
	printf("%p\n", string2[0]);//"Dreams�� ù���� D�� �ּ�
	printf("%c\n", *string2[0]);// 'D'
	printf("%c\n", string2[0][1]); //'r'��.     �ּҰ� �����°� �ƴ�. ����ü�� ����
	printf("\n--------------------\n");


	char arr[3][3] = { "one","two","tre" };
	printf("%c", arr[0][1]);//n���

	printf("\n--------------------\n");

	/*
	����
	"one" ���ڿ��� 'o', 'n', 'e', �׸��� �� ���� ���� '\0'���� �����Ͽ� ������ 4���� ���� ������ �ʿ�� �մϴ�.
	*/

	
	//char arr1[2] = { {"one"} ,{"two"} }; ����
	//char arr1[2] = { "one" ,"two" };����
	
	char arr1[4] = { "one" };//����
	printf("%s\n", arr1);
	char arr2[4] = "one";//����
	printf("%s\n", arr2);

	char arr3[2][4] = { {"one"} ,{"two"} };// [4]�κ��� ���ڿ��� ũ���̴�. \0�� �����ؾ���
	printf("%s\n", arr3[1]);
	char arr4[2][4] = { "one" ,"tto" };// 
	printf("%s\n", arr4[1]);

	printf("\n--------------------\n");
	//������ �迭
	
	char* ptrArray[3] = { {"korea"},{"japan"},{"china"} };
	//char* ptrArray[3] = { "korea", "japan", "china" }; �� ����.
	ptrArray[2] = "jongro";
	/*
	ptrArray[2] = "jongro"; ������ ptrArray �迭�� �� ��° ���(2�� �ε���)�� ����Ű�� �ּҸ� �����մϴ�.
	ó���� ptrArray[2]�� "china" ���ڿ��� ���� �ּҸ� ����Ű�� ������,
	�� ������ ������ �Ŀ��� "jongro" ���ڿ��� ���� �ּҸ� ����Ű�� �˴ϴ�.
	*/
	printf("%s\n", ptrArray[2]);
	/*
	* printf �Լ��� %s ���� �����ڸ� ����� ��, �����ϴ� �ּҴ� ���ڿ��� ù ��° ���ڸ� ����Ű�� �����Ϳ��� �մϴ�.
	printf�� �� �ּҸ� ���������� �Ͽ� �޸𸮸� ���������� �о�ٰ� �� ���ڸ� ������ ����� �ߴ��մϴ�.
	�� ������� ���� ���޵� �ּҷκ��� �����ϴ� ���ڿ� ��ü�� ��µ˴ϴ�.
	*/

	for (int i = 0; i < 3; i++) {
		printf("%s\n", ptrArray[i]);
	}
	printf("\n");



}