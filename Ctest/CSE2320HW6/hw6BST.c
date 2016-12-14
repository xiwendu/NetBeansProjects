
//------------------------------------------------------------------------------
//Hi Sadia,
//I have not find out how to import the dictionary file. But this is the binary 
//search tree. It can input the English word and Spanish meaning by user. and Then
//doing the Search. Hope I can get a good partial credit.
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct BSTnode {
        char word[128], meaning[256];
        struct BSTnode *left, *right;
  };

  struct BSTnode *root = NULL;

  struct BSTnode * createNode(char *word, char *meaning) {
        struct BSTnode *newnode;
        newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        strcpy(newnode->word, word);
        strcpy(newnode->meaning, meaning);
        newnode->left = newnode->right = NULL;
        return newnode;
  }

  void insert(char *word, char *meaning) {
        struct BSTnode *parent = NULL, *current = NULL, *newnode = NULL;
        int res = 0;
        if (!root) {
                root = createNode(word, meaning);
                return;
        }
        for (current = root; current !=NULL;
           current = (res > 0) ? current->right : current->left) {
                res = strcasecmp(word, current->word);
                if (res == 0) {
                        printf("Duplicate entry!!\n");
                        return;
                }
                parent = current;
        }
        newnode = createNode(word, meaning);
        res > 0 ? (parent->right = newnode) : (parent->left = newnode);
        return;
  }

  void deleteNode(char *str) {
        struct BSTnode *parent = NULL, *current = NULL, *temp = NULL;
        int flag = 0, res = 0;
        if (!root) {
                printf("BST is not present!!\n");
                return;
        }
        current = root;
        while (1) {
                res = strcasecmp(current->word, str);
                if (res == 0)
                        break;
                flag = res;
                parent = current;
                current = (res > 0) ? current->left : current->right;
                if (current == NULL)
                        return;
        }
        /* deleting leaf node */
        if (current->right == NULL) {
                if (current == root && current->left == NULL) {
                        free(current);
                        root = NULL;
                        return;
                } else if (current == root) {
                        root = current->left;
                        free (current);
                        return;
                }

                flag > 0 ? (parent->left = current->left) :
                                (parent->right = current->left);
        } else {
                /* delete node with single child */
                temp = current->right;
                if (!temp->left) {
                        temp->left = current->left;
                        if (current == root) {
                                root = temp;
                                free(current);
                                return;
                        }
                        flag > 0 ? (parent->left = temp) :
                                        (parent->right = temp);
                } else {
                        /* delete node with two children */
                        struct BSTnode *successor = NULL;
                        while (1) {
                                successor = temp->left;
                                if (!successor->left)
                                        break;
                                temp = successor;
                        }
                        temp->left = successor->right;
                        successor->left = current->left;
                        successor->right = current->right;
                        if (current == root) {
                                root = successor;
                                free(current);
                                return;
                        }
                        (flag > 0) ? (parent->left = successor) :
                                        (parent->right = successor);
                }
        }
        free (current);
        return;
  }

  void findElement(char *str) {
        struct BSTnode *temp = NULL;
        int flag = 0, res = 0,count =1;
        if (root == NULL) {
                printf("Binary Search Tree is out of station!!\n");
                return;
        }
        temp = root;
        while (temp) {
                if ((res = strcasecmp(temp->word, str)) == 0) {
                        printf("Word   : %s", str);
                        printf("Meaning: %s", temp->meaning);
                        printf("%d BST nodes\n",count);
                        flag = 1;
                        break;
                }
                temp = (res > 0) ? temp->left : temp->right;
                count++;
                
        }
        if (!flag)
                printf("Search Element not found in Binary Search Tree\n");
        return;
  }

  int main() {
        int ch;
        char str[128], meaning[256];
        while (1) {
                printf("1. Insertion\n");
                printf("2. Deletion\n");
                printf("3. Searching\n");
                printf("4. Exit\nEnter your choice:");
                scanf("%d", &ch);
                getchar();
                switch (ch) {
                        case 1:
                                printf("English Word:");
                                fgets(str, 100, stdin);
                                printf("Spanish Meaning:");
                                fgets(meaning, 256, stdin);
                                insert(str, meaning);
                                break;
                        case 2:
                                printf("Enter the word to delete:");
                                fgets(str, 100, stdin);
                                deleteNode(str);
                                break;
                        case 3:
                                printf("Enter the English word that you want to search:");
                                fgets(str, 100, stdin);
                                findElement(str);
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("You have entered wrong option\n");
                                break;
                }
        }
        return 0;
  }