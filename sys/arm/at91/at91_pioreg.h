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
name|ARM_AT91_AT91_PIOREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PIOREG_H
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|PIO_PER
value|0x00
end_define

begin_comment
comment|/* PIO Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PDR
value|0x04
end_define

begin_comment
comment|/* PIO Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PSR
value|0x08
end_define

begin_comment
comment|/* PIO Status Register */
end_comment

begin_comment
comment|/*	0x0c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_OER
value|0x10
end_define

begin_comment
comment|/* PIO Output Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ODR
value|0x14
end_define

begin_comment
comment|/* PIO Output Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_OSR
value|0x18
end_define

begin_comment
comment|/* PIO Output Status Register */
end_comment

begin_comment
comment|/*	0x1c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_IFER
value|0x20
end_define

begin_comment
comment|/* PIO Glitch Input Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IFDR
value|0x24
end_define

begin_comment
comment|/* PIO Glitch Input Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IFSR
value|0x28
end_define

begin_comment
comment|/* PIO Glitch Input Status Register */
end_comment

begin_comment
comment|/*	0x2c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_SODR
value|0x30
end_define

begin_comment
comment|/* PIO Set Output Data Register */
end_comment

begin_define
define|#
directive|define
name|PIO_CODR
value|0x34
end_define

begin_comment
comment|/* PIO Clear Output Data Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ODSR
value|0x38
end_define

begin_comment
comment|/* PIO Output Data Status Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PDSR
value|0x3c
end_define

begin_comment
comment|/* PIO Pin Data Status Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IER
value|0x40
end_define

begin_comment
comment|/* PIO Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IDR
value|0x44
end_define

begin_comment
comment|/* PIO Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IMR
value|0x48
end_define

begin_comment
comment|/* PIO Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ISR
value|0x4c
end_define

begin_comment
comment|/* PIO Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|PIO_MDER
value|0x50
end_define

begin_comment
comment|/* PIO Multi-Driver Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_MDDR
value|0x54
end_define

begin_comment
comment|/* PIO Multi-Driver Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_MDSR
value|0x58
end_define

begin_comment
comment|/* PIO Multi-Driver Status Register */
end_comment

begin_comment
comment|/*	0x5c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_PUDR
value|0x60
end_define

begin_comment
comment|/* PIO Pull-up Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PUER
value|0x64
end_define

begin_comment
comment|/* PIO Pull-up Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PUSR
value|0x68
end_define

begin_comment
comment|/* PIO Pull-up Status Register */
end_comment

begin_comment
comment|/*	0x6c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_ASR
value|0x70
end_define

begin_comment
comment|/* PIO Peripheral A Select Register */
end_comment

begin_define
define|#
directive|define
name|PIO_BSR
value|0x74
end_define

begin_comment
comment|/* PIO Peripheral B Select Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ABSR
value|0x78
end_define

begin_comment
comment|/* PIO AB Status Register */
end_comment

begin_comment
comment|/*	0x7c-0x9c	   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_OWER
value|0xa0
end_define

begin_comment
comment|/* PIO Output Write Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_OWDR
value|0xa4
end_define

begin_comment
comment|/* PIO Output Write Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_OWSR
value|0xa8
end_define

begin_comment
comment|/* PIO Output Write Status Register */
end_comment

begin_comment
comment|/*	0xac		   reserved */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PIOREG_H */
end_comment

end_unit

