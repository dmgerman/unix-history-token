begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfs_prot.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|xdr_nfsstat
value|xdr_enum
end_define

begin_define
define|#
directive|define
name|xdr_ftype
value|xdr_enum
end_define

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
name|NFS_FIFO_DEV
value|-1
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

begin_enum
enum|enum
name|nfsstat
block|{
name|NFS_OK
init|=
literal|0
block|,
name|NFSERR_PERM
init|=
literal|1
block|,
name|NFSERR_NOENT
init|=
literal|2
block|,
name|NFSERR_IO
init|=
literal|5
block|,
name|NFSERR_NXIO
init|=
literal|6
block|,
name|NFSERR_ACCES
init|=
literal|13
block|,
name|NFSERR_EXIST
init|=
literal|17
block|,
name|NFSERR_NODEV
init|=
literal|19
block|,
name|NFSERR_NOTDIR
init|=
literal|20
block|,
name|NFSERR_ISDIR
init|=
literal|21
block|,
name|NFSERR_FBIG
init|=
literal|27
block|,
name|NFSERR_NOSPC
init|=
literal|28
block|,
name|NFSERR_ROFS
init|=
literal|30
block|,
name|NFSERR_NAMETOOLONG
init|=
literal|63
block|,
name|NFSERR_NOTEMPTY
init|=
literal|66
block|,
name|NFSERR_DQUOT
init|=
literal|69
block|,
name|NFSERR_STALE
init|=
literal|70
block|,
name|NFSERR_WFLUSH
init|=
literal|99
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|nfsstat
name|nfsstat
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_nfsstat
parameter_list|()
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ftype
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
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ftype
name|ftype
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_ftype(); */
end_comment

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

begin_typedef
typedef|typedef
name|struct
name|nfs_fh
name|nfs_fh
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_nfs_fh
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|nfstime
block|{
name|u_int
name|seconds
decl_stmt|;
name|u_int
name|useconds
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfstime
name|nfstime
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_nfstime(); */
end_comment

begin_struct
struct|struct
name|fattr
block|{
name|ftype
name|type
decl_stmt|;
name|u_int
name|mode
decl_stmt|;
name|u_int
name|nlink
decl_stmt|;
name|u_int
name|uid
decl_stmt|;
name|u_int
name|gid
decl_stmt|;
name|u_int
name|size
decl_stmt|;
name|u_int
name|blocksize
decl_stmt|;
name|u_int
name|rdev
decl_stmt|;
name|u_int
name|blocks
decl_stmt|;
name|u_int
name|fsid
decl_stmt|;
name|u_int
name|fileid
decl_stmt|;
name|nfstime
name|atime
decl_stmt|;
name|nfstime
name|mtime
decl_stmt|;
name|nfstime
name|ctime
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fattr
name|fattr
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_fattr(); */
end_comment

begin_struct
struct|struct
name|sattr
block|{
name|u_int
name|mode
decl_stmt|;
name|u_int
name|uid
decl_stmt|;
name|u_int
name|gid
decl_stmt|;
name|u_int
name|size
decl_stmt|;
name|nfstime
name|atime
decl_stmt|;
name|nfstime
name|mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sattr
name|sattr
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_sattr(); */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|filename
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_filename(); */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|nfspath
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_nfspath
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|attrstat
block|{
name|nfsstat
name|status
decl_stmt|;
union|union
block|{
name|fattr
name|attributes
decl_stmt|;
block|}
name|attrstat_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|attrstat
name|attrstat
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_attrstat
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|sattrargs
block|{
name|nfs_fh
name|file
decl_stmt|;
name|sattr
name|attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sattrargs
name|sattrargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_sattrargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|diropargs
block|{
name|nfs_fh
name|dir
decl_stmt|;
name|filename
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|diropargs
name|diropargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_diropargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|diropokres
block|{
name|nfs_fh
name|file
decl_stmt|;
name|fattr
name|attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|diropokres
name|diropokres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_diropokres
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|diropres
block|{
name|nfsstat
name|status
decl_stmt|;
union|union
block|{
name|diropokres
name|diropres
decl_stmt|;
block|}
name|diropres_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|diropres
name|diropres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_diropres
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|readlinkres
block|{
name|nfsstat
name|status
decl_stmt|;
union|union
block|{
name|nfspath
name|data
decl_stmt|;
block|}
name|readlinkres_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|readlinkres
name|readlinkres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_readlinkres
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|readargs
block|{
name|nfs_fh
name|file
decl_stmt|;
name|u_int
name|offset
decl_stmt|;
name|u_int
name|count
decl_stmt|;
name|u_int
name|totalcount
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|readargs
name|readargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_readargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|readokres
block|{
name|fattr
name|attributes
decl_stmt|;
struct|struct
block|{
name|u_int
name|data_len
decl_stmt|;
name|char
modifier|*
name|data_val
decl_stmt|;
block|}
name|data
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|readokres
name|readokres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_readokres
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|readres
block|{
name|nfsstat
name|status
decl_stmt|;
union|union
block|{
name|readokres
name|reply
decl_stmt|;
block|}
name|readres_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|readres
name|readres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_readres
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|writeargs
block|{
name|nfs_fh
name|file
decl_stmt|;
name|u_int
name|beginoffset
decl_stmt|;
name|u_int
name|offset
decl_stmt|;
name|u_int
name|totalcount
decl_stmt|;
struct|struct
block|{
name|u_int
name|data_len
decl_stmt|;
name|char
modifier|*
name|data_val
decl_stmt|;
block|}
name|data
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|writeargs
name|writeargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_writeargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|createargs
block|{
name|diropargs
name|where
decl_stmt|;
name|sattr
name|attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|createargs
name|createargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_createargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|renameargs
block|{
name|diropargs
name|from
decl_stmt|;
name|diropargs
name|to
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|renameargs
name|renameargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_renameargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|linkargs
block|{
name|nfs_fh
name|from
decl_stmt|;
name|diropargs
name|to
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|linkargs
name|linkargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_linkargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|symlinkargs
block|{
name|diropargs
name|from
decl_stmt|;
name|nfspath
name|to
decl_stmt|;
name|sattr
name|attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|symlinkargs
name|symlinkargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_symlinkargs
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|char
name|nfscookie
index|[
name|NFS_COOKIESIZE
index|]
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_nfscookie(); */
end_comment

begin_struct
struct|struct
name|readdirargs
block|{
name|nfs_fh
name|dir
decl_stmt|;
name|nfscookie
name|cookie
decl_stmt|;
name|u_int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|readdirargs
name|readdirargs
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_readdirargs
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|entry
block|{
name|u_int
name|fileid
decl_stmt|;
name|filename
name|name
decl_stmt|;
name|nfscookie
name|cookie
decl_stmt|;
name|struct
name|entry
modifier|*
name|nextentry
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|entry
name|entry
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_entry(); */
end_comment

begin_struct
struct|struct
name|dirlist
block|{
name|entry
modifier|*
name|entries
decl_stmt|;
name|bool_t
name|eof
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dirlist
name|dirlist
typedef|;
end_typedef

begin_comment
comment|/* static bool_t xdr_dirlist(); */
end_comment

begin_struct
struct|struct
name|readdirres
block|{
name|nfsstat
name|status
decl_stmt|;
union|union
block|{
name|dirlist
name|reply
decl_stmt|;
block|}
name|readdirres_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|readdirres
name|readdirres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_readdirres
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|statfsokres
block|{
name|u_int
name|tsize
decl_stmt|;
name|u_int
name|bsize
decl_stmt|;
name|u_int
name|blocks
decl_stmt|;
name|u_int
name|bfree
decl_stmt|;
name|u_int
name|bavail
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|statfsokres
name|statfsokres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_statfsokres
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|statfsres
block|{
name|nfsstat
name|status
decl_stmt|;
union|union
block|{
name|statfsokres
name|reply
decl_stmt|;
block|}
name|statfsres_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|statfsres
name|statfsres
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_statfsres
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFS_PROGRAM
value|((u_long)100003)
end_define

begin_define
define|#
directive|define
name|NFS_VERSION
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|NFSPROC_NULL
value|((u_long)0)
end_define

begin_function_decl
specifier|extern
name|voidp
name|nfsproc_null_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_GETATTR
value|((u_long)1)
end_define

begin_function_decl
specifier|extern
name|attrstat
modifier|*
name|nfsproc_getattr_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_SETATTR
value|((u_long)2)
end_define

begin_function_decl
specifier|extern
name|attrstat
modifier|*
name|nfsproc_setattr_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_ROOT
value|((u_long)3)
end_define

begin_function_decl
specifier|extern
name|voidp
name|nfsproc_root_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_LOOKUP
value|((u_long)4)
end_define

begin_function_decl
specifier|extern
name|diropres
modifier|*
name|nfsproc_lookup_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_READLINK
value|((u_long)5)
end_define

begin_function_decl
specifier|extern
name|readlinkres
modifier|*
name|nfsproc_readlink_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_READ
value|((u_long)6)
end_define

begin_function_decl
specifier|extern
name|readres
modifier|*
name|nfsproc_read_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_WRITECACHE
value|((u_long)7)
end_define

begin_function_decl
specifier|extern
name|voidp
name|nfsproc_writecache_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_WRITE
value|((u_long)8)
end_define

begin_function_decl
specifier|extern
name|attrstat
modifier|*
name|nfsproc_write_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_CREATE
value|((u_long)9)
end_define

begin_function_decl
specifier|extern
name|diropres
modifier|*
name|nfsproc_create_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_REMOVE
value|((u_long)10)
end_define

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_remove_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_RENAME
value|((u_long)11)
end_define

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_rename_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_LINK
value|((u_long)12)
end_define

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_link_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_SYMLINK
value|((u_long)13)
end_define

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_symlink_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_MKDIR
value|((u_long)14)
end_define

begin_function_decl
specifier|extern
name|diropres
modifier|*
name|nfsproc_mkdir_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_RMDIR
value|((u_long)15)
end_define

begin_function_decl
specifier|extern
name|nfsstat
modifier|*
name|nfsproc_rmdir_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_READDIR
value|((u_long)16)
end_define

begin_function_decl
specifier|extern
name|readdirres
modifier|*
name|nfsproc_readdir_2
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NFSPROC_STATFS
value|((u_long)17)
end_define

begin_function_decl
specifier|extern
name|statfsres
modifier|*
name|nfsproc_statfs_2
parameter_list|()
function_decl|;
end_function_decl

end_unit

