begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: buf.h,v 1.3 2001/11/02 03:12:49 lukem Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Luke Mewburn for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FFS_BUF_H
end_ifndef

begin_define
define|#
directive|define
name|_FFS_BUF_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|vnode
block|{
name|int
name|fd
decl_stmt|;
name|void
modifier|*
name|fs
decl_stmt|;
name|void
modifier|*
name|v_data
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|buf
block|{
name|void
modifier|*
name|b_data
decl_stmt|;
name|long
name|b_bufsize
decl_stmt|;
name|long
name|b_bcount
decl_stmt|;
name|daddr_t
name|b_blkno
decl_stmt|;
name|daddr_t
name|b_lblkno
decl_stmt|;
name|int
name|b_fd
decl_stmt|;
name|void
modifier|*
name|b_fs
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|buf
argument_list|)
name|b_tailq
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|bcleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bread
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|brelse
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|getblk
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bdwrite
parameter_list|(
name|bp
parameter_list|)
value|bwrite(bp)
end_define

begin_define
define|#
directive|define
name|clrbuf
parameter_list|(
name|bp
parameter_list|)
value|memset((bp)->b_data, 0, (u_int)(bp)->b_bcount)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFS_BUF_H */
end_comment

end_unit

