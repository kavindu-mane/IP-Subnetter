#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int blocks[4] = {-1 , -1 , -1 ,-1}; /// set default value to -1
char *temp_save; /// temporary value saving pointer
char dump[2]; /// remainder saving char array

void getValidIp(){

    printf(" Input your IP address----------------: ");

    scanf("%d %1[.] %d %1[.] %d %1[.] %d" ,&blocks[0] , &temp_save , &blocks[1] , &temp_save  , &blocks[2] , &temp_save , &blocks[3] ); /// get octets
    gets(dump); /// get remaining inputs

    if(blocks[0] == -1 || blocks[1] == -1 ||
       blocks[2] == -1 || blocks[3] == -1 ||
       dump[0] != '\0'){
        printf("\n----------------------------------------Input correct IP address--------------------------------------\n\n");
        return getValidIp();
    }else {
        for(int i = 0; i<4; i++){

            if(blocks[i]<0 || blocks[i]>255){
                printf("\n----------------------------------------Input correct IP address--------------------------------------\n\n");
                return getValidIp();
            }
        }
    }
}

int ipBlocks(int index){
    return blocks[index];
}
                                                                                                                                                #include<stdio.h>
#include<stdlib.h>
#include<string.h>

int blocks[4] = {-1 , -1 , -1 ,-1}; /// set default value to -1
char *temp_save; /// temporary value saving pointer
char dump[2]; /// remainder saving char array

void getValidIp(){

    printf(" Input your IP address----------------: ");

    scanf("%d %1[.] %d %1[.] %d %1[.] %d" ,&blocks[0] , &temp_save , &blocks[1] , &temp_save  , &blocks[2] , &temp_save , &blocks[3] ); /// get octets
    gets(dump); /// get remaining inputs

    if(blocks[0] == -1 || blocks[1] == -1 ||
       blocks[2] == -1 || blocks[3] == -1 ||
       dump[0] != '\0'){
        printf("\n----------------------------------------Input correct IP address--------------------------------------\n\n");
        return getValidIp();
    }else {
        for(int i = 0; i<4; i++){

            if(blocks[i]<0 || blocks[i]>255){
                printf("\n----------------------------------------Input correct IP address--------------------------------------\n\n");
                return getValidIp();
            }
        }
    }
}

int ipBlocks(int index){
    return blocks[index];
}
