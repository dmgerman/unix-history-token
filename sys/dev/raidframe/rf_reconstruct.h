begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_reconstruct.h,v 1.5 2000/05/28 00:48:30 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*********************************************************  * rf_reconstruct.h -- header file for reconstruction code  *********************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_RECONSTRUCT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_RECONSTRUCT_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_reconmap.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_psstatus.h>
end_include

begin_comment
comment|/* reconstruction configuration information */
end_comment

begin_struct
struct|struct
name|RF_ReconConfig_s
block|{
name|unsigned
name|numFloatingReconBufs
decl_stmt|;
comment|/* number of floating recon bufs to 					 * use */
name|RF_HeadSepLimit_t
name|headSepLimit
decl_stmt|;
comment|/* how far apart the heads are allow 					 * to become, in parity stripes */
block|}
struct|;
end_struct

begin_comment
comment|/* a reconstruction buffer */
end_comment

begin_struct
struct|struct
name|RF_ReconBuffer_s
block|{
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
comment|/* void * to avoid recursive includes */
name|caddr_t
name|buffer
decl_stmt|;
comment|/* points to the data */
name|RF_StripeNum_t
name|parityStripeID
decl_stmt|;
comment|/* the parity stripe that this data 					 * relates to */
name|int
name|which_ru
decl_stmt|;
comment|/* which reconstruction unit within the PSS */
name|RF_SectorNum_t
name|failedDiskSectorOffset
decl_stmt|;
comment|/* the offset into the failed 						 * disk */
name|RF_RowCol_t
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* which disk this buffer belongs to or is 				 * targeted at */
name|RF_StripeCount_t
name|count
decl_stmt|;
comment|/* counts the # of SUs installed so far */
name|int
name|priority
decl_stmt|;
comment|/* used to force hi priority recon */
name|RF_RbufType_t
name|type
decl_stmt|;
comment|/* FORCED or FLOATING */
name|char
modifier|*
name|arrived
decl_stmt|;
comment|/* [x] = 1/0 if SU from disk x has/hasn't 				 * arrived */
name|RF_ReconBuffer_t
modifier|*
name|next
decl_stmt|;
comment|/* used for buffer management */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* generic field for general use */
name|RF_RowCol_t
name|spRow
decl_stmt|,
name|spCol
decl_stmt|;
comment|/* spare disk to which this buf should 					 * be written */
comment|/* if dist sparing off, always identifies the replacement disk */
name|RF_SectorNum_t
name|spOffset
decl_stmt|;
comment|/* offset into the spare disk */
comment|/* if dist sparing off, identical to failedDiskSectorOffset */
name|RF_ReconParityStripeStatus_t
modifier|*
name|pssPtr
decl_stmt|;
comment|/* debug- pss associated with 						 * issue-pending write */
block|}
struct|;
end_struct

begin_comment
comment|/* a reconstruction event descriptor.  The event types currently are:  *    RF_REVENT_READDONE    -- a read operation has completed  *    RF_REVENT_WRITEDONE   -- a write operation has completed  *    RF_REVENT_BUFREADY    -- the buffer manager has produced a full buffer  *    RF_REVENT_BLOCKCLEAR  -- a reconstruction blockage has been cleared  *    RF_REVENT_BUFCLEAR    -- the buffer manager has released a process blocked on submission  *    RF_REVENT_SKIP        -- we need to skip the current RU and go on to the next one, typ. b/c we found recon forced  *    RF_REVENT_FORCEDREADONE- a forced-reconstructoin read operation has completed  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|RF_Revent_e
block|{
name|RF_REVENT_READDONE
block|,
name|RF_REVENT_WRITEDONE
block|,
name|RF_REVENT_BUFREADY
block|,
name|RF_REVENT_BLOCKCLEAR
block|,
name|RF_REVENT_BUFCLEAR
block|,
name|RF_REVENT_HEADSEPCLEAR
block|,
name|RF_REVENT_SKIP
block|,
name|RF_REVENT_FORCEDREADDONE
block|}
name|RF_Revent_t
typedef|;
end_typedef

begin_struct
struct|struct
name|RF_ReconEvent_s
block|{
name|RF_Revent_t
name|type
decl_stmt|;
comment|/* what kind of event has occurred */
name|RF_RowCol_t
name|col
decl_stmt|;
comment|/* row ID is implicit in the queue in which 				 * the event is placed */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* a generic argument */
name|RF_ReconEvent_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reconstruction control information maintained per-disk  * (for surviving disks)  */
end_comment

begin_struct
struct|struct
name|RF_PerDiskReconCtrl_s
block|{
name|RF_ReconCtrl_t
modifier|*
name|reconCtrl
decl_stmt|;
name|RF_RowCol_t
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* to make this structure self-identifying */
name|RF_StripeNum_t
name|curPSID
decl_stmt|;
comment|/* the next parity stripe ID to check on this 				 * disk */
name|RF_HeadSepLimit_t
name|headSepCounter
decl_stmt|;
comment|/* counter used to control 						 * maximum head separation */
name|RF_SectorNum_t
name|diskOffset
decl_stmt|;
comment|/* the offset into the indicated disk 					 * of the current PU */
name|RF_ReconUnitNum_t
name|ru_count
decl_stmt|;
comment|/* this counts off the recon units 					 * within each parity unit */
name|RF_ReconBuffer_t
modifier|*
name|rbuf
decl_stmt|;
comment|/* the recon buffer assigned to this disk */
block|}
struct|;
end_struct

begin_comment
comment|/* main reconstruction control structure */
end_comment

begin_struct
struct|struct
name|RF_ReconCtrl_s
block|{
name|RF_RaidReconDesc_t
modifier|*
name|reconDesc
decl_stmt|;
name|RF_RowCol_t
name|fcol
decl_stmt|;
comment|/* which column has failed */
name|RF_PerDiskReconCtrl_t
modifier|*
name|perDiskInfo
decl_stmt|;
comment|/* information maintained 						 * per-disk */
name|RF_ReconMap_t
modifier|*
name|reconMap
decl_stmt|;
comment|/* map of what has/has not been reconstructed */
name|RF_RowCol_t
name|spareRow
decl_stmt|;
comment|/* which of the spare disks we're using */
name|RF_RowCol_t
name|spareCol
decl_stmt|;
name|RF_StripeNum_t
name|lastPSID
decl_stmt|;
comment|/* the ID of the last parity stripe we want 				 * reconstructed */
name|int
name|percentComplete
decl_stmt|;
comment|/* percentage completion of reconstruction */
name|int
name|numRUsComplete
decl_stmt|;
comment|/* number of Reconstruction Units done */
name|int
name|numRUsTotal
decl_stmt|;
comment|/* total number of Reconstruction Units */
comment|/* reconstruction event queue */
name|RF_ReconEvent_t
modifier|*
name|eventQueue
decl_stmt|;
comment|/* queue of pending reconstruction 					 * events */
name|RF_DECLARE_MUTEX
argument_list|(
argument|eq_mutex
argument_list|)
comment|/* mutex for locking event 						 * queue */
name|RF_DECLARE_COND
argument_list|(
argument|eq_cond
argument_list|)
comment|/* condition variable for 						 * signalling recon events */
name|int
name|eq_count
decl_stmt|;
comment|/* debug only */
comment|/* reconstruction buffer management */
name|RF_DECLARE_MUTEX
argument_list|(
argument|rb_mutex
argument_list|)
comment|/* mutex for messing around 						 * with recon buffers */
name|RF_ReconBuffer_t
modifier|*
name|floatingRbufs
decl_stmt|;
comment|/* available floating 						 * reconstruction buffers */
name|RF_ReconBuffer_t
modifier|*
name|committedRbufs
decl_stmt|;
comment|/* recon buffers that have 						 * been committed to some 						 * waiting disk */
name|RF_ReconBuffer_t
modifier|*
name|fullBufferList
decl_stmt|;
comment|/* full buffers waiting to be 						 * written out */
name|RF_ReconBuffer_t
modifier|*
name|priorityList
decl_stmt|;
comment|/* full buffers that have been 					 * elevated to higher priority */
name|RF_CallbackDesc_t
modifier|*
name|bufferWaitList
decl_stmt|;
comment|/* disks that are currently 						 * blocked waiting for buffers */
comment|/* parity stripe status table */
name|RF_PSStatusHeader_t
modifier|*
name|pssTable
decl_stmt|;
comment|/* stores the reconstruction status of 					 * active parity stripes */
comment|/* maximum-head separation control */
name|RF_HeadSepLimit_t
name|minHeadSepCounter
decl_stmt|;
comment|/* the minimum hs counter over 						 * all disks */
name|RF_CallbackDesc_t
modifier|*
name|headSepCBList
decl_stmt|;
comment|/* list of callbacks to be 						 * done as minPSID advances */
comment|/* performance monitoring */
name|struct
name|timeval
name|starttime
decl_stmt|;
comment|/* recon start time */
name|void
function_decl|(
modifier|*
name|continueFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* function to call when io 						 * returns */
name|void
modifier|*
name|continueArg
decl_stmt|;
comment|/* argument for Func */
block|}
struct|;
end_struct

begin_comment
comment|/* the default priority for reconstruction accesses */
end_comment

begin_define
define|#
directive|define
name|RF_IO_RECON_PRIORITY
value|RF_IO_LOW_PRIORITY
end_define

begin_function_decl
name|int
name|rf_ConfigureReconstruction
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ReconstructFailedDisk
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|RF_RowCol_t
name|col
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ReconstructFailedDiskBasic
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|RF_RowCol_t
name|col
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ReconstructInPlace
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|RF_RowCol_t
name|col
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ContinueReconstructFailedDisk
parameter_list|(
name|RF_RaidReconDesc_t
modifier|*
name|reconDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ForceOrBlockRecon
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|void
function_decl|(
modifier|*
name|cbFunc
function_decl|)
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_UnblockRecon
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RegisterReconDoneProc
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|RF_ReconDoneProc_t
modifier|*
modifier|*
name|handlep
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_RECONSTRUCT_H_ */
end_comment

end_unit

