begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: am_utils.h,v 1.6 1999/08/22 05:12:55 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * Definitions that are specific to the am-utils package.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AM_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|_AM_UTILS_H
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** MACROS								***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * General macros.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not FALSE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TRUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MAX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MIN */
end_comment

begin_define
define|#
directive|define
name|ONE_HOUR
value|(60 * 60)
end_define

begin_comment
comment|/* One hour in seconds */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HOSTNAMESZ
end_ifdef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|HOSTNAMESZ
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HOSTNAMESZ */
end_comment

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HOSTNAMESZ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MAXHOSTNAMELEN */
end_comment

begin_comment
comment|/*  * String comparison macros  */
end_comment

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp((s1), (s2)) == 0)
end_define

begin_define
define|#
directive|define
name|STRCEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcasecmp((s1), (s2)) == 0)
end_define

begin_define
define|#
directive|define
name|NSTREQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|(strncmp((s1), (s2), (n)) == 0)
end_define

begin_define
define|#
directive|define
name|FSTREQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|((*(s1) == *(s2))&& STREQ((s1),(s2)))
end_define

begin_comment
comment|/*  * Logging options/flags  */
end_comment

begin_define
define|#
directive|define
name|XLOG_FATAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|XLOG_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|XLOG_USER
value|0x0004
end_define

begin_define
define|#
directive|define
name|XLOG_WARNING
value|0x0008
end_define

begin_define
define|#
directive|define
name|XLOG_INFO
value|0x0010
end_define

begin_define
define|#
directive|define
name|XLOG_DEBUG
value|0x0020
end_define

begin_define
define|#
directive|define
name|XLOG_MAP
value|0x0040
end_define

begin_define
define|#
directive|define
name|XLOG_STATS
value|0x0080
end_define

begin_define
define|#
directive|define
name|XLOG_DEFSTR
value|"all,nomap,nostats"
end_define

begin_comment
comment|/* Default log options */
end_comment

begin_define
define|#
directive|define
name|XLOG_ALL
value|(XLOG_FATAL|XLOG_ERROR|XLOG_USER|XLOG_WARNING|XLOG_INFO|XLOG_MAP|XLOG_STATS)
end_define

begin_define
define|#
directive|define
name|clocktime
parameter_list|()
value|(clock_valid ? clock_valid : time(&clock_valid))
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
name|NO_SUBNET
value|"notknown"
end_define

begin_comment
comment|/* default subnet name for no subnet */
end_comment

begin_define
define|#
directive|define
name|NEXP_AP
value|(1022)
end_define

begin_comment
comment|/* gdmr: was 254 */
end_comment

begin_define
define|#
directive|define
name|NEXP_AP_MARGIN
value|(128)
end_define

begin_define
define|#
directive|define
name|MAX_READDIR_ENTRIES
value|16
end_define

begin_comment
comment|/*  * Linked list macros  */
end_comment

begin_define
define|#
directive|define
name|AM_FIRST
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) ((q)->q_forw))
end_define

begin_define
define|#
directive|define
name|AM_LAST
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) ((q)->q_back))
end_define

begin_define
define|#
directive|define
name|NEXT
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) (((qelem *) q)->q_forw))
end_define

begin_define
define|#
directive|define
name|PREV
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) (((qelem *) q)->q_back))
end_define

begin_define
define|#
directive|define
name|HEAD
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) q)
end_define

begin_define
define|#
directive|define
name|ITER
parameter_list|(
name|v
parameter_list|,
name|ty
parameter_list|,
name|q
parameter_list|)
define|\
value|for ((v) = AM_FIRST(ty,(q)); (v) != HEAD(ty,(q)); (v) = NEXT(ty,(v)))
end_define

begin_comment
comment|/* allocate anything of type ty */
end_comment

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|ty
parameter_list|)
value|((ty *) xmalloc(sizeof(ty)))
end_define

begin_define
define|#
directive|define
name|CALLOC
parameter_list|(
name|ty
parameter_list|)
value|((ty *) xcalloc(1, sizeof(ty)))
end_define

begin_comment
comment|/* simply allocate b bytes */
end_comment

begin_define
define|#
directive|define
name|SALLOC
parameter_list|(
name|b
parameter_list|)
value|xmalloc((b))
end_define

begin_comment
comment|/* converting am-filehandles to mount-points */
end_comment

begin_define
define|#
directive|define
name|fh_to_mp2
parameter_list|(
name|fhp
parameter_list|,
name|rp
parameter_list|)
value|fh_to_mp3(fhp, rp, VLOOK_CREATE)
end_define

begin_comment
comment|/*  * Systems which have the mount table in a file need to read it before  * they can perform an unmount() system call.  */
end_comment

begin_define
define|#
directive|define
name|UMOUNT_FS
parameter_list|(
name|dir
parameter_list|,
name|mtb_name
parameter_list|)
value|umount_fs(dir, mtb_name)
end_define

begin_comment
comment|/* imported via $srcdir/conf/umount/umount_*.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|umount_fs
parameter_list|(
name|char
modifier|*
name|fs_name
parameter_list|,
specifier|const
name|char
modifier|*
name|mnttabname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * macros for automounter vfs/vnode operations.  */
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
name|FSRV_ISDOWN
parameter_list|(
name|fs
parameter_list|)
value|(((fs)->fs_flags& (FSF_DOWN|FSF_VALID)) == (FSF_DOWN|FSF_VALID))
end_define

begin_define
define|#
directive|define
name|FSRV_ISUP
parameter_list|(
name|fs
parameter_list|)
value|(((fs)->fs_flags& (FSF_DOWN|FSF_VALID)) == (FSF_VALID))
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_NFSL
end_ifdef

begin_define
define|#
directive|define
name|MFF_NFSLINK
value|0x0200
end_define

begin_comment
comment|/* nfsl type, and deemed a link */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AM_FS_NFSL */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_define
define|#
directive|define
name|AMF_AUTOFS
value|0x0004
end_define

begin_comment
comment|/* this node is of type autofs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_AUTOFS */
end_comment

begin_comment
comment|/*  * The following values can be tuned...  */
end_comment

begin_define
define|#
directive|define
name|ALLOWED_MOUNT_TIME
value|40
end_define

begin_comment
comment|/* 40s for a mount */
end_comment

begin_define
define|#
directive|define
name|AM_TTL
value|(5 * 60)
end_define

begin_comment
comment|/* Default cache period */
end_comment

begin_define
define|#
directive|define
name|AM_TTL_W
value|(2 * 60)
end_define

begin_comment
comment|/* Default unmount interval */
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

begin_comment
comment|/*  * default amfs_auto retrans - 1/10th seconds  */
end_comment

begin_define
define|#
directive|define
name|AMFS_AUTO_RETRANS
value|((ALLOWED_MOUNT_TIME*10+5*gopt.amfs_auto_timeo)/gopt.amfs_auto_timeo * 2)
end_define

begin_comment
comment|/*  * RPC-related macros.  */
end_comment

begin_define
define|#
directive|define
name|RPC_XID_PORTMAP
value|0
end_define

begin_define
define|#
directive|define
name|RPC_XID_MOUNTD
value|1
end_define

begin_define
define|#
directive|define
name|RPC_XID_NFSPING
value|2
end_define

begin_define
define|#
directive|define
name|RPC_XID_MASK
value|(0x0f)
end_define

begin_comment
comment|/* 16 id's for now */
end_comment

begin_define
define|#
directive|define
name|MK_RPC_XID
parameter_list|(
name|type_id
parameter_list|,
name|uniq
parameter_list|)
value|((type_id) | ((uniq)<< 4))
end_define

begin_comment
comment|/*  * What level of AMD are we backward compatible with?  * This only applies to externally visible characteristics.  * Rev.Minor.Branch.Patch (2 digits each)  */
end_comment

begin_define
define|#
directive|define
name|AMD_COMPAT
value|5000000
end_define

begin_comment
comment|/* 5.0 */
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
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** STRUCTURES AND TYPEDEFS						***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/* some typedefs must come first */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|amq_string
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
name|am_node
name|am_node
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_qelem
name|qelem
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mntlist
name|mntlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fserver
name|fserver
typedef|;
end_typedef

begin_comment
comment|/*  * Linked list  * (the name 'struct qelem' conflicts with linux's unistd.h)  */
end_comment

begin_struct
struct|struct
name|_qelem
block|{
name|qelem
modifier|*
name|q_forw
decl_stmt|;
name|qelem
modifier|*
name|q_back
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Option tables  */
end_comment

begin_struct
struct|struct
name|opt_tab
block|{
name|char
modifier|*
name|opt
decl_stmt|;
name|int
name|flag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Server states  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Start
block|,
name|Run
block|,
name|Finishing
block|,
name|Quit
block|,
name|Done
block|}
name|serv_state
typedef|;
end_typedef

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
name|opt_autopref
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
name|opt_unmount
decl_stmt|;
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
name|fserver
modifier|*
name|mf_server
decl_stmt|;
comment|/* File server */
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
name|voidp
parameter_list|)
function_decl|;
comment|/* Free private space */
name|voidp
name|mf_private
decl_stmt|;
comment|/* Private - per-fs data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * File Handle  *  * This is interpreted by indexing the exported array  * by fhh_id.  *  * The whole structure is mapped onto a standard fhandle_t  * when transmitted.  */
end_comment

begin_struct
struct|struct
name|am_fh
block|{
name|int
name|fhh_pid
decl_stmt|;
comment|/* process id */
name|int
name|fhh_id
decl_stmt|;
comment|/* map id */
name|int
name|fhh_gen
decl_stmt|;
comment|/* generation number */
block|}
struct|;
end_struct

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
name|struct
name|mountres3
name|v3
decl_stmt|;
comment|/* NFS version 3 handle */
endif|#
directive|endif
comment|/* HAVE_FS_NFS3 */
name|struct
name|fhstatus
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
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|vfmount_fs
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
name|vumount_fs
function_decl|)
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|vfumount_fs
function_decl|)
parameter_list|(
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
name|vlookuppn
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
name|am_node
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

begin_struct
struct|struct
name|am_ops
block|{
name|char
modifier|*
name|fs_type
decl_stmt|;
comment|/* type of filesystems "nfsx" */
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
comment|/* fxn: mount vnode */
name|vfmount_fs
name|fmount_fs
decl_stmt|;
comment|/* fxn: mount VFS */
name|vumount_fs
name|umount_fs
decl_stmt|;
comment|/* fxn: unmount vnode */
name|vfumount_fs
name|fumount_fs
decl_stmt|;
comment|/* fxn: unmount VFS */
name|vlookuppn
name|lookuppn
decl_stmt|;
comment|/* fxn: lookup path-name */
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
name|int
name|fs_flags
decl_stmt|;
comment|/* filesystem flags FS_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|task_fun
function_decl|)
parameter_list|(
name|voidp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cb_fun
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|voidp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*fwd_fun
argument_list|)
name|P
argument_list|(
operator|(
name|voidp
operator|,
name|int
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|voidp
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/*  * List of mount table entries  */
end_comment

begin_struct
struct|struct
name|mntlist
block|{
name|struct
name|mntlist
modifier|*
name|mnext
decl_stmt|;
name|mntent_t
modifier|*
name|mnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mount map  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mnt_map
name|mnt_map
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|struct
name|am_stats
name|am_stats
typedef|;
end_typedef

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
comment|/* Number of references to this node */
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
name|voidp
name|fs_private
decl_stmt|;
comment|/* Private data */
name|void
function_decl|(
modifier|*
name|fs_prfree
function_decl|)
parameter_list|(
name|voidp
parameter_list|)
function_decl|;
comment|/* Free private data */
block|}
struct|;
end_struct

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
comment|/* Wait interval */
name|int
name|am_timeo
decl_stmt|;
comment|/* Timeout interval */
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
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** EXTERNALS								***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Useful constants  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mnttab_file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mount table */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "CPU type" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endian
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "big" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hostdomain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "southseas.nz" */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|copyright
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copyright info */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|hostd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "kiska.southseas.nz" */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|pid_fsname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kiska.southseas.nz:(pid%d) */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Version info */
end_comment

begin_comment
comment|/*  * Global variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|AUTH
modifier|*
name|nfs_auth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dummy authorization for remote servers */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|logfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Log file */
end_comment

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
modifier|*
name|exported_ap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of nodes */
end_comment

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|root_node
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Node for "root" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PrimNetName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of primary connected network */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PrimNetNum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of primary connected network */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SubsNetName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of subsidiary connected network */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SubsNetNum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of subsidiary connected network */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|extern char *progname;
comment|/* "amd" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|am_set_progname
parameter_list|(
name|char
modifier|*
name|pn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* "amd" */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|am_get_progname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* "amd" */
end_comment

begin_function_decl
specifier|extern
name|void
name|am_set_hostname
parameter_list|(
name|char
modifier|*
name|hn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|am_get_hostname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pid_t
name|am_set_mypid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|pid_t
name|am_mypid
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|extern char hostname[];
comment|/* "kiska" */
end_comment

begin_comment
unit|extern pid_t mypid;
comment|/* Current process id */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|first_free_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First free node */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|foreground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Foreground process */
end_comment

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
name|last_used_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last map being used for mounts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|orig_umask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* umask() on startup */
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
name|int
name|xlog_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logging level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xlog_level_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|serv_state
name|amd_state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should we go now */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|myipaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (An) IP address of this host */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|opt_tab
name|xlog_opt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|clock_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clock needs recalculating */
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

begin_decl_stmt
specifier|extern
name|u_short
name|nfs_port
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our NFS service port */
end_comment

begin_comment
comment|/*  * Global routines  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|get_mount_client
parameter_list|(
name|char
modifier|*
name|unused_host
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|sin
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|int
modifier|*
name|sock
parameter_list|,
name|u_long
name|mnt_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RETSIGTYPE
name|sigchld
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|nfsxprt
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|efs_lookuppn
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
name|fh_to_mp
parameter_list|(
name|am_nfs_fh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|fh_to_mp3
parameter_list|(
name|am_nfs_fh
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
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
name|am_node
modifier|*
name|root_ap
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
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
name|bool_t
name|xdr_amq_string
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_string
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|strsplit
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|expand_key
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_version_string
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|inet_dquad
parameter_list|(
name|char
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|print_wires
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|str3cat
parameter_list|(
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
name|char
modifier|*
name|strealloc
parameter_list|(
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
name|char
modifier|*
name|strip_selectors
parameter_list|(
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
name|char
modifier|*
name|strnsave
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
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
name|int
name|amu_close
parameter_list|(
name|int
name|fd
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
name|int
name|bind_resv_port
parameter_list|(
name|int
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cmdoption
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|opt_tab
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|compute_automounter_mount_flags
parameter_list|(
name|mntent_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|compute_mount_flags
parameter_list|(
name|mntent_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|efs_readdir
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
name|int
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
name|voidp
parameter_list|,
name|fwd_fun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_amd_program_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hasmntval
parameter_list|(
name|mntent_t
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
name|is_network_member
parameter_list|(
specifier|const
name|char
modifier|*
name|net
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|islocalnet
parameter_list|(
name|u_long
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
name|int
name|make_rpc_packet
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|,
name|voidp
parameter_list|,
name|XDRPROC_T_TYPE
parameter_list|,
name|AUTH
modifier|*
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
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|voidp
parameter_list|)
parameter_list|,
name|voidp
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
name|int
name|mkdirs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
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
name|voidp
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
name|int
name|mount_fs
parameter_list|(
name|mntent_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|,
name|MTYPE_TYPE
parameter_list|,
name|u_long
parameter_list|,
specifier|const
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
name|int
name|mount_node
parameter_list|(
name|am_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nfs_srvr_port
parameter_list|(
name|fserver
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|voidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pickup_rpc_reply
parameter_list|(
name|voidp
parameter_list|,
name|int
parameter_list|,
name|voidp
parameter_list|,
name|XDRPROC_T_TYPE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|root_keyiter
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|voidp
parameter_list|)
parameter_list|,
name|voidp
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
name|switch_option
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|switch_to_logfile
parameter_list|(
name|char
modifier|*
name|logfile
parameter_list|,
name|int
name|orig_umask
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
name|voidp
parameter_list|)
parameter_list|,
name|voidp
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
name|mntlist
modifier|*
name|read_mtab
parameter_list|(
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
name|struct
name|sockaddr_in
modifier|*
name|amu_svc_getcaller
parameter_list|(
name|SVCXPRT
modifier|*
name|xprt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|(
name|time_t
modifier|*
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
name|am_unmounted
parameter_list|(
name|am_node
modifier|*
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
name|void
name|amu_get_myaddress
parameter_list|(
name|struct
name|in_addr
modifier|*
name|iap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amu_release_controlling_tty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compute_automounter_nfs_args
parameter_list|(
name|nfs_args_t
modifier|*
name|nap
parameter_list|,
name|mntent_t
modifier|*
name|mntp
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
name|discard_mntlist
parameter_list|(
name|mntlist
modifier|*
name|mp
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
name|flush_nfs_fhandle_cache
parameter_list|(
name|fserver
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
name|free_mntfs
parameter_list|(
name|voidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_mntlist
parameter_list|(
name|mntlist
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
name|void
name|getwire
parameter_list|(
name|char
modifier|*
modifier|*
name|name1
parameter_list|,
name|char
modifier|*
modifier|*
name|number1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|going_down
parameter_list|(
name|int
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
name|void
name|mapc_free
parameter_list|(
name|voidp
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
name|void
name|mapc_showtypes
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mk_fattr
parameter_list|(
name|am_node
modifier|*
parameter_list|,
name|nfsftype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mnt_free
parameter_list|(
name|mntent_t
modifier|*
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
name|nfs_program_2
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|plog
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

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
name|rmdirs
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rpc_msg_init
parameter_list|(
name|struct
name|rpc_msg
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|run_task
parameter_list|(
name|task_fun
parameter_list|,
name|voidp
parameter_list|,
name|cb_fun
parameter_list|,
name|voidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sched_task
parameter_list|(
name|cb_fun
parameter_list|,
name|voidp
parameter_list|,
name|voidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_amd_program_number
parameter_list|(
name|int
name|program
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_opts
parameter_list|(
name|int
name|ch
parameter_list|,
name|struct
name|opt_tab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_rcs_info
parameter_list|(
specifier|const
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
name|void
name|timeout_mp
parameter_list|(
name|voidp
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
name|void
name|unregister_amq
parameter_list|(
name|void
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
name|wakeup
parameter_list|(
name|voidp
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
name|voidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|voidp
name|xmalloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|voidp
name|xrealloc
parameter_list|(
name|voidp
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|voidp
name|xzalloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|get_nfs_version
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|sin
parameter_list|,
name|u_long
name|nfs_version
parameter_list|,
specifier|const
name|char
modifier|*
name|proto
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MOUNT_TABLE_ON_FILE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|rewrite_mtab
parameter_list|(
name|mntlist
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
name|unlock_mntlist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_mntent
parameter_list|(
name|mntent_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOUNT_TABLE_ON_FILE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYSLOG_H
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_SYS_SYSLOG_H
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|syslogging
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_SYSLOG_H) || defined(HAVE_SYS_SYSLOG_H) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TRANSPORT_TYPE_TLI
end_ifdef

begin_function_decl
specifier|extern
name|void
name|compute_nfs_args
parameter_list|(
name|nfs_args_t
modifier|*
name|nap
parameter_list|,
name|mntent_t
modifier|*
name|mntp
parameter_list|,
name|int
name|genflags
parameter_list|,
name|struct
name|netconfig
modifier|*
name|nfsncp
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|ip_addr
parameter_list|,
name|u_long
name|nfs_version
parameter_list|,
name|char
modifier|*
name|nfs_proto
parameter_list|,
name|am_nfs_handle_t
modifier|*
name|fhp
parameter_list|,
name|char
modifier|*
name|host_name
parameter_list|,
name|char
modifier|*
name|fs_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|create_amq_service
parameter_list|(
name|int
modifier|*
name|udp_soAMQp
parameter_list|,
name|SVCXPRT
modifier|*
modifier|*
name|udp_amqpp
parameter_list|,
name|struct
name|netconfig
modifier|*
modifier|*
name|udp_amqncpp
parameter_list|,
name|int
modifier|*
name|tcp_soAMQp
parameter_list|,
name|SVCXPRT
modifier|*
modifier|*
name|tcp_amqpp
parameter_list|,
name|struct
name|netconfig
modifier|*
modifier|*
name|tcp_amqncpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|create_nfs_service
parameter_list|(
name|int
modifier|*
name|soNFSp
parameter_list|,
name|u_short
modifier|*
name|nfs_portp
parameter_list|,
name|SVCXPRT
modifier|*
modifier|*
name|nfs_xprtp
parameter_list|,
name|void
function_decl|(
modifier|*
name|dispatch_fxn
function_decl|)
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_knetconfig
parameter_list|(
name|struct
name|knetconfig
modifier|*
modifier|*
name|kncpp
parameter_list|,
name|struct
name|netconfig
modifier|*
name|in_ncp
parameter_list|,
name|char
modifier|*
name|nc_protoname
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|netconfig
modifier|*
name|nfsncp
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|free_knetconfig
parameter_list|(
name|struct
name|knetconfig
modifier|*
name|kncp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_TRANSPORT_TYPE_TLI */
end_comment

begin_function_decl
specifier|extern
name|void
name|compute_nfs_args
parameter_list|(
name|nfs_args_t
modifier|*
name|nap
parameter_list|,
name|mntent_t
modifier|*
name|mntp
parameter_list|,
name|int
name|genflags
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|ip_addr
parameter_list|,
name|u_long
name|nfs_version
parameter_list|,
name|char
modifier|*
name|nfs_proto
parameter_list|,
name|am_nfs_handle_t
modifier|*
name|fhp
parameter_list|,
name|char
modifier|*
name|host_name
parameter_list|,
name|char
modifier|*
name|fs_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|clnt_stat
name|pmap_ping
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|create_amq_service
parameter_list|(
name|int
modifier|*
name|udp_soAMQp
parameter_list|,
name|SVCXPRT
modifier|*
modifier|*
name|udp_amqpp
parameter_list|,
name|int
modifier|*
name|tcp_soAMQp
parameter_list|,
name|SVCXPRT
modifier|*
modifier|*
name|tcp_amqpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|create_nfs_service
parameter_list|(
name|int
modifier|*
name|soNFSp
parameter_list|,
name|u_short
modifier|*
name|nfs_portp
parameter_list|,
name|SVCXPRT
modifier|*
modifier|*
name|nfs_xprtp
parameter_list|,
name|void
function_decl|(
modifier|*
name|dispatch_fxn
function_decl|)
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
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_TRANSPORT_TYPE_TLI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FIELD_STRUCT_FHSTATUS_FHS_FH
end_ifndef

begin_define
define|#
directive|define
name|fhs_fh
value|fhstatus_u.fhs_fhandle
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_FIELD_STRUCT_FHSTATUS_FHS_FH */
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

begin_function_decl
specifier|extern
name|int
name|nfs_fmount
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
name|nfs_fumount
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
name|nfs_init
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|qelem
name|nfs_srvr_list
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|nfs_umounted
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_NFS */
end_comment

begin_comment
comment|/*  * Network File System: the new generation  * NFS V.3  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_NFS3
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_VERSION3
end_ifndef

begin_define
define|#
directive|define
name|NFS_VERSION3
value|((u_int) 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFS_VERSION3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_NFS3 */
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
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** Automounter file-system types, implemented by amd.			***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Automount File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_AUTO
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

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_toplvl_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Top-level automount file system */
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

begin_decl_stmt
specifier|extern
name|qelem
name|amfs_auto_srvr_list
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|amfs_auto_lookuppn
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
name|char
modifier|*
name|amfs_auto_match
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
name|find_amfs_auto_srvr
parameter_list|(
name|mntfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amfs_auto_readdir
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
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amfs_auto_umount
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
name|amfs_auto_fmount
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
name|amfs_auto_fumount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AM_FS_AUTO */
end_comment

begin_comment
comment|/*  * Toplvl Automount File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_TOPLVL
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amfs_toplvl_mounted
parameter_list|(
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
comment|/* HAVE_AM_FS_TOPLVL */
end_comment

begin_comment
comment|/*  * Direct Automount File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_DIRECT
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
comment|/* HAVE_AM_FS_DIRECT */
end_comment

begin_comment
comment|/*  * Error File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_ERROR
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
name|amfs_error_lookuppn
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
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AM_FS_ERROR */
end_comment

begin_comment
comment|/*  * Inheritance File System  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_INHERIT
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|amfs_inherit_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Inheritance file system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_AM_FS_INHERIT */
end_comment

begin_comment
comment|/*  * NFS mounts with local existence check.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_NFSL
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
comment|/* HAVE_AM_FS_NFSL */
end_comment

begin_comment
comment|/*  * Multi-nfs mounts.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_NFSX
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
comment|/* HAVE_AM_FS_NFSX */
end_comment

begin_comment
comment|/*  * NFS host - a whole tree.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_HOST
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
comment|/* HAVE_AM_FS_HOST */
end_comment

begin_comment
comment|/*  * Program File System  * This is useful for things like RVD.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_PROGRAM
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
comment|/* HAVE_AM_FS_PROGRAM */
end_comment

begin_comment
comment|/*  * Symbolic-link file system.  * A "filesystem" which is just a symbol link.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_LINK
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

begin_function_decl
specifier|extern
name|int
name|amfs_link_fmount
parameter_list|(
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
comment|/* HAVE_AM_FS_LINK */
end_comment

begin_comment
comment|/*  * Symbolic-link file system, which also checks that the target of  * the symlink exists.  * A "filesystem" which is just a symbol link.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_LINKX
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
comment|/* HAVE_AM_FS_LINKX */
end_comment

begin_comment
comment|/*  * Union file system  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_UNION
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
comment|/* HAVE_AM_FS_UNION */
end_comment

begin_comment
comment|/*  * Autofs file system  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
name|autofs_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (Sun) Autofs FS */
end_comment

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
comment|/*** DEBUGGING								***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * DEBUGGING:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|D_ALL
value|(~0)
end_define

begin_define
define|#
directive|define
name|D_DAEMON
value|0x0001
end_define

begin_comment
comment|/* Enter daemon mode */
end_comment

begin_define
define|#
directive|define
name|D_TRACE
value|0x0002
end_define

begin_comment
comment|/* Do protocol trace */
end_comment

begin_define
define|#
directive|define
name|D_FULL
value|0x0004
end_define

begin_comment
comment|/* Do full trace */
end_comment

begin_define
define|#
directive|define
name|D_MTAB
value|0x0008
end_define

begin_comment
comment|/* Use local mtab */
end_comment

begin_define
define|#
directive|define
name|D_AMQ
value|0x0010
end_define

begin_comment
comment|/* Register amq program */
end_comment

begin_define
define|#
directive|define
name|D_STR
value|0x0020
end_define

begin_comment
comment|/* Debug string munging */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEM
end_ifdef

begin_define
define|#
directive|define
name|D_MEM
value|0x0040
end_define

begin_comment
comment|/* Trace memory allocations */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM */
end_comment

begin_define
define|#
directive|define
name|D_FORK
value|0x0080
end_define

begin_comment
comment|/* Fork server */
end_comment

begin_comment
comment|/* info service specific debugging (hesiod, nis, etc) */
end_comment

begin_define
define|#
directive|define
name|D_INFO
value|0x0100
end_define

begin_comment
comment|/*  * Normally, don't enter daemon mode, and don't register amq  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEM
end_ifdef

begin_define
define|#
directive|define
name|D_TEST
value|(~(D_DAEMON|D_MEM|D_STR))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG_MEM */
end_comment

begin_define
define|#
directive|define
name|D_TEST
value|(~(D_DAEMON|D_STR))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG_MEM */
end_comment

begin_define
define|#
directive|define
name|amuDebug
parameter_list|(
name|x
parameter_list|)
value|if (debug_flags& (x))
end_define

begin_define
define|#
directive|define
name|dlog
value|amuDebug(D_FULL) dplog
end_define

begin_define
define|#
directive|define
name|amuDebugNo
parameter_list|(
name|x
parameter_list|)
value|if (!(debug_flags& (x)))
end_define

begin_comment
comment|/* debugging mount-table file to use */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG_MNTTAB
end_ifndef

begin_define
define|#
directive|define
name|DEBUG_MNTTAB
value|"./mnttab"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG_MNTTAB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEM
end_ifdef

begin_comment
comment|/*  * If debugging memory, then call a special freeing function that logs  * more info, and resets the pointer to NULL so it cannot be used again.  */
end_comment

begin_define
define|#
directive|define
name|XFREE
parameter_list|(
name|x
parameter_list|)
value|dxfree(__FILE__,__LINE__,x)
end_define

begin_function_decl
specifier|extern
name|void
name|dxfree
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|voidp
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|malloc_verify
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG_MEM */
end_comment

begin_comment
comment|/*  * If regular debugging, then free the pointer and reset to NULL.  * This should remain so for as long as am-utils is in alpha/beta testing.  */
end_comment

begin_define
define|#
directive|define
name|XFREE
parameter_list|(
name|x
parameter_list|)
value|do { free((voidp)x); x = NULL;} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG_MEM */
end_comment

begin_comment
comment|/* functions that depend solely on debugging */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_nfs_args
parameter_list|(
specifier|const
name|nfs_args_t
modifier|*
name|nap
parameter_list|,
name|u_long
name|nfs_version
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG */
end_comment

begin_comment
comment|/*  * if not debugging, then simple perform free, and don't bother  * resetting the pointer.  */
end_comment

begin_define
define|#
directive|define
name|XFREE
parameter_list|(
name|x
parameter_list|)
value|free(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug options */
end_comment

begin_function_decl
specifier|extern
name|int
name|debug_option
parameter_list|(
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|opt_tab
name|dbg_opt
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|dplog
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*** MISC (stuff left to autoconfiscate)				***/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AM_UTILS_H */
end_comment

end_unit

