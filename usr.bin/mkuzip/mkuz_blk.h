begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2016 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|OFFSET_UNDEF
value|UINT64_MAX
end_define

begin_struct
struct|struct
name|mkuz_blk_info
block|{
name|uint64_t
name|offset
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|uint32_t
name|blkno
decl_stmt|;
name|unsigned
name|char
name|digest
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MKUZ_BLK_EOF
value|(void *)0x1
end_define

begin_define
define|#
directive|define
name|MKUZ_BLK_MORE
value|(void *)0x2
end_define

begin_struct
struct|struct
name|mkuz_blk
block|{
name|struct
name|mkuz_blk_info
name|info
decl_stmt|;
name|size_t
name|alen
decl_stmt|;
name|uint64_t
name|br_offset
decl_stmt|;
name|unsigned
name|char
name|data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|mkuz_blk
modifier|*
name|mkuz_blk_ctor
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

