begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/_task.h>
end_include

begin_comment
comment|/*  * Silly rename structure that hangs off the nfsnode until the name  * can be removed by nfs_inactive()  */
end_comment

begin_struct
struct|struct
name|sillyrename
block|{
name|struct
name|task
name|s_task
decl_stmt|;
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

begin_struct
struct|struct
name|nfs_accesscache
block|{
name|u_int32_t
name|mode
decl_stmt|;
comment|/* ACCESS mode cache */
name|uid_t
name|uid
decl_stmt|;
comment|/* credentials having mode */
name|time_t
name|stamp
decl_stmt|;
comment|/* mode cache timestamp */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The nfsnode is the nfs equivalent to ufs's inode. Any similarity  * is purely coincidental.  * There is a unique nfsnode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An nfsnode is 'named' by its file handle. (nget/nfs_node.c)  * If this structure exceeds 256 bytes (it is currently 256 using 4.4BSD-Lite  * type definitions), file handles of> 32 bytes should probably be split out  * into a separate MALLOC()'d data structure. (Reduce the size of nfsfh_t by  * changing the definition in nfsproto.h of NFS_SMALLFH.)  * NB: Hopefully the current order of the fields is such that everything will  *     be well aligned and, therefore, tightly packed.  */
end_comment

begin_struct
struct|struct
name|nfsnode
block|{
name|struct
name|mtx
name|n_mtx
decl_stmt|;
comment|/* Protects all of these members */
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
name|nfsvattr
name|n_vattr
decl_stmt|;
comment|/* Vnode attribute cache */
name|time_t
name|n_attrstamp
decl_stmt|;
comment|/* Attr. cache timestamp */
name|struct
name|nfs_accesscache
name|n_accesscache
index|[
name|NFS_ACCESSCACHESIZE
index|]
decl_stmt|;
name|struct
name|timespec
name|n_mtime
decl_stmt|;
comment|/* Prev modify time. */
name|struct
name|nfsfh
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
name|NFSX_VERF
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
name|u_int32_t
name|n_flag
decl_stmt|;
comment|/* Flag for locking.. */
name|int
name|n_directio_opens
decl_stmt|;
name|int
name|n_directio_asyncwr
decl_stmt|;
name|u_int64_t
name|n_change
decl_stmt|;
comment|/* old Change attribute */
name|struct
name|nfsv4node
modifier|*
name|n_v4
decl_stmt|;
comment|/* extra V4 stuff */
name|struct
name|ucred
modifier|*
name|n_writecred
decl_stmt|;
comment|/* Cred. for putpages */
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
name|NDIRCOOKIELK
value|0x00000001
end_define

begin_comment
comment|/* Lock to serialize access to directory cookies */
end_comment

begin_define
define|#
directive|define
name|NFSYNCWAIT
value|0x00000002
end_define

begin_comment
comment|/* fsync waiting for all directio async 				  writes to drain */
end_comment

begin_define
define|#
directive|define
name|NMODIFIED
value|0x00000004
end_define

begin_comment
comment|/* Might have a modified buffer in bio */
end_comment

begin_define
define|#
directive|define
name|NWRITEERR
value|0x00000008
end_define

begin_comment
comment|/* Flag write errors so close will know */
end_comment

begin_define
define|#
directive|define
name|NCREATED
value|0x00000010
end_define

begin_comment
comment|/* Opened by nfs_create() */
end_comment

begin_define
define|#
directive|define
name|NTRUNCATE
value|0x00000020
end_define

begin_comment
comment|/* Opened by nfs_setattr() */
end_comment

begin_define
define|#
directive|define
name|NSIZECHANGED
value|0x00000040
end_define

begin_comment
comment|/* File size has changed: need cache inval */
end_comment

begin_define
define|#
directive|define
name|NNONCACHE
value|0x00000080
end_define

begin_comment
comment|/* Node marked as noncacheable */
end_comment

begin_define
define|#
directive|define
name|NACC
value|0x00000100
end_define

begin_comment
comment|/* Special file accessed */
end_comment

begin_define
define|#
directive|define
name|NUPD
value|0x00000200
end_define

begin_comment
comment|/* Special file updated */
end_comment

begin_define
define|#
directive|define
name|NCHG
value|0x00000400
end_define

begin_comment
comment|/* Special file times changed */
end_comment

begin_define
define|#
directive|define
name|NDELEGMOD
value|0x00000800
end_define

begin_comment
comment|/* Modified delegation */
end_comment

begin_define
define|#
directive|define
name|NDELEGRECALL
value|0x00001000
end_define

begin_comment
comment|/* Recall in progress */
end_comment

begin_define
define|#
directive|define
name|NREMOVEINPROG
value|0x00002000
end_define

begin_comment
comment|/* Remove in progress */
end_comment

begin_define
define|#
directive|define
name|NREMOVEWANT
value|0x00004000
end_define

begin_comment
comment|/* Want notification that remove is done */
end_comment

begin_define
define|#
directive|define
name|NLOCK
value|0x00008000
end_define

begin_comment
comment|/* Sleep lock the node */
end_comment

begin_define
define|#
directive|define
name|NLOCKWANT
value|0x00010000
end_define

begin_comment
comment|/* Want the sleep lock */
end_comment

begin_define
define|#
directive|define
name|NNOLAYOUT
value|0x00020000
end_define

begin_comment
comment|/* Can't get a layout for this file */
end_comment

begin_define
define|#
directive|define
name|NWRITEOPENED
value|0x00040000
end_define

begin_comment
comment|/* Has been opened for writing */
end_comment

begin_define
define|#
directive|define
name|NHASBEENLOCKED
value|0x00080000
end_define

begin_comment
comment|/* Has been file locked. */
end_comment

begin_define
define|#
directive|define
name|NDSCOMMIT
value|0x00100000
end_define

begin_comment
comment|/* Commit is done via the DS. */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/*  * Prototypes for NFS vnode operations  */
end_comment

begin_function_decl
name|int
name|ncl_getpages
parameter_list|(
name|struct
name|vop_getpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_putpages
parameter_list|(
name|struct
name|vop_putpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_write
parameter_list|(
name|struct
name|vop_write_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_reclaim
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
name|ncl_removeit
parameter_list|(
name|struct
name|sillyrename
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_nget
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|u_int8_t
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nfsuint64
modifier|*
name|ncl_getcookie
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
name|ncl_invaldir
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_upgrade_vnlock
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_downgrade_vnlock
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_dircookie_lock
parameter_list|(
name|struct
name|nfsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_dircookie_unlock
parameter_list|(
name|struct
name|nfsnode
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

begin_comment
comment|/* _NFSCLIENT_NFSNODE_H_ */
end_comment

end_unit

