# 230box

Proyecto para automatizar una caja de electricidad de 230 voltios de una autocaravana con arduino.

## Definicion de la caja

La caja dispone de:

### 3 Entradas de corriente.

Una proviene del inversor el cual és activado solo bajo demanda através del arduino, para ello dispone de su driver correspondiente instalado en el inversor.

Las otras dos son similares pero independientes cada una dispuesta hacia el exterior a sendos laterales. Estos pueden tanto adquirir como ofrecer 230V indiferentemente.

### 4 Salidas de corriente.

Las dos tomas exteriores, que como dijimos pueden tanto adquirir como ofrecer 230V indiferentemente.

La alimentación de la vivienda.

El cargador de baterías de 230V. Este solo puede ser activado cuando la alimentación de 230V no provenga del inversor.

## Todas las salidas estan devidamente protegidas:

### De forma pasiva

* Dispone de Protección de armónicos (Filtro EMI).

* Protección Sobretensión Transitoria.

* Protección Sobretensión Permanente.

* Diferencial.

* Magnetotérmico.

### De forma activa (através del arduino)

* Protección de sobretensión y bajotensión de la batería.

* Protección de sobrecorriente.

* Control y monotorización de su actividad y consumo.

* Control y reducción de la temperatura con dos ventiladores extractores.


## Dispone de botones para la realización de maniobras manuales.

Estas solo activan/desactivan el arduino y los relés.

## Los relés

Al disponer de un tamaño muy reducido y necesitar cinco relés, no se han encontrado ninguno bipolar que se ajuste a las medidas, por ello dispone de diez relés sólidos que quedan conectados para que actúen de forma paralela por circuito.

## Comunicación

La comunicación se realiza através de un módulo SPI to CANbus. Esto mantiene todos los arduinos con la Raspberry conectados entre sí, por el mismo cable ethernet Cat7.

4 Pares:

* 1 par cruzado para CANbus.

* 2 pares para alimentación 12V.

* 1 par auxiliar.


## Recursos para el autómata

* Arduino Mega.

* Amperímetro WCS1800 con un amplificador MCP602.

* 3 Voltímetros ZMPT101B con un amplificador LM358.

* Sensores de temperatura DS18B20 1-wire.

* Módulo SPI to CANbus MCP2515.

* Micro botonera de seis botones.

* Una placa artesanal con cuatro drivers (en su momento se subirá el esquema).

* 12VDC to 5VDC


## Licencia


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
