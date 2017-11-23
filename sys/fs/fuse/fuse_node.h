begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007-2009 Google Inc. and Amit Singh  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *   * * Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above  *   copyright notice, this list of conditions and the following disclaimer  *   in the documentation and/or other materials provided with the  *   distribution.  * * Neither the name of Google Inc. nor the names of its  *   contributors may be used to endorse or promote products derived from  *   this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * Copyright (C) 2005 Csaba Henk.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FUSE_NODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_FUSE_NODE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|"fuse_file.h"
end_include

begin_define
define|#
directive|define
name|FN_REVOKED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FN_FLUSHINPROG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FN_FLUSHWANT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FN_SIZECHANGE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FN_DIRECTIO
value|0x00000200
end_define

begin_struct
struct|struct
name|fuse_vnode_data
block|{
comment|/** self **/
name|uint64_t
name|nid
decl_stmt|;
comment|/** parent **/
comment|/* XXXIP very likely to be stale, it's not updated in rename() */
name|uint64_t
name|parent_nid
decl_stmt|;
comment|/** I/O **/
name|struct
name|fuse_filehandle
name|fufh
index|[
name|FUFH_MAXTYPE
index|]
decl_stmt|;
comment|/** flags **/
name|uint32_t
name|flag
decl_stmt|;
comment|/** meta **/
name|struct
name|vattr
name|cached_attrs
decl_stmt|;
name|off_t
name|filesize
decl_stmt|;
name|uint64_t
name|nlookup
decl_stmt|;
name|enum
name|vtype
name|vtype
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTOFUD
parameter_list|(
name|vp
parameter_list|)
define|\
value|((struct fuse_vnode_data *)((vp)->v_data))
end_define

begin_define
define|#
directive|define
name|VTOI
parameter_list|(
name|vp
parameter_list|)
value|(VTOFUD(vp)->nid)
end_define

begin_define
define|#
directive|define
name|VTOVA
parameter_list|(
name|vp
parameter_list|)
value|(&(VTOFUD(vp)->cached_attrs))
end_define

begin_define
define|#
directive|define
name|VTOILLU
parameter_list|(
name|vp
parameter_list|)
value|((uint64_t)(VTOFUD(vp) ? VTOI(vp) : 0))
end_define

begin_define
define|#
directive|define
name|FUSE_NULL_ID
value|0
end_define

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|fuse_vnops
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|void
name|fuse_vnode_setparent
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|)
block|{
if|if
condition|(
name|dvp
operator|!=
name|NULL
operator|&&
name|vp
operator|->
name|v_type
operator|==
name|VDIR
condition|)
block|{
name|MPASS
argument_list|(
name|dvp
operator|->
name|v_type
operator|==
name|VDIR
argument_list|)
expr_stmt|;
name|VTOFUD
argument_list|(
name|vp
argument_list|)
operator|->
name|parent_nid
operator|=
name|VTOI
argument_list|(
name|dvp
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function_decl
name|void
name|fuse_vnode_destroy
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fuse_vnode_get
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|uint64_t
name|nodeid
parameter_list|,
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|enum
name|vtype
name|vtyp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fuse_vnode_open
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int32_t
name|fuse_open_flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fuse_vnode_refreshsize
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fuse_vnode_savesize
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fuse_vnode_setsize
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|off_t
name|newsize
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FUSE_NODE_H_ */
end_comment

end_unit

