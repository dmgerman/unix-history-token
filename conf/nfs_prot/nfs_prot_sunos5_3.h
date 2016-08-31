begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/nfs_prot/nfs_prot_sunos5_3.h  *  */
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
comment|/*  * Do not include<nfs/nfs.h> because Solaris 2.3 really does not have NFS  * V.3 support, despite what their header files claim.  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|fhandle_t
end_ifndef

begin_define
define|#
directive|define
name|fhandle_t
value|nfs_fh
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not fhandle_t */
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

begin_comment
comment|/* missing mntent definition for cachefs */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTYPE_CACHEFS
end_ifndef

begin_define
define|#
directive|define
name|MNTTYPE_CACHEFS
value|"cachefs"
end_define

begin_comment
comment|/* Cache File System */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTYPE_CACHEFS */
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
name|FHSIZE
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
name|name
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|fhandle
index|[
name|FHSIZE
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|ftype
name|nfsftype
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

begin_comment
comment|/*  * ENUMS:  */
end_comment

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

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

