begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IF_DTSEC_H_
end_ifndef

begin_define
define|#
directive|define
name|IF_DTSEC_H_
end_define

begin_comment
comment|/**  * @group dTSEC common API.  * @{  */
end_comment

begin_define
define|#
directive|define
name|DTSEC_MODE_REGULAR
value|0
end_define

begin_define
define|#
directive|define
name|DTSEC_MODE_INDEPENDENT
value|1
end_define

begin_define
define|#
directive|define
name|DTSEC_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|DTSEC_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|DTSEC_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->sc_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|DTSEC_MII_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mii_lock)
end_define

begin_define
define|#
directive|define
name|DTSEC_MII_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mii_lock)
end_define

begin_enum
enum|enum
name|eth_dev_type
block|{
name|ETH_DTSEC
init|=
literal|0x1
block|,
name|ETH_10GSEC
init|=
literal|0x2
block|}
enum|;
end_enum

begin_struct
struct|struct
name|dtsec_softc
block|{
comment|/* XXX MII bus requires that struct ifnet is first!!! */
name|struct
name|ifnet
modifier|*
name|sc_ifnet
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem
decl_stmt|;
name|struct
name|mtx
name|sc_lock
decl_stmt|;
name|int
name|sc_mode
decl_stmt|;
comment|/* Methods */
name|int
function_decl|(
modifier|*
name|sc_port_rx_init
function_decl|)
parameter_list|(
name|struct
name|dtsec_softc
modifier|*
name|sc
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_port_tx_init
function_decl|)
parameter_list|(
name|struct
name|dtsec_softc
modifier|*
name|sc
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_start_locked
function_decl|)
parameter_list|(
name|struct
name|dtsec_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
comment|/* dTSEC data */
name|enum
name|eth_dev_type
name|sc_eth_dev_type
decl_stmt|;
name|uint8_t
name|sc_eth_id
decl_stmt|;
comment|/* Ethernet ID within its frame manager */
name|uintptr_t
name|sc_mac_mem_offset
decl_stmt|;
name|e_EnetMode
name|sc_mac_enet_mode
decl_stmt|;
name|int
name|sc_mac_mdio_irq
decl_stmt|;
name|uint8_t
name|sc_mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|int
name|sc_port_rx_hw_id
decl_stmt|;
name|int
name|sc_port_tx_hw_id
decl_stmt|;
name|uint32_t
name|sc_port_tx_qman_chan
decl_stmt|;
name|int
name|sc_phy_addr
decl_stmt|;
name|bool
name|sc_hidden
decl_stmt|;
name|device_t
name|sc_mdio
decl_stmt|;
comment|/* Params from fman_bus driver */
name|vm_offset_t
name|sc_fm_base
decl_stmt|;
name|t_Handle
name|sc_fmh
decl_stmt|;
name|t_Handle
name|sc_muramh
decl_stmt|;
name|t_Handle
name|sc_mach
decl_stmt|;
name|t_Handle
name|sc_rxph
decl_stmt|;
name|t_Handle
name|sc_txph
decl_stmt|;
comment|/* MII data */
name|struct
name|mii_data
modifier|*
name|sc_mii
decl_stmt|;
name|device_t
name|sc_mii_dev
decl_stmt|;
name|struct
name|mtx
name|sc_mii_lock
decl_stmt|;
name|struct
name|callout
name|sc_tick_callout
decl_stmt|;
comment|/* RX Pool */
name|t_Handle
name|sc_rx_pool
decl_stmt|;
name|uint8_t
name|sc_rx_bpid
decl_stmt|;
name|uma_zone_t
name|sc_rx_zone
decl_stmt|;
name|char
name|sc_rx_zname
index|[
literal|64
index|]
decl_stmt|;
comment|/* RX Frame Queue */
name|t_Handle
name|sc_rx_fqr
decl_stmt|;
name|uint32_t
name|sc_rx_fqid
decl_stmt|;
comment|/* TX Frame Queue */
name|t_Handle
name|sc_tx_fqr
decl_stmt|;
name|bool
name|sc_tx_fqr_full
decl_stmt|;
name|t_Handle
name|sc_tx_conf_fqr
decl_stmt|;
name|uint32_t
name|sc_tx_conf_fqid
decl_stmt|;
comment|/* Frame Info Zone */
name|uma_zone_t
name|sc_fi_zone
decl_stmt|;
name|char
name|sc_fi_zname
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/**  * @group dTSEC FMan PORT API.  * @{  */
end_comment

begin_enum
enum|enum
name|dtsec_fm_port_params
block|{
name|FM_PORT_LIODN_BASE
init|=
literal|0
block|,
name|FM_PORT_LIODN_OFFSET
init|=
literal|0
block|,
name|FM_PORT_MEM_ID
init|=
literal|0
block|,
name|FM_PORT_MEM_ATTR
init|=
name|MEMORY_ATTR_CACHEABLE
block|,
name|FM_PORT_BUFFER_SIZE
init|=
name|MCLBYTES
block|, }
enum|;
end_enum

begin_function_decl
name|e_FmPortType
name|dtsec_fm_port_rx_type
parameter_list|(
name|enum
name|eth_dev_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtsec_fm_port_rx_exception_callback
parameter_list|(
name|t_Handle
name|app
parameter_list|,
name|e_FmPortExceptions
name|exception
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtsec_fm_port_tx_exception_callback
parameter_list|(
name|t_Handle
name|app
parameter_list|,
name|e_FmPortExceptions
name|exception
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|e_FmPortType
name|dtsec_fm_port_tx_type
parameter_list|(
name|enum
name|eth_dev_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/**  * @group dTSEC bus interface.  * @{  */
end_comment

begin_function_decl
name|int
name|dtsec_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtsec_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtsec_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtsec_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtsec_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtsec_miibus_readreg
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtsec_miibus_writereg
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtsec_miibus_statchg
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_DTSEC_H_ */
end_comment

end_unit

