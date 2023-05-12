#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int dizi[], int diziBoyutu) //siralama icin fonksiyon tanimladim.
{
	//dizinin elemanlari ikiser ikiser karsilastirilir.
	//buyuk eleman dizide saga atilarak dizi kucukten buyuge siralanir.
	int i, j, minimum;
	for(i=0; i<diziBoyutu; i++)
	{
		minimum=dizi[i]; 
		j=i-1;
		while(j>=0 && dizi[j]>minimum)
		{
			dizi[j+1]=dizi[j]; 
			j--;
		}
		dizi[j+1]=minimum;
	}
}

int BinarySearch(int dizi[], int ilkIndex, int sonIndex, int arananSayi) //arama islemi icin fonksiyon tanimladim.
{
	//dizi siralidir ve ortadan ikiye ayrilir.
	//aranan sayi ortada aranir.
	if(sonIndex>=ilkIndex){
		
	int ortancaSayiIndex=(ilkIndex+sonIndex)/2;
	
	int i;
	
	if(dizi[ortancaSayiIndex]==arananSayi) //aranan sayi ortada ise 
		return ortancaSayiIndex; //ortanca sayinin indesini dondurur.
		
	if(dizi[ortancaSayiIndex]>arananSayi) //aranan sayi ortanca sayidan kucuk ise
		return BinarySearch(dizi, 0, ortancaSayiIndex-1, arananSayi); 
		//dizinin soluna dogru yeniden fonksiyon dondurulur. Dizi yeniden ikiye ayrilir ve yeni ortanca sayi karsilastirilir.
		
	return BinarySearch(dizi, ortancaSayiIndex+1, sonIndex, arananSayi); //aranana sayi oratnca syidan buyuk ise
	//dizinin sagina dogru yeniden fonksiyon dondurulur. Dizi yeniden ikiye ayrilir ve yeni ortanca sayi karsilastirilir.
	
	}
	return -1;
}

int main() {
	
	int i, arananSayi;
	
	int  dizi[]={4, 8, 3, 84, 47, 76, 9, 24, 68};
	int diziBoyutu=sizeof(dizi)/sizeof(dizi[0]); 
	
	printf("Dizide aranacak sayiyi girin: "); 
	scanf("%d",&arananSayi);
	
	//binary search icin dizinin sirali olmasi gerekir bu yuzden once iinsertion sort tercih ettim.
	InsertionSort(dizi, diziBoyutu);
	
	int sonuc=BinarySearch(dizi, 0, diziBoyutu-1, arananSayi); //aramadan sonra gelen deger icin degiken tanimladim.
	
	if(sonuc==-1) //donen deger -1 ise sayi dizide yoktur.
	{
		printf("Aranan sayi dizide bulunmuyor.");
	}
	else //eger baska deger donerse sayi dizide bulunur.
	{
		printf("Aranan sayi dizide bulunuyor.");
	}
	return 0;
}
