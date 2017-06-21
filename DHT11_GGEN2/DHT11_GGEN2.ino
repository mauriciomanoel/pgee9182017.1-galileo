
#include "DHT.h"

#define DHTIN 2 // what pin we're connected to
#define DHTOUT 3 // Conectar um diodo de DHTOUT -> DHTIN

#define DHTTYPE DHT11 // DHT 11 

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTIN,DHTOUT, DHTTYPE);

String comando, temperatura, umidade;
const char* cmd;

void setup() {
 Serial.begin(9600); 
 Serial.println("Teste DHT11");
 
 dht.begin();
}

void loop() {
  // Aguardando um segundo para medição.
  delay(1000);

  // O tempo de leitura para temperatura ou umidade leva cerca de 250 milissegundos!  
  float h = dht.readHumidity(); // leitura da humidade  
  float t = dht.readTemperature(); // leitura da temperatura em celsius (Para F, passar como parâmetro true);

  //temperatura = String(t);
  //umidade = String(h);
  temperatura = String('t, 2');
  umidade = String('h, 2');
    
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Falha na leitura do Sensor DHT11");
    return;
  }

  Serial.print("Humidade: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: "); 
  Serial.print(t);
  Serial.println(" *C ");

  //comando = "python /home/pi/create_html_dht11.py ok " + temperatura + " " + umidade + " > /dev/ttyGS0"; // String com o comando para execução no system
  //cmd = comando.c_str(); // convertendo os dados para contante char;
  //system(comando.buffer);
    
}
