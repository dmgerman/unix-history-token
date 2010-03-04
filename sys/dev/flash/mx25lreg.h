begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MX25LREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__MX25LREG_H__
end_define

begin_comment
comment|/*  * Commands   */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE_ENABLE
value|0x06
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_DISABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|CMD_READ_IDENT
value|0x9F
end_define

begin_define
define|#
directive|define
name|CMD_READ_STATUS
value|0x05
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|CMD_READ
value|0x03
end_define

begin_define
define|#
directive|define
name|CMD_FAST_READ
value|0x0B
end_define

begin_define
define|#
directive|define
name|CMD_PAGE_PROGRAM
value|0x02
end_define

begin_define
define|#
directive|define
name|CMD_SECTOR_ERASE
value|0xD8
end_define

begin_define
define|#
directive|define
name|CMD_BULK_ERASE
value|0xC7
end_define

begin_comment
comment|/*  * Status register flags  */
end_comment

begin_define
define|#
directive|define
name|STATUS_SRWD
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|STATUS_BP2
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|STATUS_BP1
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|STATUS_BP0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|STATUS_WEL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|STATUS_WIP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FLASH_PAGE_SIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MX25LREG_H__ */
end_comment

end_unit

