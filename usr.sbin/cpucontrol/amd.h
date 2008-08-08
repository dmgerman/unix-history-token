begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, 2008 Stanislav Sedov<stas@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMD_H
end_ifndef

begin_define
define|#
directive|define
name|AMD_H
end_define

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_decl_stmt
name|ucode_probe_t
name|amd_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ucode_update_t
name|amd_update
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|amd_fw_header
block|{
name|uint32_t
name|date
decl_stmt|;
comment|/* Update creation date. */
name|uint32_t
name|xz0
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|checksum
decl_stmt|;
comment|/* ucode checksum. */
name|uint32_t
name|xz1
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|signature
decl_stmt|;
comment|/* Low byte of cpuid(0). */
name|uint32_t
name|magic
decl_stmt|;
comment|/* 0x0Xaaaaaa */
name|uint32_t
name|xz2
index|[
literal|8
index|]
decl_stmt|;
block|}
name|amd_fw_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AMD_MAGIC
value|0xaaaaaa
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !AMD_H */
end_comment

end_unit

