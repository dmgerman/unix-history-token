begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Soft Definitions for for Qlogic ISP SCSI adapters.  *  * Copyright (c) 1997, 1998, 1999, 2000 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
file|<dev/ic/ispmbox.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_include
include|#
directive|include
file|<dev/ic/isp_target.h>
end_include

begin_include
include|#
directive|include
file|<dev/ic/isp_tpublic.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_include
include|#
directive|include
file|<dev/isp/isp_target.h>
end_include

begin_include
include|#
directive|include
file|<dev/isp/isp_tpublic.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|"ispmbox.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_include
include|#
directive|include
file|"isp_target.h"
end_include

begin_include
include|#
directive|include
file|"isp_tpublic.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISP_CORE_VERSION_MAJOR
value|2
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
name|XS_T
operator|*
operator|,
name|ispreq_t
operator|*
operator|,
name|u_int16_t
operator|*
operator|,
name|u_int16_t
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
name|XS_T
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
operator|,
specifier|const
name|char
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
name|dv_conf1
decl_stmt|;
name|u_int16_t
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISP2100_FABRIC
end_ifdef

begin_define
define|#
directive|define
name|MAX_FC_TARG
value|256
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_FC_TARG
value|126
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

begin_comment
comment|/*  * Macros to access ISP registers through bus specific layers-  * mostly wrappers to vector through the mdvec structure.  */
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
name|hndl
parameter_list|)
define|\
value|if ((isp)->isp_mdvec->dv_dmaclr) \ 	    (*(isp)->isp_mdvec->dv_dmaclr)((isp), (xs), (hndl))
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
name|iptr
parameter_list|)
define|\
value|MEMORYBARRIER(isp, SYNC_REQUEST, iptr, QENTRY_LEN); \ 	ISP_WRITE(isp, INMAILBOX4, iptr); \ 	isp->isp_reqidx = iptr
end_define

begin_comment
comment|/*  * SCSI Specific Host Adapter Parameters- per bus, per target  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|isp_gotdparms
range|:
literal|1
decl_stmt|,
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
literal|3
decl_stmt|,
name|isp_ultramode
range|:
literal|1
decl_stmt|,
name|isp_diffmode
range|:
literal|1
decl_stmt|,
name|isp_lvdmode
range|:
literal|1
decl_stmt|,
name|isp_fast_mttr
range|:
literal|1
decl_stmt|,
comment|/* fast sram */
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
name|dev_enable
range|:
literal|1
decl_stmt|,
comment|/* ignored */
range|:
literal|1
decl_stmt|,
name|dev_update
range|:
literal|1
decl_stmt|,
name|dev_refresh
range|:
literal|1
decl_stmt|,
name|exc_throttle
range|:
literal|8
decl_stmt|,
name|cur_offset
range|:
literal|4
decl_stmt|,
name|sync_offset
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|cur_period
decl_stmt|;
comment|/* current sync period */
name|u_int8_t
name|sync_period
decl_stmt|;
comment|/* goal sync period */
name|u_int16_t
name|dev_flags
decl_stmt|;
comment|/* goal device flags */
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

begin_define
define|#
directive|define
name|FL_PORT_ID
value|0x7e
end_define

begin_comment
comment|/* FL_Port Special ID */
end_comment

begin_define
define|#
directive|define
name|FC_PORT_ID
value|0x7f
end_define

begin_comment
comment|/* Fabric Controller Special ID */
end_comment

begin_define
define|#
directive|define
name|FC_SNS_ID
value|0x80
end_define

begin_comment
comment|/* SNS Server Special ID */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|isp_fwoptions
range|:
literal|16
decl_stmt|,
range|:
literal|4
decl_stmt|,
name|loop_seen_once
range|:
literal|1
decl_stmt|,
name|isp_loopstate
range|:
literal|3
decl_stmt|,
comment|/* Current Loop State */
name|isp_fwstate
range|:
literal|3
decl_stmt|,
comment|/* ISP F/W state */
name|isp_gotdparms
range|:
literal|1
decl_stmt|,
name|isp_topo
range|:
literal|3
decl_stmt|,
name|isp_onfabric
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|isp_loopid
decl_stmt|;
comment|/* hard loop id */
name|u_int8_t
name|isp_alpa
decl_stmt|;
comment|/* ALPA */
specifier|volatile
name|u_int16_t
name|isp_lipseq
decl_stmt|;
comment|/* LIP sequence # */
name|u_int32_t
name|isp_portid
decl_stmt|;
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
name|isp_reserved
decl_stmt|;
name|u_int16_t
name|isp_maxalloc
decl_stmt|;
name|u_int16_t
name|isp_maxfrmlen
decl_stmt|;
name|u_int64_t
name|isp_nodewwn
decl_stmt|;
name|u_int64_t
name|isp_portwwn
decl_stmt|;
comment|/* 	 * Port Data Base. This is indexed by 'target', which is invariate. 	 * However, elements within can move around due to loop changes, 	 * so the actual loop ID passed to the F/W is in this structure. 	 * The first time the loop is seen up, loopid will match the index 	 * (except for fabric nodes which are above mapped above FC_SNS_ID 	 * and are completely virtual), but subsequent LIPs can cause things 	 * to move around. 	 */
struct|struct
name|lportdb
block|{
name|u_int
name|loopid
range|:
literal|8
decl_stmt|,
range|:
literal|4
decl_stmt|,
name|loggedin
range|:
literal|1
decl_stmt|,
name|roles
range|:
literal|2
decl_stmt|,
name|valid
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|portid
decl_stmt|;
name|u_int64_t
name|node_wwn
decl_stmt|;
name|u_int64_t
name|port_wwn
decl_stmt|;
block|}
name|portdb
index|[
name|MAX_FC_TARG
index|]
struct|,
name|tport
index|[
name|FL_PORT_ID
index|]
struct|;
comment|/* 	 * Scratch DMA mapped in area to fetch Port Database stuff, etc. 	 */
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
name|FW_CONFIG_WAIT
value|0
end_define

begin_define
define|#
directive|define
name|FW_WAIT_AL_PA
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
name|LOOP_LIP_RCVD
value|1
end_define

begin_define
define|#
directive|define
name|LOOP_PDB_RCVD
value|2
end_define

begin_define
define|#
directive|define
name|LOOP_READY
value|7
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

begin_comment
comment|/*  * Soft Structure per host adapter  */
end_comment

begin_typedef
typedef|typedef
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
name|u_int16_t
name|isp_fwrev
index|[
literal|3
index|]
decl_stmt|;
comment|/* Loaded F/W revision */
name|u_int16_t
name|isp_romfw_rev
index|[
literal|3
index|]
decl_stmt|;
comment|/* PROM F/W revision */
name|u_int16_t
name|isp_maxcmds
decl_stmt|;
comment|/* max possible I/O cmds */
name|u_int8_t
name|isp_type
decl_stmt|;
comment|/* HBA Chip Type */
name|u_int8_t
name|isp_revision
decl_stmt|;
comment|/* HBA Chip H/W Revision */
name|u_int32_t
name|isp_maxluns
decl_stmt|;
comment|/* maximum luns supported */
name|u_int32_t
name|isp_touched
range|:
literal|1
decl_stmt|,
comment|/* board ever seen? */
range|:
literal|1
decl_stmt|,
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
literal|12
decl_stmt|,
comment|/* debug log mask */
name|isp_clock
range|:
literal|8
decl_stmt|,
comment|/* input clock */
name|isp_confopts
range|:
literal|8
decl_stmt|;
comment|/* config options */
comment|/* 	 * Instrumentation 	 */
name|u_int64_t
name|isp_intcnt
decl_stmt|;
comment|/* total int count */
name|u_int64_t
name|isp_intbogus
decl_stmt|;
comment|/* spurious int count */
comment|/* 	 * Volatile state 	 */
specifier|volatile
name|u_int32_t
name|isp_mboxbsy
range|:
literal|8
decl_stmt|,
comment|/* mailbox command active */
range|:
literal|1
decl_stmt|,
name|isp_state
range|:
literal|3
decl_stmt|,
name|isp_sendmarker
range|:
literal|2
decl_stmt|,
comment|/* send a marker entry */
name|isp_update
range|:
literal|2
decl_stmt|,
comment|/* update parameters */
name|isp_nactive
range|:
literal|16
decl_stmt|;
comment|/* how many commands active */
specifier|volatile
name|u_int16_t
name|isp_reqodx
decl_stmt|;
comment|/* index of last ISP pickup */
specifier|volatile
name|u_int16_t
name|isp_reqidx
decl_stmt|;
comment|/* index of next request */
specifier|volatile
name|u_int16_t
name|isp_residx
decl_stmt|;
comment|/* index of next result */
specifier|volatile
name|u_int16_t
name|isp_lasthdls
decl_stmt|;
comment|/* last handle seed */
specifier|volatile
name|u_int16_t
name|isp_mboxtmp
index|[
name|MAX_MAILBOX
index|]
decl_stmt|;
comment|/* 	 * Active commands are stored here, indexed by handle functions. 	 */
name|XS_T
modifier|*
modifier|*
name|isp_xflist
decl_stmt|;
comment|/* 	 * request/result queue pointers and dma handles for them. 	 */
name|caddr_t
name|isp_rquest
decl_stmt|;
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
name|ispsoftc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SDPARAM
parameter_list|(
name|isp
parameter_list|)
value|((sdparam *) (isp)->isp_param)
end_define

begin_define
define|#
directive|define
name|FCPARAM
parameter_list|(
name|isp
parameter_list|)
value|((fcparam *) (isp)->isp_param)
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
name|ISP_CFG_NONVRAM
value|0x40
end_define

begin_comment
comment|/* ignore NVRAM */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_NOINIT
value|0x20
end_define

begin_comment
comment|/* just set defaults- don't init */
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
name|ISP_CFG_OWNWWN
value|0x02
end_define

begin_comment
comment|/* override NVRAM wwn */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_PORT_PREF
value|0x0C
end_define

begin_comment
comment|/* Mask for Port Prefs (2200 only) */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_LPORT
value|0x00
end_define

begin_comment
comment|/* prefer {N/F}L-Port connection */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_NPORT
value|0x04
end_define

begin_comment
comment|/* prefer {N/F}-Port connection */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_NPORT_ONLY
value|0x08
end_define

begin_comment
comment|/* insist on {N/F}-Port connection */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_LPORT_ONLY
value|0x0C
end_define

begin_comment
comment|/* insist on {N/F}L-Port connection */
end_comment

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
name|ISP_FW_REVX
parameter_list|(
name|xp
parameter_list|)
value|((xp[0]<<24) | (xp[1]<< 16) | xp[2])
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
name|ISP_HA_SCSI_12160
value|0xb
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
name|IS_SCSI
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type& ISP_HA_SCSI)
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
value|(IS_1080(isp) || IS_1280(isp) || IS_12160(isp))
end_define

begin_define
define|#
directive|define
name|IS_ULTRA3
parameter_list|(
name|isp
parameter_list|)
value|(IS_12160(isp))
end_define

begin_define
define|#
directive|define
name|IS_FC
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type& ISP_HA_FC)
end_define

begin_define
define|#
directive|define
name|IS_2100
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type == ISP_HA_FC_2100)
end_define

begin_define
define|#
directive|define
name|IS_2200
parameter_list|(
name|isp
parameter_list|)
value|(isp->isp_type == ISP_HA_FC_2200)
end_define

begin_comment
comment|/*  * DMA cookie macros  */
end_comment

begin_define
define|#
directive|define
name|DMA_MSW
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|DMA_LSW
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff))
end_define

begin_comment
comment|/*  * Core System Function Prototypes  */
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
comment|/*  * Reset the ISP and call completion for any orphaned commands.  */
end_comment

begin_decl_stmt
name|void
name|isp_reinit
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
comment|/*  * Command Entry Point- Platform Dependent layers call into this  */
end_comment

begin_decl_stmt
name|int
name|isp_start
name|__P
argument_list|(
operator|(
name|XS_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|isp_done
name|__P
argument_list|(
operator|(
name|XS_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Platform Dependent to External to Internal Control Function  *  * Assumes all locks are held and that no reentrancy issues need be dealt with.  *  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ISPCTL_RESET_BUS
block|,
comment|/* Reset Bus */
name|ISPCTL_RESET_DEV
block|,
comment|/* Reset Device */
name|ISPCTL_ABORT_CMD
block|,
comment|/* Abort Command */
name|ISPCTL_UPDATE_PARAMS
block|,
comment|/* Update Operating Parameters */
name|ISPCTL_FCLINK_TEST
block|,
comment|/* Test FC Link Status */
name|ISPCTL_PDB_SYNC
block|,
comment|/* Synchronize Port Database */
name|ISPCTL_TOGGLE_TMODE
comment|/* toggle target mode */
block|}
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
comment|/*  * Platform Dependent to Internal to External Control Function  * (each platform must provide such a function)  *  * Assumes all locks are held and that no reentrancy issues need be dealt with.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ISPASYNC_NEW_TGT_PARAMS
block|,
name|ISPASYNC_BUS_RESET
block|,
comment|/* Bus Was Reset */
name|ISPASYNC_LOOP_DOWN
block|,
comment|/* FC Loop Down */
name|ISPASYNC_LOOP_UP
block|,
comment|/* FC Loop Up */
name|ISPASYNC_CHANGE_NOTIFY
block|,
comment|/* FC SNS or Port Database Changed */
name|ISPASYNC_FABRIC_DEV
block|,
comment|/* FC Fabric Device Arrived/Left */
name|ISPASYNC_LOGGED_INOUT
block|,
comment|/* FC Object Logged In/Out */
name|ISPASYNC_TARGET_MESSAGE
block|,
comment|/* target message */
name|ISPASYNC_TARGET_EVENT
block|,
comment|/* target asynchronous event */
name|ISPASYNC_TARGET_ACTION
comment|/* other target command action */
block|}
name|ispasync_t
typedef|;
end_typedef

begin_decl_stmt
name|int
name|isp_async
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|ispasync_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Platform Dependent Error and Debug Printout  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_decl_stmt
name|void
name|isp_prt
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|int
name|level
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__printf__
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|isp_prt
name|__P
argument_list|(
operator|(
expr|struct
name|ispsoftc
operator|*
operator|,
name|int
name|level
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
value|0x100
end_define

begin_comment
comment|/* log high frequency debug messages */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGTDEBUG0
value|0x200
end_define

begin_comment
comment|/* log simple debug messages (target mode) */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGTDEBUG1
value|0x400
end_define

begin_comment
comment|/* log intermediate debug messages (target) */
end_comment

begin_define
define|#
directive|define
name|ISP_LOGTDEBUG2
value|0x800
end_define

begin_comment
comment|/* log all debug messages (target) */
end_comment

begin_comment
comment|/*  * Each Platform provides it's own isposinfo substructure of the ispsoftc  * defined above.  *  * Each platform must also provide the following macros/defines:  *  *  *	INLINE		-	platform specific define for 'inline' functions  *  *	ISP2100_FABRIC	-	defines whether FABRIC support is enabled  *	ISP2100_SCRLEN	-	length for the Fibre Channel scratch DMA area  *  *	MEMZERO(dst, src)			platform zeroing function  *	MEMCPY(dst, src, count)			platform copying function  *	SNPRINTF(buf, bufsize, fmt, ...)	snprintf  *	STRNCAT(dstbuf, size, srcbuf)		strncat  *	USEC_DELAY(usecs)			microsecond spindelay function  *	USEC_SLEEP(isp, usecs)			microsecond sleep function  *  *	NANOTIME_T				nanosecond time type  *  *	GET_NANOTIME(NANOTIME_T *)		get current nanotime.  *  *	GET_NANOSEC(NANOTIME_T *)		get u_int64_t from NANOTIME_T  *  *	NANOTIME_SUB(NANOTIME_T *, NANOTIME_T *)  *						subtract two NANOTIME_T values  *  *  *	MAXISPREQUEST(struct ispsoftc *)	maximum request queue size  *						for this particular board type  *  *	MEMORYBARRIER(struct ispsoftc *, barrier_type, offset, size)  *  *		Function/Macro the provides memory synchronization on  *		various objects so that the ISP's and the system's view  *		of the same object is consistent.  *  *	MBOX_ACQUIRE(struct ispsoftc *)		acquire lock on mailbox regs  *	MBOX_WAIT_COMPLETE(struct ispsoftc *)	wait for mailbox cmd to be done  *	MBOX_NOTIFY_COMPLETE(struct ispsoftc *)	notification of mbox cmd donee  *	MBOX_RELEASE(struct ispsoftc *)		release lock on mailbox regs  *   *  *	SCSI_GOOD	SCSI 'Good' Status  *	SCSI_CHECK	SCSI 'Check Condition' Status  *	SCSI_BUSY	SCSI 'Busy' Status  *	SCSI_QFULL	SCSI 'Queue Full' Status  *  *	XS_T		Platform SCSI transaction type (i.e., command for HBA)  *	XS_ISP(xs)	gets an instance out of an XS_T  *	XS_CHANNEL(xs)	gets the channel (bus # for DUALBUS cards) ""  *	XS_TGT(xs)	gets the target ""  *	XS_LUN(xs)	gets the lun ""  *	XS_CDBP(xs)	gets a pointer to the scsi CDB ""  *	XS_CDBLEN(xs)	gets the CDB's length ""  *	XS_XFRLEN(xs)	gets the associated data transfer length ""  *	XS_TIME(xs)	gets the time (in milliseconds) for this command  *	XS_RESID(xs)	gets the current residual count  *	XS_STSP(xs)	gets a pointer to the SCSI status byte ""  *	XS_SNSP(xs)	gets a pointer to the associate sense data  *	XS_SNSLEN(xs)	gets the length of sense data storage  *	XS_SNSKEY(xs)	dereferences XS_SNSP to get the current stored Sense Key  *	XS_TAG_P(xs)	predicate of whether this command should be tagged  *	XS_TAG_TYPE(xs)	which type of tag to use  *	XS_SETERR(xs)	set error state  *  *		HBA_NOERROR	command has no erros  *		HBA_BOTCH	hba botched something  *		HBA_CMDTIMEOUT	command timed out  *		HBA_SELTIMEOUT	selection timed out (also port logouts for FC)  *		HBA_TGTBSY	target returned a BUSY status  *		HBA_BUSRESET	bus reset destroyed command  *		HBA_ABORTED	command was aborted (by request)  *		HBA_DATAOVR	a data overrun was detected  *		HBA_ARQFAIL	Automatic Request Sense failed  *  *	XS_ERR(xs)	return current error state  *	XS_NOERR(xs)	there is no error currently set  *	XS_INITERR(xs)	initialize error state  *  *	XS_SAVE_SENSE(xs, sp)		save sense data  *  *	XS_SET_STATE_STAT(isp, sp, xs)	platform dependent interpreter of  *					response queue entry status bits  *  *  *	DEFAULT_IID(struct ispsoftc *)		Default SCSI initiator ID  *	DEFAULT_LOOPID(struct ispsoftc *)	Default FC Loop ID  *	DEFAULT_NODEWWN(struct ispsoftc *)	Default Node WWN  *	DEFAULT_PORTWWN(struct ispsoftc *)	Default Port WWN  *		These establish reasonable defaults for each platform.  * 		These must be available independent of card NVRAM and are  *		to be used should NVRAM not be readable.  *  *	ISP_NODEWWN(struct ispsoftc *)	FC Node WWN to use  *	ISP_PORTWWN(struct ispsoftc *)	FC Port WWN to use  *  *		These are to be used after NVRAM is read. The tags  *		in fcparam.isp_{node,port}wwn reflect the values  *		read from NVRAM (possibly corrected for card botches).  *		Each platform can take that information and override  *		it or ignore and return the Node and Port WWNs to be  * 		used when sending the Qlogic f/w the Initialization Control  *		Block.  *  *	(XXX these do endian specific transformations- in transition XXX)  *	ISP_SWIZZLE_ICB  *	ISP_UNSWIZZLE_AND_COPY_PDBP  *	ISP_SWIZZLE_CONTINUATION  *	ISP_SWIZZLE_REQUEST  *	ISP_UNSWIZZLE_RESPONSE  *	ISP_SWIZZLE_SNS_REQ  *	ISP_UNSWIZZLE_SNS_RSP  *	ISP_SWIZZLE_NVRAM_WORD  *  *  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPVAR_H */
end_comment

end_unit

