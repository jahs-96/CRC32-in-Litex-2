# Generación de CRC32 para textos de entrada

## Descripción
Este proyecto implementa un sistema para calcular el CRC32 de textos de entrada de hasta 30 caracteres. El cálculo del CRC32 se realiza utilizando un algoritmo implementado en lenguaje ensamblador para RV32I, ejecutado en un sistema en chip (SoC) creado con LiteX. El proyecto incluye tanto el código en C para la manipulación de datos como el ensamblador para el cálculo eficiente del CRC32.

## Estructura del Proyecto
El proyecto se encuentra en la carpeta `proy1` y contiene los siguientes archivos principales:

- **crc32.c**: Implementa la lógica para capturar y preparar los datos de entrada.
- **crc32.h**: Encabezado para las funciones definidas en `crc32.c`.
- **crc32_asm.S**: Implementación en ensamblador del algoritmo CRC32.
- **main.c**: Contiene la lógica principal del programa, incluyendo el menú de comandos y la integración de las funciones.
- **helloc.c**: Ejemplo de función en C que imprime un mensaje de prueba.
- **add.c**: Implementa una función para sumar dos números enteros.
- **Makefile**: Archivo de configuración para compilar el proyecto.
- **proy1.py**: Script de Python para compilar y preparar el binario ejecutable.

## Comandos Disponibles
El programa incluye un menú interactivo con los siguientes comandos:

- `help`: Muestra la lista de comandos disponibles.
- `reboot`: Reinicia la CPU.
- `helloc`: Ejecuta un ejemplo de "Hello, World!".
- `add`: Suma dos números enteros y muestra el resultado.
- `CRC32`: Calcula el CRC32 de una frase de entrada de hasta 30 caracteres.

## Cómo Ejecutar el Proyecto

### Requisitos Previos
1. Tener LiteX instalado en su sistema o en una máquina virtual.
2. Crear el SoC ejecutando el siguiente comando desde la raíz del proyecto:
   ```bash
   litex_sim --integrated-main-ram-size=0x10000 --cpu-type=vexriscv --no-compile-gateware
   ```

### Compilación del Código
1. Navegue a la carpeta `proy1`.
2. Ejecute el script de Python para compilar el proyecto:
   ```bash
   ./proy1.py --build-path=../build/sim
   ```

### Ejecución del Binario
1. Cargue el binario generado en el SoC con el siguiente comando:
   ```bash
   litex_sim --integrated-main-ram-size=0x10000 --cpu-type=vexriscv --ram-init=./proy1/proy1.bin
   ```
2. Interactúe con el menú de comandos para probar las funcionalidades.

## Casos de Prueba
Se recomienda probar el cálculo del CRC32 con las siguientes frases y validar los resultados con herramientas en línea como [Online CRC Calculator](https://emn178.github.io/online-tools/crc/):

- `Prueba`
- `Sistemas Digitales`
- `Este es texto de prueba`
- `abcdefghijklmnopqrstuvwxyz0123`
- `XYZ123`

## Créditos
Este proyecto fue desarrollado como parte del curso EL3310 - Diseño de Sistemas Digitales en el Tecnológico de Costa Rica. El código base fue adaptado y extendido por el equipo de trabajo para cumplir con los requisitos del proyecto.
