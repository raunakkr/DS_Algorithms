#include<stdio.h>

void rotate(int matrix[3][3], int n) {
 int i,layer;
 for (layer = 0; layer < n / 2; ++layer) {
 int first = layer;
 int last = n - 1 - layer;
 for(i = first; i < last; ++i) {
 int offset = i - first;
 int top = matrix[first][i]; // save top
 // left -> top
 matrix[first][i] = matrix[last-offset][first];

 // bottom -> left
 matrix[last-offset][first] = matrix[last][last - offset];

 // right -> bottom
 matrix[last][last - offset] = matrix[i][last];

 // top -> right
 matrix[i][last] = top; // right <- saved top
 }
 }
 }





int main(){
int i,j,a[3][3]={{2,4,5},{7,8,9},{1,2,3}};
int n=sizeof(a)/sizeof(a[0]);

for(i=0;i<n;i++){
    for(j=0;j<n;j++)
    printf("%d ",a[i][j]);

  printf("\n");}

printf("\n\n");
rotate(a,n);

for(i=0;i<n;i++){
    for(j=0;j<n;j++)
    printf("%d ",a[i][j]);
  printf("\n");}


return 0;
}
