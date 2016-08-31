begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/nfs_prot/nfs_prot_linux.h  *  */
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

begin_comment
comment|/*  * Hard-code support for some file systems so the built amd  * binary can always run them.  Also, this helps detection of iso9660  * file system for which the module isn't named as the file system mount  * name.  */
end_comment

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL_VERSION
end_ifndef

begin_define
define|#
directive|define
name|KERNEL_VERSION
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(((a)<< 16) + ((b)<< 8) + (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not KERNEL_VERSION */
end_comment

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|MS_BIND
end_ifndef

begin_define
define|#
directive|define
name|MS_BIND
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MS_BIND */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTYPE_LOFS
end_ifndef

begin_define
define|#
directive|define
name|MNTTYPE_LOFS
value|"bind"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTYPE_LOFS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_VERSION_CODE>= KERNEL_VERSION(2,4,0) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTYPE_ISO9660
end_ifndef

begin_define
define|#
directive|define
name|MNTTYPE_ISO9660
value|"iso9660"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTYPE_ISO9660 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FHSIZE
end_ifndef

begin_define
define|#
directive|define
name|FHSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not FHSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FHSIZE3
end_ifndef

begin_define
define|#
directive|define
name|FHSIZE3
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not FHSIZE3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_NFS3
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTYPE_NFS3
end_ifndef

begin_define
define|#
directive|define
name|MNTTYPE_NFS3
value|"nfs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTYPE_NFS3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_NFS3 */
end_comment

begin_comment
comment|/*  * These two force/lazy unmount flags are sometimes missing from some linux  * systems' headers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UMOUNT2
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MNT_FORCE
end_ifndef

begin_define
define|#
directive|define
name|MNT_FORCE
value|0x1
end_define

begin_comment
comment|/* from<sys/mount.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNT_FORCE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNT_DETACH
end_ifndef

begin_define
define|#
directive|define
name|MNT_DETACH
value|0x2
end_define

begin_comment
comment|/* from kernel<linux/fs.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNT_DETACH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UMOUNT2 */
end_comment

begin_comment
comment|/* XXX: hack until we have a better way to detect /dev/loop devices */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_LOOP_H
end_ifdef

begin_define
define|#
directive|define
name|HAVE_LOOP_DEVICE
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|setup_loop_device
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|delete_loop_device
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_LOOP_H */
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
name|fhsize
value|root.size
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
comment|/* Autofs trick */
end_comment

begin_typedef
typedef|typedef
name|int
name|autofs_args_t
typedef|;
end_typedef

begin_comment
comment|/*  * We use our own definitions here, because the definitions in the  * kernel change the API (though not the ABI) *way* too often.  */
end_comment

begin_undef
undef|#
directive|undef
name|nfs_args_t
end_undef

begin_struct
struct|struct
name|nfs2_fh
block|{
name|char
name|data
index|[
name|FHSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs3_fh
block|{
name|u_short
name|size
decl_stmt|;
name|u_char
name|data
index|[
name|FHSIZE3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs_args
block|{
name|int
name|version
decl_stmt|;
comment|/* 1 */
name|int
name|fd
decl_stmt|;
comment|/* 1 */
name|struct
name|nfs2_fh
name|old_root
decl_stmt|;
comment|/* 1 */
name|int
name|flags
decl_stmt|;
comment|/* 1 */
name|int
name|rsize
decl_stmt|;
comment|/* 1 */
name|int
name|wsize
decl_stmt|;
comment|/* 1 */
name|int
name|timeo
decl_stmt|;
comment|/* 1 */
name|int
name|retrans
decl_stmt|;
comment|/* 1 */
name|int
name|acregmin
decl_stmt|;
comment|/* 1 */
name|int
name|acregmax
decl_stmt|;
comment|/* 1 */
name|int
name|acdirmin
decl_stmt|;
comment|/* 1 */
name|int
name|acdirmax
decl_stmt|;
comment|/* 1 */
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
comment|/* 1 */
name|char
name|hostname
index|[
literal|256
index|]
decl_stmt|;
comment|/* 1 */
name|int
name|namlen
decl_stmt|;
comment|/* 2 */
name|unsigned
name|int
name|bsize
decl_stmt|;
comment|/* 3 */
name|struct
name|nfs3_fh
name|root
decl_stmt|;
comment|/* 4 */
name|int
name|pseudoflavor
decl_stmt|;
comment|/* 5 */
name|char
name|context
index|[
literal|256
operator|+
literal|1
index|]
decl_stmt|;
comment|/* 6 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfs_args
name|nfs_args_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NFS4_MOUNT_VERSION
value|1
end_define

begin_struct
struct|struct
name|nfs_string
block|{
name|unsigned
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfs4_args
block|{
name|int
name|version
decl_stmt|;
comment|/* 1 */
name|int
name|flags
decl_stmt|;
comment|/* 1 */
name|int
name|rsize
decl_stmt|;
comment|/* 1 */
name|int
name|wsize
decl_stmt|;
comment|/* 1 */
name|int
name|timeo
decl_stmt|;
comment|/* 1 */
name|int
name|retrans
decl_stmt|;
comment|/* 1 */
name|int
name|acregmin
decl_stmt|;
comment|/* 1 */
name|int
name|acregmax
decl_stmt|;
comment|/* 1 */
name|int
name|acdirmin
decl_stmt|;
comment|/* 1 */
name|int
name|acdirmax
decl_stmt|;
comment|/* 1 */
name|struct
name|nfs_string
name|client_addr
decl_stmt|;
comment|/* 1 */
name|struct
name|nfs_string
name|mnt_path
decl_stmt|;
comment|/* 1 */
name|struct
name|nfs_string
name|hostname
decl_stmt|;
comment|/* 1 */
name|unsigned
name|int
name|host_addrlen
decl_stmt|;
comment|/* 1 */
name|struct
name|sockaddr
modifier|*
name|host_addr
decl_stmt|;
comment|/* 1 */
name|int
name|proto
decl_stmt|;
comment|/* 1 */
name|int
name|auth_flavourlen
decl_stmt|;
comment|/* 1 */
name|int
modifier|*
name|auth_flavours
decl_stmt|;
comment|/* 1 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfs4_args
name|nfs4_args_t
typedef|;
end_typedef

begin_comment
comment|/* HACK: these are not defined on Linux but we still need them  * internally.  We have to be able to differentiate between having a  * timeout value set to zero and not having the option at all. These  * flags are masked off before passing the nfs_args structure to  * mount2() */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACREGMIN
value|0x10000
end_define

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACREGMAX
value|0x20000
end_define

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACDIRMIN
value|0x40000
end_define

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACDIRMAX
value|0x80000
end_define

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_FLAGMASK
value|0xFFFF
end_define

begin_comment
comment|/*  * Missing definitions on redhat alpha linux  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SELECTBITS_H
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__FD_ZERO
end_ifndef

begin_comment
comment|/* This line MUST be split!  Otherwise m4 will not change it.  */
end_comment

begin_define
define|#
directive|define
name|__FD_ZERO
parameter_list|(
name|set
parameter_list|)
define|\
value|((void) memset ((__ptr_t) (set), 0, sizeof(fd_set)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __FD_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FD_SET
end_ifndef

begin_define
define|#
directive|define
name|__FD_SET
parameter_list|(
name|d
parameter_list|,
name|set
parameter_list|)
value|((set)->fds_bits[__FDELT(d)] |= __FDMASK(d))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __FD_SET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FD_CLR
end_ifndef

begin_define
define|#
directive|define
name|__FD_CLR
parameter_list|(
name|d
parameter_list|,
name|set
parameter_list|)
value|((set)->fds_bits[__FDELT(d)]&= ~__FDMASK(d))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __FD_CLR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FD_ISSET
end_ifndef

begin_define
define|#
directive|define
name|__FD_ISSET
parameter_list|(
name|d
parameter_list|,
name|set
parameter_list|)
value|((set)->fds_bits[__FDELT(d)]& __FDMASK(d))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __FD_ISSET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SELECTBITS_H */
end_comment

begin_comment
comment|/* turn off this (b/c of hlfsd) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_RPC_AUTH_DES_H
end_undef

begin_function_decl
specifier|extern
name|int
name|linux_version_code
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* use a private mapper from errno's to NFS errors */
end_comment

begin_function_decl
specifier|extern
name|int
name|linux_nfs_error
parameter_list|(
name|int
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|nfs_error
parameter_list|(
name|e
parameter_list|)
value|linux_nfs_error(e)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMU_NFS_PROT_H */
end_comment

end_unit

