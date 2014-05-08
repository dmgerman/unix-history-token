begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*  * Driver for the Atheros Wireless LAN controller.  *  * This software is derived from work of Atsushi Onoe; his contribution  * is greatly appreciated.  */
end_comment

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_ath.h"
end_include

begin_comment
comment|/*  * This is needed for register operations which are performed  * by the driver - eg, calls to ath_hal_gettsf32().  */
end_comment

begin_include
include|#
directive|include
file|"opt_ah.h"
end_include

begin_include
include|#
directive|include
file|"opt_wlan.h"
end_include

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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
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
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
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
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_comment
comment|/* for mp_ncpus */
end_comment

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
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
file|<net/if_llc.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_regdomain.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_SUPPORT_SUPERG
end_ifdef

begin_include
include|#
directive|include
file|<net80211/ieee80211_superg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_SUPPORT_TDMA
end_ifdef

begin_include
include|#
directive|include
file|<net80211/ieee80211_tdma.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/ath/if_athvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_devid.h>
end_include

begin_comment
comment|/* XXX for softled */
end_comment

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_diagcodes.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_misc.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_led.h>
end_include

begin_comment
comment|/*  * Software LED driver routines.  */
end_comment

begin_comment
comment|/*  * XXX TODO: move the LED sysctls here.  */
end_comment

begin_comment
comment|/*  * Configure the hardware for software and LED blinking.  * The user may choose to configure part of each, depending upon the  * NIC being used.  *  * This requires the configuration to be set before this function  * is called.  */
end_comment

begin_function
name|void
name|ath_led_config
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
block|{
name|ATH_LOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|ath_power_set_power_state
argument_list|(
name|sc
argument_list|,
name|HAL_PM_AWAKE
argument_list|)
expr_stmt|;
name|ATH_UNLOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Software LED blinking - GPIO controlled LED */
if|if
condition|(
name|sc
operator|->
name|sc_softled
condition|)
block|{
name|ath_hal_gpioCfgOutput
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|sc
operator|->
name|sc_ledpin
argument_list|,
name|HAL_GPIO_OUTPUT_MUX_AS_OUTPUT
argument_list|)
expr_stmt|;
name|ath_hal_gpioset
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|sc
operator|->
name|sc_ledpin
argument_list|,
operator|!
name|sc
operator|->
name|sc_ledon
argument_list|)
expr_stmt|;
block|}
comment|/* Hardware LED blinking - MAC controlled LED */
if|if
condition|(
name|sc
operator|->
name|sc_hardled
condition|)
block|{
comment|/* 		 * Only enable each LED if required. 		 * 		 * Some NICs only have one LED connected; others may 		 * have GPIO1/GPIO2 connected to other hardware. 		 */
if|if
condition|(
name|sc
operator|->
name|sc_led_pwr_pin
operator|>
literal|0
condition|)
name|ath_hal_gpioCfgOutput
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|sc
operator|->
name|sc_led_pwr_pin
argument_list|,
name|HAL_GPIO_OUTPUT_MUX_MAC_POWER_LED
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_led_net_pin
operator|>
literal|0
condition|)
name|ath_hal_gpioCfgOutput
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|sc
operator|->
name|sc_led_net_pin
argument_list|,
name|HAL_GPIO_OUTPUT_MUX_MAC_NETWORK_LED
argument_list|)
expr_stmt|;
block|}
name|ATH_LOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|ath_power_restore_power_state
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|ATH_UNLOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ath_led_done
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|ath_softc
modifier|*
name|sc
init|=
name|arg
decl_stmt|;
name|sc
operator|->
name|sc_blinking
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Turn the LED off: flip the pin and then set a timer so no  * update will happen for the specified duration.  */
end_comment

begin_function
specifier|static
name|void
name|ath_led_off
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|ath_softc
modifier|*
name|sc
init|=
name|arg
decl_stmt|;
name|ath_hal_gpioset
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|sc
operator|->
name|sc_ledpin
argument_list|,
operator|!
name|sc
operator|->
name|sc_ledon
argument_list|)
expr_stmt|;
name|callout_reset
argument_list|(
operator|&
name|sc
operator|->
name|sc_ledtimer
argument_list|,
name|sc
operator|->
name|sc_ledoff
argument_list|,
name|ath_led_done
argument_list|,
name|sc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Blink the LED according to the specified on/off times.  */
end_comment

begin_function
specifier|static
name|void
name|ath_led_blink
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|int
name|on
parameter_list|,
name|int
name|off
parameter_list|)
block|{
name|DPRINTF
argument_list|(
name|sc
argument_list|,
name|ATH_DEBUG_LED
argument_list|,
literal|"%s: on %u off %u\n"
argument_list|,
name|__func__
argument_list|,
name|on
argument_list|,
name|off
argument_list|)
expr_stmt|;
name|ath_hal_gpioset
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|sc
operator|->
name|sc_ledpin
argument_list|,
name|sc
operator|->
name|sc_ledon
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_blinking
operator|=
literal|1
expr_stmt|;
name|sc
operator|->
name|sc_ledoff
operator|=
name|off
expr_stmt|;
name|callout_reset
argument_list|(
operator|&
name|sc
operator|->
name|sc_ledtimer
argument_list|,
name|on
argument_list|,
name|ath_led_off
argument_list|,
name|sc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ath_led_event
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|int
name|rix
parameter_list|)
block|{
name|sc
operator|->
name|sc_ledevent
operator|=
name|ticks
expr_stmt|;
comment|/* time of last event */
if|if
condition|(
name|sc
operator|->
name|sc_blinking
condition|)
comment|/* don't interrupt active blink */
return|return;
name|ath_led_blink
argument_list|(
name|sc
argument_list|,
name|sc
operator|->
name|sc_hwmap
index|[
name|rix
index|]
operator|.
name|ledon
argument_list|,
name|sc
operator|->
name|sc_hwmap
index|[
name|rix
index|]
operator|.
name|ledoff
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

