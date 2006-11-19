begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Sam Leffler.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXP425_NPEVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXP425_NPEVAR_H_
end_define

begin_comment
comment|/*  * Intel (R) IXP400 Software NPE Image ID Definition  *  * Firmware Id's for current firmware image.  These are typed by  * NPE ID and the feature set.  Not all features are available  * on all NPE's.  *  * HSS-0: supports 32 channelized and 4 packetized.  * HSS-0 + ATM + SPHY:  *    For HSS, 16/32 channelized and 4/0 packetized.  *    For ATM, AAL5, AAL0 and OAM for UTOPIA SPHY, 1 logical port, 32 VCs.  *    Fast Path support.  * HSS-0 + ATM + MPHY:  *    For HSS, 16/32 channelized and 4/0 packetized.  *    For ATM, AAL5, AAL0 and OAM for UTOPIA MPHY, 1 logical port, 32 VCs.  *    Fast Path support.  * ATM-Only:  *    AAL5, AAL0 and OAM for UTOPIA MPHY, 12 logical ports, 32 VCs.  *    Fast Path support.  * HSS-2:  *    HSS-0 and HSS-1.  *    Each HSS port supports 32 channelized and 4 packetized.  * ETH: Ethernet Rx/Tx which includes:  *    MAC_FILTERING, MAC_LEARNING, SPANNING_TREE, FIREWALL  * ETH+VLAN Ethernet Rx/Tx which includes:  *    MAC_FILTERING, MAC_LEARNING, SPANNING_TREE, FIREWALL, VLAN_QOS  * ETH+VLAN+HDR: Ethernet Rx/Tx which includes:  *    SPANNING_TREE, FIREWALL, VLAN_QOS, HEADER_CONVERSION  */
end_comment

begin_comment
comment|/* XXX not right, revise */
end_comment

begin_comment
comment|/* NPE A Firmware Image Id's */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_HSS0
value|0x00010000
end_define

begin_comment
comment|/* HSS-0: 32 chan+4 packet */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_HSS0_ATM_S_1
value|0x00020000
end_define

begin_comment
comment|/* HSS-0+ATM UTOPIA SPHY (1 port) */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_HSS0_ATM_M_1
value|0x00020000
end_define

begin_comment
comment|/* HSS-0+ATM UTOPIA MPHY (1 port) */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_ATM_M_12
value|0x00040000
end_define

begin_comment
comment|/* ATM UTOPIA MPHY (12 ports) */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_DMA
value|0x00150100
end_define

begin_comment
comment|/* DMA only */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_HSS2
value|0x00090000
end_define

begin_comment
comment|/* HSS-0 + HSS-1 */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_ETH
value|0x10800200
end_define

begin_comment
comment|/* Basic Ethernet */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_ETH_VLAN
value|0x10810200
end_define

begin_comment
comment|/* NPEFW_A_ETH + VLAN QoS */
end_comment

begin_define
define|#
directive|define
name|NPEFW_A_ETH_VLAN_HDR
value|0x10820200
end_define

begin_comment
comment|/* NPEFW_A_ETH_VLAN + Hdr conv */
end_comment

begin_comment
comment|/* XXX ... more not included */
end_comment

begin_comment
comment|/* NPE B Firmware Image Id's */
end_comment

begin_define
define|#
directive|define
name|NPEFW_B_ETH
value|0x01000200
end_define

begin_comment
comment|/* Basic Ethernet */
end_comment

begin_define
define|#
directive|define
name|NPEFW_B_ETH_VLAN
value|0x01010200
end_define

begin_comment
comment|/* NPEFW_B_ETH + VLAN QoS */
end_comment

begin_define
define|#
directive|define
name|NPEFW_B_ETH_VLAN_HDR
value|0x01020201
end_define

begin_comment
comment|/* NPEFW_B_ETH_VLAN + Hdr conv */
end_comment

begin_define
define|#
directive|define
name|NPEFW_B_DMA
value|0x01020100
end_define

begin_comment
comment|/* DMA only */
end_comment

begin_comment
comment|/* XXX ... more not include */
end_comment

begin_define
define|#
directive|define
name|IXP425_NPE_B_IMAGEID
value|0x01000200
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_C_IMAGEID
value|0x02000200
end_define

begin_struct_decl
struct_decl|struct
name|ixpnpe_softc
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ixpnpe_softc
modifier|*
name|ixpnpe_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixpnpe_detach
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_stopandreset
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_start
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_stop
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_init
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|imageName
parameter_list|,
name|uint32_t
name|imageId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_getfunctionality
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_sendmsg
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|,
specifier|const
name|uint32_t
name|msg
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_recvmsg
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|,
name|uint32_t
name|msg
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpnpe_sendandrecvmsg
parameter_list|(
name|struct
name|ixpnpe_softc
modifier|*
parameter_list|,
specifier|const
name|uint32_t
name|send
index|[
literal|2
index|]
parameter_list|,
name|uint32_t
name|recv
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXP425_NPEVAR_H_ */
end_comment

end_unit

