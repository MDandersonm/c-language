#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct searchTreeNode {
	char key;
	struct searchTreeNode* left;
	struct searchTreeNode* right;


}searchTreeNode;




typedef char element;


searchTreeNode* searchBST(searchTreeNode* root, char key) {

	if (root==NULL) {
		return NULL;

	}
	else if (root->key < key) {
		return searchBST(root->right, key);
	}
	else if (key < root->key) {
		return searchBST(root->left, key);
	}
	else if (key == root->key)
		return root;

}

searchTreeNode* insertNode(searchTreeNode* root, char key) {
	if (root == NULL) {
		searchTreeNode* new = (searchTreeNode*)malloc(sizeof(searchTreeNode));
		new->key = key;
		new->left = new->right = NULL;
		return new;
	}
	if (key < root->key)
		root->left = insertNode(root->left, key);//최종적으로 root의 left노드를 new노드로 설정하게함
	else if (key > root->key)
		root->right = insertNode(root->right, key);
	else {
		printf("이미 같은 키가 있습니다 \n");
	}
	//printf("%c 반환됨", root->key);
	return root;// 최종적으로 삽입노드의 부모노드가 출력됨
}


void menu() {
	printf("번호 입력해주세요:\n");
	printf("1: 이진트리 출력\n");
	printf("2: 문자 삽입\n");
	printf("3: 문자 삭제\n");
	printf("4: 문자 검색\n");
	printf("q: 종료\n");
}

void displayInorder(searchTreeNode* root) {

	if (root == NULL) {
		return;
	}
	displayInorder(root->left);
	printf("%c",root->key);
	displayInorder(root->right);
}


//오른쪽 서브트리중 가장 작은값을 찾는 함수
searchTreeNode* minNode(searchTreeNode* node) {
	searchTreeNode* current = node;
	while (current && current->left != NULL) {
		current = current->left;
	}
	return current;
}


searchTreeNode* deleteNodeRecursive(searchTreeNode* root, char key) {
	if (root == NULL) {
		return root;
	}
	if (key < root->key) {//root는 최종적으로 삭제할노드의 부모가됨
		root->left = deleteNodeRecursive(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNodeRecursive(root->right, key);
	}
	else {//삭제할 노드를 찾았을때

		// 삭제할 노드의 차수가0 또는 1인 경우
		//차수가0이면 NULL, 차수가1이면 자식노드반환
		if (root->left == NULL) {
			searchTreeNode* temp = root->right; 
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			searchTreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 2명의 자식일떄: Get the inorder successor (smallest in the right subtree)
		searchTreeNode* temp = minNode(root->right);
		// Copy the inorder successor's content to this node
		root->key = temp->key;
		// Delete the inorder successor
		root->right = deleteNodeRecursive(root->right, temp->key);
	}
	return root;
}

void deleteNode(searchTreeNode** root, char key) {
	if (root == NULL) return;
	*root = deleteNodeRecursive(*root, key);
}


void freeTree(searchTreeNode* root) {
	if (root == NULL) {
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int main0170() {

	searchTreeNode* root = NULL;
	searchTreeNode* foundedNode = NULL;
	char choice, key;
	root = insertNode(root, 'G');
	searchTreeNode * what=insertNode(root, 'I');
	printf("%c !", what->key);
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');
	printf("%c !!", what->key);


	while (1) {
		menu();
		choice = getchar();
		getchar();

		switch (choice) {
		case '1':
			printf("[이진트리 출력] :  ");
			displayInorder(root);
			printf("\n\n");

			break;
		case '2':
			printf("삽입할 문자를 입력하세요: ");
			key = getchar(); getchar();
			insertNode(root, key);
			printf("\n");
			break;
		case '3':
			printf("삭제할 문자를 입력하세요:");
			key = getchar(); getchar();
			deleteNode(&root, key);
			break;
		case '4':
			printf("찾을 문자를 입력하세요:");
			key = getchar(); getchar();
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL) {
				printf(" %c를 찾았습니다 \n", foundedNode->key);
			}
			else {
				printf(" 문자를 찾지 못했습니다 \n ");
			}
			break;
		default:
			printf("없는 메뉴입니다 메뉴를 다시 선택하세요 \n");
			break;
		
		case 'q':
			freeTree(root);
			return 0;
		};
	}

	return 0;
}