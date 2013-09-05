begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_PROC_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_PROC_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<libproc.h>
end_include

begin_include
include|#
directive|include
file|<dtrace.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<dt_list.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
struct|struct
name|dt_proc
block|{
name|dt_list_t
name|dpr_list
decl_stmt|;
comment|/* prev/next pointers for lru chain */
name|struct
name|dt_proc
modifier|*
name|dpr_hash
decl_stmt|;
comment|/* next pointer for pid hash chain */
name|dtrace_hdl_t
modifier|*
name|dpr_hdl
decl_stmt|;
comment|/* back pointer to libdtrace handle */
name|struct
name|ps_prochandle
modifier|*
name|dpr_proc
decl_stmt|;
comment|/* proc handle for libproc calls */
name|char
name|dpr_errmsg
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* error message */
name|rd_agent_t
modifier|*
name|dpr_rtld
decl_stmt|;
comment|/* rtld handle for librtld_db calls */
name|pthread_mutex_t
name|dpr_lock
decl_stmt|;
comment|/* lock for manipulating dpr_hdl */
name|pthread_cond_t
name|dpr_cv
decl_stmt|;
comment|/* cond for dpr_stop/quit/done */
name|pid_t
name|dpr_pid
decl_stmt|;
comment|/* pid of process */
name|uint_t
name|dpr_refs
decl_stmt|;
comment|/* reference count */
name|uint8_t
name|dpr_cacheable
decl_stmt|;
comment|/* cache handle using lru list */
name|uint8_t
name|dpr_stop
decl_stmt|;
comment|/* stop mask: see flag bits below */
name|uint8_t
name|dpr_quit
decl_stmt|;
comment|/* quit flag: ctl thread should quit */
name|uint8_t
name|dpr_done
decl_stmt|;
comment|/* done flag: ctl thread has exited */
name|uint8_t
name|dpr_usdt
decl_stmt|;
comment|/* usdt flag: usdt initialized */
name|uint8_t
name|dpr_stale
decl_stmt|;
comment|/* proc flag: been deprecated */
name|uint8_t
name|dpr_rdonly
decl_stmt|;
comment|/* proc flag: opened read-only */
name|pthread_t
name|dpr_tid
decl_stmt|;
comment|/* control thread (or zero if none) */
name|dt_list_t
name|dpr_bps
decl_stmt|;
comment|/* list of dt_bkpt_t structures */
block|}
name|dt_proc_t
typedef|;
typedef|typedef
struct|struct
name|dt_proc_notify
block|{
name|dt_proc_t
modifier|*
name|dprn_dpr
decl_stmt|;
comment|/* process associated with the event */
name|char
name|dprn_errmsg
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* error message */
name|struct
name|dt_proc_notify
modifier|*
name|dprn_next
decl_stmt|;
comment|/* next pointer */
block|}
name|dt_proc_notify_t
typedef|;
define|#
directive|define
name|DT_PROC_STOP_IDLE
value|0x01
comment|/* idle on owner's stop request */
define|#
directive|define
name|DT_PROC_STOP_CREATE
value|0x02
comment|/* wait on dpr_cv at process exec */
define|#
directive|define
name|DT_PROC_STOP_GRAB
value|0x04
comment|/* wait on dpr_cv at process grab */
define|#
directive|define
name|DT_PROC_STOP_PREINIT
value|0x08
comment|/* wait on dpr_cv at rtld preinit */
define|#
directive|define
name|DT_PROC_STOP_POSTINIT
value|0x10
comment|/* wait on dpr_cv at rtld postinit */
define|#
directive|define
name|DT_PROC_STOP_MAIN
value|0x20
comment|/* wait on dpr_cv at a.out`main() */
typedef|typedef
name|void
name|dt_bkpt_f
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_proc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|dt_bkpt
block|{
name|dt_list_t
name|dbp_list
decl_stmt|;
comment|/* prev/next pointers for bkpt list */
name|dt_bkpt_f
modifier|*
name|dbp_func
decl_stmt|;
comment|/* callback function to execute */
name|void
modifier|*
name|dbp_data
decl_stmt|;
comment|/* callback function private data */
name|uintptr_t
name|dbp_addr
decl_stmt|;
comment|/* virtual address of breakpoint */
name|ulong_t
name|dbp_instr
decl_stmt|;
comment|/* saved instruction from breakpoint */
name|ulong_t
name|dbp_hits
decl_stmt|;
comment|/* count of breakpoint hits for debug */
name|int
name|dbp_active
decl_stmt|;
comment|/* flag indicating breakpoint is on */
block|}
name|dt_bkpt_t
typedef|;
typedef|typedef
struct|struct
name|dt_proc_hash
block|{
name|pthread_mutex_t
name|dph_lock
decl_stmt|;
comment|/* lock protecting dph_notify list */
name|pthread_cond_t
name|dph_cv
decl_stmt|;
comment|/* cond for waiting for dph_notify */
name|dt_proc_notify_t
modifier|*
name|dph_notify
decl_stmt|;
comment|/* list of pending proc notifications */
name|dt_list_t
name|dph_lrulist
decl_stmt|;
comment|/* list of dt_proc_t's in lru order */
name|uint_t
name|dph_lrulim
decl_stmt|;
comment|/* limit on number of procs to hold */
name|uint_t
name|dph_lrucnt
decl_stmt|;
comment|/* count of cached process handles */
name|uint_t
name|dph_hashlen
decl_stmt|;
comment|/* size of hash chains array */
name|dt_proc_t
modifier|*
name|dph_hash
index|[
literal|1
index|]
decl_stmt|;
comment|/* hash chains array */
block|}
name|dt_proc_hash_t
typedef|;
specifier|extern
name|struct
name|ps_prochandle
modifier|*
name|dt_proc_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|proc_child_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|struct
name|ps_prochandle
modifier|*
name|dt_proc_grab
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|pid_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_proc_release
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|struct
name|ps_prochandle
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_proc_continue
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|struct
name|ps_prochandle
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_proc_lock
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|struct
name|ps_prochandle
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_proc_unlock
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|struct
name|ps_prochandle
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_proc_t
modifier|*
name|dt_proc_lookup
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|struct
name|ps_prochandle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_proc_hash_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_proc_hash_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_PROC_H */
end_comment

end_unit

