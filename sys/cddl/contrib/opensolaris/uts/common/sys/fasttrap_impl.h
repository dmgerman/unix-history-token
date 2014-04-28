begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FASTTRAP_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_FASTTRAP_IMPL_H
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/dtrace.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/fasttrap.h>
end_include

begin_include
include|#
directive|include
file|<sys/fasttrap_isa.h>
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
comment|/*  * Fasttrap Providers, Probes and Tracepoints  *  * Each Solaris process can have multiple providers -- the pid provider as  * well as any number of user-level statically defined tracing (USDT)  * providers. Those providers are each represented by a fasttrap_provider_t.  * All providers for a given process have a pointer to a shared  * fasttrap_proc_t. The fasttrap_proc_t has two states: active or defunct.  * When the count of active providers goes to zero it becomes defunct; a  * provider drops its active count when it is removed individually or as part  * of a mass removal when a process exits or performs an exec.  *  * Each probe is represented by a fasttrap_probe_t which has a pointer to  * its associated provider as well as a list of fasttrap_id_tp_t structures  * which are tuples combining a fasttrap_id_t and a fasttrap_tracepoint_t.  * A fasttrap_tracepoint_t represents the actual point of instrumentation  * and it contains two lists of fasttrap_id_t structures (to be fired pre-  * and post-instruction emulation) that identify the probes attached to the  * tracepoint. Tracepoints also have a pointer to the fasttrap_proc_t for the  * process they trace which is used when looking up a tracepoint both when a  * probe fires and when enabling and disabling probes.  *  * It's important to note that probes are preallocated with the necessary  * number of tracepoints, but that tracepoints can be shared by probes and  * swapped between probes. If a probe's preallocated tracepoint is enabled  * (and, therefore, the associated probe is enabled), and that probe is  * then disabled, ownership of that tracepoint may be exchanged for an  * unused tracepoint belonging to another probe that was attached to the  * enabled tracepoint.  *  * On FreeBSD, fasttrap providers also maintain per-thread scratch space for use  * by the ISA-specific fasttrap code. The fasttrap_scrblock_t type stores the  * virtual address of a page-sized memory block that is mapped into a process'  * address space. Each block is carved up into chunks (fasttrap_scrspace_t) for  * use by individual threads, which keep the address of their scratch space  * chunk in their struct kdtrace_thread. A thread's scratch space isn't released  * until it exits.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
typedef|typedef
struct|struct
name|fasttrap_scrblock
block|{
name|vm_offset_t
name|ftsb_addr
decl_stmt|;
comment|/* address of a scratch block */
name|LIST_ENTRY
argument_list|(
argument|fasttrap_scrblock
argument_list|)
name|ftsb_next
expr_stmt|;
comment|/* next block in list */
block|}
name|fasttrap_scrblock_t
typedef|;
define|#
directive|define
name|FASTTRAP_SCRBLOCK_SIZE
value|PAGE_SIZE
typedef|typedef
struct|struct
name|fasttrap_scrspace
block|{
name|uintptr_t
name|ftss_addr
decl_stmt|;
comment|/* scratch space address */
name|LIST_ENTRY
argument_list|(
argument|fasttrap_scrspace
argument_list|)
name|ftss_next
expr_stmt|;
comment|/* next in list */
block|}
name|fasttrap_scrspace_t
typedef|;
define|#
directive|define
name|FASTTRAP_SCRSPACE_SIZE
value|64
endif|#
directive|endif
typedef|typedef
struct|struct
name|fasttrap_proc
block|{
name|pid_t
name|ftpc_pid
decl_stmt|;
comment|/* process ID for this proc */
name|uint64_t
name|ftpc_acount
decl_stmt|;
comment|/* count of active providers */
name|uint64_t
name|ftpc_rcount
decl_stmt|;
comment|/* count of extant providers */
name|kmutex_t
name|ftpc_mtx
decl_stmt|;
comment|/* lock on all but acount */
name|struct
name|fasttrap_proc
modifier|*
name|ftpc_next
decl_stmt|;
comment|/* next proc in hash chain */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
name|LIST_HEAD
argument_list|(
argument_list|,
argument|fasttrap_scrblock
argument_list|)
name|ftpc_scrblks
expr_stmt|;
comment|/* mapped scratch blocks */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|fasttrap_scrspace
argument_list|)
name|ftpc_fscr
expr_stmt|;
comment|/* free scratch space */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|fasttrap_scrspace
argument_list|)
name|ftpc_ascr
expr_stmt|;
comment|/* used scratch space */
endif|#
directive|endif
block|}
name|fasttrap_proc_t
typedef|;
typedef|typedef
struct|struct
name|fasttrap_provider
block|{
name|pid_t
name|ftp_pid
decl_stmt|;
comment|/* process ID for this prov */
name|char
name|ftp_name
index|[
name|DTRACE_PROVNAMELEN
index|]
decl_stmt|;
comment|/* prov name (w/o the pid) */
name|dtrace_provider_id_t
name|ftp_provid
decl_stmt|;
comment|/* DTrace provider handle */
name|uint_t
name|ftp_marked
decl_stmt|;
comment|/* mark for possible removal */
name|uint_t
name|ftp_retired
decl_stmt|;
comment|/* mark when retired */
name|kmutex_t
name|ftp_mtx
decl_stmt|;
comment|/* provider lock */
name|kmutex_t
name|ftp_cmtx
decl_stmt|;
comment|/* lock on creating probes */
name|uint64_t
name|ftp_rcount
decl_stmt|;
comment|/* enabled probes ref count */
name|uint64_t
name|ftp_ccount
decl_stmt|;
comment|/* consumers creating probes */
name|uint64_t
name|ftp_mcount
decl_stmt|;
comment|/* meta provider count */
name|fasttrap_proc_t
modifier|*
name|ftp_proc
decl_stmt|;
comment|/* shared proc for all provs */
name|struct
name|fasttrap_provider
modifier|*
name|ftp_next
decl_stmt|;
comment|/* next prov in hash chain */
block|}
name|fasttrap_provider_t
typedef|;
typedef|typedef
name|struct
name|fasttrap_id
name|fasttrap_id_t
typedef|;
typedef|typedef
name|struct
name|fasttrap_probe
name|fasttrap_probe_t
typedef|;
typedef|typedef
name|struct
name|fasttrap_tracepoint
name|fasttrap_tracepoint_t
typedef|;
struct|struct
name|fasttrap_id
block|{
name|fasttrap_probe_t
modifier|*
name|fti_probe
decl_stmt|;
comment|/* referrring probe */
name|fasttrap_id_t
modifier|*
name|fti_next
decl_stmt|;
comment|/* enabled probe list on tp */
name|fasttrap_probe_type_t
name|fti_ptype
decl_stmt|;
comment|/* probe type */
block|}
struct|;
typedef|typedef
struct|struct
name|fasttrap_id_tp
block|{
name|fasttrap_id_t
name|fit_id
decl_stmt|;
name|fasttrap_tracepoint_t
modifier|*
name|fit_tp
decl_stmt|;
block|}
name|fasttrap_id_tp_t
typedef|;
struct|struct
name|fasttrap_probe
block|{
name|dtrace_id_t
name|ftp_id
decl_stmt|;
comment|/* DTrace probe identifier */
name|pid_t
name|ftp_pid
decl_stmt|;
comment|/* pid for this probe */
name|fasttrap_provider_t
modifier|*
name|ftp_prov
decl_stmt|;
comment|/* this probe's provider */
name|uintptr_t
name|ftp_faddr
decl_stmt|;
comment|/* associated function's addr */
name|size_t
name|ftp_fsize
decl_stmt|;
comment|/* associated function's size */
name|uint64_t
name|ftp_gen
decl_stmt|;
comment|/* modification generation */
name|uint64_t
name|ftp_ntps
decl_stmt|;
comment|/* number of tracepoints */
name|uint8_t
modifier|*
name|ftp_argmap
decl_stmt|;
comment|/* native to translated args */
name|uint8_t
name|ftp_nargs
decl_stmt|;
comment|/* translated argument count */
name|uint8_t
name|ftp_enabled
decl_stmt|;
comment|/* is this probe enabled */
name|char
modifier|*
name|ftp_xtypes
decl_stmt|;
comment|/* translated types index */
name|char
modifier|*
name|ftp_ntypes
decl_stmt|;
comment|/* native types index */
name|fasttrap_id_tp_t
name|ftp_tps
index|[
literal|1
index|]
decl_stmt|;
comment|/* flexible array */
block|}
struct|;
define|#
directive|define
name|FASTTRAP_ID_INDEX
parameter_list|(
name|id
parameter_list|)
define|\
value|((fasttrap_id_tp_t *)(((char *)(id) - offsetof(fasttrap_id_tp_t, fit_id))) - \&(id)->fti_probe->ftp_tps[0])
struct|struct
name|fasttrap_tracepoint
block|{
name|fasttrap_proc_t
modifier|*
name|ftt_proc
decl_stmt|;
comment|/* associated process struct */
name|uintptr_t
name|ftt_pc
decl_stmt|;
comment|/* address of tracepoint */
name|pid_t
name|ftt_pid
decl_stmt|;
comment|/* pid of tracepoint */
name|fasttrap_machtp_t
name|ftt_mtp
decl_stmt|;
comment|/* ISA-specific portion */
name|fasttrap_id_t
modifier|*
name|ftt_ids
decl_stmt|;
comment|/* NULL-terminated list */
name|fasttrap_id_t
modifier|*
name|ftt_retids
decl_stmt|;
comment|/* NULL-terminated list */
name|fasttrap_tracepoint_t
modifier|*
name|ftt_next
decl_stmt|;
comment|/* link in global hash */
block|}
struct|;
typedef|typedef
struct|struct
name|fasttrap_bucket
block|{
name|kmutex_t
name|ftb_mtx
decl_stmt|;
comment|/* bucket lock */
name|void
modifier|*
name|ftb_data
decl_stmt|;
comment|/* data payload */
name|uint8_t
name|ftb_pad
index|[
literal|64
operator|-
sizeof|sizeof
argument_list|(
name|kmutex_t
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
block|}
name|fasttrap_bucket_t
typedef|;
typedef|typedef
struct|struct
name|fasttrap_hash
block|{
name|ulong_t
name|fth_nent
decl_stmt|;
comment|/* power-of-2 num. of entries */
name|ulong_t
name|fth_mask
decl_stmt|;
comment|/* fth_nent - 1 */
name|fasttrap_bucket_t
modifier|*
name|fth_table
decl_stmt|;
comment|/* array of buckets */
block|}
name|fasttrap_hash_t
typedef|;
comment|/*  * If at some future point these assembly functions become observable by  * DTrace, then these defines should become separate functions so that the  * fasttrap provider doesn't trigger probes during internal operations.  */
define|#
directive|define
name|fasttrap_copyout
value|copyout
define|#
directive|define
name|fasttrap_fuword32
value|fuword32
define|#
directive|define
name|fasttrap_suword32
value|suword32
define|#
directive|define
name|fasttrap_suword64
value|suword64
ifdef|#
directive|ifdef
name|__amd64__
define|#
directive|define
name|fasttrap_fulword
value|fuword64
define|#
directive|define
name|fasttrap_sulword
value|suword64
else|#
directive|else
define|#
directive|define
name|fasttrap_fulword
value|fuword32
define|#
directive|define
name|fasttrap_sulword
value|suword32
endif|#
directive|endif
specifier|extern
name|void
name|fasttrap_sigtrap
parameter_list|(
name|proc_t
modifier|*
parameter_list|,
name|kthread_t
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
specifier|extern
name|fasttrap_scrspace_t
modifier|*
name|fasttrap_scraddr
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|fasttrap_proc_t
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|extern
name|dtrace_id_t
name|fasttrap_probe_id
decl_stmt|;
specifier|extern
name|fasttrap_hash_t
name|fasttrap_tpoints
decl_stmt|;
define|#
directive|define
name|FASTTRAP_TPOINTS_INDEX
parameter_list|(
name|pid
parameter_list|,
name|pc
parameter_list|)
define|\
value|(((pc) / sizeof (fasttrap_instr_t) + (pid))& fasttrap_tpoints.fth_mask)
comment|/*  * Must be implemented by fasttrap_isa.c  */
specifier|extern
name|int
name|fasttrap_tracepoint_init
parameter_list|(
name|proc_t
modifier|*
parameter_list|,
name|fasttrap_tracepoint_t
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|fasttrap_probe_type_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|fasttrap_tracepoint_install
parameter_list|(
name|proc_t
modifier|*
parameter_list|,
name|fasttrap_tracepoint_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|fasttrap_tracepoint_remove
parameter_list|(
name|proc_t
modifier|*
parameter_list|,
name|fasttrap_tracepoint_t
modifier|*
parameter_list|)
function_decl|;
struct_decl|struct
name|reg
struct_decl|;
specifier|extern
name|int
name|fasttrap_pid_probe
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|fasttrap_return_probe
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint64_t
name|fasttrap_pid_getarg
parameter_list|(
name|void
modifier|*
parameter_list|,
name|dtrace_id_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|uint64_t
name|fasttrap_usdt_getarg
parameter_list|(
name|void
modifier|*
parameter_list|,
name|dtrace_id_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
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
comment|/* _FASTTRAP_IMPL_H */
end_comment

end_unit

