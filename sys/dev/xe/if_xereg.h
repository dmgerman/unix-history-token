begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Scott Mitchell  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: if_xereg.h,v 1.5 1999/05/20 21:53:58 scott Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_XE_IF_XEREG_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_XE_IF_XEREG_H
end_define

begin_comment
comment|/*  * Register definitions for Xircom PCMCIA Ethernet controllers, based on  * Rev. B of the "Dingo" 10/100 controller used in Xircom CEM56 and RealPort  * Ethernet/modem cards.  The Dingo can be configured to be register  * compatible with the "Mohawk" 10/100 controller used in Xircom CE3 cards  * (also some Intel and Compaq OEM versions of the CE3).  The older 10Mbps CE2  * cards seem to use earlier revisions of the same device.  Some registers and  * bits below are marked 'CE2 only'; these are used by Werner Koch's xirc2ps  * driver that was originally for the CE2 but, according to the spec, aren't  * present on the Dingo.  They often seem to relate to operation on coax  * cables, which Mohawk can do in theory (it has the SSI interface) so they  * _might_ also work on Mohawk. I've also noted the few registers that are  * specific to Dingo.  *  * As far as I can tell, the Dingo is basically a Mohawk device with a few  * registers and support for a second PCMCIA function (the modem) added.  In  * Dingo mode the SSI (non-MII) PHY interface of the Mohawk is not available.  * The CE2 chip is most likely a Mohawk without the MII and definitely with a  * slightly different register set.  *  * In all cases, the controller uses a paged model of register access.  The  * first eight registers are always the same, the function of the second eight   * is selected by the value in the Page Register (reg 0x01).  *  * References:  * 1. Dingo External Reference Specification, Revision B.  Xircom Inc.,  *    Thousand Oaks, California.  August 1998.  Available under licence from  *    Xircom, http://www.xircom.com/  * 2. ML6692 100BASE-TX Physical Layer with MII specification.  MicroLinear  *    Corp, San Jose, California.  May 1997.  Available for download from  *    http://www.microlinear.com/  * 3. DP83840 10/100 Mb/s Ethernet Physical Layer specification.  National  *    Semiconductor Corp., Arlington, Texas.  March 1997.  Available for  *    download from http://www.ns.com/  * 4. Werner Koch's xirc2ps driver for Linux, for all the CE2 and CE3 frobs  *    that aren't documented in the Xircom spec.  Available for download from  *    http://www.d.shuttle.de/isil/xircom/xirc2ps.html  */
end_comment

begin_comment
comment|/*******************  * PCMCIA registers  *******************/
end_comment

begin_comment
comment|/*  * These are probably Dingo-specific, but you won't need them unless you have  * a CEM card that needs a bit of hackery to get the Ethernet function to  * operate.  All addresses are in card attribute space.  */
end_comment

begin_define
define|#
directive|define
name|DINGO_CIS
value|0x0000
end_define

begin_comment
comment|/* Start of CIS tuples */
end_comment

begin_define
define|#
directive|define
name|DINGO_ETH
value|0x0800
end_define

begin_comment
comment|/* Ethernet configuration registers */
end_comment

begin_define
define|#
directive|define
name|DINGO_COR
value|0x0820
end_define

begin_comment
comment|/* Dingo configuration option registers */
end_comment

begin_define
define|#
directive|define
name|DINGO_2ND
value|0x0840
end_define

begin_comment
comment|/* 2nd function configuration registers */
end_comment

begin_comment
comment|/*  * Ethernet configuration registers  */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR
value|(DINGO_ETH+0)
end_define

begin_comment
comment|/* Ethernet Configuration Option Register */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECSR
value|(DINGO_ETH+2)
end_define

begin_comment
comment|/* Ethernet Configuration Status Register */
end_comment

begin_define
define|#
directive|define
name|DINGO_EBAR0
value|(DINGO_ETH+10)
end_define

begin_comment
comment|/* Ethernet Base Address Register bits 7:4 (3:0 always 0) */
end_comment

begin_define
define|#
directive|define
name|DINGO_EBAR1
value|(DINGO_ETH+12)
end_define

begin_comment
comment|/* Ethernet Base Address Register bits 15:8 */
end_comment

begin_comment
comment|/* DINGO_ECOR bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR_ETH_ENABLE
value|0x01
end_define

begin_comment
comment|/* 1 = Enable Ethernet part of adapter */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR_IOB_ENABLE
value|0x02
end_define

begin_comment
comment|/* 1 = Enable EBAR, else use INDEX bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR_INT_ENABLE
value|0x04
end_define

begin_comment
comment|/* 1 = Enable Ethernet interrupts */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR_IOB_INDEX
value|0x18
end_define

begin_comment
comment|/* 00 = 0x300; 01 = 0x310; 10 = 0x320; 11 = no IO base */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR_IOB_SHIFT
value|0x03
end_define

begin_define
define|#
directive|define
name|DINGO_ECOR_IRQ_STSCHG
value|0x20
end_define

begin_comment
comment|/* 1 = Route interrupts to -STSCHG pin, else use -INT pin */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR_IRQ_LEVEL
value|0x40
end_define

begin_comment
comment|/* 1 = Level-triggered interrupts, else edge-triggered */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECOR_SRESET
value|0x80
end_define

begin_comment
comment|/* 1 = Soft reset Ethernet adpater.  Must write to 0 */
end_comment

begin_comment
comment|/* DINGO_ECSR bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECSR_INT_ACK
value|0x01
end_define

begin_comment
comment|/* 1 = Host must acknowledge interrupts (Clear ECSR_INT bit) */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECSR_INT
value|0x02
end_define

begin_comment
comment|/* 1 = Interrupt service requested */
end_comment

begin_define
define|#
directive|define
name|DINGO_ECSR_POWER_DOWN
value|0x04
end_define

begin_comment
comment|/* 1 = Power down Ethernet adapter */
end_comment

begin_comment
comment|/*  * EBAR0/EBAR1 set the I/O base address of the Ethernet adapter when  * ECOR_IOB_ENABLE is set.  12 significant bits.  */
end_comment

begin_comment
comment|/*  * Dingo configuration registers  */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0
value|(DINGO_COR+0)
end_define

begin_comment
comment|/* Dingo Configuration Options Register 0 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1
value|(DINGO_COR+2)
end_define

begin_comment
comment|/* Dingo Configuration Options Register 1 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR2
value|(DINGO_COR+4)
end_define

begin_comment
comment|/* Dingo Configuration Options Register 2 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR3
value|(DINGO_COR+6)
end_define

begin_comment
comment|/* Dingo Configuration Options Register 3 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR4
value|(DINGO_COR+8)
end_define

begin_comment
comment|/* Dingo Configuration Options Register 4 */
end_comment

begin_comment
comment|/* DINGO_DCOR0 bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0_SF_INT
value|0x01
end_define

begin_comment
comment|/* 1 = Enable 2ndF interrupts (alternate to SFCOR:2) */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0_DECODE
value|0x04
end_define

begin_comment
comment|/* 1 = Decode 2ndF interrupts in Dingo, else in 2ndF */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0_BUS
value|0x08
end_define

begin_comment
comment|/* 1 = 2ndF bus is ISA, else PCMCIA */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0_LED3_POWER
value|0x10
end_define

begin_comment
comment|/* 1 = Drive LED3 line from SFCSR:2 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0_LED3_RESET
value|0x20
end_define

begin_comment
comment|/* 1 = Drive LED3 line from SFCOR:7 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0_MR_POWER
value|0x40
end_define

begin_comment
comment|/* 1 = Drive MRESET line from SFCSR:2 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR0_MR_RESET
value|0x80
end_define

begin_comment
comment|/* 1 = Drive MRESET line from SFCOR:7 */
end_comment

begin_comment
comment|/* DINGO_DCOR1 bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_INT_STSCHG
value|0x01
end_define

begin_comment
comment|/* 1 = Route 2ndF interrupts to -STSCHG (alternate to SFCOR:5) */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_MSTSCHG
value|0x02
end_define

begin_comment
comment|/* 1 = Route 2ndF -MSTSCHG line to -STSCHG */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_EEDIO
value|0x04
end_define

begin_comment
comment|/* 1 = Use EEDIO pin as data line 6 to 2ndF */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_INT_LEVEL
value|0x08
end_define

begin_comment
comment|/* 1 = Force level-triggered interrupts from 2ndF */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_SHADOW_CSR
value|0x10
end_define

begin_comment
comment|/* Reserved, always write 0 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_SHADOW_IOB
value|0x20
end_define

begin_comment
comment|/* Reserved, always write 0 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_CSR_WAIT
value|0xC0
end_define

begin_comment
comment|/* Reserved, always write 0 */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR1_CSR_SHIFT
value|0x06
end_define

begin_comment
comment|/* DINGO_DCOR2 bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR2_SHM_BASE
value|0x0f
end_define

begin_comment
comment|/* Bits 15-12 of Ethernet shared memory window */
end_comment

begin_define
define|#
directive|define
name|DINGO_DCOR2_SHM_SHIFT
value|0x00
end_define

begin_define
define|#
directive|define
name|DINGO_DCOR2_SHADOW_COR
value|0x10
end_define

begin_comment
comment|/* Reserved, always write 0 */
end_comment

begin_comment
comment|/*  * DCOR3/DCOR4 configure Dingo to assert -IOIS16 on any access to each pair of   * ports in the range SFIOB+0 .. SFIOB+31.  Each pair can be set individually,  * eg. DCOR3:0 enables this function on ports SFIOB+0 and SFIOB+1.  */
end_comment

begin_comment
comment|/*  * Second function configuration registers  */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR
value|(DINGO_2ND+0)
end_define

begin_comment
comment|/* 2nd Function Configuration Option Register */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCSR
value|(DINGO_2ND+2)
end_define

begin_comment
comment|/* 2nd Function Configuration Status Register */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFBAR0
value|(DINGO_2ND+10)
end_define

begin_comment
comment|/* 2nd Function Base Address Register bits 7:0 */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFBAR1
value|(DINGO_2ND+12)
end_define

begin_comment
comment|/* 2nd Function Base Address Register bits 15:8 */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFILR
value|(DINGO_2ND+18)
end_define

begin_comment
comment|/* 2nd Function I/O Limit Register */
end_comment

begin_comment
comment|/* DINGO_SFCOR bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR_SF_ENABLE
value|0x01
end_define

begin_comment
comment|/* 1 = Enable second fuction */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR_IOB_ENABLE
value|0x02
end_define

begin_comment
comment|/* 1 = Enable SFBAR, else use COM_SELECT bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR_INT_ENABLE
value|0x04
end_define

begin_comment
comment|/* 1 = Enable second function interrupts */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR_COM_SELECT
value|0x18
end_define

begin_comment
comment|/* 00 = 0x3f8; 01 = 0x2f8; 10 = 0x3e8; 11 = 0x2e8 */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR_COM_SHIFT
value|0x03
end_define

begin_define
define|#
directive|define
name|DINGO_SFCOR_IRQ_STSCHG
value|0x20
end_define

begin_comment
comment|/* 1 = Route interrupts to -STSCHG pin, else use -INT pin */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR_IRQ_LEVEL
value|0x40
end_define

begin_comment
comment|/* 1 = Level-triggered interrupts, else edge-triggered */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCOR_SRESET
value|0x80
end_define

begin_comment
comment|/* 1 = Soft reset second function.  Must write to 0 */
end_comment

begin_comment
comment|/* DINGO_SFCSR bits */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCSR_INT_ACK
value|0x01
end_define

begin_comment
comment|/* 1 = Host must acknowledge interrupts (Clear SFCSR_INT bit) */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCSR_INT
value|0x02
end_define

begin_comment
comment|/* 1 = Interrupt service requested */
end_comment

begin_define
define|#
directive|define
name|DINGO_SFCSR_POWER_DOWN
value|0x04
end_define

begin_comment
comment|/* 1 = Power down second function */
end_comment

begin_comment
comment|/*  * SFBAR0/SFBAR1 set the I/O base address of the second function when  * SFCOR_IOB_ENABLE is set.  16 significant bits.  */
end_comment

begin_comment
comment|/*  * SFILR is a bitmap of address lines 7:0 decoded by the second function  * device.  Eg. a device with 16 ports should write 0x0f to this register.  */
end_comment

begin_comment
comment|/********************************  * Ethernet controller registers  ********************************/
end_comment

begin_comment
comment|/*  * Common registers (available from any register page)  *  * Note: The EDP is actually 32 bits wide, occupying registers 2-5.  In PCMCIA   * operation we can only access 16 bits at once, through registers 4& 5.  */
end_comment

begin_define
define|#
directive|define
name|XE_CR
value|0x00
end_define

begin_comment
comment|/* Command register (write) */
end_comment

begin_define
define|#
directive|define
name|XE_ESR
value|0x00
end_define

begin_comment
comment|/* Ethernet status register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_PR
value|0x01
end_define

begin_comment
comment|/* Page select register */
end_comment

begin_define
define|#
directive|define
name|XE_EDP
value|0x04
end_define

begin_comment
comment|/* Ethernet data port */
end_comment

begin_define
define|#
directive|define
name|XE_ISR
value|0x06
end_define

begin_comment
comment|/* Ethernet interrupt status register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_GIR
value|0x07
end_define

begin_comment
comment|/* Global interrupt register (Dingo only) */
end_comment

begin_comment
comment|/* XE_CR bits */
end_comment

begin_define
define|#
directive|define
name|XE_CR_TX_PACKET
value|0x01
end_define

begin_comment
comment|/* Transmit packet */
end_comment

begin_define
define|#
directive|define
name|XE_CR_SOFT_RESET
value|0x02
end_define

begin_comment
comment|/* Software reset */
end_comment

begin_define
define|#
directive|define
name|XE_CR_ENABLE_INTR
value|0x04
end_define

begin_comment
comment|/* Enable interrupts */
end_comment

begin_define
define|#
directive|define
name|XE_CR_FORCE_INTR
value|0x08
end_define

begin_comment
comment|/* Force an interrupt */
end_comment

begin_define
define|#
directive|define
name|XE_CR_CLEAR_FIFO
value|0x10
end_define

begin_comment
comment|/* Clear FIFO after transmit overrun */
end_comment

begin_define
define|#
directive|define
name|XE_CR_CLEAR_OVERRUN
value|0x20
end_define

begin_comment
comment|/* Clear receive overrun condition */
end_comment

begin_define
define|#
directive|define
name|XE_CR_RESTART_TX
value|0x40
end_define

begin_comment
comment|/* Restart TX after 16 collisions or TX underrun */
end_comment

begin_comment
comment|/* XE_ESR bits */
end_comment

begin_define
define|#
directive|define
name|XE_ESR_FULL_PACKET_RX
value|0x01
end_define

begin_comment
comment|/* At least one full packet received */
end_comment

begin_define
define|#
directive|define
name|XE_ESR_PART_PACKET_RX
value|0x02
end_define

begin_comment
comment|/* At least 64 bytes of packet received */
end_comment

begin_define
define|#
directive|define
name|XE_ESR_REJECT_PACKET
value|0x04
end_define

begin_comment
comment|/* Partial packet rejected */
end_comment

begin_define
define|#
directive|define
name|XE_ESR_TX_PENDING
value|0x08
end_define

begin_comment
comment|/* At least one packet waiting to transmit */
end_comment

begin_define
define|#
directive|define
name|XE_ESR_BAD_POLARITY
value|0x10
end_define

begin_comment
comment|/* Bad cable polarity? (CE2 only) */
end_comment

begin_define
define|#
directive|define
name|XE_ESR_MEDIA_SELECT
value|0x20
end_define

begin_comment
comment|/* SSI(?) media select: 1 = Twisted pair; 0 = AUI */
end_comment

begin_comment
comment|/* XE_ISR bits */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_TX_OVERFLOW
value|0x01
end_define

begin_comment
comment|/* No space in transmit buffer */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_TX_PACKET
value|0x02
end_define

begin_comment
comment|/* Packet sent successfully */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_MAC_INTR
value|0x04
end_define

begin_comment
comment|/* Some kind of MAC interrupt happened */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_RX_EARLY
value|0x10
end_define

begin_comment
comment|/* Incoming packet in early receive mode */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_RX_PACKET
value|0x20
end_define

begin_comment
comment|/* Complete packet received successfully */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_RX_REJECT
value|0x40
end_define

begin_comment
comment|/* Partial incoming packet rejected by MAC */
end_comment

begin_define
define|#
directive|define
name|XE_ISR_FORCE_INTR
value|0x80
end_define

begin_comment
comment|/* Interrupt forced */
end_comment

begin_comment
comment|/* XE_GIR bits */
end_comment

begin_define
define|#
directive|define
name|XE_GIR_ETH_IRQ
value|0x01
end_define

begin_comment
comment|/* Ethernet IRQ pending */
end_comment

begin_define
define|#
directive|define
name|XE_GIR_ETH_MASK
value|0x02
end_define

begin_comment
comment|/* 1 = Mask Ethernet interrupts to host */
end_comment

begin_define
define|#
directive|define
name|XE_GIR_SF_IRQ
value|0x04
end_define

begin_comment
comment|/* Second function IRQ pending */
end_comment

begin_define
define|#
directive|define
name|XE_GIR_SF_MASK
value|0x08
end_define

begin_comment
comment|/* 1 = Mask second function interrupts to host */
end_comment

begin_comment
comment|/*  * Page 0 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_TSO
value|0x08
end_define

begin_comment
comment|/* Transmit space open (17 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_TRS
value|0x0a
end_define

begin_comment
comment|/* Transmit reservation size (CE2 only, removed in rev. 1) */
end_comment

begin_define
define|#
directive|define
name|XE_DO
value|0x0c
end_define

begin_comment
comment|/* Data offset register (13 bits/3 flags, write) */
end_comment

begin_define
define|#
directive|define
name|XE_RSR
value|0x0c
end_define

begin_comment
comment|/* Receive status register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_TPR
value|0x0d
end_define

begin_comment
comment|/* Packets transmitted register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_RBC
value|0x0e
end_define

begin_comment
comment|/* Received byte count (13 bits/3 flags, read) */
end_comment

begin_comment
comment|/* XE_DO bits */
end_comment

begin_define
define|#
directive|define
name|XE_DO_OFFSET
value|0x1fff
end_define

begin_comment
comment|/* First byte fetched when CHANGE_OFFSET issued */
end_comment

begin_define
define|#
directive|define
name|XE_DO_OFFSET_SHIFT
value|0x00
end_define

begin_define
define|#
directive|define
name|XE_DO_CHANGE_OFFSET
value|0x2000
end_define

begin_comment
comment|/* Flush RX FIFO, start fetching from OFFSET */
end_comment

begin_define
define|#
directive|define
name|XE_DO_SHARED_MEM
value|0x4000
end_define

begin_comment
comment|/* Enable shared memory mode */
end_comment

begin_define
define|#
directive|define
name|XE_DO_SKIP_RX_PACKET
value|0x8000
end_define

begin_comment
comment|/* Skip to next packet in buffer memory */
end_comment

begin_comment
comment|/* XE_RSR bits */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_PHYS_PACKET
value|0x01
end_define

begin_comment
comment|/* 1 = Physical packet, 0 = Multicast packet */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_BCAST_PACKET
value|0x02
end_define

begin_comment
comment|/* Broadcast packet */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_LONG_PACKET
value|0x04
end_define

begin_comment
comment|/* Packet>1518 bytes */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_ADDR_MATCH
value|0x08
end_define

begin_comment
comment|/* Packet matched one of our node addresses */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_ALIGN_ERROR
value|0x10
end_define

begin_comment
comment|/* Bad alignment? (CE2 only) */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_CRC_ERROR
value|0x20
end_define

begin_comment
comment|/* Incorrect CRC */
end_comment

begin_define
define|#
directive|define
name|XE_RSR_RX_OK
value|0x80
end_define

begin_comment
comment|/* No errors on received packet */
end_comment

begin_comment
comment|/* XE_RBC bits */
end_comment

begin_define
define|#
directive|define
name|XE_RBC_BYTE_COUNT
value|0x1fff
end_define

begin_comment
comment|/* Bytes received for current packet */
end_comment

begin_define
define|#
directive|define
name|XE_RBC_COUNT_SHIFT
value|0x00
end_define

begin_define
define|#
directive|define
name|XE_RBC_FULL_PACKET_RX
value|0x2000
end_define

begin_comment
comment|/* These mirror bits 2:0 of ESR, if ECR:7 is set */
end_comment

begin_define
define|#
directive|define
name|XE_RBC_PART_PACKET_RX
value|0x4000
end_define

begin_define
define|#
directive|define
name|XE_RBC_REJECT_PACKET
value|0x8000
end_define

begin_comment
comment|/*  * Page 1 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_IMR0
value|0x0c
end_define

begin_comment
comment|/* Interrupt mask register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_IMR1
value|0x0d
end_define

begin_comment
comment|/* Interrupt mask register 1 (CE2 only) */
end_comment

begin_define
define|#
directive|define
name|XE_ECR
value|0x0e
end_define

begin_comment
comment|/* Ethernet configuration register */
end_comment

begin_comment
comment|/* XE_IMR0 bits */
end_comment

begin_define
define|#
directive|define
name|XE_IMR0_TX_OVERFLOW
value|0x01
end_define

begin_comment
comment|/* Masks for bits in ISR */
end_comment

begin_define
define|#
directive|define
name|XE_IMR0_TX_PACKET
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_IMR0_MAC_INTR
value|0x04
end_define

begin_define
define|#
directive|define
name|XE_IMR0_RX_EARLY
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_IMR0_RX_PACKET
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_IMR0_RX_REJECT
value|0x40
end_define

begin_define
define|#
directive|define
name|XE_IMR0_FORCE_INTR
value|0x80
end_define

begin_comment
comment|/* XE_ECR bits */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_EARLY_TX
value|0x01
end_define

begin_comment
comment|/* Enable early transmit mode */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_EARLY_RX
value|0x02
end_define

begin_comment
comment|/* Enable early receive mode */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_FULL_DUPLEX
value|0x04
end_define

begin_comment
comment|/* Enable full-duplex (disable collision detection) */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_LONG_TPCABLE
value|0x08
end_define

begin_comment
comment|/* CE2 only */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_NO_POL_COL
value|0x10
end_define

begin_comment
comment|/* CE2 only */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_NO_LINK_PULSE
value|0x20
end_define

begin_comment
comment|/* Don't check/send link pulses (not 10BT compliant) */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_NO_AUTO_TX
value|0x40
end_define

begin_comment
comment|/* CE2 only */
end_comment

begin_define
define|#
directive|define
name|XE_ECR_SOFT_COMPAT
value|0x80
end_define

begin_comment
comment|/* Map ESR bits 2:0 to RBC bits 15:13 */
end_comment

begin_comment
comment|/*  * Page 2 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_RBS
value|0x08
end_define

begin_comment
comment|/* Receive buffer start (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_LED
value|0x0a
end_define

begin_comment
comment|/* LED control register */
end_comment

begin_define
define|#
directive|define
name|XE_LED3
value|0x0b
end_define

begin_comment
comment|/* LED3 control register */
end_comment

begin_define
define|#
directive|define
name|XE_MSR
value|0x0c
end_define

begin_comment
comment|/* Misc. setup register (Mohawk specific register?) */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2
value|0x0d
end_define

begin_comment
comment|/* General purpose register 2 */
end_comment

begin_comment
comment|/*  * LED function selection:  * 000 - Disabled  * 001 - Collision activity  * 010 - !Collision activity  * 011 - 10Mbit link detected  * 100 - 100Mbit link detected  * 101 - 10/100Mbit link detected  * 110 - Automatic assertion  * 111 - Transmit activity  */
end_comment

begin_comment
comment|/* XE_LED bits */
end_comment

begin_define
define|#
directive|define
name|XE_LED_LED0_MASK
value|0x07
end_define

begin_comment
comment|/* LED0 function selection */
end_comment

begin_define
define|#
directive|define
name|XE_LED_LED0_SHIFT
value|0x00
end_define

begin_define
define|#
directive|define
name|XE_LED_LED1_MASK
value|0x38
end_define

begin_comment
comment|/* LED1 function selection */
end_comment

begin_define
define|#
directive|define
name|XE_LED_LED1_SHIFT
value|0x03
end_define

begin_define
define|#
directive|define
name|XE_LED_LED0_RX
value|0x40
end_define

begin_comment
comment|/* Add receive activity to LED0 */
end_comment

begin_define
define|#
directive|define
name|XE_LED_LED1_RX
value|0x80
end_define

begin_comment
comment|/* Add receive activity to LED1 */
end_comment

begin_comment
comment|/* XE_LED3 bits */
end_comment

begin_define
define|#
directive|define
name|XE_LED3_MASK
value|0x07
end_define

begin_comment
comment|/* LED3 function selection */
end_comment

begin_define
define|#
directive|define
name|XE_LED3_SHIFT
value|0x00
end_define

begin_define
define|#
directive|define
name|XE_LED3_RX
value|0x40
end_define

begin_comment
comment|/* Add receive activity to LED3 */
end_comment

begin_comment
comment|/* XE_MSR bits */
end_comment

begin_define
define|#
directive|define
name|XE_MSR_128K_SRAM
value|0x01
end_define

begin_comment
comment|/* Select 128K SRAM */
end_comment

begin_define
define|#
directive|define
name|XE_MSR_RBS_BIT16
value|0x02
end_define

begin_comment
comment|/* Bit 16 of RBS (only useful with big SRAM) */
end_comment

begin_define
define|#
directive|define
name|XE_MSR_MII_SELECT
value|0x08
end_define

begin_comment
comment|/* Select MII instead of SSI interface */
end_comment

begin_define
define|#
directive|define
name|XE_MSR_HASH_TABLE
value|0x20
end_define

begin_comment
comment|/* Enable hash table filtering */
end_comment

begin_comment
comment|/* XE_GPR2 bits */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2_GP3_OUT
value|0x01
end_define

begin_comment
comment|/* Value written to GP3 line */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2_GP4_OUT
value|0x02
end_define

begin_comment
comment|/* Value written to GP4 line */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2_GP3_SELECT
value|0x04
end_define

begin_comment
comment|/* 1 = GP3 is output, 0 = GP3 is input */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2_GP4_SELECT
value|0x08
end_define

begin_comment
comment|/* 1 = GP4 is output, 0 = GP3 is input */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2_GP3_IN
value|0x10
end_define

begin_comment
comment|/* Value read from GP3 line */
end_comment

begin_define
define|#
directive|define
name|XE_GPR2_GP4_IN
value|0x20
end_define

begin_comment
comment|/* Value read from GP4 line */
end_comment

begin_comment
comment|/*  * Page 3 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_TPT
value|0x0a
end_define

begin_comment
comment|/* Transmit packet threshold (13 bits) */
end_comment

begin_comment
comment|/*  * Page 4 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0
value|0x08
end_define

begin_comment
comment|/* General purpose register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_GPR1
value|0x09
end_define

begin_comment
comment|/* General purpose register 1 */
end_comment

begin_define
define|#
directive|define
name|XE_BOV
value|0x0a
end_define

begin_comment
comment|/* Bonding version register (read) */
end_comment

begin_define
define|#
directive|define
name|XE_EES
value|0x0b
end_define

begin_comment
comment|/* EEPROM control register */
end_comment

begin_define
define|#
directive|define
name|XE_LMA
value|0x0c
end_define

begin_comment
comment|/* Local memory address (CE2 only) */
end_comment

begin_define
define|#
directive|define
name|XE_LMD
value|0x0e
end_define

begin_comment
comment|/* Local memory data (CE2 only) */
end_comment

begin_comment
comment|/* XE_GPR0 bits */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0_GP1_OUT
value|0x01
end_define

begin_comment
comment|/* Value written to GP1 line */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0_GP2_OUT
value|0x02
end_define

begin_comment
comment|/* Value wirtten to GP2 line */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0_GP1_SELECT
value|0x04
end_define

begin_comment
comment|/* 1 = GP1 is output, 0 = GP1 is input */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0_GP2_SELECT
value|0x08
end_define

begin_comment
comment|/* 1 = GP2 is output, 0 = GP2 is input */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0_GP1_IN
value|0x10
end_define

begin_comment
comment|/* Value read from GP1 line */
end_comment

begin_define
define|#
directive|define
name|XE_GPR0_GP2_IN
value|0x20
end_define

begin_comment
comment|/* Value read from GP2 line */
end_comment

begin_comment
comment|/* XE_GPR1 bits */
end_comment

begin_define
define|#
directive|define
name|XE_GPR1_POWER_DOWN
value|0x01
end_define

begin_comment
comment|/* Power down analog section (down to 20mA load) */
end_comment

begin_comment
comment|/* XE_BOV values */
end_comment

begin_define
define|#
directive|define
name|XE_BOV_DINGO
value|0x55
end_define

begin_comment
comment|/* Dingo in Dingo mode */
end_comment

begin_define
define|#
directive|define
name|XE_BOV_MOHAWK
value|0x41
end_define

begin_comment
comment|/* Original Mohawk */
end_comment

begin_define
define|#
directive|define
name|XE_BOV_MOHAWK_REV1
value|0x45
end_define

begin_comment
comment|/* Rev. 1 Mohawk, or Dingo in Mohawk mode */
end_comment

begin_define
define|#
directive|define
name|XE_BOV_CEM28
value|0x11
end_define

begin_comment
comment|/* CEM28 */
end_comment

begin_comment
comment|/* XE_EES bits */
end_comment

begin_define
define|#
directive|define
name|XE_EES_SCL_OUTPUT
value|0x01
end_define

begin_comment
comment|/* Value written to SCL line, when MANUAL_ROM set */
end_comment

begin_define
define|#
directive|define
name|XE_EES_SDA_OUTPUT
value|0x02
end_define

begin_comment
comment|/* Value written to SDA line, when MANUAL_ROM set */
end_comment

begin_define
define|#
directive|define
name|XE_EES_SDA_INPUT
value|0x04
end_define

begin_comment
comment|/* Value read from SDA line */
end_comment

begin_define
define|#
directive|define
name|XE_EES_SDA_TRISTATE
value|0x08
end_define

begin_comment
comment|/* 1 = SDA is output, 0 = SDA is input */
end_comment

begin_define
define|#
directive|define
name|XE_EES_MANUAL_ROM
value|0x20
end_define

begin_comment
comment|/* Enable manual contro of serial EEPROM */
end_comment

begin_comment
comment|/*  * Page 5 registers (all read only)  */
end_comment

begin_define
define|#
directive|define
name|XE_CRHA
value|0x08
end_define

begin_comment
comment|/* Current Rx host address (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_RHSA
value|0x0a
end_define

begin_comment
comment|/* Rx host start address (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_RNSA
value|0x0c
end_define

begin_comment
comment|/* Rx network start address (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_CRNA
value|0x0e
end_define

begin_comment
comment|/* Current Rx network address (16 bits) */
end_comment

begin_comment
comment|/*  * Page 6 registers (all read only)  */
end_comment

begin_define
define|#
directive|define
name|XE_CTHA
value|0x08
end_define

begin_comment
comment|/* Current Tx host address (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_THSA
value|0x0a
end_define

begin_comment
comment|/* Tx host start address (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_TNSA
value|0x0c
end_define

begin_comment
comment|/* Tx network statr address (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_CTNA
value|0x0e
end_define

begin_comment
comment|/* Current Tx network address (16 bits) */
end_comment

begin_comment
comment|/*  * Page 8 registers (all read only)  */
end_comment

begin_define
define|#
directive|define
name|XE_THBC
value|0x08
end_define

begin_comment
comment|/* Tx host byte count (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_THPS
value|0x0a
end_define

begin_comment
comment|/* Tx host packet size (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_TNBC
value|0x0c
end_define

begin_comment
comment|/* Tx network byte count (16 bits) */
end_comment

begin_define
define|#
directive|define
name|XE_TNPS
value|0x0e
end_define

begin_comment
comment|/* Tx network packet size (16 bits) */
end_comment

begin_comment
comment|/*  * Page 0x10 registers (all read only)  */
end_comment

begin_define
define|#
directive|define
name|XE_DINGOID
value|0x08
end_define

begin_comment
comment|/* Dingo ID register (16 bits) (Dingo only) */
end_comment

begin_define
define|#
directive|define
name|XE_RevID
value|0x0a
end_define

begin_comment
comment|/* Dingo revision ID (16 bits) (Dingo only) */
end_comment

begin_define
define|#
directive|define
name|XE_VendorID
value|0x0c
end_define

begin_comment
comment|/* Dingo vendor ID   (16 bits) (Dingo only) */
end_comment

begin_comment
comment|/* Values for the above registers */
end_comment

begin_define
define|#
directive|define
name|XE_DINGOID_DINGO3
value|0x444b
end_define

begin_comment
comment|/* In both Dingo and Mohawk modes */
end_comment

begin_define
define|#
directive|define
name|XE_RevID_DINGO3
value|0x0001
end_define

begin_define
define|#
directive|define
name|XE_VendorID_DINGO3
value|0x0041
end_define

begin_comment
comment|/*  * Page 0x40 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0
value|0x08
end_define

begin_comment
comment|/* MAC Command register (write) */
end_comment

begin_define
define|#
directive|define
name|XE_RST0
value|0x09
end_define

begin_comment
comment|/* Receive status register */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0
value|0x0b
end_define

begin_comment
comment|/* Transmit status register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_TXST1
value|0x0c
end_define

begin_comment
comment|/* Transmit status register 1 */
end_comment

begin_define
define|#
directive|define
name|XE_RX0Msk
value|0x0d
end_define

begin_comment
comment|/* Receive status mask register */
end_comment

begin_define
define|#
directive|define
name|XE_TX0Msk
value|0x0e
end_define

begin_comment
comment|/* Transmit status 0 mask register */
end_comment

begin_define
define|#
directive|define
name|XE_TX1Msk
value|0x0f
end_define

begin_comment
comment|/* Transmit status 1 mask register */
end_comment

begin_comment
comment|/* CMD0 bits */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0_TX
value|0x01
end_define

begin_comment
comment|/* CE2 only */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0_RX_ENABLE
value|0x04
end_define

begin_comment
comment|/* Enable receiver */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0_RX_DISABLE
value|0x08
end_define

begin_comment
comment|/* Disable receiver */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0_ABORT
value|0x10
end_define

begin_comment
comment|/* CE2 only */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0_ONLINE
value|0x20
end_define

begin_comment
comment|/* Take MAC online */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0_ACK_INTR
value|0x40
end_define

begin_comment
comment|/* CE2 only */
end_comment

begin_define
define|#
directive|define
name|XE_CMD0_OFFLINE
value|0x80
end_define

begin_comment
comment|/* Take MAC offline */
end_comment

begin_comment
comment|/* RST0 bits */
end_comment

begin_define
define|#
directive|define
name|XE_RST0_LONG_PACKET
value|0x02
end_define

begin_comment
comment|/* Packet received with>1518 and<8184 bytes */
end_comment

begin_define
define|#
directive|define
name|XE_RST0_CRC_ERROR
value|0x08
end_define

begin_comment
comment|/* Packet received with incorrect CRC */
end_comment

begin_define
define|#
directive|define
name|XE_RST0_RX_OVERRUN
value|0x10
end_define

begin_comment
comment|/* Receiver overrun, byte(s) dropped */
end_comment

begin_define
define|#
directive|define
name|XE_RST0_RX_ENABLE
value|0x20
end_define

begin_comment
comment|/* Receiver enabled */
end_comment

begin_define
define|#
directive|define
name|XE_RST0_RX_ABORT
value|0x40
end_define

begin_comment
comment|/* Receive aborted: CRC, FIFO overrun or addr mismatch */
end_comment

begin_define
define|#
directive|define
name|XE_RST0_RX_OK
value|0x80
end_define

begin_comment
comment|/* Complete packet received OK */
end_comment

begin_comment
comment|/* TXST0 bits */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0_NO_CARRIER
value|0x01
end_define

begin_comment
comment|/* Lost carrier.  Only valid in 10Mbit half-duplex */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0_16_COLLISIONS
value|0x02
end_define

begin_comment
comment|/* Packet aborted after 16 collisions */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0_TX_UNDERRUN
value|0x08
end_define

begin_comment
comment|/* MAC ran out of data to send */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0_LATE_COLLISION
value|0x10
end_define

begin_comment
comment|/* Collision later than 512 bits */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0_SQE_FAIL
value|0x20
end_define

begin_comment
comment|/* SQE test failed. */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0_TX_ABORT
value|0x40
end_define

begin_comment
comment|/* Transmit aborted: collisions, underrun or overrun */
end_comment

begin_define
define|#
directive|define
name|XE_TXST0_TX_OK
value|0x80
end_define

begin_comment
comment|/* Complete packet sent OK */
end_comment

begin_comment
comment|/* TXST1 bits */
end_comment

begin_define
define|#
directive|define
name|XE_TXST1_RETRY_COUNT
value|0x0f
end_define

begin_comment
comment|/* Collision counter for current packet */
end_comment

begin_define
define|#
directive|define
name|XE_TXST1_LINK_STATUS
value|0x10
end_define

begin_comment
comment|/* Valid link status */
end_comment

begin_comment
comment|/* RX0Msk bits */
end_comment

begin_define
define|#
directive|define
name|XE_RX0M_LONG_PACKET
value|0x02
end_define

begin_comment
comment|/* Masks for bits in RXST0 */
end_comment

begin_define
define|#
directive|define
name|XE_RX0M_ALIGN_ERROR
value|0x04
end_define

begin_comment
comment|/* Alignment error (CE2 only) */
end_comment

begin_define
define|#
directive|define
name|XE_RX0M_CRC_ERROR
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_RX0M_RX_OVERRUN
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_RX0M_RX_ABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|XE_RX0M_RX_OK
value|0x80
end_define

begin_comment
comment|/* TX0Msk bits */
end_comment

begin_define
define|#
directive|define
name|XE_TX0M_NO_CARRIER
value|0x01
end_define

begin_comment
comment|/* Masks for bits in TXST0 */
end_comment

begin_define
define|#
directive|define
name|XE_TX0M_16_COLLISIONS
value|0x02
end_define

begin_define
define|#
directive|define
name|XE_TX0M_TX_UNDERRUN
value|0x08
end_define

begin_define
define|#
directive|define
name|XE_TX0M_LATE_COLLISION
value|0x10
end_define

begin_define
define|#
directive|define
name|XE_TX0M_SQE_FAIL
value|0x20
end_define

begin_define
define|#
directive|define
name|XE_TX0M_TX_ABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|XE_TX0M_TX_OK
value|0x80
end_define

begin_comment
comment|/* TX1Msk bits */
end_comment

begin_define
define|#
directive|define
name|XE_TX1M_PKTDEF
value|0x20
end_define

begin_comment
comment|/*  * Page 0x42 registers  */
end_comment

begin_define
define|#
directive|define
name|XE_SWC0
value|0x08
end_define

begin_comment
comment|/* Software configuration 0 */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1
value|0x09
end_define

begin_comment
comment|/* Software configuration 1 */
end_comment

begin_define
define|#
directive|define
name|XE_BOC
value|0x0a
end_define

begin_comment
comment|/* Back-off configuration */
end_comment

begin_define
define|#
directive|define
name|XE_TCD
value|0x0b
end_define

begin_comment
comment|/* Transmit collision deferral */
end_comment

begin_comment
comment|/* SWC0 bits */
end_comment

begin_define
define|#
directive|define
name|XE_SWC0_LOOPBACK_ENABLE
value|0x01
end_define

begin_comment
comment|/* Enable loopback operation */
end_comment

begin_define
define|#
directive|define
name|XE_SWC0_LOOPBACK_SOURCE
value|0x02
end_define

begin_comment
comment|/* 1 = Transceiver, 0 = MAC */
end_comment

begin_define
define|#
directive|define
name|XE_SWC0_ACCEPT_ERROR
value|0x04
end_define

begin_comment
comment|/* Accept otherwise OK packets with CRC errors */
end_comment

begin_define
define|#
directive|define
name|XE_SWC0_ACCEPT_SHORT
value|0x08
end_define

begin_comment
comment|/* Accept otherwise OK packets that are too short */
end_comment

begin_define
define|#
directive|define
name|XE_SWC0_NO_CRC_INSERT
value|0x40
end_define

begin_comment
comment|/* Don't add CRC to outgoing packets */
end_comment

begin_comment
comment|/* SWC1 bits */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1_IA_ENABLE
value|0x01
end_define

begin_comment
comment|/* Enable individual address filters */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1_ALLMULTI
value|0x02
end_define

begin_comment
comment|/* Accept all multicast packets */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1_PROMISCUOUS
value|0x04
end_define

begin_comment
comment|/* Accept all non-multicast packets */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1_BCAST_DISABLE
value|0x08
end_define

begin_comment
comment|/* Reject broadcast packets */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1_MEDIA_SELECT
value|0x40
end_define

begin_comment
comment|/* AUI media select (Mohawk only) */
end_comment

begin_define
define|#
directive|define
name|XE_SWC1_AUTO_MEDIA
value|0x80
end_define

begin_comment
comment|/* Auto media select (Mohawk only) */
end_comment

begin_comment
comment|/*  * Page 0x44 registers (CE2 only)  */
end_comment

begin_define
define|#
directive|define
name|XE_TDR0
value|0x08
end_define

begin_comment
comment|/* Time domain reflectometry register 0 */
end_comment

begin_define
define|#
directive|define
name|XE_TDR1
value|0x09
end_define

begin_comment
comment|/* Time domain reflectometry register 1 */
end_comment

begin_define
define|#
directive|define
name|XE_RXC0
value|0x0a
end_define

begin_comment
comment|/* Receive byte count low */
end_comment

begin_define
define|#
directive|define
name|XE_RXC1
value|0x0b
end_define

begin_comment
comment|/* Receive byte count high */
end_comment

begin_comment
comment|/*  * Page 0x45 registers (CE2 only)  */
end_comment

begin_define
define|#
directive|define
name|XE_REV
value|0x0f
end_define

begin_comment
comment|/* Revision (read) */
end_comment

begin_comment
comment|/*  * Page 0x50-0x57: Individual address 0-9  *  * Used to filter incoming packets by matching against individual node  * addresses.  If IA matching is enabled (SWC1, bit0) any incoming packet with   * a destination matching one of these 10 addresses will be received.  IA0 is  * always enabled and usually matches the card's unique address.  *  * Addresses are stored LSB first, ie. IA00 (reg. 8 on page 0x50) contains the   * LSB of IA0, and so on.  The data is stored contiguously, in that addresses  * can be broken across page boundaries.  That is:  *  * Reg: 50/8 50/9 50/a 50/b 50/c 50/d 50/e 50/f 51/8 51/9 ... 57/a 57/b  *      IA00 IA01 IA02 IA03 IA04 IA05 IA10 IA11 IA12 IA13 ... IA94 IA95  */
end_comment

begin_comment
comment|/*  * Page 0x58: Multicast hash table filter  *  * In case the 10 individual addresses aren't enough, we also have a multicast  * hash filter, enabled through MSR:5.  The most significant six bits of the  * CRC on each incoming packet are reversed and used as an index into the 64  * bits of the hash table.  If the appropriate bit is set the packet it  * received, although higher layers may still need to filter it out.  The CRC  * calculation is as follows:  *  * crc = 0xffffffff;  * poly = 0x04c11db6;  * for (i = 0; i< 6; i++) {  *   current = mcast_addr[i];  *   for (k = 1; k<= 8; k++) {  *     if (crc& 0x80000000);  *       crc31 = 0x01;  *     else  *       crc31 = 0;  *     bit = crc31 ^ (current& 0x01);  *     crc<<= 1;  *     current>>= 1;  *     if (bit)  *       crc = (crc ^ poly)|1  *   }  * }  */
end_comment

begin_comment
comment|/****************  * MII registers  ****************/
end_comment

begin_comment
comment|/*  * Basic MII-compliant PHY register definitions.  According to the Dingo spec,   * PHYs from (at least) MicroLinear, National Semiconductor, ICS, TDK and  * Quality Semiconductor have been used.  These apparently all come up with  * PHY ID 0x00 unless the "interceptor module" on the Dingo 3 is in use.  With   * the interceptor enabled, the PHY is faked up to look like an ICS unit with  * ID 0x16.  The interceptor can be enabled/disabled in software.  *  * The ML6692 (and maybe others) doesn't have a 10Mbps mode -- this is handled   * by an internal 10Mbps transceiver that we know nothing about... some cards  * seem to work with the MII in 10Mbps mode, so I guess some PHYs must support   * it.  The question is, how can you figure out which one you have?  Just to  * add to the fun there are also 10Mbps _only_ Mohawk/Dingo cards.  Aaargh!  */
end_comment

begin_comment
comment|/*  * Masks for the MII-related bits in GPR2  */
end_comment

begin_define
define|#
directive|define
name|XE_MII_CLK
value|XE_GPR2_GP3_OUT
end_define

begin_define
define|#
directive|define
name|XE_MII_DIR
value|XE_GPR2_GP4_SELECT
end_define

begin_define
define|#
directive|define
name|XE_MII_WRD
value|XE_GPR2_GP4_OUT
end_define

begin_define
define|#
directive|define
name|XE_MII_RDD
value|XE_GPR2_GP4_IN
end_define

begin_comment
comment|/*  * MII PHY ID register values  */
end_comment

begin_define
define|#
directive|define
name|PHY_ID_ML6692
value|0x0000
end_define

begin_comment
comment|/* MicroLinear ML6692? Or unknown */
end_comment

begin_define
define|#
directive|define
name|PHY_ID_ICS1890
value|0x0015
end_define

begin_comment
comment|/* ICS1890 */
end_comment

begin_define
define|#
directive|define
name|PHY_ID_QS6612
value|0x0181
end_define

begin_comment
comment|/* Quality QS6612 */
end_comment

begin_define
define|#
directive|define
name|PHY_ID_DP83840
value|0x2000
end_define

begin_comment
comment|/* National DP83840 */
end_comment

begin_comment
comment|/*  * MII command (etc) bit strings.  */
end_comment

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

begin_comment
comment|/*  * PHY registers.  */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR
value|0x00
end_define

begin_comment
comment|/* Basic Mode Control Register */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR
value|0x01
end_define

begin_comment
comment|/* Basic Mode Status Register */
end_comment

begin_define
define|#
directive|define
name|PHY_ID1
value|0x02
end_define

begin_comment
comment|/* PHY ID 1 */
end_comment

begin_define
define|#
directive|define
name|PHY_ID2
value|0x03
end_define

begin_comment
comment|/* PHY ID 2 */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR
value|0x04
end_define

begin_comment
comment|/* Auto-Negotiation Advertisment Register */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR
value|0x05
end_define

begin_comment
comment|/* Auto-Negotiation Link Partner Ability Register */
end_comment

begin_define
define|#
directive|define
name|PHY_ANER
value|0x06
end_define

begin_comment
comment|/* Auto-Negotiation Expansion Register */
end_comment

begin_comment
comment|/* BMCR bits */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RESET
value|0x8000
end_define

begin_comment
comment|/* Soft reset PHY.  Self-clearing */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_LOOPBK
value|0x4000
end_define

begin_comment
comment|/* Enable loopback */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_SPEEDSEL
value|0x2000
end_define

begin_comment
comment|/* 1=100Mbps, 0=10Mbps */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGENBL
value|0x1000
end_define

begin_comment
comment|/* Auto-negotiation enabled */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_ISOLATE
value|0x0400
end_define

begin_comment
comment|/* Isolate ML6692 from MII */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGRSTR
value|0x0200
end_define

begin_comment
comment|/* Restart auto-negotiation.  Self-clearing */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_DUPLEX
value|0x0100
end_define

begin_comment
comment|/* Full duplex operation */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_COLLTEST
value|0x0080
end_define

begin_comment
comment|/* Enable collision test */
end_comment

begin_comment
comment|/* BMSR bits */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_100BT4
value|0x8000
end_define

begin_comment
comment|/* 100Base-T4 capable */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXFULL
value|0x4000
end_define

begin_comment
comment|/* 100Base-TX full duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXHALF
value|0x2000
end_define

begin_comment
comment|/* 100Base-TX half duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_10BTFULL
value|0x1000
end_define

begin_comment
comment|/* 10Base-T full duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_10BTHALF
value|0x0800
end_define

begin_comment
comment|/* 10Base-T half duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_AUTONEGCOMP
value|0x0020
end_define

begin_comment
comment|/* Auto-negotiation complete */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_CANAUTONEG
value|0x0008
end_define

begin_comment
comment|/* Auto-negotiation supported */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_LINKSTAT
value|0x0004
end_define

begin_comment
comment|/* Link is up */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_EXTENDED
value|0x0001
end_define

begin_comment
comment|/* Extended register capabilities */
end_comment

begin_comment
comment|/* ANAR bits */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_NEXTPAGE
value|0x8000
end_define

begin_comment
comment|/* Additional link code word pages */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_TLRFLT
value|0x2000
end_define

begin_comment
comment|/* Remote wire fault detected */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_100BT4
value|0x0200
end_define

begin_comment
comment|/* 100Base-T4 capable */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXFULL
value|0x0100
end_define

begin_comment
comment|/* 100Base-TX full duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXHALF
value|0x0080
end_define

begin_comment
comment|/* 100Base-TX half duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_10BTFULL
value|0x0040
end_define

begin_comment
comment|/* 10Base-T full duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_10BTHALF
value|0x0020
end_define

begin_comment
comment|/* 10Base-T half duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO4
value|0x0010
end_define

begin_comment
comment|/* Protocol selection (00001 = 802.3) */
end_comment

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

begin_define
define|#
directive|define
name|PHY_ANAR_8023
value|PHY_ANAR_PROTO0
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_DINGO
value|PHY_ANAR_100BT+PHY_ANAR_10BT_FD+PHY_ANAR_10BT+PHY_ANAR_8023
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_MOHAWK
value|PHY_ANAR_100BT+PHY_ANAR_10BT_FD+PHY_ANAR_10BT+PHY_ANAR_8023
end_define

begin_comment
comment|/* LPAR bits */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_NEXTPAGE
value|0x8000
end_define

begin_comment
comment|/* Additional link code word pages */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_LPACK
value|0x4000
end_define

begin_comment
comment|/* Link partner acknowledged receipt */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_TLRFLT
value|0x2000
end_define

begin_comment
comment|/* Remote wire fault detected */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_100BT4
value|0x0200
end_define

begin_comment
comment|/* 100Base-T4 capable */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_100BTXFULL
value|0x0100
end_define

begin_comment
comment|/* 100Base-TX full duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_100BTXHALF
value|0x0080
end_define

begin_comment
comment|/* 100Base-TX half duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_10BTFULL
value|0x0040
end_define

begin_comment
comment|/* 10Base-T full duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_10BTHALF
value|0x0020
end_define

begin_comment
comment|/* 10Base-T half duplex capable */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_PROTO4
value|0x0010
end_define

begin_comment
comment|/* Protocol selection (00001 = 802.3) */
end_comment

begin_define
define|#
directive|define
name|PHY_LPAR_PROTO3
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_LPAR_PROTO2
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_LPAR_PROTO1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_LPAR_PROTO0
value|0x0001
end_define

begin_comment
comment|/* ANER bits */
end_comment

begin_define
define|#
directive|define
name|PHY_ANER_MLFAULT
value|0x0010
end_define

begin_comment
comment|/* More than one link is up! */
end_comment

begin_define
define|#
directive|define
name|PHY_ANER_LPNPABLE
value|0x0008
end_define

begin_comment
comment|/* Link partner supports next page */
end_comment

begin_define
define|#
directive|define
name|PHY_ANER_NPABLE
value|0x0004
end_define

begin_comment
comment|/* Local port supports next page */
end_comment

begin_define
define|#
directive|define
name|PHY_ANER_PAGERX
value|0x0002
end_define

begin_comment
comment|/* Page received */
end_comment

begin_define
define|#
directive|define
name|PHY_ANER_LPAUTONEG
value|0x0001
end_define

begin_comment
comment|/* Link partner can auto-negotiate */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_XE_IF_XEREG_H */
end_comment

end_unit

