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
name|ARM_AT91_AT91_TWIREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_TWIREG_H
end_define

begin_define
define|#
directive|define
name|TWI_CR
value|0x00
end_define

begin_comment
comment|/* TWI Control Register */
end_comment

begin_define
define|#
directive|define
name|TWI_MMR
value|0x04
end_define

begin_comment
comment|/* TWI Master Mode Register */
end_comment

begin_define
define|#
directive|define
name|TWI_SMR
value|0x08
end_define

begin_comment
comment|/* TWI Master Mode Register */
end_comment

begin_define
define|#
directive|define
name|TWI_IADR
value|0x0c
end_define

begin_comment
comment|/* TWI Internal Address Register */
end_comment

begin_define
define|#
directive|define
name|TWI_CWGR
value|0x10
end_define

begin_comment
comment|/* TWI Clock Waveform Generator Reg */
end_comment

begin_comment
comment|/*	0x14		   reserved */
end_comment

begin_comment
comment|/*	0x18		   reserved */
end_comment

begin_comment
comment|/*	0x1c		   reserved */
end_comment

begin_define
define|#
directive|define
name|TWI_SR
value|0x20
end_define

begin_comment
comment|/* TWI Status Register */
end_comment

begin_define
define|#
directive|define
name|TWI_IER
value|0x24
end_define

begin_comment
comment|/* TWI Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|TWI_IDR
value|0x28
end_define

begin_comment
comment|/* TWI Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|TWI_IMR
value|0x2c
end_define

begin_comment
comment|/* TWI Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|TWI_RHR
value|0x30
end_define

begin_comment
comment|/* TWI Receiver Holding Register */
end_comment

begin_define
define|#
directive|define
name|TWI_THR
value|0x34
end_define

begin_comment
comment|/* TWI Transmit Holding Register */
end_comment

begin_comment
comment|/* TWI_CR */
end_comment

begin_define
define|#
directive|define
name|TWI_CR_START
value|(1U<< 0)
end_define

begin_comment
comment|/* Send a start */
end_comment

begin_define
define|#
directive|define
name|TWI_CR_STOP
value|(1U<< 1)
end_define

begin_comment
comment|/* Send a stop */
end_comment

begin_define
define|#
directive|define
name|TWI_CR_MSEN
value|(1U<< 2)
end_define

begin_comment
comment|/* Master Transfer Enable */
end_comment

begin_define
define|#
directive|define
name|TWI_CR_MSDIS
value|(1U<< 3)
end_define

begin_comment
comment|/* Master Transfer Disable */
end_comment

begin_define
define|#
directive|define
name|TWI_CR_SVEN
value|(1U<< 4)
end_define

begin_comment
comment|/* Slave Transfer Enable */
end_comment

begin_define
define|#
directive|define
name|TWI_CR_SVDIS
value|(1U<< 5)
end_define

begin_comment
comment|/* Slave Transfer Disable */
end_comment

begin_define
define|#
directive|define
name|TWI_CR_SWRST
value|(1U<< 7)
end_define

begin_comment
comment|/* Software Reset */
end_comment

begin_comment
comment|/* TWI_MMR */
end_comment

begin_comment
comment|/* TWI_SMR */
end_comment

begin_define
define|#
directive|define
name|TWI_MMR_IADRSZ
parameter_list|(
name|n
parameter_list|)
value|((n)<< 8)
end_define

begin_comment
comment|/* Set size of transfer */
end_comment

begin_define
define|#
directive|define
name|TWI_MMR_MWRITE
value|0U
end_define

begin_comment
comment|/* Master Read Direction */
end_comment

begin_define
define|#
directive|define
name|TWI_MMR_MREAD
value|(1U<< 12)
end_define

begin_comment
comment|/* Master Read Direction */
end_comment

begin_define
define|#
directive|define
name|TWI_MMR_DADR
parameter_list|(
name|n
parameter_list|)
value|((n)<< 15)
end_define

begin_comment
comment|/* Device Address */
end_comment

begin_comment
comment|/* TWI_CWGR */
end_comment

begin_define
define|#
directive|define
name|TWI_CWGR_CKDIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_comment
comment|/* Clock Divider */
end_comment

begin_define
define|#
directive|define
name|TWI_CWGR_CHDIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* Clock High Divider */
end_comment

begin_define
define|#
directive|define
name|TWI_CWGR_CLDIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_comment
comment|/* Clock Low Divider */
end_comment

begin_define
define|#
directive|define
name|TWI_CWGR_DIV
parameter_list|(
name|rate
parameter_list|)
value|((AT91C_MASTER_CLOCK /(4*(rate))) - 2)
end_define

begin_comment
comment|/* TWI_SR */
end_comment

begin_comment
comment|/* TWI_IER */
end_comment

begin_comment
comment|/* TWI_IDR */
end_comment

begin_comment
comment|/* TWI_IMR */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_TXCOMP
value|(1U<< 0)
end_define

begin_comment
comment|/* Transmission Completed */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_RXRDY
value|(1U<< 1)
end_define

begin_comment
comment|/* Receive Holding Register Ready */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_TXRDY
value|(1U<< 2)
end_define

begin_comment
comment|/* Transmit Holding Register Ready */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_SVREAD
value|(1U<< 3)
end_define

begin_comment
comment|/* Slave Read */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_SVACC
value|(1U<< 4)
end_define

begin_comment
comment|/* Slave Access */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_GCACC
value|(1U<< 5)
end_define

begin_comment
comment|/* General Call Access */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_OVRE
value|(1U<< 6)
end_define

begin_comment
comment|/* Overrun error */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_UNRE
value|(1U<< 7)
end_define

begin_comment
comment|/* Underrun Error */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_NACK
value|(1U<< 8)
end_define

begin_comment
comment|/* Not Acknowledged */
end_comment

begin_define
define|#
directive|define
name|TWI_SR_ARBLST
value|(1U<< 9)
end_define

begin_comment
comment|/* Arbitration Lost */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_TWIREG_H */
end_comment

end_unit

