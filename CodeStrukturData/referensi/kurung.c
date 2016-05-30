#include <stdio.h>

int dapatDiisi(int top,int maxStack);
int dapatDiambil(int top);
void pop(char *stack,char kurung,int &top,int &salah);
void push(char *stack,char simpan,int &top,int &salah,int maxStack);

main()
{
    system(“cls”);
    int top=-1; //indeks penunjuk puncak Stack
    int maxStack; //nilai maximal isi stack
    int salah=0; //variable untuk mengontrol kesalahan
    char *kalimat;
    char *stack; //variable stack
    kalimat=(char *)malloc(sizeof(char)*30);
    stack=(char *)malloc(sizeof(char)*maxStack);
    do{
        printf(“max stack = “);
        fflush(stdin);
        scanf(“%d”,&maxStack);
    }while(maxStack<0||isalpha(maxStack));

    printf(“operasi matematika = \n”);
    fflush(stdin);

    gets(kalimat);

    for(int i=0;kalimat[i];i++)
    {
        if(kalimat[i]=='(‘||kalimat[i]=='[‘||kalimat[i]=='{‘)
           //jika mendapati kurung buka, maka akan dilakukan PUSH
            push(stack,kalimat[i],top,salah,maxStack);
        else if (kalimat[i]==’)’||kalimat[i]==’]’||kalimat[i]==’}’)
            //jika mendapati kurung buka, maka akan dilakukan POP
            pop(stack,kalimat[i],top,salah);
        if(salah)
            break;
        }

        if(!salah)
        {
            if(top==-1)
                printf(“Operasi Matematika sudah benar\n”);
            else
                printf(“Terdapat kurung buka yang tidak berpasangan\n”);
        }

        printf(“Tekan (k) untuk kembali menjalankan program\n”);

        if(getch()==’k’)
            main();
        else
            system(“pause”);
}

int dapatDiisi(int top,int maxStack)

{ if(top<maxStack-1)

return 1;

else

return 0;

}

int dapatDiambil(int top)

{ if(top>-1)

return 1;

else

return 0;

}

void pop(char *stack,char kurung,int &top,int &salah)

{ if(dapatDiambil(top))

{ switch (kurung) //pencocokan tanda kurung

{ case ‘)’ : if(stack[top]!='(‘)

{  printf(“Tanda kurung %c%c salah\n”,stack[top],kurung);

printf(“Kesalahan terjadi karena %c berpasangan dengan %c\n”,stack[top],kurung);

salah=1;

}break;

case ‘]’ : if(stack[top]!='[‘)

{  printf(“Tanda kurung %c%c salah\n”,stack[top],kurung);

printf(“Kesalahan terjadi karena %c berpasangan dengan %c\n”,stack[top],kurung);

salah=1;

}break;

case ‘}’ : if(stack[top]!='{‘)

{  printf(“Tanda kurung %c%c salah\n”,stack[top],kurung);

printf(“Kesalahan terjadi karena %c berpasangan dengan %c\n”,stack[top],kurung);

salah=1;

}break;

}

stack[top–]=’ ‘; //menghapus stack yang telah diambil dengan cara menggantinys dengan spasi

}

else

{ printf(“STACK sudah kosong\n”);

salah=1;

}

}

void push(char *stack,char simpan,int &top,int &salah,int maxStack)

{ if(dapatDiisi(top,maxStack))

stack[++top]=simpan;

else

{ printf(“STACK telah penuh\n”);

salah=1;

}

}
