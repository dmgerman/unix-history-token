begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsv2.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSV2_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSV2_H_
end_define

begin_comment
comment|/*  * nfs definitions as per the version 2 specs  */
end_comment

begin_comment
comment|/*  * Constants as defined in the Sun NFS Version 2 spec.  * "NFS: Network File System Protocol Specification" RFC1094  */
end_comment

begin_define
define|#
directive|define
name|NFS_PORT
value|2049
end_define

begin_define
define|#
directive|define
name|NFS_PROG
value|100003
end_define

begin_define
define|#
directive|define
name|NFS_VER2
value|2
end_define

begin_define
define|#
directive|define
name|NFS_MAXDGRAMDATA
value|8192
end_define

begin_define
define|#
directive|define
name|NFS_MAXDATA
value|32768
end_define

begin_define
define|#
directive|define
name|NFS_MAXPATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|NFS_MAXNAMLEN
value|255
end_define

begin_define
define|#
directive|define
name|NFS_FHSIZE
value|32
end_define

begin_define
define|#
directive|define
name|NFS_MAXPKTHDR
value|404
end_define

begin_define
define|#
directive|define
name|NFS_MAXPACKET
value|(NFS_MAXPKTHDR+NFS_MAXDATA)
end_define

begin_define
define|#
directive|define
name|NFS_MINPACKET
value|20
end_define

begin_define
define|#
directive|define
name|NFS_FABLKSIZE
value|512
end_define

begin_comment
comment|/* Size in bytes of a block wrt fa_blocks */
end_comment

begin_comment
comment|/* Stat numbers for rpc returns */
end_comment

begin_define
define|#
directive|define
name|NFS_OK
value|0
end_define

begin_define
define|#
directive|define
name|NFSERR_PERM
value|1
end_define

begin_define
define|#
directive|define
name|NFSERR_NOENT
value|2
end_define

begin_define
define|#
directive|define
name|NFSERR_IO
value|5
end_define

begin_define
define|#
directive|define
name|NFSERR_NXIO
value|6
end_define

begin_define
define|#
directive|define
name|NFSERR_ACCES
value|13
end_define

begin_define
define|#
directive|define
name|NFSERR_EXIST
value|17
end_define

begin_define
define|#
directive|define
name|NFSERR_NODEV
value|19
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|NFSERR_ISDIR
value|21
end_define

begin_define
define|#
directive|define
name|NFSERR_FBIG
value|27
end_define

begin_define
define|#
directive|define
name|NFSERR_NOSPC
value|28
end_define

begin_define
define|#
directive|define
name|NFSERR_ROFS
value|30
end_define

begin_define
define|#
directive|define
name|NFSERR_NAMETOL
value|63
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTEMPTY
value|66
end_define

begin_define
define|#
directive|define
name|NFSERR_DQUOT
value|69
end_define

begin_define
define|#
directive|define
name|NFSERR_STALE
value|70
end_define

begin_define
define|#
directive|define
name|NFSERR_WFLUSH
value|99
end_define

begin_comment
comment|/* Sizes in bytes of various nfs rpc components */
end_comment

begin_define
define|#
directive|define
name|NFSX_FH
value|32
end_define

begin_define
define|#
directive|define
name|NFSX_UNSIGNED
value|4
end_define

begin_define
define|#
directive|define
name|NFSX_NFSFATTR
value|68
end_define

begin_define
define|#
directive|define
name|NFSX_NQFATTR
value|92
end_define

begin_define
define|#
directive|define
name|NFSX_NFSSATTR
value|32
end_define

begin_define
define|#
directive|define
name|NFSX_NQSATTR
value|44
end_define

begin_define
define|#
directive|define
name|NFSX_COOKIE
value|4
end_define

begin_define
define|#
directive|define
name|NFSX_NFSSTATFS
value|20
end_define

begin_define
define|#
directive|define
name|NFSX_NQSTATFS
value|28
end_define

begin_define
define|#
directive|define
name|NFSX_FATTR
parameter_list|(
name|isnq
parameter_list|)
value|((isnq) ? NFSX_NQFATTR : NFSX_NFSFATTR)
end_define

begin_define
define|#
directive|define
name|NFSX_SATTR
parameter_list|(
name|isnq
parameter_list|)
value|((isnq) ? NFSX_NQSATTR : NFSX_NFSSATTR)
end_define

begin_define
define|#
directive|define
name|NFSX_STATFS
parameter_list|(
name|isnq
parameter_list|)
value|((isnq) ? NFSX_NQSTATFS : NFSX_NFSSTATFS)
end_define

begin_comment
comment|/* nfs rpc procedure numbers */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|NFSPROC_GETATTR
value|1
end_define

begin_define
define|#
directive|define
name|NFSPROC_SETATTR
value|2
end_define

begin_define
define|#
directive|define
name|NFSPROC_NOOP
value|3
end_define

begin_define
define|#
directive|define
name|NFSPROC_ROOT
value|NFSPROC_NOOP
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_LOOKUP
value|4
end_define

begin_define
define|#
directive|define
name|NFSPROC_READLINK
value|5
end_define

begin_define
define|#
directive|define
name|NFSPROC_READ
value|6
end_define

begin_define
define|#
directive|define
name|NFSPROC_WRITECACHE
value|NFSPROC_NOOP
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_WRITE
value|8
end_define

begin_define
define|#
directive|define
name|NFSPROC_CREATE
value|9
end_define

begin_define
define|#
directive|define
name|NFSPROC_REMOVE
value|10
end_define

begin_define
define|#
directive|define
name|NFSPROC_RENAME
value|11
end_define

begin_define
define|#
directive|define
name|NFSPROC_LINK
value|12
end_define

begin_define
define|#
directive|define
name|NFSPROC_SYMLINK
value|13
end_define

begin_define
define|#
directive|define
name|NFSPROC_MKDIR
value|14
end_define

begin_define
define|#
directive|define
name|NFSPROC_RMDIR
value|15
end_define

begin_define
define|#
directive|define
name|NFSPROC_READDIR
value|16
end_define

begin_define
define|#
directive|define
name|NFSPROC_STATFS
value|17
end_define

begin_comment
comment|/* NQ nfs numbers */
end_comment

begin_define
define|#
directive|define
name|NQNFSPROC_READDIRLOOK
value|18
end_define

begin_define
define|#
directive|define
name|NQNFSPROC_GETLEASE
value|19
end_define

begin_define
define|#
directive|define
name|NQNFSPROC_VACATED
value|20
end_define

begin_define
define|#
directive|define
name|NQNFSPROC_EVICTED
value|21
end_define

begin_define
define|#
directive|define
name|NQNFSPROC_ACCESS
value|22
end_define

begin_define
define|#
directive|define
name|NFS_NPROCS
value|23
end_define

begin_comment
comment|/* Conversion macros */
end_comment

begin_define
define|#
directive|define
name|vtonfs_mode
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
define|\
value|txdr_unsigned(((t) == VFIFO) ? MAKEIMODE(VCHR, (m)) : \ 				MAKEIMODE((t), (m)))
end_define

begin_define
define|#
directive|define
name|nfstov_mode
parameter_list|(
name|a
parameter_list|)
value|(fxdr_unsigned(u_short, (a))&07777)
end_define

begin_define
define|#
directive|define
name|vtonfs_type
parameter_list|(
name|a
parameter_list|)
value|txdr_unsigned(nfs_type[((long)(a))])
end_define

begin_define
define|#
directive|define
name|nfstov_type
parameter_list|(
name|a
parameter_list|)
value|ntov_type[fxdr_unsigned(u_long,(a))&0x7]
end_define

begin_comment
comment|/* File types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NFNON
init|=
literal|0
block|,
name|NFREG
init|=
literal|1
block|,
name|NFDIR
init|=
literal|2
block|,
name|NFBLK
init|=
literal|3
block|,
name|NFCHR
init|=
literal|4
block|,
name|NFLNK
init|=
literal|5
block|}
name|nfstype
typedef|;
end_typedef

begin_comment
comment|/* Structs for common parts of the rpc's */
end_comment

begin_struct
struct|struct
name|nfsv2_time
block|{
name|u_long
name|nfs_sec
decl_stmt|;
name|u_long
name|nfs_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nqnfs_time
block|{
name|u_long
name|nq_sec
decl_stmt|;
name|u_long
name|nq_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * File attributes and setable attributes. These structures cover both  * NFS version 2 and the NQNFS protocol. Note that the union is only  * used to that one pointer can refer to both variants. These structures  * go out on the wire and must be densely packed, so no quad data types  * are used. (all fields are longs or u_longs or structures of same)  * NB: You can't do sizeof(struct nfsv2_fattr), you must use the  *     NFSX_FATTR(isnq) macro.  */
end_comment

begin_struct
struct|struct
name|nfsv2_fattr
block|{
name|u_long
name|fa_type
decl_stmt|;
name|u_long
name|fa_mode
decl_stmt|;
name|u_long
name|fa_nlink
decl_stmt|;
name|u_long
name|fa_uid
decl_stmt|;
name|u_long
name|fa_gid
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_long
name|nfsfa_size
decl_stmt|;
name|u_long
name|nfsfa_blocksize
decl_stmt|;
name|u_long
name|nfsfa_rdev
decl_stmt|;
name|u_long
name|nfsfa_blocks
decl_stmt|;
name|u_long
name|nfsfa_fsid
decl_stmt|;
name|u_long
name|nfsfa_fileid
decl_stmt|;
name|struct
name|nfsv2_time
name|nfsfa_atime
decl_stmt|;
name|struct
name|nfsv2_time
name|nfsfa_mtime
decl_stmt|;
name|struct
name|nfsv2_time
name|nfsfa_ctime
decl_stmt|;
block|}
name|fa_nfsv2
struct|;
struct|struct
block|{
struct|struct
block|{
name|u_long
name|nqfa_qsize
index|[
literal|2
index|]
decl_stmt|;
block|}
name|nqfa_size
struct|;
name|u_long
name|nqfa_blocksize
decl_stmt|;
name|u_long
name|nqfa_rdev
decl_stmt|;
struct|struct
block|{
name|u_long
name|nqfa_qbytes
index|[
literal|2
index|]
decl_stmt|;
block|}
name|nqfa_bytes
struct|;
name|u_long
name|nqfa_fsid
decl_stmt|;
name|u_long
name|nqfa_fileid
decl_stmt|;
name|struct
name|nqnfs_time
name|nqfa_atime
decl_stmt|;
name|struct
name|nqnfs_time
name|nqfa_mtime
decl_stmt|;
name|struct
name|nqnfs_time
name|nqfa_ctime
decl_stmt|;
name|u_long
name|nqfa_flags
decl_stmt|;
name|u_long
name|nqfa_gen
decl_stmt|;
struct|struct
block|{
name|u_long
name|nqfa_qfilerev
index|[
literal|2
index|]
decl_stmt|;
block|}
name|nqfa_filerev
struct|;
block|}
name|fa_nqnfs
struct|;
block|}
name|fa_un
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* and some ugly defines for accessing union components */
end_comment

begin_define
define|#
directive|define
name|fa_nfssize
value|fa_un.fa_nfsv2.nfsfa_size
end_define

begin_define
define|#
directive|define
name|fa_nfsblocksize
value|fa_un.fa_nfsv2.nfsfa_blocksize
end_define

begin_define
define|#
directive|define
name|fa_nfsrdev
value|fa_un.fa_nfsv2.nfsfa_rdev
end_define

begin_define
define|#
directive|define
name|fa_nfsblocks
value|fa_un.fa_nfsv2.nfsfa_blocks
end_define

begin_define
define|#
directive|define
name|fa_nfsfsid
value|fa_un.fa_nfsv2.nfsfa_fsid
end_define

begin_define
define|#
directive|define
name|fa_nfsfileid
value|fa_un.fa_nfsv2.nfsfa_fileid
end_define

begin_define
define|#
directive|define
name|fa_nfsatime
value|fa_un.fa_nfsv2.nfsfa_atime
end_define

begin_define
define|#
directive|define
name|fa_nfsmtime
value|fa_un.fa_nfsv2.nfsfa_mtime
end_define

begin_define
define|#
directive|define
name|fa_nfsctime
value|fa_un.fa_nfsv2.nfsfa_ctime
end_define

begin_define
define|#
directive|define
name|fa_nqsize
value|fa_un.fa_nqnfs.nqfa_size
end_define

begin_define
define|#
directive|define
name|fa_nqblocksize
value|fa_un.fa_nqnfs.nqfa_blocksize
end_define

begin_define
define|#
directive|define
name|fa_nqrdev
value|fa_un.fa_nqnfs.nqfa_rdev
end_define

begin_define
define|#
directive|define
name|fa_nqbytes
value|fa_un.fa_nqnfs.nqfa_bytes
end_define

begin_define
define|#
directive|define
name|fa_nqfsid
value|fa_un.fa_nqnfs.nqfa_fsid
end_define

begin_define
define|#
directive|define
name|fa_nqfileid
value|fa_un.fa_nqnfs.nqfa_fileid
end_define

begin_define
define|#
directive|define
name|fa_nqatime
value|fa_un.fa_nqnfs.nqfa_atime
end_define

begin_define
define|#
directive|define
name|fa_nqmtime
value|fa_un.fa_nqnfs.nqfa_mtime
end_define

begin_define
define|#
directive|define
name|fa_nqctime
value|fa_un.fa_nqnfs.nqfa_ctime
end_define

begin_define
define|#
directive|define
name|fa_nqflags
value|fa_un.fa_nqnfs.nqfa_flags
end_define

begin_define
define|#
directive|define
name|fa_nqgen
value|fa_un.fa_nqnfs.nqfa_gen
end_define

begin_define
define|#
directive|define
name|fa_nqfilerev
value|fa_un.fa_nqnfs.nqfa_filerev
end_define

begin_struct
struct|struct
name|nfsv2_sattr
block|{
name|u_long
name|sa_mode
decl_stmt|;
name|u_long
name|sa_uid
decl_stmt|;
name|u_long
name|sa_gid
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_long
name|nfssa_size
decl_stmt|;
name|struct
name|nfsv2_time
name|nfssa_atime
decl_stmt|;
name|struct
name|nfsv2_time
name|nfssa_mtime
decl_stmt|;
block|}
name|sa_nfsv2
struct|;
struct|struct
block|{
struct|struct
block|{
name|u_long
name|nqsa_qsize
index|[
literal|2
index|]
decl_stmt|;
block|}
name|nqsa_size
struct|;
name|struct
name|nqnfs_time
name|nqsa_atime
decl_stmt|;
name|struct
name|nqnfs_time
name|nqsa_mtime
decl_stmt|;
name|u_long
name|nqsa_flags
decl_stmt|;
name|u_long
name|nqsa_rdev
decl_stmt|;
block|}
name|sa_nqnfs
struct|;
block|}
name|sa_un
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* and some ugly defines for accessing the unions */
end_comment

begin_define
define|#
directive|define
name|sa_nfssize
value|sa_un.sa_nfsv2.nfssa_size
end_define

begin_define
define|#
directive|define
name|sa_nfsatime
value|sa_un.sa_nfsv2.nfssa_atime
end_define

begin_define
define|#
directive|define
name|sa_nfsmtime
value|sa_un.sa_nfsv2.nfssa_mtime
end_define

begin_define
define|#
directive|define
name|sa_nqsize
value|sa_un.sa_nqnfs.nqsa_size
end_define

begin_define
define|#
directive|define
name|sa_nqatime
value|sa_un.sa_nqnfs.nqsa_atime
end_define

begin_define
define|#
directive|define
name|sa_nqmtime
value|sa_un.sa_nqnfs.nqsa_mtime
end_define

begin_define
define|#
directive|define
name|sa_nqflags
value|sa_un.sa_nqnfs.nqsa_flags
end_define

begin_define
define|#
directive|define
name|sa_nqrdev
value|sa_un.sa_nqnfs.nqsa_rdev
end_define

begin_struct
struct|struct
name|nfsv2_statfs
block|{
name|u_long
name|sf_tsize
decl_stmt|;
name|u_long
name|sf_bsize
decl_stmt|;
name|u_long
name|sf_blocks
decl_stmt|;
name|u_long
name|sf_bfree
decl_stmt|;
name|u_long
name|sf_bavail
decl_stmt|;
name|u_long
name|sf_files
decl_stmt|;
comment|/* Nqnfs only */
name|u_long
name|sf_ffree
decl_stmt|;
comment|/* ditto      */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

