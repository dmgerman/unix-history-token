begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $FreeBSD$  *  * portions derived from   *	$NetBSD: config.h,v 1.11 1998/08/08 22:33:37 christos Exp $  *  */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* aux/config.h.in.  Generated automatically from ./aux/configure.in by autoheader.  */
end_comment

begin_comment
comment|/*  * Start of am-utils-6.x config.h file.  * Erez Zadok<ezk@cs.columbia.edu>  *  * DO NOT EDIT BY HAND.  * Note: acconfig.h generates config.h.in, which generates config.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_H
end_define

begin_comment
comment|/*  * Check for types of amd filesystems available.  */
end_comment

begin_comment
comment|/* Define if have automount filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_AUTO
value|1
end_define

begin_comment
comment|/* Define if have direct automount filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_DIRECT
value|1
end_define

begin_comment
comment|/* Define if have "top-level" filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_TOPLVL
value|1
end_define

begin_comment
comment|/* Define if have error filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_ERROR
value|1
end_define

begin_comment
comment|/* Define if have inheritance filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_INHERIT
value|1
end_define

begin_comment
comment|/* Define if have program filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_PROGRAM
value|1
end_define

begin_comment
comment|/* Define if have symbolic-link filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_LINK
value|1
end_define

begin_comment
comment|/* Define if have symlink with existence check filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_LINKX
value|1
end_define

begin_comment
comment|/* Define if have NFS host-tree filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_HOST
value|1
end_define

begin_comment
comment|/* Define if have nfsl (NFS with local link check) filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_NFSL
value|1
end_define

begin_comment
comment|/* Define if have multi-NFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_NFSX
value|1
end_define

begin_comment
comment|/* Define if have union filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_AM_FS_UNION
value|1
end_define

begin_comment
comment|/*  * Check for types of maps available.  */
end_comment

begin_comment
comment|/* Define if have file maps (everyone should have it!) */
end_comment

begin_define
define|#
directive|define
name|HAVE_MAP_FILE
value|1
end_define

begin_comment
comment|/* Define if have NIS maps */
end_comment

begin_define
define|#
directive|define
name|HAVE_MAP_NIS
value|1
end_define

begin_comment
comment|/* Define if have NIS+ maps */
end_comment

begin_comment
comment|/* #undef HAVE_MAP_NISPLUS */
end_comment

begin_comment
comment|/* Define if have DBM maps */
end_comment

begin_comment
comment|/* #undef HAVE_MAP_DBM */
end_comment

begin_comment
comment|/* Define if have NDBM maps */
end_comment

begin_define
define|#
directive|define
name|HAVE_MAP_NDBM
value|1
end_define

begin_comment
comment|/* Define if have HESIOD maps */
end_comment

begin_comment
comment|/* #undef HAVE_MAP_HESIOD */
end_comment

begin_comment
comment|/* Define if have LDAP maps */
end_comment

begin_comment
comment|/* #undef HAVE_MAP_LDAP */
end_comment

begin_comment
comment|/* Define if have PASSWD maps */
end_comment

begin_define
define|#
directive|define
name|HAVE_MAP_PASSWD
value|1
end_define

begin_comment
comment|/* Define if have UNION maps */
end_comment

begin_define
define|#
directive|define
name|HAVE_MAP_UNION
value|1
end_define

begin_comment
comment|/*  * Check for filesystem types available.  */
end_comment

begin_comment
comment|/* Define if have UFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_UFS
value|1
end_define

begin_comment
comment|/* Define if have XFS filesystem (irix) */
end_comment

begin_comment
comment|/* #undef HAVE_FS_XFS */
end_comment

begin_comment
comment|/* Define if have EFS filesystem (irix) */
end_comment

begin_comment
comment|/* #undef HAVE_FS_EFS */
end_comment

begin_comment
comment|/* Define if have NFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_NFS
value|1
end_define

begin_comment
comment|/* Define if have NFS3 filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_NFS3
value|1
end_define

begin_comment
comment|/* Define if have PCFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_PCFS
value|1
end_define

begin_comment
comment|/* Define if have LOFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_LOFS
value|1
end_define

begin_comment
comment|/* Define if have HSFS filesystem */
end_comment

begin_comment
comment|/* #undef HAVE_FS_HSFS */
end_comment

begin_comment
comment|/* Define if have CDFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_CDFS
value|1
end_define

begin_comment
comment|/* Define if have TFS filesystem */
end_comment

begin_comment
comment|/* #undef HAVE_FS_TFS */
end_comment

begin_comment
comment|/* Define if have TMPFS filesystem */
end_comment

begin_comment
comment|/* #undef HAVE_FS_TMPFS */
end_comment

begin_comment
comment|/* Define if have MFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_MFS
value|1
end_define

begin_comment
comment|/* Define if have CFS (crypto) filesystem */
end_comment

begin_comment
comment|/* #undef HAVE_FS_CFS */
end_comment

begin_comment
comment|/* Define if have AUTOFS filesystem */
end_comment

begin_comment
comment|/* #undef HAVE_FS_AUTOFS */
end_comment

begin_comment
comment|/* Define if have CACHEFS filesystem */
end_comment

begin_comment
comment|/* #undef HAVE_FS_CACHEFS */
end_comment

begin_comment
comment|/* Define if have NULLFS (loopback on bsd44) filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_NULLFS
value|1
end_define

begin_comment
comment|/* Define if have UNIONFS filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_UNIONFS
value|1
end_define

begin_comment
comment|/* Define if have UMAPFS (uid/gid mapping) filesystem */
end_comment

begin_define
define|#
directive|define
name|HAVE_FS_UMAPFS
value|1
end_define

begin_comment
comment|/*  * Check for the type of the mount(2) system name for a filesystem.  * Normally this is "nfs" (e.g. Solaris) or an integer (older systems)  */
end_comment

begin_comment
comment|/* Mount(2) type/name for UFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|"ufs"
end_define

begin_comment
comment|/* Mount(2) type/name for XFS filesystem (irix) */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_XFS */
end_comment

begin_comment
comment|/* Mount(2) type/name for EFS filesystem (irix) */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_EFS */
end_comment

begin_comment
comment|/* Mount(2) type/name for NFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|"nfs"
end_define

begin_comment
comment|/* Mount(2) type/name for NFS3 filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS3
value|"nfs"
end_define

begin_comment
comment|/* Mount(2) type/name for PCFS filesystem */
end_comment

begin_comment
comment|/* XXX: conf/trap/trap_hpux.h may override this definition for HPUX 9.0 */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_PCFS
value|"msdos"
end_define

begin_comment
comment|/* Mount(2) type/name for LOFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_LOFS
value|"lofs"
end_define

begin_comment
comment|/* Mount(2) type/name for CDFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_CDFS
value|"cd9660"
end_define

begin_comment
comment|/* Mount(2) type/name for TFS filesystem */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_TFS */
end_comment

begin_comment
comment|/* Mount(2) type/name for TMPFS filesystem */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_TMPFS */
end_comment

begin_comment
comment|/* Mount(2) type/name for MFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_MFS
value|"mfs"
end_define

begin_comment
comment|/* Mount(2) type/name for CFS (crypto) filesystem */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_CFS */
end_comment

begin_comment
comment|/* Mount(2) type/name for AUTOFS filesystem */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_AUTOFS */
end_comment

begin_comment
comment|/* Mount(2) type/name for CACHEFS filesystem */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_CACHEFS */
end_comment

begin_comment
comment|/* Mount(2) type/name for IGNORE filesystem (not real just ignore for df) */
end_comment

begin_comment
comment|/* #undef MOUNT_TYPE_IGNORE */
end_comment

begin_comment
comment|/* Mount(2) type/name for NULLFS (loopback on bsd44) filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NULLFS
value|"null"
end_define

begin_comment
comment|/* Mount(2) type/name for UNIONFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_UNIONFS
value|"union"
end_define

begin_comment
comment|/* Mount(2) type/name for UMAPFS (uid/gid mapping) filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_UMAPFS
value|"umap"
end_define

begin_comment
comment|/*  * Check for the string name for the mount-table of a filesystem.  */
end_comment

begin_comment
comment|/* Mount-table entry name for UFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_UFS
value|"ufs"
end_define

begin_comment
comment|/* Mount-table entry name for XFS filesystem (irix) */
end_comment

begin_comment
comment|/* #undef MNTTAB_TYPE_XFS */
end_comment

begin_comment
comment|/* Mount-table entry name for EFS filesystem (irix) */
end_comment

begin_comment
comment|/* #undef MNTTAB_TYPE_EFS */
end_comment

begin_comment
comment|/* Mount-table entry name for NFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_NFS
value|"nfs"
end_define

begin_comment
comment|/* Mount-table entry name for NFS3 filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_NFS3
value|"nfs"
end_define

begin_comment
comment|/* Mount-table entry name for PCFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_PCFS
value|"msdos"
end_define

begin_comment
comment|/* Mount-table entry name for LOFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_LOFS
value|"lofs"
end_define

begin_comment
comment|/* Mount-table entry name for CDFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_CDFS
value|"cd9660"
end_define

begin_comment
comment|/* Mount-table entry name for TFS filesystem */
end_comment

begin_comment
comment|/* #undef MNTTAB_TYPE_TFS */
end_comment

begin_comment
comment|/* Mount-table entry name for TMPFS filesystem */
end_comment

begin_comment
comment|/* #undef MNTTAB_TYPE_TMPFS */
end_comment

begin_comment
comment|/* Mount-table entry name for MFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_MFS
value|"mfs"
end_define

begin_comment
comment|/* Mount-table entry name for CFS (crypto) filesystem */
end_comment

begin_comment
comment|/* #undef MNTTAB_TYPE_CFS */
end_comment

begin_comment
comment|/* Mount-table entry name for AUTOFS filesystem */
end_comment

begin_comment
comment|/* #undef MNTTAB_TYPE_AUTOFS */
end_comment

begin_comment
comment|/* Mount-table entry name for CACHEFS filesystem */
end_comment

begin_comment
comment|/* #undef MNTTAB_TYPE_CACHEFS */
end_comment

begin_comment
comment|/* Mount-table entry name for NULLFS (loopback on bsd44) filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_NULLFS
value|"null"
end_define

begin_comment
comment|/* Mount-table entry name for UNIONFS filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_UNIONFS
value|"union"
end_define

begin_comment
comment|/* Mount-table entry name for UMAPFS (uid/gid mapping) filesystem */
end_comment

begin_define
define|#
directive|define
name|MNTTAB_TYPE_UMAPFS
value|"umap"
end_define

begin_comment
comment|/*  * Name of mount table file name.  */
end_comment

begin_comment
comment|/* #undef MNTTAB_FILE_NAME */
end_comment

begin_comment
comment|/* Name of mount type to hide amd mount from df(1) */
end_comment

begin_define
define|#
directive|define
name|HIDE_MOUNT_TYPE
value|"nfs"
end_define

begin_comment
comment|/*  * Names of various mount table option strings.  */
end_comment

begin_comment
comment|/* Mount Table option string: Read only */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_RO */
end_comment

begin_comment
comment|/* Mount Table option string: Read/write */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_RW */
end_comment

begin_comment
comment|/* Mount Table option string: Read/write with quotas */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_RQ */
end_comment

begin_comment
comment|/* Mount Table option string: Check quotas */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_QUOTA */
end_comment

begin_comment
comment|/* Mount Table option string: Don't check quotas */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOQUOTA */
end_comment

begin_comment
comment|/* Mount Table option string: action to taken on error */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_ONERROR */
end_comment

begin_comment
comment|/* Mount Table option string: min. time between inconsistencies */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_TOOSOON */
end_comment

begin_comment
comment|/* Mount Table option string: Soft mount */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_SOFT */
end_comment

begin_comment
comment|/* Mount Table option string: spongy mount */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_SPONGY */
end_comment

begin_comment
comment|/* Mount Table option string: Hard mount */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_HARD */
end_comment

begin_comment
comment|/* Mount Table option string: Set uid allowed */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_SUID */
end_comment

begin_comment
comment|/* Mount Table option string: Set uid not allowed */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOSUID */
end_comment

begin_comment
comment|/* Mount Table option string: SysV-compatible gid on create */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_GRPID */
end_comment

begin_comment
comment|/* Mount Table option string: Change mount options */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_REMOUNT */
end_comment

begin_comment
comment|/* Mount Table option string: Disallow mounts on subdirs */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOSUB */
end_comment

begin_comment
comment|/* Mount Table option string: Do multi-component lookup */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_MULTI */
end_comment

begin_comment
comment|/* Mount Table option string: Allow NFS ops to be interrupted */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_INTR */
end_comment

begin_comment
comment|/* Mount Table option string: Don't allow interrupted ops */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOINTR */
end_comment

begin_comment
comment|/* Mount Table option string: NFS server IP port number */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_PORT */
end_comment

begin_comment
comment|/* Mount Table option string: Secure (AUTH_DES) mounting */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_SECURE */
end_comment

begin_comment
comment|/* Mount Table option string: Secure (AUTH_Kerb) mounting */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_KERB */
end_comment

begin_comment
comment|/* Mount Table option string: Max NFS read size (bytes) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_RSIZE */
end_comment

begin_comment
comment|/* Mount Table option string: Max NFS write size (bytes) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_WSIZE */
end_comment

begin_comment
comment|/* Mount Table option string: NFS timeout (1/10 sec) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_TIMEO */
end_comment

begin_comment
comment|/* Mount Table option string: Max retransmissions (soft mnts) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_RETRANS */
end_comment

begin_comment
comment|/* Mount Table option string: Attr cache timeout (sec) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_ACTIMEO */
end_comment

begin_comment
comment|/* Mount Table option string: Min attr cache timeout (files) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_ACREGMIN */
end_comment

begin_comment
comment|/* Mount Table option string: Max attr cache timeout (files) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_ACREGMAX */
end_comment

begin_comment
comment|/* Mount Table option string: Min attr cache timeout (dirs) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_ACDIRMIN */
end_comment

begin_comment
comment|/* Mount Table option string: Max attr cache timeout (dirs) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_ACDIRMAX */
end_comment

begin_comment
comment|/* Mount Table option string: Don't cache attributes at all */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOAC */
end_comment

begin_comment
comment|/* Mount Table option string: No close-to-open consistency */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOCTO */
end_comment

begin_comment
comment|/* Mount Table option string: Do mount retries in background */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_BG */
end_comment

begin_comment
comment|/* Mount Table option string: Do mount retries in foreground */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_FG */
end_comment

begin_comment
comment|/* Mount Table option string: Number of mount retries */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_RETRY */
end_comment

begin_comment
comment|/* Mount Table option string: Device id of mounted fs */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_DEV */
end_comment

begin_comment
comment|/* Mount Table option string: Filesystem id of mounted fs */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_FSID */
end_comment

begin_comment
comment|/* Mount Table option string: Get static pathconf for mount */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_POSIX */
end_comment

begin_comment
comment|/* Mount Table option string: Automount map */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_MAP */
end_comment

begin_comment
comment|/* Mount Table option string: Automount   direct map mount */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_DIRECT */
end_comment

begin_comment
comment|/* Mount Table option string: Automount indirect map mount */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_INDIRECT */
end_comment

begin_comment
comment|/* Mount Table option string: Local locking (no lock manager) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_LLOCK */
end_comment

begin_comment
comment|/* Mount Table option string: Ignore this entry */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_IGNORE */
end_comment

begin_comment
comment|/* Mount Table option string: No auto (what?) */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOAUTO */
end_comment

begin_comment
comment|/* Mount Table option string: No connection */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOCONN */
end_comment

begin_comment
comment|/* Mount Table option string: protocol version number indicator */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_VERS */
end_comment

begin_comment
comment|/* Mount Table option string: protocol network_id indicator */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_PROTO */
end_comment

begin_comment
comment|/* Mount Table option string: Synchronous local directory ops */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_SYNCDIR */
end_comment

begin_comment
comment|/* Mount Table option string: Do no allow setting sec attrs */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_NOSETSEC */
end_comment

begin_comment
comment|/* Mount Table option string: set symlink cache time-to-live */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_SYMTTL */
end_comment

begin_comment
comment|/* Mount Table option string: compress */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_COMPRESS */
end_comment

begin_comment
comment|/* Mount Table option string: paging threshold */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_PGTHRESH */
end_comment

begin_comment
comment|/* Mount Table option string: max groups */
end_comment

begin_comment
comment|/* #undef MNTTAB_OPT_MAXGROUPS */
end_comment

begin_comment
comment|/*  * Generic mount(2) options (hex numbers)  */
end_comment

begin_comment
comment|/* asynchronous filesystem access */
end_comment

begin_define
define|#
directive|define
name|MNT2_GEN_OPT_ASYNC
value|0x40
end_define

begin_comment
comment|/* automounter filesystem (ignore) flag, used in bsdi-4.1 */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_AUTOMNTFS */
end_comment

begin_comment
comment|/* cache (what?) */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_CACHE */
end_comment

begin_comment
comment|/* 6-argument mount */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_DATA */
end_comment

begin_comment
comment|/* old (4-argument) mount (compatibility) */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_FSS */
end_comment

begin_comment
comment|/* ignore mount entry in df output */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_IGNORE */
end_comment

begin_comment
comment|/* journaling filesystem (AIX's UFS/FFS) */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_JFS */
end_comment

begin_comment
comment|/* old BSD group-id on create */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_GRPID */
end_comment

begin_comment
comment|/* do multi-component lookup on files */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_MULTI */
end_comment

begin_comment
comment|/* use type string instead of int */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_NEWTYPE */
end_comment

begin_comment
comment|/* NFS mount */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_NFS */
end_comment

begin_comment
comment|/* nocache (what?) */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_NOCACHE */
end_comment

begin_comment
comment|/* not a device */
end_comment

begin_define
define|#
directive|define
name|MNT2_GEN_OPT_NODEV
value|0x10
end_define

begin_comment
comment|/* no exec calls allowed */
end_comment

begin_define
define|#
directive|define
name|MNT2_GEN_OPT_NOEXEC
value|0x4
end_define

begin_comment
comment|/* not a device  */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_NONDEV */
end_comment

begin_comment
comment|/* Disallow mounts beneath this mount */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_NOSUB */
end_comment

begin_comment
comment|/* Setuid programs disallowed */
end_comment

begin_define
define|#
directive|define
name|MNT2_GEN_OPT_NOSUID
value|0x8
end_define

begin_comment
comment|/* Return ENAMETOOLONG for long filenames */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_NOTRUNC */
end_comment

begin_comment
comment|/* allow overlay mounts */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_OVERLAY */
end_comment

begin_comment
comment|/* check quotas */
end_comment

begin_define
define|#
directive|define
name|MNT2_GEN_OPT_QUOTA
value|0x2000
end_define

begin_comment
comment|/* Read-only */
end_comment

begin_define
define|#
directive|define
name|MNT2_GEN_OPT_RDONLY
value|0x1
end_define

begin_comment
comment|/* change options on an existing mount */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_REMOUNT */
end_comment

begin_comment
comment|/* read only */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_RONLY */
end_comment

begin_comment
comment|/* synchronize data immediately to filesystem */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_SYNC */
end_comment

begin_comment
comment|/* synchronous filesystem access (same as SYNC) */
end_comment

begin_define
define|#
directive|define
name|MNT2_GEN_OPT_SYNCHRONOUS
value|0x2
end_define

begin_comment
comment|/* Mount with Sys 5-specific semantics */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_SYS5 */
end_comment

begin_comment
comment|/* Union mount */
end_comment

begin_comment
comment|/* #undef MNT2_GEN_OPT_UNION */
end_comment

begin_comment
comment|/*  * NFS-specific mount(2) options (hex numbers)  */
end_comment

begin_comment
comment|/* hide mount type from df(1) */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_AUTO */
end_comment

begin_comment
comment|/* set max secs for dir attr cache */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACDIRMAX
value|0x200000
end_define

begin_comment
comment|/* set min secs for dir attr cache */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACDIRMIN
value|0x100000
end_define

begin_comment
comment|/* set max secs for file attr cache */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACREGMAX
value|0x80000
end_define

begin_comment
comment|/* set min secs for file attr cache */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_ACREGMIN
value|0x40000
end_define

begin_comment
comment|/* Authentication error */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_AUTHERR */
end_comment

begin_comment
comment|/* set dead server retry thresh */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_DEADTHRESH
value|0x4000
end_define

begin_comment
comment|/* Dismount in progress */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_DISMINPROG */
end_comment

begin_comment
comment|/* Dismounted */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_DISMNT */
end_comment

begin_comment
comment|/* Don't estimate rtt dynamically */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_DUMBTIMR
value|0x800
end_define

begin_comment
comment|/* System V-style gid inheritance */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_GRPID */
end_comment

begin_comment
comment|/* Has authenticator */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_HASAUTH */
end_comment

begin_comment
comment|/* provide name of server's fs to system */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_FSNAME */
end_comment

begin_comment
comment|/* set hostname for error printf */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_HOSTNAME */
end_comment

begin_comment
comment|/* ignore mount point */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_IGNORE */
end_comment

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_INT
value|0x40
end_define

begin_comment
comment|/* Bits set internally */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_INTERNAL */
end_comment

begin_comment
comment|/* Use Kerberos authentication */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_KERB */
end_comment

begin_comment
comment|/* use kerberos credentials */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_KERBEROS */
end_comment

begin_comment
comment|/* transport's knetconfig structure */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_KNCONF */
end_comment

begin_comment
comment|/* set lease term (nqnfs) */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_LEASETERM
value|0x1000
end_define

begin_comment
comment|/* Local locking (no lock manager) */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_LLOCK */
end_comment

begin_comment
comment|/* set maximum grouplist size */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_MAXGRPS
value|0x20
end_define

begin_comment
comment|/* Mnt server for mnt point */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_MNTD */
end_comment

begin_comment
comment|/* Assume writes were mine */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_MYWRITE */
end_comment

begin_comment
comment|/* mount NFS Version 3 */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_NFSV3
value|0x200
end_define

begin_comment
comment|/* don't cache attributes */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_NOAC */
end_comment

begin_comment
comment|/* Don't Connect the socket */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_NOCONN
value|0x80
end_define

begin_comment
comment|/* no close-to-open consistency */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_NOCTO */
end_comment

begin_comment
comment|/* disallow interrupts on hard mounts */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_NOINT */
end_comment

begin_comment
comment|/* Get lease for lookup */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_NQLOOKLEASE */
end_comment

begin_comment
comment|/* Use Nqnfs protocol */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_NQNFS
value|0x100
end_define

begin_comment
comment|/* static pathconf kludge info */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_POSIX */
end_comment

begin_comment
comment|/* Rcv socket lock */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_RCVLOCK */
end_comment

begin_comment
comment|/* Do lookup with readdir (nqnfs) */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_RDIRALOOK */
end_comment

begin_comment
comment|/* set read ahead */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_READAHEAD
value|0x2000
end_define

begin_comment
comment|/* Allocate a reserved port */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_RESVPORT
value|0x8000
end_define

begin_comment
comment|/* set number of request retries */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_RETRANS
value|0x10
end_define

begin_comment
comment|/* read only */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_RONLY */
end_comment

begin_comment
comment|/* use RPC to do secure NFS time sync */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_RPCTIMESYNC */
end_comment

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_RSIZE
value|0x4
end_define

begin_comment
comment|/* secure mount */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_SECURE */
end_comment

begin_comment
comment|/* Send socket lock */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_SNDLOCK */
end_comment

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_SOFT
value|0x1
end_define

begin_comment
comment|/* spongy mount */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_SPONGY */
end_comment

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_TIMEO
value|0x8
end_define

begin_comment
comment|/* use TCP for mounts */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_TCP */
end_comment

begin_comment
comment|/* Wait for authentication */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_WAITAUTH */
end_comment

begin_comment
comment|/* Wants an authenticator */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_WANTAUTH */
end_comment

begin_comment
comment|/* Want receive socket lock */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_WANTRCV */
end_comment

begin_comment
comment|/* Want send socket lock */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_WANTSND */
end_comment

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|MNT2_NFS_OPT_WSIZE
value|0x2
end_define

begin_comment
comment|/* set symlink cache time-to-live */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_SYMTTL */
end_comment

begin_comment
comment|/* paging threshold */
end_comment

begin_comment
comment|/* #undef MNT2_NFS_OPT_PGTHRESH */
end_comment

begin_comment
comment|/*  * CDFS-specific mount(2) options (hex numbers)  */
end_comment

begin_comment
comment|/* Ignore permission bits */
end_comment

begin_comment
comment|/* #undef MNT2_CDFS_OPT_DEFPERM */
end_comment

begin_comment
comment|/* Use on-disk permission bits */
end_comment

begin_comment
comment|/* #undef MNT2_CDFS_OPT_NODEFPERM */
end_comment

begin_comment
comment|/* Strip off extension from version string */
end_comment

begin_comment
comment|/* #undef MNT2_CDFS_OPT_NOVERSION */
end_comment

begin_comment
comment|/* Use Rock Ridge Interchange Protocol (RRIP) extensions */
end_comment

begin_comment
comment|/* #undef MNT2_CDFS_OPT_RRIP */
end_comment

begin_comment
comment|/*  * Existence of fields in structures.  */
end_comment

begin_comment
comment|/* does mntent_t have mnt_cnode field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_MNTENT_T_MNT_CNODE */
end_comment

begin_comment
comment|/* does mntent_t have mnt_time field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_MNTENT_T_MNT_TIME */
end_comment

begin_comment
comment|/* does mntent_t have mnt_time field and is of type "char *" ? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_MNTENT_T_MNT_TIME_STRING */
end_comment

begin_comment
comment|/* does mntent_t have mnt_ro field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_MNTENT_T_MNT_RO */
end_comment

begin_comment
comment|/* does cdfs_args_t have flags field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_CDFS_ARGS_T_FLAGS
value|1
end_define

begin_comment
comment|/* does cdfs_args_t have fspec field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_CDFS_ARGS_T_FSPEC
value|1
end_define

begin_comment
comment|/* does cdfs_args_t have iso_flags field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_CDFS_ARGS_T_ISO_FLAGS */
end_comment

begin_comment
comment|/* does cdfs_args_t have iso_pgthresh field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_CDFS_ARGS_T_ISO_PGTHRESH */
end_comment

begin_comment
comment|/* does cdfs_args_t have norrip field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_CDFS_ARGS_T_NORRIP */
end_comment

begin_comment
comment|/* does cdfs_args_t have ssector field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_CDFS_ARGS_T_SSECTOR
value|1
end_define

begin_comment
comment|/* does pcfs_args_t have dsttime field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_PCFS_ARGS_T_DSTTIME */
end_comment

begin_comment
comment|/* does pcfs_args_t have fspec field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_PCFS_ARGS_T_FSPEC
value|1
end_define

begin_comment
comment|/* does pcfs_args_t have gid field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_PCFS_ARGS_T_GID
value|1
end_define

begin_comment
comment|/* does pcfs_args_t have mask field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_PCFS_ARGS_T_MASK
value|1
end_define

begin_comment
comment|/* does pcfs_args_t have secondswest field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_PCFS_ARGS_T_SECONDSWEST */
end_comment

begin_comment
comment|/* does pcfs_args_t have uid field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_PCFS_ARGS_T_UID
value|1
end_define

begin_comment
comment|/* does ufs_args_t have flags field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_UFS_ARGS_T_FLAGS */
end_comment

begin_comment
comment|/* does ufs_args_t have fspec field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_UFS_ARGS_T_FSPEC
value|1
end_define

begin_comment
comment|/* does efs_args_t have flags field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_EFS_ARGS_T_FLAGS */
end_comment

begin_comment
comment|/* does efs_args_t have fspec field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_EFS_ARGS_T_FSPEC */
end_comment

begin_comment
comment|/* does xfs_args_t have flags field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_XFS_ARGS_T_FLAGS */
end_comment

begin_comment
comment|/* does xfs_args_t have fspec field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_XFS_ARGS_T_FSPEC */
end_comment

begin_comment
comment|/* does ufs_ars_t have ufs_flags field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_UFS_ARGS_T_UFS_FLAGS */
end_comment

begin_comment
comment|/* does ufs_ars_t have ufs_pgthresh field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_UFS_ARGS_T_UFS_PGTHRESH */
end_comment

begin_comment
comment|/* does struct fhstatus have a fhs_fh field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_STRUCT_FHSTATUS_FHS_FH */
end_comment

begin_comment
comment|/* does struct statfs have an f_fstypename field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_STRUCT_STATFS_F_FSTYPENAME
value|1
end_define

begin_comment
comment|/* does struct nfs_args have an acdirmin field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_NFS_ARGS_T_ACDIRMIN
value|1
end_define

begin_comment
comment|/* does struct nfs_args have an acregmin field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_NFS_ARGS_T_ACREGMIN
value|1
end_define

begin_comment
comment|/* does struct nfs_args have a bsize field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_NFS_ARGS_T_BSIZE */
end_comment

begin_comment
comment|/* does struct nfs_args have an fh_len field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_NFS_ARGS_T_FH_LEN */
end_comment

begin_comment
comment|/* does struct nfs_args have an fhsize field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_NFS_ARGS_T_FHSIZE
value|1
end_define

begin_comment
comment|/* does struct nfs_args have a gfs_flags field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_NFS_ARGS_T_GFS_FLAGS */
end_comment

begin_comment
comment|/* does struct nfs_args have a namlen field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_NFS_ARGS_T_NAMLEN */
end_comment

begin_comment
comment|/* does struct nfs_args have an optstr field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_NFS_ARGS_T_OPTSTR */
end_comment

begin_comment
comment|/* does struct nfs_args have a proto field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_NFS_ARGS_T_PROTO
value|1
end_define

begin_comment
comment|/* does struct nfs_args have a socket type field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_NFS_ARGS_T_SOTYPE
value|1
end_define

begin_comment
comment|/* does struct nfs_args have a version field? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_NFS_ARGS_T_VERSION
value|1
end_define

begin_comment
comment|/* does struct ifreq have field ifr_addr? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_STRUCT_IFREQ_IFR_ADDR
value|1
end_define

begin_comment
comment|/* does struct ifaddrs have field ifa_next? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_STRUCT_IFADDRS_IFA_NEXT */
end_comment

begin_comment
comment|/* does struct sockaddr have field sa_len? */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIELD_STRUCT_SOCKADDR_SA_LEN
value|1
end_define

begin_comment
comment|/* does struct autofs_args have an addr field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_AUTOFS_ARGS_T_ADDR */
end_comment

begin_comment
comment|/* does umntrequest have an rdevid field? */
end_comment

begin_comment
comment|/* #undef HAVE_FIELD_UMNTREQUEST_RDEVID */
end_comment

begin_comment
comment|/* should signal handlers be reinstalled? */
end_comment

begin_comment
comment|/* #undef REINSTALL_SIGNAL_HANDLER */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** Everything above this line is part of the "TOP" of acconfig.h.	***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/* Define if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_comment
comment|/* #undef _ALL_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to the type of elements in the array set by `getgroups'.    Usually this is either `int' or `gid_t'.  */
end_comment

begin_define
define|#
directive|define
name|GETGROUPS_T
value|gid_t
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define if you have alloca, as a function or macro.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you support file names longer than 14 characters.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_FILE_NAMES
value|1
end_define

begin_comment
comment|/* Define if system calls automatically restart after interruption    by a signal.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESTARTABLE_SYSCALLS
value|1
end_define

begin_comment
comment|/* Define if your struct stat has st_rdev.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_RDEV
value|1
end_define

begin_comment
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have<vfork.h>.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define if you have the wait3 system call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT3
value|1
end_define

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define if your C compiler doesn't accept -c and -o together.  */
end_comment

begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if the `S_IS*' macros in<sys/stat.h> do not work properly.  */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if your<sys/time.h> declares struct tm.  */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if your processor stores words with the most significant    byte first (like Motorola and SPARC, unlike Intel and VAX).  */
end_comment

begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if lex declares yytext as a char * by default, not a char[].  */
end_comment

begin_define
define|#
directive|define
name|YYTEXT_POINTER
value|1
end_define

begin_comment
comment|/* Turn off general debugging by default */
end_comment

begin_comment
comment|/* #undef DEBUG */
end_comment

begin_comment
comment|/* Turn off memory debugging by default */
end_comment

begin_comment
comment|/* #undef DEBUG_MEM */
end_comment

begin_comment
comment|/* Enable "amq -M" remote mount code (insecure due to IP spoofing) */
end_comment

begin_comment
comment|/* #undef ENABLE_AMQ_MOUNT */
end_comment

begin_comment
comment|/* Define package name (must be defined by configure.in) */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"am-utils"
end_define

begin_comment
comment|/* Define version of package (must be defined by configure.in) */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"6.0.3s1"
end_define

begin_comment
comment|/* We [FREEBSD-NATIVE] pick some parameters from our local config file */
end_comment

begin_include
include|#
directive|include
file|"config_local.h"
end_include

begin_comment
comment|/* Define name of host machine's cpu (eg. sparc) */
end_comment

begin_comment
comment|/* #define HOST_CPU "i386" */
end_comment

begin_comment
comment|/* Define name of host machine's architecture (eg. sun4) */
end_comment

begin_comment
comment|/* #define HOST_ARCH "i386" */
end_comment

begin_comment
comment|/* Define name of host machine's vendor (eg. sun) */
end_comment

begin_define
define|#
directive|define
name|HOST_VENDOR
value|"unknown"
end_define

begin_comment
comment|/* Define name and version of host machine (eg. solaris2.5.1) */
end_comment

begin_comment
comment|/* #define HOST_OS "freebsd3.0" */
end_comment

begin_comment
comment|/* Define only name of host machine OS (eg. solaris2) */
end_comment

begin_comment
comment|/* #define HOST_OS_NAME "freebsd3" */
end_comment

begin_comment
comment|/* Define only version of host machine (eg. 2.5.1) */
end_comment

begin_comment
comment|/* #define HOST_OS_VERSION "3.0" */
end_comment

begin_comment
comment|/* Define the header version of (linux) hosts (eg. 2.2.10) */
end_comment

begin_comment
comment|/* #define HOST_HEADER_VERSION "4.0" */
end_comment

begin_comment
comment|/* Define name of host */
end_comment

begin_comment
comment|/* #define HOST_NAME "dragon.nuxi.com" */
end_comment

begin_comment
comment|/* Define user name */
end_comment

begin_comment
comment|/* #define USER_NAME "obrien" */
end_comment

begin_comment
comment|/* Define configuration date */
end_comment

begin_comment
comment|/* #define CONFIG_DATE "Fri Aug 21 19:35:55 PDT 1998" */
end_comment

begin_comment
comment|/* what type of network transport type is in use?  TLI or sockets? */
end_comment

begin_comment
comment|/* #undef HAVE_TRANSPORT_TYPE_TLI */
end_comment

begin_comment
comment|/* Define to "void *" if compiler can handle, otherwise "char *" */
end_comment

begin_define
define|#
directive|define
name|voidp
value|void *
end_define

begin_comment
comment|/* Define a type/structure for an NFS V2 filehandle */
end_comment

begin_define
define|#
directive|define
name|am_nfs_fh
value|nfs_fh
end_define

begin_comment
comment|/* Define a type/structure for an NFS V3 filehandle */
end_comment

begin_define
define|#
directive|define
name|am_nfs_fh3
value|nfs_fh3
end_define

begin_comment
comment|/* define name of am-utils' NFS protocol header */
end_comment

begin_define
define|#
directive|define
name|AMU_NFS_PROTOCOL_HEADER
value|"./conf/nfs_prot/nfs_prot_freebsd3.h"
end_define

begin_comment
comment|/* Define a type for the nfs_args structure */
end_comment

begin_define
define|#
directive|define
name|nfs_args_t
value|struct nfs_args
end_define

begin_comment
comment|/* Define the field name for the filehandle within nfs_args_t */
end_comment

begin_define
define|#
directive|define
name|NFS_FH_FIELD
value|fh
end_define

begin_comment
comment|/* Define if plain fhandle type exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_FHANDLE
value|1
end_define

begin_comment
comment|/* Define the type of the 3rd argument ('in') to svc_getargs() */
end_comment

begin_define
define|#
directive|define
name|SVC_IN_ARG_TYPE
value|caddr_t
end_define

begin_comment
comment|/* Define to the type of xdr procedure type */
end_comment

begin_define
define|#
directive|define
name|XDRPROC_T_TYPE
value|xdrproc_t
end_define

begin_comment
comment|/* Define if mount table is on file, undefine if in kernel */
end_comment

begin_comment
comment|/* #undef MOUNT_TABLE_ON_FILE */
end_comment

begin_comment
comment|/* Define if have struct mntent in one of the standard headers */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_MNTENT */
end_comment

begin_comment
comment|/* Define if have struct mnttab in one of the standard headers */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_MNTTAB */
end_comment

begin_comment
comment|/* Define if have struct nfs_args in one of the standard nfs headers */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_NFS_ARGS
value|1
end_define

begin_comment
comment|/* Define if have struct nfs_mount_data in one of the standard nfs headers */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_NFS_MOUNT_DATA */
end_comment

begin_comment
comment|/* Define if have struct nfs_gfs_mount in one of the standard nfs headers */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_NFS_GFS_MOUNT */
end_comment

begin_comment
comment|/* Type of the 3rd argument to yp_order() */
end_comment

begin_define
define|#
directive|define
name|YP_ORDER_OUTORDER_TYPE
value|int
end_define

begin_comment
comment|/* Type of the 6th argument to recvfrom() */
end_comment

begin_define
define|#
directive|define
name|RECVFROM_FROMLEN_TYPE
value|int
end_define

begin_comment
comment|/* Type of the 5rd argument to authunix_create() */
end_comment

begin_define
define|#
directive|define
name|AUTH_CREATE_GIDLIST_TYPE
value|gid_t
end_define

begin_comment
comment|/* The string used in printf to print the mount-type field of mount(2) */
end_comment

begin_define
define|#
directive|define
name|MTYPE_PRINTF_TYPE
value|"%s"
end_define

begin_comment
comment|/* Type of the mount-type field in the mount() system call */
end_comment

begin_define
define|#
directive|define
name|MTYPE_TYPE
value|const char *
end_define

begin_comment
comment|/* Define a type for the pcfs_args structure */
end_comment

begin_define
define|#
directive|define
name|pcfs_args_t
value|struct msdosfs_args
end_define

begin_comment
comment|/* Define a type for the autofs_args structure */
end_comment

begin_comment
comment|/* #undef autofs_args_t */
end_comment

begin_comment
comment|/* Define a type for the cachefs_args structure */
end_comment

begin_comment
comment|/* #undef cachefs_args_t */
end_comment

begin_comment
comment|/* Define a type for the tmpfs_args structure */
end_comment

begin_comment
comment|/* #undef tmpfs_args_t */
end_comment

begin_comment
comment|/* Define a type for the ufs_args structure */
end_comment

begin_define
define|#
directive|define
name|ufs_args_t
value|struct ufs_args
end_define

begin_comment
comment|/* Define a type for the efs_args structure */
end_comment

begin_comment
comment|/* #undef efs_args_t */
end_comment

begin_comment
comment|/* Define a type for the xfs_args structure */
end_comment

begin_comment
comment|/* #undef xfs_args_t */
end_comment

begin_comment
comment|/* Define a type for the lofs_args structure */
end_comment

begin_comment
comment|/* #undef lofs_args_t */
end_comment

begin_comment
comment|/* Define a type for the cdfs_args structure */
end_comment

begin_define
define|#
directive|define
name|cdfs_args_t
value|struct iso_args
end_define

begin_comment
comment|/* Define a type for the mfs_args structure */
end_comment

begin_define
define|#
directive|define
name|mfs_args_t
value|struct mfs_args
end_define

begin_comment
comment|/* Define a type for the rfs_args structure */
end_comment

begin_comment
comment|/* #undef rfs_args_t */
end_comment

begin_comment
comment|/* define if have a bad version of memcmp() */
end_comment

begin_comment
comment|/* #undef HAVE_BAD_MEMCMP */
end_comment

begin_comment
comment|/* define if have a bad version of yp_all() */
end_comment

begin_comment
comment|/* #undef HAVE_BAD_YP_ALL */
end_comment

begin_comment
comment|/* define if must use NFS "noconn" option */
end_comment

begin_comment
comment|/* #undef USE_UNCONNECTED_NFS_SOCKETS */
end_comment

begin_comment
comment|/* define if must NOT use NFS "noconn" option */
end_comment

begin_define
define|#
directive|define
name|USE_CONNECTED_NFS_SOCKETS
value|1
end_define

begin_comment
comment|/* Define if you have the __seterr_reply function.  */
end_comment

begin_comment
comment|/* #undef HAVE___SETERR_REPLY */
end_comment

begin_comment
comment|/* Define if you have the _seterr_reply function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE__SETERR_REPLY
value|1
end_define

begin_comment
comment|/* Define if you have the bcmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BCMP
value|1
end_define

begin_comment
comment|/* Define if you have the bcopy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BCOPY
value|1
end_define

begin_comment
comment|/* Define if you have the bzero function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_comment
comment|/* Define if you have the clnt_create function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLNT_CREATE
value|1
end_define

begin_comment
comment|/* Define if you have the clnt_create_timed function.  */
end_comment

begin_comment
comment|/* #undef HAVE_CLNT_CREATE_TIMED */
end_comment

begin_comment
comment|/* Define if you have the clnt_spcreateerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLNT_SPCREATEERROR
value|1
end_define

begin_comment
comment|/* Define if you have the clnt_sperrno function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLNT_SPERRNO
value|1
end_define

begin_comment
comment|/* Define if you have the cnodeid function.  */
end_comment

begin_comment
comment|/* #undef HAVE_CNODEID */
end_comment

begin_comment
comment|/* Define if you have the dbm_open function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DBM_OPEN
value|1
end_define

begin_comment
comment|/* Define if you have the dg_mount function.  */
end_comment

begin_comment
comment|/* #undef HAVE_DG_MOUNT */
end_comment

begin_comment
comment|/* Define if you have the fgets function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FGETS
value|1
end_define

begin_comment
comment|/* Define if you have the flock function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_comment
comment|/* Define if you have the fsmount function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FSMOUNT */
end_comment

begin_comment
comment|/* Define if you have the get_myaddress function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GET_MYADDRESS
value|1
end_define

begin_comment
comment|/* Define if you have the getccent function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETCCENT */
end_comment

begin_comment
comment|/* Define if you have the getcwd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the getdomainname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDOMAINNAME
value|1
end_define

begin_comment
comment|/* Define if you have the getdtablesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the gethostname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* Define if you have the getifaddrs function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETIFADDRS */
end_comment

begin_comment
comment|/* Define if you have the getmntinfo function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETMNTINFO
value|1
end_define

begin_comment
comment|/* Define if you have the getmountent function.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETMOUNTENT */
end_comment

begin_comment
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getpwnam function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPWNAM
value|1
end_define

begin_comment
comment|/* Define if you have the gettimeofday function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the hasmntopt function.  */
end_comment

begin_comment
comment|/* #undef HAVE_HASMNTOPT */
end_comment

begin_comment
comment|/* Define if you have the hes_init function.  */
end_comment

begin_comment
comment|/* #undef HAVE_HES_INIT */
end_comment

begin_comment
comment|/* Define if you have the hesiod_init function.  */
end_comment

begin_comment
comment|/* #undef HAVE_HESIOD_INIT */
end_comment

begin_comment
comment|/* Define if you have the hesiod_reload function.  */
end_comment

begin_comment
comment|/* #undef HAVE_HESIOD_RELOAD */
end_comment

begin_comment
comment|/* Define if you have the hesiod_to_bind function.  */
end_comment

begin_comment
comment|/* #undef HAVE_HESIOD_TO_BIND */
end_comment

begin_comment
comment|/* Define if you have the ldap_open function.  */
end_comment

begin_comment
comment|/* #undef HAVE_LDAP_OPEN */
end_comment

begin_comment
comment|/* Define if you have the memcmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCMP
value|1
end_define

begin_comment
comment|/* Define if you have the memcpy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCPY
value|1
end_define

begin_comment
comment|/* Define if you have the memmove function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the memset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define if you have the mkdir function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKDIR
value|1
end_define

begin_comment
comment|/* Define if you have the mkstemp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the mntctl function.  */
end_comment

begin_comment
comment|/* #undef HAVE_MNTCTL */
end_comment

begin_comment
comment|/* Define if you have the mount function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MOUNT
value|1
end_define

begin_comment
comment|/* Define if you have the mountsyscall function.  */
end_comment

begin_comment
comment|/* #undef HAVE_MOUNTSYSCALL */
end_comment

begin_comment
comment|/* Define if you have the nis_domain_of function.  */
end_comment

begin_comment
comment|/* #undef HAVE_NIS_DOMAIN_OF */
end_comment

begin_comment
comment|/* Define if you have the opendir function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENDIR
value|1
end_define

begin_comment
comment|/* Define if you have the plock function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PLOCK */
end_comment

begin_comment
comment|/* Define if you have the regcomp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGCOMP
value|1
end_define

begin_comment
comment|/* Define if you have the regexec function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGEXEC
value|1
end_define

begin_comment
comment|/* Define if you have the rmdir function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RMDIR
value|1
end_define

begin_comment
comment|/* Define if you have the select function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* Define if you have the seteuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the setitimer function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETITIMER
value|1
end_define

begin_comment
comment|/* Define if you have the setresuid function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SETRESUID */
end_comment

begin_comment
comment|/* Define if you have the setsid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define if you have the sigaction function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have the signal function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL
value|1
end_define

begin_comment
comment|/* Define if you have the socket function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKET
value|1
end_define

begin_comment
comment|/* Define if you have the strcasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the strcspn function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCSPN
value|1
end_define

begin_comment
comment|/* Define if you have the strdup function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the strerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the strspn function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSPN
value|1
end_define

begin_comment
comment|/* Define if you have the strstr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* Define if you have the svc_getreq function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SVC_GETREQ
value|1
end_define

begin_comment
comment|/* Define if you have the svc_getreqset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SVC_GETREQSET
value|1
end_define

begin_comment
comment|/* Define if you have the sysfs function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYSFS */
end_comment

begin_comment
comment|/* Define if you have the syslog function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG
value|1
end_define

begin_comment
comment|/* Define if you have the ualarm function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UALARM
value|1
end_define

begin_comment
comment|/* Define if you have the umount function.  */
end_comment

begin_comment
comment|/* #undef HAVE_UMOUNT */
end_comment

begin_comment
comment|/* Define if you have the uname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNAME
value|1
end_define

begin_comment
comment|/* Define if you have the unmount function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNMOUNT
value|1
end_define

begin_comment
comment|/* Define if you have the uvmount function.  */
end_comment

begin_comment
comment|/* #undef HAVE_UVMOUNT */
end_comment

begin_comment
comment|/* Define if you have the vfork function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define if you have the vfsmount function.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFSMOUNT */
end_comment

begin_comment
comment|/* Define if you have the vmount function.  */
end_comment

begin_comment
comment|/* #undef HAVE_VMOUNT */
end_comment

begin_comment
comment|/* Define if you have the vsnprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the wait3 function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT3
value|1
end_define

begin_comment
comment|/* Define if you have the waitpid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAITPID
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_attrstat function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_ATTRSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_createargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_CREATEARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_dirlist function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_DIRLIST
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_diropargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_DIROPARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_diropokres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_DIROPOKRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_diropres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_DIROPRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_dirpath function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_DIRPATH
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_entry function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_ENTRY
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_exportnode function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_EXPORTNODE
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_exports function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_EXPORTS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_fattr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_FATTR
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_fhandle function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_FHANDLE
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_fhstatus function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_FHSTATUS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_filename function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_FILENAME
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_ftype function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_FTYPE
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_groupnode function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_GROUPNODE
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_groups function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_GROUPS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_linkargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_LINKARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_mntrequest function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XDR_MNTREQUEST */
end_comment

begin_comment
comment|/* Define if you have the xdr_mntres function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XDR_MNTRES */
end_comment

begin_comment
comment|/* Define if you have the xdr_mountbody function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_MOUNTBODY
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_mountlist function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_MOUNTLIST
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_mountres3 function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XDR_MOUNTRES3 */
end_comment

begin_comment
comment|/* Define if you have the xdr_name function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_NAME
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_nfs_fh function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_NFS_FH
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_nfscookie function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_NFSCOOKIE
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_nfspath function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_NFSPATH
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_nfsstat function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_NFSSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_nfstime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_NFSTIME
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_pointer function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_POINTER
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_readargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_READARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_readdirargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_READDIRARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_readdirres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_READDIRRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_readlinkres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_READLINKRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_readokres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_READOKRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_readres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_READRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_renameargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_RENAMEARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_sattr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_SATTR
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_sattrargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_SATTRARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_statfsokres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_STATFSOKRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_statfsres function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_STATFSRES
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_symlinkargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_SYMLINKARGS
value|1
end_define

begin_comment
comment|/* Define if you have the xdr_umntrequest function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XDR_UMNTREQUEST */
end_comment

begin_comment
comment|/* Define if you have the xdr_umntres function.  */
end_comment

begin_comment
comment|/* #undef HAVE_XDR_UMNTRES */
end_comment

begin_comment
comment|/* Define if you have the xdr_writeargs function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_XDR_WRITEARGS
value|1
end_define

begin_comment
comment|/* Define if you have the yp_all function.  */
end_comment

begin_comment
comment|/* #undef HAVE_YP_ALL */
end_comment

begin_comment
comment|/* Define if you have the yp_get_default_domain function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_YP_GET_DEFAULT_DOMAIN
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/inet.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_INET_H
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/nameser.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_comment
comment|/* Define if you have the<assert.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASSERT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<bsd/rpc/rpc.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_BSD_RPC_RPC_H */
end_comment

begin_comment
comment|/* Define if you have the<cdfs/cdfs_mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_CDFS_CDFS_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<cdfs/cdfsmount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_CDFS_CDFSMOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<cluster.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_CLUSTER_H */
end_comment

begin_comment
comment|/* Define if you have the<ctype.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTYPE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<db1/ndbm.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_DB1_NDBM_H */
end_comment

begin_comment
comment|/* Define if you have the<dirent.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<errno.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<grp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GRP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<hesiod.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_HESIOD_H */
end_comment

begin_comment
comment|/* Define if you have the<hsfs/hsfs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_HSFS_HSFS_H */
end_comment

begin_comment
comment|/* Define if you have the<ifaddrs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_IFADDRS_H */
end_comment

begin_comment
comment|/* Define if you have the<irs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_IRS_H */
end_comment

begin_comment
comment|/* Define if you have the<isofs/cd9660/cd9660_mount.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISOFS_CD9660_CD9660_MOUNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<lber.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LBER_H */
end_comment

begin_comment
comment|/* Define if you have the<ldap.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LDAP_H */
end_comment

begin_comment
comment|/* Define if you have the<libgen.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBGEN_H */
end_comment

begin_comment
comment|/* Define if you have the<linux/auto_fs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_AUTO_FS_H */
end_comment

begin_comment
comment|/* Define if you have the<linux/fs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_FS_H */
end_comment

begin_comment
comment|/* Define if you have the<linux/nfs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_NFS_H */
end_comment

begin_comment
comment|/* Define if you have the<linux/nfs_mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_NFS_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<linux/posix_types.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_POSIX_TYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<machine/endian.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MACHINE_ENDIAN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<mntent.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MNTENT_H */
end_comment

begin_comment
comment|/* Define if you have the<mnttab.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MNTTAB_H */
end_comment

begin_comment
comment|/* Define if you have the<mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<msdosfs/msdosfsmount.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MSDOSFS_MSDOSFSMOUNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<ndbm.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NDBM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<net/errno.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NET_ERRNO_H */
end_comment

begin_comment
comment|/* Define if you have the<net/if.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<net/if_var.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_VAR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<net/route.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_ROUTE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netconfig.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NETCONFIG_H */
end_comment

begin_comment
comment|/* Define if you have the<netdb.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netdir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NETDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<netinet/if_ether.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IF_ETHER_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/in.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nfs/export.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NFS_EXPORT_H */
end_comment

begin_comment
comment|/* Define if you have the<nfs/mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NFS_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<nfs/nfs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NFS_NFS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nfs/nfs_clnt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NFS_NFS_CLNT_H */
end_comment

begin_comment
comment|/* Define if you have the<nfs/nfs_gfs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NFS_NFS_GFS_H */
end_comment

begin_comment
comment|/* Define if you have the<nfs/nfs_mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NFS_NFS_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<nfs/nfsmount.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NFS_NFSMOUNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nfs/nfsproto.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NFS_NFSPROTO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nfs/nfsv2.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NFS_NFSV2_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nfs/pathconf.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NFS_PATHCONF_H */
end_comment

begin_comment
comment|/* Define if you have the<nfs/rpcv2.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NFS_RPCV2_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nsswitch.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NSSWITCH_H */
end_comment

begin_comment
comment|/* Define if you have the<pwd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<regex.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGEX_H
value|1
end_define

begin_comment
comment|/* Define if you have the<resolv.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpc/auth_des.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPC_AUTH_DES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpc/pmap_clnt.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPC_PMAP_CLNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpc/pmap_prot.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPC_PMAP_PROT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpc/rpc.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPC_RPC_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpc/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPC_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpc/xdr.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPC_XDR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpcsvc/mount.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_MOUNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpcsvc/mountv3.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_RPCSVC_MOUNTV3_H */
end_comment

begin_comment
comment|/* Define if you have the<rpcsvc/nfs_prot.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_NFS_PROT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpcsvc/nis.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_NIS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpcsvc/yp_prot.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_YP_PROT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rpcsvc/ypclnt.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_YPCLNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<setjmp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETJMP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<signal.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<socketbits.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SOCKETBITS_H */
end_comment

begin_comment
comment|/* Define if you have the<statbuf.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_STATBUF_H */
end_comment

begin_comment
comment|/* Define if you have the<stdarg.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/config.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CONFIG_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/dg_mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DG_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/errno.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/fs/autofs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_AUTOFS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/autofs_prot.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_AUTOFS_PROT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/cachefs_fs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_CACHEFS_FS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/efs_clnt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_EFS_CLNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/nfs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_NFS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/nfs/mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_NFS_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/nfs/nfs_clnt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_NFS_NFS_CLNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/nfs_clnt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_NFS_CLNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/pc_fs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_PC_FS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/tmp.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_TMP_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/ufs_mount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_UFS_MOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs/xfs_clnt.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_XFS_CLNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fs_types.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FS_TYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fsid.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FSID_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fstyp.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FSTYP_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ioctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/lock.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_LOCK_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/machine.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MACHINE_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/mbuf.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MBUF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/mntctl.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MNTCTL_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/mntent.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MNTENT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/mnttab.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MNTTAB_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/mount.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MOUNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/netconfig.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NETCONFIG_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/pathconf.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PATHCONF_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/proc.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROC_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/resource.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sema.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SEMA_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/signal.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/socket.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sockio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/statfs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STATFS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/syscall.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCALL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/syslimits.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSLIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/syslog.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSLOG_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/tiuser.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TIUSER_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ucred.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UCRED_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/uio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/utsname.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTSNAME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/vfs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_VFS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/vmount.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_VMOUNT_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/vnode.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_VNODE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<syslog.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG_H
value|1
end_define

begin_comment
comment|/* Define if you have the<time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<tiuser.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TIUSER_H */
end_comment

begin_comment
comment|/* Define if you have the<tmpfs/tmp.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TMPFS_TMP_H */
end_comment

begin_comment
comment|/* Define if you have the<ufs/ufs/ufsmount.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UFS_UFS_UFSMOUNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<ufs/ufs_mount.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UFS_UFS_MOUNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<varargs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VARARGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<vfork.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define if you have the gdbm library (-lgdbm).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBGDBM */
end_comment

begin_comment
comment|/* Define if you have the malloc library (-lmalloc).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBMALLOC */
end_comment

begin_comment
comment|/* Define if you have the mapmalloc library (-lmapmalloc).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBMAPMALLOC */
end_comment

begin_comment
comment|/* Define if you have the nsl library (-lnsl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* Define if you have the rpc library (-lrpc).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBRPC */
end_comment

begin_comment
comment|/* Define if you have the rpcsvc library (-lrpcsvc).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBRPCSVC
value|1
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef time_t */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** Everything below this line is part of the "BOTTOM" of acconfig.h.	***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Existence of external definitions.  */
end_comment

begin_comment
comment|/* does extern definition for sys_errlist[] exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_SYS_ERRLIST
value|1
end_define

begin_comment
comment|/* does extern definition for optarg exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_OPTARG
value|1
end_define

begin_comment
comment|/* does extern definition for clnt_spcreateerror() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_CLNT_SPCREATEERROR
value|1
end_define

begin_comment
comment|/* does extern definition for clnt_sperrno() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_CLNT_SPERRNO
value|1
end_define

begin_comment
comment|/* does extern definition for free() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_FREE
value|1
end_define

begin_comment
comment|/* does extern definition for get_myaddress() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_GET_MYADDRESS
value|1
end_define

begin_comment
comment|/* does extern definition for getccent() (hpux) exist? */
end_comment

begin_comment
comment|/* #undef HAVE_EXTERN_GETCCENT */
end_comment

begin_comment
comment|/* does extern definition for getdomainname() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_GETDOMAINNAME
value|1
end_define

begin_comment
comment|/* does extern definition for gethostname() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* does extern definition for getlogin() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_GETLOGIN
value|1
end_define

begin_comment
comment|/* does extern definition for gettablesize() exist? */
end_comment

begin_comment
comment|/* #undef HAVE_EXTERN_GETTABLESIZE */
end_comment

begin_comment
comment|/* does extern definition for getpagesize() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* does extern definition for innetgr() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_INNETGR
end_define

begin_comment
comment|/* does extern definition for mkstemp() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_MKSTEMP
value|1
end_define

begin_comment
comment|/* does extern definition for sbrk() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_SBRK
value|1
end_define

begin_comment
comment|/* does extern definition for seteuid() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_SETEUID
value|1
end_define

begin_comment
comment|/* does extern definition for setitimer() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_SETITIMER
value|1
end_define

begin_comment
comment|/* does extern definition for strcasecmp() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_STRCASECMP
value|1
end_define

begin_comment
comment|/* does extern definition for strdup() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_STRDUP
value|1
end_define

begin_comment
comment|/* does extern definition for strstr() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_STRSTR
value|1
end_define

begin_comment
comment|/* does extern definition for usleep() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_USLEEP
value|1
end_define

begin_comment
comment|/* does extern definition for wait3() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_WAIT3
value|1
end_define

begin_comment
comment|/* does extern definition for vsnprintf() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_VSNPRINTF
value|1
end_define

begin_comment
comment|/* does extern definition for xdr_opaque_auth() exist? */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXTERN_XDR_OPAQUE_AUTH
value|1
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*** INCLUDE localconfig.h if it exists, to allow users to make some      ***/
end_comment

begin_comment
comment|/*** compile time configuration changes.                                  ***/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* does a local configuration file exist? */
end_comment

begin_comment
comment|/* #undef HAVE_LOCALCONFIG_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALCONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<localconfig.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LOCALCONFIG_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _CONFIG_H */
end_comment

begin_comment
comment|/*  * Local Variables:  * mode: c  * End:  */
end_comment

begin_comment
comment|/* End of am-utils-6.x config.h file */
end_comment

end_unit

