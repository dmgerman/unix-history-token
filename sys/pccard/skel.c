begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Loadable kernel module skeleton driver  * 11 July 1995 Andrew McRae  *  *-------------------------------------------------------------------------  *  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<pccard/cardinfo.h>
end_include

begin_include
include|#
directive|include
file|<pccard/driver.h>
end_include

begin_include
include|#
directive|include
file|<pccard/slot.h>
end_include

begin_function_decl
specifier|static
name|int
name|skelinit
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* init device */
end_comment

begin_function_decl
specifier|static
name|void
name|skelunload
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disable driver */
end_comment

begin_function_decl
specifier|static
name|int
name|skelintr
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Interrupt handler */
end_comment

begin_expr_stmt
name|PCCARD_MODULE
argument_list|(
name|skel
argument_list|,
name|skelinit
argument_list|,
name|skelunload
argument_list|,
name|skelintr
argument_list|,
literal|0
argument_list|,
name|net_imask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|opened
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rather minimal device state... */
end_comment

begin_comment
comment|/*  *	Skeleton driver entry points for PCCARD configuration.  */
end_comment

begin_comment
comment|/*  *	Initialize the device.  */
end_comment

begin_function
specifier|static
name|int
name|skelinit
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
name|devi
parameter_list|)
block|{
name|int
name|unit
init|=
name|devi
operator|->
name|isahd
operator|.
name|id_unit
decl_stmt|;
if|if
condition|(
name|opened
operator|&
operator|(
literal|1
operator|<<
name|unit
operator|)
condition|)
return|return
operator|(
name|EBUSY
operator|)
return|;
name|opened
operator||=
literal|1
operator|<<
name|unit
expr_stmt|;
name|printf
argument_list|(
literal|"%s%d: init\n"
argument_list|,
name|devi
operator|->
name|drv
operator|->
name|name
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s%d: irq %d iobase 0x%x maddr 0x%x memlen %d\n"
argument_list|,
name|devi
operator|->
name|drv
operator|->
name|name
argument_list|,
name|unit
argument_list|,
name|devi
operator|->
name|isahd
operator|.
name|id_irq
argument_list|,
name|devi
operator|->
name|isahd
operator|.
name|id_iobase
argument_list|,
name|devi
operator|->
name|isahd
operator|.
name|id_maddr
argument_list|,
name|devi
operator|->
name|isahd
operator|.
name|id_msize
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	The device entry is being removed. Shut it down,  *	and turn off interrupts etc. Not called unless  *	the device was successfully installed.  */
end_comment

begin_function
specifier|static
name|void
name|skelunload
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
name|devi
parameter_list|)
block|{
name|int
name|unit
init|=
name|devi
operator|->
name|isahd
operator|.
name|id_unit
decl_stmt|;
name|printf
argument_list|(
literal|"%s%d: unload\n"
argument_list|,
name|devi
operator|->
name|drv
operator|->
name|name
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|opened
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|unit
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	Interrupt handler.  *	Returns true if the interrupt is for us.  */
end_comment

begin_function
specifier|static
name|int
name|skelintr
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
name|devi
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

