#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

#define sens A1

byte durum = 0;
byte menu = 0;
byte alt_durum = 0;
byte ilk_gosterilen = 0;

byte yiyecek_sayisi[5] = {0, 0, 0, 0, 0};
byte icecek_sayisi[5] = {0, 0, 0, 0, 0};
byte tatli_sayisi[5] = {0, 0, 0, 0, 0};

const float yiyecek_fiyat[5] = {20, 25, 30, 23, 20};
const float icecek_fiyat[5] = {5, 10, 4, 8, 9};
const float tatli_fiyat[5] = {15, 20, 10, 23, 12};

int tus_oku() // Bu fonksiyon, analog pininden gelen değere bağlı olarak hangi tuşun basıldığını belirler.
{
  int okunan = analogRead(0);
  if (okunan > 1000) return yok;
  if (okunan < 50) return sag;
  if (okunan < 195) return ust;
  if (okunan < 380) return alt;
  if (okunan < 555) return sol;
  if (okunan < 790) return secim;
  return yok;
}

void setup() {
  lcd.begin(16, 2); // LCD'yi başlat
  delay(1000); // 1 saniye bekle
  anaMenuGoster(); // Başlangıçta ana menüyü göster
}

void anaMenuGoster() {
  lcd.clear();
  if (durum == 0) {
    lcd.setCursor(0, 0);
    lcd.print("> YIYECEK");
    //lcd.setCursor(0, 1);
    //lcd.print("  YIYECEK");
  } else if (durum == 1) {
    lcd.setCursor(0, 0);
    //lcd.print("  ICECEK");
    //lcd.setCursor(0, 1);
    lcd.print("> ICECEK");
  } else if (durum == 2) {
    lcd.setCursor(0, 0);
    //lcd.print("  YIYECEK");
    //lcd.setCursor(0, 1);
    lcd.print("> TATLI");
  }
}

void altMenuGoster(const char* items[], byte itemCount, byte miktar[]) {
  lcd.clear();
  for (byte i = 0; i < 2 && ilk_gosterilen + i < itemCount; i++) {
    lcd.setCursor(0, i);
    if (alt_durum == ilk_gosterilen + i) {
      lcd.print(">");
    } else {
      lcd.print(" ");
    }
    lcd.print(items[ilk_gosterilen + i]);
    lcd.print(" ");
    lcd.print(miktar[ilk_gosterilen + i]);
  }
}

void toplamFiyatGoster() {
  float toplam_fiyat = 0;

  for (int i = 0; i < 5; i++) {
    toplam_fiyat += yiyecek_sayisi[i] * yiyecek_fiyat[i];
  }
  for (int i = 0; i < 5; i++) {
    toplam_fiyat += icecek_sayisi[i] * icecek_fiyat[i];
  }
  for (int i = 0; i < 5; i++) {
    toplam_fiyat += tatli_sayisi[i] * tatli_fiyat[i];
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Toplam Fiyat:");
  lcd.setCursor(0, 1);
  lcd.print(toplam_fiyat);
  delay(4000); // Toplam fiyatı 4 saniye göster
  anaMenuGoster(); // Ana menüye dön
}

void loop() {
  if (tus_oku() == secim && menu == 0) { // Ana menüde seçim tuşuna basıldıysa alt menüye gir
    menu = 1;
    delay(300);
  }

  while (menu == 1) {
    if (tus_oku() == sag && durum < 2) durum++; // Sağ tuşuna basılırsa menüde ilerle
    if (tus_oku() == sol && durum > 0) durum--; // Sol tuşuna basılırsa menüde geri git
    anaMenuGoster();
    delay(300);
    if (tus_oku() == secim) {
      menu = 2;
      alt_durum = 0;
      ilk_gosterilen = 0;
      delay(300);
    }
  }

  const char* yiyecekler[] = {"Makarna=20", "Pilav=25", "Karniyarik=30", "Salata=23","Corba=20"};
  const char* icecekler[] = {"Cay=5", "Kahve=10", "Su=4", "Limonata=8", "Kola=9"};
  const char* tatlilar[] = {"Tulumba=15", "Baklava=20", "Kazandibi=10","Ekler=23","Sutlac=12"};

  while (menu == 2) {
    if (tus_oku() == ust && alt_durum > 0) {
      alt_durum--;
      if (alt_durum < ilk_gosterilen) {
        ilk_gosterilen--;
      }
    }

    if (tus_oku() == alt && alt_durum < (durum == 0 ? sizeof(yiyecekler)/sizeof(yiyecekler[0]) : (durum == 1 ? sizeof(icecekler)/sizeof(icecekler[0]) : sizeof(tatlilar)/sizeof(tatlilar[0]))) - 1) {
      alt_durum++;
      if (alt_durum > ilk_gosterilen + 1) {
        ilk_gosterilen++;
      }
    }

    if (durum == 0) {
      altMenuGoster(yiyecekler, sizeof(yiyecekler)/sizeof(yiyecekler[0]), yiyecek_sayisi);
    } else if (durum == 1) {
      altMenuGoster(icecekler, sizeof(icecekler)/sizeof(icecekler[0]), icecek_sayisi);
    } else if (durum == 2) {
      altMenuGoster(tatlilar, sizeof(tatlilar)/sizeof(tatlilar[0]), tatli_sayisi);
    }

    delay(300);

    if (tus_oku() == secim) { // Kaç tane seçileceği artırılır
      if (durum == 0) {
        yiyecek_sayisi[alt_durum]++;
      } else if (durum == 1) {
        icecek_sayisi[alt_durum]++;
      } else if (durum == 2) {
        tatli_sayisi[alt_durum]++;
      }
      delay(300); // Seçim yapıldıktan sonra bekle
    }
    
    if (tus_oku() == sol) { // Seçilen öğenin miktarını azaltma
      if (durum == 0 && yiyecek_sayisi[alt_durum] > 0) {
        yiyecek_sayisi[alt_durum]--;
      } else if (durum == 1 && icecek_sayisi[alt_durum] > 0) {
        icecek_sayisi[alt_durum]--;
      } else if (durum == 2 && tatli_sayisi[alt_durum] > 0) {
        tatli_sayisi[alt_durum]--;
      }
      delay(300); // Geri alma işlemi yapıldıktan sonra bekle
    }

    if (tus_oku() == sag) {
      toplamFiyatGoster(); // Toplam fiyatı göster
      menu = 0; // Ana menüye dön
      ilk_gosterilen = 0;
      alt_durum = 0;
      delay(300);
    }
  }
}
