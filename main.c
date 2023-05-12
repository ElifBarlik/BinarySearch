#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int dizi[], int diziBoyutu)
{
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

int BinarySearch(int dizi[], int ilkIndex, int sonIndex, int arananSayi)
{

	if(sonIndex>=ilkIndex){
		
	int ortancaSayiIndex=(ilkIndex+sonIndex)/2;
	
	int i;
	
	if(dizi[ortancaSayiIndex]==arananSayi)
		return ortancaSayiIndex;
		
	if(dizi[ortancaSayiIndex]>arananSayi)
		return BinarySearch(dizi, 0, ortancaSayiIndex-1, arananSayi);
		
	return BinarySearch(dizi, ortancaSayiIndex+1, sonIndex, arananSayi);
	
	}
	return -1;
}

int main() {
	
	int i, arananSayi;
	
	int  dizi[]={4, 8, 3, 84, 47, 76, 9, 24, 68};
	int diziBoyutu=sizeof(dizi)/sizeof(dizi[0]);
	
	printf("Dizide aranacak sayiyi girin: ");
	scanf("%d",&arananSayi);
	
	InsertionSort(dizi, diziBoyutu);
	
	int sonuc=BinarySearch(dizi, 0, diziBoyutu-1, arananSayi);
	
	if(sonuc==-1)
	{
		printf("Aranan sayi dizide bulunmuyor.");
	}
	else
	{
		printf("Aranan sayi dizide bulunuyor.");
	}
	return 0;
}
