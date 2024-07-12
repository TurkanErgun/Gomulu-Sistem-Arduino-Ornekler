#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

int tus_oku()
{
  int okunan = analogRead(0);
  if (okunan > 900) return yok;
  if (okunan < 50) return sag;
  if (okunan < 195) return ust;
  if (okunan < 380) return alt;
  if (okunan < 555) return sol;
  if (okunan < 790) return secim;
  return yok;
}

bool menu_goruntusu = false;
int menu_index = 0;
String yiyecekler[7] = {"Pizza  ", "Burger ", "Makarna", "Kraker  ", "Biskuvi  ", "Cikolata  ", "Pirinc Patlagi"};
String icecekler[8] = {"Kola    ", "Limonata", "Cay     ", "Ice Tea  ", "Ayran     ", "Soda       ", "Gazoz     ", "Meyve Suyu    "};
int liste_index = 0;
bool yiyecek_secili[7] = {false};
bool icecek_secili[8] = {false};

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Hosgeldiniz");
}

void menuGuncelle()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(menu_index == 0 ? "Yiyecekler" : "Icecekler");
  for (int i = 0; i < 2; i++)
  {
    int index = (liste_index + i) % (menu_index == 0 ? 7 : 8);
    lcd.setCursor(0, i + 1);
    if (menu_index == 0)
    {
      if (yiyecek_secili[index])
        lcd.print("*" + yiyecekler[index]);
      else
        lcd.print(yiyecekler[index]);
    }
    else
    {
      if (icecek_secili[index])
        lcd.print("*" + icecekler[index]);
      else
        lcd.print(icecekler[index]);
    }
  }
}

void loop()
{
  int tus_durumu = tus_oku();

  if (!menu_goruntusu && tus_durumu == secim)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Menuye giris");
    menu_goruntusu = true;
    delay(500);
    menuGuncelle();
  }
  else if (menu_goruntusu)
  {
    if (tus_durumu == sag || tus_durumu == sol)
    {
      menu_index = 1 - menu_index;
      liste_index = 0;
      menuGuncelle();
      delay(500);
    }
    else if (tus_durumu == ust && liste_index > 0)
    {
      liste_index--;
      menuGuncelle();
      delay(500);
    }
    else if (tus_durumu == alt && liste_index < (menu_index == 0 ? 6 : 7))
    {
      liste_index++;
      menuGuncelle();
      delay(500);
    }
    else if (tus_durumu == secim)
    {
      if (menu_index == 0)
        yiyecek_secili[liste_index] = !yiyecek_secili[liste_index];
      else
        icecek_secili[liste_index] = !icecek_secili[liste_index];
      menuGuncelle();
      delay(500);
    }
  }
}
