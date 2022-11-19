#include <stdio.h>

int main()
{
    char userInput[20];
    char temp;
    int i=0;
    int index=0;
    
    printf("검색할 문자열 : ");
    scanf("%s", userInput);

    printf("\n");
    
    FILE *fp = fopen("a.txt", "r");
    
    while(1){
        temp=fgetc(fp);
        if(temp==EOF) break;
    
        if(temp==*(userInput+i)){
            i++;
            if(*(userInput+i)==NULL){
                break;
            }
        }
        else{
            i=0;
            index++;
        }
    }
    if(temp==EOF) 
        printf("Not Equal\n");
    else 
        printf("Equal\nindex : %d", index);
    
    fclose(fp);
    return 0;
}