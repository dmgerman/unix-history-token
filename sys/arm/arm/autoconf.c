begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)autoconf.c	7.1 (Berkeley) 5/9/91  * from: FreeBSD: src/sys/i386/i386/autoconf.c,v 1.156  */
end_comment

begin_comment
comment|/*  * Setup the system to run on the current machine.  *  * Configure() is called at boot time and initializes the vba  * device tables and the memory controller monitoring.  Available  * devices are determined (from possibilities mentioned in ioconf.c),  * and the drivers are initialized.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_function_decl
specifier|static
name|void
name|configure_first
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|configure
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|configure_final
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure1
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|configure_first
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SI_ORDER_SECOND is hookable */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure2
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_THIRD
argument_list|,
name|configure
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SI_ORDER_MIDDLE is hookable */
end_comment

begin_expr_stmt
name|SYSINIT
argument_list|(
name|configure3
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|configure_final
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|device_t
name|nexus_dev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Determine i/o configuration for a machine.  */
end_comment

begin_function
specifier|static
name|void
name|configure_first
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|device_add_child
argument_list|(
name|root_bus
argument_list|,
literal|"nexus"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

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
name|root_bus_configure
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|configure_final
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|cninit_finish
argument_list|()
expr_stmt|;
name|cold
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

