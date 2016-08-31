begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/nfs_prot/nfs_prot_nextstep.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMU_NFS_PROT_H
end_ifndef

begin_define
define|#
directive|define
name|_AMU_NFS_PROT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPCSVC_NFS_PROT_H
end_ifdef

begin_include
include|#
directive|include
file|<rpcsvc/nfs_prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPCSVC_NFS_PROT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BSD_RPC_RPC_H
end_ifdef

begin_include
include|#
directive|include
file|<bsd/rpc/rpc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BSD_RPC_RPC_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_STAT_H */
end_comment

begin_comment
comment|/*  * odd problems happen during configuration and nextstep's /bin/cc  * gets strange errors from /bin/sh.  I suspect it may be a conflict  * over some memory, a bad /bin/cc, or even kernel bug.  * this is what I get, as a result of running cc inside configure:  *  /bin/cc -o conftest -g -O2 -D_POSIX_SOURCE conftest.c -lrpcsvc  *  configure:2294: illegal external declaration, found `#'  *  configure:2388: illegal file name 'AMU_NFS_PROTOCOL_HEADER'  *  configure:2416: illegal external declaration, found `{'  * I have no explanation for it... -Erez  * Solution: don't use /bin/cc, but gcc 2.7.2.1 or better!  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* cannot include this file b/c it refers to non-existing headers */
end_comment

begin_include
include|#
directive|include
file|<bsd/nfs/nfs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/*  * MACROS:  */
end_comment

begin_comment
comment|/* ugly: fix up nextstep's nfs mount type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOUNT_TYPE_NFS___off_no_longer_needed
end_ifdef

begin_undef
undef|#
directive|undef
name|MOUNT_TYPE_UFS
end_undef

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|MOUNT_UFS
end_define

begin_undef
undef|#
directive|undef
name|MOUNT_TYPE_NFS
end_undef

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|MOUNT_NFS
end_define

begin_undef
undef|#
directive|undef
name|MOUNT_TYPE_PCFS
end_undef

begin_define
define|#
directive|define
name|MOUNT_TYPE_PCFS
value|MOUNT_PC
end_define

begin_undef
undef|#
directive|undef
name|MOUNT_TYPE_LOFS
end_undef

begin_define
define|#
directive|define
name|MOUNT_TYPE_LOFS
value|MOUNT_LO
end_define

begin_undef
undef|#
directive|undef
name|MOUNT_TYPE_SPECFS
end_undef

begin_define
define|#
directive|define
name|MOUNT_TYPE_SPECFS
value|MOUNT_SPECFS
end_define

begin_undef
undef|#
directive|undef
name|MOUNT_TYPE_CFS
end_undef

begin_define
define|#
directive|define
name|MOUNT_TYPE_CFS
value|MOUNT_CFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOUNT_TYPE_NFS */
end_comment

begin_define
define|#
directive|define
name|dr_drok_u
value|diropres
end_define

begin_define
define|#
directive|define
name|ca_attributes
value|attributes
end_define

begin_define
define|#
directive|define
name|ca_where
value|where
end_define

begin_define
define|#
directive|define
name|da_fhandle
value|dir
end_define

begin_define
define|#
directive|define
name|da_name
value|name
end_define

begin_define
define|#
directive|define
name|dl_entries
value|entries
end_define

begin_define
define|#
directive|define
name|dl_eof
value|eof
end_define

begin_define
define|#
directive|define
name|dr_status
value|status
end_define

begin_define
define|#
directive|define
name|dr_u
value|diropres_u
end_define

begin_define
define|#
directive|define
name|drok_attributes
value|attributes
end_define

begin_define
define|#
directive|define
name|drok_fhandle
value|file
end_define

begin_define
define|#
directive|define
name|fh_data
value|data
end_define

begin_define
define|#
directive|define
name|la_fhandle
value|from
end_define

begin_define
define|#
directive|define
name|la_to
value|to
end_define

begin_define
define|#
directive|define
name|na_atime
value|atime
end_define

begin_define
define|#
directive|define
name|na_blocks
value|blocks
end_define

begin_define
define|#
directive|define
name|na_blocksize
value|blocksize
end_define

begin_define
define|#
directive|define
name|na_ctime
value|ctime
end_define

begin_define
define|#
directive|define
name|na_fileid
value|fileid
end_define

begin_define
define|#
directive|define
name|na_fsid
value|fsid
end_define

begin_define
define|#
directive|define
name|na_gid
value|gid
end_define

begin_define
define|#
directive|define
name|na_mode
value|mode
end_define

begin_define
define|#
directive|define
name|na_mtime
value|mtime
end_define

begin_define
define|#
directive|define
name|na_nlink
value|nlink
end_define

begin_define
define|#
directive|define
name|na_rdev
value|rdev
end_define

begin_define
define|#
directive|define
name|na_size
value|size
end_define

begin_define
define|#
directive|define
name|na_type
value|type
end_define

begin_define
define|#
directive|define
name|na_uid
value|uid
end_define

begin_define
define|#
directive|define
name|ne_cookie
value|cookie
end_define

begin_define
define|#
directive|define
name|ne_fileid
value|fileid
end_define

begin_define
define|#
directive|define
name|ne_name
value|name
end_define

begin_define
define|#
directive|define
name|ne_nextentry
value|nextentry
end_define

begin_define
define|#
directive|define
name|ns_attr_u
value|attributes
end_define

begin_define
define|#
directive|define
name|ns_status
value|status
end_define

begin_define
define|#
directive|define
name|ns_u
value|attrstat_u
end_define

begin_define
define|#
directive|define
name|nt_seconds
value|seconds
end_define

begin_define
define|#
directive|define
name|nt_useconds
value|useconds
end_define

begin_define
define|#
directive|define
name|ra_count
value|count
end_define

begin_define
define|#
directive|define
name|ra_fhandle
value|file
end_define

begin_define
define|#
directive|define
name|ra_offset
value|offset
end_define

begin_define
define|#
directive|define
name|ra_totalcount
value|totalcount
end_define

begin_define
define|#
directive|define
name|raok_attributes
value|attributes
end_define

begin_define
define|#
directive|define
name|raok_len_u
value|data_len
end_define

begin_define
define|#
directive|define
name|raok_u
value|data
end_define

begin_define
define|#
directive|define
name|raok_val_u
value|data_val
end_define

begin_define
define|#
directive|define
name|rda_cookie
value|cookie
end_define

begin_define
define|#
directive|define
name|rda_count
value|count
end_define

begin_define
define|#
directive|define
name|rda_fhandle
value|dir
end_define

begin_define
define|#
directive|define
name|rdr_reply_u
value|reply
end_define

begin_define
define|#
directive|define
name|rdr_status
value|status
end_define

begin_define
define|#
directive|define
name|rdr_u
value|readdirres_u
end_define

begin_define
define|#
directive|define
name|rlr_data_u
value|data
end_define

begin_define
define|#
directive|define
name|rlr_status
value|status
end_define

begin_define
define|#
directive|define
name|rlr_u
value|readlinkres_u
end_define

begin_define
define|#
directive|define
name|rna_from
value|from
end_define

begin_define
define|#
directive|define
name|rna_to
value|to
end_define

begin_define
define|#
directive|define
name|rr_reply_u
value|reply
end_define

begin_define
define|#
directive|define
name|rr_status
value|status
end_define

begin_define
define|#
directive|define
name|rr_u
value|readres_u
end_define

begin_define
define|#
directive|define
name|sa_atime
value|atime
end_define

begin_define
define|#
directive|define
name|sa_gid
value|gid
end_define

begin_define
define|#
directive|define
name|sa_mode
value|mode
end_define

begin_define
define|#
directive|define
name|sa_mtime
value|mtime
end_define

begin_define
define|#
directive|define
name|sa_size
value|size
end_define

begin_define
define|#
directive|define
name|sa_uid
value|uid
end_define

begin_define
define|#
directive|define
name|sag_attributes
value|attributes
end_define

begin_define
define|#
directive|define
name|sag_fhandle
value|file
end_define

begin_define
define|#
directive|define
name|sfr_reply_u
value|reply
end_define

begin_define
define|#
directive|define
name|sfr_status
value|status
end_define

begin_define
define|#
directive|define
name|sfr_u
value|statfsres_u
end_define

begin_define
define|#
directive|define
name|sfrok_bavail
value|bavail
end_define

begin_define
define|#
directive|define
name|sfrok_bfree
value|bfree
end_define

begin_define
define|#
directive|define
name|sfrok_blocks
value|blocks
end_define

begin_define
define|#
directive|define
name|sfrok_bsize
value|bsize
end_define

begin_define
define|#
directive|define
name|sfrok_tsize
value|tsize
end_define

begin_define
define|#
directive|define
name|sla_attributes
value|attributes
end_define

begin_define
define|#
directive|define
name|sla_from
value|from
end_define

begin_define
define|#
directive|define
name|sla_to
value|to
end_define

begin_define
define|#
directive|define
name|wra_beginoffset
value|beginoffset
end_define

begin_define
define|#
directive|define
name|wra_fhandle
value|file
end_define

begin_define
define|#
directive|define
name|wra_len_u
value|data_len
end_define

begin_define
define|#
directive|define
name|wra_offset
value|offset
end_define

begin_define
define|#
directive|define
name|wra_totalcount
value|totalcount
end_define

begin_define
define|#
directive|define
name|wra_u
value|data
end_define

begin_define
define|#
directive|define
name|wra_val_u
value|data_val
end_define

begin_comment
comment|/* map field names */
end_comment

begin_define
define|#
directive|define
name|ex_dir
value|ex_name
end_define

begin_define
define|#
directive|define
name|gr_name
value|g_name
end_define

begin_define
define|#
directive|define
name|gr_next
value|g_next
end_define

begin_define
define|#
directive|define
name|ml_directory
value|ml_path
end_define

begin_define
define|#
directive|define
name|ml_hostname
value|ml_name
end_define

begin_define
define|#
directive|define
name|ml_next
value|ml_nxt
end_define

begin_comment
comment|/*  * NFS mount option flags  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SOFT
value|0x001
end_define

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WSIZE
value|0x002
end_define

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RSIZE
value|0x004
end_define

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_TIMEO
value|0x008
end_define

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RETRANS
value|0x010
end_define

begin_comment
comment|/* set number of request retries */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HOSTNAME
value|0x020
end_define

begin_comment
comment|/* set hostname for error printf */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x040
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOAC
value|0x080
end_define

begin_comment
comment|/* don't cache attributes */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACREGMIN
value|0x0100
end_define

begin_comment
comment|/* set min secs for file attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACREGMAX
value|0x0200
end_define

begin_comment
comment|/* set max secs for file attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACDIRMIN
value|0x0400
end_define

begin_comment
comment|/* set min secs for dir attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_ACDIRMAX
value|0x0800
end_define

begin_comment
comment|/* set max secs for dir attr cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SECURE
value|0x1000
end_define

begin_comment
comment|/* secure mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOCTO
value|0x2000
end_define

begin_comment
comment|/* no close-to-open consistency */
end_comment

begin_define
define|#
directive|define
name|NFS_PORT
value|2049
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MAXDATA
end_ifndef

begin_define
define|#
directive|define
name|NFS_MAXDATA
value|8192
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFS_MAXDATA */
end_comment

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
name|NFS_COOKIESIZE
value|4
end_define

begin_define
define|#
directive|define
name|MNTPATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|MNTNAMLEN
value|255
end_define

begin_define
define|#
directive|define
name|NFSMODE_FMT
value|0170000
end_define

begin_define
define|#
directive|define
name|NFSMODE_DIR
value|0040000
end_define

begin_define
define|#
directive|define
name|NFSMODE_CHR
value|0020000
end_define

begin_define
define|#
directive|define
name|NFSMODE_BLK
value|0060000
end_define

begin_define
define|#
directive|define
name|NFSMODE_REG
value|0100000
end_define

begin_define
define|#
directive|define
name|NFSMODE_LNK
value|0120000
end_define

begin_define
define|#
directive|define
name|NFSMODE_SOCK
value|0140000
end_define

begin_define
define|#
directive|define
name|NFSMODE_FIFO
value|0010000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_PROGRAM
end_ifndef

begin_define
define|#
directive|define
name|NFS_PROGRAM
value|((u_long)100003)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFS_PROGRAM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_VERSION
end_ifndef

begin_define
define|#
directive|define
name|NFS_VERSION
value|((u_long)2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFS_VERSION */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_NULL
value|((u_long)0)
end_define

begin_define
define|#
directive|define
name|NFSPROC_GETATTR
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|NFSPROC_SETATTR
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|NFSPROC_ROOT
value|((u_long)3)
end_define

begin_define
define|#
directive|define
name|NFSPROC_LOOKUP
value|((u_long)4)
end_define

begin_define
define|#
directive|define
name|NFSPROC_READLINK
value|((u_long)5)
end_define

begin_define
define|#
directive|define
name|NFSPROC_READ
value|((u_long)6)
end_define

begin_define
define|#
directive|define
name|NFSPROC_WRITECACHE
value|((u_long)7)
end_define

begin_define
define|#
directive|define
name|NFSPROC_WRITE
value|((u_long)8)
end_define

begin_define
define|#
directive|define
name|NFSPROC_CREATE
value|((u_long)9)
end_define

begin_define
define|#
directive|define
name|NFSPROC_REMOVE
value|((u_long)10)
end_define

begin_define
define|#
directive|define
name|NFSPROC_RENAME
value|((u_long)11)
end_define

begin_define
define|#
directive|define
name|NFSPROC_LINK
value|((u_long)12)
end_define

begin_define
define|#
directive|define
name|NFSPROC_SYMLINK
value|((u_long)13)
end_define

begin_define
define|#
directive|define
name|NFSPROC_MKDIR
value|((u_long)14)
end_define

begin_define
define|#
directive|define
name|NFSPROC_RMDIR
value|((u_long)15)
end_define

begin_define
define|#
directive|define
name|NFSPROC_READDIR
value|((u_long)16)
end_define

begin_define
define|#
directive|define
name|NFSPROC_STATFS
value|((u_long)17)
end_define

begin_comment
comment|/*  * fix up or complete other some definitions...  */
end_comment

begin_define
define|#
directive|define
name|WNOHANG
value|01
end_define

begin_define
define|#
directive|define
name|WUNTRACED
value|02
end_define

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|status
parameter_list|)
value|((status)& 0100)
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|status
parameter_list|)
value|(int)(WIFSTOPPED(status) ? \ 				      (((status)>> 8)& 0177) : -1)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|status
parameter_list|)
value|( !WIFEXITED(status)&& \ 				  !WIFSTOPPED(status) )
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|status
parameter_list|)
value|(int)(WIFSIGNALED(status) ? \                                       ((status)& 0177) : -1)
end_define

begin_comment
comment|/* define missing macros */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFMT
end_ifdef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& (S_IFMT)) == (S_IFDIR))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not S_IFMT */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& (_S_IFMT)) == (_S_IFDIR))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not S_IFMT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not S_ISDIR */
end_comment

begin_comment
comment|/*  * ENUMS:  */
end_comment

begin_enum
enum|enum
name|nfstype
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
name|NFBAD
init|=
literal|7
block|,
name|NFFIFO
init|=
literal|8
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|nfsstat
block|{
name|NFS_OK
init|=
literal|0
block|,
comment|/* no error */
name|NFSERR_PERM
init|=
name|EPERM
block|,
comment|/* Not owner */
name|NFSERR_NOENT
init|=
name|ENOENT
block|,
comment|/* No such file or directory */
name|NFSERR_IO
init|=
name|EIO
block|,
comment|/* I/O error */
name|NFSERR_NXIO
init|=
name|ENXIO
block|,
comment|/* No such device or address */
name|NFSERR_ACCES
init|=
name|EACCES
block|,
comment|/* Permission denied */
name|NFSERR_EXIST
init|=
name|EEXIST
block|,
comment|/* File exists */
name|NFSERR_NODEV
init|=
name|ENODEV
block|,
comment|/* No such device */
name|NFSERR_NOTDIR
init|=
name|ENOTDIR
block|,
comment|/* Not a directory */
name|NFSERR_ISDIR
init|=
name|EISDIR
block|,
comment|/* Is a directory */
name|NFSERR_FBIG
init|=
name|EFBIG
block|,
comment|/* File too large */
name|NFSERR_NOSPC
init|=
name|ENOSPC
block|,
comment|/* No space left on device */
name|NFSERR_ROFS
init|=
name|EROFS
block|,
comment|/* Read-only file system */
name|NFSERR_NAMETOOLONG
init|=
name|ENAMETOOLONG
block|,
comment|/* File name too long */
name|NFSERR_NOTEMPTY
init|=
name|ENOTEMPTY
block|,
comment|/* Directory not empty */
name|NFSERR_DQUOT
init|=
name|EDQUOT
block|,
comment|/* Disc quota exceeded */
name|NFSERR_STALE
init|=
name|ESTALE
block|,
comment|/* Stale NFS file handle */
name|NFSERR_WFLUSH
comment|/* write cache flushed */
block|}
enum|;
end_enum

begin_comment
comment|/*  * TYPEDEFS:  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|dirpath
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|filename
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|name
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|nfspath
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|fhandle
index|[
name|NFS_FHSIZE
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|nfscookie
index|[
name|NFS_COOKIESIZE
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|ftype
name|ftype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|nfsstat
name|nfsstat
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|nfstype
name|nfsftype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|fhandle
name|fhandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|attrstat
name|nfsattrstat
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|createargs
name|nfscreateargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dirlist
name|nfsdirlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|diropargs
name|nfsdiropargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|diropokres
name|nfsdiropokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|diropres
name|nfsdiropres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|entry
name|nfsentry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|exports
modifier|*
name|exports
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|exports
name|exportnode
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fattr
name|nfsfattr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fhstatus
name|fhstatus
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|groups
modifier|*
name|groups
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|groups
name|groupnode
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|linkargs
name|nfslinkargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mountlist
modifier|*
name|mountlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mountlist
name|mountbody
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfs_fh
name|nfs_fh
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfstime
name|nfstime
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|readargs
name|nfsreadargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|readdirargs
name|nfsreaddirargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|readdirres
name|nfsreaddirres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|readlinkres
name|nfsreadlinkres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|readokres
name|nfsreadokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|readres
name|nfsreadres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|renameargs
name|nfsrenameargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sattr
name|nfssattr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sattrargs
name|nfssattrargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|statfsokres
name|nfsstatfsokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|statfsres
name|nfsstatfsres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|symlinkargs
name|nfssymlinkargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|writeargs
name|nfswriteargs
typedef|;
end_typedef

begin_comment
comment|/*  * EXTERNALS:  */
end_comment

begin_function_decl
specifier|extern
name|nfsattrstat
modifier|*
name|nfsproc_getattr_2_svc
parameter_list|(
name|nfs_fh
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsattrstat
modifier|*
name|nfsproc_setattr_2_svc
parameter_list|(
name|nfssattrargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsattrstat
modifier|*
name|nfsproc_write_2_svc
parameter_list|(
name|nfswriteargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsdiropres
modifier|*
name|nfsproc_create_2_svc
parameter_list|(
name|nfscreateargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsdiropres
modifier|*
name|nfsproc_lookup_2_svc
parameter_list|(
name|nfsdiropargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsdiropres
modifier|*
name|nfsproc_mkdir_2_svc
parameter_list|(
name|nfscreateargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsreaddirres
modifier|*
name|nfsproc_readdir_2_svc
parameter_list|(
name|nfsreaddirargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsreadlinkres
modifier|*
name|nfsproc_readlink_2_svc
parameter_list|(
name|nfs_fh
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsreadres
modifier|*
name|nfsproc_read_2_svc
parameter_list|(
name|nfsreadargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_link_2_svc
parameter_list|(
name|nfslinkargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_remove_2_svc
parameter_list|(
name|nfsdiropargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_rename_2_svc
parameter_list|(
name|nfsrenameargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_rmdir_2_svc
parameter_list|(
name|nfsdiropargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_symlink_2_svc
parameter_list|(
name|nfssymlinkargs
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nfsstatfsres
modifier|*
name|nfsproc_statfs_2_svc
parameter_list|(
name|nfs_fh
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|nfsproc_null_2_svc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|nfsproc_root_2_svc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|nfsproc_writecache_2_svc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_attrstat
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsattrstat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_createargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfscreateargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_dirlist
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsdirlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_diropargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsdiropargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_diropokres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsdiropokres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_diropres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsdiropres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_entry
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_fattr
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsfattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_filename
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|filename
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_ftype
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsftype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_linkargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfslinkargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_mountlist
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|mountlist
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_nfs_fh
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfs_fh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_nfscookie
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfscookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_nfspath
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfspath
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_nfsstat
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsstat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_nfstime
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfstime
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_readargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsreadargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_readdirargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsreaddirargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_readdirres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsreaddirres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_readlinkres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsreadlinkres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_readokres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsreadokres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_readres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsreadres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_renameargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsrenameargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_sattr
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfssattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_sattrargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfssattrargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_statfsokres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsstatfsokres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_statfsres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfsstatfsres
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_symlinkargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfssymlinkargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_writeargs
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|nfswriteargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

begin_struct
struct|struct
name|nfs_args
block|{
name|struct
name|sockaddr_in
modifier|*
name|addr
decl_stmt|;
comment|/* file server address */
name|caddr_t
name|fh
decl_stmt|;
comment|/* File handle to be mounted */
name|int
name|flags
decl_stmt|;
comment|/* flags */
name|int
name|wsize
decl_stmt|;
comment|/* write size in bytes */
name|int
name|rsize
decl_stmt|;
comment|/* read size in bytes */
name|int
name|timeo
decl_stmt|;
comment|/* initial timeout in .1 secs */
name|int
name|retrans
decl_stmt|;
comment|/* times to retry send */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's hostname */
name|int
name|acregmin
decl_stmt|;
comment|/* attr cache file min secs */
name|int
name|acregmax
decl_stmt|;
comment|/* attr cache file max secs */
name|int
name|acdirmin
decl_stmt|;
comment|/* attr cache dir min secs */
name|int
name|acdirmax
decl_stmt|;
comment|/* attr cache dir max secs */
name|char
modifier|*
name|netname
decl_stmt|;
comment|/* server's netname */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs_fh
block|{
name|char
name|data
index|[
name|NFS_FHSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfstime
block|{
name|u_int
name|nt_seconds
decl_stmt|;
name|u_int
name|nt_useconds
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fattr
block|{
name|nfsftype
name|na_type
decl_stmt|;
name|u_int
name|na_mode
decl_stmt|;
name|u_int
name|na_nlink
decl_stmt|;
name|u_int
name|na_uid
decl_stmt|;
name|u_int
name|na_gid
decl_stmt|;
name|u_int
name|na_size
decl_stmt|;
name|u_int
name|na_blocksize
decl_stmt|;
name|u_int
name|na_rdev
decl_stmt|;
name|u_int
name|na_blocks
decl_stmt|;
name|u_int
name|na_fsid
decl_stmt|;
name|u_int
name|na_fileid
decl_stmt|;
name|nfstime
name|na_atime
decl_stmt|;
name|nfstime
name|na_mtime
decl_stmt|;
name|nfstime
name|na_ctime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sattr
block|{
name|u_int
name|sa_mode
decl_stmt|;
name|u_int
name|sa_uid
decl_stmt|;
name|u_int
name|sa_gid
decl_stmt|;
name|u_int
name|sa_size
decl_stmt|;
name|nfstime
name|sa_atime
decl_stmt|;
name|nfstime
name|sa_mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|attrstat
block|{
name|nfsstat
name|ns_status
decl_stmt|;
union|union
block|{
name|nfsfattr
name|ns_attr_u
decl_stmt|;
block|}
name|ns_u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sattrargs
block|{
name|nfs_fh
name|sag_fhandle
decl_stmt|;
name|nfssattr
name|sag_attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|diropargs
block|{
name|nfs_fh
name|da_fhandle
decl_stmt|;
comment|/* was dir */
name|filename
name|da_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|diropokres
block|{
name|nfs_fh
name|drok_fhandle
decl_stmt|;
name|nfsfattr
name|drok_attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|diropres
block|{
name|nfsstat
name|dr_status
decl_stmt|;
comment|/* was status */
union|union
block|{
name|nfsdiropokres
name|dr_drok_u
decl_stmt|;
comment|/* was diropres */
block|}
name|dr_u
union|;
comment|/* was diropres_u */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|readlinkres
block|{
name|nfsstat
name|rlr_status
decl_stmt|;
union|union
block|{
name|nfspath
name|rlr_data_u
decl_stmt|;
block|}
name|rlr_u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|readargs
block|{
name|nfs_fh
name|ra_fhandle
decl_stmt|;
name|u_int
name|ra_offset
decl_stmt|;
name|u_int
name|ra_count
decl_stmt|;
name|u_int
name|ra_totalcount
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|readokres
block|{
name|nfsfattr
name|raok_attributes
decl_stmt|;
struct|struct
block|{
name|u_int
name|raok_len_u
decl_stmt|;
name|char
modifier|*
name|raok_val_u
decl_stmt|;
block|}
name|raok_u
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|readres
block|{
name|nfsstat
name|rr_status
decl_stmt|;
union|union
block|{
name|nfsreadokres
name|rr_reply_u
decl_stmt|;
block|}
name|rr_u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|writeargs
block|{
name|nfs_fh
name|wra_fhandle
decl_stmt|;
name|u_int
name|wra_beginoffset
decl_stmt|;
name|u_int
name|wra_offset
decl_stmt|;
name|u_int
name|wra_totalcount
decl_stmt|;
struct|struct
block|{
name|u_int
name|wra_len_u
decl_stmt|;
name|char
modifier|*
name|wra_val_u
decl_stmt|;
block|}
name|wra_u
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|createargs
block|{
name|nfsdiropargs
name|ca_where
decl_stmt|;
name|nfssattr
name|ca_attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|renameargs
block|{
name|nfsdiropargs
name|rna_from
decl_stmt|;
name|nfsdiropargs
name|rna_to
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linkargs
block|{
name|nfs_fh
name|la_fhandle
decl_stmt|;
name|nfsdiropargs
name|la_to
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|symlinkargs
block|{
name|nfsdiropargs
name|sla_from
decl_stmt|;
name|nfspath
name|sla_to
decl_stmt|;
name|nfssattr
name|sla_attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|readdirargs
block|{
name|nfs_fh
name|rda_fhandle
decl_stmt|;
name|nfscookie
name|rda_cookie
decl_stmt|;
name|u_int
name|rda_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|entry
block|{
name|u_int
name|ne_fileid
decl_stmt|;
name|filename
name|ne_name
decl_stmt|;
name|nfscookie
name|ne_cookie
decl_stmt|;
name|nfsentry
modifier|*
name|ne_nextentry
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dirlist
block|{
name|nfsentry
modifier|*
name|dl_entries
decl_stmt|;
name|bool_t
name|dl_eof
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|readdirres
block|{
name|nfsstat
name|rdr_status
decl_stmt|;
union|union
block|{
name|nfsdirlist
name|rdr_reply_u
decl_stmt|;
block|}
name|rdr_u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|statfsokres
block|{
name|u_int
name|sfrok_tsize
decl_stmt|;
name|u_int
name|sfrok_bsize
decl_stmt|;
name|u_int
name|sfrok_blocks
decl_stmt|;
name|u_int
name|sfrok_bfree
decl_stmt|;
name|u_int
name|sfrok_bavail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|statfsres
block|{
name|nfsstat
name|sfr_status
decl_stmt|;
union|union
block|{
name|nfsstatfsokres
name|sfr_reply_u
decl_stmt|;
block|}
name|sfr_u
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMU_NFS_PROT_H */
end_comment

end_unit

