begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  *  * Copyright (c) 2002-2004 David Boggs. (boggs@boggs.palo-alto.ca.us)  * All rights reserved.  *  * BSD License:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * GNU General Public License:  *  * This program is free software; you can redistribute it and/or modify it   * under the terms of the GNU General Public License as published by the Free   * Software Foundation; either version 2 of the License, or (at your option)   * any later version.  *   * This program is distributed in the hope that it will be useful, but WITHOUT   * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or   * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for   * more details.  *  * You should have received a copy of the GNU General Public License along with  * this program; if not, write to the Free Software Foundation, Inc., 59   * Temple Place - Suite 330, Boston, MA  02111-1307, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|IF_LMC_H
end_ifndef

begin_define
define|#
directive|define
name|IF_LMC_H
end_define

begin_define
define|#
directive|define
name|DEVICE_NAME
value|"lmc"
end_define

begin_comment
comment|/* Linux RPM-style version information */
end_comment

begin_define
define|#
directive|define
name|DRIVER_MAJOR_VERSION
value|2005
end_define

begin_comment
comment|/* year */
end_comment

begin_define
define|#
directive|define
name|DRIVER_MINOR_VERSION
value|9
end_define

begin_comment
comment|/* month */
end_comment

begin_define
define|#
directive|define
name|DRIVER_SUB_VERSION
value|29
end_define

begin_comment
comment|/* day */
end_comment

begin_comment
comment|/* netgraph stuff */
end_comment

begin_define
define|#
directive|define
name|NG_LMC_NODE_TYPE
value|DEVICE_NAME
end_define

begin_define
define|#
directive|define
name|NGM_LMC_COOKIE
value|1128054761
end_define

begin_comment
comment|/* date -u +'%s' */
end_comment

begin_comment
comment|/* Tulip PCI configuration registers */
end_comment

begin_define
define|#
directive|define
name|TLP_CFID
value|0x00
end_define

begin_comment
comment|/*  0: CFg ID register     */
end_comment

begin_define
define|#
directive|define
name|TLP_CFCS
value|0x04
end_define

begin_comment
comment|/*  1: CFg Command/Status  */
end_comment

begin_define
define|#
directive|define
name|TLP_CFRV
value|0x08
end_define

begin_comment
comment|/*  2: CFg ReVision        */
end_comment

begin_define
define|#
directive|define
name|TLP_CFLT
value|0x0C
end_define

begin_comment
comment|/*  3: CFg Latency Timer   */
end_comment

begin_define
define|#
directive|define
name|TLP_CBIO
value|0x10
end_define

begin_comment
comment|/*  4: Cfg Base IO address */
end_comment

begin_define
define|#
directive|define
name|TLP_CBMA
value|0x14
end_define

begin_comment
comment|/*  5: Cfg Base Mem Addr   */
end_comment

begin_define
define|#
directive|define
name|TLP_CSID
value|0x2C
end_define

begin_comment
comment|/* 11: Cfg Subsys ID reg   */
end_comment

begin_define
define|#
directive|define
name|TLP_CFIT
value|0x3C
end_define

begin_comment
comment|/* 15: CFg InTerrupt       */
end_comment

begin_define
define|#
directive|define
name|TLP_CFDD
value|0x40
end_define

begin_comment
comment|/* 16: CFg Driver Data     */
end_comment

begin_define
define|#
directive|define
name|TLP_CFID_TULIP
value|0x00091011
end_define

begin_comment
comment|/* DEC 21140A Ethernet chip */
end_comment

begin_define
define|#
directive|define
name|TLP_CFCS_MSTR_ABORT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TLP_CFCS_TARG_ABORT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TLP_CFCS_SYS_ERROR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TLP_CFCS_PAR_ERROR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TLP_CFCS_MWI_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TLP_CFCS_BUS_MASTER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TLP_CFCS_MEM_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TLP_CFCS_IO_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TLP_CFLT_LATENCY
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|TLP_CFLT_CACHE
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|TLP_CSID_HSSI
value|0x00031376
end_define

begin_comment
comment|/* LMC 5200 HSSI card */
end_comment

begin_define
define|#
directive|define
name|TLP_CSID_T3
value|0x00041376
end_define

begin_comment
comment|/* LMC 5245 T3   card */
end_comment

begin_define
define|#
directive|define
name|TLP_CSID_SSI
value|0x00051376
end_define

begin_comment
comment|/* LMC 1000 SSI  card */
end_comment

begin_define
define|#
directive|define
name|TLP_CSID_T1E1
value|0x00061376
end_define

begin_comment
comment|/* LMC 1200 T1E1 card */
end_comment

begin_define
define|#
directive|define
name|TLP_CSID_HSSIc
value|0x00071376
end_define

begin_comment
comment|/* LMC 5200 HSSI cPCI */
end_comment

begin_define
define|#
directive|define
name|TLP_CSID_SDSL
value|0x00081376
end_define

begin_comment
comment|/* LMC 1168 SDSL card */
end_comment

begin_define
define|#
directive|define
name|TLP_CFIT_MAX_LAT
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|TLP_CFDD_SLEEP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TLP_CFDD_SNOOZE
value|0x40000000
end_define

begin_comment
comment|/* Tulip Control and Status Registers */
end_comment

begin_define
define|#
directive|define
name|TLP_CSR_STRIDE
value|8
end_define

begin_comment
comment|/* 64 bits */
end_comment

begin_define
define|#
directive|define
name|TLP_BUS_MODE
value|0 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_TX_POLL
value|1 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_RX_POLL
value|2 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_RX_LIST
value|3 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_TX_LIST
value|4 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_STATUS
value|5 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_OP_MODE
value|6 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_INT_ENBL
value|7 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_MISSED
value|8 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_SROM_MII
value|9 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_BIOS_ROM
value|10 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_TIMER
value|11 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_GPIO
value|12 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_CSR13
value|13 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_CSR14
value|14 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_WDOG
value|15 * TLP_CSR_STRIDE
end_define

begin_define
define|#
directive|define
name|TLP_CSR_SIZE
value|128
end_define

begin_comment
comment|/* IO bus space size */
end_comment

begin_comment
comment|/* CSR 0 - PCI Bus Mode Register */
end_comment

begin_define
define|#
directive|define
name|TLP_BUS_WRITE_INVAL
value|0x01000000
end_define

begin_comment
comment|/* DONT USE! */
end_comment

begin_define
define|#
directive|define
name|TLP_BUS_READ_LINE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TLP_BUS_READ_MULT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TLP_BUS_DESC_BIGEND
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TLP_BUS_TAP
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|TLP_BUS_CAL
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|TLP_BUS_PBL
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|TLP_BUS_DATA_BIGEND
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TLP_BUS_DSL
value|0x0000007C
end_define

begin_define
define|#
directive|define
name|TLP_BUS_ARB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TLP_BUS_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TLP_BUS_CAL_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|TLP_BUS_PBL_SHIFT
value|8
end_define

begin_comment
comment|/* CSR 5 - Status Register */
end_comment

begin_define
define|#
directive|define
name|TLP_STAT_FATAL_BITS
value|0x03800000
end_define

begin_define
define|#
directive|define
name|TLP_STAT_TX_FSM
value|0x00700000
end_define

begin_define
define|#
directive|define
name|TLP_STAT_RX_FSM
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|TLP_STAT_FATAL_ERROR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TLP_STAT_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TLP_STAT_FATAL_SHIFT
value|23
end_define

begin_comment
comment|/* CSR 6 - Operating Mode Register */
end_comment

begin_define
define|#
directive|define
name|TLP_OP_RECEIVE_ALL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TLP_OP_MUST_BE_ONE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TLP_OP_NO_HEART_BEAT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TLP_OP_PORT_SELECT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TLP_OP_TX_THRESH
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|TLP_OP_TX_RUN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TLP_OP_LOOP_MODE
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|TLP_OP_EXT_LOOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TLP_OP_INT_LOOP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|TLP_OP_FULL_DUPLEX
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TLP_OP_PROMISCUOUS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TLP_OP_PASS_BAD_PKT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TLP_OP_RX_RUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TLP_OP_TR_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|TLP_OP_INIT
value|(TLP_OP_PORT_SELECT   | \ 				 TLP_OP_FULL_DUPLEX   | \ 				 TLP_OP_MUST_BE_ONE   | \ 				 TLP_OP_NO_HEART_BEAT | \ 				 TLP_OP_RECEIVE_ALL   | \ 				 TLP_OP_PROMISCUOUS   | \ 				 TLP_OP_PASS_BAD_PKT  | \ 				 TLP_OP_RX_RUN        | \ 				 TLP_OP_TX_RUN)
end_define

begin_comment
comment|/* CSR 7 - Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|TLP_INT_NORMAL_INTR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TLP_INT_ABNRML_INTR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TLP_INT_FATAL_ERROR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TLP_INT_RX_NO_BUFS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TLP_INT_RX_INTR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TLP_INT_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TLP_INT_TX_INTR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TLP_INT_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|TLP_INT_TX
value|(TLP_INT_NORMAL_INTR | \ 				 TLP_INT_ABNRML_INTR | \ 				 TLP_INT_FATAL_ERROR | \ 				 TLP_INT_TX_UNDERRUN | \ 				 TLP_INT_TX_INTR)
end_define

begin_define
define|#
directive|define
name|TLP_INT_RX
value|(TLP_INT_NORMAL_INTR | \ 				 TLP_INT_ABNRML_INTR | \ 				 TLP_INT_FATAL_ERROR | \ 				 TLP_INT_RX_NO_BUFS  | \ 				 TLP_INT_RX_INTR)
end_define

begin_define
define|#
directive|define
name|TLP_INT_TXRX
value|(TLP_INT_TX | TLP_INT_RX)
end_define

begin_comment
comment|/* CSR 8 - RX Missed Frames& Overrun Register */
end_comment

begin_define
define|#
directive|define
name|TLP_MISS_OCO
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TLP_MISS_OVERRUN
value|0x0FFE0000
end_define

begin_define
define|#
directive|define
name|TLP_MISS_MFO
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TLP_MISS_MISSED
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|TLP_OVERRUN_SHIFT
value|17
end_define

begin_comment
comment|/* CSR 9 - SROM& MII& Boot ROM Register */
end_comment

begin_define
define|#
directive|define
name|TLP_MII_MDIN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TLP_MII_MDOE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TLP_MII_MDOUT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TLP_MII_MDC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TLP_BIOS_RD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TLP_BIOS_WR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TLP_BIOS_SEL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TLP_SROM_RD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TLP_SROM_SEL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TLP_SROM_DOUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TLP_SROM_DIN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TLP_SROM_CLK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TLP_SROM_CS
value|0x00000001
end_define

begin_comment
comment|/* CSR 12 - General Purpose IO register */
end_comment

begin_define
define|#
directive|define
name|TLP_GPIO_DIR
value|0x00000100
end_define

begin_comment
comment|/* CSR 15 - Watchdog Timer Register */
end_comment

begin_define
define|#
directive|define
name|TLP_WDOG_RX_OFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TLP_WDOG_TX_OFF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TLP_WDOG_INIT
value|(TLP_WDOG_TX_OFF | \ 				 TLP_WDOG_RX_OFF)
end_define

begin_comment
comment|/* GPIO bits common to all cards */
end_comment

begin_define
define|#
directive|define
name|GPIO_INIT
value|0x01
end_define

begin_comment
comment|/*    from Xilinx                  */
end_comment

begin_define
define|#
directive|define
name|GPIO_RESET
value|0x02
end_define

begin_comment
comment|/* to      Xilinx                  */
end_comment

begin_comment
comment|/* bits 2 and 3 vary with board type -- see below */
end_comment

begin_define
define|#
directive|define
name|GPIO_MODE
value|0x10
end_define

begin_comment
comment|/* to      Xilinx                  */
end_comment

begin_define
define|#
directive|define
name|GPIO_DP
value|0x20
end_define

begin_comment
comment|/* to/from Xilinx                  */
end_comment

begin_define
define|#
directive|define
name|GPIO_DATA
value|0x40
end_define

begin_comment
comment|/* serial data                     */
end_comment

begin_define
define|#
directive|define
name|GPIO_CLK
value|0x80
end_define

begin_comment
comment|/* serial clock                    */
end_comment

begin_comment
comment|/* HSSI GPIO bits */
end_comment

begin_define
define|#
directive|define
name|GPIO_HSSI_ST
value|0x04
end_define

begin_comment
comment|/* send timing sense (deprecated)  */
end_comment

begin_define
define|#
directive|define
name|GPIO_HSSI_TXCLK
value|0x08
end_define

begin_comment
comment|/* clock source                    */
end_comment

begin_comment
comment|/* HSSIc GPIO bits */
end_comment

begin_define
define|#
directive|define
name|GPIO_HSSI_SYNTH
value|0x04
end_define

begin_comment
comment|/* Synth osc chip select           */
end_comment

begin_define
define|#
directive|define
name|GPIO_HSSI_DCE
value|0x08
end_define

begin_comment
comment|/* provide clock on TXCLOCK output */
end_comment

begin_comment
comment|/* T3   GPIO bits */
end_comment

begin_define
define|#
directive|define
name|GPIO_T3_DAC
value|0x04
end_define

begin_comment
comment|/* DAC chip select                 */
end_comment

begin_define
define|#
directive|define
name|GPIO_T3_INTEN
value|0x08
end_define

begin_comment
comment|/* Framer Interupt enable          */
end_comment

begin_comment
comment|/* SSI  GPIO bits */
end_comment

begin_define
define|#
directive|define
name|GPIO_SSI_SYNTH
value|0x04
end_define

begin_comment
comment|/* Synth osc chip select           */
end_comment

begin_define
define|#
directive|define
name|GPIO_SSI_DCE
value|0x08
end_define

begin_comment
comment|/* provide clock on TXCLOCK output */
end_comment

begin_comment
comment|/* T1E1 GPIO bits */
end_comment

begin_define
define|#
directive|define
name|GPIO_T1_INTEN
value|0x08
end_define

begin_comment
comment|/* Framer Interupt enable          */
end_comment

begin_comment
comment|/* MII register 16 bits common to all cards */
end_comment

begin_comment
comment|/* NB: LEDs  for HSSI& SSI are in DIFFERENT bits than for T1E1& T3; oops */
end_comment

begin_comment
comment|/* NB: CRC32 for HSSI& SSI is  in DIFFERENT bit  than for T1E1& T3; oops */
end_comment

begin_define
define|#
directive|define
name|MII16_LED_ALL
value|0x0780
end_define

begin_comment
comment|/* RW: LED bit mask                */
end_comment

begin_define
define|#
directive|define
name|MII16_FIFO
value|0x0800
end_define

begin_comment
comment|/* RW: 1=reset, 0=not reset        */
end_comment

begin_comment
comment|/* MII register 16 bits for HSSI */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_TA
value|0x0001
end_define

begin_comment
comment|/* RW: host ready;  host->modem    */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_CA
value|0x0002
end_define

begin_comment
comment|/* RO: modem ready; modem->host    */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LA
value|0x0004
end_define

begin_comment
comment|/* RW: loopback A;  host->modem    */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LB
value|0x0008
end_define

begin_comment
comment|/* RW: loopback B;  host->modem    */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LC
value|0x0010
end_define

begin_comment
comment|/* RO: loopback C;  modem->host    */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_TM
value|0x0020
end_define

begin_comment
comment|/* RO: test mode;   modem->host    */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_CRC32
value|0x0040
end_define

begin_comment
comment|/* RW: CRC length 16/32            */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LED_LL
value|0x0080
end_define

begin_comment
comment|/* RW: lower left  - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LED_LR
value|0x0100
end_define

begin_comment
comment|/* RW: lower right - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LED_UL
value|0x0200
end_define

begin_comment
comment|/* RW: upper left  - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LED_UR
value|0x0400
end_define

begin_comment
comment|/* RW: upper right - red           */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_FIFO
value|0x0800
end_define

begin_comment
comment|/* RW: reset fifos                 */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_FORCECA
value|0x1000
end_define

begin_comment
comment|/* RW: [cPCI] force CA on          */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_CLKMUX
value|0x6000
end_define

begin_comment
comment|/* RW: [cPCI] TX clock selection   */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_LOOP
value|0x8000
end_define

begin_comment
comment|/* RW: [cPCI] LOOP TX into RX      */
end_comment

begin_define
define|#
directive|define
name|MII16_HSSI_MODEM
value|0x003F
end_define

begin_comment
comment|/* TA+CA+LA+LB+LC+TM               */
end_comment

begin_comment
comment|/* MII register 16 bits for DS3 */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_ZERO
value|0x0001
end_define

begin_comment
comment|/* RW: short/long cables           */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_TRLBK
value|0x0002
end_define

begin_comment
comment|/* RW: loop towards host           */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_LNLBK
value|0x0004
end_define

begin_comment
comment|/* RW: loop towards net            */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_RAIS
value|0x0008
end_define

begin_comment
comment|/* RO: LIU receive AIS      (depr) */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_TAIS
value|0x0010
end_define

begin_comment
comment|/* RW: LIU transmit AIS     (depr) */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_BIST
value|0x0020
end_define

begin_comment
comment|/* RO: LIU QRSS patt match  (depr) */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_DLOS
value|0x0040
end_define

begin_comment
comment|/* RO: LIU Digital LOS      (depr) */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_LED_BLU
value|0x0080
end_define

begin_comment
comment|/* RW: lower right - blue          */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_LED_YEL
value|0x0100
end_define

begin_comment
comment|/* RW: lower left  - yellow        */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_LED_RED
value|0x0200
end_define

begin_comment
comment|/* RW: upper right - red           */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_LED_GRN
value|0x0400
end_define

begin_comment
comment|/* RW: upper left  - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_FIFO
value|0x0800
end_define

begin_comment
comment|/* RW: reset fifos                 */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_CRC32
value|0x1000
end_define

begin_comment
comment|/* RW: CRC length 16/32            */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_SCRAM
value|0x2000
end_define

begin_comment
comment|/* RW: payload scrambler           */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_POLY
value|0x4000
end_define

begin_comment
comment|/* RW: 1=Larse, 0=DigLink|Kentrox  */
end_comment

begin_define
define|#
directive|define
name|MII16_DS3_FRAME
value|0x8000
end_define

begin_comment
comment|/* RW: 1=stop txframe pulses       */
end_comment

begin_comment
comment|/* MII register 16 bits for SSI */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_DTR
value|0x0001
end_define

begin_comment
comment|/* RW: DTR host->modem             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_DSR
value|0x0002
end_define

begin_comment
comment|/* RO: DSR modem->host             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_RTS
value|0x0004
end_define

begin_comment
comment|/* RW: RTS host->modem             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_CTS
value|0x0008
end_define

begin_comment
comment|/* RO: CTS modem->host             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_DCD
value|0x0010
end_define

begin_comment
comment|/* RW: DCD modem<->host            */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_RI
value|0x0020
end_define

begin_comment
comment|/* RO: RI  modem->host             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_CRC32
value|0x0040
end_define

begin_comment
comment|/* RW: CRC length 16/32            */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_LED_LL
value|0x0080
end_define

begin_comment
comment|/* RW: lower left  - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_LED_LR
value|0x0100
end_define

begin_comment
comment|/* RW: lower right - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_LED_UL
value|0x0200
end_define

begin_comment
comment|/* RW: upper left  - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_LED_UR
value|0x0400
end_define

begin_comment
comment|/* RW: upper right - red           */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_FIFO
value|0x0800
end_define

begin_comment
comment|/* RW: reset fifos                 */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_LL
value|0x1000
end_define

begin_comment
comment|/* RW: LL: host->modem             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_RL
value|0x2000
end_define

begin_comment
comment|/* RW: RL: host->modem             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_TM
value|0x4000
end_define

begin_comment
comment|/* RO: TM: modem->host             */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_LOOP
value|0x8000
end_define

begin_comment
comment|/* RW: Loop at ext conn            */
end_comment

begin_define
define|#
directive|define
name|MII16_SSI_MODEM
value|0x703F
end_define

begin_comment
comment|/* DTR+DSR+RTS+CTS+DCD+RI+LL+RL+TM */
end_comment

begin_comment
comment|/* Mii register 17 has the SSI cable bits */
end_comment

begin_define
define|#
directive|define
name|MII17_SSI_CABLE_SHIFT
value|3
end_define

begin_comment
comment|/* shift to get cable type         */
end_comment

begin_define
define|#
directive|define
name|MII17_SSI_CABLE_MASK
value|0x0038
end_define

begin_comment
comment|/* RO: mask  to get cable type     */
end_comment

begin_define
define|#
directive|define
name|MII17_SSI_PRESCALE
value|0x0040
end_define

begin_comment
comment|/* RW: divide by: 0=16; 1=512      */
end_comment

begin_define
define|#
directive|define
name|MII17_SSI_ITF
value|0x0100
end_define

begin_comment
comment|/* RW: fill with: 0=flags; 1=ones  */
end_comment

begin_define
define|#
directive|define
name|MII17_SSI_NRZI
value|0x0400
end_define

begin_comment
comment|/* RW: coding: NRZ= 0; NRZI=1      */
end_comment

begin_comment
comment|/* MII register 16 bits for T1/E1 */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_UNUSED1
value|0x0001
end_define

begin_define
define|#
directive|define
name|MII16_T1_INVERT
value|0x0002
end_define

begin_comment
comment|/* RW: invert data (for SF/AMI)    */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_XOE
value|0x0004
end_define

begin_comment
comment|/* RW: TX Output Enable; 0=disable */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_RST
value|0x0008
end_define

begin_comment
comment|/* RW: Bt8370 chip reset           */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_Z
value|0x0010
end_define

begin_comment
comment|/* RW: output impedance T1=1 E1=0  */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_INTR
value|0x0020
end_define

begin_comment
comment|/* RO: interrupt from Bt8370       */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_ONESEC
value|0x0040
end_define

begin_comment
comment|/* RO: one second square wave      */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_LED_BLU
value|0x0080
end_define

begin_comment
comment|/* RW: lower right - blue          */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_LED_YEL
value|0x0100
end_define

begin_comment
comment|/* RW: lower left  - yellow        */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_LED_RED
value|0x0200
end_define

begin_comment
comment|/* RW: upper right - red           */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_LED_GRN
value|0x0400
end_define

begin_comment
comment|/* RW: upper left  - green         */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_FIFO
value|0x0800
end_define

begin_comment
comment|/* RW: reset fifos                 */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_CRC32
value|0x1000
end_define

begin_comment
comment|/* RW: CRC length 16/32            */
end_comment

begin_define
define|#
directive|define
name|MII16_T1_UNUSED2
value|0xE000
end_define

begin_comment
comment|/* T3 framer:  RW=Read/Write;  RO=Read-Only;  RC=Read/Clr;  WO=Write-Only  */
end_comment

begin_define
define|#
directive|define
name|T3CSR_STAT0
value|0x00
end_define

begin_comment
comment|/* RO: real-time status            */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CTL1
value|0x01
end_define

begin_comment
comment|/* RW: global control bits         */
end_comment

begin_define
define|#
directive|define
name|T3CSR_FEBE
value|0x02
end_define

begin_comment
comment|/* RC: Far End Block Error Counter */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CERR
value|0x03
end_define

begin_comment
comment|/* RC: C-bit Parity Error Counter  */
end_comment

begin_define
define|#
directive|define
name|T3CSR_PERR
value|0x04
end_define

begin_comment
comment|/* RC: P-bit Parity Error Counter  */
end_comment

begin_define
define|#
directive|define
name|T3CSR_TX_FEAC
value|0x05
end_define

begin_comment
comment|/* RW: Far End Alarm& Control     */
end_comment

begin_define
define|#
directive|define
name|T3CSR_RX_FEAC
value|0x06
end_define

begin_comment
comment|/* RO: Far End Alarm& Control     */
end_comment

begin_define
define|#
directive|define
name|T3CSR_STAT7
value|0x07
end_define

begin_comment
comment|/* RL: latched real-time status    */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CTL8
value|0x08
end_define

begin_comment
comment|/* RW: extended global ctl bits    */
end_comment

begin_define
define|#
directive|define
name|T3CSR_STAT9
value|0x09
end_define

begin_comment
comment|/* RL: extended status bits        */
end_comment

begin_define
define|#
directive|define
name|T3CSR_FERR
value|0x0A
end_define

begin_comment
comment|/* RC: F-bit Error Counter         */
end_comment

begin_define
define|#
directive|define
name|T3CSR_MERR
value|0x0B
end_define

begin_comment
comment|/* RC: M-bit Error Counter         */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CTL12
value|0x0C
end_define

begin_comment
comment|/* RW: more extended ctl bits      */
end_comment

begin_define
define|#
directive|define
name|T3CSR_DBL_FEAC
value|0x0D
end_define

begin_comment
comment|/* RW: TX double FEAC              */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CTL14
value|0x0E
end_define

begin_comment
comment|/* RW: even more extended ctl bits */
end_comment

begin_define
define|#
directive|define
name|T3CSR_FEAC_STK
value|0x0F
end_define

begin_comment
comment|/* RO: RX FEAC stack               */
end_comment

begin_define
define|#
directive|define
name|T3CSR_STAT16
value|0x10
end_define

begin_comment
comment|/* RL: extended latched status     */
end_comment

begin_define
define|#
directive|define
name|T3CSR_INTEN
value|0x11
end_define

begin_comment
comment|/* RW: interrupt enable            */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CVLO
value|0x12
end_define

begin_comment
comment|/* RC: coding violation cntr LSB   */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CVHI
value|0x13
end_define

begin_comment
comment|/* RC: coding violation cntr MSB   */
end_comment

begin_define
define|#
directive|define
name|T3CSR_CTL20
value|0x14
end_define

begin_comment
comment|/* RW: yet more extended ctl bits  */
end_comment

begin_define
define|#
directive|define
name|CTL1_XTX
value|0x01
end_define

begin_comment
comment|/* Transmit X-bit value            */
end_comment

begin_define
define|#
directive|define
name|CTL1_3LOOP
value|0x02
end_define

begin_comment
comment|/* framer loop back                */
end_comment

begin_define
define|#
directive|define
name|CTL1_SER
value|0x04
end_define

begin_comment
comment|/* SERial interface selected       */
end_comment

begin_define
define|#
directive|define
name|CTL1_M13MODE
value|0x08
end_define

begin_comment
comment|/* M13 frame format                */
end_comment

begin_define
define|#
directive|define
name|CTL1_TXIDL
value|0x10
end_define

begin_comment
comment|/* Transmit Idle signal            */
end_comment

begin_define
define|#
directive|define
name|CTL1_ENAIS
value|0x20
end_define

begin_comment
comment|/* Enable AIS upon LOS             */
end_comment

begin_define
define|#
directive|define
name|CTL1_TXAIS
value|0x40
end_define

begin_comment
comment|/* Transmit Alarm Indication Sig   */
end_comment

begin_define
define|#
directive|define
name|CTL1_NOFEBE
value|0x80
end_define

begin_comment
comment|/* No Far End Block Errors         */
end_comment

begin_define
define|#
directive|define
name|CTL5_EMODE
value|0x80
end_define

begin_comment
comment|/* rev B Extended features enabled */
end_comment

begin_define
define|#
directive|define
name|CTL5_START
value|0x40
end_define

begin_comment
comment|/* transmit the FEAC msg now       */
end_comment

begin_define
define|#
directive|define
name|CTL8_FBEC
value|0x80
end_define

begin_comment
comment|/* F-Bit Error Count control       */
end_comment

begin_define
define|#
directive|define
name|CTL8_TBLU
value|0x20
end_define

begin_comment
comment|/* Transmit Blue signal            */
end_comment

begin_define
define|#
directive|define
name|STAT9_SEF
value|0x80
end_define

begin_comment
comment|/* Severely Errored Frame          */
end_comment

begin_define
define|#
directive|define
name|STAT9_RBLU
value|0x20
end_define

begin_comment
comment|/* Receive Blue signal             */
end_comment

begin_define
define|#
directive|define
name|CTL12_RTPLLEN
value|0x80
end_define

begin_comment
comment|/* Rx-to-Tx Payload Lpbk Lock ENbl */
end_comment

begin_define
define|#
directive|define
name|CTL12_RTPLOOP
value|0x40
end_define

begin_comment
comment|/* Rx-to-Tx Payload Loopback       */
end_comment

begin_define
define|#
directive|define
name|CTL12_DLCB1
value|0x08
end_define

begin_comment
comment|/* Data Link C-Bits forced to 1    */
end_comment

begin_define
define|#
directive|define
name|CTL12_C21
value|0x04
end_define

begin_comment
comment|/* C2 forced to 1                  */
end_comment

begin_define
define|#
directive|define
name|CTL12_MCB1
value|0x02
end_define

begin_comment
comment|/* Most C-Bits forced to 1         */
end_comment

begin_define
define|#
directive|define
name|CTL13_DFEXEC
value|0x40
end_define

begin_comment
comment|/* Execute Double FEAC             */
end_comment

begin_define
define|#
directive|define
name|CTL14_FEAC10
value|0x80
end_define

begin_comment
comment|/* Transmit FEAC word 10 times     */
end_comment

begin_define
define|#
directive|define
name|CTL14_RGCEN
value|0x20
end_define

begin_comment
comment|/* Receive Gapped Clock Out Enbl   */
end_comment

begin_define
define|#
directive|define
name|CTL14_TGCEN
value|0x10
end_define

begin_comment
comment|/* Timing Gen Gapped Clk Out Enbl  */
end_comment

begin_define
define|#
directive|define
name|FEAC_STK_MORE
value|0x80
end_define

begin_comment
comment|/* FEAC stack has more FEACs       */
end_comment

begin_define
define|#
directive|define
name|FEAC_STK_VALID
value|0x40
end_define

begin_comment
comment|/* FEAC stack is valid             */
end_comment

begin_define
define|#
directive|define
name|FEAC_STK_FEAC
value|0x3F
end_define

begin_comment
comment|/* FEAC stack FEAC data            */
end_comment

begin_define
define|#
directive|define
name|STAT16_XERR
value|0x01
end_define

begin_comment
comment|/* X-bit Error                     */
end_comment

begin_define
define|#
directive|define
name|STAT16_SEF
value|0x02
end_define

begin_comment
comment|/* Severely Errored Frame          */
end_comment

begin_define
define|#
directive|define
name|STAT16_RTLOC
value|0x04
end_define

begin_comment
comment|/* Rx/Tx Loss Of Clock             */
end_comment

begin_define
define|#
directive|define
name|STAT16_FEAC
value|0x08
end_define

begin_comment
comment|/* new FEAC msg                    */
end_comment

begin_define
define|#
directive|define
name|STAT16_RIDL
value|0x10
end_define

begin_comment
comment|/* channel IDLe signal             */
end_comment

begin_define
define|#
directive|define
name|STAT16_RAIS
value|0x20
end_define

begin_comment
comment|/* Alarm Indication Signal         */
end_comment

begin_define
define|#
directive|define
name|STAT16_ROOF
value|0x40
end_define

begin_comment
comment|/* Out Of Frame sync               */
end_comment

begin_define
define|#
directive|define
name|STAT16_RLOS
value|0x80
end_define

begin_comment
comment|/* Loss Of Signal                  */
end_comment

begin_define
define|#
directive|define
name|CTL20_CVEN
value|0x01
end_define

begin_comment
comment|/* Coding Violation Counter Enbl   */
end_comment

begin_comment
comment|/* T1.107 Bit Oriented C-Bit Parity Far End Alarm Control and Status codes */
end_comment

begin_define
define|#
directive|define
name|T3BOP_OOF
value|0x00
end_define

begin_comment
comment|/* Yellow alarm status             */
end_comment

begin_define
define|#
directive|define
name|T3BOP_LINE_UP
value|0x07
end_define

begin_comment
comment|/* line loopback activate          */
end_comment

begin_define
define|#
directive|define
name|T3BOP_LINE_DOWN
value|0x1C
end_define

begin_comment
comment|/* line loopback deactivate        */
end_comment

begin_define
define|#
directive|define
name|T3BOP_LOOP_DS3
value|0x1B
end_define

begin_comment
comment|/* loopback full DS3               */
end_comment

begin_define
define|#
directive|define
name|T3BOP_IDLE
value|0x1A
end_define

begin_comment
comment|/* IDLE alarm status               */
end_comment

begin_define
define|#
directive|define
name|T3BOP_AIS
value|0x16
end_define

begin_comment
comment|/* AIS  alarm status               */
end_comment

begin_define
define|#
directive|define
name|T3BOP_LOS
value|0x0E
end_define

begin_comment
comment|/* LOS  alarm status               */
end_comment

begin_comment
comment|/* T1E1 regs;  RW=Read/Write;  RO=Read-Only;  RC=Read/Clr;  WO=Write-Only  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DID
value|0x000
end_define

begin_comment
comment|/* RO: Device ID                   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CR0
value|0x001
end_define

begin_comment
comment|/* RW; Primary Control Register    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_JAT_CR
value|0x002
end_define

begin_comment
comment|/* RW: Jitter Attenuator CR        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IRR
value|0x003
end_define

begin_comment
comment|/* RO: Interrupt Request Reg       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR7
value|0x004
end_define

begin_comment
comment|/* RC: Alarm 1 Interrupt Status    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR6
value|0x005
end_define

begin_comment
comment|/* RC: Alarm 2 Interrupt Status    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR5
value|0x006
end_define

begin_comment
comment|/* RC: Error Interrupt Status      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR4
value|0x007
end_define

begin_comment
comment|/* RC; Cntr Ovfl Interrupt Status  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR3
value|0x008
end_define

begin_comment
comment|/* RC: Timer Interrupt Status      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR2
value|0x009
end_define

begin_comment
comment|/* RC: Data Link 1 Int Status      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR1
value|0x00A
end_define

begin_comment
comment|/* RC: Data Link 2 Int Status      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ISR0
value|0x00B
end_define

begin_comment
comment|/* RC: Pattrn Interrupt Status     */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER7
value|0x00C
end_define

begin_comment
comment|/* RW: Alarm 1 Interrupt Enable    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER6
value|0x00D
end_define

begin_comment
comment|/* RW: Alarm 2 Interrupt Enable    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER5
value|0x00E
end_define

begin_comment
comment|/* RW: Error Interrupt Enable      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER4
value|0x00F
end_define

begin_comment
comment|/* RW: Cntr Ovfl Interrupt Enable  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER3
value|0x010
end_define

begin_comment
comment|/* RW: Timer Interrupt Enable      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER2
value|0x011
end_define

begin_comment
comment|/* RW: Data Link 1 Int Enable      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER1
value|0x012
end_define

begin_comment
comment|/* RW: Data Link 2 Int Enable      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_IER0
value|0x013
end_define

begin_comment
comment|/* RW: Pattern Interrupt Enable    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LOOP
value|0x014
end_define

begin_comment
comment|/* RW: Loopback Config Reg         */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL3_TS
value|0x015
end_define

begin_comment
comment|/* RW: External Data Link Channel  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL3_BIT
value|0x016
end_define

begin_comment
comment|/* RW: External Data Link Bit      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_FSTAT
value|0x017
end_define

begin_comment
comment|/* RO: Offline Framer Status       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_PIO
value|0x018
end_define

begin_comment
comment|/* RW: Programmable Input/Output   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_POE
value|0x019
end_define

begin_comment
comment|/* RW: Programmable Output Enable  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CMUX
value|0x01A
end_define

begin_comment
comment|/* RW: Clock Input Mux             */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TMUX
value|0x01B
end_define

begin_comment
comment|/* RW: Test Mux Config             */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TEST
value|0x01C
end_define

begin_comment
comment|/* RW: Test Config                 */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LIU_CR
value|0x020
end_define

begin_comment
comment|/* RW: Line Intf Unit Config Reg   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSTAT
value|0x021
end_define

begin_comment
comment|/* RO; Receive LIU Status          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RLIU_CR
value|0x022
end_define

begin_comment
comment|/* RW: Receive LIU Config          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LPF
value|0x023
end_define

begin_comment
comment|/* RW: RPLL Low Pass Filter        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_VGA_MAX
value|0x024
end_define

begin_comment
comment|/* RW: Variable Gain Amplifier Max */
end_comment

begin_define
define|#
directive|define
name|Bt8370_EQ_DAT
value|0x025
end_define

begin_comment
comment|/* RW: Equalizer Coeff Data Reg    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_EQ_PTR
value|0x026
end_define

begin_comment
comment|/* RW: Equzlizer Coeff Table Ptr   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DSLICE
value|0x027
end_define

begin_comment
comment|/* RW: Data Slicer Threshold       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_EQ_OUT
value|0x028
end_define

begin_comment
comment|/* RW: Equalizer Output Levels     */
end_comment

begin_define
define|#
directive|define
name|Bt8370_VGA
value|0x029
end_define

begin_comment
comment|/* RO: Variable Gain Ampl Status   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_PRE_EQ
value|0x02A
end_define

begin_comment
comment|/* RW: Pre-Equalizer               */
end_comment

begin_define
define|#
directive|define
name|Bt8370_COEFF0
value|0x030
end_define

begin_comment
comment|/* RO: LMS Adj Eq Coeff Status     */
end_comment

begin_define
define|#
directive|define
name|Bt8370_GAIN0
value|0x038
end_define

begin_comment
comment|/* RW: Equalizer Gain Thresh       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_GAIN1
value|0x039
end_define

begin_comment
comment|/* RW: Equalizer Gain Thresh       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_GAIN2
value|0x03A
end_define

begin_comment
comment|/* RW: Equalizer Gain Thresh       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_GAIN3
value|0x03B
end_define

begin_comment
comment|/* RW: Equalizer Gain Thresh       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_GAIN4
value|0x03C
end_define

begin_comment
comment|/* RW: Equalizer Gain Thresh       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RCR0
value|0x040
end_define

begin_comment
comment|/* RW: Rx Configuration            */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RPATT
value|0x041
end_define

begin_comment
comment|/* RW: Rx Test Pattern Config      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RLB
value|0x042
end_define

begin_comment
comment|/* RW: Rx Loopback Code Detr Conf  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LBA
value|0x043
end_define

begin_comment
comment|/* RW: Loopback Activate Code Patt */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LBD
value|0x044
end_define

begin_comment
comment|/* RW: Loopback Deact Code Patt    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RALM
value|0x045
end_define

begin_comment
comment|/* RW: Rx Alarm Signal Config      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LATCH
value|0x046
end_define

begin_comment
comment|/* RW: Alarm/Err/Cntr Latch Config */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ALM1
value|0x047
end_define

begin_comment
comment|/* RO: Alarm 1 Status              */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ALM2
value|0x048
end_define

begin_comment
comment|/* RO: Alarm 2 Status              */
end_comment

begin_define
define|#
directive|define
name|Bt8370_ALM3
value|0x049
end_define

begin_comment
comment|/* RO: Alarm 3 Status              */
end_comment

begin_define
define|#
directive|define
name|Bt8370_FERR_LO
value|0x050
end_define

begin_comment
comment|/* RC: Framing Bit Error Cntr LSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_FERR_HI
value|0x051
end_define

begin_comment
comment|/* RC: Framing Bit Error Cntr MSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CRC_LO
value|0x052
end_define

begin_comment
comment|/* RC: CRC    Error   Counter LSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CRC_HI
value|0x053
end_define

begin_comment
comment|/* RC: CRC    Error   Counter MSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LCV_LO
value|0x054
end_define

begin_comment
comment|/* RC: Line Code Viol Counter LSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LCV_HI
value|0x055
end_define

begin_comment
comment|/* RC: Line Code Viol Counter MSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_FEBE_LO
value|0x056
end_define

begin_comment
comment|/* RC: Far End Block Err Cntr LSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_FEBE_HI
value|0x057
end_define

begin_comment
comment|/* RC: Far End Block Err Cntr MSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_BERR_LO
value|0x058
end_define

begin_comment
comment|/* RC: PRBS Bit Error Counter LSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_BERR_HI
value|0x059
end_define

begin_comment
comment|/* RC: PRBS Bit Error Counter MSB  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_AERR
value|0x05A
end_define

begin_comment
comment|/* RC: SEF/LOF/COFA counter        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSA4
value|0x05B
end_define

begin_comment
comment|/* RO: Rx Sa4 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSA5
value|0x05C
end_define

begin_comment
comment|/* RO: Rx Sa5 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSA6
value|0x05D
end_define

begin_comment
comment|/* RO: Rx Sa6 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSA7
value|0x05E
end_define

begin_comment
comment|/* RO: Rx Sa7 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSA8
value|0x05F
end_define

begin_comment
comment|/* RO: Rx Sa8 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_SHAPE0
value|0x060
end_define

begin_comment
comment|/* RW: Tx Pulse Shape Config       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TLIU_CR
value|0x068
end_define

begin_comment
comment|/* RW: Tx LIU Config Reg           */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TCR0
value|0x070
end_define

begin_comment
comment|/* RW: Tx Framer Config            */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TCR1
value|0x071
end_define

begin_comment
comment|/* RW: Txter Configuration         */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TFRM
value|0x072
end_define

begin_comment
comment|/* RW: Tx Frame Format             */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TERROR
value|0x073
end_define

begin_comment
comment|/* RW: Tx Error Insert             */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TMAN
value|0x074
end_define

begin_comment
comment|/* RW: Tx Manual Sa/FEBE Config    */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TALM
value|0x075
end_define

begin_comment
comment|/* RW: Tx Alarm Signal Config      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TPATT
value|0x076
end_define

begin_comment
comment|/* RW: Tx Test Pattern Config      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TLB
value|0x077
end_define

begin_comment
comment|/* RW: Tx Inband Loopback Config   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_LBP
value|0x078
end_define

begin_comment
comment|/* RW: Tx Inband Loopback Patt     */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSA4
value|0x07B
end_define

begin_comment
comment|/* RW: Tx Sa4 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSA5
value|0x07C
end_define

begin_comment
comment|/* RW: Tx Sa5 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSA6
value|0x07D
end_define

begin_comment
comment|/* RW: Tx Sa6 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSA7
value|0x07E
end_define

begin_comment
comment|/* RW: Tx Sa7 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSA8
value|0x07F
end_define

begin_comment
comment|/* RW: Tx Sa8 Byte Buffer          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CLAD_CR
value|0x090
end_define

begin_comment
comment|/* RW: Clock Rate Adapter Config   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CSEL
value|0x091
end_define

begin_comment
comment|/* RW: CLAD Frequency Select       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CPHASE
value|0x092
end_define

begin_comment
comment|/* RW: CLAD Phase Det Scale Factor */
end_comment

begin_define
define|#
directive|define
name|Bt8370_CTEST
value|0x093
end_define

begin_comment
comment|/* RW: CLAD Test                   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_BOP
value|0x0A0
end_define

begin_comment
comment|/* RW: Bit Oriented Protocol Xcvr  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TBOP
value|0x0A1
end_define

begin_comment
comment|/* RW: Tx BOP Codeword             */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RBOP
value|0x0A2
end_define

begin_comment
comment|/* RO; Rx BOP Codeword             */
end_comment

begin_define
define|#
directive|define
name|Bt8370_BOP_STAT
value|0x0A3
end_define

begin_comment
comment|/* RO: BOP Status                  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL1_TS
value|0x0A4
end_define

begin_comment
comment|/* RW: DL1 Time Slot Enable        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL1_BIT
value|0x0A5
end_define

begin_comment
comment|/* RW: DL1 Bit Enable              */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL1_CTL
value|0x0A6
end_define

begin_comment
comment|/* RW: DL1 Control                 */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RDL1_FFC
value|0x0A7
end_define

begin_comment
comment|/* RW: RDL1 FIFO Fill Control      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RDL1
value|0x0A8
end_define

begin_comment
comment|/* RO: RDL1 FIFO                   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RDL1_STAT
value|0x0A9
end_define

begin_comment
comment|/* RO: RDL1 Status                 */
end_comment

begin_define
define|#
directive|define
name|Bt8370_PRM
value|0x0AA
end_define

begin_comment
comment|/* RW: Performance Report Message  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL1_FEC
value|0x0AB
end_define

begin_comment
comment|/* RW: TDL1 FIFO Empty Control     */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL1_EOM
value|0x0AC
end_define

begin_comment
comment|/* WO: TDL1 End Of Message Control */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL1
value|0x0AD
end_define

begin_comment
comment|/* RW: TDL1 FIFO                   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL1_STAT
value|0x0AE
end_define

begin_comment
comment|/* RO: TDL1 Status                 */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL2_TS
value|0x0AF
end_define

begin_comment
comment|/* RW: DL2 Time Slot Enable        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL2_BIT
value|0x0B0
end_define

begin_comment
comment|/* RW: DL2 Bit Enable              */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL2_CTL
value|0x0B1
end_define

begin_comment
comment|/* RW: DL2 Control                 */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RDL2_FFC
value|0x0B2
end_define

begin_comment
comment|/* RW: RDL2 FIFO Fill Control      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RDL2
value|0x0B3
end_define

begin_comment
comment|/* RO: RDL2 FIFO                   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RDL2_STAT
value|0x0B4
end_define

begin_comment
comment|/* RO: RDL2 Status                 */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL2_FEC
value|0x0B6
end_define

begin_comment
comment|/* RW: TDL2 FIFO Empty Control     */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL2_EOM
value|0x0B7
end_define

begin_comment
comment|/* WO; TDL2 End Of Message Control */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL2
value|0x0B8
end_define

begin_comment
comment|/* RW: TDL2 FIFO                   */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TDL2_STAT
value|0x0B9
end_define

begin_comment
comment|/* RO: TDL2 Status                 */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL_TEST1
value|0x0BA
end_define

begin_comment
comment|/* RW: DLINK Test Config           */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL_TEST2
value|0x0BB
end_define

begin_comment
comment|/* RW: DLINK Test Status           */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL_TEST3
value|0x0BC
end_define

begin_comment
comment|/* RW: DLINK Test Status           */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL_TEST4
value|0x0BD
end_define

begin_comment
comment|/* RW: DLINK Test Control          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_DL_TEST5
value|0x0BE
end_define

begin_comment
comment|/* RW: DLINK Test Control          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_SBI_CR
value|0x0D0
end_define

begin_comment
comment|/* RW: System Bus Interface Config */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSB_CR
value|0x0D1
end_define

begin_comment
comment|/* RW: Rx System Bus Config        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSYNC_BIT
value|0x0D2
end_define

begin_comment
comment|/* RW: Rx System Bus Sync Bit Offs */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSYNC_TS
value|0x0D3
end_define

begin_comment
comment|/* RW: Rx System Bus Sync TS Offs  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSB_CR
value|0x0D4
end_define

begin_comment
comment|/* RW: Tx System Bus Config        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSYNC_BIT
value|0x0D5
end_define

begin_comment
comment|/* RW: Tx System Bus Sync Bit OFfs */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSYNC_TS
value|0x0D6
end_define

begin_comment
comment|/* RW: Tx System Bus Sync TS Offs  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSIG_CR
value|0x0D7
end_define

begin_comment
comment|/* RW: Rx Siganalling Config       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSYNC_FRM
value|0x0D8
end_define

begin_comment
comment|/* RW: Sig Reinsertion Frame Offs  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_SSTAT
value|0x0D9
end_define

begin_comment
comment|/* RO: Slip Buffer Status          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_STACK
value|0x0DA
end_define

begin_comment
comment|/* RO: Rx Signalling Stack         */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RPHASE
value|0x0DB
end_define

begin_comment
comment|/* RO: RSLIP Phase Status          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TPHASE
value|0x0DC
end_define

begin_comment
comment|/* RO: TSLIP Phase Status          */
end_comment

begin_define
define|#
directive|define
name|Bt8370_PERR
value|0x0DD
end_define

begin_comment
comment|/* RO: RAM Parity Status           */
end_comment

begin_define
define|#
directive|define
name|Bt8370_SBCn
value|0x0E0
end_define

begin_comment
comment|/* RW: System Bus Per-Channel Ctl  */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TPCn
value|0x100
end_define

begin_comment
comment|/* RW: Tx Per-Channel Control      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSIGn
value|0x120
end_define

begin_comment
comment|/* RW: Tx Signalling Buffer        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSLIP_LOn
value|0x140
end_define

begin_comment
comment|/* RW: Tx PCM Slip Buffer Lo       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_TSLIP_HIn
value|0x160
end_define

begin_comment
comment|/* RW: Tx PCM Slip Buffer Hi       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RPCn
value|0x180
end_define

begin_comment
comment|/* RW: Rx Per-Channel Control      */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSIGn
value|0x1A0
end_define

begin_comment
comment|/* RW: Rx Signalling Buffer        */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSLIP_LOn
value|0x1C0
end_define

begin_comment
comment|/* RW: Rx PCM Slip Buffer Lo       */
end_comment

begin_define
define|#
directive|define
name|Bt8370_RSLIP_HIn
value|0x1E0
end_define

begin_comment
comment|/* RW: Rx PCM Slip Buffer Hi       */
end_comment

begin_comment
comment|/* Bt8370_LOOP (0x14) framer loopback control register bits */
end_comment

begin_define
define|#
directive|define
name|LOOP_ANALOG
value|0x01
end_define

begin_comment
comment|/* inward  loop thru LIU           */
end_comment

begin_define
define|#
directive|define
name|LOOP_FRAMER
value|0x02
end_define

begin_comment
comment|/* inward  loop thru framer        */
end_comment

begin_define
define|#
directive|define
name|LOOP_LINE
value|0x04
end_define

begin_comment
comment|/* outward loop thru LIU           */
end_comment

begin_define
define|#
directive|define
name|LOOP_PAYLOAD
value|0x08
end_define

begin_comment
comment|/* outward loop of payload         */
end_comment

begin_define
define|#
directive|define
name|LOOP_DUAL
value|0x06
end_define

begin_comment
comment|/* inward framer + outward line    */
end_comment

begin_comment
comment|/* Bt8370_ALM1 (0x47) receiver alarm status register bits */
end_comment

begin_define
define|#
directive|define
name|ALM1_SIGFRZ
value|0x01
end_define

begin_comment
comment|/* Rx Signalling Freeze            */
end_comment

begin_define
define|#
directive|define
name|ALM1_RLOF
value|0x02
end_define

begin_comment
comment|/* Rx loss of frame alignment      */
end_comment

begin_define
define|#
directive|define
name|ALM1_RLOS
value|0x04
end_define

begin_comment
comment|/* Rx digital loss of signal       */
end_comment

begin_define
define|#
directive|define
name|ALM1_RALOS
value|0x08
end_define

begin_comment
comment|/* Rx analog  loss of signal       */
end_comment

begin_define
define|#
directive|define
name|ALM1_RAIS
value|0x10
end_define

begin_comment
comment|/* Rx Alarm Indication Signal      */
end_comment

begin_define
define|#
directive|define
name|ALM1_RYEL
value|0x40
end_define

begin_comment
comment|/* Rx Yellow alarm indication      */
end_comment

begin_define
define|#
directive|define
name|ALM1_RMYEL
value|0x80
end_define

begin_comment
comment|/* Rx multiframe YELLOW alarm      */
end_comment

begin_comment
comment|/* Bt8370_ALM3 (0x49) receive framer status register bits */
end_comment

begin_define
define|#
directive|define
name|ALM3_FRED
value|0x04
end_define

begin_comment
comment|/* Rx Out Of T1/FAS alignment      */
end_comment

begin_define
define|#
directive|define
name|ALM3_MRED
value|0x08
end_define

begin_comment
comment|/* Rx Out Of MFAS alignment        */
end_comment

begin_define
define|#
directive|define
name|ALM3_SRED
value|0x10
end_define

begin_comment
comment|/* Rx Out Of CAS alignment         */
end_comment

begin_define
define|#
directive|define
name|ALM3_SEF
value|0x20
end_define

begin_comment
comment|/* Rx Severely Errored Frame       */
end_comment

begin_define
define|#
directive|define
name|ALM3_RMAIS
value|0x40
end_define

begin_comment
comment|/* Rx TS16 AIS (CAS)               */
end_comment

begin_comment
comment|/* Bt8370_TALM (0x75) transmit alarm control register bits */
end_comment

begin_define
define|#
directive|define
name|TALM_TAIS
value|0x01
end_define

begin_comment
comment|/* Tx Alarm Indication Signal      */
end_comment

begin_define
define|#
directive|define
name|TALM_TYEL
value|0x02
end_define

begin_comment
comment|/* Tx Yellow alarm                 */
end_comment

begin_define
define|#
directive|define
name|TALM_TMYEL
value|0x04
end_define

begin_comment
comment|/* Tx Multiframe Yellow alarm      */
end_comment

begin_define
define|#
directive|define
name|TALM_AUTO_AIS
value|0x08
end_define

begin_comment
comment|/* auto send AIS on LOS            */
end_comment

begin_define
define|#
directive|define
name|TALM_AUTO_YEL
value|0x10
end_define

begin_comment
comment|/* auto send YEL on LOF            */
end_comment

begin_define
define|#
directive|define
name|TALM_AUTO_MYEL
value|0x20
end_define

begin_comment
comment|/* auto send E1-Y16 on loss-of-CAS */
end_comment

begin_comment
comment|/* 8370 BOP (Bit Oriented Protocol) command fragments */
end_comment

begin_define
define|#
directive|define
name|RBOP_OFF
value|0x00
end_define

begin_comment
comment|/* BOP Rx disabled                 */
end_comment

begin_define
define|#
directive|define
name|RBOP_25
value|0xE0
end_define

begin_comment
comment|/* BOP Rx requires 25 BOPs         */
end_comment

begin_define
define|#
directive|define
name|TBOP_OFF
value|0x00
end_define

begin_comment
comment|/* BOP Tx disabled                 */
end_comment

begin_define
define|#
directive|define
name|TBOP_25
value|0x0B
end_define

begin_comment
comment|/* BOP Tx sends 25 BOPs            */
end_comment

begin_define
define|#
directive|define
name|TBOP_CONT
value|0x0F
end_define

begin_comment
comment|/* BOP Tx sends continuously       */
end_comment

begin_comment
comment|/* T1.403 Bit-Oriented ESF Data-Link Message codes */
end_comment

begin_define
define|#
directive|define
name|T1BOP_OOF
value|0x00
end_define

begin_comment
comment|/* Yellow alarm status             */
end_comment

begin_define
define|#
directive|define
name|T1BOP_LINE_UP
value|0x07
end_define

begin_comment
comment|/* line loopback activate          */
end_comment

begin_define
define|#
directive|define
name|T1BOP_LINE_DOWN
value|0x1C
end_define

begin_comment
comment|/* line loopback deactivate        */
end_comment

begin_define
define|#
directive|define
name|T1BOP_PAY_UP
value|0x0A
end_define

begin_comment
comment|/* payload loopback activate       */
end_comment

begin_define
define|#
directive|define
name|T1BOP_PAY_DOWN
value|0x19
end_define

begin_comment
comment|/* payload loopback deactivate     */
end_comment

begin_define
define|#
directive|define
name|T1BOP_NET_UP
value|0x09
end_define

begin_comment
comment|/* network loopback activate       */
end_comment

begin_define
define|#
directive|define
name|T1BOP_NET_DOWN
value|0x12
end_define

begin_comment
comment|/* network loopback deactivate     */
end_comment

begin_comment
comment|/* Unix& Linux reserve 16 device-private IOCTLs */
end_comment

begin_if
if|#
directive|if
name|BSD
end_if

begin_define
define|#
directive|define
name|LMCIOCGSTAT
value|_IOWR('i', 240, struct status)
end_define

begin_define
define|#
directive|define
name|LMCIOCGCFG
value|_IOWR('i', 241, struct config)
end_define

begin_define
define|#
directive|define
name|LMCIOCSCFG
value|_IOW('i', 242, struct config)
end_define

begin_define
define|#
directive|define
name|LMCIOCREAD
value|_IOWR('i', 243, struct ioctl)
end_define

begin_define
define|#
directive|define
name|LMCIOCWRITE
value|_IOW('i', 244, struct ioctl)
end_define

begin_define
define|#
directive|define
name|LMCIOCTL
value|_IOWR('i', 245, struct ioctl)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
end_elif

begin_comment
comment|/* sigh */
end_comment

begin_define
define|#
directive|define
name|LMCIOCGSTAT
value|SIOCDEVPRIVATE+0
end_define

begin_define
define|#
directive|define
name|LMCIOCGCFG
value|SIOCDEVPRIVATE+1
end_define

begin_define
define|#
directive|define
name|LMCIOCSCFG
value|SIOCDEVPRIVATE+2
end_define

begin_define
define|#
directive|define
name|LMCIOCREAD
value|SIOCDEVPRIVATE+3
end_define

begin_define
define|#
directive|define
name|LMCIOCWRITE
value|SIOCDEVPRIVATE+4
end_define

begin_define
define|#
directive|define
name|LMCIOCTL
value|SIOCDEVPRIVATE+5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|iohdr
comment|/* all LMCIOCs begin with this     */
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name, e.g. "lmc0"     */
name|u_int32_t
name|cookie
decl_stmt|;
comment|/* interface version number        */
name|u_int16_t
name|direction
decl_stmt|;
comment|/* missing in Linux IOCTL          */
name|u_int16_t
name|length
decl_stmt|;
comment|/* missing in Linux IOCTL          */
name|struct
name|iohdr
modifier|*
name|iohdr
decl_stmt|;
comment|/* missing in Linux IOCTL          */
name|u_int32_t
name|spare
decl_stmt|;
comment|/* pad this struct to **32 bytes** */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DIR_IO
value|0
end_define

begin_define
define|#
directive|define
name|DIR_IOW
value|1
end_define

begin_comment
comment|/* copy data user->kernel          */
end_comment

begin_define
define|#
directive|define
name|DIR_IOR
value|2
end_define

begin_comment
comment|/* copy data kernel->user          */
end_comment

begin_define
define|#
directive|define
name|DIR_IOWR
value|3
end_define

begin_comment
comment|/* copy data kernel<->user         */
end_comment

begin_struct
struct|struct
name|hssi_snmp
block|{
name|u_int16_t
name|sigs
decl_stmt|;
comment|/* MII16_HSSI& MII16_HSSI_MODEM   */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ssi_snmp
block|{
name|u_int16_t
name|sigs
decl_stmt|;
comment|/* MII16_SSI& MII16_SSI_MODEM     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_snmp
block|{
name|u_int16_t
name|febe
decl_stmt|;
comment|/*  8 bits - Far End Block err cnt */
name|u_int16_t
name|lcv
decl_stmt|;
comment|/* 16 bits - BPV           err cnt */
name|u_int16_t
name|pcv
decl_stmt|;
comment|/*  8 bits - P-bit         err cnt */
name|u_int16_t
name|ccv
decl_stmt|;
comment|/*  8 bits - C-bit         err cnt */
name|u_int16_t
name|line
decl_stmt|;
comment|/* line status bit vector          */
name|u_int16_t
name|loop
decl_stmt|;
comment|/* loop status bit vector          */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t1_snmp
block|{
name|u_int16_t
name|prm
index|[
literal|4
index|]
decl_stmt|;
comment|/* T1.403 Performance Report Msg   */
name|u_int16_t
name|febe
decl_stmt|;
comment|/* 10 bits - E1 FAR CRC    err cnt */
name|u_int16_t
name|lcv
decl_stmt|;
comment|/* 16 bits - BPV + EXZ     err cnt */
name|u_int16_t
name|fe
decl_stmt|;
comment|/* 12 bits - Ft/Fs/FPS/FAS err cnt */
name|u_int16_t
name|crc
decl_stmt|;
comment|/* 10 bits - CRC6/CRC4     err cnt */
name|u_int16_t
name|line
decl_stmt|;
comment|/* line status bit vector          */
name|u_int16_t
name|loop
decl_stmt|;
comment|/* loop status bit vector          */
block|}
struct|;
end_struct

begin_comment
comment|/* SNMP trunk MIB Send codes */
end_comment

begin_define
define|#
directive|define
name|TSEND_NORMAL
value|1
end_define

begin_comment
comment|/* Send data (normal or looped)    */
end_comment

begin_define
define|#
directive|define
name|TSEND_LINE
value|2
end_define

begin_comment
comment|/* Send 'line loopback activate'   */
end_comment

begin_define
define|#
directive|define
name|TSEND_PAYLOAD
value|3
end_define

begin_comment
comment|/* Send 'payload loop activate'    */
end_comment

begin_define
define|#
directive|define
name|TSEND_RESET
value|4
end_define

begin_comment
comment|/* Send 'loopback deactivate'      */
end_comment

begin_define
define|#
directive|define
name|TSEND_QRS
value|5
end_define

begin_comment
comment|/* Send Quasi Random Signal        */
end_comment

begin_comment
comment|/* ANSI T1.403 Performance Report Msg -- once a second from the far end    */
end_comment

begin_define
define|#
directive|define
name|T1PRM_FE
value|0x8000
end_define

begin_comment
comment|/* Frame Sync Bit Error Event>= 1 */
end_comment

begin_define
define|#
directive|define
name|T1PRM_SE
value|0x4000
end_define

begin_comment
comment|/* Severely Err Framing Event>= 1 */
end_comment

begin_define
define|#
directive|define
name|T1PRM_LB
value|0x2000
end_define

begin_comment
comment|/* Payload Loopback Activated      */
end_comment

begin_define
define|#
directive|define
name|T1PRM_G1
value|0x1000
end_define

begin_comment
comment|/* CRC Error Event = 1             */
end_comment

begin_define
define|#
directive|define
name|T1PRM_R
value|0x0800
end_define

begin_comment
comment|/* Reserved                        */
end_comment

begin_define
define|#
directive|define
name|T1PRM_G2
value|0x0400
end_define

begin_comment
comment|/* 1< CRC Error Event<= 5        */
end_comment

begin_define
define|#
directive|define
name|T1PRM_SEQ
value|0x0300
end_define

begin_comment
comment|/* modulo 4 counter                */
end_comment

begin_define
define|#
directive|define
name|T1PRM_G3
value|0x0080
end_define

begin_comment
comment|/* 5< CRC Error Event<= 10       */
end_comment

begin_define
define|#
directive|define
name|T1PRM_LV
value|0x0040
end_define

begin_comment
comment|/* Line Code Violation Event>= 1  */
end_comment

begin_define
define|#
directive|define
name|T1PRM_G4
value|0x0020
end_define

begin_comment
comment|/* 10< CRC Error Event<= 100     */
end_comment

begin_define
define|#
directive|define
name|T1PRM_U
value|0x0018
end_define

begin_comment
comment|/* Under study for synchronization */
end_comment

begin_define
define|#
directive|define
name|T1PRM_G5
value|0x0004
end_define

begin_comment
comment|/* 100< CRC Error Event<= 319    */
end_comment

begin_define
define|#
directive|define
name|T1PRM_SL
value|0x0002
end_define

begin_comment
comment|/* Slip Event>= 1                 */
end_comment

begin_define
define|#
directive|define
name|T1PRM_G6
value|0x0001
end_define

begin_comment
comment|/* CRC Error Event>= 320          */
end_comment

begin_comment
comment|/* SNMP Line Status */
end_comment

begin_define
define|#
directive|define
name|TLINE_NORM
value|0x0001
end_define

begin_comment
comment|/* no alarm present                */
end_comment

begin_define
define|#
directive|define
name|TLINE_RX_RAI
value|0x0002
end_define

begin_comment
comment|/* receiving RAI = Yellow alarm    */
end_comment

begin_define
define|#
directive|define
name|TLINE_TX_RAI
value|0x0004
end_define

begin_comment
comment|/* sending   RAI = Yellow alarm    */
end_comment

begin_define
define|#
directive|define
name|TLINE_RX_AIS
value|0x0008
end_define

begin_comment
comment|/* receiving AIS =  blue  alarm    */
end_comment

begin_define
define|#
directive|define
name|TLINE_TX_AIS
value|0x0010
end_define

begin_comment
comment|/* sending   AIS =  blue  alarm    */
end_comment

begin_define
define|#
directive|define
name|TLINE_LOF
value|0x0020
end_define

begin_comment
comment|/* near end  LOF =   red  alarm    */
end_comment

begin_define
define|#
directive|define
name|TLINE_LOS
value|0x0040
end_define

begin_comment
comment|/* near end loss of Signal         */
end_comment

begin_define
define|#
directive|define
name|TLINE_LOOP
value|0x0080
end_define

begin_comment
comment|/* near end is looped              */
end_comment

begin_define
define|#
directive|define
name|T1LINE_RX_TS16_AIS
value|0x0100
end_define

begin_comment
comment|/* near end receiving TS16 AIS     */
end_comment

begin_define
define|#
directive|define
name|T1LINE_RX_TS16_LOMF
value|0x0200
end_define

begin_comment
comment|/* near end sending   TS16 LOMF    */
end_comment

begin_define
define|#
directive|define
name|T1LINE_TX_TS16_LOMF
value|0x0400
end_define

begin_comment
comment|/* near end receiving TS16 LOMF    */
end_comment

begin_define
define|#
directive|define
name|T1LINE_RX_TEST
value|0x0800
end_define

begin_comment
comment|/* near end receiving QRS Signal   */
end_comment

begin_define
define|#
directive|define
name|T1LINE_SEF
value|0x1000
end_define

begin_comment
comment|/* near end severely errored frame */
end_comment

begin_define
define|#
directive|define
name|T3LINE_RX_IDLE
value|0x0100
end_define

begin_comment
comment|/* near end receiving IDLE signal  */
end_comment

begin_define
define|#
directive|define
name|T3LINE_SEF
value|0x0200
end_define

begin_comment
comment|/* near end severely errored frame */
end_comment

begin_comment
comment|/* SNMP Loopback Status */
end_comment

begin_define
define|#
directive|define
name|TLOOP_NONE
value|0x01
end_define

begin_comment
comment|/* no loopback                     */
end_comment

begin_define
define|#
directive|define
name|TLOOP_NEAR_PAYLOAD
value|0x02
end_define

begin_comment
comment|/* near end payload loopback       */
end_comment

begin_define
define|#
directive|define
name|TLOOP_NEAR_LINE
value|0x04
end_define

begin_comment
comment|/* near end line loopback          */
end_comment

begin_define
define|#
directive|define
name|TLOOP_NEAR_OTHER
value|0x08
end_define

begin_comment
comment|/* near end looped somehow         */
end_comment

begin_define
define|#
directive|define
name|TLOOP_NEAR_INWARD
value|0x10
end_define

begin_comment
comment|/* near end looped inward          */
end_comment

begin_define
define|#
directive|define
name|TLOOP_FAR_PAYLOAD
value|0x20
end_define

begin_comment
comment|/* far  end payload loopback       */
end_comment

begin_define
define|#
directive|define
name|TLOOP_FAR_LINE
value|0x40
end_define

begin_comment
comment|/* far  end line loopback          */
end_comment

begin_comment
comment|/* event counters record interesting statistics */
end_comment

begin_struct
struct|struct
name|event_cntrs
block|{
name|struct
name|timeval
name|reset_time
decl_stmt|;
comment|/* time when cntrs were reset      */
name|u_int64_t
name|ibytes
decl_stmt|;
comment|/* Rx bytes   with good status     */
name|u_int64_t
name|obytes
decl_stmt|;
comment|/* Tx bytes                        */
name|u_int64_t
name|ipackets
decl_stmt|;
comment|/* Rx packets with good status     */
name|u_int64_t
name|opackets
decl_stmt|;
comment|/* Tx packets                      */
name|u_int32_t
name|ierrors
decl_stmt|;
comment|/* Rx packets with bad status      */
name|u_int32_t
name|oerrors
decl_stmt|;
comment|/* Tx packets with bad status      */
name|u_int32_t
name|idiscards
decl_stmt|;
comment|/* Rx packets discarded            */
name|u_int32_t
name|odiscards
decl_stmt|;
comment|/* Tx packets discarded            */
name|u_int32_t
name|fifo_over
decl_stmt|;
comment|/* Rx fifo overruns                */
name|u_int32_t
name|fifo_under
decl_stmt|;
comment|/* Tx fifo underruns               */
name|u_int32_t
name|missed
decl_stmt|;
comment|/* Rx pkts missed: no DMA descs    */
name|u_int32_t
name|overruns
decl_stmt|;
comment|/* Rx pkts missed: fifo overrun    */
name|u_int32_t
name|fdl_pkts
decl_stmt|;
comment|/* Rx T1 Facility Data Link pkts   */
name|u_int32_t
name|crc_errs
decl_stmt|;
comment|/* Rx T1 frame CRC errors          */
name|u_int32_t
name|lcv_errs
decl_stmt|;
comment|/* Rx T1 T3 Line Coding Violation  */
name|u_int32_t
name|frm_errs
decl_stmt|;
comment|/* Rx T1 T3 Frame bit errors       */
name|u_int32_t
name|febe_errs
decl_stmt|;
comment|/* Rx T1 T3 Far End Bit Errors     */
name|u_int32_t
name|par_errs
decl_stmt|;
comment|/* Rx T3 P-bit parity errors       */
name|u_int32_t
name|cpar_errs
decl_stmt|;
comment|/* Rx T3 C-bit parity errors       */
name|u_int32_t
name|mfrm_errs
decl_stmt|;
comment|/* Rx T3 Multi-frame bit errors    */
name|u_int32_t
name|rxdma
decl_stmt|;
comment|/* Rx out of kernel buffers        */
name|u_int32_t
name|txdma
decl_stmt|;
comment|/* Tx out of DMA desciptors        */
name|u_int32_t
name|lck_watch
decl_stmt|;
comment|/* try_lock conflict in watchdog   */
name|u_int32_t
name|lck_ioctl
decl_stmt|;
comment|/* try_lock conflict in ioctl      */
name|u_int32_t
name|lck_intr
decl_stmt|;
comment|/* try_lock conflict in interrupt  */
block|}
struct|;
end_struct

begin_comment
comment|/* sc->status is the READ ONLY status of the card.                         */
end_comment

begin_comment
comment|/* Accessed using socket IO control calls or netgraph control messages.    */
end_comment

begin_struct
struct|struct
name|status
block|{
name|struct
name|iohdr
name|iohdr
decl_stmt|;
comment|/* common ioctl header             */
name|u_int32_t
name|card_type
decl_stmt|;
comment|/* PCI device number               */
name|u_int16_t
name|ieee
index|[
literal|3
index|]
decl_stmt|;
comment|/* IEEE MAC-addr from Tulip SROM   */
name|u_int16_t
name|oper_status
decl_stmt|;
comment|/* actual state:  up, down, test   */
name|u_int32_t
name|tx_speed
decl_stmt|;
comment|/* measured TX bits/sec            */
name|u_int32_t
name|cable_type
decl_stmt|;
comment|/* SSI only: cable type            */
name|u_int32_t
name|line_pkg
decl_stmt|;
comment|/* actual line pkg in use          */
name|u_int32_t
name|line_prot
decl_stmt|;
comment|/* actual line proto in use        */
name|u_int32_t
name|ticks
decl_stmt|;
comment|/* incremented by watchdog @ 1 Hz  */
name|struct
name|event_cntrs
name|cntrs
decl_stmt|;
comment|/* event counters                  */
union|union
block|{
name|struct
name|hssi_snmp
name|hssi
decl_stmt|;
comment|/* data for RFC-???? HSSI MIB      */
name|struct
name|t3_snmp
name|t3
decl_stmt|;
comment|/* data for RFC-2496 T3 MIB        */
name|struct
name|ssi_snmp
name|ssi
decl_stmt|;
comment|/* data for RFC-1659 RS232 MIB     */
name|struct
name|t1_snmp
name|t1
decl_stmt|;
comment|/* data for RFC-2495 T1 MIB        */
block|}
name|snmp
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* line protocol package codes                                       fnobl */
end_comment

begin_define
define|#
directive|define
name|PKG_RAWIP
value|1
end_define

begin_comment
comment|/* driver                    yyyyy */
end_comment

begin_define
define|#
directive|define
name|PKG_SPPP
value|2
end_define

begin_comment
comment|/* fbsd, nbsd, obsd          yyynn */
end_comment

begin_define
define|#
directive|define
name|PKG_P2P
value|3
end_define

begin_comment
comment|/* bsd/os                    nnnyn */
end_comment

begin_define
define|#
directive|define
name|PKG_NG
value|4
end_define

begin_comment
comment|/* fbsd                      ynnnn */
end_comment

begin_define
define|#
directive|define
name|PKG_GEN_HDLC
value|5
end_define

begin_comment
comment|/* linux                     nnnny */
end_comment

begin_comment
comment|/* line protocol codes                                               fnobl */
end_comment

begin_define
define|#
directive|define
name|PROT_PPP
value|1
end_define

begin_comment
comment|/* Point-to-Point Protocol   yyyyy */
end_comment

begin_define
define|#
directive|define
name|PROT_C_HDLC
value|2
end_define

begin_comment
comment|/* Cisco HDLC Protocol       yyyyy */
end_comment

begin_define
define|#
directive|define
name|PROT_FRM_RLY
value|3
end_define

begin_comment
comment|/* Frame Relay Protocol      ynnyy */
end_comment

begin_define
define|#
directive|define
name|PROT_X25
value|4
end_define

begin_comment
comment|/* X.25/LAPB Protocol        nnnny */
end_comment

begin_define
define|#
directive|define
name|PROT_ETH_HDLC
value|5
end_define

begin_comment
comment|/* raw Ether pkts in HDLC    nnnny */
end_comment

begin_define
define|#
directive|define
name|PROT_IP_HDLC
value|6
end_define

begin_comment
comment|/* raw IP4/6 pkts in HDLC    yyyyy */
end_comment

begin_comment
comment|/* oper_status codes (same as SNMP status codes) */
end_comment

begin_define
define|#
directive|define
name|STATUS_UP
value|1
end_define

begin_comment
comment|/* may/will    tx/rx pkts          */
end_comment

begin_define
define|#
directive|define
name|STATUS_DOWN
value|2
end_define

begin_comment
comment|/* can't/won't tx/rx pkts          */
end_comment

begin_define
define|#
directive|define
name|STATUS_TEST
value|3
end_define

begin_comment
comment|/* currently not used              */
end_comment

begin_struct
struct|struct
name|synth
comment|/* programmable oscillator params  */
block|{
name|unsigned
name|n
range|:
literal|7
decl_stmt|;
comment|/*   numerator (3..127)            */
name|unsigned
name|m
range|:
literal|7
decl_stmt|;
comment|/* denominator (3..127)            */
name|unsigned
name|v
range|:
literal|1
decl_stmt|;
comment|/* mul by 1|8                      */
name|unsigned
name|x
range|:
literal|2
decl_stmt|;
comment|/* div by 1|2|4|8                  */
name|unsigned
name|r
range|:
literal|2
decl_stmt|;
comment|/* div by 1|2|4|8                  */
name|unsigned
name|prescale
range|:
literal|13
decl_stmt|;
comment|/* log(final divisor): 2, 4 or 9   */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SYNTH_FREF
value|20e6
end_define

begin_comment
comment|/* reference xtal =  20 MHz        */
end_comment

begin_define
define|#
directive|define
name|SYNTH_FMIN
value|50e6
end_define

begin_comment
comment|/* internal VCO min  50 MHz        */
end_comment

begin_define
define|#
directive|define
name|SYNTH_FMAX
value|250e6
end_define

begin_comment
comment|/* internal VCO max 250 MHz        */
end_comment

begin_comment
comment|/* sc->config is the READ/WRITE configuration of the card.                 */
end_comment

begin_comment
comment|/* Accessed using socket IO control calls or netgraph control messages.    */
end_comment

begin_struct
struct|struct
name|config
block|{
name|struct
name|iohdr
name|iohdr
decl_stmt|;
comment|/* common ioctl header             */
name|u_int32_t
name|crc_len
decl_stmt|;
comment|/* ALL: CRC-16 or CRC-32 or none   */
name|u_int32_t
name|loop_back
decl_stmt|;
comment|/* ALL: many kinds of loopbacks    */
name|u_int32_t
name|tx_clk_src
decl_stmt|;
comment|/* T1, HSSI: ST, RT, int, ext      */
name|u_int32_t
name|format
decl_stmt|;
comment|/* T3, T1: ckt framing format      */
name|u_int32_t
name|time_slots
decl_stmt|;
comment|/* T1: 64Kb time slot config       */
name|u_int32_t
name|cable_len
decl_stmt|;
comment|/* T3, T1: cable length in meters  */
name|u_int32_t
name|scrambler
decl_stmt|;
comment|/* T3: payload scrambler config    */
name|u_int32_t
name|dte_dce
decl_stmt|;
comment|/* SSI, HSSIc: drive TXCLK         */
name|struct
name|synth
name|synth
decl_stmt|;
comment|/* SSI, HSSIc: synth oscil params  */
name|u_int32_t
name|rx_gain
decl_stmt|;
comment|/* T1: receiver gain limit 0-50 dB */
name|u_int32_t
name|tx_pulse
decl_stmt|;
comment|/* T1: transmitter pulse shape     */
name|u_int32_t
name|tx_lbo
decl_stmt|;
comment|/* T1: transmitter atten 0-22.5 dB */
name|u_int32_t
name|debug
decl_stmt|;
comment|/* ALL: extra printout             */
name|u_int32_t
name|line_pkg
decl_stmt|;
comment|/* ALL:  use this line pkg         */
name|u_int32_t
name|line_prot
decl_stmt|;
comment|/* SPPP: use this line proto       */
name|u_int32_t
name|keep_alive
decl_stmt|;
comment|/* SPPP: use keep-alive packets    */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CFG_CRC_0
value|0
end_define

begin_comment
comment|/* no CRC                          */
end_comment

begin_define
define|#
directive|define
name|CFG_CRC_16
value|2
end_define

begin_comment
comment|/* X^16+X^12+X^5+1 (default)       */
end_comment

begin_define
define|#
directive|define
name|CFG_CRC_32
value|4
end_define

begin_comment
comment|/* X^32+X^26+X^23+X^22+X^16+X^12+  */
end_comment

begin_comment
comment|/* X^11+X^10+X^8+X^7+X^5+X^4+X^2+X+1 */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_NONE
value|1
end_define

begin_comment
comment|/* SNMP don't loop back anything   */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_PAYLOAD
value|2
end_define

begin_comment
comment|/* SNMP loop outward thru framer   */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_LINE
value|3
end_define

begin_comment
comment|/* SNMP loop outward thru LIU      */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_OTHER
value|4
end_define

begin_comment
comment|/* SNMP loop  inward thru LIU      */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_INWARD
value|5
end_define

begin_comment
comment|/* SNMP loop  inward thru framer   */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_DUAL
value|6
end_define

begin_comment
comment|/* SNMP loop  inward& outward     */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_TULIP
value|16
end_define

begin_comment
comment|/* ALL: loop  inward thru Tulip    */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_PINS
value|17
end_define

begin_comment
comment|/* HSSIc, SSI: loop inward-pins    */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_LL
value|18
end_define

begin_comment
comment|/* HSSI, SSI: assert LA/LL mdm pin */
end_comment

begin_define
define|#
directive|define
name|CFG_LOOP_RL
value|19
end_define

begin_comment
comment|/* HSSI, SSI: assert LB/RL mdm pin */
end_comment

begin_define
define|#
directive|define
name|CFG_CLKMUX_ST
value|1
end_define

begin_comment
comment|/* TX clk<- Send timing           */
end_comment

begin_define
define|#
directive|define
name|CFG_CLKMUX_INT
value|2
end_define

begin_comment
comment|/* TX clk<- internal source       */
end_comment

begin_define
define|#
directive|define
name|CFG_CLKMUX_RT
value|3
end_define

begin_comment
comment|/* TX clk<- Receive (loop) timing */
end_comment

begin_define
define|#
directive|define
name|CFG_CLKMUX_EXT
value|4
end_define

begin_comment
comment|/* TX clk<- ext connector         */
end_comment

begin_comment
comment|/* values 0-31 are Bt8370 CR0 register values (LSB is zero if E1).         */
end_comment

begin_comment
comment|/* values 32-99 are reserved for other T1E1 formats, (even number if E1)   */
end_comment

begin_comment
comment|/* values 100 and up are used for T3 frame formats.                        */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_T1SF
value|9
end_define

begin_comment
comment|/* T1-SF          AMI              */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_T1ESF
value|27
end_define

begin_comment
comment|/* T1-ESF+CRC     B8ZS     X^6+X+1 */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_E1FAS
value|0
end_define

begin_comment
comment|/* E1-FAS         HDB3 TS0         */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_E1FASCRC
value|8
end_define

begin_comment
comment|/* E1-FAS+CRC     HDB3 TS0 X^4+X+1 */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_E1FASCAS
value|16
end_define

begin_comment
comment|/* E1-FAS    +CAS HDB3 TS0& TS16  */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_E1FASCRCCAS
value|24
end_define

begin_comment
comment|/* E1-FAS+CRC+CAS HDB3 TS0& TS16  */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_E1NONE
value|32
end_define

begin_comment
comment|/* E1-NO framing  HDB3             */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_T3CPAR
value|100
end_define

begin_comment
comment|/* T3-C-Bit par   B3ZS             */
end_comment

begin_define
define|#
directive|define
name|CFG_FORMAT_T3M13
value|101
end_define

begin_comment
comment|/* T3-M13 format  B3ZS             */
end_comment

begin_comment
comment|/* format aliases that improve code readability */
end_comment

begin_define
define|#
directive|define
name|FORMAT_T1ANY
value|((sc->config.format& 1)==1)
end_define

begin_define
define|#
directive|define
name|FORMAT_E1ANY
value|((sc->config.format& 1)==0)
end_define

begin_define
define|#
directive|define
name|FORMAT_E1CAS
value|((sc->config.format& 0x11)==0x10)
end_define

begin_define
define|#
directive|define
name|FORMAT_E1CRC
value|((sc->config.format& 0x09)==0x08)
end_define

begin_define
define|#
directive|define
name|FORMAT_E1NONE
value|(sc->config.format == CFG_FORMAT_E1NONE)
end_define

begin_define
define|#
directive|define
name|FORMAT_T1ESF
value|(sc->config.format == CFG_FORMAT_T1ESF)
end_define

begin_define
define|#
directive|define
name|FORMAT_T1SF
value|(sc->config.format == CFG_FORMAT_T1SF)
end_define

begin_define
define|#
directive|define
name|FORMAT_T3CPAR
value|(sc->config.format == CFG_FORMAT_T3CPAR)
end_define

begin_define
define|#
directive|define
name|CFG_SCRAM_OFF
value|1
end_define

begin_comment
comment|/* DS3 payload scrambler off       */
end_comment

begin_define
define|#
directive|define
name|CFG_SCRAM_DL_KEN
value|2
end_define

begin_comment
comment|/* DS3 DigitalLink/Kentrox X^43+1  */
end_comment

begin_define
define|#
directive|define
name|CFG_SCRAM_LARS
value|3
end_define

begin_comment
comment|/* DS3 Larscom X^20+X^17+1 w/28ZS  */
end_comment

begin_define
define|#
directive|define
name|CFG_DTE
value|1
end_define

begin_comment
comment|/* HSSIc, SSI: rcv TXCLK; rcv DCD  */
end_comment

begin_define
define|#
directive|define
name|CFG_DCE
value|2
end_define

begin_comment
comment|/* HSSIc, SSI: drv TXCLK; drv DCD  */
end_comment

begin_define
define|#
directive|define
name|CFG_GAIN_SHORT
value|0x24
end_define

begin_comment
comment|/* 0-20 dB of equalized gain       */
end_comment

begin_define
define|#
directive|define
name|CFG_GAIN_MEDIUM
value|0x2C
end_define

begin_comment
comment|/* 0-30 dB of equalized gain       */
end_comment

begin_define
define|#
directive|define
name|CFG_GAIN_LONG
value|0x34
end_define

begin_comment
comment|/* 0-40 dB of equalized gain       */
end_comment

begin_define
define|#
directive|define
name|CFG_GAIN_EXTEND
value|0x3F
end_define

begin_comment
comment|/* 0-64 dB of equalized gain       */
end_comment

begin_define
define|#
directive|define
name|CFG_GAIN_AUTO
value|0xFF
end_define

begin_comment
comment|/* auto-set based on cable length  */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_T1DSX0
value|0
end_define

begin_comment
comment|/* T1 DSX   0- 40 meters           */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_T1DSX1
value|2
end_define

begin_comment
comment|/* T1 DSX  40- 80 meters           */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_T1DSX2
value|4
end_define

begin_comment
comment|/* T1 DSX  80-120 meters           */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_T1DSX3
value|6
end_define

begin_comment
comment|/* T1 DSX 120-160 meters           */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_T1DSX4
value|8
end_define

begin_comment
comment|/* T1 DSX 160-200 meters           */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_E1COAX
value|10
end_define

begin_comment
comment|/* E1  75 ohm coax pair            */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_E1TWIST
value|12
end_define

begin_comment
comment|/* E1 120 ohm twisted pairs        */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_T1CSU
value|14
end_define

begin_comment
comment|/* T1 CSU 200-2000 meters; set LBO */
end_comment

begin_define
define|#
directive|define
name|CFG_PULSE_AUTO
value|0xFF
end_define

begin_comment
comment|/* auto-set based on cable length  */
end_comment

begin_define
define|#
directive|define
name|CFG_LBO_0DB
value|0
end_define

begin_comment
comment|/* T1CSU LBO =  0.0 dB; FCC opt A  */
end_comment

begin_define
define|#
directive|define
name|CFG_LBO_7DB
value|16
end_define

begin_comment
comment|/* T1CSU LBO =  7.5 dB; FCC opt B  */
end_comment

begin_define
define|#
directive|define
name|CFG_LBO_15DB
value|32
end_define

begin_comment
comment|/* T1CSU LBO = 15.0 dB; FCC opt C  */
end_comment

begin_define
define|#
directive|define
name|CFG_LBO_22DB
value|48
end_define

begin_comment
comment|/* T1CSU LBO = 22.5 dB; final span */
end_comment

begin_define
define|#
directive|define
name|CFG_LBO_AUTO
value|0xFF
end_define

begin_comment
comment|/* auto-set based on cable length  */
end_comment

begin_struct
struct|struct
name|ioctl
block|{
name|struct
name|iohdr
name|iohdr
decl_stmt|;
comment|/* common ioctl header             */
name|u_int32_t
name|cmd
decl_stmt|;
comment|/* command			   */
name|u_int32_t
name|address
decl_stmt|;
comment|/* command address                 */
name|u_int32_t
name|data
decl_stmt|;
comment|/* command data                    */
name|char
modifier|*
name|ucode
decl_stmt|;
comment|/* user-land address of ucode      */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCTL_RW_PCI
value|1
end_define

begin_comment
comment|/* RW: Tulip PCI config registers  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_RW_CSR
value|2
end_define

begin_comment
comment|/* RW: Tulip Control& Status Regs */
end_comment

begin_define
define|#
directive|define
name|IOCTL_RW_SROM
value|3
end_define

begin_comment
comment|/* RW: Tulip Serial Rom            */
end_comment

begin_define
define|#
directive|define
name|IOCTL_RW_BIOS
value|4
end_define

begin_comment
comment|/* RW: Tulip Boot rom              */
end_comment

begin_define
define|#
directive|define
name|IOCTL_RW_MII
value|5
end_define

begin_comment
comment|/* RW: MII registers               */
end_comment

begin_define
define|#
directive|define
name|IOCTL_RW_FRAME
value|6
end_define

begin_comment
comment|/* RW: Framer registers            */
end_comment

begin_define
define|#
directive|define
name|IOCTL_WO_SYNTH
value|7
end_define

begin_comment
comment|/* WO: Synthesized oscillator      */
end_comment

begin_define
define|#
directive|define
name|IOCTL_WO_DAC
value|8
end_define

begin_comment
comment|/* WO: Digital/Analog Converter    */
end_comment

begin_define
define|#
directive|define
name|IOCTL_XILINX_RESET
value|16
end_define

begin_comment
comment|/* reset Xilinx: all FFs set to 0  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_XILINX_ROM
value|17
end_define

begin_comment
comment|/* load  Xilinx program from ROM   */
end_comment

begin_define
define|#
directive|define
name|IOCTL_XILINX_FILE
value|18
end_define

begin_comment
comment|/* load  Xilinx program from file  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_SET_STATUS
value|50
end_define

begin_comment
comment|/* set mdm ctrl bits (internal use)*/
end_comment

begin_define
define|#
directive|define
name|IOCTL_SNMP_SEND
value|51
end_define

begin_comment
comment|/* trunk MIB send code             */
end_comment

begin_define
define|#
directive|define
name|IOCTL_SNMP_LOOP
value|52
end_define

begin_comment
comment|/* trunk MIB loop configuration    */
end_comment

begin_define
define|#
directive|define
name|IOCTL_SNMP_SIGS
value|53
end_define

begin_comment
comment|/* RS232-like modem control sigs   */
end_comment

begin_define
define|#
directive|define
name|IOCTL_RESET_CNTRS
value|54
end_define

begin_comment
comment|/* reset event counters            */
end_comment

begin_comment
comment|/* storage for these strings is allocated here! */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|ssi_cables
index|[]
init|=
block|{
literal|"V.10/EIA423"
block|,
literal|"V.11/EIA530A"
block|,
literal|"RESERVED"
block|,
literal|"X.21"
block|,
literal|"V.35"
block|,
literal|"V.36/EIA449"
block|,
literal|"V.28/EIA232"
block|,
literal|"NO CABLE"
block|,
name|NULL
block|,   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/*    Declarations above here are shared with the user lmcconfig program.  */
end_comment

begin_comment
comment|/*    Declarations below here are private to the kernel device driver.     */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_if
if|#
directive|if
operator|(
name|_KERNEL
operator|||
name|KERNEL
operator|||
name|__KERNEL__
operator|)
end_if

begin_define
define|#
directive|define
name|SNDQ_MAXLEN
value|32
end_define

begin_comment
comment|/* packets awaiting transmission */
end_comment

begin_define
define|#
directive|define
name|DESCS_PER_PKT
value|4
end_define

begin_comment
comment|/* DMA descriptors per TX pkt */
end_comment

begin_define
define|#
directive|define
name|NUM_TX_DESCS
value|(DESCS_PER_PKT * SNDQ_MAXLEN)
end_define

begin_comment
comment|/* Increase DESCS_PER_PKT if status.cntrs.txdma increments. */
end_comment

begin_comment
comment|/* A Tulip DMA descriptor can point to two chunks of memory.  * Each chunk has a max length of 2047 bytes (ask the VMS guys...).  * 2047 isn't a multiple of a cache line size (32 bytes typically).  * So back off to 2048-32 = 2016 bytes per chunk (2 chunks per descr).  */
end_comment

begin_define
define|#
directive|define
name|MAX_CHUNK_LEN
value|2016
end_define

begin_define
define|#
directive|define
name|MAX_DESC_LEN
value|(2 * MAX_CHUNK_LEN)
end_define

begin_comment
comment|/* Tulip DMA descriptor; THIS STRUCT MUST MATCH THE HARDWARE */
end_comment

begin_struct
struct|struct
name|dma_desc
block|{
name|u_int32_t
name|status
decl_stmt|;
comment|/* hardware->to->software */
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
comment|/* left-to-right packing by compiler */
name|unsigned
name|length1
range|:
literal|11
decl_stmt|;
comment|/* buffer1 length */
name|unsigned
name|length2
range|:
literal|11
decl_stmt|;
comment|/* buffer2 length */
name|unsigned
name|control
range|:
literal|10
decl_stmt|;
comment|/* software->to->hardware */
else|#
directive|else
comment|/* right-to-left packing by compiler */
name|unsigned
name|control
range|:
literal|10
decl_stmt|;
comment|/* software->to->hardware */
name|unsigned
name|length2
range|:
literal|11
decl_stmt|;
comment|/* buffer2 length */
name|unsigned
name|length1
range|:
literal|11
decl_stmt|;
comment|/* buffer1 length */
endif|#
directive|endif
name|u_int32_t
name|address1
decl_stmt|;
comment|/* buffer1 bus address */
name|u_int32_t
name|address2
decl_stmt|;
comment|/* buffer2 bus address */
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|)
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* bus dmamap for this descriptor */
define|#
directive|define
name|TLP_BUS_DSL_VAL
value|(sizeof(bus_dmamap_t)& TLP_BUS_DSL)
else|#
directive|else
define|#
directive|define
name|TLP_BUS_DSL_VAL
value|0
endif|#
directive|endif
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Tulip DMA descriptor status bits */
end_comment

begin_define
define|#
directive|define
name|TLP_DSTS_OWNER
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TLP_DSTS_RX_DESC_ERR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TLP_DSTS_RX_FIRST_DESC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TLP_DSTS_RX_LAST_DESC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TLP_DSTS_RX_MII_ERR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TLP_DSTS_RX_DRIBBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TLP_DSTS_TX_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TLP_DSTS_RX_OVERRUN
value|0x00000001
end_define

begin_comment
comment|/* not documented in rev AF */
end_comment

begin_define
define|#
directive|define
name|TLP_DSTS_RX_BAD
value|(TLP_DSTS_RX_MII_ERR  | \ 				 TLP_DSTS_RX_DRIBBLE  | \ 				 TLP_DSTS_RX_DESC_ERR | \ 				 TLP_DSTS_RX_OVERRUN)
end_define

begin_comment
comment|/* Tulip DMA descriptor control bits */
end_comment

begin_define
define|#
directive|define
name|TLP_DCTL_TX_INTERRUPT
value|0x0200
end_define

begin_define
define|#
directive|define
name|TLP_DCTL_TX_LAST_SEG
value|0x0100
end_define

begin_define
define|#
directive|define
name|TLP_DCTL_TX_FIRST_SEG
value|0x0080
end_define

begin_define
define|#
directive|define
name|TLP_DCTL_TX_NO_CRC
value|0x0010
end_define

begin_define
define|#
directive|define
name|TLP_DCTL_END_RING
value|0x0008
end_define

begin_define
define|#
directive|define
name|TLP_DCTL_TX_NO_PAD
value|0x0002
end_define

begin_comment
comment|/* DMA descriptors are kept in a ring.  * Ring is empty when (read == write).  * Ring is full  when (read == wrap(write+1)),  * The ring also contains a tailq of data buffers.  */
end_comment

begin_struct
struct|struct
name|desc_ring
block|{
name|struct
name|dma_desc
modifier|*
name|read
decl_stmt|;
comment|/* next  descriptor to be read */
name|struct
name|dma_desc
modifier|*
name|write
decl_stmt|;
comment|/* next  descriptor to be written */
name|struct
name|dma_desc
modifier|*
name|first
decl_stmt|;
comment|/* first descriptor in ring */
name|struct
name|dma_desc
modifier|*
name|last
decl_stmt|;
comment|/* last  descriptor in ring */
name|struct
name|dma_desc
modifier|*
name|temp
decl_stmt|;
comment|/* temporary write pointer for tx */
name|u_int32_t
name|dma_addr
decl_stmt|;
comment|/* bus address for desc array */
name|int
name|size_descs
decl_stmt|;
comment|/* bus_dmamap_sync needs this */
name|int
name|num_descs
decl_stmt|;
comment|/* used to set rx quota */
ifdef|#
directive|ifdef
name|__linux__
name|struct
name|sk_buff
modifier|*
name|head
decl_stmt|;
comment|/* tail-queue of skbuffs */
name|struct
name|sk_buff
modifier|*
name|tail
decl_stmt|;
elif|#
directive|elif
name|BSD
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|;
comment|/* tail-queue of mbufs */
name|struct
name|mbuf
modifier|*
name|tail
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|)
name|bus_dma_tag_t
name|tag
decl_stmt|;
comment|/* bus_dma tag for desc array */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* bus_dma map for desc array */
name|bus_dma_segment_t
name|segs
index|[
literal|2
index|]
decl_stmt|;
comment|/* bus_dmamap_load() or bus_dmamem_alloc() */
name|int
name|nsegs
decl_stmt|;
comment|/* bus_dmamap_load() or bus_dmamem_alloc() */
endif|#
directive|endif
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* break circular definition */
end_comment

begin_typedef
typedef|typedef
name|struct
name|softc
name|softc_t
typedef|;
end_typedef

begin_comment
comment|/* card-dependent methods */
end_comment

begin_struct
struct|struct
name|card
block|{
name|void
function_decl|(
modifier|*
name|config
function_decl|)
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ident
function_decl|)
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|watchdog
function_decl|)
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
comment|/* must not sleep */
name|int
function_decl|(
modifier|*
name|ioctl
function_decl|)
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|ioctl
modifier|*
parameter_list|)
function_decl|;
comment|/* can sleep */
block|}
struct|;
end_struct

begin_comment
comment|/* flag bits in sc->flags */
end_comment

begin_define
define|#
directive|define
name|FLAG_IFNET
value|0x00000002
end_define

begin_comment
comment|/* IFNET is attached           */
end_comment

begin_define
define|#
directive|define
name|FLAG_NETDEV
value|0x00000004
end_define

begin_comment
comment|/* NETDEV is registered        */
end_comment

begin_define
define|#
directive|define
name|FLAG_NETGRAPH
value|0x00000008
end_define

begin_comment
comment|/* NETGRAPH is attached        */
end_comment

begin_comment
comment|/* Accessing Tulip CSRs:  * There are two ways: IO instruction (default) and memory reference.  *  IO refs are used if IOREF_CSR is defined; otherwise memory refs are used.  *  MEMORY REFERENCES DO NOT WORK in BSD/OS: page faults happen.  */
end_comment

begin_define
define|#
directive|define
name|IOREF_CSR
value|1
end_define

begin_comment
comment|/* access Tulip CSRs with IO cycles if 1 */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEVICE_POLLING
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|DEV_POLL
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEV_POLL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ALTQ
argument_list|)
operator|&&
name|ALTQ
end_if

begin_define
define|#
directive|define
name|ALTQ_PRESENT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALTQ_PRESENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the instance data, or "software context" for the device driver. */
end_comment

begin_comment
comment|/* NetBSD, OpenBSD and BSD/OS want struct device first in the softc. */
end_comment

begin_comment
comment|/* FreeBSD wants struct ifnet first in the softc. */
end_comment

begin_struct
struct|struct
name|softc
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|)
name|struct
name|device
name|dev
decl_stmt|;
comment|/* base device -- must be first in softc   */
name|pcitag_t
name|pa_tag
decl_stmt|;
comment|/* pci_conf_read/write need this           */
name|pci_chipset_tag_t
name|pa_pc
decl_stmt|;
comment|/* pci_conf_read/write need this           */
name|bus_dma_tag_t
name|pa_dmat
decl_stmt|;
comment|/* bus_dma needs this                      */
name|bus_space_tag_t
name|csr_tag
decl_stmt|;
comment|/* bus_space needs this                    */
name|bus_space_handle_t
name|csr_handle
decl_stmt|;
comment|/* bus_space needs this                    */
name|pci_intr_handle_t
name|intr_handle
decl_stmt|;
comment|/* interrupt handle                        */
name|void
modifier|*
name|irq_cookie
decl_stmt|;
comment|/* pci_intr_disestablish needs this        */
name|void
modifier|*
name|sdh_cookie
decl_stmt|;
comment|/* shutdownhook_disestablish needs this    */
name|struct
name|simplelock
name|top_lock
decl_stmt|;
comment|/* lock card->watchdog vs core_ioctl       */
name|struct
name|simplelock
name|bottom_lock
decl_stmt|;
comment|/* lock for buf queues& descriptor rings  */
name|struct
name|mbuf
modifier|*
name|tx_mbuf
decl_stmt|;
comment|/* hang mbuf here while building dma descs */
endif|#
directive|endif
comment|/* __NetBSD__ || __OpenBSD__ */
ifdef|#
directive|ifdef
name|__bsdi__
name|struct
name|device
name|dev
decl_stmt|;
comment|/* base device -- must be first in softc   */
name|struct
name|isadev
name|id
decl_stmt|;
comment|/* bus resource                            */
name|struct
name|intrhand
name|ih
decl_stmt|;
comment|/* interrupt vectoring                     */
name|struct
name|atshutdown
name|ats
decl_stmt|;
comment|/* shutdown hook                           */
name|pci_devaddr_t
name|cfgbase
decl_stmt|;
comment|/* base address of PCI config regs         */
name|u_int16_t
name|csr_iobase
decl_stmt|;
comment|/*     io base address of Tulip CSRs       */
name|u_int32_t
modifier|*
name|csr_membase
decl_stmt|;
comment|/* kv mem base address of Tulip CSRs       */
name|struct
name|simplelock
name|top_lock
decl_stmt|;
comment|/* lock card->watchdog vs core_ioctl       */
name|struct
name|simplelock
name|bottom_lock
decl_stmt|;
comment|/* lock for buf queues& descriptor rings  */
name|struct
name|mbuf
modifier|*
name|tx_mbuf
decl_stmt|;
comment|/* hang mbuf here while building dma descs */
endif|#
directive|endif
comment|/* __bsdi__ */
comment|/* State for kernel-resident Line Protocols */
if|#
directive|if
name|IFNET
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|ifm
decl_stmt|;
comment|/* hooks for ifconfig(8) */
if|#
directive|if
name|NSPPP
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<
literal|600000
operator|)
name|struct
name|sppp
name|spppcom
decl_stmt|;
comment|/* must be first in sc for fbsd< 6 */
endif|#
directive|endif
name|struct
name|sppp
modifier|*
name|sppp
decl_stmt|;
elif|#
directive|elif
name|P2P
name|struct
name|p2pcom
name|p2pcom
decl_stmt|;
name|struct
name|p2pcom
modifier|*
name|p2p
decl_stmt|;
elif|#
directive|elif
operator|(
name|__FreeBSD_version
operator|<
literal|600000
operator|)
name|struct
name|ifnet
name|ifnet
decl_stmt|;
comment|/* must be first in sc for fbsd< 6 */
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__linux__
if|#
directive|if
name|GEN_HDLC
name|hdlc_device
modifier|*
name|hdlc_dev
decl_stmt|;
comment|/* state for HDLC code                     */
name|sync_serial_settings
name|hdlc_settings
decl_stmt|;
comment|/* state set by sethdlc program      */
else|#
directive|else
name|struct
name|net_device_stats
name|net_stats
decl_stmt|;
comment|/* linux_stats storage                */
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|NETGRAPH
name|node_p
name|ng_node
decl_stmt|;
comment|/* pointer to our node struct              */
name|hook_p
name|ng_hook
decl_stmt|;
comment|/* non-zero means NETGRAPH owns device     */
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|503000
operator|)
name|struct
name|ifaltq
name|ng_sndq
decl_stmt|;
name|struct
name|ifaltq
name|ng_fastq
decl_stmt|;
else|#
directive|else
name|struct
name|ifqueue
name|ng_sndq
decl_stmt|;
name|struct
name|ifqueue
name|ng_fastq
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|callout
name|callout
decl_stmt|;
comment|/* watchdog needs this                  */
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
comment|/* base device pointer                     */
name|bus_space_tag_t
name|csr_tag
decl_stmt|;
comment|/* bus_space needs this                    */
name|bus_space_handle_t
name|csr_handle
decl_stmt|;
comment|/* bus_space_needs this                    */
name|void
modifier|*
name|irq_cookie
decl_stmt|;
comment|/* bus_teardown_intr needs this            */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* bus_release_resource needs this         */
name|int
name|irq_res_id
decl_stmt|;
comment|/* bus_release_resource needs this         */
name|struct
name|resource
modifier|*
name|csr_res
decl_stmt|;
comment|/* bus_release_resource needs this         */
name|int
name|csr_res_id
decl_stmt|;
comment|/* bus_release resource needs this         */
name|int
name|csr_res_type
decl_stmt|;
comment|/* bus_release resource needs this         */
name|struct
name|mbuf
modifier|*
name|tx_mbuf
decl_stmt|;
comment|/* hang mbuf here while building dma descs */
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|quota
decl_stmt|;
comment|/* used for incoming packet flow control   */
endif|#
directive|endif
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
name|struct
name|mtx
name|top_mtx
decl_stmt|;
comment|/* lock card->watchdog vs core_ioctl       */
name|struct
name|mtx
name|bottom_mtx
decl_stmt|;
comment|/* lock for buf queues& descriptor rings  */
else|#
directive|else
comment|/* FreeBSD-4 */
name|int
name|top_spl
decl_stmt|;
comment|/* lock card->watchdog vs core_ioctl       */
name|int
name|bottom_spl
decl_stmt|;
comment|/* lock for buf queues& descriptor rings  */
endif|#
directive|endif
endif|#
directive|endif
comment|/* __FreeBSD__ */
ifdef|#
directive|ifdef
name|__linux__
name|struct
name|pci_dev
modifier|*
name|pci_dev
decl_stmt|;
comment|/* READ/WRITE_PCI_CFG macros need this     */
name|struct
name|net_device
modifier|*
name|net_dev
decl_stmt|;
comment|/* NAME_UNIT macro needs this              */
name|struct
name|timer_list
name|wd_timer
decl_stmt|;
comment|/* timer calls watchdog() once a second    */
name|u_int32_t
name|csr_iobase
decl_stmt|;
comment|/*     io base address of Tulip CSRs       */
name|void
modifier|*
name|csr_membase
decl_stmt|;
comment|/* kv mem base address of Tulip CSRs       */
name|struct
name|sk_buff
modifier|*
name|tx_skb
decl_stmt|;
comment|/* hang skb here while building dma descs  */
name|int
name|quota
decl_stmt|;
comment|/* used for incoming packet flow control   */
name|struct
name|semaphore
name|top_lock
decl_stmt|;
comment|/* lock card->watchdog vs core_ioctl       */
name|spinlock_t
name|bottom_lock
decl_stmt|;
comment|/* lock for buf queues& descriptor rings  */
endif|#
directive|endif
comment|/* __linux__ */
comment|/* Top-half state used by all card types; lock with top_lock,            */
specifier|const
name|char
modifier|*
name|dev_desc
decl_stmt|;
comment|/* string describing type of board         */
name|struct
name|status
name|status
decl_stmt|;
comment|/* driver status lmcconfig can read        */
name|struct
name|config
name|config
decl_stmt|;
comment|/* driver config lmcconfig can read/write  */
name|struct
name|card
modifier|*
name|card
decl_stmt|;
comment|/* card methods: config, ioctl, watchdog   */
name|u_int32_t
name|gpio_dir
decl_stmt|;
comment|/* s/w copy of GPIO direction register     */
name|u_int16_t
name|led_state
decl_stmt|;
comment|/* last value written to mii16             */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* driver-global flags                     */
comment|/* Top-half state used by card-specific watchdogs; lock with top_lock.   */
name|u_int32_t
name|last_mii16
decl_stmt|;
comment|/* SSI, HSSI: MII reg 16 one second ago    */
name|u_int32_t
name|last_stat16
decl_stmt|;
comment|/* T3:     framer reg 16 one second ago    */
name|u_int32_t
name|last_alm1
decl_stmt|;
comment|/* T1E1:   framer reg 47 one second ago    */
name|u_int32_t
name|last_FEAC
decl_stmt|;
comment|/* last FEAC msg code received             */
name|u_int32_t
name|loop_timer
decl_stmt|;
comment|/* seconds until loopback expires          */
comment|/* Bottom-half state used by the interrupt code; lock with bottom_lock.  */
name|struct
name|desc_ring
name|txring
decl_stmt|;
comment|/* tx descriptor ring state                */
name|struct
name|desc_ring
name|rxring
decl_stmt|;
comment|/* rx descriptor ring state                */
block|}
struct|;
end_struct

begin_comment
comment|/* end of softc */
end_comment

begin_comment
comment|/* Hide the minor differences between OS versions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_typedef
typedef|typedef
name|void
name|intr_return_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|READ_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|)
value|pci_read_config ((sc)->dev, addr, 4)
end_define

begin_define
define|#
directive|define
name|WRITE_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|data
parameter_list|)
value|pci_write_config((sc)->dev, addr, data, 4)
end_define

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|csr
parameter_list|)
value|bus_space_read_4 (sc->csr_tag, sc->csr_handle, csr)
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->csr_tag, sc->csr_handle, csr, val)
end_define

begin_define
define|#
directive|define
name|NAME_UNIT
value|device_get_nameunit(sc->dev)
end_define

begin_define
define|#
directive|define
name|DRIVER_DEBUG
value|((sc->config.debug) || (sc->ifp->if_flags& IFF_DEBUG))
end_define

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_define
define|#
directive|define
name|TOP_TRYLOCK
value|mtx_trylock(&sc->top_mtx)
end_define

begin_define
define|#
directive|define
name|TOP_UNLOCK
value|mtx_unlock (&sc->top_mtx)
end_define

begin_define
define|#
directive|define
name|BOTTOM_TRYLOCK
value|mtx_trylock(&sc->bottom_mtx)
end_define

begin_define
define|#
directive|define
name|BOTTOM_UNLOCK
value|mtx_unlock (&sc->bottom_mtx)
end_define

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|700000
operator|)
end_if

begin_define
define|#
directive|define
name|CHECK_CAP
value|priv_check(curthread, PRIV_DRIVER)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_CAP
value|suser(curthread)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD-4 */
end_comment

begin_define
define|#
directive|define
name|TOP_TRYLOCK
value|(sc->top_spl = splimp())
end_define

begin_define
define|#
directive|define
name|TOP_UNLOCK
value|splx(sc->top_spl)
end_define

begin_define
define|#
directive|define
name|BOTTOM_TRYLOCK
value|1
end_define

begin_comment
comment|/* giant_lock protects */
end_comment

begin_define
define|#
directive|define
name|BOTTOM_UNLOCK
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|CHECK_CAP
value|suser(curproc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DISABLE_INTR
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|ENABLE_INTR
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|IRQ_NONE
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|IRQ_HANDLED
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|IFP2SC
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_softc
end_define

begin_define
define|#
directive|define
name|COPY_BREAK
value|MHLEN
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|usecs
parameter_list|)
value|tsleep(sc, PCATCH | PZERO, DEVICE_NAME, 1+(usecs/tick))
end_define

begin_define
define|#
directive|define
name|DMA_SYNC
parameter_list|(
name|map
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|)
value|bus_dmamap_sync(ring->tag, map, flags)
end_define

begin_define
define|#
directive|define
name|DMA_LOAD
parameter_list|(
name|map
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
value|bus_dmamap_load(ring->tag, map, addr, size, fbsd_dmamap_load, ring, 0)
end_define

begin_if
if|#
directive|if
operator|(
name|NBPFILTER
operator|!=
literal|0
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_define
define|#
directive|define
name|LMC_BPF_MTAP
parameter_list|(
name|mbuf
parameter_list|)
value|BPF_MTAP(sc->ifp, mbuf)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD-4 */
end_comment

begin_define
define|#
directive|define
name|LMC_BPF_MTAP
parameter_list|(
name|mbuf
parameter_list|)
value|if (sc->ifp->if_bpf) bpf_mtap(sc->ifp, mbuf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LMC_BPF_ATTACH
parameter_list|(
name|dlt
parameter_list|,
name|len
parameter_list|)
value|bpfattach(sc->ifp, dlt, len)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_DETACH
value|bpfdetach(sc->ifp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_define
define|#
directive|define
name|IF_DROP
parameter_list|(
name|ifq
parameter_list|)
value|_IF_DROP(ifq)
end_define

begin_define
define|#
directive|define
name|IF_QFULL
parameter_list|(
name|ifq
parameter_list|)
value|_IF_QFULL(ifq)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<
literal|500000
operator|)
end_if

begin_define
define|#
directive|define
name|INTR_MPSAFE
value|0
end_define

begin_define
define|#
directive|define
name|BUS_DMA_COHERENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|600000
operator|)
end_if

begin_define
define|#
directive|define
name|IFF_RUNNING
value|IFF_DRV_RUNNING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_typedef
typedef|typedef
name|int
name|intr_return_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|READ_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|)
value|pci_conf_read ((sc)->pa_pc, (sc)->pa_tag, addr)
end_define

begin_define
define|#
directive|define
name|WRITE_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|data
parameter_list|)
value|pci_conf_write((sc)->pa_pc, (sc)->pa_tag, addr, data)
end_define

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|csr
parameter_list|)
value|bus_space_read_4 (sc->csr_tag, sc->csr_handle, csr)
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->csr_tag, sc->csr_handle, csr, val)
end_define

begin_define
define|#
directive|define
name|NAME_UNIT
value|sc->dev.dv_xname
end_define

begin_define
define|#
directive|define
name|DRIVER_DEBUG
value|((sc->config.debug) || (sc->ifp->if_flags& IFF_DEBUG))
end_define

begin_define
define|#
directive|define
name|TOP_TRYLOCK
value|simple_lock_try(&sc->top_lock)
end_define

begin_define
define|#
directive|define
name|TOP_UNLOCK
value|simple_unlock  (&sc->top_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_TRYLOCK
value|simple_lock_try(&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_UNLOCK
value|simple_unlock  (&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|CHECK_CAP
value|suser(curproc->p_ucred,&curproc->p_acflag)
end_define

begin_define
define|#
directive|define
name|DISABLE_INTR
value|int spl = splnet()
end_define

begin_define
define|#
directive|define
name|ENABLE_INTR
value|splx(spl)
end_define

begin_define
define|#
directive|define
name|IRQ_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IRQ_HANDLED
value|1
end_define

begin_define
define|#
directive|define
name|IFP2SC
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_softc
end_define

begin_define
define|#
directive|define
name|COPY_BREAK
value|MHLEN
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|usecs
parameter_list|)
value|tsleep(sc, PCATCH | PZERO, DEVICE_NAME, 1+(usecs/tick))
end_define

begin_define
define|#
directive|define
name|DMA_SYNC
parameter_list|(
name|map
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|)
value|bus_dmamap_sync(ring->tag, map, 0, size, flags)
end_define

begin_define
define|#
directive|define
name|DMA_LOAD
parameter_list|(
name|map
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
value|bus_dmamap_load(ring->tag, map, addr, size, 0, BUS_DMA_NOWAIT)
end_define

begin_if
if|#
directive|if
operator|(
name|NBPFILTER
operator|!=
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|LMC_BPF_MTAP
parameter_list|(
name|mbuf
parameter_list|)
value|if (sc->ifp->if_bpf) bpf_mtap(sc->ifp->if_bpf, mbuf)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_ATTACH
parameter_list|(
name|dlt
parameter_list|,
name|len
parameter_list|)
value|bpfattach(sc->ifp, dlt, len)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_DETACH
value|bpfdetach(sc->ifp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_typedef
typedef|typedef
name|int
name|intr_return_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|READ_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|)
value|pci_conf_read ((sc)->pa_pc, (sc)->pa_tag, addr)
end_define

begin_define
define|#
directive|define
name|WRITE_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|data
parameter_list|)
value|pci_conf_write((sc)->pa_pc, (sc)->pa_tag, addr, data)
end_define

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|csr
parameter_list|)
value|bus_space_read_4 (sc->csr_tag, sc->csr_handle, csr)
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->csr_tag, sc->csr_handle, csr, val)
end_define

begin_define
define|#
directive|define
name|NAME_UNIT
value|sc->dev.dv_xname
end_define

begin_define
define|#
directive|define
name|DRIVER_DEBUG
value|((sc->config.debug) || (sc->ifp->if_flags& IFF_DEBUG))
end_define

begin_define
define|#
directive|define
name|TOP_TRYLOCK
value|simple_lock_try(&sc->top_lock)
end_define

begin_define
define|#
directive|define
name|TOP_UNLOCK
value|simple_unlock  (&sc->top_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_TRYLOCK
value|simple_lock_try(&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_UNLOCK
value|simple_unlock  (&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|CHECK_CAP
value|suser(curproc, 0)
end_define

begin_define
define|#
directive|define
name|DISABLE_INTR
value|int spl = splnet()
end_define

begin_define
define|#
directive|define
name|ENABLE_INTR
value|splx(spl)
end_define

begin_define
define|#
directive|define
name|IRQ_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IRQ_HANDLED
value|1
end_define

begin_define
define|#
directive|define
name|IFP2SC
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_softc
end_define

begin_define
define|#
directive|define
name|COPY_BREAK
value|MHLEN
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|usecs
parameter_list|)
value|tsleep(sc, PCATCH | PZERO, DEVICE_NAME, 1+(usecs/tick))
end_define

begin_define
define|#
directive|define
name|DMA_SYNC
parameter_list|(
name|map
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|)
value|bus_dmamap_sync(ring->tag, map, 0, size, flags)
end_define

begin_define
define|#
directive|define
name|DMA_LOAD
parameter_list|(
name|map
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
value|bus_dmamap_load(ring->tag, map, addr, size, 0, BUS_DMA_NOWAIT)
end_define

begin_if
if|#
directive|if
operator|(
name|NBPFILTER
operator|!=
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|LMC_BPF_MTAP
parameter_list|(
name|mbuf
parameter_list|)
value|if (sc->ifp->if_bpf) bpf_mtap(sc->ifp->if_bpf, mbuf)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_ATTACH
parameter_list|(
name|dlt
parameter_list|,
name|len
parameter_list|)
value|bpfattach(&sc->ifp->if_bpf, sc->ifp, dlt, len)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_DETACH
value|bpfdetach(sc->ifp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_typedef
typedef|typedef
name|int
name|intr_return_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|READ_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|)
value|pci_inl(&(sc)->cfgbase, addr)
end_define

begin_define
define|#
directive|define
name|WRITE_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|data
parameter_list|)
value|pci_outl(&(sc)->cfgbase, addr, data)
end_define

begin_if
if|#
directive|if
name|IOREF_CSR
end_if

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|csr
parameter_list|)
value|inl(sc->csr_iobase+(csr))
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
value|outl(sc->csr_iobase+(csr), (val))
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Memory refs to Tulip CSRs cause page faults in BSD/OS
end_error

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|csr
parameter_list|)
value|(0 + *(sc->csr_membase+(csr)))
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
value|((void)(*(sc->csr_membase+(csr)) = (val)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NAME_UNIT
value|sc->dev.dv_xname
end_define

begin_define
define|#
directive|define
name|DRIVER_DEBUG
value|((sc->config.debug) || (sc->ifp->if_flags& IFF_DEBUG))
end_define

begin_define
define|#
directive|define
name|TOP_TRYLOCK
value|simple_lock_try(&sc->top_lock)
end_define

begin_define
define|#
directive|define
name|TOP_UNLOCK
value|simple_unlock  (&sc->top_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_TRYLOCK
value|simple_lock_try(&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_UNLOCK
value|simple_unlock  (&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|CHECK_CAP
value|suser(PCPU(curproc)->p_ucred,&PCPU(curproc)->p_acflag)
end_define

begin_define
define|#
directive|define
name|DISABLE_INTR
value|int spl = splimp()
end_define

begin_define
define|#
directive|define
name|ENABLE_INTR
value|splx(spl)
end_define

begin_define
define|#
directive|define
name|IRQ_NONE
value|1
end_define

begin_comment
comment|/* XXX 0 */
end_comment

begin_define
define|#
directive|define
name|IRQ_HANDLED
value|1
end_define

begin_define
define|#
directive|define
name|IFP2SC
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_softc
end_define

begin_define
define|#
directive|define
name|COPY_BREAK
value|MHLEN
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|usecs
parameter_list|)
value|tsleep(sc, PCATCH | PZERO, DEVICE_NAME, 1+(usecs/tick))
end_define

begin_define
define|#
directive|define
name|DMA_SYNC
parameter_list|(
name|map
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|DMA_LOAD
parameter_list|(
name|map
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|bus_dmamap_unload
parameter_list|(
name|tag
parameter_list|,
name|map
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|bus_dmamap_destroy
parameter_list|(
name|tag
parameter_list|,
name|map
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_if
if|#
directive|if
operator|(
name|NBPFILTER
operator|!=
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|LMC_BPF_MTAP
parameter_list|(
name|mbuf
parameter_list|)
value|if (sc->ifp->if_bpf) bpf_mtap(sc->ifp->if_bpf, mbuf)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_ATTACH
parameter_list|(
name|dlt
parameter_list|,
name|len
parameter_list|)
value|bpfattach(&sc->ifp->if_bpf, sc->ifp, dlt, len)
end_define

begin_define
define|#
directive|define
name|LMC_BPF_DETACH
end_define

begin_comment
comment|/* bpfdetach(sc->ifp) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|bcopy(src, dst, len)
end_define

begin_define
define|#
directive|define
name|if_detach
parameter_list|(
name|ifp
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_comment
comment|/*  BSD/OS-4.1 doesn't have a back pointer to softc in struct ifnet, */
end_comment

begin_comment
comment|/*  and it passes a unit number not a struct ifnet* to watchdog. */
end_comment

begin_if
if|#
directive|if
operator|(
name|_BSDI_VERSION
operator|<=
literal|199910
operator|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|cfdriver
name|lmccd
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|IFP2SC
end_undef

begin_define
define|#
directive|define
name|UNIT2SC
parameter_list|(
name|unit
parameter_list|)
value|((softc_t *)lmccd.cd_devs[unit])
end_define

begin_define
define|#
directive|define
name|IFP2SC
parameter_list|(
name|ifp
parameter_list|)
value|(UNIT2SC((ifp)->if_unit))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __bsdi__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_function
specifier|static
name|u_int32_t
comment|/* inline? so rare it doesn't matter */
name|READ_PCI_CFG
parameter_list|(
name|softc_t
modifier|*
name|sc
parameter_list|,
name|u_int32_t
name|addr
parameter_list|)
block|{
name|u_int32_t
name|data
decl_stmt|;
name|pci_read_config_dword
argument_list|(
name|sc
operator|->
name|pci_dev
argument_list|,
name|addr
argument_list|,
operator|&
name|data
argument_list|)
expr_stmt|;
return|return
name|data
return|;
block|}
end_function

begin_define
define|#
directive|define
name|WRITE_PCI_CFG
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|data
parameter_list|)
value|pci_write_config_dword(sc->pci_dev, addr, data)
end_define

begin_if
if|#
directive|if
name|IOREF_CSR
end_if

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|csr
parameter_list|)
value|inl((sc->csr_iobase+(csr)))
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
value|outl((val),(sc->csr_iobase+(csr)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|csr
parameter_list|)
value|readl((sc->csr_membase+(csr)))
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
value|writel((val),(sc->csr_membase+(csr)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NAME_UNIT
value|sc->net_dev->name
end_define

begin_define
define|#
directive|define
name|DRIVER_DEBUG
value|((sc->config.debug) || (sc->net_dev->flags& IFF_DEBUG))
end_define

begin_define
define|#
directive|define
name|TOP_TRYLOCK
value|((down_trylock(&sc->top_lock)==0) ? 1:0)
end_define

begin_define
define|#
directive|define
name|TOP_UNLOCK
value|up(&sc->top_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_TRYLOCK
value|spin_trylock_bh(&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|BOTTOM_UNLOCK
value|spin_unlock_bh(&sc->bottom_lock)
end_define

begin_define
define|#
directive|define
name|CHECK_CAP
value|capable(CAP_NET_ADMIN)? 0 : -EPERM
end_define

begin_define
define|#
directive|define
name|DISABLE_INTR
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|ENABLE_INTR
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|COPY_BREAK
value|200
end_define

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|usecs
parameter_list|)
value|udelay(usecs)
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|usecs
parameter_list|)
value|do { set_current_state(TASK_INTERRUPTIBLE);\ 				schedule_timeout(1+(usecs*HZ)/1000000UL); } while (0)
end_define

begin_define
define|#
directive|define
name|printf
value|printk
end_define

begin_define
define|#
directive|define
name|copyin
parameter_list|(
name|u
parameter_list|,
name|k
parameter_list|,
name|len
parameter_list|)
value|copy_from_user(k, u, len)
end_define

begin_define
define|#
directive|define
name|microtime
parameter_list|(
name|time
parameter_list|)
value|do_gettimeofday(time)
end_define

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|len
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|)
value|kmalloc(len, GFP_KERNEL)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|addr
parameter_list|,
name|t
parameter_list|)
value|kfree(addr)
end_define

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|4321
end_define

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|1234
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"asm/byteorder.h is wrong"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GEN_HDLC
operator|==
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|dev_to_hdlc
parameter_list|(
name|net_dev
parameter_list|)
value|net_dev
end_define

begin_define
define|#
directive|define
name|hdlc_set_carrier
parameter_list|(
name|val
parameter_list|,
name|net_dev
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_if
if|#
directive|if
operator|(
name|NBPFILTER
operator|==
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|LMC_BPF_MTAP
parameter_list|(
name|mbuf
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|LMC_BPF_ATTACH
parameter_list|(
name|dlt
parameter_list|,
name|len
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|LMC_BPF_DETACH
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
comment|/* unconditionally */
expr|\
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|<
literal|503000
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|<
literal|106000000
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|&&
operator|(
name|OpenBSD
operator|<
literal|200111
operator|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|IFQ_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|pa
parameter_list|,
name|err
parameter_list|)
define|\
value|do {					\   if (pa==0);
comment|/* suppress warning */
value|\   if (IF_QFULL(ifq))			\     {					\     IF_DROP(ifq);			\     m_freem(m);				\     err = ENOBUFS;			\     }					\   else					\     {					\     IF_ENQUEUE(ifq, m);			\     err = 0;				\     }					\    } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do { IF_DEQUEUE((ifq), m) } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_IS_EMPTY
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_head == NULL)
end_define

begin_define
define|#
directive|define
name|IFQ_SET_MAXLEN
parameter_list|(
name|ifq
parameter_list|,
name|len
parameter_list|)
value|(ifq)->ifq_maxlen = len
end_define

begin_define
define|#
directive|define
name|IFQ_SET_READY
parameter_list|(
name|ifq
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|IFQ_PURGE
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do {					\   while ((ifq)->ifq_head != NULL)	\     {					\     struct mbuf *m;			\     IF_DEQUEUE(ifq, m);			\     m_freem(m);				\     }					\    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HSSI_DESC
value|"SBE/LMC HSSI Card"
end_define

begin_define
define|#
directive|define
name|T3_DESC
value|"SBE/LMC T3 Card"
end_define

begin_define
define|#
directive|define
name|SSI_DESC
value|"SBE/LMC SSI Card"
end_define

begin_define
define|#
directive|define
name|T1E1_DESC
value|"SBE/LMC T1E1 Card"
end_define

begin_comment
comment|/* procedure prototypes */
end_comment

begin_function_decl
specifier|static
name|void
name|shift_srom_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int16_t
name|read_srom
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_srom
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int8_t
name|read_bios
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_bios_phys
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_bios
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|erase_bios
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|shift_mii_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int16_t
name|read_mii
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_mii
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_mii16_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|clr_mii16_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_mii17_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|clr_mii17_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|led_off
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|led_on
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|led_inv
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_framer
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int8_t
name|read_framer
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|make_gpio_input
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|make_gpio_output
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int32_t
name|read_gpio
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_gpio_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|clr_gpio_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|reset_xilinx
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|load_xilinx_from_rom
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|load_xilinx_from_file
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|shift_synth_bits
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_synth
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|synth
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|write_dac
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|hssi_config
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|hssi_ident
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|hssi_watchdog
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|hssi_ioctl
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|ioctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|t3_config
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|t3_ident
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|t3_watchdog
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|t3_send_dbl_feac
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|t3_ioctl
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|ioctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ssi_config
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ssi_ident
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ssi_watchdog
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ssi_ioctl
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|ioctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|t1_config
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|t1_ident
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|t1_watchdog
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|t1_send_bop
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|t1_ioctl
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|ioctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|IFNET
end_if

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|<
literal|500000
operator|)
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|)
end_if

begin_function_decl
specifier|static
name|void
name|netisr_dispatch
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|lmc_raw_input
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IFNET */
end_comment

begin_if
if|#
directive|if
name|BSD
end_if

begin_function_decl
specifier|static
name|void
name|mbuf_enqueue
parameter_list|(
name|struct
name|desc_ring
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|struct
name|mbuf
modifier|*
name|mbuf_dequeue
parameter_list|(
name|struct
name|desc_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
specifier|static
name|void
name|fbsd_dmamap_load
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|create_ring
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|desc_ring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|destroy_ring
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|desc_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|rxintr_cleanup
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|rxintr_setup
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|txintr_cleanup
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|txintr_setup_mbuf
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|txintr_setup
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_function_decl
specifier|static
name|void
name|skbuff_enqueue
parameter_list|(
name|struct
name|desc_ring
modifier|*
parameter_list|,
name|struct
name|sk_buff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|struct
name|sk_buff
modifier|*
name|skbuff_dequeue
parameter_list|(
name|struct
name|desc_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|create_ring
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|desc_ring
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|destroy_ring
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|desc_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|rxintr_cleanup
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|rxintr_setup
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|txintr_cleanup
parameter_list|(
name|softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|txintr_setup_frag
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|txintr_setup_skb
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|sk_buff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|txintr_setup
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_function_decl
specifier|static
name|void
name|check_intr_status
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|core_interrupt
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|user_interrupt
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|BSD
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEVICE_POLLING
argument_list|)
operator|)
end_if

begin_function_decl
specifier|static
name|int
name|fbsd_poll
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|enum
name|poll_cmd
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|intr_return_t
name|bsd_interrupt
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_function_decl
specifier|static
name|void
name|set_status
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|P2P
end_if

begin_function_decl
specifier|static
name|int
name|p2p_getmdm
parameter_list|(
name|struct
name|p2pcom
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|p2p_mdmctl
parameter_list|(
name|struct
name|p2pcom
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NSPPP
end_if

begin_function_decl
specifier|static
name|void
name|sppp_tls
parameter_list|(
name|struct
name|sppp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sppp_tlf
parameter_list|(
name|struct
name|sppp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|config_proto
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|struct
name|config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|core_ioctl
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|core_watchdog
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|IFNET
end_if

begin_function_decl
specifier|static
name|int
name|lmc_raw_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|lmc_ifnet_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|lmc_ifnet_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|lmc_raw_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_function_decl
specifier|static
name|int
name|ifmedia_change
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ifmedia_status
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifmediareq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_function_decl
specifier|static
name|void
name|setup_ifnet
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|lmc_ifnet_attach
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|lmc_ifnet_detach
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IFNET */
end_comment

begin_if
if|#
directive|if
name|NETGRAPH
end_if

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_function_decl
specifier|static
name|int
name|ng_constructor
parameter_list|(
name|node_p
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD-4 */
end_comment

begin_function_decl
specifier|static
name|int
name|ng_constructor
parameter_list|(
name|node_p
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_function_decl
specifier|static
name|int
name|ng_rcvmsg
parameter_list|(
name|node_p
parameter_list|,
name|item_p
parameter_list|,
name|hook_p
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD-4 */
end_comment

begin_function_decl
specifier|static
name|int
name|ng_rcvmsg
parameter_list|(
name|node_p
parameter_list|,
name|struct
name|ng_mesg
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ng_mesg
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|ng_shutdown
parameter_list|(
name|node_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ng_newhook
parameter_list|(
name|node_p
parameter_list|,
name|hook_p
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ng_connect
parameter_list|(
name|hook_p
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_function_decl
specifier|static
name|int
name|ng_rcvdata
parameter_list|(
name|hook_p
parameter_list|,
name|item_p
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD-4 */
end_comment

begin_function_decl
specifier|static
name|int
name|ng_rcvdata
parameter_list|(
name|hook_p
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|meta_p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|ng_disconnect
parameter_list|(
name|hook_p
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|IFNET
operator|==
literal|0
operator|)
end_if

begin_function_decl
specifier|static
name|void
name|ng_watchdog
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|ng_attach
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ng_detach
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_function_decl
specifier|static
name|int
name|startup_card
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|shutdown_card
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|attach_card
parameter_list|(
name|softc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|detach_card
parameter_list|(
name|softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
specifier|static
name|int
name|fbsd_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|fbsd_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|fbsd_shutdown
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|fbsd_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_function_decl
specifier|static
name|int
name|nbsd_match
parameter_list|(
name|struct
name|device
modifier|*
name|t
parameter_list|,
name|struct
name|cfdata
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|nbsd_detach
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|nbsd_attach
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|struct
name|device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|lkm_nbsd_match
parameter_list|(
name|struct
name|pci_attach_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_lmc_lkmentry
parameter_list|(
name|struct
name|lkm_table
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_function_decl
specifier|static
name|int
name|obsd_match
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|obsd_detach
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|obsd_attach
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|struct
name|device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_lmc_lkmentry
parameter_list|(
name|struct
name|lkm_table
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_function_decl
specifier|static
name|int
name|bsdi_match
parameter_list|(
name|pci_devaddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|bsdi_probe
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|struct
name|cfdata
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|bsdi_attach
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|struct
name|device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __bsdi__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_function_decl
specifier|static
name|irqreturn_t
name|linux_interrupt
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pt_regs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|linux_poll
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|linux_start
parameter_list|(
name|struct
name|sk_buff
modifier|*
parameter_list|,
name|struct
name|net_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|linux_timeout
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|linux_ioctl
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|,
name|struct
name|ifreq
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|struct
name|net_device_stats
modifier|*
name|linux_stats
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|linux_watchdog
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|linux_stop
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|linux_open
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|GEN_HDLC
end_if

begin_function_decl
specifier|static
name|int
name|hdlc_attach
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|__exit
name|linux_remove
parameter_list|(
name|struct
name|pci_dev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|setup_netdev
parameter_list|(
name|struct
name|net_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|__init
name|linux_probe
parameter_list|(
name|struct
name|pci_dev
modifier|*
parameter_list|,
specifier|const
name|struct
name|pci_device_id
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_LMC_H */
end_comment

end_unit

