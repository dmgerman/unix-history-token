begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Harti Brandt.  * Copyright (c) 2003 Vincent Jardin.  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Supported AALs  */
end_comment

begin_enum
enum|enum
name|vatmpif_aal
block|{
name|VATMPIF_AAL_0
init|=
literal|0
block|,
comment|/* Cell Service */
name|VATMPIF_AAL_4
init|=
literal|4
block|,
comment|/* AAL 3/4 */
name|VATMPIF_AAL_5
init|=
literal|5
block|,
comment|/* AAL 5 */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|vatmpif_aal
name|Vatmpif_aal
typedef|;
end_typedef

begin_comment
comment|/*  * Supported traffic type  */
end_comment

begin_enum
enum|enum
name|vatmpif_traffic_type
block|{
name|VATMPIF_TRAF_CBR
init|=
literal|0x01
block|,
comment|/* Constant bit rate */
name|VATMPIF_TRAF_VBR
init|=
literal|0x02
block|,
comment|/* Variable bit rate */
name|VATMPIF_TRAF_ABR
init|=
literal|0x03
block|,
comment|/* Available Bit Rate */
name|VATMPIF_TRAF_UBR
init|=
literal|0x04
block|,
comment|/* Unspecified bit rate */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|vatmpif_traffic_type
name|Vatmpif_traffic_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|t_atm_traffic
name|Vatmpif_traffic
typedef|;
end_typedef

begin_comment
comment|/*  * Host protocol control blocks  *   */
end_comment

begin_comment
comment|/*  * Device VCC Entry  *   * Contains the common (vv_cmn) and specific information for each VCC  * which is opened through a ATM PIF node.  * It is a virtual VCC. From the Netgraph poit of view it is a  * per-node's hook private data.  *  * It is a polymorph object with the instances of Cmn_vcc.  */
end_comment

begin_struct
struct|struct
name|vatmpif_vcc
block|{
name|Cmn_vcc
name|vv_cmn
decl_stmt|;
comment|/* Common VCC stuff */
name|Vatmpif_aal
name|vv_aal
decl_stmt|;
comment|/* AAL */
name|Vatmpif_traffic
name|vv_traffic
decl_stmt|;
comment|/* forward and backward ATM traffic */
name|Vatmpif_traffic_type
name|vv_traffic_type
decl_stmt|;
comment|/* CBR, VBR, UBR, ... */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vatmpif_vcc
name|Vatmpif_vcc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vv_next
value|vv_cmn.cv_next
end_define

begin_define
define|#
directive|define
name|vv_toku
value|vv_cmn.cv_toku
end_define

begin_define
define|#
directive|define
name|vv_upper
value|vv_cmn.cv_upper
end_define

begin_define
define|#
directive|define
name|vv_connvc
value|vv_cmn.cv_connvc
end_define

begin_define
define|#
directive|define
name|vv_state
value|vv_cmn.cv_state
end_define

begin_comment
comment|/*  * The hook structure describes a virtual link  */
end_comment

begin_struct
struct|struct
name|ng_vatmpif_hook
block|{
name|hook_p
name|hook
decl_stmt|;
comment|/* netgraph hook */
name|Vatmpif_stats
name|stats
decl_stmt|;
comment|/* link stats */
name|uint32_t
name|InSeq
decl_stmt|;
comment|/* last received sequence number + 1 */
name|uint32_t
name|OutSeq
decl_stmt|;
comment|/* last sent sequence number */
name|uint32_t
name|cur_pcr
decl_stmt|;
comment|/* slot's reserved PCR */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Device Virtual Unit Structure  *   * Contains all the information for a single device (adapter).  * It is a virtual device. From the Netgraph point of view it is  * a per-node private data.  *  * It is a polymorph object with the instances of Cmn_unit.  */
end_comment

begin_struct
struct|struct
name|vatmpif_unit
block|{
name|Cmn_unit
name|vu_cmn
decl_stmt|;
comment|/* Common unit stuff */
name|node_p
name|node
decl_stmt|;
comment|/* netgraph node */
name|struct
name|ng_vatmpif_hook
modifier|*
name|link
decl_stmt|;
comment|/* virtual link hoook */
name|struct
name|ng_vatmpif_config
name|conf
decl_stmt|;
comment|/* node configuration */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vatmpif_unit
name|Vatmpif_unit
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ng_vatmpif_private
value|vatmpif_unit
end_define

begin_typedef
typedef|typedef
name|struct
name|ng_vatmpif_private
modifier|*
name|priv_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vu_pif
value|vu_cmn.cu_pif
end_define

begin_define
define|#
directive|define
name|vu_unit
value|vu_cmn.cu_unit
end_define

begin_define
define|#
directive|define
name|vu_flags
value|vu_cmn.cu_flags
end_define

begin_define
define|#
directive|define
name|vu_mtu
value|vu_cmn.cu_mtu
end_define

begin_define
define|#
directive|define
name|vu_open_vcc
value|vu_cmn.cu_open_vcc
end_define

begin_define
define|#
directive|define
name|vu_vcc
value|vu_cmn.cu_vcc
end_define

begin_define
define|#
directive|define
name|vu_vcc_zone
value|vu_cmn.cu_vcc_zone
end_define

begin_define
define|#
directive|define
name|vu_nif_zone
value|vu_cmn.cu_nif_zone
end_define

begin_define
define|#
directive|define
name|vu_ioctl
value|vu_cmn.cu_ioctl
end_define

begin_define
define|#
directive|define
name|vu_instvcc
value|vu_cmn.cu_instvcc
end_define

begin_define
define|#
directive|define
name|vu_openvcc
value|vu_cmn.cu_openvcc
end_define

begin_define
define|#
directive|define
name|vu_closevcc
value|vu_cmn.cu_closevcc
end_define

begin_define
define|#
directive|define
name|vu_output
value|vu_cmn.cu_output
end_define

begin_define
define|#
directive|define
name|vu_config
value|vu_cmn.cu_config
end_define

begin_define
define|#
directive|define
name|vu_softc
value|vu_cmn.cu_softc
end_define

begin_define
define|#
directive|define
name|vu_stats
value|link->stats
end_define

begin_define
define|#
directive|define
name|vu_cur_pcr
value|link->cur_pcr
end_define

begin_comment
comment|/*  * Netgraph to HARP API  */
end_comment

begin_function_decl
name|int
name|vatmpif_harp_attach
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatmpif_harp_detach
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatmpif_harp_recv_drain
parameter_list|(
name|Vatmpif_unit
modifier|*
name|vup
parameter_list|,
name|KBuffer
modifier|*
name|m
parameter_list|,
name|uint8_t
name|vpi
parameter_list|,
name|uint16_t
name|vci
parameter_list|,
name|uint8_t
name|pt
parameter_list|,
name|uint8_t
name|clp
parameter_list|,
name|Vatmpif_aal
name|aal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * HARP to Netgraph API  */
end_comment

begin_function_decl
name|int
name|ng_atmpif_transmit
parameter_list|(
specifier|const
name|priv_p
name|priv
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint8_t
name|vpi
parameter_list|,
name|uint16_t
name|vci
parameter_list|,
name|uint8_t
name|pt
parameter_list|,
name|uint8_t
name|clp
parameter_list|,
name|Vatmpif_aal
name|aal
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|vatmpif_nif_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|vatmpif_vcc_zone
decl_stmt|;
end_decl_stmt

end_unit

