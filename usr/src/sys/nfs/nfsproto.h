begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nfsproto.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * nfs definitions as per the version 2 specs  */
end_comment

begin_comment
comment|/*  * Constants as defined in the Sun NFS Version 2 spec.  * "Network File System Protocol Specification" in the  * Manual "Networking on the Sun Workstation", Part #800-1324-03, Rev B  */
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
name|NFS_MAXDATA
value|8192
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
name|NFS_NPROCS
value|18
end_define

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

begin_define
define|#
directive|define
name|vtonfs_mode
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|txdr_unsigned(MAKEIMODE(t,m))
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
value|v_type[fxdr_unsigned(u_long, (a))]
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

