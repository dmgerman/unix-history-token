begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)am.h	5.6 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/*  * Global declarations  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|"nfs_prot.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MNTENT_HDR
end_ifdef

begin_include
include|#
directive|include
include|MNTENT_HDR
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNTENT_HDR */
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEM
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

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
comment|/* MAXHOSTNAMELEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNTTYPE_AUTO
end_ifndef

begin_define
define|#
directive|define
name|MNTTYPE_AUTO
value|"auto"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNTTYPE_AUTO */
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
comment|/* FALSE */
end_comment

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
comment|/* ROOT_MAP */
end_comment

begin_comment
comment|/*  * Flags from command line  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|print_pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print pid to stdout */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|normalize_hosts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Normalize host names before use */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|restart_existing_mounts
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_NIS_MAPS
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|domain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NIS domain to use */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_NIS_MAPS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|am_timeo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cache period */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|afs_timeo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AFS timeout */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|afs_retrans
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AFS retrans */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|am_timeo_w
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unmount timeout */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mount table */
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
name|int
name|immediate_abort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should close-down unmounts be retried */
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

begin_comment
comment|/*  * Useful constants  */
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
modifier|*
name|op_sys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "sos4" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|arch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "sun4" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|karch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "sun4c" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cluster
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "r+d-kluster" */
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
name|auto_dir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "/a" */
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
name|am_opts
name|am_opts
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
name|fserver
name|fserver
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fsrvinfo
name|fsrvinfo
typedef|;
end_typedef

begin_comment
comment|/*  * Debug defns.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DEBUG_MTAB
value|"./mtab"
end_define

begin_decl_stmt
specifier|extern
name|int
name|debug_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug options */
end_comment

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

begin_define
define|#
directive|define
name|D_MEM
value|0x0040
end_define

begin_comment
comment|/* Trace memory allocations */
end_comment

begin_comment
comment|/*  * Normally, don't enter daemon mode, and don't register amq  */
end_comment

begin_define
define|#
directive|define
name|D_TEST
value|(~(D_DAEMON|D_MEM|D_STR))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*  * Global variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|nfs_port
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our NFS service port */
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
name|int
name|foreground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Foreground process */
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
name|int
name|task_notify_todo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Task notifier needs running */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_TFS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|nfs_server_code_available
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_TFS */
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
name|AUTH
modifier|*
name|nfs_auth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dummy uthorisation for remote servers */
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
name|int
name|first_free_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First free node */
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
name|wire
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of primary connected network */
end_comment

begin_define
define|#
directive|define
name|NEXP_AP
value|(254)
end_define

begin_define
define|#
directive|define
name|NEXP_AP_MARGIN
value|(128)
end_define

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*task_fun
argument_list|)
name|P
argument_list|(
operator|(
name|voidp
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*cb_fun
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|voidp
operator|)
argument_list|)
expr_stmt|;
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
name|FSTREQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|((*(s1) == *(s2))&& STREQ((s1),(s2)))
end_define

begin_comment
comment|/*  * Linked list  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|qelem
name|qelem
typedef|;
end_typedef

begin_struct
struct|struct
name|qelem
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

begin_define
define|#
directive|define
name|FIRST
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
name|LAST
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
value|for ((v) = FIRST(ty,(q)); (v) != HEAD(ty,(q)); (v) = NEXT(ty,(v)))
end_define

begin_comment
comment|/*  * List of mount table entries  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mntlist
name|mntlist
typedef|;
end_typedef

begin_struct
struct|struct
name|mntlist
block|{
name|struct
name|mntlist
modifier|*
name|mnext
decl_stmt|;
name|struct
name|mntent
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
comment|/*  * Global routines  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atoi
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|am_mounted
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|am_unmounted
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|background
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|bind_resv_port
name|P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
name|short
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compute_mount_flags
name|P
argument_list|(
operator|(
expr|struct
name|mntent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|softclock
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug_option
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deslashify
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*extern void domain_strip P((char*, char*));*/
end_comment

begin_decl_stmt
specifier|extern
name|mntfs
modifier|*
name|dup_mntfs
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fserver
modifier|*
name|dup_srvr
name|P
argument_list|(
operator|(
name|fserver
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|eval_fs_opts
name|P
argument_list|(
operator|(
name|am_opts
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|expand_key
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|am_node
modifier|*
name|exported_ap_alloc
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|find_ap
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|find_mf
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mntfs
modifier|*
name|find_mntfs
name|P
argument_list|(
operator|(
name|am_ops
operator|*
operator|,
name|am_opts
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|flush_mntfs
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|flush_nfs_fhandle_cache
name|P
argument_list|(
operator|(
name|fserver
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|forcibly_timeout_mp
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FREE_RETURN_TYPE
name|free
name|P
argument_list|(
operator|(
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|free_mntfs
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_opts
name|P
argument_list|(
operator|(
name|am_opts
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_map
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_mntlist
name|P
argument_list|(
operator|(
name|mntlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_srvr
name|P
argument_list|(
operator|(
name|fserver
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|fwd_init
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|fwd_packet
name|P
argument_list|(
operator|(
name|int
operator|,
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
name|fwd_fun
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|fwd_reply
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|get_args
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getwire
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_MNTOPT_PARSER
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hasmntopt
name|P
argument_list|(
operator|(
expr|struct
name|mntent
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_MNTOPT_PARSER */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hasmntval
name|P
argument_list|(
operator|(
expr|struct
name|mntent
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|host_normalize
name|P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inet_dquad
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_map
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|insert_am
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|am_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ins_que
name|P
argument_list|(
operator|(
name|qelem
operator|*
operator|,
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|islocalnet
name|P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|make_nfs_auth
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|make_root_node
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|make_rpc_packet
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|u_long
operator|,
expr|struct
name|rpc_msg
operator|*
operator|,
name|voidp
operator|,
name|xdrproc_t
operator|,
name|AUTH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|map_flush_srvr
name|P
argument_list|(
operator|(
name|fserver
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mapc_add_kv
name|P
argument_list|(
operator|(
name|mnt_map
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mnt_map
modifier|*
name|mapc_find
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mapc_free
name|P
argument_list|(
operator|(
name|mnt_map
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mapc_keyiter
name|P
argument_list|(
operator|(
name|mnt_map
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|,
name|voidp
argument_list|)
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mapc_search
name|P
argument_list|(
operator|(
name|mnt_map
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|mapc_reload
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|mapc_showtypes
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mkdirs
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mk_fattr
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
expr|enum
name|ftype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mnt_free
name|P
argument_list|(
operator|(
expr|struct
name|mntent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mount_auto_node
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mount_automounter
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|mount_exported
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|mount_fs
name|P
argument_list|(
operator|(
expr|struct
name|mntent
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|,
name|MTYPE_TYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*extern int mount_nfs_fh P((struct fhstatus*, char*, char*, char*, mntfs*));*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mount_node
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|mntfs
modifier|*
name|new_mntfs
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|new_ttl
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|next_map
name|P
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfs_srvr_port
name|P
argument_list|(
operator|(
name|fserver
operator|*
operator|,
name|u_short
operator|*
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|normalize_slash
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ops_showfstypes
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pickup_rpc_reply
name|P
argument_list|(
operator|(
name|voidp
operator|,
name|int
operator|,
name|voidp
operator|,
name|xdrproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mntlist
modifier|*
name|read_mtab
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mntfs
modifier|*
name|realloc_mntfs
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|,
name|am_ops
operator|*
operator|,
name|am_opts
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rem_que
name|P
argument_list|(
operator|(
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|reschedule_timeout_mp
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restart
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|UPDATE_MTAB
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|rewrite_mtab
name|P
argument_list|(
operator|(
name|mntlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UPDATE_MTAB */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|rmdirs
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|root_ap
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|root_keyiter
name|P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|,
name|voidp
argument_list|)
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|root_newmap
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rpc_msg_init
name|P
argument_list|(
operator|(
expr|struct
name|rpc_msg
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|run_task
name|P
argument_list|(
operator|(
name|task_fun
operator|,
name|voidp
operator|,
name|cb_fun
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sched_task
name|P
argument_list|(
operator|(
name|cb_fun
operator|,
name|voidp
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|show_rcs_info
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sigchld
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|srvrlog
name|P
argument_list|(
operator|(
name|fserver
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|str3cat
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcat
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strcmp
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|,
name|Const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strlen
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strnsave
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strrchr
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strealloc
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|strsplit
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|switch_option
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|switch_to_logfile
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|do_task_notify
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|timeout
name|P
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|void
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|()
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|timeout_mp
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|umount_exported
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|umount_fs
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*extern int unmount_node P((am_node*)); extern int unmount_node_wrap P((voidp));*/
end_comment

begin_function_decl
specifier|extern
name|void
name|unregister_amq
parameter_list|(
name|P_void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|untimeout
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|valid_key
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wakeup
name|P
argument_list|(
operator|(
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wakeup_task
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|voidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wakeup_srvr
name|P
argument_list|(
operator|(
name|fserver
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_mntent
name|P
argument_list|(
operator|(
expr|struct
name|mntent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|UPDATE_MTAB
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|unlock_mntlist
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|unlock_mntlist
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UPDATE_MTAB */
end_comment

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|ty
parameter_list|)
value|((struct ty *) xmalloc(sizeof(struct ty)))
end_define

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
name|opt_unmount
decl_stmt|;
name|char
modifier|*
name|opt_user
decl_stmt|;
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

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|fh_to_mp
name|P
argument_list|(
operator|(
name|nfs_fh
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|fh_to_mp3
name|P
argument_list|(
operator|(
name|nfs_fh
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mp_to_fh
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|nfs_fh
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|auto_fmount
name|P
argument_list|(
operator|(
name|am_node
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auto_fumount
name|P
argument_list|(
operator|(
name|am_node
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_READDIR_ENTRIES
value|16
end_define

begin_typedef
typedef|typedef
name|char
operator|*
operator|(
operator|*
name|vfs_match
operator|)
name|P
argument_list|(
operator|(
name|am_opts
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*vfs_init
argument_list|)
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*vmount_fs
argument_list|)
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*vfmount_fs
argument_list|)
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*vumount_fs
argument_list|)
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*vfumount_fs
argument_list|)
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|am_node
operator|*
operator|(
operator|*
name|vlookuppn
operator|)
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*vreaddir
argument_list|)
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|nfscookie
operator|,
name|dirlist
operator|*
operator|,
name|entry
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|am_node
operator|*
operator|(
operator|*
name|vreadlink
operator|)
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*vmounted
argument_list|)
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*vumounted
argument_list|)
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|fserver
operator|*
operator|(
operator|*
name|vffserver
operator|)
name|P
argument_list|(
operator|(
name|mntfs
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|am_ops
block|{
name|char
modifier|*
name|fs_type
decl_stmt|;
name|vfs_match
name|fs_match
decl_stmt|;
name|vfs_init
name|fs_init
decl_stmt|;
name|vmount_fs
name|mount_fs
decl_stmt|;
name|vfmount_fs
name|fmount_fs
decl_stmt|;
name|vumount_fs
name|umount_fs
decl_stmt|;
name|vfumount_fs
name|fumount_fs
decl_stmt|;
name|vlookuppn
name|lookuppn
decl_stmt|;
name|vreaddir
name|readdir
decl_stmt|;
name|vreadlink
name|readlink
decl_stmt|;
name|vmounted
name|mounted
decl_stmt|;
name|vumounted
name|umounted
decl_stmt|;
name|vffserver
name|ffserver
decl_stmt|;
name|int
name|fs_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|am_node
modifier|*
name|efs_lookuppn
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|efs_readdir
name|P
argument_list|(
operator|(
name|am_node
operator|*
operator|,
name|nfscookie
operator|,
name|dirlist
operator|*
operator|,
name|entry
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4_COMPAT
end_ifdef

begin_decl_stmt
specifier|extern
name|am_ops
modifier|*
name|sunos4_match
name|P
argument_list|(
operator|(
name|am_opts
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4_COMPAT */
end_comment

begin_decl_stmt
specifier|extern
name|am_ops
modifier|*
name|ops_match
name|P
argument_list|(
operator|(
name|am_opts
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"fstype.h"
end_include

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
comment|/* Succesful mounts */
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
name|voidp
name|fs_private
decl_stmt|;
comment|/* Private data */
name|void
function_decl|(
modifier|*
name|fs_prfree
function_decl|)
parameter_list|()
function_decl|;
comment|/* Free private data */
block|}
struct|;
end_struct

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
comment|/* Permanent error has occured */
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
comment|/* Flags */
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
parameter_list|()
function_decl|;
comment|/* Free private space */
name|voidp
name|mf_private
decl_stmt|;
comment|/* Private - per-fs data */
block|}
struct|;
end_struct

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
comment|/* "kiska" 					   Name of this node */
name|char
modifier|*
name|am_path
decl_stmt|;
comment|/* "/home/kiska" 					   Path of this node's mount point */
name|char
modifier|*
name|am_link
decl_stmt|;
comment|/* "/a/kiska/home/kiska/this/that" 					   Link to sub-directory */
name|am_node
modifier|*
name|am_parent
decl_stmt|,
comment|/* Parent of this node */
modifier|*
name|am_ysib
decl_stmt|,
comment|/* Younger sibling of this node */
modifier|*
name|am_osib
decl_stmt|,
comment|/* Older sibling of this node */
modifier|*
name|am_child
decl_stmt|;
comment|/* First child of this node */
name|struct
name|attrstat
name|am_attr
decl_stmt|;
comment|/* File attributes */
define|#
directive|define
name|am_fattr
value|am_attr.attrstat_u.attributes
name|int
name|am_flags
decl_stmt|;
comment|/* Boolean flags */
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
name|unsigned
name|int
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
block|}
struct|;
end_struct

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
name|ONE_HOUR
value|(60 * 60)
end_define

begin_comment
comment|/* One hour in seconds */
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
name|AFS_TIMEO
value|8
end_define

begin_comment
comment|/* Default afs timeout - .8s */
end_comment

begin_define
define|#
directive|define
name|AFS_RETRANS
value|((ALLOWED_MOUNT_TIME*10+5*afs_timeo)/afs_timeo * 2)
end_define

begin_comment
comment|/* Default afs retrans - 1/10th seconds */
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

end_unit

