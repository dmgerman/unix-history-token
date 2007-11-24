begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsnode.h	8.9 (Berkeley) 5/14/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFSNODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFSNODE_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_NFSCLIENT_NFS_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

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
name|int
function_decl|(
modifier|*
name|s_removeit
function_decl|)
parameter_list|(
name|struct
name|sillyrename
modifier|*
name|sp
parameter_list|)
function_decl|;
name|long
name|s_namlen
decl_stmt|;
name|char
name|s_name
index|[
literal|32
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
union|union
block|{
name|nfsuint64
name|ndmu3_cookies
index|[
name|NFSNUMCOOKIES
index|]
decl_stmt|;
name|uint64_t
name|ndmu4_cookies
index|[
name|NFSNUMCOOKIES
index|]
decl_stmt|;
block|}
name|ndm_un1
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ndm_cookies
value|ndm_un1.ndmu3_cookies
end_define

begin_define
define|#
directive|define
name|ndm4_cookies
value|ndm_un1.ndmu4_cookies
end_define

begin_comment
comment|/*  * The nfsnode is the nfs equivalent to ufs's inode. Any similarity  * is purely coincidental.  * There is a unique nfsnode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An nfsnode is 'named' by its file handle. (nget/nfs_node.c)  * If this structure exceeds 256 bytes (it is currently 256 using 4.4BSD-Lite  * type definitions), file handles of> 32 bytes should probably be split out  * into a separate MALLOC()'d data structure. (Reduce the size of nfsfh_t by  * changing the definition in nfsproto.h of NFS_SMALLFH.)  * NB: Hopefully the current order of the fields is such that everything will  *     be well aligned and, therefore, tightly packed.  */
end_comment

begin_struct
struct|struct
name|nfsnode
block|{
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
name|u_int32_t
name|n_mode
decl_stmt|;
comment|/* ACCESS mode cache */
name|uid_t
name|n_modeuid
decl_stmt|;
comment|/* credentials having mode */
name|time_t
name|n_modestamp
decl_stmt|;
comment|/* mode cache timestamp */
name|struct
name|timespec
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
name|vnode
modifier|*
name|n_dvp
decl_stmt|;
comment|/* parent vnode */
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
name|u_char
name|nd4_cookieverf
index|[
name|NFSX_V4VERF
index|]
decl_stmt|;
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
name|struct
name|lock
name|n_rslock
decl_stmt|;
name|struct
name|nfs4_fctx
name|n_rfc
decl_stmt|;
name|struct
name|nfs4_fctx
name|n_wfc
decl_stmt|;
name|u_char
modifier|*
name|n_name
decl_stmt|;
comment|/* leaf name, for v4 OPEN op */
name|uint32_t
name|n_namelen
decl_stmt|;
name|daddr_t
name|ra_expect_lbn
decl_stmt|;
name|int
name|n_directio_opens
decl_stmt|;
name|int
name|n_directio_asyncwr
decl_stmt|;
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
name|n4_cookieverf
value|n_un1.nd4_cookieverf
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

begin_comment
comment|/* 0x20, 0x40, 0x80 free */
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
name|NCREATED
value|0x0800
end_define

begin_comment
comment|/* Opened by nfs_create() */
end_comment

begin_define
define|#
directive|define
name|NTRUNCATE
value|0x1000
end_define

begin_comment
comment|/* Opened by nfs_setattr() */
end_comment

begin_define
define|#
directive|define
name|NSIZECHANGED
value|0x2000
end_define

begin_comment
comment|/* File size has changed: need cache inval */
end_comment

begin_define
define|#
directive|define
name|NNONCACHE
value|0x4000
end_define

begin_comment
comment|/* Node marked as noncacheable */
end_comment

begin_define
define|#
directive|define
name|NFSYNCWAIT
value|0x8000
end_define

begin_comment
comment|/* fsync waiting for all directio async writes  				   to drain */
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

begin_define
define|#
directive|define
name|NFS_TIMESPEC_COMPARE
parameter_list|(
name|T1
parameter_list|,
name|T2
parameter_list|)
value|(((T1)->tv_sec != (T2)->tv_sec) || ((T1)->tv_nsec != (T2)->tv_nsec))
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
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/*  *	nfs_rslock -	Attempt to obtain lock on nfsnode  *  *	Attempt to obtain a lock on the passed nfsnode, returning ENOLCK  *	if the lock could not be obtained due to our having to sleep.  This  *	function is generally used to lock around code that modifies an  *	NFS file's size.  In order to avoid deadlocks the lock  *	should not be obtained while other locks are being held.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|nfs_rslock
parameter_list|(
name|struct
name|nfsnode
modifier|*
name|np
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
return|return
operator|(
name|lockmgr
argument_list|(
operator|&
name|np
operator|->
name|n_rslock
argument_list|,
name|LK_EXCLUSIVE
operator||
name|LK_CANRECURSE
operator||
name|LK_SLEEPFAIL
argument_list|,
name|NULL
argument_list|,
name|td
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|nfs_rsunlock
parameter_list|(
name|struct
name|nfsnode
modifier|*
name|np
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
operator|(
name|void
operator|)
name|lockmgr
argument_list|(
operator|&
name|np
operator|->
name|n_rslock
argument_list|,
name|LK_RELEASE
argument_list|,
name|NULL
argument_list|,
name|td
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|nfs_fifoops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|nfs_vnodeops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|nfs4_vnodeops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|buf_ops
name|buf_ops_nfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|buf_ops
name|buf_ops_nfs4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes for NFS vnode operations  */
end_comment

begin_function_decl
name|int
name|nfs_getpages
parameter_list|(
name|struct
name|vop_getpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_putpages
parameter_list|(
name|struct
name|vop_putpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_write
parameter_list|(
name|struct
name|vop_write_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* other stuff */
end_comment

begin_function_decl
name|int
name|nfs_removeit
parameter_list|(
name|struct
name|sillyrename
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs4_removeit
parameter_list|(
name|struct
name|sillyrename
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_nget
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|nfsfh_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|nfsnode
modifier|*
modifier|*
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nfsuint64
modifier|*
name|nfs_getcookie
parameter_list|(
name|struct
name|nfsnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
modifier|*
name|nfs4_getcookie
parameter_list|(
name|struct
name|nfsnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_invaldir
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs4_invaldir
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

