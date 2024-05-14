#include <stdio.h>

void main01() {
	//문자배열
	char s1[10] = "string";//s1은 "string"의 s를 가리키는 주소
	for (int i = 0;s1[i]; i++) {
		printf("%c",s1[i]);
	};
	printf("\n--------------------\n");
	
	//2차원배열
	char string1[3][10] = { "Dreams","come","true!" };
	printf("%p\n", string1[0]);//"Dreams의 첫번쨰 D의 주소
	printf("%s\n", string1[0]);//"Dreams의 첫번쨰 D의 주소를 넣어주고 %s로 하면 문자열이 출력되네?
	printf("%c\n", *string1[0]);// 'D'
	printf("%c\n", string1[0][1]); //'r'값.     주소가 나오는게 아님. 값자체가 나옴
	printf("\n--------------------\n");


	//2차원배열 { } 로 묶어도 위의 결과와 차이가 없다.
	char string2[3][10] = { {"Dreams"},{"come"},{"true!"} };
	printf("%p\n", string2[0]);//"Dreams의 첫번쨰 D의 주소
	printf("%c\n", *string2[0]);// 'D'
	printf("%c\n", string2[0][1]); //'r'값.     주소가 나오는게 아님. 값자체가 나옴
	printf("\n--------------------\n");


	char arr[3][3] = { "one","two","tre" };
	printf("%c", arr[0][1]);//n출력

	printf("\n--------------------\n");

	/*
	주의
	"one" 문자열은 'o', 'n', 'e', 그리고 널 종료 문자 '\0'까지 포함하여 실제로 4개의 문자 공간을 필요로 합니다.
	*/

	
	//char arr1[2] = { {"one"} ,{"two"} }; 에러
	//char arr1[2] = { "one" ,"two" };에러
	
	char arr1[4] = { "one" };//가능
	printf("%s\n", arr1);
	char arr2[4] = "one";//가능
	printf("%s\n", arr2);

	char arr3[2][4] = { {"one"} ,{"two"} };// [4]부분은 문자열의 크기이다. \0를 포함해야함
	printf("%s\n", arr3[1]);
	char arr4[2][4] = { "one" ,"tto" };// 
	printf("%s\n", arr4[1]);

	printf("\n--------------------\n");
	//포인터 배열
	
	char* ptrArray[3] = { {"korea"},{"japan"},{"china"} };
	//char* ptrArray[3] = { "korea", "japan", "china" }; 와 같다.
	ptrArray[2] = "jongro";
	/*
	ptrArray[2] = "jongro"; 구문은 ptrArray 배열의 세 번째 요소(2번 인덱스)가 가리키는 주소를 변경합니다.
	처음에 ptrArray[2]는 "china" 문자열의 시작 주소를 가리키고 있지만,
	이 구문을 실행한 후에는 "jongro" 문자열의 시작 주소를 가리키게 됩니다.
	*/
	printf("%s\n", ptrArray[2]);
	/*
	* printf 함수에 %s 서식 지정자를 사용할 때, 전달하는 주소는 문자열의 첫 번째 문자를 가리키는 포인터여야 합니다.
	printf는 이 주소를 시작점으로 하여 메모리를 순차적으로 읽어가다가 널 문자를 만나면 출력을 중단합니다.
	이 방식으로 인해 전달된 주소로부터 시작하는 문자열 전체가 출력됩니다.
	*/

	for (int i = 0; i < 3; i++) {
		printf("%s\n", ptrArray[i]);
	}
	printf("\n");



}