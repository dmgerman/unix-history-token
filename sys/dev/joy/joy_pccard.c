begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Jean-Marc Zucconi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/joy/joyvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccardreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccardvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccarddevs.h>
end_include

begin_function
specifier|static
name|int
name|joy_pccard_match
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
comment|/* For the moment, don't match anything :-) */
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|joy_pccard_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|pccard_compat_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|pccard_compat_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|joy_detach
argument_list|)
block|,
comment|/* Card interface */
name|DEVMETHOD
argument_list|(
name|card_compat_match
argument_list|,
name|joy_pccard_match
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|card_compat_probe
argument_list|,
name|joy_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|card_compat_attach
argument_list|,
name|joy_attach
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
name|joy_pccard_driver
init|=
block|{
literal|"joy"
block|,
name|joy_pccard_methods
block|,
expr|sizeof
operator|(
expr|struct
name|joy_softc
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|joy
argument_list|,
name|pccard
argument_list|,
name|joy_pccard_driver
argument_list|,
name|joy_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

