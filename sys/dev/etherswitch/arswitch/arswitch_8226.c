begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Stefan Bethke.  * Copyright (c) 2012 Adrian Chadd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/iic.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iiconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iicbus.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/mdio.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/etherswitch.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitchreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitchvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitch_phy.h>
end_include

begin_include
include|#
directive|include
file|<dev/etherswitch/arswitch/arswitch_8226.h>
end_include

begin_include
include|#
directive|include
file|"mdio_if.h"
end_include

begin_include
include|#
directive|include
file|"miibus_if.h"
end_include

begin_include
include|#
directive|include
file|"etherswitch_if.h"
end_include

begin_comment
comment|/*  * AR8226 specific functions  */
end_comment

begin_function
specifier|static
name|int
name|ar8226_hw_setup
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Initialise other global values, for the AR8226.  */
end_comment

begin_function
specifier|static
name|int
name|ar8226_hw_global_setup
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ar8226_attach
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
block|{
name|sc
operator|->
name|hal
operator|.
name|arswitch_hw_setup
operator|=
name|ar8226_hw_setup
expr_stmt|;
name|sc
operator|->
name|hal
operator|.
name|arswitch_hw_global_setup
operator|=
name|ar8226_hw_global_setup
expr_stmt|;
name|sc
operator|->
name|info
operator|.
name|es_nvlangroups
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

