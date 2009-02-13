begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_SSCREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_SSCREG_H
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|SSC_CR
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|SSC_CMR
value|0x04
end_define

begin_comment
comment|/* Clock Mode Register */
end_comment

begin_comment
comment|/*	0x08		Reserved */
end_comment

begin_comment
comment|/*	0x0c		Reserved */
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR
value|0x10
end_define

begin_comment
comment|/* Receive Clock Mode Register */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR
value|0x14
end_define

begin_comment
comment|/* Receive Frame Mode Register */
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR
value|0x18
end_define

begin_comment
comment|/* Transmit Clock Mode Register */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR
value|0x1c
end_define

begin_comment
comment|/* Transmit Frame Mode register */
end_comment

begin_define
define|#
directive|define
name|SSC_RHR
value|0x20
end_define

begin_comment
comment|/* Receive Holding Register */
end_comment

begin_define
define|#
directive|define
name|SSC_THR
value|0x24
end_define

begin_comment
comment|/* Transmit Holding Register */
end_comment

begin_comment
comment|/*	0x28		Reserved */
end_comment

begin_comment
comment|/*	0x2c		Reserved */
end_comment

begin_define
define|#
directive|define
name|SSC_RSHR
value|0x30
end_define

begin_comment
comment|/* Receive Sync Holding Register */
end_comment

begin_define
define|#
directive|define
name|SSC_TSHR
value|0x34
end_define

begin_comment
comment|/* Transmit Sync Holding Register */
end_comment

begin_comment
comment|/*	0x38		Reserved */
end_comment

begin_comment
comment|/*	0x3c		Reserved */
end_comment

begin_define
define|#
directive|define
name|SSC_SR
value|0x40
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|SSC_IER
value|0x44
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|SSC_IDR
value|0x48
end_define

begin_comment
comment|/* Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|SSC_IMR
value|0x4c
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_comment
comment|/* And PDC registers */
end_comment

begin_comment
comment|/* SSC_CR */
end_comment

begin_define
define|#
directive|define
name|SSC_CR_RXEN
value|(1u<< 0)
end_define

begin_comment
comment|/* RXEN: Receive Enable */
end_comment

begin_define
define|#
directive|define
name|SSC_CR_RXDIS
value|(1u<< 1)
end_define

begin_comment
comment|/* RXDIS: Receive Disable */
end_comment

begin_define
define|#
directive|define
name|SSC_CR_TXEN
value|(1u<< 8)
end_define

begin_comment
comment|/* TXEN: Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|SSC_CR_TXDIS
value|(1u<< 9)
end_define

begin_comment
comment|/* TXDIS: Transmit Disable */
end_comment

begin_define
define|#
directive|define
name|SSC_CR_SWRST
value|(1u<< 15)
end_define

begin_comment
comment|/* SWRST: Software Reset */
end_comment

begin_comment
comment|/* SSC_CMR */
end_comment

begin_define
define|#
directive|define
name|SSC_CMR_DIV
value|0xfffu
end_define

begin_comment
comment|/* DIV: Clock Divider mask */
end_comment

begin_comment
comment|/* SSC_RCMR */
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR_PERIOD
value|(0xffu<< 24)
end_define

begin_comment
comment|/* PERIOD: Receive Period Divider sel*/
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR_STTDLY
value|(0xffu<< 16)
end_define

begin_comment
comment|/* STTDLY: Receive Start Delay */
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR_START
value|(0xfu<< 8)
end_define

begin_comment
comment|/* START: Receive Start Sel */
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR_START_CONT
value|(0u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_START_TX_START
value|(1u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_START_LOW_RF
value|(2u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_START_HIGH_RF
value|(3u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_START_FALL_EDGE_RF
value|(4u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_START_RISE_EDGE_RF
value|(5u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_START_LEVEL_CHANGE_RF
value|(6u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_START_ANY_EDGE_RF
value|(7u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_CKI
value|(1u<< 5)
end_define

begin_comment
comment|/* CKI: Receive Clock Inversion */
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR_CKO
value|(7u<< 2)
end_define

begin_comment
comment|/* CKO: Receive Clock Output Mode Sel*/
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR_CKO_NONE
value|(0u<< 2)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_CKO_CONTINUOUS
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_CKS
value|(3u)
end_define

begin_comment
comment|/* CKS: Receive Clock Selection */
end_comment

begin_define
define|#
directive|define
name|SSC_RCMR_CKS_DIVIDED
value|(0)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_CKS_TK_CLOCK
value|(1)
end_define

begin_define
define|#
directive|define
name|SSC_RCMR_CKS_RK
value|(2)
end_define

begin_comment
comment|/* SSC_RFMR */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR_FSEDGE
value|(1u<< 24)
end_define

begin_comment
comment|/* FSEDGE: Frame Sync Edge Detection */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR_FSOS
value|(7u<< 20)
end_define

begin_comment
comment|/* FSOS: Receive frame Sync Out sel */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR_FSOS_NONE
value|(0u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_RFMR_FSOS_NEG_PULSE
value|(1u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_RFMR_FSOS_POS_PULSE
value|(2u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_RFMR_FSOS_LOW
value|(3u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_RFMR_FSOS_HIGH
value|(4u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_RFMR_FSOS_TOGGLE
value|(5u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_RFMR_FSLEN
value|(0xfu<< 16)
end_define

begin_comment
comment|/* FSLEN: Receive Frame Sync Length */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR_DATNB
value|(0xfu<< 8)
end_define

begin_comment
comment|/* DATNB: Data Number per Frame */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR_MSFBF
value|(1u<< 7)
end_define

begin_comment
comment|/* MSBF: Most Significant Bit First */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR_LOOP
value|(1u<< 5)
end_define

begin_comment
comment|/* LOOP: Loop Mode */
end_comment

begin_define
define|#
directive|define
name|SSC_RFMR_DATLEN
value|(0x1fu<< 0)
end_define

begin_comment
comment|/* DATLEN: Data Length */
end_comment

begin_comment
comment|/* SSC_TCMR */
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR_PERIOD
value|(0xffu<< 24)
end_define

begin_comment
comment|/* PERIOD: Receive Period Divider sel*/
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR_STTDLY
value|(0xffu<< 16)
end_define

begin_comment
comment|/* STTDLY: Receive Start Delay */
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR_START
value|(0xfu<< 8)
end_define

begin_comment
comment|/* START: Receive Start Sel */
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR_START_CONT
value|(0u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_START_RX_START
value|(1u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_START_LOW_RF
value|(2u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_START_HIGH_RF
value|(3u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_START_FALL_EDGE_RF
value|(4u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_START_RISE_EDGE_RF
value|(5u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_START_LEVEL_CHANGE_RF
value|(6u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_START_ANY_EDGE_RF
value|(7u<< 8)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_CKI
value|(1u<< 5)
end_define

begin_comment
comment|/* CKI: Receive Clock Inversion */
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR_CKO
value|(7u<< 2)
end_define

begin_comment
comment|/* CKO: Receive Clock Output Mode Sel*/
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR_CKO_NONE
value|(0u<< 2)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_CKO_CONTINUOUS
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_CKS
value|(3u)
end_define

begin_comment
comment|/* CKS: Receive Clock Selection */
end_comment

begin_define
define|#
directive|define
name|SSC_TCMR_CKS_DIVIDED
value|(0)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_CKS_RK_CLOCK
value|(1)
end_define

begin_define
define|#
directive|define
name|SSC_TCMR_CKS_TK
value|(2)
end_define

begin_comment
comment|/* SSC_TFMR */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR_FSEDGE
value|(1u<< 24)
end_define

begin_comment
comment|/* FSEDGE: Frame Sync Edge Detection */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR_FSOS
value|(7u<< 20)
end_define

begin_comment
comment|/* FSOS: Receive frame Sync Out sel */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR_FSOS_NONE
value|(0u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_TFMR_FSOS_NEG_PULSE
value|(1u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_TFMR_FSOS_POS_PULSE
value|(2u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_TFMR_FSOS_LOW
value|(3u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_TFMR_FSOS_HIGH
value|(4u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_TFMR_FSOS_TOGGLE
value|(5u<< 20)
end_define

begin_define
define|#
directive|define
name|SSC_TFMR_FSLEN
value|(0xfu<< 16)
end_define

begin_comment
comment|/* FSLEN: Receive Frame Sync Length */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR_DATNB
value|(0xfu<< 8)
end_define

begin_comment
comment|/* DATNB: Data Number per Frame */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR_MSFBF
value|(1u<< 7)
end_define

begin_comment
comment|/* MSBF: Most Significant Bit First */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR_DATDEF
value|(1u<< 5)
end_define

begin_comment
comment|/* DATDEF: Data Default Value */
end_comment

begin_define
define|#
directive|define
name|SSC_TFMR_DATLEN
value|(0x1fu<< 0)
end_define

begin_comment
comment|/* DATLEN: Data Length */
end_comment

begin_comment
comment|/* SSC_SR */
end_comment

begin_define
define|#
directive|define
name|SSC_SR_TXRDY
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|SSC_SR_TXEMPTY
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|SSC_SR_ENDTX
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|SSC_SR_TXBUFE
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|SSC_SR_RXRDY
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|SSC_SR_OVRUN
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|SSC_SR_ENDRX
value|(1u<< 6)
end_define

begin_define
define|#
directive|define
name|SSC_SR_RXBUFF
value|(1u<< 7)
end_define

begin_define
define|#
directive|define
name|SSC_SR_TXSYN
value|(1u<< 10)
end_define

begin_define
define|#
directive|define
name|SSC_SR_RSSYN
value|(1u<< 11)
end_define

begin_define
define|#
directive|define
name|SSC_SR_TXEN
value|(1u<< 16)
end_define

begin_define
define|#
directive|define
name|SSC_SR_RXEN
value|(1u<< 17)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_SSCREG_H */
end_comment

end_unit

