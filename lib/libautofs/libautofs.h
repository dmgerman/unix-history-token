begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Alfred Perlstein<alfred@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  * $Id: libautofs.h,v 1.4 2004/09/08 08:12:21 bright Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBAUTOFS_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBAUTOFS_H
end_define

begin_struct_decl
struct_decl|struct
name|auto_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|auto_handle
modifier|*
name|autoh_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|autofs_userreq
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|autofs_userreq
modifier|*
name|autoreq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|autoino_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AUTO_INODE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|AUTO_DIRECT
value|1
end_define

begin_define
define|#
directive|define
name|AUTO_INDIRECT
value|2
end_define

begin_define
define|#
directive|define
name|AUTO_MOUNTER
value|3
end_define

begin_define
define|#
directive|define
name|AUTO_BROWSE
value|4
end_define

begin_enum
enum|enum
name|autoreq_op
block|{
name|AUTOREQ_OP_UNKNOWN
init|=
literal|0
block|,
name|AUTOREQ_OP_LOOKUP
block|,
name|AUTOREQ_OP_STAT
block|,
name|AUTOREQ_OP_READDIR
block|}
enum|;
end_enum

begin_comment
comment|/* get a handle based on a path. */
end_comment

begin_function_decl
name|int
name|autoh_get
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|autoh_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* release. */
end_comment

begin_function_decl
name|void
name|autoh_free
parameter_list|(
name|autoh_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get an array of pointers to handles for all autofs mounts, returns count  * or -1  */
end_comment

begin_function_decl
name|int
name|autoh_getall
parameter_list|(
name|autoh_t
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free the array of pointers */
end_comment

begin_function_decl
name|void
name|autoh_freeall
parameter_list|(
name|autoh_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return fd to select on. */
end_comment

begin_function_decl
name|int
name|autoh_fd
parameter_list|(
name|autoh_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* returns the mount point of the autofs instance. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|autoh_mp
parameter_list|(
name|autoh_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get an array of pending requests */
end_comment

begin_function_decl
name|int
name|autoreq_get
parameter_list|(
name|autoh_t
parameter_list|,
name|autoreq_t
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free an array of requests */
end_comment

begin_function_decl
name|void
name|autoreq_free
parameter_list|(
name|autoh_t
parameter_list|,
name|autoreq_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* serve a request */
end_comment

begin_function_decl
name|int
name|autoreq_serv
parameter_list|(
name|autoh_t
parameter_list|,
name|autoreq_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get the operation requested */
end_comment

begin_function_decl
name|enum
name|autoreq_op
name|autoreq_getop
parameter_list|(
name|autoreq_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get a request's file name. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|autoreq_getpath
parameter_list|(
name|autoreq_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get a request's inode.  a indirect mount may return AUTO_INODE_NONE. */
end_comment

begin_function_decl
name|autoino_t
name|autoreq_getino
parameter_list|(
name|autoreq_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * set a request's inode.  an indirect mount may return AUTO_INODE_NONE,  * this is a fixup for indirect mounts.  */
end_comment

begin_function_decl
name|void
name|autoreq_setino
parameter_list|(
name|autoreq_t
parameter_list|,
name|autoino_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get a request's directory inode. */
end_comment

begin_function_decl
name|autoino_t
name|autoreq_getdirino
parameter_list|(
name|autoreq_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|autoreq_seterrno
parameter_list|(
name|autoreq_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|autoreq_setaux
parameter_list|(
name|autoreq_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|autoreq_getaux
parameter_list|(
name|autoreq_t
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|autoreq_seteof
parameter_list|(
name|autoreq_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|autoreq_getoffset
parameter_list|(
name|autoreq_t
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|autoreq_getxid
parameter_list|(
name|autoreq_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* toggle by path. args = handle, AUTO_?, pid (-1 to disable), path. */
end_comment

begin_function_decl
name|int
name|autoh_togglepath
parameter_list|(
name|autoh_t
parameter_list|,
name|int
parameter_list|,
name|pid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* toggle by fd. args = handle, AUTO_?, pid (-1 to disable), fd. */
end_comment

begin_function_decl
name|int
name|autoh_togglefd
parameter_list|(
name|autoh_t
parameter_list|,
name|int
parameter_list|,
name|pid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

