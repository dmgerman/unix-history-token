begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Id: isp_freebsd.h,v 1.9 1998/04/17 17:09:29 mjacob Exp $ */
end_comment

begin_comment
comment|/*  * Qlogic ISP SCSI Host Adapter FreeBSD Wrapper Definitions (non CAM version)  *---------------------------------------  * Copyright (c) 1997, 1998 by Matthew Jacob  * NASA/Ames Research Center  * All rights reserved.  *---------------------------------------  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<pci.h>
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
file|<scsi/scsi_debug.h>
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
file|<osreldate.h>
end_include

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
name|struct
name|scsi_link
name|_link
decl_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|300001
name|struct
name|callout_handle
name|watchid
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXXX: UNTIL WE PUT CODE IN THAT CHECKS RETURNS FROM MALLOC  * XXXX: FOR CONTIGOUS PAGES, WE LIMIT TO PAGE_SIZE THE SIZE  * XXXX: OF MAILBOXES.  */
end_comment

begin_define
define|#
directive|define
name|MAXISPREQUEST
value|64
end_define

begin_define
define|#
directive|define
name|ISP_VERSION_STRING
define|\
value|"Version 0.92 Alpha Fri Apr 17 09:34:03 PDT 1998"
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
name|PRINTF
value|printf
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

begin_ifdef
ifdef|#
directive|ifdef
name|SCSIDEBUG
end_ifdef

begin_define
define|#
directive|define
name|DFLT_DBLEVEL
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DFLT_DBLEVEL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISP_LOCKVAL_DECL
value|int isp_spl_save
end_define

begin_define
define|#
directive|define
name|ISP_UNLOCK
value|(void) splx(isp_spl_save)
end_define

begin_define
define|#
directive|define
name|ISP_LOCK
value|isp_spl_save = splbio()
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
value|(xs)->sc_link->adapter_softc
end_define

begin_define
define|#
directive|define
name|XS_LUN
parameter_list|(
name|xs
parameter_list|)
value|(xs)->sc_link->lun
end_define

begin_define
define|#
directive|define
name|XS_TGT
parameter_list|(
name|xs
parameter_list|)
value|(xs)->sc_link->target
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
value|(sizeof (xs)->sense)
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

begin_define
define|#
directive|define
name|XS_POLLDCMD
parameter_list|(
name|xs
parameter_list|)
value|((xs)->flags& SCSI_NOMASK)
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
name|SYS_DELAY
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|WATCH_INTERVAL
value|30
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|300001
end_if

begin_define
define|#
directive|define
name|START_WATCHDOG
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(s)->isp_osinfo.watchid = timeout(f, s, WATCH_INTERVAL * hz), \ 	s->isp_dogactive = 1
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
value|untimeout(f, s, (s)->isp_osinfo.watchid),\ 	(s)->isp_dogactive = 0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|START_WATCHDOG
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|timeout(f, s, WATCH_INTERVAL * hz), s->isp_dogactive = 1
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
value|untimeout(f, s), (s)->isp_dogactive = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RESTART_WATCHDOG
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
value|START_WATCHDOG(f, s)
end_define

begin_decl_stmt
specifier|extern
name|void
name|isp_attach
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_FREEBSD_H */
end_comment

end_unit

