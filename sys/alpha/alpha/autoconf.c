begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: autoconf.c,v 1.7 1998/08/20 08:27:10 dfr Exp $  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/diskslice.h>
end_include

begin_comment
comment|/* for BASE_SLICE, MAX_SLICES */
end_comment

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cons.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|"scbus.h"
end_include

begin_decl_stmt
specifier|static
name|void
name|configure
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|SYSINIT
argument_list|(
argument|configure
argument_list|,
argument|SI_SUB_CONFIGURE
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|configure
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_decl_stmt
specifier|static
name|void
name|configure_finish
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|configure_start
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|device_t
name|isa_bus_device
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xpt_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|configure_start
parameter_list|()
block|{
if|#
directive|if
name|NSCBUS
operator|>
literal|0
name|xpt_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|void
name|configure_finish
parameter_list|()
block|{ }
end_function

begin_function_decl
specifier|extern
name|void
name|pci_configure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Determine i/o configuration for a machine.  */
end_comment

begin_function
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|configure_start
argument_list|()
expr_stmt|;
name|device_add_child
argument_list|(
name|root_bus
argument_list|,
name|platform
operator|.
name|iobus
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|root_bus_configure
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|hwrpb
operator|->
name|rpb_type
operator|!=
name|ST_DEC_3000_300
operator|)
operator|&&
operator|(
name|hwrpb
operator|->
name|rpb_type
operator|!=
name|ST_DEC_3000_500
operator|)
condition|)
block|{
name|pci_configure
argument_list|()
expr_stmt|;
comment|/* 		 * Probe ISA devices after everything. 		 */
name|bus_generic_attach
argument_list|(
name|isa_bus_device
argument_list|)
expr_stmt|;
block|}
name|configure_finish
argument_list|()
expr_stmt|;
name|cninit_finish
argument_list|()
expr_stmt|;
comment|/* 	 * Now we're ready to handle (pending) interrupts. 	 * XXX this is slightly misplaced. 	 */
name|spl0
argument_list|()
expr_stmt|;
name|cold
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_rootconf
parameter_list|()
block|{
specifier|static
name|char
name|rootname
index|[]
init|=
literal|"da0a"
decl_stmt|;
name|mountrootfsname
operator|=
literal|"ufs"
expr_stmt|;
name|rootdevs
index|[
literal|0
index|]
operator|=
name|rootdev
expr_stmt|;
name|rootname
index|[
literal|2
index|]
operator|+=
name|dkunit
argument_list|(
name|rootdev
argument_list|)
expr_stmt|;
name|rootdevnames
index|[
literal|0
index|]
operator|=
name|rootname
expr_stmt|;
name|rootdevs
index|[
literal|1
index|]
operator|=
name|makedev
argument_list|(
literal|4
argument_list|,
name|dkmakeminor
argument_list|(
literal|0
argument_list|,
name|COMPATIBILITY_SLICE
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|rootdevnames
index|[
literal|1
index|]
operator|=
literal|"da0a"
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_dumpconf
parameter_list|()
block|{ }
end_function

end_unit

