begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Jared McNeill<jmcneill@invisible.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Ingenic JZ4780 SMB Controller  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__JZ4780_SMB_H__
end_ifndef

begin_define
define|#
directive|define
name|__JZ4780_SMB_H__
end_define

begin_define
define|#
directive|define
name|SMBCON
value|0x00
end_define

begin_define
define|#
directive|define
name|SMBCON_STPHLD
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SMBCON_SLVDIS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SMBCON_REST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SMBCON_MATP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SMBCON_SATP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SMBCON_SPD
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|SMBCON_SPD_STANDARD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SMBCON_SPD_FAST
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|SMBCON_MD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SMBTAR
value|0x04
end_define

begin_define
define|#
directive|define
name|SMBTAR_MATP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SMBTAR_SPECIAL
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SMBTAR_GC_OR_START
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SMBTAR_SMBTAR
value|(0x3ff<< 0)
end_define

begin_define
define|#
directive|define
name|SMBSAR
value|0x08
end_define

begin_define
define|#
directive|define
name|SMBDC
value|0x10
end_define

begin_define
define|#
directive|define
name|SMBDC_CMD
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SMBDC_DAT
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|SMBSHCNT
value|0x14
end_define

begin_define
define|#
directive|define
name|SMBSLCNT
value|0x18
end_define

begin_define
define|#
directive|define
name|SMBFHCNT
value|0x1c
end_define

begin_define
define|#
directive|define
name|SMBFLCNT
value|0x20
end_define

begin_define
define|#
directive|define
name|SMBINTST
value|0x2c
end_define

begin_define
define|#
directive|define
name|SMBINTM
value|0x30
end_define

begin_define
define|#
directive|define
name|SMBRXTL
value|0x38
end_define

begin_define
define|#
directive|define
name|SMBTXTL
value|0x3c
end_define

begin_define
define|#
directive|define
name|SMBCINT
value|0x40
end_define

begin_define
define|#
directive|define
name|SMBCRXUF
value|0x44
end_define

begin_define
define|#
directive|define
name|SMBCRXOF
value|0x48
end_define

begin_define
define|#
directive|define
name|SMBCTXOF
value|0x4c
end_define

begin_define
define|#
directive|define
name|SMBCRXREQ
value|0x50
end_define

begin_define
define|#
directive|define
name|SMBCTXABT
value|0x54
end_define

begin_define
define|#
directive|define
name|SMBCRXDN
value|0x58
end_define

begin_define
define|#
directive|define
name|SMBCACT
value|0x5c
end_define

begin_define
define|#
directive|define
name|SMBCSTP
value|0x60
end_define

begin_define
define|#
directive|define
name|SMBCSTT
value|0x64
end_define

begin_define
define|#
directive|define
name|SMBCGC
value|0x68
end_define

begin_define
define|#
directive|define
name|SMBENB
value|0x6c
end_define

begin_define
define|#
directive|define
name|SMBENB_SMBENB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SMBST
value|0x70
end_define

begin_define
define|#
directive|define
name|SMBST_SLVACT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SMBST_MSTACT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SMBST_RFF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SMBST_RFNE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SMBST_TFE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SMBST_TFNF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SMBST_ACT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SMBABTSRC
value|0x80
end_define

begin_define
define|#
directive|define
name|SMBDMACR
value|0x88
end_define

begin_define
define|#
directive|define
name|SMBDMATDLR
value|0x8c
end_define

begin_define
define|#
directive|define
name|SMBDMARDLR
value|0x90
end_define

begin_define
define|#
directive|define
name|SMBSDASU
value|0x94
end_define

begin_define
define|#
directive|define
name|SMBACKGC
value|0x98
end_define

begin_define
define|#
directive|define
name|SMBENBST
value|0x9c
end_define

begin_define
define|#
directive|define
name|SMBENBST_SLVRDLST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SMBENBST_SLVDISB
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SMBENBST_SMBEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SMBSDAHD
value|0xd0
end_define

begin_define
define|#
directive|define
name|SMBSDAHD_HDENB
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SMBSDAHD_SDAHD
value|(0xff<< 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__JZ4780_SMB_H__ */
end_comment

end_unit

