begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 M. Warner Losh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Herb Peyerl.  * 4. The name of Herb Peyerl may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
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
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_include
include|#
directive|include
file|<dev/sn/if_snvar.h>
end_include

begin_function_decl
specifier|static
name|int
name|sn_isa_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|sn_isa_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|sn_isa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|isa_get_logicalid
argument_list|(
name|dev
argument_list|)
condition|)
comment|/* skip PnP probes */
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|sn_probe
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sn_isa_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|sn_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|sc
operator|->
name|pccard_enaddr
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|sn_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|sn_isa_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|sn_isa_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|sn_isa_attach
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
name|sn_isa_driver
init|=
block|{
literal|"sn"
block|,
name|sn_isa_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|sn_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|sn_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|if_sn
argument_list|,
name|isa
argument_list|,
name|sn_isa_driver
argument_list|,
name|sn_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

