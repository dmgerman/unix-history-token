begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Qlogic ISP SCSI Host Adapter FreeBSD Wrapper Definitions  * Copyright (c) 1997, 1998, 1999, 2000, 2001 by Matthew Jacob  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
value|16
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

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
file|<machine/bus_memio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

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

begin_comment
comment|/*  * Efficiency- get rid of SBus code&& tests unless we need them.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparcv9__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_if

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

begin_typedef
typedef|typedef
name|void
name|ispfwfunc
name|__P
typedef|((
name|int
typedef|,
name|int
typedef|,
name|int
typedef|,
name|u_int16_t
modifier|*
modifier|*
typedef|));
end_typedef

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
name|u_int32_t
name|orig_datalen
decl_stmt|;
name|u_int32_t
name|bytes_xfered
decl_stmt|;
name|u_int32_t
name|last_xframt
decl_stmt|;
name|u_int32_t
name|tag
decl_stmt|;
block|}
name|atio_private_data_t
typedef|;
end_typedef

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
name|u_int32_t
name|hold
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
name|u_int64_t
name|default_port_wwn
decl_stmt|;
name|u_int64_t
name|default_node_wwn
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
name|u_int8_t
name|mboxwaiting
decl_stmt|;
name|u_int8_t
name|simqfrozen
decl_stmt|;
name|u_int8_t
name|drain
decl_stmt|;
name|u_int8_t
name|intsok
decl_stmt|;
name|int
name|islocked
decl_stmt|;
name|int
name|splsaved
decl_stmt|;
name|struct
name|proc
modifier|*
name|kproc
decl_stmt|;
ifdef|#
directive|ifdef
name|ISP_TARGET_MODE
define|#
directive|define
name|TM_WANTED
value|0x80
define|#
directive|define
name|TM_BUSY
value|0x40
define|#
directive|define
name|TM_WILDCARD_ENABLED
value|0x02
define|#
directive|define
name|TM_TMODE_ENABLED
value|0x01
name|u_int8_t
name|tmflags
index|[
literal|2
index|]
decl_stmt|;
comment|/* two busses */
name|u_int8_t
name|rstatus
index|[
literal|2
index|]
decl_stmt|;
comment|/* two bussed */
name|u_int16_t
name|rollinfo
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

begin_define
define|#
directive|define
name|ISP_LOCK
value|isp_lockspl
end_define

begin_define
define|#
directive|define
name|ISP_UNLOCK
value|isp_unlockspl
end_define

begin_define
define|#
directive|define
name|ISPLOCK_2_CAMLOCK
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_ISPLOCK
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*  * Required Macros/Defines  */
end_comment

begin_define
define|#
directive|define
name|INLINE
value|__inline
end_define

begin_define
define|#
directive|define
name|ISP2100_SCRLEN
value|0x400
end_define

begin_define
define|#
directive|define
name|MEMZERO
value|bzero
end_define

begin_define
define|#
directive|define
name|MEMCPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|amt
parameter_list|)
value|bcopy((src), (dst), (amt))
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
name|STRNCAT
value|strncat
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
define|\
value|if (isp->isp_osinfo.intsok)	\ 		ISP_UNLOCK(isp);	\ 	DELAY(x);			\ 	if (isp->isp_osinfo.intsok)	\ 		ISP_LOCK(isp)
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
value|nanotime_sub
end_define

begin_define
define|#
directive|define
name|MAXISPREQUEST
parameter_list|(
name|isp
parameter_list|)
value|256
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

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
value|alpha_mb()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

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
value|do { ia64_mf(); ia64_mf_a(); } while (0)
end_define

begin_else
else|#
directive|else
end_else

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
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MBOX_ACQUIRE
parameter_list|(
name|isp
parameter_list|)
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
parameter_list|(
name|isp
parameter_list|)
define|\
value|if (isp->isp_osinfo.mboxwaiting) { \ 		isp->isp_osinfo.mboxwaiting = 0; \ 		wakeup(&isp->isp_osinfo.mboxwaiting); \ 	} \ 	isp->isp_mboxbsy = 0
end_define

begin_define
define|#
directive|define
name|MBOX_RELEASE
parameter_list|(
name|isp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|FC_SCRATCH_ACQUIRE
parameter_list|(
name|isp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|FC_SCRATCH_RELEASE
parameter_list|(
name|isp
parameter_list|)
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
name|XS_ISP
parameter_list|(
name|ccb
parameter_list|)
value|((struct ispsoftc *) (ccb)->ccb_h.spriv_ptr1)
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
name|sp
parameter_list|)
define|\
value|(xs)->ccb_h.status |= CAM_AUTOSNS_VALID,	\ 	bcopy(sp->req_sense_data,&(xs)->sense_data,	\ 	    imin(XS_SNSLEN(xs), sp->req_sense_len))
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
value|7
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOOPID
parameter_list|(
name|x
parameter_list|)
value|109
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
value|FCPARAM(isp)->isp_nodewwn
end_define

begin_define
define|#
directive|define
name|ISP_PORTWWN
parameter_list|(
name|isp
parameter_list|)
value|FCPARAM(isp)->isp_portwwn
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
value|d = (*((u_int8_t *)s))
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
value|d = (isp->isp_bustype == ISP_BT_SBUS)?			\ 	*((u_int16_t *)s) : bswap16(*((u_int16_t *)s))
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
value|d = (isp->isp_bustype == ISP_BT_SBUS)?			\ 	*((u_int32_t *)s) : bswap32(*((u_int32_t *)s))
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
value|d = (*((u_int8_t *)s))
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
value|d = bswap16(*((u_int16_t *)s))
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
value|d = bswap32(*((u_int32_t *)s))
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
name|struct
name|ispsoftc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isp_uninit
parameter_list|(
name|struct
name|ispsoftc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/*  * Platform specific inline functions  */
end_comment

begin_function_decl
specifier|static
name|INLINE
name|void
name|isp_lockspl
parameter_list|(
name|struct
name|ispsoftc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|INLINE
name|void
name|isp_lockspl
parameter_list|(
name|struct
name|ispsoftc
modifier|*
name|isp
parameter_list|)
block|{
name|int
name|s
init|=
name|splcam
argument_list|()
decl_stmt|;
if|if
condition|(
name|isp
operator|->
name|isp_osinfo
operator|.
name|islocked
operator|++
operator|==
literal|0
condition|)
block|{
name|isp
operator|->
name|isp_osinfo
operator|.
name|splsaved
operator|=
name|s
expr_stmt|;
block|}
else|else
block|{
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function_decl
specifier|static
name|INLINE
name|void
name|isp_unlockspl
parameter_list|(
name|struct
name|ispsoftc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|INLINE
name|void
name|isp_unlockspl
parameter_list|(
name|struct
name|ispsoftc
modifier|*
name|isp
parameter_list|)
block|{
if|if
condition|(
name|isp
operator|->
name|isp_osinfo
operator|.
name|islocked
condition|)
block|{
if|if
condition|(
operator|--
name|isp
operator|->
name|isp_osinfo
operator|.
name|islocked
operator|==
literal|0
condition|)
block|{
name|splx
argument_list|(
name|isp
operator|->
name|isp_osinfo
operator|.
name|splsaved
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function_decl
specifier|static
name|INLINE
name|void
name|isp_mbox_wait_complete
parameter_list|(
name|struct
name|ispsoftc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|INLINE
name|void
name|isp_mbox_wait_complete
parameter_list|(
name|struct
name|ispsoftc
modifier|*
name|isp
parameter_list|)
block|{
if|if
condition|(
name|isp
operator|->
name|isp_osinfo
operator|.
name|intsok
condition|)
block|{
name|int
name|lim
init|=
operator|(
operator|(
name|isp
operator|->
name|isp_mbxwrk0
operator|)
condition|?
literal|120
else|:
literal|20
operator|)
operator|*
name|hz
decl_stmt|;
name|isp
operator|->
name|isp_osinfo
operator|.
name|mboxwaiting
operator|=
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|tsleep
argument_list|(
operator|&
name|isp
operator|->
name|isp_osinfo
operator|.
name|mboxwaiting
argument_list|,
name|PRIBIO
argument_list|,
literal|"isp_mboxwaiting"
argument_list|,
name|lim
argument_list|)
expr_stmt|;
if|if
condition|(
name|isp
operator|->
name|isp_mboxbsy
operator|!=
literal|0
condition|)
block|{
name|isp_prt
argument_list|(
name|isp
argument_list|,
name|ISP_LOGWARN
argument_list|,
literal|"Interrupting Mailbox Command (0x%x) Timeout"
argument_list|,
name|isp
operator|->
name|isp_lastmbxcmd
argument_list|)
expr_stmt|;
name|isp
operator|->
name|isp_mboxbsy
operator|=
literal|0
expr_stmt|;
block|}
name|isp
operator|->
name|isp_osinfo
operator|.
name|mboxwaiting
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|int
name|lim
init|=
operator|(
operator|(
name|isp
operator|->
name|isp_mbxwrk0
operator|)
condition|?
literal|240
else|:
literal|60
operator|)
operator|*
literal|10000
decl_stmt|;
name|int
name|j
decl_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|lim
condition|;
name|j
operator|++
control|)
block|{
name|u_int16_t
name|isr
decl_stmt|,
name|sema
decl_stmt|,
name|mbox
decl_stmt|;
if|if
condition|(
name|isp
operator|->
name|isp_mboxbsy
operator|==
literal|0
condition|)
block|{
break|break;
block|}
if|if
condition|(
name|ISP_READ_ISR
argument_list|(
name|isp
argument_list|,
operator|&
name|isr
argument_list|,
operator|&
name|sema
argument_list|,
operator|&
name|mbox
argument_list|)
condition|)
block|{
name|isp_intr
argument_list|(
name|isp
argument_list|,
name|isr
argument_list|,
name|sema
argument_list|,
name|mbox
argument_list|)
expr_stmt|;
if|if
condition|(
name|isp
operator|->
name|isp_mboxbsy
operator|==
literal|0
condition|)
block|{
break|break;
block|}
block|}
name|USEC_DELAY
argument_list|(
literal|500
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|isp
operator|->
name|isp_mboxbsy
operator|!=
literal|0
condition|)
block|{
name|isp_prt
argument_list|(
name|isp
argument_list|,
name|ISP_LOGWARN
argument_list|,
literal|"Polled Mailbox Command (0x%x) Timeout"
argument_list|,
name|isp
operator|->
name|isp_lastmbxcmd
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function_decl
specifier|static
name|INLINE
name|u_int64_t
name|nanotime_sub
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

begin_function
specifier|static
name|INLINE
name|u_int64_t
name|nanotime_sub
parameter_list|(
name|struct
name|timespec
modifier|*
name|b
parameter_list|,
name|struct
name|timespec
modifier|*
name|a
parameter_list|)
block|{
name|u_int64_t
name|elapsed
decl_stmt|;
name|struct
name|timespec
name|x
init|=
operator|*
name|b
decl_stmt|;
name|timespecsub
argument_list|(
operator|&
name|x
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|elapsed
operator|=
name|GET_NANOSEC
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|elapsed
operator|==
literal|0
condition|)
name|elapsed
operator|++
expr_stmt|;
return|return
operator|(
name|elapsed
operator|)
return|;
block|}
end_function

begin_function_decl
specifier|static
name|INLINE
name|char
modifier|*
name|strncat
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|INLINE
name|char
modifier|*
name|strncat
parameter_list|(
name|char
modifier|*
name|d
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|char
modifier|*
name|t
init|=
name|d
decl_stmt|;
if|if
condition|(
name|c
condition|)
block|{
while|while
condition|(
operator|*
name|d
condition|)
name|d
operator|++
expr_stmt|;
while|while
condition|(
operator|(
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
operator|)
condition|)
block|{
if|if
condition|(
operator|--
name|c
operator|==
literal|0
condition|)
block|{
operator|*
name|d
operator|=
literal|'\0'
expr_stmt|;
break|break;
block|}
block|}
block|}
return|return
operator|(
name|t
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Common inline functions  */
end_comment

begin_include
include|#
directive|include
file|<dev/isp/isp_inline.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_FREEBSD_H */
end_comment

end_unit

