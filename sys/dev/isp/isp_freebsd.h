begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Qlogic ISP SCSI Host Adapter FreeBSD Wrapper Definitions  *  * Copyright (c) 1997-2008 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
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

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MAJOR
value|7
end_define

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MINOR
value|0
end_define

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
name|ISP_IFLAGS
value|INTR_TYPE_CAM | INTR_ENTROPY | INTR_MPSAFE
end_define

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
value|4096
end_define

begin_include
include|#
directive|include
file|<dev/isp/isp_target.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|next
decl_stmt|;
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
decl_stmt|;
name|uint32_t
name|lun
decl_stmt|;
name|uint32_t
name|nphdl
decl_stmt|;
name|uint32_t
name|sid
decl_stmt|;
name|uint32_t
name|portid
decl_stmt|;
name|uint32_t
name|oxid
range|:
literal|16
decl_stmt|,
name|cdb0
range|:
literal|8
decl_stmt|,
range|:
literal|1
decl_stmt|,
name|dead
range|:
literal|1
decl_stmt|,
name|tattr
range|:
literal|3
decl_stmt|,
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
name|union
name|inot_private_data
name|inot_private_data_t
typedef|;
end_typedef

begin_union
union|union
name|inot_private_data
block|{
name|inot_private_data_t
modifier|*
name|next
decl_stmt|;
struct|struct
block|{
name|isp_notify_t
name|nt
decl_stmt|;
comment|/* must be first! */
name|uint8_t
name|data
index|[
literal|64
index|]
decl_stmt|;
comment|/* sb QENTRY_LEN, but order of definitions is wrong */
name|uint32_t
name|tag_id
decl_stmt|,
name|seq_id
decl_stmt|;
block|}
name|rd
struct|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
struct|struct
name|tstate
block|{
name|SLIST_ENTRY
argument_list|(
argument|tstate
argument_list|)
name|next
expr_stmt|;
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
name|uint32_t
name|hold
decl_stmt|;
name|int
name|atio_count
decl_stmt|;
name|int
name|inot_count
decl_stmt|;
name|inot_private_data_t
modifier|*
name|restart_queue
decl_stmt|;
name|inot_private_data_t
modifier|*
name|ntfree
decl_stmt|;
name|inot_private_data_t
name|ntpool
index|[
name|ATPDPSIZE
index|]
decl_stmt|;
name|atio_private_data_t
modifier|*
name|atfree
decl_stmt|;
name|atio_private_data_t
name|atpool
index|[
name|ATPDPSIZE
index|]
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
name|lun
parameter_list|)
value|((lun)& (LUN_HASH_SIZE - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Per command info.  */
end_comment

begin_struct
struct|struct
name|isp_pcmd
block|{
name|struct
name|isp_pcmd
modifier|*
name|next
decl_stmt|;
name|bus_dmamap_t
name|dmap
decl_stmt|;
comment|/* dma map for this command */
name|struct
name|ispsoftc
modifier|*
name|isp
decl_stmt|;
comment|/* containing isp */
name|struct
name|callout
name|wdog
decl_stmt|;
comment|/* watchdog timer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISP_PCMD
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->ccb_h.spriv_ptr1
end_define

begin_define
define|#
directive|define
name|PISP_PCMD
parameter_list|(
name|ccb
parameter_list|)
value|((struct isp_pcmd *)ISP_PCMD(ccb))
end_define

begin_comment
comment|/*  * Per channel information  */
end_comment

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|tslist
argument_list|,
name|tstate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|isp_fc
block|{
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
name|ispsoftc
modifier|*
name|isp
decl_stmt|;
name|struct
name|proc
modifier|*
name|kproc
decl_stmt|;
name|bus_dma_tag_t
name|tdmat
decl_stmt|;
name|bus_dmamap_t
name|tdmap
decl_stmt|;
name|uint64_t
name|def_wwpn
decl_stmt|;
name|uint64_t
name|def_wwnn
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
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
ifdef|#
directive|ifdef
name|ISP_INTERNAL_TARGET
name|proc_active
range|:
literal|1
decl_stmt|,
endif|#
directive|endif
name|tm_luns_enabled
range|:
literal|1
decl_stmt|,
name|tm_enable_defer
range|:
literal|1
decl_stmt|,
name|tm_enabled
range|:
literal|1
decl_stmt|,
endif|#
directive|endif
name|simqfrozen
range|:
literal|3
decl_stmt|,
name|default_id
range|:
literal|8
decl_stmt|,
name|hysteresis
range|:
literal|8
decl_stmt|,
name|role
range|:
literal|2
decl_stmt|,
name|gdt_running
range|:
literal|1
decl_stmt|,
name|loop_dead
range|:
literal|1
decl_stmt|,
name|fcbsy
range|:
literal|1
decl_stmt|,
name|ready
range|:
literal|1
decl_stmt|;
name|struct
name|callout
name|ldt
decl_stmt|;
comment|/* loop down timer */
name|struct
name|callout
name|gdt
decl_stmt|;
comment|/* gone device timer */
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
name|struct
name|tslist
name|lun_hash
index|[
name|LUN_HASH_SIZE
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|ISP_INTERNAL_TARGET
name|struct
name|proc
modifier|*
name|target_proc
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isp_spi
block|{
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
name|uint32_t
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
ifdef|#
directive|ifdef
name|ISP_INTERNAL_TARGET
name|proc_active
range|:
literal|1
decl_stmt|,
endif|#
directive|endif
name|tm_luns_enabled
range|:
literal|1
decl_stmt|,
name|tm_enable_defer
range|:
literal|1
decl_stmt|,
name|tm_enabled
range|:
literal|1
decl_stmt|,
endif|#
directive|endif
name|simqfrozen
range|:
literal|3
decl_stmt|,
name|role
range|:
literal|3
decl_stmt|,
name|iid
range|:
literal|4
decl_stmt|;
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
name|struct
name|tslist
name|lun_hash
index|[
name|LUN_HASH_SIZE
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|ISP_INTERNAL_TARGET
name|struct
name|proc
modifier|*
name|target_proc
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isposinfo
block|{
comment|/* 	 * Linkage, locking, and identity 	 */
name|struct
name|mtx
name|lock
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|cdev
decl_stmt|;
name|struct
name|intr_config_hook
name|ehook
decl_stmt|;
name|struct
name|cam_devq
modifier|*
name|devq
decl_stmt|;
comment|/* 	 * Firmware pointer 	 */
specifier|const
name|struct
name|firmware
modifier|*
name|fw
decl_stmt|;
comment|/* 	 * DMA related sdtuff 	 */
name|bus_space_tag_t
name|bus_tag
decl_stmt|;
name|bus_dma_tag_t
name|dmat
decl_stmt|;
name|bus_space_handle_t
name|bus_handle
decl_stmt|;
name|bus_dma_tag_t
name|cdmat
decl_stmt|;
name|bus_dmamap_t
name|cdmap
decl_stmt|;
comment|/* 	 * Command and transaction related related stuff 	 */
name|struct
name|isp_pcmd
modifier|*
name|pcmd_pool
decl_stmt|;
name|struct
name|isp_pcmd
modifier|*
name|pcmd_free
decl_stmt|;
name|uint32_t
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
name|tmwanted
range|:
literal|1
decl_stmt|,
name|tmbusy
range|:
literal|1
decl_stmt|,
else|#
directive|else
range|:
literal|2
decl_stmt|,
endif|#
directive|endif
name|forcemulti
range|:
literal|1
decl_stmt|,
name|timer_active
range|:
literal|1
decl_stmt|,
name|autoconf
range|:
literal|1
decl_stmt|,
name|ehook_active
range|:
literal|1
decl_stmt|,
name|disabled
range|:
literal|1
decl_stmt|,
name|mbox_sleeping
range|:
literal|1
decl_stmt|,
name|mbox_sleep_ok
range|:
literal|1
decl_stmt|,
name|mboxcmd_done
range|:
literal|1
decl_stmt|,
name|mboxbsy
range|:
literal|1
decl_stmt|;
name|struct
name|callout
name|tmo
decl_stmt|;
comment|/* general timer */
comment|/* 	 * misc- needs to be sorted better XXXXXX 	 */
name|int
name|framesize
decl_stmt|;
name|int
name|exec_throttle
decl_stmt|;
name|int
name|cont_max
decl_stmt|;
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
name|cam_status
modifier|*
name|rptr
decl_stmt|;
endif|#
directive|endif
comment|/* 	 * Per-type private storage... 	 */
union|union
block|{
name|struct
name|isp_fc
modifier|*
name|fc
decl_stmt|;
name|struct
name|isp_spi
modifier|*
name|spi
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
name|pc
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISP_FC_PC
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|(&(isp)->isp_osinfo.pc.fc[(chan)])
end_define

begin_define
define|#
directive|define
name|ISP_SPI_PC
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|(&(isp)->isp_osinfo.pc.spi[(chan)])
end_define

begin_define
define|#
directive|define
name|ISP_GET_PC
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|,
name|tag
parameter_list|,
name|rslt
parameter_list|)
define|\
value|if (IS_SCSI(isp)) {				\ 		rslt = ISP_SPI_PC(isp, chan)-> tag;	\ 	} else {					\ 		rslt = ISP_FC_PC(isp, chan)-> tag;	\ 	}
end_define

begin_define
define|#
directive|define
name|ISP_GET_PC_ADDR
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|,
name|tag
parameter_list|,
name|rp
parameter_list|)
define|\
value|if (IS_SCSI(isp)) {				\ 		rp =&ISP_SPI_PC(isp, chan)-> tag;	\ 	} else {					\ 		rp =&ISP_FC_PC(isp, chan)-> tag;	\ 	}
end_define

begin_define
define|#
directive|define
name|ISP_SET_PC
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|,
name|tag
parameter_list|,
name|val
parameter_list|)
define|\
value|if (IS_SCSI(isp)) {				\ 		ISP_SPI_PC(isp, chan)-> tag = val;	\ 	} else {					\ 		ISP_FC_PC(isp, chan)-> tag = val;	\ 	}
end_define

begin_define
define|#
directive|define
name|isp_lock
value|isp_osinfo.lock
end_define

begin_define
define|#
directive|define
name|isp_bus_tag
value|isp_osinfo.bus_tag
end_define

begin_define
define|#
directive|define
name|isp_bus_handle
value|isp_osinfo.bus_handle
end_define

begin_comment
comment|/*  * Locking macros...  */
end_comment

begin_define
define|#
directive|define
name|ISP_LOCK
parameter_list|(
name|isp
parameter_list|)
value|mtx_lock(&isp->isp_osinfo.lock)
end_define

begin_define
define|#
directive|define
name|ISP_UNLOCK
parameter_list|(
name|isp
parameter_list|)
value|mtx_unlock(&isp->isp_osinfo.lock)
end_define

begin_comment
comment|/*  * Required Macros/Defines  */
end_comment

begin_define
define|#
directive|define
name|ISP_FC_SCRLEN
value|0x1000
end_define

begin_define
define|#
directive|define
name|ISP_MEMZERO
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
name|ISP_MEMCPY
value|memcpy
end_define

begin_define
define|#
directive|define
name|ISP_SNPRINTF
value|snprintf
end_define

begin_define
define|#
directive|define
name|ISP_DELAY
value|DELAY
end_define

begin_define
define|#
directive|define
name|ISP_SLEEP
parameter_list|(
name|isp
parameter_list|,
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DIAGNOSTIC
end_ifndef

begin_define
define|#
directive|define
name|ISP_INLINE
value|__inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|switch (type) {							\ case SYNC_SFORDEV:						\ case SYNC_REQUEST:						\ 	bus_dmamap_sync(isp->isp_osinfo.cdmat,			\ 	   isp->isp_osinfo.cdmap, 				\ 	   BUS_DMASYNC_PREREAD | BUS_DMASYNC_PREWRITE);		\ 	break;							\ case SYNC_SFORCPU:						\ case SYNC_RESULT:						\ 	bus_dmamap_sync(isp->isp_osinfo.cdmat, 			\ 	   isp->isp_osinfo.cdmap,				\ 	   BUS_DMASYNC_POSTREAD | BUS_DMASYNC_POSTWRITE);	\ 	break;							\ case SYNC_REG:							\ 	bus_space_barrier(isp->isp_osinfo.bus_tag,		\ 	    isp->isp_osinfo.bus_handle, offset, size,		\ 	    BUS_SPACE_BARRIER_READ);				\ 	break;							\ default:							\ 	break;							\ }
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
value|isp_fc_scratch_acquire
end_define

begin_define
define|#
directive|define
name|FC_SCRATCH_RELEASE
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|isp->isp_osinfo.pc.fc[chan].fcbsy = 0
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
name|XS_GET_DMA64_SEG
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|{						\ 	ispds64_t *d = a;			\ 	bus_dma_segment_t *e = b;		\ 	uint32_t f = c;				\ 	e += f;					\         d->ds_base = DMA_LO32(e->ds_addr);	\         d->ds_basehi = DMA_HI32(e->ds_addr);	\         d->ds_count = e->ds_len;		\ }
end_define

begin_define
define|#
directive|define
name|XS_GET_DMA_SEG
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|{						\ 	ispds_t *d = a;				\ 	bus_dma_segment_t *e = b;		\ 	uint32_t f = c;				\ 	e += f;					\         d->ds_base = DMA_LO32(e->ds_addr);	\         d->ds_count = e->ds_len;		\ }
end_define

begin_define
define|#
directive|define
name|XS_ISP
parameter_list|(
name|ccb
parameter_list|)
value|cam_sim_softc(xpt_path_sim((ccb)->ccb_h.path))
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
name|XS_GET_RESID
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->resid
end_define

begin_define
define|#
directive|define
name|XS_SET_RESID
parameter_list|(
name|ccb
parameter_list|,
name|r
parameter_list|)
value|(ccb)->resid = r
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
name|DEFAULT_FRAMESIZE
parameter_list|(
name|isp
parameter_list|)
value|isp->isp_osinfo.framesize
end_define

begin_define
define|#
directive|define
name|DEFAULT_EXEC_THROTTLE
parameter_list|(
name|isp
parameter_list|)
value|isp->isp_osinfo.exec_throttle
end_define

begin_define
define|#
directive|define
name|GET_DEFAULT_ROLE
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
define|\
value|(IS_FC(isp)? ISP_FC_PC(isp, chan)->role : ISP_SPI_PC(isp, chan)->role)
end_define

begin_define
define|#
directive|define
name|SET_DEFAULT_ROLE
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
define|\
value|if (IS_FC(isp)) { 				\ 		ISP_FC_PC(isp, chan)->role = val;	\ 	} else {					\ 		ISP_SPI_PC(isp, chan)->role = val;	\ 	}
end_define

begin_define
define|#
directive|define
name|DEFAULT_IID
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|isp->isp_osinfo.pc.spi[chan].iid
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOOPID
parameter_list|(
name|x
parameter_list|,
name|chan
parameter_list|)
value|isp->isp_osinfo.pc.fc[chan].default_id
end_define

begin_define
define|#
directive|define
name|DEFAULT_NODEWWN
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|isp_default_wwn(isp, chan, 0, 1)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORTWWN
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|isp_default_wwn(isp, chan, 0, 0)
end_define

begin_define
define|#
directive|define
name|ACTIVE_NODEWWN
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|isp_default_wwn(isp, chan, 1, 1)
end_define

begin_define
define|#
directive|define
name|ACTIVE_PORTWWN
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
value|isp_default_wwn(isp, chan, 1, 0)
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
name|ISP_SWIZZLE_NVRAM_LONG
parameter_list|(
name|isp
parameter_list|,
name|rp
parameter_list|)
value|*rp = bswap32(*rp)
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
name|ISP_SWIZZLE_NVRAM_LONG
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

begin_define
define|#
directive|define
name|ISP_SWAP16
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|)
value|bswap16(s)
end_define

begin_define
define|#
directive|define
name|ISP_SWAP32
parameter_list|(
name|isp
parameter_list|,
name|s
parameter_list|)
value|bswap32(s)
end_define

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
name|isp_dev
value|isp_osinfo.dev
end_define

begin_comment
comment|/*  * prototypes for isp_pci&& isp_freebsd to share  */
end_comment

begin_function_decl
specifier|extern
name|int
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
name|isp_detach
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

begin_function_decl
specifier|extern
name|uint64_t
name|isp_default_wwn
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
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

begin_decl_stmt
specifier|extern
name|int
name|isp_autoconfig
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
name|ISP_SPRIV_DONE
value|0x8
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
name|isp_fc_scratch_acquire
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|int
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

begin_function_decl
name|void
name|isp_platform_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isp_common_dmateardown
parameter_list|(
name|ispsoftc_t
modifier|*
parameter_list|,
name|struct
name|ccb_scsiio
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform Version specific defines  */
end_comment

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
value|bus_dma_tag_create(a, b, c, d, e, f, g, h, i, j, k, \ 	busdma_lock_mutex,&isp->isp_osinfo.lock, z)
end_define

begin_define
define|#
directive|define
name|isp_setup_intr
value|bus_setup_intr
end_define

begin_define
define|#
directive|define
name|isp_sim_alloc
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
parameter_list|)
define|\
value|cam_sim_alloc(a, b, c, d, e,&(d)->isp_osinfo.lock, f, g, h)
end_define

begin_comment
comment|/* Should be BUS_SPACE_MAXSIZE, but MAXPHYS is larger than BUS_SPACE_MAXSIZE */
end_comment

begin_define
define|#
directive|define
name|ISP_NSEGS
value|((MAXPHYS / PAGE_SIZE) + 1)
end_define

begin_define
define|#
directive|define
name|ISP_PATH_PRT
parameter_list|(
name|i
parameter_list|,
name|l
parameter_list|,
name|p
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if ((l) == ISP_LOGALL || ((l)& (i)->isp_dblev) != 0) {		\                 xpt_print(p, __VA_ARGS__);				\         }
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

