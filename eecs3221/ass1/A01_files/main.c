#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


//ask proff:
//does a ptr store a relative address or an absolute address
union {
    int i;
    char msg[4];
}converter;

typedef struct Node {
    char* data;
    struct Node* next;
}Node, *NodePTR;

typedef struct Queue{
    NodePTR head;
    NodePTR tail;
    int size;
}Queue, *QueuePTR;

void LLinitList(QueuePTR list,char* data){
    list->head = (NodePTR)malloc(sizeof(Node));
    list->head->data = data;
    list->head->next = NULL;
    list->tail = list->head;
    list->size = 1;
}

void LLappendHead(QueuePTR list, char* data){
    if (list->head == NULL){
        LLinitList(list, data);
        return;
    }
    NodePTR newHead = (NodePTR)malloc(sizeof(Node));
    newHead->data = data;
    newHead->next = list->head;
    list->head = newHead;
    
    list->size++;
}
 
void LLappendToTail(QueuePTR list, char* data){
    if (list->head == NULL){
        LLinitList(list, data);
        return;
    }
    list->tail->next = (NodePTR)malloc(sizeof(Node));
    list->tail->next->data = data;
    list->tail = list->tail->next;
    list->tail->next = NULL;
    
    list->size++;
}

void LLpop(QueuePTR list){
    if (list->head == NULL){
        return;
    }
    if (list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        list->size--;
        return;
    }

    NodePTR curr = list->head, prev = curr;

    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    list->size--;
    free(curr);
    curr = NULL;
    return;
    
    
}

void LLfreeAll(QueuePTR list){
    NodePTR curr = list->head;
    NodePTR toBeRemoved;

    while(curr->next != NULL){
        toBeRemoved = curr;
        curr = curr->next;
        list->size --;
        free(toBeRemoved);
        
    }
    free(curr);
}


void parser(QueuePTR list, FILE* filePTR){
    int buffSize = 4000;
    char* buffer = (char*)malloc(buffSize);
    memset(buffer, '\0' ,buffSize);
    while (fgets(buffer, buffSize, filePTR) != NULL) {
        int size  = 0, i = 0;
        while(buffer[i] != '\r' && buffer[i] != '\n' && buffer[i] != '\0'){
            size ++;
            i++;
        }
        char* str2 = (char*)malloc(size);
        for (i = 0; i < size; i++) {
            str2[i] = buffer[i];
       
        }
        LLappendToTail(list,str2);
        buffer = (char*)malloc(buffSize);
        memset(buffer, '\0' ,buffSize);
        
    }
    free(buffer);
    

}

void writeOutput(char* command, char* output)
{
	printf("The output of: %s : is\n", command);
	printf(">>>>>>>>>>>>>>>\n%s<<<<<<<<<<<<<<<\n", output);	
}


char** getArgs2(char* s){
    int slen = strlen(s);
    char* scopy = strdup(s);
    char** args = (char**)malloc(slen*sizeof(char*));
    int i = 0;
    char* tokens = strtok(scopy, " \"");
    while(tokens != NULL && i < slen){
        args[i++] = tokens;
        tokens = strtok(NULL," \"");

    }
    args[i] = NULL;
    
    return args;


}


void runCommand(char* command){
    
    
    char** strNew = getArgs2(command);
    
    int buffSize = 40;
    int pipeOutfd[2];
    pipe(pipeOutfd);
    char* buffer  = (char*)malloc(buffSize);
    
    int p = fork();
    
    
    
    if (p ==0){
        dup2 (pipeOutfd[1], STDOUT_FILENO);
        close(pipeOutfd[0]);
        close(pipeOutfd[1]);
        execvp(strNew[0], strNew);
        exit(1);
    }
    if(p > 0){
        
        memset(buffer, '\0', buffSize);
        wait(NULL);
        close(pipeOutfd[1]);
        int n = read(pipeOutfd[0], buffer, buffSize);
        while (n >= buffSize/2) {
            buffSize*=2;
            char* oldbuff = buffer;
            buffer = (char*)malloc(buffSize);
            memset(buffer, '\0', buffSize);
            memcpy(buffer, oldbuff, buffSize / 2);
            free(oldbuff);
            n = read(pipeOutfd[0], buffer+ buffSize/2, buffSize/2);
        }
        fflush(stdout);
        writeOutput(command, buffer);
        
        
    }
    free(command);
    free(buffer);
    free(strNew);
}


int main(int argc, char** argv){

    if (argc != 2){
        perror("needs argument (text document)");
        exit(1);
        return -1;
    }
    FILE* filePTR = fopen(argv[1],"r");
    
    if (filePTR == NULL) {
        perror("Error opening file");
        exit(1);
        return -1;
    }

    Queue list;

    parser(&list,filePTR);
 /*   
    pid_t mainPid = getpid();
    
    int pipeMainToChildrenfd[2];
    int pipeChildrenToMainfd[2];
 
    //pipe(pipeMainToChildrenfd);
    //pipe(pipeChildrenToMainfd);
    //pid_t p = fork();
    if (p < 0){
        return -1;
    }
    if (getpid() == mainPid){
        printf("\nfrom main\n");
        close(pipeMainToChildrenfd[0]);
        converter.i = p;
        write(pipeMainToChildrenfd[1],converter.msg , 4) ;
        printf("%d\n" ,p);
    }    
    else{
        close(pipeMainToChildrenfd[1]);
        read(pipeMainToChildrenfd[0],converter.msg,4);
        p = converter.i;
        printf("p = %d getid = %d\n",p,getpid());
    }
*/
    NodePTR curr = list.head;
    while (curr != NULL){
        runCommand(curr->data);
        curr = curr->next;
    }
    LLfreeAll(&list);


    return 0;
}