begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/include/mount_headers1.h  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TYPES_H */
end_comment

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
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PARAM_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TIME_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UCRED_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_UCRED_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SOCKET_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NETINET_IN_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NET_IF_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDIO_H
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDIO_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|KERNEL_off_for_now_breaks_FreeBSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MNTENT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mntent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MNTENT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MNTENT_H
end_ifdef

begin_include
include|#
directive|include
file|<mntent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MNTENT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MNTTAB_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mnttab.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MNTTAB_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MNTTAB_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB
argument_list|)
end_if

begin_comment
comment|/*  * Do not include it if MNTTAB is already defined because it probably  * came from<sys/mnttab.h> and we do not want conflicting definitions.  */
end_comment

begin_include
include|#
directive|include
file|<mnttab.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_MNTTAB_H)&& !defined(MNTTAB) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MOUNT_H
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NFSCLIENT
end_ifndef

begin_define
define|#
directive|define
name|NFSCLIENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFSCLIENT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCFS
end_ifndef

begin_define
define|#
directive|define
name|PCFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not PCFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOFS
end_ifndef

begin_define
define|#
directive|define
name|LOFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not LOFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RFS
end_ifndef

begin_define
define|#
directive|define
name|RFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not RFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOSFS
end_ifndef

begin_define
define|#
directive|define
name|MSDOSFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MSDOSFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MFS
end_ifndef

begin_define
define|#
directive|define
name|MFS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CD9660
end_ifndef

begin_define
define|#
directive|define
name|CD9660
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CD9660 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS
end_ifndef

begin_define
define|#
directive|define
name|NFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFS */
end_comment

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_VMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/vmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_VMOUNT_H */
end_comment

begin_comment
comment|/*  * There is no point in including this on a glibc2 system  * we're only asking for trouble  */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_LINUX_FS_H
operator|&&
operator|(
operator|!
name|defined
name|__GLIBC__
operator|||
name|__GLIBC__
operator|<
literal|2
operator|)
end_if

begin_comment
comment|/*  * There's a conflict of definitions on redhat alpha linux between  *<netinet/in.h> and<linux/fs.h>.  * Also a conflict in definitions of ntohl/htonl in RH-5.1 sparc64  * between<netinet/in.h> and<linux/byteorder/generic.h> (2.1 kernels).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SOCKETBITS_H
end_ifdef

begin_define
define|#
directive|define
name|_LINUX_SOCKET_H
end_define

begin_undef
undef|#
directive|undef
name|BLKFLSBUF
end_undef

begin_undef
undef|#
directive|undef
name|BLKGETSIZE
end_undef

begin_undef
undef|#
directive|undef
name|BLKRAGET
end_undef

begin_undef
undef|#
directive|undef
name|BLKRASET
end_undef

begin_undef
undef|#
directive|undef
name|BLKROGET
end_undef

begin_undef
undef|#
directive|undef
name|BLKROSET
end_undef

begin_undef
undef|#
directive|undef
name|BLKRRPART
end_undef

begin_undef
undef|#
directive|undef
name|MS_MGC_VAL
end_undef

begin_undef
undef|#
directive|undef
name|MS_RMT_MASK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SOCKETBITS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_POSIX_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<linux/posix_types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_POSIX_TYPES_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_BYTEORDER_GENERIC_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_BYTEORDER_GENERIC_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_BYTEORDER_GENERIC_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_STRING_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_STRING_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _LINUX_STRING_H_ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_KDEV_T_H
end_ifdef

begin_define
define|#
directive|define
name|__KERNEL__
end_define

begin_include
include|#
directive|include
file|<linux/kdev_t.h>
end_include

begin_undef
undef|#
directive|undef
name|__KERNEL__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_KDEV_T_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_LIST_H
end_ifdef

begin_define
define|#
directive|define
name|__KERNEL__
end_define

begin_include
include|#
directive|include
file|<linux/list.h>
end_include

begin_undef
undef|#
directive|undef
name|__KERNEL__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_LIST_H */
end_comment

begin_include
include|#
directive|include
file|<linux/fs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_FS_H&& (!__GLIBC__ || __GLIBC__< 2) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs_types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_TYPES_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UFS_UFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<ufs/ufs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UFS_UFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UFS_UFS_UFSMOUNT_H_off
end_ifdef

begin_error
error|#
directive|error
error|do not include this file here because on *bsd it
end_error

begin_error
error|#
directive|error
error|causes errors with other header files.  Instead, add it to the
end_error

begin_error
error|#
directive|error
error|specific conf/nfs_prot_*.h file.
end_error

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
comment|/* HAVE_UFS_UFS_UFSMOUNT_H_off */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CDFS_CDFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<cdfs/cdfs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CDFS_CDFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CDFS_CDFSMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<cdfs/cdfsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CDFS_CDFSMOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ISOFS_CD9660_CD9660_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<isofs/cd9660/cd9660_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ISOFS_CD9660_CD9660_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_PC_FS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/pc_fs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_PC_FS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MSDOSFS_MSDOSFSMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<msdosfs/msdosfsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MSDOSFS_MSDOSFSMOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_MSDOSFS_MSDOSFSMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<fs/msdosfs/msdosfsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_MSDOSFS_MSDOSFSMOUNT_H */
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
name|HAVE_RPC_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPC_TYPES_H */
end_comment

begin_comment
comment|/* Prevent multiple inclusion on Ultrix 4 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_RPC_XDR_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__XDR_HEADER__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_RPC_XDR_H)&& !defined(__XDR_HEADER__) */
end_comment

begin_comment
comment|/* ALWAYS INCLUDE AM-UTILS' SPECIFIC NFS PROTOCOL HEADER NEXT! */
end_comment

end_unit

