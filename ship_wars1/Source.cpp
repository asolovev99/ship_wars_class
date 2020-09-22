#define _CRT_SECURE_NO_WARNINGS // ����
#include <iostream>
#include <math.h>
#include "windows.h"
#include <time.h>

class Cell // ������ ����
{
    int info; // 0 - ���������� ������ ��� �������, 1 - ���������� ������ � �������, 2 - �������� ������ ��� �������, 3 - �������� ������ � �������, 4 - ������, �� ������� ������ ������� ������� (= 0..9)
    int number_of_ship; // ������ ������� (-1 - ������� ���, 0..9 - ������� ������, 10..19 - ������� ���������� (�� 10..19 ����� ������ 10, ����� �������� ������))
public:
    Cell() // �����������
    {
        info = 0;
        number_of_ship = -1;
    }
    /*cell(int in_info, int in_number_of_ship)
    {
        info = in_info;
        number_of_ship = in_number_of_ship;
    }*/
    int get_info()
    {
        return info;
    }
    int get_number_of_ship()
    {
        return number_of_ship;
    }
    void change_info(int in_info)
    {
        info = in_info;
    }
    void change_number_of_ship(int in_number_of_ship)
    {
        number_of_ship = in_number_of_ship;
    }
};

class Field // ������� ����
{
    Cell cell_of_field[10][10]; // ������� ���� 10�10 ������
public:
    Field() // ����������� (������, ��� ��� ����������� Cell �������� ������ ����)
    {

    }
    void change_info_cell(int x, int y, int in_info) // �������� info � ������ � ��������� x � y ��������������
    {
        cell_of_field[x][y].change_info(in_info);
    }
    void change_number_of_ship_cell(int x, int y, int in_number_of_ship) // �������� number_of_ship � ������ � ��������� x � y ��������������
    {
        cell_of_field[x][y].change_number_of_ship(in_number_of_ship);
    }
    int get_info_cell(int x, int y) // ���������� �������� info ������ � ��������� x � y
    {
        return cell_of_field[x][y].get_info();
    }
    int get_number_of_ship_cell(int x, int y) // ���������� �������� number_of_ship ������ � ��������� x � y
    {
        return cell_of_field[x][y].get_number_of_ship();
    }
    /*field()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cell_of_field[i][j]
            }
        }
    }*/
};

class Ship { // �������
    bool alive; // true - ������� ���, false - ������� ��������
public:
    Ship()  // �����������
    {
        alive = true;
    }
    void dead() // ������ ��������� ������� �� �����������
    {
        alive = false;
    }
    bool check_alive() // 
    {
        return alive;
    }
};

struct pole {
    int info;
    int num_of_ship;
};

struct ship {
    int x;
    int y;
};

void graphic_develop_class(Field in_player, Field in_computer) {
    int i, j;
    printf("\n\n");
    printf(" ���������                   �����\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", in_computer.get_info_cell(j, i) + 100/*pole_ai[j][i].info*/);
        }
        printf("    ");
        for (j = 0; j < 10; j++) {
            printf("%c ", in_player.get_info_cell(j, i) + 100/*pole_player[j][i].info*/);
        }
        printf("\n");
    }
    printf("\n\n");
}

void graphic_develop_class_2(Field in_player, Field in_computer) {
    int x, y;
    printf("\n");
    printf("     ���������                    �����\n");
    for (x = 1; x <= 47; x++) printf("-");
    printf("\n");
    for (y = -1; y <= 9; y++) {
        if (y != -1) {
            printf("%i", y); // ���������� �� ��� �
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|"); // ������� ����� �������� �� �����������
                else {
                    switch (in_computer.get_info_cell((x - 2) / 2, y)/*pole_ai[(x - 2) / 2][y].info*/) { // ������
                    case -1: 
                    {
                        printf("#");
                        break;
                    }
                    case 0: { // ���������� ��� �������
                        printf(" ");
                        break;
                    }
                    case 1: { // ���������� � �������
                        printf("*");
                        break;
                    }
                    case 2: { // ������ ������
                        printf("0");
                        break;
                    }
                    case 3: { // ������ � �������
                        printf("1");
                        break;
                    }
                    case 4:
                    {
                        printf(" ");
                        break;
                    }
                    default: { // ���������� ������
                        printf(" "); // & or SPACE
                        break;
                    }
                    }
                }
            }



            printf(" | ");
            printf("%i", y); // ���������� �� ��� �
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|"); // ������� ����� �������� �� �����������
                else {
                    switch (in_computer.get_info_cell((x - 2) / 2, y)/*pole_player[(x - 2) / 2][y].info*/) { // ������
                    case -1:
                    {
                        printf("#");
                        break;
                    }
                    case 0: { // ���������� ��� �������
                        printf(" ");
                        break;
                    }
                    case 1: { // ���������� � �������
                        printf("*");
                        break;
                    }
                    case 2: { // �������� ��� �������
                        printf("0");
                        break;
                    }
                    case 3: { // �������� � �������
                        printf("1");
                        break;
                    }
                    case 4:
                    {
                        printf("+");
                        break;
                    }
                    }
                }
            }




            printf("\n");
            for (x = 1; x <= 22; x++) printf("-"); // ������� ����� �������� �� ���������

            printf(" | ");
            for (x = 1; x <= 22; x++) printf("-"); // ������� ����� �������� �� ���������




        }
        else { // ���������� �� ��� �
            printf(" ");
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|"); // ������� ����� �������� �� �����������
                else {
                    printf("%i", (x - 2) / 2); // ���������� �� ��� �
                }
            }


            printf(" | ");
            printf(" ");
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|");
                else {
                    printf("%i", (x - 2) / 2);
                }
            }



            printf("\n");
            for (x = 1; x <= 22; x++) printf("-");

            printf(" | ");
            for (x = 1; x <= 22; x++) printf("-");




        }
        printf("\n");
    }
}

void place_ships_of_player(Field* in_field, Ship in_ship[10]) // ������� �������� ������
{
    int x_begin, x_end, y_begin, y_end;
    printf("������� ���������� ������ � ����� ��������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
    do
    {
        scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� ���������������
    } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 3)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 3))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)))); // ������� �� �����, ���� ������� ���������� ������������� ��� ����������� � � � � ���������� ������ ���� ������ -1 � ������ 10, ������� ��������������
    for (int i = 0; i <= 3; i++) // ������� �������
    {
        in_field->change_number_of_ship_cell(x_begin + i*((x_end - x_begin) / 3), y_begin + i * ((y_end - y_begin) / 3), 0); // ������� ������ �������
        in_field->change_info_cell(x_begin + i * ((x_end - x_begin) / 3), y_begin + i * ((y_end - y_begin) / 3), 1); // ������� ����� �������
    }
    // ������� ����������� ����� ������ �������
    if (x_begin == x_end) // ������� ����� �����������
    {
        for (int i = -1; i <= 4; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((y_begin + i * ((y_end - y_begin) / 3) <= 9) && (y_begin + i * ((y_end - y_begin) / 3) >= 0))
            {
                if (x_begin + 1 <= 9)
                {
                    in_field->change_info_cell(x_begin + 1, y_begin + i * ((y_end - y_begin) / 3), 4); 
                }
                if (x_begin - 1 >= 0)
                {
                    in_field->change_info_cell(x_begin - 1, y_begin + i * ((y_end - y_begin) / 3), 4);
                }
            }
        }
        // ������� ����� ������ � �����
        if ((y_begin + 4 * ((y_end - y_begin) / 3) >= 0) && (y_begin + 4 * ((y_end - y_begin) / 3) <= 9))
        {
            in_field->change_info_cell(x_begin, y_begin + 4 * ((y_end - y_begin) / 3), 4);
        }
        if ((y_begin - (y_end - y_begin) / 3 >= 0) && (y_begin - (y_end - y_begin) / 3 <= 9))
        {
            in_field->change_info_cell(x_begin, y_begin - (y_end - y_begin) / 3, 4);
        }
    }
    if (y_begin == y_end) // ������� ����� �������������
    {
        for (int i = -1; i <= 4; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((x_begin + i * ((x_end - x_begin) / 3) <= 9) && (x_begin + i * ((x_end - x_begin) / 3) >= 0))
            {
                if (y_begin + 1 <= 9)
                {
                    in_field->change_info_cell(x_begin + i * ((x_end - x_begin) / 3), y_begin + 1, 4);
                }
                if (y_begin - 1 >= 0)
                {
                    in_field->change_info_cell(x_begin + i * ((x_end - x_begin) / 3), y_begin - 1, 4);
                }
            }         
        }
        // ������� ����� ����� � ������
        if ((x_begin + 4 * ((x_end - x_begin) / 3) >= 0) && (x_begin + 4 * ((x_end - x_begin) / 3) <= 9))
        {
            in_field->change_info_cell(x_begin + 4 * ((x_end - x_begin) / 3), y_begin, 4);
        }
        if ((x_begin - (x_end - x_begin) / 3 >= 0) && (x_begin - (x_end - x_begin) / 3 <= 9))
        {
            in_field->change_info_cell(x_begin - (x_end - x_begin) / 3, y_begin, 4);
        }
    }

    graphic_develop_class_2(*in_field, *in_field);
    system("pause");

    /*while (!((((x_begin != x_end) && (y_begin == y_end)) || ((y_begin != y_end) && (x_begin == x_end))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9))))
    {
        scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� ���������������
    }*/
    //scanf("%i%i%i%i", &ship4[0].x, &ship4[0].y, &ship4[3].x, &ship4[3].y); // ���������� ������ � �����
    for (int j = 1; j <= 2; j++)
    {
        switch (j)
        {
        case 1:
            printf("������� ���������� ������ � ����� ������� ������������ �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        case 2:
            printf("������� ���������� ������ � ����� ������� ������������ �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        default:
            printf("������: �������� ������ ������������ � ����� ��� ������������ �� ���� �� ����� 1 ��� 2");
            break;
        }
        do
        {
            scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� ������������
        } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 2)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 2))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4) && (in_field->get_info_cell(x_end, y_end) != 1) && (in_field->get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� �����������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
        for (int i = 0; i <= 2; i++) // ������� �������
        {
            in_field->change_number_of_ship_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin + i * ((y_end - y_begin) / 2), j); // ������� ������ �������
            in_field->change_info_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin + i * ((y_end - y_begin) / 2), 1); // ������� ����� �������
        }
        // ������� ����������� ����� ������ �������
        if (x_begin == x_end) // ������� ����� �����������
        {
            for (int i = -1; i <= 3; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((y_begin + i * ((y_end - y_begin) / 2) <= 9) && (y_begin + i * ((y_end - y_begin) / 2) >= 0))
                {
                    if (x_begin + 1 <= 9)
                    {
                        in_field->change_info_cell(x_begin + 1, y_begin + i * ((y_end - y_begin) / 2), 4);
                    }
                    if (x_begin - 1 >= 0)
                    {
                        in_field->change_info_cell(x_begin - 1, y_begin + i * ((y_end - y_begin) / 2), 4);
                    }
                }
            }
            // ������� ����� ������ � �����
            if ((y_begin + 3 * ((y_end - y_begin) / 2) >= 0) && (y_begin + 3 * ((y_end - y_begin) / 2) <= 9))
            {
                in_field->change_info_cell(x_begin, y_begin + 3 * ((y_end - y_begin) / 2), 4);
            }
            if ((y_begin - (y_end - y_begin) / 2 >= 0) && (y_begin - (y_end - y_begin) / 2 <= 9))
            {
                in_field->change_info_cell(x_begin, y_begin - (y_end - y_begin) / 2, 4);
            }
        }
        if (y_begin == y_end) // ������� ����� �������������
        {
            for (int i = -1; i <= 3; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((x_begin + i * ((x_end - x_begin) / 2) <= 9) && (x_begin + i * ((x_end - x_begin) / 2) >= 0))
                {
                    if (y_begin + 1 <= 9)
                    {
                        in_field->change_info_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin + 1, 4);
                    }
                    if (y_begin - 1 >= 0)
                    {
                        in_field->change_info_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin - 1, 4);
                    }
                }
            }
            // ������� ����� ����� � ������
            if ((x_begin + 3 * ((x_end - x_begin) / 2) >= 0) && (x_begin + 3 * ((x_end - x_begin) / 2) <= 9))
            {
                in_field->change_info_cell(x_begin + 3 * ((x_end - x_begin) / 2), y_begin, 4);
            }
            if ((x_begin - (x_end - x_begin) / 2 >= 0) && (x_begin - (x_end - x_begin) / 2 <= 9))
            {
                in_field->change_info_cell(x_begin - (x_end - x_begin) / 2, y_begin, 4);
            }
        }
    }
    

    graphic_develop_class_2(*in_field, *in_field);
    system("pause");

    
    
    /*printf("������� ���������� ������ � ����� ������� ������������ �� ��� X � ��� Y (�� 0 �� 9)\n");
    do
    {
        scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� ������������
    } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 2)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 2))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4) && (in_field.get_info_cell(x_end, y_end) != 1) && (in_field.get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� �����������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
    for (int i = 0; i <= 2; i++) // ������� �������
    {
        in_field.change_number_of_ship_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin + i * ((y_end - y_begin) / 2), 2); // ������� ������ �������
        in_field.change_info_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin + i * ((y_end - y_begin) / 2), 1); // ������� ����� �������
    }
    // ������� ����������� ����� ������ �������
    if (x_begin == x_end) // ������� ����� �����������
    {
        for (int i = -1; i <= 3; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((y_begin + i * ((y_end - y_begin) / 2) <= 9) && (y_begin + i * ((y_end - y_begin) / 2) >= 0))
            {
                if (x_begin + 1 <= 9)
                {
                    in_field.change_info_cell(x_begin + 1, y_begin + i * ((y_end - y_begin) / 2), 4);
                }
                if (x_begin - 1 >= 0)
                {
                    in_field.change_info_cell(x_begin - 1, y_begin + i * ((y_end - y_begin) / 2), 4);
                }
            }
        }
        // ������� ����� ������ � �����
        if ((y_begin + 3 * ((y_end - y_begin) / 2) >= 0) && (y_begin + 3 * ((y_end - y_begin) / 2) <= 9))
        {
            in_field.change_info_cell(x_begin, y_begin + 3 * ((y_end - y_begin) / 2), 4);
        }
        if ((y_begin - (y_end - y_begin) / 2 >= 0) && (y_begin - (y_end - y_begin) / 2 <= 9))
        {
            in_field.change_info_cell(x_begin, y_begin - (y_end - y_begin) / 2, 4);
        }
    }
    if (y_begin == y_end) // ������� ����� �������������
    {
        for (int i = -1; i <= 3; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((x_begin + i * ((x_end - x_begin) / 2) <= 9) && (x_begin + i * ((x_end - x_begin) / 2) >= 0))
            {
                if (y_begin + 1 <= 9)
                {
                    in_field.change_info_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin + 1, 4);
                }
                if (y_begin - 1 >= 0)
                {
                    in_field.change_info_cell(x_begin + i * ((x_end - x_begin) / 2), y_begin - 1, 4);
                }
            }
        }
        // ������� ����� ����� � ������
        if ((x_begin + 3 * ((x_end - x_begin) / 2) >= 0) && (x_begin + 3 * ((x_end - x_begin) / 2) <= 9))
        {
            in_field.change_info_cell(x_begin + 3 * ((x_end - x_begin) / 2), y_begin, 4);
        }
        if ((x_begin - (x_end - x_begin) / 2 >= 0) && (x_begin - (x_end - x_begin) / 2 <= 9))
        {
            in_field.change_info_cell(x_begin - (x_end - x_begin) / 2, y_begin, 4);
        }
    }
    */
    for (int j = 3; j <= 5; j++)
    {
        switch (j)
        {
        case 3:
            printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        case 4:
            printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        case 5:
            printf("������� ���������� ������ � ����� �������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        default:
            printf("������: �������� ������ ������������� � ����� ��� ������������ �� ���� �� ����� 6-9");
            break;
        }
        do
        {
            scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� �������������
        } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 1)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 1))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4) && (in_field->get_info_cell(x_end, y_end) != 1) && (in_field->get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� ������������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
        for (int i = 0; i <= 1; i++) // ������� �������
        {
            in_field->change_number_of_ship_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), j); // ������� ������ �������
            in_field->change_info_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 1); // ������� ����� �������
        }
        // ������� ����������� ����� ������ �������
        if (x_begin == x_end) // ������� ����� �����������
        {
            for (int i = -1; i <= 2; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((y_begin + i * (y_end - y_begin) <= 9) && (y_begin + i * (y_end - y_begin) >= 0))
                {
                    if (x_begin + 1 <= 9)
                    {
                        in_field->change_info_cell(x_begin + 1, y_begin + i * (y_end - y_begin), 4);
                    }
                    if (x_begin - 1 >= 0)
                    {
                        in_field->change_info_cell(x_begin - 1, y_begin + i * (y_end - y_begin), 4);
                    }
                }
            }
            // ������� ����� ������ � �����
            if ((y_begin + 2 * (y_end - y_begin) >= 0) && (y_begin + 2 * (y_end - y_begin) <= 9))
            {
                in_field->change_info_cell(x_begin, y_begin + 2 * (y_end - y_begin), 4);
            }
            if ((y_begin - (y_end - y_begin) >= 0) && (y_begin - (y_end - y_begin) <= 9))
            {
                in_field->change_info_cell(x_begin, y_begin - (y_end - y_begin), 4);
            }
        }
        if (y_begin == y_end) // ������� ����� �������������
        {
            for (int i = -1; i <= 2; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((x_begin + i * (x_end - x_begin) <= 9) && (x_begin + i * (x_end - x_begin) >= 0))
                {
                    if (y_begin + 1 <= 9)
                    {
                        in_field->change_info_cell(x_begin + i * (x_end - x_begin), y_begin + 1, 4);
                    }
                    if (y_begin - 1 >= 0)
                    {
                        in_field->change_info_cell(x_begin + i * (x_end - x_begin), y_begin - 1, 4);
                    }
                }
            }
            // ������� ����� ����� � ������
            if ((x_begin + 2 * (x_end - x_begin) >= 0) && (x_begin + 2 * (x_end - x_begin) <= 9))
            {
                in_field->change_info_cell(x_begin + 2 * (x_end - x_begin), y_begin, 4);
            }
            if ((x_begin - (x_end - x_begin) >= 0) && (x_begin - (x_end - x_begin) <= 9))
            {
                in_field->change_info_cell(x_begin - (x_end - x_begin), y_begin, 4);
            }
        }
    }   
    

    graphic_develop_class_2(*in_field, *in_field);
    system("pause");

    /*printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
    do
    {
        scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� �������������
    } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 1)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 1))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4) && (in_field.get_info_cell(x_end, y_end) != 1) && (in_field.get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� ������������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
    for (int i = 0; i <= 1; i++) // ������� �������
    {
        in_field.change_number_of_ship_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 4); // ������� ������ �������
        in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 1); // ������� ����� �������
    }
    // ������� ����������� ����� ������ �������
    if (x_begin == x_end) // ������� ����� �����������
    {
        for (int i = -1; i <= 2; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((y_begin + i * (y_end - y_begin) <= 9) && (y_begin + i * (y_end - y_begin) >= 0))
            {
                if (x_begin + 1 <= 9)
                {
                    in_field.change_info_cell(x_begin + 1, y_begin + i * (y_end - y_begin), 4);
                }
                if (x_begin - 1 >= 0)
                {
                    in_field.change_info_cell(x_begin - 1, y_begin + i * (y_end - y_begin), 4);
                }
            }
        }
        // ������� ����� ������ � �����
        if ((y_begin + 2 * (y_end - y_begin) >= 0) && (y_begin + 2 * (y_end - y_begin) <= 9))
        {
            in_field.change_info_cell(x_begin, y_begin + 2 * (y_end - y_begin), 4);
        }
        if ((y_begin - (y_end - y_begin) >= 0) && (y_begin - (y_end - y_begin) <= 9))
        {
            in_field.change_info_cell(x_begin, y_begin - (y_end - y_begin), 4);
        }
    }
    if (y_begin == y_end) // ������� ����� �������������
    {
        for (int i = -1; i <= 2; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((x_begin + i * (x_end - x_begin) <= 9) && (x_begin + i * (x_end - x_begin) >= 0))
            {
                if (y_begin + 1 <= 9)
                {
                    in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + 1, 4);
                }
                if (y_begin - 1 >= 0)
                {
                    in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin - 1, 4);
                }
            }
        }
        // ������� ����� ����� � ������
        if ((x_begin + 2 * (x_end - x_begin) >= 0) && (x_begin + 2 * (x_end - x_begin) <= 9))
        {
            in_field.change_info_cell(x_begin + 2 * (x_end - x_begin), y_begin, 4);
        }
        if ((x_begin - (x_end - x_begin) >= 0) && (x_begin - (x_end - x_begin) <= 9))
        {
            in_field.change_info_cell(x_begin - (x_end - x_begin), y_begin, 4);
        }
    }


    printf("������� ���������� ������ � ����� �������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
    do
    {
        scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� �������������
    } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 1)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 1))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4) && (in_field.get_info_cell(x_end, y_end) != 1) && (in_field.get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� ������������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
    for (int i = 0; i <= 1; i++) // ������� �������
    {
        in_field.change_number_of_ship_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 5); // ������� ������ �������
        in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 1); // ������� ����� �������
    }
    // ������� ����������� ����� ������ �������
    if (x_begin == x_end) // ������� ����� �����������
    {
        for (int i = -1; i <= 2; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((y_begin + i * (y_end - y_begin) <= 9) && (y_begin + i * (y_end - y_begin) >= 0))
            {
                if (x_begin + 1 <= 9)
                {
                    in_field.change_info_cell(x_begin + 1, y_begin + i * (y_end - y_begin), 4);
                }
                if (x_begin - 1 >= 0)
                {
                    in_field.change_info_cell(x_begin - 1, y_begin + i * (y_end - y_begin), 4);
                }
            }
        }
        // ������� ����� ������ � �����
        if ((y_begin + 2 * (y_end - y_begin) >= 0) && (y_begin + 2 * (y_end - y_begin) <= 9))
        {
            in_field.change_info_cell(x_begin, y_begin + 2 * (y_end - y_begin), 4);
        }
        if ((y_begin - (y_end - y_begin) >= 0) && (y_begin - (y_end - y_begin) <= 9))
        {
            in_field.change_info_cell(x_begin, y_begin - (y_end - y_begin), 4);
        }
    }
    if (y_begin == y_end) // ������� ����� �������������
    {
        for (int i = -1; i <= 2; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((x_begin + i * (x_end - x_begin) <= 9) && (x_begin + i * (x_end - x_begin) >= 0))
            {
                if (y_begin + 1 <= 9)
                {
                    in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + 1, 4);
                }
                if (y_begin - 1 >= 0)
                {
                    in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin - 1, 4);
                }
            }
        }
        // ������� ����� ����� � ������
        if ((x_begin + 2 * (x_end - x_begin) >= 0) && (x_begin + 2 * (x_end - x_begin) <= 9))
        {
            in_field.change_info_cell(x_begin + 2 * (x_end - x_begin), y_begin, 4);
        }
        if ((x_begin - (x_end - x_begin) >= 0) && (x_begin - (x_end - x_begin) <= 9))
        {
            in_field.change_info_cell(x_begin - (x_end - x_begin), y_begin, 4);
        }
    }*/





    for (int j = 6; j <= 9; j++)
    {
        switch (j)
        {
        case 6:
            printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        case 7:
            printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        case 8:
            printf("������� ���������� ������ � ����� �������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        case 9:
            printf("������� ���������� ������ � ����� ��������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
            break;
        default:
            printf("������: �������� ������ ������������� � ����� ��� ������������ �� ���� �� ����� 6-9");
            break;
        }
        do
        {
            scanf("%i%i", &x_begin, &y_begin); // ���������� ������ � ����� �������������
        } while (!(((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && (in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4))); // ������� �� �����, ����  � � � ���������� ������ ���� ������ -1 � ������ 10, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
        // ������� �������
        in_field->change_number_of_ship_cell(x_begin, y_begin, j); // ������� ������ �������
        in_field->change_info_cell(x_begin, y_begin, 1); // ������� ����� �������

        // ������� ����������� ����� ������ �������        
        for (int i = -1; i <= 1; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
        {
            if ((y_begin + i <= 9) && (y_begin + i >= 0))
            {
                if (x_begin + 1 <= 9)
                {
                    in_field->change_info_cell(x_begin + 1, y_begin + i, 4);
                }
                if (x_begin - 1 >= 0)
                {
                    in_field->change_info_cell(x_begin - 1, y_begin + i, 4);
                }
            }
        }
        // ������� ����� ������ � �����
        if (y_begin + 1 <= 9)
        {
            in_field->change_info_cell(x_begin, y_begin + 1, 4);
        }
        if (y_begin - 1 >= 0)
        {
            in_field->change_info_cell(x_begin, y_begin - 1, 4);
        }
    }

    


    graphic_develop_class_2(*in_field, *in_field);
    system("pause");

    
















    /*x_begin = 0;
    y_begin = 0;
    x_end = 0;
    y_end = 0;*/
    /*while (!((((x_begin != x_end) && (y_begin == y_end)) || ((y_begin != y_end) && (x_begin == x_end))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9))))
    {

    }*/

    /*do
    {
        scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� 1-�� ������������
    } while (!((((x_begin != x_end) && (y_begin == y_end)) || ((y_begin != y_end) && (x_begin == x_end))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9))));*/
   // scanf("%i%i%i%i%i%i%i%i", &ship3[0][0].x, &ship3[0][0].y, &ship3[2][0].x, &ship3[2][0].y, &ship3[0][1].x, &ship3[0][1].y, &ship3[2][1].x, &ship3[2][1].y);  // ���������� ������ � �����
    //printf("������� ���������� ������ � ����� ��������������\n");
   // scanf("%i%i%i%i%i%i%i%i%i%i%i%i", &ship2[0][0].x, &ship2[0][0].y, &ship2[1][0].x, &ship2[1][0].y, &ship2[0][1].x, &ship2[0][1].y, &ship2[1][1].x, &ship2[1][1].y, &ship2[0][2].x, &ship2[0][2].y, &ship2[1][2].x, &ship2[1][2].y);  // ���������� ������ � �����
    //printf("������� ���������� ��������������\n");
   // scanf("%i%i%i%i%i%i%i%i", &ship1[0].x, &ship1[0].y, &ship1[1].x, &ship1[1].y, &ship1[2].x, &ship1[2].y, &ship1[3].x, &ship1[3].y);  // ���������� ������ � �����
}

void place_ships_of_computer(Field* in_field, Ship in_ship[10]) // ������� �������� ����������
{









    // ������� �������� ����������
    {
        int x_begin, y_begin;
        //printf("������� ���������� ������ � ����� ��������������� �� ��� X � ��� Y (�� 0 �� 9)\n");        
        // ������� ���������������
        if (rand() % 2 == 1) // ������� ����� �����������
        {
            x_begin = rand() % 10;
            y_begin = rand() % 7;
            for (int i = 0; i <= 3; i++) // ������� �������
            {
                in_field->change_number_of_ship_cell(x_begin, y_begin + i, 0);
                in_field->change_info_cell(x_begin, y_begin + i, 1);
            }
            // ������� ����������� ����� ������ �������
            for (int i = -1; i <= 4; i++) // ������� ����� ����� � ������. ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((y_begin + i <= 9) && (y_begin + i >= 0))
                {
                    if (x_begin + 1 <= 9)
                    {
                        in_field->change_info_cell(x_begin + 1, y_begin + i, 4);
                    }
                    if (x_begin - 1 >= 0)
                    {
                        in_field->change_info_cell(x_begin - 1, y_begin + i, 4);
                    }
                }
            }
            // ������� ����� ������ � �����
            if (y_begin + 4 <= 9)
            {
                in_field->change_info_cell(x_begin, y_begin + 4, 4); // ������� ����� ����� 
            }
            if (y_begin - 1 >= 0)
            {
                in_field->change_info_cell(x_begin, y_begin - 1, 4); // ������� ����� ������
            }
        }
        else // ������� ����� �������������
        {
            x_begin = rand() % 7;
            y_begin = rand() % 10;


            for (int i = 0; i <= 3; i++) // ������� �������
            {
                in_field->change_number_of_ship_cell(x_begin + i, y_begin, 0);
                in_field->change_info_cell(x_begin + i, y_begin, 1);
            }
            // ������� ����������� ����� ������ �������
            for (int i = -1; i <= 4; i++) // ������� ����� ������ � �����. ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((x_begin + i <= 9) && (x_begin + i >= 0))
                {
                    if (y_begin + 1 <= 9)
                    {
                        in_field->change_info_cell(x_begin + i, y_begin + 1, 4); // ������� ����� �����
                    }
                    if (y_begin - 1 >= 0)
                    {
                        in_field->change_info_cell(x_begin + i, y_begin - 1, 4); // ������� ����� ������
                    }
                }
            }
            // ������� ����� ������ � �����
            if (x_begin + 4 <= 9)
            {
                in_field->change_info_cell(x_begin + 4, y_begin, 4); // ������� ����� ������ 
            }
            if (x_begin - 1 >= 0)
            {
                in_field->change_info_cell(x_begin - 1, y_begin, 4); // ������� ����� �����
            }
        }

        graphic_develop_class_2(*in_field, *in_field);    
        system("pause");

        // ������� �������������
        for (int j = 1; j <= 2; j++)
        {
            /*switch (j)
            {
            case 1:
                printf("������� ���������� ������ � ����� ������� ������������ �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            case 2:
                printf("������� ���������� ������ � ����� ������� ������������ �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            default:
                printf("������: �������� ������ ������������ � ����� ��� ������������ �� ���� �� ����� 1 ��� 2");
                break;
            }*/
            if (rand() % 2 == 1) // ������� ����� �����������
            {
                do
                {
                    x_begin = rand() % 10;
                    y_begin = rand() % 8;
                } while (!((in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4) && (in_field->get_info_cell(x_begin, y_begin + 2) != 1) && (in_field->get_info_cell(x_begin, y_begin + 2) != 4)));
                for (int i = 0; i <= 2; i++) // ������� �������
                {
                    in_field->change_number_of_ship_cell(x_begin, y_begin + i, j);
                    in_field->change_info_cell(x_begin, y_begin + i, 1);
                }
                // ������� ����������� ����� ������ �������
                for (int i = -1; i <= 3; i++) // ������� ����� ����� � ������. ����� ��������������!!!!!!!! ��������� �� ������!!!!
                {
                    if ((y_begin + i <= 9) && (y_begin + i >= 0))
                    {
                        if (x_begin + 1 <= 9)
                        {
                            in_field->change_info_cell(x_begin + 1, y_begin + i, 4);
                        }
                        if (x_begin - 1 >= 0)
                        {
                            in_field->change_info_cell(x_begin - 1, y_begin + i, 4);
                        }
                    }
                }
                // ������� ����� ������ � �����
                if (y_begin + 3 <= 9)
                {
                    in_field->change_info_cell(x_begin, y_begin + 3, 4); // ������� ����� ����� 
                }
                if (y_begin - 1 >= 0)
                {
                    in_field->change_info_cell(x_begin, y_begin - 1, 4); // ������� ����� ������
                }
            }
            else // ������� ����� �������������
            {
                do
                {
                    x_begin = rand() % 8;
                    y_begin = rand() % 10;
                } while (!((in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4) && (in_field->get_info_cell(x_begin + 2, y_begin) != 1) && (in_field->get_info_cell(x_begin + 2, y_begin) != 4)));
                for (int i = 0; i <= 2; i++) // ������� �������
                {
                    in_field->change_number_of_ship_cell(x_begin + i, y_begin, j);
                    in_field->change_info_cell(x_begin + i, y_begin, 1);
                }
                // ������� ����������� ����� ������ �������
                for (int i = -1; i <= 3; i++) // ������� ����� ������ � �����. ����� ��������������!!!!!!!! ��������� �� ������!!!!
                {
                    if ((x_begin + i <= 9) && (x_begin + i >= 0))
                    {
                        if (y_begin + 1 <= 9)
                        {
                            in_field->change_info_cell(x_begin + i, y_begin + 1, 4); // ������� ����� �����
                        }
                        if (y_begin - 1 >= 0)
                        {
                            in_field->change_info_cell(x_begin + i, y_begin - 1, 4); // ������� ����� ������
                        }
                    }
                }
                // ������� ����� ������ � �����
                if (x_begin + 3 <= 9)
                {
                    in_field->change_info_cell(x_begin + 3, y_begin, 4); // ������� ����� ������ 
                }
                if (x_begin - 1 >= 0)
                {
                    in_field->change_info_cell(x_begin - 1, y_begin, 4); // ������� ����� �����
                }
            }
            /*do
            {
                scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� ������������
            } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 2)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 2))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4) && (in_field.get_info_cell(x_end, y_end) != 1) && (in_field.get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� �����������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������) */
        }


        graphic_develop_class_2(*in_field, *in_field);
        system("pause");



        // ������� ��������������
        for (int j = 3; j <= 5; j++)
        {
            /*switch (j)
            {
            case 1:
                printf("������� ���������� ������ � ����� ������� ������������ �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            case 2:
                printf("������� ���������� ������ � ����� ������� ������������ �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            default:
                printf("������: �������� ������ ������������ � ����� ��� ������������ �� ���� �� ����� 1 ��� 2");
                break;
            }*/
            if (rand() % 2 == 1) // ������� ����� �����������
            {
                do
                {
                    x_begin = rand() % 10;
                    y_begin = rand() % 9;
                } while (!((in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4) && (in_field->get_info_cell(x_begin, y_begin + 1) != 1) && (in_field->get_info_cell(x_begin, y_begin + 1) != 4)));
                for (int i = 0; i <= 1; i++) // ������� �������
                {
                    in_field->change_number_of_ship_cell(x_begin, y_begin + i, j);
                    in_field->change_info_cell(x_begin, y_begin + i, 1);
                }
                // ������� ����������� ����� ������ �������
                for (int i = -1; i <= 2; i++) // ������� ����� ����� � ������. ����� ��������������!!!!!!!! ��������� �� ������!!!!
                {
                    if ((y_begin + i <= 9) && (y_begin + i >= 0))
                    {
                        if (x_begin + 1 <= 9)
                        {
                            in_field->change_info_cell(x_begin + 1, y_begin + i, 4);
                        }
                        if (x_begin - 1 >= 0)
                        {
                            in_field->change_info_cell(x_begin - 1, y_begin + i, 4);
                        }
                    }
                }
                // ������� ����� ������ � �����
                if (y_begin + 2 <= 9)
                {
                    in_field->change_info_cell(x_begin, y_begin + 2, 4); // ������� ����� ����� 
                }
                if (y_begin - 1 >= 0)
                {
                    in_field->change_info_cell(x_begin, y_begin - 1, 4); // ������� ����� ������
                }
            }
            else // ������� ����� �������������
            {

                do
                {
                    x_begin = rand() % 9;
                    y_begin = rand() % 10;
                } while (!((in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4) && (in_field->get_info_cell(x_begin + 1, y_begin) != 1) && (in_field->get_info_cell(x_begin + 1, y_begin) != 4)));
                for (int i = 0; i <= 1; i++) // ������� �������
                {
                    in_field->change_number_of_ship_cell(x_begin + i, y_begin, j);
                    in_field->change_info_cell(x_begin + i, y_begin, 1);
                }
                // ������� ����������� ����� ������ �������
                for (int i = -1; i <= 2; i++) // ������� ����� ������ � �����. ����� ��������������!!!!!!!! ��������� �� ������!!!!
                {
                    if ((x_begin + i <= 9) && (x_begin + i >= 0))
                    {
                        if (y_begin + 1 <= 9)
                        {
                            in_field->change_info_cell(x_begin + i, y_begin + 1, 4); // ������� ����� �����
                        }
                        if (y_begin - 1 >= 0)
                        {
                            in_field->change_info_cell(x_begin + i, y_begin - 1, 4); // ������� ����� ������
                        }
                    }
                }
                // ������� ����� ������ � �����
                if (x_begin + 2 <= 9)
                {
                    in_field->change_info_cell(x_begin + 2, y_begin, 4); // ������� ����� ������ 
                }
                if (x_begin - 1 >= 0)
                {
                    in_field->change_info_cell(x_begin - 1, y_begin, 4); // ������� ����� �����
                }
            }
            /*do
            {
                scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� ������������
            } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 2)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 2))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4) && (in_field.get_info_cell(x_end, y_end) != 1) && (in_field.get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� �����������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������) */
        }

        graphic_develop_class_2(*in_field, *in_field);
        system("pause");

        /*printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
        do
        {
            scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� �������������
        } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 1)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 1))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4) && (in_field.get_info_cell(x_end, y_end) != 1) && (in_field.get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� ������������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
        for (int i = 0; i <= 1; i++) // ������� �������
        {
            in_field.change_number_of_ship_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 4); // ������� ������ �������
            in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 1); // ������� ����� �������
        }
        // ������� ����������� ����� ������ �������
        if (x_begin == x_end) // ������� ����� �����������
        {
            for (int i = -1; i <= 2; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((y_begin + i * (y_end - y_begin) <= 9) && (y_begin + i * (y_end - y_begin) >= 0))
                {
                    if (x_begin + 1 <= 9)
                    {
                        in_field.change_info_cell(x_begin + 1, y_begin + i * (y_end - y_begin), 4);
                    }
                    if (x_begin - 1 >= 0)
                    {
                        in_field.change_info_cell(x_begin - 1, y_begin + i * (y_end - y_begin), 4);
                    }
                }
            }
            // ������� ����� ������ � �����
            if ((y_begin + 2 * (y_end - y_begin) >= 0) && (y_begin + 2 * (y_end - y_begin) <= 9))
            {
                in_field.change_info_cell(x_begin, y_begin + 2 * (y_end - y_begin), 4);
            }
            if ((y_begin - (y_end - y_begin) >= 0) && (y_begin - (y_end - y_begin) <= 9))
            {
                in_field.change_info_cell(x_begin, y_begin - (y_end - y_begin), 4);
            }
        }
        if (y_begin == y_end) // ������� ����� �������������
        {
            for (int i = -1; i <= 2; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((x_begin + i * (x_end - x_begin) <= 9) && (x_begin + i * (x_end - x_begin) >= 0))
                {
                    if (y_begin + 1 <= 9)
                    {
                        in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + 1, 4);
                    }
                    if (y_begin - 1 >= 0)
                    {
                        in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin - 1, 4);
                    }
                }
            }
            // ������� ����� ����� � ������
            if ((x_begin + 2 * (x_end - x_begin) >= 0) && (x_begin + 2 * (x_end - x_begin) <= 9))
            {
                in_field.change_info_cell(x_begin + 2 * (x_end - x_begin), y_begin, 4);
            }
            if ((x_begin - (x_end - x_begin) >= 0) && (x_begin - (x_end - x_begin) <= 9))
            {
                in_field.change_info_cell(x_begin - (x_end - x_begin), y_begin, 4);
            }
        }


        printf("������� ���������� ������ � ����� �������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
        do
        {
            scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� �������������
        } while (!((((x_begin != x_end) && (y_begin == y_end) && (abs(x_begin - x_end) == 1)) || ((y_begin != y_end) && (x_begin == x_end) && (abs(y_begin - y_end) == 1))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4) && (in_field.get_info_cell(x_end, y_end) != 1) && (in_field.get_info_cell(x_end, y_end) != 4))); // ������� �� �����, ���� ������� ���������� ������������� ��� �����������, � � � ���������� ������ ���� ������ -1 � ������ 10, ������� ������������, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������)
        for (int i = 0; i <= 1; i++) // ������� �������
        {
            in_field.change_number_of_ship_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 5); // ������� ������ �������
            in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + i * (y_end - y_begin), 1); // ������� ����� �������
        }
        // ������� ����������� ����� ������ �������
        if (x_begin == x_end) // ������� ����� �����������
        {
            for (int i = -1; i <= 2; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((y_begin + i * (y_end - y_begin) <= 9) && (y_begin + i * (y_end - y_begin) >= 0))
                {
                    if (x_begin + 1 <= 9)
                    {
                        in_field.change_info_cell(x_begin + 1, y_begin + i * (y_end - y_begin), 4);
                    }
                    if (x_begin - 1 >= 0)
                    {
                        in_field.change_info_cell(x_begin - 1, y_begin + i * (y_end - y_begin), 4);
                    }
                }
            }
            // ������� ����� ������ � �����
            if ((y_begin + 2 * (y_end - y_begin) >= 0) && (y_begin + 2 * (y_end - y_begin) <= 9))
            {
                in_field.change_info_cell(x_begin, y_begin + 2 * (y_end - y_begin), 4);
            }
            if ((y_begin - (y_end - y_begin) >= 0) && (y_begin - (y_end - y_begin) <= 9))
            {
                in_field.change_info_cell(x_begin, y_begin - (y_end - y_begin), 4);
            }
        }
        if (y_begin == y_end) // ������� ����� �������������
        {
            for (int i = -1; i <= 2; i++) // ������� ����� ������ � ����� ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((x_begin + i * (x_end - x_begin) <= 9) && (x_begin + i * (x_end - x_begin) >= 0))
                {
                    if (y_begin + 1 <= 9)
                    {
                        in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin + 1, 4);
                    }
                    if (y_begin - 1 >= 0)
                    {
                        in_field.change_info_cell(x_begin + i * (x_end - x_begin), y_begin - 1, 4);
                    }
                }
            }
            // ������� ����� ����� � ������
            if ((x_begin + 2 * (x_end - x_begin) >= 0) && (x_begin + 2 * (x_end - x_begin) <= 9))
            {
                in_field.change_info_cell(x_begin + 2 * (x_end - x_begin), y_begin, 4);
            }
            if ((x_begin - (x_end - x_begin) >= 0) && (x_begin - (x_end - x_begin) <= 9))
            {
                in_field.change_info_cell(x_begin - (x_end - x_begin), y_begin, 4);
            }
        }*/





        for (int j = 6; j <= 9; j++)
        {
            /*switch (j)
            {
            case 6:
                printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            case 7:
                printf("������� ���������� ������ � ����� ������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            case 8:
                printf("������� ���������� ������ � ����� �������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            case 9:
                printf("������� ���������� ������ � ����� ��������� ������������� �� ��� X � ��� Y (�� 0 �� 9)\n");
                break;
            default:
                printf("������: �������� ������ ������������� � ����� ��� ������������ �� ���� �� ����� 6-9");
                break;
            }*/
            /*do
            {
                scanf("%i%i", &x_begin, &y_begin); // ���������� ������ � ����� �������������
            } while (!(((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && (in_field.get_info_cell(x_begin, y_begin) != 1) && (in_field.get_info_cell(x_begin, y_begin) != 4))); // ������� �� �����, ����  � � � ���������� ������ ���� ������ -1 � ������ 10, ������� �� ����� �� ����������� �������(������� ��������, ���� ������� ����� � �������) */
            // ������� �������

            do
            {
                x_begin = rand() % 10;
                y_begin = rand() % 10;
            } while (!((in_field->get_info_cell(x_begin, y_begin) != 1) && (in_field->get_info_cell(x_begin, y_begin) != 4)));
            in_field->change_number_of_ship_cell(x_begin, y_begin, j); // ������� ������ �������
            in_field->change_info_cell(x_begin, y_begin, 1); // ������� ����� �������

            // ������� ����������� ����� ������ �������        
            for (int i = -1; i <= 1; i++) // ������� ����� ����� � ������ ����� ��������������!!!!!!!! ��������� �� ������!!!!
            {
                if ((y_begin + i <= 9) && (y_begin + i >= 0))
                {
                    if (x_begin + 1 <= 9)
                    {
                        in_field->change_info_cell(x_begin + 1, y_begin + i, 4);
                    }
                    if (x_begin - 1 >= 0)
                    {
                        in_field->change_info_cell(x_begin - 1, y_begin + i, 4);
                    }
                }
            }
            // ������� ����� ������ � �����
            if (y_begin + 1 <= 9)
            {
                in_field->change_info_cell(x_begin, y_begin + 1, 4);
            }
            if (y_begin - 1 >= 0)
            {
                in_field->change_info_cell(x_begin, y_begin - 1, 4);
            }
        }
        

        graphic_develop_class_2(*in_field, *in_field);
        system("pause");

        /*x_begin = 0;
        y_begin = 0;
        x_end = 0;
        y_end = 0;*/
        /*while (!((((x_begin != x_end) && (y_begin == y_end)) || ((y_begin != y_end) && (x_begin == x_end))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9))))
        {

        }*/

        /*do
        {
            scanf("%i%i%i%i", &x_begin, &y_begin, &x_end, &y_end); // ���������� ������ � ����� 1-�� ������������
        } while (!((((x_begin != x_end) && (y_begin == y_end)) || ((y_begin != y_end) && (x_begin == x_end))) && ((x_begin >= 0) && (x_begin <= 9)) && ((y_begin >= 0) && (y_begin <= 9)) && ((x_end >= 0) && (x_end <= 9)) && ((y_end >= 0) && (y_end <= 9))));*/
        // scanf("%i%i%i%i%i%i%i%i", &ship3[0][0].x, &ship3[0][0].y, &ship3[2][0].x, &ship3[2][0].y, &ship3[0][1].x, &ship3[0][1].y, &ship3[2][1].x, &ship3[2][1].y);  // ���������� ������ � �����
         //printf("������� ���������� ������ � ����� ��������������\n");
        // scanf("%i%i%i%i%i%i%i%i%i%i%i%i", &ship2[0][0].x, &ship2[0][0].y, &ship2[1][0].x, &ship2[1][0].y, &ship2[0][1].x, &ship2[0][1].y, &ship2[1][1].x, &ship2[1][1].y, &ship2[0][2].x, &ship2[0][2].y, &ship2[1][2].x, &ship2[1][2].y);  // ���������� ������ � �����
         //printf("������� ���������� ��������������\n");
        // scanf("%i%i%i%i%i%i%i%i", &ship1[0].x, &ship1[0].y, &ship1[1].x, &ship1[1].y, &ship1[2].x, &ship1[2].y, &ship1[3].x, &ship1[3].y);  // ���������� ������ � �����
    }
}

void Shot(Field* in_field_player, Field* in_field_computer, bool turn) // ��������� ��� ���������� �������
{
       // bool aim = 0; // ��������� ����� �� ��������� � ���������� ������ (1 - �����, 0 - �� �����)
    int x = 0, y = 0; // ���������� ��������
        if (turn == 1) { // ��� ������
            do {
                printf("������� ���������� ��������\n");
                scanf("%i%i", &x, &y); //A=65 a=97 ��������� ���������� ��������
                if ((x >= 0) && (x <= 9) && (y >= 0) && (y <= 9) && (in_field_computer->get_info_cell(x, y)/*pole_ai[shot.x][shot.y].info*/ != 0) && (in_field_computer->get_info_cell(x, y)/*pole_ai[shot.x][shot.y].info*/ != 1)) { // ���������, ��� 0 <= x <= 9, 0 <= y <= 9 � ������ � ������������ (x, y) �� �������
                    printf("�� ��������\n");
                }
            } while ((x >= 0) && (x <= 9) && (y >= 0) && (y <= 9) && (in_field_computer->get_info_cell(x, y)/*pole_ai[shot.x][shot.y].info*/ != 0) && (in_field_computer->get_info_cell(x, y)/*pole_ai[shot.x][shot.y].info*/ != 1)); // ���������, ��� 0 <= x <= 9, 0 <= y <= 9 � ������ � ������������ (x, y) �� �������
        }
        // ���������� ������!!!!
        else { // ��� ����������
           // turn == 1;
            switch (hit) { // ����� �������� ������������ � ����������� �� ���������� ��������� �� 1-�� ������� �� ��� ����������
            case 0: { // �� ���� �� ����� => �������� ��������� �����, � ������� ����� ��������
                //aim = false; // ������� ��������� ������ �� �����
                while (aim == false) {
                    shot.x = rand() % 10;
                    shot.y = rand() % 10;
                    if (pole_player[shot.x][shot.y].info == 0 || pole_player[shot.x][shot.y].info == 1) aim = true;
                }
                break;
            }
            case 1: { // ����� ���� ��� => �������� ����� � ����������
                aim = false; // ������� ��������� ������ �� �����
                do {
                    switch (rand() % 4) { // �������� ����������� ������ ��������� ����� �������; 0 - �����, 1 - �����, 2 - ���� , 3 - ������
                    case 0: { // �����
                        if (shot_ai[0].y - 1 >= 0 && (pole_player[shot_ai[0].x][shot_ai[0].y - 1].info == 0 || pole_player[shot_ai[0].x][shot_ai[0].y - 1].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                            shot.x = shot_ai[0].x;
                            shot.y = shot_ai[0].y - 1;
                            aim = true;
                        }
                    }
                    case 1: { // �����
                        if (shot_ai[0].x - 1 >= 0 && (pole_player[shot_ai[0].x - 1][shot_ai[0].y].info == 0 || pole_player[shot_ai[0].x - 1][shot_ai[0].y].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                            shot.y = shot_ai[0].y;
                            shot.x = shot_ai[0].x - 1;
                            aim = true;
                        }
                    }
                    case 2: { // ����
                        if (shot_ai[0].y + 1 <= 9 && (pole_player[shot_ai[0].x][shot_ai[0].y + 1].info == 0 || pole_player[shot_ai[0].x][shot_ai[0].y + 1].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                            shot.x = shot_ai[0].x;
                            shot.y = shot_ai[0].y + 1;
                            aim = true;
                        }
                    }
                    case 3: { // ������
                        if (shot_ai[0].x + 1 <= 9 && (pole_player[shot_ai[0].x + 1][shot_ai[0].y].info == 0 || pole_player[shot_ai[0].x + 1][shot_ai[0].y].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                            shot.y = shot_ai[0].y;
                            shot.x = shot_ai[0].x + 1;
                            aim = true;
                        }
                    }
                    }
                } while (aim == false);
                break;
            }
            default: { // ����� 2 ��� ����� ��� => �������� ���� ����� � ������������ �������
                if (shot_ai[0].x == shot_ai[1].x) { // ������� ����� �����������
                    aim = false;
                    while (aim == false) {
                        switch (rand() % 4) { //
                        case 0: { // �������� � �����, ����������� ���� shot_ai[0].y ( - 1 )
                            if (shot_ai[0].y - 1 >= 0 && pole_player[shot_ai[0].x][shot_ai[0].y - 1].info != 2 && pole_player[shot_ai[0].x][shot_ai[0].y - 1].info != 3) {
                                shot.x = shot_ai[0].x;
                                shot.y = shot_ai[0].y - 1;
                                aim = true;
                            }
                            break;
                        }
                        case 1: { // �������� � �����, ����������� ���� shot_ai[0].y
                            if (shot_ai[0].y + 1 <= 9 && pole_player[shot_ai[0].x][shot_ai[0].y + 1].info != 2 && pole_player[shot_ai[0].x][shot_ai[0].y + 1].info != 3) {
                                shot.x = shot_ai[0].x;
                                shot.y = shot_ai[0].y + 1;
                                aim = true;
                            }
                            break;
                        }
                        case 2: { // �������� � �����, ����������� ���� shot_ai[1].y
                            if (shot_ai[1].y - 1 >= 0 && pole_player[shot_ai[1].x][shot_ai[1].y - 1].info != 2 && pole_player[shot_ai[1].x][shot_ai[1].y - 1].info != 3) {
                                shot.x = shot_ai[1].x;
                                shot.y = shot_ai[1].y - 1;
                                aim = true;
                            }
                            break;
                        }
                        case 3: { // �������� � �����, ����������� ���� shot_ai[1].y
                            if (shot_ai[1].y + 1 <= 9 && pole_player[shot_ai[1].x][shot_ai[1].y + 1].info != 2 && pole_player[shot_ai[1].x][shot_ai[1].y + 1].info != 3) {
                                shot.x = shot_ai[1].x;
                                shot.y = shot_ai[1].y + 1;
                                aim = true;
                            }
                            break;
                        }
                        }
                    }
                }
                else { // ������� ����� �������������
                    aim = false;
                    while (aim == false) {
                        switch (rand() % 4) { //
                        case 0: { // �������� � �����, ����������� ����� shot_ai[0].x
                            if (shot_ai[0].x - 1 >= 0 && pole_player[shot_ai[0].x - 1][shot_ai[0].y].info != 2 && pole_player[shot_ai[0].x - 1][shot_ai[0].y].info != 3) {
                                shot.y = shot_ai[0].y;
                                shot.x = shot_ai[0].x - 1;
                                aim = true;
                            }
                            break;
                        }
                        case 1: { // �������� � �����, ����������� ������ shot_ai[0].x
                            if (shot_ai[0].x + 1 <= 9 && pole_player[shot_ai[0].x + 1][shot_ai[0].y].info != 2 && pole_player[shot_ai[0].x + 1][shot_ai[0].y].info != 3) {
                                shot.y = shot_ai[0].y;
                                shot.x = shot_ai[0].x + 1;
                                aim = true;
                            }
                            break;
                        }
                        case 2: { // �������� � �����, ����������� ����� shot_ai[1].x
                            if (shot_ai[1].x - 1 >= 0 && pole_player[shot_ai[1].x - 1][shot_ai[1].y].info != 2 && pole_player[shot_ai[1].x - 1][shot_ai[1].y].info != 3) {
                                shot.y = shot_ai[1].y;
                                shot.x = shot_ai[1].x - 1;
                                aim = true;
                            }
                            break;
                        }
                        case 3: { // �������� � �����, ����������� ������ shot_ai[1].x
                            if (shot_ai[1].x + 1 <= 9 && pole_player[shot_ai[1].x + 1][shot_ai[1].y].info != 2 && pole_player[shot_ai[1].x + 1][shot_ai[1].y].info != 3) {
                                shot.y = shot_ai[1].y;
                                shot.x = shot_ai[1].x + 1;
                                aim = true;
                            }
                            break;
                        }
                        }
                    }
                }
                break;
            }
            }

        }
        return aim;
    
}

int hit = 0; // ������� ��� ��������� ����� �� �������; ����������, ����� �� "�������" �������
bool dead_ship_of_player[10]; // (true => dead, false => alive)
bool dead_ship_of_ai[10]; // (true => dead, false => alive)
//char winner; // ���������� ���������� (�������: p - �����, a - ���������, n - ���� ��� ����� �� �������)
bool xod_of_player; // ���������� ��� ������ �������� ( true/1 => ����� �����, false/0 => ����� ��������� )
pole pole_player[10][10]; // 0 ~ ���������� ������ ��� �������, 1 ~ ���������� ������ � �������, 2 ~ �������� ������ ��� �������, 3 ~ �������� ������ � �������, 4 ~ ������, �� ������� ������ ������� ������� (= 0..9)
pole pole_ai[10][10];  // = (0..9)
ship shot_ai[2]; // ���������� �����
ship shot; // ���������� ��������
ship ship1[4]; // [����� �������] (= 0..9)
ship ship2[2][3]; // [����� ������][����� �������] (= 0..9)
ship ship3[3][2]; // [����� ������][����� �������] (= 0..9)
ship ship4[4]; // [����� ������]
ship ship1_ai[4]; // [����� ������] ���������
ship ship2_ai[2][3]; //[����� ������][����� �������] ���������
ship ship3_ai[3][2]; //[����� ������][����� �������] ���������
ship ship4_ai[4]; //[����� �������] ���������
void graphic_develop() {
    int i, j;
    printf("\n\n");
    printf(" ���������                   �����\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%i ", pole_ai[j][i].info);
        }
        printf("    ");
        for (j = 0; j < 10; j++) {
            printf("%i ", pole_player[j][i].info);
        }
        printf("\n");
    }
    printf("\n\n");
}

void ship_ai() { //������� �������� ����������
    bool possible; // ��������� ����� �� ��������� �������; ������� ������ (false), ����� ����� ���� ����� � ����
    int i, j;
    int x, y;
    x = rand() % 10; // ������� 4-�� ���������
    y = rand() % 10;
    if (rand() % 2 == 1) { // ������� ����� �����������
        if (y > 6)
            y = rand() % 7;
        for (i = 0; i < 4; i++) {
            ship4_ai[i].x = x;  // ������� ����� ������� � ������� ������� �� ��� �
            ship4_ai[i].y = y + i;  // ������� ����� ������� � ������� ������� �� ��� �
            pole_ai[ship4_ai[i].x][ship4_ai[i].y].info = 1; // ������� ����� ������� �� ����
            pole_ai[ship4_ai[i].x][ship4_ai[i].y].num_of_ship = 1;
            if (ship4_ai[i].x - 1 > -1)
                pole_ai[ship4_ai[i].x - 1][ship4_ai[i].y].info = 4; // ������� �� ���� �����, ����������� ����� �� �������, �� ������� ������ ������� �������
            if (ship4_ai[i].x + 1 < 10)
                pole_ai[ship4_ai[i].x + 1][ship4_ai[i].y].info = 4; // ������� �� ���� �����, ����������� ������ �� �������, �� ������� ������ ������� �������
        }
        for (j = 0; j < 3; j++) {
            if ((x - 1 + j > -1) && (y - 1 > -1) && (x - 1 + j < 10))
                pole_ai[x - 1 + j][y - 1].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
            if ((x - 1 + j > -1) && (y + 4 < 10) && (x - 1 + j < 10))
                pole_ai[x - 1 + j][y + 4].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
        }
    }
    else {
        if (x > 6)
            x = rand() % 7; // ������� ����� �������������
        for (i = 0; i < 4; i++) {
            ship4_ai[i].x = x + i;  // ������� ����� ������� � ������� ������� �� ��� �
            ship4_ai[i].y = y;  // ������� ����� ������� � ������� ������� �� ��� �
            pole_ai[ship4_ai[i].x][ship4_ai[i].y].info = 1; // ������� ����� ������� �� ����
            pole_ai[ship4_ai[i].x][ship4_ai[i].y].num_of_ship = 1;
            if (ship4_ai[i].y - 1 > -1)
                pole_ai[ship4_ai[i].x][ship4_ai[i].y - 1].info = 4; // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
            if (ship4_ai[i].y + 1 < 10)
                pole_ai[ship4_ai[i].x][ship4_ai[i].y + 1].info = 4; // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
        }
        for (j = 0; j < 3; j++) {
            if ((y - 1 + j > -1) && (x - 1 > -1) && (y - 1 + j < 10))
                pole_ai[x - 1][y - 1 + j].info = 4;  // ������� �� ���� �����, ����������� ����� �� �������, �� ������� ������ ������� �������
            if ((y - 1 + j > -1) && (x + 4 < 10) && (y - 1 + j < 10))
                pole_ai[x + 4][y - 1 + j].info = 4;  // ������� �� ���� �����, ����������� ������ �� �������, �� ������� ������ ������� �������
        }
    } // ����� ������� ���������������
    for (j = 0; j < 2; j++) { // ������� �������������
        if (rand() % 2 == 1) { // ������� ����� �����������
            possible = false;
            while (!possible) {
                x = rand() % 10;
                y = rand() % 8;
                possible = true;
                for (i = 0; i < 3; i++) {
                    if (pole_ai[x][y + i].info != 0) {
                        possible = false;
                    }
                }
                if (possible) {
                    for (i = 0; i < 3; i++) {
                        ship3_ai[i][j].x = x;  // ������� ����� ������� � ������� ������� �� ��� �
                        ship3_ai[i][j].y = y + i;  // ������� ����� ������� � ������� ������� �� ��� �
                        pole_ai[ship3_ai[i][j].x][ship3_ai[i][j].y].info = 1; // ������� ����� ������� �� ����
                        pole_ai[ship3_ai[i][j].x][ship3_ai[i][j].y].num_of_ship = 2 + j;
                        if (ship3_ai[i][j].x - 1 > -1)
                            pole_ai[ship3_ai[i][j].x - 1][ship3_ai[i][j].y].info = 4; // ������� �� ���� �����, ����������� ����� �� �������, �� ������� ������ ������� �������
                        if (ship3_ai[i][j].x + 1 < 10)
                            pole_ai[ship3_ai[i][j].x + 1][ship3_ai[i][j].y].info = 4; // ������� �� ���� �����, ����������� ������ �� �������, �� ������� ������ ������� �������
                    }
                    for (i = 0; i < 3; i++) {
                        if ((x - 1 + i > -1) && (y - 1 > -1) && (x - 1 + i < 10))
                            pole_ai[x - 1 + i][y - 1].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                        if ((x - 1 + i > -1) && (y + 3 < 10) && (x - 1 + i < 10))
                            pole_ai[x - 1 + i][y + 3].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    }
                }
            }
        }


        else { // ������� ����� �������������
            possible = false;
            while (!possible) {
                y = rand() % 10;
                x = rand() % 8;
                possible = true;
                for (i = 0; i < 3; i++) {
                    if (pole_ai[x + i][y].info != 0) {
                        possible = false;
                    }
                }
                if (possible) {
                    for (i = 0; i < 3; i++) {
                        ship3_ai[i][j].x = x + i;  // ������� ����� ������� � ������� ������� �� ��� �
                        ship3_ai[i][j].y = y;  // ������� ����� ������� � ������� ������� �� ��� �
                        pole_ai[ship3_ai[i][j].x][ship3_ai[i][j].y].info = 1; // ������� ����� ������� �� ����
                        pole_ai[ship3_ai[i][j].x][ship3_ai[i][j].y].num_of_ship = 2 + j;
                        if (ship3_ai[i][j].y - 1 > -1)
                            pole_ai[ship3_ai[i][j].x][ship3_ai[i][j].y - 1].info = 4; // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                        if (ship3_ai[i][j].y + 1 < 10)
                            pole_ai[ship3_ai[i][j].x][ship3_ai[i][j].y + 1].info = 4; // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    }
                    for (i = 0; i < 3; i++) {
                        if ((y - 1 + i > -1) && (x - 1 > -1) && (y - 1 + i < 10))
                            pole_ai[x - 1][y - 1 + i].info = 4;  // ������� �� ���� �����, ����������� ����� �������, �� ������� ������ ������� �������
                        if ((y - 1 + i > -1) && (x + 3 < 10) && (y - 1 + i < 10))
                            pole_ai[x + 3][y - 1 + i].info = 4;  // ������� �� ���� �����, ����������� ������ �������, �� ������� ������ ������� �������
                    }
                }
            }



        }

    } // ����� ������� �������������
    for (j = 0; j < 3; j++) { // ������� ��������������

        if (rand() % 2 == 1) { // ������� ����� �����������
            possible = false;
            while (!possible) {
                x = rand() % 10;
                y = rand() % 9;
                possible = true;
                for (i = 0; i < 2; i++) {
                    if (pole_ai[x][y + i].info != 0) {
                        possible = false;
                    }
                }
                if (possible) {
                    for (i = 0; i < 2; i++) {
                        ship2_ai[i][j].x = x;  // ������� ����� ������� � ������� ������� �� ��� �
                        ship2_ai[i][j].y = y + i;  // ������� ����� ������� � ������� ������� �� ��� �
                        pole_ai[ship2_ai[i][j].x][ship2_ai[i][j].y].info = 1; // ������� ����� ������� �� ����
                        pole_ai[ship2_ai[i][j].x][ship2_ai[i][j].y].num_of_ship = 4 + j;
                        if (ship2_ai[i][j].x - 1 > -1)
                            pole_ai[ship2_ai[i][j].x -
                            1][ship2_ai[i][j].y].info = 4; // ������� �� ���� �����, ����������� ����� �� �������, �� ������� ������ ������� �������
                        if (ship2_ai[i][j].x + 1 < 10)
                            pole_ai[ship2_ai[i][j].x +
                            1][ship2_ai[i][j].y].info = 4; // ������� �� ���� �����, ����������� ������ �� �������, �� ������� ������ ������� �������
                    }
                    for (i = 0; i < 3; i++) {
                        if ((x - 1 + i > -1) && (y - 1 > -1) && (x - 1 + i < 10))
                            pole_ai[x - 1 + i][y -
                            1].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                        if ((x - 1 + i > -1) && (y + 2 < 10) && (x - 1 + i < 10))
                            pole_ai[x - 1 + i][y +
                            2].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    }
                }
            }
        }
        else { // ������� ����� �������������
            possible = false;
            while (!possible) {
                y = rand() % 10;
                x = rand() % 9;
                possible = true;
                for (i = 0; i < 2; i++) {
                    if (pole_ai[x + i][y].info != 0) {
                        possible = false;
                    }
                }
                if (possible) {
                    for (i = 0; i < 2; i++) {
                        ship2_ai[i][j].x = x + i;  // ������� ����� ������� � ������� ������� �� ��� �
                        ship2_ai[i][j].y = y;  // ������� ����� ������� � ������� ������� �� ��� �
                        pole_ai[ship2_ai[i][j].x][ship2_ai[i][j].y].info = 1; // ������� ����� ������� �� ����
                        pole_ai[ship2_ai[i][j].x][ship2_ai[i][j].y].num_of_ship = 4 + j;
                        if (ship2_ai[i][j].y - 1 > -1)
                            pole_ai[ship2_ai[i][j].x][ship2_ai[i][j].y -
                            1].info = 4; // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                        if (ship2_ai[i][j].y + 1 < 10)
                            pole_ai[ship2_ai[i][j].x][ship2_ai[i][j].y +
                            1].info = 4; // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    }
                    for (i = 0; i < 3; i++) {
                        if ((y - 1 + i > -1) && (x - 1 > -1) && (y - 1 + i < 10))
                            pole_ai[x - 1][y - 1 +
                            i].info = 4;  // ������� �� ���� �����, ����������� ����� �������, �� ������� ������ ������� �������
                        if ((y - 1 + i > -1) && (x + 2 < 10) && (y - 1 + i < 10))
                            pole_ai[x + 2][y - 1 +
                            i].info = 4;  // ������� �� ���� �����, ����������� ������ �������, �� ������� ������ ������� �������
                    }
                }
            }


        } // ����� ������� ��������������
    }
    for (j = 0; j < 4; j++) { //
        possible = false;
        while (!possible) {
            x = rand() % 10;
            y = rand() % 10;
            possible = true;
            if (pole_ai[x][y].info != 0) {
                possible = false;
            }
            if (possible) {
                ship1_ai[j].x = x;  // ������� ����� ������� � ������� ������� �� ��� �
                ship1_ai[j].y = y;  // ������� ����� ������� � ������� ������� �� ��� �
                pole_ai[ship1_ai[j].x][ship1_ai[j].y].info = 1; // ������� ����� ������� �� ����
                pole_ai[ship1_ai[j].x][ship1_ai[j].y].num_of_ship = 7 + j;
                if (ship1_ai[j].x - 1 > -1)
                    pole_ai[ship1_ai[j].x - 1][ship1_ai[j].y].info = 4; // ������� �� ���� �����, ����������� ����� �� �������, �� ������� ������ ������� �������
                if (ship1_ai[j].x + 1 < 10)
                    pole_ai[ship1_ai[j].x + 1][ship1_ai[j].y].info = 4; // ������� �� ���� �����, ����������� ������ �� �������, �� ������� ������ ������� �������

                for (i = 0; i < 3; i++) {
                    if ((x - 1 + i > -1) && (y - 1 > -1) && (x - 1 + i < 10))
                        pole_ai[x - 1 + i][y - 1].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    if ((x - 1 + i > -1) && (y + 1 < 10) && (x - 1 + i < 10))
                        pole_ai[x - 1 + i][y + 1].info = 4;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                }
            }
        }
    }


}
void point() { //������� �������� ������
    int i;
    int j;
    if (ship4[0].x > ship4[3].x) {  //������� ����� ������������� � �0 > �3 ������� � �������������� ����� 4-�� ��������
        ship4[0].x = ship4[0].x + ship4[3].x;
        ship4[3].x = ship4[0].x - ship4[3].x;
        ship4[0].x = ship4[0].x - ship4[3].x; //x0=min(x0,x3) x3=max(x0,x3)

    }
    if (ship4[0].y > ship4[3].y) { // ������� ����� ����������� � �0 > �3
        ship4[0].y = ship4[0].y + ship4[3].y;
        ship4[3].y = ship4[0].y - ship4[3].y;
        ship4[0].y = ship4[0].y - ship4[3].y; //y0=min(y0,y3) y3=max(y0,y3)

    }
    if (ship4[0].x != ship4[3].x) {
        ship4[1].x = ship4[0].x + 1; //x1=x0+1
        ship4[2].x = ship4[0].x + 2; //x2=x0+2
        ship4[1].y = ship4[0].y; //y1=y0
        ship4[2].y = ship4[0].y; //y2=y0
    }
    else {
        ship4[1].y = ship4[0].y + 1; //y1 = y0 + 1
        ship4[2].y = ship4[0].y + 2; //y2=y0+2
        ship4[1].x = ship4[0].x; //x1=x0
        ship4[2].x = ship4[0].x; //x2=x0
    }
    for (j = 0; j < 4; j++)
        pole_player[ship4[j].x][ship4[j].y].info = 1; //������� � �������������� ����� 4-�� ��������� �� ���� ������
    for (i = 0; i < 2; i++) {
        if (ship3[0][i].x > ship3[2][i].x) { //������� ����� 3-�� ��������
            ship3[0][i].x = ship3[0][i].x + ship3[2][i].x;
            ship3[2][i].x = ship3[0][i].x - ship3[2][i].x;
            ship3[0][i].x = ship3[0][i].x - ship3[2][i].x; //x0=min(x0,x2) x3=max(x0,x2)

        }
        if (ship3[0][i].y > ship3[2][i].y) {
            ship3[0][i].y = ship3[0][i].y + ship3[2][i].y;
            ship3[2][i].y = ship3[0][i].y - ship3[2][i].y;
            ship3[0][i].y = ship3[0][i].y - ship3[2][i].y; //y0=min(y0,y3) y3=max(y0,y3)


        }
        if (ship3[0][i].x != ship3[2][i].x) {
            ship3[1][i].x = ship3[0][i].x + 1; //x1=x0+1
            ship3[1][i].y = ship3[0][i].y; //y1=y0
        }
        else {
            ship3[1][i].y = ship3[0][i].y + 1; //x1=x0+1
            ship3[1][i].x = ship3[0][i].x; //y1=y0
        }
        for (j = 0; j < 3; j++)
            pole_player[ship3[j][i].x][ship3[j][i].y].info = 1; //������� � �������������� ����� 3-�� ��������� �� ���� ������
    }
    for (i = 0; i < 3; i++) {
        if (ship2[0][i].x > ship2[1][i].x) {  //�������������� ����� 2-y� ���������
            ship2[0][i].x = ship2[0][i].x + ship2[1][i].x;
            ship2[1][i].x = ship2[0][i].x - ship2[1][i].x;
            ship2[0][i].x = ship2[0][i].x - ship2[1][i].x; //x0=min(x0,x1) x3=max(x0,x1)
        }
        if (ship2[0][i].y > ship2[1][i].y) {
            ship2[0][i].y = ship2[0][i].y + ship2[1][i].y;
            ship2[1][i].y = ship2[0][i].y - ship2[1][i].y;
            ship2[0][i].y = ship2[0][i].y - ship2[1][i].y; //y0=min(y0,y1) y3=max(y0,y1)
        }
        for (j = 0; j < 2; j++)
            pole_player[ship2[j][i].x][ship2[j][i].y].info = 1;
    }
    for (i = 0; i < 4; i++)
        pole_player[ship1[i].x][ship1[i].y].info = 1;

}
void dead_of_ships_player() { // ��������� ���� �� ������� ������, ���� ��� �� �������� ������ � �������� �� ���� ������ ������ ������ �������
    int i, j, k;
    if (dead_ship_of_player[0] == false && pole_player[ship4[0].x][ship4[0].y].info == 3 &&
        pole_player[ship4[1].x][ship4[1].y].info == 3 && pole_player[ship4[2].x][ship4[2].y].info == 3 &&
        pole_player[ship4[3].x][ship4[3].y].info == 3) {
        dead_ship_of_player[0] = true;
        hit = 0;
        for (j = 0; j < 4; j++) {
            if (ship4[j].x - 1 > -1 && pole_player[ship4[j].x - 1][ship4[j].y].info != 3)
                pole_player[ship4[j].x - 1][ship4[j].y].info = 2; // ������� �� ���� �����, ����������� ����� �� ����� �������, �� ������� ������ ������� �������
            if (ship4[j].x + 1 < 10 && pole_player[ship4[j].x + 1][ship4[j].y].info != 3)
                pole_player[ship4[j].x + 1][ship4[j].y].info = 2; // ������� �� ���� �����, ����������� ������ �� ����� �������, �� ������� ������ ������� �������
            for (i = 0; i < 3; i++) {
                if ((ship4[j].x - 1 + i > -1) && (ship4[j].y - 1 > -1) && (ship4[j].x - 1 + i < 10) &&
                    (pole_player[ship4[j].x - 1 + i][ship4[j].y - 1].info != 3))
                    pole_player[ship4[j].x - 1 + i][ship4[j].y -
                    1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                if ((ship4[j].x - 1 + i > -1) && (ship4[j].y + 1 < 10) && (ship4[j].x - 1 + i < 10) &&
                    (pole_player[ship4[j].x - 1 + i][ship4[j].y + 1].info != 3))
                    pole_player[ship4[j].x - 1 + i][ship4[j].y + 1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
            }   // ������� �� ���� ������ ����� ������ ������� ������� ���� ����� ����� ��� ������
        }
    }
    for (i = 1; i <= 2; i++) {
        if (dead_ship_of_player[i] == false && pole_player[ship3[0][i - 1].x][ship3[0][i - 1].y].info == 3 &&
            pole_player[ship3[1][i - 1].x][ship3[1][i - 1].y].info == 3 &&
            pole_player[ship3[2][i - 1].x][ship3[2][i - 1].y].info == 3) {
            dead_ship_of_player[i] = true;
            hit = 0;
            for (j = 0; j < 3; j++) {
                if (ship3[j][i - 1].x - 1 > -1 && pole_player[ship3[j][i - 1].x - 1][ship3[j][i - 1].y].info != 3)
                    pole_player[ship3[j][i - 1].x - 1][ship3[j][i -
                    1].y].info = 2; // ������� �� ���� �����, ����������� ����� �� ����� �������, �� ������� ������ ������� �������
                if (ship3[j][i - 1].x + 1 < 10 && pole_player[ship3[j][i - 1].x + 1][ship3[j][i - 1].y].info != 3)
                    pole_player[ship3[j][i - 1].x + 1][ship3[j][i -
                    1].y].info = 2; // ������� �� ���� �����, ����������� ������ �� ����� �������, �� ������� ������ ������� �������

                for (k = 0; k < 3; k++) {
                    if ((ship3[j][i - 1].x - 1 + k > -1) && (ship3[j][i - 1].y - 1 > -1) &&
                        (ship3[j][i - 1].x - 1 + k < 10) &&
                        (pole_player[ship3[j][i - 1].x - 1 + k][ship3[j][i - 1].y - 1].info != 3))
                        pole_player[ship3[j][i - 1].x - 1 + k][ship3[j][i - 1].y -
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    if ((ship3[j][i - 1].x - 1 + k > -1) && (ship3[j][i - 1].y + 1 < 10) &&
                        (ship3[j][i - 1].x - 1 + k < 10) &&
                        (pole_player[ship3[j][i - 1].x - 1 + k][ship3[j][i - 1].y + 1].info != 3))
                        pole_player[ship3[j][i - 1].x - 1 + k][ship3[j][i - 1].y +
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
// ������� �� ���� ������ ����� ������ ������� ������� ���� ����� ����� ��� ������
                }

            }
        }
    }
    for (i = 3; i <= 5; i++) {
        if (dead_ship_of_player[i] == false && pole_player[ship2[0][i - 3].x][ship2[0][i - 3].y].info == 3 &&
            pole_player[ship2[1][i - 3].x][ship2[1][i - 3].y].info == 3) {
            dead_ship_of_player[i] = true;
            hit = 0;
            for (j = 0; j < 2; j++) {
                if (ship2[j][i - 3].x - 1 > -1 && pole_player[ship2[j][i - 3].x - 1][ship2[j][i - 3].y].info != 3)
                    pole_player[ship2[j][i - 3].x - 1][ship2[j][i -
                    3].y].info = 2; // ������� �� ���� �����, ����������� ����� �� ����� �������, �� ������� ������ ������� �������
                if (ship2[j][i - 3].x + 1 < 10 && pole_player[ship2[j][i - 3].x + 1][ship2[j][i - 3].y].info != 3)
                    pole_player[ship2[j][i - 3].x + 1][ship2[j][i -
                    3].y].info = 2; // ������� �� ���� �����, ����������� ������ �� ����� �������, �� ������� ������ ������� �������

                for (k = 0; k < 3; k++) {
                    if ((ship2[j][i - 3].x - 1 + k > -1) && (ship2[j][i - 3].y - 1 > -1) &&
                        (ship2[j][i - 3].x - 1 + k < 10) &&
                        (pole_player[ship2[j][i - 3].x - 1 + k][ship2[j][i - 3].y - 1].info != 3))
                        pole_player[ship2[j][i - 3].x - 1 + k][ship2[j][i - 3].y -
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    if ((ship2[j][i - 3].x - 1 + k > -1) && (ship2[j][i - 3].y + 1 < 10) &&
                        (ship2[j][i - 3].x - 1 + k < 10) &&
                        (pole_player[ship2[j][i - 3].x - 1 + k][ship2[j][i - 3].y + 1].info != 3))
                        pole_player[ship2[j][i - 3].x - 1 + k][ship2[j][i - 3].y +
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
// ������� �� ���� ������ ����� ������ ������� ������� ���� ����� ����� ��� ������
                }

            }
        }
    }
    for (i = 6; i <= 9; i++) {
        if (dead_ship_of_player[i] == false && pole_player[ship1[i - 6].x][ship1[i - 6].y].info == 3) {
            dead_ship_of_player[i] = true;
            hit = 0;
            if (ship1[i - 6].x - 1 > -1)
                pole_player[ship1[i - 6].x - 1][ship1[i - 6].y].info = 2; // ������� �� ���� �����, ����������� ����� �� �������, �� ������� ������ ������� �������
            if (ship1[i - 6].x + 1 < 10)
                pole_player[ship1[i - 6].x + 1][ship1[i - 6].y].info = 2; // ������� �� ���� �����, ����������� ������ �� �������, �� ������� ������ ������� �������

            for (k = 0; k < 3; k++) {
                if ((ship1[i - 6].x - 1 + k > -1) && (ship1[i - 6].y - 1 > -1) && (ship1[i - 6].x - 1 + k < 10))
                    pole_player[ship1[i - 6].x - 1 + k][ship1[i - 6].y - 1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                if ((ship1[i - 6].x - 1 + k > -1) && (ship1[i - 6].y + 1 < 10) && (ship1[i - 6].x - 1 + k < 10))
                    pole_player[ship1[i - 6].x - 1 + k][ship1[i - 6].y + 1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
            }

        }
    }
}
void dead_of_ships_ai() {  // ��������� ���� �� ������� ����������, ���� ��� �� �������� ������ � �������� �� ���� ������ ������ ������ �������
    int i, j, k;
    if (dead_ship_of_ai[0] == false && pole_ai[ship4_ai[0].x][ship4_ai[0].y].info == 3 &&
        pole_ai[ship4_ai[1].x][ship4_ai[1].y].info == 3 && pole_ai[ship4_ai[2].x][ship4_ai[2].y].info == 3 &&
        pole_ai[ship4_ai[3].x][ship4_ai[3].y].info == 3) {
        dead_ship_of_ai[0] = true;
        for (j = 0; j < 4; j++) {
            if (ship4_ai[j].x - 1 > -1 && pole_ai[ship4_ai[j].x - 1][ship4_ai[j].y].info != 3)
                pole_ai[ship4_ai[j].x - 1][ship4_ai[j].y].info = 2; // ������� �� ���� �����, ����������� ����� �� ����� �������, �� ������� ������ ������� �������
            if (ship4_ai[j].x + 1 < 10 && pole_ai[ship4_ai[j].x + 1][ship4_ai[j].y].info != 3)
                pole_ai[ship4_ai[j].x + 1][ship4_ai[j].y].info = 2; // ������� �� ���� �����, ����������� ������ �� ����� �������, �� ������� ������ ������� �������
            for (i = 0; i < 3; i++) {
                if ((ship4_ai[j].x - 1 + i > -1) && (ship4_ai[j].y - 1 > -1) && (ship4_ai[j].x - 1 + i < 10) &&
                    (pole_ai[ship4_ai[j].x - 1 + i][ship4_ai[j].y - 1].info != 3))
                    pole_ai[ship4_ai[j].x - 1 + i][ship4_ai[j].y -
                    1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                if ((ship4_ai[j].x - 1 + i > -1) && (ship4_ai[j].y + 1 < 10) && (ship4_ai[j].x - 1 + i < 10) &&
                    (pole_ai[ship4_ai[j].x - 1 + i][ship4_ai[j].y + 1].info != 3))
                    pole_ai[ship4_ai[j].x - 1 + i][ship4_ai[j].y + 1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
            }   // ������� �� ���� ������ ����� ������ ������� ������� ���� ����� ����� ��� ������
        }
    }
    for (i = 1; i <= 2; i++) {
        if (dead_ship_of_ai[i] == false && pole_ai[ship3_ai[0][i - 1].x][ship3_ai[0][i - 1].y].info == 3 &&
            pole_ai[ship3_ai[1][i - 1].x][ship3_ai[1][i - 1].y].info == 3 &&
            pole_ai[ship3_ai[2][i - 1].x][ship3_ai[2][i - 1].y].info == 3) {
            dead_ship_of_ai[i] = true;
            for (j = 0; j < 3; j++) {
                if (ship3_ai[j][i - 1].x - 1 > -1 && pole_ai[ship3_ai[j][i - 1].x - 1][ship3_ai[j][i - 1].y].info != 3)
                    pole_ai[ship3_ai[j][i - 1].x - 1][ship3_ai[j][i -
                    1].y].info = 2; // ������� �� ���� �����, ����������� ����� �� ����� �������, �� ������� ������ ������� �������
                if (ship3_ai[j][i - 1].x + 1 < 10 && pole_ai[ship3_ai[j][i - 1].x + 1][ship3_ai[j][i - 1].y].info != 3)
                    pole_ai[ship3_ai[j][i - 1].x + 1][ship3_ai[j][i -
                    1].y].info = 2; // ������� �� ���� �����, ����������� ������ �� ����� �������, �� ������� ������ ������� �������

                for (k = 0; k < 3; k++) {
                    if ((ship3_ai[j][i - 1].x - 1 + k > -1) && (ship3_ai[j][i - 1].y - 1 > -1) &&
                        (ship3_ai[j][i - 1].x - 1 + k < 10) &&
                        (pole_ai[ship3_ai[j][i - 1].x - 1 + k][ship3_ai[j][i - 1].y - 1].info != 3))
                        pole_ai[ship3_ai[j][i - 1].x - 1 + k][ship3_ai[j][i - 1].y -
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    if ((ship3_ai[j][i - 1].x - 1 + k > -1) && (ship3_ai[j][i - 1].y + 1 < 10) &&
                        (ship3_ai[j][i - 1].x - 1 + k < 10) &&
                        (pole_ai[ship3_ai[j][i - 1].x - 1 + k][ship3_ai[j][i - 1].y + 1].info != 3))
                        pole_ai[ship3_ai[j][i - 1].x - 1 + k][ship3_ai[j][i - 1].y +
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
// ������� �� ���� ������ ����� ������ ������� ������� ���� ����� ����� ��� ������
                }

            }
        }
    }
    for (i = 3; i <= 5; i++) {
        if (dead_ship_of_ai[i] == false && pole_ai[ship2_ai[0][i - 3].x][ship2_ai[0][i - 3].y].info == 3 &&
            pole_ai[ship2_ai[1][i - 3].x][ship2_ai[1][i - 3].y].info == 3) {
            dead_ship_of_ai[i] = true;
            for (j = 0; j < 2; j++) {
                if (ship2_ai[j][i - 3].x - 1 > -1 && pole_ai[ship2_ai[j][i - 3].x - 1][ship2_ai[j][i - 3].y].info != 3)
                    pole_ai[ship2_ai[j][i - 3].x - 1][ship2_ai[j][i -
                    3].y].info = 2; // ������� �� ���� �����, ����������� ����� �� ����� �������, �� ������� ������ ������� �������
                if (ship2_ai[j][i - 3].x + 1 < 10 && pole_ai[ship2_ai[j][i - 3].x + 1][ship2_ai[j][i - 3].y].info != 3)
                    pole_ai[ship2_ai[j][i - 3].x + 1][ship2_ai[j][i -
                    3].y].info = 2; // ������� �� ���� �����, ����������� ������ �� ����� �������, �� ������� ������ ������� �������

                for (k = 0; k < 3; k++) {
                    if ((ship2_ai[j][i - 3].x - 1 + k > -1) && (ship2_ai[j][i - 3].y - 1 > -1) &&
                        (ship2_ai[j][i - 3].x - 1 + k < 10) &&
                        (pole_ai[ship2_ai[j][i - 3].x - 1 + k][ship2_ai[j][i - 3].y - 1].info != 3))
                        pole_ai[ship2_ai[j][i - 3].x - 1 + k][ship2_ai[j][i - 3].y -
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                    if ((ship2_ai[j][i - 3].x - 1 + k > -1) && (ship2_ai[j][i - 3].y + 1 < 10) &&
                        (ship2_ai[j][i - 3].x - 1 + k < 10) &&
                        (pole_ai[ship2_ai[j][i - 3].x - 1 + k][ship2_ai[j][i - 3].y + 1].info != 3))
                        pole_ai[ship2_ai[j][i - 3].x - 1 + k][ship2_ai[j][i - 3].y +
                        1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
// ������� �� ���� ������ ����� ������ ������� ������� ���� ����� ����� ��� ������
                }

            }
        }
    }
    for (i = 6; i <= 9; i++) {
        if (dead_ship_of_ai[i] == false && pole_ai[ship1_ai[i - 6].x][ship1_ai[i - 6].y].info == 3) {
            dead_ship_of_ai[i] = true;

            if (ship1_ai[i - 6].x - 1 > -1)
                pole_ai[ship1_ai[i - 6].x - 1][ship1_ai[i - 6].y].info = 2; // ������� �� ���� �����, ����������� ����� �� �������, �� ������� ������ ������� �������
            if (ship1_ai[i - 6].x + 1 < 10)
                pole_ai[ship1_ai[i - 6].x + 1][ship1_ai[i - 6].y].info = 2; // ������� �� ���� �����, ����������� ������ �� �������, �� ������� ������ ������� �������

            for (k = 0; k < 3; k++) {
                if ((ship1_ai[i - 6].x - 1 + k > -1) && (ship1_ai[i - 6].y - 1 > -1) && (ship1_ai[i - 6].x - 1 + k < 10))
                    pole_ai[ship1_ai[i - 6].x - 1 + k][ship1_ai[i - 6].y - 1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
                if ((ship1_ai[i - 6].x - 1 + k > -1) && (ship1_ai[i - 6].y + 1 < 10) && (ship1_ai[i - 6].x - 1 + k < 10))
                    pole_ai[ship1_ai[i - 6].x - 1 + k][ship1_ai[i - 6].y + 1].info = 2;  // ������� �� ���� �����, ����������� ���� �������, �� ������� ������ ������� �������
            }

        }
    }
}
void win() {   // ��������� ������� �� ���-����; ���� ���-�� �������, �� �������� ��� ������� � ���������� winner
    if (xod_of_player == true && dead_ship_of_ai[0] == true && dead_ship_of_ai[1] == true && dead_ship_of_ai[2] == true && dead_ship_of_ai[3] == true && dead_ship_of_ai[4] == true && dead_ship_of_ai[5] == true && dead_ship_of_ai[6] == true && dead_ship_of_ai[7] == true && dead_ship_of_ai[8] == true && dead_ship_of_ai[9] == true) {
        //winner = 'p';
    }
    if (xod_of_player == false && dead_ship_of_player[0] == true && dead_ship_of_player[1] == true && dead_ship_of_player[2] == true && dead_ship_of_player[3] == true && dead_ship_of_player[4] == true && dead_ship_of_player[5] == true && dead_ship_of_player[6] == true && dead_ship_of_player[7] == true && dead_ship_of_player[8] == true && dead_ship_of_player[9] == true) {
        //winner = 'a';
    }
}

bool player() { // ��������� ��� ���������� �������
    bool aim = 0; // ��������� ����� �� ��������� � ���������� ������ (1 - �����, 0 - �� �����)
    if (xod_of_player == 1) { // ��� ������
        do {
            printf("������� ���������� ��������\n");
            scanf("%i%i", &shot.x, &shot.y); //A=65 a=97 ��������� ���������� ��������
            if (pole_ai[shot.x][shot.y].info != 0 && pole_ai[shot.x][shot.y].info != 1) { // �������� �� ��, ��� ������� ����� � ��� ����� ��� ���
                printf("�� ��������\n");
            }
        } while (pole_ai[shot.x][shot.y].info != 0 && pole_ai[shot.x][shot.y].info != 1);
    }
    else { // ��� ����������
       // xod_of_player == 1;
        switch (hit) { // ����� �������� ������������ � ����������� �� ���������� ��������� �� 1-�� ������� �� ��� ����������
        case 0: { // �� ���� �� ����� => �������� ��������� �����, � ������� ����� ��������
            aim = false; // ������� ��������� ������ �� �����
            while (aim == false) {
                shot.x = rand() % 10;
                shot.y = rand() % 10;
                if (pole_player[shot.x][shot.y].info == 0 || pole_player[shot.x][shot.y].info == 1) aim = true;
            }
            break;
        }
        case 1: { // ����� ���� ��� => �������� ����� � ����������
            aim = false; // ������� ��������� ������ �� �����
            do {
                switch (rand() % 4) { // �������� ����������� ������ ��������� ����� �������; 0 - �����, 1 - �����, 2 - ���� , 3 - ������
                case 0: { // �����
                    if (shot_ai[0].y - 1 >= 0 && (pole_player[shot_ai[0].x][shot_ai[0].y - 1].info == 0 || pole_player[shot_ai[0].x][shot_ai[0].y - 1].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                        shot.x = shot_ai[0].x;
                        shot.y = shot_ai[0].y - 1;
                        aim = true;
                    }
                }
                case 1: { // �����
                    if (shot_ai[0].x - 1 >= 0 && (pole_player[shot_ai[0].x - 1][shot_ai[0].y].info == 0 || pole_player[shot_ai[0].x - 1][shot_ai[0].y].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                        shot.y = shot_ai[0].y;
                        shot.x = shot_ai[0].x - 1;
                        aim = true;
                    }
                }
                case 2: { // ����
                    if (shot_ai[0].y + 1 <= 9 && (pole_player[shot_ai[0].x][shot_ai[0].y + 1].info == 0 || pole_player[shot_ai[0].x][shot_ai[0].y + 1].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                        shot.x = shot_ai[0].x;
                        shot.y = shot_ai[0].y + 1;
                        aim = true;
                    }
                }
                case 3: { // ������
                    if (shot_ai[0].x + 1 <= 9 && (pole_player[shot_ai[0].x + 1][shot_ai[0].y].info == 0 || pole_player[shot_ai[0].x + 1][shot_ai[0].y].info == 1)) { // ���������� �� ����� ������ �� ���� � ����� ������� �� ���
                        shot.y = shot_ai[0].y;
                        shot.x = shot_ai[0].x + 1;
                        aim = true;
                    }
                }
                }
            } while (aim == false);
            break;
        }
        default: { // ����� 2 ��� ����� ��� => �������� ���� ����� � ������������ �������
            if (shot_ai[0].x == shot_ai[1].x) { // ������� ����� �����������
                aim = false;
                while (aim == false) {
                    switch (rand() % 4) { //
                    case 0: { // �������� � �����, ����������� ���� shot_ai[0].y ( - 1 )
                        if (shot_ai[0].y - 1 >= 0 && pole_player[shot_ai[0].x][shot_ai[0].y - 1].info != 2 && pole_player[shot_ai[0].x][shot_ai[0].y - 1].info != 3) {
                            shot.x = shot_ai[0].x;
                            shot.y = shot_ai[0].y - 1;
                            aim = true;
                        }
                        break;
                    }
                    case 1: { // �������� � �����, ����������� ���� shot_ai[0].y
                        if (shot_ai[0].y + 1 <= 9 && pole_player[shot_ai[0].x][shot_ai[0].y + 1].info != 2 && pole_player[shot_ai[0].x][shot_ai[0].y + 1].info != 3) {
                            shot.x = shot_ai[0].x;
                            shot.y = shot_ai[0].y + 1;
                            aim = true;
                        }
                        break;
                    }
                    case 2: { // �������� � �����, ����������� ���� shot_ai[1].y
                        if (shot_ai[1].y - 1 >= 0 && pole_player[shot_ai[1].x][shot_ai[1].y - 1].info != 2 && pole_player[shot_ai[1].x][shot_ai[1].y - 1].info != 3) {
                            shot.x = shot_ai[1].x;
                            shot.y = shot_ai[1].y - 1;
                            aim = true;
                        }
                        break;
                    }
                    case 3: { // �������� � �����, ����������� ���� shot_ai[1].y
                        if (shot_ai[1].y + 1 <= 9 && pole_player[shot_ai[1].x][shot_ai[1].y + 1].info != 2 && pole_player[shot_ai[1].x][shot_ai[1].y + 1].info != 3) {
                            shot.x = shot_ai[1].x;
                            shot.y = shot_ai[1].y + 1;
                            aim = true;
                        }
                        break;
                    }
                    }
                }
            }
            else { // ������� ����� �������������
                aim = false;
                while (aim == false) {
                    switch (rand() % 4) { //
                    case 0: { // �������� � �����, ����������� ����� shot_ai[0].x
                        if (shot_ai[0].x - 1 >= 0 && pole_player[shot_ai[0].x - 1][shot_ai[0].y].info != 2 && pole_player[shot_ai[0].x - 1][shot_ai[0].y].info != 3) {
                            shot.y = shot_ai[0].y;
                            shot.x = shot_ai[0].x - 1;
                            aim = true;
                        }
                        break;
                    }
                    case 1: { // �������� � �����, ����������� ������ shot_ai[0].x
                        if (shot_ai[0].x + 1 <= 9 && pole_player[shot_ai[0].x + 1][shot_ai[0].y].info != 2 && pole_player[shot_ai[0].x + 1][shot_ai[0].y].info != 3) {
                            shot.y = shot_ai[0].y;
                            shot.x = shot_ai[0].x + 1;
                            aim = true;
                        }
                        break;
                    }
                    case 2: { // �������� � �����, ����������� ����� shot_ai[1].x
                        if (shot_ai[1].x - 1 >= 0 && pole_player[shot_ai[1].x - 1][shot_ai[1].y].info != 2 && pole_player[shot_ai[1].x - 1][shot_ai[1].y].info != 3) {
                            shot.y = shot_ai[1].y;
                            shot.x = shot_ai[1].x - 1;
                            aim = true;
                        }
                        break;
                    }
                    case 3: { // �������� � �����, ����������� ������ shot_ai[1].x
                        if (shot_ai[1].x + 1 <= 9 && pole_player[shot_ai[1].x + 1][shot_ai[1].y].info != 2 && pole_player[shot_ai[1].x + 1][shot_ai[1].y].info != 3) {
                            shot.y = shot_ai[1].y;
                            shot.x = shot_ai[1].x + 1;
                            aim = true;
                        }
                        break;
                    }
                    }
                }
            }
            break;
        }
        }

    }
    return aim;
}

void shot_of_gamer() { // �������� � ������������ ��������
    if (xod_of_player == true) { // ��� ������
        switch (pole_ai[shot.x][shot.y].info) {
        case 0: { // �� �����
            printf("������");
            pole_ai[shot.x][shot.y].info = 2; // ������� �� ����
            xod_of_player = false; // ����� ����
            break;
        }
        case 1: { // �����
            printf("���������");
            pole_ai[shot.x][shot.y].info = 3; // ������� �� ����
            dead_of_ships_ai(); // ���� �� �������?
            break;
        }
        }
    }
    else { // ��� ����������
        switch (pole_player[shot.x][shot.y].info) {
        case 0: { // �� �����
            printf("��������� ��������� � %i %i", shot.x, shot.y);
            pole_player[shot.x][shot.y].info = 2; // ������� �� ����
            xod_of_player = true; // ����� ����
            break;
        }
        case 1: { // ����� (��� ����� ����  shot_ai[2].(x or y)) ����� ��������� �����(-�) ���������!!!!!!!!!!!!!!!!!!
            printf("��������� ����� � %i %i", shot.x, shot.y);
            pole_player[shot.x][shot.y].info = 3; // ������� �� ����
            switch (hit) { // ����������� ����� ��������� � ���������� �� ���������� ��������� �� ����� �������
            case 0: { // �� ����� ������� �� ���� �� �����
                shot_ai[0].x = shot.x;
                shot_ai[0].y = shot.y;
                break;
            }
            case 1: { // �� ����� ������� ����� ���� ���
                shot_ai[1].x = shot.x;
                shot_ai[1].y = shot.y;
                break;
            }
            default: { // �� ����� ������� ����� 2 ��� ����� ���  shot_ai[0] � shot_ai[1] ������ ���� �������� ��������� ������� �������
                if (shot_ai[0].x == shot_ai[1].x) { // ������� ����� �����������
                    if (abs(shot_ai[1].y - shot.y) < abs(shot_ai[0].y - shot.y)) shot_ai[1].y = shot.y; // ����������� ���������� �� ����� ��������
                    else shot_ai[0].y = shot.y;
                }
                else {
                    if (abs(shot_ai[1].x - shot.x) < abs(shot_ai[0].x - shot.x)) shot_ai[1].x = shot.x;
                    else shot_ai[0].x = shot.x;
                }
                break;
            }
            }
            hit = hit + 1; // ����� �� ���� ��� ������ �� ������ �������
            dead_of_ships_player(); // ���� �� �������?
            break;
        }
        }
        //xod_of_player = true;
    }
}

void graphic() {
    int x, y;
    printf("\n");
    printf("     ���������                    �����\n");
    for (x = 1; x <= 47; x++) printf("-");
    printf("\n");
    for (y = -1; y <= 9; y++) {
        if (y != -1) {
            printf("%i", y); // ���������� �� ��� �
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|"); // ������� ����� �������� �� �����������
                else {
                    switch (pole_ai[(x - 2) / 2][y].info) { // ������
                    case 2: { // ������ ������
                        printf("0");
                        break;
                    }
                    case 3: { // ������ � �������
                        printf("1");
                        break;
                    }
                    default: { // ���������� ������
                        printf(" "); // & or SPACE
                        break;
                    }
                    }
                }
            }



            printf(" | ");
            printf("%i", y); // ���������� �� ��� �
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|"); // ������� ����� �������� �� �����������
                else {
                    switch (pole_player[(x - 2) / 2][y].info) { // ������
                    case 0: { // ���������� ��� �������
                        printf(" ");
                        break;
                    }
                    case 1: { // ���������� � �������
                        printf("*");
                        break;
                    }
                    case 2: { // �������� ��� �������
                        printf("0");
                        break;
                    }
                    case 3: { // �������� � �������
                        printf("1");
                        break;
                    }
                    }
                }
            }




            printf("\n");
            for (x = 1; x <= 22; x++) printf("-"); // ������� ����� �������� �� ���������

            printf(" | ");
            for (x = 1; x <= 22; x++) printf("-"); // ������� ����� �������� �� ���������




        }
        else { // ���������� �� ��� �
            printf(" ");
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|"); // ������� ����� �������� �� �����������
                else {
                    printf("%i", (x - 2) / 2); // ���������� �� ��� �
                }
            }


            printf(" | ");
            printf(" ");
            for (x = 1; x <= 21; x++) {
                if (x % 2 == 1) printf("|");
                else {
                    printf("%i", (x - 2) / 2);
                }
            }



            printf("\n");
            for (x = 1; x <= 22; x++) printf("-");

            printf(" | ");
            for (x = 1; x <= 22; x++) printf("-");




        }
        printf("\n");
    }
}

/*
void Test(Field* in_field_star_1, Field* in_field_star_2, Field in_field_1, Field in_field_2)
{
    in_field_star_1->change_info_cell(0, 0, 0);
    int* test = new int;
    *test = 1;
    printf("test: %i  &test: %i  *test: %i", test, &test, *test);
    system("pause");
} */





int main() {
    setlocale(LC_ALL, "Russian");
    Field field_player, field_computer;
    Ship ships_player[10], ships_computer[10]; // 0 - ��������������; 1,2 - ������������; 3..5 - �������������, 6..9 - �������������
    bool turn_of_player = false;



    char winner = 'n'; // ���������� ���������� (�������: p - �����, a - ���������, n - ���� ��� ����� �� �������)



    int i, j;
    bool need_wait;
    place_ships_of_player(&field_player, ships_player);
    place_ships_of_computer(&field_computer, ships_computer);
    graphic_develop_class_2(field_player, field_computer);







    srand(time(NULL));
    if (rand() % 2 == 1) // ����������, ��� ����� ������
    {
        turn_of_player = 1; // ������ ����� �����
    }
    else
    {
        turn_of_player = 0; // ������ ����� ���������
    }
    while (winner == 'n')
    {

    }
        /*for (i = 0; i < 10; i++) { // ��������� ������ ����� � ������� �� ������
        dead_ship_of_ai[i] = false; // ��� ������� ����
        dead_ship_of_player[i] = false; // ��� ������� ����
        for (j = 0; j < 10; j++) {
            pole_player[i][j].info = 0;
            pole_ai[i][j].info = 0;
        }
    }*/
    /*
    
    point();
    
    ship_ai();
    for (i = 0; i < 10; i++) // ��������� ������ ���� ����������
        for (j = 0; j < 10; j++) {
            if (pole_ai[i][j].info != 0 && pole_ai[i][j].info != 1) {
                pole_ai[i][j].info = 0;
            }
        }
    if (rand() % 2 == 1) xod_of_player = 1; // ����������, ��� ����� ������
    else xod_of_player = 0;
    xod_of_player = 1;
    //  graphic_develop();
    graphic();
    while (winner == 'n') {
        need_wait = player();
        shot_of_gamer();
        graphic();       
            //system("pause");
            Sleep(3000);
            printf("\n");
        
        win();
        //   graphic_develop();
    }
    if (winner == 'a') {
        printf("YOU LOSE");
    }
    if (winner == 'p') {
        printf("YOU WIN");
    }*/    
    return 0; //srand ( time(NULL) ); rand()%10
}