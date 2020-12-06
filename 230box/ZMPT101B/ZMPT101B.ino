 /*
 * Para calibrar, usar corriente
 * la media debe ser 512.
 * 
 * Hacemos lectura con voltímetro,
 * el valor lo ingresamos como realVal.
 * 
 * El valor que nos da en ese momento
 * maxVal lo ingresamos como maxCalib.
 * 
 * Es posible que permanezca con
 * un maxValue estático, bajar el valor
 * hasta que el valor fluctúe.
 * 
 * Consejo: Si no tienes fuente variable VDC
 * realizar test a partir del atardecer,
 * suele haber cauídas de tensión.
 *
 * Developer c2mismo 2019.
 * License GNU, see at the end.
 */

static const int sensor = A9;

int waves = 10; // Numeros de ondas para leer
int freq = 20;      // 50 Hz = 20 m/s; 60 Hz = 16.6667 m/s
int t = waves * freq;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int maxVal = 512; // Valores iniciales
  int minVal = 512;
  int average;

  int tMax = millis();
  tMax = tMax + t;

  for (int tAct = millis(); tMax > tAct; tAct = millis())
  {
    int s = analogRead(sensor);
    if (s > maxVal) maxVal = s;
    if (s < minVal) minVal = s;
  }
  average = (maxVal - minVal)/2 + minVal;

  Serial.print(" maxValue : "); Serial.println(maxVal);
  Serial.print(" average  : "); Serial.println(average);
  //Serial.print(" minValue : "); Serial.println(minVal);
  //Serial.println();Serial.println("------------------------------------------------");Serial.println();

  const int realVal = 224; // Lectura con voltimetro
  const int maxCalib = 757; // maxVal en el instante de la lextura

  int value = map(maxVal, average, maxCalib, 0, realVal);
  Serial.print(" Value    : "); Serial.println(value);
  Serial.println();Serial.println("************************************************");
  Serial.println();Serial.println("************************************************");Serial.println();

  delay(1000);
}
/*
  License:

    Copyright (C) 2019  c2mismo.

    This file is part of 230box.

    230box is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This 230box is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this 230box, see COPYING.  If not, see <https://www.gnu.org/licenses/>.

    You can download a full copy of 230box at <https://github.com/c2mismo>.
 */
