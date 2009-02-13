begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/amd/amd.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMD_H
end_ifndef

begin_define
define|#
directive|define
name|_AMD_H
end_define

begin_comment
comment|/*  * MACROS:  */
end_comment

begin_comment
comment|/*  * Define a default debug mtab path for systems  * that support mtab on file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOUNT_TABLE_ON_FILE
end_ifdef

begin_define
define|#
directive|define
name|DEBUG_MNTTAB_FILE
value|"/tmp/mnttab"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOUNT_TABLE_ON_FILE */
end_comment

begin_comment
comment|/* options for amd.conf */
end_comment

begin_define
define|#
directive|define
name|CFM_BROWSABLE_DIRS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CFM_MOUNT_TYPE_AUTOFS
value|0x00000002
end_define

begin_comment
comment|/* use kernel autofs support */
end_comment

begin_define
define|#
directive|define
name|CFM_SELECTORS_IN_DEFAULTS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CFM_NORMALIZE_HOSTNAMES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CFM_PROCESS_LOCK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CFM_PRINT_PID
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CFM_RESTART_EXISTING_MOUNTS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CFM_SHOW_STATFS_ENTRIES
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CFM_FULLY_QUALIFIED_HOSTS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CFM_BROWSABLE_DIRS_FULL
value|0x00000200
end_define

begin_comment
comment|/* allow '/' in readdir() */
end_comment

begin_define
define|#
directive|define
name|CFM_UNMOUNT_ON_EXIT
value|0x00000400
end_define

begin_comment
comment|/* when amd finishing */
end_comment

begin_define
define|#
directive|define
name|CFM_USE_TCPWRAPPERS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CFM_AUTOFS_USE_LOFS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CFM_NFS_INSECURE_PORT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CFM_DOMAIN_STRIP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CFM_NORMALIZE_SLASHES
value|0x00008000
end_define

begin_comment
comment|/* normalize slashes? */
end_comment

begin_define
define|#
directive|define
name|CFM_FORCED_UNMOUNTS
value|0x00010000
end_define

begin_comment
comment|/* forced unmounts? */
end_comment

begin_define
define|#
directive|define
name|CFM_TRUNCATE_LOG
value|0x00020000
end_define

begin_comment
comment|/* truncate log file? */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: reserved to sync up with am-utils-6.2 */
end_comment

begin_define
define|#
directive|define
name|CFM_SUN_MAP_SYNTAX
value|0x00040000
end_define

begin_comment
comment|/* Sun map syntax? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CFM_NFS_ANY_INTERFACE
value|0x00080000
end_define

begin_comment
comment|/* all interfaces are acceptable */
end_comment

begin_comment
comment|/* defaults global flags: plock, tcpwrappers, and autofs/lofs */
end_comment

begin_define
define|#
directive|define
name|CFM_DEFAULT_FLAGS
value|(CFM_PROCESS_LOCK|CFM_USE_TCPWRAPPERS|CFM_AUTOFS_USE_LOFS|CFM_DOMAIN_STRIP|CFM_NORMALIZE_SLASHES)
end_define

begin_comment
comment|/*  * macro definitions for automounter vfs/vnode operations.  */
end_comment

begin_define
define|#
directive|define
name|VLOOK_CREATE
value|0x1
end_define

begin_define
define|#
directive|define
name|VLOOK_DELETE
value|0x2
end_define

begin_define
define|#
directive|define
name|VLOOK_LOOKUP
value|0x3
end_define

begin_comment
comment|/*  * macro definitions for automounter vfs capabilities  */
end_comment

begin_define
define|#
directive|define
name|FS_DIRECTORY
value|0x0001
end_define

begin_comment
comment|/* This looks like a dir, not a link */
end_comment

begin_define
define|#
directive|define
name|FS_MBACKGROUND
value|0x0002
end_define

begin_comment
comment|/* Should background this mount */
end_comment

begin_define
define|#
directive|define
name|FS_NOTIMEOUT
value|0x0004
end_define

begin_comment
comment|/* Don't bother with timeouts */
end_comment

begin_define
define|#
directive|define
name|FS_MKMNT
value|0x0008
end_define

begin_comment
comment|/* Need to make the mount point */
end_comment

begin_define
define|#
directive|define
name|FS_UBACKGROUND
value|0x0010
end_define

begin_comment
comment|/* Unmount in background */
end_comment

begin_define
define|#
directive|define
name|FS_BACKGROUND
value|(FS_MBACKGROUND|FS_UBACKGROUND)
end_define

begin_define
define|#
directive|define
name|FS_DISCARD
value|0x0020
end_define

begin_comment
comment|/* Discard immediately on last reference */
end_comment

begin_define
define|#
directive|define
name|FS_AMQINFO
value|0x0040
end_define

begin_comment
comment|/* Amq is interested in this fs type */
end_comment

begin_define
define|#
directive|define
name|FS_AUTOFS
value|0x0080
end_define

begin_comment
comment|/* This filesystem can be an autofs f/s */
end_comment

begin_define
define|#
directive|define
name|FS_DIRECT
value|0x0100
end_define

begin_comment
comment|/* Direct mount */
end_comment

begin_define
define|#
directive|define
name|FS_ON_AUTOFS
value|0x0200
end_define

begin_comment
comment|/* This filesystem can be mounted directly 				   onto an autofs mountpoint */
end_comment

begin_comment
comment|/*  * macros for struct am_node (map of auto-mount points).  */
end_comment

begin_define
define|#
directive|define
name|AMF_NOTIMEOUT
value|0x0001
end_define

begin_comment
comment|/* This node never times out */
end_comment

begin_define
define|#
directive|define
name|AMF_ROOT
value|0x0002
end_define

begin_comment
comment|/* This is a root node */
end_comment

begin_define
define|#
directive|define
name|AMF_AUTOFS
value|0x0004
end_define

begin_comment
comment|/* This node is part of an autofs filesystem */
end_comment

begin_define
define|#
directive|define
name|AMF_REMOUNT
value|0x0008
end_define

begin_comment
comment|/* This node needs to be remounted */
end_comment

begin_define
define|#
directive|define
name|AMF_SOFTLOOKUP
value|0x0010
end_define

begin_comment
comment|/* This node returns EIO if server is down */
end_comment

begin_comment
comment|/*  * macros for struct mntfs (list of mounted filesystems)  */
end_comment

begin_define
define|#
directive|define
name|MFF_MOUNTED
value|0x0001
end_define

begin_comment
comment|/* Node is mounted */
end_comment

begin_define
define|#
directive|define
name|MFF_MOUNTING
value|0x0002
end_define

begin_comment
comment|/* Mount is in progress */
end_comment

begin_define
define|#
directive|define
name|MFF_UNMOUNTING
value|0x0004
end_define

begin_comment
comment|/* Unmount is in progress */
end_comment

begin_define
define|#
directive|define
name|MFF_RESTART
value|0x0008
end_define

begin_comment
comment|/* Restarted node */
end_comment

begin_define
define|#
directive|define
name|MFF_MKMNT
value|0x0010
end_define

begin_comment
comment|/* Delete this node's am_mount */
end_comment

begin_define
define|#
directive|define
name|MFF_ERROR
value|0x0020
end_define

begin_comment
comment|/* This node failed to mount */
end_comment

begin_define
define|#
directive|define
name|MFF_LOGDOWN
value|0x0040
end_define

begin_comment
comment|/* Logged that this mount is down */
end_comment

begin_define
define|#
directive|define
name|MFF_RSTKEEP
value|0x0080
end_define

begin_comment
comment|/* Don't timeout this filesystem - restarted */
end_comment

begin_define
define|#
directive|define
name|MFF_WANTTIMO
value|0x0100
end_define

begin_comment
comment|/* Need a timeout call when not busy */
end_comment

begin_define
define|#
directive|define
name|MFF_NFSLINK
value|0x0200
end_define

begin_comment
comment|/* nfsl type, and deemed a link */
end_comment

begin_define
define|#
directive|define
name|MFF_IS_AUTOFS
value|0x0400
end_define

begin_comment
comment|/* this filesystem is of type autofs */
end_comment

begin_define
define|#
directive|define
name|MFF_NFS_SCALEDOWN
value|0x0800
end_define

begin_comment
comment|/* the mount failed, retry with v2/UDP */
end_comment

begin_define
define|#
directive|define
name|MFF_ON_AUTOFS
value|0x1000
end_define

begin_comment
comment|/* autofs has a lofs/link to this f/s */
end_comment

begin_define
define|#
directive|define
name|MFF_WEBNFS
value|0x2000
end_define

begin_comment
comment|/* use public filehandle */
end_comment

begin_comment
comment|/*  * macros for struct fserver.  */
end_comment

begin_define
define|#
directive|define
name|FSF_VALID
value|0x0001
end_define

begin_comment
comment|/* Valid information available */
end_comment

begin_define
define|#
directive|define
name|FSF_DOWN
value|0x0002
end_define

begin_comment
comment|/* This fileserver is thought to be down */
end_comment

begin_define
define|#
directive|define
name|FSF_ERROR
value|0x0004
end_define

begin_comment
comment|/* Permanent error has occurred */
end_comment

begin_define
define|#
directive|define
name|FSF_WANT
value|0x0008
end_define

begin_comment
comment|/* Want a wakeup call */
end_comment

begin_define
define|#
directive|define
name|FSF_PINGING
value|0x0010
end_define

begin_comment
comment|/* Already doing pings */
end_comment

begin_define
define|#
directive|define
name|FSF_WEBNFS
value|0x0020
end_define

begin_comment
comment|/* Don't try to contact portmapper */
end_comment

begin_define
define|#
directive|define
name|FSF_PING_UNINIT
value|0x0040
end_define

begin_comment
comment|/* ping values have not been initilized */
end_comment

begin_define
define|#
directive|define
name|FSF_FORCE_UNMOUNT
value|0x0080
end_define

begin_comment
comment|/* force umount of this fserver */
end_comment

begin_define
define|#
directive|define
name|FSRV_ERROR
parameter_list|(
name|fs
parameter_list|)
value|((fs)&& (((fs)->fs_flags& FSF_ERROR) == FSF_ERROR))
end_define

begin_define
define|#
directive|define
name|FSRV_ISDOWN
parameter_list|(
name|fs
parameter_list|)
value|((fs)&& (((fs)->fs_flags& (FSF_DOWN|FSF_VALID)) == (FSF_DOWN|FSF_VALID)))
end_define

begin_define
define|#
directive|define
name|FSRV_ISUP
parameter_list|(
name|fs
parameter_list|)
value|(!(fs) || (((fs)->fs_flags& (FSF_DOWN|FSF_VALID)) == (FSF_VALID)))
end_define

begin_comment
comment|/* some systems (SunOS 4.x) neglect to define the mount null message */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MOUNTPROC_NULL
end_ifndef

begin_define
define|#
directive|define
name|MOUNTPROC_NULL
value|((u_long)(0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MOUNTPROC_NULL */
end_comment

begin_comment
comment|/*  * Error to return if remote host is not available.  * Try, in order, "host down", "host unreachable", "invalid argument".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EHOSTDOWN
end_ifdef

begin_define
define|#
directive|define
name|AM_ERRNO_HOST_DOWN
value|EHOSTDOWN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not EHOSTDOWN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EHOSTUNREACH
end_ifdef

begin_define
define|#
directive|define
name|AM_ERRNO_HOST_DOWN
value|EHOSTUNREACH
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not EHOSTUNREACH */
end_comment

begin_define
define|#
directive|define
name|AM_ERRNO_HOST_DOWN
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not EHOSTUNREACH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not EHOSTDOWN */
end_comment

begin_comment
comment|/* Hash table size */
end_comment

begin_define
define|#
directive|define
name|NKVHASH
value|(1<< 2)
end_define

begin_comment
comment|/* Power of two */
end_comment

begin_comment
comment|/* Max entries to return in one call */
end_comment

begin_define
define|#
directive|define
name|MAX_READDIR_ENTRIES
value|16
end_define

begin_comment
comment|/*  * default amfs_auto retrans - 1/10th seconds  */
end_comment

begin_define
define|#
directive|define
name|AMFS_AUTO_RETRANS
parameter_list|(
name|x
parameter_list|)
value|((ALLOWED_MOUNT_TIME*10+5*gopt.amfs_auto_timeo[(x)])/gopt.amfs_auto_timeo[(x)] * 2)
end_define

begin_comment
comment|/*  * The following values can be tuned...  */
end_comment

begin_define
define|#
directive|define
name|AM_TTL
value|(300)
end_define

begin_comment
comment|/* Default cache period (5 min) */
end_comment

begin_define
define|#
directive|define
name|AM_TTL_W
value|(120)
end_define

begin_comment
comment|/* Default unmount interval (2 min) */
end_comment

begin_define
define|#
directive|define
name|AM_PINGER
value|30
end_define

begin_comment
comment|/* NFS ping interval for live systems */
end_comment

begin_define
define|#
directive|define
name|AMFS_AUTO_TIMEO
value|8
end_define

begin_comment
comment|/* Default amfs_auto timeout - .8s */
end_comment

begin_define
define|#
directive|define
name|AMFS_EXEC_MAP_TIMEOUT
value|10
end_define

begin_comment
comment|/* default 10sec exec map timeout */
end_comment

begin_comment
comment|/* interval between forced retries of a mount */
end_comment

begin_define
define|#
directive|define
name|RETRY_INTERVAL
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ROOT_MAP
end_ifndef

begin_define
define|#
directive|define
name|ROOT_MAP
value|"\"root\""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not ROOT_MAP */
end_comment

begin_define
define|#
directive|define
name|ereturn
parameter_list|(
name|x
parameter_list|)
value|do { *error_return = x; return 0; } while (0)
end_define

begin_define
define|#
directive|define
name|NEVER
value|(time_t) 0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TCPD_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LIBWRAP
argument_list|)
end_if

begin_define
define|#
directive|define
name|AMD_SERVICE_NAME
value|"amd"
end_define

begin_comment
comment|/* for tcpwrappers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_TCPD_H)&& defined(HAVE_LIBWRAP) */
end_comment

begin_comment
comment|/*  * TYPEDEFS:  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cf_map
name|cf_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|kv
name|kv
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|am_node
name|am_node
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mntfs
name|mntfs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|am_opts
name|am_opts
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|am_ops
name|am_ops
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|am_stats
name|am_stats
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fserver
name|fserver
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|voidp
name|wchan_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|voidp
name|opaque_t
typedef|;
end_typedef

begin_comment
comment|/*  * Cache map operations  */
end_comment

begin_typedef
typedef|typedef
name|void
name|add_fn
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|init_fn
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mtime_fn
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|isup_fn
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|reload_fn
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|add_fn
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|search_fn
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|task_fun
parameter_list|(
name|opaque_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cb_fun
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|opaque_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|fwd_fun
parameter_list|(
name|voidp
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|opaque_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|key_fun
parameter_list|(
name|char
modifier|*
parameter_list|,
name|opaque_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|callout_fun
parameter_list|(
name|opaque_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * automounter vfs/vnode operations.  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|vfs_match
function_decl|)
parameter_list|(
name|am_opts
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|vfs_init
function_decl|)
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|vmount_fs
function_decl|)
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|vumount_fs
function_decl|)
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|am_node
modifier|*
function_decl|(
modifier|*
name|vlookup_child
function_decl|)
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|am_node
modifier|*
function_decl|(
modifier|*
name|vmount_child
function_decl|)
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|vreaddir
function_decl|)
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|nfscookie
parameter_list|,
name|nfsdirlist
modifier|*
parameter_list|,
name|nfsentry
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|am_node
modifier|*
function_decl|(
modifier|*
name|vreadlink
function_decl|)
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vmounted
function_decl|)
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vumounted
function_decl|)
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|fserver
modifier|*
function_decl|(
modifier|*
name|vffserver
function_decl|)
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|wchan_t
function_decl|(
modifier|*
name|vget_wchan
function_decl|)
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

begin_comment
comment|/* global amd options that are manipulated by conf.c */
end_comment

begin_struct
struct|struct
name|amu_global_options
block|{
name|char
modifier|*
name|arch
decl_stmt|;
comment|/* name of current architecture */
name|char
modifier|*
name|auto_dir
decl_stmt|;
comment|/* automounter temp dir */
name|int
name|auto_attrcache
decl_stmt|;
comment|/* attribute cache timeout for auto dirs */
name|char
modifier|*
name|cluster
decl_stmt|;
comment|/* cluster name */
name|char
modifier|*
name|karch
decl_stmt|;
comment|/* kernel architecture */
name|char
modifier|*
name|logfile
decl_stmt|;
comment|/* amd log file */
name|char
modifier|*
name|op_sys
decl_stmt|;
comment|/* operating system name ${os} */
name|char
modifier|*
name|op_sys_ver
decl_stmt|;
comment|/* OS version ${osver} */
name|char
modifier|*
name|op_sys_full
decl_stmt|;
comment|/* full OS name ${full_os} */
name|char
modifier|*
name|op_sys_vendor
decl_stmt|;
comment|/* name of OS vendor ${vendor} */
name|char
modifier|*
name|pid_file
decl_stmt|;
comment|/* PID file */
name|char
modifier|*
name|sub_domain
decl_stmt|;
comment|/* local domain */
name|char
modifier|*
name|localhost_address
decl_stmt|;
comment|/* localhost address (NULL means use 127.0.0.1) */
name|char
modifier|*
name|map_defaults
decl_stmt|;
comment|/* global map /default options */
name|char
modifier|*
name|map_options
decl_stmt|;
comment|/* global map options */
name|int
name|map_reload_interval
decl_stmt|;
comment|/* map reload interval */
name|char
modifier|*
name|map_type
decl_stmt|;
comment|/* global map type */
name|char
modifier|*
name|search_path
decl_stmt|;
comment|/* search path for maps */
name|char
modifier|*
name|mount_type
decl_stmt|;
comment|/* mount type for map */
name|char
modifier|*
name|debug_mtab_file
decl_stmt|;
comment|/* path for the mtab file during debug mode */
name|u_int
name|flags
decl_stmt|;
comment|/* various CFM_* flags */
define|#
directive|define
name|AMU_TYPE_NONE
value|-1
comment|/* for amfs_auto_{timeo,retrans,toplvl} */
define|#
directive|define
name|AMU_TYPE_UDP
value|0
comment|/* for amfs_auto_{timeo,retrans,toplvl} */
define|#
directive|define
name|AMU_TYPE_TCP
value|1
comment|/* for amfs_auto_{timeo,retrans,toplvl} */
comment|/*    * Note: toplvl is only UDP, but we want to separate it from regular    * NFS mounts which Amd makes, because the toplvl mount is a localhost    * mount for which different timeo/retrans parameters may be desired.    */
define|#
directive|define
name|AMU_TYPE_TOPLVL
value|2
comment|/* for amfs_auto_{timeo,retrans,toplvl} */
define|#
directive|define
name|AMU_TYPE_MAX
value|3
comment|/* for amfs_auto_{timeo,retrans,toplvl} */
name|int
name|amfs_auto_retrans
index|[
name|AMU_TYPE_MAX
index|]
decl_stmt|;
comment|/* NFS retransmit counter */
name|int
name|amfs_auto_timeo
index|[
name|AMU_TYPE_MAX
index|]
decl_stmt|;
comment|/* NFS retry interval */
name|int
name|am_timeo
decl_stmt|;
comment|/* cache duration */
name|int
name|am_timeo_w
decl_stmt|;
comment|/* dismount interval */
name|u_long
name|portmap_program
decl_stmt|;
comment|/* amd RPC program number */
name|u_short
name|preferred_amq_port
decl_stmt|;
comment|/* preferred amq service RPC port number (0 means "any") */
ifdef|#
directive|ifdef
name|HAVE_MAP_HESIOD
name|char
modifier|*
name|hesiod_base
decl_stmt|;
comment|/* Hesiod rhs */
endif|#
directive|endif
comment|/* HAVE_MAP_HESIOD */
ifdef|#
directive|ifdef
name|HAVE_MAP_LDAP
name|char
modifier|*
name|ldap_base
decl_stmt|;
comment|/* LDAP base */
name|char
modifier|*
name|ldap_hostports
decl_stmt|;
comment|/* LDAP host ports */
name|long
name|ldap_cache_seconds
decl_stmt|;
comment|/* LDAP internal cache - keep seconds */
name|long
name|ldap_cache_maxmem
decl_stmt|;
comment|/* LDAP internal cache - max memory (bytes) */
name|long
name|ldap_proto_version
decl_stmt|;
comment|/* LDAP protocol version */
endif|#
directive|endif
comment|/* HAVE_MAP_LDAP */
ifdef|#
directive|ifdef
name|HAVE_MAP_NIS
name|char
modifier|*
name|nis_domain
decl_stmt|;
comment|/* YP domain name */
endif|#
directive|endif
comment|/* HAVE_MAP_NIS */
name|char
modifier|*
name|nfs_proto
decl_stmt|;
comment|/* NFS protocol (NULL, udp, tcp) */
name|int
name|nfs_vers
decl_stmt|;
comment|/* NFS version (0, 2, 3, 4) */
name|u_int
name|exec_map_timeout
decl_stmt|;
comment|/* timeout (seconds) for executable maps */
block|}
struct|;
end_struct

begin_comment
comment|/* if you add anything here, update conf.c:reset_cf_map() */
end_comment

begin_struct
struct|struct
name|cf_map
block|{
name|char
modifier|*
name|cfm_dir
decl_stmt|;
comment|/* /home, /u, /src */
name|char
modifier|*
name|cfm_name
decl_stmt|;
comment|/* amd.home, /etc/amd.home ... */
name|char
modifier|*
name|cfm_type
decl_stmt|;
comment|/* file, hesiod, ndbm, nis ... */
name|char
modifier|*
name|cfm_defaults
decl_stmt|;
comment|/* map /defaults options in amd.conf */
name|char
modifier|*
name|cfm_opts
decl_stmt|;
comment|/* -cache:=all, etc. */
name|char
modifier|*
name|cfm_search_path
decl_stmt|;
comment|/* /etc/local:/etc/amdmaps:/misc/yp */
name|char
modifier|*
name|cfm_tag
decl_stmt|;
comment|/* optional map tag for amd -T */
name|u_int
name|cfm_flags
decl_stmt|;
comment|/* browsable_dirs? mount_type? */
name|struct
name|cf_map
modifier|*
name|cfm_next
decl_stmt|;
comment|/* pointer to next in list (if any) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Key-value pair  */
end_comment

begin_struct
struct|struct
name|kv
block|{
name|kv
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_REGEXEC
name|regex_t
name|re
decl_stmt|;
comment|/* store the regexp from regcomp() */
endif|#
directive|endif
comment|/* HAVE_REGEXEC */
name|char
modifier|*
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mnt_map
block|{
name|qelem
name|hdr
decl_stmt|;
name|int
name|refc
decl_stmt|;
comment|/* Reference count */
name|short
name|flags
decl_stmt|;
comment|/* Allocation flags */
name|short
name|alloc
decl_stmt|;
comment|/* Allocation mode */
name|time_t
name|modify
decl_stmt|;
comment|/* Modify time of map */
name|u_int
name|reloads
decl_stmt|;
comment|/* Number of times map was reloaded */
name|char
modifier|*
name|map_name
decl_stmt|;
comment|/* Name of this map */
name|char
modifier|*
name|wildcard
decl_stmt|;
comment|/* Wildcard value */
name|reload_fn
modifier|*
name|reload
decl_stmt|;
comment|/* Function to be used for reloads */
name|isup_fn
modifier|*
name|isup
decl_stmt|;
comment|/* Is service up or not? (1=up, 0=down) */
name|search_fn
modifier|*
name|search
decl_stmt|;
comment|/* Function to be used for searching */
name|mtime_fn
modifier|*
name|mtime
decl_stmt|;
comment|/* Modify time function */
name|kv
modifier|*
name|kvhash
index|[
name|NKVHASH
index|]
decl_stmt|;
comment|/* Cached data */
name|cf_map_t
modifier|*
name|cfm
decl_stmt|;
comment|/* pointer to per-map amd.conf opts, if any */
name|void
modifier|*
name|map_data
decl_stmt|;
comment|/* Map data black box */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Options  */
end_comment

begin_struct
struct|struct
name|am_opts
block|{
name|char
modifier|*
name|fs_glob
decl_stmt|;
comment|/* Smashed copy of global options */
name|char
modifier|*
name|fs_local
decl_stmt|;
comment|/* Expanded copy of local options */
name|char
modifier|*
name|fs_mtab
decl_stmt|;
comment|/* Mount table entry */
comment|/* Other options ... */
name|char
modifier|*
name|opt_dev
decl_stmt|;
name|char
modifier|*
name|opt_delay
decl_stmt|;
name|char
modifier|*
name|opt_dir
decl_stmt|;
name|char
modifier|*
name|opt_fs
decl_stmt|;
name|char
modifier|*
name|opt_group
decl_stmt|;
name|char
modifier|*
name|opt_mount
decl_stmt|;
name|char
modifier|*
name|opt_opts
decl_stmt|;
name|char
modifier|*
name|opt_remopts
decl_stmt|;
name|char
modifier|*
name|opt_pref
decl_stmt|;
name|char
modifier|*
name|opt_cache
decl_stmt|;
name|char
modifier|*
name|opt_rfs
decl_stmt|;
name|char
modifier|*
name|opt_rhost
decl_stmt|;
name|char
modifier|*
name|opt_sublink
decl_stmt|;
name|char
modifier|*
name|opt_type
decl_stmt|;
name|char
modifier|*
name|opt_mount_type
decl_stmt|;
comment|/* "nfs" or "autofs" */
name|char
modifier|*
name|opt_unmount
decl_stmt|;
name|char
modifier|*
name|opt_umount
decl_stmt|;
comment|/* an "alias" for opt_unmount (type:=program) */
name|char
modifier|*
name|opt_user
decl_stmt|;
name|char
modifier|*
name|opt_maptype
decl_stmt|;
comment|/* map type: file, nis, hesiod, etc. */
name|char
modifier|*
name|opt_cachedir
decl_stmt|;
comment|/* cache directory */
name|char
modifier|*
name|opt_addopts
decl_stmt|;
comment|/* options to add to opt_opts */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|am_ops
block|{
name|char
modifier|*
name|fs_type
decl_stmt|;
comment|/* type of filesystems e.g. "nfsx" */
name|vfs_match
name|fs_match
decl_stmt|;
comment|/* fxn: match */
name|vfs_init
name|fs_init
decl_stmt|;
comment|/* fxn: initialization */
name|vmount_fs
name|mount_fs
decl_stmt|;
comment|/* fxn: mount my own vnode */
name|vumount_fs
name|umount_fs
decl_stmt|;
comment|/* fxn: unmount my own vnode */
name|vlookup_child
name|lookup_child
decl_stmt|;
comment|/* fxn: lookup path-name */
name|vmount_child
name|mount_child
decl_stmt|;
comment|/* fxn: mount path-name */
name|vreaddir
name|readdir
decl_stmt|;
comment|/* fxn: read directory */
name|vreadlink
name|readlink
decl_stmt|;
comment|/* fxn: read link */
name|vmounted
name|mounted
decl_stmt|;
comment|/* fxn: after-mount extra actions */
name|vumounted
name|umounted
decl_stmt|;
comment|/* fxn: after-umount extra actions */
name|vffserver
name|ffserver
decl_stmt|;
comment|/* fxn: find a file server */
name|vget_wchan
name|get_wchan
decl_stmt|;
comment|/* fxn: get the waiting channel */
name|int
name|nfs_fs_flags
decl_stmt|;
comment|/* filesystem flags FS_* for nfs mounts */
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
name|int
name|autofs_fs_flags
decl_stmt|;
comment|/* filesystem flags FS_* for autofs mounts */
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
block|}
struct|;
end_struct

begin_comment
comment|/*  * List of mounted filesystems  */
end_comment

begin_struct
struct|struct
name|mntfs
block|{
name|qelem
name|mf_q
decl_stmt|;
comment|/* List of mounted filesystems */
name|am_ops
modifier|*
name|mf_ops
decl_stmt|;
comment|/* Operations on this mountpoint */
name|am_opts
modifier|*
name|mf_fo
decl_stmt|;
comment|/* File opts */
name|char
modifier|*
name|mf_mount
decl_stmt|;
comment|/* "/a/kiska/home/kiska" */
name|char
modifier|*
name|mf_info
decl_stmt|;
comment|/* Mount info */
name|char
modifier|*
name|mf_auto
decl_stmt|;
comment|/* Automount opts */
name|char
modifier|*
name|mf_mopts
decl_stmt|;
comment|/* FS mount opts */
name|char
modifier|*
name|mf_remopts
decl_stmt|;
comment|/* Remote FS mount opts */
name|char
modifier|*
name|mf_loopdev
decl_stmt|;
comment|/* loop device name for /dev/loop mounts */
name|fserver
modifier|*
name|mf_server
decl_stmt|;
comment|/* File server */
name|int
name|mf_fsflags
decl_stmt|;
comment|/* Flags FS_* copied from mf_ops->*_fs_flags */
name|int
name|mf_flags
decl_stmt|;
comment|/* Flags MFF_* */
name|int
name|mf_error
decl_stmt|;
comment|/* Error code from background mount */
name|int
name|mf_refc
decl_stmt|;
comment|/* Number of references to this node */
name|int
name|mf_cid
decl_stmt|;
comment|/* Callout id */
name|void
function_decl|(
modifier|*
name|mf_prfree
function_decl|)
parameter_list|(
name|opaque_t
parameter_list|)
function_decl|;
comment|/* Free private space */
name|opaque_t
name|mf_private
decl_stmt|;
comment|/* Private - per-fs data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * List of fileservers  */
end_comment

begin_struct
struct|struct
name|fserver
block|{
name|qelem
name|fs_q
decl_stmt|;
comment|/* List of fileservers */
name|int
name|fs_refc
decl_stmt|;
comment|/* Number of references to this server */
name|char
modifier|*
name|fs_host
decl_stmt|;
comment|/* Normalized hostname of server */
name|struct
name|sockaddr_in
modifier|*
name|fs_ip
decl_stmt|;
comment|/* Network address of server */
name|int
name|fs_cid
decl_stmt|;
comment|/* Callout id */
name|int
name|fs_pinger
decl_stmt|;
comment|/* Ping (keepalive) interval */
name|int
name|fs_flags
decl_stmt|;
comment|/* Flags */
name|char
modifier|*
name|fs_type
decl_stmt|;
comment|/* File server type */
name|u_long
name|fs_version
decl_stmt|;
comment|/* NFS version of server (2, 3, etc.)*/
name|char
modifier|*
name|fs_proto
decl_stmt|;
comment|/* NFS protocol of server (tcp, udp, etc.) */
name|opaque_t
name|fs_private
decl_stmt|;
comment|/* Private data */
name|void
function_decl|(
modifier|*
name|fs_prfree
function_decl|)
parameter_list|(
name|opaque_t
parameter_list|)
function_decl|;
comment|/* Free private data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-mountpoint statistics  */
end_comment

begin_struct
struct|struct
name|am_stats
block|{
name|time_t
name|s_mtime
decl_stmt|;
comment|/* Mount time */
name|u_short
name|s_uid
decl_stmt|;
comment|/* Uid of mounter */
name|int
name|s_getattr
decl_stmt|;
comment|/* Count of getattrs */
name|int
name|s_lookup
decl_stmt|;
comment|/* Count of lookups */
name|int
name|s_readdir
decl_stmt|;
comment|/* Count of readdirs */
name|int
name|s_readlink
decl_stmt|;
comment|/* Count of readlinks */
name|int
name|s_statfs
decl_stmt|;
comment|/* Count of statfs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * System statistics  */
end_comment

begin_struct
struct|struct
name|amd_stats
block|{
name|int
name|d_drops
decl_stmt|;
comment|/* Dropped requests */
name|int
name|d_stale
decl_stmt|;
comment|/* Stale NFS handles */
name|int
name|d_mok
decl_stmt|;
comment|/* Successful mounts */
name|int
name|d_merr
decl_stmt|;
comment|/* Failed mounts */
name|int
name|d_uerr
decl_stmt|;
comment|/* Failed unmounts */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|amd_stats
name|amd_stats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Map of auto-mount points.  */
end_comment

begin_struct
struct|struct
name|am_node
block|{
name|int
name|am_mapno
decl_stmt|;
comment|/* Map number */
name|mntfs
modifier|*
name|am_mnt
decl_stmt|;
comment|/* Mounted filesystem */
name|mntfs
modifier|*
modifier|*
name|am_mfarray
decl_stmt|;
comment|/* Filesystem sources to try to mount */
name|char
modifier|*
name|am_name
decl_stmt|;
comment|/* "kiska": name of this node */
name|char
modifier|*
name|am_path
decl_stmt|;
comment|/* "/home/kiska": path of this node's mount point */
name|char
modifier|*
name|am_link
decl_stmt|;
comment|/* "/a/kiska/home/kiska/this/that": link to sub-dir */
name|am_node
modifier|*
name|am_parent
decl_stmt|;
comment|/* Parent of this node */
name|am_node
modifier|*
name|am_ysib
decl_stmt|;
comment|/* Younger sibling of this node */
name|am_node
modifier|*
name|am_osib
decl_stmt|;
comment|/* Older sibling of this node */
name|am_node
modifier|*
name|am_child
decl_stmt|;
comment|/* First child of this node */
name|nfsattrstat
name|am_attr
decl_stmt|;
comment|/* File attributes */
define|#
directive|define
name|am_fattr
value|am_attr.ns_u.ns_attr_u
name|int
name|am_flags
decl_stmt|;
comment|/* Boolean flags AMF_* */
name|int
name|am_error
decl_stmt|;
comment|/* Specific mount error */
name|time_t
name|am_ttl
decl_stmt|;
comment|/* Time to live */
name|int
name|am_timeo_w
decl_stmt|;
comment|/* Dismount wait interval */
name|int
name|am_timeo
decl_stmt|;
comment|/* Cache timeout interval */
name|u_int
name|am_gen
decl_stmt|;
comment|/* Generation number */
name|char
modifier|*
name|am_pref
decl_stmt|;
comment|/* Mount info prefix */
name|am_stats
name|am_stats
decl_stmt|;
comment|/* Statistics gathering */
name|SVCXPRT
modifier|*
name|am_transp
decl_stmt|;
comment|/* Info for quick reply */
name|dev_t
name|am_dev
decl_stmt|;
comment|/* Device number */
name|dev_t
name|am_rdev
decl_stmt|;
comment|/* Remote/real device number */
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
name|autofs_fh_t
modifier|*
name|am_autofs_fh
decl_stmt|;
name|time_t
name|am_autofs_ttl
decl_stmt|;
comment|/* Time to expire autofs nodes */
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
block|}
struct|;
end_struct

begin_comment
comment|/*  * EXTERNALS:  */
end_comment

begin_comment
comment|/*  * Amq server global functions  */
end_comment

begin_function_decl
specifier|extern
name|amq_mount_info_list
modifier|*
name|amqproc_getmntfs_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_mount_stats
modifier|*
name|amqproc_stats_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_mount_tree_list
modifier|*
name|amqproc_export_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_mount_tree_p
modifier|*
name|amqproc_mnttree_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_string
modifier|*
name|amqproc_getvers_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|amq_string
modifier|*
name|amqproc_pawd_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|amqproc_getpid_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|amqproc_mount_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|amqproc_setopt_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|voidp
name|amqproc_null_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|voidp
name|amqproc_umnt_1_svc
parameter_list|(
name|voidp
name|argp
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* other external definitions */
end_comment

begin_function_decl
specifier|extern
name|am_nfs_fh
modifier|*
name|get_root_nfs_fh
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|find_ap
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|get_ap_child
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_mount_info_qelem
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|qelem
modifier|*
name|qhead
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fserver
modifier|*
name|find_nfs_srvr
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mount_nfs_fh
parameter_list|(
name|am_nfs_handle_t
modifier|*
name|fhp
parameter_list|,
name|char
modifier|*
name|mntdir
parameter_list|,
name|char
modifier|*
name|fs_name
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|process_all_regular_maps
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cf_map_t
modifier|*
name|find_cf_map
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_conf_kv
parameter_list|(
specifier|const
name|char
modifier|*
name|section
parameter_list|,
specifier|const
name|char
modifier|*
name|k
parameter_list|,
specifier|const
name|char
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mount_node
parameter_list|(
name|opaque_t
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unmount_mp
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amfs_mkcacheref
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amfs_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|,
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|assign_error_mntfs
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|next_nonerror_node
parameter_list|(
name|am_node
modifier|*
name|xp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_srvr_nfs_cache
parameter_list|(
name|fserver
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|am_mounted
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mf_mounted
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|,
name|bool_t
name|call_free_opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|am_unmounted
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|get_exported_ap
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|get_first_exported_ap
parameter_list|(
name|int
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|get_next_exported_ap
parameter_list|(
name|int
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|path_to_exported_ap
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|exported_ap_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|find_mf
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|next_map
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_ops
modifier|*
name|ops_match
parameter_list|(
name|am_opts
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_ops
modifier|*
name|ops_search
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fserver
modifier|*
name|dup_srvr
parameter_list|(
name|fserver
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|srvrlog
parameter_list|(
name|fserver
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_mountd_port
parameter_list|(
name|fserver
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|wchan_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_nfs_fhandle_cache
parameter_list|(
name|fserver
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mntfs
modifier|*
name|dup_mntfs
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mntfs
modifier|*
name|find_mntfs
parameter_list|(
name|am_ops
modifier|*
parameter_list|,
name|am_opts
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mntfs
modifier|*
name|locate_mntfs
parameter_list|(
name|am_ops
modifier|*
parameter_list|,
name|am_opts
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mntfs
modifier|*
name|new_mntfs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mntfs
modifier|*
name|realloc_mntfs
parameter_list|(
name|mntfs
modifier|*
parameter_list|,
name|am_ops
modifier|*
parameter_list|,
name|am_opts
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_mntfs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_mntfs
parameter_list|(
name|voidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amq_program_1
parameter_list|(
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|,
name|SVCXPRT
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|background
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deslashify
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_task_notify
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|eval_fs_opts
parameter_list|(
name|am_opts
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|forcibly_timeout_mp
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_map
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_opts
parameter_list|(
name|am_opts
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_srvr
parameter_list|(
name|fserver
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fwd_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fwd_packet
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|opaque_t
parameter_list|,
name|fwd_fun
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fwd_reply
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_args
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|wchan_t
name|get_mntfs_wchan
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|host_normalize
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_map
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ins_que
parameter_list|(
name|qelem
modifier|*
parameter_list|,
name|qelem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insert_am
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|make_nfs_auth
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_root_node
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|map_flush_srvr
parameter_list|(
name|fserver
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mapc_add_kv
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mnt_map
modifier|*
name|mapc_find
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mapc_free
parameter_list|(
name|opaque_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mapc_keyiter
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|key_fun
parameter_list|,
name|opaque_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mapc_reload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mapc_search
parameter_list|(
name|mnt_map
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mapc_showtypes
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mapc_type_exists
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mk_fattr
parameter_list|(
name|nfsfattr
modifier|*
parameter_list|,
name|nfsftype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mount_auto_node
parameter_list|(
name|char
modifier|*
parameter_list|,
name|opaque_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mount_automounter
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mount_exported
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_to_fh
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|am_nfs_fh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|new_ttl
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nfs_quick_reply
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|normalize_slash
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ops_showamfstypes
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ops_showfstypes
parameter_list|(
name|char
modifier|*
name|outbuf
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rem_que
parameter_list|(
name|qelem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reschedule_timeout_mp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restart_automounter_nodes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|root_keyiter
parameter_list|(
name|key_fun
modifier|*
parameter_list|,
name|opaque_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|root_newmap
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|cf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|run_task
parameter_list|(
name|task_fun
modifier|*
parameter_list|,
name|opaque_t
parameter_list|,
name|cb_fun
modifier|*
parameter_list|,
name|opaque_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sched_task
parameter_list|(
name|cb_fun
modifier|*
parameter_list|,
name|opaque_t
parameter_list|,
name|wchan_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|softclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|timeout
parameter_list|(
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|opaque_t
parameter_list|)
parameter_list|,
name|opaque_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timeout_mp
parameter_list|(
name|opaque_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|untimeout
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|umount_exported
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|valid_key
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wakeup
parameter_list|(
name|wchan_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wakeup_srvr
parameter_list|(
name|fserver
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wakeup_task
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|wchan_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SIZEOF_PID_FSNAME
value|(16 + MAXHOSTNAMELEN)
end_define

begin_decl_stmt
specifier|extern
name|char
name|pid_fsname
index|[
name|SIZEOF_PID_FSNAME
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "kiska.southseas.nz:(pid%d)" */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_HOSTD
value|(2 * MAXHOSTNAMELEN + 1)
end_define

begin_decl_stmt
specifier|extern
name|char
name|hostd
index|[
name|SIZEOF_HOSTD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Host+domain */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_OPTS
value|256
end_define

begin_comment
comment|/* used for char opts[] and preopts[] */
end_comment

begin_comment
comment|/*  * Global variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|yyin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|current_transp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For nfs_quick_reply() */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|conf_tag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIZEOF_UID_STR
value|12
end_define

begin_define
define|#
directive|define
name|SIZEOF_GID_STR
value|12
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|opt_gid
decl_stmt|,
name|gid_str
index|[
name|SIZEOF_GID_STR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|opt_uid
decl_stmt|,
name|uid_str
index|[
name|SIZEOF_UID_STR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|NumChildren
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fwd_sock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|select_intr_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|immediate_abort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should close-down unmounts be retried */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|usage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|use_conf_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use amd configuration file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|task_notify_todo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Task notifier needs running */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|select_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|qelem
name|mfhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|amu_global_options
name|gopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where global options are stored */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|do_mapc_reload
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flush& reload mount map cache */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|next_softclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Time to call softclock() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SIGACTION
end_ifdef

begin_decl_stmt
specifier|extern
name|sigset_t
name|masked_sigs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGACTION */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_AMU_FS_LINK
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_AMU_FS_LINKX
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|amfs_link_match
parameter_list|(
name|am_opts
modifier|*
name|fo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_AMU_FS_LINK) || defined(HAVE_AMU_FS_LINKX) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|amd_use_autofs
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|autofs_get_fh
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_release_fh
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_get_mp
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_release_mp
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_add_fdset
parameter_list|(
name|fd_set
modifier|*
name|readfds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|autofs_handle_fdset
parameter_list|(
name|fd_set
modifier|*
name|readfds
parameter_list|,
name|int
name|nsel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_mounted
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_mount_succeeded
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_mount_failed
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|autofs_umount_succeeded
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|autofs_umount_failed
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|autofs_mount_fs
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|autofs_umount_fs
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_get_opts
parameter_list|(
name|char
modifier|*
name|opts
parameter_list|,
name|size_t
name|l
parameter_list|,
name|autofs_fh_t
modifier|*
name|fh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|autofs_compute_mount_flags
parameter_list|(
name|mntent_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_timeout_mp
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|create_autofs_service
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|destroy_autofs_service
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_AUTOFS */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** Generic file-system types, implemented as part of the native O/S.	***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Loopback File System  * Many systems can't support this, and in any case most of the  * functionality is available with Symlink FS.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_LOFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|lofs_ops
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|mount_lofs
parameter_list|(
name|char
modifier|*
name|mntdir
parameter_list|,
name|char
modifier|*
name|fs_name
parameter_list|,
name|char
modifier|*
name|opts
parameter_list|,
name|int
name|on_autofs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_LOFS */
end_comment

begin_comment
comment|/*  * CD-ROM File System (CD-ROM)  * (HSFS: High Sierra F/S on some machines)  * Many systems can't support this, and in any case most of the  * functionality is available with program FS.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_CDFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|cdfs_ops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_CDFS */
end_comment

begin_comment
comment|/*  * PC File System (MS-DOS)  * Many systems can't support this, and in any case most of the  * functionality is available with program FS.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_PCFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|pcfs_ops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_PCFS */
end_comment

begin_comment
comment|/*  * Caching File System (Solaris)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_CACHEFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|cachefs_ops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_CACHEFS */
end_comment

begin_comment
comment|/*  * Network File System  * Good, slow, NFS V.2.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_NFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|nfs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NFS */
end_comment

begin_function_decl
specifier|extern
name|fserver
modifier|*
name|find_nfs_srvr
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|qelem
name|nfs_srvr_list
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_NFS */
end_comment

begin_comment
comment|/*  * Un*x File System  * Normal local disk file system.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_UFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|ufs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Un*x file system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_UFS */
end_comment

begin_comment
comment|/* Unix file system (irix) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_XFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|xfs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Un*x file system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_XFS */
end_comment

begin_comment
comment|/* Unix file system (irix) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_EFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|efs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Un*x file system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_EFS */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** Automounter file-system types, implemented by amd.			***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Root AMD File System  */
end_comment

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_root_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Root file system */
end_comment

begin_comment
comment|/*  * Generic amfs helper methods  */
end_comment

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|amfs_generic_lookup_child
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|,
name|int
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|amfs_generic_mount_child
parameter_list|(
name|am_node
modifier|*
name|ap
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amfs_generic_readdir
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|nfscookie
name|cookie
parameter_list|,
name|nfsdirlist
modifier|*
name|dp
parameter_list|,
name|nfsentry
modifier|*
name|ep
parameter_list|,
name|u_int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amfs_generic_umount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amfs_generic_mounted
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|amfs_generic_match
parameter_list|(
name|am_opts
modifier|*
name|fo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fserver
modifier|*
name|amfs_generic_find_srvr
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Automount File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_AUTO
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_auto_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Automount file system (this!) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_AUTO */
end_comment

begin_comment
comment|/*  * Toplvl Automount File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_TOPLVL
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_toplvl_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Toplvl Automount file system */
end_comment

begin_function_decl
specifier|extern
name|int
name|amfs_toplvl_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amfs_toplvl_umount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_TOPLVL */
end_comment

begin_comment
comment|/*  * Direct Automount File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_DIRECT
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_direct_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Direct Automount file system (this too) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_DIRECT */
end_comment

begin_comment
comment|/*  * Error File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_ERROR
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_error_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error file system */
end_comment

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|amfs_error_lookup_child
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|,
name|int
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|amfs_error_mount_child
parameter_list|(
name|am_node
modifier|*
name|ap
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amfs_error_readdir
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|nfscookie
name|cookie
parameter_list|,
name|nfsdirlist
modifier|*
name|dp
parameter_list|,
name|nfsentry
modifier|*
name|ep
parameter_list|,
name|u_int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_ERROR */
end_comment

begin_comment
comment|/*  * NFS mounts with local existence check.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_NFSL
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_nfsl_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NFSL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_NFSL */
end_comment

begin_comment
comment|/*  * Multi-nfs mounts.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_NFSX
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_nfsx_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NFSX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_NFSX */
end_comment

begin_comment
comment|/*  * NFS host - a whole tree.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_HOST
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_host_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NFS host */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_HOST */
end_comment

begin_comment
comment|/*  * Program File System  * This is useful for things like RVD.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_PROGRAM
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_program_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Program File System */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_PROGRAM */
end_comment

begin_comment
comment|/*  * Symbolic-link file system.  * A "filesystem" which is just a symbol link.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_LINK
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_link_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Symlink FS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_LINK */
end_comment

begin_comment
comment|/*  * Symbolic-link file system, which also checks that the target of  * the symlink exists.  * A "filesystem" which is just a symbol link.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_LINKX
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_linkx_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Symlink FS with existence check */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_LINKX */
end_comment

begin_comment
comment|/*  * Union file system  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AMU_FS_UNION
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_union_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Union FS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AMU_FS_UNION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMD_H */
end_comment

end_unit

