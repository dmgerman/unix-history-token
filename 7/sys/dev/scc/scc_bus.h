begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2006 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_SCC_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_SCC_BUS_H_
end_define

begin_include
include|#
directive|include
file|<sys/serial.h>
end_include

begin_include
include|#
directive|include
file|<serdev_if.h>
end_include

begin_define
define|#
directive|define
name|SCC_IVAR_CHANNEL
value|0
end_define

begin_define
define|#
directive|define
name|SCC_IVAR_CLASS
value|1
end_define

begin_define
define|#
directive|define
name|SCC_IVAR_CLOCK
value|2
end_define

begin_define
define|#
directive|define
name|SCC_IVAR_MODE
value|3
end_define

begin_define
define|#
directive|define
name|SCC_IVAR_REGSHFT
value|4
end_define

begin_define
define|#
directive|define
name|SCC_IVAR_HWMTX
value|5
end_define

begin_comment
comment|/* Hardware class -- the SCC type. */
end_comment

begin_define
define|#
directive|define
name|SCC_CLASS_SAB82532
value|0
end_define

begin_define
define|#
directive|define
name|SCC_CLASS_Z8530
value|1
end_define

begin_comment
comment|/* The possible modes supported by the SCC. */
end_comment

begin_define
define|#
directive|define
name|SCC_MODE_ASYNC
value|0x01
end_define

begin_define
define|#
directive|define
name|SCC_MODE_BISYNC
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_MODE_HDLC
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_SCC_BUS_H_ */
end_comment

end_unit

