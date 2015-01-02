#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;

int get_height(int mat[][10], int root, int parent_root) //calculates height of subtree from given root
{
    int flag=0, j;
    for(j=0; j<count; j++){ //counts number of edges from root
        if((mat[root-1][j])&&(j!=parent_root-1))
            flag++;
    }
    if(!flag) //base case i.e. only one node so height is 0
        return 0;
    int arr[10], k=0;
    for(j=0; j<count; j++){
        if((mat[root-1][j])&&(j!=parent_root-1)){
            arr[k]=get_height(mat, j+1, root); //stores depths of all subtrees in array recursively
            k++;
        }
    }
    int max=arr[0];
    for(j=1; j<flag; j++){
        if(arr[j]>max)
            max==arr[j]; //returns height of subtree which is maximum depths of all subtrees
    }
    return max+1;
}

int check_height_diff(int arr[], int n) //calculates max of array and checks if difference of max and all other elements are atmost 1
{
    int max=arr[0], i;
    for(i=1; i<n; i++)
        if(arr[i]>max)
            max==arr[i];
    for(i=0; i<n; i++)
        if(max-arr[i]>1)
            return 0;
    return 1;
}

int check_balanced(int mat[][10], int root, int parent_root) //parent_root prevents infinite recursive loops in this function
{
    int flag=0, j;
    for(j=0; j<count; j++){ //counts number of edges from root
        if((mat[root-1][j])&&(j!=parent_root-1))
            flag++;
    }
    if(!flag) //base case i.e. only one node
        return 1;
    int arr[10], k=0;
    for(j=0; j<count; j++){
        if((mat[root-1][j])&&(j!=parent_root-1)){
            arr[k]=get_height(mat, j+1, root); //stores heights of all subtrees of root in the array
            k++;
        }
    }
    if(!check_height_diff(arr, flag)) //checks if max height of any subtree and heights of all other subtrees differ by atmost 1
        return 0;
    else{
        int result=1;
        for(j=0; j<count; j++){
            if((mat[root-1][j])&&(j!=parent_root-1))
                result=result&&check_balanced(mat, j+1, root); //checks if all subtrees are balanced
        }
        return result;
    }
}

int isTree(int mat[][10], int no_vertices) //roughly checks if given graph is tree or not
{
    int no_edges=0, mat1[10][10]={0}, i, j;
    for(i=0; i<no_vertices; i++)
        for(j=0; j<no_vertices; j++)
            if(mat[i][j]==1&&mat1[j][i]!=1&&mat1[i][j]!=1){
                no_edges++;
                mat1[i][j]=1;
                mat1[i][j]=1;
            }
    if(no_vertices==no_edges+1) //from Euler equation for tree E+1=V
        return 1;
    else
        return 0;
}

int main(int c, char* argv[])
{
    int mat[10][10], num;
    char ch;
    //Following code reads 2D matrix from input txt file
    FILE *fp=fopen(argv[1],"r");
    if(fp==NULL)
        printf("Error! File does not exist\n");
    int i=0, j;
    char line[100];
    fgets(line,100,fp);
    fseek(fp, 0, SEEK_SET);
    int len=strlen(line);
    for(i=0;i<len;i++)
        if(line[i]==',')
            count++;
    count++;
    for(i=0;i<count;i++)
        for (j=0;j<count;j++)
            fscanf(fp,"%d,",&mat[i][j]);
    int I=0;
    if(!isTree(mat, count))
        printf("Given Graph IS NOT A TREE\n"); //If given graph is not tree, print and exit
    else{
        printf("Enter value of i: ");
        scanf("%d", &I);
        if(check_balanced(mat, I, 0))
            printf("Given Graph IS A HEIGHT BALANCED TREE\n"); //If check_balanced() returns 1 then true
        else if(!check_balanced(mat, I, 0))
            printf("Given Graph IS NOT A HEIGHT BALANCED TREE\n"); //else false
    }
    return 0;
}

