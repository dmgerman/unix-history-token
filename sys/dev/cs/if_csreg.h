begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997,1998 Maxim Bolotin and Oleg Sharoiko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|CS_89x0_IO_PORTS
value|0x0020
end_define

begin_define
define|#
directive|define
name|PP_ChipID
value|0x0000
end_define

begin_comment
comment|/* offset   0h -> Corp -ID              */
end_comment

begin_comment
comment|/* offset   2h -> Model/Product Number  */
end_comment

begin_comment
comment|/* offset   3h -> Chip Revision Number  */
end_comment

begin_define
define|#
directive|define
name|PP_ISAIOB
value|0x0020
end_define

begin_comment
comment|/*  IO base address */
end_comment

begin_define
define|#
directive|define
name|PP_CS8900_ISAINT
value|0x0022
end_define

begin_comment
comment|/*  ISA interrupt select */
end_comment

begin_define
define|#
directive|define
name|PP_CS8900_ISADMA
value|0x0024
end_define

begin_comment
comment|/*  ISA Rec DMA channel */
end_comment

begin_define
define|#
directive|define
name|PP_CS8920_ISAINT
value|0x0370
end_define

begin_comment
comment|/*  ISA interrupt select */
end_comment

begin_define
define|#
directive|define
name|PP_CS8920_ISADMA
value|0x0374
end_define

begin_comment
comment|/*  ISA Rec DMA channel */
end_comment

begin_define
define|#
directive|define
name|PP_ISASOF
value|0x0026
end_define

begin_comment
comment|/*  ISA DMA offset */
end_comment

begin_define
define|#
directive|define
name|PP_DmaFrameCnt
value|0x0028
end_define

begin_comment
comment|/*  ISA DMA Frame count */
end_comment

begin_define
define|#
directive|define
name|PP_DmaByteCnt
value|0x002A
end_define

begin_comment
comment|/*  ISA DMA Byte count */
end_comment

begin_define
define|#
directive|define
name|PP_CS8920_ISAMemB
value|0x0348
end_define

begin_comment
comment|/*  Memory base */
end_comment

begin_comment
comment|/* EEPROM data and command registers */
end_comment

begin_define
define|#
directive|define
name|PP_EECMD
value|0x0040
end_define

begin_comment
comment|/*  NVR Interface Command register */
end_comment

begin_define
define|#
directive|define
name|PP_EEData
value|0x0042
end_define

begin_comment
comment|/*  NVR Interface Data Register */
end_comment

begin_define
define|#
directive|define
name|PP_DebugReg
value|0x0044
end_define

begin_comment
comment|/*  Debug Register */
end_comment

begin_define
define|#
directive|define
name|PP_RxCFG
value|0x0102
end_define

begin_comment
comment|/*  Rx Bus config */
end_comment

begin_define
define|#
directive|define
name|PP_RxCTL
value|0x0104
end_define

begin_comment
comment|/*  Receive Control Register */
end_comment

begin_define
define|#
directive|define
name|PP_TxCFG
value|0x0106
end_define

begin_comment
comment|/*  Transmit Config Register */
end_comment

begin_define
define|#
directive|define
name|PP_TxCMD
value|0x0108
end_define

begin_comment
comment|/*  Transmit Command Register */
end_comment

begin_define
define|#
directive|define
name|PP_BufCFG
value|0x010A
end_define

begin_comment
comment|/*  Bus configuration Register */
end_comment

begin_define
define|#
directive|define
name|PP_LineCTL
value|0x0112
end_define

begin_comment
comment|/*  Line Config Register */
end_comment

begin_define
define|#
directive|define
name|PP_SelfCTL
value|0x0114
end_define

begin_comment
comment|/*  Self Command Register */
end_comment

begin_define
define|#
directive|define
name|PP_BusCTL
value|0x0116
end_define

begin_comment
comment|/*  ISA bus control Register */
end_comment

begin_define
define|#
directive|define
name|PP_TestCTL
value|0x0118
end_define

begin_comment
comment|/*  Test Register */
end_comment

begin_define
define|#
directive|define
name|PP_AutoNegCTL
value|0x011C
end_define

begin_comment
comment|/*  Auto Negotiation Ctrl */
end_comment

begin_define
define|#
directive|define
name|PP_ISQ
value|0x0120
end_define

begin_comment
comment|/*  Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|PP_RxEvent
value|0x0124
end_define

begin_comment
comment|/*  Rx Event Register */
end_comment

begin_define
define|#
directive|define
name|PP_TxEvent
value|0x0128
end_define

begin_comment
comment|/*  Tx Event Register */
end_comment

begin_define
define|#
directive|define
name|PP_BufEvent
value|0x012C
end_define

begin_comment
comment|/*  Bus Event Register */
end_comment

begin_define
define|#
directive|define
name|PP_RxMiss
value|0x0130
end_define

begin_comment
comment|/*  Receive Miss Count */
end_comment

begin_define
define|#
directive|define
name|PP_TxCol
value|0x0132
end_define

begin_comment
comment|/*  Transmit Collision Count */
end_comment

begin_define
define|#
directive|define
name|PP_LineST
value|0x0134
end_define

begin_comment
comment|/*  Line State Register */
end_comment

begin_define
define|#
directive|define
name|PP_SelfST
value|0x0136
end_define

begin_comment
comment|/*  Self State register */
end_comment

begin_define
define|#
directive|define
name|PP_BusST
value|0x0138
end_define

begin_comment
comment|/*  Bus Status */
end_comment

begin_define
define|#
directive|define
name|PP_TDR
value|0x013C
end_define

begin_comment
comment|/*  Time Domain Reflectometry */
end_comment

begin_define
define|#
directive|define
name|PP_AutoNegST
value|0x013E
end_define

begin_comment
comment|/*  Auto Neg Status */
end_comment

begin_define
define|#
directive|define
name|PP_TxCommand
value|0x0144
end_define

begin_comment
comment|/*  Tx Command */
end_comment

begin_define
define|#
directive|define
name|PP_TxLength
value|0x0146
end_define

begin_comment
comment|/*  Tx Length */
end_comment

begin_define
define|#
directive|define
name|PP_LAF
value|0x0150
end_define

begin_comment
comment|/*  Hash Table */
end_comment

begin_define
define|#
directive|define
name|PP_IA
value|0x0158
end_define

begin_comment
comment|/*  Physical Address Register */
end_comment

begin_define
define|#
directive|define
name|PP_RxStatus
value|0x0400
end_define

begin_comment
comment|/*  Receive start of frame */
end_comment

begin_define
define|#
directive|define
name|PP_RxLength
value|0x0402
end_define

begin_comment
comment|/*  Receive Length of frame */
end_comment

begin_define
define|#
directive|define
name|PP_RxFrame
value|0x0404
end_define

begin_comment
comment|/*  Receive frame pointer */
end_comment

begin_define
define|#
directive|define
name|PP_TxFrame
value|0x0A00
end_define

begin_comment
comment|/*  Transmit frame pointer */
end_comment

begin_comment
comment|/*  *  Primary I/O Base Address. If no I/O base is supplied by the user, then this  *  can be used as the default I/O base to access the PacketPage Area.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULTIOBASE
value|0x0300
end_define

begin_define
define|#
directive|define
name|FIRST_IO
value|0x020C
end_define

begin_comment
comment|/*  First I/O port to check */
end_comment

begin_define
define|#
directive|define
name|LAST_IO
value|0x037C
end_define

begin_comment
comment|/*  Last I/O port to check (+10h) */
end_comment

begin_define
define|#
directive|define
name|ADD_MASK
value|0x3000
end_define

begin_comment
comment|/*  Mask it use of the ADD_PORT register */
end_comment

begin_define
define|#
directive|define
name|ADD_SIG
value|0x3000
end_define

begin_comment
comment|/*  Expected ID signature */
end_comment

begin_define
define|#
directive|define
name|CHIP_EISA_ID_SIG
value|0x630E
end_define

begin_comment
comment|/*  Product ID Code for Crystal Chip (CS8900 spec 4.3) */
end_comment

begin_define
define|#
directive|define
name|PRODUCT_ID_ADD
value|0x0002
end_define

begin_comment
comment|/*  Address of product ID */
end_comment

begin_comment
comment|/*  Mask to find out the types of  registers */
end_comment

begin_define
define|#
directive|define
name|REG_TYPE_MASK
value|0x001F
end_define

begin_comment
comment|/*  Eeprom Commands */
end_comment

begin_define
define|#
directive|define
name|ERSE_WR_ENBL
value|0x00F0
end_define

begin_define
define|#
directive|define
name|ERSE_WR_DISABLE
value|0x0000
end_define

begin_comment
comment|/*  Defines Control/Config register quintuplet numbers */
end_comment

begin_define
define|#
directive|define
name|RX_BUF_CFG
value|0x0003
end_define

begin_define
define|#
directive|define
name|RX_CONTROL
value|0x0005
end_define

begin_define
define|#
directive|define
name|TX_CFG
value|0x0007
end_define

begin_define
define|#
directive|define
name|TX_COMMAND
value|0x0009
end_define

begin_define
define|#
directive|define
name|BUF_CFG
value|0x000B
end_define

begin_define
define|#
directive|define
name|LINE_CONTROL
value|0x0013
end_define

begin_define
define|#
directive|define
name|SELF_CONTROL
value|0x0015
end_define

begin_define
define|#
directive|define
name|BUS_CONTROL
value|0x0017
end_define

begin_define
define|#
directive|define
name|TEST_CONTROL
value|0x0019
end_define

begin_comment
comment|/*  Defines Status/Count registers quintuplet numbers */
end_comment

begin_define
define|#
directive|define
name|RX_EVENT
value|0x0004
end_define

begin_define
define|#
directive|define
name|TX_EVENT
value|0x0008
end_define

begin_define
define|#
directive|define
name|BUF_EVENT
value|0x000C
end_define

begin_define
define|#
directive|define
name|RX_MISS_COUNT
value|0x0010
end_define

begin_define
define|#
directive|define
name|TX_COL_COUNT
value|0x0012
end_define

begin_define
define|#
directive|define
name|LINE_STATUS
value|0x0014
end_define

begin_define
define|#
directive|define
name|SELF_STATUS
value|0x0016
end_define

begin_define
define|#
directive|define
name|BUS_STATUS
value|0x0018
end_define

begin_define
define|#
directive|define
name|TDR
value|0x001C
end_define

begin_comment
comment|/*  * PP_RxCFG - Receive  Configuration and Interrupt Mask  *			 bit definition -  Read/write  */
end_comment

begin_define
define|#
directive|define
name|SKIP_1
value|0x0040
end_define

begin_define
define|#
directive|define
name|RX_STREAM_ENBL
value|0x0080
end_define

begin_define
define|#
directive|define
name|RX_OK_ENBL
value|0x0100
end_define

begin_define
define|#
directive|define
name|RX_DMA_ONLY
value|0x0200
end_define

begin_define
define|#
directive|define
name|AUTO_RX_DMA
value|0x0400
end_define

begin_define
define|#
directive|define
name|BUFFER_CRC
value|0x0800
end_define

begin_define
define|#
directive|define
name|RX_CRC_ERROR_ENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|RX_RUNT_ENBL
value|0x2000
end_define

begin_define
define|#
directive|define
name|RX_EXTRA_DATA_ENBL
value|0x4000
end_define

begin_comment
comment|/* PP_RxCTL - Receive Control bit definition - Read/write */
end_comment

begin_define
define|#
directive|define
name|RX_IA_HASH_ACCEPT
value|0x0040
end_define

begin_define
define|#
directive|define
name|RX_PROM_ACCEPT
value|0x0080
end_define

begin_define
define|#
directive|define
name|RX_OK_ACCEPT
value|0x0100
end_define

begin_define
define|#
directive|define
name|RX_MULTCAST_ACCEPT
value|0x0200
end_define

begin_define
define|#
directive|define
name|RX_IA_ACCEPT
value|0x0400
end_define

begin_define
define|#
directive|define
name|RX_BROADCAST_ACCEPT
value|0x0800
end_define

begin_define
define|#
directive|define
name|RX_BAD_CRC_ACCEPT
value|0x1000
end_define

begin_define
define|#
directive|define
name|RX_RUNT_ACCEPT
value|0x2000
end_define

begin_define
define|#
directive|define
name|RX_EXTRA_DATA_ACCEPT
value|0x4000
end_define

begin_define
define|#
directive|define
name|RX_ALL_ACCEPT
value|(RX_PROM_ACCEPT | RX_BAD_CRC_ACCEPT |	\ 				 RX_RUNT_ACCEPT | RX_EXTRA_DATA_ACCEPT)
end_define

begin_comment
comment|/*  *  Default receive mode - individually addressed, broadcast, and error free  */
end_comment

begin_define
define|#
directive|define
name|RX_DEF_ACCEPT
value|(RX_IA_ACCEPT | RX_BROADCAST_ACCEPT | RX_OK_ACCEPT)
end_define

begin_comment
comment|/*  * PP_TxCFG - Transmit Configuration Interrupt Mask  *			 bit definition - Read/write  */
end_comment

begin_define
define|#
directive|define
name|TX_LOST_CRS_ENBL
value|0x0040
end_define

begin_define
define|#
directive|define
name|TX_SQE_ERROR_ENBL
value|0x0080
end_define

begin_define
define|#
directive|define
name|TX_OK_ENBL
value|0x0100
end_define

begin_define
define|#
directive|define
name|TX_LATE_COL_ENBL
value|0x0200
end_define

begin_define
define|#
directive|define
name|TX_JBR_ENBL
value|0x0400
end_define

begin_define
define|#
directive|define
name|TX_ANY_COL_ENBL
value|0x0800
end_define

begin_define
define|#
directive|define
name|TX_16_COL_ENBL
value|0x8000
end_define

begin_comment
comment|/*  * PP_TxCMD - Transmit Command bit definition - Read-only  */
end_comment

begin_define
define|#
directive|define
name|TX_START_4_BYTES
value|0x0000
end_define

begin_define
define|#
directive|define
name|TX_START_64_BYTES
value|0x0040
end_define

begin_define
define|#
directive|define
name|TX_START_128_BYTES
value|0x0080
end_define

begin_define
define|#
directive|define
name|TX_START_ALL_BYTES
value|0x00C0
end_define

begin_define
define|#
directive|define
name|TX_FORCE
value|0x0100
end_define

begin_define
define|#
directive|define
name|TX_ONE_COL
value|0x0200
end_define

begin_define
define|#
directive|define
name|TX_TWO_PART_DEFF_DISABLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|TX_NO_CRC
value|0x1000
end_define

begin_define
define|#
directive|define
name|TX_RUNT
value|0x2000
end_define

begin_comment
comment|/*  * PP_BufCFG - Buffer Configuration Interrupt Mask  *			 bit definition - Read/write  */
end_comment

begin_define
define|#
directive|define
name|GENERATE_SW_INTERRUPT
value|0x0040
end_define

begin_define
define|#
directive|define
name|RX_DMA_ENBL
value|0x0080
end_define

begin_define
define|#
directive|define
name|READY_FOR_TX_ENBL
value|0x0100
end_define

begin_define
define|#
directive|define
name|TX_UNDERRUN_ENBL
value|0x0200
end_define

begin_define
define|#
directive|define
name|RX_MISS_ENBL
value|0x0400
end_define

begin_define
define|#
directive|define
name|RX_128_BYTE_ENBL
value|0x0800
end_define

begin_define
define|#
directive|define
name|TX_COL_COUNT_OVRFLOW_ENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|RX_MISS_COUNT_OVRFLOW_ENBL
value|0x2000
end_define

begin_define
define|#
directive|define
name|RX_DEST_MATCH_ENBL
value|0x8000
end_define

begin_comment
comment|/*  * PP_LineCTL - Line Control bit definition - Read/write  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_RX_ON
value|0x0040
end_define

begin_define
define|#
directive|define
name|SERIAL_TX_ON
value|0x0080
end_define

begin_define
define|#
directive|define
name|AUI_ONLY
value|0x0100
end_define

begin_define
define|#
directive|define
name|AUTO_AUI_10BASET
value|0x0200
end_define

begin_define
define|#
directive|define
name|MODIFIED_BACKOFF
value|0x0800
end_define

begin_define
define|#
directive|define
name|NO_AUTO_POLARITY
value|0x1000
end_define

begin_define
define|#
directive|define
name|TWO_PART_DEFDIS
value|0x2000
end_define

begin_define
define|#
directive|define
name|LOW_RX_SQUELCH
value|0x4000
end_define

begin_comment
comment|/*  * PP_SelfCTL - Software Self Control bit definition - Read/write  */
end_comment

begin_define
define|#
directive|define
name|POWER_ON_RESET
value|0x0040
end_define

begin_define
define|#
directive|define
name|SW_STOP
value|0x0100
end_define

begin_define
define|#
directive|define
name|SLEEP_ON
value|0x0200
end_define

begin_define
define|#
directive|define
name|AUTO_WAKEUP
value|0x0400
end_define

begin_define
define|#
directive|define
name|HCB0_ENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|HCB1_ENBL
value|0x2000
end_define

begin_define
define|#
directive|define
name|HCB0
value|0x4000
end_define

begin_define
define|#
directive|define
name|HCB1
value|0x8000
end_define

begin_comment
comment|/*  * PP_BusCTL - ISA Bus Control bit definition - Read/write  */
end_comment

begin_define
define|#
directive|define
name|RESET_RX_DMA
value|0x0040
end_define

begin_define
define|#
directive|define
name|MEMORY_ON
value|0x0400
end_define

begin_define
define|#
directive|define
name|DMA_BURST_MODE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IO_CHANNEL_READY_ON
value|0x1000
end_define

begin_define
define|#
directive|define
name|RX_DMA_SIZE_64Ks
value|0x2000
end_define

begin_define
define|#
directive|define
name|ENABLE_IRQ
value|0x8000
end_define

begin_comment
comment|/*  * PP_TestCTL - Test Control bit definition - Read/write  */
end_comment

begin_define
define|#
directive|define
name|LINK_OFF
value|0x0080
end_define

begin_define
define|#
directive|define
name|ENDEC_LOOPBACK
value|0x0200
end_define

begin_define
define|#
directive|define
name|AUI_LOOPBACK
value|0x0400
end_define

begin_define
define|#
directive|define
name|BACKOFF_OFF
value|0x0800
end_define

begin_define
define|#
directive|define
name|FAST_TEST
value|0x8000
end_define

begin_comment
comment|/*  * PP_RxEvent - Receive Event Bit definition - Read-only  */
end_comment

begin_define
define|#
directive|define
name|RX_IA_HASHED
value|0x0040
end_define

begin_define
define|#
directive|define
name|RX_DRIBBLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|RX_OK
value|0x0100
end_define

begin_define
define|#
directive|define
name|RX_HASHED
value|0x0200
end_define

begin_define
define|#
directive|define
name|RX_IA
value|0x0400
end_define

begin_define
define|#
directive|define
name|RX_BROADCAST
value|0x0800
end_define

begin_define
define|#
directive|define
name|RX_CRC_ERROR
value|0x1000
end_define

begin_define
define|#
directive|define
name|RX_RUNT
value|0x2000
end_define

begin_define
define|#
directive|define
name|RX_EXTRA_DATA
value|0x4000
end_define

begin_define
define|#
directive|define
name|HASH_INDEX_MASK
value|0x0FC00
end_define

begin_comment
comment|/*  * PP_TxEvent - Transmit Event Bit definition - Read-only  */
end_comment

begin_define
define|#
directive|define
name|TX_LOST_CRS
value|0x0040
end_define

begin_define
define|#
directive|define
name|TX_SQE_ERROR
value|0x0080
end_define

begin_define
define|#
directive|define
name|TX_OK
value|0x0100
end_define

begin_define
define|#
directive|define
name|TX_LATE_COL
value|0x0200
end_define

begin_define
define|#
directive|define
name|TX_JBR
value|0x0400
end_define

begin_define
define|#
directive|define
name|TX_16_COL
value|0x8000
end_define

begin_define
define|#
directive|define
name|TX_SEND_OK_BITS
value|(TX_OK | TX_LOST_CRS)
end_define

begin_define
define|#
directive|define
name|TX_COL_COUNT_MASK
value|0x7800
end_define

begin_comment
comment|/*  * PP_BufEvent - Buffer Event Bit definition - Read-only  */
end_comment

begin_define
define|#
directive|define
name|SW_INTERRUPT
value|0x0040
end_define

begin_define
define|#
directive|define
name|RX_DMA
value|0x0080
end_define

begin_define
define|#
directive|define
name|READY_FOR_TX
value|0x0100
end_define

begin_define
define|#
directive|define
name|TX_UNDERRUN
value|0x0200
end_define

begin_define
define|#
directive|define
name|RX_MISS
value|0x0400
end_define

begin_define
define|#
directive|define
name|RX_128_BYTE
value|0x0800
end_define

begin_define
define|#
directive|define
name|TX_COL_OVRFLW
value|0x1000
end_define

begin_define
define|#
directive|define
name|RX_MISS_OVRFLW
value|0x2000
end_define

begin_define
define|#
directive|define
name|RX_DEST_MATCH
value|0x8000
end_define

begin_comment
comment|/*  * PP_LineST - Ethernet Line Status bit definition - Read-only  */
end_comment

begin_define
define|#
directive|define
name|LINK_OK
value|0x0080
end_define

begin_define
define|#
directive|define
name|AUI_ON
value|0x0100
end_define

begin_define
define|#
directive|define
name|TENBASET_ON
value|0x0200
end_define

begin_define
define|#
directive|define
name|POLARITY_OK
value|0x1000
end_define

begin_define
define|#
directive|define
name|CRS_OK
value|0x4000
end_define

begin_comment
comment|/*  * PP_SelfST - Chip Software Status bit definition  */
end_comment

begin_define
define|#
directive|define
name|ACTIVE_33V
value|0x0040
end_define

begin_define
define|#
directive|define
name|INIT_DONE
value|0x0080
end_define

begin_define
define|#
directive|define
name|SI_BUSY
value|0x0100
end_define

begin_define
define|#
directive|define
name|EEPROM_PRESENT
value|0x0200
end_define

begin_define
define|#
directive|define
name|EEPROM_OK
value|0x0400
end_define

begin_define
define|#
directive|define
name|EL_PRESENT
value|0x0800
end_define

begin_define
define|#
directive|define
name|EE_SIZE_64
value|0x1000
end_define

begin_comment
comment|/*  * PP_BusST - ISA Bus Status bit definition  */
end_comment

begin_define
define|#
directive|define
name|TX_BID_ERROR
value|0x0080
end_define

begin_define
define|#
directive|define
name|READY_FOR_TX_NOW
value|0x0100
end_define

begin_comment
comment|/*  * PP_AutoNegCTL - Auto Negotiation Control bit definition  */
end_comment

begin_define
define|#
directive|define
name|RE_NEG_NOW
value|0x0040
end_define

begin_define
define|#
directive|define
name|ALLOW_FDX
value|0x0080
end_define

begin_define
define|#
directive|define
name|AUTO_NEG_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|NLP_ENABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|FORCE_FDX
value|0x8000
end_define

begin_define
define|#
directive|define
name|AUTO_NEG_BITS
value|(FORCE_FDX | NLP_ENABLE | AUTO_NEG_ENABLE)
end_define

begin_define
define|#
directive|define
name|AUTO_NEG_MASK
value|(FORCE_FDX | NLP_ENABLE | AUTO_NEG_ENABLE | \ 				 ALLOW_FDX | RE_NEG_NOW)
end_define

begin_comment
comment|/*  * PP_AutoNegST - Auto Negotiation Status bit definition  */
end_comment

begin_define
define|#
directive|define
name|AUTO_NEG_BUSY
value|0x0080
end_define

begin_define
define|#
directive|define
name|FLP_LINK
value|0x0100
end_define

begin_define
define|#
directive|define
name|FLP_LINK_GOOD
value|0x0800
end_define

begin_define
define|#
directive|define
name|LINK_FAULT
value|0x1000
end_define

begin_define
define|#
directive|define
name|HDX_ACTIVE
value|0x4000
end_define

begin_define
define|#
directive|define
name|FDX_ACTIVE
value|0x8000
end_define

begin_comment
comment|/*  * The following block defines the ISQ event types  */
end_comment

begin_define
define|#
directive|define
name|ISQ_RECEIVER_EVENT
value|0x04
end_define

begin_define
define|#
directive|define
name|ISQ_TRANSMITTER_EVENT
value|0x08
end_define

begin_define
define|#
directive|define
name|ISQ_BUFFER_EVENT
value|0x0c
end_define

begin_define
define|#
directive|define
name|ISQ_RX_MISS_EVENT
value|0x10
end_define

begin_define
define|#
directive|define
name|ISQ_TX_COL_EVENT
value|0x12
end_define

begin_define
define|#
directive|define
name|ISQ_EVENT_MASK
value|0x003F
end_define

begin_comment
comment|/* ISQ mask to find out type of event */
end_comment

begin_define
define|#
directive|define
name|ISQ_HIST
value|16
end_define

begin_comment
comment|/* small history buffer */
end_comment

begin_define
define|#
directive|define
name|AUTOINCREMENT
value|0x8000
end_define

begin_comment
comment|/* Bit mask to set bit-15 for autoincrement */
end_comment

begin_define
define|#
directive|define
name|TXRXBUFSIZE
value|0x0600
end_define

begin_define
define|#
directive|define
name|RXDMABUFSIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|RXDMASIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|TXRX_LENGTH_MASK
value|0x07FF
end_define

begin_comment
comment|/*  rx options bits */
end_comment

begin_define
define|#
directive|define
name|RCV_WITH_RXON
value|1
end_define

begin_comment
comment|/*  Set SerRx ON */
end_comment

begin_define
define|#
directive|define
name|RCV_COUNTS
value|2
end_define

begin_comment
comment|/*  Use Framecnt1 */
end_comment

begin_define
define|#
directive|define
name|RCV_PONG
value|4
end_define

begin_comment
comment|/*  Pong respondent */
end_comment

begin_define
define|#
directive|define
name|RCV_DONG
value|8
end_define

begin_comment
comment|/*  Dong operation */
end_comment

begin_define
define|#
directive|define
name|RCV_POLLING
value|0x10
end_define

begin_comment
comment|/*  Poll RxEvent */
end_comment

begin_define
define|#
directive|define
name|RCV_ISQ
value|0x20
end_define

begin_comment
comment|/*  Use ISQ, int */
end_comment

begin_define
define|#
directive|define
name|RCV_AUTO_DMA
value|0x100
end_define

begin_comment
comment|/*  Set AutoRxDMAE */
end_comment

begin_define
define|#
directive|define
name|RCV_DMA
value|0x200
end_define

begin_comment
comment|/*  Set RxDMA only */
end_comment

begin_define
define|#
directive|define
name|RCV_DMA_ALL
value|0x400
end_define

begin_comment
comment|/*  Copy all DMA'ed */
end_comment

begin_define
define|#
directive|define
name|RCV_FIXED_DATA
value|0x800
end_define

begin_comment
comment|/*  Every frame same */
end_comment

begin_define
define|#
directive|define
name|RCV_IO
value|0x1000
end_define

begin_comment
comment|/*  Use ISA IO only */
end_comment

begin_define
define|#
directive|define
name|RCV_MEMORY
value|0x2000
end_define

begin_comment
comment|/*  Use ISA Memory */
end_comment

begin_define
define|#
directive|define
name|RAM_SIZE
value|0x1000
end_define

begin_comment
comment|/*  The card has 4k bytes or RAM */
end_comment

begin_define
define|#
directive|define
name|PKT_START
value|PP_TxFrame
end_define

begin_comment
comment|/*  Start of packet RAM */
end_comment

begin_define
define|#
directive|define
name|RX_FRAME_PORT
value|0x0000
end_define

begin_define
define|#
directive|define
name|TX_FRAME_PORT
value|RX_FRAME_PORT
end_define

begin_define
define|#
directive|define
name|TX_CMD_PORT
value|0x0004
end_define

begin_define
define|#
directive|define
name|TX_CS8900_NOW
value|0x0000
end_define

begin_comment
comment|/* Tx packet after   5 bytes copied */
end_comment

begin_define
define|#
directive|define
name|TX_CS8900_AFTER_381
value|0x0020
end_define

begin_comment
comment|/* Tx packet after 381 bytes copied */
end_comment

begin_define
define|#
directive|define
name|TX_CS8900_AFTER_ALL
value|0x0060
end_define

begin_comment
comment|/* Tx packet after all bytes copied */
end_comment

begin_define
define|#
directive|define
name|TX_CS8920_NOW
value|0x0000
end_define

begin_comment
comment|/* Tx packet after   5 bytes copied */
end_comment

begin_define
define|#
directive|define
name|TX_CS8920_AFTER_381
value|0x0040
end_define

begin_comment
comment|/* Tx packet after 381 bytes copied */
end_comment

begin_define
define|#
directive|define
name|TX_CS8920_AFTER_1021
value|0x0080
end_define

begin_comment
comment|/* Tx packet after1021 bytes copied */
end_comment

begin_define
define|#
directive|define
name|TX_CS8920_AFTER_ALL
value|0x00C0
end_define

begin_comment
comment|/* Tx packet after all bytes copied */
end_comment

begin_define
define|#
directive|define
name|TX_LEN_PORT
value|0x0006
end_define

begin_define
define|#
directive|define
name|ISQ_PORT
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADD_PORT
value|0x000A
end_define

begin_define
define|#
directive|define
name|DATA_PORT
value|0x000C
end_define

begin_define
define|#
directive|define
name|EEPROM_WRITE_EN
value|0x00F0
end_define

begin_define
define|#
directive|define
name|EEPROM_WRITE_DIS
value|0x0000
end_define

begin_define
define|#
directive|define
name|EEPROM_WRITE_CMD
value|0x0100
end_define

begin_define
define|#
directive|define
name|EEPROM_READ_CMD
value|0x0200
end_define

begin_comment
comment|/*  Receive Header  *  Description of header of each packet in receive area of memory  */
end_comment

begin_define
define|#
directive|define
name|RBUF_EVENT_LOW
value|0
end_define

begin_comment
comment|/* Low byte of RxEvent - status of received frame */
end_comment

begin_define
define|#
directive|define
name|RBUF_EVENT_HIGH
value|1
end_define

begin_comment
comment|/* High byte of RxEvent - status of received frame */
end_comment

begin_define
define|#
directive|define
name|RBUF_LEN_LOW
value|2
end_define

begin_comment
comment|/* Length of received data - low byte */
end_comment

begin_define
define|#
directive|define
name|RBUF_LEN_HI
value|3
end_define

begin_comment
comment|/* Length of received data - high byte */
end_comment

begin_define
define|#
directive|define
name|RBUF_HEAD_LEN
value|4
end_define

begin_comment
comment|/* Length of this header */
end_comment

begin_define
define|#
directive|define
name|CHIP_READ
value|0x1
end_define

begin_comment
comment|/* Used to mark state of the repins code (chip or dma) */
end_comment

begin_define
define|#
directive|define
name|DMA_READ
value|0x2
end_define

begin_comment
comment|/* Used to mark state of the repins code (chip or dma) */
end_comment

begin_comment
comment|/*  for bios scan */
end_comment

begin_comment
comment|/*  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CSDEBUG
end_ifdef

begin_comment
comment|/*  use these values for debugging bios scan */
end_comment

begin_define
define|#
directive|define
name|BIOS_START_SEG
value|0x00000
end_define

begin_define
define|#
directive|define
name|BIOS_OFFSET_INC
value|0x0010
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BIOS_START_SEG
value|0x0c000
end_define

begin_define
define|#
directive|define
name|BIOS_OFFSET_INC
value|0x0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BIOS_LAST_OFFSET
value|0x0fc00
end_define

begin_comment
comment|/*  *  Byte offsets into the EEPROM configuration buffer  */
end_comment

begin_define
define|#
directive|define
name|ISA_CNF_OFFSET
value|0x6
end_define

begin_define
define|#
directive|define
name|TX_CTL_OFFSET
value|(ISA_CNF_OFFSET + 8)
end_define

begin_comment
comment|/*  8900 eeprom */
end_comment

begin_define
define|#
directive|define
name|AUTO_NEG_CNF_OFFSET
value|(ISA_CNF_OFFSET + 8)
end_define

begin_comment
comment|/*  8920 eeprom */
end_comment

begin_comment
comment|/*  *  the assumption here is that the bits in the eeprom are generally   *  in the same position as those in the autonegctl register.   *  Of course the IMM bit is not in that register so it must be   *  masked out  */
end_comment

begin_define
define|#
directive|define
name|EE_FORCE_FDX
value|0x8000
end_define

begin_define
define|#
directive|define
name|EE_NLP_ENABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|EE_AUTO_NEG_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|EE_ALLOW_FDX
value|0x0080
end_define

begin_define
define|#
directive|define
name|EE_AUTO_NEG_CNF_MASK
value|(EE_FORCE_FDX | EE_NLP_ENABLE | 	\ 				 EE_AUTO_NEG_ENABLE | EE_ALLOW_FDX)
end_define

begin_define
define|#
directive|define
name|IMM_BIT
value|0x0040
end_define

begin_comment
comment|/*  ignore missing media	 */
end_comment

begin_define
define|#
directive|define
name|ADAPTER_CNF_OFFSET
value|(AUTO_NEG_CNF_OFFSET + 2)
end_define

begin_define
define|#
directive|define
name|A_CNF_MEDIA
value|0x0007
end_define

begin_define
define|#
directive|define
name|A_CNF_10B_T
value|0x0001
end_define

begin_define
define|#
directive|define
name|A_CNF_AUI
value|0x0002
end_define

begin_define
define|#
directive|define
name|A_CNF_10B_2
value|0x0004
end_define

begin_define
define|#
directive|define
name|A_CNF_MEDIA_TYPE
value|0x0060
end_define

begin_define
define|#
directive|define
name|A_CNF_MEDIA_AUTO
value|0x0000
end_define

begin_define
define|#
directive|define
name|A_CNF_MEDIA_10B_T
value|0x0020
end_define

begin_define
define|#
directive|define
name|A_CNF_MEDIA_AUI
value|0x0040
end_define

begin_define
define|#
directive|define
name|A_CNF_MEDIA_10B_2
value|0x0060
end_define

begin_define
define|#
directive|define
name|A_CNF_DC_DC_POLARITY
value|0x0080
end_define

begin_define
define|#
directive|define
name|A_CNF_NO_AUTO_POLARITY
value|0x2000
end_define

begin_define
define|#
directive|define
name|A_CNF_LOW_RX_SQUELCH
value|0x4000
end_define

begin_define
define|#
directive|define
name|A_CNF_EXTND_10B_2
value|0x8000
end_define

begin_define
define|#
directive|define
name|PACKET_PAGE_OFFSET
value|0x8
end_define

begin_comment
comment|/*  *  Bit definitions for the ISA configuration word from the EEPROM  */
end_comment

begin_define
define|#
directive|define
name|INT_NO_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|DMA_NO_MASK
value|0x0070
end_define

begin_define
define|#
directive|define
name|ISA_DMA_SIZE
value|0x0200
end_define

begin_define
define|#
directive|define
name|ISA_AUTO_RxDMA
value|0x0400
end_define

begin_define
define|#
directive|define
name|ISA_RxDMA
value|0x0800
end_define

begin_define
define|#
directive|define
name|DMA_BURST
value|0x1000
end_define

begin_define
define|#
directive|define
name|STREAM_TRANSFER
value|0x2000
end_define

begin_define
define|#
directive|define
name|ANY_ISA_DMA
value|(ISA_AUTO_RxDMA | ISA_RxDMA)
end_define

begin_comment
comment|/*  DMA controller registers */
end_comment

begin_define
define|#
directive|define
name|DMA_BASE
value|0x00
end_define

begin_comment
comment|/* DMA controller base */
end_comment

begin_define
define|#
directive|define
name|DMA_BASE_2
value|0x0C0
end_define

begin_comment
comment|/* DMA controller base */
end_comment

begin_define
define|#
directive|define
name|DMA_STAT
value|0x0D0
end_define

begin_comment
comment|/* DMA controller status register */
end_comment

begin_define
define|#
directive|define
name|DMA_MASK
value|0x0D4
end_define

begin_comment
comment|/* DMA controller mask register */
end_comment

begin_define
define|#
directive|define
name|DMA_MODE
value|0x0D6
end_define

begin_comment
comment|/* DMA controller mode register */
end_comment

begin_define
define|#
directive|define
name|DMA_RESETFF
value|0x0D8
end_define

begin_comment
comment|/* DMA controller first/last flip flop */
end_comment

begin_comment
comment|/*  DMA data */
end_comment

begin_define
define|#
directive|define
name|DMA_DISABLE
value|0x04
end_define

begin_comment
comment|/*  Disable channel n */
end_comment

begin_define
define|#
directive|define
name|DMA_ENABLE
value|0x00
end_define

begin_comment
comment|/*  Enable channel n */
end_comment

begin_comment
comment|/*  Demand transfers, incr. address, auto init, writes, ch. n */
end_comment

begin_define
define|#
directive|define
name|DMA_RX_MODE
value|0x14
end_define

begin_comment
comment|/*  Demand transfers, incr. address, auto init, reads, ch. n */
end_comment

begin_define
define|#
directive|define
name|DMA_TX_MODE
value|0x18
end_define

begin_define
define|#
directive|define
name|DMA_SIZE
value|(16*1024)
end_define

begin_comment
comment|/* Size of dma buffer - 16k */
end_comment

begin_define
define|#
directive|define
name|CS8900
value|0x0000
end_define

begin_define
define|#
directive|define
name|CS8920
value|0x4000
end_define

begin_define
define|#
directive|define
name|CS8920M
value|0x6000
end_define

begin_define
define|#
directive|define
name|REVISON_BITS
value|0x1F00
end_define

begin_define
define|#
directive|define
name|EEVER_NUMBER
value|0x12
end_define

begin_define
define|#
directive|define
name|CHKSUM_LEN
value|0x14
end_define

begin_define
define|#
directive|define
name|CHKSUM_VAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|START_EEPROM_DATA
value|0x001c
end_define

begin_comment
comment|/* Offset into eeprom for start of data */
end_comment

begin_define
define|#
directive|define
name|IRQ_MAP_EEPROM_DATA
value|0x0046
end_define

begin_comment
comment|/* Offset into eeprom for the IRQ map */
end_comment

begin_define
define|#
directive|define
name|IRQ_MAP_LEN
value|0x0004
end_define

begin_comment
comment|/* No of bytes to read for the IRQ map */
end_comment

begin_define
define|#
directive|define
name|PNP_IRQ_FRMT
value|0x0022
end_define

begin_comment
comment|/* PNP small item IRQ format */
end_comment

begin_define
define|#
directive|define
name|CS8900_IRQ_MAP
value|0x1c20
end_define

begin_comment
comment|/* This IRQ map is fixed */
end_comment

begin_define
define|#
directive|define
name|CS8920_NO_INTS
value|0x0F
end_define

begin_comment
comment|/*  Max CS8920 interrupt select # */
end_comment

begin_define
define|#
directive|define
name|PNP_ADD_PORT
value|0x0279
end_define

begin_define
define|#
directive|define
name|PNP_WRITE_PORT
value|0x0A79
end_define

begin_define
define|#
directive|define
name|GET_PNP_ISA_STRUCT
value|0x40
end_define

begin_define
define|#
directive|define
name|PNP_ISA_STRUCT_LEN
value|0x06
end_define

begin_define
define|#
directive|define
name|PNP_CSN_CNT_OFF
value|0x01
end_define

begin_define
define|#
directive|define
name|PNP_RD_PORT_OFF
value|0x02
end_define

begin_define
define|#
directive|define
name|PNP_FUNCTION_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|PNP_WAKE
value|0x03
end_define

begin_define
define|#
directive|define
name|PNP_RSRC_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|PNP_RSRC_READY
value|0x01
end_define

begin_define
define|#
directive|define
name|PNP_STATUS
value|0x05
end_define

begin_define
define|#
directive|define
name|PNP_ACTIVATE
value|0x30
end_define

begin_define
define|#
directive|define
name|PNP_CNF_IO_H
value|0x60
end_define

begin_define
define|#
directive|define
name|PNP_CNF_IO_L
value|0x61
end_define

begin_define
define|#
directive|define
name|PNP_CNF_INT
value|0x70
end_define

begin_define
define|#
directive|define
name|PNP_CNF_DMA
value|0x74
end_define

begin_define
define|#
directive|define
name|PNP_CNF_MEM
value|0x48
end_define

begin_define
define|#
directive|define
name|BIT0
value|1
end_define

begin_define
define|#
directive|define
name|BIT15
value|0x8000
end_define

begin_define
define|#
directive|define
name|CS_DUPLEX_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|CS_DUPLEX_FULL
value|1
end_define

begin_define
define|#
directive|define
name|CS_DUPLEX_HALF
value|2
end_define

begin_comment
comment|/* Device name */
end_comment

begin_define
define|#
directive|define
name|CS_NAME
value|"cs"
end_define

begin_define
define|#
directive|define
name|cs_readreg
parameter_list|(
name|iobase
parameter_list|,
name|portno
parameter_list|)
define|\
value|(outw((iobase) + ADD_PORT, (portno)), \ 	inw((iobase) + DATA_PORT))
end_define

begin_define
define|#
directive|define
name|cs_writereg
parameter_list|(
name|iobase
parameter_list|,
name|portno
parameter_list|,
name|value
parameter_list|)
define|\
value|(outw((iobase) + ADD_PORT, (portno)), \ 	outw((iobase) + DATA_PORT, (value)))
end_define

begin_define
define|#
directive|define
name|cs_readword
parameter_list|(
name|iobase
parameter_list|,
name|portno
parameter_list|)
define|\
value|(inw((iobase) + (portno)))
end_define

begin_define
define|#
directive|define
name|cs_writeword
parameter_list|(
name|iobase
parameter_list|,
name|portno
parameter_list|,
name|value
parameter_list|)
define|\
value|(outw((iobase) + (portno), (value)))
end_define

begin_define
define|#
directive|define
name|reset_chip
parameter_list|(
name|nic_addr
parameter_list|)
define|\
value|cs_writereg(nic_addr, PP_SelfCTL, cs_readreg(ioaddr, PP_SelfCTL) | POWER_ON_RESET), \ 	DELAY(30000)
end_define

begin_define
define|#
directive|define
name|cs_duplex_full
parameter_list|(
name|sc
parameter_list|)
define|\
value|(cs_writereg(sc->nic_addr, PP_AutoNegCTL, FORCE_FDX))
end_define

begin_define
define|#
directive|define
name|cs_duplex_half
parameter_list|(
name|sc
parameter_list|)
define|\
value|(cs_writereg(sc->nic_addr, PP_AutoNegCTL, NLP_ENABLE))
end_define

end_unit

