begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XLPGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XLPGE_H__
end_define

begin_define
define|#
directive|define
name|NLM_XLPGE_TXQ_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MAC_CRC_LEN
value|4
end_define

begin_enum
enum|enum
name|xlpge_link_state
block|{
name|NLM_LINK_DOWN
block|,
name|NLM_LINK_UP
block|}
enum|;
end_enum

begin_enum
enum|enum
name|xlpge_floctrl_status
block|{
name|NLM_FLOWCTRL_DISABLED
block|,
name|NLM_FLOWCTRL_ENABLED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|nlm_xlp_portdata
block|{
name|struct
name|ifnet
modifier|*
name|xlpge_if
decl_stmt|;
name|struct
name|nlm_xlpge_softc
modifier|*
name|xlpge_sc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nlm_xlpnae_softc
block|{
name|device_t
name|xlpnae_dev
decl_stmt|;
name|int
name|node
decl_stmt|;
comment|/* XLP Node id */
name|uint64_t
name|base
decl_stmt|;
comment|/* NAE IO base */
name|uint64_t
name|poe_base
decl_stmt|;
comment|/* POE IO base */
name|uint64_t
name|poedv_base
decl_stmt|;
comment|/* POE distribution vec IO base */
name|int
name|freq
decl_stmt|;
comment|/* frequency of nae block */
name|int
name|flow_crc_poly
decl_stmt|;
comment|/* Flow CRC16 polynomial */
name|int
name|total_free_desc
decl_stmt|;
comment|/* total for node */
name|int
name|max_ports
decl_stmt|;
name|int
name|total_num_ports
decl_stmt|;
name|int
name|per_port_num_flows
decl_stmt|;
name|u_int
name|nucores
decl_stmt|;
name|u_int
name|nblocks
decl_stmt|;
name|u_int
name|num_complex
decl_stmt|;
name|u_int
name|ncontexts
decl_stmt|;
comment|/*  Ingress side parameters */
name|u_int
name|num_desc
decl_stmt|;
comment|/* no of descriptors in each packet */
name|u_int
name|parser_threshold
decl_stmt|;
comment|/* threshold of entries above which */
comment|/* the parser sequencer is scheduled */
comment|/* NetIOR configs */
name|u_int
name|cmplx_type
index|[
literal|8
index|]
decl_stmt|;
comment|/* XXXJC: redundant? */
name|struct
name|nae_port_config
modifier|*
name|portcfg
decl_stmt|;
name|u_int
name|blockmask
decl_stmt|;
name|u_int
name|portmask
index|[
name|XLP_NAE_NBLOCKS
index|]
decl_stmt|;
name|u_int
name|ilmask
decl_stmt|;
name|u_int
name|xauimask
decl_stmt|;
name|u_int
name|sgmiimask
decl_stmt|;
name|u_int
name|hw_parser_en
decl_stmt|;
name|u_int
name|prepad_en
decl_stmt|;
name|u_int
name|prepad_size
decl_stmt|;
name|u_int
name|driver_mode
decl_stmt|;
name|u_int
name|ieee_1588_en
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nlm_xlpge_softc
block|{
name|struct
name|ifnet
modifier|*
name|xlpge_if
decl_stmt|;
comment|/* should be first member */
comment|/* see - mii.c:miibus_attach() */
name|device_t
name|xlpge_dev
decl_stmt|;
name|device_t
name|mii_bus
decl_stmt|;
name|struct
name|nlm_xlpnae_softc
modifier|*
name|network_sc
decl_stmt|;
name|uint64_t
name|base_addr
decl_stmt|;
comment|/* NAE IO base */
name|int
name|node
decl_stmt|;
comment|/* node id (quickread) */
name|int
name|block
decl_stmt|;
comment|/* network block id (quickread) */
name|int
name|port
decl_stmt|;
comment|/* port id - among the 18 in XLP */
name|int
name|type
decl_stmt|;
comment|/* port type - see xlp_gmac_port_types */
name|int
name|valid
decl_stmt|;
comment|/* boolean: valid port or not */
name|struct
name|mii_data
name|xlpge_mii
decl_stmt|;
name|int
name|nfree_desc
decl_stmt|;
comment|/* No of free descriptors sent to port */
name|int
name|phy_addr
decl_stmt|;
comment|/* PHY id for the interface */
name|int
name|speed
decl_stmt|;
comment|/* Port speed */
name|int
name|duplexity
decl_stmt|;
comment|/* Port duplexity */
name|int
name|link
decl_stmt|;
comment|/* Port link status */
name|int
name|flowctrl
decl_stmt|;
comment|/* Port flow control setting */
name|unsigned
name|char
name|dev_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_lock
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|nae_port_config
modifier|*
name|portcfg
decl_stmt|;
name|struct
name|callout
name|xlpge_callout
decl_stmt|;
name|int
name|mdio_bus
decl_stmt|;
name|int
name|txq
decl_stmt|;
name|int
name|rxfreeq
decl_stmt|;
name|int
name|hw_parser_en
decl_stmt|;
name|int
name|prepad_en
decl_stmt|;
name|int
name|prepad_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XLP_NTXFRAGS
value|16
end_define

begin_define
define|#
directive|define
name|NULL_VFBID
value|127
end_define

begin_struct
struct|struct
name|xlpge_tx_desc
block|{
name|uint64_t
name|frag
index|[
name|XLP_NTXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XLPGE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->sc_lock, _name, MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|XLPGE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|XLPGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|XLPGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|XLPGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_lock, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

