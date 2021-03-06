                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 #include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

char *temp_save;
int filled = 0;
bool gotoNextOctet = false;

struct ipBlocksSet{
    int netAdd[4];
    int subNetMask[4];
    int firstAdd[4];
    int lastAdd[4];
    int broadCast[4];

}ips;

/** function prototypes area start */

int getHostCount(int);
void setAddress(int , char);
void octetSet(char);

/** function prototypes area end */

void vlsm(){

    char temp_store[4];
    int totalHosts=0;
    int lastHostCount = 8388608; /// 2 to the power 24
    int netBits;
    int hostBit;
    char temp_class;

    printf(" Enter subnets count that you need---------------: ");
    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > 256){
        printf("\n--------------------------------------Input correct subnet count--------------------------------------\n");
        printf("\t\t\t\tMinimum : 2 subnets\n\t\t\t\tMaximum : 256 subnets\n\n");
        return vlsm();
    }

    int blocks[temp_count];/// get temp_count value as array length

    printf("\n-------------------Enter the required host count for each subnet in descending order------------------\n\n");


    for(int i=0; i < temp_count; i++){

        int getReqHost = getHostCount(lastHostCount);
        int hosts = 4;

        for(int k = 2; k<24; k++){
            if(getReqHost <= hosts -2){
                totalHosts += hosts; /// with broadcast and network address
                lastHostCount = hosts;

                if(i==0 && k > 15){
                    netBits = 24 - k;
                    hostBit = 8 - netBits;
                    temp_class = 'A';

                }else if(i==0 && k > 7){
                    netBits = 16 - k;
                    hostBit = 8 - netBits;
                    temp_class = 'B';

                }else if(i==0){
                    netBits = 8 - k;
                    hostBit = k; ///
                    temp_class = 'C';
                }
                break;
            }
            hosts *=2;
        }

        blocks[i] = lastHostCount;///

        if(totalHosts > 8388608 ){
            printf("\n-------------------------------------Total host limit out of range------------------------------------\n");
            totalHosts = 0;
            lastHostCount = 8388608;
            i =0;
        }
    }


    int tmp_val = pow(2.0,(float) netBits);
    if(tmp_val*blocks[0] < totalHosts){

        if(temp_class == 'C'){
            temp_class = 'B';
            ips.broadCast[3]=255;
            hostBit = 0;
        }else{
            temp_class = 'A';
            ips.broadCast[3]=255;
            ips.broadCast[2]=255;
            hostBit = 0;
        }
        netBits = 8;

    }

    printf("\n Class-------------------------------------------: Class %c Ip range\n" , temp_class);

    octetSet(temp_class);/// call octetSet function

    system("cls");

    printf("\n******************************************* Subnet details *******************************************\n\n");
    printf("\n  Network Address \tSubnet Mask \t\tFirst Host \t\tLast Host \t\tBroadcast Address\n\n");
    fileop("\n\t******************************************* Subnet details *******************************************\n"); /// add to file

    switch (temp_class){ /// add ton file
    case 'A':
        fileop("\n Class--------------------------------------: Class A Ip range\n" );
        break;
    case 'B':
        fileop("\n Class--------------------------------------: Class B Ip range\n" );
        break;
    default:
        fileop("\n Class--------------------------------------: Class C Ip range\n" );

    }

    fileop("\n Network Address \tSubnet Mask \t\tFirst Host \t\tLast Host \t\tBroadcast Address\n\n");

    /********************************************** Octet value set section start ****************************************************/

    for( int i = 0; i < temp_count; i++){

    /********************************************************** class C **************************************************************/

        if(temp_class == 'C'){
            ips.netAdd[3] = filled;
            ips.subNetMask[3] = 256 - blocks[i];
            ips.firstAdd[3] = filled + 1;
            ips.lastAdd[3] = filled + blocks[i] -2 ;
            ips.broadCast[3] = filled + blocks[i] -1;

            filled += blocks[i];

    /*********************************************************** class B *************************************************************/

        }else if(temp_class == 'B'){

            int over_bit = blocks[i]/256;

            if(over_bit > 0){

                ips.netAdd[3] = 0;
                ips.firstAdd[3] = 1;
                ips.lastAdd[3] = 254 ;
                ips.broadCast[3] = 255;
                ips.subNetMask[3] = 0;

                ips.netAdd[2] = filled;
                ips.subNetMask[2] = 256 - over_bit;
                ips.firstAdd[2] = filled;
                ips.lastAdd[2] = filled + over_bit -1 ;
                ips.broadCast[2] = filled + over_bit -1;

                filled += over_bit;

            }else {

                if(ips.broadCast[3]==255){
                    ips.netAdd[3] = 0;
                    ips.firstAdd[3] = 1;
                    ips.lastAdd[3] = blocks[i] -2 ;
                    ips.broadCast[3] = blocks[i] -1;

                }else{
                    ips.netAdd[3] = ips.broadCast[3] +1;
                    ips.firstAdd[3] = ips.netAdd[3] + 1;
                    ips.lastAdd[3] = ips.netAdd[3] + blocks[i] - 2 ;
                    ips.broadCast[3] = ips.netAdd[3] + blocks[i] - 1;
                }

                ips.subNetMask[3] = 256 - blocks[i];

                ips.netAdd[2] = filled;
                ips.subNetMask[2] = 255;
                ips.firstAdd[2] = filled;
                ips.lastAdd[2] = filled;
                ips.broadCast[2] = filled;

                if(ips.broadCast[3]==255){ /// if subnets combination fill 256 hosts
                    filled++;
                }
            }

    /********************************************************* class A *****************************************************************/

        }else if(temp_class == 'A'){

            int over_bit_B = blocks[i]/65516;
            int over_bit_C = blocks[i]/256;

            if(over_bit_B > 0){

                ips.netAdd[3] = 0;
                ips.firstAdd[3] = 1;
                ips.lastAdd[3] = 254 ;
                ips.broadCast[3] = 255;
                ips.subNetMask[3] = 0;

                ips.netAdd[2] = 0;
                ips.firstAdd[2] = 0;
                ips.lastAdd[2] = 255 ;
                ips.broadCast[2] = 255;
                ips.subNetMask[2] = 0;

                ips.netAdd[1] = filled;
                ips.subNetMask[1] = 256 - over_bit_B;
                ips.firstAdd[1] = filled;
                ips.lastAdd[1] = filled + over_bit_B -1 ;
                ips.broadCast[1] = filled + over_bit_B -1;

                filled += over_bit_B;
                gotoNextOctet = true;

            }else if(over_bit_C > 0){

                if(ips.broadCast[2]==255){
                    ips.netAdd[2] = 0;
                    ips.firstAdd[2] = 0;
                    ips.lastAdd[2] = blocks[i]/256 -1 ;
                    ips.broadCast[2] = blocks[i]/256 -1;

                }else{
                    ips.netAdd[2] = ips.broadCast[2] +1;
                    ips.firstAdd[2] = ips.netAdd[2] ;
                    ips.lastAdd[2] = ips.netAdd[2] + blocks[i]/256 - 1 ;
                    ips.broadCast[2] = ips.netAdd[2] + blocks[i]/256 - 1;
                }

                ips.subNetMask[2] = 256 - blocks[i]/256;

                ips.netAdd[1] = filled;
                ips.subNetMask[1] = 255;
                ips.firstAdd[1] = filled;
                ips.lastAdd[1] = filled;
                ips.broadCast[1] = filled;

                ips.netAdd[3] = 0;
                ips.subNetMask[3] = 0;
                ips.firstAdd[3] = 1;
                ips.lastAdd[3] = 244;

                gotoNextOctet = false;

                if(ips.broadCast[2]==255){ /// if subnets combination fill 256 hosts
                    gotoNextOctet = true;
                    filled++;
                }
            }else {

                if(ips.broadCast[3]==255){
                    ips.netAdd[3] = 0;
                    ips.firstAdd[3] = 1;
                    ips.lastAdd[3] = blocks[i] -2 ;
                    ips.broadCast[3] = blocks[i] -1;

                    if(gotoNextOctet){
                        ips.netAdd[2] = 0;
                        gotoNextOctet = false;
                    }else{
                        ips.netAdd[2] = + ips.broadCast[2] + 1;
                    }

                    ips.subNetMask[2] = 255;

                }else{
                    ips.netAdd[3] = ips.broadCast[3] +1;
                    ips.firstAdd[3] = ips.netAdd[3]+1 ;
                    ips.lastAdd[3] = ips.netAdd[3] + blocks[i] - 2 ;
                    ips.broadCast[3] = ips.netAdd[3] + blocks[i] - 1;
                }

                ips.subNetMask[3] = 256 - blocks[i];

                ips.netAdd[1] = filled;
                ips.subNetMask[1] = 255;
                ips.firstAdd[1] = filled;
                ips.lastAdd[1] = filled;
                ips.broadCast[1] = filled;

                ips.firstAdd[2] = ips.netAdd[2];
                ips.lastAdd[2] = ips.netAdd[2];
                ips.broadCast[2] = ips.netAdd[2];

                if(ips.netAdd[2] == 255 && ips.broadCast[3] == 255){
                    ips.netAdd[2] = 0;
                    filled++;
                }
            }
        }

    /********************************************** Octet value set section end ****************************************************/

        setAddress(i , temp_class ); /// call setAddress function
    }

    fileop("\n\t************************************ Thank you using IP subnetter ************************************");  /// add to file

}

int getHostCount(int lastHostCount){
    char temp_store[8];///

    printf(" Enter host count that you need------------------: ");
    gets(temp_store);
    int temp_count = strtol(temp_store , &temp_save,10);

    if(*temp_save != '\0' || temp_count <2 || temp_count > 8388606){
        printf("\n---------------------------------------Input correct host count---------------------------------------\n");
        printf("\t\t\t\tMinimum hosts count : 2 hosts\n\t\t\t\tMaximum hosts count : 8 388 606 hosts\n\n");
        return getHostCount(lastHostCount);

    }else if(lastHostCount < temp_count){
        printf("\n---------------------------------------Input value less than %d---------------------------------------\n",lastHostCount);
        return getHostCount(lastHostCount);
    }

    return temp_count;
}

void setAddress(int index , char ipclass){

    if(ipclass == 'C'){

        printf("  %d.%d.%d.%d     \t", ips.netAdd[0], ips.netAdd[1], ips.netAdd[2] , ips.netAdd[3]);
        printf("255.255.255.%d \t" , ips.subNetMask[3]);
        printf("%d.%d.%d.%d       \t", ips.firstAdd[0] , ips.firstAdd[1] , ips.firstAdd[2] , ips.firstAdd[3]);
        printf("%d.%d.%d.%d       \t", ips.lastAdd[0], ips.lastAdd[1] , ips.lastAdd[2] , ips.lastAdd[3]);
        printf("%d.%d.%d.%d\n", ips.broadCast[0] , ips.broadCast[1], ips.broadCast[2],ips.broadCast[3]);

        fileDataStore(2);

    }else if(ipclass == 'B'){

        printf("  %d.%d.%d.%d     \t", ips.netAdd[0], ips.netAdd[1] , ips.netAdd[2], ips.netAdd[3]);
        printf("255.255.%d.%d     \t" , ips.subNetMask[2] , ips.subNetMask[3]);
        printf("%d.%d.%d.%d       \t", ips.firstAdd[0] , ips.firstAdd[1], ips.firstAdd[2] , ips.firstAdd[3]);
        printf("%d.%d.%d.%d       \t", ips.lastAdd[0] , ips.lastAdd[1], ips.lastAdd[2] , ips.lastAdd[3]);
        printf("%d.%d.%d.%d\n", ips.broadCast[0],ips.broadCast[1] ,ips.broadCast[2],ips.broadCast[3]);

        fileDataStore(1);

    }else{

        printf("  %d.%d.%d.%d      \t", ips.netAdd[0] , ips.netAdd[1] , ips.netAdd[2], ips.netAdd[3]);
        printf("255.%d.%d.%d      \t" , ips.subNetMask[1]  , ips.subNetMask[2] , ips.subNetMask[3]);
        printf("%d.%d.%d.%d        \t", ips.firstAdd[0] , ips.firstAdd[1] , ips.firstAdd[2] , ips.firstAdd[3]);
        printf("%d.%d.%d.%d        \t", ips.lastAdd[0], ips.lastAdd[1], ips.lastAdd[2] , ips.lastAdd[3]);
        printf("%d.%d.%d.%d\n", ips.broadCast[0] , ips.broadCast[1] ,ips.broadCast[2],ips.broadCast[3]);

        fileDataStore(0);

    }
}

void octetSet(char classVal){
    char temp_result[10];
    printf(" Do you need private IP range? (Y/N)-------------: ");
    gets(temp_result);

    if((temp_result[0] == 'y' || temp_result[0] == 'Y') && temp_result[1] == '\0'){

        switch (classVal){
        case 'A':
            ips.broadCast[0] = ips.firstAdd[0] = ips.lastAdd[0] = ips.netAdd[0] = 10;
            break;

        case 'B':
            ips.broadCast[0] = ips.firstAdd[0] = ips.lastAdd[0] = ips.netAdd[0] = 172;
            ips.broadCast[1] = ips.firstAdd[1] = ips.lastAdd[1] = ips.netAdd[1] =  (rand()%16) + 16;
            break;

        default:
            ips.broadCast[0] = ips.firstAdd[0] = ips.lastAdd[0] = ips.netAdd[0] = 192;
            ips.broadCast[1] = ips.firstAdd[1] = ips.lastAdd[1] = ips.netAdd[1] = 168;
            ips.broadCast[2] = ips.firstAdd[2] = ips.lastAdd[2] = ips.netAdd[2] =  rand()%256;
        }

    }else if((temp_result[0] == 'n' || temp_result[0] == 'N') && temp_result[1] == '\0'){

        switch (classVal){
        case 'A':
            ips.broadCast[0] = ips.firstAdd[0] = ips.lastAdd[0] = ips.netAdd[0] = rand()%126 + 1; /// get random number greater than or equal 0
            break;

        case 'B':
            ips.broadCast[0] = ips.firstAdd[0] = ips.lastAdd[0] = ips.netAdd[0] = 128 + rand()%64;
            ips.broadCast[1] = ips.firstAdd[1] = ips.lastAdd[1] = ips.netAdd[1] =  rand()%256;
            break;

        default:
            ips.broadCast[0] = ips.firstAdd[0] = ips.lastAdd[0] = ips.netAdd[0] = 192 + rand()%32;
            ips.broadCast[1] = ips.firstAdd[1] = ips.lastAdd[1] = ips.netAdd[1] =  rand()%256;
            ips.broadCast[2] = ips.firstAdd[2] = ips.lastAdd[2] = ips.netAdd[2] =  rand()%256;
        }

    }else{
        printf("\n-----------------------------------------Input correct values-----------------------------------------\n\n");
        return askPrivet();
    }
}

/**************************************** file data generate area start **********************************************/

void fileDataStore(int index){

    char sbMskC[] = "255.255.255.";
    char sbMskB[] = "255.255.";
    char sbMskA[] = "255.";
    char retStr[85] = " ";
    char tmp[4];
    char dot[] =".";
    char endIp[] = "\n";
    char tab[] = "\t\t";


    for(int i = 0; i<4; i++){  /// network address for all classes
        itoa(ips.netAdd[i],tmp,10);
        strcat(retStr,tmp);
        if(i == 3){
            strcat(retStr ,tab);
        }else{
            strcat(retStr ,dot);
        }
    }

    switch (index){ /// subnet mask
    case 0: /// class A
        strcat(retStr ,sbMskA);
        for(int i = 1; i<4; i++){
            itoa(ips.subNetMask[i],tmp,10);
            strcat(retStr,tmp);
            if(i == 3){
                strcat(retStr ,tab);
            }else{
                strcat(retStr ,dot);
            }
        }
        break;

    case 1: /// class B
        strcat(retStr ,sbMskB);
        for(int i = 2; i<4; i++){
            itoa(ips.subNetMask[i],tmp,10);
            strcat(retStr,tmp);
            if(i == 3){
                strcat(retStr ,tab);
            }else{
                strcat(retStr ,dot);
            }
        }
        break;

    default: /// class C
        strcat(retStr ,sbMskC);
        itoa(ips.subNetMask[3],tmp,10);
        strcat(retStr,tmp);
        strcat(retStr ,tab);
    }

    for(int i = 0; i<4; i++){ /// first address for all classes
        itoa(ips.firstAdd[i],tmp,10);
        strcat(retStr,tmp);
        if(i == 3){
            strcat(retStr ,tab);
        }else{
            strcat(retStr ,dot);
        }
    }

    for(int i = 0; i<4; i++){ /// last address for all classes
        itoa(ips.lastAdd[i],tmp,10);
        strcat(retStr,tmp);
        if(i == 3){
            strcat(retStr ,tab);
        }else{
            strcat(retStr ,dot);
        }
    }

    for(int i = 0; i<4; i++){ /// broadcast address for all classes
        itoa(ips.broadCast[i],tmp,10);
        strcat(retStr,tmp);
        if(i == 3){
            strcat(retStr ,tab);
        }else{
            strcat(retStr ,dot);
        }
    }

    strcat(retStr,endIp);
    fileop(retStr);
}

/**************************************** file data generate area end **********************************************/

