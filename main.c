#include <stdio.h>
#include <stdlib.h>
#define N 2

struct oyuncu{
    char ad[20];
    char soyad[20];
    int yas;
    int seviye;

};

struct ekip{
    char isim[20];
    struct oyuncu oyuncu1;
    struct oyuncu oyuncu2;

};

void ekipOlustur(struct ekip *e);
void oyuncu_olustur(struct oyuncu *o);
void ekipYazdir(struct ekip *e);
void oyuncu_yazdir(struct oyuncu *o);

int main()
{
    struct ekip teams[N];

    // 2 ekip olusturma
    for(int i=0;i<N;i++)
    {
        printf("EKIP %d:\n",i+1);
        ekipOlustur(&teams[i]);
    }
    // ekiplerin bilgilerini ekrana yazdirma
    for(int j=0;j<N;j++)
    {
        ekipYazdir(&teams[j]);
    }


    return 0;
}

void ekipOlustur(struct ekip *e)
{
    printf("Ekip ismi: ");
    gets(e->isim);

    // oyunculari oyuncu_olustur fonksiyonuna adresiyle gondererek orada olustur
    printf("Oyuncu 1:\n");
    oyuncu_olustur(&e->oyuncu1);
    printf("Oyuncu 2:\n");
    oyuncu_olustur(&e->oyuncu2);fflush(stdin);
}

void oyuncu_olustur(struct oyuncu *o)  // kullanicidan istenilen verileri alarak oyuncu olusturma fonksiyonu
{
    printf("ad: ");
    scanf("%s",o->ad);
    printf("soyad: ");
    scanf("%s",o->soyad);
    printf("yas: ");
    scanf("%d",&o->yas);
    printf("seviye: ");
    scanf("%d",&o->seviye);
}

void ekipYazdir(struct ekip *e)
{
    printf("isim: %s\n",e->isim);
    printf("oyuncu 1:\n");
    oyuncu_yazdir(&e->oyuncu1);
    printf("\noyuncu 2:\n");
    oyuncu_yazdir(&e->oyuncu2);

}

void oyuncu_yazdir(struct oyuncu *o)
{
    printf("\tad    : %s\n",o->ad);
    printf("\tsoyad : %s\n",o->soyad);
    printf("\tyas   : %d\n",o->yas);
    printf("\tseviye: %d\n",o->seviye);
}
