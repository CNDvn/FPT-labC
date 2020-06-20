/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on May 29, 2020, 3:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
void menu() {
    printf("\t\t=============Menu=============\n");
    printf("1. Quadratic equation\n");
    printf("2. Bank deposit problem\n");
    printf("3. Quit\n");
}
//kiem tra dau vao

int checkInput(int s, char c) {
    if (s == 2 && c == '\n') {
        return 1;
    } else {
        return 0;
    }
}
//kiem tra input phuong trinh bac 2

void inputQuadraticEquation() {
    double a, b, c;
    int s, flag;
    char temp;
    printf("Quadratic equations form: ax^2 + bx + c\n");
    //kiem tra co so a khac 0 va khong phai chu
    do {
        flag = 1;
        fpurge(stdin);
        printf("Input a: ");
        s = scanf("%lf%c", &a, &temp);
        s = checkInput(s, temp);
        if (s == 1 && a != 0) {
            flag = 0;
        } else {
            printf("Input wrong: a must different from 0\n");
        }
    } while (flag == 1);
    //kiem tra co so b khong phai chu
    do {
        fpurge(stdin);
        printf("Input b: ");
        s = scanf("%lf%c", &b, &temp);
        s = checkInput(s, temp);

        if (s == 0) {
            printf("Input wrong\n");
        }
    } while (s == 0);
    //kiem tra co so c khong phai chu
    do {
        fpurge(stdin);
        printf("Input c: ");
        s = scanf("%lf%c", &c, &temp);
        s = checkInput(s, temp);

        if (s == 0) {
            printf("Input Wrong\n");
        }
    } while (s == 0);
    QuadraticEquation(a, b, c);
}
//kiem tra input cua lai xuat ngan hang

void inputBankDeposit() {
    int flag = 1;
    char c;
    int s, deposit, month;
    double rate;
    //input deposit va check xem dung yeu cau chua
    do {
        fpurge(stdin);
        printf("Input deposits (a positive number):");
        s = scanf("%d%c", &deposit, &c);
        s = checkInput(s, c);
    } while (s == 0);
    //input rate va check xem dung yeu cau chua
    do {
        fpurge(stdin);
        printf("Deposit interest rates (a positive number <= 0.1): ");
        s = scanf("%lf%c", &rate, &c);
        s = checkInput(s, c);
        if (s == 1 && rate >= 0 && rate <= 1)
            flag = 0;
        else
            printf("Input wrong\n");

    } while (flag == 1);

    //input month va check xem dung yeu cau chua
    do {
        fpurge(stdin);
        printf("Number of deposit months: ");
        s = scanf("%d%c", &month, &c);
        s = checkInput(s, c);

        if (s == 0 || month <= 0)
            printf("Input wrong\n");

    } while (s != 1 || month <= 0);
    bankDeposit(deposit, rate, month);
}
//tinh va out ket qua phuong trinh bac 2

void QuadraticEquation(double a, double b, double c) {
    double dental = b * b - 4 * a*c;

    if (dental < 0) {
        printf("No solution\n");
    } else if (dental == 0) {
        printf("The equation has a double solution: X1 = X2 = %lf", -b / (2 * a));
    } else {
        printf("The equation has solution:\n");
        printf("X1 = %.2lf\n", (-b + sqrt(dental)) / (2 * a));
        printf("X2 = %.2lf\n", (-b - sqrt(dental)) / (2 * a));
    }
}
//tinh va out lai xuat ngan hang

void bankDeposit(int deposit, double rate, int month) {
    printf("Total amount received: %.2f\n", deposit * rate * month);
}

int main(int argc, char** argv) {
    int option;
    char c;
    int s;

    do {
        menu();
        do {
            printf("Select an option: ");
            fpurge(stdin);
            s = scanf("%d%c", &option, &c);
            s = checkInput(s, c);
        } while (s == 0);
        switch (option) {
            case 1: inputQuadraticEquation();
                break;
            case 2: inputBankDeposit();
                break;
            case 3:printf("Bye bye!!\n");
                break;
            default: option = 3;
                printf("Bye bye!!\n");
                break;
        }
    } while (option != 3);
    return (EXIT_SUCCESS);
}

