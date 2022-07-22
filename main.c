#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char *temp_pointer;

/** function prototypes area start */

void flsmType();
void loading(int);

/** function prototypes area end */

void createOrClear(){ /// clear or create file
    ///printf("\t**We have limited maximum subnet count to 256 because we can\'t give more than 256 due to technical reasons.**\n\n");

    FILE *fp;

    fp = fopen("ip_subnetter_output.txt","w");
    fclose(fp);

}

void fileop(char arr[85]){ /// edit file
    FILE *fp;

    fp = fopen("ip_subnetter_output.txt","a");
    fputs(arr, fp);
    fclose(fp);

}

void main(){

    char temp_store[2];

    createOrClear();

    printf(" Choose subnetting method using bellow numbers:\n\t\t ~ Fixed Length Subnet Masking(FLSM) ------ 1\n\t\t ~ Variable Length Subnet Masking(VLSM) --- 2\n\n");
    printf(" Select IP subnetting method-----: ");
    gets(temp_store);

    int temp_val = strtol(temp_store , &temp_pointer , 10);

    if(*temp_pointer == '\0' && temp_val ==1){

        flsmType();

    }else if(*temp_pointer == '\0' && temp_val == 2){

        load#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char *temp_pointer;

/** function prototypes area start */

void flsmType();
void loading(int);

/** function prototypes area end */

void createOrClear(){ /// clear or create file
    ///printf("\t**We have limited maximum subnet count to 256 because we can\'t give more than 256 due to technical reasons.**\n\n");

    FILE *fp;

    fp = fopen("ip_subnetter_output.txt","w");
    fclose(fp);

}

void fileop(char arr[85]){ /// edit file
    FILE *fp;

    fp = fopen("ip_subnetter_output.txt","a");
    fputs(arr, fp);
    fclose(fp);

}

void main(){

    char temp_store[2];

    createOrClear();

    printf(" Choose subnetting method using bellow numbers:\n\t\t ~ Fixed Length Subnet Masking(FLSM) ------ 1\n\t\t ~ Variable Length Subnet Masking(VLSM) --- 2\n\n");
    printf(" Select IP subnetting method-----: ");
    gets(temp_store);

    int temp_val = strtol(temp_store , &temp_pointer , 10);

    if(*temp_pointer == '\0' && temp_val ==1){

        flsmType();

    }else if(*temp_pointer == '\0' && temp_val == 2){

        loading(2); /// mode 2 vlsm
        vlsm(); /// call vlsm function in vlsm.c file

    }else{
        system("cls"); /// clear screen
        printf("\n-----------------------------------------Input correct values-----------------------------------------\n\n");
        return main();
    }

    endProgram();

}


void flsmType(){

    char temp_store[2];

    printf("\n\n Choose FLSM method using bellow numbers:\n\t\t ~ FLSM with host counts ------------------ 1\n\t\t ~ FLSM with custom IP address ------------ 2\n\n");
    printf(" Select IP FLSM method-----------: ");
    gets(temp_store);

    int temp_val = strtol(temp_store , &temp_pointer , 10);

    if(*temp_pointer == '\0' && temp_val ==1){

        loading(0); /// mode 0 flsm with host
        flsmHost();

    }else if(*temp_pointer == '\0' && temp_val == 2){

        loading(1); /// mode 1 flsm with ip
        flsmIP(); /// call flsmIP function in flsm_with_ip.c file

    }else{
        system("cls");
        printf("\n-----------------------------------------Input correct values-----------------------------------------\n");
        return flsmType();
    }

}

void loading(int mode){

    system("cls");
    system("COLOR A"); /// A = green

    for(int i =1; i <51; i++){
        time_t start_time = clock();

        while(clock() < start_time + 50){}

        int val = i%5;
        switch (val){
        case 4:
            printf("\t\t\t\t\t\tLoading.     %d%c" , i*2 , '%');
            break;
        case 3:
            printf("\t\t\t\t\t\tLoading..    %d%c" , i*2 , '%');
            break;
        case 2:
            printf("\t\t\t\t\t\tLoading...   %d%c" , i*2 , '%');
            break;
        case 1:
            printf("\t\t\t\t\t\tLoading....  %d%c" , i*2 , '%');
            break;
        default:
            printf("\t\t\t\t\t\tLoading..... %d%c" , i*2 , '%');
        }
        printf("\r");
    }

    switch (mode){
    case 0:
        printf("************************************* FLSM with host mode started ************************************");
        break;
    case 1:
        printf("************************************** FLSM with IP mode started *************************************");
        break;
    default:
        printf("***************************************** VLSM mode started ******************************************");

    }

    system("COLOR 7"); /// default white
    printf("\n\n");

}

void endProgram(){

    printf("\n***************************************** Program terminated *****************************************\n\n");
    getchar(); /// for stay console

}
