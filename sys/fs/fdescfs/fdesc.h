begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fdesc.h	8.5 (Berkeley) 1/21/94  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_FDESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_FDESC_H_
end_define

begin_comment
comment|/* Private mount flags for fdescfs. */
end_comment

begin_define
define|#
directive|define
name|FMNT_UNMOUNTF
value|0x01
end_define

begin_define
define|#
directive|define
name|FMNT_LINRDLNKF
value|0x02
end_define

begin_struct
struct|struct
name|fdescmount
block|{
name|struct
name|vnode
modifier|*
name|f_root
decl_stmt|;
comment|/* Root node */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FD_ROOT
value|1
end_define

begin_define
define|#
directive|define
name|FD_DESC
value|3
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|Froot
block|,
name|Fdesc
block|}
name|fdntype
typedef|;
end_typedef

begin_struct
struct|struct
name|fdescnode
block|{
name|LIST_ENTRY
argument_list|(
argument|fdescnode
argument_list|)
name|fd_hash
expr_stmt|;
comment|/* Hash list */
name|struct
name|vnode
modifier|*
name|fd_vnode
decl_stmt|;
comment|/* Back ptr to vnode */
name|fdntype
name|fd_type
decl_stmt|;
comment|/* Type of this node */
name|unsigned
name|fd_fd
decl_stmt|;
comment|/* Fd to be dup'ed */
name|int
name|fd_ix
decl_stmt|;
comment|/* filesystem index */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|fdesc_hashmtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VFSTOFDESC
parameter_list|(
name|mp
parameter_list|)
value|((struct fdescmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOFDESC
parameter_list|(
name|vp
parameter_list|)
value|((struct fdescnode *)(vp)->v_data)
end_define

begin_decl_stmt
specifier|extern
name|vfs_init_t
name|fdesc_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vfs_uninit_t
name|fdesc_uninit
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|fdesc_allocvp
parameter_list|(
name|fdntype
parameter_list|,
name|unsigned
parameter_list|,
name|int
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_FDESC_H_ */
end_comment

end_unit

