begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 Gardner Buchanan<gbuchanan@shl.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Gardner Buchanan.  * 4. The name of Gardner Buchanan may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *   $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file contains register information and access macros for  * the SMC91xxx chipset.  *  * Information contained in this file was obtained from the SMC91C92  * and SMC91C94 manuals from SMC.  You will need one of these in order  * to make any meaningful changes to this driver.  Information about  * obtaining one can be found at http://www.smc.com in the components  * division.  *  * This FreeBSD driver is derived in part from the smc9194 Linux driver  * by Erik Stahlman and is Copyright (C) 1996 by Erik Stahlman.  * It is also derived in part from the FreeBSD ep (3C509) driver which  * is Copyright (c) 1993 Herb Peyerl (hpeyerl@novatel.ca) All rights  * reserved.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SNREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_SNREG_H_
end_define

begin_comment
comment|/*  * Wait time for memory to be free.  This probably shouldn't be  * tuned that much, as waiting for this means nothing else happens  * in the system  */
end_comment

begin_define
define|#
directive|define
name|MEMORY_WAIT_TIME
value|1000
end_define

begin_comment
comment|/* The SMC91xxx uses 16 I/O ports  */
end_comment

begin_define
define|#
directive|define
name|SMC_IO_EXTENT
value|16
end_define

begin_comment
comment|/*  * A description of the SMC registers is probably in order here,  * although for details, the SMC datasheet is invaluable.  * The data sheet I (GB) am using is "SMC91C92 Single Chip Ethernet  * Controller With RAM", Rev. 12/0/94.  Constant definitions I give  * here are loosely based on the mnemonic names given to them in the  * data sheet, but there are many exceptions.  *  * Basically, the chip has 4 banks of registers (0 to 3), which  * are accessed by writing a number into the BANK_SELECT register  * (I also use a SMC_SELECT_BANK macro for this).  Registers are  * either Byte or Word sized.  My constant definitions end in _B  * or _W as appropriate.  *  * The banks are arranged so that for most purposes, bank 2 is all  * that is needed for normal run time tasks.  */
end_comment

begin_comment
comment|/*  * Bank Select Register.  This also doubles as  * a chip identification register.  This register  * is mapped at the same position in all banks.  */
end_comment

begin_define
define|#
directive|define
name|BANK_SELECT_REG_W
value|0x0e
end_define

begin_define
define|#
directive|define
name|BSR_DETECT_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|BSR_DETECT_VALUE
value|0x3300
end_define

begin_comment
comment|/* BANK 0  */
end_comment

begin_comment
comment|/* Transmit Control Register controls some aspects of the transmit  * behavior of the Ethernet Protocol Handler.  */
end_comment

begin_define
define|#
directive|define
name|TXMIT_CONTROL_REG_W
value|0x00
end_define

begin_define
define|#
directive|define
name|TCR_ENABLE
value|0x0001
end_define

begin_comment
comment|/* if this is 1, we can transmit */
end_comment

begin_define
define|#
directive|define
name|TCR_LOOP
value|0x0002
end_define

begin_comment
comment|/* Enable internal analogue loopback */
end_comment

begin_define
define|#
directive|define
name|TCR_FORCOL
value|0x0004
end_define

begin_comment
comment|/* Force Collision on next TX */
end_comment

begin_define
define|#
directive|define
name|TCR_PAD_ENABLE
value|0x0080
end_define

begin_comment
comment|/* Pad short packets to 64 bytes */
end_comment

begin_define
define|#
directive|define
name|TCR_NOCRC
value|0x0100
end_define

begin_comment
comment|/* Do not append CRC */
end_comment

begin_define
define|#
directive|define
name|TCR_MON_CSN
value|0x0400
end_define

begin_comment
comment|/* monitors the carrier status */
end_comment

begin_define
define|#
directive|define
name|TCR_FDUPLX
value|0x0800
end_define

begin_comment
comment|/* receive packets sent out */
end_comment

begin_define
define|#
directive|define
name|TCR_STP_SQET
value|0x1000
end_define

begin_comment
comment|/* stop transmitting if Signal quality error */
end_comment

begin_define
define|#
directive|define
name|TCR_EPH_LOOP
value|0x2000
end_define

begin_comment
comment|/* Enable internal digital loopback */
end_comment

begin_comment
comment|/* Status of the last transmitted frame and instantaneous status of  * the Ethernet Protocol Handler jumbled together.  In auto-release  * mode this information is simply discarded after each TX.  This info  * is copied to the status word of in-memory packets after transmit  * where relevent statuses can be checked.  */
end_comment

begin_define
define|#
directive|define
name|EPH_STATUS_REG_W
value|0x02
end_define

begin_define
define|#
directive|define
name|EPHSR_TX_SUC
value|0x0001
end_define

begin_comment
comment|/* Transmit was successful */
end_comment

begin_define
define|#
directive|define
name|EPHSR_SNGLCOL
value|0x0002
end_define

begin_comment
comment|/* Single collision occurred */
end_comment

begin_define
define|#
directive|define
name|EPHSR_MULCOL
value|0x0004
end_define

begin_comment
comment|/* Multiple Collisions occurred */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LTX_MULT
value|0x0008
end_define

begin_comment
comment|/* Transmit was a multicast */
end_comment

begin_define
define|#
directive|define
name|EPHSR_16COL
value|0x0010
end_define

begin_comment
comment|/* 16 Collisions occurred, TX disabled */
end_comment

begin_define
define|#
directive|define
name|EPHSR_SQET
value|0x0020
end_define

begin_comment
comment|/* SQE Test failed, TX disabled */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LTX_BRD
value|0x0040
end_define

begin_comment
comment|/* Transmit was a broadcast */
end_comment

begin_define
define|#
directive|define
name|EPHSR_DEFR
value|0x0080
end_define

begin_comment
comment|/* TX deferred due to carrier det. */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LATCOL
value|0x0200
end_define

begin_comment
comment|/* Late collision detected, TX disabled */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LOST_CAR
value|0x0400
end_define

begin_comment
comment|/* Lost carrier sense, TX disabled */
end_comment

begin_define
define|#
directive|define
name|EPHSR_EXC_DEF
value|0x0800
end_define

begin_comment
comment|/* Excessive deferrals in TX>2 MAXETHER 				 * times */
end_comment

begin_define
define|#
directive|define
name|EPHSR_CTR_ROL
value|0x1000
end_define

begin_comment
comment|/* Some ECR Counter(s) rolled over */
end_comment

begin_define
define|#
directive|define
name|EPHSR_RX_OVRN
value|0x2000
end_define

begin_comment
comment|/* Receiver overrun, packets dropped */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LINK_OK
value|0x4000
end_define

begin_comment
comment|/* Link integrity is OK */
end_comment

begin_define
define|#
directive|define
name|EPHSR_TXUNRN
value|0x8000
end_define

begin_comment
comment|/* Transmit underrun */
end_comment

begin_comment
comment|/* Receiver Control Register controls some aspects of the receive  * behavior of the Ethernet Protocol Handler.  */
end_comment

begin_define
define|#
directive|define
name|RECV_CONTROL_REG_W
value|0x04
end_define

begin_define
define|#
directive|define
name|RCR_RX_ABORT
value|0x0001
end_define

begin_comment
comment|/* Received huge packet */
end_comment

begin_define
define|#
directive|define
name|RCR_PROMISC
value|0x0002
end_define

begin_comment
comment|/* enable promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|RCR_ALMUL
value|0x0004
end_define

begin_comment
comment|/* receive all multicast packets */
end_comment

begin_define
define|#
directive|define
name|RCR_ENABLE
value|0x0100
end_define

begin_comment
comment|/* IFF this is set, we can recieve packets */
end_comment

begin_define
define|#
directive|define
name|RCR_STRIP_CRC
value|0x0200
end_define

begin_comment
comment|/* strips CRC */
end_comment

begin_define
define|#
directive|define
name|RCR_GAIN_BITS
value|0x0c00
end_define

begin_comment
comment|/* PLL Gain control (for testing) */
end_comment

begin_define
define|#
directive|define
name|RCR_FILT_CAR
value|0x4000
end_define

begin_comment
comment|/* Enable 12 bit carrier filter */
end_comment

begin_define
define|#
directive|define
name|RCR_SOFTRESET
value|0x8000
end_define

begin_comment
comment|/* Resets the EPH logic */
end_comment

begin_comment
comment|/* TX Statistics counters  */
end_comment

begin_define
define|#
directive|define
name|COUNTER_REG_W
value|0x06
end_define

begin_define
define|#
directive|define
name|ECR_COLN_MASK
value|0x000f
end_define

begin_comment
comment|/* Vanilla collisions */
end_comment

begin_define
define|#
directive|define
name|ECR_MCOLN_MASK
value|0x00f0
end_define

begin_comment
comment|/* Multiple collisions */
end_comment

begin_define
define|#
directive|define
name|ECR_DTX_MASK
value|0x0f00
end_define

begin_comment
comment|/* Deferred transmits */
end_comment

begin_define
define|#
directive|define
name|ECR_EXDTX_MASK
value|0xf000
end_define

begin_comment
comment|/* Excessively deferred transmits */
end_comment

begin_comment
comment|/* Memory Information  */
end_comment

begin_define
define|#
directive|define
name|MEM_INFO_REG_W
value|0x08
end_define

begin_define
define|#
directive|define
name|MIR_FREE_MASK
value|0xff00
end_define

begin_comment
comment|/* Free memory pages available */
end_comment

begin_define
define|#
directive|define
name|MIR_TOTAL_MASK
value|0x00ff
end_define

begin_comment
comment|/* Total memory pages available */
end_comment

begin_comment
comment|/* Memory Configuration  */
end_comment

begin_define
define|#
directive|define
name|MEM_CFG_REG_W
value|0x0a
end_define

begin_define
define|#
directive|define
name|MCR_TXRSV_MASK
value|0x001f
end_define

begin_comment
comment|/* Count of pages reserved for transmit */
end_comment

begin_comment
comment|/* Bank 0, Register 0x0c is unised in the SMC91C92  */
end_comment

begin_comment
comment|/* BANK 1  */
end_comment

begin_comment
comment|/* Adapter configuration  */
end_comment

begin_define
define|#
directive|define
name|CONFIG_REG_W
value|0x00
end_define

begin_define
define|#
directive|define
name|CR_INT_SEL0
value|0x0002
end_define

begin_comment
comment|/* Interrupt selector */
end_comment

begin_define
define|#
directive|define
name|CR_INT_SEL1
value|0x0004
end_define

begin_comment
comment|/* Interrupt selector */
end_comment

begin_define
define|#
directive|define
name|CR_DIS_LINK
value|0x0040
end_define

begin_comment
comment|/* Disable 10BaseT Link Test */
end_comment

begin_define
define|#
directive|define
name|CR_16BIT
value|0x0080
end_define

begin_comment
comment|/* Bus width */
end_comment

begin_define
define|#
directive|define
name|CR_AUI_SELECT
value|0x0100
end_define

begin_comment
comment|/* Use external (AUI) Transceiver */
end_comment

begin_define
define|#
directive|define
name|CR_SET_SQLCH
value|0x0200
end_define

begin_comment
comment|/* Squelch level */
end_comment

begin_define
define|#
directive|define
name|CR_FULL_STEP
value|0x0400
end_define

begin_comment
comment|/* AUI signalling mode */
end_comment

begin_define
define|#
directive|define
name|CR_NOW_WAIT_ST
value|0x1000
end_define

begin_comment
comment|/* Disable bus wait states */
end_comment

begin_comment
comment|/* The contents of this port are used by the adapter  * to decode its I/O address.  We use it as a varification  * that the adapter is detected properly when probing.  */
end_comment

begin_define
define|#
directive|define
name|BASE_ADDR_REG_W
value|0x02
end_define

begin_comment
comment|/* The select IO Base addr. */
end_comment

begin_comment
comment|/* These registers hold the Ethernet MAC address.  */
end_comment

begin_define
define|#
directive|define
name|IAR_ADDR0_REG_W
value|0x04
end_define

begin_comment
comment|/* My Ethernet address */
end_comment

begin_define
define|#
directive|define
name|IAR_ADDR1_REG_W
value|0x06
end_define

begin_comment
comment|/* My Ethernet address */
end_comment

begin_define
define|#
directive|define
name|IAR_ADDR2_REG_W
value|0x08
end_define

begin_comment
comment|/* My Ethernet address */
end_comment

begin_comment
comment|/* General purpose register used for talking to the EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|GENERAL_REG_W
value|0x0a
end_define

begin_comment
comment|/* Control register used for talking to the EEPROM and  * setting some EPH functions.  */
end_comment

begin_define
define|#
directive|define
name|CONTROL_REG_W
value|0x0c
end_define

begin_define
define|#
directive|define
name|CTR_STORE
value|0x0001
end_define

begin_comment
comment|/* Store something to EEPROM */
end_comment

begin_define
define|#
directive|define
name|CTR_RELOAD
value|0x0002
end_define

begin_comment
comment|/* Read EEPROM into registers */
end_comment

begin_define
define|#
directive|define
name|CTR_EEPROM_SEL
value|0x0004
end_define

begin_comment
comment|/* Select registers for Reload/Store */
end_comment

begin_define
define|#
directive|define
name|CTR_TE_ENABLE
value|0x0020
end_define

begin_comment
comment|/* Enable TX Error detection via EPH_INT */
end_comment

begin_define
define|#
directive|define
name|CTR_CR_ENABLE
value|0x0040
end_define

begin_comment
comment|/* Enable Counter Rollover via EPH_INT */
end_comment

begin_define
define|#
directive|define
name|CTR_LE_ENABLE
value|0x0080
end_define

begin_comment
comment|/* Enable Link Error detection via EPH_INT */
end_comment

begin_define
define|#
directive|define
name|CTR_AUTO_RELEASE
value|0x0800
end_define

begin_comment
comment|/* Enable auto release mode for TX */
end_comment

begin_define
define|#
directive|define
name|CTR_POWERDOWN
value|0x2000
end_define

begin_comment
comment|/* Enter powerdown mode */
end_comment

begin_define
define|#
directive|define
name|CTR_RCV_BAD
value|0x4000
end_define

begin_comment
comment|/* Enable receipt of frames with bad CRC */
end_comment

begin_comment
comment|/* BANK 2  */
end_comment

begin_comment
comment|/* Memory Management Unit Control Register  * Controls allocation of memory to receive and  * transmit functions.  */
end_comment

begin_define
define|#
directive|define
name|MMU_CMD_REG_W
value|0x00
end_define

begin_define
define|#
directive|define
name|MMUCR_BUSY
value|0x0001
end_define

begin_comment
comment|/* MMU busy performing a release */
end_comment

begin_comment
comment|/* MMU Commands:  */
end_comment

begin_define
define|#
directive|define
name|MMUCR_NOP
value|0x0000
end_define

begin_comment
comment|/* Do nothing */
end_comment

begin_define
define|#
directive|define
name|MMUCR_ALLOC
value|0x0020
end_define

begin_comment
comment|/* Or with number of 256 byte packets - 1 */
end_comment

begin_define
define|#
directive|define
name|MMUCR_RESET
value|0x0040
end_define

begin_comment
comment|/* Reset MMU State */
end_comment

begin_define
define|#
directive|define
name|MMUCR_REMOVE
value|0x0060
end_define

begin_comment
comment|/* Dequeue (but not free) current RX packet */
end_comment

begin_define
define|#
directive|define
name|MMUCR_RELEASE
value|0x0080
end_define

begin_comment
comment|/* Dequeue and free the current RX packet */
end_comment

begin_define
define|#
directive|define
name|MMUCR_FREEPKT
value|0x00a0
end_define

begin_comment
comment|/* Release packet in PNR register */
end_comment

begin_define
define|#
directive|define
name|MMUCR_ENQUEUE
value|0x00c0
end_define

begin_comment
comment|/* Enqueue the packet for transmit */
end_comment

begin_define
define|#
directive|define
name|MMUCR_RESETTX
value|0x00e0
end_define

begin_comment
comment|/* Reset transmit queues */
end_comment

begin_comment
comment|/* Packet Number at TX Area  */
end_comment

begin_define
define|#
directive|define
name|PACKET_NUM_REG_B
value|0x02
end_define

begin_comment
comment|/* Packet number resulting from MMUCR_ALLOC  */
end_comment

begin_define
define|#
directive|define
name|ALLOC_RESULT_REG_B
value|0x03
end_define

begin_define
define|#
directive|define
name|ARR_FAILED
value|0x80
end_define

begin_comment
comment|/* Transmit and receive queue heads  */
end_comment

begin_define
define|#
directive|define
name|FIFO_PORTS_REG_W
value|0x04
end_define

begin_define
define|#
directive|define
name|FIFO_REMPTY
value|0x8000
end_define

begin_define
define|#
directive|define
name|FIFO_TEMPTY
value|0x0080
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK
value|0x7f00
end_define

begin_define
define|#
directive|define
name|FIFO_TX_MASK
value|0x007f
end_define

begin_comment
comment|/* The address within the packet for reading/writing.  The  * PTR_RCV bit is tricky.  When PTR_RCV==1, the packet number  * to be read is found in the FIFO_PORTS_REG_W, FIFO_RX_MASK.  * When PTR_RCV==0, the packet number to be written is found  * in the PACKET_NUM_REG_B.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_REG_W
value|0x06
end_define

begin_define
define|#
directive|define
name|PTR_READ
value|0x2000
end_define

begin_comment
comment|/* Intended access mode */
end_comment

begin_define
define|#
directive|define
name|PTR_AUTOINC
value|0x4000
end_define

begin_comment
comment|/* Do auto inc after read/write */
end_comment

begin_define
define|#
directive|define
name|PTR_RCV
value|0x8000
end_define

begin_comment
comment|/* FIFO_RX is packet, otherwise PNR is packet */
end_comment

begin_comment
comment|/* Data I/O register to be used in conjunction with  * The pointer register to read and write data from the  * card.  The same register can be used for byte and word  * ops.  */
end_comment

begin_define
define|#
directive|define
name|DATA_REG_W
value|0x08
end_define

begin_define
define|#
directive|define
name|DATA_REG_B
value|0x08
end_define

begin_define
define|#
directive|define
name|DATA_1_REG_B
value|0x08
end_define

begin_define
define|#
directive|define
name|DATA_2_REG_B
value|0x0a
end_define

begin_comment
comment|/* Sense interrupt status (READ)  */
end_comment

begin_define
define|#
directive|define
name|INTR_STAT_REG_B
value|0x0c
end_define

begin_comment
comment|/* Acknowledge interrupt sources (WRITE)  */
end_comment

begin_define
define|#
directive|define
name|INTR_ACK_REG_B
value|0x0c
end_define

begin_comment
comment|/* Interrupt mask.  Bit set indicates interrupt allowed.  */
end_comment

begin_define
define|#
directive|define
name|INTR_MASK_REG_B
value|0x0d
end_define

begin_comment
comment|/* Interrupts  */
end_comment

begin_define
define|#
directive|define
name|IM_RCV_INT
value|0x01
end_define

begin_comment
comment|/* A packet has been received */
end_comment

begin_define
define|#
directive|define
name|IM_TX_INT
value|0x02
end_define

begin_comment
comment|/* Packet TX complete */
end_comment

begin_define
define|#
directive|define
name|IM_TX_EMPTY_INT
value|0x04
end_define

begin_comment
comment|/* No packets left to TX  */
end_comment

begin_define
define|#
directive|define
name|IM_ALLOC_INT
value|0x08
end_define

begin_comment
comment|/* Memory allocation completed */
end_comment

begin_define
define|#
directive|define
name|IM_RX_OVRN_INT
value|0x10
end_define

begin_comment
comment|/* Receiver was overrun */
end_comment

begin_define
define|#
directive|define
name|IM_EPH_INT
value|0x20
end_define

begin_comment
comment|/* Misc. EPH conditions (see CONTROL_REG_W) */
end_comment

begin_define
define|#
directive|define
name|IM_ERCV_INT
value|0x40
end_define

begin_comment
comment|/* not on SMC9192 */
end_comment

begin_comment
comment|/* BANK 3  */
end_comment

begin_comment
comment|/* Multicast subscriptions.  * The multicast handling in the SMC90Cxx is quite complicated.  A table  * of multicast address subscriptions is provided and a clever way of  * speeding the search of that table by hashing is implemented in the  * hardware.  I have ignored this and simply subscribed to all multicasts  * and let the kernel deal with the results.  */
end_comment

begin_define
define|#
directive|define
name|MULTICAST1_REG_W
value|0x00
end_define

begin_define
define|#
directive|define
name|MULTICAST2_REG_W
value|0x02
end_define

begin_define
define|#
directive|define
name|MULTICAST3_REG_W
value|0x04
end_define

begin_define
define|#
directive|define
name|MULTICAST4_REG_W
value|0x06
end_define

begin_comment
comment|/* These registers do not exist on SMC9192, or at least  * are not documented in the SMC91C92 data sheet.  * The REVISION_REG_W register does however seem to work.  */
end_comment

begin_define
define|#
directive|define
name|MGMT_REG_W
value|0x08
end_define

begin_define
define|#
directive|define
name|REVISION_REG_W
value|0x0a
end_define

begin_comment
comment|/* (hi: chip id low: rev #) */
end_comment

begin_define
define|#
directive|define
name|ERCV_REG_W
value|0x0c
end_define

begin_comment
comment|/* These are constants expected to be found in the  * chip id register.  */
end_comment

begin_define
define|#
directive|define
name|CHIP_9190
value|3
end_define

begin_define
define|#
directive|define
name|CHIP_9194
value|4
end_define

begin_define
define|#
directive|define
name|CHIP_9195
value|5
end_define

begin_define
define|#
directive|define
name|CHIP_91100
value|7
end_define

begin_define
define|#
directive|define
name|CHIP_91100FD
value|8
end_define

begin_comment
comment|/* When packets are stuffed into the card or sucked out of the card  * they are set up more or less as follows:  *  * Addr msbyte   lsbyte  * 00   SSSSSSSS SSSSSSSS - STATUS-WORD 16 bit TX or RX status  * 02   RRRRR             - RESERVED (unused)  * 02        CCC CCCCCCCC - BYTE COUNT (RX: always even, TX: bit 0 ignored)  * 04   DDDDDDDD DDDDDDDD - DESTINATION ADDRESS  * 06   DDDDDDDD DDDDDDDD        (48 bit Ethernet MAC Address)  * 08   DDDDDDDD DDDDDDDD  * 0A   SSSSSSSS SSSSSSSS - SOURCE ADDRESS  * 0C   SSSSSSSS SSSSSSSS        (48 bit Ethernet MAC Address)  * 0E   SSSSSSSS SSSSSSSS  * 10   PPPPPPPP PPPPPPPP  * ..   PPPPPPPP PPPPPPPP  * C-2  CCCCCCCC          - CONTROL BYTE  * C-2           PPPPPPPP - Last data byte (If odd length)  *  * The STATUS_WORD is derived from the EPH_STATUS_REG_W register  * during transmit and is composed of another set of bits described  * below during receive.  */
end_comment

begin_comment
comment|/* Receive status bits.  These values are found in the status word  * field of a received packet.  For receive packets I use the RS_ODDFRAME  * to detect whether a frame has an extra byte on it.  The CTLB_ODD  * bit of the control byte tells the same thing.  */
end_comment

begin_define
define|#
directive|define
name|RS_MULTICAST
value|0x0001
end_define

begin_comment
comment|/* Packet is multicast */
end_comment

begin_define
define|#
directive|define
name|RS_HASH_MASK
value|0x007e
end_define

begin_comment
comment|/* Mask of multicast hash value */
end_comment

begin_define
define|#
directive|define
name|RS_TOOSHORT
value|0x0400
end_define

begin_comment
comment|/* Frame was a runt,<64 bytes */
end_comment

begin_define
define|#
directive|define
name|RS_TOOLONG
value|0x0800
end_define

begin_comment
comment|/* Frame was giant,>1518 */
end_comment

begin_define
define|#
directive|define
name|RS_ODDFRAME
value|0x1000
end_define

begin_comment
comment|/* Frame is odd lengthed */
end_comment

begin_define
define|#
directive|define
name|RS_BADCRC
value|0x2000
end_define

begin_comment
comment|/* Frame had CRC error */
end_comment

begin_define
define|#
directive|define
name|RS_ALGNERR
value|0x8000
end_define

begin_comment
comment|/* Frame had alignment error */
end_comment

begin_define
define|#
directive|define
name|RS_ERRORS
value|(RS_ALGNERR | RS_BADCRC | RS_TOOLONG | RS_TOOSHORT)
end_define

begin_define
define|#
directive|define
name|RLEN_MASK
value|0x07ff
end_define

begin_comment
comment|/* Significant length bits in RX length */
end_comment

begin_comment
comment|/* The control byte has the following significant bits.  * For transmit, the CTLB_ODD bit specifies whether an extra byte  * is present in the frame.  Bit 0 of the byte count field is  * ignored.  I just pad every frame to even length and forget about  * it.  */
end_comment

begin_define
define|#
directive|define
name|CTLB_CRC
value|0x10
end_define

begin_comment
comment|/* Add CRC for this packet (TX only) */
end_comment

begin_define
define|#
directive|define
name|CTLB_ODD
value|0x20
end_define

begin_comment
comment|/* The packet length is ODD */
end_comment

begin_comment
comment|/*  * I define some macros to make it easier to do somewhat common  * or slightly complicated, repeated tasks.  */
end_comment

begin_comment
comment|/* The base I/O address.  */
end_comment

begin_define
define|#
directive|define
name|BASE
value|(sc->sn_io_addr)
end_define

begin_comment
comment|/* Select a register bank, 0 to 3  */
end_comment

begin_define
define|#
directive|define
name|SMC_SELECT_BANK
parameter_list|(
name|x
parameter_list|)
value|{ outw( BASE + BANK_SELECT_REG_W, (x) ); }
end_define

begin_comment
comment|/* Define a small delay for the reset  */
end_comment

begin_define
define|#
directive|define
name|SMC_DELAY
parameter_list|()
value|{ inw( BASE + RECV_CONTROL_REG_W );\                       inw( BASE + RECV_CONTROL_REG_W );\                       inw( BASE + RECV_CONTROL_REG_W );  }
end_define

begin_comment
comment|/* Define flags  */
end_comment

begin_define
define|#
directive|define
name|SN_FLAGS_PCCARD
value|0x0001
end_define

begin_comment
comment|/* PCMCIA (PC-card) */
end_comment

begin_define
define|#
directive|define
name|SN_FLAGS_XJBT10
value|0x0002
end_define

begin_comment
comment|/* Megahertz XJ-BT10 (PCMCIA) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_SNREG_H_ */
end_comment

end_unit

