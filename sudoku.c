#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  for(int i = 0; i < 9; i++)
  {
    int row[10] = {0};
    int col[10] = {0};
    int sub[10] = {0};

    for(int j = 0; j < 9; j++)
    {
      int row_value = n->sudo[i][j];
      int col_value = n->sudo[j][i];
      int sub_value = n->sudo[3*(i/3)+(j/3)][3*(i%3)+(j%3)];

      printf("%d\n%d\n%d\n\n", row_value, col_value, sub_value);

      if(row[row_value] == 1 || col[col_value] == 1 || sub[sub_value] == 1)
        return 0;

      if(row_value != 0) row[row_value] = 1;
      if(col_value != 0) col[col_value] = 1;
      if(sub_value != 0) sub[sub_value] = 1;
    }
  }

  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int flag = 0;
    
  int i, j, k;
  for(i = 0; i < 9; i++)
  {
    for(j = 0; j < 9; j++)
    {
      if(n->sudo[i][j] == 0)
      {
        flag = 1;
        break;
      }
    }
    if(flag == 1) break;
  }

  if(flag == 0) return list;

  for(k = 1; k <= 9; k++)
  {
    Node *adj = copy(n);
    adj->sudo[i][j] = k;
    pushBack(list, adj);
  }

  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/