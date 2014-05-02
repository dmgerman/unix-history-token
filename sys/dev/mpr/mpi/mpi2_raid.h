begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 LSI Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2013 LSI Corporation.  *  *  *           Name:  mpi2_raid.h  *          Title:  MPI Integrated RAID messages and structures  *  Creation Date:  April 26, 2007  *  *    mpi2_raid.h Version:  02.00.10  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  08-31-07  02.00.01  Modifications to RAID Action request and reply,  *                      including the Actions and ActionData.  *  02-29-08  02.00.02  Added MPI2_RAID_ACTION_ADATA_DISABL_FULL_REBUILD.  *  05-21-08  02.00.03  Added MPI2_RAID_VOL_CREATION_NUM_PHYSDISKS so that  *                      the PhysDisk array in MPI2_RAID_VOLUME_CREATION_STRUCT  *                      can be sized by the build environment.  *  07-30-09  02.00.04  Added proper define for the Use Default Settings bit of  *                      VolumeCreationFlags and marked the old one as obsolete.  *  05-12-10  02.00.05  Added MPI2_RAID_VOL_FLAGS_OP_MDC define.  *  08-24-10  02.00.06  Added MPI2_RAID_ACTION_COMPATIBILITY_CHECK along with  *                      related structures and defines.  *                      Added product-specific range to RAID Action values.  *  11-18-11  02.00.07  Incorporating additions for MPI v2.5.  *  02-06-12  02.00.08  Added MPI2_RAID_ACTION_PHYSDISK_HIDDEN.  *  07-26-12  02.00.09  Added ElapsedSeconds field to MPI2_RAID_VOL_INDICATOR.  *                      Added MPI2_RAID_VOL_FLAGS_ELAPSED_SECONDS_VALID define.  *  04-17-13  02.00.10  Added MPI25_RAID_ACTION_ADATA_ALLOW_PI.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_RAID_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_RAID_H
end_define

begin_comment
comment|/***************************************************************************** * *               Integrated RAID Messages * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  RAID Action messages ****************************************************************************/
end_comment

begin_comment
comment|/* ActionDataWord defines for use with MPI2_RAID_ACTION_CREATE_VOLUME action */
end_comment

begin_define
define|#
directive|define
name|MPI25_RAID_ACTION_ADATA_ALLOW_PI
value|(0x80000000)
end_define

begin_comment
comment|/* ActionDataWord defines for use with MPI2_RAID_ACTION_DELETE_VOLUME action */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ADATA_KEEP_LBA0
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ADATA_ZERO_LBA0
value|(0x00000001)
end_define

begin_comment
comment|/* use MPI2_RAIDVOL0_SETTING_ defines from mpi2_cnfg.h for MPI2_RAID_ACTION_CHANGE_VOL_WRITE_CACHE action */
end_comment

begin_comment
comment|/* ActionDataWord defines for use with MPI2_RAID_ACTION_DISABLE_ALL_VOLUMES action */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ADATA_DISABL_FULL_REBUILD
value|(0x00000001)
end_define

begin_comment
comment|/* ActionDataWord for MPI2_RAID_ACTION_SET_RAID_FUNCTION_RATE Action */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACTION_RATE_DATA
block|{
name|U8
name|RateToChange
decl_stmt|;
comment|/* 0x00 */
name|U8
name|RateOrMode
decl_stmt|;
comment|/* 0x01 */
name|U16
name|DataScrubDuration
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_RAID_ACTION_RATE_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_RATE_DATA
operator|,
name|Mpi2RaidActionRateData_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionRateData_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_SET_RATE_RESYNC
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_SET_RATE_DATA_SCRUB
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_SET_RATE_POWERSAVE_MODE
value|(0x02)
end_define

begin_comment
comment|/* ActionDataWord for MPI2_RAID_ACTION_START_RAID_FUNCTION Action */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACTION_START_RAID_FUNCTION
block|{
name|U8
name|RAIDFunction
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_RAID_ACTION_START_RAID_FUNCTION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_START_RAID_FUNCTION
operator|,
name|Mpi2RaidActionStartRaidFunction_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionStartRaidFunction_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the RAIDFunction field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_START_BACKGROUND_INIT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_START_ONLINE_CAP_EXPANSION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_START_CONSISTENCY_CHECK
value|(0x02)
end_define

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_START_NEW
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_START_RESUME
value|(0x01)
end_define

begin_comment
comment|/* ActionDataWord for MPI2_RAID_ACTION_STOP_RAID_FUNCTION Action */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACTION_STOP_RAID_FUNCTION
block|{
name|U8
name|RAIDFunction
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_RAID_ACTION_STOP_RAID_FUNCTION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_STOP_RAID_FUNCTION
operator|,
name|Mpi2RaidActionStopRaidFunction_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionStopRaidFunction_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the RAIDFunction field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_STOP_BACKGROUND_INIT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_STOP_ONLINE_CAP_EXPANSION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_STOP_CONSISTENCY_CHECK
value|(0x02)
end_define

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_STOP_ABORT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_STOP_PAUSE
value|(0x01)
end_define

begin_comment
comment|/* ActionDataWord for MPI2_RAID_ACTION_CREATE_HOT_SPARE Action */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACTION_HOT_SPARE
block|{
name|U8
name|HotSparePool
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_RAID_ACTION_HOT_SPARE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_HOT_SPARE
operator|,
name|Mpi2RaidActionHotSpare_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionHotSpare_t
typedef|;
end_typedef

begin_comment
comment|/* ActionDataWord for MPI2_RAID_ACTION_DEVICE_FW_UPDATE_MODE Action */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACTION_FW_UPDATE_MODE
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|DeviceFirmwareUpdateModeTimeout
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_RAID_ACTION_FW_UPDATE_MODE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_FW_UPDATE_MODE
operator|,
name|Mpi2RaidActionFwUpdateMode_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionFwUpdateMode_t
typedef|;
end_typedef

begin_comment
comment|/* ActionDataWord defines for use with MPI2_RAID_ACTION_DEVICE_FW_UPDATE_MODE action */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ADATA_DISABLE_FW_UPDATE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ADATA_ENABLE_FW_UPDATE
value|(0x01)
end_define

begin_typedef
typedef|typedef
union|union
name|_MPI2_RAID_ACTION_DATA
block|{
name|U32
name|Word
decl_stmt|;
name|MPI2_RAID_ACTION_RATE_DATA
name|Rates
decl_stmt|;
name|MPI2_RAID_ACTION_START_RAID_FUNCTION
name|StartRaidFunction
decl_stmt|;
name|MPI2_RAID_ACTION_STOP_RAID_FUNCTION
name|StopRaidFunction
decl_stmt|;
name|MPI2_RAID_ACTION_HOT_SPARE
name|HotSpare
decl_stmt|;
name|MPI2_RAID_ACTION_FW_UPDATE_MODE
name|FwUpdateMode
decl_stmt|;
block|}
name|MPI2_RAID_ACTION_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_DATA
operator|,
name|Mpi2RaidActionData_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionData_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Action Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACTION_REQUEST
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|VolDevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|MPI2_RAID_ACTION_DATA
name|ActionDataWord
decl_stmt|;
comment|/* 0x10 */
name|MPI2_SGE_SIMPLE_UNION
name|ActionDataSGE
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_RAID_ACTION_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_REQUEST
operator|,
name|Mpi2RaidActionRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionRequest_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Action request Action values */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_INDICATOR_STRUCT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_CREATE_VOLUME
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_DELETE_VOLUME
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_DISABLE_ALL_VOLUMES
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ENABLE_ALL_VOLUMES
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_PHYSDISK_OFFLINE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_PHYSDISK_ONLINE
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_FAIL_PHYSDISK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ACTIVATE_VOLUME
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_DEVICE_FW_UPDATE_MODE
value|(0x15)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_CHANGE_VOL_WRITE_CACHE
value|(0x17)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_SET_VOLUME_NAME
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_SET_RAID_FUNCTION_RATE
value|(0x19)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_ENABLE_FAILED_VOLUME
value|(0x1C)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_CREATE_HOT_SPARE
value|(0x1D)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_DELETE_HOT_SPARE
value|(0x1E)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_SYSTEM_SHUTDOWN_INITIATED
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_START_RAID_FUNCTION
value|(0x21)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_STOP_RAID_FUNCTION
value|(0x22)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_COMPATIBILITY_CHECK
value|(0x23)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_PHYSDISK_HIDDEN
value|(0x24)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_MIN_PRODUCT_SPECIFIC
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_ACTION_MAX_PRODUCT_SPECIFIC
value|(0xFF)
end_define

begin_comment
comment|/* RAID Volume Creation Structure */
end_comment

begin_comment
comment|/*  * The following define can be customized for the targeted product.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_RAID_VOL_CREATION_NUM_PHYSDISKS
end_ifndef

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_CREATION_NUM_PHYSDISKS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_VOLUME_PHYSDISK
block|{
name|U8
name|RAIDSetNum
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysDiskMap
decl_stmt|;
comment|/* 0x01 */
name|U16
name|PhysDiskDevHandle
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_RAID_VOLUME_PHYSDISK
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_VOLUME_PHYSDISK
operator|,
name|Mpi2RaidVolumePhysDisk_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidVolumePhysDisk_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the PhysDiskMap field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDACTION_PHYSDISK_PRIMARY
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDACTION_PHYSDISK_SECONDARY
value|(0x02)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_VOLUME_CREATION_STRUCT
block|{
name|U8
name|NumPhysDisks
decl_stmt|;
comment|/* 0x00 */
name|U8
name|VolumeType
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
name|U32
name|VolumeCreationFlags
decl_stmt|;
comment|/* 0x04 */
name|U32
name|VolumeSettings
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U8
name|ResyncRate
decl_stmt|;
comment|/* 0x0D */
name|U16
name|DataScrubDuration
decl_stmt|;
comment|/* 0x0E */
name|U64
name|VolumeMaxLBA
decl_stmt|;
comment|/* 0x10 */
name|U32
name|StripeSize
decl_stmt|;
comment|/* 0x18 */
name|U8
name|Name
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x1C */
name|MPI2_RAID_VOLUME_PHYSDISK
name|PhysDisk
index|[
name|MPI2_RAID_VOL_CREATION_NUM_PHYSDISKS
index|]
decl_stmt|;
comment|/* 0x2C */
block|}
name|MPI2_RAID_VOLUME_CREATION_STRUCT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_VOLUME_CREATION_STRUCT
operator|,
name|Mpi2RaidVolumeCreationStruct_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidVolumeCreationStruct_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_RAID_VOL_TYPE_ defines from mpi2_cnfg.h for VolumeType */
end_comment

begin_comment
comment|/* defines for the VolumeCreationFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_CREATION_DEFAULT_SETTINGS
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_CREATION_BACKGROUND_INIT
value|(0x00000004)
end_define

begin_comment
comment|/* MPI 2.0 only */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_CREATION_LOW_LEVEL_INIT
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_CREATION_MIGRATE_DATA
value|(0x00000001)
end_define

begin_comment
comment|/* The following is an obsolete define.  * It must be shifted left 24 bits in order to set the proper bit.  */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_CREATION_USE_DEFAULT_SETTINGS
value|(0x80)
end_define

begin_comment
comment|/* RAID Online Capacity Expansion Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ONLINE_CAPACITY_EXPANSION
block|{
name|U32
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U16
name|DevHandle0
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
name|U16
name|DevHandle1
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
block|}
name|MPI2_RAID_ONLINE_CAPACITY_EXPANSION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ONLINE_CAPACITY_EXPANSION
operator|,
name|Mpi2RaidOnlineCapacityExpansion_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidOnlineCapacityExpansion_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Compatibility Input Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_COMPATIBILITY_INPUT_STRUCT
block|{
name|U16
name|SourceDevHandle
decl_stmt|;
comment|/* 0x00 */
name|U16
name|CandidateDevHandle
decl_stmt|;
comment|/* 0x02 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_RAID_COMPATIBILITY_INPUT_STRUCT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_COMPATIBILITY_INPUT_STRUCT
operator|,
name|Mpi2RaidCompatibilityInputStruct_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidCompatibilityInputStruct_t
typedef|;
end_typedef

begin_comment
comment|/* defines for RAID Compatibility Structure Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_SOURCE_IS_VOLUME_FLAG
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_REPORT_SOURCE_INFO_FLAG
value|(0x00000001)
end_define

begin_comment
comment|/* RAID Volume Indicator Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_VOL_INDICATOR
block|{
name|U64
name|TotalBlocks
decl_stmt|;
comment|/* 0x00 */
name|U64
name|BlocksRemaining
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x10 */
name|U32
name|ElapsedSeconds
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_RAID_VOL_INDICATOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_VOL_INDICATOR
operator|,
name|Mpi2RaidVolIndicator_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidVolIndicator_t
typedef|;
end_typedef

begin_comment
comment|/* defines for RAID Volume Indicator Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_FLAGS_ELAPSED_SECONDS_VALID
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_FLAGS_OP_MASK
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_FLAGS_OP_BACKGROUND_INIT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_FLAGS_OP_ONLINE_CAP_EXPANSION
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_FLAGS_OP_CONSISTENCY_CHECK
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_FLAGS_OP_RESYNC
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_FLAGS_OP_MDC
value|(0x00000004)
end_define

begin_comment
comment|/* RAID Compatibility Result Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_COMPATIBILITY_RESULT_STRUCT
block|{
name|U8
name|State
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|GenericAttributes
decl_stmt|;
comment|/* 0x04 */
name|U32
name|OEMSpecificAttributes
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_RAID_COMPATIBILITY_RESULT_STRUCT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_COMPATIBILITY_RESULT_STRUCT
operator|,
name|Mpi2RaidCompatibilityResultStruct_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidCompatibilityResultStruct_t
typedef|;
end_typedef

begin_comment
comment|/* defines for RAID Compatibility Result Structure State field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_STATE_COMPATIBLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_STATE_NOT_COMPATIBLE
value|(0x01)
end_define

begin_comment
comment|/* defines for RAID Compatibility Result Structure GenericAttributes field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_GENATTRIB_4K_SECTOR
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_GENATTRIB_MEDIA_MASK
value|(0x0000000C)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_GENATTRIB_SOLID_STATE_DRIVE
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_GENATTRIB_HARD_DISK_DRIVE
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_GENATTRIB_PROTOCOL_MASK
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_GENATTRIB_SAS_PROTOCOL
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_COMPAT_GENATTRIB_SATA_PROTOCOL
value|(0x00000001)
end_define

begin_comment
comment|/* RAID Action Reply ActionData union */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_RAID_ACTION_REPLY_DATA
block|{
name|U32
name|Word
index|[
literal|6
index|]
decl_stmt|;
name|MPI2_RAID_VOL_INDICATOR
name|RaidVolumeIndicator
decl_stmt|;
name|U16
name|VolDevHandle
decl_stmt|;
name|U8
name|VolumeState
decl_stmt|;
name|U8
name|PhysDiskNum
decl_stmt|;
name|MPI2_RAID_COMPATIBILITY_RESULT_STRUCT
name|RaidCompatibilityResult
decl_stmt|;
block|}
name|MPI2_RAID_ACTION_REPLY_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_REPLY_DATA
operator|,
name|Mpi2RaidActionReplyData_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionReplyData_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_RAIDVOL0_SETTING_ defines from mpi2_cnfg.h for MPI2_RAID_ACTION_CHANGE_VOL_WRITE_CACHE action */
end_comment

begin_comment
comment|/* RAID Action Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACTION_REPLY
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|VolDevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0x0E */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 0x10 */
name|MPI2_RAID_ACTION_REPLY_DATA
name|ActionData
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_RAID_ACTION_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACTION_REPLY
operator|,
name|Mpi2RaidActionReply_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidActionReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

