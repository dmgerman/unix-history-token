begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   *   *           Name:  mpi_raid.h  *          Title:  MPI RAID message and structures  *  Creation Date:  February 27, 2001  *  *    mpi_raid.h Version:  01.05.02  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  02-27-01  01.01.01  Original release for this file.  *  03-27-01  01.01.02  Added structure offset comments.  *  08-08-01  01.02.01  Original release for v1.2 work.  *  09-28-01  01.02.02  Major rework for MPI v1.2 Integrated RAID changes.  *  10-04-01  01.02.03  Added ActionData defines for  *                      MPI_RAID_ACTION_DELETE_VOLUME action.  *  11-01-01  01.02.04  Added define for MPI_RAID_ACTION_ADATA_DO_NOT_SYNC.  *  03-14-02  01.02.05  Added define for MPI_RAID_ACTION_ADATA_LOW_LEVEL_INIT.  *  05-07-02  01.02.06  Added define for MPI_RAID_ACTION_ACTIVATE_VOLUME,  *                      MPI_RAID_ACTION_INACTIVATE_VOLUME, and  *                      MPI_RAID_ACTION_ADATA_INACTIVATE_ALL.  *  07-12-02  01.02.07  Added structures for Mailbox request and reply.  *  11-15-02  01.02.08  Added missing MsgContext field to MSG_MAILBOX_REQUEST.  *  04-01-03  01.02.09  New action data option flag for  *                      MPI_RAID_ACTION_DELETE_VOLUME.  *  05-11-04  01.03.01  Original release for MPI v1.3.  *  08-19-04  01.05.01  Original release for MPI v1.5.  *  01-15-05  01.05.02  Added defines for the two new RAID Actions for  *                      _SET_RESYNC_RATE and _SET_DATA_SCRUB_RATE.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_RAID_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_RAID_H
end_define

begin_comment
comment|/****************************************************************************** * *        R A I D    M e s s a g e s * *******************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* RAID Action Request                                                      */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_RAID_ACTION
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|VolumeID
decl_stmt|;
comment|/* 04h */
name|U8
name|VolumeBus
decl_stmt|;
comment|/* 05h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U32
name|ActionDataWord
decl_stmt|;
comment|/* 10h */
name|SGE_SIMPLE_UNION
name|ActionDataSGE
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_RAID_ACTION_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_RAID_ACTION_REQUEST
operator|,
name|MpiRaidActionRequest_t
operator|,
name|MPI_POINTER
name|pMpiRaidActionRequest_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Action request Action values */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_STATUS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_INDICATOR_STRUCT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_CREATE_VOLUME
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_DELETE_VOLUME
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_DISABLE_VOLUME
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ENABLE_VOLUME
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_QUIESCE_PHYS_IO
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ENABLE_PHYS_IO
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_CHANGE_VOLUME_SETTINGS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_PHYSDISK_OFFLINE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_PHYSDISK_ONLINE
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_CHANGE_PHYSDISK_SETTINGS
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_CREATE_PHYSDISK
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_DELETE_PHYSDISK
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_FAIL_PHYSDISK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_REPLACE_PHYSDISK
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ACTIVATE_VOLUME
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_INACTIVATE_VOLUME
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_SET_RESYNC_RATE
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_SET_DATA_SCRUB_RATE
value|(0x14)
end_define

begin_comment
comment|/* ActionDataWord defines for use with MPI_RAID_ACTION_CREATE_VOLUME action */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_DO_NOT_SYNC
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_LOW_LEVEL_INIT
value|(0x00000002)
end_define

begin_comment
comment|/* ActionDataWord defines for use with MPI_RAID_ACTION_DELETE_VOLUME action */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_KEEP_PHYS_DISKS
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_DEL_PHYS_DISKS
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_KEEP_LBA0
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_ZERO_LBA0
value|(0x00000002)
end_define

begin_comment
comment|/* ActionDataWord defines for use with MPI_RAID_ACTION_ACTIVATE_VOLUME action */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_INACTIVATE_ALL
value|(0x00000001)
end_define

begin_comment
comment|/* ActionDataWord defines for use with MPI_RAID_ACTION_SET_RESYNC_RATE action */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_RESYNC_RATE_MASK
value|(0x000000FF)
end_define

begin_comment
comment|/* ActionDataWord defines for use with MPI_RAID_ACTION_SET_DATA_SCRUB_RATE action */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ADATA_DATA_SCRUB_RATE_MASK
value|(0x000000FF)
end_define

begin_comment
comment|/* RAID Action reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_RAID_ACTION_REPLY
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|VolumeID
decl_stmt|;
comment|/* 04h */
name|U8
name|VolumeBus
decl_stmt|;
comment|/* 05h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|ActionStatus
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|VolumeStatus
decl_stmt|;
comment|/* 14h */
name|U32
name|ActionData
decl_stmt|;
comment|/* 18h */
block|}
name|MSG_RAID_ACTION_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_RAID_ACTION_REPLY
operator|,
name|MpiRaidActionReply_t
operator|,
name|MPI_POINTER
name|pMpiRaidActionReply_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Volume reply ActionStatus values */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ASTATUS_SUCCESS
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ASTATUS_INVALID_ACTION
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ASTATUS_FAILURE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_ACTION_ASTATUS_IN_PROGRESS
value|(0x0003)
end_define

begin_comment
comment|/* RAID Volume reply RAID Volume Indicator structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_RAID_VOL_INDICATOR
block|{
name|U64
name|TotalBlocks
decl_stmt|;
comment|/* 00h */
name|U64
name|BlocksRemaining
decl_stmt|;
comment|/* 08h */
block|}
name|MPI_RAID_VOL_INDICATOR
operator|,
name|MPI_POINTER
name|PTR_MPI_RAID_VOL_INDICATOR
operator|,
name|MpiRaidVolIndicator_t
operator|,
name|MPI_POINTER
name|pMpiRaidVolIndicator_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* SCSI IO RAID Passthrough Request                                         */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSI_IO_RAID_PT_REQUEST
block|{
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|CDBLength
decl_stmt|;
comment|/* 04h */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 05h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Control
decl_stmt|;
comment|/* 14h */
name|U8
name|CDB
index|[
literal|16
index|]
decl_stmt|;
comment|/* 18h */
name|U32
name|DataLength
decl_stmt|;
comment|/* 28h */
name|U32
name|SenseBufferLowAddr
decl_stmt|;
comment|/* 2Ch */
name|SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 30h */
block|}
name|MSG_SCSI_IO_RAID_PT_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_SCSI_IO_RAID_PT_REQUEST
operator|,
name|SCSIIORaidPassthroughRequest_t
operator|,
name|MPI_POINTER
name|pSCSIIORaidPassthroughRequest_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO RAID Passthrough reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSI_IO_RAID_PT_REPLY
block|{
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 01h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|CDBLength
decl_stmt|;
comment|/* 04h */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 05h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|SCSIStatus
decl_stmt|;
comment|/* 0Ch */
name|U8
name|SCSIState
decl_stmt|;
comment|/* 0Dh */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|TransferCount
decl_stmt|;
comment|/* 14h */
name|U32
name|SenseCount
decl_stmt|;
comment|/* 18h */
name|U32
name|ResponseInfo
decl_stmt|;
comment|/* 1Ch */
block|}
name|MSG_SCSI_IO_RAID_PT_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SCSI_IO_RAID_PT_REPLY
operator|,
name|SCSIIORaidPassthroughReply_t
operator|,
name|MPI_POINTER
name|pSCSIIORaidPassthroughReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Mailbox reqeust structure */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_MAILBOX_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
name|U8
name|ChainOffset
decl_stmt|;
name|U8
name|Function
decl_stmt|;
name|U16
name|Reserved2
decl_stmt|;
name|U8
name|Reserved3
decl_stmt|;
name|U8
name|MsgFlags
decl_stmt|;
name|U32
name|MsgContext
decl_stmt|;
name|U8
name|Command
index|[
literal|10
index|]
decl_stmt|;
name|U16
name|Reserved4
decl_stmt|;
name|SGE_IO_UNION
name|SGL
decl_stmt|;
block|}
name|MSG_MAILBOX_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_MAILBOX_REQUEST
operator|,
name|MailboxRequest_t
operator|,
name|MPI_POINTER
name|pMailboxRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Mailbox reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_MAILBOX_REPLY
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|MailboxStatus
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_MAILBOX_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_MAILBOX_REPLY
operator|,
name|MailboxReply_t
operator|,
name|MPI_POINTER
name|pMailboxReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

