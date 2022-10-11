#include "DHT.h"
#include <LCD_I2C.h>
#include <Fuzzy.h>
#include <WiFi.h>
#include <WebServer.h>

LCD_I2C lcd(0x27, 16, 2);
#define DHTPIN 23     
#define DHTTYPE DHT11   // DHT 11
#define Buton1 27
#define Buton2 26
#define Buton3 33
#define buzzer 13
#define kirmizi 12
#define sari 19
#define yesil 15
#define fan 5
DHT dht(DHTPIN, DHTTYPE);
const float topraknem=34;
float toprak_nem=0;
float output1=0; 
int sayi=0;
float h=0;
float t=0;
const char* ssid = "SUPERONLINE_Wi-Fi_117146";  // Wifi
const char* password = "INNBOX2503008816";  //wifi şifre
WebServer server(80);  //80 portunu kullanarak bir web server nesnesi oluşturduk


Fuzzy *fuzzy = new Fuzzy();// Fuzzy
// Fuzzy giriş sıcaklık
FuzzySet *soguk = new FuzzySet(0, 5, 5, 10);
FuzzySet *hafif_soguk = new FuzzySet(5, 10, 10, 15);
FuzzySet *ilik = new FuzzySet(10, 15, 15, 20);
FuzzySet *hafif_sicak = new FuzzySet(15, 20, 20, 25);
FuzzySet *sicak = new FuzzySet(20, 25, 25, 30);

// Fuzzy giriş nem
FuzzySet *dusuk_nem = new FuzzySet(0, 20, 20, 30);
FuzzySet *orta_nem = new FuzzySet(20, 30, 30, 40);
FuzzySet *yuksek_nem = new FuzzySet(30, 40, 40, 50);

//Fuzzy giriş toprak nem
FuzzySet *toprak_dusuk_nem = new FuzzySet(0, 2000, 2000, 3000);
FuzzySet *toprak_orta_nem = new FuzzySet(2000, 3000, 3000, 4000);
FuzzySet *toprak_yuksek_nem = new FuzzySet(3000,4000, 4000, 5000);


// Fuzzy çıkış ürün kalitesi
FuzzySet *kotu_meyve = new FuzzySet(0, 25, 25, 50);
FuzzySet *orta_meyve = new FuzzySet(25, 50, 50,75 );
FuzzySet *iyi_meyve= new FuzzySet(50, 75, 75, 100);

void handle_OnConnect() {
    
  h = dht.readHumidity();
  t = dht.readTemperature();
  output1 = fuzzy->defuzzify(1);
  toprak_nem = analogRead(topraknem);

 server.send(200, "text/html", SendHTML(t,h,output1,toprak_nem)); 
}
void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
String SendHTML(float t,float h, float output1,float toprak_nem){
  String ptr = "<html lang=en-EN><head><meta http-equiv='refresh' content='60'/>";
  ptr += "<title>TARLALAR</title>";
  ptr += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000000; }</style>";
  ptr += "</head><body><h1>TARLALARIN DURUMLARI</h1>";
  ptr += "<h1>Kavun Tarlasi</h1>";  //Kavun Tarlasi
  ptr += "<ul><li>Sicaklik: ";
  ptr += (int)t;
  ptr +="&deg;C</li>";
  ptr += "<li>Nem: ";
  ptr += (int)h;
  ptr += "RH</li>";
  ptr += "<li>Toprak nemi: ";
  ptr += (int) toprak_nem;
   ptr += "RH</li>";
  ptr += "<li>Urun Kalitesi: ";
  ptr += (int)output1;
  ptr += " %</li></ul>";
 
  ptr += "<h3>\n\nSicaklik</h3>";
   ptr +=("<ul><li>\n\nsoguk-> ");
  ptr +=(soguk->getPertinence());
  ptr +="</li><li>hafif_soguk-> ";
  ptr +=(hafif_soguk->getPertinence());
  ptr +="</li><li>\nilik-> ";
  ptr +=(ilik->getPertinence());
  ptr +=("</li><li>\nhafif_sicak-> ");
  ptr +=(hafif_sicak->getPertinence());
  ptr +=("</li><li>\nsicak-> ");
  ptr +=(sicak->getPertinence());
  ptr += "</li></ul>";

  ptr += "<h3>Nem</h3>";
  ptr +=("<ul><li>\n\ndusuk_nem-> ");
  ptr +=(dusuk_nem->getPertinence());
  ptr +=("</li><li>\norta_nem-> ");
  ptr +=(orta_nem->getPertinence());
  ptr +=("</li><li>\nyuksek_nem-> ");
  ptr +=(yuksek_nem->getPertinence());
  ptr += "</li></ul>";

  ptr += "<h3>Toprak Nem</h3>";
  ptr +=("<ul><li>\n\ntoprak_dusuk_nem-> ");
  ptr +=(toprak_dusuk_nem->getPertinence());
  ptr +=("</li><li>\ntoprak_orta_nem-> ");
  ptr +=(toprak_orta_nem->getPertinence());
  ptr +=("</li><li>\ntoprak_yuksek_nem-> ");
  ptr +=(toprak_yuksek_nem->getPertinence());
  ptr += "</li></ul>";
  
  ptr +=("<h3>\n\nUrun Kalitesi: </h3>");
  ptr +=("<ul><li>\n\nkotu_meyve-> ");
  ptr +=(kotu_meyve->getPertinence());
  ptr +=("</li><li>\norta_meyve-> ");
  ptr +=(orta_meyve->getPertinence());
  ptr +=("</li><li>\niyi_meyve-> ");
  ptr +=(iyi_meyve->getPertinence());
  ptr += "</li></ul>";

  
   ptr += "<h1>Salatalik Tarlasi</h1>";   //Salatalik Tarlasi
  ptr += "<ul><li>Sicaklik: ";
  ptr += (int)t;
  ptr +="&deg;C</li>";
  ptr += "<li>Nem: ";
  ptr += (int)h;
  ptr += "RH</li>";
  ptr += "<li>Toprak nemi: ";
  ptr += (int)toprak_nem;
   ptr += "RH</li>";
  ptr += "<li>Urun Kalitesi: ";
  ptr += (int)output1;
  ptr += " %</li></ul>";
 
 ptr += "<h3>\n\nSicaklik</h3>";
   ptr +=("<ul><li>\n\nsoguk-> ");
  ptr +=(soguk->getPertinence());
  ptr +="</li><li>hafif_soguk-> ";
  ptr +=(hafif_soguk->getPertinence());
  ptr +="</li><li>\nilik-> ";
  ptr +=(ilik->getPertinence());
  ptr +=("</li><li>\nhafif_sicak-> ");
  ptr +=(hafif_sicak->getPertinence());
  ptr +=("</li><li>\nsicak-> ");
  ptr +=(sicak->getPertinence());
  ptr += "</li></ul>";

  ptr += "<h3>Nem</h3>";
  ptr +=("<ul><li>\n\ndusuk_nem-> ");
  ptr +=(dusuk_nem->getPertinence());
  ptr +=("</li><li>\norta_nem-> ");
  ptr +=(orta_nem->getPertinence());
  ptr +=("</li><li>\nyuksek_nem-> ");
  ptr +=(yuksek_nem->getPertinence());
  ptr += "</li></ul>";

  ptr += "<h3>Toprak Nem</h3>";
  ptr +=("<ul><li>\n\ntoprak_dusuk_nem-> ");
  ptr +=(toprak_dusuk_nem->getPertinence());
  ptr +=("</li><li>\ntoprak_orta_nem-> ");
  ptr +=(toprak_orta_nem->getPertinence());
  ptr +=("</li><li>\ntoprak_yuksek_nem-> ");
  ptr +=(toprak_yuksek_nem->getPertinence());
  ptr += "</li></ul>";
  
  ptr +=("<h3>\n\nUrun Kalitesi: </h3>");
  ptr +=("<ul><li>\n\nkotu_meyve-> ");
  ptr +=(kotu_meyve->getPertinence());
  ptr +=("</li><li>\norta_meyve-> ");
  ptr +=(orta_meyve->getPertinence());
  ptr +=("</li><li>\niyi_meyve-> ");
  ptr +=(iyi_meyve->getPertinence());
  ptr += "</li></ul>";

  
  ptr += "<h1>Domates Tarlasi</h1>";  //Domates Tarlasi
  ptr += "<ul><li>Sicaklik: ";
  ptr += (int)t;
  ptr +="&deg;C</li>";
  ptr += "<li>Nem: ";
  ptr += (int)h;
  ptr += "RH</li>";
  ptr += "<li>Toprak nemi: ";
  ptr += (int)toprak_nem;
   ptr += "RH</li>";
  ptr += "<li>Urun Kalitesi: ";
  ptr += (int)output1;
  ptr += " %</li></ul>";
 
  ptr += "<h3>\n\nSicaklik</h3>";
   ptr +=("<ul><li>\n\nsoguk-> ");
  ptr +=(soguk->getPertinence());
  ptr +="</li><li>hafif_soguk-> ";
  ptr +=(hafif_soguk->getPertinence());
  ptr +="</li><li>\nilik-> ";
  ptr +=(ilik->getPertinence());
  ptr +=("</li><li>\nhafif_sicak-> ");
  ptr +=(hafif_sicak->getPertinence());
  ptr +=("</li><li>\nsicak-> ");
  ptr +=(sicak->getPertinence());
  ptr += "</li></ul>";

  ptr += "<h3>Nem</h3>";
  ptr +=("<ul><li>\n\ndusuk_nem-> ");
  ptr +=(dusuk_nem->getPertinence());
  ptr +=("</li><li>\norta_nem-> ");
  ptr +=(orta_nem->getPertinence());
  ptr +=("</li><li>\nyuksek_nem-> ");
  ptr +=(yuksek_nem->getPertinence());
  ptr += "</li></ul>";

  ptr += "<h3>Toprak Nem</h3>";
  ptr +=("<ul><li>\n\ntoprak_dusuk_nem-> ");
  ptr +=(toprak_dusuk_nem->getPertinence());
  ptr +=("</li><li>\ntoprak_orta_nem-> ");
  ptr +=(toprak_orta_nem->getPertinence());
  ptr +=("</li><li>\ntoprak_yuksek_nem-> ");
  ptr +=(toprak_yuksek_nem->getPertinence());
  ptr += "</li></ul>";
  
  ptr +=("<h3>\n\nUrun Kalitesi: </h3>");
  ptr +=("<ul><li>\n\nkotu_meyve-> ");
  ptr +=(kotu_meyve->getPertinence());
  ptr +=("</li><li>\norta_meyve-> ");
  ptr +=(orta_meyve->getPertinence());
  ptr +=("</li><li>\niyi_meyve-> ");
  ptr +=(iyi_meyve->getPertinence());
  ptr += "</li></ul>";

   
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  pinMode(Buton1, INPUT_PULLUP);
  pinMode(Buton2, INPUT_PULLUP);
  pinMode(Buton3, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, HIGH);  
  
  // Fuzzy giriş
  FuzzyInput *sicaklik = new FuzzyInput(1);
  sicaklik->addFuzzySet(soguk);
  sicaklik->addFuzzySet(hafif_soguk);
  sicaklik->addFuzzySet(ilik);
  sicaklik->addFuzzySet(hafif_sicak);
  sicaklik->addFuzzySet(sicak);
  fuzzy->addFuzzyInput(sicaklik);

  // Fuzzy giriş
  FuzzyInput *nem = new FuzzyInput(2);
  nem->addFuzzySet(dusuk_nem);
  nem->addFuzzySet(orta_nem);
  nem->addFuzzySet(yuksek_nem);
  fuzzy->addFuzzyInput(nem);
  
  // Fuzzy giriş
  FuzzyInput *toprak_nem = new FuzzyInput(3);
  toprak_nem->addFuzzySet(toprak_dusuk_nem);
  toprak_nem->addFuzzySet(toprak_orta_nem);
  toprak_nem->addFuzzySet(toprak_yuksek_nem);
  fuzzy->addFuzzyInput(toprak_nem);

  
  // Fuzzy çıkış
  FuzzyOutput *urun_kalitesi = new FuzzyOutput(1);
  urun_kalitesi->addFuzzySet(kotu_meyve);
  urun_kalitesi->addFuzzySet(orta_meyve);
  urun_kalitesi->addFuzzySet(iyi_meyve);
  fuzzy->addFuzzyOutput(urun_kalitesi);

  
  // tanımlama
  FuzzyRuleAntecedent *toprakdusuknem = new FuzzyRuleAntecedent();
  toprakdusuknem->joinSingle(toprak_dusuk_nem);
  FuzzyRuleAntecedent *toprakortanem = new FuzzyRuleAntecedent();
  toprakortanem->joinSingle(toprak_orta_nem);
  FuzzyRuleAntecedent *toprakyukseknem = new FuzzyRuleAntecedent();
  toprakyukseknem->joinSingle(toprak_yuksek_nem);

  FuzzyRuleAntecedent *sicakliksoguk_nemdusuk = new FuzzyRuleAntecedent();
  sicakliksoguk_nemdusuk->joinWithAND(soguk,dusuk_nem);
  FuzzyRuleAntecedent *sicakliksoguk_nemorta = new FuzzyRuleAntecedent();
  sicakliksoguk_nemorta->joinWithAND(soguk,orta_nem);
  FuzzyRuleAntecedent *sicakliksoguk_nemyuksek= new FuzzyRuleAntecedent();
  sicakliksoguk_nemyuksek->joinWithAND(soguk,yuksek_nem);

  FuzzyRuleAntecedent *sicaklikhafifsoguk_nemdusuk = new FuzzyRuleAntecedent();
  sicakliksoguk_nemdusuk->joinWithAND(hafif_soguk,dusuk_nem);
  FuzzyRuleAntecedent *sicaklikhafifsoguk_nemorta = new FuzzyRuleAntecedent();
  sicaklikhafifsoguk_nemorta->joinWithAND(hafif_soguk,orta_nem);
  FuzzyRuleAntecedent *sicaklikhafifsoguk_nemyuksek = new FuzzyRuleAntecedent();
  sicaklikhafifsoguk_nemyuksek->joinWithAND(hafif_soguk,yuksek_nem);

  FuzzyRuleAntecedent *sicaklikilik_nemdusuk = new FuzzyRuleAntecedent();
  sicakliksoguk_nemdusuk->joinWithAND(ilik,dusuk_nem);
  FuzzyRuleAntecedent *sicaklikilik_nemorta = new FuzzyRuleAntecedent();
  sicaklikilik_nemorta->joinWithAND(ilik,orta_nem);
  FuzzyRuleAntecedent *sicaklikilik_nemyuksek = new FuzzyRuleAntecedent();
  sicaklikilik_nemyuksek->joinWithAND(ilik,yuksek_nem);

  FuzzyRuleAntecedent *sicaklikhafifsicak_nemdusuk = new FuzzyRuleAntecedent();
  sicaklikhafifsicak_nemdusuk->joinWithAND(hafif_sicak,dusuk_nem);
  FuzzyRuleAntecedent *sicaklikhafifsicak_nemorta = new FuzzyRuleAntecedent();
  sicaklikhafifsicak_nemorta->joinWithAND(hafif_sicak,orta_nem);
  FuzzyRuleAntecedent *sicaklikhafifsicak_nemyuksek = new FuzzyRuleAntecedent();
  sicaklikhafifsicak_nemyuksek->joinWithAND(hafif_sicak,yuksek_nem);

  FuzzyRuleAntecedent *sicakliksicak_nemdusuk = new FuzzyRuleAntecedent();
  sicakliksicak_nemdusuk->joinWithAND(sicak,dusuk_nem);
  FuzzyRuleAntecedent *sicakliksicak_nemorta = new FuzzyRuleAntecedent();
  sicakliksicak_nemorta->joinWithAND(sicak,orta_nem);
  FuzzyRuleAntecedent *sicakliksicak_nemyuksek = new FuzzyRuleAntecedent();
  sicakliksicak_nemyuksek->joinWithAND(sicak,yuksek_nem);

  FuzzyRuleConsequent *urunkalitesi_kotumeyve = new FuzzyRuleConsequent();
  urunkalitesi_kotumeyve->addOutput(kotu_meyve);
  FuzzyRuleConsequent *urunkalitesi_ortameyve = new FuzzyRuleConsequent();
  urunkalitesi_ortameyve->addOutput(orta_meyve);
  FuzzyRuleConsequent *urunkalitesi_iyimeyve = new FuzzyRuleConsequent();
  urunkalitesi_iyimeyve->addOutput(iyi_meyve);

  // fuzzy kurallarını oluşturma
  FuzzyRuleAntecedent *eger_sicakliksoguk_nemdusuk_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemdusuk_topraknemdusuk->joinWithOR(sicakliksoguk_nemdusuk, toprakdusuknem);
  FuzzyRule *fuzzykural_1 = new FuzzyRule(1,eger_sicakliksoguk_nemdusuk_topraknemdusuk, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_1);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemdusuk_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemdusuk_topraknemorta->joinWithOR(sicakliksoguk_nemdusuk, toprakortanem);
  FuzzyRule *fuzzykural_2 = new FuzzyRule(1.20,eger_sicakliksoguk_nemdusuk_topraknemorta, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_2);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemdusuk_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemdusuk_topraknemyuksek->joinWithOR(sicakliksoguk_nemdusuk, toprakyukseknem);
  FuzzyRule *fuzzykural_3 = new FuzzyRule(1.40,eger_sicakliksoguk_nemdusuk_topraknemyuksek, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_3);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemorta_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemorta_topraknemdusuk->joinWithOR(sicakliksoguk_nemorta, toprakdusuknem);
  FuzzyRule *fuzzykural_4 = new FuzzyRule(1.60,eger_sicakliksoguk_nemorta_topraknemdusuk, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_4);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemorta_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemorta_topraknemorta->joinWithOR(sicakliksoguk_nemorta, toprakortanem);
  FuzzyRule *fuzzykural_5 = new FuzzyRule(1.80,eger_sicakliksoguk_nemorta_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_5);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemorta_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemorta_topraknemorta->joinWithOR(sicakliksoguk_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_6 = new FuzzyRule(2,eger_sicakliksoguk_nemorta_topraknemyuksek, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_6);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemyuksek_topraknemdusuk= new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemyuksek_topraknemdusuk->joinWithOR(sicakliksoguk_nemyuksek, toprakdusuknem);
  FuzzyRule *fuzzykural_7 = new FuzzyRule(2.20,eger_sicakliksoguk_nemyuksek_topraknemdusuk, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_7);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemyuksek_topraknemorta= new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemyuksek_topraknemorta->joinWithOR(sicakliksoguk_nemyuksek, toprakortanem);
  FuzzyRule *fuzzykural_8 = new FuzzyRule(2.40,eger_sicakliksoguk_nemyuksek_topraknemorta, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_8);

  FuzzyRuleAntecedent *eger_sicakliksoguk_nemyuksek_topraknemyuksek= new FuzzyRuleAntecedent();
  eger_sicakliksoguk_nemyuksek_topraknemyuksek->joinWithOR(sicakliksoguk_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_9 = new FuzzyRule(2.60,eger_sicakliksoguk_nemyuksek_topraknemyuksek, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_9);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemdusuk_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemdusuk_topraknemdusuk->joinWithOR(sicaklikhafifsoguk_nemdusuk, toprakdusuknem);
  FuzzyRule *fuzzykural_10 = new FuzzyRule(2.8,eger_sicaklikhafifsoguk_nemdusuk_topraknemdusuk, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_10);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemdusuk_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemdusuk_topraknemorta->joinWithOR(sicaklikhafifsoguk_nemdusuk, toprakortanem);
  FuzzyRule *fuzzykural_11 = new FuzzyRule(3,eger_sicaklikhafifsoguk_nemdusuk_topraknemorta, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_11);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemdusuk_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemdusuk_topraknemyuksek->joinWithOR(sicaklikhafifsoguk_nemdusuk, toprakyukseknem);
  FuzzyRule *fuzzykural_12 = new FuzzyRule(3.2,eger_sicaklikhafifsoguk_nemdusuk_topraknemyuksek, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_12);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemorta_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemorta_topraknemdusuk->joinWithOR(sicaklikhafifsoguk_nemorta, toprakdusuknem);
  FuzzyRule *fuzzykural_13 = new FuzzyRule(3.4,eger_sicaklikhafifsoguk_nemorta_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_13);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemorta_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemorta_topraknemorta->joinWithOR(sicaklikhafifsoguk_nemorta, toprakortanem);
  FuzzyRule *fuzzykural_14 = new FuzzyRule(3.6,eger_sicaklikhafifsoguk_nemorta_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_14);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemorta_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemorta_topraknemorta->joinWithOR(sicaklikhafifsoguk_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_15 = new FuzzyRule(3.8,eger_sicaklikhafifsoguk_nemorta_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_15);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemyuksek_topraknemdusuk= new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemyuksek_topraknemdusuk->joinWithOR(sicaklikhafifsoguk_nemyuksek, toprakdusuknem);
  FuzzyRule *fuzzykural_16 = new FuzzyRule(4,eger_sicaklikhafifsoguk_nemyuksek_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_16);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemyuksek_topraknemorta= new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemyuksek_topraknemorta->joinWithOR(sicaklikhafifsoguk_nemyuksek, toprakortanem);
  FuzzyRule *fuzzykural_17 = new FuzzyRule(4.2,eger_sicaklikhafifsoguk_nemyuksek_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_17);

  FuzzyRuleAntecedent *eger_sicaklikhafifsoguk_nemyuksek_topraknemyuksek= new FuzzyRuleAntecedent();
  eger_sicaklikhafifsoguk_nemyuksek_topraknemyuksek->joinWithOR(sicaklikhafifsoguk_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_18 = new FuzzyRule(4.4,eger_sicaklikhafifsoguk_nemyuksek_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_18);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemdusuk_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemdusuk_topraknemdusuk->joinWithOR(sicaklikilik_nemdusuk, toprakdusuknem);
  FuzzyRule *fuzzykural_19 = new FuzzyRule(4.6,eger_sicaklikilik_nemdusuk_topraknemdusuk, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_19);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemdusuk_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemdusuk_topraknemorta->joinWithOR(sicaklikilik_nemdusuk, toprakortanem);
  FuzzyRule *fuzzykural_20 = new FuzzyRule(4.8,eger_sicaklikilik_nemdusuk_topraknemorta, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_20);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemdusuk_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemdusuk_topraknemyuksek->joinWithOR(sicaklikilik_nemdusuk, toprakyukseknem);
  FuzzyRule *fuzzykural_21 = new FuzzyRule(5,eger_sicaklikilik_nemdusuk_topraknemyuksek, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_21);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemorta_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemorta_topraknemdusuk->joinWithOR(sicaklikilik_nemorta, toprakdusuknem);
  FuzzyRule *fuzzykural_22 = new FuzzyRule(5.20,eger_sicaklikilik_nemorta_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_22);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemorta_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemorta_topraknemorta->joinWithOR(sicaklikilik_nemorta, toprakortanem);
  FuzzyRule *fuzzykural_23 = new FuzzyRule(5.40,eger_sicaklikilik_nemorta_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_23);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemorta_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemorta_topraknemorta->joinWithOR(sicaklikilik_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_24 = new FuzzyRule(5.6,eger_sicaklikilik_nemorta_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_24);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemyuksek_topraknemdusuk= new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemyuksek_topraknemdusuk->joinWithOR(sicaklikilik_nemyuksek, toprakdusuknem);
  FuzzyRule *fuzzykural_25 = new FuzzyRule(5.8,eger_sicaklikilik_nemyuksek_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_25);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemyuksek_topraknemorta= new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemyuksek_topraknemorta->joinWithOR(sicaklikilik_nemyuksek, toprakortanem);
  FuzzyRule *fuzzykural_26 = new FuzzyRule(6,eger_sicaklikilik_nemyuksek_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_26);

  FuzzyRuleAntecedent *eger_sicaklikilik_nemyuksek_topraknemyuksek= new FuzzyRuleAntecedent();
  eger_sicaklikilik_nemyuksek_topraknemyuksek->joinWithOR(sicaklikilik_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_27 = new FuzzyRule(6.2,eger_sicaklikilik_nemyuksek_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_27);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemdusuk_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemdusuk_topraknemdusuk->joinWithOR(sicaklikhafifsicak_nemdusuk, toprakdusuknem);
  FuzzyRule *fuzzykural_28 = new FuzzyRule(6.4,eger_sicaklikhafifsicak_nemdusuk_topraknemdusuk, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_28);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemdusuk_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemdusuk_topraknemorta->joinWithOR(sicaklikhafifsicak_nemdusuk, toprakortanem);
  FuzzyRule *fuzzykural_29 = new FuzzyRule(6.6,eger_sicaklikhafifsicak_nemdusuk_topraknemorta, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_29);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemdusuk_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemdusuk_topraknemyuksek->joinWithOR(sicaklikhafifsicak_nemdusuk, toprakyukseknem);
  FuzzyRule *fuzzykural_30 = new FuzzyRule(6.8,eger_sicaklikhafifsicak_nemdusuk_topraknemyuksek, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_30);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemorta_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemorta_topraknemdusuk->joinWithOR(sicaklikhafifsicak_nemorta, toprakdusuknem);
  FuzzyRule *fuzzykural_31 = new FuzzyRule(7,eger_sicaklikhafifsicak_nemorta_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_31);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemorta_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemorta_topraknemorta->joinWithOR(sicaklikhafifsicak_nemorta, toprakortanem);
  FuzzyRule *fuzzykural_32 = new FuzzyRule(7.2,eger_sicaklikhafifsicak_nemorta_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_32);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemorta_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemorta_topraknemorta->joinWithOR(sicaklikhafifsicak_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_33 = new FuzzyRule(7.4,eger_sicaklikhafifsicak_nemorta_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_33);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemyuksek_topraknemdusuk= new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemyuksek_topraknemdusuk->joinWithOR(sicaklikhafifsicak_nemyuksek, toprakdusuknem);
  FuzzyRule *fuzzykural_34 = new FuzzyRule(7.6,eger_sicaklikhafifsicak_nemyuksek_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_34);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemyuksek_topraknemorta= new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemyuksek_topraknemorta->joinWithOR(sicaklikhafifsicak_nemyuksek, toprakortanem);
  FuzzyRule *fuzzykural_35 = new FuzzyRule(7.8,eger_sicaklikhafifsicak_nemyuksek_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_35);

  FuzzyRuleAntecedent *eger_sicaklikhafifsicak_nemyuksek_topraknemyuksek= new FuzzyRuleAntecedent();
  eger_sicaklikhafifsicak_nemyuksek_topraknemyuksek->joinWithOR(sicaklikhafifsicak_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_36 = new FuzzyRule(8,eger_sicaklikhafifsicak_nemyuksek_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_36);

  FuzzyRuleAntecedent *eger_sicakliksicak_nemdusuk_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemdusuk_topraknemdusuk->joinWithOR(sicakliksicak_nemdusuk, toprakdusuknem);
  FuzzyRule *fuzzykural_37 = new FuzzyRule(1,eger_sicakliksicak_nemdusuk_topraknemdusuk, urunkalitesi_kotumeyve);
  fuzzy->addFuzzyRule(fuzzykural_37);

  FuzzyRuleAntecedent *eger_sicakliksicak_nemdusuk_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemdusuk_topraknemorta->joinWithOR(sicakliksicak_nemdusuk, toprakortanem);
  FuzzyRule *fuzzykural_38 = new FuzzyRule(1.20,eger_sicakliksicak_nemdusuk_topraknemorta, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_38);

  FuzzyRuleAntecedent *eger_sicakliksicak_nemdusuk_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemdusuk_topraknemyuksek->joinWithOR(sicakliksicak_nemdusuk, toprakyukseknem);
  FuzzyRule *fuzzykural_39 = new FuzzyRule(1.40,eger_sicakliksicak_nemdusuk_topraknemyuksek, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_39);

  FuzzyRuleAntecedent *eger_sicakliksicak_nemorta_topraknemdusuk = new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemorta_topraknemdusuk->joinWithOR(sicakliksicak_nemorta, toprakdusuknem);
  FuzzyRule *fuzzykural_40 = new FuzzyRule(1.60,eger_sicakliksicak_nemorta_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_40);

  FuzzyRuleAntecedent *eger_sicakliksicak_nemorta_topraknemorta = new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemorta_topraknemorta->joinWithOR(sicakliksicak_nemorta, toprakortanem);
  FuzzyRule *fuzzykural_41 = new FuzzyRule(1.80,eger_sicakliksicak_nemorta_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_41);

  FuzzyRuleAntecedent *eger_sicakliksicak_nemorta_topraknemyuksek = new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemorta_topraknemorta->joinWithOR(sicakliksicak_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_42 = new FuzzyRule(2,eger_sicakliksicak_nemorta_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_42);


  FuzzyRuleAntecedent *eger_sicakliksicak_nemyuksek_topraknemdusuk= new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemyuksek_topraknemdusuk->joinWithOR(sicakliksicak_nemyuksek, toprakdusuknem);
  FuzzyRule *fuzzykural_43 = new FuzzyRule(2.20,eger_sicakliksicak_nemyuksek_topraknemdusuk, urunkalitesi_ortameyve);
  fuzzy->addFuzzyRule(fuzzykural_43);


  FuzzyRuleAntecedent *eger_sicakliksicak_nemyuksek_topraknemorta= new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemyuksek_topraknemorta->joinWithOR(sicakliksicak_nemyuksek, toprakortanem);
  FuzzyRule *fuzzykural_44 = new FuzzyRule(2.40,eger_sicakliksicak_nemyuksek_topraknemorta, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_44);


  FuzzyRuleAntecedent *eger_sicakliksicak_nemyuksek_topraknemyuksek= new FuzzyRuleAntecedent();
  eger_sicakliksicak_nemyuksek_topraknemyuksek->joinWithOR(sicakliksicak_nemyuksek, toprakyukseknem);
  FuzzyRule *fuzzykural_45 = new FuzzyRule(2.60,eger_sicakliksicak_nemyuksek_topraknemyuksek, urunkalitesi_iyimeyve);
  fuzzy->addFuzzyRule(fuzzykural_45);


  
 Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
  
 }

void loop() {
  delay(500);  
  toprak_nem=analogRead(topraknem);  
  float h = dht.readHumidity();  
  float t = dht.readTemperature();
  output1 = fuzzy->defuzzify(1);
      
  fuzzy->setInput(1, t);
  fuzzy->setInput(2, h);
  fuzzy->setInput(3, toprak_nem);
  fuzzy->fuzzify();

  server.handleClient();
  

  


   
  Serial.println("\n\n\nGİRİŞ: ");
  Serial.print("\t\t\tSıcaklık: ");
  Serial.print(t);
  Serial.print(", Nem: ");
  Serial.print(h);
  Serial.print(", Toprak Nemi: ");
  Serial.println(toprak_nem);
  Serial.print("\nSıcaklık:\nSoğuk-> ");
  Serial.print(soguk->getPertinence());
  Serial.print("\nHafif Soguk-> ");
  Serial.print(hafif_soguk->getPertinence());
  Serial.print(" \nIlık-> ");
  Serial.print(ilik->getPertinence());
  Serial.print(" \nHafif Sıcak-> ");
  Serial.print(hafif_sicak->getPertinence());
  Serial.print("\nSıcak-> ");
  Serial.print(sicak->getPertinence());
  Serial.print("\n\nNem:\nDüşük Nem-> ");
  Serial.print(dusuk_nem->getPertinence());
  Serial.print("\nOrta Nem-> ");
  Serial.print(orta_nem->getPertinence());
  Serial.print("\nYüksek Nem-> ");
  Serial.print(yuksek_nem->getPertinence());
  Serial.print("\n\nToprak Nem:\nToprak Düşük Nem-> ");
  Serial.print(toprak_dusuk_nem->getPertinence());
  Serial.print("\nToprak Orta Nem-> ");
  Serial.print(toprak_orta_nem->getPertinence());
  Serial.print("\nToprak Yuksek Nem-> ");
  Serial.print(toprak_yuksek_nem->getPertinence()); 
  Serial.print("\n\nÇIKIŞ: ");
  Serial.print("\nÜrün Kalitesi: \nKötü Meyve-> ");
  Serial.print(kotu_meyve->getPertinence());
  Serial.print("\nOrta Meyve-> ");
  Serial.print(orta_meyve->getPertinence());
  Serial.print("\nİyi Meyve-> ");
  Serial.print(iyi_meyve->getPertinence());
  Serial.println("\n\nSONUÇ: ");
  Serial.println("\nÜrün Kalitesi: ");
  Serial.print(output1);  
  
  if (digitalRead(Buton1) == LOW){
    sayi=1;
   }
   if  (sayi==1){
    lcd.setCursor(0,0);
  lcd.cursor();
  lcd.print("TARLA DURUMU");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.blink();
  lcd.print("KAVUN SERASI");
  delay(500);    
  lcd.setCursor(0,1);
  lcd.print("Sicaklik:");
  lcd.setCursor(9,1);
  lcd.print(t);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nem:");
  lcd.setCursor(4,0);
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Toprak Nemi:");
  lcd.setCursor(12,1);
  lcd.print(toprak_nem);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("urun kalite:");
  lcd.setCursor(12,0);
  lcd.print(output1);
  delay(500);
  lcd.clear();
  if (35<t){
    digitalWrite(fan,LOW);
    delay(500);
    digitalWrite(fan,HIGH);
    delay(100);
    }   
  if (output1<30){
      digitalWrite(buzzer, HIGH); 
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(kirmizi, HIGH); 
      delay(200);
      digitalWrite(kirmizi, LOW);
      delay(200);
    }
    if(output1>29 && output1<70){      
      digitalWrite(sari, HIGH); 
      delay(200);
      digitalWrite(sari, LOW);
      delay(200);      
    }
     if (output1>69 && output1<100){
      digitalWrite(yesil, HIGH); 
      delay(200);
      digitalWrite(yesil, LOW);
      delay(200);      
     }
     
    }
  if (digitalRead(Buton2) == LOW){
    sayi=2;
   }
   if  (sayi==2){
    lcd.setCursor(0,0);
  lcd.cursor();
  lcd.print("TARLA DURUMU");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.blink();
  lcd.print("SALATALIK SERASI");
  delay(500);    
  lcd.setCursor(0,1);
  lcd.print("Sicaklik:");
  lcd.setCursor(9,1);
  lcd.print(t);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nem:");
  lcd.setCursor(4,0);
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Toprak Nemi:");
  lcd.setCursor(12,1);
  lcd.print(toprak_nem);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("urun kalite:");
  lcd.setCursor(12,0);
  lcd.print(output1);
  delay(500);
  lcd.clear();
  if (30<t ){
    digitalWrite(fan,LOW);
    delay(500);
    digitalWrite(fan,HIGH);
    delay(100);
    }   
   if (output1<30){
      digitalWrite(buzzer, HIGH); 
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(kirmizi, HIGH); 
      delay(200);
      digitalWrite(kirmizi, LOW);
      delay(200);
    }
    if(output1>29 && output1<70){      
      digitalWrite(sari, HIGH); 
      delay(200);
      digitalWrite(sari, LOW);
      delay(200);      
    }
     if (output1>69 && output1<100){
      digitalWrite(yesil, HIGH); 
      delay(200);
      digitalWrite(yesil, LOW);
      delay(200);      
     }
   }
    
  if (digitalRead(Buton3) == LOW){
    sayi=3;
   }
  if  (sayi==3){
    lcd.setCursor(0,0);
  lcd.cursor();
  lcd.print("TARLA DURUMU");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.blink();
  lcd.print("DOMATES SERASI");
  delay(500);    
  lcd.setCursor(0,1);
  lcd.print("Sicaklik:");
  lcd.setCursor(9,1);
  lcd.print(t);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nem:");
  lcd.setCursor(4,0);
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Toprak Nemi:");
  lcd.setCursor(12,1);
  lcd.print(toprak_nem);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("urun kalite:");
  lcd.setCursor(12,0);
  lcd.print(output1);
  delay(500);
  lcd.clear();
  if (25<t ){
    digitalWrite(fan,LOW);
    delay(500);
    digitalWrite(fan,HIGH);
    delay(100);
    }   
    if (output1<30){
      digitalWrite(buzzer, HIGH); 
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(kirmizi, HIGH); 
      delay(200);
      digitalWrite(kirmizi, LOW);
      delay(200);
    }
    if(output1>29 && output1<70){      
      digitalWrite(sari, HIGH); 
      delay(200);
      digitalWrite(sari, LOW);
      delay(200);      
    }
     if (output1>69 && output1<100){
      digitalWrite(yesil, HIGH); 
      delay(200);
      digitalWrite(yesil, LOW);
      delay(200);      
     }
    }
    
 }
