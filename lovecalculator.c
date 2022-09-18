#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void spilt_number(int * arr,int *array_size),spilt_number_while_adding(int *arr,int *l_var1,int *size);
void string_lower(char *name),remove_space_in_string(char *string),print(int *arr,char *string_1,char *string_2);
int main ()
{ printf("WELCOME TO LOVE CALCULATOR\n");
    char string_1[30],string_2[30];
    printf("Enter first partner name\n");
    gets(string_1);
    printf("Enter second partner name\n");
    gets(string_2);
    char love[]="loves\0";
    char *name=(char*)calloc((strlen(string_1)+strlen(string_2)+strlen(love)),sizeof(char));
    strcpy(name,string_1);
    strcat(name,love);
    strcat(name,string_2);
    remove_space_in_string(name);
    string_lower(name);
    int l_var1,l_var2,*arr,array_size=0;
    arr=(int*)calloc(1,sizeof(int));
    for(l_var1=0; name[l_var1]!='\0'; l_var1++) {//traverse the string for storing count of repeating/single letters
                int c=1;
        char ch;
        if(name[l_var1]!='$') {
            for(l_var2=l_var1+1; name[l_var2]!='\0'; l_var2++) {
                if(name[l_var1]==name[l_var2]) {
                    ch = name[l_var2]; 
                    name[l_var2]='$';
                    c++;
                }
            }
            arr[array_size]=c;
            
            if(arr[array_size]>=10){
                spilt_number(arr,&array_size);
            }
            arr=realloc(arr,(array_size+2)*sizeof(int));
            array_size++;
        }
    }
    int size = array_size-1,df=0;
    while((size!=1)) {
        for(l_var1=0,size; l_var1<size; l_var1++,size--) {
            arr[l_var1]= arr[l_var1]+arr[size];
            arr[size]=0;
            if(arr[l_var1]>=10)
            {
                spilt_number_while_adding(arr,&l_var1,&size);  
            }
        }
    }
    arr[0]=arr[0]+arr[2];
    arr[0]=(arr[0]*10)+arr[1];
    print(arr,string_1,string_2);
free(arr);
    return 0;
}
//when a number 11>=10 occur,it spilts 11 into 1 1 and stores the element in side by side and reallocate memory for next element
void spilt_number(int * arr,int *array_size){
arr=realloc(arr,(*(array_size)+2)*sizeof(int));
                int y =arr[*(array_size)];
                arr[*(array_size)]=(int)(y/10);
                arr[*array_size+1]=y%10;
                (*array_size)++;
}
//when a number 11>=10 occur,it spilts 11 into 1 1 and stores the element in side by side and shifts the other elements of the array
void spilt_number_while_adding(int *arr,int *l_var1,int *size){
                int y =arr[*l_var1],temp=arr[*l_var1+1];
                arr[*l_var1]=(int)(y/10);
                arr[*l_var1+1]=y%10;
                for(int l_var2=*l_var1+2;l_var2<=*size;l_var2++){
                    y=arr[l_var2];
                    
              arr[l_var2]=temp;
              temp=y;
                }
                (*l_var1)++;
             (*size)++;
            }
void string_lower(char *name){
    for(int l_var1=0;name[l_var1]!='\0';l_var1++)
    name[l_var1]=tolower(name[l_var1]);
}
void remove_space_in_string(char *string){
    int count=0;
    for(int i=0;string[i]!='\0';i++){
      if(string[i]!=' ')
      string[count++]=string[i];
      }
      string[count]='\0';
}
void print(int *a,char *string_1,char *string_2){                                        
                                printf("\n      %s\n\n",string_1);
                              printf("  ████     ████\n");                              
                              printf("██▒▒▒▒█████▒▒▒▒██\n");                            
                              printf("██▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");                            
                              printf("██▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");                            
                              printf("  ██▒▒ %d%% ▒▒██\n",a[0]);                              
                              printf("    ██▒▒▒▒▒██\n");                                
                              printf("      █▒▒▒█\n");
                              printf("       █▒█\n");
                              printf("        █\n\n");                            
                                printf("      %s\n",string_2);
                                }
