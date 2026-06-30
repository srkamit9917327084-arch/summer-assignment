#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addProduct() {
    FILE *fp = fopen("inventory.dat", "ab");
    struct Product p;
    printf("Enter Product ID: ");
    scanf("%d", &p.id);
    printf("Enter Product Name: ");
    scanf("%s", p.name);
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Price: ");
    scanf("%f", &p.price);
    
    fwrite(&p, sizeof(struct Product), 1, fp);
    fclose(fp);
    printf("Product added successfully!\n");
}

void viewInventory() {
    FILE *fp = fopen("inventory.dat", "rb");
    struct Product p;
    printf("\nID\tName\tQty\tPrice\n");
    printf("------------------------------\n");
    while(fread(&p, sizeof(struct Product), 1, fp)) {
        printf("%d\t%s\t%d\t%.2f\n", p.id, p.name, p.quantity, p.price);
    }
    fclose(fp);
}

int main() {
    int choice;
    while(1) {
        printf("\n--- Inventory System ---\n1. Add Product\n2. View Inventory\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}