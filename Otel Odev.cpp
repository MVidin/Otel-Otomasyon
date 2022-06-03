#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int oda_no[21]; 
void oda_yaz(); 
int oda_doldur(); 
int oda_numarasi; 
int room=1; 
int matris[5][4];
int oda;

void oda_yaz(){ 
char AD[20],SOYAD[20];
room=1; 
int i;
int j;
    for (i=0;i<5;i++){ 
        for (j=0;j<4;j++){ 
            matris[i][j]=room; 
            if (oda_no[room])
			printf("\tREZERVE\t"); 
            else printf("\t%d\t",matris[i][j]); 
            room++; 
            } 
           	printf("\n");
	}
	FILE *FATURA;
	printf("Adiniz     :");
	 scanf("%s",&AD);
	printf("Soyadiniz  :");
	  scanf("%s",&SOYAD);
	printf("\n");
    printf("\nKac tane oda alacaksiniz? = ");
    scanf("%d",&oda);
    FATURA=fopen("gun.txt","a");
    fprintf(FATURA,"%s %s %d %d %d\n",AD,SOYAD,oda);
    fclose(FATURA);
    for(i=1;i<=oda;i++){
    	oda_doldur(); 
    }
    system("PAUSE");
    
} 	


int oda_doldur(){	
	printf("\n");
	printf("\nOda numarasini giriniz [1-20] :"); 
	scanf("%d",&oda_numarasi); 
	if(oda_no[oda_numarasi]==1){
		printf("%d NUMARALI ODA REZERVE, LUTFEN BASKA ODA SECINIZ\n\n",oda_numarasi); 
	}
	else if (oda_no[oda_numarasi]==0){
		printf("\n");
		printf("%d NUMARALI ODA ALINDI\n\n",oda_numarasi);
	}
	else printf("%d NUMARALI ODA BULUNMAMAKTA\n",oda_numarasi);
	oda_no[oda_numarasi]=1;
}


void USDTL(){
	system("color 3F");	
	float sonuc;
	int gelen;	
	printf("USD:");
	scanf("%d",&gelen);
	sonuc=gelen*2.26;
	system("color 4F");	
	printf("%d USD -> %.2f TL",gelen,sonuc);	
}


void EURTL(){
	system("color 4F");	
	float sonuc;
	int gelen;	
	printf("EUR:");
	scanf("%d",&gelen);
	sonuc=gelen*2.82;
	printf("%d EUR -> %.2f TL",gelen,sonuc);	
}


void TLEUR(){
	system("color 4F");	
	float sonuc;
	int gelen;	
	printf("TL:");
	scanf("%d",&gelen);
	sonuc=gelen*0.35;
	printf("%d TL -> %.2f EUR",gelen,sonuc);	
}


void TLUSD(){
	system("color 4F");	
	float sonuc;
	int gelen;	
	printf("TL:");
	scanf("%d",&gelen);
	sonuc=gelen*0.44;
	printf("%d TL -> %.2f USD",gelen,sonuc);
}


void DVZKUR(){
	system("color 4F");
	system("CLS");
	int secim;
	printf("...Doviz Kurlari Bolumune Hos geldiniz...\n\n");
	printf("1 USD = 2.26 TL\n"
		   "1 EUR = 2.82 TL\n");
	printf("Lutfen donusum secininiz...\n\n"
	       "1- (USD->TL)  2-(TL->USD)  3-(EUR->TL)  4-(TL->EUR)  5-(CIKIS)\n\n" );
	scanf("%d",&secim);
	switch(secim){
		case 1:
		USDTL();	
		break;
		
		case 2:
		TLUSD();
		break;
		
		case 3:
		EURTL();
		break;
		
		case 4:
		TLEUR();
		break;
		
		case 5:
		break;
		
		default:
		system("CLS");	
		printf("Lutfen donusturmek istediginiz doviz kodunu belirten rakami giriniz...!\n\n");
	}
}


void FATURA(){
	char isim[20],soyisim[20];		
	printf("Adiniz:"); scanf("%s",&isim);
	printf("Soyadiniz :");scanf("%s",&soyisim);
	FILE *FATURA;
	char isimler[20][20],soyadlar[20][20];
	int gunler[20],i=0;
	FATURA=fopen("gun.txt","r");
	while(!feof(FATURA)){
		fscanf(FATURA,"%s %s %d",&isimler[i],&soyadlar[i],&gunler[i]);
		if(isimler[i]==isim){
			printf("kado");
		}
		i++;
	}
	fclose(FATURA);	
}


struct MisafirBilgileri{	
	char ad	[20];
	char sehir[20];
	int tel[10];
		
}MSB[3];


void MSKB(){
	int i,tel;	
		
		printf("Isim :"); scanf("%s",&MSB[i].ad);
		printf("Sehir:"); scanf("%s",&MSB[i].sehir);
	 	printf("Tel  :"); scanf("%d",&tel);	
 	printf("DOKUMAN\n");	
	printf("%s \t %s \t %d\n",MSB[i].ad,MSB[i].sehir,tel);		
}


void hesapla(){
	float gunsayisi,kdvoran,toplam,fiyat;
	printf("\t**Toplam Fiyat Hesaplama**\n\n");
	printf("\t************************\n\n");
	printf("\ngunsayisini Giriniz : ");
	scanf("%f",&gunsayisi);
	printf("\n");
	printf("\n oda fiyati giriniz(40 tl/60tl/100tl):");
	scanf("%f",&fiyat);
	printf("\n");
	printf("\tKDV oranini giriniz : ");
	scanf("%f",&kdvoran);
	printf("\n");
	printf("\t***********************\n\n");
	printf("\tgunsayisi      : %.2f\n",gunsayisi);
	printf("\tKDV Orani        : Yuzde %.2f\n", kdvoran);
	printf("\n");
	printf("\t***********************\n\n");
	toplam= (float)  gunsayisi*kdvoran/100 + gunsayisi*fiyat;
	printf("\tToplam Fiyat     : %.2f\n\n\a",toplam);
	printf("\t**************************\n\n");
	
	 system("PAUSE");
    
}

void Kontenjan()
{
	int i;
int j;
    for (i=0;i<5;i++){ 
        for (j=0;j<4;j++){ 
            matris[i][j]=room; 
            if (oda_no[room])
			printf("\tREZERVE\t"); 
            else printf("\t%d\t",matris[i][j]); 
            room++; 
            } 
           	printf("\n\n");
	}
}

 
 
int main(){	
	while(1){
		system("color 4F");
		int secim;
		AN:
		DN:
		printf("1-<KONTENJAN>             2-<REZARVASYON>                     3-<TADILAT/ARIZA> \n\n"
			   "4-<DOVIZ KURLARI>         5-<MISAFIR KIMLIK BILGILERI>        6-<FATURA> \n\n\n"
				"7-<TOPLAM F?YAT HESAPLAMA>	0-<Otomasyon Cikis>\n\n\n");
		scanf("%d",&secim);

		switch(secim){
			case 1:
			printf("KONTENJAN\n");
			Kontenjan();
			break;		
			
			case 2:
			printf("REZARVASYON\n");
			oda_yaz();
			system("CLS");
			break;
			
			case 3:
			printf("TADILAT/ARIZA");
			break;
					
			case 4:
			printf("DOVIZ KURLARI\n");
			DVZKUR();
			break;
					
			case 5:
			printf("MISAFIR KIMLIK BILGILERI\n\n");
			MSKB();
			break;
					
			case 6:
			printf("FATURA");
			FATURA();
			break;
			
			case 7:
			printf("TOPLAM FÝYAT HESAPLAMA");
			hesapla();
			break;
			case 0:
			system("EXIT");
			break;		
			default: 
			system("CLS");
			printf("Lutfen erismek istediginiz bolumu belirten rakami giriniz...!\n\n");		
			goto DN;
		}	
	}
}
