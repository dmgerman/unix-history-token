begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_types.h,v 1.6 1999/09/05 03:05:55 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_types.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/***********************************************************  *  * rf_types.h -- standard types for RAIDframe  *  ***********************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * First, define system-dependent types and constants.  *  * If the machine is big-endian, RF_BIG_ENDIAN should be 1.  * Otherwise, it should be 0.  *  * The various integer types should be self-explanatory; we  * use these elsewhere to avoid size confusion.  *  * LONGSHIFT is lg(sizeof(long)) (that is, log base two of sizeof(long)  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|RF_IS_BIG_ENDIAN
value|1
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|RF_IS_BIG_ENDIAN
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|byte order not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int8_t
name|RF_int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
name|RF_uint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|RF_int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|RF_uint16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|RF_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|RF_uint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|RF_int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|RF_uint64
typedef|;
end_typedef

begin_if
if|#
directive|if
name|LONG_BIT
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|RF_LONGSHIFT
value|2
end_define

begin_elif
elif|#
directive|elif
name|LONG_BIT
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|RF_LONGSHIFT
value|3
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RF_LONGSHIFT
value|2
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RF_LONGSHIFT
value|3
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|word size not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are just zero and non-zero. We don't use "TRUE"  * and "FALSE" because there's too much nonsense trying  * to get them defined exactly once on every platform, given  * the different places they may be defined in system header  * files.  */
end_comment

begin_define
define|#
directive|define
name|RF_TRUE
value|1
end_define

begin_define
define|#
directive|define
name|RF_FALSE
value|0
end_define

begin_comment
comment|/*  * Now, some generic types  */
end_comment

begin_typedef
typedef|typedef
name|RF_uint64
name|RF_IoCount_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint64
name|RF_Offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_PSSFlags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint64
name|RF_SectorCount_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint64
name|RF_StripeCount_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_int64
name|RF_SectorNum_t
typedef|;
end_typedef

begin_comment
comment|/* these are unsigned so we can set them to 				 * (-1) for "uninitialized" */
end_comment

begin_typedef
typedef|typedef
name|RF_int64
name|RF_StripeNum_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_int64
name|RF_RaidAddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|RF_RowCol_t
typedef|;
end_typedef

begin_comment
comment|/* unsigned so it can be (-1) */
end_comment

begin_typedef
typedef|typedef
name|RF_int64
name|RF_HeadSepLimit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_int64
name|RF_ReconUnitCount_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|RF_ReconUnitNum_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|RF_ParityConfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|RF_DiskQueueType_t
index|[
literal|1024
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_DISK_QUEUE_TYPE_NONE
value|""
end_define

begin_comment
comment|/* values for the 'type' field in a reconstruction buffer */
end_comment

begin_typedef
typedef|typedef
name|int
name|RF_RbufType_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_RBUF_TYPE_EXCLUSIVE
value|0
end_define

begin_comment
comment|/* this buf assigned exclusively to 					 * one disk */
end_comment

begin_define
define|#
directive|define
name|RF_RBUF_TYPE_FLOATING
value|1
end_define

begin_comment
comment|/* this is a floating recon buf */
end_comment

begin_define
define|#
directive|define
name|RF_RBUF_TYPE_FORCED
value|2
end_define

begin_comment
comment|/* this rbuf was allocated to complete 					 * a forced recon */
end_comment

begin_typedef
typedef|typedef
name|char
name|RF_IoType_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_IO_TYPE_READ
value|'r'
end_define

begin_define
define|#
directive|define
name|RF_IO_TYPE_WRITE
value|'w'
end_define

begin_define
define|#
directive|define
name|RF_IO_TYPE_NOP
value|'n'
end_define

begin_define
define|#
directive|define
name|RF_IO_IS_R_OR_W
parameter_list|(
name|_type_
parameter_list|)
value|(((_type_) == RF_IO_TYPE_READ) \                                 || ((_type_) == RF_IO_TYPE_WRITE))
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|RF_VoidFuncPtr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_AccessStripeMapFlags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_DiskQueueDataFlags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_DiskQueueFlags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_RaidAccessFlags_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_DISKQUEUE_DATA_FLAGS_NONE
value|((RF_DiskQueueDataFlags_t)0)
end_define

begin_typedef
typedef|typedef
name|struct
name|RF_AccessStripeMap_s
name|RF_AccessStripeMap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_AccessStripeMapHeader_s
name|RF_AccessStripeMapHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_AllocListElem_s
name|RF_AllocListElem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_CallbackDesc_s
name|RF_CallbackDesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ChunkDesc_s
name|RF_ChunkDesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_CommonLogData_s
name|RF_CommonLogData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_Config_s
name|RF_Config_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_CumulativeStats_s
name|RF_CumulativeStats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DagHeader_s
name|RF_DagHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DagList_s
name|RF_DagList_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DagNode_s
name|RF_DagNode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DeclusteredConfigInfo_s
name|RF_DeclusteredConfigInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DiskId_s
name|RF_DiskId_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DiskMap_s
name|RF_DiskMap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DiskQueue_s
name|RF_DiskQueue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DiskQueueData_s
name|RF_DiskQueueData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_DiskQueueSW_s
name|RF_DiskQueueSW_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_Etimer_s
name|RF_Etimer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_EventCreate_s
name|RF_EventCreate_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_FreeList_s
name|RF_FreeList_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_LockReqDesc_s
name|RF_LockReqDesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_LockTableEntry_s
name|RF_LockTableEntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_MCPair_s
name|RF_MCPair_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_OwnerInfo_s
name|RF_OwnerInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ParityLog_s
name|RF_ParityLog_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ParityLogAppendQueue_s
name|RF_ParityLogAppendQueue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ParityLogData_s
name|RF_ParityLogData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ParityLogDiskQueue_s
name|RF_ParityLogDiskQueue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ParityLogQueue_s
name|RF_ParityLogQueue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ParityLogRecord_s
name|RF_ParityLogRecord_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_PerDiskReconCtrl_s
name|RF_PerDiskReconCtrl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_PSStatusHeader_s
name|RF_PSStatusHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_PhysDiskAddr_s
name|RF_PhysDiskAddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_PropHeader_s
name|RF_PropHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_Raid_s
name|RF_Raid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_RaidAccessDesc_s
name|RF_RaidAccessDesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_RaidDisk_s
name|RF_RaidDisk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_RaidLayout_s
name|RF_RaidLayout_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_RaidReconDesc_s
name|RF_RaidReconDesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconBuffer_s
name|RF_ReconBuffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconConfig_s
name|RF_ReconConfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconCtrl_s
name|RF_ReconCtrl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconDoneProc_s
name|RF_ReconDoneProc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconEvent_s
name|RF_ReconEvent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconMap_s
name|RF_ReconMap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconMapListElem_s
name|RF_ReconMapListElem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ReconParityStripeStatus_s
name|RF_ReconParityStripeStatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_RedFuncs_s
name|RF_RedFuncs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_RegionBufferQueue_s
name|RF_RegionBufferQueue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_RegionInfo_s
name|RF_RegionInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ShutdownList_s
name|RF_ShutdownList_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_SpareTableEntry_s
name|RF_SpareTableEntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_SparetWait_s
name|RF_SparetWait_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_StripeLockDesc_s
name|RF_StripeLockDesc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ThreadGroup_s
name|RF_ThreadGroup_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|RF_ThroughputStats_s
name|RF_ThroughputStats_t
typedef|;
end_typedef

begin_comment
comment|/*  * Important assumptions regarding ordering of the states in this list  * have been made!!!  * Before disturbing this ordering, look at code in rf_states.c  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|RF_AccessState_e
block|{
comment|/* original states */
name|rf_QuiesceState
block|,
comment|/* handles queisence for reconstruction */
name|rf_IncrAccessesCountState
block|,
comment|/* count accesses in flight */
name|rf_DecrAccessesCountState
block|,
name|rf_MapState
block|,
comment|/* map access to disk addresses */
name|rf_LockState
block|,
comment|/* take stripe locks */
name|rf_CreateDAGState
block|,
comment|/* create DAGs */
name|rf_ExecuteDAGState
block|,
comment|/* execute DAGs */
name|rf_ProcessDAGState
block|,
comment|/* DAGs are completing- check if correct, or 				 * if we need to retry */
name|rf_CleanupState
block|,
comment|/* release stripe locks, clean up */
name|rf_LastState
comment|/* must be the last state */
block|}
name|RF_AccessState_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_MAXROW
value|10
end_define

begin_comment
comment|/* these are arbitrary and can be modified at 				 * will */
end_comment

begin_define
define|#
directive|define
name|RF_MAXCOL
value|40
end_define

begin_define
define|#
directive|define
name|RF_MAXSPARE
value|10
end_define

begin_define
define|#
directive|define
name|RF_MAXDBGV
value|75
end_define

begin_comment
comment|/* max number of debug variables */
end_comment

begin_union
union|union
name|RF_GenericParam_u
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|RF_uint64
name|v
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|RF_GenericParam_u
name|RF_DagParam_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|RF_GenericParam_u
name|RF_CBParam_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_typedef
typedef|typedef
name|struct
name|bio
modifier|*
name|RF_Buf_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|buf
modifier|*
name|RF_Buf_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RF__RF_TYPES_H_ */
end_comment

end_unit

