//auther: Siddharth Acharya
#include<stdio.h>

//*c in parameter means the function takes address as argument

int lens(char *d); //returns length of string
int isin(char d, char *c); //returns true id d in c;
int isnum(char *c); //return true if sting is numeric
char *concats(char *c , char *d); //concatanates 2 strings
char *removes(char *c, int d);  //removes index d from string c
char *part(int start, int end, char *c); //returns a part of string starting index and ending index(both included)
int ints(char *c); //converts to int
float floats(char *); //converts to floating point value; 
float calc(char *c);  //main calculator function

char sym[] = "+-*/";

int main(){
    char chk[15]; // sample "1-2+4";
    scanf("%s",chk);
    printf("calc is %f\n",calc(chk));
}

int lens(char *d){
    int i = 0;
    for(i=0 ; d[i]; i++);
    return i;
}
int isin(char d, char *c){
    int bool = 0;
    int i;
    for(i=0; c[i]; i++) if (c[i] == d) bool = 1;
    return bool;
}

int isnum(char *c){
    int length = lens(c);
    int sum = 0;
    int i = 0;
    for(;i<length;i++){
        if ((c[i]>='0') && (c[i] <= '9') || (c[i] == '.')) sum++;
    }
    if (sum == length) return 1;
    else return 0;
}

char *concats(char *c, char *d){ //returns pointer; since pointer stores address therefore this function also return an address
    //c is adress while *c is the value pointed
    static char ret[10];
    int i= 0,j = 0;
    for(; c[i]; i++) ret[i] = c[i];
    for(; d[j] ; j++) {ret[i] = d[j]; i++;}
    ret[i] = '\0';
    return ret;
}
char *removes(char *c,int d){
    static char rret[100];
    int i = 0,tosub = 0;
    for(i=0;c[i];i++){
        if (i == 3) continue;
        
        if (i > d) tosub = 1;

        rret[i-tosub] = c[i];
        
        
    }
    return rret;
}
char *part(int start, int end, char *c){
    int i = start;
    char static rret[100];
    for(i=start;i<=end;i++) {
        rret[i-start] = c[i];
    }
    rret[i-start] = '\0';
    return rret;
}
int ints(char *c){
    int length = lens(c)-1;
    int sum = 0;
    int i = 0,j=1;
    for(i = length;i>=0;i--) {sum += (c[i]-'0')*j;j*=10;}
    return sum;
}
float floats(char *c){
    int i = 0,index = -1;
    for(; c[i];i++) if (c[i] == '.') {index = i ;break;}
    if (index == -1) return ints(c);
    else {
        int integer_part = ints(part(0,index-1,c));
        float fract_part = 0; float dev = 10;
        for(i = index+1; c[i]; i++){
            fract_part+=(c[i]-'0')/dev;
            dev*=10;
        }
        return fract_part+integer_part;
    }
}

float calc(char *c){
    int length = lens(c);
    int i = 0,j = 0,flag = 0; 
 
    printf("exp is %s \n",c);
    if (isnum(c) ) return floats(c);
    else{
    for(j=0;j<=3;j++){      //j parses sym (in line 15)
        for(i = 0; i<length ; i++){
            //if ()
            if (c[i]==sym[j]){
                flag = 1;
                break;
            }
        }
        if (flag == 1){
                flag = 0;
                break;
            }
        
    }
    
    if (sym[j] == '+') return calc(part(0,i-1,c)) + calc(part(i+1,length-1,c));
    else if (sym[j] == '-') return calc(part(0,i-1,c)) - calc(part(i+1,length-1,c));
    else if (sym[j] == '*') return calc(part(0,i-1,c)) * calc(part(i+1,length-1,c));
    else if (sym[j] == '/') return calc(part(0,i-1,c)) / calc(part(i+1,length-1,c));
    }
}


