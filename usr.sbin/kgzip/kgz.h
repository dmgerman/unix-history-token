begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KGZ_H_
end_ifndef

begin_define
define|#
directive|define
name|_KGZ_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * KGZ definitions: kgzip(8) output.  */
end_comment

begin_comment
comment|/* Values for ident[]. */
end_comment

begin_define
define|#
directive|define
name|KGZ_ID0
value|'K'
end_define

begin_define
define|#
directive|define
name|KGZ_ID1
value|'G'
end_define

begin_define
define|#
directive|define
name|KGZ_ID2
value|'Z'
end_define

begin_define
define|#
directive|define
name|KGZ_ID3
value|'\0'
end_define

begin_comment
comment|/* KGZ header. */
end_comment

begin_struct
struct|struct
name|kgz_hdr
block|{
name|char
name|ident
index|[
literal|4
index|]
decl_stmt|;
comment|/* identification */
name|uint32_t
name|dload
decl_stmt|;
comment|/* decoded image load address */
name|uint32_t
name|dsize
decl_stmt|;
comment|/* decoded image size */
name|uint32_t
name|isize
decl_stmt|;
comment|/* image size in memory */
name|uint32_t
name|entry
decl_stmt|;
comment|/* program entry point */
name|uint32_t
name|nsize
decl_stmt|;
comment|/* encoded image size */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|kgz_hdr
name|kgz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header */
end_comment

begin_decl_stmt
specifier|extern
name|uint8_t
name|kgz_ndata
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* encoded image */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KGZ_H_ */
end_comment

end_unit

