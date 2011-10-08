begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2000 Benno Rice.  * Copyright (C) 2007 Semihalf, Rafal Jaworowski<raj@semihalf.com>  * Copyright (C) 2011 glevand (geoffrey.levand@mail.ru)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PS3_DEV_DESC_H
end_ifndef

begin_define
define|#
directive|define
name|_PS3_DEV_DESC_H
end_define

begin_comment
comment|/* Note: Must match the 'struct devdesc' in bootstrap.h */
end_comment

begin_struct
struct|struct
name|ps3_devdesc
block|{
name|struct
name|devsw
modifier|*
name|d_dev
decl_stmt|;
name|int
name|d_type
decl_stmt|;
name|int
name|d_unit
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|pnum
decl_stmt|;
name|int
name|ptype
decl_stmt|;
block|}
name|disk
struct|;
block|}
name|d_kind
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|d_disk
value|d_kind.disk
end_define

begin_define
define|#
directive|define
name|PTYPE_BSDLABEL
value|1
end_define

begin_define
define|#
directive|define
name|PTYPE_GPT
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

