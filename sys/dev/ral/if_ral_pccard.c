begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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

begin_comment
comment|/*  * CardBus front-end for the Ralink RT2500 driver.  * XXX this is actually a PC Card front end.  Maybe?  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
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
file|<sys/endian.h>
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
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_radiotap.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccardvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccard_cis.h>
end_include

begin_include
include|#
directive|include
file|<dev/ral/if_ralrate.h>
end_include

begin_include
include|#
directive|include
file|<dev/ral/if_ralreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/ral/if_ralvar.h>
end_include

begin_include
include|#
directive|include
file|"card_if.h"
end_include

begin_include
include|#
directive|include
file|"pccarddevs.h"
end_include

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ral
argument_list|,
name|wlan
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|pccard_product
name|ral_pccard_products
index|[]
init|=
block|{
name|PCMCIA_CARD
argument_list|(
name|RALINK
argument_list|,
name|RT2560
argument_list|)
block|,
block|{
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|ral_pccard_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ral_pccard_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|ral_pccard_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ral_pccard_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ral_pccard_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|ral_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|ral_shutdown
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
name|ral_pccard_driver
init|=
block|{
literal|"ral"
block|,
name|ral_pccard_methods
block|,
expr|sizeof
operator|(
expr|struct
name|ral_softc
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ral
argument_list|,
name|pccard
argument_list|,
name|ral_pccard_driver
argument_list|,
name|ral_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|ral_pccard_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
specifier|const
name|struct
name|pccard_product
modifier|*
name|pp
decl_stmt|;
if|if
condition|(
operator|(
name|pp
operator|=
name|pccard_product_lookup
argument_list|(
name|dev
argument_list|,
name|ral_pccard_products
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pccard_product
argument_list|)
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|pp
operator|->
name|pp_name
operator|!=
name|NULL
condition|)
name|device_set_desc
argument_list|(
name|dev
argument_list|,
name|pp
operator|->
name|pp_name
argument_list|)
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
name|ral_pccard_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|ral_alloc
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
name|error
return|;
name|error
operator|=
name|ral_attach
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
name|ral_free
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

end_unit

