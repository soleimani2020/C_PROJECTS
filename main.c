/******************************************************************************

library system program: The program manages a library using a Book structure and an array of Books.


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int id;
    char title[100];
    char autor[100];
    int status;

}Book;


int Book_count=0;
Book Books[1000];


void Add(){

    Book data;

    printf("Enter book id:\n");
    scanf("%d",&data.id);

    printf("Enter book title:\n");
    scanf("%s",&data.title);

    printf("Enter book author:\n");
    scanf("%s",&data.autor);

    data.status=0;
    Books[Book_count++]=data;
    printf("Book added sucessfully !\n");
}



void Display() {
    if (Book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("Books in the library:\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < Book_count; i++) {
        printf("Book %d:\n", i + 1);
        printf("  ID: %d\n", Books[i].id);
        printf("  Title: %s\n", Books[i].title);
        printf("  Borrow Status: %s\n", Books[i].Borrow_status ? "Borrowed" : "Available");
        printf("  ---- End of Book ----\n");
    }
}




void Delete() {
    if (Book_count == 0) {
        printf("The library is empty!\n");
        return; // Exit if there are no books
    }

    printf("Enter the book ID to delete: ");
    int book_id;
    scanf("%d", &book_id);

    int found = 0; // Flag to track if the book is found

    for (int i = 0; i < Book_count; i++) {
        if (Books[i].id == book_id) {
            // Shift all elements to the left
            for (int j = i; j < Book_count - 1; j++) {
                Books[j] = Books[j + 1];
            }

            Book_count--; // Decrease the book count
            printf("Book deleted successfully!\n");
            found = 1; // Mark as found
            break; // Exit the loop after deletion
        }
    }

    if (!found) {
        printf("No book found with ID %d.\n", book_id);
    }
}




// double check ... Chatgpt

void Borrow() {
    printf("Enter the book ID to borrow: ");
    int book_id;
    scanf("%d", &book_id);
    for (int i = 0; i < Book_count; i++) {
        if (Books[i].id == book_id) {
            if (Books[i].status == 1) {
                printf("Book is already borrowed.\n");
                return;
            }
            Books[i].status = 1;
            printf("Book borrowed successfully.\n");
            return;
        }
    }
    printf("No book found with ID %d.\n", book_id);
}




void Return() {
    printf("Enter the book ID to return: ");
    int book_id;
    scanf("%d", &book_id);
    for (int i = 0; i < Book_count; i++) {
        if (Books[i].id == book_id) {
            if (Books[i].status == 0) {
                printf("Book is already available.\n");
                return;
            }
            Books[i].status = 0;
            printf("Book returned successfully.\n");
            return;
        }
    }
    printf("No book found with ID %d.\n", book_id);
}





for (int i = 0; i < Book_count; i++) {
    if (Books[i].id == data.id) {
        printf("Book ID already exists!\n");
        return;
    }
}



int main() {
    int choice;

    printf("Welcome to the Library Management System!\n");

    while (1) { // Infinite loop until the user chooses to exit
        printf("\nChoose an operation:\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Delete a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Add a Book ---\n");
                Add();
                break;

            case 2:
                printf("\n--- Display All Books ---\n");
                Display();
                break;

            case 3:
                printf("\n--- Delete a Book ---\n");
                Delete();
                break;

            case 4:
                printf("\nExiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}







