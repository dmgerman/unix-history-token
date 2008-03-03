begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Juniper Networks  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IC_QUICC_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IC_QUICC_H_
end_define

begin_comment
comment|/*  * Device parameter RAM  */
end_comment

begin_define
define|#
directive|define
name|QUICC_PRAM_BASE
value|0x8000
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_REV_NUM
value|(QUICC_PRAM_BASE + 0xaf0)
end_define

begin_comment
comment|/* SCC parameter RAM. */
end_comment

begin_define
define|#
directive|define
name|QUICC_PRAM_SIZE_SCC
value|256
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_BASE_SCC
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE + QUICC_PRAM_SIZE_SCC * (u))
end_define

begin_comment
comment|/* SCC parameters that are common for all modes. */
end_comment

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_RBASE
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x00)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_TBASE
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x02)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_RFCR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x04)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_TFCR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x05)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_MRBLR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x06)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_RBPTR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x10)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_TBPTR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x20)
end_define

begin_comment
comment|/*  * SCC parameters that are specific to UART/ASYNC mode.  */
end_comment

begin_define
define|#
directive|define
name|QUICC_PRAM_SIZE_SCC_UART
value|0x68
end_define

begin_comment
comment|/* Rounded up. */
end_comment

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_MAX_IDL
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x38)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_IDLC
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x3a)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_BRKCR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x3c)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_PAREC
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x3e)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_FRMEC
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x40)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_NOSEC
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x42)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_BRKEC
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x44)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_BRKLN
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x46)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_UADDR1
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x48)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_UADDR2
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x4a)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_TOSEQ
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x4e)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_CC
parameter_list|(
name|u
parameter_list|,
name|n
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x50 + (n)*2)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_RCCM
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x60)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_RCCR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x62)
end_define

begin_define
define|#
directive|define
name|QUICC_PRAM_SCC_UART_RLBC
parameter_list|(
name|u
parameter_list|)
value|(QUICC_PRAM_BASE_SCC(u) + 0x64)
end_define

begin_comment
comment|/*  * Interrupt controller.  */
end_comment

begin_define
define|#
directive|define
name|QUICC_REG_SICR
value|0x10c00
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SIVEC
value|0x10c04
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SIPNR_H
value|0x10c08
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SIPNR_L
value|0x10c0c
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCPRR_H
value|0x10c14
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCPRR_L
value|0x10c18
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SIMR_H
value|0x10c1c
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SIMR_L
value|0x10c20
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SIEXR
value|0x10c24
end_define

begin_comment
comment|/*  * System clock control register.  */
end_comment

begin_define
define|#
directive|define
name|QUICC_REG_SCCR
value|0x10c80
end_define

begin_comment
comment|/*  * Baudrate generator registers.  */
end_comment

begin_define
define|#
directive|define
name|QUICC_REG_BRG
parameter_list|(
name|u
parameter_list|)
value|(0x119f0 + ((u)& 3) * 4 - ((u)& 4) * 0x100)
end_define

begin_comment
comment|/*  * SCC registers.  */
end_comment

begin_define
define|#
directive|define
name|QUICC_REG_SIZE_SCC
value|0x20
end_define

begin_define
define|#
directive|define
name|QUICC_REG_BASE_SCC
parameter_list|(
name|u
parameter_list|)
value|(0x11a00 + QUICC_REG_SIZE_SCC * (u))
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_GSMR_L
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x00)
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_GSMR_H
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x04)
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_PSMR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x08)
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_TODR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x0c)
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_DSR
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x0e)
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_SCCE
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x10)
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_SCCM
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x14)
end_define

begin_define
define|#
directive|define
name|QUICC_REG_SCC_SCCS
parameter_list|(
name|u
parameter_list|)
value|(QUICC_REG_BASE_SCC(u) + 0x17)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_IC_QUICC_H_ */
end_comment

end_unit

