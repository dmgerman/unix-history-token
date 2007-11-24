begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMMAND_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMMAND_H_
end_define

begin_comment
comment|/***************************************************************************  * Description: Command  ***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AtaCommand
block|{
name|LBA_T
name|Lba
decl_stmt|;
comment|/* Current Logic Disk command: LBA   */
name|USHORT
name|nSectors
decl_stmt|;
comment|/* sector count. May great than 0x80 */
name|UCHAR
name|Command
decl_stmt|;
comment|/* IDE_COMMAND_READ, _WRITE, _VERIFY */
name|UCHAR
name|QueueTag
decl_stmt|;
block|}
name|AtaComm
operator|,
typedef|*
name|PAtaComm
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PassthroughCmd
block|{
name|BYTE
name|bFeaturesReg
decl_stmt|;
comment|/* feature register */
name|BYTE
name|bSectorCountReg
decl_stmt|;
comment|/* IDE sector count register. */
name|BYTE
name|bSectorNumberReg
decl_stmt|;
comment|/* IDE sector number register. */
name|BYTE
name|bCylLowReg
decl_stmt|;
comment|/* IDE low order cylinder value. */
name|BYTE
name|bCylHighReg
decl_stmt|;
comment|/* IDE high order cylinder value. */
name|BYTE
name|bDriveHeadReg
decl_stmt|;
comment|/* IDE drive/head register. */
name|BYTE
name|bCommandReg
decl_stmt|;
comment|/* Actual IDE command. Checked for validity by driver. */
name|BYTE
name|nSectors
decl_stmt|;
comment|/* data transfer */
name|ADDRESS
name|pDataBuffer
decl_stmt|;
comment|/* data buffer */
block|}
name|PassthroughCmd
typedef|;
end_typedef

begin_comment
comment|/* control commands */
end_comment

begin_define
define|#
directive|define
name|CTRL_CMD_REBUILD
value|1
end_define

begin_define
define|#
directive|define
name|CTRL_CMD_VERIFY
value|2
end_define

begin_define
define|#
directive|define
name|CTRL_CMD_INIT
value|3
end_define

begin_comment
comment|/*   * RAID5 rebuild/verify  *   Rebuild/verify one stripe line.  *   The caller needn't supply a buffer for rebuild.  *   RebuildSectors member will be updated if its previous location is the   *   begin of this stripe line.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_R5ControlCmd
block|{
name|LBA_T
name|StripeLine
decl_stmt|;
comment|/* _physical_ stripe line on array */
name|USHORT
name|Offset
decl_stmt|;
comment|/* internal use, don't set */
name|UCHAR
name|Command
decl_stmt|;
comment|/* CTRL_CMD_XXX */
name|UCHAR
name|reserve1
decl_stmt|;
block|}
name|R5ControlCmd
operator|,
typedef|*
name|PR5ControlCmd
typedef|;
end_typedef

begin_comment
comment|/*   * RAID1 rebuild/verify   *   Rebuild/verify specified sectors.  *   The caller must supply a valid buffer and a physical SG table (or a  *   pfnBuildSgl routine).  *   For rebuild/initialize, the buffer size should be nSectors<<9;  *   For verify, the buffer size should be (nSectors*2)<<9.  *   RebuildSectors member will be updated if its previous value equals Lba.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_R1ControlCmd
block|{
name|LBA_T
name|Lba
decl_stmt|;
name|USHORT
name|nSectors
decl_stmt|;
name|UCHAR
name|Command
decl_stmt|;
comment|/* CTRL_CMD_XXX */
name|UCHAR
name|reserve1
decl_stmt|;
name|ADDRESS
name|Buffer
decl_stmt|;
comment|/* buffer logical address */
ifdef|#
directive|ifdef
name|_MACOSX_
name|ADDRESS
name|PhysicalAddress
decl_stmt|;
endif|#
directive|endif
block|}
name|R1ControlCmd
operator|,
typedef|*
name|PR1ControlCmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Command
block|{
name|PVDevice
name|pVDevice
decl_stmt|;
union|union
block|{
comment|/* Ide Command */
name|AtaComm
name|Ide
decl_stmt|;
name|PassthroughCmd
name|Passthrough
decl_stmt|;
comment|/* Atapi Command */
name|UCHAR
name|Atapi
index|[
literal|12
index|]
decl_stmt|;
comment|/* Control command */
name|R5ControlCmd
name|R5Control
decl_stmt|;
name|R1ControlCmd
name|R1Control
decl_stmt|;
block|}
name|uCmd
union|;
name|USHORT
name|cf_physical_sg
range|:
literal|1
decl_stmt|;
name|USHORT
name|cf_data_in
range|:
literal|1
decl_stmt|;
name|USHORT
name|cf_data_out
range|:
literal|1
decl_stmt|;
name|USHORT
name|cf_atapi
range|:
literal|1
decl_stmt|;
name|USHORT
name|cf_ide_passthrough
range|:
literal|1
decl_stmt|;
name|USHORT
name|cf_control
range|:
literal|1
decl_stmt|;
comment|/* return status */
name|UCHAR
name|Result
decl_stmt|;
comment|/* retry count */
name|UCHAR
name|RetryCount
decl_stmt|;
comment|/* S/G table address, if already prepared */
name|FPSCAT_GATH
name|pSgTable
decl_stmt|;
comment|/* called if pSgTable is invalid. */
name|int
function_decl|(
modifier|*
name|HPTLIBAPI
name|pfnBuildSgl
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|,
name|FPSCAT_GATH
name|pSgTable
parameter_list|,
name|int
name|logical
parameter_list|)
function_decl|;
comment|/* called when this command is finished */
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|pfnCompletion
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
comment|/* pointer to origional command */
name|void
modifier|*
name|pOrgCommand
decl_stmt|;
comment|/* scratch data area */
union|union
block|{
struct|struct
block|{
name|LBA_T
name|StartLBA
decl_stmt|;
name|UCHAR
name|FirstMember
decl_stmt|;
comment|/* the sequence number of the first member */
name|UCHAR
name|LastMember
decl_stmt|;
comment|/* the sequence number of the last member */
name|USHORT
name|LastSectors
decl_stmt|;
comment|/* the number of sectors for the last member */
name|USHORT
name|FirstSectors
decl_stmt|;
comment|/* the number of sectors for the first member */
name|USHORT
name|FirstOffset
decl_stmt|;
comment|/* the offset from the StartLBA for the first member */
name|USHORT
name|AllMemberBlocks
decl_stmt|;
comment|/* the number of sectors for all member */
name|USHORT
name|WaitInterrupt
decl_stmt|;
comment|/* bit map the members who wait interrupt */
name|UCHAR
name|InSameLine
decl_stmt|;
comment|/* if the start and end on the same line */
name|UCHAR
name|pad1
decl_stmt|;
block|}
name|array
struct|;
struct|struct
block|{
name|LBA_T
name|StartLBA
decl_stmt|;
name|USHORT
name|FirstSectors
decl_stmt|;
comment|/* the number of sectors for the first member */
name|USHORT
name|FirstOffset
decl_stmt|;
comment|/* the offset from the StartLBA for the first member */
name|USHORT
name|WaitInterrupt
decl_stmt|;
comment|/* bit map the members who wait interrupt */
name|USHORT
name|r5_gap
decl_stmt|;
comment|/* see raid5.c */
name|UCHAR
name|ParDiskNo
decl_stmt|;
comment|/* parity for startLba */
name|UCHAR
name|BadDiskNo
decl_stmt|;
name|UCHAR
name|FirstMember
decl_stmt|;
name|UCHAR
name|pad1
decl_stmt|;
block|}
name|r5
struct|;
struct|struct
block|{
name|PCommand
name|pCmd1
decl_stmt|;
name|PCommand
name|pCmd2
decl_stmt|;
block|}
name|r5split
struct|;
ifdef|#
directive|ifdef
name|_RAID5N_
struct|struct
block|{
name|ULONG
name|dummy
index|[
literal|2
index|]
decl_stmt|;
comment|/* uScratch.wait shall be moved out uScratch. 							   now just fix it thisway */
name|struct
name|range_lock
modifier|*
name|range_lock
decl_stmt|;
name|struct
name|stripe
modifier|*
name|stripes
index|[
literal|5
index|]
decl_stmt|;
name|UCHAR
name|nstripes
decl_stmt|;
name|UCHAR
name|finished_stripes
decl_stmt|;
name|USHORT
name|pad2
decl_stmt|;
comment|/* for direct-read: */
struct|struct
block|{
name|UCHAR
name|cmds
decl_stmt|;
name|UCHAR
name|finished
decl_stmt|;
name|UCHAR
name|first
decl_stmt|;
name|UCHAR
name|parity
decl_stmt|;
name|LBA_T
name|base
decl_stmt|;
name|USHORT
name|firstoffset
decl_stmt|;
name|USHORT
name|firstsectors
decl_stmt|;
block|}
name|dr
struct|;
block|}
name|r5n2
struct|;
endif|#
directive|endif
struct|struct
block|{
name|ULONG
name|WordsLeft
decl_stmt|;
name|FPSCAT_GATH
name|pPIOSg
decl_stmt|;
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|pfnOrgDone
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|SUPPORT_HPT584
name|UCHAR
name|cmd
decl_stmt|;
endif|#
directive|endif
block|}
name|disk
struct|;
struct|struct
block|{
name|PCommand
name|pNext
decl_stmt|;
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|WaitEntry
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
block|}
name|wait
struct|;
struct|struct
block|{
name|PVOID
name|prdAddr
decl_stmt|;
name|ULONG
name|cmd_priv
decl_stmt|;
name|USHORT
name|responseFlags
decl_stmt|;
name|UCHAR
name|bIdeStatus
decl_stmt|;
name|UCHAR
name|errorRegister
decl_stmt|;
block|}
name|sata_param
struct|;
block|}
name|uScratch
union|;
block|}
name|Command
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************  * command return value  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|RETURN_PENDING
value|0
end_define

begin_define
define|#
directive|define
name|RETURN_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|RETURN_BAD_DEVICE
value|2
end_define

begin_define
define|#
directive|define
name|RETURN_BAD_PARAMETER
value|3
end_define

begin_define
define|#
directive|define
name|RETURN_WRITE_NO_DRQ
value|4
end_define

begin_define
define|#
directive|define
name|RETURN_DEVICE_BUSY
value|5
end_define

begin_define
define|#
directive|define
name|RETURN_INVALID_REQUEST
value|6
end_define

begin_define
define|#
directive|define
name|RETURN_SELECTION_TIMEOUT
value|7
end_define

begin_define
define|#
directive|define
name|RETURN_IDE_ERROR
value|8
end_define

begin_define
define|#
directive|define
name|RETURN_NEED_LOGICAL_SG
value|9
end_define

begin_define
define|#
directive|define
name|RETURN_NEED_PHYSICAL_SG
value|10
end_define

begin_define
define|#
directive|define
name|RETURN_RETRY
value|11
end_define

begin_define
define|#
directive|define
name|RETURN_DATA_ERROR
value|12
end_define

begin_define
define|#
directive|define
name|RETURN_BUS_RESET
value|13
end_define

begin_define
define|#
directive|define
name|RETURN_BAD_TRANSFER_LENGTH
value|14
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|DPC_PROC
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dpc_routine
block|{
name|DPC_PROC
name|proc
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|}
name|DPC_ROUTINE
typedef|;
end_typedef

begin_comment
comment|/*  * MAX_QUEUE_COMM is defined in platform related compiler.h  * to specify the maximum requests allowed (for each VBus) from system.  *  * Maximum command blocks needed for each VBus:  *   Each OS command requests 1+MAX_MEMBERS*2 command blocks (RAID1/0 case)  *   This space is allocated by platform dependent part, either static or   *   dynamic, continuous or non-continous.  *   The code only needs _vbus_(pFreeCommands) to be set.  *  * PendingRoutines[] size:  *   Each command may invoke CallAfterReturn once.  *  * IdleRoutines[] size:  *   Each command may invoke CallWhenIdle once.  */
end_comment

begin_define
define|#
directive|define
name|MAX_COMMAND_BLOCKS_FOR_EACH_VBUS
value|(MAX_QUEUE_COMM * (1+MAX_MEMBERS*2))
end_define

begin_define
define|#
directive|define
name|MAX_PENDING_ROUTINES
value|(MAX_COMMAND_BLOCKS_FOR_EACH_VBUS+1)
end_define

begin_define
define|#
directive|define
name|MAX_IDLE_ROUTINES
value|(MAX_COMMAND_BLOCKS_FOR_EACH_VBUS+1)
end_define

begin_define
define|#
directive|define
name|mWaitingForIdle
parameter_list|(
name|pVBus
parameter_list|)
value|((pVBus)->IdleRoutinesFirst!=(pVBus)->IdleRoutinesLast)
end_define

begin_function_decl
name|PCommand
name|HPTLIBAPI
name|AllocateCommand
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FASTCALL
name|FreeCommand
parameter_list|(
name|_VBUS_ARG
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FASTCALL
name|CallAfterReturn
parameter_list|(
name|_VBUS_ARG
name|DPC_PROC
name|proc
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|CheckPendingCall
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FASTCALL
name|CallWhenIdle
parameter_list|(
name|_VBUS_ARG
name|DPC_PROC
name|proc
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|CheckIdleCall
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|AddToWaitingList
parameter_list|(
name|PCommand
modifier|*
name|ppList
parameter_list|,
name|PCommand
name|pCmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|DoWaitingList
parameter_list|(
name|_VBUS_ARG
name|PCommand
modifier|*
name|ppList
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

