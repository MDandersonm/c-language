#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 200

typedef struct {
	char word[MAX_WORD_LENGTH];
	char mean[MAX_MEAN_LENGTH];

} element ;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* insertKey30(treeNode* p, element key) {
	if (p == NULL) {
		treeNode* new = (treeNode*)malloc(sizeof(treeNode));
		new->key = key;
		new->left = new->right = NULL;
		return new;
	}
	if (strcmp(key.word, p->key.word)<0)
		p->left = insertKey30(p->left, key);//���������� root�� left��带 new���� �����ϰ���
	else if (strcmp(key.word, p->key.word) >0)
		p->right = insertKey30(p->right, key);
	else {
		printf("�̹� ���� Ű�� �ֽ��ϴ� \n");
	}
	//printf("%c ��ȯ��", root->key);
	return p;// ���������� ���Գ���� �θ��尡 ��µ�

}

void insert30(treeNode** root, element key) {
	*root = insertKey30(*root, key);

}

void deleteNode30(treeNode* root, element key) {


}

treeNode* searchBST30(treeNode* root, element key) {

	if (root == NULL) {
		return NULL;

	}
	else if (strcmp(root->key.word , key.word)<0) {
		return searchBST30(root->right, key);
	}
	else if (strcmp(root->key.word, key.word) > 0) {
		return searchBST30(root->left, key);
	}
	else if (strcmp(root->key.word, key.word) ==0)
		return root;

}

void displayInorder30(treeNode* root) {
	if (root == NULL) {
		return;
	}
	displayInorder30(root->left);
	printf("%s: %s\n", root->key.word, root->key.mean);
	displayInorder30(root->right);


}

void menu30() {
	printf("<<------------------------------------->>\n");
	printf("\t1:���\n\t2:�Է�\n\t3:����\n\t4:�˻�\n\t5:����\n");
	printf("<<------------------------------------->>\n");

}

int main0300() {
	int choice;
	element e;
	treeNode* root = NULL, * temp = NULL;
	while (1) {
		menu30();
		
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\t[�������]\n");
			displayInorder30(root); printf("\n\t[������]\n");
			break;
		case 2:
			printf("[�ܾ� �Է�] �ܾ �Է��ϼ���: ");
			scanf("%s", e.word);
			printf("[�ܾ� �Է�] �ܾ� ���� �Է��ϼ��� :  ");
			scanf("%s", e.mean);
			insert30(&root, e);
			break;
		case 3:
			scanf("%s", e.word);
			deleteNode30(root, e);
			break;
		case 4:
			printf("\n[�ܾ� �˻�] �˻��� �ܾ�:");
			scanf("%s", e.word);
			temp = searchBST30(root, e);
			if (temp != NULL) {
				printf("\n �ܾ� ��: %s\n", temp->key.mean);
			}
			else {
				printf("\n������ ���� �ܾ��Դϴ�.\n");
			}
			break;
		case 5:
			exit(1);
			break;
		}
		
	}
	


	return 0;
}