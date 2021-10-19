//12.1 2.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
#define SIZE 20
struct stock {
    char name[SIZE];
    float earn_p_s;
    float price_t_e_r;
}stock1;
void main() {
    int i;
    float stock_price;

    for (i = 0;i < MAX;i++) {
        printf("Type name of stock, its estimated earnings per share, its estimated price-to-earnings ratio:\n");
        scanf("%s", stock1.name);
        scanf("%f", &stock1.earn_p_s);
        scanf("%f", &stock1.price_t_e_r);
        stock_price = stock1.earn_p_s * stock1.price_t_e_r;
        printf("%s ", stock1.name);
        printf("Stock price is $%.2f\n", stock_price);
    }
}