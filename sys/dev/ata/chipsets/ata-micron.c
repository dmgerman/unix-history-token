begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2008 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_ata.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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
file|<sys/ata.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/ata/ata-all.h>
end_include

begin_include
include|#
directive|include
file|<dev/ata/ata-pci.h>
end_include

begin_include
include|#
directive|include
file|<ata_if.h>
end_include

begin_comment
comment|/*  * Cenatek chipset support functions  */
end_comment

begin_function
specifier|static
name|int
name|ata_micron_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|ata_pci_controller
modifier|*
name|ctlr
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
if|if
condition|(
name|pci_get_devid
argument_list|(
name|dev
argument_list|)
operator|==
name|ATA_MICRON_RZ1000
operator|||
name|pci_get_devid
argument_list|(
name|dev
argument_list|)
operator|==
name|ATA_MICRON_RZ1001
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"RZ 100? ATA controller !WARNING! data loss/corruption risk"
argument_list|)
expr_stmt|;
name|ctlr
operator|->
name|chipinit
operator|=
name|ata_generic_chipinit
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|ATA_DECLARE_DRIVER
argument_list|(
name|ata_micron
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

