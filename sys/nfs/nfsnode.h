begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsnode.h	8.4 (Berkeley) 2/13/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSNODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSNODE_H_
end_define

begin_comment
comment|/*  * Silly rename structure that hangs off the nfsnode until the name  * can be removed by nfs_inactive()  */
end_comment

begin_struct
struct|struct
name|sillyrename
block|{
name|struct
name|ucred
modifier|*
name|s_cred
decl_stmt|;
name|struct
name|vnode
modifier|*
name|s_dvp
decl_stmt|;
name|long
name|s_namlen
decl_stmt|;
name|char
name|s_name
index|[
literal|20
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The nfsnode is the nfs equivalent to ufs's inode. Any similarity  * is purely coincidental.  * There is a unique nfsnode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An nfsnode is 'named' by its file handle. (nget/nfs_node.c)  */
end_comment

begin_struct
struct|struct
name|nfsnode
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsnode
argument_list|)
name|n_hash
expr_stmt|;
comment|/* Hash chain */
name|CIRCLEQ_ENTRY
argument_list|(
argument|nfsnode
argument_list|)
name|n_timer
expr_stmt|;
comment|/* Nqnfs timer chain */
name|nfsv2fh_t
name|n_fh
decl_stmt|;
comment|/* NFS File Handle */
name|long
name|n_flag
decl_stmt|;
comment|/* Flag for locking.. */
name|struct
name|vnode
modifier|*
name|n_vnode
decl_stmt|;
comment|/* vnode associated with this node */
name|struct
name|vattr
name|n_vattr
decl_stmt|;
comment|/* Vnode attribute cache */
name|time_t
name|n_attrstamp
decl_stmt|;
comment|/* Time stamp for cached attributes */
name|struct
name|sillyrename
modifier|*
name|n_sillyrename
decl_stmt|;
comment|/* Ptr to silly rename struct */
name|u_quad_t
name|n_size
decl_stmt|;
comment|/* Current size of file */
name|struct
name|lockf
modifier|*
name|n_lockf
decl_stmt|;
comment|/* Locking record of file */
name|int
name|n_error
decl_stmt|;
comment|/* Save write error value */
name|u_long
name|n_direofoffset
decl_stmt|;
comment|/* Dir. EOF offset cache */
name|time_t
name|n_mtime
decl_stmt|;
comment|/* Prev modify time. */
name|time_t
name|n_ctime
decl_stmt|;
comment|/* Prev create time. */
name|u_quad_t
name|n_brev
decl_stmt|;
comment|/* Modify rev when cached */
name|u_quad_t
name|n_lrev
decl_stmt|;
comment|/* Modify rev for lease */
name|time_t
name|n_expiry
decl_stmt|;
comment|/* Lease expiry time */
name|struct
name|sillyrename
name|n_silly
decl_stmt|;
comment|/* Silly rename struct */
name|struct
name|timeval
name|n_atim
decl_stmt|;
comment|/* Special file times */
name|struct
name|timeval
name|n_mtim
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for n_flag  */
end_comment

begin_define
define|#
directive|define
name|NFLUSHWANT
value|0x0001
end_define

begin_comment
comment|/* Want wakeup from a flush in prog. */
end_comment

begin_define
define|#
directive|define
name|NFLUSHINPROG
value|0x0002
end_define

begin_comment
comment|/* Avoid multiple calls to vinvalbuf() */
end_comment

begin_define
define|#
directive|define
name|NMODIFIED
value|0x0004
end_define

begin_comment
comment|/* Might have a modified buffer in bio */
end_comment

begin_define
define|#
directive|define
name|NWRITEERR
value|0x0008
end_define

begin_comment
comment|/* Flag write errors so close will know */
end_comment

begin_define
define|#
directive|define
name|NQNFSNONCACHE
value|0x0020
end_define

begin_comment
comment|/* Non-cachable lease */
end_comment

begin_define
define|#
directive|define
name|NQNFSWRITE
value|0x0040
end_define

begin_comment
comment|/* Write lease */
end_comment

begin_define
define|#
directive|define
name|NQNFSEVICTED
value|0x0080
end_define

begin_comment
comment|/* Has been evicted */
end_comment

begin_define
define|#
directive|define
name|NACC
value|0x0100
end_define

begin_comment
comment|/* Special file accessed */
end_comment

begin_define
define|#
directive|define
name|NUPD
value|0x0200
end_define

begin_comment
comment|/* Special file updated */
end_comment

begin_define
define|#
directive|define
name|NCHG
value|0x0400
end_define

begin_comment
comment|/* Special file times changed */
end_comment

begin_comment
comment|/*  * Convert between nfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTONFS
parameter_list|(
name|vp
parameter_list|)
value|((struct nfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|NFSTOV
parameter_list|(
name|np
parameter_list|)
value|((struct vnode *)(np)->n_vnode)
end_define

begin_comment
comment|/*  * Queue head for nfsiod's  */
end_comment

begin_macro
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|buf
argument_list|)
end_macro

begin_expr_stmt
name|nfs_bufq
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|fifo_nfsv2nodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|nfsv2_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|spec_nfsv2nodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|nfs_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_abortop
name|__P
argument_list|(
operator|(
expr|struct
name|vop_abortop_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vop_inactive_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_reclaim
name|__P
argument_list|(
operator|(
expr|struct
name|vop_reclaim_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_unlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_islocked
name|__P
argument_list|(
operator|(
expr|struct
name|vop_islocked_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* other stuff */
end_comment

begin_decl_stmt
name|int
name|nfs_removeit
name|__P
argument_list|(
operator|(
expr|struct
name|sillyrename
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_nget
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|nfsv2fh_t
operator|*
operator|,
expr|struct
name|nfsnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|nfs_lookitup
name|__P
argument_list|(
operator|(
expr|struct
name|sillyrename
operator|*
operator|,
name|nfsv2fh_t
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|nfs_sillyrename
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|componentname
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

