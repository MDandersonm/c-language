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
		root->left = insertNode(root->left, key);//���������� root�� left��带 new���� �����ϰ���
	else if (key > root->key)
		root->right = insertNode(root->right, key);
	else {
		printf("�̹� ���� Ű�� �ֽ��ϴ� \n");
	}
	//printf("%c ��ȯ��", root->key);
	return root;// ���������� ���Գ���� �θ��尡 ��µ�
}


void menu() {
	printf("��ȣ �Է����ּ���:\n");
	printf("1: ����Ʈ�� ���\n");
	printf("2: ���� ����\n");
	printf("3: ���� ����\n");
	printf("4: ���� �˻�\n");
	printf("q: ����\n");
}

void displayInorder(searchTreeNode* root) {

	if (root == NULL) {
		return;
	}
	displayInorder(root->left);
	printf("%c",root->key);
	displayInorder(root->right);
}


//������ ����Ʈ���� ���� �������� ã�� �Լ�
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
	if (key < root->key) {//root�� ���������� �����ҳ���� �θ𰡵�
		root->left = deleteNodeRecursive(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNodeRecursive(root->right, key);
	}
	else {//������ ��带 ã������

		// ������ ����� ������0 �Ǵ� 1�� ���
		//������0�̸� NULL, ������1�̸� �ڽĳ���ȯ
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
		// 2���� �ڽ��ϋ�: Get the inorder successor (smallest in the right subtree)
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
			printf("[����Ʈ�� ���] :  ");
			displayInorder(root);
			printf("\n\n");

			break;
		case '2':
			printf("������ ���ڸ� �Է��ϼ���: ");
			key = getchar(); getchar();
			insertNode(root, key);
			printf("\n");
			break;
		case '3':
			printf("������ ���ڸ� �Է��ϼ���:");
			key = getchar(); getchar();
			deleteNode(&root, key);
			break;
		case '4':
			printf("ã�� ���ڸ� �Է��ϼ���:");
			key = getchar(); getchar();
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL) {
				printf(" %c�� ã�ҽ��ϴ� \n", foundedNode->key);
			}
			else {
				printf(" ���ڸ� ã�� ���߽��ϴ� \n ");
			}
			break;
		default:
			printf("���� �޴��Դϴ� �޴��� �ٽ� �����ϼ��� \n");
			break;
		
		case 'q':
			freeTree(root);
			return 0;
		};
	}

	return 0;
}