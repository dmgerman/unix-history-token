begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
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
value|2
end_define

begin_define
define|#
directive|define
name|ISP_PLATFORM_VERSION_MINOR
value|0
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
decl_stmt|,
name|blocked
decl_stmt|;
union|union
block|{
name|int
name|_seed
decl_stmt|;
name|u_int16_t
name|_discovered
index|[
literal|2
index|]
decl_stmt|;
block|}
name|un
union|;
define|#
directive|define
name|seed
value|un._seed
define|#
directive|define
name|discovered
value|un._discovered
name|struct
name|scsi_link
name|_link
decl_stmt|;
name|struct
name|scsi_link
name|_link_b
decl_stmt|;
name|struct
name|scsi_xfer
modifier|*
name|wqf
decl_stmt|,
modifier|*
name|wqt
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
name|MemoryBarrier
parameter_list|()
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SCSIDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|DFLT_DBLEVEL
value|3
end_define

begin_define
define|#
directive|define
name|CFGPRINTF
value|printf
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DIAGNOSTIC
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG
argument_list|)
end_elif

begin_define
define|#
directive|define
name|DFLT_DBLEVEL
value|1
end_define

begin_define
define|#
directive|define
name|CFGPRINTF
value|printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DFLT_DBLEVEL
value|0
end_define

begin_define
define|#
directive|define
name|CFGPRINTF
value|if (0)	printf
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
value|REQFLAG_OTAG
end_define

begin_comment
comment|/*  * These get turned into NetBSD midlayer codes  */
end_comment

begin_define
define|#
directive|define
name|CMD_COMPLETE
value|100
end_define

begin_define
define|#
directive|define
name|CMD_EAGAIN
value|101
end_define

begin_define
define|#
directive|define
name|CMD_QUEUED
value|102
end_define

begin_define
define|#
directive|define
name|CMD_RQLATER
value|103
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

begin_define
define|#
directive|define
name|FC_FW_READY_DELAY
value|(12 * 1000000)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_define
define|#
directive|define
name|ISP_SWIZZLE_REQUEST
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|ISP_SBUSIFY_ISPHDR(a,&(b)->req_header);	\         ISP_SBUSIFY_ISPREQ(a, b)
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
define|\
value|ISP_SBUSIFY_ISPHDR(a,&(b)->req_header)
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

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

