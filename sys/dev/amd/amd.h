begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *********************************************************************  *	FILE NAME  : amd.h  *	     BY    : C.L. Huang 	(ching@tekram.com.tw)  *		     Erich Chen     (erich@tekram.com.tw)  *	Description: Device Driver for the amd53c974 PCI Bus Master  *		     SCSI Host adapter found on cards such as  *		     the Tekram DC-390(T).  * (C)Copyright 1995-1999 Tekram Technology Co., Ltd.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *********************************************************************  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMD_H
end_ifndef

begin_define
define|#
directive|define
name|AMD_H
end_define

begin_define
define|#
directive|define
name|AMD_TRANS_CUR
value|0x01
end_define

begin_comment
comment|/* Modify current neogtiation status */
end_comment

begin_define
define|#
directive|define
name|AMD_TRANS_ACTIVE
value|0x03
end_define

begin_comment
comment|/* Assume this is the active target */
end_comment

begin_define
define|#
directive|define
name|AMD_TRANS_GOAL
value|0x04
end_define

begin_comment
comment|/* Modify negotiation goal */
end_comment

begin_define
define|#
directive|define
name|AMD_TRANS_USER
value|0x08
end_define

begin_comment
comment|/* Modify user negotiation settings */
end_comment

begin_comment
comment|/*  * Per target transfer parameters.  */
end_comment

begin_struct
struct|struct
name|amd_transinfo
block|{
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|amd_target_info
block|{
comment|/* 	 * Records the currently active and user/default settings for 	 * tagged queueing and disconnection for each target. 	 */
name|u_int8_t
name|disc_tag
decl_stmt|;
define|#
directive|define
name|AMD_CUR_DISCENB
value|0x01
define|#
directive|define
name|AMD_CUR_TAGENB
value|0x02
define|#
directive|define
name|AMD_USR_DISCENB
value|0x04
define|#
directive|define
name|AMD_USR_TAGENB
value|0x08
name|u_int8_t
name|CtrlR1
decl_stmt|;
name|u_int8_t
name|CtrlR3
decl_stmt|;
name|u_int8_t
name|CtrlR4
decl_stmt|;
name|u_int8_t
name|sync_period_reg
decl_stmt|;
name|u_int8_t
name|sync_offset_reg
decl_stmt|;
comment|/* 	 * Currently active transfer settings. 	 */
name|struct
name|amd_transinfo
name|current
decl_stmt|;
comment|/* 	 * Transfer settings we wish to achieve 	 * through negotiation. 	 */
name|struct
name|amd_transinfo
name|goal
decl_stmt|;
comment|/* 	 * User defined or default transfer settings. 	 */
name|struct
name|amd_transinfo
name|user
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scatter/Gather Segment entry.  */
end_comment

begin_struct
struct|struct
name|amd_sg
block|{
name|u_int32_t
name|SGXLen
decl_stmt|;
name|u_int32_t
name|SGXPtr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Chipset feature limits  */
end_comment

begin_define
define|#
directive|define
name|MAX_SCSI_ID
value|8
end_define

begin_define
define|#
directive|define
name|AMD_MAX_SYNC_OFFSET
value|15
end_define

begin_define
define|#
directive|define
name|AMD_TARGET_MAX
value|7
end_define

begin_define
define|#
directive|define
name|AMD_LUN_MAX
value|7
end_define

begin_define
define|#
directive|define
name|AMD_NSEG
value|(btoc(MAXPHYS) + 1)
end_define

begin_define
define|#
directive|define
name|AMD_MAXTRANSFER_SIZE
value|0xFFFFFF
end_define

begin_comment
comment|/* restricted by 24 bit counter */
end_comment

begin_define
define|#
directive|define
name|MAX_DEVICES
value|10
end_define

begin_define
define|#
directive|define
name|MAX_TAGS_CMD_QUEUE
value|256
end_define

begin_define
define|#
directive|define
name|MAX_CMD_PER_LUN
value|6
end_define

begin_define
define|#
directive|define
name|MAX_SRB_CNT
value|256
end_define

begin_define
define|#
directive|define
name|MAX_START_JOB
value|256
end_define

begin_comment
comment|/*  * BIT position to integer mapping.  */
end_comment

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|N
parameter_list|)
value|(0x01<< N)
end_define

begin_comment
comment|/*  * EEPROM storage offsets and data structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EEprom
block|{
name|u_int8_t
name|EE_MODE1
decl_stmt|;
name|u_int8_t
name|EE_SPEED
decl_stmt|;
name|u_int8_t
name|xx1
decl_stmt|;
name|u_int8_t
name|xx2
decl_stmt|;
block|}
name|EEprom
operator|,
typedef|*
name|PEEprom
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EE_ADAPT_SCSI_ID
value|64
end_define

begin_define
define|#
directive|define
name|EE_MODE2
value|65
end_define

begin_define
define|#
directive|define
name|EE_DELAY
value|66
end_define

begin_define
define|#
directive|define
name|EE_TAG_CMD_NUM
value|67
end_define

begin_define
define|#
directive|define
name|EE_DATA_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|EE_CHECKSUM
value|0x1234
end_define

begin_comment
comment|/*  * EE_MODE1 bits definition  */
end_comment

begin_define
define|#
directive|define
name|PARITY_CHK
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|EN_DISCONNECT
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|SEND_START
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|TAG_QUEUING
value|BIT(4)
end_define

begin_comment
comment|/*  * EE_MODE2 bits definition  */
end_comment

begin_define
define|#
directive|define
name|MORE2_DRV
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|GREATER_1G
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|RST_SCSI_BUS
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|ACTIVE_NEGATION
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|NO_SEEK
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|LUN_CHECK
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|ENABLE_CE
value|1
end_define

begin_define
define|#
directive|define
name|DISABLE_CE
value|0
end_define

begin_define
define|#
directive|define
name|EEPROM_READ
value|0x80
end_define

begin_define
define|#
directive|define
name|AMD_TAG_WILDCARD
value|((u_int)(~0))
end_define

begin_comment
comment|/*  * SCSI Request Block  */
end_comment

begin_struct
struct|struct
name|amd_srb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|amd_srb
argument_list|)
name|links
expr_stmt|;
name|u_int8_t
name|CmdBlock
index|[
literal|12
index|]
decl_stmt|;
name|union
name|ccb
modifier|*
name|pccb
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|struct
name|amd_sg
modifier|*
name|pSGlist
decl_stmt|;
name|u_int32_t
name|TotalXferredLen
decl_stmt|;
name|u_int32_t
name|SGPhysAddr
decl_stmt|;
comment|/* a segment starting address */
name|u_int32_t
name|SGToBeXferLen
decl_stmt|;
comment|/* to be xfer length */
name|u_int32_t
name|Segment0
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|Segment1
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|amd_sg
name|SGsegment
index|[
name|AMD_NSEG
index|]
decl_stmt|;
name|struct
name|amd_sg
name|Segmentx
decl_stmt|;
comment|/* a one entry of S/G list table */
name|u_int8_t
modifier|*
name|pMsgPtr
decl_stmt|;
name|u_int16_t
name|SRBState
decl_stmt|;
name|u_int8_t
name|AdaptStatus
decl_stmt|;
name|u_int8_t
name|TargetStatus
decl_stmt|;
name|u_int8_t
name|MsgCnt
decl_stmt|;
name|u_int8_t
name|EndMessage
decl_stmt|;
name|u_int8_t
name|TagNumber
decl_stmt|;
name|u_int8_t
name|SGcount
decl_stmt|;
name|u_int8_t
name|SGIndex
decl_stmt|;
name|u_int8_t
name|IORBFlag
decl_stmt|;
comment|/* ;81h-Reset, 2-retry */
name|u_int8_t
name|SRBStatus
decl_stmt|;
name|u_int8_t
name|SRBFlag
decl_stmt|;
comment|/* ; b0-AutoReqSense,b6-Read,b7-write */
comment|/* ; b4-settimeout,b5-Residual valid */
name|u_int8_t
name|ScsiCmdLen
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|srb_queue
argument_list|,
name|amd_srb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Per-adapter, software configuration.  */
end_comment

begin_struct
struct|struct
name|amd_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* dmat for buffer I/O */
name|int
name|unit
decl_stmt|;
name|int
name|last_phase
decl_stmt|;
name|int
name|cur_target
decl_stmt|;
name|int
name|cur_lun
decl_stmt|;
name|struct
name|amd_srb
modifier|*
name|active_srb
decl_stmt|;
name|struct
name|amd_srb
modifier|*
name|untagged_srbs
index|[
name|AMD_TARGET_MAX
operator|+
literal|1
index|]
index|[
name|AMD_LUN_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|amd_target_info
name|tinfo
index|[
name|AMD_TARGET_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|u_int16_t
name|disc_count
index|[
name|AMD_TARGET_MAX
operator|+
literal|1
index|]
index|[
name|AMD_LUN_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|srb_queue
name|free_srbs
decl_stmt|;
name|struct
name|srb_queue
name|waiting_srbs
decl_stmt|;
name|struct
name|srb_queue
name|running_srbs
decl_stmt|;
name|struct
name|amd_srb
modifier|*
name|pTmpSRB
decl_stmt|;
name|u_int16_t
name|SRBCount
decl_stmt|;
name|u_int16_t
name|max_id
decl_stmt|;
name|u_int16_t
name|max_lun
decl_stmt|;
comment|/* Hooks into the CAM XPT */
name|struct
name|cam_sim
modifier|*
name|psim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|ppath
decl_stmt|;
name|u_int8_t
name|msgin_buf
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|msgout_buf
index|[
literal|6
index|]
decl_stmt|;
name|u_int
name|msgin_index
decl_stmt|;
name|u_int
name|msgout_index
decl_stmt|;
name|u_int
name|msgout_len
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|AdaptSCSIID
decl_stmt|;
comment|/* ; Adapter SCSI Target ID */
name|u_int8_t
name|AdaptSCSILUN
decl_stmt|;
comment|/* ; Adapter SCSI LUN */
name|u_int8_t
name|ACBFlag
decl_stmt|;
name|u_int8_t
name|Gmode2
decl_stmt|;
name|u_int8_t
name|HostID_Bit
decl_stmt|;
name|u_int8_t
name|InitDCB_flag
index|[
literal|8
index|]
index|[
literal|8
index|]
decl_stmt|;
comment|/* flag of initDCB for device */
name|struct
name|amd_srb
name|SRB_array
index|[
name|MAX_SRB_CNT
index|]
decl_stmt|;
comment|/* +45Ch, Len=	 */
name|struct
name|amd_srb
name|TmpSRB
decl_stmt|;
comment|/* Setup data stored in an 93c46 serial eeprom */
name|u_int8_t
name|eepromBuf
index|[
name|EE_DATA_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *   ----SRB State machine definition  */
end_comment

begin_define
define|#
directive|define
name|SRB_FREE
value|0
end_define

begin_define
define|#
directive|define
name|SRB_READY
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|SRB_MSGOUT
value|BIT(2)
end_define

begin_comment
comment|/* ;arbitration+msg_out 1st byte */
end_comment

begin_define
define|#
directive|define
name|SRB_MSGIN
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|SRB_MSGIN_MULTI
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|SRB_COMMAND
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|SRB_START
value|BIT(6)
end_define

begin_comment
comment|/* ;arbitration+msg_out+command_out */
end_comment

begin_define
define|#
directive|define
name|SRB_DISCONNECT
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|SRB_DATA_XFER
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|SRB_XFERPAD
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|SRB_STATUS
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|SRB_COMPLETED
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|SRB_ABORT_SENT
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|DO_SYNC_NEGO
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|SRB_UNEXPECT_RESEL
value|BIT(14)
end_define

begin_comment
comment|/*  *   ---ACB Flag  */
end_comment

begin_define
define|#
directive|define
name|RESET_DEV
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|RESET_DETECT
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|RESET_DONE
value|BIT(2)
end_define

begin_comment
comment|/*  *   ---DCB Flag  */
end_comment

begin_define
define|#
directive|define
name|ABORT_DEV_
value|BIT(0)
end_define

begin_comment
comment|/*  *   ---SRB status  */
end_comment

begin_define
define|#
directive|define
name|SRB_OK
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|ABORTION
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|OVER_RUN
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|UNDER_RUN
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|PARITY_ERROR
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|SRB_ERROR
value|BIT(5)
end_define

begin_comment
comment|/*  *   ---SRB Flags  */
end_comment

begin_define
define|#
directive|define
name|DATAOUT
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|DATAIN
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|RESIDUAL_VALID
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|ENABLE_TIMER
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|RESET_DEV0
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|ABORT_DEV
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|AUTO_REQSENSE
value|BIT(0)
end_define

begin_comment
comment|/*  *   ---Adapter status  */
end_comment

begin_define
define|#
directive|define
name|H_STATUS_GOOD
value|0
end_define

begin_define
define|#
directive|define
name|H_SEL_TIMEOUT
value|0x11
end_define

begin_define
define|#
directive|define
name|H_OVER_UNDER_RUN
value|0x12
end_define

begin_define
define|#
directive|define
name|H_UNEXP_BUS_FREE
value|0x13
end_define

begin_define
define|#
directive|define
name|H_TARGET_PHASE_F
value|0x14
end_define

begin_define
define|#
directive|define
name|H_INVALID_CCB_OP
value|0x16
end_define

begin_define
define|#
directive|define
name|H_LINK_CCB_BAD
value|0x17
end_define

begin_define
define|#
directive|define
name|H_BAD_TARGET_DIR
value|0x18
end_define

begin_define
define|#
directive|define
name|H_DUPLICATE_CCB
value|0x19
end_define

begin_define
define|#
directive|define
name|H_BAD_CCB_OR_SG
value|0x1A
end_define

begin_define
define|#
directive|define
name|H_ABORT
value|0x0FF
end_define

begin_comment
comment|/*  * AMD specific "status" codes returned in the SCSI status byte.  */
end_comment

begin_define
define|#
directive|define
name|AMD_SCSI_STAT_UNEXP_BUS_F
value|0xFD
end_define

begin_comment
comment|/* ;  Unexpect Bus Free */
end_comment

begin_define
define|#
directive|define
name|AMD_SCSI_STAT_BUS_RST_DETECT
value|0xFE
end_define

begin_comment
comment|/* ;  Scsi Bus Reset detected */
end_comment

begin_define
define|#
directive|define
name|AMD_SCSI_STAT_SEL_TIMEOUT
value|0xFF
end_define

begin_comment
comment|/* ;  Selection Time out */
end_comment

begin_comment
comment|/*  *   ---Sync_Mode  */
end_comment

begin_define
define|#
directive|define
name|SYNC_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|SYNC_ENABLE
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_DONE
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WIDE_ENABLE
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WIDE_NEGO_DONE
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|EN_TAG_QUEUING
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|EN_ATN_STOP
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_OFFSET
value|15
end_define

begin_comment
comment|/*  *    ---SCSI bus phase  */
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_OUT
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_DATA_IN
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_COMMAND
value|2
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS
value|3
end_define

begin_define
define|#
directive|define
name|SCSI_NOP0
value|4
end_define

begin_define
define|#
directive|define
name|SCSI_ARBITRATING
value|5
end_define

begin_define
define|#
directive|define
name|SCSI_MSG_OUT
value|6
end_define

begin_define
define|#
directive|define
name|SCSI_MSG_IN
value|7
end_define

begin_define
define|#
directive|define
name|SCSI_BUS_FREE
value|8
end_define

begin_comment
comment|/*  *==========================================================  *      	AMD 53C974 Registers bit Definition  *==========================================================  */
end_comment

begin_comment
comment|/*  *      ------SCSI Register-------  *      Command Reg.(+0CH)  */
end_comment

begin_define
define|#
directive|define
name|DMA_COMMAND
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|NOP_CMD
value|0
end_define

begin_define
define|#
directive|define
name|CLEAR_FIFO_CMD
value|1
end_define

begin_define
define|#
directive|define
name|RST_DEVICE_CMD
value|2
end_define

begin_define
define|#
directive|define
name|RST_SCSI_BUS_CMD
value|3
end_define

begin_define
define|#
directive|define
name|INFO_XFER_CMD
value|0x10
end_define

begin_define
define|#
directive|define
name|INITIATOR_CMD_CMPLTE
value|0x11
end_define

begin_define
define|#
directive|define
name|MSG_ACCEPTED_CMD
value|0x12
end_define

begin_define
define|#
directive|define
name|XFER_PAD_BYTE
value|0x18
end_define

begin_define
define|#
directive|define
name|SET_ATN_CMD
value|0x1A
end_define

begin_define
define|#
directive|define
name|RESET_ATN_CMD
value|0x1B
end_define

begin_define
define|#
directive|define
name|SEL_W_ATN
value|0x42
end_define

begin_define
define|#
directive|define
name|SEL_W_ATN_STOP
value|0x43
end_define

begin_define
define|#
directive|define
name|EN_SEL_RESEL
value|0x44
end_define

begin_define
define|#
directive|define
name|SEL_W_ATN2
value|0x46
end_define

begin_define
define|#
directive|define
name|DATA_XFER_CMD
value|INFO_XFER_CMD
end_define

begin_comment
comment|/*  *     ------SCSI Register-------  *     SCSI Status Reg.(+10H)  */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|ILLEGAL_OP_ERR
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|PARITY_ERR
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|COUNT_2_ZERO
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|GROUP_CODE_VALID
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|SCSI_PHASE_MASK
value|(BIT(2)+BIT(1)+BIT(0))
end_define

begin_comment
comment|/*  *     ------SCSI Register-------  *     Interrupt Status Reg.(+14H)  */
end_comment

begin_define
define|#
directive|define
name|SCSI_RESET_
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|INVALID_CMD
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|DISCONNECTED
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|SERVICE_REQUEST
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|SUCCESSFUL_OP
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|RESELECTED
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|SEL_ATTENTION
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|SELECTED
value|BIT(0)
end_define

begin_comment
comment|/*  *     ------SCSI Register-------  *    Internal State Reg.(+18H)  */
end_comment

begin_define
define|#
directive|define
name|SYNC_OFFSET_FLAG
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|INTRN_STATE_MASK
value|(BIT(2)+BIT(1)+BIT(0))
end_define

begin_comment
comment|/*  *     ------SCSI Register-------  *     Clock Factor Reg.(+24H)  */
end_comment

begin_define
define|#
directive|define
name|CLK_FREQ_40MHZ
value|0
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_35MHZ
value|(BIT(2)+BIT(1)+BIT(0))
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_30MHZ
value|(BIT(2)+BIT(1))
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_25MHZ
value|(BIT(2)+BIT(0))
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_20MHZ
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_15MHZ
value|(BIT(1)+BIT(0))
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_10MHZ
value|BIT(1)
end_define

begin_comment
comment|/*  *     ------SCSI Register-------  *     Control Reg. 1(+20H)  */
end_comment

begin_define
define|#
directive|define
name|EXTENDED_TIMING
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|DIS_INT_ON_SCSI_RST
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|PARITY_ERR_REPO
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|SCSI_ID_ON_BUS
value|(BIT(2)+BIT(1)+BIT(0))
end_define

begin_comment
comment|/*  *     ------SCSI Register-------  *     Control Reg. 2(+2CH)  */
end_comment

begin_define
define|#
directive|define
name|EN_FEATURE
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|EN_SCSI2_CMD
value|BIT(3)
end_define

begin_comment
comment|/*  *     ------SCSI Register-------  *     Control Reg. 3(+30H)  */
end_comment

begin_define
define|#
directive|define
name|ID_MSG_CHECK
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|EN_QTAG_MSG
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|EN_GRP2_CMD
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|FAST_SCSI
value|BIT(4)
end_define

begin_comment
comment|/* ;10MB/SEC */
end_comment

begin_define
define|#
directive|define
name|FAST_CLK
value|BIT(3)
end_define

begin_comment
comment|/* ;25 - 40 MHZ */
end_comment

begin_comment
comment|/*  *     ------SCSI Register-------  *     Control Reg. 4(+34H)  */
end_comment

begin_define
define|#
directive|define
name|EATER_12NS
value|0
end_define

begin_define
define|#
directive|define
name|EATER_25NS
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|EATER_35NS
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|EATER_0NS
value|(BIT(7)+BIT(6))
end_define

begin_define
define|#
directive|define
name|NEGATE_REQACKDATA
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|NEGATE_REQACK
value|BIT(3)
end_define

begin_comment
comment|/*  *========================================  *             DMA Register  *========================================  */
end_comment

begin_comment
comment|/*  *        -------DMA Register--------  *        DMA Command Reg.(+40H)  */
end_comment

begin_define
define|#
directive|define
name|READ_DIRECTION
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WRITE_DIRECTION
value|0
end_define

begin_define
define|#
directive|define
name|EN_DMA_INT
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|MAP_TO_MDL
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|DMA_DIAGNOSTIC
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|DMA_IDLE_CMD
value|0
end_define

begin_define
define|#
directive|define
name|DMA_BLAST_CMD
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|DMA_ABORT_CMD
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|DMA_START_CMD
value|(BIT(1)|BIT(0))
end_define

begin_comment
comment|/*  *        -------DMA Register--------  *         DMA Status Reg.(+54H)  */
end_comment

begin_define
define|#
directive|define
name|PCI_MS_ABORT
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|BLAST_COMPLETE
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|SCSI_INTERRUPT
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|DMA_XFER_DONE
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|DMA_XFER_ABORT
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|DMA_XFER_ERROR
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|POWER_DOWN
value|BIT(0)
end_define

begin_comment
comment|/*  *        -------DMA Register--------  *        DMA SCSI Bus and Ctrl.(+70H)  *        EN_INT_ON_PCI_ABORT  */
end_comment

begin_comment
comment|/*  *==========================================================  *           SCSI Chip register address offset  *==========================================================  */
end_comment

begin_define
define|#
directive|define
name|CTCREG_LOW
value|0x00
end_define

begin_comment
comment|/* (R)   current transfer count register low */
end_comment

begin_define
define|#
directive|define
name|STCREG_LOW
value|0x00
end_define

begin_comment
comment|/* (W)   start transfer count register low */
end_comment

begin_define
define|#
directive|define
name|CTCREG_MID
value|0x04
end_define

begin_comment
comment|/* (R)   current transfer count register 				 * middle */
end_comment

begin_define
define|#
directive|define
name|STCREG_MID
value|0x04
end_define

begin_comment
comment|/* (W)   start transfer count register middle */
end_comment

begin_define
define|#
directive|define
name|SCSIFIFOREG
value|0x08
end_define

begin_comment
comment|/* (R/W) SCSI FIFO register */
end_comment

begin_define
define|#
directive|define
name|SCSICMDREG
value|0x0C
end_define

begin_comment
comment|/* (R/W) SCSI command register */
end_comment

begin_define
define|#
directive|define
name|SCSISTATREG
value|0x10
end_define

begin_comment
comment|/* (R)   SCSI status register */
end_comment

begin_define
define|#
directive|define
name|SCSIDESTIDREG
value|0x10
end_define

begin_comment
comment|/* (W)   SCSI destination ID register */
end_comment

begin_define
define|#
directive|define
name|INTSTATREG
value|0x14
end_define

begin_comment
comment|/* (R)   interrupt status register */
end_comment

begin_define
define|#
directive|define
name|SCSITIMEOUTREG
value|0x14
end_define

begin_comment
comment|/* (W)   SCSI timeout register */
end_comment

begin_define
define|#
directive|define
name|INTERNSTATREG
value|0x18
end_define

begin_comment
comment|/* (R)   internal state register */
end_comment

begin_define
define|#
directive|define
name|SYNCPERIOREG
value|0x18
end_define

begin_comment
comment|/* (W)   synchronous transfer period register */
end_comment

begin_define
define|#
directive|define
name|CURRENTFIFOREG
value|0x1C
end_define

begin_comment
comment|/* (R)   current FIFO/internal state register */
end_comment

begin_define
define|#
directive|define
name|SYNCOFFREG
value|0x1C
end_define

begin_comment
comment|/* (W)   synchronous transfer period register */
end_comment

begin_define
define|#
directive|define
name|CNTLREG1
value|0x20
end_define

begin_comment
comment|/* (R/W) control register 1 */
end_comment

begin_define
define|#
directive|define
name|CLKFACTREG
value|0x24
end_define

begin_comment
comment|/* (W)   clock factor register */
end_comment

begin_define
define|#
directive|define
name|CNTLREG2
value|0x2C
end_define

begin_comment
comment|/* (R/W) control register 2 */
end_comment

begin_define
define|#
directive|define
name|CNTLREG3
value|0x30
end_define

begin_comment
comment|/* (R/W) control register 3 */
end_comment

begin_define
define|#
directive|define
name|CNTLREG4
value|0x34
end_define

begin_comment
comment|/* (R/W) control register 4 */
end_comment

begin_define
define|#
directive|define
name|CURTXTCNTREG
value|0x38
end_define

begin_comment
comment|/* (R)   current transfer count register 				 * high/part-unique ID code */
end_comment

begin_define
define|#
directive|define
name|STCREG_HIGH
value|0x38
end_define

begin_comment
comment|/* (W)   Start current transfer count register 				 * high */
end_comment

begin_comment
comment|/*  *********************************************************  *  *                 SCSI DMA register  *  *********************************************************  */
end_comment

begin_define
define|#
directive|define
name|DMA_Cmd
value|0x40
end_define

begin_comment
comment|/* (R/W) command register */
end_comment

begin_define
define|#
directive|define
name|DMA_XferCnt
value|0x44
end_define

begin_comment
comment|/* (R/W) starting transfer count */
end_comment

begin_define
define|#
directive|define
name|DMA_XferAddr
value|0x48
end_define

begin_comment
comment|/* (R/W) starting Physical address */
end_comment

begin_define
define|#
directive|define
name|DMA_Wk_ByteCntr
value|0x4C
end_define

begin_comment
comment|/* ( R ) working byte counter */
end_comment

begin_define
define|#
directive|define
name|DMA_Wk_AddrCntr
value|0x50
end_define

begin_comment
comment|/* ( R ) working address counter */
end_comment

begin_define
define|#
directive|define
name|DMA_Status
value|0x54
end_define

begin_comment
comment|/* ( R ) status register */
end_comment

begin_define
define|#
directive|define
name|DMA_MDL_Addr
value|0x58
end_define

begin_comment
comment|/* (R/W) starting memory descriptor list (MDL) 				 * address */
end_comment

begin_define
define|#
directive|define
name|DMA_Wk_MDL_Cntr
value|0x5C
end_define

begin_comment
comment|/* ( R ) working MDL counter */
end_comment

begin_define
define|#
directive|define
name|DMA_ScsiBusCtrl
value|0x70
end_define

begin_comment
comment|/* (bits R/W) SCSI BUS and control */
end_comment

begin_comment
comment|/* ******************************************************* */
end_comment

begin_define
define|#
directive|define
name|am_target
value|SCSISTATREG
end_define

begin_define
define|#
directive|define
name|am_timeout
value|INTSTATREG
end_define

begin_define
define|#
directive|define
name|am_seq_step
value|SYNCPERIOREG
end_define

begin_define
define|#
directive|define
name|am_fifo_count
value|SYNCOFFREG
end_define

begin_define
define|#
directive|define
name|amd_read8
parameter_list|(
name|amd
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((amd)->tag, (amd)->bsh, port)
end_define

begin_define
define|#
directive|define
name|amd_read16
parameter_list|(
name|amd
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_2((amd)->tag, (amd)->bsh, port)
end_define

begin_define
define|#
directive|define
name|amd_read32
parameter_list|(
name|amd
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_4((amd)->tag, (amd)->bsh, port)
end_define

begin_define
define|#
directive|define
name|amd_write8
parameter_list|(
name|amd
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((amd)->tag, (amd)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|amd_write8_multi
parameter_list|(
name|amd
parameter_list|,
name|port
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|)
define|\
value|bus_space_write_multi_1((amd)->tag, (amd)->bsh, port, ptr, len)
end_define

begin_define
define|#
directive|define
name|amd_write16
parameter_list|(
name|amd
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2((amd)->tag, (amd)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|amd_write32
parameter_list|(
name|amd
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4((amd)->tag, (amd)->bsh, port, value)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AMD_H */
end_comment

end_unit

