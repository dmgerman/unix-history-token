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
name|ARM_AT91_AT91_PDCREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PDCREG_H
end_define

begin_define
define|#
directive|define
name|PDC_RPR
value|0x100
end_define

begin_comment
comment|/* PDC Receive Pointer Register */
end_comment

begin_define
define|#
directive|define
name|PDC_RCR
value|0x104
end_define

begin_comment
comment|/* PDC Receive Counter Register */
end_comment

begin_define
define|#
directive|define
name|PDC_TPR
value|0x108
end_define

begin_comment
comment|/* PDC Transmit Pointer Register */
end_comment

begin_define
define|#
directive|define
name|PDC_TCR
value|0x10c
end_define

begin_comment
comment|/* PDC Transmit Counter Register */
end_comment

begin_define
define|#
directive|define
name|PDC_RNPR
value|0x110
end_define

begin_comment
comment|/* PDC Receive Next Pointer Register */
end_comment

begin_define
define|#
directive|define
name|PDC_RNCR
value|0x114
end_define

begin_comment
comment|/* PDC Receive Next Counter Register */
end_comment

begin_define
define|#
directive|define
name|PDC_TNPR
value|0x118
end_define

begin_comment
comment|/* PDC Transmit Next Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|PDC_TNCR
value|0x11c
end_define

begin_comment
comment|/* PDC Transmit Next Counter Reg */
end_comment

begin_define
define|#
directive|define
name|PDC_PTCR
value|0x120
end_define

begin_comment
comment|/* PDC Transfer Control Register */
end_comment

begin_define
define|#
directive|define
name|PDC_PTSR
value|0x124
end_define

begin_comment
comment|/* PDC Transfer Status Register */
end_comment

begin_comment
comment|/* PTCR/PTSR */
end_comment

begin_define
define|#
directive|define
name|PDC_PTCR_RXTEN
value|(1UL<< 0)
end_define

begin_comment
comment|/* RXTEN: Receiver Transfer Enable */
end_comment

begin_define
define|#
directive|define
name|PDC_PTCR_RXTDIS
value|(1UL<< 1)
end_define

begin_comment
comment|/* RXTDIS: Receiver Transfer Disable */
end_comment

begin_define
define|#
directive|define
name|PDC_PTCR_TXTEN
value|(1UL<< 8)
end_define

begin_comment
comment|/* TXTEN: Transmitter Transfer En */
end_comment

begin_define
define|#
directive|define
name|PDC_PTCR_TXTDIS
value|(1UL<< 9)
end_define

begin_comment
comment|/* TXTDIS: Transmitter Transmit Dis */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PDCREG_H */
end_comment

end_unit

