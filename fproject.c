#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int i = 0, main_array[32], count_2 = -1;
char dastorat[100], har_khat[100], meghdar_sabet[8],dastorat_2[100];
void HELP();
void ADD(int, int, int);
void SUB(int, int, int);
void ADDI(int, int, int);
void SUBI(int, int, int);
void MOV(int, int, int);
void DUMP_REGS();
void DUMP_REGS_F();
void SWP(int, int);
void INPUT();
void OUTPUT();
void AND(int, int, int);
void XOR(int, int, int);
void OR(int, int, int);
void JMP(int,char []);
void ANDI(int, int, int);
void ORI(int, int, int);
void XORI(int, int, int);
void check_binary_addad(int);
void check_andaze_javab(int);
void overflow_ADD(int, int, int);
void overflow_SUB(int, int, int);
void DIV(int ,int);
FILE *stream;
char exit_asli[3],input[4],help[3],output[5],d_r[8],d_r_f[11],input_r[4],output_r[5],d_r_r[8],
d_r_f_r[10],exit_r[3],help_r[3];

int main()
{

char file_name[100];
for (int i = 0; i < 100; i++)
{
    file_name[i] = ' ';
}

// scanf("%d",file_name);
int count = 0, count_1 = 0, x, y, z;

//     for (int i = 0; i < 100; i++)
// {
//     dastorat_2[i] = ' ';
// }
int v=0;
    scanf("%s",file_name);
    FILE *stream = fopen(file_name, "r");
    while (EOF != fscanf(stream, "%[^\n]\n", dastorat))
    {v++;
        
        // if (v==8)
        // {
        //     printf("%s",dastorat);
        
        // }
        for (int i = 0; i < 100; i++)
        {
            dastorat[i] = toupper(dastorat[i]);
        }
        
        if (dastorat[0]=='E'&&dastorat[3]=='T')
        {
            for (int i = 0; i < 4; i++)
            {
                exit_asli[i] = dastorat[i];
            }
            
        }
        
        else if (dastorat[0]=='O'&&dastorat[5] =='T')
        {
            for (int i = 0; i < 6; i++)
            {
                output[i] = dastorat[i];
            }
            
        }
        else if (dastorat[0]=='I'&&dastorat[4] =='T')
        {
            for (int i = 0; i < 5; i++)
            {
                input[i] = dastorat[i];
            }
            
        }
        else if (dastorat[0]=='D'&&dastorat[10] =='F')
        {
            
            for (int i = 0; i < 11; i++)
            {
                d_r_f[i] = dastorat[i];
            }
            // printf("%s",d_r_f);
            d_r_f[11] = ' ';
        }
        else if (dastorat[0]=='D'&&dastorat[8] =='S')
        {
            for (int i = 0; i < 9; i++)
            {
                d_r[i] = dastorat[i];
            }
            
        }
        else if (dastorat[0]=='H'&&dastorat[3] =='P')
        {
            for (int i = 0; i < 4; i++)
            {
                help[i] = dastorat[i];
            }
            
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
            ADD(x, y, z);
        }
        else if (strcmp(har_khat, "SUB") == 0)
        {
            
            sscanf(dastorat, "SUB S%d, S%d, S%d", &x, &y, &z);
            SUB(x, y, z);
        }

        else if (strcmp(har_khat, "AND") == 0)
        {

            sscanf(dastorat, "AND S%d, S%d, S%d", &x, &y, &z);
            AND(x, y, z);
        }
        else if (strcmp(har_khat, "XOR") == 0)
        {

            sscanf(dastorat, "XOR S%d, S%d, S%d", &x, &y, &z);
            XOR(x, y, z);
        }
        else if (strcmp(har_khat, "OR") == 0)
        {

            sscanf(dastorat, "OR S%d, S%d, S%d", &x, &y, &z);
            OR(x, y, z);
        }
        else if (strcmp(har_khat, "ADDI") == 0)
        {

            sscanf(dastorat, "ADDI S%d, S%d, %d", &x, &y, &z);
            ADDI(x, y, z);
        }

        else if (strcmp(har_khat, "SUBI") == 0)
        {

            sscanf(dastorat, "SUBI S%d, S%d, %d", &x, &y, &z);
            SUBI(x, y, z);
        }
        else if (strcmp(har_khat, "XORI") == 0)
        {

            sscanf(dastorat, "XORI S%d, S%d, %d", &x, &y, &z);
            XORI(x, y, z);
        }
        else if (strcmp(har_khat, "ORI") == 0)
        {

            sscanf(dastorat, "ORI S%d, S%d, %d", &x, &y, &z);
            XORI(x, y, z);
        }
        else if (strcmp(har_khat, "ANDI") == 0)
        {

            sscanf(dastorat, "ANDI S%d, S%d, %d", &x, &y, &z);
            ANDI(x, y, z);
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
            SWP(x, y);
        }
        else if (strcmp(help, "HELP") == 0)
        {
            
            HELP();
            for (int w = 0; w < 4; w++)
            {
                
                help[w] = help_r[w];
            }
            
        }
        else if (strcmp(d_r, "DUMP_REGS") == 0)
        {
            // printf("dump_regs");
            DUMP_REGS();
            for (int w = 0; w < 9; w++)
            {
                
                d_r[w] = d_r_r[w];
            }
            
        }

        else if (strcmp(d_r_f,"DUMP_REGS_F ") == 0)
        {   
            // printf("dump_regs_f");

            DUMP_REGS_F();
        for (int w = 0; w < 11; w++)
            {
                d_r_f[w] = d_r_f_r[w];
            }
            
            
        }
        else if (strcmp(input, "INPUT") == 0)
        {
        // printf("input");
        INPUT();
         
        for (int w = 0; w < 5; w++)
            {
                input[w] = input_r[w];
            }
        }
        else if (strcmp(output, "OUTPUT") == 0)
        {
            // printf("output");
            OUTPUT();
            for (int w = 0; w < 6; w++)
            {
                output[w] = output_r[w];
            }
            
            
            
        }
        else if (strcmp(har_khat, "JMP") == 0)
        {

            sscanf(dastorat, "JMP %d", &x);
            
            JMP(x,file_name);
            return 0;
        }
        else if (strcmp(exit_asli, "EXIT") == 0)
        { 
            for (int i = 0; i < 4; i++)
            {
                exit_asli[i] = exit_r[i];
            }
            
            break;
        }
        else if (strcmp(har_khat, "DIV") == 0)
        {

            sscanf(dastorat, "DIV S%d, S%d", &x, &y);
            DIV(x, y);
        }
        else
        {
            printf("\n%s is not recognized as an internal or external command,operable program or batch file."
            , har_khat);
        }
        for (int i = 0; i < 100; i++)
        {
            har_khat[i] = dastorat_2[i];
        }
        
       
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
            printf("sobat_omomi:");
        }
        printf(" %d:%d ", i,main_array[i]);
        if (i == 31)
        {
            printf("\n");
            printf("sobat_vaziat:");
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf(" %d:%d", i,meghdar_sabet[i]);
    if (i==7)
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
{   scanf("%d",&main_array[0]);
    // (:      ):      |:
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

void JMP(int line,char file[100])
{ 
    int d = 0, x, y, z, count_1 = 0, count = 0;
    FILE *jump;
    jump = fopen(file, "r");
    // fscanf(jump, "%[^\n]\n", dastorat);
    // printf("%s",dastorat);
    while (EOF != fscanf(jump, "%[^\n]\n", dastorat))
    {  
         d++;
        if (d > line)
        {
            if (dastorat[0]=='E'&&dastorat[3]=='T')
        {
            for (int i = 0; i < 4; i++)
            {
                exit_asli[i] = dastorat[i];
            }
            
        }        
    else if (dastorat[0]=='O'&&dastorat[5] =='T')
        {
            for (int i = 0; i < 6; i++)
            {
                output[i] = dastorat[i];
            }
            
        }
        else if (dastorat[0]=='I'&&dastorat[5] =='T')
        {
            for (int i = 0; i < 6; i++)
            {
                input[i] = dastorat[i];
            }
            
        }
        else if (dastorat[0]=='D'&&dastorat[10] =='F')
        {
            
            for (int i = 0; i < 11; i++)
            {
                d_r_f[i] = dastorat[i];
            }
            // printf("%s",d_r_f);
            d_r_f[11] = ' ';
        }
        else if (dastorat[0]=='D'&&dastorat[8] =='S')
        {
            for (int i = 0; i < 9; i++)
            {
                d_r[i] = dastorat[i];
            }
            
        }
        else if (dastorat[0]=='H'&&dastorat[3] =='P')
        {
            for (int i = 0; i < 4; i++)
            {
                help[i] = dastorat[i];
            }
            
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
            ADD(x, y, z);
        }
        else if (strcmp(har_khat, "SUB") == 0)
        {
            
            sscanf(dastorat, "SUB S%d, S%d, S%d", &x, &y, &z);
            SUB(x, y, z);
        }

        else if (strcmp(har_khat, "AND") == 0)
        {

            sscanf(dastorat, "AND S%d, S%d, S%d", &x, &y, &z);
            AND(x, y, z);
        }
        else if (strcmp(har_khat, "XOR") == 0)
        {

            sscanf(dastorat, "XOR S%d, S%d, S%d", &x, &y, &z);
            XOR(x, y, z);
        }
        else if (strcmp(har_khat, "OR") == 0)
        {

            sscanf(dastorat, "OR S%d, S%d, S%d", &x, &y, &z);
            OR(x, y, z);
        }
        else if (strcmp(har_khat, "ADDI") == 0)
        {

            sscanf(dastorat, "ADDI S%d, S%d, %d", &x, &y, &z);
            ADDI(x, y, z);
        }

        else if (strcmp(har_khat, "SUBI") == 0)
        {

            sscanf(dastorat, "SUBI S%d, S%d, %d", &x, &y, &z);
            SUBI(x, y, z);
        }
        else if (strcmp(har_khat, "XORI") == 0)
        {

            sscanf(dastorat, "XORI S%d, S%d, %d", &x, &y, &z);
            XORI(x, y, z);
        }
        else if (strcmp(har_khat, "ORI") == 0)
        {

            sscanf(dastorat, "ORI S%d, S%d, %d", &x, &y, &z);
            XORI(x, y, z);
        }
        else if (strcmp(har_khat, "ANDI") == 0)
        {

            sscanf(dastorat, "ANDI S%d, S%d, %d", &x, &y, &z);
            ANDI(x, y, z);
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
            SWP(x, y);
        }
        else if (strcmp(d_r, "DUMP_REGS") == 0)
        {
            // printf("dump_regs");
            DUMP_REGS();
            for (int w = 0; w < 9; w++)
            {
                
                d_r[w] = d_r_r[w];
            }
            
        }

        else if (strcmp(d_r_f,"DUMP_REGS_F ") == 0)
        {   
            // printf("dump_regs_f");

            DUMP_REGS_F();
        for (int w = 0; w < 11; w++)
            {
                d_r_f[w] = d_r_f_r[w];
            }
            
            
        }
        else if (strcmp(input,"INPUT") == 0)
        {
        
        INPUT();
         
        for (int w = 0; w < 5; w++)
            {
                input[w] = input_r[w];
            }
        }
        else if (strcmp(help, "HELP") == 0)
        {
            
            HELP();
            for (int w = 0; w < 4; w++)
            {
                
                help[w] = help_r[w];
            }
            
        }
        else if (strcmp(output, "OUTPUT") == 0)
        {
            // printf("output");
            OUTPUT();
            for (int w = 0; w < 6; w++)
            {
                output[w] = output_r[w];
            }
            
            
            
        }
        else if (strcmp(har_khat, "JMP") == 0)
        {

            printf("\nyou ran into an unlimited loop pls try agian");
            return ;
        }
        else if (strcmp(exit_asli, "EXIT") == 0)
        {  
            for (int i = 0; i < 4; i++)
            {
                exit_asli[i] = exit_r[i];
            }
            

            break;
        }
        else if (strcmp(har_khat, "DIV") == 0)
        {

            sscanf(dastorat, "DIV S%d, S%d", &x, &y);
            DIV(x, y);
        }
        else
        {
            printf("\n%s is not recognized as an internal or external command,operable program or batch file."
            , har_khat);
        }
        for (int i = 0; i < 100; i++)
        {
            har_khat[i] = dastorat_2[i];
        }
        
       
    }
   }
    fclose(jump);

}

void HELP(){
printf("Add : jamm kardan 2 adadi ke type shode ast ke an 2 addad ra dar araye asli mizarim va jamm mikonim\nva rikhtan on dar araye asli entekhabi\n");
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
printf("EXIT : kharaj shodan az dastorha va exit shodan az terminal\n");
}
void DIV(int x,int y){
main_array[x] =main_array[x]/main_array[y];
main_array[y] = main_array[x]%main_array[y];
// check_binary_addad()
// printf("%d %d",main_array[x],main_array[y]);
check_binary_addad(main_array[x]);
check_andaze_javab(main_array[x]);
check_binary_addad(main_array[y]);
check_andaze_javab(main_array[y]);
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
