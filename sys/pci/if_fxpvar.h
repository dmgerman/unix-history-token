begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*                    * Copyright (c) 1995, David Greenman  * All rights reserved.  *                * Modifications to support NetBSD:  * Copyright (c) 1997 Jason R. Thorpe.  All rights reserved.  *                    * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:               * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.    * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Misc. defintions for the Intel EtherExpress Pro/100B PCI Fast  * Ethernet driver  */
end_comment

begin_comment
comment|/*  * NOTE: Elements are ordered for optimal cacheline behavior, and NOT  *	 for functional grouping.  */
end_comment

begin_struct
struct|struct
name|fxp_softc
block|{
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|struct
name|device
name|sc_dev
decl_stmt|;
comment|/* generic device structures */
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt handler cookie */
name|struct
name|ethercom
name|sc_ethercom
decl_stmt|;
comment|/* ethernet common part */
else|#
directive|else
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
endif|#
directive|endif
comment|/* __NetBSD__ */
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
name|int
name|all_mcasts
decl_stmt|;
comment|/* receive all multicasts */
name|struct
name|ifmedia
name|sc_media
decl_stmt|;
comment|/* media information */
name|int
name|phy_primary_addr
decl_stmt|;
comment|/* address of primary PHY */
name|int
name|phy_primary_device
decl_stmt|;
comment|/* device type of primary PHY */
name|int
name|phy_10Mbps_only
decl_stmt|;
comment|/* PHY is 10Mbps-only device */
name|int
name|eeprom_size
decl_stmt|;
comment|/* size of serial EEPROM */
name|int
name|suspended
decl_stmt|;
comment|/* 0 = normal  1 = suspended (APM) */
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

begin_comment
comment|/* Deal with slight differences in software interfaces. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|sc_if
value|sc_ethercom.ec_if
end_define

begin_define
define|#
directive|define
name|FXP_FORMAT
value|"%s"
end_define

begin_define
define|#
directive|define
name|FXP_ARGS
parameter_list|(
name|sc
parameter_list|)
value|(sc)->sc_dev.dv_xname
end_define

begin_define
define|#
directive|define
name|FXP_INTR_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|FXP_IOCTLCMD_TYPE
value|u_long
end_define

begin_define
define|#
directive|define
name|FXP_BPFTAP_ARG
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_bpf
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_define
define|#
directive|define
name|sc_if
value|arpcom.ac_if
end_define

begin_define
define|#
directive|define
name|FXP_FORMAT
value|"fxp%d"
end_define

begin_define
define|#
directive|define
name|FXP_ARGS
parameter_list|(
name|sc
parameter_list|)
value|(sc)->arpcom.ac_if.if_unit
end_define

begin_define
define|#
directive|define
name|FXP_INTR_TYPE
value|void
end_define

begin_define
define|#
directive|define
name|FXP_IOCTLCMD_TYPE
value|u_long
end_define

begin_define
define|#
directive|define
name|FXP_BPFTAP_ARG
parameter_list|(
name|ifp
parameter_list|)
value|ifp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

end_unit

