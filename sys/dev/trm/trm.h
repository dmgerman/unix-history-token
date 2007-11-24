begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *	File Name : trm.h	  *				      *	Tekram DC395U/UW/F ,DC315/U   *   PCI SCSI Bus Master Host Adapter Device Driver	  *   (SCSI chip set used Tekram ASIC TRM-S1040)	  *  * (C)Copyright 1995-2001 Tekram Technology Co.,Ltd.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.	  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|trm_H
end_ifndef

begin_define
define|#
directive|define
name|trm_H
end_define

begin_comment
comment|/* SCSI CAM */
end_comment

begin_define
define|#
directive|define
name|TRM_TRANS_CUR
value|0x01
end_define

begin_comment
comment|/* Modify current neogtiation status */
end_comment

begin_define
define|#
directive|define
name|TRM_TRANS_ACTIVE
value|0x03
end_define

begin_comment
comment|/* Assume this is the active target */
end_comment

begin_define
define|#
directive|define
name|TRM_TRANS_GOAL
value|0x04
end_define

begin_comment
comment|/* Modify negotiation goal */
end_comment

begin_define
define|#
directive|define
name|TRM_TRANS_USER
value|0x08
end_define

begin_comment
comment|/* Modify user negotiation settings */
end_comment

begin_struct
struct|struct
name|trm_transinfo
block|{
name|u_int8_t
name|width
decl_stmt|;
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
name|trm_target_info
block|{
name|u_int8_t
name|disc_tag
decl_stmt|;
comment|/* bits define..... */
define|#
directive|define
name|TRM_CUR_DISCENB
value|0x01
comment|/* current setting disconnect enable */
define|#
directive|define
name|TRM_CUR_TAGENB
value|0x02
comment|/* current setting tag command Q enable */
define|#
directive|define
name|TRM_USR_DISCENB
value|0x04
comment|/* user adapter device setting disconnect enable */
define|#
directive|define
name|TRM_USR_TAGENB
value|0x08
comment|/* user adapter device setting tag command Q enable*/
name|struct
name|trm_transinfo
name|current
decl_stmt|;
comment|/* info of current */
name|struct
name|trm_transinfo
name|goal
decl_stmt|;
comment|/* info of after negotiating */
name|struct
name|trm_transinfo
name|user
decl_stmt|;
comment|/* info of user adapter device setting  */
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI CAM  **  */
end_comment

begin_comment
comment|/*  *	bus_dma_segment_t  *  *	Describes a single contiguous DMA transaction.  Values  *	are suitable for programming into DMA registers.  *  *typedef struct bus_dma_segment   *{  *	bus_addr_t	ds_addr;	// DMA address  *	bus_size_t	ds_len;		// length of transfer  *} bus_dma_segment_t;  */
end_comment

begin_comment
comment|/*;----------------------Segment Entry------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SGentry
block|{
name|u_int32_t
name|address
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
block|}
name|SGentry
operator|,
typedef|*
name|PSEG
typedef|;
end_typedef

begin_comment
comment|/*  *-----------------------------------------------------------------------  *     feature of chip set MAX value  *-----------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|TRM_MAX_ADAPTER_NUM
value|4
end_define

begin_define
define|#
directive|define
name|TRM_MAX_DEVICES
value|16
end_define

begin_define
define|#
directive|define
name|TRM_MAX_SG_LISTENTRY
value|32
end_define

begin_define
define|#
directive|define
name|TRM_MAX_TARGETS
value|16
end_define

begin_define
define|#
directive|define
name|TRM_MAX_TAGS_CMD_QUEUE
value|256
end_define

begin_comment
comment|/* MAX_CMD_QUEUE	20*/
end_comment

begin_define
define|#
directive|define
name|TRM_MAX_CMD_PER_LUN
value|32
end_define

begin_define
define|#
directive|define
name|TRM_MAX_SRB_CNT
value|256
end_define

begin_define
define|#
directive|define
name|TRM_MAX_START_JOB
value|256
end_define

begin_define
define|#
directive|define
name|TRM_NSEG
value|(btoc(MAXPHYS) + 1)
end_define

begin_define
define|#
directive|define
name|TRM_MAXTRANSFER_SIZE
value|0xFFFFFF
end_define

begin_comment
comment|/* restricted by 24 bit counter */
end_comment

begin_define
define|#
directive|define
name|PAGELEN
value|4096
end_define

begin_define
define|#
directive|define
name|SEL_TIMEOUT
value|153
end_define

begin_comment
comment|/* 250 ms selection timeout (@ 40MHz) */
end_comment

begin_comment
comment|/*  *  CAM ccb  * Union of all CCB types for kernel space allocation.  This union should  * never be used for manipulating CCBs - its only use is for the allocation  * and deallocation of raw CCB space and is the return type of xpt_ccb_alloc  * and the argument to xpt_ccb_free.  *   *union ccb {  *	struct	ccb_hdr		   	    ccb_h;	// For convenience   *	struct	ccb_scsiio	        csio;  *	struct	ccb_getdev	        cgd;  *	struct	ccb_getdevlist  	cgdl;  *	struct	ccb_pathinq		    cpi;  *	struct	ccb_relsim	    	crs;  *	struct	ccb_setasync		csa;  *	struct	ccb_setdev	    	csd;  *	struct	ccb_dev_match		cdm;  *	struct	ccb_trans_settings	cts;  *	struct	ccb_calc_geometry	ccg;	  *	struct	ccb_abort	    	cab;  *	struct	ccb_resetbus		crb;  *	struct	ccb_resetdev		crd;  *	struct	ccb_termio	    	tio;  *	struct	ccb_accept_tio		atio;  *	struct	ccb_scsiio	    	ctio;  *	struct	ccb_en_lun	    	cel;  *	struct	ccb_immed_notify	cin;  *	struct	ccb_notify_ack		cna;  *	struct	ccb_eng_inq	    	cei;  *	struct	ccb_eng_exec		cee;  *	struct 	ccb_rescan	    	crcn;  *	struct  ccb_debug	    	cdbg;  *  };  */
end_comment

begin_comment
comment|/*  *-----------------------------------------------------------------------  *               SCSI Request Block  *-----------------------------------------------------------------------  */
end_comment

begin_struct
struct|struct
name|_SRB
block|{
name|u_int8_t
name|CmdBlock
index|[
literal|12
index|]
decl_stmt|;
name|u_long
name|Segment0
index|[
literal|2
index|]
decl_stmt|;
name|u_long
name|Segment1
index|[
literal|2
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
name|SGentry
name|SgSenseTemp
decl_stmt|;
name|PSEG
name|pSRBSGL
decl_stmt|;
comment|/* scatter gather list */
name|u_int32_t
name|SRBSGPhyAddr
decl_stmt|;
comment|/* a segment starting address */
name|u_int32_t
name|SRBTotalXferLength
decl_stmt|;
comment|/* 	 *	          CAM ccb 	 */
name|union
name|ccb
modifier|*
name|pccb
decl_stmt|;
name|bus_dmamap_t
name|sg_dmamap
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|u_int16_t
name|SRBState
decl_stmt|;
name|u_int8_t
modifier|*
name|pMsgPtr
decl_stmt|;
name|u_int8_t
name|SRBSGCount
decl_stmt|;
name|u_int8_t
name|SRBSGIndex
decl_stmt|;
name|u_int8_t
name|MsgInBuf
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|MsgOutBuf
index|[
literal|6
index|]
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
name|TagNumber
decl_stmt|;
name|u_int8_t
name|SRBStatus
decl_stmt|;
name|u_int8_t
name|RetryCnt
decl_stmt|;
name|u_int8_t
name|SRBFlag
decl_stmt|;
name|u_int8_t
name|ScsiCmdLen
decl_stmt|;
name|u_int8_t
name|ScsiPhase
decl_stmt|;
name|u_int8_t
name|Reserved
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
name|TRM_SRB
typedef|,
modifier|*
name|PSRB
typedef|;
end_typedef

begin_comment
comment|/*  *-----------------------------------------------------------------------  *                   Device Control Block  *-----------------------------------------------------------------------  */
end_comment

begin_struct
struct|struct
name|_DCB
block|{
name|PSRB
name|pWaitingSRB
decl_stmt|;
name|PSRB
name|pWaitingLastSRB
decl_stmt|;
name|PSRB
name|pGoingSRB
decl_stmt|;
name|PSRB
name|pGoingLastSRB
decl_stmt|;
name|PSRB
name|pActiveSRB
decl_stmt|;
name|u_int16_t
name|GoingSRBCnt
decl_stmt|;
name|u_int16_t
name|MaxActiveCommandCnt
decl_stmt|;
name|u_int8_t
name|TargetID
decl_stmt|;
comment|/*; SCSI Target ID  (SCSI Only) */
name|u_int8_t
name|TargetLUN
decl_stmt|;
comment|/*; SCSI Log.  Unit (SCSI Only) */
name|u_int8_t
name|DCBFlag
decl_stmt|;
name|u_int8_t
name|DevType
decl_stmt|;
name|u_int8_t
name|SyncMode
decl_stmt|;
comment|/* mode ? (1 sync):(0 async)  */
name|u_int8_t
name|MaxNegoPeriod
decl_stmt|;
comment|/* for nego. */
name|u_int8_t
name|SyncPeriod
decl_stmt|;
comment|/* for reg. */
name|u_int8_t
name|SyncOffset
decl_stmt|;
comment|/* for reg. and nego.(low nibble) */
name|u_int8_t
name|DevMode
decl_stmt|;
name|u_int8_t
name|AdpMode
decl_stmt|;
name|u_int8_t
name|IdentifyMsg
decl_stmt|;
name|u_int8_t
name|DCBstatus
decl_stmt|;
comment|/* DCB status */
comment|/*u_int8_t	Reserved[3];	for dword alignment */
name|struct
name|trm_target_info
name|tinfo
decl_stmt|;
comment|/* 10 bytes */
name|struct
name|_DCB
modifier|*
name|pNextDCB
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_DCB
name|TRM_DCB
typedef|,
modifier|*
name|PDCB
typedef|;
end_typedef

begin_comment
comment|/*  *-----------------------------------------------------------------------  *                  Adapter Control Block  *-----------------------------------------------------------------------  */
end_comment

begin_struct
struct|struct
name|_ACB
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
name|parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* dmat for buffer I/O */
name|bus_dma_tag_t
name|srb_dmat
decl_stmt|;
name|bus_dma_tag_t
name|sense_dmat
decl_stmt|;
comment|/* dmat for sense buffer */
name|bus_dma_tag_t
name|sg_dmat
decl_stmt|;
name|bus_dmamap_t
name|sense_dmamap
decl_stmt|;
name|bus_dmamap_t
name|srb_dmamap
decl_stmt|;
name|bus_addr_t
name|sense_busaddr
decl_stmt|;
name|struct
name|scsi_sense_data
modifier|*
name|sense_buffers
decl_stmt|;
name|struct
name|resource
modifier|*
name|iores
decl_stmt|,
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
comment|/*      *	          CAM SIM/XPT      */
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
name|TRM_SRB
name|TmpSRB
decl_stmt|;
name|TRM_DCB
name|DCBarray
index|[
literal|16
index|]
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|srb_physbase
decl_stmt|;
name|PSRB
name|pFreeSRB
decl_stmt|;
name|PDCB
name|pActiveDCB
decl_stmt|;
name|PDCB
name|pLinkDCB
decl_stmt|;
name|PDCB
name|pDCBRunRobin
decl_stmt|;
name|u_int16_t
name|max_id
decl_stmt|;
name|u_int16_t
name|max_lun
decl_stmt|;
name|u_int8_t
name|msgin123
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|scan_devices
index|[
literal|16
index|]
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|AdaptSCSIID
decl_stmt|;
comment|/*; Adapter SCSI Target ID */
name|u_int8_t
name|AdaptSCSILUN
decl_stmt|;
comment|/*; Adapter SCSI LUN */
name|u_int8_t
name|DeviceCnt
decl_stmt|;
name|u_int8_t
name|ACBFlag
decl_stmt|;
name|u_int8_t
name|TagMaxNum
decl_stmt|;
name|u_int8_t
name|Config
decl_stmt|;
name|u_int8_t
name|AdaptType
decl_stmt|;
name|u_int8_t
name|AdapterUnit
decl_stmt|;
comment|/* nth Adapter this driver */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_ACB
name|TRM_ACB
typedef|,
modifier|*
name|PACB
typedef|;
end_typedef

begin_comment
comment|/*  *   ----SRB State machine definition  */
end_comment

begin_define
define|#
directive|define
name|SRB_FREE
value|0x0000
end_define

begin_define
define|#
directive|define
name|SRB_WAIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|SRB_READY
value|0x0002
end_define

begin_define
define|#
directive|define
name|SRB_MSGOUT
value|0x0004
end_define

begin_comment
comment|/*arbitration+msg_out 1st byte*/
end_comment

begin_define
define|#
directive|define
name|SRB_MSGIN
value|0x0008
end_define

begin_define
define|#
directive|define
name|SRB_EXTEND_MSGIN
value|0x0010
end_define

begin_define
define|#
directive|define
name|SRB_COMMAND
value|0x0020
end_define

begin_define
define|#
directive|define
name|SRB_START_
value|0x0040
end_define

begin_comment
comment|/*arbitration+msg_out+command_out*/
end_comment

begin_define
define|#
directive|define
name|SRB_DISCONNECT
value|0x0080
end_define

begin_define
define|#
directive|define
name|SRB_DATA_XFER
value|0x0100
end_define

begin_define
define|#
directive|define
name|SRB_XFERPAD
value|0x0200
end_define

begin_define
define|#
directive|define
name|SRB_STATUS
value|0x0400
end_define

begin_define
define|#
directive|define
name|SRB_COMPLETED
value|0x0800
end_define

begin_define
define|#
directive|define
name|SRB_ABORT_SENT
value|0x1000
end_define

begin_define
define|#
directive|define
name|SRB_DO_SYNC_NEGO
value|0x2000
end_define

begin_define
define|#
directive|define
name|SRB_DO_WIDE_NEGO
value|0x4000
end_define

begin_define
define|#
directive|define
name|SRB_UNEXPECT_RESEL
value|0x8000
end_define

begin_comment
comment|/*  *  *      ACB Config	  *  */
end_comment

begin_define
define|#
directive|define
name|HCC_WIDE_CARD
value|0x20
end_define

begin_define
define|#
directive|define
name|HCC_SCSI_RESET
value|0x10
end_define

begin_define
define|#
directive|define
name|HCC_PARITY
value|0x08
end_define

begin_define
define|#
directive|define
name|HCC_AUTOTERM
value|0x04
end_define

begin_define
define|#
directive|define
name|HCC_LOW8TERM
value|0x02
end_define

begin_define
define|#
directive|define
name|HCC_UP8TERM
value|0x01
end_define

begin_comment
comment|/*  *   ---ACB Flag  */
end_comment

begin_define
define|#
directive|define
name|RESET_DEV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RESET_DETECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RESET_DONE
value|0x00000004
end_define

begin_comment
comment|/*  *   ---DCB Flag  */
end_comment

begin_define
define|#
directive|define
name|ABORT_DEV_
value|0x00000001
end_define

begin_comment
comment|/*  *   ---DCB status  */
end_comment

begin_define
define|#
directive|define
name|DS_IN_QUEUE
value|0x00000001
end_define

begin_comment
comment|/*  *   ---SRB status   */
end_comment

begin_define
define|#
directive|define
name|SRB_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ABORTION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OVER_RUN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|UNDER_RUN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PARITY_ERROR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SRB_ERROR
value|0x00000020
end_define

begin_comment
comment|/*  *   ---SRB Flag   */
end_comment

begin_define
define|#
directive|define
name|DATAOUT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DATAIN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RESIDUAL_VALID
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ENABLE_TIMER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RESET_DEV0
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ABORT_DEV
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AUTO_REQSENSE
value|0x00000001
end_define

begin_comment
comment|/*  *   ---Adapter status  */
end_comment

begin_define
define|#
directive|define
name|H_STATUS_GOOD
value|0x00
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
comment|/*  *   ---SCSI Status byte codes  */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_GOOD
value|0x00
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
comment|/*  *   ---Sync_Mode  */
end_comment

begin_define
define|#
directive|define
name|SYNC_WIDE_TAG_ATNT_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WIDE_NEGO_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WIDE_NEGO_DONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EN_TAG_QUEUING
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EN_ATN_STOP
value|0x00000020
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
comment|/*  *     ----SCSI MSG u_int8_t  */
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

begin_comment
comment|/* #define MSG_ABORT_TAG	    	0x0D */
end_comment

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
name|MSG_IGNOREWIDE
value|0x23
end_define

begin_comment
comment|/* #define MSG_IDENTIFY	    		0x80 */
end_comment

begin_define
define|#
directive|define
name|MSG_HOST_ID
value|0xC0
end_define

begin_comment
comment|/*     bus wide length     */
end_comment

begin_define
define|#
directive|define
name|MSG_EXT_WDTR_BUS_8_BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG_EXT_WDTR_BUS_16_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG_EXT_WDTR_BUS_32_BIT
value|0x02
end_define

begin_comment
comment|/*  *     ----SCSI STATUS u_int8_t  */
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
comment|/*  *     ---- cmd->result  */
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
comment|/*  *  Inquiry Data format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SCSIInqData
block|{
comment|/* INQ */
name|u_int8_t
name|DevType
decl_stmt|;
comment|/* Periph Qualifier& Periph Dev Type */
name|u_int8_t
name|RMB_TypeMod
decl_stmt|;
comment|/* rem media bit& Dev Type Modifier  */
name|u_int8_t
name|Vers
decl_stmt|;
comment|/* ISO, ECMA,& ANSI versions	      */
name|u_int8_t
name|RDF
decl_stmt|;
comment|/* AEN, TRMIOP,& response data format*/
name|u_int8_t
name|AddLen
decl_stmt|;
comment|/* length of additional data	      */
name|u_int8_t
name|Res1
decl_stmt|;
comment|/* reserved	                      */
name|u_int8_t
name|Res2
decl_stmt|;
comment|/* reserved	                      */
name|u_int8_t
name|Flags
decl_stmt|;
comment|/* RelADr,Wbus32,Wbus16,Sync,etc.     */
name|u_int8_t
name|VendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* Vendor Identification	      */
name|u_int8_t
name|ProductID
index|[
literal|16
index|]
decl_stmt|;
comment|/* Product Identification          */
name|u_int8_t
name|ProductRev
index|[
literal|4
index|]
decl_stmt|;
comment|/* Product Revision              */
block|}
name|SCSI_INQDATA
operator|,
typedef|*
name|PSCSI_INQDATA
typedef|;
end_typedef

begin_comment
comment|/*    *      Inquiry byte 0 masks   */
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
comment|/* Peripheral Qualifier	    */
end_comment

begin_comment
comment|/*   *      Inquiry byte 1 mask  */
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
comment|/*   *      Peripheral Device Type definitions  */
end_comment

begin_define
define|#
directive|define
name|SCSI_DASD
value|0x00
end_define

begin_comment
comment|/* Direct-access Device	  */
end_comment

begin_define
define|#
directive|define
name|SCSI_SEQACESS
value|0x01
end_define

begin_comment
comment|/* Sequential-access device	  */
end_comment

begin_define
define|#
directive|define
name|SCSI_PRINTER
value|0x02
end_define

begin_comment
comment|/* Printer device		  */
end_comment

begin_define
define|#
directive|define
name|SCSI_PROCESSOR
value|0x03
end_define

begin_comment
comment|/* Processor device		  */
end_comment

begin_define
define|#
directive|define
name|SCSI_WRITEONCE
value|0x04
end_define

begin_comment
comment|/* Write-once device 	  */
end_comment

begin_define
define|#
directive|define
name|SCSI_CDROM
value|0x05
end_define

begin_comment
comment|/* CD-ROM device		  */
end_comment

begin_define
define|#
directive|define
name|SCSI_SCANNER
value|0x06
end_define

begin_comment
comment|/* Scanner device		  */
end_comment

begin_define
define|#
directive|define
name|SCSI_OPTICAL
value|0x07
end_define

begin_comment
comment|/* Optical memory device	  */
end_comment

begin_define
define|#
directive|define
name|SCSI_MEDCHGR
value|0x08
end_define

begin_comment
comment|/* Medium changer device	  */
end_comment

begin_define
define|#
directive|define
name|SCSI_COMM
value|0x09
end_define

begin_comment
comment|/* Communications device	  */
end_comment

begin_define
define|#
directive|define
name|SCSI_NODEV
value|0x1F
end_define

begin_comment
comment|/* Unknown or no device type   */
end_comment

begin_comment
comment|/*  *      Inquiry flag definitions (Inq data byte 7)  */
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
comment|/*  *==========================================================  *                EEPROM byte offset  *==========================================================  */
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

begin_comment
comment|/*  *    EE_MODE1 bits definition  */
end_comment

begin_define
define|#
directive|define
name|PARITY_CHK_
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SYNC_NEGO_
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EN_DISCONNECT_
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SEND_START_
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TAG_QUEUING_
value|0x00000010
end_define

begin_comment
comment|/*  *    EE_MODE2 bits definition  */
end_comment

begin_define
define|#
directive|define
name|MORE2_DRV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GREATER_1G
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RST_SCSI_BUS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACTIVE_NEGATION
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NO_SEEK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LUN_CHECK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ENABLE_CE
value|0x01
end_define

begin_define
define|#
directive|define
name|DISABLE_CE
value|0x00
end_define

begin_define
define|#
directive|define
name|EEPROM_READ
value|0x80
end_define

begin_comment
comment|/*  * The PCI configuration register offset for TRM_S1040	  *                  Registers bit Definition		  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_ID
value|0x00
end_define

begin_comment
comment|/* Vendor and Device ID	     	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_COMMAND
value|0x04
end_define

begin_comment
comment|/* PCI command register	       	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_IOBASE
value|0x10
end_define

begin_comment
comment|/* I/O Space base address     	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_ROMBASE
value|0x30
end_define

begin_comment
comment|/* Expansion ROM Base Address  	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_INTLINE
value|0x3C
end_define

begin_comment
comment|/* Interrupt line	       	*/
end_comment

begin_comment
comment|/*  *  * The SCSI register offset for TRM_S1040		  *  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_STATUS
value|0x80
end_define

begin_comment
comment|/* SCSI Status (R)	      	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|COMMANDPHASEDONE
value|0x2000
end_define

begin_comment
comment|/* SCSI command phase done     	*/
end_comment

begin_define
define|#
directive|define
name|SCSIXFERDONE
value|0x0800
end_define

begin_comment
comment|/* SCSI SCSI transfer done	*/
end_comment

begin_define
define|#
directive|define
name|SCSIXFERCNT_2_ZERO
value|0x0100
end_define

begin_comment
comment|/* SCSI SCSI transfer count to zero*/
end_comment

begin_define
define|#
directive|define
name|SCSIINTERRUPT
value|0x0080
end_define

begin_comment
comment|/* SCSI interrupt pending     	*/
end_comment

begin_define
define|#
directive|define
name|COMMANDABORT
value|0x0040
end_define

begin_comment
comment|/* SCSI command abort	       	*/
end_comment

begin_define
define|#
directive|define
name|SEQUENCERACTIVE
value|0x0020
end_define

begin_comment
comment|/* SCSI sequencer active       	*/
end_comment

begin_define
define|#
directive|define
name|PHASEMISMATCH
value|0x0010
end_define

begin_comment
comment|/* SCSI phase mismatch	       	*/
end_comment

begin_define
define|#
directive|define
name|PARITYERROR
value|0x0008
end_define

begin_comment
comment|/* SCSI parity error	       	*/
end_comment

begin_define
define|#
directive|define
name|PHASEMASK
value|0x0007
end_define

begin_comment
comment|/* Phase MSG/CD/IO	       	*/
end_comment

begin_define
define|#
directive|define
name|PH_DATA_OUT
value|0x00
end_define

begin_comment
comment|/* Data out phase      	*/
end_comment

begin_define
define|#
directive|define
name|PH_DATA_IN
value|0x01
end_define

begin_comment
comment|/* Data in phase       	*/
end_comment

begin_define
define|#
directive|define
name|PH_COMMAND
value|0x02
end_define

begin_comment
comment|/* Command phase       	*/
end_comment

begin_define
define|#
directive|define
name|PH_STATUS
value|0x03
end_define

begin_comment
comment|/* Status phase	       	*/
end_comment

begin_define
define|#
directive|define
name|PH_BUS_FREE
value|0x05
end_define

begin_comment
comment|/* Invalid phase used as bus free	*/
end_comment

begin_define
define|#
directive|define
name|PH_MSG_OUT
value|0x06
end_define

begin_comment
comment|/* Message out phase   	*/
end_comment

begin_define
define|#
directive|define
name|PH_MSG_IN
value|0x07
end_define

begin_comment
comment|/* Message in phase    	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_CONTROL
value|0x80
end_define

begin_comment
comment|/* SCSI Control (W)	       	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|DO_CLRATN
value|0x0400
end_define

begin_comment
comment|/* Clear ATN	        	*/
end_comment

begin_define
define|#
directive|define
name|DO_SETATN
value|0x0200
end_define

begin_comment
comment|/* Set ATN		       	*/
end_comment

begin_define
define|#
directive|define
name|DO_CMDABORT
value|0x0100
end_define

begin_comment
comment|/* Abort SCSI command   	*/
end_comment

begin_define
define|#
directive|define
name|DO_RSTMODULE
value|0x0010
end_define

begin_comment
comment|/* Reset SCSI chip      	*/
end_comment

begin_define
define|#
directive|define
name|DO_RSTSCSI
value|0x0008
end_define

begin_comment
comment|/* Reset SCSI bus	       	*/
end_comment

begin_define
define|#
directive|define
name|DO_CLRFIFO
value|0x0004
end_define

begin_comment
comment|/* Clear SCSI transfer FIFO    	*/
end_comment

begin_define
define|#
directive|define
name|DO_DATALATCH
value|0x0002
end_define

begin_comment
comment|/* Enable SCSI bus data latch 	*/
end_comment

begin_define
define|#
directive|define
name|DO_HWRESELECT
value|0x0001
end_define

begin_comment
comment|/* Enable hardware reselection 	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_FIFOCNT
value|0x82
end_define

begin_comment
comment|/* SCSI FIFO Counter 5bits(R) 	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_SIGNAL
value|0x83
end_define

begin_comment
comment|/* SCSI low level signal (R/W) 	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_INTSTATUS
value|0x84
end_define

begin_comment
comment|/* SCSI Interrupt Status (R)   	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|INT_SCAM
value|0x80
end_define

begin_comment
comment|/* SCAM selection interrupt    	*/
end_comment

begin_define
define|#
directive|define
name|INT_SELECT
value|0x40
end_define

begin_comment
comment|/* Selection interrupt	       	*/
end_comment

begin_define
define|#
directive|define
name|INT_SELTIMEOUT
value|0x20
end_define

begin_comment
comment|/* Selection timeout interrupt 	*/
end_comment

begin_define
define|#
directive|define
name|INT_DISCONNECT
value|0x10
end_define

begin_comment
comment|/* Bus disconnected interrupt  	*/
end_comment

begin_define
define|#
directive|define
name|INT_RESELECTED
value|0x08
end_define

begin_comment
comment|/* Reselected interrupt	       	*/
end_comment

begin_define
define|#
directive|define
name|INT_SCSIRESET
value|0x04
end_define

begin_comment
comment|/* SCSI reset detected interrupt*/
end_comment

begin_define
define|#
directive|define
name|INT_BUSSERVICE
value|0x02
end_define

begin_comment
comment|/* Bus service interrupt       	*/
end_comment

begin_define
define|#
directive|define
name|INT_CMDDONE
value|0x01
end_define

begin_comment
comment|/* SCSI command done interrupt 	*/
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_OFFSET
value|0x84
end_define

begin_comment
comment|/* SCSI Offset Count (W)       	*/
end_comment

begin_comment
comment|/*  *   Bit		Name	        Definition  *   07-05	0	RSVD	        Reversed. Always 0.  *   04 	0	OFFSET4	        Reversed for LVDS. Always 0.  *   03-00	0	OFFSET[03:00]	Offset number from 0 to 15  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_SYNC
value|0x85
end_define

begin_comment
comment|/* SCSI Synchronous Control (R/W)*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|LVDS_SYNC
value|0x20
end_define

begin_comment
comment|/* Enable LVDS synchronous       */
end_comment

begin_define
define|#
directive|define
name|WIDE_SYNC
value|0x10
end_define

begin_comment
comment|/* Enable WIDE synchronous       */
end_comment

begin_define
define|#
directive|define
name|ALT_SYNC
value|0x08
end_define

begin_comment
comment|/* Enable Fast-20 alternate synchronous */
end_comment

begin_comment
comment|/*  * SYNCM	7    6	  5	   4	3   	2   	1   	0  * Name 	RSVD RSVD LVDS WIDE	ALTPERD	PERIOD2	PERIOD1	PERIOD0  * Default	0	 0	  0	   0	0	    0	    0	    0  *  *  * Bit		    Name                	Definition  * 07-06	0	RSVD                	Reversed. Always read 0  * 05   	0	LVDS                	Reversed. Always read 0  * 04   	0	WIDE/WSCSI          	Enable wide (16-bits) SCSI transfer.  * 03   	0	ALTPERD/ALTPD	        Alternate (Sync./Period) mode.   *  *                                      @@ When this bit is set,  *                                         the synchronous period bits 2:0   *                                         in the Synchronous Mode register  *                                         are used to transfer data   *                                         at the Fast-20 rate.  *                                      @@ When this bit is reset,  *                                         the synchronous period bits 2:0   *                                         in the Synchronous Mode Register  *                                         are used to transfer data   *                                         at the Fast-40 rate.  *  * 02-00	0	PERIOD[2:0]/SXPD[02:00]	Synchronous SCSI Transfer Rate.  *                                      These 3 bits specify   *                                      the Synchronous SCSI Transfer Rate  *                                      for Fast-20 and Fast-10.  *                                      These bits are also reset  *                                      by a SCSI Bus reset.  *  * For Fast-10 bit ALTPD = 0 and LVDS = 0   *     and 0x00000004,0x00000002,0x00000001 is defined as follows :  *  *  	   000	100ns, 10.0 Mbytes/s  *   	   001	150ns,  6.6 Mbytes/s  *  	   010	200ns,  5.0 Mbytes/s  *  	   011	250ns,  4.0 Mbytes/s  *   	   100	300ns,  3.3 Mbytes/s  *  	   101	350ns,  2.8 Mbytes/s  *	       110	400ns,  2.5 Mbytes/s  *	       111	450ns,  2.2 Mbytes/s  *  * For Fast-20 bit ALTPD = 1 and LVDS = 0   *     and 0x00000004,0x00000002,0x00000001 is defined as follows :  *  *	       000	 50ns, 20.0 Mbytes/s  *	       001	 75ns, 13.3 Mbytes/s  *	       010	100ns, 10.0 Mbytes/s  *	       011	125ns,  8.0 Mbytes/s  *	       100	150ns,  6.6 Mbytes/s  *	       101	175ns,  5.7 Mbytes/s  *	       110	200ns,  5.0 Mbytes/s  *	       111	250ns,  4.0 Mbytes/s  *  * For Fast-40 bit ALTPD = 0 and LVDS = 1  *     and 0x00000004,0x00000002,0x00000001 is defined as follows :  *  *	       000	 25ns, 40.0 Mbytes/s  *	       001	 50ns, 20.0 Mbytes/s  *	       010	 75ns, 13.3 Mbytes/s  *	       011	100ns, 10.0 Mbytes/s  *	       100	125ns,  8.0 Mbytes/s  *	       101	150ns,  6.6 Mbytes/s  *	       110	175ns,  5.7 Mbytes/s  *	       111	200ns,  5.0 Mbytes/s  */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_TARGETID
value|0x86
end_define

begin_comment
comment|/* SCSI Target ID (R/W)  	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_IDMSG
value|0x87
end_define

begin_comment
comment|/* SCSI Identify Message (R)   	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_HOSTID
value|0x87
end_define

begin_comment
comment|/* SCSI Host ID (W)	       	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_COUNTER
value|0x88
end_define

begin_comment
comment|/* SCSI Transfer Counter 24bits(R/W)*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_INTEN
value|0x8C
end_define

begin_comment
comment|/* SCSI Interrupt Enable (R/W)   */
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|EN_SCAM
value|0x80
end_define

begin_comment
comment|/* Enable SCAM selection interrupt*/
end_comment

begin_define
define|#
directive|define
name|EN_SELECT
value|0x40
end_define

begin_comment
comment|/* Enable selection interrupt     */
end_comment

begin_define
define|#
directive|define
name|EN_SELTIMEOUT
value|0x20
end_define

begin_comment
comment|/* Enable selection timeout interrupt*/
end_comment

begin_define
define|#
directive|define
name|EN_DISCONNECT
value|0x10
end_define

begin_comment
comment|/* Enable bus disconnected interrupt*/
end_comment

begin_define
define|#
directive|define
name|EN_RESELECTED
value|0x08
end_define

begin_comment
comment|/* Enable reselected interrupt   */
end_comment

begin_define
define|#
directive|define
name|EN_SCSIRESET
value|0x04
end_define

begin_comment
comment|/* Enable SCSI reset detected interrupt*/
end_comment

begin_define
define|#
directive|define
name|EN_BUSSERVICE
value|0x02
end_define

begin_comment
comment|/* Enable bus service interrupt  */
end_comment

begin_define
define|#
directive|define
name|EN_CMDDONE
value|0x01
end_define

begin_comment
comment|/* Enable SCSI command done interrupt*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_CONFIG0
value|0x8D
end_define

begin_comment
comment|/* SCSI Configuration 0 (R/W)  	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|PHASELATCH
value|0x40
end_define

begin_comment
comment|/* Enable phase latch	       	*/
end_comment

begin_define
define|#
directive|define
name|INITIATOR
value|0x20
end_define

begin_comment
comment|/* Enable initiator mode       	*/
end_comment

begin_define
define|#
directive|define
name|PARITYCHECK
value|0x10
end_define

begin_comment
comment|/* Enable parity check	       	*/
end_comment

begin_define
define|#
directive|define
name|BLOCKRST
value|0x01
end_define

begin_comment
comment|/* Disable SCSI reset1	       	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_CONFIG1
value|0x8E
end_define

begin_comment
comment|/* SCSI Configuration 1 (R/W)  	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|ACTIVE_NEGPLUS
value|0x10
end_define

begin_comment
comment|/* Enhance active negation     	*/
end_comment

begin_define
define|#
directive|define
name|FILTER_DISABLE
value|0x08
end_define

begin_comment
comment|/* Disable SCSI data filter    	*/
end_comment

begin_define
define|#
directive|define
name|ACTIVE_NEG
value|0x02
end_define

begin_comment
comment|/* Enable active negation      	*/
end_comment

begin_define
define|#
directive|define
name|ACTIVE_HISLEW
value|0x01
end_define

begin_comment
comment|/* Enable high slew rate (3/6 ns) */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_CONFIG2
value|0x8F
end_define

begin_comment
comment|/* SCSI Configuration 2 (R/W)  	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_COMMAND
value|0x90
end_define

begin_comment
comment|/* SCSI Command (R/W)  		*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|SCMD_COMP
value|0x12
end_define

begin_comment
comment|/* Command complete            	*/
end_comment

begin_define
define|#
directive|define
name|SCMD_SEL_ATN
value|0x60
end_define

begin_comment
comment|/* Selection with ATN  		*/
end_comment

begin_define
define|#
directive|define
name|SCMD_SEL_ATN3
value|0x64
end_define

begin_comment
comment|/* Selection with ATN3 		*/
end_comment

begin_define
define|#
directive|define
name|SCMD_SEL_ATNSTOP
value|0xB8
end_define

begin_comment
comment|/* Selection with ATN and Stop 	*/
end_comment

begin_define
define|#
directive|define
name|SCMD_FIFO_OUT
value|0xC0
end_define

begin_comment
comment|/* SCSI FIFO transfer out      	*/
end_comment

begin_define
define|#
directive|define
name|SCMD_DMA_OUT
value|0xC1
end_define

begin_comment
comment|/* SCSI DMA transfer out       	*/
end_comment

begin_define
define|#
directive|define
name|SCMD_FIFO_IN
value|0xC2
end_define

begin_comment
comment|/* SCSI FIFO transfer in       	*/
end_comment

begin_define
define|#
directive|define
name|SCMD_DMA_IN
value|0xC3
end_define

begin_comment
comment|/* SCSI DMA transfer in	       	*/
end_comment

begin_define
define|#
directive|define
name|SCMD_MSGACCEPT
value|0xD8
end_define

begin_comment
comment|/* Message accept	       	*/
end_comment

begin_comment
comment|/*  *  Code	Command Description  *  *  02	    Enable reselection with FIFO  *  40  	Select without ATN with FIFO  *  60   	Select with ATN with FIFO  *  64  	Select with ATN3 with FIFO  *  A0  	Select with ATN and stop with FIFO  *  C0  	Transfer information out with FIFO  *  C1  	Transfer information out with DMA  *  C2  	Transfer information in with FIFO  *  C3  	Transfer information in with DMA  *  12  	Initiator command complete with FIFO  *  50  	Initiator transfer information out sequence without ATN with FIFO  *  70  	Initiator transfer information out sequence with ATN with FIFO  *  74  	Initiator transfer information out sequence with ATN3 with FIFO  *  52  	Initiator transfer information in sequence without ATN with FIFO  *  72   	Initiator transfer information in sequence with ATN with FIFO  *  76	    Initiator transfer information in sequence with ATN3 with FIFO  *  90  	Initiator transfer information out command complete with FIFO  *  92  	Initiator transfer information in command complete with FIFO  *  D2  	Enable selection  *  08  	Reselection  *  48  	Disconnect command with FIFO  *  88  	Terminate command with FIFO  *  C8  	Target command complete with FIFO  *  18  	SCAM Arbitration/ Selection  *  5A  	Enable reselection  *  98  	Select without ATN with FIFO  *  B8  	Select with ATN with FIFO  *  D8  	Message Accepted  *  58  	NOP  */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_TIMEOUT
value|0x91
end_define

begin_comment
comment|/* SCSI Time Out Value (R/W)   	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_FIFO
value|0x98
end_define

begin_comment
comment|/* SCSI FIFO (R/W)	       	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_TCR00
value|0x9C
end_define

begin_comment
comment|/* SCSI Target Control 0 (R/W) 	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|TCR0_DO_WIDE_NEGO
value|0x80
end_define

begin_comment
comment|/* Do wide NEGO		      	*/
end_comment

begin_define
define|#
directive|define
name|TCR0_DO_SYNC_NEGO
value|0x40
end_define

begin_comment
comment|/* Do sync NEGO	             	*/
end_comment

begin_define
define|#
directive|define
name|TCR0_DISCONNECT_EN
value|0x20
end_define

begin_comment
comment|/* Disconnection enable     	*/
end_comment

begin_define
define|#
directive|define
name|TCR0_OFFSET_MASK
value|0x1F
end_define

begin_comment
comment|/* Offset number	       	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_TCR01
value|0x9D
end_define

begin_comment
comment|/* SCSI Target Control 0 (R/W)  */
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|TCR0_ENABLE_LVDS
value|0xF8
end_define

begin_comment
comment|/* LVD   		   	*/
end_comment

begin_define
define|#
directive|define
name|TCR0_ENABLE_WIDE
value|0xF9
end_define

begin_comment
comment|/* SE       			*/
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_SCSI_TCR1
value|0x9E
end_define

begin_comment
comment|/* SCSI Target Control 1 (R/W) 	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|MAXTAG_MASK
value|0x7F00
end_define

begin_comment
comment|/* Maximum tags (127)	       	*/
end_comment

begin_define
define|#
directive|define
name|NON_TAG_BUSY
value|0x0080
end_define

begin_comment
comment|/* Non tag command active      	*/
end_comment

begin_define
define|#
directive|define
name|ACTTAG_MASK
value|0x007F
end_define

begin_comment
comment|/* Active tags		      	*/
end_comment

begin_comment
comment|/*  *  * The DMA register offset for TRM_S1040				  *  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_COMMAND
value|0xA0
end_define

begin_comment
comment|/* DMA Command (R/W)	        	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|XFERDATAIN
value|0x0103
end_define

begin_comment
comment|/* Transfer data in	       	*/
end_comment

begin_define
define|#
directive|define
name|XFERDATAOUT
value|0x0102
end_define

begin_comment
comment|/* Transfer data out    	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_FIFOCNT
value|0xA1
end_define

begin_comment
comment|/* DMA FIFO Counter (R)	       	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_CONTROL
value|0xA1
end_define

begin_comment
comment|/* DMA Control (W)     		*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|STOPDMAXFER
value|0x08
end_define

begin_comment
comment|/* Stop  DMA transfer  		*/
end_comment

begin_define
define|#
directive|define
name|ABORTXFER
value|0x04
end_define

begin_comment
comment|/* Abort DMA transfer         	*/
end_comment

begin_define
define|#
directive|define
name|CLRXFIFO
value|0x02
end_define

begin_comment
comment|/* Clear DMA transfer FIFO     	*/
end_comment

begin_define
define|#
directive|define
name|STARTDMAXFER
value|0x01
end_define

begin_comment
comment|/* Start DMA transfer     	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_STATUS
value|0xA3
end_define

begin_comment
comment|/* DMA Interrupt Status (R/W)  	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|XFERPENDING
value|0x80
end_define

begin_comment
comment|/* Transfer pending	        */
end_comment

begin_define
define|#
directive|define
name|DMAXFERCOMP
value|0x02
end_define

begin_comment
comment|/* Bus Master XFER Complete status  */
end_comment

begin_define
define|#
directive|define
name|SCSICOMP
value|0x01
end_define

begin_comment
comment|/* SCSI complete interrupt     	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_INTEN
value|0xA4
end_define

begin_comment
comment|/* DMA Interrupt Enable (R/W)*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|EN_SCSIINTR
value|0x01
end_define

begin_comment
comment|/* Enable SCSI complete interrupt   */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_CONFIG
value|0xA6
end_define

begin_comment
comment|/* DMA Configuration (R/W)     	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|DMA_ENHANCE
value|0x8000
end_define

begin_comment
comment|/* Enable DMA enhance feature  	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_XCNT
value|0xA8
end_define

begin_comment
comment|/* DMA Transfer Counter (R/W)*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_CXCNT
value|0xAC
end_define

begin_comment
comment|/* DMA Current Transfer Counter (R) */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_XLOWADDR
value|0xB0
end_define

begin_comment
comment|/* DMA Transfer Physical Low Address  */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_DMA_XHIGHADDR
value|0xB4
end_define

begin_comment
comment|/* DMA Transfer Physical High Address */
end_comment

begin_comment
comment|/*  *  * The general register offset for TRM_S1040	  *  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_GEN_CONTROL
value|0xD4
end_define

begin_comment
comment|/* Global Control	       	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|EN_EEPROM
value|0x10
end_define

begin_comment
comment|/* Enable EEPROM programming   	*/
end_comment

begin_define
define|#
directive|define
name|AUTOTERM
value|0x04
end_define

begin_comment
comment|/* Enable Auto SCSI terminator 	*/
end_comment

begin_define
define|#
directive|define
name|LOW8TERM
value|0x02
end_define

begin_comment
comment|/* Enable Lower 8 bit SCSI terminator */
end_comment

begin_define
define|#
directive|define
name|UP8TERM
value|0x01
end_define

begin_comment
comment|/* Enable Upper 8 bit SCSI terminator */
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_GEN_STATUS
value|0xD5
end_define

begin_comment
comment|/* Global Status	       	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|GTIMEOUT
value|0x80
end_define

begin_comment
comment|/* Global timer reach 0 	*/
end_comment

begin_define
define|#
directive|define
name|CON5068
value|0x10
end_define

begin_comment
comment|/* External 50/68 pin connected	*/
end_comment

begin_define
define|#
directive|define
name|CON68
value|0x08
end_define

begin_comment
comment|/* Internal 68 pin connected   	*/
end_comment

begin_define
define|#
directive|define
name|CON50
value|0x04
end_define

begin_comment
comment|/* Internal 50 pin connected   	*/
end_comment

begin_define
define|#
directive|define
name|WIDESCSI
value|0x02
end_define

begin_comment
comment|/* Wide SCSI card	       	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_GEN_NVRAM
value|0xD6
end_define

begin_comment
comment|/* Serial NON-VOLATILE RAM port	*/
end_comment

begin_comment
comment|/* ######### */
end_comment

begin_define
define|#
directive|define
name|NVR_BITOUT
value|0x08
end_define

begin_comment
comment|/* Serial data out	       	*/
end_comment

begin_define
define|#
directive|define
name|NVR_BITIN
value|0x04
end_define

begin_comment
comment|/* Serial data in	       	*/
end_comment

begin_define
define|#
directive|define
name|NVR_CLOCK
value|0x02
end_define

begin_comment
comment|/* Serial clock		       	*/
end_comment

begin_define
define|#
directive|define
name|NVR_SELECT
value|0x01
end_define

begin_comment
comment|/* Serial select	       	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_GEN_EDATA
value|0xD7
end_define

begin_comment
comment|/* Parallel EEPROM data port   	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_GEN_EADDRESS
value|0xD8
end_define

begin_comment
comment|/* Parallel EEPROM address     	*/
end_comment

begin_comment
comment|/*  ***************************************  */
end_comment

begin_define
define|#
directive|define
name|TRMREG_GEN_TIMER
value|0xDB
end_define

begin_comment
comment|/* Global timer	       		*/
end_comment

begin_comment
comment|/*  * The SEEPROM structure for TRM_S1040			  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|NVRAM_TARGET_STRUCT
block|{
name|u_int8_t
name|NvmTarCfg0
decl_stmt|;
comment|/* Target configuration byte 0	*/
name|u_int8_t
name|NvmTarPeriod
decl_stmt|;
comment|/* Target period	       	*/
name|u_int8_t
name|NvmTarCfg2
decl_stmt|;
comment|/* Target configuration byte 2  */
name|u_int8_t
name|NvmTarCfg3
decl_stmt|;
comment|/* Target configuration byte 3 	*/
block|}
name|NVRAMTARGETTYPE
typedef|;
end_typedef

begin_comment
comment|/*   NvmTarCfg0: Target configuration byte 0 :..pDCB->DevMode */
end_comment

begin_define
define|#
directive|define
name|NTC_DO_WIDE_NEGO
value|0x20
end_define

begin_comment
comment|/* Wide negotiate	    	*/
end_comment

begin_define
define|#
directive|define
name|NTC_DO_TAG_QUEUING
value|0x10
end_define

begin_comment
comment|/* Enable SCSI tag queuing	*/
end_comment

begin_define
define|#
directive|define
name|NTC_DO_SEND_START
value|0x08
end_define

begin_comment
comment|/* Send start command SPINUP*/
end_comment

begin_define
define|#
directive|define
name|NTC_DO_DISCONNECT
value|0x04
end_define

begin_comment
comment|/* Enable SCSI disconnect	*/
end_comment

begin_define
define|#
directive|define
name|NTC_DO_SYNC_NEGO
value|0x02
end_define

begin_comment
comment|/* Sync negotiation	    	*/
end_comment

begin_define
define|#
directive|define
name|NTC_DO_PARITY_CHK
value|0x01
end_define

begin_comment
comment|/* (it sould define at NAC )                                            Parity check enable		*/
end_comment

begin_comment
comment|/*  *  *  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|NVRAM_STRUC
block|{
name|u_int8_t
name|NvramSubVendorID
index|[
literal|2
index|]
decl_stmt|;
comment|/*0,1  Sub Vendor ID	 */
name|u_int8_t
name|NvramSubSysID
index|[
literal|2
index|]
decl_stmt|;
comment|/*2,3  Sub System ID*/
name|u_int8_t
name|NvramSubClass
decl_stmt|;
comment|/*4    Sub Class  	*/
name|u_int8_t
name|NvramVendorID
index|[
literal|2
index|]
decl_stmt|;
comment|/*5,6  Vendor ID  	*/
name|u_int8_t
name|NvramDeviceID
index|[
literal|2
index|]
decl_stmt|;
comment|/*7,8  Device ID  	*/
name|u_int8_t
name|NvramReserved
decl_stmt|;
comment|/*9    Reserved   	*/
name|NVRAMTARGETTYPE
name|NvramTarget
index|[
name|TRM_MAX_TARGETS
index|]
decl_stmt|;
comment|/*										  *10,11,12,13 	                                          *14,15,16,17									  * .... 						  * .... 						  *70,71,72,73 	                                          */
name|u_int8_t
name|NvramScsiId
decl_stmt|;
comment|/*74 Host Adapter SCSI ID	*/
name|u_int8_t
name|NvramChannelCfg
decl_stmt|;
comment|/*75 Channel configuration	*/
name|u_int8_t
name|NvramDelayTime
decl_stmt|;
comment|/*76 Power on delay time	*/
name|u_int8_t
name|NvramMaxTag
decl_stmt|;
comment|/*77 Maximum tags	    	*/
name|u_int8_t
name|NvramReserved0
decl_stmt|;
comment|/*78  */
name|u_int8_t
name|NvramBootTarget
decl_stmt|;
comment|/*79  */
name|u_int8_t
name|NvramBootLun
decl_stmt|;
comment|/*80  */
name|u_int8_t
name|NvramReserved1
decl_stmt|;
comment|/*81  */
name|u_int16_t
name|Reserved
index|[
literal|22
index|]
decl_stmt|;
comment|/*82,..125 */
name|u_int16_t
name|NvramCheckSum
decl_stmt|;
comment|/*126,127*/
block|}
name|NVRAMTYPE
operator|,
typedef|*
name|PNVRAMTYPE
typedef|;
end_typedef

begin_comment
comment|/* Nvram Initiater bits definition */
end_comment

begin_define
define|#
directive|define
name|MORE2_DRV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GREATER_1G
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RST_SCSI_BUS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACTIVE_NEGATION
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NO_SEEK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LUN_CHECK
value|0x00000020
end_define

begin_comment
comment|/* Nvram Adapter NvramChannelCfg bits definition */
end_comment

begin_define
define|#
directive|define
name|NAC_SCANLUN
value|0x20
end_define

begin_comment
comment|/* Include LUN as BIOS device*/
end_comment

begin_define
define|#
directive|define
name|NAC_POWERON_SCSI_RESET
value|0x04
end_define

begin_comment
comment|/* Power on reset enable     */
end_comment

begin_define
define|#
directive|define
name|NAC_GREATER_1G
value|0x02
end_define

begin_comment
comment|/*> 1G support enable	     */
end_comment

begin_define
define|#
directive|define
name|NAC_GT2DRIVES
value|0x01
end_define

begin_comment
comment|/* Support more than 2 drives*/
end_comment

begin_comment
comment|/*  *#define NAC_DO_PARITY_CHK       	0x08    // Parity check enable	      */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* trm_H */
end_comment

end_unit

