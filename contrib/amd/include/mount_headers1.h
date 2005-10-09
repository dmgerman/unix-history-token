begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|HAVE_UFS_UFS_UFSMOUNT_H
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXQUOTAS
end_ifndef

begin_define
define|#
directive|define
name|MAXQUOTAS
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MAXQUOTAS */
end_comment

begin_struct
struct|struct
name|netexport
block|{
name|int
name|this_is_SO_wrong
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* for bsdi-2.1 */
end_comment

begin_comment
comment|/* netbsd-1.4 does't protect<ufs/ufs/ufsmount.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_UFSMOUNT_H
end_ifndef

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
end_include

begin_define
define|#
directive|define
name|_UFS_UFS_UFSMOUNT_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _UFS_UFS_UFSMOUNT_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UFS_UFS_UFSMOUNT_H */
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

