    .section .text
    .globl my_crc32_asm
my_crc32_asm:
    # Entradas:
    #   a0 → puntero a datos
    #   a1 → longitud en bytes
    # Salida:
    #   a0 → CRC32 calculado

    # Inicializa el acumulador CRC a 0xFFFFFFFF
    addi    t0, x0, -1           # t0 = CRC

    # Copia parámetros
    addi    t1, a0, 0            # t1 = ptr a datos
    addi    t2, a1, 0            # t2 = longitud

    # Cargar el polinomio reflejado 0xEDB88320
    lui     t6, 0xEDB88
    addi    t6, t6, 0x320

byte_loop:
    beq     t2, x0, finalize     # Si longitud = 0 → terminar

    lbu     t3, 0(t1)            # cargar siguiente byte
    xor     t0, t0, t3           # mezclar byte con CRC

    addi    t4, x0, 8            # contador de bits = 8
bit_loop:
    andi    t5, t0, 1            # extraer LSB
    srli    t0, t0, 1            # CRC >>= 1
    beq     t5, x0, skip_xor     # si LSB = 0 → saltar
    xor     t0, t0, t6           # CRC ^= polinomio
skip_xor:
    addi    t4, t4, -1
    bnez    t4, bit_loop

    addi    t1, t1, 1            # avanzar al siguiente byte
    addi    t2, t2, -1
    jal     x0, byte_loop

finalize:
    addi    t5, x0, -1           # t5 = 0xFFFFFFFF
    xor     t0, t0, t5           # invertir bits del CRC final
    addi    a0, t0, 0            # devolver en a0
    jalr    x0, 0(ra)            # return
