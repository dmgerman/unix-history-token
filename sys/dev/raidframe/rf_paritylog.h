begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_paritylog.h,v 1.3 1999/02/05 00:06:14 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: William V. Courtright II  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* header file for parity log  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_PARITYLOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_PARITYLOG_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_define
define|#
directive|define
name|RF_DEFAULT_NUM_SECTORS_PER_LOG
value|64
end_define

begin_typedef
typedef|typedef
name|int
name|RF_RegionId_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|RF_ParityRecordType_e
block|{
name|RF_STOP
block|,
name|RF_UPDATE
block|,
name|RF_OVERWRITE
block|}
name|RF_ParityRecordType_t
typedef|;
end_typedef

begin_struct
struct|struct
name|RF_CommonLogData_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* protects cnt */
name|int
name|cnt
decl_stmt|;
comment|/* when 0, time to call wakeFunc */
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
comment|/*   int                    (*wakeFunc)(RF_Buf_t); */
name|int
function_decl|(
modifier|*
name|wakeFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
name|void
modifier|*
name|wakeArg
decl_stmt|;
name|RF_AccTraceEntry_t
modifier|*
name|tracerec
decl_stmt|;
name|RF_Etimer_t
name|startTime
decl_stmt|;
name|caddr_t
name|bufPtr
decl_stmt|;
name|RF_ParityRecordType_t
name|operation
decl_stmt|;
name|RF_CommonLogData_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_ParityLogData_s
block|{
name|RF_RegionId_t
name|regionID
decl_stmt|;
comment|/* this struct guaranteed to span a single 				 * region */
name|int
name|bufOffset
decl_stmt|;
comment|/* offset from common->bufPtr */
name|RF_PhysDiskAddr_t
name|diskAddress
decl_stmt|;
name|RF_CommonLogData_t
modifier|*
name|common
decl_stmt|;
comment|/* info shared by one or more 					 * parityLogData structs */
name|RF_ParityLogData_t
modifier|*
name|next
decl_stmt|;
name|RF_ParityLogData_t
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_ParityLogAppendQueue_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_ParityLogRecord_s
block|{
name|RF_PhysDiskAddr_t
name|parityAddr
decl_stmt|;
name|RF_ParityRecordType_t
name|operation
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_ParityLog_s
block|{
name|RF_RegionId_t
name|regionID
decl_stmt|;
name|int
name|numRecords
decl_stmt|;
name|int
name|diskOffset
decl_stmt|;
name|RF_ParityLogRecord_t
modifier|*
name|records
decl_stmt|;
name|caddr_t
name|bufPtr
decl_stmt|;
name|RF_ParityLog_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_ParityLogQueue_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
name|RF_ParityLog_t
modifier|*
name|parityLogs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_RegionBufferQueue_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
name|RF_DECLARE_COND
argument_list|(
argument|cond
argument_list|)
name|int
name|bufferSize
decl_stmt|;
name|int
name|totalBuffers
decl_stmt|;
comment|/* size of array 'buffers' */
name|int
name|availableBuffers
decl_stmt|;
comment|/* num available 'buffers' */
name|int
name|emptyBuffersIndex
decl_stmt|;
comment|/* stick next freed buffer here */
name|int
name|availBuffersIndex
decl_stmt|;
comment|/* grab next buffer from here */
name|caddr_t
modifier|*
name|buffers
decl_stmt|;
comment|/* array buffers used to hold parity */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_PLOG_CREATED
value|(1<<0)
end_define

begin_comment
comment|/* thread is created */
end_comment

begin_define
define|#
directive|define
name|RF_PLOG_RUNNING
value|(1<<1)
end_define

begin_comment
comment|/* thread is running */
end_comment

begin_define
define|#
directive|define
name|RF_PLOG_TERMINATE
value|(1<<2)
end_define

begin_comment
comment|/* thread is terminated (should exit) */
end_comment

begin_define
define|#
directive|define
name|RF_PLOG_SHUTDOWN
value|(1<<3)
end_define

begin_comment
comment|/* thread is aware and exiting/exited */
end_comment

begin_struct
struct|struct
name|RF_ParityLogDiskQueue_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* protects all vars in this struct */
name|RF_DECLARE_COND
argument_list|(
argument|cond
argument_list|)
name|int
name|threadState
decl_stmt|;
comment|/* is thread running, should it shutdown  (see 				 * above) */
name|RF_ParityLog_t
modifier|*
name|flushQueue
decl_stmt|;
comment|/* list of parity logs to be flushed 					 * to log disk */
name|RF_ParityLog_t
modifier|*
name|reintQueue
decl_stmt|;
comment|/* list of parity logs waiting to be 					 * reintegrated */
name|RF_ParityLogData_t
modifier|*
name|bufHead
decl_stmt|;
comment|/* head of FIFO list of log data, 					 * waiting on a buffer */
name|RF_ParityLogData_t
modifier|*
name|bufTail
decl_stmt|;
comment|/* tail of FIFO list of log data, 					 * waiting on a buffer */
name|RF_ParityLogData_t
modifier|*
name|reintHead
decl_stmt|;
comment|/* head of FIFO list of log data, 					 * waiting on reintegration */
name|RF_ParityLogData_t
modifier|*
name|reintTail
decl_stmt|;
comment|/* tail of FIFO list of log data, 					 * waiting on reintegration */
name|RF_ParityLogData_t
modifier|*
name|logBlockHead
decl_stmt|;
comment|/* queue of work, blocked 						 * until a log is available */
name|RF_ParityLogData_t
modifier|*
name|logBlockTail
decl_stmt|;
name|RF_ParityLogData_t
modifier|*
name|reintBlockHead
decl_stmt|;
comment|/* queue of work, blocked 						 * until reintegration is 						 * complete */
name|RF_ParityLogData_t
modifier|*
name|reintBlockTail
decl_stmt|;
name|RF_CommonLogData_t
modifier|*
name|freeCommonList
decl_stmt|;
comment|/* list of unused common data 						 * structs */
name|RF_ParityLogData_t
modifier|*
name|freeDataList
decl_stmt|;
comment|/* list of unused log data 						 * structs */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_DiskMap_s
block|{
name|RF_PhysDiskAddr_t
name|parityAddr
decl_stmt|;
name|RF_ParityRecordType_t
name|operation
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_RegionInfo_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* protects: diskCount, diskMap, 				 * loggingEnabled, coreLog */
name|RF_DECLARE_MUTEX
argument_list|(
argument|reintMutex
argument_list|)
comment|/* protects: reintInProgress */
name|int
name|reintInProgress
decl_stmt|;
comment|/* flag used to suspend flushing operations */
name|RF_SectorCount_t
name|capacity
decl_stmt|;
comment|/* capacity of this region in sectors */
name|RF_SectorNum_t
name|regionStartAddr
decl_stmt|;
comment|/* starting disk address for this 					 * region */
name|RF_SectorNum_t
name|parityStartAddr
decl_stmt|;
comment|/* starting disk address for this 					 * region */
name|RF_SectorCount_t
name|numSectorsParity
decl_stmt|;
comment|/* number of parity sectors 						 * protected by this region */
name|RF_SectorCount_t
name|diskCount
decl_stmt|;
comment|/* num of sectors written to this 					 * region's disk log */
name|RF_DiskMap_t
modifier|*
name|diskMap
decl_stmt|;
comment|/* in-core map of what's in this region's disk 				 * log */
name|int
name|loggingEnabled
decl_stmt|;
comment|/* logging enable for this region */
name|RF_ParityLog_t
modifier|*
name|coreLog
decl_stmt|;
comment|/* in-core log for this region */
block|}
struct|;
end_struct

begin_function_decl
name|RF_ParityLogData_t
modifier|*
name|rf_CreateParityLogData
parameter_list|(
name|RF_ParityRecordType_t
name|operation
parameter_list|,
name|RF_PhysDiskAddr_t
modifier|*
name|pda
parameter_list|,
name|caddr_t
name|bufPtr
parameter_list|,
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|int
function_decl|(
modifier|*
name|wakeFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|,
name|int
name|status
parameter_list|)
parameter_list|,
name|void
modifier|*
name|wakeArg
parameter_list|,
name|RF_AccTraceEntry_t
modifier|*
name|tracerec
parameter_list|,
name|RF_Etimer_t
name|startTime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ParityLogData_t
modifier|*
name|rf_SearchAndDequeueParityLogData
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RegionId_t
name|regionID
parameter_list|,
name|RF_ParityLogData_t
modifier|*
modifier|*
name|head
parameter_list|,
name|RF_ParityLogData_t
modifier|*
modifier|*
name|tail
parameter_list|,
name|int
name|ignoreLocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ReleaseParityLogs
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_ParityLog_t
modifier|*
name|firstLog
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ParityLogAppend
parameter_list|(
name|RF_ParityLogData_t
modifier|*
name|logData
parameter_list|,
name|int
name|finish
parameter_list|,
name|RF_ParityLog_t
modifier|*
modifier|*
name|incomingLog
parameter_list|,
name|int
name|clearReintFlag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_EnableParityLogging
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_PARITYLOG_H_ */
end_comment

end_unit

