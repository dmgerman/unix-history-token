begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_SMBFS_NODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_SMBFS_NODE_H_
end_define

begin_define
define|#
directive|define
name|SMBFS_ROOT_INO
value|2
end_define

begin_comment
comment|/* just like in UFS */
end_comment

begin_comment
comment|/* Bits for smbnode.n_flag */
end_comment

begin_define
define|#
directive|define
name|NFLUSHINPROG
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFLUSHWANT
value|0x0002
end_define

begin_comment
comment|/* they should gone ... */
end_comment

begin_define
define|#
directive|define
name|NMODIFIED
value|0x0004
end_define

begin_comment
comment|/* bogus, until async IO implemented */
end_comment

begin_comment
comment|/*efine	NNEW			0x0008*/
end_comment

begin_comment
comment|/* smb/vnode has been allocated */
end_comment

begin_define
define|#
directive|define
name|NREFPARENT
value|0x0010
end_define

begin_comment
comment|/* node holds parent from recycling */
end_comment

begin_struct_decl
struct_decl|struct
name|smbfs_fctx
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|smbnode
block|{
name|struct
name|lock
name|n_lock
decl_stmt|;
comment|/* smbnode lock. (mbf) */
name|int
name|n_flag
decl_stmt|;
name|struct
name|smbnode
modifier|*
name|n_parent
decl_stmt|;
name|struct
name|vnode
modifier|*
name|n_vnode
decl_stmt|;
name|struct
name|smbmount
modifier|*
name|n_mount
decl_stmt|;
name|time_t
name|n_attrage
decl_stmt|;
comment|/* attributes cache time */
comment|/*	time_t			n_ctime;*/
name|struct
name|timespec
name|n_mtime
decl_stmt|;
comment|/* modify time */
name|struct
name|timespec
name|n_atime
decl_stmt|;
comment|/* last access time */
name|u_quad_t
name|n_size
decl_stmt|;
name|long
name|n_ino
decl_stmt|;
name|int
name|n_dosattr
decl_stmt|;
name|int
name|n_opencount
decl_stmt|;
name|u_int16_t
name|n_fid
decl_stmt|;
comment|/* file handle */
name|int
name|n_rwstate
decl_stmt|;
comment|/* granted access mode */
name|u_char
name|n_nmlen
decl_stmt|;
name|u_char
modifier|*
name|n_name
decl_stmt|;
name|struct
name|smbfs_fctx
modifier|*
name|n_dirseq
decl_stmt|;
comment|/* ff context */
name|long
name|n_dirofs
decl_stmt|;
comment|/* last ff offset */
name|struct
name|lockf
modifier|*
name|n_lockf
decl_stmt|;
comment|/* Locking records of file */
name|LIST_ENTRY
argument_list|(
argument|smbnode
argument_list|)
name|n_hash
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTOSMB
parameter_list|(
name|vp
parameter_list|)
value|((struct smbnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|SMBTOV
parameter_list|(
name|np
parameter_list|)
value|((struct vnode *)(np)->n_vnode)
end_define

begin_struct_decl
struct_decl|struct
name|vop_getpages_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_inactive_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_putpages_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_reclaim_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smbfattr
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|smbfs_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_nget
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|nmlen
parameter_list|,
name|struct
name|smbfattr
modifier|*
name|fap
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|smbfs_hash
parameter_list|(
specifier|const
name|u_char
modifier|*
name|name
parameter_list|,
name|int
name|nmlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_getpages
parameter_list|(
name|struct
name|vop_getpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_putpages
parameter_list|(
name|struct
name|vop_putpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_readvnode
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
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
name|smbfs_writevnode
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smbfs_attr_cacheenter
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|smbfattr
modifier|*
name|fap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_attr_cachelookup
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|vattr
modifier|*
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|smbfs_attr_cacheremove
parameter_list|(
name|vp
parameter_list|)
value|VTOSMB(vp)->n_attrage = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FS_SMBFS_NODE_H_ */
end_comment

end_unit

