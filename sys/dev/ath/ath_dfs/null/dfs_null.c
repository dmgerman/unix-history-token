begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Adrian Chadd, Xenion Pty Ltd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
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
comment|/*  * This implements an empty DFS module.  */
end_comment

begin_include
include|#
directive|include
file|"opt_inet.h"
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
file|<sys/kernel.h>
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
file|<sys/errno.h>
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
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

begin_comment
comment|/* XXX for ether_sprintf */
end_comment

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

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
file|<dev/ath/if_athdfs.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_desc.h>
end_include

begin_comment
comment|/*  * Methods which are required  */
end_comment

begin_comment
comment|/*  * Attach DFS to the given interface  */
end_comment

begin_function
name|int
name|ath_dfs_attach
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Detach DFS from the given interface  */
end_comment

begin_function
name|int
name|ath_dfs_detach
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Enable radar check  */
end_comment

begin_function
name|void
name|ath_dfs_radar_enable
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
block|{
comment|/* Check if the current channel is radar-enabled */
if|if
condition|(
operator|!
name|IEEE80211_IS_CHAN_DFS
argument_list|(
name|chan
argument_list|)
condition|)
return|return;
block|}
end_function

begin_comment
comment|/*  * Process DFS related PHY errors  */
end_comment

begin_function
name|void
name|ath_dfs_process_phy_err
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|uint64_t
name|tsf
parameter_list|,
name|struct
name|ath_rx_status
modifier|*
name|rxstat
parameter_list|)
block|{  }
end_function

begin_comment
comment|/*  * Process the radar events and determine whether a DFS event has occured.  *  * This is designed to run outside of the RX processing path.  * The RX path will call ath_dfs_tasklet_needed() to see whether  * the task/callback running this routine needs to be called.  */
end_comment

begin_function
name|int
name|ath_dfs_process_radar_event
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Determine whether the the DFS check task needs to be queued.  *  * This is called in the RX task when the current batch of packets  * have been received. It will return whether there are any radar  * events for ath_dfs_process_radar_event() to handle.  */
end_comment

begin_function
name|int
name|ath_dfs_tasklet_needed
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Handle ioctl requests from the diagnostic interface  */
end_comment

begin_function
name|int
name|ath_ioctl_phyerr
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_diag
modifier|*
name|ad
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Get the current DFS thresholds from the HAL  */
end_comment

begin_function
name|int
name|ath_dfs_get_thresholds
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|HAL_PHYERR_PARAM
modifier|*
name|param
parameter_list|)
block|{
name|ath_hal_getdfsthresh
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
name|param
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

