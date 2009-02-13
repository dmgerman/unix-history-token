begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995, David Greenman  * All rights reserved.  *                * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:               * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.    * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Misc. defintions for the Intel EtherExpress Pro/100B PCI Fast  * Ethernet driver  */
end_comment

begin_comment
comment|/*  * Number of transmit control blocks. This determines the number  * of transmit buffers that can be chained in the CB list.  * This must be a power of two.  */
end_comment

begin_define
define|#
directive|define
name|FXP_NTXCB
value|128
end_define

begin_comment
comment|/*  * Size of the TxCB list.  */
end_comment

begin_define
define|#
directive|define
name|FXP_TXCB_SZ
value|(FXP_NTXCB * sizeof(struct fxp_cb_tx))
end_define

begin_comment
comment|/*  * Macro to obtain the DMA address of a virtual address in the  * TxCB list based on the base DMA address of the TxCB list.  */
end_comment

begin_define
define|#
directive|define
name|FXP_TXCB_DMA_ADDR
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|)
define|\
value|(sc->fxp_desc.cbl_addr + (uintptr_t)addr -			\ 	(uintptr_t)sc->fxp_desc.cbl_list)
end_define

begin_comment
comment|/*  * Number of completed TX commands at which point an interrupt  * will be generated to garbage collect the attached buffers.  * Must be at least one less than FXP_NTXCB, and should be  * enough less so that the transmitter doesn't becomes idle  * during the buffer rundown (which would reduce performance).  */
end_comment

begin_define
define|#
directive|define
name|FXP_CXINT_THRESH
value|120
end_define

begin_comment
comment|/*  * TxCB list index mask. This is used to do list wrap-around.  */
end_comment

begin_define
define|#
directive|define
name|FXP_TXCB_MASK
value|(FXP_NTXCB - 1)
end_define

begin_comment
comment|/*  * Number of receive frame area buffers. These are large so chose  * wisely.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEVICE_POLLING
end_ifdef

begin_define
define|#
directive|define
name|FXP_NRFABUFS
value|192
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FXP_NRFABUFS
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Maximum number of seconds that the receiver can be idle before we  * assume it's dead and attempt to reset it by reprogramming the  * multicast filter. This is part of a work-around for a bug in the  * NIC. See fxp_stats_update().  */
end_comment

begin_define
define|#
directive|define
name|FXP_MAX_RX_IDLE
value|15
end_define

begin_comment
comment|/*  * Default maximum time, in microseconds, that an interrupt may be delayed  * in an attempt to coalesce interrupts.  This is only effective if the Intel   * microcode is loaded, and may be changed via either loader tunables or  * sysctl.  See also the CPUSAVER_DWORD entry in rcvbundl.h.  */
end_comment

begin_define
define|#
directive|define
name|TUNABLE_INT_DELAY
value|1000
end_define

begin_comment
comment|/*  * Default number of packets that will be bundled, before an interrupt is   * generated.  This is only effective if the Intel microcode is loaded, and  * may be changed via either loader tunables or sysctl.  This may not be   * present in all microcode revisions, see also the CPUSAVER_BUNDLE_MAX_DWORD  * entry in rcvbundl.h.  */
end_comment

begin_define
define|#
directive|define
name|TUNABLE_BUNDLE_MAX
value|6
end_define

begin_define
define|#
directive|define
name|FXP_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|FXP_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|FXP_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|_what
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, (_what))
end_define

begin_comment
comment|/*  * Structures to handle TX and RX descriptors.  */
end_comment

begin_struct
struct|struct
name|fxp_rx
block|{
name|struct
name|fxp_rx
modifier|*
name|rx_next
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rx_mbuf
decl_stmt|;
name|bus_dmamap_t
name|rx_map
decl_stmt|;
name|uint32_t
name|rx_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fxp_tx
block|{
name|struct
name|fxp_tx
modifier|*
name|tx_next
decl_stmt|;
name|struct
name|fxp_cb_tx
modifier|*
name|tx_cb
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tx_mbuf
decl_stmt|;
name|bus_dmamap_t
name|tx_map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fxp_desc_list
block|{
name|struct
name|fxp_rx
name|rx_list
index|[
name|FXP_NRFABUFS
index|]
decl_stmt|;
name|struct
name|fxp_tx
name|tx_list
index|[
name|FXP_NTXCB
index|]
decl_stmt|;
name|struct
name|fxp_tx
name|mcs_tx
decl_stmt|;
name|struct
name|fxp_rx
modifier|*
name|rx_head
decl_stmt|;
name|struct
name|fxp_rx
modifier|*
name|rx_tail
decl_stmt|;
name|struct
name|fxp_tx
modifier|*
name|tx_first
decl_stmt|;
name|struct
name|fxp_tx
modifier|*
name|tx_last
decl_stmt|;
name|struct
name|fxp_rfa
modifier|*
name|rfa_list
decl_stmt|;
name|struct
name|fxp_cb_tx
modifier|*
name|cbl_list
decl_stmt|;
name|uint32_t
name|cbl_addr
decl_stmt|;
name|bus_dma_tag_t
name|rx_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NOTE: Elements are ordered for optimal cacheline behavior, and NOT  *	 for functional grouping.  */
end_comment

begin_struct
struct|struct
name|fxp_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* per-interface network data */
name|struct
name|resource
modifier|*
name|fxp_res
index|[
literal|2
index|]
decl_stmt|;
comment|/* I/O and IRQ resources */
name|struct
name|resource_spec
modifier|*
name|fxp_spec
decl_stmt|;
comment|/* the resource spec we used */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handler cookie */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|bus_dma_tag_t
name|fxp_mtag
decl_stmt|;
comment|/* bus DMA tag for mbufs */
name|bus_dma_tag_t
name|fxp_stag
decl_stmt|;
comment|/* bus DMA tag for stats */
name|bus_dmamap_t
name|fxp_smap
decl_stmt|;
comment|/* bus DMA map for stats */
name|bus_dma_tag_t
name|cbl_tag
decl_stmt|;
comment|/* DMA tag for the TxCB list */
name|bus_dmamap_t
name|cbl_map
decl_stmt|;
comment|/* DMA map for the TxCB list */
name|bus_dma_tag_t
name|mcs_tag
decl_stmt|;
comment|/* DMA tag for the multicast setup */
name|bus_dmamap_t
name|mcs_map
decl_stmt|;
comment|/* DMA map for the multicast setup */
name|bus_dmamap_t
name|spare_map
decl_stmt|;
comment|/* spare DMA map */
name|struct
name|fxp_desc_list
name|fxp_desc
decl_stmt|;
comment|/* descriptors management struct */
name|int
name|maxtxseg
decl_stmt|;
comment|/* maximum # of TX segments */
name|int
name|tx_queued
decl_stmt|;
comment|/* # of active TxCB's */
name|int
name|need_mcsetup
decl_stmt|;
comment|/* multicast filter needs programming */
name|struct
name|fxp_stats
modifier|*
name|fxp_stats
decl_stmt|;
comment|/* Pointer to interface stats */
name|uint32_t
name|stats_addr
decl_stmt|;
comment|/* DMA address of the stats structure */
name|int
name|rx_idle_secs
decl_stmt|;
comment|/* # of seconds RX has been idle */
name|struct
name|callout
name|stat_ch
decl_stmt|;
comment|/* stat callout */
name|int
name|watchdog_timer
decl_stmt|;
comment|/* seconds until chip reset */
name|struct
name|fxp_cb_mcs
modifier|*
name|mcsp
decl_stmt|;
comment|/* Pointer to mcast setup descriptor */
name|uint32_t
name|mcs_addr
decl_stmt|;
comment|/* DMA address of the multicast cmd */
name|struct
name|ifmedia
name|sc_media
decl_stmt|;
comment|/* media information */
name|device_t
name|miibus
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|int
name|tunable_int_delay
decl_stmt|;
comment|/* interrupt delay value for ucode */
name|int
name|tunable_bundle_max
decl_stmt|;
comment|/* max # frames per interrupt (ucode) */
name|int
name|tunable_noflow
decl_stmt|;
comment|/* flow control disabled */
name|int
name|rnr
decl_stmt|;
comment|/* RNR events */
name|int
name|eeprom_size
decl_stmt|;
comment|/* size of serial EEPROM */
name|int
name|suspended
decl_stmt|;
comment|/* 0 = normal  1 = suspended or dead */
name|int
name|cu_resume_bug
decl_stmt|;
name|int
name|revision
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|uint8_t
name|rfa_size
decl_stmt|;
name|uint32_t
name|tx_cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FXP_FLAG_MWI_ENABLE
value|0x0001
end_define

begin_comment
comment|/* MWI enable */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_READ_ALIGN
value|0x0002
end_define

begin_comment
comment|/* align read access with cacheline */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_WRITE_ALIGN
value|0x0004
end_define

begin_comment
comment|/* end write on cacheline */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_EXT_TXCB
value|0x0008
end_define

begin_comment
comment|/* enable use of extended TXCB */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_SERIAL_MEDIA
value|0x0010
end_define

begin_comment
comment|/* 10Mbps serial interface */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_LONG_PKT_EN
value|0x0020
end_define

begin_comment
comment|/* enable long packet reception */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_ALL_MCAST
value|0x0040
end_define

begin_comment
comment|/* accept all multicast frames */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_CU_RESUME_BUG
value|0x0080
end_define

begin_comment
comment|/* requires workaround for CU_RESUME */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_UCODE
value|0x0100
end_define

begin_comment
comment|/* ucode is loaded */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_DEFERRED_RNR
value|0x0200
end_define

begin_comment
comment|/* DEVICE_POLLING deferred RNR */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_EXT_RFA
value|0x0400
end_define

begin_comment
comment|/* extended RFDs for csum offload */
end_comment

begin_define
define|#
directive|define
name|FXP_FLAG_SAVE_BAD
value|0x0800
end_define

begin_comment
comment|/* save bad pkts: bad size, CRC, etc */
end_comment

begin_comment
comment|/* Macros to ease CSR access. */
end_comment

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_1(sc->fxp_res[0], reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_2(sc->fxp_res[0], reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4(sc->fxp_res[0], reg)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_1(sc->fxp_res[0], reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_2(sc->fxp_res[0], reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4(sc->fxp_res[0], reg, val)
end_define

end_unit

