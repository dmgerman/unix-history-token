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
name|ARM_AT91_AT91_SPIREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_SPIREG_H
end_define

begin_define
define|#
directive|define
name|SPI_CR
value|0x00
end_define

begin_comment
comment|/* CR: Control Register */
end_comment

begin_define
define|#
directive|define
name|SPI_CR_SPIEN
value|0x1
end_define

begin_define
define|#
directive|define
name|SPI_CR_SPIDIS
value|0x2
end_define

begin_define
define|#
directive|define
name|SPI_CR_SWRST
value|0x8
end_define

begin_define
define|#
directive|define
name|SPI_MR
value|0x04
end_define

begin_comment
comment|/* MR: Mode Register */
end_comment

begin_define
define|#
directive|define
name|SPI_MR_MSTR
value|0x01
end_define

begin_define
define|#
directive|define
name|SPI_MR_PS
value|0x02
end_define

begin_define
define|#
directive|define
name|SPI_MR_PCSDEC
value|0x04
end_define

begin_define
define|#
directive|define
name|SPI_MR_DIV32
value|0x08
end_define

begin_define
define|#
directive|define
name|SPI_MR_MODFDIS
value|0x10
end_define

begin_define
define|#
directive|define
name|SPI_MR_LLB
value|0x80
end_define

begin_define
define|#
directive|define
name|SPI_MR_PSC_CS0
value|0xe0000
end_define

begin_define
define|#
directive|define
name|SPI_MR_PSC_CS1
value|0xd0000
end_define

begin_define
define|#
directive|define
name|SPI_MR_PSC_CS2
value|0xb0000
end_define

begin_define
define|#
directive|define
name|SPI_MR_PSC_CS3
value|0x70000
end_define

begin_define
define|#
directive|define
name|SPI_RDR
value|0x08
end_define

begin_comment
comment|/* RDR: Receive Data Register */
end_comment

begin_define
define|#
directive|define
name|SPI_TDR
value|0x0c
end_define

begin_comment
comment|/* TDR: Transmit Data Register */
end_comment

begin_define
define|#
directive|define
name|SPI_SR
value|0x10
end_define

begin_comment
comment|/* SR: Status Register */
end_comment

begin_define
define|#
directive|define
name|SPI_SR_RDRF
value|0x00001
end_define

begin_define
define|#
directive|define
name|SPI_SR_TDRE
value|0x00002
end_define

begin_define
define|#
directive|define
name|SPI_SR_MODF
value|0x00004
end_define

begin_define
define|#
directive|define
name|SPI_SR_OVRES
value|0x00008
end_define

begin_define
define|#
directive|define
name|SPI_SR_ENDRX
value|0x00010
end_define

begin_define
define|#
directive|define
name|SPI_SR_ENDTX
value|0x00020
end_define

begin_define
define|#
directive|define
name|SPI_SR_RXBUFF
value|0x00040
end_define

begin_define
define|#
directive|define
name|SPI_SR_TXBUFE
value|0x00080
end_define

begin_define
define|#
directive|define
name|SPI_SR_SPIENS
value|0x10000
end_define

begin_define
define|#
directive|define
name|SPI_IER
value|0x14
end_define

begin_comment
comment|/* IER: Interrupt Enable Regsiter */
end_comment

begin_define
define|#
directive|define
name|SPI_IDR
value|0x18
end_define

begin_comment
comment|/* IDR: Interrupt Disable Regsiter */
end_comment

begin_define
define|#
directive|define
name|SPI_IMR
value|0x1c
end_define

begin_comment
comment|/* IMR: Interrupt Mask Regsiter */
end_comment

begin_define
define|#
directive|define
name|SPI_CSR0
value|0x30
end_define

begin_comment
comment|/* CS0: Chip Select 0 */
end_comment

begin_define
define|#
directive|define
name|SPI_CSR_CPOL
value|0x01
end_define

begin_define
define|#
directive|define
name|SPI_CSR1
value|0x34
end_define

begin_comment
comment|/* CS1: Chip Select 1 */
end_comment

begin_define
define|#
directive|define
name|SPI_CSR2
value|0x38
end_define

begin_comment
comment|/* CS2: Chip Select 2 */
end_comment

begin_define
define|#
directive|define
name|SPI_CSR3
value|0x3c
end_define

begin_comment
comment|/* CS3: Chip Select 3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_SPIREG_H */
end_comment

end_unit

