begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: nfs_prot_freebsd3.h,v 1.4 1999/03/30 17:22:54 ezk Exp $  * $FreeBSD$  *  */
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
name|COMMENT_OUT
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT_OUT */
end_comment

begin_comment
comment|/* nfs_prot.h defines struct `nfs_fh3', but it is a ``dmr "unwarranted  * chumminess with the C implementation".  We need the more complete  * structure, which is defined below.  So get the stock `nfs_fh3'  * out of the way.  */
end_comment

begin_struct_decl
struct_decl|struct
name|nfs_fh3
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|nfs_fh3
value|nfs_fh3_fbsd_
end_define

begin_include
include|#
directive|include
file|"nfs_prot.h"
end_include

begin_undef
undef|#
directive|undef
name|nfs_fh3
end_undef

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
name|HAVE_UFS_UFS_UFSMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UFS_UFS_UFSMOUNT_H */
end_comment

begin_comment
comment|/*  * MACROS:  */
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
name|rr_status
value|status
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
name|sla_from
value|from
end_define

begin_define
define|#
directive|define
name|wra_fhandle
value|file
end_define

begin_comment
comment|/*  * TYPEDEFS:  */
end_comment

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
comment|/*  *  * FreeBSD-3.0-RELEASE has NFS V3.  Older versions had it only defined  * in the rpcgen source file.  If you are on an older system, and you  * want NFSv3 support, you need to regenerate the rpcsvc header files as  * follows:  *	cd /usr/include/rpcsvc  *	rpcgen -h -C -DWANT_NFS3 mount.x  *	rpcgen -h -C -DWANT_NFS3 nfs_prot.x  * If you don't want NFSv3, then you will have to turn off the NFSMNT_NFSV3  * macro below.  If the code doesn't compile, upgrade to the latest 3.0  * version...  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NFSMNT_NFSV3
end_ifdef

begin_define
define|#
directive|define
name|MOUNT_NFS3
value|MOUNT_NFS
end_define

begin_define
define|#
directive|define
name|MNTOPT_NFS3
value|"nfs"
end_define

begin_comment
comment|/*  * as of 3.0-RELEASE the nfs_fh3 that is defined in the system headers  * (or the one generated by rpcgen) lacks the proper full definition,  * listed below.  A special macro (aux/macros/struct_nfs_fh3.m4) searches  * for this special name before other names.  */
end_comment

begin_struct
struct|struct
name|nfs_fh3_freebsd3
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
name|nfs_fh3_freebsd3
name|nfs_fh3_freebsd3
typedef|;
end_typedef

begin_comment
comment|/* since we don't use Am-utils's aux/macros/struct_nfs_fh3.m4, we don't get    their special searching.  So restore the standard name. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|nfs_fh3_freebsd3
name|nfs_fh3
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFSMNT_NFSV3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMU_NFS_PROT_H */
end_comment

end_unit

