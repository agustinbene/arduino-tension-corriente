![](Fuente.001.png)
# Proyecto Integrador

## Diseño y construcción de una fuente de alimentación

####Integrantes: 

- Benegas, Agustín
- Grageda, Gonzalo 
- Gonzalez Conosciuto, Guillermo A. 


**Tabla de contenido** 

## Objetivos 

Diseñar y construir una fuente regulable de corriente continua en función del alcance y los lineamientos establecidos por la cátedra. Se propone que la fuente funcione a 700mA entre 5V - 25V. 

## Análisis  

Para conseguir los lineamientos establecidos por la cátedra consideramos como base del circuito principal el integrado LM317, el mismo se utilizó para obtener la salida de tensión variable. Con el fin de conseguir los valores de las resistencias del circuito del integrado necesarias para obtener un máximo de 30V aproximadamente en la salida de la fuente se realizó el siguiente cálculo: 

```math
V_{out} = 1.25*(1+\frac{R_2}{R_1})
```

Dónde: 

* V_out es la tensión de salida del circuito del integrado. 
* R2 es la resistencia máxima del potenciómetro utilizado 
* R1 es la resistencia fija del circuito que se pretende calcular.

Para calcular la resistencia R1 se realiza el siguiente despeje: 

```math
R_1 = R_2*\frac{1.25}{V_{out}+1.25}
```

Queriendo conseguir los 30V aproximadamente, y con el potenciómetro de resistencia máxima 10KΩ, se obtuvo una resistencia fija de 434Ω. 

Por otro lado, se observó la hoja de datos del dispositivo mencionado y se halló allí la corriente máxima que soportaba. Se verificó así que podía tenerse 700mA de corriente en la salida del aparato. 

Para el circuito rectificador se utilizó lo aprendido. Se partió de las características del transformador para tener en cuenta los niveles de tensión que se podía llegar a manejar, la medición del bobinado principal era de 24v C.A. por consiguiente luego de la etapa de rectificación se obtendrían 33.94V D.C, también se contó con un bobinado con salida de 9v A.C. que, rectificado, se obtuvo 12.72V D.C.  

Para lograr que el dispositivo Arduino tomara las medidas de tensión de salida se tuvo en cuenta que el mismo no resiste tensiones mayores a 5V. Por esta razón se creo un divisor de tensión. El cálculo de la caída de tensión en la resistencia más chica del divisor se obtuvo mediante el siguiente cálculo: 

```math
369uA= \frac{30v}{78k + 3.3k}
```

Obtenida la corriente máxima que atraviesa por el divisor de tensión, se calcula diferencia de potencial entre las terminales de la resistencia de 3,3K. 

```math
369uA*3.3k=1.21V
```

De esta forma se protege el microcontrolador y se obtiene mayor precisión en la “lectura” de tensiones. 

Por cuestiones sobrecalentamiento de los dispositivos, especialmente el integrado LM317, se propuso el uso de un Fan-Cooler a modo de refrigeración activa de forma hiperbárica. Así, se realiza un esfuerzo para que ingrese aire frío dentro, por lo que la presión aumenta, y esto provoca que el aire caliente salga de manera pasiva para nivelar la presión con la atmosférica. La expresión hiperbárico se relaciona con presiones más altas que la atmosférica. 

También se consideró un disipador de calor para el integrado. 

Diseño 

Teniendo en cuenta las consideraciones anteriores se diseñó el siguiente circuito: 

![](Fuente.002.png)
El circuito consta de dos partes. En la entrada de 220V a 50Hz se utiliza un transformador con dos bobinados de salida los cuales dividen en dos el circuito general. 

Por un lado, se tiene la salida del transformador (T1) de 24 V. Esta parte contiene el circuito rectificador con el regulador de tensión. Consta de un puente de diodos conectados en paralelo con un filtro capacitivo, seguido del circuito regulador con el integrado (LM317). 

En la segunda parte, la salida del transformador (T2) de 9V se utiliza para alimentar el circuito del Arduino, junto a otro circuito rectificador similar al anterior. El Arduino internamente ya posee un regulador de tensión por lo que no fue necesario agregarlo. Con esta tensión ya se pudo lograr alimentar este circuito. 

Supongamos dividir nuevamente el circuito para proceder a la explicación de la tarea del Arduino en la fuente creada. Al ser un microcontrolador programable se pudo utilizar para agregar “gadgets” a la fuente de corriente continua. Su función principal era la de “leer” la tensión de salida y devolver los valores tomados al usuario mediante una pantalla LCD. También se agregó la opción de conectarse a la fuente mediante tecnología bluetooth, y que el usuario pueda leer los valores en su dispositivo móvil. Los dispositivos Display y Bluetooth se controlan mediante código conectándolos al Arduino, el cual se encuentra programado. 


Una vez diseñado esto procedimos a la construcción de la fuente. 

## Construcción 

Instrumentación utilizada 

- Pinza punta plana 
- Alicate 
- Soldador 
- Estaño 
- Soporte para soldadura 
- Destornilladores varios 
- Dremel 
- Taladro eléctrico 
- Muktímetros digitales 
- Osciloscopios 

### Elementos del circuito 

- Placa de experimentación perforada. 
- Caja reglamentaria. 
- Cable de alimentación 
- Transformador 220 – 9V+24V 
- Puente de diodos MB6S 
- Puente de diodos KBP206 
- Capacitor electrolítico 2000
- Capacitor electrolítico 1000 F 
- Capacitor electrolítico 1
- Potenciómetro 10KΩ 
- Potenciómetro 2,2KΩ 
- Resistencias 
- 0,26Ω 
- 3,3KΩ 
- 78KΩ 
- 440Ω 
- Ficha banana 
- 2 Switches 
- Fan – Cooler 
- Arduino nano©(ATMega328) 
- LCD I2C16x2 (Display) 
- Arduino© Módulo Bluetooth HC-06 
- Disipador 

### Procedimiento 

En una primera instancia se comprobó el funcionamiento del circuito montándolo en un protoboard. Una vez realizado esto se comenzó a ensamblar en la placa experimental perforada. Los componentes fueron soldados a la misma siguiendo el diseño.  

Una vez integrado el circuito sobre la placa se procedió a montar el mismo en la caja reglamentaria. Tanto la placa que contiene el circuito rectificador, como el microcontrolador, el display, el módulo bluetooth, y el fan-cooler fueron fijados a la caja mediante el uso de tornillos. 

La caja se modificó para la colocación de el interruptor encendido/apagado de la fuente y las salidas de tensión con las fichas banana. 

A continuación, se muestra la fuente en su versión final: 

![](Fuente.003.png)

Ensayo y puesta en marcha 

Antes de realizar comprobaciones con carga, se realizó un ensayo de las partes de la fuente a modo de verificación. 

Con la caja abierta, se comenzó el ensayo analizando que no exista continuidad en los bornes de salida para evitar el cortocircuito. Luego, se midió la tensión de salida en el transformador, ésta se comprobó correcta, ya que se obtuvieron valores similares a los calculados. Se prosiguió midiendo la tensión de salida (para distintos niveles de tensión), y comparando con los que aparecían en pantalla, con el fin de determinar el funcionamiento del módulo Arduino, y corroborando el código. Una vez hecho esto se siguió el ensayo midiendo con el osciloscopio, y se verificó que la corriente de salida era continua. Para finalizar se conectó una carga de prueba (motor chico), y se probó la fuente. 

Todos los componentes anduvieron durante el ensayo, siempre exponiéndolos a la máxima capacidad de la fuente, sin dañarse, habiendo conseguido resultados satisfactorios durante las pruebas se cerró la caja y se preparó para la entrega. 

A continuación, se muestra la medición de corriente de salida con el osciloscopio. 

![](Fuente.004.png)

Conclusión 

Durante el procedimiento de construcción no surgieron inconvenientes grandes. Existió un percance al quemarse un dispositivo Arduino, pero fue reemplazado.  

Se cree necesario aclarar que el agregado de componentes extra a la fuente provoca una leve decaída de precisión, ya que suma ruido a la señal de salida. 

Los resultados, sin embargo, fueron satisfactorios y se cree que se pudo abarcar con los requerimientos. 

Bibliografía 

* Apuntes de clase. 

* “Gabinetes: Refrigeración y Ventilación” – Puede hallarse en el siguiente link: [https://formadortionline.blogspot.com/2016/04/gabinetes-refrigeracion-y-ventilacion.html ](https://formadortionline.blogspot.com/2016/04/gabinetes-refrigeracion-y-ventilacion.html)
 
