begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/nfs_prot/nfs_prot_hpux11.h  *  */
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

begin_comment
comment|/*  * NOTE: HPUX 11 is missing many header definitions which had to be  * guessed and copied over from HPUX 10.20.  */
end_comment

begin_comment
comment|/* don't include this file as it isn't needed on hpux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIUSER_H
end_ifndef

begin_define
define|#
directive|define
name|_TIUSER_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIUSER_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIUSER_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_TIUSER_INCLUDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIUSER_INCLUDED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIUSER_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIUSER_INCLUDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TIUSER_INCLUDED */
end_comment

begin_comment
comment|/* if T_NULL is defined, undefine it due to a conflict with<arpa/nameser.h> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|T_NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|T_NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T_NULL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_EXPORT_H_not
end_ifdef

begin_comment
comment|/* don't include this b/c it'll get included twice */
end_comment

begin_include
include|#
directive|include
file|<nfs/export.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_EXPORT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_NFSV2_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/nfsv2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_NFSV2_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_RPCV2_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_RPCV2_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_NFS_H
end_ifdef

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
comment|/* HAVE_NFS_NFS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_NFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/nfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_NFS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPCSVC_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<rpcsvc/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPCSVC_MOUNT_H */
end_comment

begin_comment
comment|/*  * MACROS  */
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
name|HOSTNAMESZ
value|32
end_define

begin_comment
comment|/* Max size of hostname in struct nfs_args */
end_comment

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
name|NFSMNT_KNCONF
value|0x4000
end_define

begin_comment
comment|/* transport's knetconfig structure */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_GRPID
value|0x8000
end_define

begin_comment
comment|/* System V-style gid inheritance */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RPCTIMESYNC
value|0x10000
end_define

begin_comment
comment|/* use RPC to do secure NFS time sync */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_KERBEROS
value|0x20000
end_define

begin_comment
comment|/* use kerberos credentials */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_POSIX
value|0x40000
end_define

begin_comment
comment|/* static pathconf kludge info */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_LLOCK
value|0x80000
end_define

begin_comment
comment|/* Local locking (no lock manager) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_REMOUNT
value|0x100000
end_define

begin_comment
comment|/* Remount from r/o to r/w */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_FSNAME
value|0x1000000
end_define

begin_comment
comment|/* FS name e.g. "host:/path/" */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NODEVS
value|0x2000000
end_define

begin_comment
comment|/* no devices access (default on) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_IGNORE
value|0x4000000
end_define

begin_comment
comment|/* ignore in mnttab */
end_comment

begin_define
define|#
directive|define
name|MS_FSS
value|0x00
end_define

begin_comment
comment|/* fake flag to do nothing */
end_comment

begin_comment
comment|/*  * ENUMS:  */
end_comment

begin_comment
comment|/*  * Error status  * Should include all possible net errors.  * For now we just cast errno into an enum nfsstat.  */
end_comment

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
literal|1
block|,
comment|/* Not owner */
name|NFSERR_NOENT
init|=
literal|2
block|,
comment|/* No such file or directory */
name|NFSERR_IO
init|=
literal|5
block|,
comment|/* I/O error */
name|NFSERR_NXIO
init|=
literal|6
block|,
comment|/* No such device or address */
name|NFSERR_ACCES
init|=
literal|13
block|,
comment|/* Permission denied */
name|NFSERR_EXIST
init|=
literal|17
block|,
comment|/* File exists */
name|NFSERR_XDEV
init|=
literal|18
block|,
comment|/* Cross-device link */
name|NFSERR_NODEV
init|=
literal|19
block|,
comment|/* No such device */
name|NFSERR_NOTDIR
init|=
literal|20
block|,
comment|/* Not a directory */
name|NFSERR_ISDIR
init|=
literal|21
block|,
comment|/* Is a directory */
name|NFSERR_INVAL
init|=
literal|22
block|,
comment|/* Invalid argument */
name|NFSERR_FBIG
init|=
literal|27
block|,
comment|/* File too large */
name|NFSERR_NOSPC
init|=
literal|28
block|,
comment|/* No space left on device */
name|NFSERR_ROFS
init|=
literal|30
block|,
comment|/* Read-only file system */
name|NFSERR_OPNOTSUPP
init|=
literal|45
block|,
comment|/* Operation not supported */
name|NFSERR_NAMETOOLONG
init|=
literal|63
block|,
comment|/* File name too long */
name|NFSERR_NOTEMPTY
init|=
literal|66
block|,
comment|/* Directory not empty */
name|NFSERR_DQUOT
init|=
literal|69
block|,
comment|/* Disc quota exceeded */
name|NFSERR_STALE
init|=
literal|70
block|,
comment|/* Stale NFS file handle */
name|NFSERR_REMOTE
init|=
literal|71
block|,
comment|/* Object is remote */
name|NFSERR_WFLUSH
comment|/* write cache flushed */
block|}
enum|;
end_enum

begin_comment
comment|/*  * File types  */
end_comment

begin_enum
enum|enum
name|nfsftype
block|{
name|NFNON
block|,
name|NFREG
block|,
comment|/* regular file */
name|NFDIR
block|,
comment|/* directory */
name|NFBLK
block|,
comment|/* block special */
name|NFCHR
block|,
comment|/* character special */
name|NFLNK
block|,
comment|/* symbolic link */
name|NFSOC
comment|/* socket */
block|}
enum|;
end_enum

begin_comment
comment|/*  * TYPEDEFS:  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|nfs_fh
name|nfs_fh
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
name|nfspath
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
name|nfsftype
name|nfsftype
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
name|fattr
name|nfsfattr
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
comment|/*  * NFSv3 handle (copied from am_xdr_func.h, because it is needed here)  * we use a different name but same storage size/alignment to avoid  * conflicts.  Sigh, this is so hacky. -ezk  */
end_comment

begin_define
define|#
directive|define
name|HPUX11_FHSIZE3
value|64
end_define

begin_comment
comment|/* size in bytes of a file handle (v3) */
end_comment

begin_struct
struct|struct
name|hpux11_nfs_fh3
block|{
name|u_int
name|am_fh3_length
decl_stmt|;
name|char
name|am_fh3_data
index|[
name|HPUX11_FHSIZE3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hpux11_nfs_fh3
name|hpux11_nfs_fh3
typedef|;
end_typedef

begin_comment
comment|/*  * EXTERNALS:  */
end_comment

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

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

begin_comment
comment|/* This is similar to Solaris 2.5.1 */
end_comment

begin_struct
struct|struct
name|nfs_args
block|{
name|struct
name|netbuf
modifier|*
name|addr
decl_stmt|;
comment|/* file server address */
name|struct
name|netbuf
modifier|*
name|syncaddr
decl_stmt|;
comment|/* secure NFS time sync addr */
name|struct
name|knetconfig
modifier|*
name|knconf
decl_stmt|;
comment|/* transport netconfig struct */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's hostname */
name|char
modifier|*
name|netname
decl_stmt|;
comment|/* server's netname */
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
name|fsname
decl_stmt|;
comment|/* F/S name */
if|#
directive|if
literal|0
block|struct pathcnf	*pathconf;
comment|/* static pathconf kludge */
endif|#
directive|endif
comment|/* 0 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs_fh
block|{
name|char
name|fh_data
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

begin_comment
comment|/*  **************************************************************************  * HP-UX 11 has Autofs support, but we don't support it yet.  * For now, undefine it or define dummy entries.  **************************************************************************  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MNTTYPE_AUTOFS
end_ifdef

begin_undef
undef|#
directive|undef
name|MNTTYPE_AUTOFS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNTTYPE_AUTOFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MNTTAB_TYPE_AUTOFS
end_ifdef

begin_undef
undef|#
directive|undef
name|MNTTAB_TYPE_AUTOFS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNTTAB_TYPE_AUTOFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_FS_AUTOFS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_AUTOFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MNTTYPE_NFS3
end_ifdef

begin_define
define|#
directive|define
name|NFSPROC3_LOOKUP
value|((u_long) 3)
end_define

begin_enum
enum|enum
name|nfsstat3
block|{
name|NFS3_OK
init|=
literal|0
block|,
name|NFS3ERR_PERM
init|=
literal|1
block|,
name|NFS3ERR_NOENT
init|=
literal|2
block|,
name|NFS3ERR_IO
init|=
literal|5
block|,
name|NFS3ERR_NXIO
init|=
literal|6
block|,
name|NFS3ERR_ACCES
init|=
literal|13
block|,
name|NFS3ERR_EXIST
init|=
literal|17
block|,
name|NFS3ERR_XDEV
init|=
literal|18
block|,
name|NFS3ERR_NODEV
init|=
literal|19
block|,
name|NFS3ERR_NOTDIR
init|=
literal|20
block|,
name|NFS3ERR_ISDIR
init|=
literal|21
block|,
name|NFS3ERR_INVAL
init|=
literal|22
block|,
name|NFS3ERR_FBIG
init|=
literal|27
block|,
name|NFS3ERR_NOSPC
init|=
literal|28
block|,
name|NFS3ERR_ROFS
init|=
literal|30
block|,
name|NFS3ERR_MLINK
init|=
literal|31
block|,
name|NFS3ERR_NAMETOOLONG
init|=
literal|63
block|,
name|NFS3ERR_NOTEMPTY
init|=
literal|66
block|,
name|NFS3ERR_DQUOT
init|=
literal|69
block|,
name|NFS3ERR_STALE
init|=
literal|70
block|,
name|NFS3ERR_REMOTE
init|=
literal|71
block|,
name|NFS3ERR_BADHANDLE
init|=
literal|10001
block|,
name|NFS3ERR_NOT_SYNC
init|=
literal|10002
block|,
name|NFS3ERR_BAD_COOKIE
init|=
literal|10003
block|,
name|NFS3ERR_NOTSUPP
init|=
literal|10004
block|,
name|NFS3ERR_TOOSMALL
init|=
literal|10005
block|,
name|NFS3ERR_SERVERFAULT
init|=
literal|10006
block|,
name|NFS3ERR_BADTYPE
init|=
literal|10007
block|,
name|NFS3ERR_JUKEBOX
init|=
literal|10008
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|nfsstat3
name|nfsstat3
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|filename3
typedef|;
end_typedef

begin_struct
struct|struct
name|diropargs3
block|{
name|hpux11_nfs_fh3
name|dir
decl_stmt|;
name|filename3
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|diropargs3
name|diropargs3
typedef|;
end_typedef

begin_struct
struct|struct
name|LOOKUP3args
block|{
name|diropargs3
name|what
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|LOOKUP3args
name|LOOKUP3args
typedef|;
end_typedef

begin_struct
struct|struct
name|LOOKUP3resok
block|{
name|hpux11_nfs_fh3
name|object
decl_stmt|;
if|#
directive|if
literal|0
block|post_op_attr obj_attributes; 	post_op_attr dir_attributes;
endif|#
directive|endif
comment|/* 0 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|LOOKUP3resok
name|LOOKUP3resok
typedef|;
end_typedef

begin_struct
struct|struct
name|LOOKUP3resfail
block|{
name|int
name|dummy
decl_stmt|;
if|#
directive|if
literal|0
block|post_op_attr dir_attributes;
endif|#
directive|endif
comment|/* 0 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|LOOKUP3resfail
name|LOOKUP3resfail
typedef|;
end_typedef

begin_struct
struct|struct
name|LOOKUP3res
block|{
name|nfsstat3
name|status
decl_stmt|;
union|union
block|{
name|LOOKUP3resok
name|ok
decl_stmt|;
name|LOOKUP3resfail
name|fail
decl_stmt|;
block|}
name|res_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|LOOKUP3res
name|LOOKUP3res
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNTTYPE_NFS3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMU_NFS_PROT_H */
end_comment

end_unit

