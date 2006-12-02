begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 The Regents of the University of California.  * Copyright (c) 1994 Jan-Simon Pendry.  * Copyright (c) 2005, 2006 Masanori Ozawa<ozawa@ongs.co.jp>, ONGS Inc.  * Copyright (c) 2006 Daichi Goto<daichi@freebsd.org>  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)union.h	8.9 (Berkeley) 12/10/94  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* copy method of attr from lower to upper */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_unionfs_copymode
block|{
name|UNIONFS_TRADITIONAL
init|=
literal|0
block|,
name|UNIONFS_TRANSPARENT
block|,
name|UNIONFS_MASQUERADE
block|}
name|unionfs_copymode
typedef|;
end_typedef

begin_struct
struct|struct
name|unionfs_mount
block|{
name|struct
name|vnode
modifier|*
name|um_lowervp
decl_stmt|;
comment|/* VREFed once */
name|struct
name|vnode
modifier|*
name|um_uppervp
decl_stmt|;
comment|/* VREFed once */
name|struct
name|vnode
modifier|*
name|um_rootvp
decl_stmt|;
comment|/* ROOT vnode */
name|unionfs_copymode
name|um_copymode
decl_stmt|;
name|uid_t
name|um_uid
decl_stmt|;
name|gid_t
name|um_gid
decl_stmt|;
name|u_short
name|um_udir
decl_stmt|;
name|u_short
name|um_ufile
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* unionfs status list */
end_comment

begin_struct
struct|struct
name|unionfs_node_status
block|{
name|LIST_ENTRY
argument_list|(
argument|unionfs_node_status
argument_list|)
name|uns_list
expr_stmt|;
comment|/* Status list */
name|lwpid_t
name|uns_tid
decl_stmt|;
comment|/* current thread id */
name|int
name|uns_node_flag
decl_stmt|;
comment|/* uns flag */
name|int
name|uns_lower_opencnt
decl_stmt|;
comment|/* open count of lower */
name|int
name|uns_upper_opencnt
decl_stmt|;
comment|/* open count of upper */
name|int
name|uns_lower_openmode
decl_stmt|;
comment|/* open mode of lower */
name|int
name|uns_lower_fdidx
decl_stmt|;
comment|/* open fdidx of lower */
name|int
name|uns_readdir_status
decl_stmt|;
comment|/* read status of readdir */
block|}
struct|;
end_struct

begin_comment
comment|/* union node status flags */
end_comment

begin_define
define|#
directive|define
name|UNS_OPENL_4_READDIR
value|0x01
end_define

begin_comment
comment|/* open lower layer for readdir */
end_comment

begin_comment
comment|/* A cache of vnode references */
end_comment

begin_struct
struct|struct
name|unionfs_node
block|{
name|LIST_ENTRY
argument_list|(
argument|unionfs_node
argument_list|)
name|un_hash
expr_stmt|;
comment|/* Hash list */
name|struct
name|vnode
modifier|*
name|un_lowervp
decl_stmt|;
comment|/* lower side vnode */
name|struct
name|vnode
modifier|*
name|un_uppervp
decl_stmt|;
comment|/* upper side vnode */
name|struct
name|vnode
modifier|*
name|un_dvp
decl_stmt|;
comment|/* parent unionfs vnode */
name|struct
name|vnode
modifier|*
name|un_vnode
decl_stmt|;
comment|/* Back pointer */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|unionfs_node_status
argument_list|)
name|un_unshead
expr_stmt|;
comment|/* unionfs status head */
name|char
modifier|*
name|un_path
decl_stmt|;
comment|/* path */
name|int
name|un_flag
decl_stmt|;
comment|/* unionfs node flag */
block|}
struct|;
end_struct

begin_comment
comment|/* unionfs node flags */
end_comment

begin_define
define|#
directive|define
name|UNIONFS_CACHED
value|0x01
end_define

begin_comment
comment|/* is cached */
end_comment

begin_define
define|#
directive|define
name|UNIONFS_OPENEXTL
value|0x02
end_define

begin_comment
comment|/* openextattr (lower) */
end_comment

begin_define
define|#
directive|define
name|UNIONFS_OPENEXTU
value|0x04
end_define

begin_comment
comment|/* openextattr (upper) */
end_comment

begin_define
define|#
directive|define
name|MOUNTTOUNIONFSMOUNT
parameter_list|(
name|mp
parameter_list|)
value|((struct unionfs_mount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOUNIONFS
parameter_list|(
name|vp
parameter_list|)
value|((struct unionfs_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|UNIONFSTOV
parameter_list|(
name|xp
parameter_list|)
value|((xp)->un_vnode)
end_define

begin_function_decl
name|int
name|unionfs_init
parameter_list|(
name|struct
name|vfsconf
modifier|*
name|vfsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_uninit
parameter_list|(
name|struct
name|vfsconf
modifier|*
name|vfsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_nodeget
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vnode
modifier|*
name|uppervp
parameter_list|,
name|struct
name|vnode
modifier|*
name|lowervp
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
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unionfs_hashrem
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
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
name|unionfs_get_node_status
parameter_list|(
name|struct
name|unionfs_node
modifier|*
name|unp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|unionfs_node_status
modifier|*
modifier|*
name|unspp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unionfs_tryrem_node_status
parameter_list|(
name|struct
name|unionfs_node
modifier|*
name|unp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|unionfs_node_status
modifier|*
name|unsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_check_rmdir
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
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_copyfile
parameter_list|(
name|struct
name|unionfs_node
modifier|*
name|unp
parameter_list|,
name|int
name|docopy
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
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
name|unionfs_create_uppervattr_core
parameter_list|(
name|struct
name|unionfs_mount
modifier|*
name|ump
parameter_list|,
name|struct
name|vattr
modifier|*
name|lva
parameter_list|,
name|struct
name|vattr
modifier|*
name|uva
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_create_uppervattr
parameter_list|(
name|struct
name|unionfs_mount
modifier|*
name|ump
parameter_list|,
name|struct
name|vnode
modifier|*
name|lvp
parameter_list|,
name|struct
name|vattr
modifier|*
name|uva
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_mkshadowdir
parameter_list|(
name|struct
name|unionfs_mount
modifier|*
name|ump
parameter_list|,
name|struct
name|vnode
modifier|*
name|duvp
parameter_list|,
name|struct
name|unionfs_node
modifier|*
name|unp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_mkwhiteout
parameter_list|(
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_relookup_for_create
parameter_list|(
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_relookup_for_delete
parameter_list|(
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unionfs_relookup_for_rename
parameter_list|(
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_function_decl
name|struct
name|vnode
modifier|*
name|unionfs_checklowervp
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|char
modifier|*
name|fil
parameter_list|,
name|int
name|lno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnode
modifier|*
name|unionfs_checkuppervp
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|char
modifier|*
name|fil
parameter_list|,
name|int
name|lno
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UNIONFSVPTOLOWERVP
parameter_list|(
name|vp
parameter_list|)
value|unionfs_checklowervp((vp), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|UNIONFSVPTOUPPERVP
parameter_list|(
name|vp
parameter_list|)
value|unionfs_checkuppervp((vp), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNIONFSVPTOLOWERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTOUNIONFS(vp)->un_lowervp)
end_define

begin_define
define|#
directive|define
name|UNIONFSVPTOUPPERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTOUNIONFS(vp)->un_uppervp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|unionfs_vnodeops
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_UNIONFSNODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_UNIONFSPATH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNIONFS_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|UNIONFSDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf(format ,## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNIONFSDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIONFS_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

