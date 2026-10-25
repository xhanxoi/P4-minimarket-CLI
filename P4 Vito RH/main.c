#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int price;
    int stock;
} Product;

typedef struct {
    char name[50];
    int points;
} Member;


// Display products
void checkProduct(Product db[], int size) {
    printf("\n--- Product Catalog ---\n");

    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rp%d (Stock: %d)\n",
               i + 1,
               db[i].name,
               db[i].price,
               db[i].stock);
    }
}


// Display members
void checkMember(Member db[], int size) {
    printf("\n--- Member Data ---\n");

    for (int i = 0; i < size; i++) {
        printf("%d. %s - Points: %d\n",
               i + 1,
               db[i].name,
               db[i].points);
    }
}


// Challenge 1: Update Product Price
void updatePrice(Product *p, int newPrice) {
    p->price = newPrice;
}


// Transaction + Challenge 3
void buyProduct(Product *p, Member *m, int qty) {

    if (p->stock >= qty) {

        int total = p->price * qty;

        // Challenge 3: Redeem points
        if (m != NULL && m->points >= 1000) {
            total = total * 90 / 100;
            m->points -= 1000;

            printf("\n[DISCOUNT] 10%% discount applied!\n");
        }

        p->stock -= qty;

        printf("[TRANSACTION] Bought %d %s\n",
               qty, p->name);

        printf("Total: Rp%d\n", total);

        // Add points
        if (m != NULL && total >= 20000) {
            m->points += 100;

            printf("%s earned +100 points!\n",
                   m->name);
        }

    } else {
        printf("\n[FAILED] Not enough stock for %s!\n",
               p->name);
    }
}


int main() {

    Product dbProduct[5] = {
        {"Soap", 5000, 10},
        {"Shampoo", 15000, 5},
        {"Bread", 12000, 8},
        {"Milk", 25000, 15},
        {"Coffee", 22000, 20}
    };

    Member dbMember[2] = {
        {"Anisa", 1200},
        {"Budi", 500}
    };


    printf("=== INITIAL DATA ===\n");

    checkProduct(dbProduct, 5);
    checkMember(dbMember, 2);


    // CHALLENGE 1
    printf("\n=== UPDATE PRICE ===\n");

    updatePrice(&dbProduct[0], 7000);

    printf("Soap price changed to Rp7000\n");

    checkProduct(dbProduct, 5);


    // CHALLENGE 3
    printf("\n=== MEMBER TRANSACTION ===\n");

    buyProduct(
        &dbProduct[3],
        &dbMember[0],
        2
    );


    printf("\n=== FINAL DATA ===\n");

    checkProduct(dbProduct, 5);
    checkMember(dbMember, 2);


    return 0;
}