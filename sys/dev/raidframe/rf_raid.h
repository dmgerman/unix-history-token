begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_raid.h,v 1.12 2000/02/24 17:12:10 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/**********************************************  * rf_raid.h -- main header file for RAID driver  **********************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_RAID_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_RAID_H_
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
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_bsd.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_stripelocks.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_layout.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_disks.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_debugMem.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_diskqueue.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_reconstruct.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_acctrace.h>
end_include

begin_if
if|#
directive|if
name|RF_INCLUDE_PARITYLOGGING
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<dev/raidframe/rf_paritylog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_INCLUDE_PARITYLOGGING> 0 */
end_comment

begin_define
define|#
directive|define
name|RF_MAX_DISKS
value|128
end_define

begin_comment
comment|/* max disks per array */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RF_DEV2RAIDID
parameter_list|(
name|_dev
parameter_list|)
value|(DISKUNIT(_dev))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RF_COMPONENT_LABEL_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|RF_COMPONENT_LABEL_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|RF_RAID_DIRTY
value|0
end_define

begin_define
define|#
directive|define
name|RF_RAID_CLEAN
value|1
end_define

begin_comment
comment|/*  * Each row in the array is a distinct parity group, so  * each has it's own status, which is one of the following.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|RF_RowStatus_e
block|{
name|rf_rs_optimal
block|,
name|rf_rs_degraded
block|,
name|rf_rs_reconstructing
block|,
name|rf_rs_reconfigured
block|}
name|RF_RowStatus_t
typedef|;
end_typedef

begin_struct
struct|struct
name|RF_CumulativeStats_s
block|{
name|struct
name|timeval
name|start
decl_stmt|;
comment|/* the time when the stats were last started */
name|struct
name|timeval
name|stop
decl_stmt|;
comment|/* the time when the stats were last stopped */
name|long
name|sum_io_us
decl_stmt|;
comment|/* sum of all user response times (us) */
name|long
name|num_ios
decl_stmt|;
comment|/* total number of I/Os serviced */
name|long
name|num_sect_moved
decl_stmt|;
comment|/* total number of sectors read or written */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_ThroughputStats_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* a mutex used to lock the configuration 				 * stuff */
name|struct
name|timeval
name|start
decl_stmt|;
comment|/* timer started when numOutstandingRequests 				 * moves from 0 to 1 */
name|struct
name|timeval
name|stop
decl_stmt|;
comment|/* timer stopped when numOutstandingRequests 				 * moves from 1 to 0 */
name|RF_uint64
name|sum_io_us
decl_stmt|;
comment|/* total time timer is enabled */
name|RF_uint64
name|num_ios
decl_stmt|;
comment|/* total number of ios processed by RAIDframe */
name|long
name|num_out_ios
decl_stmt|;
comment|/* number of outstanding ios */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_Raid_s
block|{
comment|/* This portion never changes, and can be accessed without locking */
comment|/* an exception is Disks[][].status, which requires locking when it is 	 * changed.  XXX this is no longer true.  numSpare and friends can  	 * change now.           */
name|u_int
name|numRow
decl_stmt|;
comment|/* number of rows of disks, typically == # of 				 * ranks */
name|u_int
name|numCol
decl_stmt|;
comment|/* number of columns of disks, typically == # 				 * of disks/rank */
name|u_int
name|numSpare
decl_stmt|;
comment|/* number of spare disks */
name|int
name|maxQueueDepth
decl_stmt|;
comment|/* max disk queue depth */
name|RF_SectorCount_t
name|totalSectors
decl_stmt|;
comment|/* total number of sectors in the 					 * array */
name|RF_SectorCount_t
name|sectorsPerDisk
decl_stmt|;
comment|/* number of sectors on each 						 * disk */
name|u_int
name|logBytesPerSector
decl_stmt|;
comment|/* base-2 log of the number of bytes 					 * in a sector */
name|u_int
name|bytesPerSector
decl_stmt|;
comment|/* bytes in a sector */
name|RF_int32
name|sectorMask
decl_stmt|;
comment|/* mask of bytes-per-sector */
name|RF_RaidLayout_t
name|Layout
decl_stmt|;
comment|/* all information related to layout */
name|RF_RaidDisk_t
modifier|*
modifier|*
name|Disks
decl_stmt|;
comment|/* all information related to physical disks */
name|RF_DiskQueue_t
modifier|*
modifier|*
name|Queues
decl_stmt|;
comment|/* all information related to disk queues */
name|RF_DiskQueueSW_t
modifier|*
name|qType
decl_stmt|;
comment|/* pointer to the DiskQueueSW used for the 				   component queues. */
comment|/* NOTE:  This is an anchor point via which the queues can be 	 * accessed, but the enqueue/dequeue routines in diskqueue.c use a 	 * local copy of this pointer for the actual accesses. */
comment|/* The remainder of the structure can change, and therefore requires 	 * locking on reads and updates */
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* mutex used to serialize access to 					 * the fields below */
name|RF_RowStatus_t
modifier|*
name|status
decl_stmt|;
comment|/* the status of each row in the array */
name|int
name|valid
decl_stmt|;
comment|/* indicates successful configuration */
name|RF_LockTableEntry_t
modifier|*
name|lockTable
decl_stmt|;
comment|/* stripe-lock table */
name|RF_LockTableEntry_t
modifier|*
name|quiesceLock
decl_stmt|;
comment|/* quiesnce table */
name|int
name|numFailures
decl_stmt|;
comment|/* total number of failures in the array */
name|int
name|numNewFailures
decl_stmt|;
comment|/* number of *new* failures (that havn't  				   caused a mod_counter update */
name|int
name|parity_good
decl_stmt|;
comment|/* !0 if parity is known to be correct */
name|int
name|serial_number
decl_stmt|;
comment|/* a "serial number" for this set */
name|int
name|mod_counter
decl_stmt|;
comment|/* modification counter for component labels */
name|int
name|clean
decl_stmt|;
comment|/* the clean bit for this array. */
name|int
name|openings
decl_stmt|;
comment|/* Number of IO's which can be scheduled 				   simultaneously (high-level - not a  				   per-component limit)*/
name|int
name|maxOutstanding
decl_stmt|;
comment|/* maxOutstanding requests (per-component) */
name|int
name|autoconfigure
decl_stmt|;
comment|/* automatically configure this RAID set.  				 0 == no, 1 == yes */
name|int
name|root_partition
decl_stmt|;
comment|/* Use this set as / 				 0 == no, 1 == yes*/
name|int
name|last_unit
decl_stmt|;
comment|/* last unit number (e.g. 0 for /dev/raid0)  				 of this component.  Used for autoconfigure 				 only. */
name|int
name|config_order
decl_stmt|;
comment|/* 0 .. n.  The order in which the component 				 should be auto-configured.  E.g. 0 is will  				 done first, (and would become raid0). 				 This may be in conflict with last_unit!!?! */
comment|/* Not currently used. */
comment|/*          * Cleanup stuff          */
name|RF_ShutdownList_t
modifier|*
name|shutdownList
decl_stmt|;
comment|/* shutdown activities */
name|RF_AllocListElem_t
modifier|*
name|cleanupList
decl_stmt|;
comment|/* memory to be freed at 						 * shutdown time */
comment|/*          * Recon stuff          */
name|RF_HeadSepLimit_t
name|headSepLimit
decl_stmt|;
name|int
name|numFloatingReconBufs
decl_stmt|;
name|int
name|reconInProgress
decl_stmt|;
name|RF_DECLARE_COND
argument_list|(
argument|waitForReconCond
argument_list|)
name|RF_RaidReconDesc_t
modifier|*
name|reconDesc
decl_stmt|;
comment|/* reconstruction descriptor */
name|RF_ReconCtrl_t
modifier|*
modifier|*
name|reconControl
decl_stmt|;
comment|/* reconstruction control structure 					 * pointers for each row in the array */
comment|/*          * Array-quiescence stuff          */
name|RF_DECLARE_MUTEX
argument_list|(
argument|access_suspend_mutex
argument_list|)
name|RF_DECLARE_COND
argument_list|(
argument|quiescent_cond
argument_list|)
name|RF_IoCount_t
name|accesses_suspended
decl_stmt|;
name|RF_IoCount_t
name|accs_in_flight
decl_stmt|;
name|int
name|access_suspend_release
decl_stmt|;
name|int
name|waiting_for_quiescence
decl_stmt|;
name|RF_CallbackDesc_t
modifier|*
name|quiesce_wait_list
decl_stmt|;
comment|/*          * Statistics          */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SIMULATE
argument_list|)
name|RF_ThroughputStats_t
name|throughputstats
decl_stmt|;
endif|#
directive|endif
comment|/* !KERNEL&& !SIMULATE */
name|RF_CumulativeStats_t
name|userstats
decl_stmt|;
name|int
name|parity_rewrite_stripes_done
decl_stmt|;
name|int
name|recon_stripes_done
decl_stmt|;
name|int
name|copyback_stripes_done
decl_stmt|;
name|int
name|recon_in_progress
decl_stmt|;
name|int
name|parity_rewrite_in_progress
decl_stmt|;
name|int
name|copyback_in_progress
decl_stmt|;
comment|/*          * Engine thread control          */
name|RF_DECLARE_MUTEX
argument_list|(
argument|node_queue_mutex
argument_list|)
name|RF_DECLARE_COND
argument_list|(
argument|node_queue_cond
argument_list|)
name|RF_DagNode_t
modifier|*
name|node_queue
decl_stmt|;
name|RF_Thread_t
name|parity_rewrite_thread
decl_stmt|;
name|RF_Thread_t
name|copyback_thread
decl_stmt|;
name|RF_Thread_t
name|engine_thread
decl_stmt|;
name|RF_Thread_t
name|recon_thread
decl_stmt|;
name|RF_ThreadGroup_t
name|engine_tg
decl_stmt|;
name|int
name|shutdown_engine
decl_stmt|;
name|int
name|dags_in_flight
decl_stmt|;
comment|/* debug */
comment|/*          * PSS (Parity Stripe Status) stuff          */
name|RF_FreeList_t
modifier|*
name|pss_freelist
decl_stmt|;
name|long
name|pssTableSize
decl_stmt|;
comment|/*          * Reconstruction stuff          */
name|int
name|procsInBufWait
decl_stmt|;
name|int
name|numFullReconBuffers
decl_stmt|;
name|RF_AccTraceEntry_t
modifier|*
name|recon_tracerecs
decl_stmt|;
name|unsigned
name|long
name|accumXorTimeUs
decl_stmt|;
name|RF_ReconDoneProc_t
modifier|*
name|recon_done_procs
decl_stmt|;
name|RF_DECLARE_MUTEX
argument_list|(
argument|recon_done_proc_mutex
argument_list|)
comment|/*          * nAccOutstanding, waitShutdown protected by desc freelist lock          * (This may seem strange, since that's a central serialization point          * for a per-array piece of data, but otherwise, it'd be an extra          * per-array lock, and that'd only be less efficient...)          */
name|RF_DECLARE_COND
argument_list|(
argument|outstandingCond
argument_list|)
name|int
name|waitShutdown
decl_stmt|;
name|int
name|nAccOutstanding
decl_stmt|;
name|RF_DiskId_t
modifier|*
modifier|*
name|diskids
decl_stmt|;
name|RF_DiskId_t
modifier|*
name|sparediskids
decl_stmt|;
name|int
name|raidid
decl_stmt|;
name|RF_AccTotals_t
name|acc_totals
decl_stmt|;
name|int
name|keep_acc_totals
decl_stmt|;
name|struct
name|raidcinfo
modifier|*
modifier|*
name|raid_cinfo
decl_stmt|;
comment|/* array of component info */
name|int
name|terminate_disk_queues
decl_stmt|;
comment|/*          * XXX          *          * config-specific information should be moved          * somewhere else, or at least hung off this          * in some generic way          */
comment|/* used by rf_compute_workload_shift */
name|RF_RowCol_t
name|hist_diskreq
index|[
name|RF_MAXROW
index|]
index|[
name|RF_MAXCOL
index|]
decl_stmt|;
comment|/* used by declustering */
name|int
name|noRotate
decl_stmt|;
if|#
directive|if
name|RF_INCLUDE_PARITYLOGGING
operator|>
literal|0
comment|/* used by parity logging */
name|RF_SectorCount_t
name|regionLogCapacity
decl_stmt|;
name|RF_ParityLogQueue_t
name|parityLogPool
decl_stmt|;
comment|/* pool of unused parity logs */
name|RF_RegionInfo_t
modifier|*
name|regionInfo
decl_stmt|;
comment|/* array of region state */
name|int
name|numParityLogs
decl_stmt|;
name|int
name|numSectorsPerLog
decl_stmt|;
name|int
name|regionParityRange
decl_stmt|;
name|int
name|logsInUse
decl_stmt|;
comment|/* debugging */
name|RF_ParityLogDiskQueue_t
name|parityLogDiskQueue
decl_stmt|;
comment|/* state of parity 							 * logging disk work */
name|RF_RegionBufferQueue_t
name|regionBufferPool
decl_stmt|;
comment|/* buffers for holding 							 * region log */
name|RF_RegionBufferQueue_t
name|parityBufferPool
decl_stmt|;
comment|/* buffers for holding 							 * parity */
name|caddr_t
name|parityLogBufferHeap
decl_stmt|;
comment|/* pool of unused parity logs */
name|RF_Thread_t
name|pLogDiskThreadHandle
decl_stmt|;
endif|#
directive|endif
comment|/* RF_INCLUDE_PARITYLOGGING> 0 */
comment|/* Point back to the softc for this device.  This is needed to rid 	 * ourselves of the ugly static device arrays. 	 * XXX Will this affect compatibility with NetBSD? 	 */
name|void
modifier|*
name|sc
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_RAID_H_ */
end_comment

end_unit

