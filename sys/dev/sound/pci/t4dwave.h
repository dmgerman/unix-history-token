begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_T4DWAVE_REG_H
end_ifndef

begin_define
define|#
directive|define
name|_T4DWAVE_REG_H
end_define

begin_define
define|#
directive|define
name|TR_REG_CIR
value|0xa0
end_define

begin_define
define|#
directive|define
name|TR_CIR_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|TR_CIR_ADDRENA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TR_CIR_MIDENA
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TR_REG_MISCINT
value|0xb0
end_define

begin_define
define|#
directive|define
name|TR_INT_ADDR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TR_INT_SB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TR_REG_DMAR0
value|0x00
end_define

begin_define
define|#
directive|define
name|TR_REG_DMAR4
value|0x04
end_define

begin_define
define|#
directive|define
name|TR_REG_DMAR11
value|0x0b
end_define

begin_define
define|#
directive|define
name|TR_REG_DMAR15
value|0x0f
end_define

begin_define
define|#
directive|define
name|TR_REG_SBR4
value|0x14
end_define

begin_define
define|#
directive|define
name|TR_REG_SBR5
value|0x15
end_define

begin_define
define|#
directive|define
name|TR_SB_INTSTATUS
value|0x82
end_define

begin_define
define|#
directive|define
name|TR_REG_SBR9
value|0x1e
end_define

begin_define
define|#
directive|define
name|TR_REG_SBR10
value|0x1f
end_define

begin_define
define|#
directive|define
name|TR_REG_SBBL
value|0xc0
end_define

begin_define
define|#
directive|define
name|TR_REG_SBCTRL
value|0xc4
end_define

begin_define
define|#
directive|define
name|TR_REG_SBDELTA
value|0xac
end_define

begin_define
define|#
directive|define
name|TR_CDC_DATA
value|16
end_define

begin_define
define|#
directive|define
name|TDX_REG_CODECWR
value|0x40
end_define

begin_define
define|#
directive|define
name|TDX_REG_CODECRD
value|0x44
end_define

begin_define
define|#
directive|define
name|TDX_CDC_RWSTAT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TDX_REG_CODECST
value|0x48
end_define

begin_define
define|#
directive|define
name|TDX_CDC_SBCTRL
value|0x40
end_define

begin_define
define|#
directive|define
name|TDX_CDC_ACTIVE
value|0x20
end_define

begin_define
define|#
directive|define
name|TDX_CDC_READY
value|0x10
end_define

begin_define
define|#
directive|define
name|TDX_CDC_ADCON
value|0x08
end_define

begin_define
define|#
directive|define
name|TDX_CDC_DACON
value|0x02
end_define

begin_define
define|#
directive|define
name|TDX_CDC_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|TDX_CDC_ON
value|(TDX_CDC_ADCON|TDX_CDC_DACON)
end_define

begin_define
define|#
directive|define
name|SPA_REG_CODECRD
value|0x44
end_define

begin_define
define|#
directive|define
name|SPA_REG_CODECWR
value|0x40
end_define

begin_define
define|#
directive|define
name|SPA_REG_CODECST
value|0x48
end_define

begin_define
define|#
directive|define
name|SPA_RST_OFF
value|0x0f0000
end_define

begin_define
define|#
directive|define
name|SPA_REG_GPIO
value|0x48
end_define

begin_define
define|#
directive|define
name|SPA_CDC_RWSTAT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TNX_REG_CODECWR
value|0x44
end_define

begin_define
define|#
directive|define
name|TNX_REG_CODEC1RD
value|0x48
end_define

begin_define
define|#
directive|define
name|TNX_REG_CODEC2RD
value|0x4c
end_define

begin_define
define|#
directive|define
name|TNX_CDC_RWSTAT
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|TNX_CDC_SEC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TNX_REG_CODECST
value|0x40
end_define

begin_define
define|#
directive|define
name|TNX_CDC_READY2
value|0x40
end_define

begin_define
define|#
directive|define
name|TNX_CDC_ADC2ON
value|0x20
end_define

begin_define
define|#
directive|define
name|TNX_CDC_DAC2ON
value|0x10
end_define

begin_define
define|#
directive|define
name|TNX_CDC_READY1
value|0x08
end_define

begin_define
define|#
directive|define
name|TNX_CDC_ADC1ON
value|0x04
end_define

begin_define
define|#
directive|define
name|TNX_CDC_DAC1ON
value|0x02
end_define

begin_define
define|#
directive|define
name|TNX_CDC_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|TNX_CDC_ON
value|(TNX_CDC_ADC1ON|TNX_CDC_DAC1ON)
end_define

begin_define
define|#
directive|define
name|TR_REG_STARTA
value|0x80
end_define

begin_define
define|#
directive|define
name|TR_REG_STOPA
value|0x84
end_define

begin_define
define|#
directive|define
name|TR_REG_CSPF_A
value|0x90
end_define

begin_define
define|#
directive|define
name|TR_REG_ADDRINTA
value|0x98
end_define

begin_define
define|#
directive|define
name|TR_REG_INTENA
value|0xa4
end_define

begin_define
define|#
directive|define
name|TR_REG_STARTB
value|0xb4
end_define

begin_define
define|#
directive|define
name|TR_REG_STOPB
value|0xb8
end_define

begin_define
define|#
directive|define
name|TR_REG_CSPF_B
value|0xbc
end_define

begin_define
define|#
directive|define
name|TR_REG_ADDRINTB
value|0xd8
end_define

begin_define
define|#
directive|define
name|TR_REG_INTENB
value|0xdc
end_define

begin_define
define|#
directive|define
name|TR_REG_CHNBASE
value|0xe0
end_define

begin_define
define|#
directive|define
name|TR_CHN_REGS
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

