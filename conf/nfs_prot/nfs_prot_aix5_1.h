begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2003 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: nfs_prot_aix5_1.h,v 1.1.2.3 2002/12/27 22:44:53 ezk Exp $  *  */
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
comment|/*  * AIX 5.1 has a different aix51_nfs_args structure, hence the separate header.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|MNTPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MNTPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTPATHLEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTNAMLEN
end_ifndef

begin_define
define|#
directive|define
name|MNTNAMLEN
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTNAMLEN */
end_comment

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
name|mountlist
modifier|*
name|mountlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|attrstat
name|nfsattrstat
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|createargs
name|nfscreateargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|dirlist
name|nfsdirlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|diropargs
name|nfsdiropargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|diropokres
name|nfsdiropokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|diropres
name|nfsdiropres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|entry
name|nfsentry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|fattr
name|nfsfattr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ftype
name|nfsftype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|linkargs
name|nfslinkargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|readargs
name|nfsreadargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|readdirargs
name|nfsreaddirargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|readdirres
name|nfsreaddirres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|readlinkres
name|nfsreadlinkres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|readokres
name|nfsreadokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|readres
name|nfsreadres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|renameargs
name|nfsrenameargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|sattr
name|nfssattr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|sattrargs
name|nfssattrargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|statfsokres
name|nfsstatfsokres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|statfsres
name|nfsstatfsres
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|symlinkargs
name|nfssymlinkargs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|writeargs
name|nfswriteargs
typedef|;
end_typedef

begin_comment
comment|/*  * EXTERNALS:  */
end_comment

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

begin_comment
comment|/*  * AIX 5.1 has NFS V3, but it is undefined in the header files.  * so I define everything that's needed for NFS V3 here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MNT_NFS3
end_ifdef

begin_define
define|#
directive|define
name|FHSIZE3
value|64
end_define

begin_comment
comment|/* size in bytes of a file handle (v3) */
end_comment

begin_define
define|#
directive|define
name|NFS3_FHSIZE
value|64
end_define

begin_define
define|#
directive|define
name|MOUNTVERS3
value|((unsigned long)(3))
end_define

begin_define
define|#
directive|define
name|NFS_V3
value|((unsigned long)(3))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|struct nfs_fh3 {   u_int len;   char val[64];
comment|/* !!! */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|aix51_nfs_args
block|{
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
comment|/* server address and port */
name|caddr_t
name|u0
decl_stmt|;
comment|/* ??? UNKNOWN ??? */
name|unsigned
name|long
name|proto
decl_stmt|;
comment|/* IPPROTO_TCP/IPPROTO_UDP */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* pointer to hostname? */
name|char
modifier|*
name|netname
decl_stmt|;
comment|/* pointer to netname? */
name|caddr_t
name|fh
decl_stmt|;
comment|/* pointer to NFS v3 fh? */
name|unsigned
name|long
name|u5
decl_stmt|;
comment|/* IBM sux, IBM sux, IBM sux... */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* flags */
name|unsigned
name|long
name|wsize
decl_stmt|;
comment|/* wsize */
name|unsigned
name|long
name|rsize
decl_stmt|;
comment|/* rsize */
name|unsigned
name|long
name|timeo
decl_stmt|;
comment|/* timeo */
name|unsigned
name|long
name|retrans
decl_stmt|;
comment|/* retrans */
name|unsigned
name|long
name|acregmin
decl_stmt|;
comment|/* acregmin */
name|unsigned
name|long
name|acregmax
decl_stmt|;
comment|/* acregmax */
name|unsigned
name|long
name|acdirmin
decl_stmt|;
comment|/* acdirmin */
name|unsigned
name|long
name|acdirmax
decl_stmt|;
comment|/* acdirmax */
name|unsigned
name|long
name|u15
decl_stmt|;
comment|/* ??? UNKNOWN ??? */
name|struct
name|pathcnf
modifier|*
name|pathconf
decl_stmt|;
comment|/* pathconf */
block|}
struct|;
end_struct

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
name|fhandle3
typedef|;
end_typedef

begin_enum
enum|enum
name|mountstat3
block|{
name|MNT3_OK
init|=
literal|0
block|,
name|MNT3ERR_PERM
init|=
literal|1
block|,
name|MNT3ERR_NOENT
init|=
literal|2
block|,
name|MNT3ERR_IO
init|=
literal|5
block|,
name|MNT3ERR_ACCES
init|=
literal|13
block|,
name|MNT3ERR_NOTDIR
init|=
literal|20
block|,
name|MNT3ERR_INVAL
init|=
literal|22
block|,
name|MNT3ERR_NAMETOOLONG
init|=
literal|63
block|,
name|MNT3ERR_NOTSUPP
init|=
literal|10004
block|,
name|MNT3ERR_SERVERFAULT
init|=
literal|10006
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|mountstat3
name|mountstat3
typedef|;
end_typedef

begin_struct
struct|struct
name|mountres3_ok
block|{
name|fhandle3
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
name|mountres3_ok
name|mountres3_ok
typedef|;
end_typedef

begin_struct
struct|struct
name|mountres3
block|{
name|mountstat3
name|fhs_status
decl_stmt|;
union|union
block|{
name|mountres3_ok
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
name|mountres3
name|mountres3
typedef|;
end_typedef

begin_struct
struct|struct
name|nfs_fh3
block|{
name|u_int
name|fh3_length
decl_stmt|;
union|union
name|nfs_fh3_u
block|{
struct|struct
name|nfs_fh3_i
block|{
name|fhandle_t
name|fh3_i
decl_stmt|;
block|}
name|nfs_fh3_i
struct|;
name|char
name|data
index|[
name|NFS3_FHSIZE
index|]
decl_stmt|;
block|}
name|fh3_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfs_fh3
name|nfs_fh3
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNT_NFS3 */
end_comment

begin_comment
comment|/*  * EXTERNALS:  */
end_comment

begin_function_decl
specifier|extern
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

begin_function_decl
specifier|extern
name|char
modifier|*
name|yperr_string
parameter_list|(
name|int
name|incode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMU_NFS_PROT_H */
end_comment

end_unit

