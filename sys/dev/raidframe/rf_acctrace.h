begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_acctrace.h,v 1.3 1999/02/05 00:06:06 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*****************************************************************************  *  * acctrace.h -- header file for acctrace.c  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_ACCTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_ACCTRACE_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_hist.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_etimer.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|RF_user_acc_stats_s
block|{
name|RF_uint64
name|suspend_ovhd_us
decl_stmt|;
comment|/* us spent mucking in the 					 * access-suspension code */
name|RF_uint64
name|map_us
decl_stmt|;
comment|/* us spent mapping the access */
name|RF_uint64
name|lock_us
decl_stmt|;
comment|/* us spent locking& unlocking stripes, 				 * including time spent blocked */
name|RF_uint64
name|dag_create_us
decl_stmt|;
comment|/* us spent creating the DAGs */
name|RF_uint64
name|dag_retry_us
decl_stmt|;
comment|/* _total_ us spent retrying the op -- not 				 * broken down into components */
name|RF_uint64
name|exec_us
decl_stmt|;
comment|/* us spent in DispatchDAG */
name|RF_uint64
name|exec_engine_us
decl_stmt|;
comment|/* us spent in engine, not including 					 * blocking time */
name|RF_uint64
name|cleanup_us
decl_stmt|;
comment|/* us spent tearing down the dag& maps, and 				 * generally cleaning up */
block|}
name|RF_user_acc_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_recon_acc_stats_s
block|{
name|RF_uint32
name|recon_start_to_fetch_us
decl_stmt|;
name|RF_uint32
name|recon_fetch_to_return_us
decl_stmt|;
name|RF_uint32
name|recon_return_to_submit_us
decl_stmt|;
block|}
name|RF_recon_acc_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_acctrace_entry_s
block|{
union|union
block|{
name|RF_user_acc_stats_t
name|user
decl_stmt|;
name|RF_recon_acc_stats_t
name|recon
decl_stmt|;
block|}
name|specific
union|;
name|RF_uint8
name|reconacc
decl_stmt|;
comment|/* whether  this is a tracerec for a user acc 				 * or a recon acc */
name|RF_uint64
name|xor_us
decl_stmt|;
comment|/* us spent doing XORs */
name|RF_uint64
name|q_us
decl_stmt|;
comment|/* us spent doing XORs */
name|RF_uint64
name|plog_us
decl_stmt|;
comment|/* us spent waiting to stuff parity into log */
name|RF_uint64
name|diskqueue_us
decl_stmt|;
comment|/* _total_ us spent in disk queue(s), incl 				 * concurrent ops */
name|RF_uint64
name|diskwait_us
decl_stmt|;
comment|/* _total_ us spent waiting actually waiting 				 * on the disk, incl concurrent ops */
name|RF_uint64
name|total_us
decl_stmt|;
comment|/* total us spent on this access */
name|RF_uint64
name|num_phys_ios
decl_stmt|;
comment|/* number of physical I/Os invoked */
name|RF_uint64
name|phys_io_us
decl_stmt|;
comment|/* time of physical I/O */
name|RF_Etimer_t
name|tot_timer
decl_stmt|;
comment|/* a timer used to compute total access time */
name|RF_Etimer_t
name|timer
decl_stmt|;
comment|/* a generic timer val for timing events that 				 * live across procedure boundaries */
name|RF_Etimer_t
name|recon_timer
decl_stmt|;
comment|/* generic timer for recon stuff */
name|RF_uint64
name|index
decl_stmt|;
block|}
name|RF_AccTraceEntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_AccTotals_s
block|{
comment|/* user acc stats */
name|RF_uint64
name|suspend_ovhd_us
decl_stmt|;
name|RF_uint64
name|map_us
decl_stmt|;
name|RF_uint64
name|lock_us
decl_stmt|;
name|RF_uint64
name|dag_create_us
decl_stmt|;
name|RF_uint64
name|dag_retry_us
decl_stmt|;
name|RF_uint64
name|exec_us
decl_stmt|;
name|RF_uint64
name|exec_engine_us
decl_stmt|;
name|RF_uint64
name|cleanup_us
decl_stmt|;
name|RF_uint64
name|user_reccount
decl_stmt|;
comment|/* recon acc stats */
name|RF_uint64
name|recon_start_to_fetch_us
decl_stmt|;
name|RF_uint64
name|recon_fetch_to_return_us
decl_stmt|;
name|RF_uint64
name|recon_return_to_submit_us
decl_stmt|;
name|RF_uint64
name|recon_io_overflow_count
decl_stmt|;
name|RF_uint64
name|recon_phys_io_us
decl_stmt|;
name|RF_uint64
name|recon_num_phys_ios
decl_stmt|;
name|RF_uint64
name|recon_diskwait_us
decl_stmt|;
name|RF_uint64
name|recon_reccount
decl_stmt|;
comment|/* trace entry stats */
name|RF_uint64
name|xor_us
decl_stmt|;
name|RF_uint64
name|q_us
decl_stmt|;
name|RF_uint64
name|plog_us
decl_stmt|;
name|RF_uint64
name|diskqueue_us
decl_stmt|;
name|RF_uint64
name|diskwait_us
decl_stmt|;
name|RF_uint64
name|total_us
decl_stmt|;
name|RF_uint64
name|num_log_ents
decl_stmt|;
name|RF_uint64
name|phys_io_overflow_count
decl_stmt|;
name|RF_uint64
name|num_phys_ios
decl_stmt|;
name|RF_uint64
name|phys_io_us
decl_stmt|;
name|RF_uint64
name|bigvals
decl_stmt|;
comment|/* histograms */
name|RF_Hist_t
name|dw_hist
index|[
name|RF_HIST_NUM_BUCKETS
index|]
decl_stmt|;
name|RF_Hist_t
name|tot_hist
index|[
name|RF_HIST_NUM_BUCKETS
index|]
decl_stmt|;
block|}
name|RF_AccTotals_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|RF_UTILITY
operator|==
literal|0
end_if

begin_macro
name|RF_DECLARE_EXTERN_MUTEX
argument_list|(
argument|rf_tracing_mutex
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_UTILITY == 0 */
end_comment

begin_function_decl
name|int
name|rf_ConfigureAccessTrace
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_LogTraceRec
parameter_list|(
name|RF_Raid_t
modifier|*
name|raid
parameter_list|,
name|RF_AccTraceEntry_t
modifier|*
name|rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FlushAccessTraceBuf
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
comment|/* !_RF__RF_ACCTRACE_H_ */
end_comment

end_unit

