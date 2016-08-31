begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/nfs_prot/nfs_prot_aix5_2.h  *  */
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
comment|/*  * AIX 5.2 has a different aix5_nfs_args structure, hence the separate header.  */
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

begin_comment
comment|/*  * AIX 5.2 wants 'struct pathcnf', but I couldn't find its definition  * anywhere.  Luckily, amd doesn't need the size of this structure in  * any other structure that it uses.  So we sidestep it for now.  */
end_comment

begin_struct_decl
struct_decl|struct
name|pathcnf
struct_decl|;
end_struct_decl

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
name|HAVE_SYS_VFS_H
end_ifdef

begin_comment
comment|/* AIX 5.3 (ppc) wants definition of kernel-specific structure */
end_comment

begin_struct_decl
struct_decl|struct
name|thread_credentials
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_VFS_H */
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
comment|/* compatible macro name with other OSs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UVMNT_FORCE
end_ifdef

begin_define
define|#
directive|define
name|MS_FORCE
value|UVMNT_FORCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UVMNT_FORCE */
end_comment

begin_comment
comment|/********************************************************************************/
end_comment

begin_comment
comment|/*  * NFS mount option flags (out of mount.h)  * Maybe one day IBM will include them in system headers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTOPT_ACDIRMAX
end_ifndef

begin_define
define|#
directive|define
name|MNTOPT_ACDIRMAX
value|"acdirmax"
end_define

begin_comment
comment|/* max ac timeout for dirs (sec) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_ACDIRMIN
value|"acdirmin"
end_define

begin_comment
comment|/* min ac timeout for dirs (sec) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_ACREGMAX
value|"acregmax"
end_define

begin_comment
comment|/* max ac timeout for reg files (sec) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_ACREGMIN
value|"acregmin"
end_define

begin_comment
comment|/* min ac timeout for reg files (sec) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_ACTIMEO
value|"actimeo"
end_define

begin_comment
comment|/* attr cache timeout (sec) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_BG
value|"bg"
end_define

begin_comment
comment|/* mount op in background if 1st attempt fails */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_FASTATTR
value|"fastattr"
end_define

begin_comment
comment|/* no sync_vp in nfs3_getattr */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_FG
value|"fg"
end_define

begin_comment
comment|/* mount op in fg if 1st attempt fails, default */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_GRPID
value|"grpid"
end_define

begin_comment
comment|/* SysV-compatible group-id on create */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_HARD
value|"hard"
end_define

begin_comment
comment|/* hard mount (default) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_INTR
value|"intr"
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOAC
value|"noac"
end_define

begin_comment
comment|/* don't cache file attributes */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOACL
value|"noacl"
end_define

begin_comment
comment|/* don't read acl's from server - default */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_ACL
value|"acl"
end_define

begin_comment
comment|/* read acl's from server means we load ksec */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOAUTO
value|"noauto"
end_define

begin_comment
comment|/* hide entry from mount -a */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOCTO
value|"nocto"
end_define

begin_comment
comment|/* no "close to open" attr consistency */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NODEV
value|"nodev"
end_define

begin_comment
comment|/*don't allow opening of devices accross mount*/
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOINTR
value|"nointr"
end_define

begin_comment
comment|/* don't allow interrupts on hard mounts */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOQUOTA
value|"noquota"
end_define

begin_comment
comment|/* don't check quotas */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NOSUID
value|"nosuid"
end_define

begin_comment
comment|/* no set uid allowed */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_BSY
value|"bsy"
end_define

begin_define
define|#
directive|define
name|MNTOPT_PORT
value|"port"
end_define

begin_comment
comment|/* server IP port number */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_POSIX
value|"posix"
end_define

begin_comment
comment|/* ask for static pathconf values from mountd */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_QUOTA
value|"quota"
end_define

begin_comment
comment|/* quotas */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RETRANS
value|"retrans"
end_define

begin_comment
comment|/* set number of request retries */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RETRYS
value|"retry"
end_define

begin_comment
comment|/* # of times mount is attempted, def=10000*/
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RMNT
value|"remount"
end_define

begin_comment
comment|/* remount to rw if mode ro */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RO
value|"ro"
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RSIZE
value|"rsize"
end_define

begin_comment
comment|/* set read size (bytes) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_RW
value|"rw"
end_define

begin_comment
comment|/* read/write */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_SECURE
value|"secure"
end_define

begin_comment
comment|/* use secure RPC for NFS */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_SHORTDEV
value|"shortdev"
end_define

begin_comment
comment|/* server dev */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_SOFT
value|"soft"
end_define

begin_comment
comment|/* soft mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_TIMEO
value|"timeo"
end_define

begin_comment
comment|/* set initial timeout (1/10 sec) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_WSIZE
value|"wsize"
end_define

begin_comment
comment|/* set write size (bytes) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_VERS
value|"vers"
end_define

begin_comment
comment|/* protocol version number indicator */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_PROTO
value|"proto"
end_define

begin_comment
comment|/* protocol network_id indicator */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_LLOCK
value|"llock"
end_define

begin_comment
comment|/* Local locking (no lock manager) */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_BIODS
value|"biods"
end_define

begin_comment
comment|/* max biods per mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_EXTATTR
value|"extraattr"
end_define

begin_comment
comment|/* extended attribute usage */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_COMBEHND
value|"combehind"
end_define

begin_comment
comment|/* extended attribute usage */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NUMCLUST
value|"numclust"
end_define

begin_comment
comment|/* max numclust per mount */
end_comment

begin_define
define|#
directive|define
name|MNTOPT_NODIRCACHE
value|"nodircache"
end_define

begin_comment
comment|/* No readdir cache */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOACL
value|0x0
end_define

begin_comment
comment|/* turn off acl support (not supported) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SHORTDEV
value|0x0
end_define

begin_comment
comment|/* server does not support 32-bit device no.                                    (not supported) */
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
comment|/* set number of request retrys */
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
name|NFSMNT_ACL
value|0x100000
end_define

begin_comment
comment|/* turn on acl support */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_BIODS
value|0x200000
end_define

begin_comment
comment|/* number of biods per mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_EXTATTR
value|0x400000
end_define

begin_comment
comment|/* extended attribute usage */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_FASTATTR
value|0x800000
end_define

begin_comment
comment|/* no sync_vp in nfs3_getattr */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_COMBEHND
value|0x1000000
end_define

begin_comment
comment|/* allow commit behind */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NUMCLUST
value|0x2000000
end_define

begin_comment
comment|/* number of cluster per mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NODIRCACHE
value|0x4000000
end_define

begin_comment
comment|/* No readdir cache */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTOPT_ACDIRMAX */
end_comment

begin_comment
comment|/********************************************************************************/
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

begin_comment
comment|/*  * If these definitions fail to compile on your AIX 5.2 system, be  * sure you install all of the necessary header files.  */
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
comment|/*  * EXTERNALS:  */
end_comment

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

begin_comment
comment|/*  * AIX 5.2 has NFS V3, but it is undefined in the header files.  * so I define everything that's needed for NFS V3 here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MNT_NFS3
end_ifdef

begin_struct
struct|struct
name|aix5_nfs_args
block|{
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
comment|/* file server address */
name|struct
name|sockaddr_in
modifier|*
name|syncaddr
decl_stmt|;
comment|/* secure NFS time sync addr */
name|int
name|proto
decl_stmt|;
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
name|struct
name|ppathcnf
modifier|*
name|pathconf
decl_stmt|;
comment|/* static pathconf kludge */
name|int
name|biods
decl_stmt|;
comment|/* biods per mount */
name|int
name|numclust
decl_stmt|;
comment|/* numclust per mount */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNT_NFS3 */
end_comment

begin_comment
comment|/*  **************************************************************************  * AIX 5.2's autofs is not ported or tested yet...  * For now, undefine it or define dummy entries.  **************************************************************************  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MNT_AUTOFS
end_ifdef

begin_undef
undef|#
directive|undef
name|MNT_AUTOFS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNT_AUTOFS */
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

