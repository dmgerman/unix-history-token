begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Scott Mitchell  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: if_xereg.h,v 1.2 1999/01/24 22:15:30 root Exp $  */
end_comment

begin_comment
comment|/*  * Register definitions for Xircom CreditCard Ethernet adapters.  See if_xe.c  * for details of supported hardware.  Adapted from Werner Koch's 'xirc2ps'  * driver for Linux.  */
end_comment

begin_include
include|#
directive|include
file|"xe.h"
end_include

begin_if
if|#
directive|if
name|NXE
operator|>
literal|0
end_if

begin_comment
comment|/*  * Common registers  */
end_comment

begin_define
define|#
directive|define
name|XE_CR
value|0
end_define

begin_comment
comment|/* Command register (write) */
end_comment

begin_define
define|#
directive|define
name|XE_ESR
value|0
end_define

begin_comment
comment|/* Ethernet status register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_PSR
value|1
end_define

begin_comment
comment|/* Page select register */
end_comment

begin_define
define|#
directive|define
name|XE_EDP
value|4
end_define

begin_comment
comment|/* Ethernet data port */
end_comment

begin_define
define|#
directive|define
name|XE_ISR
value|6
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_comment
comment|/*  * Command register values  */
end_comment

begin_define
define|#
directive|define
name|XE_CR_TX_PACKET
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_CR_SOFT_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_CR_ENABLE_INTR
value|0x04
end_define

begin_define
define|#
directive|define
name|XE_CR_FORCE_INTR
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_CR_CLEAR_FIFO
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_CR_CLEAR_OVERRUN
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_CR_RESTART_TX
value|0x40
end_define

begin_comment
comment|/*  * Status register values  */
end_comment

begin_define
define|#
directive|define
name|XE_ESR_FULL_PKT_RX
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_ESR_PKT_REJECT
value|0x04
end_define

begin_define
define|#
directive|define
name|XE_ESR_TX_PENDING
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_ESR_BAD_POLARITY
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_ESR_MEDIA_SELECT
value|0x20
end_define

begin_comment
comment|/*  * Interrupt register values  */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_TX_OVERFLOW
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_ISR_TX_PACKET
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_ISR_MAC_INTR
value|0x04
end_define

begin_define
define|#
directive|define
name|XE_ISR_TX_RES
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_ISR_RX_PACKET
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_ISR_RX_REJECT
value|0x40
end_define

begin_define
define|#
directive|define
name|XE_ISR_FORCE_INTR
value|0x80
end_define

begin_comment
comment|/*  * Page 0 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_TSO
value|8
end_define

begin_comment
comment|/* Transmit space open */
end_comment

begin_define
define|#
directive|define
name|XE_TRS
value|10
end_define

begin_comment
comment|/* Transmit reservation size */
end_comment

begin_define
define|#
directive|define
name|XE_DOR
value|12
end_define

begin_comment
comment|/* Data offset register (write) */
end_comment

begin_define
define|#
directive|define
name|XE_RSR
value|12
end_define

begin_comment
comment|/* Receive status register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_PTR
value|13
end_define

begin_comment
comment|/* Packets transmitted register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_RBC
value|14
end_define

begin_comment
comment|/* Received byte count (read) */
end_comment

begin_comment
comment|/*  * RSR values  */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_PHYS_PKT
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_RSR_BCAST_PKT
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_RSR_LONG_PKT
value|0x04
end_define

begin_define
define|#
directive|define
name|XE_RSR_ALIGN_ERR
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_RSR_CRC_ERR
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_RSR_RX_OK
value|0x80
end_define

begin_comment
comment|/*  * Page 1 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_IMR0
value|12
end_define

begin_comment
comment|/* Interrupt mask register, part 1 */
end_comment

begin_define
define|#
directive|define
name|XE_IMR1
value|13
end_define

begin_comment
comment|/* Interrupt mask register, part 2 */
end_comment

begin_define
define|#
directive|define
name|XE_ECR
value|14
end_define

begin_comment
comment|/* Ethernet configuration register */
end_comment

begin_comment
comment|/*  * ECR values  */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_FULL_DUPLEX
value|0x04
end_define

begin_define
define|#
directive|define
name|XE_ECR_LONG_TPCABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_ECR_NO_POLCOL
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_ECR_NO_LINKPULSE
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_ECR_NO_AUTOTX
value|0x40
end_define

begin_comment
comment|/*  * Page 2 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_RBS
value|8
end_define

begin_comment
comment|/* Receive buffer start */
end_comment

begin_define
define|#
directive|define
name|XE_LED
value|10
end_define

begin_comment
comment|/* LED configuration register */
end_comment

begin_define
define|#
directive|define
name|XE_MSR
value|12
end_define

begin_comment
comment|/* Mohawk specfic register (Mohawk = CE3) */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2
value|13
end_define

begin_comment
comment|/* General purpose register 2 */
end_comment

begin_comment
comment|/*  * Page 4 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0
value|8
end_define

begin_comment
comment|/* General purpose register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_GPR1
value|9
end_define

begin_comment
comment|/* General purpose register 1 */
end_comment

begin_define
define|#
directive|define
name|XE_BOV
value|10
end_define

begin_comment
comment|/* Bonding version register */
end_comment

begin_define
define|#
directive|define
name|XE_LMA
value|12
end_define

begin_comment
comment|/* Local memory address */
end_comment

begin_define
define|#
directive|define
name|XE_LMD
value|14
end_define

begin_comment
comment|/* Local memory data */
end_comment

begin_comment
comment|/*  * Page 5 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_RHS
value|10
end_define

begin_comment
comment|/* Receive host start address */
end_comment

begin_comment
comment|/*  * Page 0x40 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_OCR
value|8
end_define

begin_comment
comment|/* The Other command register */
end_comment

begin_define
define|#
directive|define
name|XE_RXS0
value|9
end_define

begin_comment
comment|/* Receive status 0 */
end_comment

begin_define
define|#
directive|define
name|XE_TXS0
value|11
end_define

begin_comment
comment|/* Transmit status 0 */
end_comment

begin_define
define|#
directive|define
name|XE_TXS1
value|12
end_define

begin_comment
comment|/* Transmit status 1 */
end_comment

begin_define
define|#
directive|define
name|XE_RXM0
value|13
end_define

begin_comment
comment|/* Receive mask register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_TXM0
value|14
end_define

begin_comment
comment|/* Transmit mask register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_TXM1
value|15
end_define

begin_comment
comment|/* Transmit mask register 1 */
end_comment

begin_comment
comment|/*  * OCR values  */
end_comment

begin_define
define|#
directive|define
name|XE_OCR_TX
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_OCR_RX_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|XE_OCR_RX_DISABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_OCR_ABORT
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_OCR_ONLINE
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_OCR_ACK_INTR
value|0x40
end_define

begin_define
define|#
directive|define
name|XE_OCR_OFFLINE
value|0x80
end_define

begin_comment
comment|/*  * Page 0x42 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_SWC0
value|8
end_define

begin_comment
comment|/* Software configuration register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1
value|9
end_define

begin_comment
comment|/* Software configuration register 1 */
end_comment

begin_define
define|#
directive|define
name|XE_BOC
value|10
end_define

begin_comment
comment|/* Back-off configuration */
end_comment

begin_comment
comment|/*  * Page 0x44 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_TDR0
value|8
end_define

begin_comment
comment|/* Time domain reflectometry register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_TDR1
value|9
end_define

begin_comment
comment|/* Time domain reflectometry register 1 */
end_comment

begin_define
define|#
directive|define
name|XE_RXC0
value|10
end_define

begin_comment
comment|/* Receive byte count low */
end_comment

begin_define
define|#
directive|define
name|XE_RXC1
value|11
end_define

begin_comment
comment|/* Receive byte count high */
end_comment

begin_comment
comment|/*  * Page 0x45 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_REV
value|15
end_define

begin_comment
comment|/* Revision (read) */
end_comment

begin_comment
comment|/*  * Page 0x50 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_IAR
value|8
end_define

begin_comment
comment|/* Individual address register */
end_comment

begin_comment
comment|/*  * Pages 0x43, 0x46-0x4f and 0x51-0x5e apparently don't exist.  * The remainder of 0x0-0x8 and 0x40-0x5f exist, but I have no  * idea what's on most of them.  */
end_comment

begin_comment
comment|/*  * MII/PHY defines adapted from the xl driver.  These need cleaning up a  * little if we end up using them.  */
end_comment

begin_define
define|#
directive|define
name|XE_MII_CLK
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_MII_DIR
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_MII_WRD
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_MII_RDD
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|XE_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_MII_SET
parameter_list|(
name|x
parameter_list|)
value|XE_OUTB(XE_GPR2, (XE_INB(XE_GPR2) | 0x04) | (x))
end_define

begin_define
define|#
directive|define
name|XE_MII_CLR
parameter_list|(
name|x
parameter_list|)
value|XE_OUTB(XE_GPR2, (XE_INB(XE_GPR2) | 0x04)& ~(x))
end_define

begin_define
define|#
directive|define
name|XL_PHY_GENCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|XL_PHY_GENSTS
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_PHY_VENID
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_PHY_DEVID
value|0x03
end_define

begin_define
define|#
directive|define
name|XL_PHY_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_PHY_LPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|XL_PHY_ANER
value|0x06
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_NEXTPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD0
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_TLRFLT
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD1
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD2
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD3
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BT4
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXFULL
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXHALF
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTFULL
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTHALF
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO4
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO3
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO2
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO0
value|0x0001
end_define

begin_comment
comment|/*  * PHY BMCR Basic Mode Control Register  */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_LOOPBK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_SPEEDSEL
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD0
value|0x0800
end_define

begin_comment
comment|/* write as zero */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_ISOLATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGRSTR
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_COLLTEST
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD1
value|0x0040
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD2
value|0x0020
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD3
value|0x0010
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD4
value|0x0008
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD5
value|0x0004
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD6
value|0x0002
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD7
value|0x0001
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_comment
comment|/*   * PHY, BMSR Basic Mode Status Register   */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BT4
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXFULL
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXHALF
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTFULL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTHALF
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD1
value|0x0400
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD2
value|0x0200
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD3
value|0x0100
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD4
value|0x0080
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_MFPRESUP
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_AUTONEGCOMP
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_REMFAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_CANAUTONEG
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_LINKSTAT
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_JABBER
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_EXTENDED
value|0x0001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NXE> 0 */
end_comment

end_unit

