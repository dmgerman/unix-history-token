begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"sc.h"
end_include

begin_include
include|#
directive|include
file|"opt_syscons.h"
end_include

begin_if
if|#
directive|if
name|NSC
operator|>
literal|0
end_if

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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/console.h>
end_include

begin_include
include|#
directive|include
file|<dev/syscons/syscons.h>
end_include

begin_include
include|#
directive|include
file|<isa/isareg.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_decl_stmt
name|devclass_t
name|sc_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|scprobe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|scattach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|sc_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|scprobe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|scattach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|sc_driver
init|=
block|{
literal|"sc"
block|,
name|sc_methods
block|,
name|DRIVER_TYPE_TTY
block|,
literal|1
block|,
comment|/* XXX */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|scprobe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"System console"
argument_list|)
expr_stmt|;
return|return
name|sc_probe_unit
argument_list|(
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|,
name|isa_get_flags
argument_list|(
name|dev
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|scattach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
name|sc_attach_unit
argument_list|(
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|,
name|isa_get_flags
argument_list|(
name|dev
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|sc
argument_list|,
name|isa
argument_list|,
name|sc_driver
argument_list|,
name|sc_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NSC> 0 */
end_comment

end_unit

