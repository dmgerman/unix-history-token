begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* release_6_5_99 */
end_comment

begin_comment
comment|/*  * Qlogic ISP SCSI Host Adapter FreeBSD 2.X Wrapper Definitions  *---------------------------------------  * Copyright (c) 1997, 1998, 1999 by Matthew Jacob  * NASA/Ames Research Center  * All rights reserved.  *---------------------------------------  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
value|0
end_define

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MINOR
value|992
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|"opt_isp.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_ISP_PREFER_MEM_MAP
end_ifndef

begin_define
define|#
directive|define
name|SCSI_ISP_PREFER_MEM_MAP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|ISP_SCSI_XFER_T
value|struct scsi_xfer
end_define

begin_struct
struct|struct
name|isposinfo
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|int
name|seed
decl_stmt|;
name|struct
name|scsi_link
name|_link
decl_stmt|;
name|int8_t
name|delay_throttle_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXISPREQUEST
value|64
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
name|PVS
value|"Qlogic ISP Driver, FreeBSD Non-Cam"
end_define

begin_define
define|#
directive|define
name|DFLT_DBLEVEL
value|1
end_define

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
value|isp_spl_save = splbio()
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
value|bio_imask
end_define

begin_define
define|#
directive|define
name|XS_NULL
parameter_list|(
name|xs
parameter_list|)
value|xs == NULL || xs->sc_link == NULL
end_define

begin_define
define|#
directive|define
name|XS_ISP
parameter_list|(
name|xs
parameter_list|)
define|\
value|((struct ispsoftc *) (xs)->sc_link->adapter_softc)
end_define

begin_define
define|#
directive|define
name|XS_LUN
parameter_list|(
name|xs
parameter_list|)
value|((int) (xs)->sc_link->lun)
end_define

begin_define
define|#
directive|define
name|XS_TGT
parameter_list|(
name|xs
parameter_list|)
value|((int) (xs)->sc_link->target)
end_define

begin_define
define|#
directive|define
name|XS_CHANNEL
parameter_list|(
name|xs
parameter_list|)
value|((int) (xs)->sc_link->adapter_bus)
end_define

begin_define
define|#
directive|define
name|XS_RESID
parameter_list|(
name|xs
parameter_list|)
value|(xs)->resid
end_define

begin_define
define|#
directive|define
name|XS_XFRLEN
parameter_list|(
name|xs
parameter_list|)
value|(xs)->datalen
end_define

begin_define
define|#
directive|define
name|XS_CDBLEN
parameter_list|(
name|xs
parameter_list|)
value|(xs)->cmdlen
end_define

begin_define
define|#
directive|define
name|XS_CDBP
parameter_list|(
name|xs
parameter_list|)
value|(xs)->cmd
end_define

begin_define
define|#
directive|define
name|XS_STS
parameter_list|(
name|xs
parameter_list|)
value|(xs)->status
end_define

begin_define
define|#
directive|define
name|XS_TIME
parameter_list|(
name|xs
parameter_list|)
value|(xs)->timeout
end_define

begin_define
define|#
directive|define
name|XS_SNSP
parameter_list|(
name|xs
parameter_list|)
value|(&(xs)->sense)
end_define

begin_define
define|#
directive|define
name|XS_SNSLEN
parameter_list|(
name|xs
parameter_list|)
value|(sizeof((xs)->sense))
end_define

begin_define
define|#
directive|define
name|XS_SNSKEY
parameter_list|(
name|xs
parameter_list|)
value|((xs)->sense.ext.extended.flags)
end_define

begin_define
define|#
directive|define
name|HBA_NOERROR
value|XS_NOERROR
end_define

begin_define
define|#
directive|define
name|HBA_BOTCH
value|XS_DRIVER_STUFFUP
end_define

begin_define
define|#
directive|define
name|HBA_CMDTIMEOUT
value|XS_TIMEOUT
end_define

begin_define
define|#
directive|define
name|HBA_SELTIMEOUT
value|XS_SELTIMEOUT
end_define

begin_define
define|#
directive|define
name|HBA_TGTBSY
value|XS_BUSY
end_define

begin_define
define|#
directive|define
name|HBA_BUSRESET
value|XS_DRIVER_STUFFUP
end_define

begin_define
define|#
directive|define
name|HBA_ABORTED
value|XS_DRIVER_STUFFUP
end_define

begin_define
define|#
directive|define
name|HBA_DATAOVR
value|XS_DRIVER_STUFFUP
end_define

begin_define
define|#
directive|define
name|HBA_ARQFAIL
value|XS_DRIVER_STUFFUP
end_define

begin_define
define|#
directive|define
name|XS_SNS_IS_VALID
parameter_list|(
name|xs
parameter_list|)
value|(xs)->error = XS_SENSE
end_define

begin_define
define|#
directive|define
name|XS_IS_SNS_VALID
parameter_list|(
name|xs
parameter_list|)
value|((xs)->error == XS_SENSE)
end_define

begin_define
define|#
directive|define
name|XS_INITERR
parameter_list|(
name|xs
parameter_list|)
value|(xs)->error = 0
end_define

begin_define
define|#
directive|define
name|XS_SETERR
parameter_list|(
name|xs
parameter_list|,
name|v
parameter_list|)
value|(xs)->error = v
end_define

begin_define
define|#
directive|define
name|XS_ERR
parameter_list|(
name|xs
parameter_list|)
value|(xs)->error
end_define

begin_define
define|#
directive|define
name|XS_NOERR
parameter_list|(
name|xs
parameter_list|)
value|(xs)->error == XS_NOERROR
end_define

begin_define
define|#
directive|define
name|XS_CMD_DONE
parameter_list|(
name|xs
parameter_list|)
value|(xs)->flags |= ITSDONE, scsi_done(xs)
end_define

begin_define
define|#
directive|define
name|XS_IS_CMD_DONE
parameter_list|(
name|xs
parameter_list|)
value|(((xs)->flags& ITSDONE) != 0)
end_define

begin_comment
comment|/*  * We decide whether to use tags based upon whether we're polling.  */
end_comment

begin_define
define|#
directive|define
name|XS_CANTAG
parameter_list|(
name|xs
parameter_list|)
value|(((xs)->flags& SCSI_NOMASK) != 0)
end_define

begin_comment
comment|/*  * Our default tag  */
end_comment

begin_define
define|#
directive|define
name|XS_KINDOF_TAG
parameter_list|(
name|xs
parameter_list|)
value|REQFLAG_STAG
end_define

begin_define
define|#
directive|define
name|CMD_COMPLETE
value|COMPLETE
end_define

begin_define
define|#
directive|define
name|CMD_EAGAIN
value|TRY_AGAIN_LATER
end_define

begin_define
define|#
directive|define
name|CMD_QUEUED
value|SUCCESSFULLY_QUEUED
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
name|isp_unit
value|isp_osinfo.unit
end_define

begin_define
define|#
directive|define
name|SCSI_QFULL
value|0x28
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
name|IDPRINTF
parameter_list|(
name|lev
parameter_list|,
name|x
parameter_list|)
value|if (isp->isp_dblev>= lev) printf x
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
value|(0x1000feeb00000000LL + (x)->isp_osinfo.seed)
end_define

begin_function_decl
specifier|static
name|__inline
name|void
name|isp_prtstst
parameter_list|(
name|ispstatusreq_t
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|isp2100_fw_statename
parameter_list|(
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|isp2100_pdb_statename
parameter_list|(
name|int
name|pdb_state
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|isp_prtstst
parameter_list|(
name|ispstatusreq_t
modifier|*
name|sp
parameter_list|)
block|{
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"states->"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_state_flags
operator|&
name|RQSF_GOT_BUS
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"GOT_BUS "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_state_flags
operator|&
name|RQSF_GOT_TARGET
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"GOT_TGT "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_state_flags
operator|&
name|RQSF_SENT_CDB
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"SENT_CDB "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_state_flags
operator|&
name|RQSF_XFRD_DATA
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"XFRD_DATA "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_state_flags
operator|&
name|RQSF_GOT_STATUS
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"GOT_STS "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_state_flags
operator|&
name|RQSF_GOT_SENSE
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"GOT_SNS "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_state_flags
operator|&
name|RQSF_XFER_COMPLETE
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"XFR_CMPLT "
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"status->"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_DISCONNECT
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Disconnect "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_SYNCHRONOUS
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Sync_xfr "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_PARITY_ERROR
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Parity "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_BUS_RESET
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Bus_Reset "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_DEVICE_RESET
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Device_Reset "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_ABORTED
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Aborted "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_TIMEOUT
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Timeout "
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|->
name|req_status_flags
operator|&
name|RQSTF_NEGOTIATION
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s%s"
argument_list|,
name|buf
argument_list|,
literal|"Negotiation "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|buf
argument_list|,
literal|"%s\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|isp2100_fw_statename
parameter_list|(
name|int
name|state
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|16
index|]
decl_stmt|;
switch|switch
condition|(
name|state
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
literal|"Waiting for AL_PA"
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
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"0x%x"
argument_list|,
name|state
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|isp2100_pdb_statename
parameter_list|(
name|int
name|pdb_state
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|16
index|]
decl_stmt|;
switch|switch
condition|(
name|pdb_state
condition|)
block|{
case|case
name|PDB_STATE_DISCOVERY
case|:
return|return
literal|"Port Discovery"
return|;
case|case
name|PDB_STATE_WDISC_ACK
case|:
return|return
literal|"Waiting Port Discovery ACK"
return|;
case|case
name|PDB_STATE_PLOGI
case|:
return|return
literal|"Port Login"
return|;
case|case
name|PDB_STATE_PLOGI_ACK
case|:
return|return
literal|"Wait Port Login ACK"
return|;
case|case
name|PDB_STATE_PRLI
case|:
return|return
literal|"Process Login"
return|;
case|case
name|PDB_STATE_PRLI_ACK
case|:
return|return
literal|"Wait Process Login ACK"
return|;
case|case
name|PDB_STATE_LOGGED_IN
case|:
return|return
literal|"Logged In"
return|;
case|case
name|PDB_STATE_PORT_UNAVAIL
case|:
return|return
literal|"Port Unavailable"
return|;
case|case
name|PDB_STATE_PRLO
case|:
return|return
literal|"Process Logout"
return|;
case|case
name|PDB_STATE_PRLO_ACK
case|:
return|return
literal|"Wait Process Logout ACK"
return|;
case|case
name|PDB_STATE_PLOGO
case|:
return|return
literal|"Port Logout"
return|;
case|case
name|PDB_STATE_PLOG_ACK
case|:
return|return
literal|"Wait Port Logout ACK"
return|;
default|default:
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"0x%x"
argument_list|,
name|pdb_state
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_FREEBSD_H */
end_comment

end_unit

