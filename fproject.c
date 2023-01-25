#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int i = 0, main_array[32], count_2 = -1, makan_stack = 0, stack[4];
char dastorat[100], har_khat[100], meghdar_sabet[8], dastorat_2[100];
void HELP();
void ADD(int, int, int);
void SUB(int, int, int);
void ADDI(int, int, int);
void SUBI(int, int, int);
void MOV(int, int, int);
void MULL(int, int);
void DUMP_REGS();
void DUMP_REGS_F();
void SWP(int, int);
void INPUT();
void OUTPUT();
void AND(int, int, int);
void XOR(int, int, int);
void OR(int, int, int);
void ANDI(int, int, int);
void ORI(int, int, int);
void XORI(int, int, int);
void check_binary_addad(int);
void check_andaze_javab(int);
void overflow_ADD(int, int, int);
void overflow_SUB(int, int, int);
void DIV(int, int);
void POP(int);
void PUSH(int);
void MUL(int, int, int);
void power(int, int, int);
void SQRT(int, int);
void MULI(int, int, int);
void POWI(int, int, int);
void SQRTI(int, int);
FILE *stream;
int main(int argc, char *argv[])
{

    char file_name[25];
    strcpy(file_name, argv[1]);

    int count = 0, count_1 = 0, charkhidan = 0, x, y, z;

    int counting_slash = 0;
    int makan_slash;

    FILE *stream = fopen(file_name, "r");
    while (EOF != fscanf(stream, "%[^\n]\n", dastorat))
    {
        charkhidan++;
        if (charkhidan > count)
        {
            for (int i = 0; i < 100; i++)
            {
                if (dastorat[i] == '/' && dastorat[i + 1] == '/')
                {
                    makan_slash = i;
                    counting_slash++;
                    break;
                }
            }

            if (counting_slash == 1)
            {
                for (int i = 100; i >= makan_slash; i--)
                {
                    dastorat[i] = dastorat_2[i];
                }

                counting_slash = 0;
            }

            for (int i = 0; i < 100; i++)
            {
                dastorat[i] = toupper(dastorat[i]);
            }

            if (dastorat[0] == 'E' && dastorat[3] == 'T')
            {
                dastorat[4] = ' ';
            }

            else if (dastorat[0] == 'O' && dastorat[5] == 'T')
            {
                dastorat[6] = ' ';
            }
            else if (dastorat[0] == 'I' && dastorat[4] == 'T')
            {
                dastorat[5] = ' ';
            }
            else if (dastorat[0] == 'D' && dastorat[10] == 'F')
            {

                dastorat[11] = ' ';
            }
            else if (dastorat[0] == 'D' && dastorat[8] == 'S')
            {
                dastorat[9] = ' ';
            }
            else if (dastorat[0] == 'H' && dastorat[3] == 'P')
            {
                dastorat[4] = ' ';
            }
            for (i = 0; dastorat[i] != ' '; i++)
            {
                har_khat[i] = dastorat[i];
            }
            count_2++;
            har_khat[i + 1] = '\0';
            if (strcmp(har_khat, "ADD") == 0)
            {

                sscanf(dastorat, "ADD S%d, S%d, S%d", &x, &y, &z);
                if (13 <= strlen(dastorat) <= 16 && 0 <= x <= 32 && 0 <= y <= 32 && 0 <= z <= 32)
                {
                    ADD(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "SUB") == 0)
            {

                sscanf(dastorat, "SUB S%d, S%d, S%d", &x, &y, &z);
                if (13 <= strlen(dastorat) <= 16 && 0 <= x <= 32 && 0 <= y <= 32 && 0 <= z <= 32)
                {
                    SUB(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }

            else if (strcmp(har_khat, "AND") == 0)
            {

                sscanf(dastorat, "AND S%d, S%d, S%d", &x, &y, &z);
                if (13 <= strlen(dastorat) <= 16 && 0 <= x <= 32 && 0 <= y <= 32 && 0 <= z <= 32)
                {
                    AND(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "XOR") == 0)
            {

                sscanf(dastorat, "XOR S%d, S%d, S%d", &x, &y, &z);
                if (13 <= strlen(dastorat) <= 16 && 0 <= x <= 32 && 0 <= y <= 32 && 0 <= z <= 32)
                {
                    XOR(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "OR") == 0)
            {

                sscanf(dastorat, "OR S%d, S%d, S%d", &x, &y, &z);
                if (12 <= strlen(dastorat) <= 15 && 0 <= x <= 32 && 0 <= y <= 32 && 0 <= z <= 32)
                {
                    OR(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "ADDI") == 0)
            {

                sscanf(dastorat, "ADDI S%d, S%d, %d", &x, &y, &z);
                if (13 <= strlen(dastorat) && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    ADDI(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }

            else if (strcmp(har_khat, "SUBI") == 0)
            {

                sscanf(dastorat, "SUBI S%d, S%d, %d", &x, &y, &z);
                if (13 <= strlen(dastorat) && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    SUBI(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "XORI") == 0)
            {

                sscanf(dastorat, "XORI S%d, S%d, %d", &x, &y, &z);
                if (13 <= strlen(dastorat) && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    XORI(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "ORI") == 0)
            {

                sscanf(dastorat, "ORI S%d, S%d, %d", &x, &y, &z);
                if (12 <= strlen(dastorat) && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    ORI(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "ANDI") == 0)
            {

                sscanf(dastorat, "ANDI S%d, S%d, %d", &x, &y, &z);
                if (13 <= strlen(dastorat) && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    ANDI(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "MOV") == 0)
            {

                for (int j = 0; j < sizeof(dastorat); j++)
                {
                    if (dastorat[j] == 'S')
                    {
                        count_1++;
                    }
                }
                if (count_1 == 2)
                {
                    sscanf(dastorat, "MOV S%d, S%d", &x, &y);
                    count_1 = 0;
                }
                else
                {

                    sscanf(dastorat, "MOV S%d, %d", &x, &y);
                    count_1 = 0;
                }
                MOV(x, y, count_1);
            }
            else if (strcmp(har_khat, "SWP") == 0)
            {

                sscanf(dastorat, "SWP S%d, S%d", &x, &y);
                if (9 <= strlen(dastorat) < 11 && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    SWP(x, y);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "HELP") == 0)
            {

                HELP();
            }
            else if (strcmp(har_khat, "DUMP_REGS") == 0)
            {

                DUMP_REGS();
            }

            else if (strcmp(har_khat, "DUMP_REGS_F") == 0)
            {

                DUMP_REGS_F();
            }
            else if (strcmp(har_khat, "INPUT") == 0)
            {

                INPUT();
            }
            else if (strcmp(har_khat, "OUTPUT") == 0)
            {

                OUTPUT();
            }
            else if (strcmp(har_khat, "MULL") == 0)
            {

                sscanf(dastorat, "MULL S%d, S%d", &x, &y);
                if (10 <= strlen(dastorat) <= 12 && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    MULL(x, y);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "POP") == 0)
            {

                sscanf(dastorat, "POP S%d", &x);
                if (13 <= strlen(dastorat) <= 14 && 0 <= x <= 32)
                {
                    POP(x);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }

            else if (strcmp(har_khat, "PUSH") == 0)
            {

                sscanf(dastorat, "PUSH S%d", &x);
                if (14 <= strlen(dastorat) <= 15 && 0 <= x <= 32)
                {
                    PUSH(x);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }

            else if (strcmp(har_khat, "JMP") == 0)
            {

                sscanf(dastorat, "JMP %d", &x);
                count = x;
                charkhidan = 0;
                rewind(stream);
            }
            else if (strcmp(har_khat, "MUL") == 0)
            {

                sscanf(dastorat, "MUL S%d, S%d, S%d", &x, &y, &z);
                if (13 <= strlen(dastorat) <= 16 && 0 <= x <= 32 && 0 <= y <= 32 && 0 <= z <= 32)
                {
                    MUL(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "POW") == 0)
            {

                sscanf(dastorat, "POW S%d, S%d, S%d", &x, &y, &z);
                if (13 <= strlen(dastorat) <= 16 && 0 <= x <= 32 && 0 <= y <= 32 && 0 <= z <= 32)
                {
                    power(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "SQRT") == 0)
            {

                sscanf(dastorat, "SQRT S%d, S%d", &x, &y);
                if (10 <= strlen(dastorat) <= 12 && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    SQRT(x, y);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "MULI") == 0)
            {

                sscanf(dastorat, "MULI S%d, S%d, %d", &x, &y, &z);
                if (13 <= strlen(dastorat) && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    MULI(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "POWI") == 0)
            {

                sscanf(dastorat, "POWI S%d, S%d, %d", &x, &y, &z);
                if (13 <= strlen(dastorat) && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    POWI(x, y, z);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "SQRTI") == 0)
            {

                sscanf(dastorat, "SQRTI S%d, %d", &x, &y);
                if (10 <= strlen(dastorat) && 0 <= x <= 32)
                {
                    SQRTI(x, y);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }
            else if (strcmp(har_khat, "DIV") == 0)
            {

                sscanf(dastorat, "DIV S%d, S%d", &x, &y);
                if (9 <= strlen(dastorat) <= 9 && 0 <= x <= 32 && 0 <= y <= 32)
                {
                    DIV(x, y);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("Error in the variable has occoured but the command is right");
                    printf("\033[0m");
                }
            }

            else if (strcmp(har_khat, "EXIT") == 0)
            {

                break;
            }

            else
            {
                printf("\033[0;31m");
                printf("\n%s is not recognized as an internal or external command,operable program or batch file.", har_khat);
                printf("\033[0m");
            }
            for (int i = 0; i < 100; i++)
            {
                har_khat[i] = dastorat_2[i];
            }
        }
    }
    if (charkhidan==0)
    {
        printf("this file did not exist");
    }
    
}
void ADD(int x, int y, int z)
{
    main_array[x] = main_array[y] + main_array[z];
    overflow_ADD(x, main_array[y], main_array[z]);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void SUB(int x, int y, int z)
{
    main_array[x] = main_array[y] - main_array[z];
    overflow_SUB(x, y, z);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void MOV(int x, int y, int count)
{

    if (count == 2)
    {
        main_array[x] = main_array[y];
    }
    else
    {
        main_array[x] = y;
    }
}
void ADDI(int x, int y, int z)
{
    main_array[x] = z + main_array[y];
    overflow_ADD(x, main_array[y], main_array[z]);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void SUBI(int x, int y, int z)
{
    main_array[x] = main_array[y] - z;
    overflow_SUB(x, y, z);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void SWP(int x, int y)
{
    int c;

    c = main_array[x];
    main_array[x] = main_array[y];
    main_array[y] = c;
}
void DUMP_REGS()
{

    for (int i = 0; i < 32; i++)
    {
        if (i == 0)
        {
            printf("\n");
            printf("\033[0:34m");
            printf("sobat_omomi:");
        }
        printf(" %d:%d ", i, main_array[i]);
        if (i == 31)
        {
            printf("\n");
            printf("\033[0:34m");
            printf("sobat_vaziat:");
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf(" %d:%d", i, meghdar_sabet[i]);
        if (i == 7)
        {
            printf("\n");
        }
    }
}
void DUMP_REGS_F()
{

    FILE *copy_kardan_info;
    copy_kardan_info = fopen("regs.txt", "w");
    fprintf(copy_kardan_info, "sobat_omomi:");
    for (int i = 0; i < 32; i++)
    {
        if (i == 0)
        {
            fprintf(copy_kardan_info, "\n");
        }
        fprintf(copy_kardan_info, "%d ", main_array[i]);
        if (i == 31)
        {
            fprintf(copy_kardan_info, "\n");
        }
    }
    fprintf(copy_kardan_info, "sobat_vaziat:");
    for (int i = 0; i < 8; i++)
    {

        fprintf(copy_kardan_info, " %d ", meghdar_sabet[i]);
    }
    fclose(copy_kardan_info);
}
void INPUT()
{
    scanf("%d", &main_array[0]);
}
void OUTPUT()
{
    printf("\narray_sobat_omomi_aval:%ld", main_array[0]);
}
void AND(int x, int y, int z)
{
    main_array[x] = main_array[y] & main_array[z];
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void XOR(int x, int y, int z)
{
    main_array[x] = main_array[y] ^ main_array[z];
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void OR(int x, int y, int z)
{
    main_array[x] = main_array[y] | main_array[z];
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void ANDI(int x, int y, int z)
{
    main_array[x] = main_array[y] & z;
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void XORI(int x, int y, int z)
{

    main_array[x] = main_array[y] ^ z;
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void ORI(int x, int y, int z)
{
    main_array[x] = main_array[y] | z;
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void HELP()
{
    printf("\nAdd : jamm kardan 2 adadi ke type shode ast ke an 2 addad ra dar araye asli mizarim va jamm mikonim\nva rikhtan on dar araye asli entekhabi\n");
    printf("Sub :  kamm kardan 2 adadi ke type shode ast ke an 2 addad ra dar araye asli mizarim va kamm mikonim\nva rikhtan on dar araye asli entekhabi\n");
    printf("Addi : jamm kardan 2 adadi ke type shode ast va rikhtan on dar araye asli entekhabi\n");
    printf("Subi : jamm kardan 2 adadi ke type shode ast va rikhtan on dar araye asli entekhabi\n");
    printf("Mov :  meghdar dehi ba addad ya yek ozv araye asli va rikhtan on dar araye asli entekhabi\n");
    printf("And : tabdil kardan 2 addad dade shode va peida kardan on location dar array asli va be tabdil bite kardan\nanha va check kardan T or F on va rikhtan on dar araye asli entekhabi\n");
    printf("Or : tabdil kardan 2 addad dade shode va peida kardan on location dar array asli va be tabdil bite kardan\nanha va check kardan T or F on va rikhtan on dar araye asli entekhabi\n");
    printf("Xor : tabdil kardan 2 addad dade shode va peida kardan on location dar array asli va be tabdil bite kardan\nanha va check kardan T or F on va rikhtan on dar araye asli entekhabi\n");
    printf("Andi : tabdil kardan 2 addad dade shode va bite kardan anha va check kardan T or F \n on va rikhtan on dar araye asli entekhabi\n");
    printf("Xori:  tabdil kardan 2 addad dade shode va bite kardan anha va check kardan T or F \n on va rikhtan on dar araye asli entekhabi\n");
    printf("Ori :  tabdil kardan 2 addad dade shode va bite kardan anha va check kardan T or F \n on va rikhtan on dar araye asli entekhabi\n");
    printf("DUMP_REGS : print kardan array asli va aray vaziat dar terminal\n");
    printf("DUMP_REGS_F : print kardan array asli va array vaziat dar file \n");
    printf("INPUT : geraftan dasti array asli ozv aval dar terminal\n");
    printf("OUTPUT : print kardan array asli ozv aval dar terminal\n");
    printf("SWP : peyda kardan 2 addad asli va location anha dar array asli va avaz kardan meghdar anha baham\n");
    printf("JMP : paridan be khat mored nazar va shoro kardan az on khat\n");
    printf("DIV : taghsim krdan addad dovomi bar avali va rikhtan baghimande on dar addad dovomi \nva kharej ghesmat dar addad aval \n");
    printf("MULL : zarb kardan 2 addad dar ham va kam kardan 4 byte az javab va rikhtan on dar yeki va 4 byte\n ezafe kardan va rikhtan on dar addad avali\n");
    printf("PUSH: Add the number you give the terminal to memory in stack\n");
    printf("POP: Remove the number  from stack and memory and add to array asli\n");
    printf("MUL: zarb kardan 2 addad dade shode dar ham bad peida karan loc \nanha dar array asli va rikhtan on dar makan addad aval dar array asli\n");
    printf("POW:  be tawan resondan 2 addad dade shode dar ham bad peida karan loc \nanha dar array asli va rikhtan on dar makan addad aval dar array asli\n");
    printf("SQRT:   radical gereftan az addad dade shode bad az inke peida karan loc \nan dar array asli va rikhtan on dar makan addad aval dar array asli\n");
    printf("MULI: zarb kardan 2 addad dar ham va rikhtan an dar loc addad avli dar array asli\n");
    printf("POWI: be tawan resondan 2 addad dar ham va rikhtan an dar loc addad avli dar array asli\n");
    printf("SQRTI:radical gereftan az addad dade shodeva rikhtan an dar loc addad avli dar array asli\n");
    printf("EXIT : kharaj shodan az dastorha va exit shodan az terminal\n");
}
void DIV(int x, int y)
//DSDSDS
{
    main_array[x] = main_array[x] / main_array[y];
    main_array[y] = main_array[x] % main_array[y];

    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
    check_binary_addad(main_array[y]);
    check_andaze_javab(main_array[y]);
}
void MULL(int x, int y)
{
    int c = main_array[x] * main_array[y];
    main_array[x] = c + 4;
    main_array[y] = c - 4;
    if (main_array[y] < 0)
    {
        main_array[y] += 255;
    }
    if (main_array[x] > 255)
    {
        main_array[x] -= 255;
    }
}
void check_binary_addad(int num)
{
    int count = 0;
    if (num == 0)
    {
        meghdar_sabet[0] = 0;
        return;
    }

    int binary_tabdil[32];
    int i = 0;

    for (; num > 0;)
    {
        binary_tabdil[i++] = num % 2;
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        if (binary_tabdil[j] == 1)
        {
            count++;
        }
    }

    if (count % 2 == 1)
    {
        meghdar_sabet[0] = 1;
    }
    else
    {
        meghdar_sabet[0] = 0;
    }
}
void check_andaze_javab(int num)
{
    if (num == 0)
    {
        meghdar_sabet[1] = 1;
        meghdar_sabet[2] = 0;
    }
    else if (num < 0)
    {
        meghdar_sabet[2] = 1;
        meghdar_sabet[1] = 0;
    }
    else if (num > 0)
    {
        meghdar_sabet[2] = 0;
        meghdar_sabet[1] = 0;
    }
}
void overflow_ADD(int x, int addad_1, int addad_2)
{
    if (addad_2 > 0 && addad_1 > 0 && main_array[x] < 0)
    {
        main_array[x] = 0;
        meghdar_sabet[5] = 1;
    }
    else if (addad_1 < 0 && addad_2 < 0 && main_array[x] > 0)
    {

        main_array[x] = 0;
        meghdar_sabet[5] = 1;
    }
    else
    {
        meghdar_sabet[5] = 0;
    }
}
void overflow_SUB(int x, int y, int z)
{

    if (main_array[y] < 0 && main_array[z] > 0 && main_array[x] < 0)
    {
        main_array[x] = 0;
        meghdar_sabet[5] = 1;
    }
    else if (main_array[y] > 0 && main_array[z] < 0 && main_array[x] > 0)
    {

        main_array[x] = 0;
        meghdar_sabet[5] = 1;
    }
    else if (main_array[y] < 0 && main_array[z] > 0 && main_array[x] > 0)
    {

        main_array[x] = 0;
        meghdar_sabet[5] = 1;
    }
    else if (main_array[y] > 0 && main_array[z] < 0 && main_array[x] < 0)
    {

        main_array[x] = 0;
        meghdar_sabet[5] = 1;
    }
    else
    {
        meghdar_sabet[5] = 0;
    }
}
void PUSH(int x)
{
    if (makan_stack < 5)
    {
        stack[makan_stack] = main_array[x];
        main_array[x] = 0;
        makan_stack++;
    }
    else
    {
        printf("\nan error has occurred :\n the memory in full and its ready to overflow please pop some information first");
    }
}
void POP(int x)
{
    if (makan_stack > 0)
    {
        main_array[x] = stack[makan_stack];
        stack[makan_stack] = 0;
        makan_stack--;
    }
    else
    {
        printf("\nan error has occurred :\n the memory in empty please push some information first");
    }
}
void MUL(int x, int y, int z)
{
    main_array[x] = main_array[y] * main_array[z];
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void power(int x, int y, int z)
{
    main_array[x] = pow(main_array[x], main_array[z]);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void SQRT(int x, int y)
{
    main_array[x] = sqrt(main_array[y]);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void MULI(int x, int y, int z)
{
    main_array[x] = main_array[y] * main_array[z];
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void POWI(int x, int y, int z)
{
    main_array[x] = pow(main_array[y], z);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
void SQRTI(int x, int y)
{
    main_array[x] = sqrt(y);
    check_binary_addad(main_array[x]);
    check_andaze_javab(main_array[x]);
}
