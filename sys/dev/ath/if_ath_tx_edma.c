begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*  * This is needed for register operations which are performed  * by the driver - eg, calls to ath_hal_gettsf32().  *  * It's also required for any AH_DEBUG checks in here, eg the  * module dependencies.  */
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
file|<dev/ath/if_ath_tsf.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_tx.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_sysctl.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_led.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_keycache.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_rx.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_ath_beacon.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_athdfs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_TX99_DIAG
end_ifdef

begin_include
include|#
directive|include
file|<dev/ath/ath_tx99/ath_tx99.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/ath/if_ath_tx_edma.h>
end_include

begin_comment
comment|/*  * some general macros  */
end_comment

begin_define
define|#
directive|define
name|INCR
parameter_list|(
name|_l
parameter_list|,
name|_sz
parameter_list|)
value|(_l) ++; (_l)&= ((_sz) - 1)
end_define

begin_define
define|#
directive|define
name|DECR
parameter_list|(
name|_l
parameter_list|,
name|_sz
parameter_list|)
value|(_l) --; (_l)&= ((_sz) - 1)
end_define

begin_comment
comment|/*  * XXX doesn't belong here, and should be tunable  */
end_comment

begin_define
define|#
directive|define
name|ATH_TXSTATUS_RING_SIZE
value|512
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ATHDEV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Re-initialise the DMA FIFO with the current contents of  * said FIFO.  *  * This should only be called as part of the chip reset path, as it  * assumes the FIFO is currently empty.  *  * TODO: verify that a cold/warm reset does clear the TX FIFO, so  * writing in a partially-filled FIFO will not cause double-entries  * to appear.  */
end_comment

begin_function
specifier|static
name|void
name|ath_edma_dma_restart
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_txq
modifier|*
name|txq
parameter_list|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: called: txq=%p, qnum=%d\n"
argument_list|,
name|__func__
argument_list|,
name|txq
argument_list|,
name|txq
operator|->
name|axq_qnum
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Handoff this frame to the hardware.  *  * For the multicast queue, this will treat it as a software queue  * and append it to the list, after updating the MORE_DATA flag  * in the previous frame.  The cabq processing code will ensure  * that the queue contents gets transferred over.  *  * For the hardware queues, this will queue a frame to the queue  * like before, then populate the FIFO from that.  Since the  * EDMA hardware has 8 FIFO slots per TXQ, this ensures that  * frames such as management frames don't get prematurely dropped.  *  * This does imply that a similar flush-hwq-to-fifoq method will  * need to be called from the processq function, before the  * per-node software scheduler is called.  */
end_comment

begin_function
specifier|static
name|void
name|ath_edma_xmit_handoff
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_txq
modifier|*
name|txq
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: called; bf=%p, txq=%p, qnum=%d\n"
argument_list|,
name|__func__
argument_list|,
name|bf
argument_list|,
name|txq
argument_list|,
name|txq
operator|->
name|axq_qnum
argument_list|)
expr_stmt|;
comment|/* 	 * XXX For now this is a placeholder; free the buffer 	 * and inform the stack that the TX failed. 	 */
name|ath_tx_default_comp
argument_list|(
name|sc
argument_list|,
name|bf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|ath_edma_setup_txfifo
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|int
name|qnum
parameter_list|)
block|{
name|struct
name|ath_tx_edma_fifo
modifier|*
name|te
init|=
operator|&
name|sc
operator|->
name|sc_txedma
index|[
name|qnum
index|]
decl_stmt|;
name|te
operator|->
name|m_fifo
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ath_buf
operator|*
argument_list|)
operator|*
name|HAL_TXFIFO_DEPTH
argument_list|,
name|M_ATHDEV
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
name|te
operator|->
name|m_fifo
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: malloc failed\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
name|ENOMEM
operator|)
return|;
block|}
comment|/* 	 * Set initial "empty" state. 	 */
name|te
operator|->
name|m_fifo_head
operator|=
name|te
operator|->
name|m_fifo_tail
operator|=
name|te
operator|->
name|m_fifo_depth
operator|=
literal|0
expr_stmt|;
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
name|ath_edma_free_txfifo
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|int
name|qnum
parameter_list|)
block|{
name|struct
name|ath_tx_edma_fifo
modifier|*
name|te
init|=
operator|&
name|sc
operator|->
name|sc_txedma
index|[
name|qnum
index|]
decl_stmt|;
comment|/* XXX TODO: actually deref the ath_buf entries? */
name|free
argument_list|(
name|te
operator|->
name|m_fifo
argument_list|,
name|M_ATHDEV
argument_list|)
expr_stmt|;
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
name|ath_edma_dma_txsetup
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|int
name|i
decl_stmt|;
name|error
operator|=
name|ath_descdma_alloc_desc
argument_list|(
name|sc
argument_list|,
operator|&
name|sc
operator|->
name|sc_txsdma
argument_list|,
name|NULL
argument_list|,
literal|"txcomp"
argument_list|,
name|sc
operator|->
name|sc_tx_statuslen
argument_list|,
name|ATH_TXSTATUS_RING_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|ath_hal_setuptxstatusring
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
operator|(
name|void
operator|*
operator|)
name|sc
operator|->
name|sc_txsdma
operator|.
name|dd_desc
argument_list|,
name|sc
operator|->
name|sc_txsdma
operator|.
name|dd_desc_paddr
argument_list|,
name|ATH_TXSTATUS_RING_SIZE
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|HAL_NUM_TX_QUEUES
condition|;
name|i
operator|++
control|)
block|{
name|ath_edma_setup_txfifo
argument_list|(
name|sc
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
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
name|ath_edma_dma_txteardown
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|HAL_NUM_TX_QUEUES
condition|;
name|i
operator|++
control|)
block|{
name|ath_edma_free_txfifo
argument_list|(
name|sc
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
name|ath_descdma_cleanup
argument_list|(
name|sc
argument_list|,
operator|&
name|sc
operator|->
name|sc_txsdma
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
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
name|ath_edma_tx_processq
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_txq
modifier|*
name|txq
parameter_list|,
name|int
name|dosched
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
specifier|static
name|void
name|ath_edma_tx_draintxq
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_txq
modifier|*
name|txq
parameter_list|)
block|{  }
end_function

begin_function
specifier|static
name|void
name|ath_edma_tx_proc
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|npending
parameter_list|)
block|{
name|struct
name|ath_softc
modifier|*
name|sc
init|=
operator|(
expr|struct
name|ath_softc
operator|*
operator|)
name|arg
decl_stmt|;
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"%s: called, npending=%d\n"
argument_list|,
name|__func__
argument_list|,
name|npending
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ath_edma_attach_comp_func
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
block|{
name|TASK_INIT
argument_list|(
operator|&
name|sc
operator|->
name|sc_txtask
argument_list|,
literal|0
argument_list|,
name|ath_edma_tx_proc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ath_xmit_setup_edma
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* Fetch EDMA field and buffer sizes */
operator|(
name|void
operator|)
name|ath_hal_gettxdesclen
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
operator|&
name|sc
operator|->
name|sc_tx_desclen
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ath_hal_gettxstatuslen
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
operator|&
name|sc
operator|->
name|sc_tx_statuslen
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ath_hal_getntxmaps
argument_list|(
name|sc
operator|->
name|sc_ah
argument_list|,
operator|&
name|sc
operator|->
name|sc_tx_nmaps
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"TX descriptor length: %d\n"
argument_list|,
name|sc
operator|->
name|sc_tx_desclen
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"TX status length: %d\n"
argument_list|,
name|sc
operator|->
name|sc_tx_statuslen
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"TX buffers per descriptor: %d\n"
argument_list|,
name|sc
operator|->
name|sc_tx_nmaps
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_tx
operator|.
name|xmit_setup
operator|=
name|ath_edma_dma_txsetup
expr_stmt|;
name|sc
operator|->
name|sc_tx
operator|.
name|xmit_teardown
operator|=
name|ath_edma_dma_txteardown
expr_stmt|;
name|sc
operator|->
name|sc_tx
operator|.
name|xmit_attach_comp_func
operator|=
name|ath_edma_attach_comp_func
expr_stmt|;
name|sc
operator|->
name|sc_tx
operator|.
name|xmit_dma_restart
operator|=
name|ath_edma_dma_restart
expr_stmt|;
name|sc
operator|->
name|sc_tx
operator|.
name|xmit_handoff
operator|=
name|ath_edma_xmit_handoff
expr_stmt|;
name|sc
operator|->
name|sc_tx
operator|.
name|xmit_processq
operator|=
name|ath_edma_tx_processq
expr_stmt|;
name|sc
operator|->
name|sc_tx
operator|.
name|xmit_drainq
operator|=
name|ath_edma_tx_draintxq
expr_stmt|;
block|}
end_function

end_unit

