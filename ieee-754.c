#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //while icinde kullanilan true icin bu kutuphaneye ihtiyacimiz var.
int main()
{
    //Gerekli degisken ve dizi tanimlamalari
    char okulNumarasi[10], tamSayiDizi[4], ondalikSayiDizi[3], usBinary[8], tamBinary[15], ondalikBinary[15], mantisBinary[23];
    int tamSayi, tamSayiF, usFloatSayi;
    float ondalikSayi, olusanSayi;
    char isaretBiti = 0;

    printf("\n");
    printf("****************************************************");
    printf("\n");

    //okulNumarasini fgets ile maks 10 elemanlı olacak şekilde kullanıcıdan aldık ve karakter dizisine atadik.
    printf("Lutfen Okul Numaranizi Giriniz:");
    fgets(okulNumarasi, 11, stdin);

    //Numaramizi aldigimiza göre noktali sayimizi olusturabiliriz.

    //Tam sayi kismini olusturmakla baslayalim.
    for (int i = 0; i < 10; i++)
    {
        /*tamSayimizi tutmak icin dizi olusturalim.
        okulNumarasinin 2.elemanini tamSayiDizi'nin 1.elemanina atadik ve if ile 
        4.elemani aldıktan sonra döngüyü bitirdik.
        4.eleman i'nin 3 degerine denk geliyor.
        */
        tamSayiDizi[i] = okulNumarasi[i + 1];
        if (i == 3)
            break;
    }

    //tamSayiDizi'yi sayiya çevirmek için atoi fonksiyonunu kullanalim.
    tamSayi = atoi(tamSayiDizi);

    //assagida tekrar kullanacagimiz icin degisikliklerden etkilenmesin diye sayimizi baska bir degiskende daha tutuyoruz.
    tamSayiF = tamSayi;

    //Ondalik kismi olusturmakla devam edelim.
    for (int i = 9; i > 7; i--)
    {
        ondalikSayiDizi[i - 8] = okulNumarasi[i];
    }
    //dizinin son elemanina NULL deger atayarak diziyi sonlandirdik.
    ondalikSayiDizi[3] = '\0';

    //ataoi ile ondalikSayiDizi'yi sayiya çevirelim ve 100 e bölelim çünkü virgüllü bir sayi elde etmemiz gerek. .
    ondalikSayi = atoi(ondalikSayiDizi) / 100.0;

    olusanSayi = tamSayi + ondalikSayi;

    printf("\n");
    printf("****************************************************");
    printf("\n");
    printf("Ikilik sistemde 32 bitlik dizilimi gosterilecek sayi:%.2f\n", olusanSayi);

    //usFloat Binary Dizilimi için Hesaplama yapmaliyiz. Bunun icin 2^7+(basamak kaydirma sayisi-1) formülünü kullanacagiz.

    //Simdi kac basamak kaydirilacak onu bulalim.
    int adimSayac = 0;
    while (true)
    {
        //Ornegin sayimiz 10
        tamSayi = tamSayi / 2; //10/2=5        5/2=2           2/2=1
        adimSayac++;           //adimSayac=1   adimSayac=2     adimSayac=3
        if (tamSayi == 1)      //sayimiz=5     sayimiz=2       sayimiz=1
            break;             //sayimiz 1 oldugu icin dongu break ile kirildi.

        /*10 un binary dizilimi 1010 olacak en solda 1 e kadar 3 basamak kaydiriyoruz.
        Aslinda amacimiz sürekli 2'ye boldugumuzde en sondaki 1 e kadar(1'i bolmek dahil degil) 
        kac kez boldugumuzu bulmak boylece kaydirma sayisina da ulasmis oluyoruz.*/
    }

    //Yukarida bahsettigimiz formul ile us kismin binary diziliminde kullanacagimiz sayiyi elde ettik.
    usFloatSayi = pow(2, 7) + (adimSayac - 1);

    //usFloatSayi'nin binary dizilimini hesaplayalim.
    //Bunun icin degiskenler kisminda 8 elemanlik bir dizi tanimladik.Cunku ussumuz 8 bitlik.
    //adimSayac'ini tekrar sifir yaptik.
    adimSayac = 0;

    while (true)
    {
        usBinary[adimSayac] = usFloatSayi % 2; //kalanlari dizimize atiyoruz.
        usFloatSayi = usFloatSayi / 2;         //her seferinde sayimizin yarisini kullaniyoruz.
        adimSayac++;
        if (usFloatSayi == 1) //son Bolunecek sayi 1 oldugunda diziye 1 i atayip sonra donguyu kiriyoruz.
        {
            usBinary[adimSayac] = 1;
            break;
        }
    }

    //Mantis kismin binary dizilimini bulalim.
    /*Bu kismi 2 asamada ele aldim.Oncelikle tamSayinin binary dizilimini sonrasinda da ondalikSayinin 
    binary dizilimini buldum. Bunlari bulduktan sonra (mantis 23 bitlik oldugundan) 23 elemanlik tek bir dizide ikisini birlestirdim. */

    adimSayac = 0;
    while (true)
    {
        //yukarida binary dizilimi tutmak icin dizi tanimlayalim.
        tamBinary[adimSayac] = tamSayiF % 2;
        tamSayiF = tamSayiF / 2;
        adimSayac++;
        if (tamSayiF == 1)
        {
            tamBinary[adimSayac] = 1;
            break;
        }
    }

    //Ondalik Kismin Binary dizilimini bulalim.
    for (int i = 0; i < 15; i++)
    {
        //ondalik sayimizi her seferinde 2 ile carpicaz.
        ondalikSayi = ondalikSayi * 2;

        //1'den kucukse binary dizimize 0, 1'e esit veya 1'den buyukse 1 atayacagiz.
        if (ondalikSayi < 1)
        {
            ondalikBinary[i] = 0;
        }
        else
        {
            ondalikBinary[i] = 1;

            //ondalikSayi 1'e esit veya 1'den buyuk oldugunda ondalikSayi'dan 1 cikarmaliyiz.
            ondalikSayi = ondalikSayi - 1;
        }
    }

    /*Tum islemlerden sonra elde edilecek olan binary diziliminde en soldaki 1 e kadar basamak kaydirilacagi icin 
    tamBinary dizimizin ilk elemani binary diziliminde olmayacak.*/
    for (int i = 0; i < 23; i++)
    {
        //yukarida tamBinary'i bulurken tanimladigimiz diziboyutunu dizileri birlestirmek icin bir sinirlayici olarak kullandik.
        if (i < adimSayac)
            mantisBinary[i] = tamBinary[adimSayac - i - 1];
        /*bu kisim ile yapmayi hedefledigimiz sey mantis'in ilk elemanina tamBinary'yi ters 
            sekilde atmak ancak tamBinary'nin ilk elemani (Yani en soldaki 1) dizilimde kullanilmayacagi icin 2.elemandan basladik.*/
        else
            mantisBinary[i] = ondalikBinary[i - adimSayac];
        //tamBinary'i mantis'e atadiktan sonra sira ondalik kisma geliyor. OndalikBinary'i düz sekilde atiyoruz.
    }

    //ARTIK BULDUGUMUZ TUM DEGERLERİ YAZDIRABILIRIZ.
    //Degiskenler kisminda isaretBiti tanimlamasi yapiyorum. Girilecek sayi pozitif olacagindan isaretBitimiz sifir olmali.

    printf("\n");
    printf("****************************************************\n");
    printf("Sayinin ikilik sistemde 32 bitlik gosterimi:");
    printf("\n");

    //isaretBitini yazdiralim.
    printf("%d%c", isaretBiti, '|');

    //usBinary'i for ile tersten yazdiralim.
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", usBinary[i]);
    }

    printf("%c", '|');

    //mantisBinary'i for ile yazdiralim.
    for (int i = 0; i < 23; i++)
    {
        printf("%d", mantisBinary[i]);
    }

    printf("\n");
    printf("****************************************************");
    printf("\n");

    return 0;
}