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


void File_Creation(char *inputFile) {
    FILE *fh;
    
    // Try to open the input file in read mode
    fh = fopen(inputFile, "r");
    
    // If the file doesn't exist, we create it
    if (!fh) {
        //printf("\nThe input file does not exist!\n");
        printf("\nLet's create a new file!\n");

        // Open the file in write mode to create it
        fh = fopen(inputFile, "w");
        if (!fh) {
            perror("Error creating the file");
            exit(1);
        }

        // Get the content to write into the file
        char buffer[1000];
        printf("What should be in the file?\n");
        printf("Enter the content (press Enter when done):\n");

        getchar();  // Clear any remaining newline in the input buffer
        fgets(buffer, sizeof(buffer), stdin);  // Get user input
        
        // Write the content to the file
        fprintf(fh, "%s", buffer);
        fclose(fh);

        // Reopen the file in read mode
        fh = fopen(inputFile, "r");
        if (!fh) {
            perror("Error reopening the file");
            exit(1);
        }

        // Display the content of the newly created file
        printf("\nDisplaying the content of the newly created file:\n");
        char line[1000];
        while (fgets(line, sizeof(line), fh)) {
            printf("%s", line);
        }
        fclose(fh);
    } else {
        // The file already exists
        printf("The file already exists. Here are its contents:\n");
        char line[1000];
        // Read and display the file content
        while (fgets(line, sizeof(line), fh)) {
            printf("%s", line);
        }
        fclose(fh);
    }
}




void Encryption(char *inputFile, char *outputFile, int key){
    
    FILE *fh;
    FILE *fh2;
    
    fh = fopen(inputFile,"r");
    
    
    // Check if input file exists
    if (!fh)
    {
        printf("The input file does not exist!\n");
        // If not, create the file
        File_Creation(inputFile);
        
        // Open the newly created file to encrypt it
        fh = fopen(inputFile, "r");
        if (!fh){
            perror("Error reopening the file");
            exit(1);
        }
        
    }
    
    // Open output file in write mode
    fh2 = fopen(outputFile,"w");
    if (!fh2) {
        perror("Error opening the output file");
        exit(1);
    }
    
    // Perform encryption by shifting each character
    
    char ch;
    while((ch=fgetc(fh))!=EOF){
        fputc(ch+key,fh2);  
    }
    
    
    fclose(fh);
    fclose(fh2);
    printf("The file is now encrypted successfully !\n");

}
    


void Decryption(char *inputFile, char *outputFile, int key) {
    FILE *fh;
    FILE *fh2;
    
    fh = fopen(inputFile, "r");
    
    // If the file does not exist, print an error and create it
    if (!fh) {
        printf("The input file does not exist!\n");
        File_Creation(inputFile);
        
        // Reopen the newly created file for decryption
        fh = fopen(inputFile, "r");
        if (!fh) {
            perror("Error reopening the input file after creation");
            exit(1);
        }
    }

    // Open the output file in write mode
    fh2 = fopen(outputFile, "w");
    if (!fh2) {
        perror("Error opening the output file for writing");
        fclose(fh);
        exit(1);
    }

    // Perform decryption by shifting each character backwards by the key
    char ch;
    while ((ch = fgetc(fh)) != EOF) {
        fputc(ch - key, fh2);  // Subtract the key to decrypt
    }
    
    fclose(fh);
    fclose(fh2);
    
    printf("The file has been decrypted successfully!\n");
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




// getchar(); // Clear any remaining newline (\n) in the input buffer
//It continues reading until:
//It reads one less than the specified n characters.
//It encounters a newline character (\n), which is included in the output.
//It reaches the end of the file (EOF).
//fgets() automatically adds a null terminator (\0) at the end of the string.
// fgets(buffer,sizeof(buffer),stdin); 



