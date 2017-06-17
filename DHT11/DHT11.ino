#include "DHT.h"
 
#define DHTPIN A1 // Pino que estamos conectado
#define DHTTYPE DHT11 // Modelo do Sensor
 
DHT dht(DHTPIN, DHTTYPE);

String comando, temperatura, umidade;
const char* cmd;
void setup() 
{
  Serial.begin(9600);
  dht.begin();
  delay(1000); //Delay para o início da execução do programa
}
 
void loop() 
{
  // Carregando os valores 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Falha ao ler o sensor ");
    
    comando = "python /home/pi/create_html_dht11.py nok 0 0 > /dev/ttyGS0"; // String com o comando para execução no system
    cmd = comando.c_str(); // convertendo os dados para contante char;
    //system(comando);
    Serial.println(comando);
    delay(2000); //Delay de dois segundos entre as leituras da informação
  } 
  else
  {
    temperatura = String(t);
    umidade = String(h);
    
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print("*C ");
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.println("%  ");
    
    comando = "python /home/pi/create_html_dht11.py ok " + temperatura + " " + umidade + " > /dev/ttyGS0"; // String com o comando para execução no system    
    cmd = comando.c_str(); // convertendo os dados para contante char;
    //system(comando);
    Serial.println(cmd);
    delay(2000); //Delay de dois segundos entre as leituras da informação
  }
}
