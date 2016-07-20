begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2016 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* CLOOP format and related constants */
end_comment

begin_comment
comment|/*  * Integer values (block size, number of blocks, offsets)  * are stored in big-endian (network) order on disk.  */
end_comment

begin_define
define|#
directive|define
name|CLOOP_MAGIC_LEN
value|128
end_define

begin_define
define|#
directive|define
name|CLOOP_OFS_COMPR
value|0x0b
end_define

begin_define
define|#
directive|define
name|CLOOP_OFS_VERSN
value|(CLOOP_OFS_COMPR + 1)
end_define

begin_define
define|#
directive|define
name|CLOOP_MAJVER_2
value|'2'
end_define

begin_define
define|#
directive|define
name|CLOOP_MAJVER_3
value|'3'
end_define

begin_define
define|#
directive|define
name|CLOOP_COMP_LIBZ
value|'V'
end_define

begin_define
define|#
directive|define
name|CLOOP_COMP_LZMA
value|'L'
end_define

begin_struct
struct|struct
name|cloop_header
block|{
name|char
name|magic
index|[
name|CLOOP_MAGIC_LEN
index|]
decl_stmt|;
comment|/* cloop magic */
name|uint32_t
name|blksz
decl_stmt|;
comment|/* block size */
name|uint32_t
name|nblocks
decl_stmt|;
comment|/* number of blocks */
block|}
struct|;
end_struct

end_unit

