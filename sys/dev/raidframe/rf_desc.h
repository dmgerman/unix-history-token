begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_desc.h,v 1.5 2000/01/09 00:00:18 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DESC_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_etimer.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dag.h>
end_include

begin_struct
struct|struct
name|RF_RaidReconDesc_s
block|{
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
comment|/* raid device descriptor */
name|RF_RowCol_t
name|row
decl_stmt|;
comment|/* row of failed disk */
name|RF_RowCol_t
name|col
decl_stmt|;
comment|/* col of failed disk */
name|int
name|state
decl_stmt|;
comment|/* how far along the reconstruction operation 				 * has gotten */
name|RF_RaidDisk_t
modifier|*
name|spareDiskPtr
decl_stmt|;
comment|/* describes target disk for recon 					 * (not used in dist sparing) */
name|int
name|numDisksDone
decl_stmt|;
comment|/* the number of surviving disks that have 				 * completed their work */
name|RF_RowCol_t
name|srow
decl_stmt|;
comment|/* row ID of the spare disk (not used in dist 				 * sparing) */
name|RF_RowCol_t
name|scol
decl_stmt|;
comment|/* col ID of the spare disk (not used in dist 				 * sparing) */
comment|/*          * Prevent recon from hogging CPU          */
name|RF_Etimer_t
name|recon_exec_timer
decl_stmt|;
name|RF_uint64
name|reconExecTimerRunning
decl_stmt|;
name|RF_uint64
name|reconExecTicks
decl_stmt|;
name|RF_uint64
name|maxReconExecTicks
decl_stmt|;
if|#
directive|if
name|RF_RECON_STATS
operator|>
literal|0
name|RF_uint64
name|hsStallCount
decl_stmt|;
comment|/* head sep stall count */
name|RF_uint64
name|numReconExecDelays
decl_stmt|;
name|RF_uint64
name|numReconEventWaits
decl_stmt|;
endif|#
directive|endif
comment|/* RF_RECON_STATS> 0 */
name|RF_RaidReconDesc_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_RaidAccessDesc_s
block|{
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
comment|/* raid device descriptor */
name|RF_IoType_t
name|type
decl_stmt|;
comment|/* read or write */
name|RF_RaidAddr_t
name|raidAddress
decl_stmt|;
comment|/* starting address in raid address 					 * space */
name|RF_SectorCount_t
name|numBlocks
decl_stmt|;
comment|/* number of blocks (sectors) to 					 * transfer */
name|RF_StripeCount_t
name|numStripes
decl_stmt|;
comment|/* number of stripes involved in 					 * access */
name|caddr_t
name|bufPtr
decl_stmt|;
comment|/* pointer to data buffer */
name|RF_RaidAccessFlags_t
name|flags
decl_stmt|;
comment|/* flags controlling operation */
name|int
name|state
decl_stmt|;
comment|/* index into states telling how far along the 				 * RAID operation has gotten */
name|RF_AccessState_t
modifier|*
name|states
decl_stmt|;
comment|/* array of states to be run */
name|int
name|status
decl_stmt|;
comment|/* pass/fail status of the last operation */
name|RF_DagList_t
modifier|*
name|dagArray
decl_stmt|;
comment|/* array of dag lists, one list per stripe */
name|RF_AccessStripeMapHeader_t
modifier|*
name|asmap
decl_stmt|;
comment|/* the asm for this I/O */
name|void
modifier|*
name|bp
decl_stmt|;
comment|/* buf pointer for this RAID acc.  ignored 				 * outside the kernel */
name|RF_DagHeader_t
modifier|*
modifier|*
name|paramDAG
decl_stmt|;
comment|/* allows the DAG to be returned to 					 * the caller after I/O completion */
name|RF_AccessStripeMapHeader_t
modifier|*
modifier|*
name|paramASM
decl_stmt|;
comment|/* allows the ASM to be 						 * returned to the caller 						 * after I/O completion */
name|RF_AccTraceEntry_t
name|tracerec
decl_stmt|;
comment|/* perf monitoring information for a 					 * user access (not for dag stats) */
name|void
function_decl|(
modifier|*
name|callbackFunc
function_decl|)
parameter_list|(
name|RF_CBParam_t
parameter_list|)
function_decl|;
comment|/* callback function for this 						 * I/O */
name|void
modifier|*
name|callbackArg
decl_stmt|;
comment|/* arg to give to callback func */
name|RF_AllocListElem_t
modifier|*
name|cleanupList
decl_stmt|;
comment|/* memory to be freed at the 						 * end of the access */
name|RF_RaidAccessDesc_t
modifier|*
name|next
decl_stmt|;
name|RF_RaidAccessDesc_t
modifier|*
name|head
decl_stmt|;
name|int
name|numPending
decl_stmt|;
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* these are used to implement 					 * blocking I/O */
name|RF_DECLARE_COND
argument_list|(
argument|cond
argument_list|)
name|int
name|async_flag
decl_stmt|;
name|RF_Etimer_t
name|timer
decl_stmt|;
comment|/* used for timing this access */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DESC_H_ */
end_comment

end_unit

