begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsnode.h	8.9 (Berkeley) 5/14/95  * $Id: nfsnode.h,v 1.21 1997/05/19 14:36:51 dfr Exp $  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFS_H_
end_ifndef

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * This structure is used to save the logical directory offset to  * NFS cookie mappings.  * The mappings are stored in a list headed  * by n_cookies, as required.  * There is one mapping for each NFS_DIRBLKSIZ bytes of directory information  * stored in increasing logical offset byte order.  */
end_comment

begin_define
define|#
directive|define
name|NFSNUMCOOKIES
value|31
end_define

begin_struct
struct|struct
name|nfsdmap
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsdmap
argument_list|)
name|ndm_list
expr_stmt|;
name|int
name|ndm_eocookie
decl_stmt|;
name|nfsuint64
name|ndm_cookies
index|[
name|NFSNUMCOOKIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The nfsnode is the nfs equivalent to ufs's inode. Any similarity  * is purely coincidental.  * There is a unique nfsnode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An nfsnode is 'named' by its file handle. (nget/nfs_node.c)  * If this structure exceeds 256 bytes (it is currently 256 using 4.4BSD-Lite  * type definitions), file handles of> 32 bytes should probably be split out  * into a separate MALLOC()'d data structure. (Reduce the size of nfsfh_t by  * changing the definition in sys/mount.h of NFS_SMALLFH.)  * NB: Hopefully the current order of the fields is such that everything will  *     be well aligned and, therefore, tightly packed.  */
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
name|u_quad_t
name|n_size
decl_stmt|;
comment|/* Current size of file */
name|u_quad_t
name|n_brev
decl_stmt|;
comment|/* Modify rev when cached */
name|u_quad_t
name|n_lrev
decl_stmt|;
comment|/* Modify rev for lease */
name|struct
name|vattr
name|n_vattr
decl_stmt|;
comment|/* Vnode attribute cache */
name|time_t
name|n_attrstamp
decl_stmt|;
comment|/* Attr. cache timestamp */
name|time_t
name|n_mtime
decl_stmt|;
comment|/* Prev modify time. */
name|time_t
name|n_ctime
decl_stmt|;
comment|/* Prev create time. */
name|time_t
name|n_expiry
decl_stmt|;
comment|/* Lease expiry time */
name|nfsfh_t
modifier|*
name|n_fhp
decl_stmt|;
comment|/* NFS File Handle */
name|struct
name|vnode
modifier|*
name|n_vnode
decl_stmt|;
comment|/* associated vnode */
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
union|union
block|{
name|struct
name|timespec
name|nf_atim
decl_stmt|;
comment|/* Special file times */
name|nfsuint64
name|nd_cookieverf
decl_stmt|;
comment|/* Cookie verifier (dir only) */
block|}
name|n_un1
union|;
union|union
block|{
name|struct
name|timespec
name|nf_mtim
decl_stmt|;
name|off_t
name|nd_direof
decl_stmt|;
comment|/* Dir. EOF offset cache */
block|}
name|n_un2
union|;
union|union
block|{
name|struct
name|sillyrename
modifier|*
name|nf_silly
decl_stmt|;
comment|/* Ptr to silly rename struct */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfsdmap
argument_list|)
name|nd_cook
expr_stmt|;
comment|/* cookies */
block|}
name|n_un3
union|;
name|short
name|n_fhsize
decl_stmt|;
comment|/* size in bytes, of fh */
name|short
name|n_flag
decl_stmt|;
comment|/* Flag for locking.. */
name|nfsfh_t
name|n_fh
decl_stmt|;
comment|/* Small File Handle */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|n_atim
value|n_un1.nf_atim
end_define

begin_define
define|#
directive|define
name|n_mtim
value|n_un2.nf_mtim
end_define

begin_define
define|#
directive|define
name|n_sillyrename
value|n_un3.nf_silly
end_define

begin_define
define|#
directive|define
name|n_cookieverf
value|n_un1.nd_cookieverf
end_define

begin_define
define|#
directive|define
name|n_direofoffset
value|n_un2.nd_direof
end_define

begin_define
define|#
directive|define
name|n_cookies
value|n_un3.nd_cook
end_define

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

begin_define
define|#
directive|define
name|NLOCKED
value|0x0800
end_define

begin_comment
comment|/* node is locked */
end_comment

begin_define
define|#
directive|define
name|NWANTED
value|0x0100
end_define

begin_comment
comment|/* someone wants to lock */
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

begin_extern
extern|extern TAILQ_HEAD(nfs_bufq
operator|,
extern|buf
end_extern

begin_expr_stmt
unit|)
name|nfs_bufq
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|nfs_iodwant
index|[
name|NFS_MAXASYNCDAEMON
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nfsmount
modifier|*
name|nfs_iodmount
index|[
name|NFS_MAXASYNCDAEMON
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|fifo_nfsv2nodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|nfsv2_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|spec_nfsv2nodeop_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes for NFS vnode operations  */
end_comment

begin_decl_stmt
name|int
name|nfs_getpages
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getpages_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|nfs_lease_check
value|((int (*) __P((struct  vop_lease_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|nqnfs_vop_lease_check
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lease_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nfs_revoke
value|vop_revoke
end_define

begin_define
define|#
directive|define
name|nfs_seek
value|((int (*) __P((struct  vop_seek_args *)))nullop)
end_define

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

begin_define
define|#
directive|define
name|nfs_lock
value|((int (*) __P((struct vop_lock_args *)))vop_sharedlock)
end_define

begin_define
define|#
directive|define
name|nfs_unlock
value|((int (*) __P((struct vop_unlock_args *)))vop_nounlock)
end_define

begin_define
define|#
directive|define
name|nfs_islocked
value|((int (*) __P((struct vop_islocked_args *)))vop_noislocked)
end_define

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
name|nfsfh_t
operator|*
operator|,
name|int
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
name|nfsuint64
modifier|*
name|nfs_getcookie
name|__P
argument_list|(
operator|(
expr|struct
name|nfsnode
operator|*
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfs_invaldir
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nqnfs_lease_updatetime
value|nfs_lease_updatetime
end_define

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

