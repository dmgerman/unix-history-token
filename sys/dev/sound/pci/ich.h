begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Katsurajima Naoto<raven@katsurajima.seya.yokohama.jp>  * Copyright (c) 2001 Cameron Grant<cg@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|PCIR_NAMBAR
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIR_NABMBAR
value|0x14
end_define

begin_comment
comment|/* Native Audio Bus Master Control Registers */
end_comment

begin_define
define|#
directive|define
name|ICH_REG_X_BDBAR
value|0x00
end_define

begin_define
define|#
directive|define
name|ICH_REG_X_CIV
value|0x04
end_define

begin_define
define|#
directive|define
name|ICH_REG_X_LVI
value|0x05
end_define

begin_define
define|#
directive|define
name|ICH_REG_X_SR
value|0x06
end_define

begin_define
define|#
directive|define
name|ICH_REG_X_PICB
value|0x08
end_define

begin_define
define|#
directive|define
name|ICH_REG_X_PIV
value|0x0a
end_define

begin_define
define|#
directive|define
name|ICH_REG_X_CR
value|0x0b
end_define

begin_define
define|#
directive|define
name|ICH_REG_PI_BASE
value|0x00
end_define

begin_define
define|#
directive|define
name|ICH_REG_PO_BASE
value|0x10
end_define

begin_define
define|#
directive|define
name|ICH_REG_MC_BASE
value|0x20
end_define

begin_define
define|#
directive|define
name|ICH_REG_GLOB_CNT
value|0x2c
end_define

begin_define
define|#
directive|define
name|ICH_REG_GLOB_STA
value|0x30
end_define

begin_define
define|#
directive|define
name|ICH_REG_ACC_SEMA
value|0x34
end_define

begin_comment
comment|/* Status Register Values */
end_comment

begin_define
define|#
directive|define
name|ICH_X_SR_DCH
value|0x0001
end_define

begin_define
define|#
directive|define
name|ICH_X_SR_CELV
value|0x0002
end_define

begin_define
define|#
directive|define
name|ICH_X_SR_LVBCI
value|0x0004
end_define

begin_define
define|#
directive|define
name|ICH_X_SR_BCIS
value|0x0008
end_define

begin_define
define|#
directive|define
name|ICH_X_SR_FIFOE
value|0x0010
end_define

begin_comment
comment|/* Control Register Values */
end_comment

begin_define
define|#
directive|define
name|ICH_X_CR_RPBM
value|0x01
end_define

begin_define
define|#
directive|define
name|ICH_X_CR_RR
value|0x02
end_define

begin_define
define|#
directive|define
name|ICH_X_CR_LVBIE
value|0x04
end_define

begin_define
define|#
directive|define
name|ICH_X_CR_FEIE
value|0x08
end_define

begin_define
define|#
directive|define
name|ICH_X_CR_IOCE
value|0x10
end_define

begin_comment
comment|/* Global Control Register Values */
end_comment

begin_define
define|#
directive|define
name|ICH_GLOB_CTL_GIE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_CTL_COLD
value|0x00000002
end_define

begin_comment
comment|/* negate */
end_comment

begin_define
define|#
directive|define
name|ICH_GLOB_CTL_WARM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_CTL_SHUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_CTL_PRES
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_CTL_SRES
value|0x00000020
end_define

begin_comment
comment|/* Global Status Register Values */
end_comment

begin_define
define|#
directive|define
name|ICH_GLOB_STA_GSCI
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_MIINT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_MOINT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_PIINT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_POINT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_MINT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_PCR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_SCR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_PRES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_SRES
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_SLOT12
value|0x00007000
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_RCODEC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_AD3
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_MD3
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ICH_GLOB_STA_IMASK
value|(ICH_GLOB_STA_MIINT | ICH_GLOB_STA_MOINT | ICH_GLOB_STA_PIINT | ICH_GLOB_STA_POINT | ICH_GLOB_STA_MINT | ICH_GLOB_STA_PRES | ICH_GLOB_STA_SRES)
end_define

begin_comment
comment|/* play/record buffer */
end_comment

begin_define
define|#
directive|define
name|ICH_BDC_IOC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ICH_BDC_BUP
value|0x40000000
end_define

end_unit

