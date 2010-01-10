begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: octeonreg.h,v 1.1 2002/03/07 14:44:04 simonb Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Simon Burge for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* 	Memory Map  	0000.0000 *	128MB	Typically SDRAM (on Core Board) 	0800.0000 *	256MB	Typically PCI 	1800.0000 *	 62MB	Typically PCI 	1be0.0000 *	  2MB	Typically System controller's internal registers 	1c00.0000 *	 32MB	Typically not used 	1e00.0000	  4MB	Monitor Flash 	1e40.0000	 12MB	reserved 	1f00.0000	 12MB	Switches 				LEDs 				ASCII display 				Soft reset 				FPGA revision number 				CBUS UART (tty2) 				General Purpose I/O 				I2C controller 	1f10.0000 *	 11MB	Typically System Controller specific 	1fc0.0000	  4MB	Maps to Monitor Flash 	1fd0.0000 *	  3MB	Typically System Controller specific  		  * depends on implementation of the Core Board and of software  */
end_comment

begin_comment
comment|/* 	CPU interrupts  		NMI	South Bridge or NMI button 		 0	South Bridge INTR 		 1	South Bridge SMI 		 2	CBUS UART (tty2) 		 3	COREHI (Core Card) 		 4	CORELO (Core Card) 		 5	Not used, driven inactive (typically CPU internal timer interrupt  	IRQ mapping (as used by YAMON)  		0	Timer		South Bridge 		1	Keyboard	SuperIO 		2			Reserved by South Bridge (for cascading) 		3	UART (tty1)	SuperIO 		4	UART (tty0)	SuperIO 		5			Not used 		6	Floppy Disk	SuperIO 		7	Parallel Port	SuperIO 		8	Real Time Clock	South Bridge 		9	I2C bus		South Bridge 		10	PCI A,B,eth	PCI slot 1..4, Ethernet 		11	PCI C,audio	PCI slot 1..4, Audio, USB (South Bridge) 			PCI D,USB 		12	Mouse		SuperIO 		13			Reserved by South Bridge 		14	Primary IDE	Primary IDE slot 		15	Secondary IDE	Secondary IDE slot/Compact flash connector  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_SYSTEMRAM_BASE
value|0x00000000
end_define

begin_comment
comment|/* System RAM:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_SYSTEMRAM_SIZE
value|0x08000000
end_define

begin_comment
comment|/*   128 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_PCIMEM1_BASE
value|0x08000000
end_define

begin_comment
comment|/* PCI 1 memory:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_PCIMEM1_SIZE
value|0x08000000
end_define

begin_comment
comment|/*   128 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_PCIMEM2_BASE
value|0x10000000
end_define

begin_comment
comment|/* PCI 2 memory:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_PCIMEM2_SIZE
value|0x08000000
end_define

begin_comment
comment|/*   128 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_PCIMEM3_BASE
value|0x18000000
end_define

begin_comment
comment|/* PCI 3 memory	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_PCIMEM3_SIZE
value|0x03e00000
end_define

begin_comment
comment|/*    62 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_CORECTRL_BASE
value|0x1be00000
end_define

begin_comment
comment|/* Core control:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_CORECTRL_SIZE
value|0x00200000
end_define

begin_comment
comment|/*     2 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_RESERVED_BASE1
value|0x1c000000
end_define

begin_comment
comment|/* Reserved:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_RESERVED_SIZE1
value|0x02000000
end_define

begin_comment
comment|/*    32 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_MONITORFLASH_BASE
value|0x1e000000
end_define

begin_comment
comment|/* Monitor Flash:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_MONITORFLASH_SIZE
value|0x003e0000
end_define

begin_comment
comment|/*     4 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_MONITORFLASH_SECTORSIZE
value|0x00010000
end_define

begin_comment
comment|/* Sect. = 64 KB */
end_comment

begin_define
define|#
directive|define
name|OCTEON_FILEFLASH_BASE
value|0x1e3e0000
end_define

begin_comment
comment|/* File Flash (for monitor): */
end_comment

begin_define
define|#
directive|define
name|OCTEON_FILEFLASH_SIZE
value|0x00020000
end_define

begin_comment
comment|/*   128 KByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_FILEFLASH_SECTORSIZE
value|0x00010000
end_define

begin_comment
comment|/* Sect. = 64 KB	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_RESERVED_BASE2
value|0x1e400000
end_define

begin_comment
comment|/* Reserved:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_RESERVED_SIZE2
value|0x00c00000
end_define

begin_comment
comment|/*    12 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_FPGA_BASE
value|0x1f000000
end_define

begin_comment
comment|/* FPGA:		*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_FPGA_SIZE
value|0x00c00000
end_define

begin_comment
comment|/*    12 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_NMISTATUS
value|(OCTEON_FPGA_BASE + 0x24)
end_define

begin_define
define|#
directive|define
name|OCTEON_NMI_SB
value|0x2
end_define

begin_comment
comment|/* Pending NMI from the South Bridge */
end_comment

begin_define
define|#
directive|define
name|OCTEON_NMI_ONNMI
value|0x1
end_define

begin_comment
comment|/* Pending NMI from the ON/NMI push button */
end_comment

begin_define
define|#
directive|define
name|OCTEON_NMIACK
value|(OCTEON_FPGA_BASE + 0x104)
end_define

begin_define
define|#
directive|define
name|OCTEON_NMIACK_ONNMI
value|0x1
end_define

begin_comment
comment|/* Write 1 to acknowledge ON/NMI */
end_comment

begin_define
define|#
directive|define
name|OCTEON_SWITCH
value|(OCTEON_FPGA_BASE + 0x200)
end_define

begin_define
define|#
directive|define
name|OCTEON_SWITCH_MASK
value|0xff
end_define

begin_comment
comment|/* settings of DIP switch S2 */
end_comment

begin_define
define|#
directive|define
name|OCTEON_STATUS
value|(OCTEON_FPGA_BASE + 0x208)
end_define

begin_define
define|#
directive|define
name|OCTEON_ST_MFWR
value|0x10
end_define

begin_comment
comment|/* Monitor Flash is write protected (JP1) */
end_comment

begin_define
define|#
directive|define
name|OCTEON_S54
value|0x08
end_define

begin_comment
comment|/* switch S5-4 - set YAMON factory default mode */
end_comment

begin_define
define|#
directive|define
name|OCTEON_S53
value|0x04
end_define

begin_comment
comment|/* switch S5-3 */
end_comment

begin_define
define|#
directive|define
name|OCTEON_BIGEND
value|0x02
end_define

begin_comment
comment|/* switch S5-2 - big endian mode */
end_comment

begin_define
define|#
directive|define
name|OCTEON_JMPRS
value|(OCTEON_FPGA_BASE + 0x210)
end_define

begin_define
define|#
directive|define
name|OCTEON_JMPRS_PCICLK
value|0x1c
end_define

begin_comment
comment|/* PCI clock frequency */
end_comment

begin_define
define|#
directive|define
name|OCTEON_JMPRS_EELOCK
value|0x02
end_define

begin_comment
comment|/* I2C EEPROM is write protected */
end_comment

begin_define
define|#
directive|define
name|OCTEON_LEDBAR
value|(OCTEON_FPGA_BASE + 0x408)
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIWORD
value|(OCTEON_FPGA_BASE + 0x410)
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCII_BASE
value|(OCTEON_FPGA_BASE + 0x418)
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS0
value|0x00
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS1
value|0x08
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS2
value|0x10
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS3
value|0x18
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS4
value|0x20
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS5
value|0x28
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS6
value|0x30
end_define

begin_define
define|#
directive|define
name|OCTEON_ASCIIPOS7
value|0x38
end_define

begin_define
define|#
directive|define
name|OCTEON_SOFTRES
value|(OCTEON_FPGA_BASE + 0x500)
end_define

begin_define
define|#
directive|define
name|OCTEON_GORESET
value|0x42
end_define

begin_comment
comment|/* write this to OCTEON_SOFTRES for board reset */
end_comment

begin_comment
comment|/*  * BRKRES is the number of milliseconds before a "break" on tty will  * trigger a reset.  A value of 0 will disable the reset.  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_BRKRES
value|(OCTEON_FPGA_BASE + 0x508)
end_define

begin_define
define|#
directive|define
name|OCTEON_BRKRES_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|OCTEON_CBUSUART
value|0x8001180000000800ull
end_define

begin_comment
comment|/* 16C550C UART, 8 bit registers on 8 byte boundaries */
end_comment

begin_comment
comment|/* RXTX    0x00 */
end_comment

begin_comment
comment|/* INTEN   0x08 */
end_comment

begin_comment
comment|/* IIFIFO  0x10 */
end_comment

begin_comment
comment|/* LCTRL   0x18 */
end_comment

begin_comment
comment|/* MCTRL   0x20 */
end_comment

begin_comment
comment|/* LSTAT   0x28 */
end_comment

begin_comment
comment|/* MSTAT   0x30 */
end_comment

begin_comment
comment|/* SCRATCH 0x38 */
end_comment

begin_define
define|#
directive|define
name|OCTEON_CBUSUART_INTR
value|2
end_define

begin_define
define|#
directive|define
name|OCTEON_GPIO_BASE
value|(OCTEON_FPGA_BASE + 0xa00)
end_define

begin_define
define|#
directive|define
name|OCTEON_GPOUT
value|0x0
end_define

begin_define
define|#
directive|define
name|OCTEON_GPINP
value|0x8
end_define

begin_define
define|#
directive|define
name|OCTEON_BOOTROM_BASE
value|0x1fc00000
end_define

begin_comment
comment|/* Boot ROM:	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_BOOTROM_SIZE
value|0x00400000
end_define

begin_comment
comment|/*     4 MByte	*/
end_comment

begin_define
define|#
directive|define
name|OCTEON_REVISION
value|0x1fc00010
end_define

begin_define
define|#
directive|define
name|OCTEON_REV_FPGRV
value|0xff0000
end_define

begin_comment
comment|/* CBUS FPGA revision */
end_comment

begin_define
define|#
directive|define
name|OCTEON_REV_CORID
value|0x00fc00
end_define

begin_comment
comment|/* Core Board ID */
end_comment

begin_define
define|#
directive|define
name|OCTEON_REV_CORRV
value|0x000300
end_define

begin_comment
comment|/* Core Board Revision */
end_comment

begin_define
define|#
directive|define
name|OCTEON_REV_PROID
value|0x0000f0
end_define

begin_comment
comment|/* Product ID */
end_comment

begin_define
define|#
directive|define
name|OCTEON_REV_PRORV
value|0x00000f
end_define

begin_comment
comment|/* Product Revision */
end_comment

begin_comment
comment|/* PCI definitions */
end_comment

begin_define
define|#
directive|define
name|OCTEON_UART0ADR
value|0x8001180000000800ull
end_define

begin_define
define|#
directive|define
name|OCTEON_UART1ADR
value|0x8001180000000C00ull
end_define

begin_define
define|#
directive|define
name|OCTEON_UART_SIZE
value|0x400
end_define

begin_define
define|#
directive|define
name|OCTEON_MIO_BOOT_BIST_STAT
value|0x80011800000000F8ull
end_define

begin_comment
comment|/**************************  * To Delete  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_SOUTHBRIDGE_INTR
value|0
end_define

begin_define
define|#
directive|define
name|OCTEON_PCI0_IO_BASE
value|OCTEON_PCIMEM3_BASE
end_define

begin_define
define|#
directive|define
name|OCTEON_PCI0_ADDR
parameter_list|(
name|addr
parameter_list|)
value|(OCTEON_PCI0_IO_BASE + (addr))
end_define

begin_define
define|#
directive|define
name|OCTEON_RTCADR
value|0x70
end_define

begin_comment
comment|// OCTEON_PCI_IO_ADDR8(0x70)
end_comment

begin_define
define|#
directive|define
name|OCTEON_RTCDAT
value|0x71
end_define

begin_comment
comment|// OCTEON_PCI_IO_ADDR8(0x71)
end_comment

begin_define
define|#
directive|define
name|OCTEON_SMSC_COM1_ADR
value|0x3f8
end_define

begin_define
define|#
directive|define
name|OCTEON_SMSC_COM2_ADR
value|0x2f8
end_define

begin_define
define|#
directive|define
name|OCTEON_UARTT0ADR
value|OCTEON_PCI0_ADDR(OCTEON_SMSC_COM1_ADR)
end_define

begin_define
define|#
directive|define
name|OCTEON_UARTT1ADR
value|OCTEON_SMSC_COM2_ADR
end_define

begin_comment
comment|// OCTEON_PCI0_ADDR(OCTEON_SMSC_COM2_ADR)
end_comment

begin_define
define|#
directive|define
name|OCTEON_SMSC_1284_ADR
value|0x378
end_define

begin_define
define|#
directive|define
name|OCTEON_1284ADR
value|OCTEON_SMSC_1284_ADR
end_define

begin_comment
comment|// OCTEON_PCI0_ADDR(OCTEON_SMSC_1284_ADR)
end_comment

begin_define
define|#
directive|define
name|OCTEON_SMSC_FDD_ADR
value|0x3f0
end_define

begin_define
define|#
directive|define
name|OCTEON_FDDADR
value|OCTEON_SMSC_FDD_ADR
end_define

begin_comment
comment|// OCTEON_PCI0_ADDR(OCTEON_SMSC_FDD_ADR)
end_comment

begin_define
define|#
directive|define
name|OCTEON_SMSC_KYBD_ADR
value|0x60
end_define

begin_comment
comment|/* Fixed 0x60, 0x64 */
end_comment

begin_define
define|#
directive|define
name|OCTEON_KYBDADR
value|OCTEON_SMSC_KYBD_ADR
end_define

begin_comment
comment|// OCTEON_PCI0_ADDR(OCTEON_SMSC_KYBD_ADR)
end_comment

begin_define
define|#
directive|define
name|OCTEON_SMSC_MOUSE_ADR
value|OCTEON_SMSC_KYBD_ADR
end_define

begin_define
define|#
directive|define
name|OCTEON_MOUSEADR
value|OCTEON_KYBDADR
end_define

begin_define
define|#
directive|define
name|OCTEON_DMA_PCI_PCIBASE
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|OCTEON_DMA_PCI_PHYSBASE
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|OCTEON_DMA_PCI_SIZE
value|(256 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|OCTEON_DMA_ISA_PCIBASE
value|0x00800000UL
end_define

begin_define
define|#
directive|define
name|OCTEON_DMA_ISA_PHYSBASE
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|OCTEON_DMA_ISA_SIZE
value|(8 * 1024 * 1024)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_function_decl
name|void
name|led_bar
parameter_list|(
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|led_display_word
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|led_display_str
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|led_display_char
parameter_list|(
name|int
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

