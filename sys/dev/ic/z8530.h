begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IC_Z8530_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IC_Z8530_H_
end_define

begin_comment
comment|/*  * Channel B control:	0  * Channel B data:	1  * Channel A control:	2  * Channel A data:	3  */
end_comment

begin_comment
comment|/* The following apply when using a device-scoped bus handle */
end_comment

begin_define
define|#
directive|define
name|CHAN_A
value|2
end_define

begin_define
define|#
directive|define
name|CHAN_B
value|0
end_define

begin_define
define|#
directive|define
name|REG_CTRL
value|0
end_define

begin_define
define|#
directive|define
name|REG_DATA
value|1
end_define

begin_comment
comment|/* Write registers. */
end_comment

begin_define
define|#
directive|define
name|WR_CR
value|0
end_define

begin_comment
comment|/* Command Register. */
end_comment

begin_define
define|#
directive|define
name|WR_IDT
value|1
end_define

begin_comment
comment|/* Interrupt and Data Transfer Mode. */
end_comment

begin_define
define|#
directive|define
name|WR_IV
value|2
end_define

begin_comment
comment|/* Interrupt Vector (shared). */
end_comment

begin_define
define|#
directive|define
name|WR_RPC
value|3
end_define

begin_comment
comment|/* Receive Parameters and Control. */
end_comment

begin_define
define|#
directive|define
name|WR_MPM
value|4
end_define

begin_comment
comment|/* Miscellaneous Parameters and Modes. */
end_comment

begin_define
define|#
directive|define
name|WR_TPC
value|5
end_define

begin_comment
comment|/* Transmit Parameters and Control. */
end_comment

begin_define
define|#
directive|define
name|WR_SCAF
value|6
end_define

begin_comment
comment|/* Sync Character or (SDLC) Address Field. */
end_comment

begin_define
define|#
directive|define
name|WR_SCF
value|7
end_define

begin_comment
comment|/* Sync Character or (SDCL) Flag. */
end_comment

begin_define
define|#
directive|define
name|WR_EFC
value|7
end_define

begin_comment
comment|/* Extended Feature and FIFO Control. */
end_comment

begin_define
define|#
directive|define
name|WR_TB
value|8
end_define

begin_comment
comment|/* Transmit Buffer. */
end_comment

begin_define
define|#
directive|define
name|WR_MIC
value|9
end_define

begin_comment
comment|/* Master Interrupt Control (shared). */
end_comment

begin_define
define|#
directive|define
name|WR_MCB1
value|10
end_define

begin_comment
comment|/* Miscellaneous Control Bits (part 1 :-). */
end_comment

begin_define
define|#
directive|define
name|WR_CMC
value|11
end_define

begin_comment
comment|/* Clock Mode Control. */
end_comment

begin_define
define|#
directive|define
name|WR_TCL
value|12
end_define

begin_comment
comment|/* BRG Time Constant Low. */
end_comment

begin_define
define|#
directive|define
name|WR_TCH
value|13
end_define

begin_comment
comment|/* BRG Time Constant High. */
end_comment

begin_define
define|#
directive|define
name|WR_MCB2
value|14
end_define

begin_comment
comment|/* Miscellaneous Control Bits (part 2 :-). */
end_comment

begin_define
define|#
directive|define
name|WR_IC
value|15
end_define

begin_comment
comment|/* Interrupt Control. */
end_comment

begin_comment
comment|/* Read registers. */
end_comment

begin_define
define|#
directive|define
name|RR_BES
value|0
end_define

begin_comment
comment|/* Buffer and External Status. */
end_comment

begin_define
define|#
directive|define
name|RR_SRC
value|1
end_define

begin_comment
comment|/* Special Receive Condition. */
end_comment

begin_define
define|#
directive|define
name|RR_IV
value|2
end_define

begin_comment
comment|/* Interrupt Vector. */
end_comment

begin_define
define|#
directive|define
name|RR_IP
value|3
end_define

begin_comment
comment|/* Interrupt Pending (ch A only). */
end_comment

begin_define
define|#
directive|define
name|RR_MPM
value|4
end_define

begin_comment
comment|/* Miscellaneous Parameters and Modes. */
end_comment

begin_define
define|#
directive|define
name|RR_TPC
value|5
end_define

begin_comment
comment|/* Transmit Parameters and Control. */
end_comment

begin_define
define|#
directive|define
name|RR_BCL
value|6
end_define

begin_comment
comment|/* Byte Count Low. */
end_comment

begin_define
define|#
directive|define
name|RR_BCH
value|7
end_define

begin_comment
comment|/* Byte Count High. */
end_comment

begin_define
define|#
directive|define
name|RR_RB
value|8
end_define

begin_comment
comment|/* Receive Buffer. */
end_comment

begin_define
define|#
directive|define
name|RR_RPC
value|9
end_define

begin_comment
comment|/* Receive Parameters and Control. */
end_comment

begin_define
define|#
directive|define
name|RR_MSB
value|10
end_define

begin_comment
comment|/* Miscellaneous Status Bits. */
end_comment

begin_define
define|#
directive|define
name|RR_MCB1
value|11
end_define

begin_comment
comment|/* Miscellaneous Control Bits (part 1). */
end_comment

begin_define
define|#
directive|define
name|RR_TCL
value|12
end_define

begin_comment
comment|/* BRG Time Constant Low. */
end_comment

begin_define
define|#
directive|define
name|RR_TCH
value|13
end_define

begin_comment
comment|/* BRG Time Constant High. */
end_comment

begin_define
define|#
directive|define
name|RR_EFC
value|14
end_define

begin_comment
comment|/* Extended Feature and FIFO Control. */
end_comment

begin_define
define|#
directive|define
name|RR_IC
value|15
end_define

begin_comment
comment|/* Interrupt Control. */
end_comment

begin_comment
comment|/* Buffer and External Status (RR0). */
end_comment

begin_define
define|#
directive|define
name|BES_BRK
value|0x80
end_define

begin_comment
comment|/* Break (Abort). */
end_comment

begin_define
define|#
directive|define
name|BES_TXU
value|0x40
end_define

begin_comment
comment|/* Tx Underrun (EOM). */
end_comment

begin_define
define|#
directive|define
name|BES_CTS
value|0x20
end_define

begin_comment
comment|/* CTS. */
end_comment

begin_define
define|#
directive|define
name|BES_SYNC
value|0x10
end_define

begin_comment
comment|/* Sync. */
end_comment

begin_define
define|#
directive|define
name|BES_DCD
value|0x08
end_define

begin_comment
comment|/* DCD. */
end_comment

begin_define
define|#
directive|define
name|BES_TXE
value|0x04
end_define

begin_comment
comment|/* Tx Empty. */
end_comment

begin_define
define|#
directive|define
name|BES_ZC
value|0x02
end_define

begin_comment
comment|/* Zero Count. */
end_comment

begin_define
define|#
directive|define
name|BES_RXA
value|0x01
end_define

begin_comment
comment|/* Rx Available. */
end_comment

begin_comment
comment|/* Clock Mode Control (WR11). */
end_comment

begin_define
define|#
directive|define
name|CMC_XTAL
value|0x80
end_define

begin_comment
comment|/* -RTxC connects to quartz crystal. */
end_comment

begin_define
define|#
directive|define
name|CMC_RC_DPLL
value|0x60
end_define

begin_comment
comment|/* Rx Clock from DPLL. */
end_comment

begin_define
define|#
directive|define
name|CMC_RC_BRG
value|0x40
end_define

begin_comment
comment|/* Rx Clock from BRG. */
end_comment

begin_define
define|#
directive|define
name|CMC_RC_TRXC
value|0x20
end_define

begin_comment
comment|/* Rx Clock from -TRxC. */
end_comment

begin_define
define|#
directive|define
name|CMC_RC_RTXC
value|0x00
end_define

begin_comment
comment|/* Rx Clock from -RTxC. */
end_comment

begin_define
define|#
directive|define
name|CMC_TC_DPLL
value|0x18
end_define

begin_comment
comment|/* Tx Clock from DPLL */
end_comment

begin_define
define|#
directive|define
name|CMC_TC_BRG
value|0x10
end_define

begin_comment
comment|/* Tx Clock from BRG */
end_comment

begin_define
define|#
directive|define
name|CMC_TC_TRXC
value|0x08
end_define

begin_comment
comment|/* Tx Clock from -TRxC. */
end_comment

begin_define
define|#
directive|define
name|CMC_TC_RTXC
value|0x00
end_define

begin_comment
comment|/* Tx Clock from -RTxC. */
end_comment

begin_define
define|#
directive|define
name|CMC_TRXC_OUT
value|0x04
end_define

begin_comment
comment|/* -TRxC is output. */
end_comment

begin_define
define|#
directive|define
name|CMC_TRXC_DPLL
value|0x03
end_define

begin_comment
comment|/* -TRxC from DPLL */
end_comment

begin_define
define|#
directive|define
name|CMC_TRXC_BRG
value|0x02
end_define

begin_comment
comment|/* -TRxC from BRG */
end_comment

begin_define
define|#
directive|define
name|CMC_TRXC_XMIT
value|0x01
end_define

begin_comment
comment|/* -TRxC from Tx clock. */
end_comment

begin_define
define|#
directive|define
name|CMC_TRXC_XTAL
value|0x00
end_define

begin_comment
comment|/* -TRxC from XTAL. */
end_comment

begin_comment
comment|/* Command Register (WR0). */
end_comment

begin_define
define|#
directive|define
name|CR_RSTTXU
value|0xc0
end_define

begin_comment
comment|/* Reset Tx. Underrun/EOM. */
end_comment

begin_define
define|#
directive|define
name|CR_RSTTXCRC
value|0x80
end_define

begin_comment
comment|/* Reset Tx. CRC. */
end_comment

begin_define
define|#
directive|define
name|CR_RSTRXCRC
value|0x40
end_define

begin_comment
comment|/* Reset Rx. CRC. */
end_comment

begin_define
define|#
directive|define
name|CR_RSTIUS
value|0x38
end_define

begin_comment
comment|/* Reset Int. Under Service. */
end_comment

begin_define
define|#
directive|define
name|CR_RSTERR
value|0x30
end_define

begin_comment
comment|/* Error Reset. */
end_comment

begin_define
define|#
directive|define
name|CR_RSTTXI
value|0x28
end_define

begin_comment
comment|/* Reset Tx. Int. */
end_comment

begin_define
define|#
directive|define
name|CR_ENARXI
value|0x20
end_define

begin_comment
comment|/* Enable Rx. Int. */
end_comment

begin_define
define|#
directive|define
name|CR_ABORT
value|0x18
end_define

begin_comment
comment|/* Send Abort. */
end_comment

begin_define
define|#
directive|define
name|CR_RSTXSI
value|0x10
end_define

begin_comment
comment|/* Reset Ext/Status Int. */
end_comment

begin_comment
comment|/* Extended Feature and FIFO Control (WR7 prime). */
end_comment

begin_define
define|#
directive|define
name|EFC_ERE
value|0x40
end_define

begin_comment
comment|/* Extended Read Enable. */
end_comment

begin_define
define|#
directive|define
name|EFC_FE
value|0x20
end_define

begin_comment
comment|/* Transmit FIFO Empty. */
end_comment

begin_define
define|#
directive|define
name|EFC_RQT
value|0x10
end_define

begin_comment
comment|/* Request Timing. */
end_comment

begin_define
define|#
directive|define
name|EFC_FHF
value|0x08
end_define

begin_comment
comment|/* Receive FIFO Half Full. */
end_comment

begin_define
define|#
directive|define
name|EFC_RTS
value|0x04
end_define

begin_comment
comment|/* Auto RTS Deactivation. */
end_comment

begin_define
define|#
directive|define
name|EFC_EOM
value|0x02
end_define

begin_comment
comment|/* Auto EOM Reset. */
end_comment

begin_define
define|#
directive|define
name|EFC_FLAG
value|0x01
end_define

begin_comment
comment|/* Auto SDLC Flag on Tx. */
end_comment

begin_comment
comment|/* Interrupt Control (WR15). */
end_comment

begin_define
define|#
directive|define
name|IC_BRK
value|0x80
end_define

begin_comment
comment|/* Break (Abort) IE. */
end_comment

begin_define
define|#
directive|define
name|IC_TXU
value|0x40
end_define

begin_comment
comment|/* Tx Underrun IE. */
end_comment

begin_define
define|#
directive|define
name|IC_CTS
value|0x20
end_define

begin_comment
comment|/* CTS IE. */
end_comment

begin_define
define|#
directive|define
name|IC_SYNC
value|0x10
end_define

begin_comment
comment|/* Sync IE. */
end_comment

begin_define
define|#
directive|define
name|IC_DCD
value|0x08
end_define

begin_comment
comment|/* DCD IE. */
end_comment

begin_define
define|#
directive|define
name|IC_FIFO
value|0x04
end_define

begin_comment
comment|/* SDLC FIFO Enable. */
end_comment

begin_define
define|#
directive|define
name|IC_ZC
value|0x02
end_define

begin_comment
comment|/* Zero Count IE. */
end_comment

begin_define
define|#
directive|define
name|IC_EF
value|0x01
end_define

begin_comment
comment|/* Extended Feature Enable. */
end_comment

begin_comment
comment|/* Interrupt and Data Transfer Mode (WR1). */
end_comment

begin_define
define|#
directive|define
name|IDT_WRE
value|0x80
end_define

begin_comment
comment|/* Wait/DMA Request Enable. */
end_comment

begin_define
define|#
directive|define
name|IDT_REQ
value|0x40
end_define

begin_comment
comment|/* DMA Request. */
end_comment

begin_define
define|#
directive|define
name|IDT_WRR
value|0x20
end_define

begin_comment
comment|/* Wait/DMA Reuest on Receive. */
end_comment

begin_define
define|#
directive|define
name|IDT_RISC
value|0x18
end_define

begin_comment
comment|/* Rx Int. on Special Condition Only. */
end_comment

begin_define
define|#
directive|define
name|IDT_RIA
value|0x10
end_define

begin_comment
comment|/* Rx Int. on All Characters. */
end_comment

begin_define
define|#
directive|define
name|IDT_RIF
value|0x08
end_define

begin_comment
comment|/* Rx Int. on First Character. */
end_comment

begin_define
define|#
directive|define
name|IDT_PSC
value|0x04
end_define

begin_comment
comment|/* Parity is Special Condition. */
end_comment

begin_define
define|#
directive|define
name|IDT_TIE
value|0x02
end_define

begin_comment
comment|/* Tx Int. Enable. */
end_comment

begin_define
define|#
directive|define
name|IDT_XIE
value|0x01
end_define

begin_comment
comment|/* Ext. Int. Enable. */
end_comment

begin_comment
comment|/* Interrupt Pending (RR3). */
end_comment

begin_define
define|#
directive|define
name|IP_RIA
value|0x20
end_define

begin_comment
comment|/* Rx. Int. ch. A. */
end_comment

begin_define
define|#
directive|define
name|IP_TIA
value|0x10
end_define

begin_comment
comment|/* Tx. Int. ch. A. */
end_comment

begin_define
define|#
directive|define
name|IP_SIA
value|0x08
end_define

begin_comment
comment|/* Ext/Status Int. ch. A. */
end_comment

begin_define
define|#
directive|define
name|IP_RIB
value|0x04
end_define

begin_comment
comment|/* Rx. Int. ch. B. */
end_comment

begin_define
define|#
directive|define
name|IP_TIB
value|0x02
end_define

begin_comment
comment|/* Tx. Int. ch. B. */
end_comment

begin_define
define|#
directive|define
name|IP_SIB
value|0x01
end_define

begin_comment
comment|/* Ext/Status Int. ch. B. */
end_comment

begin_comment
comment|/* Interrupt Vector Status Low (RR2). */
end_comment

begin_define
define|#
directive|define
name|IV_SCA
value|0x0e
end_define

begin_comment
comment|/* Special Condition ch. A. */
end_comment

begin_define
define|#
directive|define
name|IV_RAA
value|0x0c
end_define

begin_comment
comment|/* Receive Available ch. A. */
end_comment

begin_define
define|#
directive|define
name|IV_XSA
value|0x0a
end_define

begin_comment
comment|/* External/Status Change ch. A. */
end_comment

begin_define
define|#
directive|define
name|IV_TEA
value|0x08
end_define

begin_comment
comment|/* Transmitter Empty ch. A. */
end_comment

begin_define
define|#
directive|define
name|IV_SCB
value|0x06
end_define

begin_comment
comment|/* Special Condition ch. B. */
end_comment

begin_define
define|#
directive|define
name|IV_RAB
value|0x04
end_define

begin_comment
comment|/* Receive Available ch. B. */
end_comment

begin_define
define|#
directive|define
name|IV_XSB
value|0x02
end_define

begin_comment
comment|/* External/Status Change ch. B. */
end_comment

begin_define
define|#
directive|define
name|IV_TEB
value|0x00
end_define

begin_comment
comment|/* Transmitter Empty ch. B. */
end_comment

begin_comment
comment|/* Miscellaneous Control Bits part 1 (WR10). */
end_comment

begin_define
define|#
directive|define
name|MCB1_CRC1
value|0x80
end_define

begin_comment
comment|/* CRC presets to 1. */
end_comment

begin_define
define|#
directive|define
name|MCB1_FM0
value|0x60
end_define

begin_comment
comment|/* FM0 Encoding. */
end_comment

begin_define
define|#
directive|define
name|MCB1_FM1
value|0x40
end_define

begin_comment
comment|/* FM1 Encoding. */
end_comment

begin_define
define|#
directive|define
name|MCB1_NRZI
value|0x20
end_define

begin_comment
comment|/* NRZI Encoding. */
end_comment

begin_define
define|#
directive|define
name|MCB1_NRZ
value|0x00
end_define

begin_comment
comment|/* NRZ Encoding. */
end_comment

begin_define
define|#
directive|define
name|MCB1_AOP
value|0x10
end_define

begin_comment
comment|/* Active On Poll. */
end_comment

begin_define
define|#
directive|define
name|MCB1_MI
value|0x08
end_define

begin_comment
comment|/* Mark Idle. */
end_comment

begin_define
define|#
directive|define
name|MCB1_AOU
value|0x04
end_define

begin_comment
comment|/* Abort On Underrun. */
end_comment

begin_define
define|#
directive|define
name|MCB1_LM
value|0x02
end_define

begin_comment
comment|/* Loop Mode. */
end_comment

begin_define
define|#
directive|define
name|MCB1_SIX
value|0x01
end_define

begin_comment
comment|/* 6 or 12 bit SYNC. */
end_comment

begin_comment
comment|/* Miscellaneous Control Bits part 2 (WR14). */
end_comment

begin_define
define|#
directive|define
name|MCB2_NRZI
value|0xe0
end_define

begin_comment
comment|/* DPLL - NRZI mode. */
end_comment

begin_define
define|#
directive|define
name|MCB2_FM
value|0xc0
end_define

begin_comment
comment|/* DPLL - FM mode. */
end_comment

begin_define
define|#
directive|define
name|MCB2_RTXC
value|0xa0
end_define

begin_comment
comment|/* DPLL - Clock from -RTxC. */
end_comment

begin_define
define|#
directive|define
name|MCB2_BRG
value|0x80
end_define

begin_comment
comment|/* DPLL - Clock from BRG. */
end_comment

begin_define
define|#
directive|define
name|MCB2_OFF
value|0x60
end_define

begin_comment
comment|/* DPLL - Disable. */
end_comment

begin_define
define|#
directive|define
name|MCB2_RMC
value|0x40
end_define

begin_comment
comment|/* DPLL - Reset Missing Clock. */
end_comment

begin_define
define|#
directive|define
name|MCB2_ESM
value|0x20
end_define

begin_comment
comment|/* DPLL - Enter Search Mode. */
end_comment

begin_define
define|#
directive|define
name|MCB2_LL
value|0x10
end_define

begin_comment
comment|/* Local Loopback. */
end_comment

begin_define
define|#
directive|define
name|MCB2_AE
value|0x08
end_define

begin_comment
comment|/* Auto Echo. */
end_comment

begin_define
define|#
directive|define
name|MCB2_REQ
value|0x04
end_define

begin_comment
comment|/* Request Function. */
end_comment

begin_define
define|#
directive|define
name|MCB2_PCLK
value|0x02
end_define

begin_comment
comment|/* BRG source is PCLK. */
end_comment

begin_define
define|#
directive|define
name|MCB2_BRGE
value|0x01
end_define

begin_comment
comment|/* BRG enable. */
end_comment

begin_comment
comment|/* Master Interrupt Control (WR9). */
end_comment

begin_define
define|#
directive|define
name|MIC_FHR
value|0xc0
end_define

begin_comment
comment|/* Force Hardware Reset. */
end_comment

begin_define
define|#
directive|define
name|MIC_CRA
value|0x80
end_define

begin_comment
comment|/* Channel Reset A. */
end_comment

begin_define
define|#
directive|define
name|MIC_CRB
value|0x40
end_define

begin_comment
comment|/* Channel Reset B. */
end_comment

begin_define
define|#
directive|define
name|MIC_SIE
value|0x20
end_define

begin_comment
comment|/* Software INTACK Enable. */
end_comment

begin_define
define|#
directive|define
name|MIC_SH
value|0x10
end_define

begin_comment
comment|/* Status High. */
end_comment

begin_define
define|#
directive|define
name|MIC_MIE
value|0x08
end_define

begin_comment
comment|/* Master Interrupt Enable. */
end_comment

begin_define
define|#
directive|define
name|MIC_DLC
value|0x04
end_define

begin_comment
comment|/* Disable Lower Chain. */
end_comment

begin_define
define|#
directive|define
name|MIC_NV
value|0x02
end_define

begin_comment
comment|/* No Vector. */
end_comment

begin_define
define|#
directive|define
name|MIC_VIS
value|0x01
end_define

begin_comment
comment|/* Vector Includes Status. */
end_comment

begin_comment
comment|/* Transmit/Receive Miscellaneous Parameters and Modes (WR4). */
end_comment

begin_define
define|#
directive|define
name|MPM_CM64
value|0xc0
end_define

begin_comment
comment|/* X64 Clock Mode. */
end_comment

begin_define
define|#
directive|define
name|MPM_CM32
value|0x80
end_define

begin_comment
comment|/* X32 Clock Mode. */
end_comment

begin_define
define|#
directive|define
name|MPM_CM16
value|0x40
end_define

begin_comment
comment|/* X16 Clock Mode. */
end_comment

begin_define
define|#
directive|define
name|MPM_CM1
value|0x00
end_define

begin_comment
comment|/* X1 Clock Mode. */
end_comment

begin_define
define|#
directive|define
name|MPM_EXT
value|0x30
end_define

begin_comment
comment|/* External Sync Mode. */
end_comment

begin_define
define|#
directive|define
name|MPM_SDLC
value|0x20
end_define

begin_comment
comment|/* SDLC mode. */
end_comment

begin_define
define|#
directive|define
name|MPM_BI
value|0x10
end_define

begin_comment
comment|/* 16-bit Sync (bi-sync). */
end_comment

begin_define
define|#
directive|define
name|MPM_MONO
value|0x00
end_define

begin_comment
comment|/* 8-bit Sync (mono-sync). */
end_comment

begin_define
define|#
directive|define
name|MPM_SB2
value|0x0c
end_define

begin_comment
comment|/* Async mode: 2 stopbits. */
end_comment

begin_define
define|#
directive|define
name|MPM_SB15
value|0x08
end_define

begin_comment
comment|/* Async mode: 1.5 stopbits. */
end_comment

begin_define
define|#
directive|define
name|MPM_SB1
value|0x04
end_define

begin_comment
comment|/* Async mode: 1 stopbit. */
end_comment

begin_define
define|#
directive|define
name|MPM_SYNC
value|0x00
end_define

begin_comment
comment|/* Sync Mode Enable. */
end_comment

begin_define
define|#
directive|define
name|MPM_EVEN
value|0x02
end_define

begin_comment
comment|/* Async mode: even parity. */
end_comment

begin_define
define|#
directive|define
name|MPM_PE
value|0x01
end_define

begin_comment
comment|/* Async mode: parity enable. */
end_comment

begin_comment
comment|/* Receive Parameters and Control (WR3). */
end_comment

begin_define
define|#
directive|define
name|RPC_RB8
value|0xc0
end_define

begin_comment
comment|/* 8 databits. */
end_comment

begin_define
define|#
directive|define
name|RPC_RB6
value|0x80
end_define

begin_comment
comment|/* 6 databits. */
end_comment

begin_define
define|#
directive|define
name|RPC_RB7
value|0x40
end_define

begin_comment
comment|/* 7 databits. */
end_comment

begin_define
define|#
directive|define
name|RPC_RB5
value|0x00
end_define

begin_comment
comment|/* 5 databits. */
end_comment

begin_define
define|#
directive|define
name|RPC_AE
value|0x20
end_define

begin_comment
comment|/* Auto Enable. */
end_comment

begin_define
define|#
directive|define
name|RPC_EHM
value|0x10
end_define

begin_comment
comment|/* Enter Hunt Mode. */
end_comment

begin_define
define|#
directive|define
name|RPC_CRC
value|0x08
end_define

begin_comment
comment|/* CRC Enable. */
end_comment

begin_define
define|#
directive|define
name|RPC_ASM
value|0x04
end_define

begin_comment
comment|/* Address Search Mode. */
end_comment

begin_define
define|#
directive|define
name|RPC_LI
value|0x02
end_define

begin_comment
comment|/* SYNC Character Load Inhibit */
end_comment

begin_define
define|#
directive|define
name|RPC_RXE
value|0x01
end_define

begin_comment
comment|/* Receiver Enable */
end_comment

begin_comment
comment|/* Special Receive Condition (RR1). */
end_comment

begin_define
define|#
directive|define
name|SRC_EOF
value|0x80
end_define

begin_comment
comment|/* End Of Frame. */
end_comment

begin_define
define|#
directive|define
name|SRC_FE
value|0x40
end_define

begin_comment
comment|/* Framing Error. */
end_comment

begin_define
define|#
directive|define
name|SRC_OVR
value|0x20
end_define

begin_comment
comment|/* Rx. Overrun. */
end_comment

begin_define
define|#
directive|define
name|SRC_PE
value|0x10
end_define

begin_comment
comment|/* Parity Error. */
end_comment

begin_define
define|#
directive|define
name|SRC_RC0
value|0x08
end_define

begin_comment
comment|/* Residue Code 0. */
end_comment

begin_define
define|#
directive|define
name|SRC_RC1
value|0x04
end_define

begin_comment
comment|/* Residue Code 1. */
end_comment

begin_define
define|#
directive|define
name|SRC_RC2
value|0x02
end_define

begin_comment
comment|/* Residue Code 2. */
end_comment

begin_define
define|#
directive|define
name|SRC_AS
value|0x01
end_define

begin_comment
comment|/* All Sent. */
end_comment

begin_comment
comment|/* Transmit Parameter and Control (WR5). */
end_comment

begin_define
define|#
directive|define
name|TPC_DTR
value|0x80
end_define

begin_comment
comment|/* DTR. */
end_comment

begin_define
define|#
directive|define
name|TPC_TB8
value|0x60
end_define

begin_comment
comment|/* 8 databits. */
end_comment

begin_define
define|#
directive|define
name|TPC_TB6
value|0x40
end_define

begin_comment
comment|/* 6 databits. */
end_comment

begin_define
define|#
directive|define
name|TPC_TB7
value|0x20
end_define

begin_comment
comment|/* 7 databits. */
end_comment

begin_define
define|#
directive|define
name|TPC_TB5
value|0x00
end_define

begin_comment
comment|/* 5 or fewer databits. */
end_comment

begin_define
define|#
directive|define
name|TPC_BRK
value|0x10
end_define

begin_comment
comment|/* Send break. */
end_comment

begin_define
define|#
directive|define
name|TPC_TXE
value|0x08
end_define

begin_comment
comment|/* Transmitter Enable. */
end_comment

begin_define
define|#
directive|define
name|TPC_CRC16
value|0x04
end_define

begin_comment
comment|/* CRC16. */
end_comment

begin_define
define|#
directive|define
name|TPC_RTS
value|0x02
end_define

begin_comment
comment|/* RTS. */
end_comment

begin_define
define|#
directive|define
name|TPC_CRC
value|0x01
end_define

begin_comment
comment|/* CRC Enable. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_IC_Z8530_H_ */
end_comment

end_unit

