begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/include/am_utils.h  *  */
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

begin_include
include|#
directive|include
file|"aux_conf.h"
end_include

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
value|256
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
comment|/*  * for hlfsd, and amd for detecting uid/gid  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INVALIDID
end_ifndef

begin_comment
comment|/* this is also defined in include/am_utils.h */
end_comment

begin_define
define|#
directive|define
name|INVALIDID
value|(((unsigned short) ~0) - 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INVALIDID */
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
name|NSTRCEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|(strncasecmp((s1), (s2), (n)) == 0)
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

begin_comment
comment|/* ???? not used */
end_comment

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
value|((ty *) xzalloc(sizeof(ty)))
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
parameter_list|,
name|unmount_flags
parameter_list|)
value|umount_fs(dir, mtb_name, unmount_flags)
end_define

begin_comment
comment|/* next two are imported via $srcdir/conf/umount/umount_*.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|umount_fs
parameter_list|(
name|char
modifier|*
name|mntdir
parameter_list|,
specifier|const
name|char
modifier|*
name|mnttabname
parameter_list|,
name|u_int
name|unmount_flags
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MNT2_GEN_OPT_FORCE
end_ifdef

begin_function_decl
specifier|extern
name|int
name|umount2_fs
parameter_list|(
specifier|const
name|char
modifier|*
name|mntdir
parameter_list|,
name|u_int
name|unmount_flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNT2_GEN_OPT_FORCE */
end_comment

begin_comment
comment|/* unmount-related flags (special handling of autofs, forced/lazy, etc.) */
end_comment

begin_define
define|#
directive|define
name|AMU_UMOUNT_FORCE
value|0x1
end_define

begin_define
define|#
directive|define
name|AMU_UMOUNT_DETACH
value|0x2
end_define

begin_define
define|#
directive|define
name|AMU_UMOUNT_AUTOFS
value|0x4
end_define

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
name|RPC_XID_WEBNFS
value|3
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
name|SVCXPRT
modifier|*
name|nfsxprt
decl_stmt|;
end_decl_stmt

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
name|orig_umask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* umask() on startup */
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
name|expand_selectors
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
name|size_t
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
name|get_amd_program_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getcreds
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
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
name|unsigned
name|int
name|hasmntvalerr
parameter_list|(
name|mntent_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|hasmntstr
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
name|char
modifier|*
name|hasmnteq
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
name|char
modifier|*
name|haseq
parameter_list|(
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
name|is_interface_local
parameter_list|(
name|u_long
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
parameter_list|,
name|int
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
parameter_list|,
name|int
name|truncate_log
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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TRANSPORT_TYPE_TLI
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_TRANSPORT_TYPE_TLI */
end_comment

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
name|amu_get_myaddress
parameter_list|(
name|struct
name|in_addr
modifier|*
name|iap
parameter_list|,
specifier|const
name|char
modifier|*
name|preferred_localhost
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
name|plog
parameter_list|(
name|int
parameter_list|,
specifier|const
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
name|unregister_amq
parameter_list|(
name|void
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
name|int
name|check_pmap_up
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|sin
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

begin_function_decl
specifier|extern
name|long
name|get_server_pid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setup_sighandler
parameter_list|(
name|int
name|signum
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|clocktime
parameter_list|(
name|nfstime
modifier|*
name|nt
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|HAVE_C99_VARARGS_MACROS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_GCC_VARARGS_MACROS
argument_list|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_C99_VARARGS_MACROS
end_ifdef

begin_define
define|#
directive|define
name|xsnprintf
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|_xsnprintf(__FILE__,__LINE__,(str),(size),(fmt),__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_C99_VARARGS_MACROS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GCC_VARARGS_MACROS
end_ifdef

begin_define
define|#
directive|define
name|xsnprintf
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|_xsnprintf(__FILE__,__LINE__,(str),(size),(fmt),args)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GCC_VARARGS_MACROS */
end_comment

begin_function_decl
specifier|extern
name|int
name|_xsnprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|lineno
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xvsnprintf
parameter_list|(
name|str
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
value|_xvsnprintf(__FILE__,__LINE__,(str),(size),(fmt),(ap))
end_define

begin_function_decl
specifier|extern
name|int
name|_xvsnprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|lineno
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG or no C99/GCC-style vararg cpp macros supported */
end_comment

begin_function_decl
specifier|extern
name|int
name|xsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG or no C99/GCC-style vararg cpp macros supported */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|_xstrlcat
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|lineno
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xstrlcat
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|_xstrlcat(__FILE__,__LINE__,(d),(s),(l))
end_define

begin_function_decl
specifier|extern
name|void
name|_xstrlcpy
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|lineno
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xstrlcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|_xstrlcpy(__FILE__,__LINE__,(d),(s),(l))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG */
end_comment

begin_function_decl
specifier|extern
name|void
name|xstrlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xstrlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG */
end_comment

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
parameter_list|,
name|u_short
name|preferred_amq_port
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
name|amu_svc_register
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
parameter_list|,
name|u_long
parameter_list|,
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TRANSPORT_TYPE_TLI
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TRANSPORT_TYPE_TLI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_function_decl
specifier|extern
name|int
name|register_autofs_service
parameter_list|(
name|char
modifier|*
name|autofs_conftype
parameter_list|,
name|void
function_decl|(
modifier|*
name|autofs_dispatch
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|,
name|SVCXPRT
modifier|*
name|xprt
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unregister_autofs_service
parameter_list|(
name|char
modifier|*
name|autofs_conftype
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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_FHSTATUS_FHS_FH
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
comment|/* not HAVE_STRUCT_FHSTATUS_FHS_FH */
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
value|(~(D_MTAB|D_HRTIME|D_XDRTRACE|D_DAEMON|D_FORK|D_AMQ))
end_define

begin_define
define|#
directive|define
name|D_DAEMON
value|0x0001
end_define

begin_comment
comment|/* Don't enter daemon mode */
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
comment|/* Don't register amq program */
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
name|D_MEM
value|0x0000
end_define

begin_comment
comment|/* Dummy */
end_comment

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
name|D_FORK
value|0x0080
end_define

begin_comment
comment|/* Don't fork server */
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

begin_define
define|#
directive|define
name|D_HRTIME
value|0x0200
end_define

begin_comment
comment|/* Print high resolution time stamps */
end_comment

begin_define
define|#
directive|define
name|D_XDRTRACE
value|0x0400
end_define

begin_comment
comment|/* Trace xdr routines */
end_comment

begin_define
define|#
directive|define
name|D_READDIR
value|0x0800
end_define

begin_comment
comment|/* Show browsable_dir progress */
end_comment

begin_comment
comment|/*  * Test mode is test mode: don't daemonize, don't register amq, don't fork,  * don't touch system mtab, etc.  */
end_comment

begin_define
define|#
directive|define
name|D_TEST
value|(~(D_MEM|D_STR|D_XDRTRACE))
end_define

begin_define
define|#
directive|define
name|amuDebug
parameter_list|(
name|x
parameter_list|)
value|(debug_flags& (x))
end_define

begin_define
define|#
directive|define
name|dlog
value|if (amuDebug(D_FULL)) dplog
end_define

begin_comment
comment|/* my favorite debugging tool -Erez */
end_comment

begin_define
define|#
directive|define
name|EZKDBG
value|plog(XLOG_INFO,"EZK:%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__)
end_define

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

begin_function_decl
specifier|extern
name|void
name|dplog
parameter_list|(
specifier|const
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG */
end_comment

begin_comment
comment|/*  * If not debugging, then also reset the pointer.  * It's safer -- and besides, free() should do that anyway.  */
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

begin_define
define|#
directive|define
name|amuDebug
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|dlog
parameter_list|(
name|fmt
modifier|...
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __GNUC__ */
end_comment

begin_comment
comment|/* this define means that we CCP leaves code behind the (list,of,args)  */
end_comment

begin_define
define|#
directive|define
name|dlog
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|print_nfs_args
parameter_list|(
name|nap
parameter_list|,
name|nfs_version
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_option
parameter_list|(
name|x
parameter_list|)
value|(1)
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

begin_decl_stmt
specifier|extern
name|struct
name|opt_tab
name|dbg_opt
index|[]
decl_stmt|;
end_decl_stmt

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

