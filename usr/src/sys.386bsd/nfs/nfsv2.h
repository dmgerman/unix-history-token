begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsv2.h	7.8 (Berkeley) 6/28/90  *  * PATCHES MAGIC                LEVEL   PATCH THAT GOT US HERE  * --------------------         -----   ----------------------  * CURRENT PATCH LEVEL:         1       00053  * --------------------         -----   ----------------------  *  * 08 Sep 92    Rick "gopher I"         Fix "reserved port" bug, fixed for  *                                              AIX3.2 NFS clients  */
end_comment

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
name|NFS_NPROCS
value|18
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
name|NFSERR_NAMETOOLONG
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
name|NFSX_FATTR
value|68
end_define

begin_define
define|#
directive|define
name|NFSX_SATTR
value|32
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
name|NFSX_STATFS
value|20
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
name|NFSPROC_ROOT
value|3
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_NOOP
value|3
end_define

begin_comment
comment|/* Fake for err returns XXX 08 Sep 92*/
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
value|7
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
comment|/* Conversion macros */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vttoif_tab
index|[]
decl_stmt|;
end_decl_stmt

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
name|tv_sec
decl_stmt|;
name|u_long
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

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
name|u_long
name|fa_size
decl_stmt|;
name|u_long
name|fa_blocksize
decl_stmt|;
name|u_long
name|fa_rdev
decl_stmt|;
name|u_long
name|fa_blocks
decl_stmt|;
name|u_long
name|fa_fsid
decl_stmt|;
name|u_long
name|fa_fileid
decl_stmt|;
name|struct
name|nfsv2_time
name|fa_atime
decl_stmt|;
name|struct
name|nfsv2_time
name|fa_mtime
decl_stmt|;
name|struct
name|nfsv2_time
name|fa_ctime
decl_stmt|;
block|}
struct|;
end_struct

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
name|u_long
name|sa_size
decl_stmt|;
name|struct
name|nfsv2_time
name|sa_atime
decl_stmt|;
name|struct
name|nfsv2_time
name|sa_mtime
decl_stmt|;
block|}
struct|;
end_struct

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
block|}
struct|;
end_struct

end_unit

