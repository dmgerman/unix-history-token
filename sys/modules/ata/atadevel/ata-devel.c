begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 S\xf8ren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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
comment|/* prototypes */
end_comment

begin_function_decl
specifier|static
name|int
name|ata_devel_chipinit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ata_devel_allocate
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ata_devel_setmode
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|ata_devel_probe
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
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"ata_devel_probe(): PCIID=0x%08x\n"
argument_list|,
name|pci_get_devid
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pci_get_devid
argument_list|(
name|dev
argument_list|)
operator|==
literal|0x12345678
condition|)
block|{
name|printf
argument_list|(
literal|"test probe successful!\n"
argument_list|)
expr_stmt|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"ATA DEVEL controller"
argument_list|)
expr_stmt|;
name|ctlr
operator|->
name|chipinit
operator|=
name|ata_devel_chipinit
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|ENXIO
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ata_devel_chipinit
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
comment|/* setup interrupt delivery */
if|if
condition|(
name|ata_setup_interrupt
argument_list|(
name|dev
argument_list|,
name|ata_generic_intr
argument_list|)
condition|)
return|return
name|ENXIO
return|;
comment|/* perform any chipset specific setups here */
comment|/* setup function ptr's, in this case allocate and setmode */
name|ctlr
operator|->
name|allocate
operator|=
name|ata_devel_allocate
expr_stmt|;
name|ctlr
operator|->
name|setmode
operator|=
name|ata_devel_setmode
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ata_devel_allocate
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|ata_pci_allocate
argument_list|(
name|dev
argument_list|)
condition|)
return|return
name|ENXIO
return|;
comment|/* setup channel specifics here like offsets to registers etc */
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|ata_devel_setmode
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
name|struct
name|ata_device
modifier|*
name|atadev
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|int
name|error
decl_stmt|;
name|error
operator|=
name|ata_controlcmd
argument_list|(
name|dev
argument_list|,
name|ATA_SETFEATURES
argument_list|,
name|ATA_SF_SETXFER
argument_list|,
literal|0
argument_list|,
name|ata_limit_mode
argument_list|(
name|dev
argument_list|,
name|mode
argument_list|,
name|ATA_UDMA5
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"%ssetting %s on DEVEL chip\n"
argument_list|,
operator|(
name|error
operator|)
condition|?
literal|"FAILURE "
else|:
literal|""
argument_list|,
name|ata_mode2str
argument_list|(
name|mode
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|atadev
operator|->
name|mode
operator|=
name|mode
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ATA_DECLARE_DRIVER
argument_list|(
name|ata_devel
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

