begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: scsi_low_pisa.c,v 1.13 1998/11/26 14:26:11 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1995, 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1995, 1996, 1997, 1998  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

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
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isareg.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isavar.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/pisaif.h>
end_include

begin_include
include|#
directive|include
file|<machine/dvcfg.h>
end_include

begin_include
include|#
directive|include
file|<dev/scsipi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<dev/scsipi/scsipi_all.h>
end_include

begin_include
include|#
directive|include
file|<dev/scsipi/scsiconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/scsipi/scsi_disk.h>
end_include

begin_include
include|#
directive|include
file|<i386/Cbus/dev/scsi_low.h>
end_include

begin_include
include|#
directive|include
file|<i386/Cbus/dev/scsi_low_pisa.h>
end_include

begin_define
define|#
directive|define
name|SCSIBUS_RESCAN
end_define

begin_function
name|int
name|scsi_low_deactivate_pisa
parameter_list|(
name|dh
parameter_list|)
name|pisa_device_handle_t
name|dh
decl_stmt|;
block|{
name|struct
name|scsi_low_softc
modifier|*
name|sc
init|=
name|PISA_DEV_SOFTC
argument_list|(
name|dh
argument_list|)
decl_stmt|;
if|if
condition|(
name|scsi_low_deactivate
argument_list|(
name|sc
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|EBUSY
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|scsi_low_activate_pisa
parameter_list|(
name|dh
parameter_list|)
name|pisa_device_handle_t
name|dh
decl_stmt|;
block|{
name|struct
name|scsi_low_softc
modifier|*
name|sc
init|=
name|PISA_DEV_SOFTC
argument_list|(
name|dh
argument_list|)
decl_stmt|;
name|slot_device_res_t
name|dr
init|=
name|PISA_RES_DR
argument_list|(
name|dh
argument_list|)
decl_stmt|;
name|sc
operator|->
name|sl_cfgflags
operator|=
name|DVCFG_MKCFG
argument_list|(
name|DVCFG_MAJOR
argument_list|(
name|sc
operator|->
name|sl_cfgflags
argument_list|)
argument_list|, \
name|DVCFG_MINOR
argument_list|(
name|PISA_DR_DVCFG
argument_list|(
name|dr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sl_irq
operator|=
name|PISA_DR_IRQ
argument_list|(
name|dr
argument_list|)
expr_stmt|;
if|if
condition|(
name|scsi_low_activate
argument_list|(
name|sc
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|EBUSY
return|;
comment|/* rescan the scsi bus */
ifdef|#
directive|ifdef
name|SCSIBUS_RESCAN
if|if
condition|(
name|scsi_low_is_busy
argument_list|(
name|sc
argument_list|)
operator|==
literal|0
operator|&&
name|PISA_RES_EVENT
argument_list|(
name|dh
argument_list|)
operator|==
name|PISA_EVENT_INSERT
condition|)
name|scsi_probe_busses
argument_list|(
operator|(
name|int
operator|)
name|sc
operator|->
name|sl_si
operator|.
name|si_splp
operator|->
name|scsipi_scsi
operator|.
name|scsibus
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|scsi_low_notify_pisa
parameter_list|(
name|dh
parameter_list|,
name|ev
parameter_list|)
name|pisa_device_handle_t
name|dh
decl_stmt|;
name|pisa_event_t
name|ev
decl_stmt|;
block|{
name|struct
name|scsi_low_softc
modifier|*
name|sc
init|=
name|PISA_DEV_SOFTC
argument_list|(
name|dh
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|ev
condition|)
block|{
case|case
name|PISA_EVENT_QUERY_SUSPEND
case|:
if|if
condition|(
name|scsi_low_is_busy
argument_list|(
name|sc
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|SD_EVENT_STATUS_BUSY
return|;
break|break;
default|default:
break|break;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500001
end_if

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/device_port.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_low.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_low_pisa.h>
end_include

begin_function
name|int
name|scsi_low_deactivate_pisa
parameter_list|(
name|sc
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|sc
decl_stmt|;
block|{
if|if
condition|(
name|scsi_low_deactivate
argument_list|(
name|sc
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|EBUSY
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|scsi_low_activate_pisa
parameter_list|(
name|sc
parameter_list|,
name|flags
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|{
name|sc
operator|->
name|sl_cfgflags
operator|=
operator|(
operator|(
name|sc
operator|->
name|sl_cfgflags
operator|&
literal|0xffff0000
operator|)
operator||
operator|(
name|flags
operator|&
literal|0x00ff
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|scsi_low_activate
argument_list|(
name|sc
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|EBUSY
return|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

end_unit

