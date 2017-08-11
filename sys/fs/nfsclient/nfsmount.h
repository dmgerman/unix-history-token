begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFSMOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFSMOUNT_H_
end_define

begin_include
include|#
directive|include
file|<nfs/nfs_mountcommon.h>
end_include

begin_comment
comment|/*  * Mount structure.  * One allocated on every NFS mount.  * Holds NFS specific information for mount.  */
end_comment

begin_struct
struct|struct
name|nfsmount
block|{
name|struct
name|nfsmount_common
name|nm_com
decl_stmt|;
comment|/* Common fields for nlm */
name|uint32_t
name|nm_privflag
decl_stmt|;
comment|/* Private flags */
name|int
name|nm_numgrps
decl_stmt|;
comment|/* Max. size of groupslist */
name|u_char
name|nm_fh
index|[
name|NFSX_FHMAX
index|]
decl_stmt|;
comment|/* File handle of root dir */
name|int
name|nm_fhsize
decl_stmt|;
comment|/* Size of root file handle */
name|struct
name|nfssockreq
name|nm_sockreq
decl_stmt|;
comment|/* Socket Info */
name|int
name|nm_timeouts
decl_stmt|;
comment|/* Request timeouts */
name|int
name|nm_rsize
decl_stmt|;
comment|/* Max size of read rpc */
name|int
name|nm_wsize
decl_stmt|;
comment|/* Max size of write rpc */
name|int
name|nm_readdirsize
decl_stmt|;
comment|/* Size of a readdir rpc */
name|int
name|nm_readahead
decl_stmt|;
comment|/* Num. of blocks to readahead */
name|int
name|nm_wcommitsize
decl_stmt|;
comment|/* Max size of commit for write */
name|int
name|nm_acdirmin
decl_stmt|;
comment|/* Directory attr cache min lifetime */
name|int
name|nm_acdirmax
decl_stmt|;
comment|/* Directory attr cache max lifetime */
name|int
name|nm_acregmin
decl_stmt|;
comment|/* Reg file attr cache min lifetime */
name|int
name|nm_acregmax
decl_stmt|;
comment|/* Reg file attr cache max lifetime */
name|u_char
name|nm_verf
index|[
name|NFSX_VERF
index|]
decl_stmt|;
comment|/* write verifier */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|buf
argument_list|)
name|nm_bufq
expr_stmt|;
comment|/* async io buffer queue */
name|short
name|nm_bufqlen
decl_stmt|;
comment|/* number of buffers in queue */
name|short
name|nm_bufqwant
decl_stmt|;
comment|/* process wants to add to the queue */
name|int
name|nm_bufqiods
decl_stmt|;
comment|/* number of iods processing queue */
name|u_int64_t
name|nm_maxfilesize
decl_stmt|;
comment|/* maximum file size */
name|int
name|nm_tprintf_initial_delay
decl_stmt|;
comment|/* initial delay */
name|int
name|nm_tprintf_delay
decl_stmt|;
comment|/* interval for messages */
name|int
name|nm_nametimeo
decl_stmt|;
comment|/* timeout for +ve entries (sec) */
name|int
name|nm_negnametimeo
decl_stmt|;
comment|/* timeout for -ve entries (sec) */
comment|/* Newnfs additions */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|nfsclds
argument_list|)
name|nm_sess
expr_stmt|;
comment|/* Session(s) for NFSv4.1. */
name|struct
name|nfsclclient
modifier|*
name|nm_clp
decl_stmt|;
name|uid_t
name|nm_uid
decl_stmt|;
comment|/* Uid for SetClientID etc. */
name|u_int64_t
name|nm_clval
decl_stmt|;
comment|/* identifies which clientid */
name|u_int64_t
name|nm_fsid
index|[
literal|2
index|]
decl_stmt|;
comment|/* NFSv4 fsid */
name|int
name|nm_minorvers
decl_stmt|;
comment|/* Minor version # for NFSv4 */
name|u_int16_t
name|nm_krbnamelen
decl_stmt|;
comment|/* Krb5 host principal, if any */
name|u_int16_t
name|nm_dirpathlen
decl_stmt|;
comment|/* and mount dirpath, for V4 */
name|u_int16_t
name|nm_srvkrbnamelen
decl_stmt|;
comment|/* and the server's target name */
name|u_char
name|nm_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* malloc'd actual len of krbname + dirpath */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nm_nam
value|nm_sockreq.nr_nam
end_define

begin_define
define|#
directive|define
name|nm_sotype
value|nm_sockreq.nr_sotype
end_define

begin_define
define|#
directive|define
name|nm_so
value|nm_sockreq.nr_so
end_define

begin_define
define|#
directive|define
name|nm_soflags
value|nm_sockreq.nr_soflags
end_define

begin_define
define|#
directive|define
name|nm_soproto
value|nm_sockreq.nr_soproto
end_define

begin_define
define|#
directive|define
name|nm_client
value|nm_sockreq.nr_client
end_define

begin_define
define|#
directive|define
name|nm_krbname
value|nm_name
end_define

begin_define
define|#
directive|define
name|nm_mtx
value|nm_com.nmcom_mtx
end_define

begin_define
define|#
directive|define
name|nm_flag
value|nm_com.nmcom_flag
end_define

begin_define
define|#
directive|define
name|nm_state
value|nm_com.nmcom_state
end_define

begin_define
define|#
directive|define
name|nm_mountp
value|nm_com.nmcom_mountp
end_define

begin_define
define|#
directive|define
name|nm_timeo
value|nm_com.nmcom_timeo
end_define

begin_define
define|#
directive|define
name|nm_retry
value|nm_com.nmcom_retry
end_define

begin_define
define|#
directive|define
name|nm_hostname
value|nm_com.nmcom_hostname
end_define

begin_define
define|#
directive|define
name|nm_getinfo
value|nm_com.nmcom_getinfo
end_define

begin_define
define|#
directive|define
name|nm_vinvalbuf
value|nm_com.nmcom_vinvalbuf
end_define

begin_comment
comment|/* Private flags. */
end_comment

begin_define
define|#
directive|define
name|NFSMNTP_FORCEDISM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSMNTP_CANCELRPCS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSMNT_DIRPATH
parameter_list|(
name|m
parameter_list|)
value|(&((m)->nm_name[(m)->nm_krbnamelen + 1]))
end_define

begin_define
define|#
directive|define
name|NFSMNT_SRVKRBNAME
parameter_list|(
name|m
parameter_list|)
define|\
value|(&((m)->nm_name[(m)->nm_krbnamelen + (m)->nm_dirpathlen + 2]))
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
comment|/*  * Convert mount ptr to nfsmount ptr.  */
end_comment

begin_define
define|#
directive|define
name|VFSTONFS
parameter_list|(
name|mp
parameter_list|)
value|((struct nfsmount *)((mp)->mnt_data))
end_define

begin_comment
comment|/*  * Get a pointer to the MDS session, which is always the first element  * in the list.  * This macro can only be safely used when the NFSLOCKMNT() lock is held.  * The inline function can be used when the lock isn't held.  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_MDSSESSION
parameter_list|(
name|m
parameter_list|)
value|(&(TAILQ_FIRST(&((m)->nm_sess))->nfsclds_sess))
end_define

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|nfsclsession
operator|*
name|nfsmnt_mdssession
argument_list|(
argument|struct nfsmount *nmp
argument_list|)
block|{ 	struct
name|nfsclsession
operator|*
name|tsep
block|;
name|mtx_lock
argument_list|(
operator|&
name|nmp
operator|->
name|nm_mtx
argument_list|)
block|;
name|tsep
operator|=
name|NFSMNT_MDSSESSION
argument_list|(
name|nmp
argument_list|)
block|;
name|mtx_unlock
argument_list|(
operator|&
name|nmp
operator|->
name|nm_mtx
argument_list|)
block|;
return|return
operator|(
name|tsep
operator|)
return|;
block|}
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_DEFAULT_NAMETIMEO
end_ifndef

begin_define
define|#
directive|define
name|NFS_DEFAULT_NAMETIMEO
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_DEFAULT_NEGNAMETIMEO
end_ifndef

begin_define
define|#
directive|define
name|NFS_DEFAULT_NEGNAMETIMEO
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* _NFSCLIENT_NFSMOUNT_H_ */
end_comment

end_unit

