begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ufs_extern.h	8.10 (Berkeley) 5/14/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_EXTERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_EXTERN_H_
end_define

begin_struct_decl
struct_decl|struct
name|componentname
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|direct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|indir
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|netcred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ufid
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vfsconf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_bmap_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_cachedlookup_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_generic_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_inactive_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_reclaim_args
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ufs_vnoperate
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_vnoperatefifo
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_vnoperatespec
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_bmap
parameter_list|(
name|struct
name|vop_bmap_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_bmaparray
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|ufs2_daddr_t
parameter_list|,
name|ufs2_daddr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_fhtovp
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|ufid
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_checkpath
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_dirbad
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|doff_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_dirbadentry
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_dirempty
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_makedirentry
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_direnter
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_dirremove
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_dirrewrite
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_getlbns
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|ufs2_daddr_t
parameter_list|,
name|struct
name|indir
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_ihashget
parameter_list|(
name|dev_t
parameter_list|,
name|ino_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_ihashinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_ihashins
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnode
modifier|*
name|ufs_ihashlookup
parameter_list|(
name|dev_t
parameter_list|,
name|ino_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_ihashrem
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_ihashuninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_init
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufs_itimes
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
name|ufs_lookup
parameter_list|(
name|struct
name|vop_cachedlookup_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_readdir
parameter_list|(
name|struct
name|vop_readdir_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_snapgone
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_root
parameter_list|(
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

begin_function_decl
name|int
name|ufs_start
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_uninit
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufs_vinit
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|vop_t
modifier|*
modifier|*
parameter_list|,
name|vop_t
modifier|*
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Soft update function prototypes.  */
end_comment

begin_function_decl
name|int
name|softdep_setup_directory_add
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|ino_t
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|softdep_change_directoryentry_offset
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|softdep_setup_remove
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|softdep_setup_directory_change
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|softdep_change_linkcnt
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|softdep_releasefile
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|softdep_slowdown
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flags to low-level allocation routines. */
end_comment

begin_define
define|#
directive|define
name|BA_CLRBUF
value|0x01
end_define

begin_comment
comment|/* Request allocated buffer be cleared. */
end_comment

begin_define
define|#
directive|define
name|BA_SYNC
value|0x02
end_define

begin_comment
comment|/* Do all allocations synchronously. */
end_comment

begin_define
define|#
directive|define
name|BA_METAONLY
value|0x04
end_define

begin_comment
comment|/* Return indirect block buffer. */
end_comment

begin_define
define|#
directive|define
name|BA_NOWAIT
value|0x08
end_define

begin_comment
comment|/* do not sleep to await lock */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UFS_UFS_EXTERN_H_ */
end_comment

end_unit

