begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Max Khon  * Copyright (c) 2014 Juniper Networks, Inc.  * Copyright (c) 2006-2016 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|g_uzip_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_expr_stmt
name|DEFINE_RAW_METHOD
argument_list|(
name|g_uzip_do
argument_list|,
name|void
argument_list|,
expr|struct
name|g_uzip_softc
operator|*
argument_list|,
expr|struct
name|bio
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|g_uzip_softc
block|{
name|uint32_t
name|blksz
decl_stmt|;
comment|/* block size */
name|uint32_t
name|nblocks
decl_stmt|;
comment|/* number of blocks */
name|struct
name|g_uzip_blk
modifier|*
name|toc
decl_stmt|;
comment|/* table of contents */
name|struct
name|mtx
name|last_mtx
decl_stmt|;
name|uint32_t
name|last_blk
decl_stmt|;
comment|/* last blk no */
name|char
modifier|*
name|last_buf
decl_stmt|;
comment|/* last blk data */
name|int
name|req_total
decl_stmt|;
comment|/* total requests */
name|int
name|req_cached
decl_stmt|;
comment|/* cached requests */
name|struct
name|g_uzip_dapi
modifier|*
name|dcp
decl_stmt|;
comment|/* decompressor instance */
name|g_uzip_do_t
name|uzip_do
decl_stmt|;
name|struct
name|proc
modifier|*
name|procp
decl_stmt|;
name|struct
name|bio_queue_head
name|bio_queue
decl_stmt|;
name|struct
name|mtx
name|queue_mtx
decl_stmt|;
name|unsigned
name|wrkthr_flags
decl_stmt|;
define|#
directive|define
name|GUZ_SHUTDOWN
value|(0x1<< 0)
define|#
directive|define
name|GUZ_EXITING
value|(0x1<< 1)
block|}
struct|;
end_struct

end_unit

