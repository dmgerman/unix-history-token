begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsproto.h  8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSPROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSPROTO_H_
end_define

begin_comment
comment|/*  * nfs definitions as per the Version 2 and 3 specs  */
end_comment

begin_comment
comment|/*  * Constants as defined in the Sun NFS Version 2 and 3 specs.  * "NFS: Network File System Protocol Specification" RFC1094  * and in the "NFS: Network File System Version 3 Protocol  * Specification"  */
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
name|NFS_VER3
value|3
end_define

begin_define
define|#
directive|define
name|NFS_V2MAXDATA
value|8192
end_define

begin_define
define|#
directive|define
name|NFS_MAXDGRAMDATA
value|16384
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
name|NFS_MAXPKTHDR
value|404
end_define

begin_define
define|#
directive|define
name|NFS_MAXPACKET
value|(NFS_MAXPKTHDR + NFS_MAXDATA)
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
comment|/* Stat numbers for rpc returns (version 2 and 3) */
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
name|NFSERR_XDEV
value|18
end_define

begin_comment
comment|/* Version 3 only */
end_comment

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
name|NFSERR_INVAL
value|22
end_define

begin_comment
comment|/* Version 3 only */
end_comment

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
name|NFSERR_MLINK
value|31
end_define

begin_comment
comment|/* Version 3 only */
end_comment

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
name|NFSERR_REMOTE
value|71
end_define

begin_comment
comment|/* Version 3 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_WFLUSH
value|99
end_define

begin_comment
comment|/* Version 2 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_BADHANDLE
value|10001
end_define

begin_comment
comment|/* The rest Version 3 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_NOT_SYNC
value|10002
end_define

begin_define
define|#
directive|define
name|NFSERR_BAD_COOKIE
value|10003
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTSUPP
value|10004
end_define

begin_define
define|#
directive|define
name|NFSERR_TOOSMALL
value|10005
end_define

begin_define
define|#
directive|define
name|NFSERR_SERVERFAULT
value|10006
end_define

begin_define
define|#
directive|define
name|NFSERR_BADTYPE
value|10007
end_define

begin_define
define|#
directive|define
name|NFSERR_JUKEBOX
value|10008
end_define

begin_define
define|#
directive|define
name|NFSERR_TRYLATER
value|NFSERR_JUKEBOX
end_define

begin_define
define|#
directive|define
name|NFSERR_STALEWRITEVERF
value|30001
end_define

begin_comment
comment|/* Fake return for nfs_commit() */
end_comment

begin_define
define|#
directive|define
name|NFSERR_RETVOID
value|0x20000000
end_define

begin_comment
comment|/* Return void, not error */
end_comment

begin_define
define|#
directive|define
name|NFSERR_AUTHERR
value|0x40000000
end_define

begin_comment
comment|/* Mark an authentication error */
end_comment

begin_define
define|#
directive|define
name|NFSERR_RETERR
value|0x80000000
end_define

begin_comment
comment|/* Mark an error return for V3 */
end_comment

begin_comment
comment|/* Sizes in bytes of various nfs rpc components */
end_comment

begin_define
define|#
directive|define
name|NFSX_UNSIGNED
value|4
end_define

begin_comment
comment|/* specific to NFS Version 2 */
end_comment

begin_define
define|#
directive|define
name|NFSX_V2FH
value|32
end_define

begin_define
define|#
directive|define
name|NFSX_V2FATTR
value|68
end_define

begin_define
define|#
directive|define
name|NFSX_V2SATTR
value|32
end_define

begin_define
define|#
directive|define
name|NFSX_V2COOKIE
value|4
end_define

begin_define
define|#
directive|define
name|NFSX_V2STATFS
value|20
end_define

begin_comment
comment|/* specific to NFS Version 3 */
end_comment

begin_define
define|#
directive|define
name|NFSX_V3FH
value|(sizeof (fhandle_t))
end_define

begin_comment
comment|/* size this server uses */
end_comment

begin_define
define|#
directive|define
name|NFSX_V3FHMAX
value|64
end_define

begin_comment
comment|/* max. allowed by protocol */
end_comment

begin_define
define|#
directive|define
name|NFSX_V3FATTR
value|84
end_define

begin_define
define|#
directive|define
name|NFSX_V3SATTR
value|60
end_define

begin_comment
comment|/* max. all fields filled in */
end_comment

begin_define
define|#
directive|define
name|NFSX_V3SRVSATTR
value|(sizeof (struct nfsv3_sattr))
end_define

begin_define
define|#
directive|define
name|NFSX_V3POSTOPATTR
value|(NFSX_V3FATTR + NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|NFSX_V3WCCDATA
value|(NFSX_V3POSTOPATTR + 8 * NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|NFSX_V3COOKIEVERF
value|8
end_define

begin_define
define|#
directive|define
name|NFSX_V3WRITEVERF
value|8
end_define

begin_define
define|#
directive|define
name|NFSX_V3CREATEVERF
value|8
end_define

begin_define
define|#
directive|define
name|NFSX_V3STATFS
value|52
end_define

begin_define
define|#
directive|define
name|NFSX_V3FSINFO
value|48
end_define

begin_define
define|#
directive|define
name|NFSX_V3PATHCONF
value|24
end_define

begin_comment
comment|/* variants for both versions */
end_comment

begin_define
define|#
directive|define
name|NFSX_FH
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? (NFSX_V3FHMAX + NFSX_UNSIGNED) : \ 					NFSX_V2FH)
end_define

begin_define
define|#
directive|define
name|NFSX_SRVFH
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3FH : NFSX_V2FH)
end_define

begin_define
define|#
directive|define
name|NFSX_FATTR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3FATTR : NFSX_V2FATTR)
end_define

begin_define
define|#
directive|define
name|NFSX_PREOPATTR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? (7 * NFSX_UNSIGNED) : 0)
end_define

begin_define
define|#
directive|define
name|NFSX_POSTOPATTR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? (NFSX_V3FATTR + NFSX_UNSIGNED) : 0)
end_define

begin_define
define|#
directive|define
name|NFSX_POSTOPORFATTR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? (NFSX_V3FATTR + NFSX_UNSIGNED) : \ 					NFSX_V2FATTR)
end_define

begin_define
define|#
directive|define
name|NFSX_WCCDATA
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3WCCDATA : 0)
end_define

begin_define
define|#
directive|define
name|NFSX_WCCORFATTR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3WCCDATA : NFSX_V2FATTR)
end_define

begin_define
define|#
directive|define
name|NFSX_SATTR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3SATTR : NFSX_V2SATTR)
end_define

begin_define
define|#
directive|define
name|NFSX_COOKIEVERF
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3COOKIEVERF : 0)
end_define

begin_define
define|#
directive|define
name|NFSX_WRITEVERF
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3WRITEVERF : 0)
end_define

begin_define
define|#
directive|define
name|NFSX_READDIR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? (5 * NFSX_UNSIGNED) : \ 					(2 * NFSX_UNSIGNED))
end_define

begin_define
define|#
directive|define
name|NFSX_STATFS
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3STATFS : NFSX_V2STATFS)
end_define

begin_comment
comment|/* nfs rpc procedure numbers (before version mapping) */
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
name|NFSPROC_LOOKUP
value|3
end_define

begin_define
define|#
directive|define
name|NFSPROC_ACCESS
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
name|NFSPROC_WRITE
value|7
end_define

begin_define
define|#
directive|define
name|NFSPROC_CREATE
value|8
end_define

begin_define
define|#
directive|define
name|NFSPROC_MKDIR
value|9
end_define

begin_define
define|#
directive|define
name|NFSPROC_SYMLINK
value|10
end_define

begin_define
define|#
directive|define
name|NFSPROC_MKNOD
value|11
end_define

begin_define
define|#
directive|define
name|NFSPROC_REMOVE
value|12
end_define

begin_define
define|#
directive|define
name|NFSPROC_RMDIR
value|13
end_define

begin_define
define|#
directive|define
name|NFSPROC_RENAME
value|14
end_define

begin_define
define|#
directive|define
name|NFSPROC_LINK
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
name|NFSPROC_READDIRPLUS
value|17
end_define

begin_define
define|#
directive|define
name|NFSPROC_FSSTAT
value|18
end_define

begin_define
define|#
directive|define
name|NFSPROC_FSINFO
value|19
end_define

begin_define
define|#
directive|define
name|NFSPROC_PATHCONF
value|20
end_define

begin_define
define|#
directive|define
name|NFSPROC_COMMIT
value|21
end_define

begin_comment
comment|/* And leasing (nqnfs) procedure numbers (must be last) */
end_comment

begin_define
define|#
directive|define
name|NQNFSPROC_GETLEASE
value|22
end_define

begin_define
define|#
directive|define
name|NQNFSPROC_VACATED
value|23
end_define

begin_define
define|#
directive|define
name|NQNFSPROC_EVICTED
value|24
end_define

begin_define
define|#
directive|define
name|NFSPROC_NOOP
value|25
end_define

begin_define
define|#
directive|define
name|NFS_NPROCS
value|26
end_define

begin_comment
comment|/* Actual Version 2 procedure numbers */
end_comment

begin_define
define|#
directive|define
name|NFSV2PROC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_GETATTR
value|1
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_SETATTR
value|2
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_NOOP
value|3
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_ROOT
value|NFSV2PROC_NOOP
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|NFSV2PROC_LOOKUP
value|4
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_READLINK
value|5
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_READ
value|6
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_WRITECACHE
value|NFSV2PROC_NOOP
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|NFSV2PROC_WRITE
value|8
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_CREATE
value|9
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_REMOVE
value|10
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_RENAME
value|11
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_LINK
value|12
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_SYMLINK
value|13
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_MKDIR
value|14
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_RMDIR
value|15
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_READDIR
value|16
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_STATFS
value|17
end_define

begin_comment
comment|/*  * Constants used by the Version 3 protocol for various RPCs  */
end_comment

begin_define
define|#
directive|define
name|NFSV3SATTRTIME_DONTCHANGE
value|0
end_define

begin_define
define|#
directive|define
name|NFSV3SATTRTIME_TOSERVER
value|1
end_define

begin_define
define|#
directive|define
name|NFSV3SATTRTIME_TOCLIENT
value|2
end_define

begin_define
define|#
directive|define
name|NFSV3ACCESS_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSV3ACCESS_LOOKUP
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSV3ACCESS_MODIFY
value|0x04
end_define

begin_define
define|#
directive|define
name|NFSV3ACCESS_EXTEND
value|0x08
end_define

begin_define
define|#
directive|define
name|NFSV3ACCESS_DELETE
value|0x10
end_define

begin_define
define|#
directive|define
name|NFSV3ACCESS_EXECUTE
value|0x20
end_define

begin_define
define|#
directive|define
name|NFSV3WRITE_UNSTABLE
value|0
end_define

begin_define
define|#
directive|define
name|NFSV3WRITE_DATASYNC
value|1
end_define

begin_define
define|#
directive|define
name|NFSV3WRITE_FILESYNC
value|2
end_define

begin_define
define|#
directive|define
name|NFSV3CREATE_UNCHECKED
value|0
end_define

begin_define
define|#
directive|define
name|NFSV3CREATE_GUARDED
value|1
end_define

begin_define
define|#
directive|define
name|NFSV3CREATE_EXCLUSIVE
value|2
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_LINK
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_SYMLINK
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_HOMOGENEOUS
value|0x08
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_CANSETTIME
value|0x10
end_define

begin_comment
comment|/* Conversion macros */
end_comment

begin_define
define|#
directive|define
name|vtonfsv2_mode
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
name|vtonfsv3_mode
parameter_list|(
name|m
parameter_list|)
value|txdr_unsigned((m)& ALLPERMS)
end_define

begin_define
define|#
directive|define
name|nfstov_mode
parameter_list|(
name|a
parameter_list|)
value|(fxdr_unsigned(u_int32_t, (a))& ALLPERMS)
end_define

begin_define
define|#
directive|define
name|vtonfsv2_type
parameter_list|(
name|a
parameter_list|)
value|txdr_unsigned(nfsv2_type[((int32_t)(a))])
end_define

begin_define
define|#
directive|define
name|vtonfsv3_type
parameter_list|(
name|a
parameter_list|)
value|txdr_unsigned(nfsv3_type[((int32_t)(a))])
end_define

begin_define
define|#
directive|define
name|nfsv2tov_type
parameter_list|(
name|a
parameter_list|)
value|nv2tov_type[fxdr_unsigned(u_int32_t,(a))&0x7]
end_define

begin_define
define|#
directive|define
name|nfsv3tov_type
parameter_list|(
name|a
parameter_list|)
value|nv3tov_type[fxdr_unsigned(u_int32_t,(a))&0x7]
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
block|,
name|NFSOCK
init|=
literal|6
block|,
name|NFFIFO
init|=
literal|7
block|}
name|nfstype
typedef|;
end_typedef

begin_comment
comment|/* Structs for common parts of the rpc's */
end_comment

begin_comment
comment|/*  * File Handle (32 bytes for version 2), variable up to 64 for version 3.  * File Handles of up to NFS_SMALLFH in size are stored directly in the  * nfs node, whereas larger ones are malloc'd. (This never happens when  * NFS_SMALLFH is set to 64.)  * NFS_SMALLFH should be in the range of 32 to 64 and be divisible by 4.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_SMALLFH
end_ifndef

begin_define
define|#
directive|define
name|NFS_SMALLFH
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_union
union|union
name|nfsfh
block|{
name|fhandle_t
name|fh_generic
decl_stmt|;
name|u_char
name|fh_bytes
index|[
name|NFS_SMALLFH
index|]
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|nfsfh
name|nfsfh_t
typedef|;
end_typedef

begin_struct
struct|struct
name|nfsv2_time
block|{
name|u_int32_t
name|nfsv2_sec
decl_stmt|;
name|u_int32_t
name|nfsv2_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv2_time
name|nfstime2
typedef|;
end_typedef

begin_struct
struct|struct
name|nfsv3_time
block|{
name|u_int32_t
name|nfsv3_sec
decl_stmt|;
name|u_int32_t
name|nfsv3_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv3_time
name|nfstime3
typedef|;
end_typedef

begin_comment
comment|/*  * Quads are defined as arrays of 2 longs to ensure dense packing for the  * protocol and to facilitate xdr conversion.  */
end_comment

begin_struct
struct|struct
name|nfs_uquad
block|{
name|u_int32_t
name|nfsuquad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfs_uquad
name|nfsuint64
typedef|;
end_typedef

begin_comment
comment|/*  * Used to convert between two u_longs and a u_quad_t.  */
end_comment

begin_union
union|union
name|nfs_quadconvert
block|{
name|u_int32_t
name|lval
index|[
literal|2
index|]
decl_stmt|;
name|u_quad_t
name|qval
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|nfs_quadconvert
name|nfsquad_t
typedef|;
end_typedef

begin_comment
comment|/*  * NFS Version 3 special file number.  */
end_comment

begin_struct
struct|struct
name|nfsv3_spec
block|{
name|u_int32_t
name|specdata1
decl_stmt|;
name|u_int32_t
name|specdata2
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv3_spec
name|nfsv3spec
typedef|;
end_typedef

begin_comment
comment|/*  * File attributes and setable attributes. These structures cover both  * NFS version 2 and the version 3 protocol. Note that the union is only  * used so that one pointer can refer to both variants. These structures  * go out on the wire and must be densely packed, so no quad data types  * are used. (all fields are longs or u_longs or structures of same)  * NB: You can't do sizeof(struct nfs_fattr), you must use the  *     NFSX_FATTR(v3) macro.  */
end_comment

begin_struct
struct|struct
name|nfs_fattr
block|{
name|u_int32_t
name|fa_type
decl_stmt|;
name|u_int32_t
name|fa_mode
decl_stmt|;
name|u_int32_t
name|fa_nlink
decl_stmt|;
name|u_int32_t
name|fa_uid
decl_stmt|;
name|u_int32_t
name|fa_gid
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|nfsv2fa_size
decl_stmt|;
name|u_int32_t
name|nfsv2fa_blocksize
decl_stmt|;
name|u_int32_t
name|nfsv2fa_rdev
decl_stmt|;
name|u_int32_t
name|nfsv2fa_blocks
decl_stmt|;
name|u_int32_t
name|nfsv2fa_fsid
decl_stmt|;
name|u_int32_t
name|nfsv2fa_fileid
decl_stmt|;
name|nfstime2
name|nfsv2fa_atime
decl_stmt|;
name|nfstime2
name|nfsv2fa_mtime
decl_stmt|;
name|nfstime2
name|nfsv2fa_ctime
decl_stmt|;
block|}
name|fa_nfsv2
struct|;
struct|struct
block|{
name|nfsuint64
name|nfsv3fa_size
decl_stmt|;
name|nfsuint64
name|nfsv3fa_used
decl_stmt|;
name|nfsv3spec
name|nfsv3fa_rdev
decl_stmt|;
name|nfsuint64
name|nfsv3fa_fsid
decl_stmt|;
name|nfsuint64
name|nfsv3fa_fileid
decl_stmt|;
name|nfstime3
name|nfsv3fa_atime
decl_stmt|;
name|nfstime3
name|nfsv3fa_mtime
decl_stmt|;
name|nfstime3
name|nfsv3fa_ctime
decl_stmt|;
block|}
name|fa_nfsv3
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
name|fa2_size
value|fa_un.fa_nfsv2.nfsv2fa_size
end_define

begin_define
define|#
directive|define
name|fa2_blocksize
value|fa_un.fa_nfsv2.nfsv2fa_blocksize
end_define

begin_define
define|#
directive|define
name|fa2_rdev
value|fa_un.fa_nfsv2.nfsv2fa_rdev
end_define

begin_define
define|#
directive|define
name|fa2_blocks
value|fa_un.fa_nfsv2.nfsv2fa_blocks
end_define

begin_define
define|#
directive|define
name|fa2_fsid
value|fa_un.fa_nfsv2.nfsv2fa_fsid
end_define

begin_define
define|#
directive|define
name|fa2_fileid
value|fa_un.fa_nfsv2.nfsv2fa_fileid
end_define

begin_define
define|#
directive|define
name|fa2_atime
value|fa_un.fa_nfsv2.nfsv2fa_atime
end_define

begin_define
define|#
directive|define
name|fa2_mtime
value|fa_un.fa_nfsv2.nfsv2fa_mtime
end_define

begin_define
define|#
directive|define
name|fa2_ctime
value|fa_un.fa_nfsv2.nfsv2fa_ctime
end_define

begin_define
define|#
directive|define
name|fa3_size
value|fa_un.fa_nfsv3.nfsv3fa_size
end_define

begin_define
define|#
directive|define
name|fa3_used
value|fa_un.fa_nfsv3.nfsv3fa_used
end_define

begin_define
define|#
directive|define
name|fa3_rdev
value|fa_un.fa_nfsv3.nfsv3fa_rdev
end_define

begin_define
define|#
directive|define
name|fa3_fsid
value|fa_un.fa_nfsv3.nfsv3fa_fsid
end_define

begin_define
define|#
directive|define
name|fa3_fileid
value|fa_un.fa_nfsv3.nfsv3fa_fileid
end_define

begin_define
define|#
directive|define
name|fa3_atime
value|fa_un.fa_nfsv3.nfsv3fa_atime
end_define

begin_define
define|#
directive|define
name|fa3_mtime
value|fa_un.fa_nfsv3.nfsv3fa_mtime
end_define

begin_define
define|#
directive|define
name|fa3_ctime
value|fa_un.fa_nfsv3.nfsv3fa_ctime
end_define

begin_struct
struct|struct
name|nfsv2_sattr
block|{
name|u_int32_t
name|sa_mode
decl_stmt|;
name|u_int32_t
name|sa_uid
decl_stmt|;
name|u_int32_t
name|sa_gid
decl_stmt|;
name|u_int32_t
name|sa_size
decl_stmt|;
name|nfstime2
name|sa_atime
decl_stmt|;
name|nfstime2
name|sa_mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS Version 3 sattr structure for the new node creation case.  */
end_comment

begin_struct
struct|struct
name|nfsv3_sattr
block|{
name|u_int32_t
name|sa_modetrue
decl_stmt|;
name|u_int32_t
name|sa_mode
decl_stmt|;
name|u_int32_t
name|sa_uidfalse
decl_stmt|;
name|u_int32_t
name|sa_gidfalse
decl_stmt|;
name|u_int32_t
name|sa_sizefalse
decl_stmt|;
name|u_int32_t
name|sa_atimetype
decl_stmt|;
name|nfstime3
name|sa_atime
decl_stmt|;
name|u_int32_t
name|sa_mtimetype
decl_stmt|;
name|nfstime3
name|sa_mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs_statfs
block|{
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|nfsv2sf_tsize
decl_stmt|;
name|u_int32_t
name|nfsv2sf_bsize
decl_stmt|;
name|u_int32_t
name|nfsv2sf_blocks
decl_stmt|;
name|u_int32_t
name|nfsv2sf_bfree
decl_stmt|;
name|u_int32_t
name|nfsv2sf_bavail
decl_stmt|;
block|}
name|sf_nfsv2
struct|;
struct|struct
block|{
name|nfsuint64
name|nfsv3sf_tbytes
decl_stmt|;
name|nfsuint64
name|nfsv3sf_fbytes
decl_stmt|;
name|nfsuint64
name|nfsv3sf_abytes
decl_stmt|;
name|nfsuint64
name|nfsv3sf_tfiles
decl_stmt|;
name|nfsuint64
name|nfsv3sf_ffiles
decl_stmt|;
name|nfsuint64
name|nfsv3sf_afiles
decl_stmt|;
name|u_int32_t
name|nfsv3sf_invarsec
decl_stmt|;
block|}
name|sf_nfsv3
struct|;
block|}
name|sf_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sf_tsize
value|sf_un.sf_nfsv2.nfsv2sf_tsize
end_define

begin_define
define|#
directive|define
name|sf_bsize
value|sf_un.sf_nfsv2.nfsv2sf_bsize
end_define

begin_define
define|#
directive|define
name|sf_blocks
value|sf_un.sf_nfsv2.nfsv2sf_blocks
end_define

begin_define
define|#
directive|define
name|sf_bfree
value|sf_un.sf_nfsv2.nfsv2sf_bfree
end_define

begin_define
define|#
directive|define
name|sf_bavail
value|sf_un.sf_nfsv2.nfsv2sf_bavail
end_define

begin_define
define|#
directive|define
name|sf_tbytes
value|sf_un.sf_nfsv3.nfsv3sf_tbytes
end_define

begin_define
define|#
directive|define
name|sf_fbytes
value|sf_un.sf_nfsv3.nfsv3sf_fbytes
end_define

begin_define
define|#
directive|define
name|sf_abytes
value|sf_un.sf_nfsv3.nfsv3sf_abytes
end_define

begin_define
define|#
directive|define
name|sf_tfiles
value|sf_un.sf_nfsv3.nfsv3sf_tfiles
end_define

begin_define
define|#
directive|define
name|sf_ffiles
value|sf_un.sf_nfsv3.nfsv3sf_ffiles
end_define

begin_define
define|#
directive|define
name|sf_afiles
value|sf_un.sf_nfsv3.nfsv3sf_afiles
end_define

begin_define
define|#
directive|define
name|sf_invarsec
value|sf_un.sf_nfsv3.nfsv3sf_invarsec
end_define

begin_struct
struct|struct
name|nfsv3_fsinfo
block|{
name|u_int32_t
name|fs_rtmax
decl_stmt|;
name|u_int32_t
name|fs_rtpref
decl_stmt|;
name|u_int32_t
name|fs_rtmult
decl_stmt|;
name|u_int32_t
name|fs_wtmax
decl_stmt|;
name|u_int32_t
name|fs_wtpref
decl_stmt|;
name|u_int32_t
name|fs_wtmult
decl_stmt|;
name|u_int32_t
name|fs_dtpref
decl_stmt|;
name|nfsuint64
name|fs_maxfilesize
decl_stmt|;
name|nfstime3
name|fs_timedelta
decl_stmt|;
name|u_int32_t
name|fs_properties
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsv3_pathconf
block|{
name|u_int32_t
name|pc_linkmax
decl_stmt|;
name|u_int32_t
name|pc_namemax
decl_stmt|;
name|u_int32_t
name|pc_notrunc
decl_stmt|;
name|u_int32_t
name|pc_chownrestricted
decl_stmt|;
name|u_int32_t
name|pc_caseinsensitive
decl_stmt|;
name|u_int32_t
name|pc_casepreserving
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

