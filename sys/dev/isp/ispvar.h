begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ispvar.h,v 1.17 1998/09/14 23:22:51 mjacob Exp $ */
end_comment

begin_comment
comment|/*  * Soft Definitions for for Qlogic ISP SCSI adapters.  *  *---------------------------------------  * Copyright (c) 1997, 1998 by Matthew Jacob  * NASA/Ames Research Center  * All rights reserved.  *---------------------------------------  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISPVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_ISPVAR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<dev/ic/ispmbox.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<dev/isp/ispmbox.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<ispmbox.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISP_CORE_VERSION_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|ISP_CORE_VERSION_MINOR
value|3
end_define

begin_comment
comment|/*  * Vector for MD code to provide specific services.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ispsoftc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ispmdvec
block|{
name|u_int16_t
argument_list|(
argument|*dv_rd_reg
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*dv_wr_reg
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|int
operator|,
name|u_int16_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*dv_mbxdma
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*dv_dmaset
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|ISP_SCSI_XFER_T
operator|*
operator|,
name|ispreq_t
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|u_int8_t
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*dv_dmaclr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|ISP_SCSI_XFER_T
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*dv_reset0
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*dv_reset1
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*dv_dregs
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
expr_stmt|;
specifier|const
name|u_int16_t
modifier|*
name|dv_ispfw
decl_stmt|;
comment|/* ptr to f/w */
name|u_int16_t
name|dv_fwlen
decl_stmt|;
comment|/* length of f/w */
name|u_int16_t
name|dv_codeorg
decl_stmt|;
comment|/* code ORG for f/w */
name|u_int16_t
name|dv_fwrev
decl_stmt|;
comment|/* f/w revision */
comment|/* 	 * Initial values for conf1 register 	 */
name|u_int16_t
name|dv_conf1
decl_stmt|;
name|u_int16_t
name|dv_clock
decl_stmt|;
comment|/* clock frequency */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_TARGETS
value|16
end_define

begin_define
define|#
directive|define
name|MAX_FC_TARG
value|126
end_define

begin_comment
comment|/* queue length must be a power of two */
end_comment

begin_define
define|#
directive|define
name|QENTRY_LEN
value|64
end_define

begin_define
define|#
directive|define
name|RQUEST_QUEUE_LEN
value|MAXISPREQUEST
end_define

begin_define
define|#
directive|define
name|RESULT_QUEUE_LEN
value|(MAXISPREQUEST/4)
end_define

begin_define
define|#
directive|define
name|ISP_QUEUE_ENTRY
parameter_list|(
name|q
parameter_list|,
name|idx
parameter_list|)
value|((q) + ((idx) * QENTRY_LEN))
end_define

begin_define
define|#
directive|define
name|ISP_QUEUE_SIZE
parameter_list|(
name|n
parameter_list|)
value|((n) * QENTRY_LEN)
end_define

begin_define
define|#
directive|define
name|ISP_NXT_QENTRY
parameter_list|(
name|idx
parameter_list|,
name|qlen
parameter_list|)
value|(((idx) + 1)& ((qlen)-1))
end_define

begin_define
define|#
directive|define
name|ISP_QAVAIL
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|,
name|qlen
parameter_list|)
define|\
value|((in == out)? (qlen - 1) : ((in> out)? \ 		((qlen - 1) - (in - out)) : (out - in - 1)))
end_define

begin_comment
comment|/*  * SCSI (as opposed to FC-PH) Specific Host Adapter Parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|isp_req_ack_active_neg
range|:
literal|1
decl_stmt|,
name|isp_data_line_active_neg
range|:
literal|1
decl_stmt|,
name|isp_cmd_dma_burst_enable
range|:
literal|1
decl_stmt|,
name|isp_data_dma_burst_enabl
range|:
literal|1
decl_stmt|,
name|isp_fifo_threshold
range|:
literal|2
decl_stmt|,
name|isp_diffmode
range|:
literal|1
decl_stmt|,
name|isp_fast_mttr
range|:
literal|1
decl_stmt|,
name|isp_initiator_id
range|:
literal|4
decl_stmt|,
name|isp_async_data_setup
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|isp_selection_timeout
decl_stmt|;
name|u_int16_t
name|isp_max_queue_depth
decl_stmt|;
name|u_int16_t
name|isp_clock
decl_stmt|;
name|u_int8_t
name|isp_tag_aging
decl_stmt|;
name|u_int8_t
name|isp_bus_reset_delay
decl_stmt|;
name|u_int8_t
name|isp_retry_count
decl_stmt|;
name|u_int8_t
name|isp_retry_delay
decl_stmt|;
struct|struct
block|{
name|u_int
name|dev_update
range|:
literal|1
decl_stmt|,
name|dev_enable
range|:
literal|1
decl_stmt|,
name|exc_throttle
range|:
literal|7
decl_stmt|,
name|sync_offset
range|:
literal|4
decl_stmt|,
name|sync_period
range|:
literal|8
decl_stmt|;
name|u_int16_t
name|dev_flags
decl_stmt|;
comment|/* persistent device flags */
name|u_int16_t
name|cur_dflags
decl_stmt|;
comment|/* current device flags */
block|}
name|isp_devparam
index|[
name|MAX_TARGETS
index|]
struct|;
block|}
name|sdparam
typedef|;
end_typedef

begin_comment
comment|/* scsi device parameters */
end_comment

begin_comment
comment|/*  * Device Flags  */
end_comment

begin_define
define|#
directive|define
name|DPARM_DISC
value|0x8000
end_define

begin_define
define|#
directive|define
name|DPARM_PARITY
value|0x4000
end_define

begin_define
define|#
directive|define
name|DPARM_WIDE
value|0x2000
end_define

begin_define
define|#
directive|define
name|DPARM_SYNC
value|0x1000
end_define

begin_define
define|#
directive|define
name|DPARM_TQING
value|0x0800
end_define

begin_define
define|#
directive|define
name|DPARM_ARQ
value|0x0400
end_define

begin_define
define|#
directive|define
name|DPARM_QFRZ
value|0x0200
end_define

begin_define
define|#
directive|define
name|DPARM_RENEG
value|0x0100
end_define

begin_define
define|#
directive|define
name|DPARM_NARROW
value|0x0080
end_define

begin_comment
comment|/* Possibly only available with>= 7.55 fw */
end_comment

begin_define
define|#
directive|define
name|DPARM_ASYNC
value|0x0040
end_define

begin_comment
comment|/* Possibly only available with>= 7.55 fw */
end_comment

begin_define
define|#
directive|define
name|DPARM_DEFAULT
value|(0xFFFF& ~DPARM_QFRZ)
end_define

begin_define
define|#
directive|define
name|DPARM_SAFE_DFLT
value|(DPARM_DEFAULT& ~(DPARM_WIDE|DPARM_SYNC|DPARM_TQING))
end_define

begin_define
define|#
directive|define
name|ISP_20M_SYNCPARMS
value|0x080c
end_define

begin_define
define|#
directive|define
name|ISP_10M_SYNCPARMS
value|0x0c19
end_define

begin_define
define|#
directive|define
name|ISP_08M_SYNCPARMS
value|0x0c25
end_define

begin_define
define|#
directive|define
name|ISP_05M_SYNCPARMS
value|0x0c32
end_define

begin_define
define|#
directive|define
name|ISP_04M_SYNCPARMS
value|0x0c41
end_define

begin_comment
comment|/*  * Fibre Channel Specifics  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int64_t
name|isp_wwn
decl_stmt|;
comment|/* WWN of adapter */
name|u_int8_t
name|isp_loopid
decl_stmt|;
comment|/* hard loop id */
name|u_int8_t
name|isp_alpa
decl_stmt|;
comment|/* ALPA */
name|u_int8_t
name|isp_execthrottle
decl_stmt|;
name|u_int8_t
name|isp_retry_delay
decl_stmt|;
name|u_int8_t
name|isp_retry_count
decl_stmt|;
name|u_int8_t
name|isp_fwstate
decl_stmt|;
comment|/* ISP F/W state */
name|u_int16_t
name|isp_maxalloc
decl_stmt|;
name|u_int16_t
name|isp_maxfrmlen
decl_stmt|;
name|u_int16_t
name|isp_fwoptions
decl_stmt|;
comment|/* 	 * Scratch DMA mapped in area to fetch Port Database stuff, etc. 	 */
specifier|volatile
name|caddr_t
name|isp_scratch
decl_stmt|;
name|u_int32_t
name|isp_scdma
decl_stmt|;
block|}
name|fcparam
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP2100_SCRLEN
value|0x100
end_define

begin_define
define|#
directive|define
name|FW_CONFIG_WAIT
value|0x0000
end_define

begin_define
define|#
directive|define
name|FW_WAIT_AL_PA
value|0x0001
end_define

begin_define
define|#
directive|define
name|FW_WAIT_LOGIN
value|0x0002
end_define

begin_define
define|#
directive|define
name|FW_READY
value|0x0003
end_define

begin_define
define|#
directive|define
name|FW_LOSS_OF_SYNC
value|0x0004
end_define

begin_define
define|#
directive|define
name|FW_ERROR
value|0x0005
end_define

begin_define
define|#
directive|define
name|FW_REINIT
value|0x0006
end_define

begin_define
define|#
directive|define
name|FW_NON_PART
value|0x0007
end_define

begin_decl_stmt
specifier|static
name|__inline
name|char
modifier|*
name|fw_statename
name|__P
argument_list|(
operator|(
name|u_int8_t
name|x
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|char
modifier|*
name|fw_statename
parameter_list|(
name|x
parameter_list|)
name|u_int8_t
name|x
decl_stmt|;
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
name|FW_CONFIG_WAIT
case|:
return|return
literal|"Config Wait"
return|;
case|case
name|FW_WAIT_AL_PA
case|:
return|return
literal|"Waiting for AL/PA"
return|;
case|case
name|FW_WAIT_LOGIN
case|:
return|return
literal|"Wait Login"
return|;
case|case
name|FW_READY
case|:
return|return
literal|"Ready"
return|;
case|case
name|FW_LOSS_OF_SYNC
case|:
return|return
literal|"Loss Of Sync"
return|;
case|case
name|FW_ERROR
case|:
return|return
literal|"Error"
return|;
case|case
name|FW_REINIT
case|:
return|return
literal|"Re-Init"
return|;
case|case
name|FW_NON_PART
case|:
return|return
literal|"Nonparticipating"
return|;
default|default:
return|return
literal|"eh?"
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Soft Structure per host adapter  */
end_comment

begin_struct
struct|struct
name|ispsoftc
block|{
comment|/* 	 * Platform (OS) specific data 	 */
name|struct
name|isposinfo
name|isp_osinfo
decl_stmt|;
comment|/* 	 * Pointer to bus specific data 	 */
name|struct
name|ispmdvec
modifier|*
name|isp_mdvec
decl_stmt|;
comment|/* 	 * State, debugging, etc.. 	 */
name|u_int
label|:
literal|8
operator|,
name|isp_confopts
operator|:
literal|8
operator|,
operator|:
literal|2
operator|,
name|isp_dblev
operator|:
literal|3
operator|,
name|isp_gotdparms
operator|:
literal|1
operator|,
name|isp_dogactive
operator|:
literal|1
operator|,
name|isp_bustype
operator|:
literal|1
operator|,
comment|/* BUS Implementation */
name|isp_type
operator|:
literal|8
expr_stmt|;
comment|/* HBA Type and Revision */
name|u_int16_t
name|isp_fwrev
decl_stmt|;
comment|/* Running F/W revision */
name|u_int16_t
name|isp_romfw_rev
decl_stmt|;
comment|/* 'ROM' F/W revision */
name|void
modifier|*
name|isp_param
decl_stmt|;
comment|/* 	 * Volatile state 	 */
specifier|volatile
name|u_int
operator|:
literal|19
operator|,
name|isp_state
operator|:
literal|3
operator|,
name|isp_sendmarker
operator|:
literal|1
operator|,
comment|/* send a marker entry */
name|isp_update
operator|:
literal|1
operator|,
comment|/* update paramters */
name|isp_nactive
operator|:
literal|9
expr_stmt|;
comment|/* how many commands active */
comment|/* 	 * Result and Request Queue indices. 	 */
specifier|volatile
name|u_int8_t
name|isp_reqodx
decl_stmt|;
comment|/* index of last ISP pickup */
specifier|volatile
name|u_int8_t
name|isp_reqidx
decl_stmt|;
comment|/* index of next request */
specifier|volatile
name|u_int8_t
name|isp_residx
decl_stmt|;
comment|/* index of next result */
specifier|volatile
name|u_int8_t
name|isp_seqno
decl_stmt|;
comment|/* rolling sequence # */
comment|/* 	 * Sheer laziness, but it gets us around the problem 	 * where we don't have a clean way of remembering 	 * which transaction is bound to which ISP queue entry. 	 * 	 * There are other more clever ways to do this, but, 	 * jeez, so I blow a couple of KB per host adapter... 	 * and it *is* faster. 	 */
specifier|volatile
name|ISP_SCSI_XFER_T
modifier|*
name|isp_xflist
index|[
name|RQUEST_QUEUE_LEN
index|]
decl_stmt|;
comment|/* 	 * request/result queues and dma handles for them. 	 */
specifier|volatile
name|caddr_t
name|isp_rquest
decl_stmt|;
specifier|volatile
name|caddr_t
name|isp_result
decl_stmt|;
name|u_int32_t
name|isp_rquest_dma
decl_stmt|;
name|u_int32_t
name|isp_result_dma
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ISP States  */
end_comment

begin_define
define|#
directive|define
name|ISP_NILSTATE
value|0
end_define

begin_define
define|#
directive|define
name|ISP_RESETSTATE
value|1
end_define

begin_define
define|#
directive|define
name|ISP_INITSTATE
value|2
end_define

begin_define
define|#
directive|define
name|ISP_RUNSTATE
value|3
end_define

begin_comment
comment|/*  * ISP Configuration Options  */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_NORELOAD
value|0x80
end_define

begin_comment
comment|/* don't download f/w */
end_comment

begin_define
define|#
directive|define
name|ISP_FW_REV
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
value|((maj)<< 10| (min))
end_define

begin_comment
comment|/*  * Bus (implementation) types  */
end_comment

begin_define
define|#
directive|define
name|ISP_BT_PCI
value|0
end_define

begin_comment
comment|/* PCI Implementations */
end_comment

begin_define
define|#
directive|define
name|ISP_BT_SBUS
value|1
end_define

begin_comment
comment|/* SBus Implementations */
end_comment

begin_comment
comment|/*  * Chip Types  */
end_comment

begin_define
define|#
directive|define
name|ISP_HA_SCSI
value|0xf
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_UNKNOWN
value|0x1
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1020
value|0x2
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1020A
value|0x3
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1040
value|0x4
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1040A
value|0x5
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1040B
value|0x6
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC
value|0xf0
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC_2100
value|0x10
end_define

begin_comment
comment|/*  * Macros to read, write ISP registers through MD code  */
end_comment

begin_define
define|#
directive|define
name|ISP_READ
parameter_list|(
name|isp
parameter_list|,
name|reg
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_rd_reg)((isp), (reg))
end_define

begin_define
define|#
directive|define
name|ISP_WRITE
parameter_list|(
name|isp
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_wr_reg)((isp), (reg), (val))
end_define

begin_define
define|#
directive|define
name|ISP_MBOXDMASETUP
parameter_list|(
name|isp
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_mbxdma)((isp))
end_define

begin_define
define|#
directive|define
name|ISP_DMASETUP
parameter_list|(
name|isp
parameter_list|,
name|xs
parameter_list|,
name|req
parameter_list|,
name|iptrp
parameter_list|,
name|optr
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_dmaset)((isp), (xs), (req), (iptrp), (optr))
end_define

begin_define
define|#
directive|define
name|ISP_DMAFREE
parameter_list|(
name|isp
parameter_list|,
name|xs
parameter_list|,
name|seqno
parameter_list|)
define|\
value|if ((isp)->isp_mdvec->dv_dmaclr) \ 		 (*(isp)->isp_mdvec->dv_dmaclr)((isp), (xs), (seqno))
end_define

begin_define
define|#
directive|define
name|ISP_RESET0
parameter_list|(
name|isp
parameter_list|)
define|\
value|if ((isp)->isp_mdvec->dv_reset0) (*(isp)->isp_mdvec->dv_reset0)((isp))
end_define

begin_define
define|#
directive|define
name|ISP_RESET1
parameter_list|(
name|isp
parameter_list|)
define|\
value|if ((isp)->isp_mdvec->dv_reset1) (*(isp)->isp_mdvec->dv_reset1)((isp))
end_define

begin_define
define|#
directive|define
name|ISP_DUMPREGS
parameter_list|(
name|isp
parameter_list|)
define|\
value|if ((isp)->isp_mdvec->dv_dregs) (*(isp)->isp_mdvec->dv_dregs)((isp))
end_define

begin_define
define|#
directive|define
name|ISP_SETBITS
parameter_list|(
name|isp
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_wr_reg)((isp), (reg), ISP_READ((isp), (reg)) | (val))
end_define

begin_define
define|#
directive|define
name|ISP_CLRBITS
parameter_list|(
name|isp
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_wr_reg)((isp), (reg), ISP_READ((isp), (reg))& ~(val))
end_define

begin_comment
comment|/*  * Function Prototypes  */
end_comment

begin_comment
comment|/*  * Reset Hardware. Totally. Assumes that you'll follow this with  * a call to isp_init.  */
end_comment

begin_decl_stmt
name|void
name|isp_reset
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialize Hardware to known state  */
end_comment

begin_decl_stmt
name|void
name|isp_init
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Free any associated resources prior to decommissioning.  */
end_comment

begin_decl_stmt
name|void
name|isp_uninit
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Reset the ISP and call completion for any orphaned commands.  */
end_comment

begin_decl_stmt
name|void
name|isp_restart
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Interrupt Service Routine  */
end_comment

begin_decl_stmt
name|int
name|isp_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Watchdog Routine  */
end_comment

begin_decl_stmt
name|void
name|isp_watch
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Command Entry Point  */
end_comment

begin_decl_stmt
name|int32_t
name|ispscsicmd
name|__P
argument_list|(
operator|(
name|ISP_SCSI_XFER_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Platform Dependent to Internal Control Point  *  * For: 	Aborting a running command	- arg is an ISP_SCSI_XFER_T *  *		Resetting a Device		- arg is target to reset  *		Resetting a BUS			- arg is ignored  *		Updating parameters		- arg is ignored  *  * Second argument is an index into xflist array.  * Assumes all locks must be held already.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ISPCTL_RESET_BUS
block|,
name|ISPCTL_RESET_DEV
block|,
name|ISPCTL_ABORT_CMD
block|,
name|ISPCTL_UPDATE_PARAMS
block|, }
name|ispctl_t
typedef|;
end_typedef

begin_decl_stmt
name|int
name|isp_control
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|ispctl_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * lost command routine (XXXX IN TRANSITION XXXX)  */
end_comment

begin_decl_stmt
name|void
name|isp_lostcmd
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|ISP_SCSI_XFER_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPVAR_H */
end_comment

end_unit

