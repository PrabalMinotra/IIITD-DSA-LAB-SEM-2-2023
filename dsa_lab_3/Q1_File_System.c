// Implement File System using Linked List.

// You need to write the following functions that are used in the file system.

// S.No.	Command	Description
// 1	pwd	                      \\  Prints the path of the directory starting from root
// 2	ls	                      \\ Lists all directories inside the current directory (space-separated) sorted in lexicographical order
// 3	mkdir 'directory_name'	  \\ Create a directory 'directory_name'
// 4	cd 'directory_name'	      \\ Change current directory to 'directory_name'
// 5	cd ..	                  \\ Change current directory to its parent directory
// 6	rm -r 'directory_name'	  \\ Deletes 'directoryName' and all its subsequent directories
// Note:

// Initially you are at 'root' directory.
// Each Directory can have maximum 20
//  directories
// You have to perform 𝑄
//  operations in the File System.

// Input
// The first line of the input contains a single integer 𝑄
//  (1<=𝑄<=105)— the number of operations to perform.

// Each of the next 𝑄
//  lines contains two lines:

// The first line contains an integer 𝑛
//  — the number of words in the command.
// The second line contains the command as a string of 𝑛
//  words as described above.
// Output
// You have to print the output the each command as follows

// S.No.	Command	Output
// 1	pwd	                    \\ Prints all directories starting from the root
//                                 each directory separated by '/' in the path.
//                                 For example : root/dir1/dir2/currentdir

// 2	ls	                    \\ dir1 dir2 dir3
// 3	mkdir 'directory_name'	\\ No Output if successfull otherwise -1
// 4	cd 'directory_name'	    \\ No Output if successfull otherwise -1
// 5	rm -r 'directory_name'	\\ No Output if successfull otherwise -1

// input
// 10
// 2
// mkdir dir1
// 2
// cd dir1
// 1
// pwd
// 2
// cd dir2
// 2
// cd ..
// 1
// pwd
// 2
// mkdir dir2
// 1
// ls
// 3
// rm -r dir2
// 1
// ls


// output
// root/dir1
// -1
// root
// dir1 dir2 
// dir1 



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cmdline{
    char* name;
    //main root
    struct cmdline* parent;
    //array for registers, directories
    struct cmdline* arr[20];
    int counter;
}cmdline;

// void sort(cmdline** arr, int len);
// void insert (cmdline** root, char* filename);
// void delete(cmdline** root, char* filename);

void sort(cmdline** arr, int len){
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            if (strcmp(arr[i]->name, arr[j]->name) > 0){
                cmdline* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }}}}

void insert (cmdline** root, char* filename){
    //error 1
    if ((*root)->counter == 20){
        printf("%d\n",-1);
        return;}
    //good work
    for (int i = 0; i < (*root)->counter; i++){
        if (strcmp((((*root)->arr)[i])->name,filename) == 0)
        {printf("%d\n",-1);
            return;}}
    cmdline* Node = (cmdline*)malloc(sizeof(cmdline));
    Node->name = filename;
    Node->parent = *root;
    for (int i = 0; i < 20; i++){(Node->arr)[i] = NULL;}
    Node->counter = 0;
    ((*root)->arr)[(*root)->counter] = Node;
    (*root)->counter = (*root)->counter + 1;}

void delete(cmdline** root, char* filename){
    //error 1
    if ((*root)->counter == 0){

    printf("%d\n",-1);
    return;}
    //good work
    for (int i = 0; i < (*root)->counter; i++){
        if (strcmp((((*root)->arr)[i])->name,filename) == 0){
            if (i == 19){
                ((*root)->arr)[i] = NULL;
                (*root)->counter = (*root)->counter - 1;
                return;}
            ((*root)->arr)[i] = NULL;
            for (int j = i; j < (*root)->counter-1; j++){
                ((*root)->arr)[j] = ((*root)->arr)[j+1];}
            ((*root)->arr)[(*root)->counter-1] = NULL;
            (*root)->counter = (*root)->counter - 1;
            return;}}
    printf("%d\n",-1);
    return;
    }


int main(){
    int q = 0;
    scanf("%d",&q);
    cmdline* root = (cmdline*)malloc(sizeof(cmdline));

    char* arr = (char*)malloc(6*sizeof(char));
    
    arr = "root\0";
    //adds the wanted root to the pathway to a file (error in prev)
    root->name = arr;
    //ll
    root->parent = NULL;
    root->counter = 0;
    //file addition, dir##
    for (int i = 0; i < 20; i++) (root->arr)[i] = NULL;
   
    cmdline* currentdir = root;
    int depth = 0;



    for (int i = 0; i < q; i++){
        char query[10];
        int words=0;
        scanf("%d",&words);
        scanf("%s",query);



        //hardcodey part
        if (query[0] == 'm'){
            char* directoryname = (char*)malloc(101*sizeof(char));
            scanf("%s",directoryname);
            insert(&currentdir,directoryname);}
        else if(query[0] == 'r'){
            char set[10];
            char* directoryname = (char*)malloc(101*sizeof(char));
            scanf("%s",set);
            scanf("%s",directoryname);
            delete(&currentdir,directoryname);}
        else if (query[0] == 'c'){
            char* directoryname = (char*)malloc(101*sizeof(char));
            scanf("%s",directoryname);
            if(directoryname[0] == '.' && directoryname[1] == '.'){
                if (currentdir->parent != NULL){
                currentdir = currentdir->parent;
                depth--;}
                else printf("%d\n",-1);
                }else{
                int flag = 0;
                for (int j = 0; j < currentdir->counter; j++){
                    if (strcmp(((currentdir->arr)[j])->name,directoryname) == 0){
                        flag = 1;
                        currentdir = (currentdir->arr)[j];
                        depth++;
                        break;}}
                if (flag == 0) printf("%d\n",-1);}}
        else if (query[0] == 'l'){
            sort(currentdir->arr,currentdir->counter);
            for (int j = 0; j < currentdir->counter; j++){
                printf("%s ",((currentdir->arr)[j])->name);}
            printf("\n");}
        else{
            char* array[depth+1];
            cmdline* temp2 = currentdir;
            int t = depth;
            while (temp2!=NULL){
                array[t] = temp2->name;
                t--;
                temp2 = temp2->parent;}
            printf("root");
            for (int j = 1; j < depth+1; j++){
                printf("/%s",array[j]);}
            printf("\n");}}
    return 0;}


