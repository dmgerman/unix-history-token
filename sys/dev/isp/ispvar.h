begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  *  Copyright (c) 1997-2009 by Matthew Jacob  *  All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *  SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * Soft Definitions for for Qlogic ISP SCSI adapters.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dev/ic/isp_stds.h>
end_include

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
file|<dev/isp/isp_stds.h>
end_include

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
file|"isp_stds.h"
end_include

begin_include
include|#
directive|include
file|"ispmbox.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__svr4__
end_ifdef

begin_include
include|#
directive|include
file|"isp_stds.h"
end_include

begin_include
include|#
directive|include
file|"ispmbox.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISP_CORE_VERSION_MAJOR
value|7
end_define

begin_define
define|#
directive|define
name|ISP_CORE_VERSION_MINOR
value|0
end_define

begin_comment
comment|/*  * Vector for bus specific code to provide specific services.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ispsoftc
name|ispsoftc_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ispmdvec
block|{
name|void
function_decl|(
modifier|*
name|dv_run_isr
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
name|uint32_t
function_decl|(
modifier|*
name|dv_rd_reg
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dv_wr_reg
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_mbxdma
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_dmaset
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|XS_T
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dv_dmaclr
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|XS_T
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_irqsetup
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dv_dregs
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|void
modifier|*
name|dv_ispfw
decl_stmt|;
comment|/* ptr to f/w */
name|uint16_t
name|dv_conf1
decl_stmt|;
name|uint16_t
name|dv_clock
decl_stmt|;
comment|/* clock frequency */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Overall parameters  */
end_comment

begin_define
define|#
directive|define
name|MAX_TARGETS
value|16
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_FC_TARG
end_ifndef

begin_define
define|#
directive|define
name|MAX_FC_TARG
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISP_MAX_TARGETS
parameter_list|(
name|isp
parameter_list|)
value|(IS_FC(isp)? MAX_FC_TARG : MAX_TARGETS)
end_define

begin_define
define|#
directive|define
name|ISP_MAX_LUNS
parameter_list|(
name|isp
parameter_list|)
value|(isp)->isp_maxluns
end_define

begin_define
define|#
directive|define
name|ISP_MAX_IRQS
value|3
end_define

begin_comment
comment|/*  * Macros to access ISP registers through bus specific layers-  * mostly wrappers to vector through the mdvec structure.  */
end_comment

begin_define
define|#
directive|define
name|ISP_RUN_ISR
parameter_list|(
name|isp
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_run_isr)(isp)
end_define

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
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_dmaset)((isp), (xs), (req))
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
name|hndl
parameter_list|)
define|\
value|if ((isp)->isp_mdvec->dv_dmaclr)	\ 	    (*(isp)->isp_mdvec->dv_dmaclr)((isp), (xs), (hndl))
end_define

begin_define
define|#
directive|define
name|ISP_IRQSETUP
parameter_list|(
name|isp
parameter_list|)
define|\
value|(((isp)->isp_mdvec->dv_irqsetup) ? (*(isp)->isp_mdvec->dv_irqsetup)(isp) : 0)
end_define

begin_define
define|#
directive|define
name|ISP_DUMPREGS
parameter_list|(
name|isp
parameter_list|,
name|m
parameter_list|)
define|\
value|if ((isp)->isp_mdvec->dv_dregs) (*(isp)->isp_mdvec->dv_dregs)((isp),(m))
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
comment|/*  * The MEMORYBARRIER macro is defined per platform (to provide synchronization  * on Request and Response Queues, Scratch DMA areas, and Registers)  *  * Defined Memory Barrier Synchronization Types  */
end_comment

begin_define
define|#
directive|define
name|SYNC_REQUEST
value|0
end_define

begin_comment
comment|/* request queue synchronization */
end_comment

begin_define
define|#
directive|define
name|SYNC_RESULT
value|1
end_define

begin_comment
comment|/* result queue synchronization */
end_comment

begin_define
define|#
directive|define
name|SYNC_SFORDEV
value|2
end_define

begin_comment
comment|/* scratch, sync for ISP */
end_comment

begin_define
define|#
directive|define
name|SYNC_SFORCPU
value|3
end_define

begin_comment
comment|/* scratch, sync for CPU */
end_comment

begin_define
define|#
directive|define
name|SYNC_REG
value|4
end_define

begin_comment
comment|/* for registers */
end_comment

begin_define
define|#
directive|define
name|SYNC_ATIOQ
value|5
end_define

begin_comment
comment|/* atio result queue (24xx) */
end_comment

begin_define
define|#
directive|define
name|SYNC_IFORDEV
value|6
end_define

begin_comment
comment|/* synchrounous IOCB, sync for ISP */
end_comment

begin_define
define|#
directive|define
name|SYNC_IFORCPU
value|7
end_define

begin_comment
comment|/* synchrounous IOCB, sync for CPU */
end_comment

begin_comment
comment|/*  * Request/Response Queue defines and macros.  * The maximum is defined per platform (and can be based on board type).  */
end_comment

begin_comment
comment|/* This is the size of a queue entry (request and response) */
end_comment

begin_define
define|#
directive|define
name|QENTRY_LEN
value|64
end_define

begin_comment
comment|/* Both request and result queue length must be a power of two */
end_comment

begin_define
define|#
directive|define
name|RQUEST_QUEUE_LEN
parameter_list|(
name|x
parameter_list|)
value|MAXISPREQUEST(x)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_define
define|#
directive|define
name|RESULT_QUEUE_LEN
parameter_list|(
name|x
parameter_list|)
value|MAXISPREQUEST(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RESULT_QUEUE_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((MAXISPREQUEST(x)>> 2)< 64)? 64 : MAXISPREQUEST(x)>> 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISP_QUEUE_ENTRY
parameter_list|(
name|q
parameter_list|,
name|idx
parameter_list|)
value|(((uint8_t *)q) + ((idx) * QENTRY_LEN))
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
name|ISP_QFREE
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|,
name|qlen
parameter_list|)
define|\
value|((in == out)? (qlen - 1) : ((in> out)? \ 	((qlen - 1) - (in - out)) : (out - in - 1)))
end_define

begin_define
define|#
directive|define
name|ISP_QAVAIL
parameter_list|(
name|isp
parameter_list|)
define|\
value|ISP_QFREE(isp->isp_reqidx, isp->isp_reqodx, RQUEST_QUEUE_LEN(isp))
end_define

begin_define
define|#
directive|define
name|ISP_ADD_REQUEST
parameter_list|(
name|isp
parameter_list|,
name|nxti
parameter_list|)
define|\
value|MEMORYBARRIER(isp, SYNC_REQUEST, isp->isp_reqidx, QENTRY_LEN, -1);	\ 	ISP_WRITE(isp, isp->isp_rqstinrp, nxti);				\ 	isp->isp_reqidx = nxti
end_define

begin_define
define|#
directive|define
name|ISP_SYNC_REQUEST
parameter_list|(
name|isp
parameter_list|)
define|\
value|MEMORYBARRIER(isp, SYNC_REQUEST, isp->isp_reqidx, QENTRY_LEN, -1);		\ 	isp->isp_reqidx = ISP_NXT_QENTRY(isp->isp_reqidx, RQUEST_QUEUE_LEN(isp));	\ 	ISP_WRITE(isp, isp->isp_rqstinrp, isp->isp_reqidx)
end_define

begin_comment
comment|/*  * SCSI Specific Host Adapter Parameters- per bus, per target  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
label|:
literal|8
operator|,
name|update
operator|:
literal|1
operator|,
name|sendmarker
operator|:
literal|1
operator|,
name|isp_req_ack_active_neg
operator|:
literal|1
operator|,
name|isp_data_line_active_neg
operator|:
literal|1
operator|,
name|isp_cmd_dma_burst_enable
operator|:
literal|1
operator|,
name|isp_data_dma_burst_enabl
operator|:
literal|1
operator|,
name|isp_fifo_threshold
operator|:
literal|3
operator|,
name|isp_ptisp
operator|:
literal|1
operator|,
name|isp_ultramode
operator|:
literal|1
operator|,
name|isp_diffmode
operator|:
literal|1
operator|,
name|isp_lvdmode
operator|:
literal|1
operator|,
name|isp_fast_mttr
operator|:
literal|1
operator|,
comment|/* fast sram */
name|isp_initiator_id
operator|:
literal|4
operator|,
name|isp_async_data_setup
operator|:
literal|4
expr_stmt|;
name|uint16_t
name|isp_selection_timeout
decl_stmt|;
name|uint16_t
name|isp_max_queue_depth
decl_stmt|;
name|uint8_t
name|isp_tag_aging
decl_stmt|;
name|uint8_t
name|isp_bus_reset_delay
decl_stmt|;
name|uint8_t
name|isp_retry_count
decl_stmt|;
name|uint8_t
name|isp_retry_delay
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|exc_throttle
range|:
literal|8
decl_stmt|,
range|:
literal|1
decl_stmt|,
name|dev_enable
range|:
literal|1
decl_stmt|,
comment|/* ignored */
name|dev_update
range|:
literal|1
decl_stmt|,
name|dev_refresh
range|:
literal|1
decl_stmt|,
name|actv_offset
range|:
literal|4
decl_stmt|,
name|goal_offset
range|:
literal|4
decl_stmt|,
name|nvrm_offset
range|:
literal|4
decl_stmt|;
name|uint8_t
name|actv_period
decl_stmt|;
comment|/* current sync period */
name|uint8_t
name|goal_period
decl_stmt|;
comment|/* goal sync period */
name|uint8_t
name|nvrm_period
decl_stmt|;
comment|/* nvram sync period */
name|uint16_t
name|actv_flags
decl_stmt|;
comment|/* current device flags */
name|uint16_t
name|goal_flags
decl_stmt|;
comment|/* goal device flags */
name|uint16_t
name|nvrm_flags
decl_stmt|;
comment|/* nvram device flags */
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

begin_define
define|#
directive|define
name|DPARM_ASYNC
value|0x0040
end_define

begin_define
define|#
directive|define
name|DPARM_PPR
value|0x0020
end_define

begin_define
define|#
directive|define
name|DPARM_DEFAULT
value|(0xFF00& ~DPARM_QFRZ)
end_define

begin_define
define|#
directive|define
name|DPARM_SAFE_DFLT
value|(DPARM_DEFAULT& ~(DPARM_WIDE|DPARM_SYNC|DPARM_TQING))
end_define

begin_comment
comment|/* technically, not really correct, as they need to be rated based upon clock */
end_comment

begin_define
define|#
directive|define
name|ISP_80M_SYNCPARMS
value|0x0c09
end_define

begin_define
define|#
directive|define
name|ISP_40M_SYNCPARMS
value|0x0c0a
end_define

begin_define
define|#
directive|define
name|ISP_20M_SYNCPARMS
value|0x0c0c
end_define

begin_define
define|#
directive|define
name|ISP_20M_SYNCPARMS_1040
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

begin_comment
comment|/* These are for non-2K Login Firmware cards */
end_comment

begin_define
define|#
directive|define
name|FL_ID
value|0x7e
end_define

begin_comment
comment|/* FL_Port Special ID */
end_comment

begin_define
define|#
directive|define
name|SNS_ID
value|0x80
end_define

begin_comment
comment|/* SNS Server Special ID */
end_comment

begin_define
define|#
directive|define
name|NPH_MAX
value|0xfe
end_define

begin_comment
comment|/* These are for 2K Login Firmware cards */
end_comment

begin_define
define|#
directive|define
name|NPH_RESERVED
value|0x7F0
end_define

begin_comment
comment|/* begin of reserved N-port handles */
end_comment

begin_define
define|#
directive|define
name|NPH_MGT_ID
value|0x7FA
end_define

begin_comment
comment|/* Management Server Special ID */
end_comment

begin_define
define|#
directive|define
name|NPH_SNS_ID
value|0x7FC
end_define

begin_comment
comment|/* SNS Server Special ID */
end_comment

begin_define
define|#
directive|define
name|NPH_FABRIC_CTLR
value|0x7FD
end_define

begin_comment
comment|/* Fabric Controller (0xFFFFFD) */
end_comment

begin_define
define|#
directive|define
name|NPH_FL_ID
value|0x7FE
end_define

begin_comment
comment|/* F Port Special ID (0xFFFFFE) */
end_comment

begin_define
define|#
directive|define
name|NPH_IP_BCST
value|0x7FF
end_define

begin_comment
comment|/* IP Broadcast Special ID (0xFFFFFF) */
end_comment

begin_define
define|#
directive|define
name|NPH_MAX_2K
value|0x800
end_define

begin_comment
comment|/*  * "Unassigned" handle to be used internally  */
end_comment

begin_define
define|#
directive|define
name|NIL_HANDLE
value|0xffff
end_define

begin_comment
comment|/*  * Limit for devices on an arbitrated loop.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LOOP_LIM
value|126
end_define

begin_comment
comment|/*  * Limit for (2K login) N-port handle amounts  */
end_comment

begin_define
define|#
directive|define
name|MAX_NPORT_HANDLE
value|2048
end_define

begin_comment
comment|/*  * Special Constants  */
end_comment

begin_define
define|#
directive|define
name|INI_NONE
value|((uint64_t) 0)
end_define

begin_define
define|#
directive|define
name|ISP_NOCHAN
value|0xff
end_define

begin_comment
comment|/*  * Special Port IDs  */
end_comment

begin_define
define|#
directive|define
name|MANAGEMENT_PORT_ID
value|0xFFFFFA
end_define

begin_define
define|#
directive|define
name|SNS_PORT_ID
value|0xFFFFFC
end_define

begin_define
define|#
directive|define
name|FABRIC_PORT_ID
value|0xFFFFFE
end_define

begin_define
define|#
directive|define
name|PORT_ANY
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|PORT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VALID_PORT
parameter_list|(
name|port
parameter_list|)
value|(port != PORT_NONE&& port != PORT_ANY)
end_define

begin_define
define|#
directive|define
name|DOMAIN_CONTROLLER_BASE
value|0xFFFC00
end_define

begin_define
define|#
directive|define
name|DOMAIN_CONTROLLER_END
value|0xFFFCFF
end_define

begin_comment
comment|/*  * Command Handles  *  * Most QLogic initiator or target have 32 bit handles associated with them.  * We want to have a quick way to index back and forth between a local SCSI  * command context and what the firmware is passing back to us. We also  * want to avoid working on stale information. This structure handles both  * at the expense of some local memory.  *  * The handle is architected thusly:  *  *	0 means "free handle"  *	bits  0..12 index commands  *	bits 13..15 bits index usage  *	bits 16..31 contain a rolling sequence  *  *   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|cmd
decl_stmt|;
comment|/* associated command context */
name|uint32_t
name|handle
decl_stmt|;
comment|/* handle associated with this command */
block|}
name|isp_hdl_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP_HANDLE_FREE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_CMD_MASK
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_USAGE_MASK
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_USAGE_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|ISP_H2HT
parameter_list|(
name|hdl
parameter_list|)
value|((hdl& ISP_HANDLE_USAGE_MASK)>> ISP_HANDLE_USAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_INITIATOR
value|1
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_TARGET
value|2
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_CTRL
value|3
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_SEQ_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|ISP_HANDLE_SEQ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ISP_H2SEQ
parameter_list|(
name|hdl
parameter_list|)
value|((hdl& ISP_HANDLE_SEQ_MASK)>> ISP_HANDLE_SEQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|ISP_VALID_HANDLE
parameter_list|(
name|c
parameter_list|,
name|hdl
parameter_list|)
define|\
value|((ISP_H2HT(hdl) == ISP_HANDLE_INITIATOR || \ 	  ISP_H2HT(hdl) == ISP_HANDLE_TARGET || \ 	  ISP_H2HT(hdl) == ISP_HANDLE_CTRL)&& \ 	 ((hdl)& ISP_HANDLE_CMD_MASK)< (c)->isp_maxcmds&& \ 	 (hdl) == ((c)->isp_xflist[(hdl)& ISP_HANDLE_CMD_MASK].handle))
end_define

begin_define
define|#
directive|define
name|ISP_BAD_HANDLE_INDEX
value|0xffffffff
end_define

begin_comment
comment|/*  * FC Port Database entry.  *  * It has a handle that the f/w uses to address commands to a device.  * This handle's value may be assigned by the firmware (e.g., for local loop  * devices) or by the driver (e.g., for fabric devices).  *  * It has a state. If the state if VALID, that means that we've logged into  * the device.  *  * Local loop devices the firmware automatically performs PLOGI on for us  * (which is why that handle is imposed upon us). Fabric devices we assign  * a handle to and perform the PLOGI on.  *  * When a PORT DATABASE CHANGED asynchronous event occurs, we mark all VALID  * entries as PROBATIONAL. This allows us, if policy says to, just keep track  * of devices whose handles change but are otherwise the same device (and  * thus keep 'target' constant).  *  * In any case, we search all possible local loop handles. For each one that  * has a port database entity returned, we search for any PROBATIONAL entry  * that matches it and update as appropriate. Otherwise, as a new entry, we  * find room for it in the Port Database. We *try* and use the handle as the  * index to put it into the Database, but that's just an optimization. We mark  * the entry VALID and make sure that the target index is updated and correct.  *  * When we get done searching the local loop, we then search similarily for  * a list of devices we've gotten from the fabric name controller (if we're  * on a fabric). VALID marking is also done similarily.  *  * When all of this is done, we can march through the database and clean up  * any entry that is still PROBATIONAL (these represent devices which have  * departed). Then we're done and can resume normal operations.  *  * Negative invariants that we try and test for are:  *  *  + There can never be two non-NIL entries with the same { Port, Node } WWN  *    duples.  *  *  + There can never be two non-NIL entries with the same handle.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 	 * This is the handle that the firmware needs in order for us to 	 * send commands to the device. For pre-24XX cards, this would be 	 * the 'loopid'. 	 */
name|uint16_t
name|handle
decl_stmt|;
comment|/* 	 * PRLI word 3 parameters contains role as well as other things. 	 * 	 * The state is the current state of this entry. 	 * 	 * The is_target is the current state of target on this port. 	 * 	 * The is_initiator is the current state of initiator on this port. 	 * 	 * Portid is obvious, as are node&& port WWNs. The new_role and 	 * new_portid is for when we are pending a change. 	 */
name|uint16_t
name|prli_word3
decl_stmt|;
comment|/* PRLI parameters */
name|uint16_t
name|new_prli_word3
decl_stmt|;
comment|/* Incoming new PRLI parameters */
name|uint16_t
label|:
literal|12
operator|,
name|probational
operator|:
literal|1
operator|,
name|state
operator|:
literal|3
expr_stmt|;
name|uint32_t
label|:
literal|6
operator|,
name|is_target
operator|:
literal|1
operator|,
name|is_initiator
operator|:
literal|1
operator|,
name|portid
operator|:
literal|24
expr_stmt|;
name|uint32_t
label|:
literal|8
operator|,
name|new_portid
operator|:
literal|24
expr_stmt|;
name|uint64_t
name|node_wwn
decl_stmt|;
name|uint64_t
name|port_wwn
decl_stmt|;
name|uint32_t
name|gone_timer
decl_stmt|;
block|}
name|fcportdb_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_NIL
value|0
end_define

begin_comment
comment|/* Empty DB slot */
end_comment

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_DEAD
value|1
end_define

begin_comment
comment|/* Was valid, but no more. */
end_comment

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_CHANGED
value|2
end_define

begin_comment
comment|/* Was valid, but changed. */
end_comment

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_NEW
value|3
end_define

begin_comment
comment|/* Logged in, not announced. */
end_comment

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_ZOMBIE
value|4
end_define

begin_comment
comment|/* Invalid, but announced. */
end_comment

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_VALID
value|5
end_define

begin_comment
comment|/* Valid */
end_comment

begin_define
define|#
directive|define
name|FC_PORTDB_TGT
parameter_list|(
name|isp
parameter_list|,
name|bus
parameter_list|,
name|pdb
parameter_list|)
value|(int)(lp - FCPARAM(isp, bus)->portdb)
end_define

begin_comment
comment|/*  * FC card specific information  *  * This structure is replicated across multiple channels for multi-id  * capapble chipsets, with some entities different on a per-channel basis.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|isp_gbspeed
decl_stmt|;
comment|/* Connection speed */
name|int
name|isp_linkstate
decl_stmt|;
comment|/* Link state */
name|int
name|isp_fwstate
decl_stmt|;
comment|/* ISP F/W state */
name|int
name|isp_loopstate
decl_stmt|;
comment|/* Loop State */
name|int
name|isp_topo
decl_stmt|;
comment|/* Connection Type */
name|uint32_t
label|:
literal|4
operator|,
name|fctape_enabled
operator|:
literal|1
operator|,
name|sendmarker
operator|:
literal|1
operator|,
name|role
operator|:
literal|2
operator|,
name|isp_portid
operator|:
literal|24
expr_stmt|;
comment|/* S_ID */
name|uint16_t
name|isp_fwoptions
decl_stmt|;
name|uint16_t
name|isp_xfwoptions
decl_stmt|;
name|uint16_t
name|isp_zfwoptions
decl_stmt|;
name|uint16_t
name|isp_loopid
decl_stmt|;
comment|/* hard loop id */
name|uint16_t
name|isp_sns_hdl
decl_stmt|;
comment|/* N-port handle for SNS */
name|uint16_t
name|isp_lasthdl
decl_stmt|;
comment|/* only valid for channel 0 */
name|uint16_t
name|isp_maxalloc
decl_stmt|;
name|uint16_t
name|isp_fabric_params
decl_stmt|;
name|uint16_t
name|isp_login_hdl
decl_stmt|;
comment|/* Logging in handle */
name|uint8_t
name|isp_retry_delay
decl_stmt|;
name|uint8_t
name|isp_retry_count
decl_stmt|;
comment|/* 	 * Current active WWNN/WWPN 	 */
name|uint64_t
name|isp_wwnn
decl_stmt|;
name|uint64_t
name|isp_wwpn
decl_stmt|;
comment|/* 	 * NVRAM WWNN/WWPN 	 */
name|uint64_t
name|isp_wwnn_nvram
decl_stmt|;
name|uint64_t
name|isp_wwpn_nvram
decl_stmt|;
comment|/* 	 * Our Port Data Base 	 */
name|fcportdb_t
name|portdb
index|[
name|MAX_FC_TARG
index|]
decl_stmt|;
comment|/* 	 * Scratch DMA mapped in area to fetch Port Database stuff, etc. 	 */
name|void
modifier|*
name|isp_scratch
decl_stmt|;
name|XS_DMA_ADDR_T
name|isp_scdma
decl_stmt|;
name|uint8_t
name|isp_scanscratch
index|[
name|ISP_FC_SCRLEN
index|]
decl_stmt|;
block|}
name|fcparam
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FW_CONFIG_WAIT
value|0
end_define

begin_define
define|#
directive|define
name|FW_WAIT_LINK
value|1
end_define

begin_define
define|#
directive|define
name|FW_WAIT_LOGIN
value|2
end_define

begin_define
define|#
directive|define
name|FW_READY
value|3
end_define

begin_define
define|#
directive|define
name|FW_LOSS_OF_SYNC
value|4
end_define

begin_define
define|#
directive|define
name|FW_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|FW_REINIT
value|6
end_define

begin_define
define|#
directive|define
name|FW_NON_PART
value|7
end_define

begin_define
define|#
directive|define
name|LOOP_NIL
value|0
end_define

begin_define
define|#
directive|define
name|LOOP_HAVE_LINK
value|1
end_define

begin_define
define|#
directive|define
name|LOOP_HAVE_ADDR
value|2
end_define

begin_define
define|#
directive|define
name|LOOP_TESTING_LINK
value|3
end_define

begin_define
define|#
directive|define
name|LOOP_LTEST_DONE
value|4
end_define

begin_define
define|#
directive|define
name|LOOP_SCANNING_LOOP
value|5
end_define

begin_define
define|#
directive|define
name|LOOP_LSCAN_DONE
value|6
end_define

begin_define
define|#
directive|define
name|LOOP_SCANNING_FABRIC
value|7
end_define

begin_define
define|#
directive|define
name|LOOP_FSCAN_DONE
value|8
end_define

begin_define
define|#
directive|define
name|LOOP_SYNCING_PDB
value|9
end_define

begin_define
define|#
directive|define
name|LOOP_READY
value|10
end_define

begin_define
define|#
directive|define
name|TOPO_NL_PORT
value|0
end_define

begin_define
define|#
directive|define
name|TOPO_FL_PORT
value|1
end_define

begin_define
define|#
directive|define
name|TOPO_N_PORT
value|2
end_define

begin_define
define|#
directive|define
name|TOPO_F_PORT
value|3
end_define

begin_define
define|#
directive|define
name|TOPO_PTP_STUB
value|4
end_define

begin_define
define|#
directive|define
name|TOPO_IS_FABRIC
parameter_list|(
name|x
parameter_list|)
value|((x) == TOPO_FL_PORT || (x) == TOPO_F_PORT)
end_define

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
comment|/* 	 * Pointer to bus specific functions and data 	 */
name|struct
name|ispmdvec
modifier|*
name|isp_mdvec
decl_stmt|;
comment|/* 	 * (Mostly) nonvolatile state. Board specific parameters 	 * may contain some volatile state (e.g., current loop state). 	 */
name|void
modifier|*
name|isp_param
decl_stmt|;
comment|/* type specific */
name|uint64_t
name|isp_fwattr
decl_stmt|;
comment|/* firmware attributes */
name|uint16_t
name|isp_fwrev
index|[
literal|3
index|]
decl_stmt|;
comment|/* Loaded F/W revision */
name|uint16_t
name|isp_maxcmds
decl_stmt|;
comment|/* max possible I/O cmds */
name|uint8_t
name|isp_type
decl_stmt|;
comment|/* HBA Chip Type */
name|uint8_t
name|isp_revision
decl_stmt|;
comment|/* HBA Chip H/W Revision */
name|uint8_t
name|isp_nirq
decl_stmt|;
comment|/* number of IRQs */
name|uint16_t
name|isp_nchan
decl_stmt|;
comment|/* number of channels */
name|uint32_t
name|isp_maxluns
decl_stmt|;
comment|/* maximum luns supported */
name|uint32_t
name|isp_clock
range|:
literal|8
decl_stmt|,
comment|/* input clock */
range|:
literal|5
decl_stmt|,
name|isp_port
range|:
literal|1
decl_stmt|,
comment|/* 23XX/24XX only */
name|isp_bustype
range|:
literal|1
decl_stmt|,
comment|/* SBus or PCI */
name|isp_loaded_fw
range|:
literal|1
decl_stmt|,
comment|/* loaded firmware */
name|isp_dblev
range|:
literal|16
decl_stmt|;
comment|/* debug log mask */
name|uint32_t
name|isp_confopts
decl_stmt|;
comment|/* config options */
name|uint32_t
name|isp_rqstinrp
decl_stmt|;
comment|/* register for REQINP */
name|uint32_t
name|isp_rqstoutrp
decl_stmt|;
comment|/* register for REQOUTP */
name|uint32_t
name|isp_respinrp
decl_stmt|;
comment|/* register for RESINP */
name|uint32_t
name|isp_respoutrp
decl_stmt|;
comment|/* register for RESOUTP */
comment|/* 	 * Volatile state 	 */
specifier|volatile
name|u_int
name|isp_mboxbsy
decl_stmt|;
comment|/* mailbox command active */
specifier|volatile
name|u_int
name|isp_state
decl_stmt|;
specifier|volatile
name|mbreg_t
name|isp_curmbx
decl_stmt|;
comment|/* currently active mailbox command */
specifier|volatile
name|uint32_t
name|isp_reqodx
decl_stmt|;
comment|/* index of last ISP pickup */
specifier|volatile
name|uint32_t
name|isp_reqidx
decl_stmt|;
comment|/* index of next request */
specifier|volatile
name|uint32_t
name|isp_residx
decl_stmt|;
comment|/* index of last ISP write */
specifier|volatile
name|uint32_t
name|isp_resodx
decl_stmt|;
comment|/* index of next result */
specifier|volatile
name|uint32_t
name|isp_atioodx
decl_stmt|;
comment|/* index of next ATIO */
specifier|volatile
name|uint32_t
name|isp_obits
decl_stmt|;
comment|/* mailbox command output */
specifier|volatile
name|uint32_t
name|isp_serno
decl_stmt|;
comment|/* rolling serial number */
specifier|volatile
name|uint16_t
name|isp_mboxtmp
index|[
name|MAX_MAILBOX
index|]
decl_stmt|;
specifier|volatile
name|uint16_t
name|isp_lastmbxcmd
decl_stmt|;
comment|/* last mbox command sent */
specifier|volatile
name|uint16_t
name|isp_seqno
decl_stmt|;
comment|/* running sequence number */
comment|/* 	 * Active commands are stored here, indexed by handle functions. 	 */
name|isp_hdl_t
modifier|*
name|isp_xflist
decl_stmt|;
name|isp_hdl_t
modifier|*
name|isp_xffree
decl_stmt|;
comment|/* 	 * DMA mapped in area for synchronous IOCB requests. 	 */
name|void
modifier|*
name|isp_iocb
decl_stmt|;
name|XS_DMA_ADDR_T
name|isp_iocb_dma
decl_stmt|;
comment|/* 	 * request/result queue pointers and DMA handles for them. 	 */
name|void
modifier|*
name|isp_rquest
decl_stmt|;
name|void
modifier|*
name|isp_result
decl_stmt|;
name|XS_DMA_ADDR_T
name|isp_rquest_dma
decl_stmt|;
name|XS_DMA_ADDR_T
name|isp_result_dma
decl_stmt|;
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
comment|/* for 24XX only */
name|void
modifier|*
name|isp_atioq
decl_stmt|;
name|XS_DMA_ADDR_T
name|isp_atioq_dma
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDPARAM
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|(&((sdparam *)(isp)->isp_param)[(chan)])
end_define

begin_define
define|#
directive|define
name|FCPARAM
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|(&((fcparam *)(isp)->isp_param)[(chan)])
end_define

begin_define
define|#
directive|define
name|ISP_SET_SENDMARKER
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
define|\
value|if (IS_FC(isp)) {				\ 	FCPARAM(isp, chan)->sendmarker = val;	\     } else {					\ 	SDPARAM(isp, chan)->sendmarker = val;	\     }
end_define

begin_define
define|#
directive|define
name|ISP_TST_SENDMARKER
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
define|\
value|(IS_FC(isp)?				\ 	FCPARAM(isp, chan)->sendmarker != 0 :	\ 	SDPARAM(isp, chan)->sendmarker != 0)
end_define

begin_comment
comment|/*  * ISP Driver Run States  */
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
name|ISP_CRASHED
value|1
end_define

begin_define
define|#
directive|define
name|ISP_RESETSTATE
value|2
end_define

begin_define
define|#
directive|define
name|ISP_INITSTATE
value|3
end_define

begin_define
define|#
directive|define
name|ISP_RUNSTATE
value|4
end_define

begin_comment
comment|/*  * ISP Runtime Configuration Options  */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_FULL_DUPLEX
value|0x01
end_define

begin_comment
comment|/* Full Duplex (Fibre Channel only) */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_PORT_PREF
value|0x0e
end_define

begin_comment
comment|/* Mask for Port Prefs (all FC except 2100) */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_PORT_DEF
value|0x00
end_define

begin_comment
comment|/* prefer connection type from NVRAM */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_LPORT_ONLY
value|0x02
end_define

begin_comment
comment|/* insist on {N/F}L-Port connection */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_NPORT_ONLY
value|0x04
end_define

begin_comment
comment|/* insist on {N/F}-Port connection */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_LPORT
value|0x06
end_define

begin_comment
comment|/* prefer {N/F}L-Port connection */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_NPORT
value|0x08
end_define

begin_comment
comment|/* prefer {N/F}-Port connection */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_1GB
value|0x10
end_define

begin_comment
comment|/* force 1GB connection (23XX only) */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_2GB
value|0x20
end_define

begin_comment
comment|/* force 2GB connection (23XX only) */
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
name|ISP_CFG_NONVRAM
value|0x40
end_define

begin_comment
comment|/* ignore NVRAM */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_NOFCTAPE
value|0x100
end_define

begin_comment
comment|/* disable FC-Tape */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_FCTAPE
value|0x200
end_define

begin_comment
comment|/* enable FC-Tape */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_OWNFSZ
value|0x400
end_define

begin_comment
comment|/* override NVRAM frame size */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_OWNLOOPID
value|0x800
end_define

begin_comment
comment|/* override NVRAM loopid */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_OWNEXCTHROTTLE
value|0x1000
end_define

begin_comment
comment|/* override NVRAM execution throttle */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_4GB
value|0x2000
end_define

begin_comment
comment|/* force 4GB connection (24XX only) */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_8GB
value|0x4000
end_define

begin_comment
comment|/* force 8GB connection (25XX only) */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_16GB
value|0x8000
end_define

begin_comment
comment|/* force 16GB connection (82XX only) */
end_comment

begin_comment
comment|/*  * For each channel, the outer layers should know what role that channel  * will take: ISP_ROLE_NONE, ISP_ROLE_INITIATOR, ISP_ROLE_TARGET,  * ISP_ROLE_BOTH.  *  * If you set ISP_ROLE_NONE, the cards will be reset, new firmware loaded,  * NVRAM read, and defaults set, but any further initialization (e.g.  * INITIALIZE CONTROL BLOCK commands for 2X00 cards) won't be done.  *  * If INITIATOR MODE isn't set, attempts to run commands will be stopped  * at isp_start and completed with the equivalent of SELECTION TIMEOUT.  *  * If TARGET MODE is set, it doesn't mean that the rest of target mode support  * needs to be enabled, or will even work. What happens with the 2X00 cards  * here is that if you have enabled it with TARGET MODE as part of the ICB  * options, but you haven't given the f/w any ram resources for ATIOs or  * Immediate Notifies, the f/w just handles what it can and you never see  * anything. Basically, it sends a single byte of data (the first byte,  * which you can set as part of the INITIALIZE CONTROL BLOCK command) for  * INQUIRY, and sends back QUEUE FULL status for any other command.  *  */
end_comment

begin_define
define|#
directive|define
name|ISP_ROLE_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_TARGET
value|0x1
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_INITIATOR
value|0x2
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_BOTH
value|(ISP_ROLE_TARGET|ISP_ROLE_INITIATOR)
end_define

begin_define
define|#
directive|define
name|ISP_ROLE_EITHER
value|ISP_ROLE_BOTH
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ISP_DEFAULT_ROLES
end_ifndef

begin_comment
comment|/*  * Counterintuitively, we prefer to default to role 'none'  * if we are enable target mode support. This gives us the  * maximum flexibility as to which port will do what.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_define
define|#
directive|define
name|ISP_DEFAULT_ROLES
value|ISP_ROLE_NONE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_DEFAULT_ROLES
value|ISP_ROLE_INITIATOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Firmware related defines  */
end_comment

begin_define
define|#
directive|define
name|ISP_CODE_ORG
value|0x1000
end_define

begin_comment
comment|/* default f/w code start */
end_comment

begin_define
define|#
directive|define
name|ISP_CODE_ORG_2300
value|0x0800
end_define

begin_comment
comment|/* ..except for 2300s */
end_comment

begin_define
define|#
directive|define
name|ISP_CODE_ORG_2400
value|0x100000
end_define

begin_comment
comment|/* ..and 2400s */
end_comment

begin_define
define|#
directive|define
name|ISP_FW_REV
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|,
name|mic
parameter_list|)
value|((maj<< 24) | (min<< 16) | mic)
end_define

begin_define
define|#
directive|define
name|ISP_FW_MAJOR
parameter_list|(
name|code
parameter_list|)
value|((code>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|ISP_FW_MINOR
parameter_list|(
name|code
parameter_list|)
value|((code>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|ISP_FW_MICRO
parameter_list|(
name|code
parameter_list|)
value|((code>>  8)& 0xff)
end_define

begin_define
define|#
directive|define
name|ISP_FW_REVX
parameter_list|(
name|xp
parameter_list|)
value|((xp[0]<<24) | (xp[1]<< 16) | xp[2])
end_define

begin_define
define|#
directive|define
name|ISP_FW_MAJORX
parameter_list|(
name|xp
parameter_list|)
value|(xp[0])
end_define

begin_define
define|#
directive|define
name|ISP_FW_MINORX
parameter_list|(
name|xp
parameter_list|)
value|(xp[1])
end_define

begin_define
define|#
directive|define
name|ISP_FW_MICROX
parameter_list|(
name|xp
parameter_list|)
value|(xp[2])
end_define

begin_define
define|#
directive|define
name|ISP_FW_NEWER_THAN
parameter_list|(
name|i
parameter_list|,
name|major
parameter_list|,
name|minor
parameter_list|,
name|micro
parameter_list|)
define|\
value|(ISP_FW_REVX((i)->isp_fwrev)> ISP_FW_REV(major, minor, micro))
end_define

begin_define
define|#
directive|define
name|ISP_FW_OLDER_THAN
parameter_list|(
name|i
parameter_list|,
name|major
parameter_list|,
name|minor
parameter_list|,
name|micro
parameter_list|)
define|\
value|(ISP_FW_REVX((i)->isp_fwrev)< ISP_FW_REV(major, minor, micro))
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
comment|/*  * If we have not otherwise defined SBus support away make sure  * it is defined here such that the code is included as default  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISP_SBUS_SUPPORTED
end_ifndef

begin_define
define|#
directive|define
name|ISP_SBUS_SUPPORTED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|ISP_HA_SCSI_1040C
value|0x7
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1240
value|0x8
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1080
value|0x9
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_1280
value|0xa
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_10160
value|0xb
end_define

begin_define
define|#
directive|define
name|ISP_HA_SCSI_12160
value|0xc
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

begin_define
define|#
directive|define
name|ISP_HA_FC_2200
value|0x20
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC_2300
value|0x30
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC_2312
value|0x40
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC_2322
value|0x50
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC_2400
value|0x60
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC_2500
value|0x70
end_define

begin_define
define|#
directive|define
name|ISP_HA_FC_2600
value|0x80
end_define

begin_define
define|#
directive|define
name|IS_SCSI
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type& ISP_HA_SCSI)
end_define

begin_define
define|#
directive|define
name|IS_1020
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type< ISP_HA_SCSI_1240)
end_define

begin_define
define|#
directive|define
name|IS_1240
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type == ISP_HA_SCSI_1240)
end_define

begin_define
define|#
directive|define
name|IS_1080
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type == ISP_HA_SCSI_1080)
end_define

begin_define
define|#
directive|define
name|IS_1280
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type == ISP_HA_SCSI_1280)
end_define

begin_define
define|#
directive|define
name|IS_10160
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type == ISP_HA_SCSI_10160)
end_define

begin_define
define|#
directive|define
name|IS_12160
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type == ISP_HA_SCSI_12160)
end_define

begin_define
define|#
directive|define
name|IS_12X0
parameter_list|(
name|isp
parameter_list|)
value|(IS_1240(isp) || IS_1280(isp))
end_define

begin_define
define|#
directive|define
name|IS_1X160
parameter_list|(
name|isp
parameter_list|)
value|(IS_10160(isp) || IS_12160(isp))
end_define

begin_define
define|#
directive|define
name|IS_DUALBUS
parameter_list|(
name|isp
parameter_list|)
value|(IS_12X0(isp) || IS_12160(isp))
end_define

begin_define
define|#
directive|define
name|IS_ULTRA2
parameter_list|(
name|isp
parameter_list|)
value|(IS_1080(isp) || IS_1280(isp) || IS_1X160(isp))
end_define

begin_define
define|#
directive|define
name|IS_ULTRA3
parameter_list|(
name|isp
parameter_list|)
value|(IS_1X160(isp))
end_define

begin_define
define|#
directive|define
name|IS_FC
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type& ISP_HA_FC)
end_define

begin_define
define|#
directive|define
name|IS_2100
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type == ISP_HA_FC_2100)
end_define

begin_define
define|#
directive|define
name|IS_2200
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type == ISP_HA_FC_2200)
end_define

begin_define
define|#
directive|define
name|IS_23XX
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type>= ISP_HA_FC_2300&& \ 				(isp)->isp_type< ISP_HA_FC_2400)
end_define

begin_define
define|#
directive|define
name|IS_2300
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type == ISP_HA_FC_2300)
end_define

begin_define
define|#
directive|define
name|IS_2312
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type == ISP_HA_FC_2312)
end_define

begin_define
define|#
directive|define
name|IS_2322
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type == ISP_HA_FC_2322)
end_define

begin_define
define|#
directive|define
name|IS_24XX
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type>= ISP_HA_FC_2400)
end_define

begin_define
define|#
directive|define
name|IS_25XX
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type>= ISP_HA_FC_2500)
end_define

begin_define
define|#
directive|define
name|IS_26XX
parameter_list|(
name|isp
parameter_list|)
value|((isp)->isp_type>= ISP_HA_FC_2600)
end_define

begin_comment
comment|/*  * DMA related macros  */
end_comment

begin_define
define|#
directive|define
name|DMA_WD3
parameter_list|(
name|x
parameter_list|)
value|(((uint16_t)(((uint64_t)x)>> 48))& 0xffff)
end_define

begin_define
define|#
directive|define
name|DMA_WD2
parameter_list|(
name|x
parameter_list|)
value|(((uint16_t)(((uint64_t)x)>> 32))& 0xffff)
end_define

begin_define
define|#
directive|define
name|DMA_WD1
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)((x)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|DMA_WD0
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)((x)& 0xffff))
end_define

begin_define
define|#
directive|define
name|DMA_LO32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t) (x))
end_define

begin_define
define|#
directive|define
name|DMA_HI32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(((uint64_t)x)>> 32))
end_define

begin_comment
comment|/*  * Core System Function Prototypes  */
end_comment

begin_comment
comment|/*  * Reset Hardware. Totally. Assumes that you'll follow this with a call to isp_init.  */
end_comment

begin_function_decl
name|void
name|isp_reset
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize Hardware to known state  */
end_comment

begin_function_decl
name|void
name|isp_init
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset the ISP and call completion for any orphaned commands.  */
end_comment

begin_function_decl
name|int
name|isp_reinit
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Shutdown hardware after use.  */
end_comment

begin_function_decl
name|void
name|isp_shutdown
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Internal Interrupt Service Routine  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_function_decl
name|void
name|isp_intr_atioq
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|isp_intr_async
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|uint16_t
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isp_intr_mbox
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|uint16_t
name|mbox0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isp_intr_respq
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Command Entry Point- Platform Dependent layers call into this  */
end_comment

begin_function_decl
name|int
name|isp_start
parameter_list|(
name|XS_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* these values are what isp_start returns */
end_comment

begin_define
define|#
directive|define
name|CMD_COMPLETE
value|101
end_define

begin_comment
comment|/* command completed */
end_comment

begin_define
define|#
directive|define
name|CMD_EAGAIN
value|102
end_define

begin_comment
comment|/* busy- maybe retry later */
end_comment

begin_define
define|#
directive|define
name|CMD_QUEUED
value|103
end_define

begin_comment
comment|/* command has been queued for execution */
end_comment

begin_define
define|#
directive|define
name|CMD_RQLATER
value|104
end_define

begin_comment
comment|/* requeue this command later */
end_comment

begin_comment
comment|/*  * Command Completion Point- Core layers call out from this with completed cmds  */
end_comment

begin_function_decl
name|void
name|isp_done
parameter_list|(
name|XS_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform Dependent to External to Internal Control Function  *  * Assumes locks are held on entry. You should note that with many of  * these commands locks may be released while this function is called.  *  * ... ISPCTL_RESET_BUS, int channel);  *        Reset BUS on this channel  * ... ISPCTL_RESET_DEV, int channel, int target);  *        Reset Device on this channel at this target.  * ... ISPCTL_ABORT_CMD, XS_T *xs);  *        Abort active transaction described by xs.  * ... IPCTL_UPDATE_PARAMS);  *        Update any operating parameters (speed, etc.)  * ... ISPCTL_FCLINK_TEST, int channel);  *        Test FC link status on this channel  * ... ISPCTL_SCAN_LOOP, int channel);  *        Scan local loop on this channel  * ... ISPCTL_SCAN_FABRIC, int channel);  *        Scan fabric on this channel  * ... ISPCTL_PDB_SYNC, int channel);  *        Synchronize port database on this channel  * ... ISPCTL_SEND_LIP, int channel);  *        Send a LIP on this channel  * ... ISPCTL_GET_NAMES, int channel, int np, uint64_t *wwnn, uint64_t *wwpn)  *        Get a WWNN/WWPN for this N-port handle on this channel  * ... ISPCTL_RUN_MBOXCMD, mbreg_t *mbp)  *        Run this mailbox command  * ... ISPCTL_GET_PDB, int channel, int nphandle, isp_pdb_t *pdb)  *        Get PDB on this channel for this N-port handle  * ... ISPCTL_PLOGX, isp_plcmd_t *)  *        Performa a port login/logout  * ... ISPCTL_CHANGE_ROLE, int channel, int role);  *        Change role of specified channel  *  * ISPCTL_PDB_SYNC is somewhat misnamed. It actually is the final step, in  * order, of ISPCTL_FCLINK_TEST, ISPCTL_SCAN_LOOP, and ISPCTL_SCAN_FABRIC.  * The main purpose of ISPCTL_PDB_SYNC is to complete management of logging  * and logging out of fabric devices (if one is on a fabric) and then marking  * the 'loop state' as being ready to now be used for sending commands to  * devices.  */
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
block|,
name|ISPCTL_FCLINK_TEST
block|,
name|ISPCTL_SCAN_FABRIC
block|,
name|ISPCTL_SCAN_LOOP
block|,
name|ISPCTL_PDB_SYNC
block|,
name|ISPCTL_SEND_LIP
block|,
name|ISPCTL_GET_NAMES
block|,
name|ISPCTL_RUN_MBOXCMD
block|,
name|ISPCTL_GET_PDB
block|,
name|ISPCTL_PLOGX
block|,
name|ISPCTL_CHANGE_ROLE
block|}
name|ispctl_t
typedef|;
end_typedef

begin_function_decl
name|int
name|isp_control
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|ispctl_t
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform Dependent to Internal to External Control Function  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ISPASYNC_NEW_TGT_PARAMS
block|,
comment|/* SPI New Target Parameters */
name|ISPASYNC_BUS_RESET
block|,
comment|/* All Bus Was Reset */
name|ISPASYNC_LOOP_DOWN
block|,
comment|/* FC Loop Down */
name|ISPASYNC_LOOP_UP
block|,
comment|/* FC Loop Up */
name|ISPASYNC_LIP
block|,
comment|/* FC LIP Received */
name|ISPASYNC_LOOP_RESET
block|,
comment|/* FC Loop Reset Received */
name|ISPASYNC_CHANGE_NOTIFY
block|,
comment|/* FC Change Notification */
name|ISPASYNC_DEV_ARRIVED
block|,
comment|/* FC Device Arrived */
name|ISPASYNC_DEV_CHANGED
block|,
comment|/* FC Device Changed */
name|ISPASYNC_DEV_STAYED
block|,
comment|/* FC Device Stayed */
name|ISPASYNC_DEV_GONE
block|,
comment|/* FC Device Departure */
name|ISPASYNC_TARGET_NOTIFY
block|,
comment|/* All target async notification */
name|ISPASYNC_TARGET_NOTIFY_ACK
block|,
comment|/* All target notify ack required */
name|ISPASYNC_TARGET_ACTION
block|,
comment|/* All target action requested */
name|ISPASYNC_FW_CRASH
block|,
comment|/* All Firmware has crashed */
name|ISPASYNC_FW_RESTARTED
comment|/* All Firmware has been restarted */
block|}
name|ispasync_t
typedef|;
end_typedef

begin_function_decl
name|void
name|isp_async
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|ispasync_t
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ISPASYNC_CHANGE_PDB
value|0
end_define

begin_define
define|#
directive|define
name|ISPASYNC_CHANGE_SNS
value|1
end_define

begin_define
define|#
directive|define
name|ISPASYNC_CHANGE_OTHER
value|2
end_define

begin_comment
comment|/*  * Platform Dependent Error and Debug Printout  *  * Two required functions for each platform must be provided:  *  *    void isp_prt(ispsoftc_t *, int level, const char *, ...)  *    void isp_xs_prt(ispsoftc_t *, XS_T *, int level, const char *, ...)  *  * but due to compiler differences on different platforms this won't be  * formally defined here. Instead, they go in each platform definition file.  */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGALL
value|0x0
end_define

begin_comment
comment|/* log always */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGCONFIG
value|0x1
end_define

begin_comment
comment|/* log configuration messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGINFO
value|0x2
end_define

begin_comment
comment|/* log informational messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGWARN
value|0x4
end_define

begin_comment
comment|/* log warning messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGERR
value|0x8
end_define

begin_comment
comment|/* log error messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGDEBUG0
value|0x10
end_define

begin_comment
comment|/* log simple debug messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGDEBUG1
value|0x20
end_define

begin_comment
comment|/* log intermediate debug messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGDEBUG2
value|0x40
end_define

begin_comment
comment|/* log most debug messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGDEBUG3
value|0x80
end_define

begin_comment
comment|/* log high frequency debug messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOG_SANCFG
value|0x100
end_define

begin_comment
comment|/* log SAN configuration */
end_comment

begin_define
define|#
directive|define
name|ISP_LOG_CWARN
value|0x200
end_define

begin_comment
comment|/* log SCSI command "warnings" (e.g., check conditions) */
end_comment

begin_define
define|#
directive|define
name|ISP_LOG_WARN1
value|0x400
end_define

begin_comment
comment|/* log WARNS we might be interested at some time */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGTINFO
value|0x1000
end_define

begin_comment
comment|/* log informational messages (target mode) */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGTDEBUG0
value|0x2000
end_define

begin_comment
comment|/* log simple debug messages (target mode) */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGTDEBUG1
value|0x4000
end_define

begin_comment
comment|/* log intermediate debug messages (target) */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGTDEBUG2
value|0x8000
end_define

begin_comment
comment|/* log all debug messages (target) */
end_comment

begin_comment
comment|/*  * Each Platform provides it's own isposinfo substructure of the ispsoftc  * defined above.  *  * Each platform must also provide the following macros/defines:  *  *  *	ISP_FC_SCRLEN				FC scratch area DMA length  *  *	ISP_MEMZERO(dst, src)			platform zeroing function  *	ISP_MEMCPY(dst, src, count)		platform copying function  *	ISP_SNPRINTF(buf, bufsize, fmt, ...)	snprintf  *	ISP_DELAY(usecs)			microsecond spindelay function  *	ISP_SLEEP(isp, usecs)			microsecond sleep function  *  *	ISP_INLINE				___inline or not- depending on how  *						good your debugger is  *	ISP_MIN					shorthand for ((a)< (b))? (a) : (b)  *  *	NANOTIME_T				nanosecond time type  *  *	GET_NANOTIME(NANOTIME_T *)		get current nanotime.  *  *	GET_NANOSEC(NANOTIME_T *)		get uint64_t from NANOTIME_T  *  *	NANOTIME_SUB(NANOTIME_T *, NANOTIME_T *)  *						subtract two NANOTIME_T values  *  *	MAXISPREQUEST(ispsoftc_t *)		maximum request queue size  *						for this particular board type  *  *	MEMORYBARRIER(ispsoftc_t *, barrier_type, offset, size, chan)  *  *		Function/Macro the provides memory synchronization on  *		various objects so that the ISP's and the system's view  *		of the same object is consistent.  *  *	MBOX_ACQUIRE(ispsoftc_t *)		acquire lock on mailbox regs  *	MBOX_WAIT_COMPLETE(ispsoftc_t *, mbreg_t *) wait for cmd to be done  *	MBOX_NOTIFY_COMPLETE(ispsoftc_t *)	notification of mbox cmd donee  *	MBOX_RELEASE(ispsoftc_t *)		release lock on mailbox regs  *  *	FC_SCRATCH_ACQUIRE(ispsoftc_t *, chan)	acquire lock on FC scratch area  *						return -1 if you cannot  *	FC_SCRATCH_RELEASE(ispsoftc_t *, chan)	acquire lock on FC scratch area  *  *	FCP_NEXT_CRN(ispsoftc_t *, XS_T *, rslt, channel, target, lun)	generate the next command reference number. XS_T * may be null.  *  *	SCSI_GOOD	SCSI 'Good' Status  *	SCSI_CHECK	SCSI 'Check Condition' Status  *	SCSI_BUSY	SCSI 'Busy' Status  *	SCSI_QFULL	SCSI 'Queue Full' Status  *  *	XS_T			Platform SCSI transaction type (i.e., command for HBA)  *	XS_DMA_ADDR_T		Platform PCI DMA Address Type  *	XS_GET_DMA_SEG(..)	Get 32 bit dma segment list value  *	XS_GET_DMA64_SEG(..)	Get 64 bit dma segment list value  *	XS_ISP(xs)		gets an instance out of an XS_T  *	XS_CHANNEL(xs)		gets the channel (bus # for DUALBUS cards) ""  *	XS_TGT(xs)		gets the target ""  *	XS_LUN(xs)		gets the lun ""  *	XS_CDBP(xs)		gets a pointer to the scsi CDB ""  *	XS_CDBLEN(xs)		gets the CDB's length ""  *	XS_XFRLEN(xs)		gets the associated data transfer length ""  *	XS_TIME(xs)		gets the time (in seconds) for this command  *	XS_GET_RESID(xs)	gets the current residual count  *	XS_GET_RESID(xs, resid)	sets the current residual count  *	XS_STSP(xs)		gets a pointer to the SCSI status byte ""  *	XS_SNSP(xs)		gets a pointer to the associate sense data  *	XS_TOT_SNSLEN(xs)	gets the total length of sense data storage  *	XS_CUR_SNSLEN(xs)	gets the currently used lenght of sense data storage  *	XS_SNSKEY(xs)		dereferences XS_SNSP to get the current stored Sense Key  *	XS_SNSASC(xs)		dereferences XS_SNSP to get the current stored Additional Sense Code  *	XS_SNSASCQ(xs)		dereferences XS_SNSP to get the current stored Additional Sense Code Qualifier  *	XS_TAG_P(xs)		predicate of whether this command should be tagged  *	XS_TAG_TYPE(xs)		which type of tag to use  *	XS_SETERR(xs)		set error state  *  *		HBA_NOERROR	command has no erros  *		HBA_BOTCH	hba botched something  *		HBA_CMDTIMEOUT	command timed out  *		HBA_SELTIMEOUT	selection timed out (also port logouts for FC)  *		HBA_TGTBSY	target returned a BUSY status  *		HBA_BUSRESET	bus reset destroyed command  *		HBA_ABORTED	command was aborted (by request)  *		HBA_DATAOVR	a data overrun was detected  *		HBA_ARQFAIL	Automatic Request Sense failed  *  *	XS_ERR(xs)	return current error state  *	XS_NOERR(xs)	there is no error currently set  *	XS_INITERR(xs)	initialize error state  *  *	XS_SAVE_SENSE(xs, sp, len)	save sense data  *	XS_APPEND_SENSE(xs, sp, len)	append more sense data  *  *	XS_SENSE_VALID(xs)		indicates whether sense is valid  *  *	DEFAULT_FRAMESIZE(ispsoftc_t *)		Default Frame Size  *	DEFAULT_EXEC_THROTTLE(ispsoftc_t *)	Default Execution Throttle  *  *	DEFAULT_ROLE(ispsoftc_t *, int)		Get Default Role for a channel  *	DEFAULT_IID(ispsoftc_t *, int)		Default SCSI initiator ID  *	DEFAULT_LOOPID(ispsoftc_t *, int)	Default FC Loop ID  *  *		These establish reasonable defaults for each platform.  * 		These must be available independent of card NVRAM and are  *		to be used should NVRAM not be readable.  *  *	DEFAULT_NODEWWN(ispsoftc_t *, chan)	Default FC Node WWN to use  *	DEFAULT_PORTWWN(ispsoftc_t *, chan)	Default FC Port WWN to use  *  *		These defines are hooks to allow the setting of node and  *		port WWNs when NVRAM cannot be read or is to be overriden.  *  *	ACTIVE_NODEWWN(ispsoftc_t *, chan)	FC Node WWN to use  *	ACTIVE_PORTWWN(ispsoftc_t *, chan)	FC Port WWN to use  *  *		After NVRAM is read, these will be invoked to get the  *		node and port WWNs that will actually be used for this  *		channel.  *  *  *	ISP_IOXPUT_8(ispsoftc_t *, uint8_t srcval, uint8_t *dstptr)  *	ISP_IOXPUT_16(ispsoftc_t *, uint16_t srcval, uint16_t *dstptr)  *	ISP_IOXPUT_32(ispsoftc_t *, uint32_t srcval, uint32_t *dstptr)  *  *	ISP_IOXGET_8(ispsoftc_t *, uint8_t *srcptr, uint8_t dstrval)  *	ISP_IOXGET_16(ispsoftc_t *, uint16_t *srcptr, uint16_t dstrval)  *	ISP_IOXGET_32(ispsoftc_t *, uint32_t *srcptr, uint32_t dstrval)  *  *	ISP_SWIZZLE_NVRAM_WORD(ispsoftc_t *, uint16_t *)  *	ISP_SWIZZLE_NVRAM_LONG(ispsoftc_t *, uint32_t *)  *	ISP_SWAP16(ispsoftc_t *, uint16_t srcval)  *	ISP_SWAP32(ispsoftc_t *, uint32_t srcval)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_comment
comment|/*  * The functions below are for the publicly available  * target mode functions that are internal to the Qlogic driver.  */
end_comment

begin_comment
comment|/*  * This function handles new response queue entry appropriate for target mode.  */
end_comment

begin_function_decl
name|int
name|isp_target_notify
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function externalizes the ability to acknowledge an Immediate Notify request.  */
end_comment

begin_function_decl
name|int
name|isp_notify_ack
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function externalized acknowledging (success/fail) an ABTS frame  */
end_comment

begin_function_decl
name|int
name|isp_acknak_abts
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General request queue 'put' routine for target mode entries.  */
end_comment

begin_function_decl
name|int
name|isp_target_put_entry
parameter_list|(
name|ispsoftc_t
modifier|*
name|isp
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General routine to put back an ATIO entry-  * used for replenishing f/w resource counts.  * The argument is a pointer to a source ATIO  * or ATIO2.  */
end_comment

begin_function_decl
name|int
name|isp_target_put_atio
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General routine to send a final CTIO for a command- used mostly for  * local responses.  */
end_comment

begin_function_decl
name|int
name|isp_endcmd
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ECMD_SVALID
value|0x100
end_define

begin_define
define|#
directive|define
name|ECMD_RVALID
value|0x200
end_define

begin_define
define|#
directive|define
name|ECMD_TERMINATE
value|0x400
end_define

begin_comment
comment|/*  * Handle an asynchronous event  */
end_comment

begin_function_decl
name|void
name|isp_target_async
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPVAR_H */
end_comment

end_unit

