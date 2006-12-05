begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Soft Definitions for for Qlogic ISP SCSI adapters.  *  * Copyright (c) 1997-2006 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
value|3
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
name|int
function_decl|(
modifier|*
name|dv_rd_isr
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|uint16_t
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
name|ispreq_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
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
name|void
function_decl|(
modifier|*
name|dv_reset0
function_decl|)
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dv_reset1
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

begin_define
define|#
directive|define
name|MAX_FC_TARG
value|512
end_define

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
name|ISP_READ_ISR
parameter_list|(
name|isp
parameter_list|,
name|isrp
parameter_list|,
name|semap
parameter_list|,
name|mbox0p
parameter_list|)
define|\
value|(*(isp)->isp_mdvec->dv_rd_isr)(isp, isrp, semap, mbox0p)
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
value|if ((isp)->isp_mdvec->dv_dmaclr)	\ 	    (*(isp)->isp_mdvec->dv_dmaclr)((isp), (xs), (hndl))
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

begin_define
define|#
directive|define
name|SYNC_ATIOQ
value|5
end_define

begin_comment
comment|/* atio result queue (24xx) */
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
value|MEMORYBARRIER(isp, SYNC_REQUEST, isp->isp_reqidx, QENTRY_LEN);	\ 	ISP_WRITE(isp, isp->isp_rqstinrp, nxti);			\ 	isp->isp_reqidx = nxti
end_define

begin_comment
comment|/*  * SCSI Specific Host Adapter Parameters- per bus, per target  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
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
name|isp_ptisp
range|:
literal|1
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
name|NPH_FL_ID
value|0x7FE
end_define

begin_comment
comment|/* FL Port Special ID */
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

begin_comment
comment|/*  * FC Port Database entry.  *  * It has a handle that the f/w uses to address commands to a device.  * This handle's value may be assigned by the firmware (e.g., for local loop  * devices) or by the driver (e.g., for fabric devices).  *  * It has a state. If the state if VALID, that means that we've logged into  * the device. We also *may* have a initiator map index entry. This is a value  * from 0..MAX_FC_TARG that is used to index into the isp_ini_map array. If  * the value therein is non-zero, then that value minus one is used to index  * into the Port Database to find the handle for forming commands. There is  * back-index minus one value within to Port Database entry that tells us   * which entry in isp_ini_map points to us (to avoid searching).  *  * Local loop devices the firmware automatically performs PLOGI on for us  * (which is why that handle is imposed upon us). Fabric devices we assign  * a handle to and perform the PLOGI on.  *  * When a PORT DATABASE CHANGED asynchronous event occurs, we mark all VALID  * entries as PROBATIONAL. This allows us, if policy says to, just keep track  * of devices whose handles change but are otherwise the same device (and  * thus keep 'target' constant).  *  * In any case, we search all possible local loop handles. For each one that  * has a port database entity returned, we search for any PROBATIONAL entry  * that matches it and update as appropriate. Otherwise, as a new entry, we  * find room for it in the Port Database. We *try* and use the handle as the  * index to put it into the Database, but that's just an optimization. We mark  * the entry VALID and make sure that the target index is updated and correct.  *  * When we get done searching the local loop, we then search similarily for  * a list of devices we've gotten from the fabric name controller (if we're  * on a fabric). VALID marking is also done similarily.  *  * When all of this is done, we can march through the database and clean up  * any entry that is still PROBATIONAL (these represent devices which have  * departed). Then we're done and can resume normal operations.  *  * Negative invariants that we try and test for are:  *  *  + There can never be two non-NIL entries with the same { Port, Node } WWN  *    duples.  *  *  + There can never be two non-NIL entries with the same handle.  *  *  + There can never be two non-NIL entries which have the same ini_map_idx  *    value.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 	 * This is the handle that the firmware needs in order for us to 	 * send commands to the device. For pre-24XX cards, this would be 	 * the 'loopid'. 	 */
name|uint16_t
name|handle
decl_stmt|;
comment|/* 	 * The ini_map_idx, if nonzero, is the system virtual target ID (+1) 	 * as a cross-reference with the isp_ini_map. 	 * 	 * A device is 'autologin' if the firmware automatically logs into 	 * it (re-logins as needed). Basically, local private loop devices. 	 * 	 * The state is the current state of thsi entry. 	 * 	 * Role is Initiator, Target, Both 	 * 	 * Portid is obvious, as or node&& port WWNs. The new_role and 	 * new_portid is for when we are pending a change. 	 */
name|uint16_t
name|ini_map_idx
range|:
literal|12
decl_stmt|,
name|autologin
range|:
literal|1
decl_stmt|,
comment|/* F/W does PLOGI/PLOGO */
name|state
range|:
literal|3
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|6
decl_stmt|,
name|roles
range|:
literal|2
decl_stmt|,
name|portid
range|:
literal|24
decl_stmt|;
name|uint32_t
name|new_reserved
range|:
literal|6
decl_stmt|,
name|new_roles
range|:
literal|2
decl_stmt|,
name|new_portid
range|:
literal|24
decl_stmt|;
name|uint64_t
name|node_wwn
decl_stmt|;
name|uint64_t
name|port_wwn
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

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_PROBATIONAL
value|1
end_define

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_DEAD
value|2
end_define

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_CHANGED
value|3
end_define

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_NEW
value|4
end_define

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_PENDING_VALID
value|5
end_define

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_ZOMBIE
value|6
end_define

begin_define
define|#
directive|define
name|FC_PORTDB_STATE_VALID
value|7
end_define

begin_comment
comment|/*  * FC card specific information  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
label|:
literal|10
operator|,
name|isp_tmode
operator|:
literal|1
operator|,
name|isp_2klogin
operator|:
literal|1
operator|,
name|isp_sccfw
operator|:
literal|1
operator|,
name|isp_gbspeed
operator|:
literal|3
operator|,
operator|:
literal|1
operator|,
operator|:
literal|1
operator|,
operator|:
literal|1
operator|,
name|isp_loopstate
operator|:
literal|4
operator|,
comment|/* Current Loop State */
name|isp_fwstate
operator|:
literal|4
operator|,
comment|/* ISP F/W state */
name|isp_gotdparms
operator|:
literal|1
operator|,
name|isp_topo
operator|:
literal|3
operator|,
name|loop_seen_once
operator|:
literal|1
expr_stmt|;
name|uint32_t
label|:
literal|8
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
name|isp_fwattr
decl_stmt|;
comment|/* firmware attributes */
name|uint16_t
name|isp_execthrottle
decl_stmt|;
name|uint8_t
name|isp_retry_delay
decl_stmt|;
name|uint8_t
name|isp_retry_count
decl_stmt|;
name|uint8_t
name|isp_reserved
decl_stmt|;
name|uint16_t
name|isp_maxalloc
decl_stmt|;
name|uint16_t
name|isp_maxfrmlen
decl_stmt|;
name|uint64_t
name|isp_nodewwn
decl_stmt|;
name|uint64_t
name|isp_portwwn
decl_stmt|;
comment|/* 	 * Our Port Data Base 	 */
name|fcportdb_t
name|portdb
index|[
name|MAX_FC_TARG
index|]
decl_stmt|;
comment|/* 	 * This maps system virtual 'target' id to a portdb entry. 	 * 	 * The mapping function is to take any non-zero entry and 	 * subtract one to get the portdb index. This means that 	 * entries which are zero are unmapped (i.e., don't exist). 	 */
name|uint16_t
name|isp_ini_map
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
ifdef|#
directive|ifdef
name|ISP_FW_CRASH_DUMP
name|uint16_t
modifier|*
name|isp_dump_data
decl_stmt|;
endif|#
directive|endif
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
name|LOOP_SCANNING_LOOP
value|3
end_define

begin_define
define|#
directive|define
name|LOOP_LSCAN_DONE
value|4
end_define

begin_define
define|#
directive|define
name|LOOP_SCANNING_FABRIC
value|5
end_define

begin_define
define|#
directive|define
name|LOOP_FSCAN_DONE
value|6
end_define

begin_define
define|#
directive|define
name|LOOP_SYNCING_PDB
value|7
end_define

begin_define
define|#
directive|define
name|LOOP_READY
value|8
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
name|uint16_t
name|isp_fwrev
index|[
literal|3
index|]
decl_stmt|;
comment|/* Loaded F/W revision */
name|uint16_t
name|isp_romfw_rev
index|[
literal|3
index|]
decl_stmt|;
comment|/* PROM F/W revision */
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
literal|4
decl_stmt|,
name|isp_port
range|:
literal|1
decl_stmt|,
comment|/* 23XX/24XX only */
name|isp_failed
range|:
literal|1
decl_stmt|,
comment|/* board failed */
name|isp_open
range|:
literal|1
decl_stmt|,
comment|/* opened (ioctl) */
name|isp_touched
range|:
literal|1
decl_stmt|,
comment|/* board ever seen? */
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
name|isp_role
range|:
literal|2
decl_stmt|,
comment|/* roles supported */
name|isp_dblev
range|:
literal|12
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
name|uint32_t
name|isp_atioinrp
decl_stmt|;
comment|/* register for ATIOINP */
name|uint32_t
name|isp_atiooutrp
decl_stmt|;
comment|/* register for ATIOOUTP */
comment|/* 	 * Instrumentation 	 */
name|uint64_t
name|isp_intcnt
decl_stmt|;
comment|/* total int count */
name|uint64_t
name|isp_intbogus
decl_stmt|;
comment|/* spurious int count */
name|uint64_t
name|isp_intmboxc
decl_stmt|;
comment|/* mbox completions */
name|uint64_t
name|isp_intoasync
decl_stmt|;
comment|/* other async */
name|uint64_t
name|isp_rsltccmplt
decl_stmt|;
comment|/* CMDs on result q */
name|uint64_t
name|isp_fphccmplt
decl_stmt|;
comment|/* CMDs via fastpost */
name|uint16_t
name|isp_rscchiwater
decl_stmt|;
name|uint16_t
name|isp_fpcchiwater
decl_stmt|;
comment|/* 	 * Volatile state 	 */
specifier|volatile
name|uint32_t
operator|:
literal|8
operator|,
name|isp_mboxbsy
operator|:
literal|1
operator|,
comment|/* mailbox command active */
name|isp_state
operator|:
literal|3
operator|,
name|isp_sendmarker
operator|:
literal|2
operator|,
comment|/* send a marker entry */
name|isp_update
operator|:
literal|2
operator|,
comment|/* update parameters */
name|isp_nactive
operator|:
literal|16
expr_stmt|;
comment|/* how many commands active */
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
comment|/* index of next result */
specifier|volatile
name|uint32_t
name|isp_resodx
decl_stmt|;
comment|/* index of next result */
specifier|volatile
name|uint32_t
name|isp_rspbsy
decl_stmt|;
specifier|volatile
name|uint32_t
name|isp_lasthdls
decl_stmt|;
comment|/* last handle seed */
specifier|volatile
name|uint32_t
name|isp_obits
decl_stmt|;
comment|/* mailbox command output */
specifier|volatile
name|uint16_t
name|isp_mboxtmp
index|[
name|MAILBOX_STORAGE
index|]
decl_stmt|;
specifier|volatile
name|uint16_t
name|isp_lastmbxcmd
decl_stmt|;
comment|/* last mbox command sent */
specifier|volatile
name|uint16_t
name|isp_mbxwrk0
decl_stmt|;
specifier|volatile
name|uint16_t
name|isp_mbxwrk1
decl_stmt|;
specifier|volatile
name|uint16_t
name|isp_mbxwrk2
decl_stmt|;
specifier|volatile
name|uint16_t
name|isp_mbxwrk8
decl_stmt|;
name|void
modifier|*
name|isp_mbxworkp
decl_stmt|;
comment|/* 	 * Active commands are stored here, indexed by handle functions. 	 */
name|XS_T
modifier|*
modifier|*
name|isp_xflist
decl_stmt|;
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
comment|/* 	 * Active target commands are stored here, indexed by handle function. 	 */
name|void
modifier|*
modifier|*
name|isp_tgtlist
decl_stmt|;
endif|#
directive|endif
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
name|ISP_CFG_TWOGB
value|0x20
end_define

begin_comment
comment|/* force 2GB connection (23XX only) */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_ONEGB
value|0x10
end_define

begin_comment
comment|/* force 1GB connection (23XX only) */
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

begin_define
define|#
directive|define
name|ISP_CFG_OWNWWPN
value|0x100
end_define

begin_comment
comment|/* override NVRAM wwpn */
end_comment

begin_define
define|#
directive|define
name|ISP_CFG_OWNWWNN
value|0x200
end_define

begin_comment
comment|/* override NVRAM wwnn */
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
name|ISP_CFG_FOURGB
value|0x2000
end_define

begin_comment
comment|/* force 4GB connection (24XX only) */
end_comment

begin_comment
comment|/*  * Prior to calling isp_reset for the first time, the outer layer  * should set isp_role to one of NONE, INITIATOR, TARGET, BOTH.  *  * If you set ISP_ROLE_NONE, the cards will be reset, new firmware loaded,  * NVRAM read, and defaults set, but any further initialization (e.g.  * INITIALIZE CONTROL BLOCK commands for 2X00 cards) won't be done.  *  * If INITIATOR MODE isn't set, attempts to run commands will be stopped  * at isp_start and completed with the moral equivalent of SELECTION TIMEOUT.  *  * If TARGET MODE is set, it doesn't mean that the rest of target mode support  * needs to be enabled, or will even work. What happens with the 2X00 cards  * here is that if you have enabled it with TARGET MODE as part of the ICB  * options, but you haven't given the f/w any ram resources for ATIOs or  * Immediate Notifies, the f/w just handles what it can and you never see  * anything. Basically, it sends a single byte of data (the first byte,  * which you can set as part of the INITIALIZE CONTROL BLOCK command) for  * INQUIRY, and sends back QUEUE FULL status for any other command.  *  */
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
comment|/*  * Reset Hardware. Totally. Assumes that you'll follow this with  * a call to isp_init.  */
end_comment

begin_function_decl
name|void
name|isp_reset
parameter_list|(
name|ispsoftc_t
modifier|*
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
name|void
name|isp_reinit
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_FW_CRASH_DUMP
end_ifdef

begin_comment
comment|/*  * Dump firmware entry point.  */
end_comment

begin_function_decl
name|void
name|isp_fw_dump
parameter_list|(
name|ispsoftc_t
modifier|*
name|isp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Internal Interrupt Service Routine  *  * The outer layers do the spade work to get the appropriate status register,  * semaphore register and first mailbox register (if appropriate). This also  * means that most spurious/bogus interrupts not for us can be filtered first.  */
end_comment

begin_function_decl
name|void
name|isp_intr
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
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
comment|/*  * Platform Dependent to External to Internal Control Function  *  * Assumes locks are held on entry. You should note that with many of  * these commands and locks may be released while this is occurring.  *  * A few notes about some of these functions:  *  * ISPCTL_FCLINK_TEST tests to make sure we have good fibre channel link.  * The argument is a pointer to an integer which is the time, in microseconds,  * we should wait to see whether we have good link. This test, if successful,  * lets us know our connection topology and our Loop ID/AL_PA and so on.  * You can't get anywhere without this.  *  * ISPCTL_SCAN_FABRIC queries the name server (if we're on a fabric) for  * all entities using the FC Generic Services subcommand GET ALL NEXT.  * For each found entity, an ISPASYNC_FABRICDEV event is generated (see  * below).  *  * ISPCTL_SCAN_LOOP does a local loop scan. This is only done if the connection  * topology is NL or FL port (private or public loop). Since the Qlogic f/w  * 'automatically' manages local loop connections, this function essentially  * notes the arrival, departure, and possible shuffling around of local loop  * entities. Thus for each arrival and departure this generates an isp_async  * event of ISPASYNC_PROMENADE (see below).  *  * ISPCTL_PDB_SYNC is somewhat misnamed. It actually is the final step, in  * order, of ISPCTL_FCLINK_TEST, ISPCTL_SCAN_FABRIC, and ISPCTL_SCAN_LOOP.  * The main purpose of ISPCTL_PDB_SYNC is to complete management of logging  * and logging out of fabric devices (if one is on a fabric) and then marking  * the 'loop state' as being ready to now be used for sending commands to  * devices. Originally fabric name server and local loop scanning were  * part of this function. It's now been separated to allow for finer control.  */
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
comment|/* Update Operating Parameters (SCSI) */
name|ISPCTL_FCLINK_TEST
block|,
comment|/* Test FC Link Status */
name|ISPCTL_SCAN_FABRIC
block|,
comment|/* (Re)scan Fabric Name Server */
name|ISPCTL_SCAN_LOOP
block|,
comment|/* (Re)scan Local Loop */
name|ISPCTL_PDB_SYNC
block|,
comment|/* Synchronize Port Database */
name|ISPCTL_SEND_LIP
block|,
comment|/* Send a LIP */
name|ISPCTL_GET_PORTNAME
block|,
comment|/* get portname from an N-port handle */
name|ISPCTL_RUN_MBOXCMD
block|,
comment|/* run a mailbox command */
name|ISPCTL_TOGGLE_TMODE
block|,
comment|/* toggle target mode */
name|ISPCTL_GET_PDB
block|,
comment|/* get a single port database entry */
name|ISPCTL_PLOGX
comment|/* do a port login/logout */
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
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform Dependent to Internal to External Control Function  * (each platform must provide such a function)  *  * Assumes locks are held.  *  * A few notes about some of these functions:  *  * ISPASYNC_CHANGE_NOTIFY notifies the outer layer that a change has  * occurred that invalidates the list of fabric devices known and/or  * the list of known loop devices. The argument passed is a pointer  * whose values are defined below  (local loop change, name server  * change, other). 'Other' may simply be a LIP, or a change in  * connection topology.  *  * ISPASYNC_FABRIC_DEV announces the next element in a list of  * fabric device names we're getting out of the name server. The  * argument points to a GET ALL NEXT response structure. The list  * is known to terminate with an entry that refers to ourselves.  * One of the main purposes of this function is to allow outer  * layers, which are OS dependent, to set policy as to which fabric  * devices might actually be logged into (and made visible) later  * at ISPCTL_PDB_SYNC time. Since there's a finite number of fabric  * devices that we can log into (256 less 3 'reserved' for F-port  * topologies), and fabrics can grow up to 8 million or so entries  * (24 bits of Port Address, less a wad of reserved spaces), clearly  * we had better let the OS determine login policy.  *  * ISPASYNC_PROMENADE has an argument that is a pointer to an integer which  * is an index into the portdb in the softc ('target'). Whether that entry's  * valid tag is set or not says whether something has arrived or departed.  * The name refers to a favorite pastime of many city dwellers- watching  * people come and go, talking of Michaelangelo, and so on..  *  * ISPASYNC_UNHANDLED_RESPONSE gives outer layers a chance to parse a  * response queue entry not otherwise handled. The outer layer should  * return non-zero if it handled it. The 'arg' points to an unmassaged  * response queue entry.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ISPASYNC_NEW_TGT_PARAMS
block|,
comment|/* New Target Parameters Negotiated */
name|ISPASYNC_BUS_RESET
block|,
comment|/* Bus Was Reset */
name|ISPASYNC_LOOP_DOWN
block|,
comment|/* FC Loop Down */
name|ISPASYNC_LOOP_UP
block|,
comment|/* FC Loop Up */
name|ISPASYNC_LIP
block|,
comment|/* LIP Received */
name|ISPASYNC_LOOP_RESET
block|,
comment|/* Loop Reset Received */
name|ISPASYNC_CHANGE_NOTIFY
block|,
comment|/* FC Change Notification */
name|ISPASYNC_DEV_ARRIVED
block|,
comment|/* FC Device Arrival */
name|ISPASYNC_DEV_CHANGED
block|,
comment|/* FC Device Change */
name|ISPASYNC_DEV_STAYED
block|,
comment|/* FC Device Stayed the Same */
name|ISPASYNC_DEV_GONE
block|,
comment|/* FC Device Depart */
name|ISPASYNC_TARGET_NOTIFY
block|,
comment|/* target asynchronous notification event */
name|ISPASYNC_TARGET_ACTION
block|,
comment|/* target action requested */
name|ISPASYNC_CONF_CHANGE
block|,
comment|/* Platform Configuration Change */
name|ISPASYNC_UNHANDLED_RESPONSE
block|,
comment|/* Unhandled Response Entry */
name|ISPASYNC_FW_CRASH
block|,
comment|/* Firmware has crashed */
name|ISPASYNC_FW_DUMPED
block|,
comment|/* Firmware crashdump taken */
name|ISPASYNC_FW_RESTARTED
comment|/* Firmware has been restarted */
block|}
name|ispasync_t
typedef|;
end_typedef

begin_function_decl
name|int
name|isp_async
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|ispasync_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ISPASYNC_CHANGE_PDB
value|((void *) 0)
end_define

begin_define
define|#
directive|define
name|ISPASYNC_CHANGE_SNS
value|((void *) 1)
end_define

begin_define
define|#
directive|define
name|ISPASYNC_CHANGE_OTHER
value|((void *) 2)
end_define

begin_comment
comment|/*  * Platform Dependent Error and Debug Printout  *  * Generally this is:  *  *    void isp_prt(ispsoftc_t *, int level, const char *, ...)  *  * but due to compiler differences on different platforms this won't be  * formally done here. Instead, it goes in each platform definition file.  */
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
name|ISP_LOGSANCFG
value|0x100
end_define

begin_comment
comment|/* log SAN configuration */
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
comment|/*  * Each Platform provides it's own isposinfo substructure of the ispsoftc  * defined above.  *  * Each platform must also provide the following macros/defines:  *  *  *	ISP2100_SCRLEN	-	length for the Fibre Channel scratch DMA area  *  *	MEMZERO(dst, src)			platform zeroing function  *	MEMCPY(dst, src, count)			platform copying function  *	SNPRINTF(buf, bufsize, fmt, ...)	snprintf  *	USEC_DELAY(usecs)			microsecond spindelay function  *	USEC_SLEEP(isp, usecs)			microsecond sleep function  *  *	NANOTIME_T				nanosecond time type  *  *	GET_NANOTIME(NANOTIME_T *)		get current nanotime.  *  *	GET_NANOSEC(NANOTIME_T *)		get uint64_t from NANOTIME_T  *  *	NANOTIME_SUB(NANOTIME_T *, NANOTIME_T *)  *						subtract two NANOTIME_T values  *  *  *	MAXISPREQUEST(ispsoftc_t *)	maximum request queue size  *						for this particular board type  *  *	MEMORYBARRIER(ispsoftc_t *, barrier_type, offset, size)  *  *		Function/Macro the provides memory synchronization on  *		various objects so that the ISP's and the system's view  *		of the same object is consistent.  *  *	MBOX_ACQUIRE(ispsoftc_t *)		acquire lock on mailbox regs  *	MBOX_WAIT_COMPLETE(ispsoftc_t *, mbreg_t *) wait for cmd to be done  *	MBOX_NOTIFY_COMPLETE(ispsoftc_t *)	notification of mbox cmd donee  *	MBOX_RELEASE(ispsoftc_t *)		release lock on mailbox regs  *  *	FC_SCRATCH_ACQUIRE(ispsoftc_t *)	acquire lock on FC scratch area  *	FC_SCRATCH_RELEASE(ispsoftc_t *)	acquire lock on FC scratch area  *  *	SCSI_GOOD	SCSI 'Good' Status  *	SCSI_CHECK	SCSI 'Check Condition' Status  *	SCSI_BUSY	SCSI 'Busy' Status  *	SCSI_QFULL	SCSI 'Queue Full' Status  *  *	XS_T		Platform SCSI transaction type (i.e., command for HBA)  *	XS_DMA_ADDR_T	Platform PCI DMA Address Type  *	XS_ISP(xs)	gets an instance out of an XS_T  *	XS_CHANNEL(xs)	gets the channel (bus # for DUALBUS cards) ""  *	XS_TGT(xs)	gets the target ""  *	XS_LUN(xs)	gets the lun ""  *	XS_CDBP(xs)	gets a pointer to the scsi CDB ""  *	XS_CDBLEN(xs)	gets the CDB's length ""  *	XS_XFRLEN(xs)	gets the associated data transfer length ""  *	XS_TIME(xs)	gets the time (in milliseconds) for this command  *	XS_RESID(xs)	gets the current residual count  *	XS_STSP(xs)	gets a pointer to the SCSI status byte ""  *	XS_SNSP(xs)	gets a pointer to the associate sense data  *	XS_SNSLEN(xs)	gets the length of sense data storage  *	XS_SNSKEY(xs)	dereferences XS_SNSP to get the current stored Sense Key  *	XS_TAG_P(xs)	predicate of whether this command should be tagged  *	XS_TAG_TYPE(xs)	which type of tag to use  *	XS_SETERR(xs)	set error state  *  *		HBA_NOERROR	command has no erros  *		HBA_BOTCH	hba botched something  *		HBA_CMDTIMEOUT	command timed out  *		HBA_SELTIMEOUT	selection timed out (also port logouts for FC)  *		HBA_TGTBSY	target returned a BUSY status  *		HBA_BUSRESET	bus reset destroyed command  *		HBA_ABORTED	command was aborted (by request)  *		HBA_DATAOVR	a data overrun was detected  *		HBA_ARQFAIL	Automatic Request Sense failed  *  *	XS_ERR(xs)	return current error state  *	XS_NOERR(xs)	there is no error currently set  *	XS_INITERR(xs)	initialize error state  *  *	XS_SAVE_SENSE(xs, sp, len)	save sense data  *  *	XS_SET_STATE_STAT(isp, sp, xs)	platform dependent interpreter of  *					response queue entry status bits  *  *  *	DEFAULT_IID(ispsoftc_t *)		Default SCSI initiator ID  *	DEFAULT_LOOPID(ispsoftc_t *)	Default FC Loop ID  *	DEFAULT_NODEWWN(ispsoftc_t *)	Default Node WWN  *	DEFAULT_PORTWWN(ispsoftc_t *)	Default Port WWN  *	DEFAULT_FRAMESIZE(ispsoftc_t *)	Default Frame Size  *	DEFAULT_EXEC_THROTTLE(ispsoftc_t *) Default Execution Throttle  *		These establish reasonable defaults for each platform.  * 		These must be available independent of card NVRAM and are  *		to be used should NVRAM not be readable.  *  *	ISP_NODEWWN(ispsoftc_t *)	FC Node WWN to use  *	ISP_PORTWWN(ispsoftc_t *)	FC Port WWN to use  *  *		These are to be used after NVRAM is read. The tags  *		in fcparam.isp_{node,port}wwn reflect the values  *		read from NVRAM (possibly corrected for card botches).  *		Each platform can take that information and override  *		it or ignore and return the Node and Port WWNs to be  * 		used when sending the Qlogic f/w the Initialization Control  *		Block.  *  *	(XXX these do endian specific transformations- in transition XXX)  *  *	ISP_IOXPUT_8(ispsoftc_t *, uint8_t srcval, uint8_t *dstptr)  *	ISP_IOXPUT_16(ispsoftc_t *, uint16_t srcval, uint16_t *dstptr)  *	ISP_IOXPUT_32(ispsoftc_t *, uint32_t srcval, uint32_t *dstptr)  *  *	ISP_IOXGET_8(ispsoftc_t *, uint8_t *srcptr, uint8_t dstrval)  *	ISP_IOXGET_16(ispsoftc_t *, uint16_t *srcptr, uint16_t dstrval)  *	ISP_IOXGET_32(ispsoftc_t *, uint32_t *srcptr, uint32_t dstrval)  *  *	ISP_SWIZZLE_NVRAM_WORD(ispsoftc_t *, uint16_t *)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPVAR_H */
end_comment

end_unit

