#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include "ipaddress.h"

char *temp_save;
int maxSubNet[3] = {256,256,64}; /// class A = 4194304 , class B = 16384 but we limit max subnet to 256
int octets[4];

/** function prototypes area start */

char getClass(int);
void chooseBlockSize(char);
void askRestart();
void printIps(int , int , int , int , int , int[4]);

/** function prototypes area end */

void flsmIP(){

    getValidIp(); /// call getValidIp function in custom header
    octets[0] = ipBlocks(0);
    octets[1] = ipBlocks(1);
    octets[2] = ipBlocks(2);
    octets[3] = ipBlocks(3); ///get 4 octets

    char temp_class = getClass(octets[0]);
    printf(" Class--------------------------------: Class %c Ip range\n" , temp_class);

    if(temp_class == 'E'){
        printf("\n-----------------------------Class E already reserved for testing purposes----------------------------\n\n");
        askRestart();
    }else if(temp_class == 'D'){
        printf("\n-------------------------------Class D already reserved for multicasting------------------------------\n\n");
        askRestart();
    }else if(octets[0] == 127 ){
        printf("\n---------------------------127.x.x.x range already reserved for localhosting--------------------------\n\n");
        askRestart();
    }

    chooseBlockSize(temp_class);
}

char getClass(int val){
    if(val > 239){
        return 'E';
    }else if(val > 223){
        return 'D';
    }else if(val > 191){
        return 'C';
    }else if(val > 127){
        return 'B';
    }else{
        return 'A';
    }
}

void askRestart(){
    char temp_result[2];
    printf(" Do you need to restart? (Y/N)-----------: ");
    gets(temp_result);

    if((temp_result[0] == 'y' || temp_result[0] == 'Y') && temp_result[1] == '\0'){
        printf("\n------------------------------------------Program restarted-------------------------------------------\n\n");
        flsmIP();
        exit(0);

    }else if((temp_result[0] == 'n' || temp_result[0] == 'N') && temp_result[1] == '\0'){
        endProgram();
        exit(0);

    }else{
        printf("\n-----------------------------------------Input correct values-----------------------------------------\n\n");
        return askRestart();
    }

}

void chooseBlockSize(char ip_class){

    int index;///
    char temp_store[8];///
    int subNetCount = 2;
    int hostCount;

    switch(ip_class){
    case 'A':
        index = 0;
        break;
    case 'B':
        index = 1;
        break;
    default:
        index = 2;
    }

    printf(" Enter subnets count that you need----: ");
    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > maxSubNet[index]){
        printf("\n--------------------------------------Input correct subnet count--------------------------------------\n");
        printf("\t\t\t\tClass A : 2 to 256 subnets \n\t\t\t\tClass B : 2 to  256 subnets \n\t\t\t\tClass C : 2 to 64 subnets\n\n");
        return chooseBlockSize(ip_class);
    }


    for(int i = 0; i<8; i++){
        if(temp_count <= subNetCount){
            int blockSize;
            if(index == 2){ /// class c
                blockSize = (maxSubNet[index]*4)/subNetCount;
                hostCount = blockSize - 2;
            }else{ /// class A , B
                blockSize = maxSubNet[index]/subNetCount;

                if(index == 0){
                  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include "ipaddress.h"

char *temp_save;
int maxSubNet[3] = {256,256,64}; /// class A = 4194304 , class B = 16384 but we limit max subnet to 256
int octets[4];

/** function prototypes area start */

char getClass(int);
void chooseBlockSize(char);
void askRestart();
void printIps(int , int , int , int , int , int[4]);

/** function prototypes area end */

void flsmIP(){

    getValidIp(); /// call getValidIp function in custom header
    octets[0] = ipBlocks(0);
    octets[1] = ipBlocks(1);
    octets[2] = ipBlocks(2);
    octets[3] = ipBlocks(3); ///get 4 octets

    char temp_class = getClass(octets[0]);
    printf(" Class--------------------------------: Class %c Ip range\n" , temp_class);

    if(temp_class == 'E'){
        printf("\n-----------------------------Class E already reserved for testing purposes----------------------------\n\n");
        askRestart();
    }else if(temp_class == 'D'){
        printf("\n-------------------------------Class D already reserved for multicasting------------------------------\n\n");
        askRestart();
    }else if(octets[0] == 127 ){
        printf("\n---------------------------127.x.x.x range already reserved for localhosting--------------------------\n\n");
        askRestart();
    }

    chooseBlockSize(temp_class);
}

char getClass(int val){
    if(val > 239){
        return 'E';
    }else if(val > 223){
        return 'D';
    }else if(val > 191){
        return 'C';
    }else if(val > 127){
        return 'B';
    }else{
        return 'A';
    }
}

void askRestart(){
    char temp_result[2];
    printf(" Do you need to restart? (Y/N)-----------: ");
    gets(temp_result);

    if((temp_result[0] == 'y' || temp_result[0] == 'Y') && temp_result[1] == '\0'){
        printf("\n------------------------------------------Program restarted-------------------------------------------\n\n");
        flsmIP();
        exit(0);

    }else if((temp_result[0] == 'n' || temp_result[0] == 'N') && temp_result[1] == '\0'){
        endProgram();
        exit(0);

    }else{
        printf("\n-----------------------------------------Input correct values-----------------------------------------\n\n");
        return askRestart();
    }

}

void chooseBlockSize(char ip_class){

    int index;///
    char temp_store[8];///
    int subNetCount = 2;
    int hostCount;

    switch(ip_class){
    case 'A':
        index = 0;
        break;
    case 'B':
        index = 1;
        break;
    default:
        index = 2;
    }

    printf(" Enter subnets count that you need----: ");
    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > maxSubNet[index]){
        printf("\n--------------------------------------Input correct subnet count--------------------------------------\n");
        printf("\t\t\t\tClass A : 2 to 256 subnets \n\t\t\t\tClass B : 2 to  256 subnets \n\t\t\t\tClass C : 2 to 64 subnets\n\n");
        return chooseBlockSize(ip_class);
    }


    for(int i = 0; i<8; i++){
        if(temp_count <= subNetCount){
            int blockSize;
            if(index == 2){ /// class c
                blockSize = (maxSubNet[index]*4)/subNetCount;
                hostCount = blockSize - 2;
            }else{ /// class A , B
                blockSize = maxSubNet[index]/subNetCount;

                if(index == 0){
                    hostCount = pow(2.0 , (float)(16 + 7 - i)) - 2;
                }else if(index == 1){
                    hostCount = pow(2.0 , (float)(8 + 7 - i)) - 2;
                }
            }
            return printIps(blockSize , subNetCount, temp_count , index , hostCount , octets);

        }else{
            subNetCount *= 2;
        }
    }
}


