begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Lev Serebryakov<lev@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UMCS7840_H_
end_ifndef

begin_define
define|#
directive|define
name|_UMCS7840_H_
end_define

begin_define
define|#
directive|define
name|UMCS7840_MAX_PORTS
value|4
end_define

begin_define
define|#
directive|define
name|UMCS7840_READ_LENGTH
value|1
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|UMCS7840_CTRL_TIMEOUT
value|500
end_define

begin_comment
comment|/* ms */
end_comment

begin_comment
comment|/* Read/Wrtire registers vendor commands */
end_comment

begin_define
define|#
directive|define
name|MCS7840_RDREQ
value|0x0d
end_define

begin_define
define|#
directive|define
name|MCS7840_WRREQ
value|0x0e
end_define

begin_comment
comment|/* Read/Wrtie EEPROM values */
end_comment

begin_define
define|#
directive|define
name|MCS7840_EEPROM_RW_WVALUE
value|0x0900
end_define

begin_comment
comment|/*  *   All these registers are documented only in full datasheet,  * which can be requested from MosChip tech support.  */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP1
value|0x00
end_define

begin_comment
comment|/* Options for for UART 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_CONTROL1
value|0x01
end_define

begin_comment
comment|/* Control bits for UART 1, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_PINPONGHIGH
value|0x02
end_define

begin_comment
comment|/* High bits of ping-pong 						 * register, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_PINPONGLOW
value|0x03
end_define

begin_comment
comment|/* Low bits of ping-pong 						 * register, R/W */
end_comment

begin_comment
comment|/* DCRx_1 Registers goes here (see below, they are documented) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_GPIO
value|0x07
end_define

begin_comment
comment|/* GPIO_0 and GPIO_1 bits, 						 * undocumented, see notes 						 * below R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP2
value|0x08
end_define

begin_comment
comment|/* Options for for UART 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_CONTROL2
value|0x09
end_define

begin_comment
comment|/* Control bits for UART 2, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP3
value|0x0a
end_define

begin_comment
comment|/* Options for for UART 3, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_CONTROL3
value|0x0b
end_define

begin_comment
comment|/* Control bits for UART 3, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP4
value|0x0c
end_define

begin_comment
comment|/* Options for for UART 4, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_CONTROL4
value|0x0d
end_define

begin_comment
comment|/* Control bits for UART 4, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_PLL_DIV_M
value|0x0e
end_define

begin_comment
comment|/* Pre-diviedr for PLL, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN1
value|0x0f
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_PLL_DIV_N
value|0x10
end_define

begin_comment
comment|/* Loop divider for PLL, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_CLOCK_MUX
value|0x12
end_define

begin_comment
comment|/* PLL input clock& Interrupt 						 * endpoint control, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN2
value|0x11
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_CLOCK_SELECT12
value|0x13
end_define

begin_comment
comment|/* Clock source for ports 1& 						 * 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_CLOCK_SELECT34
value|0x14
end_define

begin_comment
comment|/* Clock source for ports 3& 						 * 4, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN3
value|0x15
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_comment
comment|/* DCRx_2-DCRx_4 Registers goes here (see below, they are documented) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN4
value|0x1f
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN5
value|0x20
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN6
value|0x21
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN7
value|0x22
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN8
value|0x23
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWN9
value|0x24
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWNA
value|0x25
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWNB
value|0x26
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWNC
value|0x27
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWND
value|0x28
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWNE
value|0x29
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_UNKNOWNF
value|0x2a
end_define

begin_comment
comment|/* NOT MENTIONED AND NOT USED */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_MODE
value|0x2b
end_define

begin_comment
comment|/* Hardware configuration, 						 * R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP1_ICG
value|0x2c
end_define

begin_comment
comment|/* Inter character gap 						 * configuration for Port 1, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP2_ICG
value|0x2d
end_define

begin_comment
comment|/* Inter character gap 						 * configuration for Port 2, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP3_ICG
value|0x2e
end_define

begin_comment
comment|/* Inter character gap 						 * configuration for Port 3, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_SP4_ICG
value|0x2f
end_define

begin_comment
comment|/* Inter character gap 						 * configuration for Port 4, 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_RX_SAMPLING12
value|0x30
end_define

begin_comment
comment|/* RX sampling for ports 1& 						 * 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_RX_SAMPLING34
value|0x31
end_define

begin_comment
comment|/* RX sampling for ports 3& 						 * 4, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BI_FIFO_STAT1
value|0x32
end_define

begin_comment
comment|/* Bulk-In FIFO Stat for Port 						 * 1, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BO_FIFO_STAT1
value|0x33
end_define

begin_comment
comment|/* Bulk-out FIFO Stat for Port 						 * 1, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BI_FIFO_STAT2
value|0x34
end_define

begin_comment
comment|/* Bulk-In FIFO Stat for Port 						 * 2, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BO_FIFO_STAT2
value|0x35
end_define

begin_comment
comment|/* Bulk-out FIFO Stat for Port 						 * 2, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BI_FIFO_STAT3
value|0x36
end_define

begin_comment
comment|/* Bulk-In FIFO Stat for Port 						 * 3, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BO_FIFO_STAT3
value|0x37
end_define

begin_comment
comment|/* Bulk-out FIFO Stat for Port 						 * 3, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BI_FIFO_STAT4
value|0x38
end_define

begin_comment
comment|/* Bulk-In FIFO Stat for Port 						 * 4, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_BO_FIFO_STAT4
value|0x39
end_define

begin_comment
comment|/* Bulk-out FIFO Stat for Port 						 * 4, contains number of 						 * availiable bytes, R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_ZERO_PERIOD1
value|0x3a
end_define

begin_comment
comment|/* Period between zero out 						 * frames for Port 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_ZERO_PERIOD2
value|0x3b
end_define

begin_comment
comment|/* Period between zero out 						 * frames for Port 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_ZERO_PERIOD3
value|0x3c
end_define

begin_comment
comment|/* Period between zero out 						 * frames for Port 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_ZERO_PERIOD4
value|0x3d
end_define

begin_comment
comment|/* Period between zero out 						 * frames for Port 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_ZERO_ENABLE
value|0x3e
end_define

begin_comment
comment|/* Enable/disable of zero out 						 * frames, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_LOW1
value|0x3f
end_define

begin_comment
comment|/* Low 8 bits of threshhold 						 * value for Bulk-Out for Port 						 * 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_HIGH1
value|0x40
end_define

begin_comment
comment|/* High 1 bit of threshhold 						 * value for Bulk-Out and 						 * enable flag for Port 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_LOW2
value|0x41
end_define

begin_comment
comment|/* Low 8 bits of threshhold 						 * value for Bulk-Out for Port 						 * 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_HIGH2
value|0x42
end_define

begin_comment
comment|/* High 1 bit of threshhold 						 * value for Bulk-Out and 						 * enable flag for Port 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_LOW3
value|0x43
end_define

begin_comment
comment|/* Low 8 bits of threshhold 						 * value for Bulk-Out for Port 						 * 3, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_HIGH3
value|0x44
end_define

begin_comment
comment|/* High 1 bit of threshhold 						 * value for Bulk-Out and 						 * enable flag for Port 3, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_LOW4
value|0x45
end_define

begin_comment
comment|/* Low 8 bits of threshhold 						 * value for Bulk-Out for Port 						 * 4, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_THR_VAL_HIGH4
value|0x46
end_define

begin_comment
comment|/* High 1 bit of threshhold 						 * value for Bulk-Out and 						 * enable flag for Port 4, R/W */
end_comment

begin_comment
comment|/* Bits for SPx registers */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_LOOP_PIPES
value|0x01
end_define

begin_comment
comment|/* Loop Bulk-Out FIFO to the 						 * Bulk-In FIFO, default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_SKIP_ERR_DATA
value|0x02
end_define

begin_comment
comment|/* Drop data bytes from UART, 						 * which were recevied with 						 * errors, default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_RESET_OUT_FIFO
value|0x04
end_define

begin_comment
comment|/* Reset Bulk-Out FIFO */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_RESET_IN_FIFO
value|0x08
end_define

begin_comment
comment|/* Reset Bulk-In FIFO */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_MASK
value|0x70
end_define

begin_comment
comment|/* Mask to extract Baud CLK 						 * source */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_X1
value|0x00
end_define

begin_comment
comment|/* CLK =  1.8432Mhz, max speed 						 * = 115200 bps, default */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_X2
value|0x10
end_define

begin_comment
comment|/* CLK =  3.6864Mhz, max speed 						 * = 230400 bps */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_X35
value|0x20
end_define

begin_comment
comment|/* CLK =  6.4512Mhz, max speed 						 * = 403200 bps */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_X4
value|0x30
end_define

begin_comment
comment|/* CLK =  7.3728Mhz, max speed 						 * = 460800 bps */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_X7
value|0x40
end_define

begin_comment
comment|/* CLK = 12.9024Mhz, max speed 						 * = 806400 bps */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_X8
value|0x50
end_define

begin_comment
comment|/* CLK = 14.7456Mhz, max speed 						 * = 921600 bps */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_24MHZ
value|0x60
end_define

begin_comment
comment|/* CLK = 24.0000Mhz, max speed 						 * = 1.5 Mbps */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_48MHZ
value|0x70
end_define

begin_comment
comment|/* CLK = 48.0000Mhz, max speed 						 * = 3.0 Mbps */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_CLOCK_SHIFT
value|4
end_define

begin_comment
comment|/* Value 0..7 can be shifted 						 * to get clock value */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_UART_RESET
value|0x80
end_define

begin_comment
comment|/* Reset UART */
end_comment

begin_comment
comment|/* Bits for CONTROLx registers */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_HWFC
value|0x01
end_define

begin_comment
comment|/* Enable hardware flow 							 * control (when power 							 * down? It is unclear 							 * in documents), 							 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_UNUNSED1
value|0x02
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_CTS_ENABLE
value|0x04
end_define

begin_comment
comment|/* CTS changes are 							 * translated to MSR, 							 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_UNUSED2
value|0x08
end_define

begin_comment
comment|/* Reserved for ports 							 * 2,3,4 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROL1_DRIVER_DONE
value|0x08
end_define

begin_comment
comment|/* USB enumerating is 							 * finished, USB 							 * enumeration memory 							 * can be used as FIFOs */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_RX_NEGATE
value|0x10
end_define

begin_comment
comment|/* Negate RX input, 							 * works for IrDA mode 							 * only, default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_RX_DISABLE
value|0x20
end_define

begin_comment
comment|/* Disable RX logic, 							 * works only for 							 * RS-232/RS-485 mode, 							 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_FSM_CONTROL
value|0x40
end_define

begin_comment
comment|/* Disable RX FSM when 							 * TX is in progress, 							 * works for IrDA mode 							 * only, default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CONTROLx_UNUSED3
value|0x80
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/*  * Bits for PINPONGx registers  * These registers control how often two input buffers  * for Bulk-In FIFOs are swapped. One of buffers is used  * for USB trnasfer, other for receiving data from UART.  * Exact meaning of 15 bit value in these registers is unknown  */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PINPONGHIGH_MULT
value|128
end_define

begin_comment
comment|/* Only 7 bits in PINPONGLOW 						 * register */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PINPONGLOW_BITS
value|7
end_define

begin_comment
comment|/* Only 7 bits in PINPONGLOW 						 * register */
end_comment

begin_comment
comment|/*  *  THIS ONE IS UNDOCUMENTED IN FULL DATASHEET, but e-mail from tech support  * confirms, that it is register for GPIO_0 and GPIO_1 data input/output.  *  Chips has 2 GPIO, but first one (lower bit) MUST be used by device  * authors as "number of port" indicator, grounded (0) for two-port  * devices and pulled-up to 1 for 4-port devices.  */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_GPIO_4PORTS
value|0x01
end_define

begin_comment
comment|/* Device has 4 ports 						 * configured */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_GPIO_GPIO_0
value|0x01
end_define

begin_comment
comment|/* The same as above */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_GPIO_GPIO_1
value|0x02
end_define

begin_comment
comment|/* GPIO_1 data */
end_comment

begin_comment
comment|/*  * Constants for PLL dividers  * Ouptut frequency of PLL is:  *   Fout = (N/M) * Fin.  * Default PLL input frequency Fin is 12Mhz (on-chip).  */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_M_BITS
value|6
end_define

begin_comment
comment|/* Number of useful bits for M 						 * divider */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_M_MASK
value|0x3f
end_define

begin_comment
comment|/* Mask for M divider */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_M_MIN
value|1
end_define

begin_comment
comment|/* Minimum value for M, 0 is 						 * forbidden */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_M_DEF
value|1
end_define

begin_comment
comment|/* Default value for M */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_M_MAX
value|63
end_define

begin_comment
comment|/* Maximum value for M */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_N_BITS
value|6
end_define

begin_comment
comment|/* Number of useful bits for N 						 * divider */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_N_MASK
value|0x3f
end_define

begin_comment
comment|/* Mask for N divider */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_N_MIN
value|1
end_define

begin_comment
comment|/* Minimum value for N, 0 is 						 * forbidden */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_N_DEF
value|8
end_define

begin_comment
comment|/* Default value for N */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_PLL_DIV_N_MAX
value|63
end_define

begin_comment
comment|/* Maximum value for N */
end_comment

begin_comment
comment|/* Bits for CLOCK_MUX register */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_INPUTMASK
value|0x03
end_define

begin_comment
comment|/* Mask to extract PLL clock 						 * input */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_IN12MHZ
value|0x00
end_define

begin_comment
comment|/* 12Mhz PLL input, default */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_INEXTRN
value|0x01
end_define

begin_comment
comment|/* External (device-depended) 						 * PLL input */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_INRSV1
value|0x02
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_INRSV2
value|0x03
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_PLLHIGH
value|0x04
end_define

begin_comment
comment|/* 0 = PLL Output is 						 * 20MHz-100MHz (default), 1 = 						 * 100MHz-300MHz range */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_INTRFIFOS
value|0x08
end_define

begin_comment
comment|/* Enable additional 8 bytes 						 * fro Interrupt USB pipe with 						 * USB FIFOs statuses, default 						 * = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_RESERVED1
value|0x10
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_RESERVED2
value|0x20
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_RESERVED3
value|0x40
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_MUX_RESERVED4
value|0x80
end_define

begin_comment
comment|/* Unused */
end_comment

begin_comment
comment|/* Bits for CLOCK_SELECTxx registers	*/
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT1_MASK
value|0x07
end_define

begin_comment
comment|/* Bits for port 1 in 						 * CLOCK_SELECT12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT1_SHIFT
value|0
end_define

begin_comment
comment|/* Shift for port 1in 						 * CLOCK_SELECT12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT2_MASK
value|0x38
end_define

begin_comment
comment|/* Bits for port 2 in 						 * CLOCK_SELECT12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT2_SHIFT
value|3
end_define

begin_comment
comment|/* Shift for port 2 in 						 * CLOCK_SELECT12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT3_MASK
value|0x07
end_define

begin_comment
comment|/* Bits for port 3 in 						 * CLOCK_SELECT23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT3_SHIFT
value|0
end_define

begin_comment
comment|/* Shift for port 3 in 						 * CLOCK_SELECT23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT4_MASK
value|0x38
end_define

begin_comment
comment|/* Bits for port 4 in 						 * CLOCK_SELECT23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT4_SHIFT
value|3
end_define

begin_comment
comment|/* Shift for port 4 in 						 * CLOCK_SELECT23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_STD
value|0x00
end_define

begin_comment
comment|/* STANDARD baudrate derived 						 * from 96Mhz, default for all 						 * ports */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_30MHZ
value|0x01
end_define

begin_comment
comment|/* 30Mhz */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_96MHZ
value|0x02
end_define

begin_comment
comment|/* 96Mhz direct */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_120MHZ
value|0x03
end_define

begin_comment
comment|/* 120Mhz */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_PLL
value|0x04
end_define

begin_comment
comment|/* PLL output (see for M and N 						 * dividers) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_EXT
value|0x05
end_define

begin_comment
comment|/* External clock input 						 * (device-dependend) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_RES1
value|0x06
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_CLOCK_SELECT_RES2
value|0x07
end_define

begin_comment
comment|/* Unused */
end_comment

begin_comment
comment|/* Bits for MODE register */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_RESERVED1
value|0x01
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_RESET
value|0x02
end_define

begin_comment
comment|/* 0: RESET = Active High 						 * (default), 1: Reserved (?) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_SER_PRSNT
value|0x04
end_define

begin_comment
comment|/* 0: Reserved, 1: Do not use 						 * hardocded values (default) 						 * (?) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_PLLBYPASS
value|0x08
end_define

begin_comment
comment|/* 1: PLL output is bypassed, 						 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_PORBYPASS
value|0x10
end_define

begin_comment
comment|/* 1: Power-On Reset is 						 * bypassed, default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_SELECT24S
value|0x20
end_define

begin_comment
comment|/* 0: 4 Serial Ports / IrDA 						 * active, 1: 2 Serial Ports / 						 * IrDA active */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_EEPROMWR
value|0x40
end_define

begin_comment
comment|/* EEPROM write is enabled, 						 * default */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_MODE_IRDA
value|0x80
end_define

begin_comment
comment|/* IrDA mode is activated 						 * (could be turned on), 						 * default */
end_comment

begin_comment
comment|/* Bits for SPx ICG */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_SPx_ICG_DEF
value|0x24
end_define

begin_comment
comment|/* All 8 bits is used as 						 * number of BAUD clocks of 						 * pause */
end_comment

begin_comment
comment|/*  * Bits for RX_SAMPLINGxx registers  * These registers control when bit value will be sampled within  * the baud period.  * 0 is very beginning of period, 15 is very end, 7 is the middle.  */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING1_MASK
value|0x0f
end_define

begin_comment
comment|/* Bits for port 1 in 						 * RX_SAMPLING12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING1_SHIFT
value|0
end_define

begin_comment
comment|/* Shift for port 1in 						 * RX_SAMPLING12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING2_MASK
value|0xf0
end_define

begin_comment
comment|/* Bits for port 2 in 						 * RX_SAMPLING12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING2_SHIFT
value|4
end_define

begin_comment
comment|/* Shift for port 2 in 						 * RX_SAMPLING12 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING3_MASK
value|0x0f
end_define

begin_comment
comment|/* Bits for port 3 in 						 * RX_SAMPLING23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING3_SHIFT
value|0
end_define

begin_comment
comment|/* Shift for port 3 in 						 * RX_SAMPLING23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING4_MASK
value|0xf0
end_define

begin_comment
comment|/* Bits for port 4 in 						 * RX_SAMPLING23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLING4_SHIFT
value|4
end_define

begin_comment
comment|/* Shift for port 4 in 						 * RX_SAMPLING23 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLINGx_MIN
value|0
end_define

begin_comment
comment|/* Max for any RX Sampling */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLINGx_DEF
value|7
end_define

begin_comment
comment|/* Default for any RX 						 * Sampling, center of period */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_RX_SAMPLINGx_MAX
value|15
end_define

begin_comment
comment|/* Min for any RX Sampling */
end_comment

begin_comment
comment|/* Bits for ZERO_PERIODx */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_ZERO_PERIODx_DEF
value|20
end_define

begin_comment
comment|/* Number of Bulk-in requests 						 * befor sending zero-sized 						 * reply */
end_comment

begin_comment
comment|/* Bits for ZERO_ENABLE */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_ZERO_ENABLE_PORT1
value|0x01
end_define

begin_comment
comment|/* Enable of sending 						 * zero-sized replies for port 						 * 1, default */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_ZERO_ENABLE_PORT2
value|0x02
end_define

begin_comment
comment|/* Enable of sending 						 * zero-sized replies for port 						 * 2, default */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_ZERO_ENABLE_PORT3
value|0x04
end_define

begin_comment
comment|/* Enable of sending 						 * zero-sized replies for port 						 * 3, default */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_ZERO_ENABLE_PORT4
value|0x08
end_define

begin_comment
comment|/* Enable of sending 						 * zero-sized replies for port 						 * 4, default */
end_comment

begin_comment
comment|/* Bits for THR_VAL_HIGHx */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_THR_VAL_HIGH_MASK
value|0x01
end_define

begin_comment
comment|/* Only one bit is used */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_THR_VAL_HIGH_MUL
value|256
end_define

begin_comment
comment|/* This one bit is means "256" */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_THR_VAL_HIGH_SHIFT
value|8
end_define

begin_comment
comment|/* This one bit is means "256" */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_THR_VAL_HIGH_ENABLE
value|0x80
end_define

begin_comment
comment|/* Enable threshold */
end_comment

begin_comment
comment|/* These are documented in "public" datasheet */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR0_1
value|0x04
end_define

begin_comment
comment|/* Device contol register 0 for Port 					 * 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR1_1
value|0x05
end_define

begin_comment
comment|/* Device contol register 1 for Port 					 * 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR2_1
value|0x06
end_define

begin_comment
comment|/* Device contol register 2 for Port 					 * 1, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR0_2
value|0x16
end_define

begin_comment
comment|/* Device contol register 0 for Port 					 * 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR1_2
value|0x17
end_define

begin_comment
comment|/* Device contol register 1 for Port 					 * 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR2_2
value|0x18
end_define

begin_comment
comment|/* Device contol register 2 for Port 					 * 2, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR0_3
value|0x19
end_define

begin_comment
comment|/* Device contol register 0 for Port 					 * 3, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR1_3
value|0x1a
end_define

begin_comment
comment|/* Device contol register 1 for Port 					 * 3, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR2_3
value|0x1b
end_define

begin_comment
comment|/* Device contol register 2 for Port 					 * 3, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR0_4
value|0x1c
end_define

begin_comment
comment|/* Device contol register 0 for Port 					 * 4, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR1_4
value|0x1d
end_define

begin_comment
comment|/* Device contol register 1 for Port 					 * 4, R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_REG_DCR2_4
value|0x1e
end_define

begin_comment
comment|/* Device contol register 2 for Port 					 * 4, R/W */
end_comment

begin_comment
comment|/* Bits of DCR0 registers, documented in datasheet */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_PWRSAVE
value|0x01
end_define

begin_comment
comment|/* Shutdown transiver 							 * when USB Suspend is 							 * engaged, default = 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_RESERVED1
value|0x02
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_GPIO_MODE_MASK
value|0x0c
end_define

begin_comment
comment|/* GPIO Mode bits, WORKS 							 * ONLY FOR PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_GPIO_MODE_IN
value|0x00
end_define

begin_comment
comment|/* GPIO Mode - Input 							 * (0b00), WORKS ONLY 							 * FOR PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_GPIO_MODE_OUT
value|0x08
end_define

begin_comment
comment|/* GPIO Mode - Input 							 * (0b10), WORKS ONLY 							 * FOR PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_RTS_ACTIVE_HIGH
value|0x10
end_define

begin_comment
comment|/* RTS Active is HIGH, 							 * default = 0 (low) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_RTS_AUTO
value|0x20
end_define

begin_comment
comment|/* RTS is controlled by 							 * state of TX buffer, 							 * default = 0 							 * (controlled by MCR) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_IRDA
value|0x40
end_define

begin_comment
comment|/* IrDA mode */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR0_RESERVED2
value|0x80
end_define

begin_comment
comment|/* Unused */
end_comment

begin_comment
comment|/* Bits of DCR1 registers, documented in datasheet */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_GPIO_CURRENT_MASK
value|0x03
end_define

begin_comment
comment|/* Mask to extract GPIO 							 * current value, WORKS 							 * ONLY FOR PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_GPIO_CURRENT_6MA
value|0x00
end_define

begin_comment
comment|/* GPIO output current 							 * 6mA, WORKS ONLY FOR 							 * PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_GPIO_CURRENT_8MA
value|0x01
end_define

begin_comment
comment|/* GPIO output current 							 * 8mA, defauilt, WORKS 							 * ONLY FOR PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_GPIO_CURRENT_10MA
value|0x02
end_define

begin_comment
comment|/* GPIO output current 							 * 10mA, WORKS ONLY FOR 							 * PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_GPIO_CURRENT_12MA
value|0x03
end_define

begin_comment
comment|/* GPIO output current 							 * 12mA, WORKS ONLY FOR 							 * PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_UART_CURRENT_MASK
value|0x0c
end_define

begin_comment
comment|/* Mask to extract UART 							 * signals current value */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_UART_CURRENT_6MA
value|0x00
end_define

begin_comment
comment|/* UART output current 							 * 6mA */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_UART_CURRENT_8MA
value|0x04
end_define

begin_comment
comment|/* UART output current 							 * 8mA, defauilt */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_UART_CURRENT_10MA
value|0x08
end_define

begin_comment
comment|/* UART output current 							 * 10mA */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_UART_CURRENT_12MA
value|0x0c
end_define

begin_comment
comment|/* UART output current 							 * 12mA */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_WAKEUP_DISABLE
value|0x10
end_define

begin_comment
comment|/* Disable Remote USB 							 * Wakeup */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_PLLPWRDOWN_DISABLE
value|0x20
end_define

begin_comment
comment|/* Disable PLL power 							 * down when not needed, 							 * WORKS ONLY FOR PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_LONG_INTERRUPT
value|0x40
end_define

begin_comment
comment|/* Enable 13 bytes of 							 * interrupt data, with 							 * FIFO statistics, 							 * WORKS ONLY FOR PORT 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR1_RESERVED1
value|0x80
end_define

begin_comment
comment|/* Unused */
end_comment

begin_comment
comment|/*  * Bits of DCR2 registers, documented in datasheet  * Wakeup will work only if DCR0_IRDA = 0 (RS-xxx mode) and  * DCR1_WAKEUP_DISABLE = 0 (wakeup enabled).  */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_WAKEUP_CTS
value|0x01
end_define

begin_comment
comment|/* Wakeup on CTS change, 						 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_WAKEUP_DCD
value|0x02
end_define

begin_comment
comment|/* Wakeup on DCD change, 						 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_WAKEUP_RI
value|0x04
end_define

begin_comment
comment|/* Wakeup on RI change, 						 * default = 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_WAKEUP_DSR
value|0x08
end_define

begin_comment
comment|/* Wakeup on DSR change, 						 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_WAKEUP_RXD
value|0x10
end_define

begin_comment
comment|/* Wakeup on RX Data change, 						 * default = 0 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_WAKEUP_RESUME
value|0x20
end_define

begin_comment
comment|/* Wakeup issues RESUME 						 * signal, DISCONNECT 						 * otherwise, default = 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_RESERVED1
value|0x40
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|MCS7840_DEV_DCR2_SHDN_POLARITY
value|0x80
end_define

begin_comment
comment|/* 0: Pin 12 Active Low, 1: 						 * Pin 12 Active High, default 						 * = 0 */
end_comment

begin_comment
comment|/* Interrupt endpoint bytes& bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_IEP_FIFO_STATUS_INDEX
value|5
end_define

begin_comment
comment|/*  * Thesse can be calculated as "1<< portnumber" for Bulk-out and  * "1<< (portnumber+1)" for Bulk-in  */
end_comment

begin_define
define|#
directive|define
name|MCS7840_IEP_BO_PORT1_HASDATA
value|0x01
end_define

begin_define
define|#
directive|define
name|MCS7840_IEP_BI_PORT1_HASDATA
value|0x02
end_define

begin_define
define|#
directive|define
name|MCS7840_IEP_BO_PORT2_HASDATA
value|0x04
end_define

begin_define
define|#
directive|define
name|MCS7840_IEP_BI_PORT2_HASDATA
value|0x08
end_define

begin_define
define|#
directive|define
name|MCS7840_IEP_BO_PORT3_HASDATA
value|0x10
end_define

begin_define
define|#
directive|define
name|MCS7840_IEP_BI_PORT3_HASDATA
value|0x20
end_define

begin_define
define|#
directive|define
name|MCS7840_IEP_BO_PORT4_HASDATA
value|0x40
end_define

begin_define
define|#
directive|define
name|MCS7840_IEP_BI_PORT4_HASDATA
value|0x80
end_define

begin_comment
comment|/* Documented UART registers (fully compatible with 16550 UART) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_THR
value|0x00
end_define

begin_comment
comment|/* Transmitter Holding 						 * Register W/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_RHR
value|0x00
end_define

begin_comment
comment|/* Receiver Holding Register 						 * R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_IER
value|0x01
end_define

begin_comment
comment|/* Interrupt enable register - 						 * R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_FCR
value|0x02
end_define

begin_comment
comment|/* FIFO Control register - 						 * W/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_ISR
value|0x02
end_define

begin_comment
comment|/* Interrupt Status Registter 						 * R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_LCR
value|0x03
end_define

begin_comment
comment|/* Line control register R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_MCR
value|0x04
end_define

begin_comment
comment|/* Modem control register R/W */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_LSR
value|0x05
end_define

begin_comment
comment|/* Line status register R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_MSR
value|0x06
end_define

begin_comment
comment|/* Modem status register 						 * R/Only */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_SCRATCHPAD
value|0x07
end_define

begin_comment
comment|/* Scratch pad register */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_DLL
value|0x00
end_define

begin_comment
comment|/* Low bits of BAUD divider */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_REG_DLM
value|0x01
end_define

begin_comment
comment|/* High bits of BAUD divider */
end_comment

begin_comment
comment|/* IER bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_IER_RXREADY
value|0x01
end_define

begin_comment
comment|/* RX Ready interrumpt mask */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_IER_TXREADY
value|0x02
end_define

begin_comment
comment|/* TX Ready interrumpt mask */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_IER_RXSTAT
value|0x04
end_define

begin_comment
comment|/* RX Status interrumpt mask */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_IER_MODEM
value|0x08
end_define

begin_comment
comment|/* Modem status change 						 * interrumpt mask */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_IER_SLEEP
value|0x10
end_define

begin_comment
comment|/* SLEEP enable */
end_comment

begin_comment
comment|/* FCR bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_ENABLE
value|0x01
end_define

begin_comment
comment|/* Enable FIFO */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_FLUSHRHR
value|0x02
end_define

begin_comment
comment|/* Flush RHR and FIFO */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_FLUSHTHR
value|0x04
end_define

begin_comment
comment|/* Flush THR and FIFO */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_RTLMASK
value|0xa0
end_define

begin_comment
comment|/* Mask to select RHR 						 * Interrupt Trigger level */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_RTL_1_1
value|0x00
end_define

begin_comment
comment|/* L1 = 1, L2 = 1 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_RTL_1_4
value|0x40
end_define

begin_comment
comment|/* L1 = 1, L2 = 4 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_RTL_1_8
value|0x80
end_define

begin_comment
comment|/* L1 = 1, L2 = 8 */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_FCR_RTL_1_14
value|0xa0
end_define

begin_comment
comment|/* L1 = 1, L2 = 14 */
end_comment

begin_comment
comment|/* ISR bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_ISR_NOPENDING
value|0x01
end_define

begin_comment
comment|/* No interrupt pending */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_ISR_INTMASK
value|0x3f
end_define

begin_comment
comment|/* Mask to select interrupt 						 * source */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_ISR_RXERR
value|0x06
end_define

begin_comment
comment|/* Recevir error */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_ISR_RXHASDATA
value|0x04
end_define

begin_comment
comment|/* Recevier has data */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_ISR_RXTIMEOUT
value|0x0c
end_define

begin_comment
comment|/* Recevier timeout */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_ISR_TXEMPTY
value|0x02
end_define

begin_comment
comment|/* Transmitter empty */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_ISR_MSCHANGE
value|0x00
end_define

begin_comment
comment|/* Modem status change */
end_comment

begin_comment
comment|/* LCR bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_DATALENMASK
value|0x03
end_define

begin_comment
comment|/* Mask for data length */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_DATALEN5
value|0x00
end_define

begin_comment
comment|/* 5 data bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_DATALEN6
value|0x01
end_define

begin_comment
comment|/* 6 data bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_DATALEN7
value|0x02
end_define

begin_comment
comment|/* 7 data bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_DATALEN8
value|0x03
end_define

begin_comment
comment|/* 8 data bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_STOPBMASK
value|0x04
end_define

begin_comment
comment|/* Mask for stop bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_STOPB1
value|0x00
end_define

begin_comment
comment|/* 1 stop bit in any case */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_STOPB2
value|0x04
end_define

begin_comment
comment|/* 1.5-2 stop bits depends on 						 * data length */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_PARITYMASK
value|0x38
end_define

begin_comment
comment|/* Mask for all parity data */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_PARITYON
value|0x08
end_define

begin_comment
comment|/* Parity ON/OFF - ON */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_PARITYODD
value|0x00
end_define

begin_comment
comment|/* Parity Odd */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_PARITYEVEN
value|0x10
end_define

begin_comment
comment|/* Parity Even */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_PARITYODD
value|0x00
end_define

begin_comment
comment|/* Parity Odd */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_PARITYFORCE
value|0x20
end_define

begin_comment
comment|/* Force parity odd/even */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_BREAK
value|0x40
end_define

begin_comment
comment|/* Send BREAK */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LCR_DIVISORS
value|0x80
end_define

begin_comment
comment|/* Map DLL/DLM instead of 						 * xHR/IER */
end_comment

begin_comment
comment|/* LSR bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LSR_RHRAVAIL
value|0x01
end_define

begin_comment
comment|/* Data available for read */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LSR_RHROVERRUN
value|0x02
end_define

begin_comment
comment|/* Data FIFO/register overflow */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LSR_PARITYERR
value|0x04
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LSR_FRAMEERR
value|0x10
end_define

begin_comment
comment|/* Framing error */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LSR_BREAKERR
value|0x20
end_define

begin_comment
comment|/* BREAK signal received */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LSR_THREMPTY
value|0x40
end_define

begin_comment
comment|/* THR register is empty, 						 * ready for transmit */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_LSR_HASERR
value|0x80
end_define

begin_comment
comment|/* Has error in receiver FIFO */
end_comment

begin_comment
comment|/* MCR bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MCR_DTR
value|0x01
end_define

begin_comment
comment|/* Force DTR to be active 						 * (low) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MCR_RTS
value|0x02
end_define

begin_comment
comment|/* Force RTS to be active 						 * (low) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MCR_IE
value|0x04
end_define

begin_comment
comment|/* Enable interrupts (from 						 * code, not documented) */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MCR_LOOPBACK
value|0x10
end_define

begin_comment
comment|/* Enable local loopback test 						 * mode */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MCR_CTSRTS
value|0x20
end_define

begin_comment
comment|/* Enable CTS/RTS flow control 						 * in 550 (FIFO) mode */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MCR_DTRDSR
value|0x40
end_define

begin_comment
comment|/* Enable DTR/DSR flow control 						 * in 550 (FIFO) mode */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MCR_DCD
value|0x80
end_define

begin_comment
comment|/* Enable DCD flow control in 						 * 550 (FIFO) mode */
end_comment

begin_comment
comment|/* MSR bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_DELTACTS
value|0x01
end_define

begin_comment
comment|/* CTS was changed since last 						 * read */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_DELTADSR
value|0x02
end_define

begin_comment
comment|/* DSR was changed since last 						 * read */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_DELTARI
value|0x04
end_define

begin_comment
comment|/* RI was changed from low to 						 * high since last read */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_DELTADCD
value|0x08
end_define

begin_comment
comment|/* DCD was changed since last 						 * read */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_NEGCTS
value|0x10
end_define

begin_comment
comment|/* Negated CTS signal */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_NEGDSR
value|0x20
end_define

begin_comment
comment|/* Negated DSR signal */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_NEGRI
value|0x40
end_define

begin_comment
comment|/* Negated RI signal */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_MSR_NEGDCD
value|0x80
end_define

begin_comment
comment|/* Negated DCD signal */
end_comment

begin_comment
comment|/* SCRATCHPAD bits */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_SCRATCHPAD_RS232
value|0x00
end_define

begin_comment
comment|/* RS-485 disabled */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_SCRATCHPAD_RS485_DTRRX
value|0x80
end_define

begin_comment
comment|/* RS-485 mode, DTR High 							 * = RX */
end_comment

begin_define
define|#
directive|define
name|MCS7840_UART_SCRATCHPAD_RS485_DTRTX
value|0xc0
end_define

begin_comment
comment|/* RS-485 mode, DTR High 							 * = TX */
end_comment

begin_define
define|#
directive|define
name|MCS7840_CONFIG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MCS7840_IFACE_INDEX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

