begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996, 2010, Oracle and/or its affiliates. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CPUPART_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CPUPART_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/processor.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpuvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/disp.h>
end_include

begin_include
include|#
directive|include
file|<sys/pset.h>
end_include

begin_include
include|#
directive|include
file|<sys/lgrp.h>
end_include

begin_include
include|#
directive|include
file|<sys/lgrp_user.h>
end_include

begin_include
include|#
directive|include
file|<sys/pg.h>
end_include

begin_include
include|#
directive|include
file|<sys/bitset.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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
ifdef|#
directive|ifdef
name|_KERNEL
typedef|typedef
name|int
name|cpupartid_t
typedef|;
comment|/*  * Special partition id.  */
define|#
directive|define
name|CP_DEFAULT
value|0
comment|/*  * Flags for cpupart_list()  */
define|#
directive|define
name|CP_ALL
value|0
comment|/* return all cpu partitions */
define|#
directive|define
name|CP_NONEMPTY
value|1
comment|/* return only non-empty ones */
typedef|typedef
struct|struct
name|cpupart
block|{
name|disp_t
name|cp_kp_queue
decl_stmt|;
comment|/* partition-wide kpreempt queue */
name|cpupartid_t
name|cp_id
decl_stmt|;
comment|/* partition ID */
name|int
name|cp_ncpus
decl_stmt|;
comment|/* number of online processors */
name|struct
name|cpupart
modifier|*
name|cp_next
decl_stmt|;
comment|/* next partition in list */
name|struct
name|cpupart
modifier|*
name|cp_prev
decl_stmt|;
comment|/* previous partition in list */
name|struct
name|cpu
modifier|*
name|cp_cpulist
decl_stmt|;
comment|/* processor list */
name|struct
name|kstat
modifier|*
name|cp_kstat
decl_stmt|;
comment|/* per-partition statistics */
comment|/* 	 * cp_nrunnable and cp_nrunning are used to calculate load average. 	 */
name|uint_t
name|cp_nrunnable
decl_stmt|;
comment|/* current # of runnable threads */
name|uint_t
name|cp_nrunning
decl_stmt|;
comment|/* current # of running threads */
comment|/* 	 * cp_updates, cp_nrunnable_cum, cp_nwaiting_cum, and cp_hp_avenrun 	 * are used to generate kstat information on an as-needed basis. 	 */
name|uint64_t
name|cp_updates
decl_stmt|;
comment|/* number of statistics updates */
name|uint64_t
name|cp_nrunnable_cum
decl_stmt|;
comment|/* cum. # of runnable threads */
name|uint64_t
name|cp_nwaiting_cum
decl_stmt|;
comment|/* cum. # of waiting threads */
name|struct
name|loadavg_s
name|cp_loadavg
decl_stmt|;
comment|/* cpupart loadavg */
name|klgrpset_t
name|cp_lgrpset
decl_stmt|;
comment|/* set of lgroups on which this */
comment|/*    partition has cpus */
name|lpl_t
modifier|*
name|cp_lgrploads
decl_stmt|;
comment|/* table of load averages for this  */
comment|/*    partition, indexed by lgrp ID */
name|int
name|cp_nlgrploads
decl_stmt|;
comment|/* size of cp_lgrploads table */
name|uint64_t
name|cp_hp_avenrun
index|[
literal|3
index|]
decl_stmt|;
comment|/* high-precision load average */
name|uint_t
name|cp_attr
decl_stmt|;
comment|/* bitmask of attributes */
name|lgrp_gen_t
name|cp_gen
decl_stmt|;
comment|/* generation number */
name|lgrp_id_t
name|cp_lgrp_hint
decl_stmt|;
comment|/* last home lgroup chosen */
name|bitset_t
name|cp_cmt_pgs
decl_stmt|;
comment|/* CMT PGs represented */
name|bitset_t
name|cp_haltset
decl_stmt|;
comment|/* halted CPUs */
block|}
name|cpupart_t
typedef|;
typedef|typedef
struct|struct
name|cpupart_kstat
block|{
name|kstat_named_t
name|cpk_updates
decl_stmt|;
comment|/* number of updates */
name|kstat_named_t
name|cpk_runnable
decl_stmt|;
comment|/* cum # of runnable threads */
name|kstat_named_t
name|cpk_waiting
decl_stmt|;
comment|/* cum # waiting for I/O */
name|kstat_named_t
name|cpk_ncpus
decl_stmt|;
comment|/* current # of CPUs */
name|kstat_named_t
name|cpk_avenrun_1min
decl_stmt|;
comment|/* 1-minute load average */
name|kstat_named_t
name|cpk_avenrun_5min
decl_stmt|;
comment|/* 5-minute load average */
name|kstat_named_t
name|cpk_avenrun_15min
decl_stmt|;
comment|/* 15-minute load average */
block|}
name|cpupart_kstat_t
typedef|;
comment|/*  * Macro to obtain the maximum run priority for the global queue associated  * with given cpu partition.  */
define|#
directive|define
name|CP_MAXRUNPRI
parameter_list|(
name|cp
parameter_list|)
value|((cp)->cp_kp_queue.disp_maxrunpri)
comment|/*  * This macro is used to determine if the given thread must surrender  * CPU to higher priority runnable threads on one of its dispatch queues.  * This should really be defined in<sys/disp.h> but it is not because  * including<sys/cpupart.h> there would cause recursive includes.  */
define|#
directive|define
name|DISP_MUST_SURRENDER
parameter_list|(
name|t
parameter_list|)
define|\
value|((DISP_MAXRUNPRI(t)> DISP_PRIO(t)) ||		\ 	(CP_MAXRUNPRI(t->t_cpupart)> DISP_PRIO(t)))
specifier|extern
name|cpupart_t
name|cp_default
decl_stmt|;
specifier|extern
name|cpupart_t
modifier|*
name|cp_list_head
decl_stmt|;
specifier|extern
name|uint_t
name|cp_numparts
decl_stmt|;
specifier|extern
name|uint_t
name|cp_numparts_nonempty
decl_stmt|;
comment|/*  * Each partition contains a bitset that indicates which CPUs are halted and  * which ones are running. Given the growing number of CPUs in current and  * future platforms, it's important to fanout each CPU within its partition's  * haltset to prevent contention due to false sharing. The fanout factor  * is platform specific, and declared accordingly.  */
specifier|extern
name|uint_t
name|cp_haltset_fanout
decl_stmt|;
specifier|extern
name|void
name|cpupart_initialize_default
parameter_list|()
function_decl|;
specifier|extern
name|cpupart_t
modifier|*
name|cpupart_find
parameter_list|(
name|psetid_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_create
parameter_list|(
name|psetid_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_destroy
parameter_list|(
name|psetid_t
parameter_list|)
function_decl|;
specifier|extern
name|psetid_t
name|cpupart_query_cpu
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_attach_cpu
parameter_list|(
name|psetid_t
parameter_list|,
name|cpu_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_get_cpus
parameter_list|(
name|psetid_t
modifier|*
parameter_list|,
name|processorid_t
modifier|*
parameter_list|,
name|uint_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_bind_thread
parameter_list|(
name|kthread_id_t
parameter_list|,
name|psetid_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpupart_kpqalloc
parameter_list|(
name|pri_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_get_loadavg
parameter_list|(
name|psetid_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|cpupart_list
parameter_list|(
name|psetid_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_setattr
parameter_list|(
name|psetid_t
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpupart_getattr
parameter_list|(
name|psetid_t
parameter_list|,
name|uint_t
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
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
comment|/* _SYS_CPUPART_H */
end_comment

end_unit

