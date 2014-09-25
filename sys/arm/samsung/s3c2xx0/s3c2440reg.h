begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2009 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Samsung S3C2440X processor is ARM920T based integrated CPU  *  * Reference:  *  S3C2440A/S3C2442B User's Manual  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_S3C2XX0_S3C2440REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_S3C2XX0_S3C2440REG_H_
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
name|S3C2440_BANK_SIZE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|S3C2440_BANK_START
parameter_list|(
name|n
parameter_list|)
value|(S3C2410_BANK_SIZE*(n))
end_define

begin_define
define|#
directive|define
name|S3C2440_SDRAM_START
value|S3C2410_BANK_START(6)
end_define

begin_comment
comment|/* interrupt control */
end_comment

begin_define
define|#
directive|define
name|S3C2440_SUBIRQ_MAX
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
name|S3C2440_CLKCON_STOP
value|(1<<0)
end_define

begin_comment
comment|/* 1=transition to STOP mode */
end_comment

begin_comment
comment|/* CLKMAN_CLKDIVN */
end_comment

begin_define
define|#
directive|define
name|S3C2440_CLKDIVN_HDIVN
value|(3<<1)
end_define

begin_comment
comment|/* hclk */
end_comment

begin_define
define|#
directive|define
name|S3C2440_CLKMAN_CAMDIVN
value|0x18
end_define

begin_define
define|#
directive|define
name|S3C2440_CAMDIVN_HCLK4_HALF
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|S3C2440_CAMDIVN_HCLK3_HALF
value|(1<<8)
end_define

begin_comment
comment|/* NAND Flash controller */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NANDFC_SIZE
value|0x40
end_define

begin_define
define|#
directive|define
name|S3C2440_NANDFC_NFCONT
value|0x04
end_define

begin_define
define|#
directive|define
name|S3C2440_NFCONT_LOCK_TIGHT
value|(1<<13)
end_define

begin_comment
comment|/* Lock part of the NAND */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_SOFT_LOCK
value|(1<<12)
end_define

begin_comment
comment|/* Soft lock part of the NAND */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_ILLEGAL_ACC_INT
value|(1<<10)
end_define

begin_comment
comment|/* Illegal access interrupt */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_RNB_INT
value|(1<<9)
end_define

begin_comment
comment|/* RnB transition interrupt */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_RNB_TRANS_MODE
value|(1<<8)
end_define

begin_comment
comment|/* RnB transition mode */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_SPARE_ECC_LOCK
value|(1<<6)
end_define

begin_comment
comment|/* Lock spare ECC generation */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_MAIN_ECC_LOCK
value|(1<<5)
end_define

begin_comment
comment|/* Lock main ECC generation */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_INIT_ECC
value|(1<<4)
end_define

begin_comment
comment|/* Init ECC encoder/decoder */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_NCE
value|(1<<1)
end_define

begin_comment
comment|/* NAND Chip select */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NFCONT_ENABLE
value|(1<<0)
end_define

begin_comment
comment|/* Enable the controller */
end_comment

begin_define
define|#
directive|define
name|S3C2440_NANDFC_NFCMMD
value|0x08
end_define

begin_define
define|#
directive|define
name|S3C2440_NANDFC_NFADDR
value|0x0c
end_define

begin_define
define|#
directive|define
name|S3C2440_NANDFC_NFDATA
value|0x10
end_define

begin_define
define|#
directive|define
name|S3C2440_NANDFC_NFSTAT
value|0x20
end_define

begin_comment
comment|/* MMC/SD */
end_comment

begin_comment
comment|/* SDI_CON */
end_comment

begin_define
define|#
directive|define
name|S3C2440_CON_RESET
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|S3C2440_CON_CLOCK_TYPE
value|(1<<5)
end_define

begin_comment
comment|/* SDI_FSTA */
end_comment

begin_define
define|#
directive|define
name|S3c2440_FSTA_RESET
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|S3C2440_FSTA_FAIL_ERROR_MSK
value|(3<<14)
end_define

begin_define
define|#
directive|define
name|S3C2440_FSTA_FAIL_NONE
value|(0<<14)
end_define

begin_define
define|#
directive|define
name|S3C2440_FSTA_FAIL_FIFO
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|S3C2440_FSTA_FAIL_LAST_TRANS
value|(2<<14)
end_define

begin_comment
comment|/* GPIO */
end_comment

begin_define
define|#
directive|define
name|S3C2440_GPIO_SIZE
value|0xd0
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
name|DCON_START
value|(1<<14)
end_define

begin_comment
comment|/* Start the data transfer */
end_comment

begin_define
define|#
directive|define
name|S3C2440_SDI_IMSK
value|0x3c
end_define

begin_comment
comment|/* Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|S3C2440_SDI_IMASK_ALL
value|0x3C7C0
end_define

begin_define
define|#
directive|define
name|S3C2440_SDI_DAT
value|0x40
end_define

begin_comment
comment|/* ADC */
end_comment

begin_define
define|#
directive|define
name|ADCTSC_UD_SEN
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|S3C2440_ADC_SIZE
value|0x18
end_define

begin_comment
comment|/* UART */
end_comment

begin_define
define|#
directive|define
name|S3C2440_UFSTAT_TXCOUNT
value|(0x3f<< 8)
end_define

begin_define
define|#
directive|define
name|S3C2440_UFSTAT_RXCOUNT
value|(0x3f<< 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_S3C2XX0_S3C2440REG_H_ */
end_comment

end_unit

