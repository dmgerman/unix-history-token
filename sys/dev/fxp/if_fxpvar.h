begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*                    * Copyright (c) 1995, David Greenman  * All rights reserved.  *                * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:               * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.    * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|FXP_LOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|FXP_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|mtx_init
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|mtx_destroy
parameter_list|(
name|a
parameter_list|)
end_define

begin_struct
struct|struct
name|mtx
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_undef
undef|#
directive|undef
name|vtophys
end_undef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|alpha_XXX_dmamap((vm_offset_t)(va))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __alpha__ */
end_comment

begin_comment
comment|/*  * NOTE: Elements are ordered for optimal cacheline behavior, and NOT  *	 for functional grouping.  */
end_comment

begin_struct
struct|struct
name|fxp_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* per-interface network data */
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
comment|/* resource descriptor for registers */
name|int
name|rtp
decl_stmt|;
comment|/* register resource type */
name|int
name|rgd
decl_stmt|;
comment|/* register descriptor in use */
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
comment|/* resource descriptor for interrupt */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handler cookie */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
comment|/* bus space handle */
name|struct
name|mbuf
modifier|*
name|rfa_headm
decl_stmt|;
comment|/* first mbuf in receive frame area */
name|struct
name|mbuf
modifier|*
name|rfa_tailm
decl_stmt|;
comment|/* last mbuf in receive frame area */
name|struct
name|fxp_cb_tx
modifier|*
name|cbl_first
decl_stmt|;
comment|/* first active TxCB in list */
name|int
name|tx_queued
decl_stmt|;
comment|/* # of active TxCB's */
name|int
name|need_mcsetup
decl_stmt|;
comment|/* multicast filter needs programming */
name|struct
name|fxp_cb_tx
modifier|*
name|cbl_last
decl_stmt|;
comment|/* last active TxCB in list */
name|struct
name|fxp_stats
modifier|*
name|fxp_stats
decl_stmt|;
comment|/* Pointer to interface stats */
name|int
name|rx_idle_secs
decl_stmt|;
comment|/* # of seconds RX has been idle */
name|struct
name|callout_handle
name|stat_ch
decl_stmt|;
comment|/* Handle for canceling our stat timeout */
name|struct
name|fxp_cb_tx
modifier|*
name|cbl_base
decl_stmt|;
comment|/* base of TxCB list */
name|struct
name|fxp_cb_mcs
modifier|*
name|mcsp
decl_stmt|;
comment|/* Pointer to mcast setup descriptor */
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
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
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
name|eeprom_size
decl_stmt|;
comment|/* size of serial EEPROM */
name|int
name|suspended
decl_stmt|;
comment|/* 0 = normal  1 = suspended (APM) */
name|int
name|cu_resume_bug
decl_stmt|;
name|int
name|revision
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|u_int32_t
name|saved_maps
index|[
literal|5
index|]
decl_stmt|;
comment|/* pci data */
name|u_int32_t
name|saved_biosaddr
decl_stmt|;
name|u_int8_t
name|saved_intline
decl_stmt|;
name|u_int8_t
name|saved_cachelnsz
decl_stmt|;
name|u_int8_t
name|saved_lattimer
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
define|\
value|bus_space_read_1((sc)->sc_st, (sc)->sc_sh, (reg))
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
define|\
value|bus_space_read_2((sc)->sc_st, (sc)->sc_sh, (reg))
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
define|\
value|bus_space_read_4((sc)->sc_st, (sc)->sc_sh, (reg))
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
define|\
value|bus_space_write_1((sc)->sc_st, (sc)->sc_sh, (reg), (val))
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
define|\
value|bus_space_write_2((sc)->sc_st, (sc)->sc_sh, (reg), (val))
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
define|\
value|bus_space_write_4((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|sc_if
value|arpcom.ac_if
end_define

begin_define
define|#
directive|define
name|FXP_UNIT
parameter_list|(
name|_sc
parameter_list|)
value|(_sc)->arpcom.ac_if.if_unit
end_define

end_unit

