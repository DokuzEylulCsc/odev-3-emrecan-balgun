#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

struct ogrenciler{
	char no[100][100];
	int puan[100];
}ogr;

int main()
{
	FILE *dosya;
	int soru_sayisi=0;
	char cevap_anahtari[100];
//	char ogrenci_no[100][100];
	char cevaplar[100][100];
//	int puan[100];
	
	int i=0;
	int j=0;
	int a=0;
	char virgul=',';

	
	if((dosya=fopen("input.txt","r+"))!=NULL)
	{
		fscanf(dosya,"%d\n", &soru_sayisi);
		fscanf(dosya,"%s\n", &cevap_anahtari);
		while(!feof(dosya))
		{
			fgets(ogr.no[i],10,dosya);
			fscanf(dosya,",%s\n", &cevaplar[i]);
			i++;
		}
	}
	
	int kac_kisi_var=i;	
	int kisi_sayisi=kac_kisi_var;
	
	fclose(dosya);
	
	while(kac_kisi_var!=0)
	{
		ogr.puan[a]=0;
		j=0;
			for(i=0; i<19; i++)
			{
				if(isalpha(cevap_anahtari[i])!=0 && isalpha(cevaplar[a][j])!=0 && cevap_anahtari[i]==cevaplar[a][j])
			{
					ogr.puan[a]=ogr.puan[a]+4;
			}
				else if(cevap_anahtari[i]==virgul && cevaplar[a][j]==virgul)
			{
					ogr.puan[a]=ogr.puan[a]+0;
			}
				else if(isalpha(cevap_anahtari[i])!=0 && cevaplar[a][j]==virgul)
			{
					i++;
			}
				else if(isalpha(cevap_anahtari[i])!=0 && isalpha(cevaplar[a][j])!=0 && cevap_anahtari[i]!=cevaplar[a][j])
			{
					ogr.puan[a]=ogr.puan[a]-1;
			}
				j++;
			}
			if(ogr.puan[a]<0)
			{
				ogr.puan[a]=0;
			}	
		a++;
		kac_kisi_var--;
	}

	for(i=0; i<kisi_sayisi; i++)
	{
		ogr.puan[i]=(ogr.puan[i]*100)/40;
	}
	
	int endusuk=ogr.puan[0];
	int enyuksek=ogr.puan[0];
	int ortalama=0;
	int medyan=0;
	int aciklik=0;
	
/*	
	for(i=0;i<kisi_sayisi;i++)
	{
		for(j=0;j<kisi_sayisi;j++)
		{
			if(ogr.puan[i]<ogr.puan[j])
			{
				temp=ogr.puan[i];
				ogr.puan[i]=ogr.puan[j];	
				ogr.puan[j]=temp;
			}
		}
	}
*/

	
	int temp;
	int puan2[100];
	
		for(i=0; i<kisi_sayisi; i++)
	{
		puan2[i]=ogr.puan[i];
	}
	
	for(i=0;i<kisi_sayisi;i++)
	{
		for(j=0;j<kisi_sayisi;j++)
		{
			if(puan2[i]<puan2[j])
			{
				temp=puan2[i];
				puan2[i]=puan2[j];	
				puan2[j]=temp;
			}
		}
	}
	
	for(i=0; i<kisi_sayisi; i++)
	{
		if(ogr.puan[i]<endusuk)
			endusuk=ogr.puan[i];
			
		if(ogr.puan[i]>enyuksek)
			enyuksek=ogr.puan[i];
			
		ortalama=ortalama+ogr.puan[i];
	}
	
	ortalama=ortalama/kisi_sayisi;
	aciklik=enyuksek-endusuk;
	
		if(kisi_sayisi%2==0)
		{
			int deger1=kisi_sayisi/2-1;		
			int deger2=(kisi_sayisi/2);
			medyan = (ogr.puan[deger1] + ogr.puan[deger2])/2;
		}
		else
		{
			int deger = (kisi_sayisi)/2;
			medyan = ogr.puan[deger];
		}
	
	dosya=fopen("output.txt","w+");

	for(i=0; i<kisi_sayisi; i++)
	{
		for(j=0; j<kisi_sayisi; j++)
		{
			if(puan2[i]==ogr.puan[j])
			{
			//	printf("%s,%d\n",ogr.no[j],ogr.puan[j]);
				fprintf(dosya,"%s,%d\n",ogr.no[j],ogr.puan[j]);
			}
		}
	}
//	printf("%d,%d,%d,%d,%d",endusuk,enyuksek,ortalama,medyan,aciklik);
	fprintf(dosya,"%d,%d,%d,%d,%d",endusuk,enyuksek,ortalama,medyan,aciklik);
	
	printf("DOSYAYA YAZMA ISLEMI BASARILI..");
	/*	
	printf("\nEn dusuk not: %d",endusuk);
	printf("\nEn yuksek not: %d",enyuksek);
	printf("\nOrtalama: %d",ortalama);
	printf("\nMedyan: %d",medyan);
	printf("\nAciklik(Range): %d",aciklik);
	*/
	return 0;
	//Emrecan Balgün - 2017280011
}
