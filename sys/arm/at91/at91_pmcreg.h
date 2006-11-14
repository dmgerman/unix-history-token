begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_PMCREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PMCREG_H
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER
value|0x00
end_define

begin_comment
comment|/* System Clock Enable Register */
end_comment

begin_define
define|#
directive|define
name|PMC_SCDR
value|0x04
end_define

begin_comment
comment|/* System Clock Disable Register */
end_comment

begin_define
define|#
directive|define
name|PMC_SCSR
value|0x08
end_define

begin_comment
comment|/* System Clock Status Register */
end_comment

begin_comment
comment|/*	0x0c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PMC_PCER
value|0x10
end_define

begin_comment
comment|/* Peripheral Clock Enable Register */
end_comment

begin_define
define|#
directive|define
name|PMC_PCDR
value|0x14
end_define

begin_comment
comment|/* Peripheral Clock Disable Register */
end_comment

begin_define
define|#
directive|define
name|PMC_PCSR
value|0x18
end_define

begin_comment
comment|/* Peripheral Clock Status Register */
end_comment

begin_comment
comment|/*	0x1c		   reserved */
end_comment

begin_define
define|#
directive|define
name|CKGR_MOR
value|0x20
end_define

begin_comment
comment|/* Main Oscillator Register */
end_comment

begin_define
define|#
directive|define
name|CKGR_MCFR
value|0x24
end_define

begin_comment
comment|/* Main Clock Frequency Register */
end_comment

begin_define
define|#
directive|define
name|CKGR_PLLAR
value|0x28
end_define

begin_comment
comment|/* PLL A Register */
end_comment

begin_define
define|#
directive|define
name|CKGR_PLLBR
value|0x2c
end_define

begin_comment
comment|/* PLL B Register */
end_comment

begin_define
define|#
directive|define
name|PMC_MCKR
value|0x30
end_define

begin_comment
comment|/* Master Clock Register */
end_comment

begin_comment
comment|/*	0x34		   reserved */
end_comment

begin_comment
comment|/*	0x38		   reserved */
end_comment

begin_comment
comment|/*	0x3c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PMC_PCK0
value|0x40
end_define

begin_comment
comment|/* Programmable Clock 0 Register */
end_comment

begin_define
define|#
directive|define
name|PMC_PCK1
value|0x44
end_define

begin_comment
comment|/* Programmable Clock 1 Register */
end_comment

begin_define
define|#
directive|define
name|PMC_PCK2
value|0x48
end_define

begin_comment
comment|/* Programmable Clock 2 Register */
end_comment

begin_define
define|#
directive|define
name|PMC_PCK3
value|0x4c
end_define

begin_comment
comment|/* Programmable Clock 3 Register */
end_comment

begin_comment
comment|/*	0x50		   reserved */
end_comment

begin_comment
comment|/*	0x54		   reserved */
end_comment

begin_comment
comment|/*	0x58		   reserved */
end_comment

begin_comment
comment|/*	0x5c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PMC_IER
value|0x60
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|PMC_IDR
value|0x64
end_define

begin_comment
comment|/* Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|PMC_SR
value|0x68
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|PMC_IMR
value|0x6c
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_comment
comment|/* PMC System Clock Enable Register */
end_comment

begin_comment
comment|/* PMC System Clock Disable Register */
end_comment

begin_comment
comment|/* PMC System Clock StatusRegister */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_PCK
value|(1UL<< 0)
end_define

begin_comment
comment|/* PCK: Processor Clock Enable */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_UDP
value|(1UL<< 1)
end_define

begin_comment
comment|/* UDP: USB Device Port Clock Enable */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_MCKUDP
value|(1UL<< 2)
end_define

begin_comment
comment|/* MCKUDP: Master disable susp/res */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_UHP
value|(1UL<< 4)
end_define

begin_comment
comment|/* UHP: USB Host Port Clock Enable */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_PCK0
value|(1UL<< 8)
end_define

begin_comment
comment|/* PCK0: Programmable Clock out en */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_PCK1
value|(1UL<< 10)
end_define

begin_comment
comment|/* PCK1: Programmable Clock out en */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_PCK2
value|(1UL<< 11)
end_define

begin_comment
comment|/* PCK2: Programmable Clock out en */
end_comment

begin_define
define|#
directive|define
name|PMC_SCER_PCK3
value|(1UL<< 12)
end_define

begin_comment
comment|/* PCK3: Programmable Clock out en */
end_comment

begin_comment
comment|/* PMC Peripheral Clock Enable Register */
end_comment

begin_comment
comment|/* PMC Peripheral Clock Disable Register */
end_comment

begin_comment
comment|/* PMC Peripheral Clock Status Register */
end_comment

begin_comment
comment|/* Each bit here is 1<< peripheral number  to enable/disable/status */
end_comment

begin_comment
comment|/* PMC Clock Generator Main Oscillator Register */
end_comment

begin_define
define|#
directive|define
name|CKGR_MOR_MOSCEN
value|(1UL<< 0)
end_define

begin_comment
comment|/* MOSCEN: Main Oscillator Enable */
end_comment

begin_define
define|#
directive|define
name|CKGR_MOR_OSCBYPASS
value|(1UL<< 1)
end_define

begin_comment
comment|/* Oscillator Bypass */
end_comment

begin_define
define|#
directive|define
name|CKGR_MOR_OSCOUNT
parameter_list|(
name|x
parameter_list|)
value|(x<< 8)
end_define

begin_comment
comment|/* Main Oscillator Start-up Time */
end_comment

begin_comment
comment|/* PMC Clock Generator Main Clock Frequency Register */
end_comment

begin_define
define|#
directive|define
name|CKGR_MCFR_MAINRDY
value|(1UL<< 16)
end_define

begin_comment
comment|/* Main Clock Ready */
end_comment

begin_define
define|#
directive|define
name|CKGR_MCFR_MAINF_MASK
value|0xfffful
end_define

begin_comment
comment|/* Main Clock Frequency */
end_comment

begin_comment
comment|/* PMC Interrupt Enable Register */
end_comment

begin_comment
comment|/* PMC Interrupt Disable Register */
end_comment

begin_comment
comment|/* PMC Status Register */
end_comment

begin_comment
comment|/* PMC Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_MOSCS
value|(1UL<< 0)
end_define

begin_comment
comment|/* Main Oscillator Status */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_LOCKA
value|(1UL<< 1)
end_define

begin_comment
comment|/* PLL A Locked */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_LOCKB
value|(1UL<< 2)
end_define

begin_comment
comment|/* PLL B Locked */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_MCKRDY
value|(1UL<< 3)
end_define

begin_comment
comment|/* Master Clock Status */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_PCK0RDY
value|(1UL<< 8)
end_define

begin_comment
comment|/* Programmable Clock 0 Ready */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_PCK1RDY
value|(1UL<< 9)
end_define

begin_comment
comment|/* Programmable Clock 1 Ready */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_PCK2RDY
value|(1UL<< 10)
end_define

begin_comment
comment|/* Programmable Clock 2 Ready */
end_comment

begin_define
define|#
directive|define
name|PMC_IER_PCK3RDY
value|(1UL<< 11)
end_define

begin_comment
comment|/* Programmable Clock 3 Ready */
end_comment

begin_comment
comment|/*  * PLL input frequency spec sheet says it must be between 1MHz and 32MHz,  * but it works down as low as 100kHz, a frequency necessary for some  * output frequencies to work.  */
end_comment

begin_define
define|#
directive|define
name|PMC_PLL_MIN_IN_FREQ
value|100000
end_define

begin_define
define|#
directive|define
name|PMC_PLL_MAX_IN_FREQ
value|32000000
end_define

begin_comment
comment|/*  * PLL Max output frequency is 240MHz.  The errata says 180MHz is the max  * for some revisions of this part.  Be more permissive and optimistic.  */
end_comment

begin_define
define|#
directive|define
name|PMC_PLL_MAX_OUT_FREQ
value|240000000
end_define

begin_define
define|#
directive|define
name|PMC_PLL_MULT_MIN
value|2
end_define

begin_define
define|#
directive|define
name|PMC_PLL_MULT_MAX
value|2048
end_define

begin_define
define|#
directive|define
name|PMC_PLL_SHIFT_TOL
value|5
end_define

begin_comment
comment|/* Allow errors 1 part in 32 */
end_comment

begin_define
define|#
directive|define
name|PMC_PLL_FAST_THRESH
value|155000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PMCREG_H */
end_comment

end_unit

