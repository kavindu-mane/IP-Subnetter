#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char *temp_save;

/** function prototypes area start */

int subNetCount(int);
void printIps(int , int , int , int , int , int[4]);
int askPrivet();

/** function prototypes area end */

void flsmHost(){

    char temp_store[8];///
    int hosts = 4;
    int hostBit;
    char temp_class;
    int maxSubnetCount;
    int reqSubnetCount;
    int index;
    int blockSize;
    int hostCount;
    int isPrivet ;
    int oct1;
    int oct2 = rand()% 256; /// get random number less than 256
    int oct3 = rand()% 256;

    printf(" Enter the maximum host count that you need----------: ");

    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > 8388606){
        printf("\n--------------------------------------Input correct host count--------------------------------------\n");
        printf("\t\t\t\tMinimum : 2 hosts\n\t\t\t\tMaximum : 8 388 606 hosts\n\n");
        return flsmHost();
    }

    for(int i = 2; i<24; i++){
        if(temp_count <= hosts -2){
            hostBit = i;
            hostCount = hosts - 2;
            break;
        }

        hosts *=2;
    }

    if(hostBit > 15){
        temp_class = 'A';
        index = 0;
        maxSubnetCount = pow(2.0 ,(float) (24 - hostBit));
        oct1 = rand()%127 +1; /// get random number between 1 and 126

    }else if(hostBit > 7){
        temp_class = 'B';
        index = 1;
        maxSubnetCount = pow(2.0 ,(float) (16 - hostBit));
        oct1 = 128 + rand()%64; /// get random number between 128 and 191

    }else{
        temp_class = 'C';
        index = 2;
        maxSubnetCount = pow(2.0 ,(float) (8 - hostBit));
        oct1 = 192 + rand()%32; /// get random number between 192 and 223

    }

    printf(" Class-----------------------------------------------: Class %c Ip range\n" , temp_class);

    reqSubnetCount = subNetCount(maxSubnetCount);
    blockSize = 256/maxSubnetCount;
    isPrivet = askPrivet();

    if(isPrivet == 1){ /// set privet IP ranges

        switch (index){
        case 0:
            oct1 = 10;
            break;
        case 1:
            oct1 = 172;
            oct2 = 16 + rand()%16;
            break;
        default:
            oct1 = 192;
            oct2 = 168;
        }
    }


    int tmp[4] ={oct1,oct2,oct3,0};
    printIps(blockSize , maxSubnetCount , reqSubnetCount , index , hostCount , tmp);
}

int subNetCount(int maxsub){
    char temp_store[4];///

    printf(" Enter the subnets count that you need(max = %d)-----: ", maxsub);
    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > maxsub){
        printf("\n--------------------------------------Input correct subnet count--------------------------------------\n");
        return subNetCount(maxsub);
    }
}

int askPrivet(){
    char temp_result[10];
    printf(" Do you need private IP range? (Y/N)-----------------: ");
    gets(temp_result);

    if((temp_result[0] == 'y' || temp_result[0] == 'Y') && temp_result[1] == '\0'){
        return 1;

    }else if((temp_result[0] == 'n' || temp_result[0] == 'N') && temp_result[1] == '\0'){
        return 0;

    }else{
        printf("\n-----------------------------------------Input correct values-----------------------------------------\n\n");
        return askPrivet();
    }

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char *temp_save;

/** function prototypes area start */

int subNetCount(int);
void printIps(int , int , int , int , int , int[4]);
int askPrivet();

/** function prototypes area end */

void flsmHost(){

    char temp_store[8];///
    int hosts = 4;
    int hostBit;
    char temp_class;
    int maxSubnetCount;
    int reqSubnetCount;
    int index;
    int blockSize;
    int hostCount;
    int isPrivet ;
    int oct1;
    int oct2 = rand()% 256; /// get random number less than 256
    int oct3 = rand()% 256;

    printf(" Enter the maximum host count that you need----------: ");

    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > 8388606){
        printf("\n--------------------------------------Input correct host count--------------------------------------\n");
        printf("\t\t\t\tMinimum : 2 hosts\n\t\t\t\tMaximum : 8 388 606 hosts\n\n");
        return flsmHost();
    }

    for(int i = 2; i<24; i++){
        if(temp_count <= hosts -2){
            hostBit = i;
            hostCount = hosts - 2;
            break;
        }

        hosts *=2;
    }

    if(hostBit > 15){
        temp_class = 'A';
        index = 0;
        maxSubnetCount = pow(2.0 ,(float) (24 - hostBit));
        oct1 = rand()%127 +1; /// get random number between 1 and 126

    }else if(hostBit > 7){
        temp_class = 'B';
        index = 1;
        maxSubnetCount = pow(2.0 ,(float) (16 - hostBit));
        oct1 = 128 + rand()%64; /// get random number between 128 and 191

    }else{
        temp_class = 'C';
        index = 2;
        maxSubnetCount = pow(2.0 ,(float) (8 - hostBit));
        oct1 = 192 + rand()%32; /// get random number between 192 and 223

    }

    printf(" Class-----------------------------------------------: Class %c Ip range\n" , temp_class);

    reqSubnetCount = subNetCount(maxSubnetCount);
    blockSize = 256/maxSubnetCount;
    isPrivet = askPrivet();

    if(isPrivet == 1){ /// set privet IP ranges

        switch (index){
        case 0:
            oct1 = 10;
            break;
        case 1:
            oct1 = 172;
            oct2 = 16 + rand()%16;
            break;
        default:
            oct1 = 192;
            oct2 = 168;
        }
    }


    int tmp[4] ={oct1,oct2,oct3,0};
    printIps(blockSize , maxSubnetCount , reqSubnetCount , index , hostCount , tmp);
}

int subNetCount(int maxsub){
    char temp_store[4];///

    printf(" Enter the subnets count that you need(max = %d)-----: ", maxsub);
    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > maxsub){
        printf("\n--------------------------------------Input correct subnet count--------------------------------------\n");
        return subNetCount(maxsub);
    }
}

int askPrivet(){
    char temp_result[10];
    printf(" Do you need private IP range? (Y/N)-----------------: ");
    gets(temp_result);

    if((temp_result[0] == 'y' || temp_result[0] == 'Y') && temp_result[1] == '\0'){
        return 1;

    }else if((temp_result[0] == 'n' || temp_result[0] == 'N') && temp_result[1] == '\0'){
        return 0;

    }else{
        printf("\n-----------------------------------------Input correct values-----------------------------------------\n\n");
        return askPrivet();
    }

}
