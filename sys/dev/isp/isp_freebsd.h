begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Qlogic ISP SCSI Host Adapter FreeBSD Wrapper Definitions (CAM version)  *---------------------------------------  * Copyright (c) 1997, 1998, 1999 by Matthew Jacob  * NASA/Ames Research Center  * All rights reserved.  *---------------------------------------  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
value|3
end_define

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MINOR
value|1
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

begin_ifdef
ifdef|#
directive|ifdef
name|SCSI_ISP_FABRIC
end_ifdef

begin_define
define|#
directive|define
name|ISP2100_FABRIC
value|1
end_define

begin_define
define|#
directive|define
name|ISP2100_SCRLEN
value|0x400
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP2100_SCRLEN
value|0x100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCSI_ISP_SCCLUN
end_ifdef

begin_define
define|#
directive|define
name|ISP2100_SCCLUN
value|1
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
name|ISP_SCSI_XFER_T
value|struct ccb_scsiio
end_define

begin_struct
struct|struct
name|isposinfo
block|{
name|u_int64_t
name|default_wwn
decl_stmt|;
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|int
name|unit
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
specifier|volatile
name|char
name|simqfrozen
decl_stmt|;
block|}
struct|;
end_struct

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
name|isp_unit
value|isp_osinfo.unit
end_define

begin_define
define|#
directive|define
name|isp_name
value|isp_osinfo.name
end_define

begin_define
define|#
directive|define
name|MAXISPREQUEST
value|256
end_define

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

begin_define
define|#
directive|define
name|DFLT_DBLEVEL
value|isp_debug
end_define

begin_decl_stmt
specifier|extern
name|int
name|isp_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ISP_LOCKVAL_DECL
value|int isp_spl_save
end_define

begin_define
define|#
directive|define
name|ISP_ILOCKVAL_DECL
value|ISP_LOCKVAL_DECL
end_define

begin_define
define|#
directive|define
name|ISP_UNLOCK
parameter_list|(
name|isp
parameter_list|)
value|(void) splx(isp_spl_save)
end_define

begin_define
define|#
directive|define
name|ISP_LOCK
parameter_list|(
name|isp
parameter_list|)
value|isp_spl_save = splcam()
end_define

begin_define
define|#
directive|define
name|ISP_ILOCK
parameter_list|(
name|isp
parameter_list|)
value|ISP_LOCK(isp)
end_define

begin_define
define|#
directive|define
name|ISP_IUNLOCK
parameter_list|(
name|isp
parameter_list|)
value|ISP_UNLOCK(isp)
end_define

begin_define
define|#
directive|define
name|IMASK
value|cam_imask
end_define

begin_define
define|#
directive|define
name|XS_NULL
parameter_list|(
name|ccb
parameter_list|)
value|ccb == NULL
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
name|XS_LUN
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->ccb_h.target_lun
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
name|XS_CHANNEL
parameter_list|(
name|ccb
parameter_list|)
value|cam_sim_bus(xpt_path_sim((ccb)->ccb_h.path))
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
name|XS_XFRLEN
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->dxfer_len
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
name|XS_CDBP
parameter_list|(
name|ccb
parameter_list|)
value|(((ccb)->ccb_h.flags& CAM_CDB_POINTER)? \ 	(ccb)->cdb_io.cdb_ptr : (ccb)->cdb_io.cdb_bytes)
end_define

begin_define
define|#
directive|define
name|XS_STS
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->scsi_status
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

begin_comment
comment|/*  * A little tricky- HBA_NOERROR is "in progress" so  * that XS_CMD_DONE can transition this to CAM_REQ_CMP.  */
end_comment

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
name|XS_SNS_IS_VALID
parameter_list|(
name|ccb
parameter_list|)
value|((ccb)->ccb_h.status |= CAM_AUTOSNS_VALID)
end_define

begin_define
define|#
directive|define
name|XS_IS_SNS_VALID
parameter_list|(
name|ccb
parameter_list|)
value|(((ccb)->ccb_h.status& CAM_AUTOSNS_VALID) != 0)
end_define

begin_define
define|#
directive|define
name|XS_INITERR
parameter_list|(
name|ccb
parameter_list|)
define|\
value|(ccb)->ccb_h.status&= ~CAM_STATUS_MASK, \ 	(ccb)->ccb_h.status |= CAM_REQ_INPROG, \ 	(ccb)->ccb_h.spriv_field0 = CAM_REQ_INPROG
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
value|(ccb)->ccb_h.spriv_field0 = v
end_define

begin_define
define|#
directive|define
name|XS_ERR
parameter_list|(
name|ccb
parameter_list|)
value|(ccb)->ccb_h.spriv_field0
end_define

begin_define
define|#
directive|define
name|XS_NOERR
parameter_list|(
name|ccb
parameter_list|)
define|\
value|((ccb)->ccb_h.spriv_field0 == CAM_REQ_INPROG)
end_define

begin_function_decl
specifier|extern
name|void
name|isp_done
parameter_list|(
name|struct
name|ccb_scsiio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XS_CMD_DONE
parameter_list|(
name|sccb
parameter_list|)
value|isp_done(sccb)
end_define

begin_define
define|#
directive|define
name|XS_IS_CMD_DONE
parameter_list|(
name|ccb
parameter_list|)
define|\
value|(((ccb)->ccb_h.status& CAM_STATUS_MASK) != CAM_REQ_INPROG)
end_define

begin_comment
comment|/*  * Can we tag?  */
end_comment

begin_define
define|#
directive|define
name|XS_CANTAG
parameter_list|(
name|ccb
parameter_list|)
value|(((ccb)->ccb_h.flags& CAM_TAG_ACTION_VALID) \&& (ccb)->tag_action != CAM_TAG_ACTION_NONE)
end_define

begin_comment
comment|/*  * And our favorite tag is....  */
end_comment

begin_define
define|#
directive|define
name|XS_KINDOF_TAG
parameter_list|(
name|ccb
parameter_list|)
define|\
value|((ccb->tag_action == MSG_SIMPLE_Q_TAG)? REQFLAG_STAG : \ 	  ((ccb->tag_action == MSG_HEAD_OF_Q_TAG)? REQFLAG_HTAG : REQFLAG_OTAG))
end_define

begin_define
define|#
directive|define
name|CMD_COMPLETE
value|0
end_define

begin_define
define|#
directive|define
name|CMD_EAGAIN
value|1
end_define

begin_define
define|#
directive|define
name|CMD_QUEUED
value|2
end_define

begin_define
define|#
directive|define
name|CMD_RQLATER
value|3
end_define

begin_define
define|#
directive|define
name|STOP_WATCHDOG
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|MemoryBarrier
value|alpha_mb
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MemoryBarrier
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|ISP_UNSWIZZLE_AND_COPY_PDBP
parameter_list|(
name|isp
parameter_list|,
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|bcopy(src, dest, sizeof (isp_pdb_t))
end_define

begin_define
define|#
directive|define
name|ISP_SWIZZLE_ICB
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZZLE_REQUEST
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ISP_UNSWIZZLE_RESPONSE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ISP_SWIZZLE_SNS_REQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ISP_UNSWIZZLE_SNS_RSP
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
name|IDPRINTF
parameter_list|(
name|lev
parameter_list|,
name|x
parameter_list|)
value|if (isp->isp_dblev>= (u_int8_t) lev) printf x
end_define

begin_define
define|#
directive|define
name|PRINTF
value|printf
end_define

begin_define
define|#
directive|define
name|CFGPRINTF
value|if (bootverbose || DFLT_DBLEVEL> 0) printf
end_define

begin_define
define|#
directive|define
name|SYS_DELAY
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|FC_FW_READY_DELAY
value|(5 * 1000000)
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
name|DEFAULT_WWN
parameter_list|(
name|x
parameter_list|)
value|(x)->isp_osinfo.default_wwn
end_define

begin_define
define|#
directive|define
name|INLINE
value|__inline
end_define

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

