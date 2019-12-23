/*
Sketch para comprobar los sensores
DS18B20 arreglado por c2mismo enero 2019

en el LCD imprimira:

Primera linea:
Numero de sensores encontrados
y temperatura en Centigrados

Segunda linea:
Numero unico identificativo del sensor

Notas:
Solo debe haber un sensor conectado.
Debe haber una resistencia de 4K7 entre 
los +5V (rojo) y la senal (amarillo). (El negro a GND)
Antes de compilar abra un aviso (error) "use of undeclared identifier discoverOneWireDevices",
es solo un aviso todo funciona bien.


0x28, 0xAA, 0xE0, 0x2A, 0x1B, 0x13, 0x02, 0xB2

*/

///////////////////////
//  LIBRARY CONF     //
///////////////////////

#include <OneWire.h>
#include <DallasTemperature.h>

const int pinOneWire = 2;

OneWire oneWire (pinOneWire);
DallasTemperature DS18B20 (&oneWire);

///////////////////////
// FIN LIBRARY CONF  //
///////////////////////


void setup(void) {
  Serial.begin(9600);
  DS18B20.begin();
  discoverOneWireDevices();
}
 
void discoverOneWireDevices(void) {
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];
  

  
  Serial.println("Buscando dispositivos 1-Wire");
  Serial.println();
  // Mostramos numero de sensores detectados
  Serial.print(DS18B20.getDeviceCount());
  Serial.println(" Sensores conectados");
  Serial.println();
  
  while(oneWire.search(addr)) {
    Serial.println("Encontrado dispositivo 1-Wire en la direccion:");
    for( i = 0; i < 8; i++) {
      // Imprimiendo la direccion unica en puerto serie
      Serial.print("0x");
      if (addr[i] < 16) {
        Serial.print('0');
      }
      Serial.print(addr[i], HEX);
      if (i < 7) {
        Serial.print(", ");
      } else {
        Serial.println();
      }

    }
    Serial.println();
    if ( OneWire::crc8( addr, 7) != addr[7]) {
        Serial.println("Error en dispositivo, CRC invalido!");
        delay(10000);
        return;
    }
  }
  oneWire.reset_search();
  Serial.println("Búsqueda finalizada");
  Serial.println();
  
  return;
}
 
void loop(void) 
{
  int i;
  int numSensor=DS18B20.getDeviceCount();
    for( i = 0; i < numSensor; i++)
    {
      // Mandamos comandos para toma de temperatura a los sensores
      DS18B20.requestTemperatures();
      
      // Mostramos los datos de los sensores DS18B20 (sin direccion conocida)
      if (DS18B20.getTempCByIndex(i) == -127.00)
      {
        Serial.println("ERROR READ");
      } else {
        int j = i+1;
        Serial.print("Datos del sensor ");
        Serial.print(j);
        Serial.print("      ");
        Serial.print(DS18B20.getTempCByIndex(i)); // Cambiar 0 por 1 si tienes otro sensor
        Serial.println(" C");
        delay(200);
      }
    }
  
  
  
  
  
}
