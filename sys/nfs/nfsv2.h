begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsv2.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<nfs/nfsproto.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

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
value|16
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
name|NFSX_V3COOKIEVERF
value|8
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
value|((v3) ? (NFSX_V3FATTR + 32) : 0)
end_define

begin_define
define|#
directive|define
name|NFSX_WCCORFATTR
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? (NFSX_V3FATTR + 32) : NFSX_V2FATTR)
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
name|NFSX_STATFS
parameter_list|(
name|isv3
parameter_list|)
value|((isv3) ? NFSX_NFSV3STATFS : NFSX_NFSSTATFS)
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
comment|/* And leasing (nqnfs) procedure numbers */
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
name|NFS_NPROCS
value|25
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
comment|/* Conversion macros */
end_comment

begin_define
unit|extern int		vttoif_tab[];
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
value|txdr_unsigned((m)& 07777)
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
name|vtonfsv2_type
parameter_list|(
name|a
parameter_list|)
value|txdr_unsigned(nfsv2_type[((long)(a))])
end_define

begin_define
define|#
directive|define
name|vtonfsv3_type
parameter_list|(
name|a
parameter_list|)
value|txdr_unsigned(nfsv3_type[((long)(a))])
end_define

begin_define
define|#
directive|define
name|nfsv2tov_type
parameter_list|(
name|a
parameter_list|)
value|nv2tov_type[fxdr_unsigned(u_long,(a))&0x7]
end_define

begin_define
define|#
directive|define
name|nfsv3tov_type
parameter_list|(
name|a
parameter_list|)
value|nv3tov_type[fxdr_unsigned(u_long,(a))&0x7]
end_define

begin_comment
comment|/* File types */
end_comment

begin_comment
unit|typedef enum { NFNON=0, NFREG=1, NFDIR=2, NFBLK=3, NFCHR=4, NFLNK=5, 	NFSOCK=6, NFFIFO=7 } nfstype;
comment|/* Structs for common parts of the rpc's */
end_comment

begin_comment
unit|struct nfsv2_time { 	u_long	nfsv2_sec; 	u_long	nfsv2_usec; }; typedef struct nfsv2_time	nfstime2;  struct nfsv3_time { 	u_long	nfsv3_sec; 	u_long	nfsv3_nsec; }; typedef struct nfsv3_time	nfstime3;
comment|/*  * Quads are defined as arrays of 2 longs to ensure dense packing for the  * protocol and to facilitate xdr conversion.  */
end_comment

begin_comment
unit|struct nfs_uquad { 	u_long	nfsuquad[2]; }; typedef	struct nfs_uquad	nfsuint64;
comment|/*  * File attributes and setable attributes. These structures cover both  * NFS version 2 and the version 3 protocol. Note that the union is only  * used so that one pointer can refer to both variants. These structures  * go out on the wire and must be densely packed, so no quad data types  * are used. (all fields are longs or u_longs or structures of same)  * NB: You can't do sizeof(struct nfs_fattr), you must use the  *     NFSX_FATTR(v3) macro.  */
end_comment

begin_comment
unit|struct nfs_fattr { 	u_long	fa_type; 	u_long	fa_mode; 	u_long	fa_nlink; 	u_long	fa_uid; 	u_long	fa_gid; 	union { 		struct { 			u_long		nfsv2fa_size; 			u_long		nfsv2fa_blocksize; 			u_long		nfsv2fa_rdev; 			u_long		nfsv2fa_blocks; 			u_long		nfsv2fa_fsid; 			u_long		nfsv2fa_fileid; 			nfstime2	nfsv2fa_atime; 			nfstime2	nfsv2fa_mtime; 			nfstime2	nfsv2fa_ctime; 		} fa_nfsv2; 		struct { 			nfsuint64	nfsv3fa_size; 			nfsuint64	nfsv3fa_used; 			nfsuint64	nfsv3fa_rdev; 			nfsuint64	nfsv3fa_fsid; 			nfsuint64	nfsv3fa_fileid; 			nfstime3	nfsv3fa_atime; 			nfstime3	nfsv3fa_mtime; 			nfstime3	nfsv3fa_ctime; 		} fa_nfsv3; 	} fa_un; };
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

begin_endif
unit|struct nfsv2_sattr { 	u_long		sa_mode; 	u_long		sa_uid; 	u_long		sa_gid; 	u_long		sa_size; 	nfstime2	sa_atime; 	nfstime2	sa_mtime; };  struct nfsv2_statfs { 	u_long	sf_tsize; 	u_long	sf_bsize; 	u_long	sf_blocks; 	u_long	sf_bfree; 	u_long	sf_bavail; };  struct nfsv3_fsstat { 	nfsuint64	sf_tbytes; 	nfsuint64	sf_fbytes; 	nfsuint64	sf_abytes; 	nfsuint64	sf_tfiles; 	nfsuint64	sf_ffiles; 	nfsuint64	sf_afiles; 	u_long		sf_invarsec; };  struct nfsv3_fsinfo { 	u_long		fs_rtmax; 	u_long		fs_rtpref; 	u_long		fs_rtmult; 	u_long		fs_wtmax; 	u_long		fs_wtpref; 	u_long		fs_wtmult; 	u_long		fs_dtpref; 	nfsuint64	fs_maxfilesize; 	nfstime3	fs_time_delta; 	u_long		fs_properties; };
endif|#
directive|endif
end_endif

end_unit

