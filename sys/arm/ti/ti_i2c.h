begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_I2C_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_I2C_H_
end_define

begin_comment
comment|/**  * Header file for the OMAP I2C driver.  *  * Simply contains register bit flags.  */
end_comment

begin_comment
comment|/*  * OMAP4 I2C Registers, Summary 1  */
end_comment

begin_define
define|#
directive|define
name|I2C_REG_IE
value|0x84
end_define

begin_define
define|#
directive|define
name|I2C_IE_XDR
value|(1UL<< 14)
end_define

begin_comment
comment|/* Transmit draining interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_RDR
value|(1UL<< 13)
end_define

begin_comment
comment|/* Receive draining interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_AAS
value|(1UL<< 9)
end_define

begin_comment
comment|/* Addressed as Slave interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_BF
value|(1UL<< 8)
end_define

begin_comment
comment|/* Bus Free interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_AERR
value|(1UL<< 7)
end_define

begin_comment
comment|/* Access Error interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_STC
value|(1UL<< 6)
end_define

begin_comment
comment|/* Start Condition interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_GC
value|(1UL<< 5)
end_define

begin_comment
comment|/* General Call interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_XRDY
value|(1UL<< 4)
end_define

begin_comment
comment|/* Transmit Data Ready interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_RRDY
value|(1UL<< 3)
end_define

begin_comment
comment|/* Receive Data Ready interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_ARDY
value|(1UL<< 2)
end_define

begin_comment
comment|/* Register Access Ready interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_NACK
value|(1UL<< 1)
end_define

begin_comment
comment|/* No Acknowledgment interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_IE_AL
value|(1UL<< 0)
end_define

begin_comment
comment|/* Arbitration Lost interrupt */
end_comment

begin_define
define|#
directive|define
name|I2C_REG_STAT
value|0x88
end_define

begin_define
define|#
directive|define
name|I2C_STAT_XDR
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_RDR
value|(1UL<< 13)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_BB
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_ROVR
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_XUDF
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_AAS
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_BF
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_AERR
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_STC
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_GC
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_XRDY
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_RRDY
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_ARDY
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_NACK
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|I2C_STAT_AL
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|I2C_REG_SYSS
value|0x90
end_define

begin_define
define|#
directive|define
name|I2C_SYSS_RDONE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|I2C_REG_BUF
value|0x94
end_define

begin_define
define|#
directive|define
name|I2C_BUF_RXFIFO_CLR
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|I2C_BUF_TXFIFO_CLR
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|I2C_BUF_RXTRSH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I2C_BUF_TRSH_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|I2C_REG_CNT
value|0x98
end_define

begin_define
define|#
directive|define
name|I2C_REG_DATA
value|0x9c
end_define

begin_define
define|#
directive|define
name|I2C_REG_CON
value|0xa4
end_define

begin_define
define|#
directive|define
name|I2C_CON_I2C_EN
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|I2C_CON_OPMODE_STD
value|(0UL<< 12)
end_define

begin_define
define|#
directive|define
name|I2C_CON_OPMODE_HS
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|I2C_CON_OPMODE_SCCB
value|(2UL<< 12)
end_define

begin_define
define|#
directive|define
name|I2C_CON_OPMODE_MASK
value|(3UL<< 13)
end_define

begin_define
define|#
directive|define
name|I2C_CON_I2C_STB
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|I2C_CON_MST
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|I2C_CON_TRX
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|I2C_CON_XSA
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|I2C_CON_XOA0
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|I2C_CON_XOA1
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|I2C_CON_XOA2
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|I2C_CON_XOA3
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|I2C_CON_STP
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|I2C_CON_STT
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|I2C_REG_OA0
value|0xa8
end_define

begin_define
define|#
directive|define
name|I2C_REG_SA
value|0xac
end_define

begin_define
define|#
directive|define
name|I2C_REG_PSC
value|0xb0
end_define

begin_define
define|#
directive|define
name|I2C_PSC_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|I2C_REG_SCLL
value|0xb4
end_define

begin_define
define|#
directive|define
name|I2C_SCLL_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|I2C_HSSCLL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I2C_REG_SCLH
value|0xb8
end_define

begin_define
define|#
directive|define
name|I2C_SCLH_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|I2C_HSSCLH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I2C_REG_SYSTEST
value|0xbc
end_define

begin_define
define|#
directive|define
name|I2C_REG_BUFSTAT
value|0xc0
end_define

begin_define
define|#
directive|define
name|I2C_BUFSTAT_FIFODEPTH_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|I2C_BUFSTAT_FIFODEPTH_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I2C_REG_OA1
value|0xc4
end_define

begin_define
define|#
directive|define
name|I2C_REG_OA2
value|0xc8
end_define

begin_define
define|#
directive|define
name|I2C_REG_OA3
value|0xcc
end_define

begin_define
define|#
directive|define
name|I2C_REG_ACTOA
value|0xd0
end_define

begin_define
define|#
directive|define
name|I2C_REG_SBLOCK
value|0xd4
end_define

begin_comment
comment|/*  * OMAP4 I2C Registers, Summary 2   */
end_comment

begin_define
define|#
directive|define
name|I2C_REG_REVNB_LO
value|0x00
end_define

begin_define
define|#
directive|define
name|I2C_REG_REVNB_HI
value|0x04
end_define

begin_define
define|#
directive|define
name|I2C_REG_SYSC
value|0x10
end_define

begin_define
define|#
directive|define
name|I2C_REG_SYSC_SRST
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|I2C_REG_STATUS_RAW
value|0x24
end_define

begin_define
define|#
directive|define
name|I2C_REG_STATUS
value|0x28
end_define

begin_define
define|#
directive|define
name|I2C_REG_IRQENABLE_SET
value|0x2C
end_define

begin_define
define|#
directive|define
name|I2C_REG_IRQENABLE_CLR
value|0x30
end_define

begin_define
define|#
directive|define
name|I2C_CLK
value|96000000UL
end_define

begin_comment
comment|/* 96MHz */
end_comment

begin_define
define|#
directive|define
name|I2C_ICLK
value|12000000UL
end_define

begin_comment
comment|/* 12MHz */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_I2C_H_ */
end_comment

end_unit

