//--------------------------------------------------------------------------------
// Auto-generated by LiteX (88258bd34) on 2025-04-16 09:55:32
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// CSR Includes.
//--------------------------------------------------------------------------------

#include <generated/soc.h>
#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H
#include <stdint.h>
#include <system.h>
#ifndef CSR_ACCESSORS_DEFINED
#include <hw/common.h>
#endif /* ! CSR_ACCESSORS_DEFINED */

#ifndef CSR_BASE
#define CSR_BASE 0xf0000000L
#endif /* ! CSR_BASE */

//--------------------------------------------------------------------------------
// CSR Registers/Fields Definition.
//--------------------------------------------------------------------------------

/* CTRL Registers */
#define CSR_CTRL_BASE (CSR_BASE + 0x0L)
#define CSR_CTRL_RESET_ADDR (CSR_BASE + 0x0L)
#define CSR_CTRL_RESET_SIZE 1
#define CSR_CTRL_SCRATCH_ADDR (CSR_BASE + 0x4L)
#define CSR_CTRL_SCRATCH_SIZE 1
#define CSR_CTRL_BUS_ERRORS_ADDR (CSR_BASE + 0x8L)
#define CSR_CTRL_BUS_ERRORS_SIZE 1

/* CTRL Fields */
#define CSR_CTRL_RESET_SOC_RST_OFFSET 0
#define CSR_CTRL_RESET_SOC_RST_SIZE 1
#define CSR_CTRL_RESET_CPU_RST_OFFSET 1
#define CSR_CTRL_RESET_CPU_RST_SIZE 1

/* IDENTIFIER_MEM Registers */
#define CSR_IDENTIFIER_MEM_BASE (CSR_BASE + 0x800L)

/* IDENTIFIER_MEM Fields */

/* TIMER0 Registers */
#define CSR_TIMER0_BASE (CSR_BASE + 0x1000L)
#define CSR_TIMER0_LOAD_ADDR (CSR_BASE + 0x1000L)
#define CSR_TIMER0_LOAD_SIZE 1
#define CSR_TIMER0_RELOAD_ADDR (CSR_BASE + 0x1004L)
#define CSR_TIMER0_RELOAD_SIZE 1
#define CSR_TIMER0_EN_ADDR (CSR_BASE + 0x1008L)
#define CSR_TIMER0_EN_SIZE 1
#define CSR_TIMER0_UPDATE_VALUE_ADDR (CSR_BASE + 0x100cL)
#define CSR_TIMER0_UPDATE_VALUE_SIZE 1
#define CSR_TIMER0_VALUE_ADDR (CSR_BASE + 0x1010L)
#define CSR_TIMER0_VALUE_SIZE 1
#define CSR_TIMER0_EV_STATUS_ADDR (CSR_BASE + 0x1014L)
#define CSR_TIMER0_EV_STATUS_SIZE 1
#define CSR_TIMER0_EV_PENDING_ADDR (CSR_BASE + 0x1018L)
#define CSR_TIMER0_EV_PENDING_SIZE 1
#define CSR_TIMER0_EV_ENABLE_ADDR (CSR_BASE + 0x101cL)
#define CSR_TIMER0_EV_ENABLE_SIZE 1

/* TIMER0 Fields */
#define CSR_TIMER0_EV_STATUS_ZERO_OFFSET 0
#define CSR_TIMER0_EV_STATUS_ZERO_SIZE 1
#define CSR_TIMER0_EV_PENDING_ZERO_OFFSET 0
#define CSR_TIMER0_EV_PENDING_ZERO_SIZE 1
#define CSR_TIMER0_EV_ENABLE_ZERO_OFFSET 0
#define CSR_TIMER0_EV_ENABLE_ZERO_SIZE 1

/* UART Registers */
#define CSR_UART_BASE (CSR_BASE + 0x1800L)
#define CSR_UART_RXTX_ADDR (CSR_BASE + 0x1800L)
#define CSR_UART_RXTX_SIZE 1
#define CSR_UART_TXFULL_ADDR (CSR_BASE + 0x1804L)
#define CSR_UART_TXFULL_SIZE 1
#define CSR_UART_RXEMPTY_ADDR (CSR_BASE + 0x1808L)
#define CSR_UART_RXEMPTY_SIZE 1
#define CSR_UART_EV_STATUS_ADDR (CSR_BASE + 0x180cL)
#define CSR_UART_EV_STATUS_SIZE 1
#define CSR_UART_EV_PENDING_ADDR (CSR_BASE + 0x1810L)
#define CSR_UART_EV_PENDING_SIZE 1
#define CSR_UART_EV_ENABLE_ADDR (CSR_BASE + 0x1814L)
#define CSR_UART_EV_ENABLE_SIZE 1
#define CSR_UART_TXEMPTY_ADDR (CSR_BASE + 0x1818L)
#define CSR_UART_TXEMPTY_SIZE 1
#define CSR_UART_RXFULL_ADDR (CSR_BASE + 0x181cL)
#define CSR_UART_RXFULL_SIZE 1

/* UART Fields */
#define CSR_UART_EV_STATUS_TX_OFFSET 0
#define CSR_UART_EV_STATUS_TX_SIZE 1
#define CSR_UART_EV_STATUS_RX_OFFSET 1
#define CSR_UART_EV_STATUS_RX_SIZE 1
#define CSR_UART_EV_PENDING_TX_OFFSET 0
#define CSR_UART_EV_PENDING_TX_SIZE 1
#define CSR_UART_EV_PENDING_RX_OFFSET 1
#define CSR_UART_EV_PENDING_RX_SIZE 1
#define CSR_UART_EV_ENABLE_TX_OFFSET 0
#define CSR_UART_EV_ENABLE_TX_SIZE 1
#define CSR_UART_EV_ENABLE_RX_OFFSET 1
#define CSR_UART_EV_ENABLE_RX_SIZE 1

//--------------------------------------------------------------------------------
// CSR Registers Access Functions.
//--------------------------------------------------------------------------------

#ifndef LITEX_CSR_ACCESS_FUNCTIONS
#define LITEX_CSR_ACCESS_FUNCTIONS 1
#endif

#if LITEX_CSR_ACCESS_FUNCTIONS

/* CTRL Access Functions */
static inline uint32_t ctrl_reset_read(void) {
	return csr_read_simple((CSR_BASE + 0x0L));
}
static inline void ctrl_reset_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x0L));
}
static inline uint32_t ctrl_scratch_read(void) {
	return csr_read_simple((CSR_BASE + 0x4L));
}
static inline void ctrl_scratch_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x4L));
}
static inline uint32_t ctrl_bus_errors_read(void) {
	return csr_read_simple((CSR_BASE + 0x8L));
}

/* IDENTIFIER_MEM Access Functions */

/* TIMER0 Access Functions */
static inline uint32_t timer0_load_read(void) {
	return csr_read_simple((CSR_BASE + 0x1000L));
}
static inline void timer0_load_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x1000L));
}
static inline uint32_t timer0_reload_read(void) {
	return csr_read_simple((CSR_BASE + 0x1004L));
}
static inline void timer0_reload_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x1004L));
}
static inline uint32_t timer0_en_read(void) {
	return csr_read_simple((CSR_BASE + 0x1008L));
}
static inline void timer0_en_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x1008L));
}
static inline uint32_t timer0_update_value_read(void) {
	return csr_read_simple((CSR_BASE + 0x100cL));
}
static inline void timer0_update_value_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x100cL));
}
static inline uint32_t timer0_value_read(void) {
	return csr_read_simple((CSR_BASE + 0x1010L));
}
static inline uint32_t timer0_ev_status_read(void) {
	return csr_read_simple((CSR_BASE + 0x1014L));
}
static inline uint32_t timer0_ev_pending_read(void) {
	return csr_read_simple((CSR_BASE + 0x1018L));
}
static inline void timer0_ev_pending_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x1018L));
}
static inline uint32_t timer0_ev_enable_read(void) {
	return csr_read_simple((CSR_BASE + 0x101cL));
}
static inline void timer0_ev_enable_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x101cL));
}

/* UART Access Functions */
static inline uint32_t uart_rxtx_read(void) {
	return csr_read_simple((CSR_BASE + 0x1800L));
}
static inline void uart_rxtx_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x1800L));
}
static inline uint32_t uart_txfull_read(void) {
	return csr_read_simple((CSR_BASE + 0x1804L));
}
static inline uint32_t uart_rxempty_read(void) {
	return csr_read_simple((CSR_BASE + 0x1808L));
}
static inline uint32_t uart_ev_status_read(void) {
	return csr_read_simple((CSR_BASE + 0x180cL));
}
static inline uint32_t uart_ev_pending_read(void) {
	return csr_read_simple((CSR_BASE + 0x1810L));
}
static inline void uart_ev_pending_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x1810L));
}
static inline uint32_t uart_ev_enable_read(void) {
	return csr_read_simple((CSR_BASE + 0x1814L));
}
static inline void uart_ev_enable_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x1814L));
}
static inline uint32_t uart_txempty_read(void) {
	return csr_read_simple((CSR_BASE + 0x1818L));
}
static inline uint32_t uart_rxfull_read(void) {
	return csr_read_simple((CSR_BASE + 0x181cL));
}
#endif /* LITEX_CSR_ACCESS_FUNCTIONS */

#endif /* ! __GENERATED_CSR_H */
