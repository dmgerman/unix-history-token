begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_driver.h,v 1.4 2000/02/13 04:53:57 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_driver.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DRIVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DRIVER_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_bsd.h>
end_include

begin_if
if|#
directive|if
name|_KERNEL
end_if

begin_macro
name|RF_DECLARE_EXTERN_MUTEX
argument_list|(
argument|rf_printf_mutex
argument_list|)
end_macro

begin_function_decl
name|int
name|rf_BootRaidframe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_UnbootRaidframe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_Shutdown
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_Configure
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|,
name|RF_AutoConfig_t
modifier|*
name|ac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_RaidAccessDesc_t
modifier|*
name|rf_AllocRaidAccDesc
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_IoType_t
name|type
parameter_list|,
name|RF_RaidAddr_t
name|raidAddress
parameter_list|,
name|RF_SectorCount_t
name|numBlocks
parameter_list|,
name|caddr_t
name|bufPtr
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_DagHeader_t
modifier|*
modifier|*
name|paramDAG
parameter_list|,
name|RF_AccessStripeMapHeader_t
modifier|*
modifier|*
name|paramASM
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|void
function_decl|(
modifier|*
name|cbF
function_decl|)
parameter_list|(
name|RF_Buf_t
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbA
parameter_list|,
name|RF_AccessState_t
modifier|*
name|states
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeRaidAccDesc
parameter_list|(
name|RF_RaidAccessDesc_t
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DoAccess
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_IoType_t
name|type
parameter_list|,
name|int
name|async_flag
parameter_list|,
name|RF_RaidAddr_t
name|raidAddress
parameter_list|,
name|RF_SectorCount_t
name|numBlocks
parameter_list|,
name|caddr_t
name|bufPtr
parameter_list|,
name|void
modifier|*
name|bp_in
parameter_list|,
name|RF_DagHeader_t
modifier|*
modifier|*
name|paramDAG
parameter_list|,
name|RF_AccessStripeMapHeader_t
modifier|*
modifier|*
name|paramASM
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_RaidAccessDesc_t
modifier|*
modifier|*
name|paramDesc
parameter_list|,
name|void
function_decl|(
modifier|*
name|cbF
function_decl|)
parameter_list|(
name|RF_Buf_t
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbA
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SetReconfiguredMode
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
name|rf_FailDisk
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|frow
parameter_list|,
name|RF_RowCol_t
name|fcol
parameter_list|,
name|int
name|initRecon
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_SignalQuiescenceLock
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidReconDesc_t
modifier|*
name|reconDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SuspendNewRequestsAndWait
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ResumeNewRequests
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_StartThroughputStats
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_StartUserStats
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_StopUserStats
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_UpdateUserStats
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|int
name|rt
parameter_list|,
name|int
name|numsect
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PrintUserStats
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DRIVER_H_ */
end_comment

end_unit

