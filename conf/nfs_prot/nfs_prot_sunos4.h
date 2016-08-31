begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/nfs_prot/nfs_prot_sunos4.h  *  */
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
name|HAVE_SYS_ERRNO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_ERRNO_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPC_RPC_H
end_ifdef

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPC_RPC_H */
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
name|HAVE_NFS_NFS_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/nfs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_NFS_CLNT_H */
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

begin_comment
comment|/* complete missing definition that is actually used in SunOS 4.x */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTOPT_DEV
end_ifndef

begin_define
define|#
directive|define
name|MNTOPT_DEV
value|"dev"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTOPT_DEV */
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
comment|/* map field names */
end_comment

begin_define
define|#
directive|define
name|ml_hostname
value|ml_name
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
name|ml_next
value|ml_nxt
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
name|gr_name
value|g_name
end_define

begin_define
define|#
directive|define
name|ex_dir
value|ex_name
end_define

begin_define
define|#
directive|define
name|na_fileid
value|na_nodeid
end_define

begin_define
define|#
directive|define
name|la_fhandle
value|la_from
end_define

begin_define
define|#
directive|define
name|ra_totalcount
value|ra_totcount
end_define

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
name|char
name|fhandle
index|[
name|NFS_FHSIZE
index|]
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
name|nfscreateargs
name|nfscreateargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsdirlist
name|nfsdirlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsdiropargs
name|nfsdiropargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsdiropokres
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
name|nfsentry
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
name|nfsfhstatus
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
name|nfslinkargs
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
name|nfstime
name|nfstime
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsreadargs
name|nfsreadargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsreaddirargs
name|nfsreaddirargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsreaddirres
name|nfsreaddirres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsreadlinkres
name|nfsreadlinkres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsreadokres
name|nfsreadokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsreadres
name|nfsreadres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsrenameargs
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
name|nfssattrargs
name|nfssattrargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsstatfsokres
name|nfsstatfsokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfsstatfsres
name|nfsstatfsres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|nfssymlinkargs
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
name|fhandle_t
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
name|fhandle_t
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
name|fhandle_t
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
name|fhandle_t
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
name|nfssattrargs
block|{
name|fhandle_t
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
name|_nfsdiropargs
block|{
name|fhandle_t
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
name|nfsdiropokres
block|{
name|fhandle_t
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
name|nfsreadlinkres
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
name|_nfsreadargs
block|{
name|fhandle_t
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
name|nfsreadokres
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
name|nfsreadres
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
name|fhandle_t
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
name|nfscreateargs
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
name|nfsrenameargs
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
name|_nfslinkargs
block|{
name|fhandle_t
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
name|nfssymlinkargs
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
name|nfsreaddirargs
block|{
name|fhandle_t
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
name|nfsentry
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
name|nfsdirlist
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
name|nfsreaddirres
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
name|nfsstatfsokres
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
name|nfsstatfsres
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

begin_struct
struct|struct
name|nfsfhstatus
block|{
name|int
name|fhs_status
decl_stmt|;
name|fhandle
name|fhs_fh
decl_stmt|;
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

