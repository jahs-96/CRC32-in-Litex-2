// This file is Copyright (c) 2020 Florent Kermarrec <florent@enjoy-digital.fr>
// License: BSD


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <irq.h>
#include <libbase/uart.h>
#include <libbase/console.h>
#include <generated/csr.h>

// Llamado de los encabezados propios

#include "crc32.h"

/*-----------------------------------------------------------------------*/
/* Uart                                                                  */
/*-----------------------------------------------------------------------*/

static char *readstr(void)
{
	char c[2];
	static char s[64];
	static int ptr = 0;

	if(readchar_nonblock()) {
		c[0] = getchar();
		c[1] = 0;
		switch(c[0]) {
			case 0x7f:
			case 0x08:
				if(ptr > 0) {
					ptr--;
					fputs("\x08 \x08", stdout);
				}
				break;
			case 0x07:
				break;
			case '\r':
			case '\n':
				s[ptr] = 0x00;
				fputs("\n", stdout);
				ptr = 0;
				return s;
			default:
				if(ptr >= (sizeof(s) - 1))
					break;
				fputs(c, stdout);
				s[ptr] = c[0];
				ptr++;
				break;
		}
	}

	return NULL;
}

static char *get_token(char **str)
{
	char *c, *d;

	c = (char *)strchr(*str, ' ');
	if(c == NULL) {
		d = *str;
		*str = *str+strlen(*str);
		return d;
	}
	*c = 0;
	d = *str;
	*str = c+1;
	return d;
}

static void prompt(void)
{
	printf("\e[92;1mproy1\e[0m> ");
}

/*-----------------------------------------------------------------------*/
/* Help                                                                  */
/*-----------------------------------------------------------------------*/

static void help(void)
{
	puts("\nLiteX minimal - Proyecto Corto 1 "__DATE__" "__TIME__"\n");
	puts("Available commands:");
	puts("help               - Show this command");
	puts("reboot             - Reboot CPU");
	puts("helloc             - Hello C");
	puts("add                - Adds two integer values");
	puts("CRC32		 - Calulate CRC32 for a 30 characters maximum string");
}

/*-----------------------------------------------------------------------*/
/* Commands                                                              */
/*-----------------------------------------------------------------------*/

static void reboot_cmd(void)
{
	ctrl_reset_write(1);
}

extern void helloc(void);

static void helloc_cmd(void)
{
	printf("Hello C demo...\n");
	helloc();
}

extern int add(int a, int b);
static void add_cmd(void)
{
	int a = 1;
	int b = 2;
	printf("Adding %d + %d is = %d \r\n", a, b, add(a,b));
}

// Llamado de la funcion CRC32 en el main
extern uint32_t crc32(const char *palabra);
static void crc32_cmd(void){
	char *frase;

	printf("Ingrese una frase de 30 caracteres maximo: \n");
	do {
        frase = readstr();
    } while(frase == NULL);

	char *mensaje;
	mensaje = frase;

    if (mensaje != NULL) {
		if (strlen(mensaje) <= 30) {
			uint32_t resultado = my_crc32(mensaje);
			printf("%08X\n", (unsigned int)resultado);
		} else {
			printf("Error en la longitud");
		}
	} else {
		printf("Error en la oracion");
	}
}

/*-----------------------------------------------------------------------*/
/* Console service / Main                                                */
/*-----------------------------------------------------------------------*/

static void console_service(void)
{
	char *str;
	char *token;

	str = readstr();
	if(str == NULL) return;
	token = get_token(&str);
	if(strcmp(token, "help") == 0)
		help();
	else if(strcmp(token, "reboot") == 0)
		reboot_cmd();
	else if(strcmp(token, "helloc") == 0)
		helloc_cmd();
	else if(strcmp(token, "add") == 0)
		add_cmd();
	// Establecimiento en la consola la opcion del CRC32
	else if(strcmp(token, "CRC32") == 0)
		crc32_cmd();
	prompt();
}

int main(void)
{
#ifdef CONFIG_CPU_HAS_INTERRUPT
	irq_setmask(0);
	irq_setie(1);
#endif
	uart_init();

	help();
	prompt();

	while(1) {
		console_service();
	}

	return 0;
}
