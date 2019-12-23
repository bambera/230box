/*
Sketch para comprobar los sensores
DS18B20 ya teniendo nuestro identificador unico arreglado por c2mismo enero 2019

en el LCD imprimira:

Primera linea:
Temperatura en Centigrados y la resolucion a la que esta configurado

Segunda linea:
Nos comenta que podemos cambiar la resolucion a la mas alta (12bits) pulsando le tecla SELEC

Notas:
Debe haber una resistencia de 4K7 entre los +5V (rojo) y la senal (amarillo). (El negro a GND)


*/

///////////////////////
//  LIBRARY CONF     //
///////////////////////


#include <OneWire.h>
#include <DallasTemperature.h>

const int pinOneWire = 2;

OneWire oneWire (pinOneWire);
DallasTemperature DS18B20 (&oneWire);
 
// Variables con las direcciones únicas del sensor DS18B20
DeviceAddress sensorPrueba = {0x28, 0xAA, 0xE0, 0x2A, 0x1B, 0x13, 0x02, 0xB2}; //Mark Amerillo/Verde
// Otro sensorPrueba
// DeviceAddress nombreSensor = {0x28, 0xE5, 0xE0, 0xAF, 0x33, 0x14, 0x01, 0x86};

///////////////////////
// FIN LIBRARY CONF  //
///////////////////////

int option;

void setup() {
  // Iniciamos la comunicación serie
  Serial.begin(9600);
  // Iniciamos el bus 1-Wire
  DS18B20.begin();
 
  // Descomenta para cambiar la resolucion
  // 9 = 9bit (0,5 C), 10 = 10bit (0,25 C), 11 = 11bit (0,129 C) y 12 = 12bit (0,0625 C)
 // DS18B20.setResolution(sensorPrueba, 12);

}


void loop() {
  
  // Mandamos comandos para toma de temperatura a los sensores
  DS18B20.requestTemperatures();

  float tmpSensor = DS18B20.getTempC(sensorPrueba);
  
  // guardamos la temperatura con una variable tipo entera para evitar
  // errores de calculo y otros.
  int tmpSensorInt = DS18B20.getTempC(sensorPrueba)*100;
  
  // para imprimir resultados convertimos en decimales
  float temperaturaSensor = tmpSensorInt;
  temperaturaSensor = temperaturaSensor/100;
  
  // Mostramos los datos del sensor
  
  Serial.print("Temp: ");
  if (tmpSensor == -127.00){
    Serial.print("ERROR READ TEMP");
  }else{
    Serial.print(tmpSensor);
    Serial.print(" ºC");
    delay(200);
  }
  
  // Mostramos la resolucion actual del sensor

  int resSensorPrueba = DS18B20.getResolution(sensorPrueba);
  
  if (resSensorPrueba != 0){
    Serial.print("    Resolution: ");
    Serial.print(resSensorPrueba);
    Serial.println(" bits");
  }else{
    Serial.println("ERROR READ Resolution"); 
  }
  Serial.println();


// Pulsamos el boton Selec para cambiar la resolucion a 12bits
  Serial.println("For change resolution push: ");
  Serial.println("1 =  9bit (0,5 C)");
  Serial.println("2 = 10bit (0,25 C)");
  Serial.println("3 = 11bit (0,129 C)");
  Serial.println("4 = 12bit (0,0625 C)");
  Serial.println("····················");
  Serial.println("····················"); Serial.println();

  if (Serial.available()>0){
    option=Serial.read();
    if (option == '1') DS18B20.setResolution(sensorPrueba, 9);
    if (option == '2') DS18B20.setResolution(sensorPrueba, 10);
    if (option == '3') DS18B20.setResolution(sensorPrueba, 11);
    if (option == '4') DS18B20.setResolution(sensorPrueba, 12);
  }

  delay (2000);

}
