begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_diskqueue.h,v 1.5 2000/02/13 04:53:57 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*****************************************************************************************  *  * rf_diskqueue.h -- header file for disk queues  *  * see comments in rf_diskqueue.c  *  ****************************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DISKQUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DISKQUEUE_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_acctrace.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
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
file|<dev/raidframe/rf_bsd.h>
end_include

begin_define
define|#
directive|define
name|RF_IO_NORMAL_PRIORITY
value|1
end_define

begin_define
define|#
directive|define
name|RF_IO_LOW_PRIORITY
value|0
end_define

begin_comment
comment|/* the data held by a disk queue entry */
end_comment

begin_struct
struct|struct
name|RF_DiskQueueData_s
block|{
name|RF_SectorNum_t
name|sectorOffset
decl_stmt|;
comment|/* sector offset into the disk */
name|RF_SectorCount_t
name|numSector
decl_stmt|;
comment|/* number of sectors to read/write */
name|RF_IoType_t
name|type
decl_stmt|;
comment|/* read/write/nop */
name|caddr_t
name|buf
decl_stmt|;
comment|/* buffer pointer */
name|RF_StripeNum_t
name|parityStripeID
decl_stmt|;
comment|/* the RAID parity stripe ID this 					 * access is for */
name|RF_ReconUnitNum_t
name|which_ru
decl_stmt|;
comment|/* which RU within this parity stripe */
name|int
name|priority
decl_stmt|;
comment|/* the priority of this request */
name|int
function_decl|(
modifier|*
name|CompleteFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* function to be called upon 						 * completion */
name|int
function_decl|(
modifier|*
name|AuxFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/* function called upon 						 * completion of the first I/O 						 * of a Read_Op_Write pair */
name|void
modifier|*
name|argument
decl_stmt|;
comment|/* argument to be passed to CompleteFunc */
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
comment|/* needed for simulation */
name|RF_AccTraceEntry_t
modifier|*
name|tracerec
decl_stmt|;
comment|/* perf mon only */
name|RF_Etimer_t
name|qtime
decl_stmt|;
comment|/* perf mon only - time request is in queue */
name|long
name|entryTime
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|next
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|prev
decl_stmt|;
name|caddr_t
name|buf2
decl_stmt|;
comment|/* for read-op-write */
name|dev_t
name|dev
decl_stmt|;
comment|/* the device number for in-kernel version */
name|RF_DiskQueue_t
modifier|*
name|queue
decl_stmt|;
comment|/* the disk queue to which this req is 				 * targeted */
name|RF_DiskQueueDataFlags_t
name|flags
decl_stmt|;
comment|/* flags controlling operation */
name|struct
name|proc
modifier|*
name|b_proc
decl_stmt|;
comment|/* the b_proc from the original bp passed into 				 * the driver for this I/O */
comment|/* XXX Should this be changed to the opaque 				 * RF_Thread_t ? */
name|RF_Buf_t
name|bp
decl_stmt|;
comment|/* a bp to use to get this I/O done */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_LOCK_DISK_QUEUE
value|0x01
end_define

begin_define
define|#
directive|define
name|RF_UNLOCK_DISK_QUEUE
value|0x02
end_define

begin_comment
comment|/* note: "Create" returns type-specific queue header pointer cast to (void *) */
end_comment

begin_struct
struct|struct
name|RF_DiskQueueSW_s
block|{
name|RF_DiskQueueType_t
name|queueType
decl_stmt|;
name|void
modifier|*
function_decl|(
modifier|*
name|Create
function_decl|)
parameter_list|(
name|RF_SectorCount_t
parameter_list|,
name|RF_AllocListElem_t
modifier|*
parameter_list|,
name|RF_ShutdownList_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/* creation routine -- 												 * one call per queue in 												 * system */
name|void
function_decl|(
modifier|*
name|Enqueue
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* enqueue routine */
name|RF_DiskQueueData_t
modifier|*
function_decl|(
modifier|*
name|Dequeue
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* dequeue routine */
name|RF_DiskQueueData_t
modifier|*
function_decl|(
modifier|*
name|Peek
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* peek at head of queue */
comment|/* the rest are optional:  they improve performance, but the driver 	 * will deal with it if they don't exist */
name|int
function_decl|(
modifier|*
name|Promote
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|RF_StripeNum_t
parameter_list|,
name|RF_ReconUnitNum_t
parameter_list|)
function_decl|;
comment|/* promotes priority of 									 * tagged accesses */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_DiskQueue_s
block|{
name|RF_DiskQueueSW_t
modifier|*
name|qPtr
decl_stmt|;
comment|/* access point to queue functions */
name|void
modifier|*
name|qHdr
decl_stmt|;
comment|/* queue header, of whatever type */
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* mutex locking data structures */
name|RF_DECLARE_COND
argument_list|(
argument|cond
argument_list|)
comment|/* condition variable for 					 * synchronization */
name|long
name|numOutstanding
decl_stmt|;
comment|/* number of I/Os currently outstanding on 				 * disk */
name|long
name|maxOutstanding
decl_stmt|;
comment|/* max # of I/Os that can be outstanding on a 				 * disk (in-kernel only) */
name|int
name|curPriority
decl_stmt|;
comment|/* the priority of accs all that are currently 				 * outstanding */
name|long
name|queueLength
decl_stmt|;
comment|/* number of requests in queue */
name|RF_DiskQueueData_t
modifier|*
name|nextLockingOp
decl_stmt|;
comment|/* a locking op that has 						 * arrived at the head of the 						 * queue& is waiting for 						 * drainage */
name|RF_DiskQueueData_t
modifier|*
name|unlockingOp
decl_stmt|;
comment|/* used at user level to 						 * communicate unlocking op 						 * b/w user (or dag exec)& 						 * disk threads */
name|int
name|numWaiting
decl_stmt|;
comment|/* number of threads waiting on this variable. 				 * user-level only */
name|RF_DiskQueueFlags_t
name|flags
decl_stmt|;
comment|/* terminate, locked */
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
comment|/* associated array */
name|dev_t
name|dev
decl_stmt|;
comment|/* device number for kernel version */
name|RF_SectorNum_t
name|last_deq_sector
decl_stmt|;
comment|/* last sector number dequeued or 					 * dispatched */
name|int
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* debug only */
name|struct
name|raidcinfo
modifier|*
name|rf_cinfo
decl_stmt|;
comment|/* disks component info.. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_DQ_LOCKED
value|0x02
end_define

begin_comment
comment|/* no new accs allowed until queue is 				 * explicitly unlocked */
end_comment

begin_comment
comment|/* macros setting& returning information about queues and requests */
end_comment

begin_define
define|#
directive|define
name|RF_QUEUE_LOCKED
parameter_list|(
name|_q
parameter_list|)
value|((_q)->flags& RF_DQ_LOCKED)
end_define

begin_define
define|#
directive|define
name|RF_QUEUE_EMPTY
parameter_list|(
name|_q
parameter_list|)
value|(((_q)->numOutstanding == 0)&& ((_q)->nextLockingOp == NULL)&& !RF_QUEUE_LOCKED(_q))
end_define

begin_define
define|#
directive|define
name|RF_QUEUE_FULL
parameter_list|(
name|_q
parameter_list|)
value|((_q)->numOutstanding == (_q)->maxOutstanding)
end_define

begin_define
define|#
directive|define
name|RF_LOCK_QUEUE
parameter_list|(
name|_q
parameter_list|)
value|(_q)->flags |= RF_DQ_LOCKED
end_define

begin_define
define|#
directive|define
name|RF_UNLOCK_QUEUE
parameter_list|(
name|_q
parameter_list|)
value|(_q)->flags&= ~RF_DQ_LOCKED
end_define

begin_define
define|#
directive|define
name|RF_LOCK_QUEUE_MUTEX
parameter_list|(
name|_q_
parameter_list|,
name|_wh_
parameter_list|)
value|RF_LOCK_MUTEX((_q_)->mutex)
end_define

begin_define
define|#
directive|define
name|RF_UNLOCK_QUEUE_MUTEX
parameter_list|(
name|_q_
parameter_list|,
name|_wh_
parameter_list|)
value|RF_UNLOCK_MUTEX((_q_)->mutex)
end_define

begin_define
define|#
directive|define
name|RF_LOCKING_REQ
parameter_list|(
name|_r
parameter_list|)
value|((_r)->flags& RF_LOCK_DISK_QUEUE)
end_define

begin_define
define|#
directive|define
name|RF_UNLOCKING_REQ
parameter_list|(
name|_r
parameter_list|)
value|((_r)->flags& RF_UNLOCK_DISK_QUEUE)
end_define

begin_comment
comment|/* whether it is ok to dispatch a regular request */
end_comment

begin_define
define|#
directive|define
name|RF_OK_TO_DISPATCH
parameter_list|(
name|_q_
parameter_list|,
name|_r_
parameter_list|)
define|\
value|(RF_QUEUE_EMPTY(_q_) || \     (!RF_QUEUE_FULL(_q_)&& ((_r_)->priority>= (_q_)->curPriority)))
end_define

begin_function_decl
name|int
name|rf_ConfigureDiskQueueSystem
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
name|rf_TerminateDiskQueues
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureDiskQueues
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_DiskIOEnqueue
parameter_list|(
name|RF_DiskQueue_t
modifier|*
name|queue
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
name|req
parameter_list|,
name|int
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_DiskIOComplete
parameter_list|(
name|RF_DiskQueue_t
modifier|*
name|queue
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
name|req
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskIOPromote
parameter_list|(
name|RF_DiskQueue_t
modifier|*
name|queue
parameter_list|,
name|RF_StripeNum_t
name|parityStripeID
parameter_list|,
name|RF_ReconUnitNum_t
name|which_ru
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_DiskQueueData_t
modifier|*
name|rf_CreateDiskQueueData
parameter_list|(
name|RF_IoType_t
name|typ
parameter_list|,
name|RF_SectorNum_t
name|ssect
parameter_list|,
name|RF_SectorCount_t
name|nsect
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|RF_StripeNum_t
name|parityStripeID
parameter_list|,
name|RF_ReconUnitNum_t
name|which_ru
parameter_list|,
name|int
function_decl|(
modifier|*
name|wakeF
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
name|next
parameter_list|,
name|RF_AccTraceEntry_t
modifier|*
name|tracerec
parameter_list|,
name|void
modifier|*
name|raidPtr
parameter_list|,
name|RF_DiskQueueDataFlags_t
name|flags
parameter_list|,
name|void
modifier|*
name|kb_proc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_DiskQueueData_t
modifier|*
name|rf_CreateDiskQueueDataFull
parameter_list|(
name|RF_IoType_t
name|typ
parameter_list|,
name|RF_SectorNum_t
name|ssect
parameter_list|,
name|RF_SectorCount_t
name|nsect
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|RF_StripeNum_t
name|parityStripeID
parameter_list|,
name|RF_ReconUnitNum_t
name|which_ru
parameter_list|,
name|int
function_decl|(
modifier|*
name|wakeF
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
name|next
parameter_list|,
name|RF_AccTraceEntry_t
modifier|*
name|tracerec
parameter_list|,
name|int
name|priority
parameter_list|,
name|int
function_decl|(
modifier|*
name|AuxFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|,
name|caddr_t
name|buf2
parameter_list|,
name|void
modifier|*
name|raidPtr
parameter_list|,
name|RF_DiskQueueDataFlags_t
name|flags
parameter_list|,
name|void
modifier|*
name|kb_proc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeDiskQueueData
parameter_list|(
name|RF_DiskQueueData_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureDiskQueue
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|RF_DiskQueue_t
modifier|*
parameter_list|,
name|RF_RowCol_t
parameter_list|,
name|RF_RowCol_t
parameter_list|,
name|RF_DiskQueueSW_t
modifier|*
parameter_list|,
name|RF_SectorCount_t
parameter_list|,
name|dev_t
parameter_list|,
name|int
parameter_list|,
name|RF_ShutdownList_t
modifier|*
modifier|*
parameter_list|,
name|RF_AllocListElem_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DISKQUEUE_H_ */
end_comment

end_unit

