begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amd.h,v 1.4 1999/09/30 21:01:29 ezk Exp $  *  */
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
comment|/* options for amd.conf */
end_comment

begin_define
define|#
directive|define
name|CFM_BROWSABLE_DIRS
value|0x0001
end_define

begin_define
define|#
directive|define
name|CFM_MOUNT_TYPE_AUTOFS
value|0x0002
end_define

begin_define
define|#
directive|define
name|CFM_ENABLE_DEFAULT_SELECTORS
value|0x0004
end_define

begin_define
define|#
directive|define
name|CFM_NORMALIZE_HOSTNAMES
value|0x0008
end_define

begin_define
define|#
directive|define
name|CFM_PROCESS_LOCK
value|0x0010
end_define

begin_define
define|#
directive|define
name|CFM_PRINT_PID
value|0x0020
end_define

begin_define
define|#
directive|define
name|CFM_RESTART_EXISTING_MOUNTS
value|0x0040
end_define

begin_define
define|#
directive|define
name|CFM_SHOW_STATFS_ENTRIES
value|0x0080
end_define

begin_define
define|#
directive|define
name|CFM_FULLY_QUALIFIED_HOSTS
value|0x0100
end_define

begin_define
define|#
directive|define
name|CFM_BROWSABLE_DIRS_FULL
value|0x0200
end_define

begin_comment
comment|/* allow '/' in readdir() */
end_comment

begin_define
define|#
directive|define
name|CFM_UNMOUNT_ON_EXIT
value|0x0400
end_define

begin_comment
comment|/* when amd finishing */
end_comment

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
comment|/* interval between forced retries of a mount */
end_comment

begin_define
define|#
directive|define
name|RETRY_INTERVAL
value|2
end_define

begin_define
define|#
directive|define
name|ereturn
parameter_list|(
name|x
parameter_list|)
value|{ *error_return = x; return 0; }
end_define

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
name|map_options
decl_stmt|;
comment|/* global map options */
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
name|u_int
name|flags
decl_stmt|;
comment|/* various CFM_* flags */
name|int
name|amfs_auto_retrans
decl_stmt|;
comment|/* NFS retransmit counter */
name|int
name|amfs_auto_timeo
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
name|int
name|portmap_program
decl_stmt|;
comment|/* amd RPC program number */
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
comment|/* options available via amd conf file */
name|char
modifier|*
name|cf_map_type
decl_stmt|;
comment|/* file, hesiod, ndbm, nis, etc. */
name|char
modifier|*
name|cf_search_path
decl_stmt|;
comment|/* /etc/local:/etc/amdmaps:/misc/yp */
name|void
modifier|*
name|map_data
decl_stmt|;
comment|/* Map data black box */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mounting a file system may take a significant period of time.  The  * problem is that if this is done in the main process thread then the  * entire automounter could be blocked, possibly hanging lots of processes  * on the system.  Instead we use a continuation scheme to allow mounts to  * be attempted in a sub-process.  When the sub-process exits we pick up the  * exit status (by convention a UN*X error number) and continue in a  * notifier.  The notifier gets handed a data structure and can then  * determine whether the mount was successful or not.  If not, it updates  * the data structure and tries again until there are no more ways to try  * the mount, or some other permanent error occurs.  In the mean time no RPC  * reply is sent, even after the mount is successful.  We rely on the RPC  * retry mechanism to resend the lookup request which can then be handled.  */
end_comment

begin_struct
struct|struct
name|continuation
block|{
name|char
modifier|*
modifier|*
name|ivec
decl_stmt|;
comment|/* Current mount info */
name|am_node
modifier|*
name|mp
decl_stmt|;
comment|/* Node we are trying to mount */
name|char
modifier|*
name|key
decl_stmt|;
comment|/* Map key */
name|char
modifier|*
name|info
decl_stmt|;
comment|/* Info string */
name|char
modifier|*
modifier|*
name|xivec
decl_stmt|;
comment|/* Saved strsplit vector */
name|char
modifier|*
name|auto_opts
decl_stmt|;
comment|/* Automount options */
name|am_opts
name|fs_opts
decl_stmt|;
comment|/* Filesystem options */
name|char
modifier|*
name|def_opts
decl_stmt|;
comment|/* Default automount options */
name|int
name|retry
decl_stmt|;
comment|/* Try again? */
name|int
name|tried
decl_stmt|;
comment|/* Have we tried any yet? */
name|time_t
name|start
decl_stmt|;
comment|/* Time we started this mount */
name|int
name|callout
decl_stmt|;
comment|/* Callout identifier */
block|}
struct|;
end_struct

begin_comment
comment|/*  * EXTERNALS:  */
end_comment

begin_comment
comment|/* Amq server global functions */
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
name|root_fh
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
name|autofs_lookuppn
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
name|find_ap2
parameter_list|(
name|char
modifier|*
parameter_list|,
name|am_node
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
name|auto_fmount
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
name|auto_fumount
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
name|mount_nfs_fh
parameter_list|(
name|am_nfs_handle_t
modifier|*
name|fhp
parameter_list|,
name|char
modifier|*
name|dir
parameter_list|,
name|char
modifier|*
name|fs_name
parameter_list|,
name|char
modifier|*
name|opts
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
name|process_last_regular_map
parameter_list|(
name|void
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
name|try_mount
parameter_list|(
name|voidp
name|mvp
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
name|nfsentry
modifier|*
name|make_entry_chain
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
specifier|const
name|nfsentry
modifier|*
name|current_chain
parameter_list|,
name|int
name|fully_browsable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amfs_auto_cont
parameter_list|(
name|int
name|rc
parameter_list|,
name|int
name|term
parameter_list|,
name|voidp
name|closure
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amfs_auto_mkcacheref
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
name|amfs_auto_retry
parameter_list|(
name|int
name|rc
parameter_list|,
name|int
name|term
parameter_list|,
name|voidp
name|closure
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
name|void
name|flush_srvr_nfs_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_continuation
parameter_list|(
name|struct
name|continuation
modifier|*
name|cp
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|quick_reply
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

begin_comment
comment|/* amd global variables */
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
name|nfs_program_2_transp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For quick_reply() */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|conf_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|NumChild
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
name|HAVE_AM_FS_LINK
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_AM_FS_LINKX
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

begin_function_decl
specifier|extern
name|int
name|amfs_link_fumount
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
comment|/* defined(HAVE_AM_FS_LINK) || defined(HAVE_AM_FS_LINKX) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AM_FS_NFSL
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|nfs_match
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
comment|/* HAVE_AM_FS_NFSL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FS_NFS3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_XDR_MOUNTRES3
argument_list|)
end_if

begin_function_decl
specifier|extern
name|bool_t
name|xdr_mountres3
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|mountres3
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_FS_NFS3)&& !defined(HAVE_XDR_MOUNTRES3) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|autofsxprt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|autofs_port
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|amd_use_autofs
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|autofs_mount
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
name|autofs_umount
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
name|create_autofs_service
parameter_list|(
name|int
modifier|*
name|soAUTOFSp
parameter_list|,
name|u_short
modifier|*
name|autofs_portp
parameter_list|,
name|SVCXPRT
modifier|*
modifier|*
name|autofs_xprtp
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
name|svc_create_local_service
parameter_list|(
name|void
function_decl|(
modifier|*
name|dispatch
function_decl|)
parameter_list|()
parameter_list|,
name|u_long
name|prognum
parameter_list|,
name|u_long
name|versnum
parameter_list|,
name|char
modifier|*
name|nettype
parameter_list|,
name|char
modifier|*
name|servname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|autofs_mounted
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
name|autofs_program_1
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_AUTOFS */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMD_H */
end_comment

end_unit

