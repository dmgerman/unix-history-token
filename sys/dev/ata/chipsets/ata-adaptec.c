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
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|MV_60XX
value|60
end_define

begin_comment
comment|//must match ata_marvell.c's definition
end_comment

begin_define
define|#
directive|define
name|MV_7042
value|72
end_define

begin_comment
comment|//must match ata_marvell.c's definition
end_comment

begin_comment
comment|/*  * Adaptec chipset support functions  */
end_comment

begin_function
specifier|static
name|int
name|ata_adaptec_probe
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
specifier|static
name|struct
name|ata_chip_id
name|ids
index|[]
init|=
block|{
block|{
name|ATA_ADAPTEC_1420
block|,
literal|0
block|,
literal|4
block|,
name|MV_60XX
block|,
name|ATA_SA300
block|,
literal|"1420SA"
block|}
block|,
block|{
name|ATA_ADAPTEC_1430
block|,
literal|0
block|,
literal|4
block|,
name|MV_7042
block|,
name|ATA_SA300
block|,
literal|"1430SA"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
if|if
condition|(
name|pci_get_vendor
argument_list|(
name|dev
argument_list|)
operator|!=
name|ATA_ADAPTEC_ID
condition|)
return|return
name|ENXIO
return|;
if|if
condition|(
operator|!
operator|(
name|ctlr
operator|->
name|chip
operator|=
name|ata_match_chip
argument_list|(
name|dev
argument_list|,
name|ids
argument_list|)
operator|)
condition|)
return|return
name|ENXIO
return|;
name|ata_set_desc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|ctlr
operator|->
name|chipinit
operator|=
name|ata_marvell_edma_chipinit
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|ATA_DECLARE_DRIVER
argument_list|(
name|ata_adaptec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ata_adaptec
argument_list|,
name|ata_marvell
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

