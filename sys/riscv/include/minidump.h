begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Peter Wemm  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * From i386: FreeBSD:  157909 2006-04-21 04:28:43Z peter  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MINIDUMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MINIDUMP_H_
value|1
end_define

begin_define
define|#
directive|define
name|MINIDUMP_MAGIC
value|"minidump FreeBSD/riscv"
end_define

begin_define
define|#
directive|define
name|MINIDUMP_VERSION
value|1
end_define

begin_struct
struct|struct
name|minidumphdr
block|{
name|char
name|magic
index|[
literal|24
index|]
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|msgbufsize
decl_stmt|;
name|uint32_t
name|bitmapsize
decl_stmt|;
name|uint32_t
name|pmapsize
decl_stmt|;
name|uint64_t
name|kernbase
decl_stmt|;
name|uint64_t
name|dmapphys
decl_stmt|;
name|uint64_t
name|dmapbase
decl_stmt|;
name|uint64_t
name|dmapend
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MINIDUMP_H_ */
end_comment

end_unit

