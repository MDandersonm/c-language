#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct folderTreeNode {
	int size;
	struct folderTreeNode* left;
	struct folderTreeNode* right;


}folderTreeNode;


folderTreeNode* makeFolderRootNode(int size, folderTreeNode* leftNode, folderTreeNode* rightNode) {
	folderTreeNode* root = (folderTreeNode*)malloc(sizeof(folderTreeNode));
	root->size = size;
	root->left = leftNode;
	root->right = rightNode;
	return root;

}

int FolderSize = 0;
int postorder_FolderSize(folderTreeNode* root) {

	if (root == NULL) {
		return 0; // 노드가 NULL이면 반환
	}

	postorder_FolderSize(root->left);
	postorder_FolderSize(root->right);
	FolderSize += root->size;
	return FolderSize;
}
int main0160() {

	folderTreeNode* f11= makeFolderRootNode(120, NULL, NULL);
	folderTreeNode* f10 = makeFolderRootNode(55, NULL, NULL);
	folderTreeNode* f9 = makeFolderRootNode(100, NULL, NULL);
	folderTreeNode* f8 = makeFolderRootNode(200, NULL, NULL);
	folderTreeNode* f7 = makeFolderRootNode(68, f10, f11);
	folderTreeNode* f6 = makeFolderRootNode(40, NULL, NULL);
	folderTreeNode* f5 = makeFolderRootNode(15, NULL, NULL);
	folderTreeNode* f4 = makeFolderRootNode(2, f8, f9);
	folderTreeNode* f3 = makeFolderRootNode(10, f6, f7);
	folderTreeNode* f2 = makeFolderRootNode(0, f4, f5);
	folderTreeNode* f1 = makeFolderRootNode(0, f2, f3);

	printf("\n C:\\의 용량 : %d M \n",postorder_FolderSize(f2) ) ;
	FolderSize = 0;
	printf("\n D:\\의 용량 : %d M \n", postorder_FolderSize(f3));
	FolderSize = 0;
	printf("\n  내 컴퓨터 전체의 용량 : %d M \n", postorder_FolderSize(f1));





	return 0;
}