begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Margarida Gouveia  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_WII_WII_PICREG_H
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_WII_WII_PICREG_H
end_define

begin_define
define|#
directive|define
name|WIIPIC_REG_ADDR
value|0x0c003000
end_define

begin_define
define|#
directive|define
name|WIIPIC_REG_LEN
value|0x08
end_define

begin_define
define|#
directive|define
name|WIIPIC_ICR
value|0x00
end_define

begin_define
define|#
directive|define
name|WIIPIC_IMR
value|0x04
end_define

begin_define
define|#
directive|define
name|WIIPIC_RESET
value|0x24
end_define

begin_define
define|#
directive|define
name|WIIPIC_NIRQ
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_WII_WII_PICREG_H */
end_comment

end_unit

