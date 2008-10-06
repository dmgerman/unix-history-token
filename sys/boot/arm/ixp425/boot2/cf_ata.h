begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 John Hay.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_BOOT_CF_ATA_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_BOOT_CF_ATA_H
end_define

begin_define
define|#
directive|define
name|CF_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|CF_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|CF_FEATURE
value|0x01
end_define

begin_define
define|#
directive|define
name|CF_SECT_CNT
value|0x02
end_define

begin_define
define|#
directive|define
name|CF_SECT_NUM
value|0x03
end_define

begin_define
define|#
directive|define
name|CF_CYL_L
value|0x04
end_define

begin_define
define|#
directive|define
name|CF_CYL_H
value|0x05
end_define

begin_define
define|#
directive|define
name|CF_DRV_HEAD
value|0x06
end_define

begin_define
define|#
directive|define
name|CF_D_MASTER
value|0x00
end_define

begin_define
define|#
directive|define
name|CF_D_LBA
value|0x40
end_define

begin_define
define|#
directive|define
name|CF_D_IBM
value|0xa0
end_define

begin_define
define|#
directive|define
name|CF_STATUS
value|0x07
end_define

begin_define
define|#
directive|define
name|CF_S_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|CF_S_INDEX
value|0x02
end_define

begin_define
define|#
directive|define
name|CF_S_CORR
value|0x04
end_define

begin_define
define|#
directive|define
name|CF_S_DRQ
value|0x08
end_define

begin_define
define|#
directive|define
name|CF_S_DSC
value|0x10
end_define

begin_define
define|#
directive|define
name|CF_S_DWF
value|0x20
end_define

begin_define
define|#
directive|define
name|CF_S_READY
value|0x40
end_define

begin_define
define|#
directive|define
name|CF_S_BUSY
value|0x80
end_define

begin_define
define|#
directive|define
name|CF_COMMAND
value|0x07
end_define

begin_comment
comment|/* This is according to the appnote, but Sam use 0x1e in avila_ata.c */
end_comment

begin_define
define|#
directive|define
name|CF_ALT_STATUS
value|0x16
end_define

begin_define
define|#
directive|define
name|CF_ALT_DEV_CTR
value|0x16
end_define

begin_define
define|#
directive|define
name|CF_ALT_DEV_CTR2
value|0x1e
end_define

begin_define
define|#
directive|define
name|CF_A_IDS
value|0x02
end_define

begin_define
define|#
directive|define
name|CF_A_RESET
value|0x04
end_define

begin_define
define|#
directive|define
name|CF_A_4BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|AVILA_IDE_GPIN
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ARM_BOOT_CF_ATA_H */
end_comment

end_unit

