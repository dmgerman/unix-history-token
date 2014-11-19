begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: s3c2410reg.h,v 1.6 2004/02/12 03:52:46 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003, 2004  Genetec corporation.  All rights reserved.  * Written by Hiroyuki Bessho for Genetec corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of Genetec corporation may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORP. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORP.  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Samsung S3C2410X processor is ARM920T based integrated CPU  *  * Reference:  *  S3C2410X User's Manual  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_S3C2XX0_S3C2410REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_S3C2XX0_S3C2410REG_H_
end_define

begin_comment
comment|/* common definitions for S3C2410 and S3C2440 */
end_comment

begin_include
include|#
directive|include
file|<arm/samsung/s3c2xx0/s3c24x0reg.h>
end_include

begin_comment
comment|/*  * Memory Map  */
end_comment

begin_define
define|#
directive|define
name|S3C2410_BANK_SIZE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|S3C2410_BANK_START
parameter_list|(
name|n
parameter_list|)
value|(S3C2410_BANK_SIZE*(n))
end_define

begin_define
define|#
directive|define
name|S3C2410_SDRAM_START
value|S3C2410_BANK_START(6)
end_define

begin_comment
comment|/* interrupt control */
end_comment

begin_define
define|#
directive|define
name|S3C2410_SUBIRQ_MAX
value|(S3C24X0_SUBIRQ_MIN+10)
end_define

begin_comment
comment|/* Clock control */
end_comment

begin_comment
comment|/* CLKMAN_CLKCON */
end_comment

begin_define
define|#
directive|define
name|S3C2410_CLKCON_SM
value|(1<<0)
end_define

begin_comment
comment|/* 1=transition to SPECIAL mode */
end_comment

begin_comment
comment|/* CLKMAN_CLKDIVN */
end_comment

begin_define
define|#
directive|define
name|S3C2410_CLKDIVN_HDIVN
value|(1<<1)
end_define

begin_comment
comment|/* hclk=fclk/2 */
end_comment

begin_comment
comment|/* NAND Flash controller */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NANDFC_SIZE
value|0x18
end_define

begin_comment
comment|/* NANDFC_NFCONF */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NFCONF_ENABLE
value|(1<<15)
end_define

begin_comment
comment|/* NAND controller enabled */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NFCONF_ECC
value|(1<<12)
end_define

begin_comment
comment|/* Initialize ECC decoder/encoder */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NFCONF_FCE
value|(1<<11)
end_define

begin_comment
comment|/* Flash chip enabled */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NFCONF_TACLS
value|(7<<8)
end_define

begin_comment
comment|/* CLE and ALE duration */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NFCONF_TWRPH0
value|(7<<4)
end_define

begin_comment
comment|/* TWRPH0 duration */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NFCONF_TWRPH1
value|(7<<0)
end_define

begin_comment
comment|/* TWRPH1 duration */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NANDFC_NFCMD
value|0x04
end_define

begin_comment
comment|/* command */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NANDFC_NFADDR
value|0x08
end_define

begin_comment
comment|/* address */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NANDFC_NFDATA
value|0x0c
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NANDFC_NFSTAT
value|0x10
end_define

begin_comment
comment|/* operation status */
end_comment

begin_define
define|#
directive|define
name|S3C2410_NANDFC_NFECC
value|0x14
end_define

begin_comment
comment|/* ecc */
end_comment

begin_comment
comment|/* MMC/SD */
end_comment

begin_comment
comment|/* SDI_CON */
end_comment

begin_define
define|#
directive|define
name|S3C2410_CON_FIFO_RESET
value|(1<<1)
end_define

begin_comment
comment|/* GPIO */
end_comment

begin_define
define|#
directive|define
name|S3C2410_GPIO_SIZE
value|0xb4
end_define

begin_comment
comment|/* SD interface */
end_comment

begin_define
define|#
directive|define
name|S3C2410_SDI_SIZE
value|0x44
end_define

begin_define
define|#
directive|define
name|DCON_STOP
value|(1<<14)
end_define

begin_comment
comment|/* Force the transfer to stop */
end_comment

begin_define
define|#
directive|define
name|S3C2410_SDI_DAT
value|0x3c
end_define

begin_define
define|#
directive|define
name|S3C2410_SDI_IMSK
value|0x40
end_define

begin_comment
comment|/* Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|S3C2410_SDI_IMASK_ALL
value|0x3ffdf
end_define

begin_comment
comment|/* ADC */
end_comment

begin_define
define|#
directive|define
name|S3C2410_ADC_SIZE
value|0x14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_S3C2XX0_S3C2410REG_H_ */
end_comment

end_unit

