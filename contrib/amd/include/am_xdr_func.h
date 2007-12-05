begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/include/am_xdr_func.h  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_NFS3
end_ifdef

begin_define
define|#
directive|define
name|AM_FHSIZE3
value|64
end_define

begin_comment
comment|/* size in bytes of a file handle (v3) */
end_comment

begin_define
define|#
directive|define
name|AM_MOUNTVERS3
value|((unsigned long)(3))
end_define

begin_comment
comment|/* NFSv3 handle */
end_comment

begin_struct
struct|struct
name|am_nfs_fh3
block|{
name|u_int
name|am_fh3_length
decl_stmt|;
name|char
name|am_fh3_data
index|[
name|AM_FHSIZE3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_nfs_fh3
name|am_nfs_fh3
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AM_NFSPROC3_LOOKUP
value|((u_long) 3)
end_define

begin_enum
enum|enum
name|am_nfsstat3
block|{
name|AM_NFS3_OK
init|=
literal|0
block|,
name|AM_NFS3ERR_PERM
init|=
literal|1
block|,
name|AM_NFS3ERR_NOENT
init|=
literal|2
block|,
name|AM_NFS3ERR_IO
init|=
literal|5
block|,
name|AM_NFS3ERR_NXIO
init|=
literal|6
block|,
name|AM_NFS3ERR_ACCES
init|=
literal|13
block|,
name|AM_NFS3ERR_EXIST
init|=
literal|17
block|,
name|AM_NFS3ERR_XDEV
init|=
literal|18
block|,
name|AM_NFS3ERR_NODEV
init|=
literal|19
block|,
name|AM_NFS3ERR_NOTDIR
init|=
literal|20
block|,
name|AM_NFS3ERR_ISDIR
init|=
literal|21
block|,
name|AM_NFS3ERR_INVAL
init|=
literal|22
block|,
name|AM_NFS3ERR_FBIG
init|=
literal|27
block|,
name|AM_NFS3ERR_NOSPC
init|=
literal|28
block|,
name|AM_NFS3ERR_ROFS
init|=
literal|30
block|,
name|AM_NFS3ERR_MLINK
init|=
literal|31
block|,
name|AM_NFS3ERR_NAMETOOLONG
init|=
literal|63
block|,
name|AM_NFS3ERR_NOTEMPTY
init|=
literal|66
block|,
name|AM_NFS3ERR_DQUOT
init|=
literal|69
block|,
name|AM_NFS3ERR_STALE
init|=
literal|70
block|,
name|AM_NFS3ERR_REMOTE
init|=
literal|71
block|,
name|AM_NFS3ERR_BADHANDLE
init|=
literal|10001
block|,
name|AM_NFS3ERR_NOT_SYNC
init|=
literal|10002
block|,
name|AM_NFS3ERR_BAD_COOKIE
init|=
literal|10003
block|,
name|AM_NFS3ERR_NOTSUPP
init|=
literal|10004
block|,
name|AM_NFS3ERR_TOOSMALL
init|=
literal|10005
block|,
name|AM_NFS3ERR_SERVERFAULT
init|=
literal|10006
block|,
name|AM_NFS3ERR_BADTYPE
init|=
literal|10007
block|,
name|AM_NFS3ERR_JUKEBOX
init|=
literal|10008
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|am_nfsstat3
name|am_nfsstat3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|fhandle3_len
decl_stmt|;
name|char
modifier|*
name|fhandle3_val
decl_stmt|;
block|}
name|am_fhandle3
typedef|;
end_typedef

begin_enum
enum|enum
name|am_mountstat3
block|{
name|AM_MNT3_OK
init|=
literal|0
block|,
name|AM_MNT3ERR_PERM
init|=
literal|1
block|,
name|AM_MNT3ERR_NOENT
init|=
literal|2
block|,
name|AM_MNT3ERR_IO
init|=
literal|5
block|,
name|AM_MNT3ERR_ACCES
init|=
literal|13
block|,
name|AM_MNT3ERR_NOTDIR
init|=
literal|20
block|,
name|AM_MNT3ERR_INVAL
init|=
literal|22
block|,
name|AM_MNT3ERR_NAMETOOLONG
init|=
literal|63
block|,
name|AM_MNT3ERR_NOTSUPP
init|=
literal|10004
block|,
name|AM_MNT3ERR_SERVERFAULT
init|=
literal|10006
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|am_mountstat3
name|am_mountstat3
typedef|;
end_typedef

begin_struct
struct|struct
name|am_mountres3_ok
block|{
name|am_fhandle3
name|fhandle
decl_stmt|;
struct|struct
block|{
name|u_int
name|auth_flavors_len
decl_stmt|;
name|int
modifier|*
name|auth_flavors_val
decl_stmt|;
block|}
name|auth_flavors
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_mountres3_ok
name|am_mountres3_ok
typedef|;
end_typedef

begin_struct
struct|struct
name|am_mountres3
block|{
name|am_mountstat3
name|fhs_status
decl_stmt|;
union|union
block|{
name|am_mountres3_ok
name|mountinfo
decl_stmt|;
block|}
name|mountres3_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_mountres3
name|am_mountres3
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|am_filename3
typedef|;
end_typedef

begin_struct
struct|struct
name|am_diropargs3
block|{
name|am_nfs_fh3
name|dir
decl_stmt|;
name|am_filename3
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_diropargs3
name|am_diropargs3
typedef|;
end_typedef

begin_struct
struct|struct
name|am_LOOKUP3args
block|{
name|am_diropargs3
name|what
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_LOOKUP3args
name|am_LOOKUP3args
typedef|;
end_typedef

begin_struct
struct|struct
name|am_LOOKUP3resok
block|{
name|am_nfs_fh3
name|object
decl_stmt|;
if|#
directive|if
literal|0
block|post_op_attr obj_attributes; 	post_op_attr dir_attributes;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_LOOKUP3resok
name|am_LOOKUP3resok
typedef|;
end_typedef

begin_struct
struct|struct
name|am_LOOKUP3resfail
block|{
if|#
directive|if
literal|0
block|post_op_attr dir_attributes;
else|#
directive|else
name|char
name|dummy
decl_stmt|;
comment|/* cannot have an empty declaration */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_LOOKUP3resfail
name|am_LOOKUP3resfail
typedef|;
end_typedef

begin_struct
struct|struct
name|am_LOOKUP3res
block|{
name|am_nfsstat3
name|status
decl_stmt|;
union|union
block|{
name|am_LOOKUP3resok
name|ok
decl_stmt|;
name|am_LOOKUP3resfail
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
name|am_LOOKUP3res
name|am_LOOKUP3res
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_NFS3 */
end_comment

begin_comment
comment|/*  * Multi-protocol NFS file handle  */
end_comment

begin_union
union|union
name|am_nfs_handle
block|{
comment|/* placeholder for V4 file handle */
ifdef|#
directive|ifdef
name|HAVE_FS_NFS3
name|am_nfs_fh3
name|v3
decl_stmt|;
comment|/* NFS version 3 handle */
endif|#
directive|endif
comment|/* HAVE_FS_NFS3 */
name|am_nfs_fh
name|v2
decl_stmt|;
comment|/* NFS version 2 handle */
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|am_nfs_handle
name|am_nfs_handle_t
typedef|;
end_typedef

begin_comment
comment|/*  * Definitions of all possible xdr functions that are otherwise  * not defined elsewhere.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AM_XDR_FUNC_H
end_ifndef

begin_define
define|#
directive|define
name|_AM_XDR_FUNC_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_ATTRSTAT
end_ifndef

begin_function_decl
name|bool_t
name|xdr_attrstat
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsattrstat
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_ATTRSTAT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_CREATEARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_createargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfscreateargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_CREATEARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_DIRLIST
end_ifndef

begin_function_decl
name|bool_t
name|xdr_dirlist
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsdirlist
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_DIRLIST */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_DIROPARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_diropargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsdiropargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_DIROPARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_DIROPOKRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_diropokres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsdiropokres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_DIROPOKRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_DIROPRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_diropres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsdiropres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_DIROPRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_DIRPATH
end_ifndef

begin_function_decl
name|bool_t
name|xdr_dirpath
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|dirpath
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_DIRPATH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_ENTRY
end_ifndef

begin_function_decl
name|bool_t
name|xdr_entry
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsentry
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_ENTRY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_EXPORTNODE
end_ifndef

begin_function_decl
name|bool_t
name|xdr_exportnode
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|exportnode
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_EXPORTNODE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_EXPORTS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_exports
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|exports
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_EXPORTS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_FATTR
end_ifndef

begin_function_decl
name|bool_t
name|xdr_fattr
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsfattr
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_FATTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_FHANDLE
end_ifndef

begin_function_decl
name|bool_t
name|xdr_fhandle
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|fhandle
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_FHANDLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_FHSTATUS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_fhstatus
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|fhstatus
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_FHSTATUS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_FILENAME
end_ifndef

begin_function_decl
name|bool_t
name|xdr_filename
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|filename
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_FILENAME */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_FTYPE
end_ifndef

begin_function_decl
name|bool_t
name|xdr_ftype
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsftype
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_FTYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_GROUPNODE
end_ifndef

begin_function_decl
name|bool_t
name|xdr_groupnode
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|groupnode
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_GROUPNODE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_GROUPS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_groups
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|groups
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_GROUPS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_LINKARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_linkargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfslinkargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_LINKARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_MOUNTBODY
end_ifndef

begin_function_decl
name|bool_t
name|xdr_mountbody
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|mountbody
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_MOUNTBODY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_MOUNTLIST
end_ifndef

begin_function_decl
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_MOUNTLIST */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_NAME
end_ifndef

begin_function_decl
name|bool_t
name|xdr_name
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|name
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_NAME */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_NFS_FH
end_ifndef

begin_function_decl
name|bool_t
name|xdr_nfs_fh
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_nfs_fh
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_NFS_FH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_NFSCOOKIE
end_ifndef

begin_function_decl
name|bool_t
name|xdr_nfscookie
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfscookie
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_NFSCOOKIE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_NFSPATH
end_ifndef

begin_function_decl
name|bool_t
name|xdr_nfspath
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfspath
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_NFSPATH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_NFSSTAT
end_ifndef

begin_function_decl
name|bool_t
name|xdr_nfsstat
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsstat
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_NFSSTAT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_NFSTIME
end_ifndef

begin_function_decl
name|bool_t
name|xdr_nfstime
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfstime
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_NFSTIME */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_POINTER
end_ifndef

begin_function_decl
name|bool_t
name|xdr_pointer
parameter_list|(
specifier|register
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|char
modifier|*
modifier|*
name|objpp
parameter_list|,
name|u_int
name|obj_size
parameter_list|,
name|XDRPROC_T_TYPE
name|xdr_obj
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_POINTER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_READARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_readargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsreadargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_READARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_READDIRARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_readdirargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsreaddirargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_READDIRARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_READDIRRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_readdirres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsreaddirres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_READDIRRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_READLINKRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_readlinkres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsreadlinkres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_READLINKRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_READOKRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_readokres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsreadokres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_READOKRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_READRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_readres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsreadres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_READRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_RENAMEARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_renameargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsrenameargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_RENAMEARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_SATTR
end_ifndef

begin_function_decl
name|bool_t
name|xdr_sattr
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfssattr
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_SATTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_SATTRARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_sattrargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfssattrargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_SATTRARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_STATFSOKRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_statfsokres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsstatfsokres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_STATFSOKRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_STATFSRES
end_ifndef

begin_function_decl
name|bool_t
name|xdr_statfsres
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfsstatfsres
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_STATFSRES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_SYMLINKARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_symlinkargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfssymlinkargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_SYMLINKARGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_XDR_WRITEARGS
end_ifndef

begin_function_decl
name|bool_t
name|xdr_writeargs
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|nfswriteargs
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_XDR_WRITEARGS */
end_comment

begin_comment
comment|/*  * NFS3 XDR FUNCTIONS:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_NFS3
end_ifdef

begin_function_decl
name|bool_t
name|xdr_am_fhandle3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_fhandle3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_mountstat3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_mountstat3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_mountres3_ok
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_mountres3_ok
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_mountres3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_mountres3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_diropargs3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_diropargs3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_filename3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_filename3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_LOOKUP3args
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_LOOKUP3args
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_LOOKUP3res
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_LOOKUP3res
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_LOOKUP3resfail
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_LOOKUP3resfail
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_LOOKUP3resok
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_LOOKUP3resok
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_nfsstat3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_nfsstat3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_am_nfs_fh3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|am_nfs_fh3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_NFS3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AM_XDR_FUNC_H */
end_comment

end_unit

