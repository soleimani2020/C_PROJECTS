/******************************************************************************
  Simulation of an Enigma-like encryption and decryption machine.
  Features:
  - Reads the whole alphabet.
  - User selects between encryption and decryption.
  - Takes a key from the user for the shift operation.
  - Reads an initial message from a file.
  - Outputs the encrypted/decrypted message to another file.


*******************************************************************************/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void Encryption(char *inputFile, char *outputFile, int key){

    FILE *fh;
    FILE *fh2;

    fh = fopen(inputFile,"r");
    fh2 = fopen(outputFile,"w");
    if (fh == NULL){
        printf("The file does not exist!\n");
        return;
    }


    char ch;
    while((ch=fgetc(fh))!=EOF){

        fputc(ch+key,fh2);

    }

    fclose(fh);
    fclose(fh2);

    printf("The file is now encrypted successfully !\n");

}


void Decryption(char *inputFile,char *outputFile, int key){

    FILE *fh;
    FILE *fh2;

    fh = fopen(inputFile,"r");
    fh2 = fopen(outputFile,"w");
    if (fh == NULL){
        printf("The Original file does not exist!\n");
        return;
    }



    char ch;
    while((ch=fgetc(fh2))!=EOF){

        fputc(ch-key,fh2);

    }

    fclose(fh);
    fclose(fh2);

    printf("The file is now decrypted successfully !\n");

}





int main()
{

    printf("Welcome to the Enigma Machine Simulator!\n\n");


    printf("Please choose the operation you need:\n");
    printf("1: Encryption\n");
    printf("2: Decryption\n");






    // Input and output file names
    char inputFile[100] , outputFile[100];
    printf("\nEnter the name of the input file: ");
    scanf("%s",inputFile);
    printf("Enter the name of the output file: ");
    scanf("%s",outputFile);


    // Key for the operation
    printf("\nPlease enter the shift key (integer value): ");
    int key;
    scanf("%d",&key);



    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);

    if ( choice == 1 ){
        Encryption(inputFile,outputFile, key);
    }

    else if ( choice == 2 ) {
        Decryption(inputFile,outputFile, key);
    }

    else {

        printf("The choice is not valid!\n");
        return 0 ;
    }





return 0;


}







