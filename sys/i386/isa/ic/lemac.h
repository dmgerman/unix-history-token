begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Matt Thomas (thomas@lkg.dec.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LEMAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LEMAC_H_
end_define

begin_comment
comment|/*  * This is list of registers used on a DEC EtherWORKS III card.  * Each board occupies a 32 byte register space.  This can be  * in either EISA or ISA space.  Currently we only support ISA  * space.  */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_CS
value|0x00
end_define

begin_comment
comment|/* Control and Status */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_CTL
value|0x01
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_IC
value|0x02
end_define

begin_comment
comment|/* Interrupt Control */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_TS
value|0x03
end_define

begin_comment
comment|/* Transmit Status */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_RSVD1
value|0x04
end_define

begin_comment
comment|/* Reserved (not used) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_RSVD2
value|0x05
end_define

begin_comment
comment|/* Reserved (not used) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_FMQ
value|0x06
end_define

begin_comment
comment|/* Free Memory Queue */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_FMC
value|0x07
end_define

begin_comment
comment|/* Free Memory Queue Count */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_RQ
value|0x08
end_define

begin_comment
comment|/* Receive Queue */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_RQC
value|0x09
end_define

begin_comment
comment|/* Receive Queue Count */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_TQ
value|0x0A
end_define

begin_comment
comment|/* Transmit Queue */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_TQC
value|0x0B
end_define

begin_comment
comment|/* Transmit Queue Count */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_TDQ
value|0x0C
end_define

begin_comment
comment|/* Transmit Done Queue */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_TDC
value|0x0D
end_define

begin_comment
comment|/* Transmit Done Queue Count */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PI1
value|0x0E
end_define

begin_comment
comment|/* Page Index #1 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PI2
value|0x0F
end_define

begin_comment
comment|/* Page Index #2 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_DAT
value|0x10
end_define

begin_comment
comment|/* Data */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_IOP
value|0x11
end_define

begin_comment
comment|/* I/O Page */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_IOB
value|0x12
end_define

begin_comment
comment|/* I/O Base */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_MPN
value|0x13
end_define

begin_comment
comment|/* Memory Page */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_MBR
value|0x14
end_define

begin_comment
comment|/* Memory Base */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_APD
value|0x15
end_define

begin_comment
comment|/* Address PROM */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_EE1
value|0x16
end_define

begin_comment
comment|/* EEPROM Data #1 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_EE2
value|0x17
end_define

begin_comment
comment|/* EEPROM Data #2 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PA0
value|0x18
end_define

begin_comment
comment|/* Physical Address (Byte 0) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PA1
value|0x19
end_define

begin_comment
comment|/* Physical Address (Byte 1) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PA2
value|0x1A
end_define

begin_comment
comment|/* Physical Address (Byte 2) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PA3
value|0x1B
end_define

begin_comment
comment|/* Physical Address (Byte 3) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PA4
value|0x1C
end_define

begin_comment
comment|/* Physical Address (Byte 4) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_PA5
value|0x1D
end_define

begin_comment
comment|/* Physical Address (Byte 5) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_CNF
value|0x1E
end_define

begin_comment
comment|/* Configuration Management */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IOSPACE
value|0x20
end_define

begin_comment
comment|/* LEMAC uses 32 bytes of IOSPACE */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_EID0
value|0x80
end_define

begin_comment
comment|/* EISA Identification 0 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_EID1
value|0x81
end_define

begin_comment
comment|/* EISA Identification 1 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_EID2
value|0x82
end_define

begin_comment
comment|/* EISA Identification 2 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_EID3
value|0x83
end_define

begin_comment
comment|/* EISA Identification 3 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_REG_EIC
value|0x84
end_define

begin_comment
comment|/* EISA Control */
end_comment

begin_comment
comment|/* Control Page (Page 0) Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_MCTBL_BITS
value|9
end_define

begin_define
define|#
directive|define
name|LEMAC_MCTBL_OFF
value|512
end_define

begin_define
define|#
directive|define
name|LEMAC_MCTBL_SIZE
value|(1<< (LEMAC_MCTBL_BITS - 3))
end_define

begin_define
define|#
directive|define
name|LEMAC_CRC32_POLY
value|0xEDB88320UL
end_define

begin_comment
comment|/* CRC-32 Poly -- Little Endian) */
end_comment

begin_comment
comment|/* EEPROM Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_CKSUM
value|0
end_define

begin_comment
comment|/* The valid checksum is 0 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_SIZE
value|32
end_define

begin_comment
comment|/* EEPROM is 32 bytes */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_DELAY
value|2000
end_define

begin_comment
comment|/* 2ms = 2000us */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_PRDNM
value|8
end_define

begin_comment
comment|/* Product Name Offset */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_PRDNMSZ
value|8
end_define

begin_comment
comment|/* Product Name Size */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_SWFLAGS
value|16
end_define

begin_comment
comment|/* Software Options Offset */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_SETUP
value|23
end_define

begin_comment
comment|/* Setup Options Offset */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_SW_SQE
value|0x10
end_define

begin_comment
comment|/* Enable TX_SQE on Transmits */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_SW_LAB
value|0x08
end_define

begin_comment
comment|/* Enable TX_LAB on Transmits */
end_comment

begin_define
define|#
directive|define
name|LEMAC_EEP_ST_DRAM
value|0x02
end_define

begin_comment
comment|/* Enable extra DRAM */
end_comment

begin_define
define|#
directive|define
name|LEMAC_ADP_ROMSZ
value|32
end_define

begin_comment
comment|/* Size of Address PROM */
end_comment

begin_comment
comment|/* Receive Status Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_RX_PLL
value|0x01
end_define

begin_comment
comment|/* Phase Lock Lost */
end_comment

begin_define
define|#
directive|define
name|LEMAC_RX_CRC
value|0x02
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|LEMAC_RX_DBE
value|0x04
end_define

begin_comment
comment|/* Dribble Bit Error */
end_comment

begin_define
define|#
directive|define
name|LEMAC_RX_MCM
value|0x08
end_define

begin_comment
comment|/* Multicast Match */
end_comment

begin_define
define|#
directive|define
name|LEMAC_RX_IAM
value|0x10
end_define

begin_comment
comment|/* Individual Address Match */
end_comment

begin_define
define|#
directive|define
name|LEMAC_RX_OK
value|0x80
end_define

begin_comment
comment|/* No Errors */
end_comment

begin_comment
comment|/* Transmit Status Definitions (not valid if TXD == 0) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TS_RTRYMSK
value|0x0F
end_define

begin_comment
comment|/* Retries of last TX PDU */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TS_ECL
value|0x10
end_define

begin_comment
comment|/* Excessive collision of ... */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TS_LCL
value|0x20
end_define

begin_comment
comment|/* Late collision of ... */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TS_ID
value|0x40
end_define

begin_comment
comment|/* Initially Deferred  ... */
end_comment

begin_comment
comment|/* Transmit Control Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_ISA
value|0x01
end_define

begin_comment
comment|/* Insert Source Address (no) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_IFC
value|0x02
end_define

begin_comment
comment|/* Insert Frame Check (yes) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_PAD
value|0x04
end_define

begin_comment
comment|/* Zero PAD to mininum length (yes) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_LAB
value|0x08
end_define

begin_comment
comment|/* Less Agressive Backoff (no) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_QMD
value|0x10
end_define

begin_comment
comment|/* Q-Mode (yes) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_STP
value|0x20
end_define

begin_comment
comment|/* Stop on Error (yes) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_SQE
value|0x40
end_define

begin_comment
comment|/* SQE Enable (yes) */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TX_FLAGS
value|(LEMAC_TX_IFC|LEMAC_TX_PAD|LEMAC_TX_QMD|\ 				 LEMAC_TX_STP|LEMAC_TX_SQE)
end_define

begin_define
define|#
directive|define
name|LEMAC_TX_HDRSZ
value|4
end_define

begin_comment
comment|/* Size of TX header */
end_comment

begin_comment
comment|/* Transmit Done Queue Status Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TDQ_COL
value|0x03
end_define

begin_comment
comment|/* Collision Mask */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TDQ_NOCOL
value|0x00
end_define

begin_comment
comment|/*   No Collisions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TDQ_ONECOL
value|0x01
end_define

begin_comment
comment|/*   One Collision */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TDQ_MULCOL
value|0x02
end_define

begin_comment
comment|/*   Multiple Collisions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TDQ_EXCCOL
value|0x03
end_define

begin_comment
comment|/*   Excesive Collisions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TDQ_ID
value|0x04
end_define

begin_comment
comment|/* Initially Deferred */
end_comment

begin_define
define|#
directive|define
name|LEMAC_TDQ_LCL
value|0x08
end_define

begin_comment
comment|/* Late Collision (will TX_STP) */
end_comment

begin_comment
comment|/* Control / Status Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_RXD
value|0x01
end_define

begin_comment
comment|/* Receiver Disabled */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_TXD
value|0x02
end_define

begin_comment
comment|/* Transmitter Disabled */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_RNE
value|0x04
end_define

begin_comment
comment|/* Receive Queue Not Empty */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_TNE
value|0x08
end_define

begin_comment
comment|/* Transmit Done Queue Not Empty */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_MBZ4
value|0x10
end_define

begin_comment
comment|/* MBZ */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_MCE
value|0x20
end_define

begin_comment
comment|/* Multicast Enable */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_PME
value|0x40
end_define

begin_comment
comment|/* Promiscuous Mode Enable */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CS_RA
value|0x80
end_define

begin_comment
comment|/* Runt Accept */
end_comment

begin_comment
comment|/* Control Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CTL_LED
value|0x02
end_define

begin_comment
comment|/* LED state (inverted) */
end_comment

begin_comment
comment|/* Interrupt Control Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_RXD
value|0x01
end_define

begin_comment
comment|/* Enable RXD Interrupt */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_TXD
value|0x02
end_define

begin_comment
comment|/* Enable TXD Interrupt */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_RNE
value|0x04
end_define

begin_comment
comment|/* Enable RNE Interrupt */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_TNE
value|0x08
end_define

begin_comment
comment|/* Enable TNE Interrupt */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_ALL
value|0x0F
end_define

begin_comment
comment|/* Enable RXD,TXD,RNE,TNE */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_IRQMSK
value|0x60
end_define

begin_comment
comment|/* Interrupt Select */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_IRQ5
value|0x00
end_define

begin_comment
comment|/*   Select IRQ 5 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_IRQ10
value|0x20
end_define

begin_comment
comment|/*   Select IRQ 10 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_IRQ11
value|0x40
end_define

begin_comment
comment|/*   Select IRQ 11 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_IRQ15
value|0x60
end_define

begin_comment
comment|/*   Select IRQ 15 */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IC_IE
value|0x80
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_comment
comment|/* I/O Page Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IOP_EEINIT
value|0xC0
end_define

begin_comment
comment|/* Perform a board init/reset */
end_comment

begin_define
define|#
directive|define
name|LEMAC_IOP_EEREAD
value|0xE0
end_define

begin_comment
comment|/* Start a read from EEPROM */
end_comment

begin_comment
comment|/* Configuration / Management Definitions */
end_comment

begin_define
define|#
directive|define
name|LEMAC_CNF_DRAM
value|0x02
end_define

begin_comment
comment|/* Extra on-board DRAM is available */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LEMAC_H_ */
end_comment

end_unit

