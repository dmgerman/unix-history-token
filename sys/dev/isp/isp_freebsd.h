begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Qlogic ISP SCSI Host Adapter FreeBSD Wrapper Definitions  *  * Copyright (c) 1997-2006 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISP_FREEBSD_H
end_ifndef

begin_define
define|#
directive|define
name|_ISP_FREEBSD_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_message.h>
end_include

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_isp.h"
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MAJOR
value|4
end_define

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MINOR
value|17
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MAJOR
value|5
end_define

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MINOR
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Efficiency- get rid of SBus code&& tests unless we need them.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc64__
end_ifdef

begin_define
define|#
directive|define
name|ISP_SBUS_SUPPORTED
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_SBUS_SUPPORTED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HANDLE_LOOPSTATE_IN_OUTER_LAYERS
value|1
end_define

begin_comment
comment|/* #define	ISP_SMPLOCK			1 */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|ISP_IFLAGS
value|INTR_TYPE_CAM
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_SMPLOCK
end_ifdef

begin_define
define|#
directive|define
name|ISP_IFLAGS
value|INTR_TYPE_CAM | INTR_ENTROPY | INTR_MPSAFE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_IFLAGS
value|INTR_TYPE_CAM | INTR_ENTROPY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
end_if

begin_typedef
typedef|typedef
name|void
name|ispfwfunc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
end_ifdef

begin_define
define|#
directive|define
name|ISP_TARGET_FUNCTIONS
value|1
end_define

begin_define
define|#
directive|define
name|ATPDPSIZE
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|orig_datalen
decl_stmt|;
name|uint32_t
name|bytes_xfered
decl_stmt|;
name|uint32_t
name|last_xframt
decl_stmt|;
name|uint32_t
name|tag
range|:
literal|16
decl_stmt|,
name|lun
range|:
literal|13
decl_stmt|,
comment|/* not enough */
name|state
range|:
literal|3
decl_stmt|;
block|}
name|atio_private_data_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATPD_STATE_FREE
value|0
end_define

begin_define
define|#
directive|define
name|ATPD_STATE_ATIO
value|1
end_define

begin_define
define|#
directive|define
name|ATPD_STATE_CAM
value|2
end_define

begin_define
define|#
directive|define
name|ATPD_STATE_CTIO
value|3
end_define

begin_define
define|#
directive|define
name|ATPD_STATE_LAST_CTIO
value|4
end_define

begin_define
define|#
directive|define
name|ATPD_STATE_PDON
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
name|tstate
block|{
name|struct
name|tstate
modifier|*
name|next
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|owner
decl_stmt|;
name|struct
name|ccb_hdr_slist
name|atios
decl_stmt|;
name|struct
name|ccb_hdr_slist
name|inots
decl_stmt|;
name|lun_id_t
name|lun
decl_stmt|;
name|int
name|bus
decl_stmt|;
name|uint32_t
name|hold
decl_stmt|;
name|int
name|atio_count
decl_stmt|;
name|int
name|inot_count
decl_stmt|;
block|}
name|tstate_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LUN_HASH_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LUN_HASH_FUNC
parameter_list|(
name|isp
parameter_list|,
name|port
parameter_list|,
name|lun
parameter_list|)
define|\
value|((IS_DUALBUS(isp)) ?						\ 		(((lun)& ((LUN_HASH_SIZE>> 1) - 1))<< (port)) :	\ 		((lun)& (LUN_HASH_SIZE - 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|isposinfo
block|{
name|struct
name|ispsoftc
modifier|*
name|next
decl_stmt|;
name|uint64_t
name|default_port_wwn
decl_stmt|;
name|uint64_t
name|default_node_wwn
decl_stmt|;
name|uint32_t
name|default_id
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim2
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path2
decl_stmt|;
name|struct
name|intr_config_hook
name|ehook
decl_stmt|;
name|uint32_t
name|loop_down_time
decl_stmt|;
name|uint32_t
name|loop_down_limit
decl_stmt|;
name|uint32_t
name|gone_device_time
decl_stmt|;
name|uint32_t
label|:
literal|5
operator|,
name|simqfrozen
operator|:
literal|3
operator|,
name|hysteresis
operator|:
literal|8
operator|,
name|gdt_running
operator|:
literal|1
operator|,
name|ldt_running
operator|:
literal|1
operator|,
name|disabled
operator|:
literal|1
operator|,
name|fcbsy
operator|:
literal|1
operator|,
name|mbox_sleeping
operator|:
literal|1
operator|,
name|mbox_sleep_ok
operator|:
literal|1
operator|,
name|mboxcmd_done
operator|:
literal|1
operator|,
name|mboxbsy
operator|:
literal|1
expr_stmt|;
name|struct
name|callout_handle
name|ldt
decl_stmt|;
comment|/* loop down timer */
name|struct
name|callout_handle
name|gdt
decl_stmt|;
comment|/* gone device timer */
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
name|struct
name|firmware
modifier|*
name|fw
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|struct
name|cv
name|kthread_cv
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|char
name|wwnn
index|[
literal|17
index|]
decl_stmt|;
name|char
name|wwpn
index|[
literal|17
index|]
decl_stmt|;
block|}
name|fc
struct|;
block|}
name|sysctl_info
union|;
endif|#
directive|endif
name|struct
name|proc
modifier|*
name|kproc
decl_stmt|;
name|bus_dma_tag_t
name|cdmat
decl_stmt|;
name|bus_dmamap_t
name|cdmap
decl_stmt|;
define|#
directive|define
name|isp_cdmat
value|isp_osinfo.cdmat
define|#
directive|define
name|isp_cdmap
value|isp_osinfo.cdmap
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
define|#
directive|define
name|TM_WILDCARD_ENABLED
value|0x02
define|#
directive|define
name|TM_TMODE_ENABLED
value|0x01
name|uint8_t
name|tmflags
index|[
literal|2
index|]
decl_stmt|;
comment|/* two busses */
define|#
directive|define
name|NLEACT
value|4
name|union
name|ccb
modifier|*
name|leact
index|[
name|NLEACT
index|]
decl_stmt|;
name|tstate_t
name|tsdflt
index|[
literal|2
index|]
decl_stmt|;
comment|/* two busses */
name|tstate_t
modifier|*
name|lun_hash
index|[
name|LUN_HASH_SIZE
index|]
decl_stmt|;
name|atio_private_data_t
name|atpdp
index|[
name|ATPDPSIZE
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|isp_lock
value|isp_osinfo.lock
end_define

begin_comment
comment|/*  * Locking macros...  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_SMPLOCK
end_ifdef

begin_define
define|#
directive|define
name|ISP_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_lock(&(x)->isp_lock)
end_define

begin_define
define|#
directive|define
name|ISP_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_unlock(&(x)->isp_lock)
end_define

begin_define
define|#
directive|define
name|ISPLOCK_2_CAMLOCK
parameter_list|(
name|isp
parameter_list|)
define|\
value|mtx_unlock(&(isp)->isp_lock); mtx_lock(&Giant)
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_ISPLOCK
parameter_list|(
name|isp
parameter_list|)
define|\
value|mtx_unlock(&Giant); mtx_lock(&(isp)->isp_lock)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|ISP_LOCK
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|ISP_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|ISPLOCK_2_CAMLOCK
parameter_list|(
name|isp
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_ISPLOCK
parameter_list|(
name|isp
parameter_list|)
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_LOCK
parameter_list|(
name|x
parameter_list|)
value|GIANT_REQUIRED
end_define

begin_define
define|#
directive|define
name|ISP_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|ISPLOCK_2_CAMLOCK
parameter_list|(
name|isp
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_ISPLOCK
parameter_list|(
name|isp
parameter_list|)
value|GIANT_REQUIRED
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
comment|/*  * Required Macros/Defines  */
end_comment

begin_define
define|#
directive|define
name|ISP2100_SCRLEN
value|0x1000
end_define

begin_define
define|#
directive|define
name|MEMZERO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset(a, 0, b)
end_define

begin_define
define|#
directive|define
name|MEMCPY
value|memcpy
end_define

begin_define
define|#
directive|define
name|SNPRINTF
value|snprintf
end_define

begin_define
define|#
directive|define
name|USEC_DELAY
value|DELAY
end_define

begin_define
define|#
directive|define
name|USEC_SLEEP
parameter_list|(
name|isp
parameter_list|,
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|NANOTIME_T
value|struct timespec
end_define

begin_define
define|#
directive|define
name|GET_NANOTIME
value|nanotime
end_define

begin_define
define|#
directive|define
name|GET_NANOSEC
parameter_list|(
name|x
parameter_list|)
value|((x)->tv_sec * 1000000000 + (x)->tv_nsec)
end_define

begin_define
define|#
directive|define
name|NANOTIME_SUB
value|isp_nanotime_sub
end_define

begin_define
define|#
directive|define
name|MAXISPREQUEST
parameter_list|(
name|isp
parameter_list|)
value|((IS_FC(isp) || IS_ULTRA2(isp))? 1024 : 256)
end_define

begin_define
define|#
directive|define
name|MEMORYBARRIER
parameter_list|(
name|isp
parameter_list|,
name|type
parameter_list|,
name|offset
parameter_list|,
name|size
parameter_list|)
define|\
value|switch (type) {							\ case SYNC_SFORDEV:						\ case SYNC_REQUEST:						\ 	bus_dmamap_sync(isp->isp_cdmat, isp->isp_cdmap, 	\ 	   BUS_DMASYNC_PREREAD | BUS_DMASYNC_PREWRITE);		\ 	break;							\ case SYNC_SFORCPU:						\ case SYNC_RESULT:						\ 	bus_dmamap_sync(isp->isp_cdmat, isp->isp_cdmap,		\ 	   BUS_DMASYNC_POSTREAD | BUS_DMASYNC_POSTWRITE);	\ 	break;							\ default:							\ 	break;							\ }
end_define

begin_define
define|#
directive|define
name|MBOX_ACQUIRE
value|isp_mbox_acquire
end_define

begin_define
define|#
directive|define
name|MBOX_WAIT_COMPLETE
value|isp_mbox_wait_complete
end_define

begin_define
define|#
directive|define
name|MBOX_NOTIFY_COMPLETE
value|isp_mbox_notify_done
end_define

begin_define
define|#
directive|define
name|MBOX_RELEASE
value|isp_mbox_release
end_define

begin_define
define|#
directive|define
name|FC_SCRATCH_ACQUIRE
parameter_list|(
name|isp
parameter_list|)
define|\
value|if (isp->isp_osinfo.fcbsy) {					\ 		isp_prt(isp, ISP_LOGWARN,				\ 		    "FC scratch area busy (line %d)!", __LINE__);	\ 	} else								\ 		isp->isp_osinfo.fcbsy = 1
end_define

begin_define
define|#
directive|define
name|FC_SCRATCH_RELEASE
parameter_list|(
name|isp
parameter_list|)
value|isp->isp_osinfo.fcbsy = 0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_GOOD
end_ifndef

begin_define
define|#
directive|define
name|SCSI_GOOD
value|SCSI_STATUS_OK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_CHECK
end_ifndef

begin_define
define|#
directive|define
name|SCSI_CHECK
value|SCSI_STATUS_CHECK_COND
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_BUSY
end_ifndef

begin_define
define|#
directive|define
name|SCSI_BUSY
value|SCSI_STATUS_BUSY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_QFULL
end_ifndef

begin_define
define|#
directive|define
name|SCSI_QFULL
value|SCSI_STATUS_QUEUE_FULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XS_T
value|struct ccb_scsiio
end_define

begin_define
define|#
directive|define
name|XS_DMA_ADDR_T
value|bus_addr_t
end_define

begin_define
define|#
directive|define
name|XS_ISP
parameter_list|(
name|ccb
parameter_list|)
value|((ispsoftc_t *) (ccb)->ccb_h.spriv_ptr1)
end_define

begin_define
define|#
directive|define
name|XS_CHANNEL
parameter_list|(
name|ccb
parameter_list|)
value|cam_sim_bus(xpt_path_sim((ccb)->ccb_h.path))
end_define

begin_define
define|#
directive|define
name|XS_TGT
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->ccb_h.target_id
end_define

begin_define
define|#
directive|define
name|XS_LUN
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->ccb_h.target_lun
end_define

begin_define
define|#
directive|define
name|XS_CDBP
parameter_list|(
name|ccb
parameter_list|)
define|\
value|(((ccb)->ccb_h.flags& CAM_CDB_POINTER)? \ 	 (ccb)->cdb_io.cdb_ptr : (ccb)->cdb_io.cdb_bytes)
end_define

begin_define
define|#
directive|define
name|XS_CDBLEN
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->cdb_len
end_define

begin_define
define|#
directive|define
name|XS_XFRLEN
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->dxfer_len
end_define

begin_define
define|#
directive|define
name|XS_TIME
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->ccb_h.timeout
end_define

begin_define
define|#
directive|define
name|XS_RESID
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->resid
end_define

begin_define
define|#
directive|define
name|XS_STSP
parameter_list|(
name|ccb
parameter_list|)
value|(&(ccb)->scsi_status)
end_define

begin_define
define|#
directive|define
name|XS_SNSP
parameter_list|(
name|ccb
parameter_list|)
value|(&(ccb)->sense_data)
end_define

begin_define
define|#
directive|define
name|XS_SNSLEN
parameter_list|(
name|ccb
parameter_list|)
define|\
value|imin((sizeof((ccb)->sense_data)), ccb->sense_len)
end_define

begin_define
define|#
directive|define
name|XS_SNSKEY
parameter_list|(
name|ccb
parameter_list|)
value|((ccb)->sense_data.flags& 0xf)
end_define

begin_define
define|#
directive|define
name|XS_TAG_P
parameter_list|(
name|ccb
parameter_list|)
define|\
value|(((ccb)->ccb_h.flags& CAM_TAG_ACTION_VALID)&& \ 	 (ccb)->tag_action != CAM_TAG_ACTION_NONE)
end_define

begin_define
define|#
directive|define
name|XS_TAG_TYPE
parameter_list|(
name|ccb
parameter_list|)
define|\
value|((ccb->tag_action == MSG_SIMPLE_Q_TAG)? REQFLAG_STAG : \ 	 ((ccb->tag_action == MSG_HEAD_OF_Q_TAG)? REQFLAG_HTAG : REQFLAG_OTAG))
end_define

begin_define
define|#
directive|define
name|XS_SETERR
parameter_list|(
name|ccb
parameter_list|,
name|v
parameter_list|)
value|(ccb)->ccb_h.status&= ~CAM_STATUS_MASK, \ 				(ccb)->ccb_h.status |= v, \ 				(ccb)->ccb_h.spriv_field0 |= ISP_SPRIV_ERRSET
end_define

begin_define
define|#
directive|define
name|HBA_NOERROR
value|CAM_REQ_INPROG
end_define

begin_define
define|#
directive|define
name|HBA_BOTCH
value|CAM_UNREC_HBA_ERROR
end_define

begin_define
define|#
directive|define
name|HBA_CMDTIMEOUT
value|CAM_CMD_TIMEOUT
end_define

begin_define
define|#
directive|define
name|HBA_SELTIMEOUT
value|CAM_SEL_TIMEOUT
end_define

begin_define
define|#
directive|define
name|HBA_TGTBSY
value|CAM_SCSI_STATUS_ERROR
end_define

begin_define
define|#
directive|define
name|HBA_BUSRESET
value|CAM_SCSI_BUS_RESET
end_define

begin_define
define|#
directive|define
name|HBA_ABORTED
value|CAM_REQ_ABORTED
end_define

begin_define
define|#
directive|define
name|HBA_DATAOVR
value|CAM_DATA_RUN_ERR
end_define

begin_define
define|#
directive|define
name|HBA_ARQFAIL
value|CAM_AUTOSENSE_FAIL
end_define

begin_define
define|#
directive|define
name|XS_ERR
parameter_list|(
name|ccb
parameter_list|)
value|((ccb)->ccb_h.status& CAM_STATUS_MASK)
end_define

begin_define
define|#
directive|define
name|XS_NOERR
parameter_list|(
name|ccb
parameter_list|)
define|\
value|(((ccb)->ccb_h.spriv_field0& ISP_SPRIV_ERRSET) == 0 || \ 	 ((ccb)->ccb_h.status& CAM_STATUS_MASK) == CAM_REQ_INPROG)
end_define

begin_define
define|#
directive|define
name|XS_INITERR
parameter_list|(
name|ccb
parameter_list|)
define|\
value|XS_SETERR(ccb, CAM_REQ_INPROG), (ccb)->ccb_h.spriv_field0 = 0
end_define

begin_define
define|#
directive|define
name|XS_SAVE_SENSE
parameter_list|(
name|xs
parameter_list|,
name|sense_ptr
parameter_list|,
name|sense_len
parameter_list|)
define|\
value|(xs)->ccb_h.status |= CAM_AUTOSNS_VALID;	\ 	memcpy(&(xs)->sense_data, sense_ptr, imin(XS_SNSLEN(xs), sense_len))
end_define

begin_define
define|#
directive|define
name|XS_SET_STATE_STAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEFAULT_IID
parameter_list|(
name|x
parameter_list|)
value|(isp)->isp_osinfo.default_id
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOOPID
parameter_list|(
name|x
parameter_list|)
value|(isp)->isp_osinfo.default_id
end_define

begin_define
define|#
directive|define
name|DEFAULT_NODEWWN
parameter_list|(
name|isp
parameter_list|)
value|(isp)->isp_osinfo.default_node_wwn
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORTWWN
parameter_list|(
name|isp
parameter_list|)
value|(isp)->isp_osinfo.default_port_wwn
end_define

begin_define
define|#
directive|define
name|ISP_NODEWWN
parameter_list|(
name|isp
parameter_list|)
value|FCPARAM(isp)->isp_wwnn_nvram
end_define

begin_define
define|#
directive|define
name|ISP_PORTWWN
parameter_list|(
name|isp
parameter_list|)
value|FCPARAM(isp)->isp_wwpn_nvram
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|ISP_SBUS_SUPPORTED
end_ifdef

begin_define
define|#
directive|define
name|ISP_IOXPUT_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOXPUT_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|*(d) = (isp->isp_bustype == ISP_BT_SBUS)? s : bswap16(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOXPUT_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|*(d) = (isp->isp_bustype == ISP_BT_SBUS)? s : bswap32(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = (*((uint8_t *)s))
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|d = (isp->isp_bustype == ISP_BT_SBUS)?			\ 	*((uint16_t *)s) : bswap16(*((uint16_t *)s))
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|d = (isp->isp_bustype == ISP_BT_SBUS)?			\ 	*((uint32_t *)s) : bswap32(*((uint32_t *)s))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISP_SBUS_SUPPORTED */
end_comment

begin_define
define|#
directive|define
name|ISP_IOXPUT_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOXPUT_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = bswap16(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOXPUT_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = bswap32(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = (*((uint8_t *)s))
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = bswap16(*((uint16_t *)s))
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = bswap32(*((uint32_t *)s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISP_SWIZZLE_NVRAM_WORD
parameter_list|(
name|isp
parameter_list|,
name|rp
parameter_list|)
value|*rp = bswap16(*rp)
end_define

begin_define
define|#
directive|define
name|ISP_IOZGET_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = (*((uint8_t *)s))
end_define

begin_define
define|#
directive|define
name|ISP_IOZGET_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = (*((uint16_t *)s))
end_define

begin_define
define|#
directive|define
name|ISP_IOZGET_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = (*((uint32_t *)s))
end_define

begin_define
define|#
directive|define
name|ISP_IOZPUT_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOZPUT_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOZPUT_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_IOXPUT_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOXPUT_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOXPUT_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = *(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = *(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOXGET_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = *(s)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZZLE_NVRAM_WORD
parameter_list|(
name|isp
parameter_list|,
name|rp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ISP_IOZPUT_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = s
end_define

begin_define
define|#
directive|define
name|ISP_IOZPUT_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = bswap16(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOZPUT_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|*(d) = bswap32(s)
end_define

begin_define
define|#
directive|define
name|ISP_IOZGET_8
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = (*((uint8_t *)(s)))
end_define

begin_define
define|#
directive|define
name|ISP_IOZGET_16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = bswap16(*((uint16_t *)(s)))
end_define

begin_define
define|#
directive|define
name|ISP_IOZGET_32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|d = bswap32(*((uint32_t *)(s)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Includes of common header files  */
end_comment

begin_include
include|#
directive|include
file|<dev/isp/ispreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/isp/ispvar.h>
end_include

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
file|<dev/isp/isp_tpublic.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * isp_osinfo definiitions&& shorthand  */
end_comment

begin_define
define|#
directive|define
name|SIMQFRZ_RESOURCE
value|0x1
end_define

begin_define
define|#
directive|define
name|SIMQFRZ_LOOPDOWN
value|0x2
end_define

begin_define
define|#
directive|define
name|SIMQFRZ_TIMED
value|0x4
end_define

begin_define
define|#
directive|define
name|isp_sim
value|isp_osinfo.sim
end_define

begin_define
define|#
directive|define
name|isp_path
value|isp_osinfo.path
end_define

begin_define
define|#
directive|define
name|isp_sim2
value|isp_osinfo.sim2
end_define

begin_define
define|#
directive|define
name|isp_path2
value|isp_osinfo.path2
end_define

begin_define
define|#
directive|define
name|isp_dev
value|isp_osinfo.dev
end_define

begin_comment
comment|/*  * prototypes for isp_pci&& isp_freebsd to share  */
end_comment

begin_function_decl
specifier|extern
name|void
name|isp_attach
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isp_uninit
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * driver global data  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|isp_announced
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isp_fabric_hysteresis
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isp_loop_down_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isp_gone_device_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isp_quickboot_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Platform private flags  */
end_comment

begin_define
define|#
directive|define
name|ISP_SPRIV_ERRSET
value|0x1
end_define

begin_define
define|#
directive|define
name|ISP_SPRIV_INWDOG
value|0x2
end_define

begin_define
define|#
directive|define
name|ISP_SPRIV_GRACE
value|0x4
end_define

begin_define
define|#
directive|define
name|ISP_SPRIV_DONE
value|0x8
end_define

begin_define
define|#
directive|define
name|XS_CMD_S_WDOG
parameter_list|(
name|sccb
parameter_list|)
value|(sccb)->ccb_h.spriv_field0 |= ISP_SPRIV_INWDOG
end_define

begin_define
define|#
directive|define
name|XS_CMD_C_WDOG
parameter_list|(
name|sccb
parameter_list|)
value|(sccb)->ccb_h.spriv_field0&= ~ISP_SPRIV_INWDOG
end_define

begin_define
define|#
directive|define
name|XS_CMD_WDOG_P
parameter_list|(
name|sccb
parameter_list|)
value|((sccb)->ccb_h.spriv_field0& ISP_SPRIV_INWDOG)
end_define

begin_define
define|#
directive|define
name|XS_CMD_S_GRACE
parameter_list|(
name|sccb
parameter_list|)
value|(sccb)->ccb_h.spriv_field0 |= ISP_SPRIV_GRACE
end_define

begin_define
define|#
directive|define
name|XS_CMD_C_GRACE
parameter_list|(
name|sccb
parameter_list|)
value|(sccb)->ccb_h.spriv_field0&= ~ISP_SPRIV_GRACE
end_define

begin_define
define|#
directive|define
name|XS_CMD_GRACE_P
parameter_list|(
name|sccb
parameter_list|)
value|((sccb)->ccb_h.spriv_field0& ISP_SPRIV_GRACE)
end_define

begin_define
define|#
directive|define
name|XS_CMD_S_DONE
parameter_list|(
name|sccb
parameter_list|)
value|(sccb)->ccb_h.spriv_field0 |= ISP_SPRIV_DONE
end_define

begin_define
define|#
directive|define
name|XS_CMD_C_DONE
parameter_list|(
name|sccb
parameter_list|)
value|(sccb)->ccb_h.spriv_field0&= ~ISP_SPRIV_DONE
end_define

begin_define
define|#
directive|define
name|XS_CMD_DONE_P
parameter_list|(
name|sccb
parameter_list|)
value|((sccb)->ccb_h.spriv_field0& ISP_SPRIV_DONE)
end_define

begin_define
define|#
directive|define
name|XS_CMD_S_CLEAR
parameter_list|(
name|sccb
parameter_list|)
value|(sccb)->ccb_h.spriv_field0 = 0
end_define

begin_comment
comment|/*  * Platform Library Functions  */
end_comment

begin_function_decl
name|void
name|isp_prt
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|uint64_t
name|isp_nanotime_sub
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isp_mbox_acquire
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isp_mbox_wait_complete
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|mbreg_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isp_mbox_notify_done
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isp_mbox_release
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isp_mstohz
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform specific defines  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|BUS_DMA_ROOTARG
parameter_list|(
name|x
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|isp_dma_tag_create
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|,
name|i
parameter_list|,
name|j
parameter_list|,
name|k
parameter_list|,
name|z
parameter_list|)
define|\
value|bus_dma_tag_create(a, b, c, d, e, f, g, h, i, j, k, z)
end_define

begin_elif
elif|#
directive|elif
name|__FreeBSD_version
operator|<
literal|700020
end_elif

begin_define
define|#
directive|define
name|BUS_DMA_ROOTARG
parameter_list|(
name|x
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|isp_dma_tag_create
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|,
name|i
parameter_list|,
name|j
parameter_list|,
name|k
parameter_list|,
name|z
parameter_list|)
define|\
value|bus_dma_tag_create(a, b, c, d, e, f, g, h, i, j, k, \ 	busdma_lock_mutex,&Giant, z)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUS_DMA_ROOTARG
parameter_list|(
name|x
parameter_list|)
value|bus_get_dma_tag(x)
end_define

begin_define
define|#
directive|define
name|isp_dma_tag_create
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|,
name|i
parameter_list|,
name|j
parameter_list|,
name|k
parameter_list|,
name|z
parameter_list|)
define|\
value|bus_dma_tag_create(a, b, c, d, e, f, g, h, i, j, k, \ 	busdma_lock_mutex,&Giant, z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Should be BUS_SPACE_MAXSIZE, but MAXPHYS is larger than BUS_SPACE_MAXSIZE */
end_comment

begin_define
define|#
directive|define
name|ISP_NSEGS
value|((MAXPHYS / PAGE_SIZE) + 1)
end_define

begin_comment
comment|/*  * Platform specific inline functions  */
end_comment

begin_comment
comment|/*  * ISP General Library functions  */
end_comment

begin_include
include|#
directive|include
file|<dev/isp/isp_library.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_FREEBSD_H */
end_comment

end_unit

