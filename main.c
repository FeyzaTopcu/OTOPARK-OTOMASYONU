#include <stdio.h>
#include <stdlib.h>

int ucretHesapla(int arabaDizi[][4], int plaka);
void elemanlariSifirla();
int MaksUcretBul(int ucretDizi[]);

int araclar[10][4];
int ucret[10];

int main()
{
    printf(" \n BAHTSiZ BEDEVi KARDESLER OTOPARKiNA HOS GELDiNiZ\n");
    elemanlariSifirla();
    int secim,plaka,i,girisSaati,cikisSaati,tip,cikisYap=0,aracSayi = 0, secilenPlaka, hesaplanan;
    while(1){
        printf("\n**************************************\n");
        printf("\nLutfen menuden eleman seciniz\n1-> Otoparka arac ekle\n2-> Otoparktaki araclari listele\n3-> Arac ucret hesaplama\n4-> Minimum ve maximum ucret hesaplama\n0-> cikis");
        printf("\nSeciminiz: ");
        scanf("%d",&secim);
        switch(secim){
            case 1:
                if(aracSayi < 9){
                    printf("\n**************************************");
                    while(1){
                        printf("\nPlakayi giriniz:");
                        scanf("%d",&plaka);
                        for(i=0;i<10;i++){
                            if(araclar[i][0] == plaka){
                                cikisYap = 1;
                                break;
                            }
                        }
                        if(cikisYap == 1) {
                            printf("Bu plaka daha once kayit edilmis\n");
                            cikisYap = 0;
                            continue;
                        }
                        else{
                            araclar[aracSayi][0] = plaka;
                            break;
                        }
                    }

                    while(1){
                        printf("\nGiris saatini giriniz:");
                        scanf("%d",&girisSaati);
                        if(girisSaati < 25 && girisSaati > 0){
                            araclar[aracSayi][1] = girisSaati;
                            break;
                        }else continue;
                    }

                    while(1){
                        printf("\nCikis saatini giriniz:");
                        scanf("%d",&cikisSaati);
                        if(cikisSaati < 25 && cikisSaati > 0){
                            if(cikisSaati>girisSaati){
                                araclar[aracSayi][2] = cikisSaati;
                            }else{
                                printf("Cikis saati, giris saatinden kucuk olamaz\n");
                                continue;
                            }
                            break;
                        }else continue;
                    }

                    while(1){
                        printf("\nTipi giriniz\n\t1->Otomobil\n\t2->Otobus\n\t3->Kamyon\nSecim:");
                        scanf("%d",&tip);
                        if(tip < 4 && tip > 0){
                            araclar[aracSayi][3] = tip;
                            break;
                        }else continue;
                    }
                    aracSayi++;
                    ucretHesapla(araclar,araclar[aracSayi][0]);
                }else{
                    printf("Maalesef otoparkimiz dolu!");
                }

                break;
            case 2:
                AraclariListele();
                break;
            case 3:
                printf("\nHangi aracin ucretini hesaplamak istersiniz (Plaka):");
                scanf("%d",&secilenPlaka);
                hesaplanan = ucretHesapla(araclar,secilenPlaka);
                if(hesaplanan == 0){
                    printf("\nBoyle bir arac bulamadi");
                    continue;
                }else{
                    printf("\nHesaplanan ucret: %d\n", hesaplanan);
                }
                break;
            case 4:
                printf("\nMinimum ucret: %d\n", MinUcretBul(ucret));
                printf("\nMaksimum ucret: %d\n", MaksUcretBul(ucret));
                break;
             case 0:
                exit(0);
                break;
            default:
                printf("\nLutfen 0 ile 5 arasinda deger giriniz\n\n");
                break;
        }
    }
    return 0;
}

void elemanlariSifirla(){
    int i;
    for(i=0;i<10;i++){
        araclar[i][0] = 0;
        ucret[i] = 0;
    }
}

void AraclariListele(){
    int i;
    for(i=0;i<10;i++){
        if(araclar[i][0] != 0){
            printf("\nArac %d\n\tPlaka:%d\n\tGiris Saati:%d\n\tCikis Saati:%d\n\tTipi:%d\n",i+1,araclar[i][0],araclar[i][1],araclar[i][2],araclar[i][3]);
        }
    }
}

int ucretHesapla(int arabaDizi[][4], int plaka){
    int hesaplanan = 0,i;
    for(i=0;i<10;i++){
        if(arabaDizi[i][0] == plaka){
            switch(arabaDizi[i][3]){
                case 1:
                    hesaplanan = 5 + (arabaDizi[i][2] - arabaDizi[i][1])*1;
                    ucret[i] = hesaplanan;
                    break;
                case 2:
                    hesaplanan = 5 + (arabaDizi[i][2] - arabaDizi[i][1])*2;
                    ucret[i] = hesaplanan;
                    break;
                case 3:
                    hesaplanan = 5 + (arabaDizi[i][2] - arabaDizi[i][1])*3;
                    ucret[i] = hesaplanan;
                    break;
                default:
                    hesaplanan = 0;
                    break;
            }
            break;
        }
    }
    return hesaplanan;
}

int MaksUcretBul(int ucretDizi[]){
    int maksimumUcret = 0,i;
    for(i=0;i<10;i++){
        if(ucretDizi[i]>maksimumUcret){
            maksimumUcret = ucretDizi[i];
        }
    }
    return maksimumUcret;
}

int MinUcretBul(int ucretDizi[]){
    int minimumUcret = 0,i,ilkEleman = 0;
    for(i=0;i<10;i++){
        if(ucretDizi[i] != 0){
            if(ilkEleman==0){
                minimumUcret = ucretDizi[0];
                ilkEleman = 1;
            }

            if(ucretDizi[i] < minimumUcret){
                minimumUcret = ucretDizi[i];
            }
        }

    }
    return minimumUcret;
}


