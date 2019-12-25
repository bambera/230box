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
DeviceAddress sensor1 = {0x28, 0xAA, 0xE0, 0x2A, 0x1B, 0x13, 0x02, 0xB2}; //Mark Amerillo/Verde
// Otro sensor1
DeviceAddress sensorExtern = {0x28, 0xE5, 0xE0, 0xAF, 0x33, 0x14, 0x01, 0x86};

///////////////////////
// FIN LIBRARY CONF  //
///////////////////////

int option;

void setup() {
  Serial.begin(9600);
  DS18B20.begin();
}


void loop() {

  DS18B20.requestTemperatures();
  float tmpSensorFlo = DS18B20.getTempC(sensor1);
    Serial.print("tmpSensorFlo: ");
  if (tmpSensorFlo == -127.00){
    Serial.print("ERROR READ TEMP");
  }else{
    Serial.print(tmpSensorFlo);
    Serial.println(" ºC");
    delay(200);
  }
  
  int tmpSensorInt = tmpSensorFlo*100;
    Serial.print("tmpSensorInt: ");
  if (tmpSensorFlo == -127.00){
    Serial.print("ERROR READ TEMP");
  }else{
    Serial.print(tmpSensorInt);
    Serial.println(" ºC");
    delay(200);
  }

  float tmpSenDirFlo = tmpSensorInt/100;
    Serial.print("tmpSenDirFlo: ");
  if (tmpSensorFlo == -127.00){
    Serial.print("ERROR READ TEMP");
  }else{
    Serial.print(tmpSenDirFlo);
    Serial.println(" ºC");
    delay(200);
  }
  
  float temperaturaSensor = tmpSensorInt;
  temperaturaSensor = temperaturaSensor/100;
  Serial.print("temperaturaSensor: ");
  if (tmpSensorFlo == -127.00){
    Serial.print("ERROR READ TEMP");
  }else{
    Serial.print(temperaturaSensor);
    Serial.println(" ºC");
    delay(200);
  }
  
  while(1);
}
