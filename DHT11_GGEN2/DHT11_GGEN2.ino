
#include "DHT.h"

#define DHTIN 2 // what pin we're connected to
#define DHTOUT 3 // Conectar um diodo de DHTOUT -> DHTIN

#define DHTTYPE DHT11 // DHT 11 

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTIN,DHTOUT, DHTTYPE);

String comando;
char temperatura[5], umidade[5];

void setup() {
 Serial.begin(9600); 
 Serial.println("Teste DHT11");
 
 dht.begin();
}

void loop() {
  // Aguardando um segundo para medição.
  delay(2000);

  // O tempo de leitura para temperatura ou umidade leva cerca de 250 milissegundos!  
  float h = dht.readHumidity(); // leitura da humidade  
  float t = dht.readTemperature(); // leitura da temperatura em celsius (Para F, passar como parâmetro true);
    
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Falha na leitura do Sensor DHT11");
    updateSystem("nok", "0", "0");
    return;
  }

  // Conversão de float para char
  sprintf(umidade, "%2.0f", h);
  sprintf(temperatura, "%2.0f", t);
  
  Serial.print("Temperatura: "); 
  Serial.print(temperatura);
  Serial.print("*C ");  
  Serial.print("Humidade: "); 
  Serial.print(umidade);
  Serial.println("%\t");
  
  updateSystem("ok", temperatura, umidade);
}

// Método responsável por enviar os dados para o SO da Galileo Gen 2
void updateSystem(String status, char temperatura[], char umidade[]) {
  String comando = "./home/root/pgee9182017.1-galileo/create_html_dht11.py " + status + " " + String(temperatura) + " " + String(umidade) + " > /dev/ttyGS0"; // String com o comando para execução no system  
  Serial.println(comando);
  system(comando.buffer);
}

