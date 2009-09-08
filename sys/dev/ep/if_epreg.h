begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 Herb Peyerl (hpeyerl@novatel.ca) All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2. The name  * of the author may not be used to endorse or promote products derived from  * this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO  * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * DELAY_MULTIPLE: How much to boost "base" delays, except  * for the inter-bit delays in get_eeprom_data.  A cyrix Media GX needed this.  */
end_comment

begin_define
define|#
directive|define
name|DELAY_MULTIPLE
value|10
end_define

begin_define
define|#
directive|define
name|BIT_DELAY_MULTIPLE
value|10
end_define

begin_comment
comment|/*  * Some global constants  */
end_comment

begin_define
define|#
directive|define
name|TX_INIT_RATE
value|16
end_define

begin_define
define|#
directive|define
name|TX_INIT_MAX_RATE
value|64
end_define

begin_define
define|#
directive|define
name|RX_INIT_LATENCY
value|64
end_define

begin_define
define|#
directive|define
name|RX_INIT_EARLY_THRESH
value|208
end_define

begin_comment
comment|/* not less than MINCLSIZE */
end_comment

begin_define
define|#
directive|define
name|RX_NEXT_EARLY_THRESH
value|500
end_define

begin_define
define|#
directive|define
name|EEPROMSIZE
value|0x40
end_define

begin_define
define|#
directive|define
name|MAX_EEPROMBUSY
value|1000
end_define

begin_define
define|#
directive|define
name|EP_LAST_TAG
value|0xd7
end_define

begin_define
define|#
directive|define
name|EP_MAX_BOARDS
value|16
end_define

begin_define
define|#
directive|define
name|EP_IOSIZE
value|16
end_define

begin_comment
comment|/* 16 bytes of I/O space used. */
end_comment

begin_comment
comment|/*  * Commands to read/write EEPROM trough EEPROM command register (Window 0,  * Offset 0xa)  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CMD_RD
value|0x0080
end_define

begin_comment
comment|/* Read:  Address required (5 bits) */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CMD_WR
value|0x0040
end_define

begin_comment
comment|/* Write: Address required (5 bits) */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CMD_ERASE
value|0x00c0
end_define

begin_comment
comment|/* Erase: Address required (5 bits) */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CMD_EWEN
value|0x0030
end_define

begin_comment
comment|/* Erase/Write Enable: No data required */
end_comment

begin_define
define|#
directive|define
name|EEPROM_BUSY
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|EEPROM_TST_MODE
value|(1<<14)
end_define

begin_comment
comment|/*  * Some short functions, worth to let them be a macro  */
end_comment

begin_define
define|#
directive|define
name|is_eeprom_busy
parameter_list|(
name|sc
parameter_list|)
value|(CSR_READ_2(sc, EP_W0_EEPROM_COMMAND)&EEPROM_BUSY)
end_define

begin_define
define|#
directive|define
name|GO_WINDOW
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|CSR_WRITE_2(sc, EP_COMMAND, WINDOW_SELECT|(x))
end_define

begin_comment
comment|/**************************************************************************  *									  *  * These define the EEPROM data structure.  They are used in the probe  * function to verify the existence of the adapter after having sent  * the ID_Sequence.  *  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|EEPROM_NODE_ADDR_0
value|0x0
end_define

begin_comment
comment|/* Word */
end_comment

begin_define
define|#
directive|define
name|EEPROM_NODE_ADDR_1
value|0x1
end_define

begin_comment
comment|/* Word */
end_comment

begin_define
define|#
directive|define
name|EEPROM_NODE_ADDR_2
value|0x2
end_define

begin_comment
comment|/* Word */
end_comment

begin_define
define|#
directive|define
name|EEPROM_PROD_ID
value|0x3
end_define

begin_comment
comment|/* 0x9[0-f]50 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MFG_DATE
value|0x4
end_define

begin_comment
comment|/* Manufacturing date */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MFG_DIVSION
value|0x5
end_define

begin_comment
comment|/* Manufacturing division */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MFG_PRODUCT
value|0x6
end_define

begin_comment
comment|/* Product code */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MFG_ID
value|0x7
end_define

begin_comment
comment|/* 0x6d50 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ADDR_CFG
value|0x8
end_define

begin_comment
comment|/* Base addr */
end_comment

begin_define
define|#
directive|define
name|ADDR_CFG_EISA
value|0x1f
end_define

begin_define
define|#
directive|define
name|ADDR_CFG_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|EEPROM_RESOURCE_CFG
value|0x9
end_define

begin_comment
comment|/* IRQ. Bits 12-15 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_OEM_ADDR0
value|0xa
end_define

begin_define
define|#
directive|define
name|EEPROM_OEM_ADDR1
value|0xb
end_define

begin_define
define|#
directive|define
name|EEPROM_OEM_ADDR2
value|0xc
end_define

begin_define
define|#
directive|define
name|EEPROM_SOFTINFO
value|0xd
end_define

begin_define
define|#
directive|define
name|EEPROM_COMPAT
value|0xe
end_define

begin_define
define|#
directive|define
name|EEPROM_SOFTINFO2
value|0xf
end_define

begin_define
define|#
directive|define
name|EEPROM_CAP
value|0x10
end_define

begin_define
define|#
directive|define
name|CAP_ISA
value|0x2083
end_define

begin_define
define|#
directive|define
name|CAP_PCMCIA
value|0x2082
end_define

begin_define
define|#
directive|define
name|EEPROM_INT_CONFIG_0
value|0x12
end_define

begin_define
define|#
directive|define
name|EEPROM_INT_CONFIG_1
value|0x13
end_define

begin_comment
comment|/* RAM Partition TX FIFO/RX FIFO */
end_comment

begin_define
define|#
directive|define
name|ICW1_RAM_PART_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|ICW1_RAM_PART_35
value|0x00
end_define

begin_comment
comment|/* 2:5 (only legal if RAM size == 000b 					 * default power-up/reset */
end_comment

begin_define
define|#
directive|define
name|ICW1_RAM_PART_13
value|0x01
end_define

begin_comment
comment|/* 1:3 (only legal if RAM size == 					 * 000b) */
end_comment

begin_define
define|#
directive|define
name|ICW1_RAM_PART_11
value|0x10
end_define

begin_comment
comment|/* 1:1		 */
end_comment

begin_define
define|#
directive|define
name|ICW1_RAM_PART_RESV
value|0x11
end_define

begin_comment
comment|/* Reserved	 */
end_comment

begin_comment
comment|/* ISA Adapter Selection */
end_comment

begin_define
define|#
directive|define
name|ICW1_IAS_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|ICW1_IAS_DIS
value|0x00
end_define

begin_comment
comment|/* Both mechanisms disabled (default) */
end_comment

begin_define
define|#
directive|define
name|ICW1_IAS_ISA
value|0x04
end_define

begin_comment
comment|/* ISA contention only */
end_comment

begin_define
define|#
directive|define
name|ICW1_IAS_PNP
value|0x08
end_define

begin_comment
comment|/* ISA Plug and Play only */
end_comment

begin_define
define|#
directive|define
name|ICW1_IAS_BOTH
value|0x0c
end_define

begin_comment
comment|/* Both mechanisms enabled */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CHECKSUM_EL3
value|0x17
end_define

begin_comment
comment|/**************************************************************************  *									  *  * These are the registers for the 3Com 3c509 and their bit patterns when *  * applicable.  They have been taken out the the "EtherLink III Parallel  *  * Tasking EISA and ISA Technical Reference" "Beta Draft 10/30/92" manual *  * from 3com.								  *  *									  *  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|EP_COMMAND
value|0x0e
end_define

begin_comment
comment|/* Write. BASE+0x0e is always a 					 * command reg. */
end_comment

begin_define
define|#
directive|define
name|EP_STATUS
value|0x0e
end_define

begin_comment
comment|/* Read. BASE+0x0e is always status 					 * reg. */
end_comment

begin_define
define|#
directive|define
name|EP_WINDOW
value|0x0f
end_define

begin_comment
comment|/* Read. BASE+0x0f is always window 					 * reg. */
end_comment

begin_comment
comment|/*  * Window 0 registers. Setup.  */
end_comment

begin_comment
comment|/* Write */
end_comment

begin_define
define|#
directive|define
name|EP_W0_EEPROM_DATA
value|0x0c
end_define

begin_define
define|#
directive|define
name|EP_W0_EEPROM_COMMAND
value|0x0a
end_define

begin_define
define|#
directive|define
name|EP_W0_RESOURCE_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|EP_W0_ADDRESS_CFG
value|0x06
end_define

begin_define
define|#
directive|define
name|EP_W0_CONFIG_CTRL
value|0x04
end_define

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|EP_W0_PRODUCT_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|EP_W0_MFG_ID
value|0x00
end_define

begin_comment
comment|/*  * Window 1 registers. Operating Set.  */
end_comment

begin_comment
comment|/* Write */
end_comment

begin_define
define|#
directive|define
name|EP_W1_TX_PIO_WR_2
value|0x02
end_define

begin_define
define|#
directive|define
name|EP_W1_TX_PIO_WR_1
value|0x00
end_define

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|EP_W1_FREE_TX
value|0x0c
end_define

begin_define
define|#
directive|define
name|EP_W1_TX_STATUS
value|0x0b
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|EP_W1_TIMER
value|0x0a
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|EP_W1_RX_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|EP_W1_RX_PIO_RD_2
value|0x02
end_define

begin_define
define|#
directive|define
name|EP_W1_RX_PIO_RD_1
value|0x00
end_define

begin_comment
comment|/*  * Window 2 registers. Station Address Setup/Read  */
end_comment

begin_comment
comment|/* Read/Write */
end_comment

begin_define
define|#
directive|define
name|EP_W2_PHY_MGMT
value|0x0c
end_define

begin_define
define|#
directive|define
name|EP_W2_ALT_EEPROM
value|0x0a
end_define

begin_define
define|#
directive|define
name|EP_W2_ADDR_5
value|0x05
end_define

begin_define
define|#
directive|define
name|EP_W2_ADDR_4
value|0x04
end_define

begin_define
define|#
directive|define
name|EP_W2_ADDR_3
value|0x03
end_define

begin_define
define|#
directive|define
name|EP_W2_ADDR_2
value|0x02
end_define

begin_define
define|#
directive|define
name|EP_W2_ADDR_1
value|0x01
end_define

begin_define
define|#
directive|define
name|EP_W2_ADDR_0
value|0x00
end_define

begin_comment
comment|/*  * Window 3 registers.  FIFO Management.  */
end_comment

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|EP_W3_FREE_TX
value|0x0c
end_define

begin_define
define|#
directive|define
name|EP_W3_FREE_RX
value|0x0a
end_define

begin_define
define|#
directive|define
name|EP_W3_OPTIONS
value|0x08
end_define

begin_comment
comment|/*  * Window 4 registers. Diagnostics.  */
end_comment

begin_comment
comment|/* Read/Write */
end_comment

begin_define
define|#
directive|define
name|EP_W4_MEDIA_TYPE
value|0x0a
end_define

begin_define
define|#
directive|define
name|EP_W4_CTRLR_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|EP_W4_NET_DIAG
value|0x06
end_define

begin_define
define|#
directive|define
name|EP_W4_FIFO_DIAG
value|0x04
end_define

begin_define
define|#
directive|define
name|EP_W4_HOST_DIAG
value|0x02
end_define

begin_define
define|#
directive|define
name|EP_W4_TX_DIAG
value|0x00
end_define

begin_comment
comment|/*  * Window 5 Registers.  Results and Internal status.  */
end_comment

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|EP_W5_READ_0_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|EP_W5_INTR_MASK
value|0x0a
end_define

begin_define
define|#
directive|define
name|EP_W5_RX_FILTER
value|0x08
end_define

begin_define
define|#
directive|define
name|EP_W5_RX_EARLY_THRESH
value|0x06
end_define

begin_define
define|#
directive|define
name|EP_W5_TX_AVAIL_THRESH
value|0x02
end_define

begin_define
define|#
directive|define
name|EP_W5_TX_START_THRESH
value|0x00
end_define

begin_comment
comment|/*  * Window 6 registers. Statistics.  */
end_comment

begin_comment
comment|/* Read/Write */
end_comment

begin_define
define|#
directive|define
name|TX_TOTAL_OK
value|0x0c
end_define

begin_define
define|#
directive|define
name|RX_TOTAL_OK
value|0x0a
end_define

begin_define
define|#
directive|define
name|TX_DEFERRALS
value|0x08
end_define

begin_define
define|#
directive|define
name|RX_FRAMES_OK
value|0x07
end_define

begin_define
define|#
directive|define
name|TX_FRAMES_OK
value|0x06
end_define

begin_define
define|#
directive|define
name|RX_OVERRUNS
value|0x05
end_define

begin_define
define|#
directive|define
name|TX_COLLISIONS
value|0x04
end_define

begin_define
define|#
directive|define
name|TX_AFTER_1_COLLISION
value|0x03
end_define

begin_define
define|#
directive|define
name|TX_AFTER_X_COLLISIONS
value|0x02
end_define

begin_define
define|#
directive|define
name|TX_NO_SQE
value|0x01
end_define

begin_define
define|#
directive|define
name|TX_CD_LOST
value|0x00
end_define

begin_comment
comment|/****************************************  *  * Register definitions.  *  ****************************************/
end_comment

begin_comment
comment|/*  * Command parameter that disables threshold interrupts  *   PIO (3c509) cards use 2044.  The fifo word-oriented and 2044--2047 work.  *  "busmastering" cards need 8188.  * The implicit two-bit upshift done by busmastering cards means  * a value of 2047 disables threshold interrupts on both.  */
end_comment

begin_define
define|#
directive|define
name|EP_THRESH_DISABLE
value|2047
end_define

begin_comment
comment|/*  * Command register. All windows.  *  * 16 bit register.  *     15-11:  5-bit code for command to be executed.  *     10-0:   11-bit arg if any. For commands with no args;  *	      this can be set to anything.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_RESET
value|(u_short) 0x0000
end_define

begin_comment
comment|/* Wait at least 1ms 							 * after issuing */
end_comment

begin_define
define|#
directive|define
name|WINDOW_SELECT
value|(u_short) (0x1<<11)
end_define

begin_define
define|#
directive|define
name|START_TRANSCEIVER
value|(u_short) (0x2<<11)
end_define

begin_comment
comment|/* Read ADDR_CFG reg to 							 * determine whether 							 * this is needed. If 							 * so; wait 800 uSec 							 * before using trans- 							 * ceiver. */
end_comment

begin_define
define|#
directive|define
name|RX_DISABLE
value|(u_short) (0x3<<11)
end_define

begin_comment
comment|/* state disabled on 							 * power-up */
end_comment

begin_define
define|#
directive|define
name|RX_ENABLE
value|(u_short) (0x4<<11)
end_define

begin_define
define|#
directive|define
name|RX_RESET
value|(u_short) (0x5<<11)
end_define

begin_define
define|#
directive|define
name|RX_DISCARD_TOP_PACK
value|(u_short) (0x8<<11)
end_define

begin_define
define|#
directive|define
name|TX_ENABLE
value|(u_short) (0x9<<11)
end_define

begin_define
define|#
directive|define
name|TX_DISABLE
value|(u_short) (0xa<<11)
end_define

begin_define
define|#
directive|define
name|TX_RESET
value|(u_short) (0xb<<11)
end_define

begin_define
define|#
directive|define
name|REQ_INTR
value|(u_short) (0xc<<11)
end_define

begin_comment
comment|/*  * The following C_* acknowledge the various interrupts. Some of them don't  * do anything.  See the manual.  */
end_comment

begin_define
define|#
directive|define
name|ACK_INTR
value|(u_short) (0x6800)
end_define

begin_define
define|#
directive|define
name|C_INTR_LATCH
value|(u_short) (ACK_INTR|0x1)
end_define

begin_define
define|#
directive|define
name|C_CARD_FAILURE
value|(u_short) (ACK_INTR|0x2)
end_define

begin_define
define|#
directive|define
name|C_TX_COMPLETE
value|(u_short) (ACK_INTR|0x4)
end_define

begin_define
define|#
directive|define
name|C_TX_AVAIL
value|(u_short) (ACK_INTR|0x8)
end_define

begin_define
define|#
directive|define
name|C_RX_COMPLETE
value|(u_short) (ACK_INTR|0x10)
end_define

begin_define
define|#
directive|define
name|C_RX_EARLY
value|(u_short) (ACK_INTR|0x20)
end_define

begin_define
define|#
directive|define
name|C_INT_RQD
value|(u_short) (ACK_INTR|0x40)
end_define

begin_define
define|#
directive|define
name|C_UPD_STATS
value|(u_short) (ACK_INTR|0x80)
end_define

begin_define
define|#
directive|define
name|SET_INTR_MASK
value|(u_short) (0xe<<11)
end_define

begin_define
define|#
directive|define
name|SET_RD_0_MASK
value|(u_short) (0xf<<11)
end_define

begin_define
define|#
directive|define
name|SET_RX_FILTER
value|(u_short) (0x10<<11)
end_define

begin_define
define|#
directive|define
name|FIL_INDIVIDUAL
value|(u_short) (0x1)
end_define

begin_define
define|#
directive|define
name|FIL_MULTICAST
value|(u_short) (0x02)
end_define

begin_define
define|#
directive|define
name|FIL_BRDCST
value|(u_short) (0x04)
end_define

begin_define
define|#
directive|define
name|FIL_PROMISC
value|(u_short) (0x08)
end_define

begin_define
define|#
directive|define
name|SET_RX_EARLY_THRESH
value|(u_short) (0x11<<11)
end_define

begin_define
define|#
directive|define
name|SET_TX_AVAIL_THRESH
value|(u_short) (0x12<<11)
end_define

begin_define
define|#
directive|define
name|SET_TX_START_THRESH
value|(u_short) (0x13<<11)
end_define

begin_define
define|#
directive|define
name|STATS_ENABLE
value|(u_short) (0x15<<11)
end_define

begin_define
define|#
directive|define
name|STATS_DISABLE
value|(u_short) (0x16<<11)
end_define

begin_define
define|#
directive|define
name|STOP_TRANSCEIVER
value|(u_short) (0x17<<11)
end_define

begin_define
define|#
directive|define
name|TX_PLL_ENABLE
value|(u_short) (0x18<<11)
end_define

begin_define
define|#
directive|define
name|TX_PLL_DISABLE
value|(u_short) (0x19<<11)
end_define

begin_define
define|#
directive|define
name|POWER_UP
value|(u_short) (0x1b<<11)
end_define

begin_define
define|#
directive|define
name|POWER_DOWN
value|(u_short) (0x1b<<11)
end_define

begin_define
define|#
directive|define
name|POWER_AUTO
value|(u_short) (0x1b<<11)
end_define

begin_comment
comment|/*  * Status register. All windows.  *  *     15-13:  Window number(0-7).  *     12:     Command_in_progress.  *     11:     reserved.  *     10:     reserved.  *     9:      reserved.  *     8:      reserved.  *     7:      Update Statistics.  *     6:      Interrupt Requested.  *     5:      RX Early.  *     4:      RX Complete.  *     3:      TX Available.  *     2:      TX Complete.  *     1:      Adapter Failure.  *     0:      Interrupt Latch.  */
end_comment

begin_define
define|#
directive|define
name|S_INTR_LATCH
value|(u_short) (0x1)
end_define

begin_define
define|#
directive|define
name|S_CARD_FAILURE
value|(u_short) (0x2)
end_define

begin_define
define|#
directive|define
name|S_TX_COMPLETE
value|(u_short) (0x4)
end_define

begin_define
define|#
directive|define
name|S_TX_AVAIL
value|(u_short) (0x8)
end_define

begin_define
define|#
directive|define
name|S_RX_COMPLETE
value|(u_short) (0x10)
end_define

begin_define
define|#
directive|define
name|S_RX_EARLY
value|(u_short) (0x20)
end_define

begin_define
define|#
directive|define
name|S_INT_RQD
value|(u_short) (0x40)
end_define

begin_define
define|#
directive|define
name|S_UPD_STATS
value|(u_short) (0x80)
end_define

begin_define
define|#
directive|define
name|S_MASK
value|(u_short) 0xFF
end_define

begin_comment
comment|/* mask of S_* */
end_comment

begin_define
define|#
directive|define
name|S_5_INTS
value|(S_CARD_FAILURE|S_TX_COMPLETE|\ 				 S_TX_AVAIL|S_RX_COMPLETE|S_RX_EARLY)
end_define

begin_define
define|#
directive|define
name|S_COMMAND_IN_PROGRESS
value|(u_short) (0x1000)
end_define

begin_define
define|#
directive|define
name|EP_BUSY_WAIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {									\ 		while (CSR_READ_2(sc, EP_STATUS)& S_COMMAND_IN_PROGRESS)	\ 			continue;						\ 	} while (0)
end_define

begin_comment
comment|/* Address Config. Register.  * Window 0/Port 06  */
end_comment

begin_define
define|#
directive|define
name|ACF_CONNECTOR_BITS
value|14
end_define

begin_define
define|#
directive|define
name|ACF_CONNECTOR_UTP
value|0
end_define

begin_define
define|#
directive|define
name|ACF_CONNECTOR_AUI
value|1
end_define

begin_define
define|#
directive|define
name|ACF_CONNECTOR_BNC
value|3
end_define

begin_comment
comment|/* Resource configuration register.  * Window 0/Port 08  *  */
end_comment

begin_define
define|#
directive|define
name|SET_IRQ
parameter_list|(
name|sc
parameter_list|,
name|irq
parameter_list|)
value|CSR_WRITE_2((sc), EP_W0_RESOURCE_CFG, \ 			((CSR_READ_2((sc), EP_W0_RESOURCE_CFG)& 0x0fff) | \ 			((u_short)(irq)<<12))  )
end_define

begin_comment
comment|/* set IRQ i */
end_comment

begin_comment
comment|/*  * FIFO Registers.  * RX Status. Window 1/Port 08  *  *     15:     Incomplete or FIFO empty.  *     14:     1: Error in RX Packet   0: Incomplete or no error.  *     13-11:  Type of error.  *	      1000 = Overrun.  *	      1011 = Run Packet Error.  *	      1100 = Alignment Error.  *	      1101 = CRC Error.  *	      1001 = Oversize Packet Error (>1514 bytes)  *	      0010 = Dribble Bits.  *	      (all other error codes, no errors.)  *  *     10-0:   RX Bytes (0-1514)  */
end_comment

begin_define
define|#
directive|define
name|ERR_RX_INCOMPLETE
value|(u_short) (0x1<<15)
end_define

begin_define
define|#
directive|define
name|ERR_RX
value|(u_short) (0x1<<14)
end_define

begin_define
define|#
directive|define
name|ERR_RX_OVERRUN
value|(u_short) (0x8<<11)
end_define

begin_define
define|#
directive|define
name|ERR_RX_RUN_PKT
value|(u_short) (0xb<<11)
end_define

begin_define
define|#
directive|define
name|ERR_RX_ALIGN
value|(u_short) (0xc<<11)
end_define

begin_define
define|#
directive|define
name|ERR_RX_CRC
value|(u_short) (0xd<<11)
end_define

begin_define
define|#
directive|define
name|ERR_RX_OVERSIZE
value|(u_short) (0x9<<11)
end_define

begin_define
define|#
directive|define
name|ERR_RX_DRIBBLE
value|(u_short) (0x2<<11)
end_define

begin_comment
comment|/*  * FIFO Registers.  * TX Status. Window 1/Port 0B  *  *   Reports the transmit status of a completed transmission. Writing this  *   register pops the transmit completion stack.  *  *   Window 1/Port 0x0b.  *  *     7:      Complete  *     6:      Interrupt on successful transmission requested.  *     5:      Jabber Error (TP Only, TX Reset required. )  *     4:      Underrun (TX Reset required. )  *     3:      Maximum Collisions.  *     2:      TX Status Overflow.  *     1-0:    Undefined.  *  */
end_comment

begin_define
define|#
directive|define
name|TXS_COMPLETE
value|0x80
end_define

begin_define
define|#
directive|define
name|TXS_SUCCES_INTR_REQ
value|0x40
end_define

begin_define
define|#
directive|define
name|TXS_JABBER
value|0x20
end_define

begin_define
define|#
directive|define
name|TXS_UNDERRUN
value|0x10
end_define

begin_define
define|#
directive|define
name|TXS_MAX_COLLISION
value|0x8
end_define

begin_define
define|#
directive|define
name|TXS_STATUS_OVERFLOW
value|0x4
end_define

begin_comment
comment|/*  * Configuration control register.  * Window 0/Port 04  */
end_comment

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|IS_AUI
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|IS_BNC
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|IS_UTP
value|(1<<9)
end_define

begin_comment
comment|/* Write */
end_comment

begin_define
define|#
directive|define
name|ENABLE_DRQ_IRQ
value|0x0001
end_define

begin_define
define|#
directive|define
name|W0_P4_CMD_RESET_ADAPTER
value|0x4
end_define

begin_define
define|#
directive|define
name|W0_P4_CMD_ENABLE_ADAPTER
value|0x1
end_define

begin_comment
comment|/*  * Media type and status.  * Window 4/Port 0A  */
end_comment

begin_define
define|#
directive|define
name|JABBER_GUARD_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|LINKBEAT_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|ENABLE_UTP
value|(JABBER_GUARD_ENABLE | LINKBEAT_ENABLE)
end_define

begin_define
define|#
directive|define
name|DISABLE_UTP
value|0x0
end_define

begin_define
define|#
directive|define
name|MT_CSD
value|0x0004
end_define

begin_comment
comment|/* CRC Strip disable */
end_comment

begin_define
define|#
directive|define
name|MT_SQE
value|0x0008
end_define

begin_comment
comment|/* SQE Enable */
end_comment

begin_define
define|#
directive|define
name|MT_C0
value|0x0010
end_define

begin_comment
comment|/* Collison */
end_comment

begin_define
define|#
directive|define
name|MT_CS
value|0x0020
end_define

begin_comment
comment|/* Carrier Sense */
end_comment

begin_define
define|#
directive|define
name|MT_J
value|0x0200
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|MT_PL
value|0x0400
end_define

begin_comment
comment|/* Plarity Inverted */
end_comment

begin_define
define|#
directive|define
name|MT_LB
value|0x0800
end_define

begin_comment
comment|/* Link Beat detected */
end_comment

begin_define
define|#
directive|define
name|MT_SQ
value|0x1000
end_define

begin_comment
comment|/* SQE Present */
end_comment

begin_define
define|#
directive|define
name|MT_IN
value|0x2000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|MT_CE
value|0x4000
end_define

begin_comment
comment|/* Coax */
end_comment

begin_define
define|#
directive|define
name|MT_TPE
value|0x8000
end_define

begin_comment
comment|/*  * Misc defines for various things.  */
end_comment

begin_define
define|#
directive|define
name|ACTIVATE_ADAPTER_TO_CONFIG
value|0xff
end_define

begin_comment
comment|/* to the id_port */
end_comment

begin_define
define|#
directive|define
name|MFG_ID
value|0x6d50
end_define

begin_comment
comment|/* in EEPROM and W0 						 * ADDR_CONFIG */
end_comment

begin_define
define|#
directive|define
name|PROD_ID
value|0x9150
end_define

begin_define
define|#
directive|define
name|AUI
value|0x1
end_define

begin_define
define|#
directive|define
name|BNC
value|0x2
end_define

begin_define
define|#
directive|define
name|UTP
value|0x4
end_define

begin_define
define|#
directive|define
name|RX_BYTES_MASK
value|(u_short) (0x07ff)
end_define

end_unit

