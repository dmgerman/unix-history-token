begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	i82365.h - Definitions for Intel 82365 PCIC  *	PCMCIA Card Interface Controller  *  * originally by Barry Jaspan; hacked over by Keith Moore  * hacked to unrecognisability by Andrew McRae (andrew@mega.com.au)  *  * Updated 3/3/95 to include Cirrus Logic stuff.  *-------------------------------------------------------------------------  *  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_I82365
value|0
end_define

begin_comment
comment|/* Intel chip */
end_comment

begin_define
define|#
directive|define
name|PCIC_IBM
value|1
end_define

begin_comment
comment|/* IBM clone */
end_comment

begin_define
define|#
directive|define
name|PCIC_VLSI
value|2
end_define

begin_comment
comment|/* VLSI chip */
end_comment

begin_define
define|#
directive|define
name|PCIC_PD672X
value|3
end_define

begin_comment
comment|/* Cirrus logic 627x */
end_comment

begin_define
define|#
directive|define
name|PCIC_PD6710
value|4
end_define

begin_comment
comment|/* Cirrus logic 6710 */
end_comment

begin_define
define|#
directive|define
name|PCIC_CL6729
value|5
end_define

begin_comment
comment|/* Cirrus logic 6729 */
end_comment

begin_define
define|#
directive|define
name|PCIC_VG468
value|6
end_define

begin_comment
comment|/* Vadem 468 */
end_comment

begin_define
define|#
directive|define
name|PCIC_VG469
value|7
end_define

begin_comment
comment|/* Vadem 469 */
end_comment

begin_define
define|#
directive|define
name|PCIC_RF5C396
value|8
end_define

begin_comment
comment|/* Ricoh RF5C396 */
end_comment

begin_define
define|#
directive|define
name|PCIC_IBM_KING
value|9
end_define

begin_comment
comment|/* IBM KING PCMCIA Controller */
end_comment

begin_define
define|#
directive|define
name|PCIC_PC98
value|10
end_define

begin_comment
comment|/* NEC PC98 PCMCIA Controller */
end_comment

begin_define
define|#
directive|define
name|PCIC_TI1130
value|11
end_define

begin_comment
comment|/* TI PCI1130 CardBus */
end_comment

begin_comment
comment|/*  *	Address of the controllers. Each controller can manage  *	two PCMCIA slots. Up to 8 slots are supported in total.  *	The PCIC controller is accessed via an index port and a  *	data port. The index port has the 8 bit address of the  *	register accessed via the data port. How I long for  *	real memory mapped I/O!  *	The top two bits of the index address are used to  *	identify the port number, and the lower 6 bits  *	select one of the 64 possible data registers.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_INDEX_0
value|0x3E0
end_define

begin_comment
comment|/* index reg, chips 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|PCIC_DATA_0
value|(PCIC_INDEX_0 + 1)
end_define

begin_comment
comment|/* data reg, chips 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|PCIC_INDEX_1
value|(PCIC_INDEX_0 + 2)
end_define

begin_comment
comment|/* index reg, chips 2 and 3 */
end_comment

begin_define
define|#
directive|define
name|PCIC_DATA_1
value|(PCIC_INDEX_1 + 1)
end_define

begin_comment
comment|/* data reg, chips 2 and 3 */
end_comment

begin_comment
comment|/*  *	Register index addresses.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_ID_REV
value|0x00
end_define

begin_comment
comment|/* Identification and Revision */
end_comment

begin_define
define|#
directive|define
name|PCIC_STATUS
value|0x01
end_define

begin_comment
comment|/* Interface Status */
end_comment

begin_define
define|#
directive|define
name|PCIC_POWER
value|0x02
end_define

begin_comment
comment|/* Power and RESETDRV control */
end_comment

begin_define
define|#
directive|define
name|PCIC_INT_GEN
value|0x03
end_define

begin_comment
comment|/* Interrupt and General Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_STAT_CHG
value|0x04
end_define

begin_comment
comment|/* Card Status Change */
end_comment

begin_define
define|#
directive|define
name|PCIC_STAT_INT
value|0x05
end_define

begin_comment
comment|/* Card Status Change Interrupt Config */
end_comment

begin_define
define|#
directive|define
name|PCIC_ADDRWINE
value|0x06
end_define

begin_comment
comment|/* Address Window Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_IOCTL
value|0x07
end_define

begin_comment
comment|/* I/O Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0
value|0x08
end_define

begin_comment
comment|/* I/O Address 0 */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1
value|0x0c
end_define

begin_comment
comment|/* I/O Address 1 */
end_comment

begin_define
define|#
directive|define
name|PCIC_MEMBASE
value|0x10
end_define

begin_comment
comment|/* Base of memory window registers */
end_comment

begin_define
define|#
directive|define
name|PCIC_CDGC
value|0x16
end_define

begin_comment
comment|/* Card Detect and General Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_MISC1
value|0x16
end_define

begin_comment
comment|/* PD672x: Misc control register 1 per slot */
end_comment

begin_define
define|#
directive|define
name|PCIC_GLO_CTRL
value|0x1e
end_define

begin_comment
comment|/* Global Control Register */
end_comment

begin_define
define|#
directive|define
name|PCIC_MISC2
value|0x1e
end_define

begin_comment
comment|/* PD672x: Misc control register 2 per chip */
end_comment

begin_define
define|#
directive|define
name|PCIC_TIME_SETUP0
value|0x3a
end_define

begin_define
define|#
directive|define
name|PCIC_TIME_CMD0
value|0x3b
end_define

begin_define
define|#
directive|define
name|PCIC_TIME_RECOV0
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCIC_TIME_SETUP1
value|0x3d
end_define

begin_define
define|#
directive|define
name|PCIC_TIME_CMD1
value|0x3e
end_define

begin_define
define|#
directive|define
name|PCIC_TIME_RECOV1
value|0x3f
end_define

begin_define
define|#
directive|define
name|PCIC_SLOT_SIZE
value|0x40
end_define

begin_comment
comment|/* Size of register set for one slot */
end_comment

begin_comment
comment|/* Now register bits, ordered by reg # */
end_comment

begin_comment
comment|/* For Identification and Revision (PCIC_ID_REV) */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTEL0
value|0x82
end_define

begin_comment
comment|/* Intel 82365SL Rev. 0; Both Memory and I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTEL1
value|0x83
end_define

begin_comment
comment|/* Intel 82365SL Rev. 1; Both Memory and I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_IBM1
value|0x88
end_define

begin_comment
comment|/* IBM PCIC clone; Both Memory and I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_IBM2
value|0x89
end_define

begin_comment
comment|/* IBM PCIC clone; Both Memory and I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_IBM3
value|0x8a
end_define

begin_comment
comment|/* IBM KING PCIC clone; Both Memory and I/O */
end_comment

begin_comment
comment|/* For Interface Status register (PCIC_STATUS) */
end_comment

begin_define
define|#
directive|define
name|PCIC_VPPV
value|0x80
end_define

begin_comment
comment|/* Vpp_valid */
end_comment

begin_define
define|#
directive|define
name|PCIC_POW
value|0x40
end_define

begin_comment
comment|/* PC Card power active */
end_comment

begin_define
define|#
directive|define
name|PCIC_READY
value|0x20
end_define

begin_comment
comment|/* Ready/~Busy */
end_comment

begin_define
define|#
directive|define
name|PCIC_MWP
value|0x10
end_define

begin_comment
comment|/* Memory Write Protect */
end_comment

begin_define
define|#
directive|define
name|PCIC_CD
value|0x0C
end_define

begin_comment
comment|/* Both card detect bits */
end_comment

begin_define
define|#
directive|define
name|PCIC_BVD
value|0x03
end_define

begin_comment
comment|/* Both Battery Voltage Detect bits */
end_comment

begin_comment
comment|/* For the Power and RESETDRV register (PCIC_POWER) */
end_comment

begin_define
define|#
directive|define
name|PCIC_OUTENA
value|0x80
end_define

begin_comment
comment|/* Output Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_DISRST
value|0x40
end_define

begin_comment
comment|/* Disable RESETDRV */
end_comment

begin_define
define|#
directive|define
name|PCIC_APSENA
value|0x20
end_define

begin_comment
comment|/* Auto Pwer Switch Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_PCPWRE
value|0x10
end_define

begin_comment
comment|/* PC Card Power Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_VCC
value|0x18
end_define

begin_comment
comment|/* Vcc control bits */
end_comment

begin_define
define|#
directive|define
name|PCIC_VCC_5V
value|0x10
end_define

begin_comment
comment|/* 5 volts */
end_comment

begin_define
define|#
directive|define
name|PCIC_VCC_3V
value|0x18
end_define

begin_comment
comment|/* 3 volts */
end_comment

begin_define
define|#
directive|define
name|PCIC_VCC_5V_KING
value|0x14
end_define

begin_comment
comment|/* 5 volts for KING PCIC */
end_comment

begin_define
define|#
directive|define
name|PCIC_VPP
value|0x0C
end_define

begin_comment
comment|/* Vpp control bits */
end_comment

begin_define
define|#
directive|define
name|PCIC_VPP_5V
value|0x01
end_define

begin_comment
comment|/* 5 volts */
end_comment

begin_define
define|#
directive|define
name|PCIC_VPP_12V
value|0x02
end_define

begin_comment
comment|/* 12 volts */
end_comment

begin_comment
comment|/* For the Interrupt and General Control register (PCIC_INT_GEN) */
end_comment

begin_define
define|#
directive|define
name|PCIC_CARDTYPE
value|0x20
end_define

begin_comment
comment|/* Card Type 0 = memory, 1 = I/O */
end_comment

begin_define
define|#
directive|define
name|PCIC_IOCARD
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_MEMCARD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_CARDRESET
value|0x40
end_define

begin_comment
comment|/* Card reset 0 = Reset, 1 = Normal */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTR_ENA
value|0x10
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_comment
comment|/* For the Card Status Change register (PCIC_STAT_CHG) */
end_comment

begin_define
define|#
directive|define
name|PCIC_CDTCH
value|0x08
end_define

begin_comment
comment|/* Card Detect Change */
end_comment

begin_define
define|#
directive|define
name|PCIC_RDYCH
value|0x04
end_define

begin_comment
comment|/* Ready Change */
end_comment

begin_define
define|#
directive|define
name|PCIC_BATWRN
value|0x02
end_define

begin_comment
comment|/* Battery Warning */
end_comment

begin_define
define|#
directive|define
name|PCIC_BATDED
value|0x01
end_define

begin_comment
comment|/* Battery Dead */
end_comment

begin_comment
comment|/*  * For the Address Window Enable Register (PCIC_ADDRWINE)  * The lower 6 bits contain enable bits for the memory  * windows (LSB = memory window 0).  */
end_comment

begin_define
define|#
directive|define
name|PCIC_MEMCS16
value|0x20
end_define

begin_comment
comment|/* ~MEMCS16 Decode A23-A12 */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO0_EN
value|0x40
end_define

begin_comment
comment|/* I/O Window 0 Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO1_EN
value|0x80
end_define

begin_comment
comment|/* I/O Window 1 Enable */
end_comment

begin_comment
comment|/*  * For the I/O Control Register (PCIC_IOCTL)  * The lower nybble is the flags for I/O window 0  * The upper nybble is the flags for I/O window 1  */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO_16BIT
value|0x01
end_define

begin_comment
comment|/* I/O to this segment is 16 bit */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO_CS16
value|0x02
end_define

begin_comment
comment|/* I/O cs16 source is the card */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO_0WS
value|0x04
end_define

begin_comment
comment|/* zero wait states added on 8 bit cycles */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO_WS
value|0x08
end_define

begin_comment
comment|/* Wait states added for 16 bit cycles */
end_comment

begin_comment
comment|/*  *	The memory window registers contain the start and end  *	physical host address that the PCIC maps to the card,  *	and an offset calculated from the card memory address.  *	All values are shifted down 12 bits, so allocation is  *	done in 4Kb blocks. Only 12 bits of each value is  *	stored, limiting the range to the ISA address size of  *	24 bits. The upper 4 bits of the most significant byte  *	within the values are used for various flags.  *  *	The layout is:  *  *	base+0 : lower 8 bits of system memory start address  *	base+1 : upper 4 bits of system memory start address + flags  *	base+2 : lower 8 bits of system memory end address  *	base+3 : upper 4 bits of system memory end address + flags  *	base+4 : lower 8 bits of offset to card address  *	base+5 : upper 4 bits of offset to card address + flags  *  *	The following two bytes are reserved for other use.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_MEMSIZE
value|8
end_define

begin_comment
comment|/*  *	Flags for system memory start address upper byte  */
end_comment

begin_define
define|#
directive|define
name|PCIC_ZEROWS
value|0x40
end_define

begin_comment
comment|/* Zero wait states */
end_comment

begin_define
define|#
directive|define
name|PCIC_DATA16
value|0x80
end_define

begin_comment
comment|/* Data width is 16 bits */
end_comment

begin_comment
comment|/*  *	Flags for system memory end address upper byte  */
end_comment

begin_define
define|#
directive|define
name|PCIC_MW0
value|0x40
end_define

begin_comment
comment|/* Wait state bit 0 */
end_comment

begin_define
define|#
directive|define
name|PCIC_MW1
value|0x80
end_define

begin_comment
comment|/* Wait state bit 1 */
end_comment

begin_comment
comment|/*  *	Flags for card offset upper byte  */
end_comment

begin_define
define|#
directive|define
name|PCIC_REG
value|0x40
end_define

begin_comment
comment|/* Attribute/Common select (why called Reg?) */
end_comment

begin_define
define|#
directive|define
name|PCIC_WP
value|0x80
end_define

begin_comment
comment|/* Write-protect this window */
end_comment

begin_comment
comment|/* For Card Detect and General Control register (PCIC_CDGC) */
end_comment

begin_define
define|#
directive|define
name|PCIC_16_DL_INH
value|0x01
end_define

begin_comment
comment|/* 16-bit memory delay inhibit */
end_comment

begin_define
define|#
directive|define
name|PCIC_CNFG_RST_EN
value|0x02
end_define

begin_comment
comment|/* configuration reset enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_GPI_EN
value|0x04
end_define

begin_comment
comment|/* GPI Enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_GPI_TRANS
value|0x08
end_define

begin_comment
comment|/* GPI Transition Control */
end_comment

begin_define
define|#
directive|define
name|PCIC_CDRES_EN
value|0x10
end_define

begin_comment
comment|/* card detect resume enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_SW_CD_INT
value|0x20
end_define

begin_comment
comment|/* s/w card detect interrupt */
end_comment

begin_comment
comment|/* For Misc. Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|PCIC_SPKR_EN
value|0x10
end_define

begin_comment
comment|/* Cirrus PD672x: speaker enable */
end_comment

begin_comment
comment|/* For Global Control register (PCIC_GLO_CTRL) */
end_comment

begin_define
define|#
directive|define
name|PCIC_PWR_DOWN
value|0x01
end_define

begin_comment
comment|/* power down */
end_comment

begin_define
define|#
directive|define
name|PCIC_LVL_MODE
value|0x02
end_define

begin_comment
comment|/* level mode interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_WB_CSCINT
value|0x04
end_define

begin_comment
comment|/* explicit write-back csc intr */
end_comment

begin_define
define|#
directive|define
name|PCIC_IRQ0_LEVEL
value|0x08
end_define

begin_comment
comment|/* irq 14 pulse mode enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_IRQ1_LEVEL
value|0x10
end_define

begin_comment
comment|/* For Misc. Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|PCIC_LPDM_EN
value|0x02
end_define

begin_comment
comment|/* Cirrus PD672x: low power dynamic mode */
end_comment

begin_comment
comment|/*  *	Mask of allowable interrupts.  *	Ints are 3,4,5,7,9,10,11,12,14,15  */
end_comment

begin_define
define|#
directive|define
name|PCIC_INT_MASK_ALLOWED
value|0xDEB8
end_define

begin_define
define|#
directive|define
name|PCIC_IO_WIN
value|2
end_define

begin_define
define|#
directive|define
name|PCIC_MEM_WIN
value|5
end_define

begin_define
define|#
directive|define
name|PCIC_MAX_SLOTS
value|8
end_define

end_unit

