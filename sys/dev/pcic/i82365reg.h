begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: i82365reg.h,v 1.3 1998/12/20 17:53:28 nathanw Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Marc Horowitz.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Horowitz.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * All information is from the intel 82365sl PC Card Interface Controller  * (PCIC) data sheet, marked "preliminary".  Order number 290423-002, January  * 1993.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_IOSIZE
value|2
end_define

begin_define
define|#
directive|define
name|PCIC_REG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|PCIC_REG_DATA
value|1
end_define

begin_comment
comment|/*  * I/o ports  */
end_comment

begin_define
define|#
directive|define
name|PCIC_INDEX0
value|0x3e0
end_define

begin_comment
comment|/*  * The PCIC allows two chips to share the same address.  In order not to run  * afoul of the netbsd device model, this driver will treat those chips as  * the same device.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_CHIP0_BASE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_CHIP1_BASE
value|0x80
end_define

begin_comment
comment|/* Each PCIC chip can drive two sockets */
end_comment

begin_define
define|#
directive|define
name|PCIC_SOCKETA_INDEX
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_SOCKETB_INDEX
value|0x40
end_define

begin_comment
comment|/* general setup registers */
end_comment

begin_define
define|#
directive|define
name|PCIC_IDENT
value|0x00
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|PCIC_IDENT_IFTYPE_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_IFTYPE_IO_ONLY
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_IFTYPE_MEM_ONLY
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_IFTYPE_MEM_AND_IO
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_IFTYPE_RESERVED
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_ZERO
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_REV_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_REV_I82365SLR0
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_IDENT_REV_I82365SLR1
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS
value|0x01
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_GPI
value|0x80
end_define

begin_comment
comment|/* General Purpose Input */
end_comment

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_POWERACTIVE
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_READY
value|0x20
end_define

begin_comment
comment|/* really READY/!BUSY */
end_comment

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_MEM_WP
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_CARDDETECT_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_CARDDETECT_PRESENT
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_BATTERY_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_BATTERY_DEAD1
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_BATTERY_DEAD2
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_BATTERY_WARNING
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_IF_STATUS_BATTERY_GOOD
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL
value|0x02
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_PWRCTL_OE
value|0x80
end_define

begin_comment
comment|/* output enable */
end_comment

begin_define
define|#
directive|define
name|PCIC_PWRCTL_DISABLE_RESETDRV
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_AUTOSWITCH_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_PWR_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP2_MASK
value|0x0C
end_define

begin_comment
comment|/* XXX these are a little unclear from the data sheet */
end_comment

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP2_RESERVED
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP2_EN1
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP2_EN0
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP2_ENX
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP1_MASK
value|0x03
end_define

begin_comment
comment|/* XXX these are a little unclear from the data sheet */
end_comment

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP1_RESERVED
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP1_EN1
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP1_EN0
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_PWRCTL_VPP1_ENX
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_CSC
value|0x04
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_CSC_ZERO
value|0xE0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_GPI
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_CD
value|0x08
end_define

begin_comment
comment|/* Card Detect Change */
end_comment

begin_define
define|#
directive|define
name|PCIC_CSC_READY
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_BATTWARN
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_BATTDEAD
value|0x01
end_define

begin_comment
comment|/* for memory cards */
end_comment

begin_define
define|#
directive|define
name|PCIC_CSC_RI
value|0x01
end_define

begin_comment
comment|/* for i/o cards */
end_comment

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE
value|0x06
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_IO1
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_IO0
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_MEMCS16
value|0x20
end_define

begin_comment
comment|/* rtfds if you care */
end_comment

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_MEM4
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_MEM3
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_MEM2
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_MEM1
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_ADDRWIN_ENABLE_MEM0
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT
value|0x16
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT_RESERVED
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT_SW_INTR
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT_RESUME_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT_GPI_TRANSCTL
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT_GPI_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT_CFGRST_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_CARD_DETECT_MEMDLY_INHIBIT
value|0x01
end_define

begin_comment
comment|/* interrupt registers */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTR
value|0x03
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTR_RI_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_RESET
value|0x40
end_define

begin_comment
comment|/* active low (zero) */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTR_CARDTYPE_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_CARDTYPE_IO
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_CARDTYPE_MEM
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_RESERVED1
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_RESERVED2
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ3
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ4
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ5
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_RESERVED6
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ7
value|0x07
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_RESERVED8
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ9
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ10
value|0x0A
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ11
value|0x0B
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ12
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_RESERVED13
value|0x0D
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ14
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ15
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCIC_INTR_IRQ_VALIDMASK
value|0xDEB8
end_define

begin_comment
comment|/* 1101 1110 1011 1000 */
end_comment

begin_define
define|#
directive|define
name|PCIC_CSC_INTR
value|0x05
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_RESERVED1
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_RESERVED2
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ3
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ4
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ5
value|0x50
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_RESERVED6
value|0x60
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ7
value|0x70
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_RESERVED8
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ9
value|0x90
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ10
value|0xA0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ11
value|0xB0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ12
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_RESERVED13
value|0xD0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ14
value|0xE0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ15
value|0xF0
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_CD_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_READY_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_BATTWARN_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_BATTDEAD_ENABLE
value|0x01
end_define

begin_comment
comment|/* for memory cards */
end_comment

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_RI_ENABLE
value|0x01
end_define

begin_comment
comment|/* for I/O cards */
end_comment

begin_define
define|#
directive|define
name|PCIC_CSC_INTR_IRQ_VALIDMASK
value|0xDEB8
end_define

begin_comment
comment|/* 1101 1110 1011 1000 */
end_comment

begin_comment
comment|/* I/O registers */
end_comment

begin_define
define|#
directive|define
name|PCIC_IO_WINS
value|2
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL
value|0x07
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_WAITSTATE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_ZEROWAIT
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_IOCS16SRC_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_IOCS16SRC_CARD
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_IOCS16SRC_DATASIZE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_DATASIZE_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_DATASIZE_16BIT
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO1_DATASIZE_8BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_WAITSTATE
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_ZEROWAIT
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_IOCS16SRC_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_IOCS16SRC_CARD
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_IOCS16SRC_DATASIZE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_DATASIZE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_DATASIZE_16BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_IOCTL_IO0_DATASIZE_8BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR0_START_LSB
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR0_START_MSB
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR0_STOP_LSB
value|0x0A
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR0_STOP_MSB
value|0x0B
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR1_START_LSB
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR1_START_MSB
value|0x0D
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR1_STOP_LSB
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCIC_IOADDR1_STOP_MSB
value|0x0F
end_define

begin_comment
comment|/* memory registers */
end_comment

begin_comment
comment|/*  * memory window addresses refer to bits A23-A12 of the ISA system memory  * address.  This is a shift of 12 bits.  The LSB contains A19-A12, and the  * MSB contains A23-A20, plus some other bits.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_MEM_WINS
value|5
end_define

begin_define
define|#
directive|define
name|PCIC_MEM_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PCIC_MEM_PAGESIZE
value|(1<<PCIC_MEM_SHIFT)
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_SHIFT
value|PCIC_MEM_SHIFT
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_START_MSB_DATASIZE_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_START_MSB_DATASIZE_16BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_START_MSB_DATASIZE_8BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_START_MSB_ZEROWAIT
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_START_MSB_SCRATCH_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_START_MSB_ADDR_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_STOP_MSB_WAIT_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_STOP_MSB_WAIT0
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_STOP_MSB_WAIT1
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_STOP_MSB_WAIT2
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_STOP_MSB_WAIT3
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDRX_STOP_MSB_ADDR_MASK
value|0x0F
end_define

begin_comment
comment|/*  * The card side of a memory mapping consists of bits A19-A12 of the card  * memory address in the LSB, and A25-A20 plus some other bits in the MSB.  * Again, the shift is 12 bits.  */
end_comment

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDRX_SHIFT
value|PCIC_MEM_SHIFT
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDRX_MSB_WP
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDRX_MSB_REGACTIVE_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDRX_MSB_REGACTIVE_ATTR
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDRX_MSB_REGACTIVE_COMMON
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDRX_MSB_ADDR_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR0_START_LSB
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR0_START_MSB
value|0x11
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR0_STOP_LSB
value|0x12
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR0_STOP_MSB
value|0x13
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR0_LSB
value|0x14
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR0_MSB
value|0x15
end_define

begin_comment
comment|/* #define	PCIC_RESERVED			0x17 */
end_comment

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR1_START_LSB
value|0x18
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR1_START_MSB
value|0x19
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR1_STOP_LSB
value|0x1A
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR1_STOP_MSB
value|0x1B
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR1_LSB
value|0x1C
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR1_MSB
value|0x1D
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR2_START_LSB
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR2_START_MSB
value|0x21
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR2_STOP_LSB
value|0x22
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR2_STOP_MSB
value|0x23
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR2_LSB
value|0x24
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR2_MSB
value|0x25
end_define

begin_comment
comment|/* #define	PCIC_RESERVED			0x26 */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x27 */
end_comment

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR3_START_LSB
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR3_START_MSB
value|0x29
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR3_STOP_LSB
value|0x2A
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR3_STOP_MSB
value|0x2B
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR3_LSB
value|0x2C
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR3_MSB
value|0x2D
end_define

begin_comment
comment|/* #define	PCIC_RESERVED			0x2E */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x2F */
end_comment

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR4_START_LSB
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR4_START_MSB
value|0x31
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR4_STOP_LSB
value|0x32
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR4_STOP_MSB
value|0x33
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR4_LSB
value|0x34
end_define

begin_define
define|#
directive|define
name|PCIC_CARDMEM_ADDR4_MSB
value|0x35
end_define

begin_comment
comment|/* #define	PCIC_RESERVED			0x36 */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x37 */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x38 */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x39 */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x3A */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x3B */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x3C */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x3D */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x3E */
end_comment

begin_comment
comment|/* #define	PCIC_RESERVED			0x3F */
end_comment

begin_comment
comment|/* cardbus extensions - memory window page registers */
end_comment

begin_define
define|#
directive|define
name|PCIC_MEMREG_WIN_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR0_WIN
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR1_WIN
value|0x41
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR2_WIN
value|0x42
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR3_WIN
value|0x43
end_define

begin_define
define|#
directive|define
name|PCIC_SYSMEM_ADDR4_WIN
value|0x44
end_define

begin_comment
comment|/* vendor-specific registers */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTEL_GLOBAL_CTL
value|0x1E
end_define

begin_comment
comment|/* RW */
end_comment

begin_define
define|#
directive|define
name|PCIC_INTEL_GLOBAL_CTL_RESERVED
value|0xF0
end_define

begin_define
define|#
directive|define
name|PCIC_INTEL_GLOBAL_CTL_IRQ14PULSE_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIC_INTEL_GLOBAL_CTL_EXPLICIT_CSC_ACK
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_INTEL_GLOBAL_CTL_IRQLEVEL_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIC_INTEL_GLOBAL_CTL_POWERDOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_MISC_CTL_2
value|0x1E
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_MISC_CTL_2_SUSPEND
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_CHIP_INFO
value|0x1F
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_CHIP_INFO_CHIP_ID
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_CHIP_INFO_SLOTS
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_CHIP_INFO_REV
value|0x1F
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_EXTENDED_INDEX
value|0x2E
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_EXTENDED_DATA
value|0x2F
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_EXT_CONTROL_1
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIC_CIRRUS_EXT_CONTROL_1_PCI_INTR_MASK
value|0x18
end_define

begin_comment
comment|/* Plug and play */
end_comment

begin_define
define|#
directive|define
name|PCIC_PNP_ACTIONTEC
value|0x1802A904
end_define

begin_comment
comment|/* AEI0218 */
end_comment

begin_define
define|#
directive|define
name|PCIC_PNP_IBM3765
value|0x65374d24
end_define

begin_comment
comment|/* IBM3765 */
end_comment

begin_define
define|#
directive|define
name|PCIC_PNP_82365
value|0x000ED041
end_define

begin_comment
comment|/* PNP0E00 */
end_comment

begin_define
define|#
directive|define
name|PCIC_PNP_CL_PD6720
value|0x010ED041
end_define

begin_comment
comment|/* PNP0E01 */
end_comment

begin_define
define|#
directive|define
name|PCIC_PNP_VLSI_82C146
value|0x020ED041
end_define

begin_comment
comment|/* PNP0E02 */
end_comment

begin_define
define|#
directive|define
name|PCIC_PNP_82365_CARDBUS
value|0x030ED041
end_define

begin_comment
comment|/* PNP0E03 */
end_comment

begin_define
define|#
directive|define
name|PCIC_PNP_SCM_SWAPBOX
value|0x69046d4c
end_define

begin_comment
comment|/* SMC0469 */
end_comment

begin_comment
comment|/* C-Bus PnP Definitions */
end_comment

begin_define
define|#
directive|define
name|PCIC_NEC_PC9801_102
value|0x9180a3b8
end_define

begin_comment
comment|/* NEC8091 PC-9801-102 */
end_comment

begin_define
define|#
directive|define
name|PCIC_NEC_PC9821RA_E01
value|0x2181a3b8
end_define

begin_comment
comment|/* NEC8121 PC-9821RA-E01 */
end_comment

end_unit

