begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * am_compat.h:  *  * This file contains compatibility functions and macros, all of which  * should be auto-discovered, but for one reason or another (mostly  * brain-damage on the part of system designers and header files) they cannot.  *  * Each compatibility macro/function must include instructions on how/when  * it can be removed the am-utils code.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AM_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_AM_COMPAT_H
end_define

begin_comment
comment|/*  * incomplete mount options definitions (sunos4, irix6, linux, etc.)  */
end_comment

begin_comment
comment|/*  * Complete MNTTAB_OPT_* options based on MNT2_NFS_OPT_* mount options.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_ACDIRMAX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_ACDIRMAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_ACDIRMAX
value|"acdirmax"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_ACDIRMAX)&& !defined(MNTTAB_OPT_ACDIRMAX) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_ACDIRMIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_ACDIRMIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_ACDIRMIN
value|"acdirmin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_ACDIRMIN)&& !defined(MNTTAB_OPT_ACDIRMIN) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_ACREGMAX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_ACREGMAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_ACREGMAX
value|"acregmax"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_ACREGMAX)&& !defined(MNTTAB_OPT_ACREGMAX) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_ACREGMIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_ACREGMIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_ACREGMIN
value|"acregmin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_ACREGMIN)&& !defined(MNTTAB_OPT_ACREGMIN) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_IGNORE
argument_list|)
end_if

begin_comment
comment|/* SunOS 4.1.x and others define "noauto" option, but not "auto" */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNTTAB_OPT_NOAUTO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_AUTO
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_AUTO
value|"auto"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNTTAB_OPT_NOAUTO)&& !defined(MNTTAB_OPT_AUTO) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(MNTTAB_OPT_IGNORE) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_NOAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NOAC
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NOAC
value|"noac"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_NOAC)&& !defined(MNTTAB_OPT_NOAC) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_NOCONN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NOCONN
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NOCONN
value|"noconn"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_CONN
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_CONN
value|"conn"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNTTAB_OPT_CONN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_NOCONN)&& !defined(MNTTAB_OPT_NOCONN) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_PGTHRESH
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_PGTHRESH
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_PGTHRESH
value|"pgthresh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_PGTHRESH)&& !defined(MNTTAB_OPT_PGTHRESH) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_RETRANS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_RETRANS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_RETRANS
value|"retrans"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_RETRANS)&& !defined(MNTTAB_OPT_RETRANS) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_RSIZE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_RSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_RSIZE
value|"rsize"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_RSIZE)&& !defined(MNTTAB_OPT_RSIZE) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_SOFT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_SOFT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_SOFT
value|"soft"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_HARD
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_HARD
value|"hard"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_HARD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_SOFT)&& !defined(MNTTAB_OPT_SOFT) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_TIMEO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_TIMEO
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_TIMEO
value|"timeo"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_TIMEO)&& !defined(MNTTAB_OPT_TIMEO) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_WSIZE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_WSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_WSIZE
value|"wsize"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_WSIZE)&& !defined(MNTTAB_OPT_WSIZE) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_NFS_OPT_MAXGRPS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_MAXGROUPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_MAXGROUPS
value|"maxgroups"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_NFS_OPT_MAXGRPS)&& !defined(MNTTAB_OPT_MAXGROUPS) */
end_comment

begin_comment
comment|/*  * Complete MNTTAB_OPT_* options based on MNT2_CDFS_OPT_* mount options.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_CDFS_OPT_DEFPERM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_DEFPERM
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_DEFPERM
value|"defperm"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_CDFS_OPT_DEFPERM)&& !defined(MNTTAB_OPT_DEFPERM) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_CDFS_OPT_NODEFPERM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NODEFPERM
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NODEFPERM
value|"nodefperm"
end_define

begin_comment
comment|/*  * DEC OSF/1 V3.x/Digital UNIX V4.0 have M_NODEFPERM only, but  * both mnttab ops.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_DEFPERM
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_DEFPERM
value|"defperm"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_DEFPERM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_CDFS_OPT_NODEFPERM)&& !defined(MNTTAB_OPT_NODEFPERM) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_CDFS_OPT_NOVERSION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NOVERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NOVERSION
value|"noversion"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_CDFS_OPT_NOVERSION)&& !defined(MNTTAB_OPT_NOVERSION) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_CDFS_OPT_RRIP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_RRIP
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_RRIP
value|"rrip"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_CDFS_OPT_RRIP)&& !defined(MNTTAB_OPT_RRIP) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_CDFS_OPT_NORRIP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NORRIP
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NORRIP
value|"norrip"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_CDFS_OPT_NORRIP)&& !defined(MNTTAB_OPT_NORRIP) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_CDFS_OPT_GENS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_GENS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_GENS
value|"gens"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_CDFS_OPT_GENS)&& !defined(MNTTAB_OPT_GENS) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_CDFS_OPT_EXTATT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_EXTATT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_EXTATT
value|"extatt"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_CDFS_OPT_EXTATT)&& !defined(MNTTAB_OPT_EXTATT) */
end_comment

begin_comment
comment|/*  * Complete MNTTAB_OPT_* options based on MNT2_GEN_OPT_* mount options.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_GRPID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_GRPID
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_GRPID
value|"grpid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_GRPID)&& !defined(MNTTAB_OPT_GRPID) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_NOCACHE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NOCACHE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NOCACHE
value|"nocache"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_NOCACHE)&& !defined(MNTTAB_OPT_NOCACHE) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_NOSUID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NOSUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NOSUID
value|"nosuid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_NOSUID)&& !defined(MNTTAB_OPT_NOSUID) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_OVERLAY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_OVERLAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_OVERLAY
value|"overlay"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_OVERLAY)&& !defined(MNTTAB_OPT_OVERLAY) */
end_comment

begin_comment
comment|/*  * Complete MNTTAB_OPT_* options and their inverse based on MNT2_GEN_OPT_*  * options.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_NODEV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NODEV
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NODEV
value|"nodev"
end_define

begin_comment
comment|/* this is missing under some versions of Linux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_DEV
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_DEV
value|"dev"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_DEV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_NODEV)&& !defined(MNTTAB_OPT_NODEV) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_NOEXEC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_NOEXEC
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_NOEXEC
value|"noexec"
end_define

begin_comment
comment|/* this is missing under some versions of Linux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_EXEC
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_EXEC
value|"exec"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_EXEC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_NOEXEC)&& !defined(MNTTAB_OPT_NOEXEC) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_QUOTA
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_QUOTA
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_QUOTA
value|"quota"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_QUOTA)&& !defined(MNTTAB_OPT_QUOTA) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNT2_GEN_OPT_SYNC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB_OPT_SYNC
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTAB_OPT_SYNC
value|"sync"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MNT2_GEN_OPT_SYNC)&& !defined(MNTTAB_OPT_SYNC) */
end_comment

begin_comment
comment|/*  * Add missing MNTTAB_OPT_* options.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_ACTIMEO
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_ACTIMEO
value|"actimeo"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_ACTIMEO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_INTR
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_INTR
value|"intr"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_INTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_PORT
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_PORT
value|"port"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_PORT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_RETRANS
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_RETRANS
value|"retrans"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_RETRANS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_RETRY
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_RETRY
value|"retry"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_RETRY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_RO
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_RO
value|"ro"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_RO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_RSIZE
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_RSIZE
value|"rsize"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_RSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_RW
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_RW
value|"rw"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_RW */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_TIMEO
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_TIMEO
value|"timeo"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_TIMEO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_WSIZE
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_WSIZE
value|"wsize"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_WSIZE */
end_comment

begin_comment
comment|/*  * Incomplete filesystem definitions (sunos4, irix6, solaris2)  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FS_CDFS
argument_list|)
operator|&&
name|defined
argument_list|(
name|MOUNT_TYPE_CDFS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTYPE_CDFS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTYPE_CDFS
value|"hsfs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_FS_CDFS)&& defined(MOUNT_TYPE_CDFS)&& !defined(MNTTYPE_CDFS) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|cdfs_args_t
end_ifndef

begin_comment
comment|/*  * Solaris has an HSFS filesystem, but does not define hsfs_args.  * XXX: the definition here for solaris is wrong, since under solaris,  * hsfs_args should be a single integer used as a bit-field for options.  * so this code has to be fixed later.  -Erez.  */
end_comment

begin_struct
struct|struct
name|hsfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* name of filesystem to mount */
name|int
name|norrip
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cdfs_args_t
value|struct hsfs_args
end_define

begin_define
define|#
directive|define
name|HAVE_FIELD_CDFS_ARGS_T_NORRIP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not cdfs_args_t */
end_comment

begin_comment
comment|/*  * if does not define struct pc_args, assume integer bit-field (irix6)  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FS_PCFS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|pcfs_args_t
argument_list|)
end_if

begin_define
define|#
directive|define
name|pcfs_args_t
value|u_int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_FS_PCFS)&& !defined(pcfs_args_t) */
end_comment

begin_comment
comment|/*  * if does not define struct ufs_args, assume integer bit-field (linux)  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FS_UFS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ufs_args_t
argument_list|)
end_if

begin_define
define|#
directive|define
name|ufs_args_t
value|u_int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_FS_UFS)&& !defined(ufs_args_t) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FS_AUTOFS
argument_list|)
operator|&&
name|defined
argument_list|(
name|MOUNT_TYPE_AUTOFS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTYPE_AUTOFS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNTTYPE_AUTOFS
value|"autofs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_FS_AUTOFS)&& defined(MOUNT_TYPE_AUTOFS)&& !defined(MNTTYPE_AUTOFS) */
end_comment

begin_comment
comment|/*  * If NFS3, then make sure that "proto" and "vers" mnttab options  * are available.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_NFS3
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_VERS
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_VERS
value|"vers"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_VERS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTAB_OPT_PROTO
end_ifndef

begin_define
define|#
directive|define
name|MNTTAB_OPT_PROTO
value|"proto"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MNTTAB_OPT_PROTO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_FS_NFS3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AM_COMPAT_H */
end_comment

end_unit

