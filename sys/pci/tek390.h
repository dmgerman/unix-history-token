begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************************** ;*	File Name : TEK390.H					       * ;*		    TEKRAM DC-390 PCI SCSI Bus Master Host Adapter     * ;*		    Device Driver				       * ;***********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TEK390_H
end_ifndef

begin_define
define|#
directive|define
name|TEK390_H
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|USHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ULONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UCHAR
modifier|*
name|PUCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|USHORT
modifier|*
name|PUSHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ULONG
modifier|*
name|PULONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|scsi_link
modifier|*
name|PSCLINK
typedef|,
name|SCSILINK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|scsi_xfer
modifier|*
name|PSCSICMD
typedef|,
name|SCSICMD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|PVOID
typedef|;
end_typedef

begin_comment
comment|/*;-----------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SyncMsg
block|{
name|UCHAR
name|ExtendMsg
decl_stmt|;
name|UCHAR
name|ExtMsgLen
decl_stmt|;
name|UCHAR
name|SyncXferReq
decl_stmt|;
name|UCHAR
name|Period
decl_stmt|;
name|UCHAR
name|ReqOffset
decl_stmt|;
block|}
name|SyncMsg
typedef|;
end_typedef

begin_comment
comment|/*;-----------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_Capacity
block|{
name|ULONG
name|BlockCount
decl_stmt|;
name|ULONG
name|BlockLength
decl_stmt|;
block|}
name|Capacity
typedef|;
end_typedef

begin_comment
comment|/*;-----------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGentry
block|{
name|ULONG
name|SGXLen
decl_stmt|;
name|ULONG
name|SGXPtr
decl_stmt|;
block|}
name|SGentry
operator|,
typedef|*
name|PSEG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SGentry1
block|{
name|ULONG
name|SGXPtr1
decl_stmt|;
name|ULONG
name|SGXLen1
decl_stmt|;
block|}
name|SGentry1
operator|,
typedef|*
name|PSEG1
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_ADAPTER_NUM
value|4
end_define

begin_define
define|#
directive|define
name|MAX_SCSI_ID
value|8
end_define

begin_define
define|#
directive|define
name|MAX_SG_ENTRY
value|33
end_define

begin_define
define|#
directive|define
name|MAX_DEVICES
value|10
end_define

begin_define
define|#
directive|define
name|MAX_CMD_QUEUE
value|20
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
value|MAX_CMD_PER_LUN*4
end_define

begin_define
define|#
directive|define
name|PAGELEN
value|4096
end_define

begin_comment
comment|/* ;----------------------------------------------------------------------- ; SCSI Request Block ;----------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|_SRB
block|{
name|UCHAR
name|CmdBlock
index|[
literal|12
index|]
decl_stmt|;
name|struct
name|_SRB
modifier|*
name|pNextSRB
decl_stmt|;
name|struct
name|_DCB
modifier|*
name|pSRBDCB
decl_stmt|;
name|PSCSICMD
name|pcmd
decl_stmt|;
name|PSEG
name|pSegmentList
decl_stmt|;
name|ULONG
name|PhysSRB
decl_stmt|;
name|ULONG
name|TotalXferredLen
decl_stmt|;
name|ULONG
name|SGPhysAddr
decl_stmt|;
comment|/*;a segment starting address */
name|ULONG
name|SGToBeXferLen
decl_stmt|;
comment|/*; to be xfer length */
name|ULONG
name|Segment0
index|[
literal|2
index|]
decl_stmt|;
name|ULONG
name|Segment1
index|[
literal|2
index|]
decl_stmt|;
name|SGentry
name|SGsegment
index|[
name|MAX_SG_ENTRY
index|]
decl_stmt|;
name|SGentry
name|Segmentx
decl_stmt|;
comment|/* make a one entry of S/G list table */
name|PUCHAR
name|pMsgPtr
decl_stmt|;
name|USHORT
name|SRBState
decl_stmt|;
name|USHORT
name|Revxx2
decl_stmt|;
comment|/* ??? */
name|UCHAR
name|MsgInBuf
index|[
literal|6
index|]
decl_stmt|;
name|UCHAR
name|MsgOutBuf
index|[
literal|6
index|]
decl_stmt|;
name|UCHAR
name|AdaptStatus
decl_stmt|;
name|UCHAR
name|TargetStatus
decl_stmt|;
name|UCHAR
name|MsgCnt
decl_stmt|;
name|UCHAR
name|EndMessage
decl_stmt|;
name|UCHAR
name|TagNumber
decl_stmt|;
name|UCHAR
name|SGcount
decl_stmt|;
name|UCHAR
name|SGIndex
decl_stmt|;
name|UCHAR
name|IORBFlag
decl_stmt|;
comment|/*;81h-Reset, 2-retry */
name|UCHAR
name|SRBStatus
decl_stmt|;
name|UCHAR
name|RetryCnt
decl_stmt|;
name|UCHAR
name|SRBFlag
decl_stmt|;
comment|/*; b0-AutoReqSense,b6-Read,b7-write */
comment|/*; b4-settimeout,b5-Residual valid */
name|UCHAR
name|ScsiCmdLen
decl_stmt|;
name|UCHAR
name|ScsiPhase
decl_stmt|;
name|UCHAR
name|Reserved3
index|[
literal|3
index|]
decl_stmt|;
comment|/*;for dword alignment */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_SRB
name|DC390_SRB
typedef|,
modifier|*
name|PSRB
typedef|;
end_typedef

begin_comment
comment|/* ;----------------------------------------------------------------------- ; Device Control Block ;----------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|_DCB
block|{
name|struct
name|_DCB
modifier|*
name|pNextDCB
decl_stmt|;
name|struct
name|_ACB
modifier|*
name|pDCBACB
decl_stmt|;
name|PSRB
name|pWaitingSRB
decl_stmt|;
name|PSRB
name|pWaitLast
decl_stmt|;
name|PSRB
name|pGoingSRB
decl_stmt|;
name|PSRB
name|pGoingLast
decl_stmt|;
name|PSRB
name|pActiveSRB
decl_stmt|;
name|USHORT
name|GoingSRBCnt
decl_stmt|;
name|USHORT
name|WaitSRBCnt
decl_stmt|;
comment|/* ??? */
name|ULONG
name|TagMask
decl_stmt|;
name|USHORT
name|MaxCommand
decl_stmt|;
name|USHORT
name|AdaptIndex
decl_stmt|;
comment|/*; UnitInfo struc start */
name|USHORT
name|UnitIndex
decl_stmt|;
comment|/*; nth Unit on this card */
name|UCHAR
name|UnitSCSIID
decl_stmt|;
comment|/*; SCSI Target ID  (SCSI Only) */
name|UCHAR
name|UnitSCSILUN
decl_stmt|;
comment|/*; SCSI Log.  Unit (SCSI Only) */
name|UCHAR
name|IdentifyMsg
decl_stmt|;
name|UCHAR
name|CtrlR1
decl_stmt|;
name|UCHAR
name|CtrlR3
decl_stmt|;
name|UCHAR
name|CtrlR4
decl_stmt|;
name|UCHAR
name|InqDataBuf
index|[
literal|8
index|]
decl_stmt|;
name|UCHAR
name|CapacityBuf
index|[
literal|8
index|]
decl_stmt|;
name|UCHAR
name|DevMode
decl_stmt|;
name|UCHAR
name|AdpMode
decl_stmt|;
name|UCHAR
name|SyncMode
decl_stmt|;
comment|/*; 0:async mode */
name|UCHAR
name|NegoPeriod
decl_stmt|;
comment|/*;for nego. */
name|UCHAR
name|SyncPeriod
decl_stmt|;
comment|/*;for reg. */
name|UCHAR
name|SyncOffset
decl_stmt|;
comment|/*;for reg. and nego.(low nibble) */
name|UCHAR
name|UnitCtrlFlag
decl_stmt|;
name|UCHAR
name|DCBFlag
decl_stmt|;
name|UCHAR
name|DevType
decl_stmt|;
name|UCHAR
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|/*;for dword alignment */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_DCB
name|DC390_DCB
typedef|,
modifier|*
name|PDCB
typedef|;
end_typedef

begin_comment
comment|/* ;----------------------------------------------------------------------- ; Adapter Control Block ;----------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|_ACB
block|{
name|ULONG
name|PhysACB
decl_stmt|;
name|struct
name|_ACB
modifier|*
name|pNextACB
decl_stmt|;
name|USHORT
name|IOPortBase
decl_stmt|;
name|USHORT
name|Revxx1
decl_stmt|;
comment|/* ??? */
name|PDCB
name|pLinkDCB
decl_stmt|;
name|PDCB
name|pDCBRunRobin
decl_stmt|;
name|PDCB
name|pActiveDCB
decl_stmt|;
name|PDCB
name|pDCB_free
decl_stmt|;
name|PSRB
name|pFreeSRB
decl_stmt|;
name|PSRB
name|pTmpSRB
decl_stmt|;
name|USHORT
name|SRBCount
decl_stmt|;
name|USHORT
name|AdapterIndex
decl_stmt|;
comment|/*; nth Adapter this driver */
name|USHORT
name|max_id
decl_stmt|;
name|USHORT
name|max_lun
decl_stmt|;
name|SCSILINK
name|ScsiLink
decl_stmt|;
name|UCHAR
name|msgin123
index|[
literal|4
index|]
decl_stmt|;
name|UCHAR
name|status
decl_stmt|;
name|UCHAR
name|AdaptSCSIID
decl_stmt|;
comment|/*; Adapter SCSI Target ID */
name|UCHAR
name|AdaptSCSILUN
decl_stmt|;
comment|/*; Adapter SCSI LUN */
name|UCHAR
name|DeviceCnt
decl_stmt|;
name|UCHAR
name|IRQLevel
decl_stmt|;
name|UCHAR
name|TagMaxNum
decl_stmt|;
name|UCHAR
name|ACBFlag
decl_stmt|;
name|UCHAR
name|Gmode2
decl_stmt|;
name|UCHAR
name|LUNchk
decl_stmt|;
name|UCHAR
name|scan_devices
decl_stmt|;
name|UCHAR
name|HostID_Bit
decl_stmt|;
name|UCHAR
name|Reserved1
index|[
literal|1
index|]
decl_stmt|;
comment|/*;for dword alignment */
name|UCHAR
name|DCBmap
index|[
name|MAX_SCSI_ID
index|]
decl_stmt|;
name|DC390_DCB
name|DCB_array
index|[
name|MAX_DEVICES
index|]
decl_stmt|;
comment|/* +74h,  Len=3E8 */
name|DC390_SRB
name|SRB_array
index|[
name|MAX_SRB_CNT
index|]
decl_stmt|;
comment|/* +45Ch, Len=	*/
name|DC390_SRB
name|TmpSRB
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ACB
name|DC390_ACB
typedef|,
modifier|*
name|PACB
typedef|;
end_typedef

begin_comment
comment|/*;-----------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|BIT31
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BIT30
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BIT29
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BIT28
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BIT27
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BIT26
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BIT25
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BIT24
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BIT23
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BIT22
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BIT21
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BIT20
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BIT19
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BIT18
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BIT17
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BIT16
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BIT15
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BIT14
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BIT13
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BIT12
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BIT11
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BIT10
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BIT9
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BIT8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BIT7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BIT6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BIT5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BIT4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BIT3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BIT2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BIT1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BIT0
value|0x00000001
end_define

begin_comment
comment|/*;---UnitCtrlFlag */
end_comment

begin_define
define|#
directive|define
name|UNIT_ALLOCATED
value|BIT0
end_define

begin_define
define|#
directive|define
name|UNIT_INFO_CHANGED
value|BIT1
end_define

begin_define
define|#
directive|define
name|FORMATING_MEDIA
value|BIT2
end_define

begin_define
define|#
directive|define
name|UNIT_RETRY
value|BIT3
end_define

begin_comment
comment|/*;---UnitFlags */
end_comment

begin_define
define|#
directive|define
name|DASD_SUPPORT
value|BIT0
end_define

begin_define
define|#
directive|define
name|SCSI_SUPPORT
value|BIT1
end_define

begin_define
define|#
directive|define
name|ASPI_SUPPORT
value|BIT2
end_define

begin_comment
comment|/*;----SRBState machine definition */
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
name|SRB_WAIT
value|BIT0
end_define

begin_define
define|#
directive|define
name|SRB_READY
value|BIT1
end_define

begin_define
define|#
directive|define
name|SRB_MSGOUT
value|BIT2
end_define

begin_comment
comment|/*;arbitration+msg_out 1st byte*/
end_comment

begin_define
define|#
directive|define
name|SRB_MSGIN
value|BIT3
end_define

begin_define
define|#
directive|define
name|SRB_MSGIN_MULTI
value|BIT4
end_define

begin_define
define|#
directive|define
name|SRB_COMMAND
value|BIT5
end_define

begin_define
define|#
directive|define
name|SRB_START_
value|BIT6
end_define

begin_comment
comment|/*;arbitration+msg_out+command_out*/
end_comment

begin_define
define|#
directive|define
name|SRB_DISCONNECT
value|BIT7
end_define

begin_define
define|#
directive|define
name|SRB_DATA_XFER
value|BIT8
end_define

begin_define
define|#
directive|define
name|SRB_XFERPAD
value|BIT9
end_define

begin_define
define|#
directive|define
name|SRB_STATUS
value|BIT10
end_define

begin_define
define|#
directive|define
name|SRB_COMPLETED
value|BIT11
end_define

begin_define
define|#
directive|define
name|SRB_ABORT_SENT
value|BIT12
end_define

begin_define
define|#
directive|define
name|DO_SYNC_NEGO
value|BIT13
end_define

begin_define
define|#
directive|define
name|SRB_UNEXPECT_RESEL
value|BIT14
end_define

begin_comment
comment|/*;---ACBFlag */
end_comment

begin_define
define|#
directive|define
name|RESET_DEV
value|BIT0
end_define

begin_define
define|#
directive|define
name|RESET_DETECT
value|BIT1
end_define

begin_define
define|#
directive|define
name|RESET_DONE
value|BIT2
end_define

begin_comment
comment|/*;---DCBFlag */
end_comment

begin_define
define|#
directive|define
name|ABORT_DEV_
value|BIT0
end_define

begin_comment
comment|/*;---SRBstatus */
end_comment

begin_define
define|#
directive|define
name|SRB_OK
value|BIT0
end_define

begin_define
define|#
directive|define
name|ABORTION
value|BIT1
end_define

begin_define
define|#
directive|define
name|OVER_RUN
value|BIT2
end_define

begin_define
define|#
directive|define
name|UNDER_RUN
value|BIT3
end_define

begin_define
define|#
directive|define
name|PARITY_ERROR
value|BIT4
end_define

begin_define
define|#
directive|define
name|SRB_ERROR
value|BIT5
end_define

begin_comment
comment|/*;---SRBFlag */
end_comment

begin_define
define|#
directive|define
name|DATAOUT
value|BIT7
end_define

begin_define
define|#
directive|define
name|DATAIN
value|BIT6
end_define

begin_define
define|#
directive|define
name|RESIDUAL_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|ENABLE_TIMER
value|BIT4
end_define

begin_define
define|#
directive|define
name|RESET_DEV0
value|BIT2
end_define

begin_define
define|#
directive|define
name|ABORT_DEV
value|BIT1
end_define

begin_define
define|#
directive|define
name|AUTO_REQSENSE
value|BIT0
end_define

begin_comment
comment|/*;---Adapter status */
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
comment|/*; SCSI Status byte codes*/
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_GOOD
value|0x0
end_define

begin_comment
comment|/*;  Good status */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_CHECKCOND
value|0x02
end_define

begin_comment
comment|/*;  SCSI Check Condition */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_CONDMET
value|0x04
end_define

begin_comment
comment|/*;  Condition Met */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_BUSY
value|0x08
end_define

begin_comment
comment|/*;  Target busy status */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_INTER
value|0x10
end_define

begin_comment
comment|/*;  Intermediate status */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_INTERCONDMET
value|0x14
end_define

begin_comment
comment|/*;  Intermediate condition met */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_RESCONFLICT
value|0x18
end_define

begin_comment
comment|/*;  Reservation conflict */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_CMDTERM
value|0x22
end_define

begin_comment
comment|/*;  Command Terminated */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_QUEUEFULL
value|0x28
end_define

begin_comment
comment|/*;  Queue Full */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_UNEXP_BUS_F
value|0xFD
end_define

begin_comment
comment|/*;  Unexpect Bus Free */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_BUS_RST_DETECT
value|0xFE
end_define

begin_comment
comment|/*;  Scsi Bus Reset detected */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_SEL_TIMEOUT
value|0xFF
end_define

begin_comment
comment|/*;  Selection Time out */
end_comment

begin_comment
comment|/*;---Sync_Mode */
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
value|BIT0
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_DONE
value|BIT1
end_define

begin_define
define|#
directive|define
name|WIDE_ENABLE
value|BIT2
end_define

begin_define
define|#
directive|define
name|WIDE_NEGO_DONE
value|BIT3
end_define

begin_define
define|#
directive|define
name|EN_TAG_QUEUING
value|BIT4
end_define

begin_define
define|#
directive|define
name|EN_ATN_STOP
value|BIT5
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_OFFSET
value|15
end_define

begin_comment
comment|/*;---SCSI bus phase*/
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_OUT_
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_DATA_IN_
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
name|SCSI_STATUS_
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
name|SCSI_NOP1
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

begin_comment
comment|/*;----SCSI MSG BYTE*/
end_comment

begin_define
define|#
directive|define
name|MSG_COMPLETE
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG_EXTENDED
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG_SAVE_PTR
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG_RESTORE_PTR
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|MSG_INITIATOR_ERROR
value|0x05
end_define

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|MSG_REJECT_
value|0x07
end_define

begin_define
define|#
directive|define
name|MSG_NOP
value|0x08
end_define

begin_define
define|#
directive|define
name|MSG_PARITY_ERROR
value|0x09
end_define

begin_define
define|#
directive|define
name|MSG_LINK_CMD_COMPL
value|0x0A
end_define

begin_define
define|#
directive|define
name|MSG_LINK_CMD_COMPL_FLG
value|0x0B
end_define

begin_define
define|#
directive|define
name|MSG_BUS_RESET
value|0x0C
end_define

begin_define
define|#
directive|define
name|MSG_ABORT_TAG
value|0x0D
end_define

begin_define
define|#
directive|define
name|MSG_SIMPLE_QTAG
value|0x20
end_define

begin_define
define|#
directive|define
name|MSG_HEAD_QTAG
value|0x21
end_define

begin_define
define|#
directive|define
name|MSG_ORDER_QTAG
value|0x22
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY
value|0x80
end_define

begin_define
define|#
directive|define
name|MSG_HOST_ID
value|0x0C0
end_define

begin_comment
comment|/*;----SCSI STATUS BYTE*/
end_comment

begin_define
define|#
directive|define
name|STATUS_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|CHECK_CONDITION_
value|0x02
end_define

begin_define
define|#
directive|define
name|STATUS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|STATUS_INTERMEDIATE
value|0x10
end_define

begin_define
define|#
directive|define
name|RESERVE_CONFLICT
value|0x18
end_define

begin_comment
comment|/* cmd->result */
end_comment

begin_define
define|#
directive|define
name|STATUS_MASK_
value|0xFF
end_define

begin_define
define|#
directive|define
name|MSG_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|RETURN_MASK
value|0xFF0000
end_define

begin_comment
comment|/* **  Inquiry Data format */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SCSIInqData
block|{
comment|/* INQ */
name|UCHAR
name|DevType
decl_stmt|;
comment|/* Periph Qualifier& Periph Dev Type*/
name|UCHAR
name|RMB_TypeMod
decl_stmt|;
comment|/* rem media bit& Dev Type Modifier */
name|UCHAR
name|Vers
decl_stmt|;
comment|/* ISO, ECMA,& ANSI versions	     */
name|UCHAR
name|RDF
decl_stmt|;
comment|/* AEN, TRMIOP,& response data format*/
name|UCHAR
name|AddLen
decl_stmt|;
comment|/* length of additional data	     */
name|UCHAR
name|Res1
decl_stmt|;
comment|/* reserved			     */
name|UCHAR
name|Res2
decl_stmt|;
comment|/* reserved			     */
name|UCHAR
name|Flags
decl_stmt|;
comment|/* RelADr,Wbus32,Wbus16,Sync,etc.    */
name|UCHAR
name|VendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* Vendor Identification	     */
name|UCHAR
name|ProductID
index|[
literal|16
index|]
decl_stmt|;
comment|/* Product Identification	     */
name|UCHAR
name|ProductRev
index|[
literal|4
index|]
decl_stmt|;
comment|/* Product Revision		     */
block|}
name|SCSI_INQDATA
operator|,
typedef|*
name|PSCSI_INQDATA
typedef|;
end_typedef

begin_comment
comment|/*  Inquiry byte 0 masks */
end_comment

begin_define
define|#
directive|define
name|SCSI_DEVTYPE
value|0x1F
end_define

begin_comment
comment|/* Peripheral Device Type 	    */
end_comment

begin_define
define|#
directive|define
name|SCSI_PERIPHQUAL
value|0xE0
end_define

begin_comment
comment|/* Peripheral Qualifier		    */
end_comment

begin_comment
comment|/*  Inquiry byte 1 mask */
end_comment

begin_define
define|#
directive|define
name|SCSI_REMOVABLE_MEDIA
value|0x80
end_define

begin_comment
comment|/* Removable Media bit (1=removable)  */
end_comment

begin_comment
comment|/*  Peripheral Device Type definitions */
end_comment

begin_define
define|#
directive|define
name|SCSI_DASD
value|0x00
end_define

begin_comment
comment|/* Direct-access Device	   */
end_comment

begin_define
define|#
directive|define
name|SCSI_SEQACESS
value|0x01
end_define

begin_comment
comment|/* Sequential-access device	   */
end_comment

begin_define
define|#
directive|define
name|SCSI_PRINTER
value|0x02
end_define

begin_comment
comment|/* Printer device		   */
end_comment

begin_define
define|#
directive|define
name|SCSI_PROCESSOR
value|0x03
end_define

begin_comment
comment|/* Processor device		   */
end_comment

begin_define
define|#
directive|define
name|SCSI_WRITEONCE
value|0x04
end_define

begin_comment
comment|/* Write-once device 	   */
end_comment

begin_define
define|#
directive|define
name|SCSI_CDROM
value|0x05
end_define

begin_comment
comment|/* CD-ROM device		   */
end_comment

begin_define
define|#
directive|define
name|SCSI_SCANNER
value|0x06
end_define

begin_comment
comment|/* Scanner device		   */
end_comment

begin_define
define|#
directive|define
name|SCSI_OPTICAL
value|0x07
end_define

begin_comment
comment|/* Optical memory device	   */
end_comment

begin_define
define|#
directive|define
name|SCSI_MEDCHGR
value|0x08
end_define

begin_comment
comment|/* Medium changer device	   */
end_comment

begin_define
define|#
directive|define
name|SCSI_COMM
value|0x09
end_define

begin_comment
comment|/* Communications device	   */
end_comment

begin_define
define|#
directive|define
name|SCSI_NODEV
value|0x1F
end_define

begin_comment
comment|/* Unknown or no device type    */
end_comment

begin_comment
comment|/* ** Inquiry flag definitions (Inq data byte 7) */
end_comment

begin_define
define|#
directive|define
name|SCSI_INQ_RELADR
value|0x80
end_define

begin_comment
comment|/* device supports relative addressing*/
end_comment

begin_define
define|#
directive|define
name|SCSI_INQ_WBUS32
value|0x40
end_define

begin_comment
comment|/* device supports 32 bit data xfers  */
end_comment

begin_define
define|#
directive|define
name|SCSI_INQ_WBUS16
value|0x20
end_define

begin_comment
comment|/* device supports 16 bit data xfers  */
end_comment

begin_define
define|#
directive|define
name|SCSI_INQ_SYNC
value|0x10
end_define

begin_comment
comment|/* device supports synchronous xfer   */
end_comment

begin_define
define|#
directive|define
name|SCSI_INQ_LINKED
value|0x08
end_define

begin_comment
comment|/* device supports linked commands    */
end_comment

begin_define
define|#
directive|define
name|SCSI_INQ_CMDQUEUE
value|0x02
end_define

begin_comment
comment|/* device supports command queueing   */
end_comment

begin_define
define|#
directive|define
name|SCSI_INQ_SFTRE
value|0x01
end_define

begin_comment
comment|/* device supports soft resets */
end_comment

begin_comment
comment|/* ;========================================================== ; EEPROM byte offset ;========================================================== */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EEprom
block|{
name|UCHAR
name|EE_MODE1
decl_stmt|;
name|UCHAR
name|EE_SPEED
decl_stmt|;
name|UCHAR
name|xx1
decl_stmt|;
name|UCHAR
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

begin_comment
comment|/*; EE_MODE1 bits definition*/
end_comment

begin_define
define|#
directive|define
name|PARITY_CHK_
value|BIT0
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_
value|BIT1
end_define

begin_define
define|#
directive|define
name|EN_DISCONNECT_
value|BIT2
end_define

begin_define
define|#
directive|define
name|SEND_START_
value|BIT3
end_define

begin_define
define|#
directive|define
name|TAG_QUEUING_
value|BIT4
end_define

begin_comment
comment|/*; EE_MODE2 bits definition*/
end_comment

begin_define
define|#
directive|define
name|MORE2_DRV
value|BIT0
end_define

begin_define
define|#
directive|define
name|GREATER_1G
value|BIT1
end_define

begin_define
define|#
directive|define
name|RST_SCSI_BUS
value|BIT2
end_define

begin_define
define|#
directive|define
name|ACTIVE_NEGATION
value|BIT3
end_define

begin_define
define|#
directive|define
name|NO_SEEK
value|BIT4
end_define

begin_define
define|#
directive|define
name|LUN_CHECK
value|BIT5
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

begin_comment
comment|/* ;========================================================== ;	AMD 53C974 Registers bit Definition ;========================================================== */
end_comment

begin_comment
comment|/* ;==================== ; SCSI Register ;==================== */
end_comment

begin_comment
comment|/*; Command Reg.(+0CH) */
end_comment

begin_define
define|#
directive|define
name|DMA_COMMAND
value|BIT7
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
name|SELECT_W_ATN
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
comment|/*; SCSI Status Reg.(+10H) */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT
value|BIT7
end_define

begin_define
define|#
directive|define
name|ILLEGAL_OP_ERR
value|BIT6
end_define

begin_define
define|#
directive|define
name|PARITY_ERR
value|BIT5
end_define

begin_define
define|#
directive|define
name|COUNT_2_ZERO
value|BIT4
end_define

begin_define
define|#
directive|define
name|GROUP_CODE_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|SCSI_PHASE_MASK
value|(BIT2+BIT1+BIT0)
end_define

begin_comment
comment|/*; Interrupt Status Reg.(+14H) */
end_comment

begin_define
define|#
directive|define
name|SCSI_RESET_
value|BIT7
end_define

begin_define
define|#
directive|define
name|INVALID_CMD
value|BIT6
end_define

begin_define
define|#
directive|define
name|DISCONNECTED
value|BIT5
end_define

begin_define
define|#
directive|define
name|SERVICE_REQUEST
value|BIT4
end_define

begin_define
define|#
directive|define
name|SUCCESSFUL_OP
value|BIT3
end_define

begin_define
define|#
directive|define
name|RESELECTED
value|BIT2
end_define

begin_define
define|#
directive|define
name|SEL_ATTENTION
value|BIT1
end_define

begin_define
define|#
directive|define
name|SELECTED
value|BIT0
end_define

begin_comment
comment|/*; Internal State Reg.(+18H) */
end_comment

begin_define
define|#
directive|define
name|SYNC_OFFSET_FLAG
value|BIT3
end_define

begin_define
define|#
directive|define
name|INTRN_STATE_MASK
value|(BIT2+BIT1+BIT0)
end_define

begin_comment
comment|/*; Clock Factor Reg.(+24H) */
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
value|(BIT2+BIT1+BIT0)
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_30MHZ
value|(BIT2+BIT1)
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_25MHZ
value|(BIT2+BIT0)
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_20MHZ
value|BIT2
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_15MHZ
value|(BIT1+BIT0)
end_define

begin_define
define|#
directive|define
name|CLK_FREQ_10MHZ
value|BIT1
end_define

begin_comment
comment|/*; Control Reg. 1(+20H) */
end_comment

begin_define
define|#
directive|define
name|EXTENDED_TIMING
value|BIT7
end_define

begin_define
define|#
directive|define
name|DIS_INT_ON_SCSI_RST
value|BIT6
end_define

begin_define
define|#
directive|define
name|PARITY_ERR_REPO
value|BIT4
end_define

begin_define
define|#
directive|define
name|SCSI_ID_ON_BUS
value|(BIT2+BIT1+BIT0)
end_define

begin_comment
comment|/*; Control Reg. 2(+2CH) */
end_comment

begin_define
define|#
directive|define
name|EN_FEATURE
value|BIT6
end_define

begin_define
define|#
directive|define
name|EN_SCSI2_CMD
value|BIT3
end_define

begin_comment
comment|/*; Control Reg. 3(+30H) */
end_comment

begin_define
define|#
directive|define
name|ID_MSG_CHECK
value|BIT7
end_define

begin_define
define|#
directive|define
name|EN_QTAG_MSG
value|BIT6
end_define

begin_define
define|#
directive|define
name|EN_GRP2_CMD
value|BIT5
end_define

begin_define
define|#
directive|define
name|FAST_SCSI
value|BIT4
end_define

begin_comment
comment|/* ;10MB/SEC */
end_comment

begin_define
define|#
directive|define
name|FAST_CLK
value|BIT3
end_define

begin_comment
comment|/* ;25 - 40 MHZ */
end_comment

begin_comment
comment|/*; Control Reg. 4(+34H) */
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
value|BIT7
end_define

begin_define
define|#
directive|define
name|EATER_35NS
value|BIT6
end_define

begin_define
define|#
directive|define
name|EATER_0NS
value|(BIT7+BIT6)
end_define

begin_define
define|#
directive|define
name|NEGATE_REQACKDATA
value|BIT2
end_define

begin_define
define|#
directive|define
name|NEGATE_REQACK
value|BIT3
end_define

begin_comment
comment|/* ;==================== ; DMA Register ;==================== */
end_comment

begin_comment
comment|/*; DMA Command Reg.(+40H) */
end_comment

begin_define
define|#
directive|define
name|READ_DIRECTION
value|BIT7
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
value|BIT6
end_define

begin_define
define|#
directive|define
name|MAP_TO_MDL
value|BIT5
end_define

begin_define
define|#
directive|define
name|DIAGNOSTIC
value|BIT4
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
value|BIT0
end_define

begin_define
define|#
directive|define
name|DMA_ABORT_CMD
value|BIT1
end_define

begin_define
define|#
directive|define
name|DMA_START_CMD
value|(BIT1+BIT0)
end_define

begin_comment
comment|/*; DMA Status Reg.(+54H) */
end_comment

begin_define
define|#
directive|define
name|PCI_MS_ABORT
value|BIT6
end_define

begin_define
define|#
directive|define
name|BLAST_COMPLETE
value|BIT5
end_define

begin_define
define|#
directive|define
name|SCSI_INTERRUPT
value|BIT4
end_define

begin_define
define|#
directive|define
name|DMA_XFER_DONE
value|BIT3
end_define

begin_define
define|#
directive|define
name|DMA_XFER_ABORT
value|BIT2
end_define

begin_define
define|#
directive|define
name|DMA_XFER_ERROR
value|BIT1
end_define

begin_define
define|#
directive|define
name|POWER_DOWN
value|BIT0
end_define

begin_comment
comment|/* ; DMA SCSI Bus and Ctrl.(+70H) ;EN_INT_ON_PCI_ABORT */
end_comment

begin_comment
comment|/* ;========================================================== ; SCSI Chip register address offset ;========================================================== */
end_comment

begin_define
define|#
directive|define
name|CtcReg_Low
value|0x00
end_define

begin_define
define|#
directive|define
name|CtcReg_Mid
value|0x04
end_define

begin_define
define|#
directive|define
name|ScsiFifo
value|0x08
end_define

begin_define
define|#
directive|define
name|ScsiCmd
value|0x0C
end_define

begin_define
define|#
directive|define
name|Scsi_Status
value|0x10
end_define

begin_define
define|#
directive|define
name|INT_Status
value|0x14
end_define

begin_define
define|#
directive|define
name|Sync_Period
value|0x18
end_define

begin_define
define|#
directive|define
name|Sync_Offset
value|0x1C
end_define

begin_define
define|#
directive|define
name|CtrlReg1
value|0x20
end_define

begin_define
define|#
directive|define
name|Clk_Factor
value|0x24
end_define

begin_define
define|#
directive|define
name|CtrlReg2
value|0x2C
end_define

begin_define
define|#
directive|define
name|CtrlReg3
value|0x30
end_define

begin_define
define|#
directive|define
name|CtrlReg4
value|0x34
end_define

begin_define
define|#
directive|define
name|CtcReg_High
value|0x38
end_define

begin_define
define|#
directive|define
name|DMA_Cmd
value|0x40
end_define

begin_define
define|#
directive|define
name|DMA_XferCnt
value|0x44
end_define

begin_define
define|#
directive|define
name|DMA_XferAddr
value|0x48
end_define

begin_define
define|#
directive|define
name|DMA_Wk_ByteCntr
value|0x4C
end_define

begin_define
define|#
directive|define
name|DMA_Wk_AddrCntr
value|0x50
end_define

begin_define
define|#
directive|define
name|DMA_Status
value|0x54
end_define

begin_define
define|#
directive|define
name|DMA_MDL_Addr
value|0x58
end_define

begin_define
define|#
directive|define
name|DMA_Wk_MDL_Cntr
value|0x5C
end_define

begin_define
define|#
directive|define
name|DMA_ScsiBusCtrl
value|0x70
end_define

begin_define
define|#
directive|define
name|StcReg_Low
value|CtcReg_Low
end_define

begin_define
define|#
directive|define
name|StcReg_Mid
value|CtcReg_Mid
end_define

begin_define
define|#
directive|define
name|Scsi_Dest_ID
value|Scsi_Status
end_define

begin_define
define|#
directive|define
name|Scsi_TimeOut
value|INT_Status
end_define

begin_define
define|#
directive|define
name|Intern_State
value|Sync_Period
end_define

begin_define
define|#
directive|define
name|Current_Fifo
value|Sync_Offset
end_define

begin_define
define|#
directive|define
name|StcReg_High
value|CtcReg_High
end_define

begin_define
define|#
directive|define
name|am_target
value|Scsi_Status
end_define

begin_define
define|#
directive|define
name|am_timeout
value|INT_Status
end_define

begin_define
define|#
directive|define
name|am_seq_step
value|Sync_Period
end_define

begin_define
define|#
directive|define
name|am_fifo_count
value|Sync_Offset
end_define

begin_define
define|#
directive|define
name|DC390_read8
parameter_list|(
name|address
parameter_list|)
define|\
value|inb(DC390_ioport + (address)))
end_define

begin_define
define|#
directive|define
name|DC390_read16
parameter_list|(
name|address
parameter_list|)
define|\
value|inw(DC390_ioport + (address)))
end_define

begin_define
define|#
directive|define
name|DC390_read32
parameter_list|(
name|address
parameter_list|)
define|\
value|inl(DC390_ioport + (address)))
end_define

begin_define
define|#
directive|define
name|DC390_write8
parameter_list|(
name|address
parameter_list|,
name|value
parameter_list|)
define|\
value|outb((value), DC390_ioport + (address)))
end_define

begin_define
define|#
directive|define
name|DC390_write16
parameter_list|(
name|address
parameter_list|,
name|value
parameter_list|)
define|\
value|outw((value), DC390_ioport + (address)))
end_define

begin_define
define|#
directive|define
name|DC390_write32
parameter_list|(
name|address
parameter_list|,
name|value
parameter_list|)
define|\
value|outl((value), DC390_ioport + (address)))
end_define

begin_comment
comment|/* Configuration method #1 */
end_comment

begin_define
define|#
directive|define
name|PCI_CFG1_ADDRESS_REG
value|0xcf8
end_define

begin_define
define|#
directive|define
name|PCI_CFG1_DATA_REG
value|0xcfc
end_define

begin_define
define|#
directive|define
name|PCI_CFG1_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PCI_CFG1_TUPPLE
parameter_list|(
name|bus
parameter_list|,
name|device
parameter_list|,
name|function
parameter_list|,
specifier|register
parameter_list|)
define|\
value|(PCI_CFG1_ENABLE | (((bus)<< 16)& 0xff0000) | 		\ 	(((device)<< 11)& 0xf800) | (((function)<< 8)& 0x700)|	\ 	(((register)<< 2)& 0xfc))
end_define

begin_comment
comment|/* Configuration method #2 */
end_comment

begin_define
define|#
directive|define
name|PCI_CFG2_ENABLE_REG
value|0xcf8
end_define

begin_define
define|#
directive|define
name|PCI_CFG2_FORWARD_REG
value|0xcfa
end_define

begin_define
define|#
directive|define
name|PCI_CFG2_ENABLE
value|0x0f0
end_define

begin_define
define|#
directive|define
name|PCI_CFG2_TUPPLE
parameter_list|(
name|function
parameter_list|)
define|\
value|(PCI_CFG2_ENABLE | (((function)<< 1)& 0xe))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEK390_H */
end_comment

end_unit

