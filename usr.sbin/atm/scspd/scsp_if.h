begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * Interface to server clients of SCSP  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSP_SCSP_IF_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSP_SCSP_IF_H
end_define

begin_comment
comment|/*  * SCSP configuration message  */
end_comment

begin_struct
struct|struct
name|scsp_cfg_msg
block|{
name|char
name|atmarp_netif
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_cfg_msg
name|Scsp_cfg_msg
typedef|;
end_typedef

begin_comment
comment|/*  * SCSP cache summary  */
end_comment

begin_struct
struct|struct
name|scsp_sum_msg
block|{
name|u_short
name|ss_hops
decl_stmt|;
comment|/* Hop count */
name|u_char
name|ss_null
decl_stmt|;
comment|/* Null flag */
name|long
name|ss_seq
decl_stmt|;
comment|/* CSA seq. no. */
name|Scsp_ckey
name|ss_key
decl_stmt|;
comment|/* Cache key */
name|Scsp_id
name|ss_oid
decl_stmt|;
comment|/* Originator ID */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_sum_msg
name|Scsp_sum_msg
typedef|;
end_typedef

begin_comment
comment|/*  * SCSP constants for ATMARP  */
end_comment

begin_define
define|#
directive|define
name|SCSP_ATMARP_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_ATMARP_SIDL
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_ATMARP_RIDL
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_ATMARP_CKL
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_ATMARP_OIDL
value|4
end_define

begin_comment
comment|/*  * SCSP ATMARP message  */
end_comment

begin_struct
struct|struct
name|scsp_atmarp_msg
block|{
name|u_char
name|sa_state
decl_stmt|;
comment|/* Cache entry state (below) */
name|struct
name|in_addr
name|sa_cpa
decl_stmt|;
comment|/* Cached protocol address */
name|Atm_addr
name|sa_cha
decl_stmt|;
comment|/* Cached ATM address */
name|Atm_addr
name|sa_csa
decl_stmt|;
comment|/* Cached ATM subaddress */
name|Scsp_ckey
name|sa_key
decl_stmt|;
comment|/* Cache key for entry */
name|Scsp_id
name|sa_oid
decl_stmt|;
comment|/* Originator ID */
name|long
name|sa_seq
decl_stmt|;
comment|/* Sequence no. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_atmarp_msg
name|Scsp_atmarp_msg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCSP_ASTATE_NEW
value|0
end_define

begin_comment
comment|/* ATMARP new server registration */
end_comment

begin_define
define|#
directive|define
name|SCSP_ASTATE_UPD
value|1
end_define

begin_comment
comment|/* ATMARP server refreshed */
end_comment

begin_define
define|#
directive|define
name|SCSP_ASTATE_DEL
value|2
end_define

begin_comment
comment|/* ATMARP server data deleted */
end_comment

begin_comment
comment|/*  * SCSP constants for NHRP  */
end_comment

begin_define
define|#
directive|define
name|SCSP_NHRP_PROTO
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_NHRP_SIDL
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_NHRP_RIDL
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_NHRP_CKL
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_NHRP_OIDL
value|4
end_define

begin_comment
comment|/*  * SCSP NHRP message  */
end_comment

begin_struct
struct|struct
name|scsp_nhrp_msg
block|{
name|u_short
name|sn_af
decl_stmt|;
comment|/* Address family */
name|u_short
name|sn_proto
decl_stmt|;
comment|/* NHRP protocol type */
name|u_char
name|sn_snap
index|[
literal|5
index|]
decl_stmt|;
comment|/* SNAP */
name|u_char
name|sn_ver
decl_stmt|;
comment|/* NHRP version number */
name|u_short
name|sn_flags
decl_stmt|;
comment|/* Flags */
name|u_long
name|sn_rid
decl_stmt|;
comment|/* Request ID */
name|u_char
name|sn_state
decl_stmt|;
comment|/* State */
name|u_char
name|sn_prel
decl_stmt|;
comment|/* Prefix length */
name|u_short
name|sn_mtu
decl_stmt|;
comment|/* Maximum transmission unit */
name|u_short
name|sn_hold
decl_stmt|;
comment|/* Holding time */
name|Atm_addr
name|sn_addr
decl_stmt|;
comment|/* Server network address */
name|Atm_addr
name|sn_saddr
decl_stmt|;
comment|/* Server network subaddress */
name|struct
name|in_addr
name|sn_paddr
decl_stmt|;
comment|/* Server protocol address */
name|Scsp_ckey
name|sn_key
decl_stmt|;
comment|/* Cache key for entry */
name|Scsp_id
name|sn_oid
decl_stmt|;
comment|/* Originator ID */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_nhrp_msg
name|Scsp_nhrp_msg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCSP_NSTATE_NEW
value|0
end_define

begin_comment
comment|/* New NHRP server */
end_comment

begin_define
define|#
directive|define
name|SCSP_NSTATE_UPD
value|1
end_define

begin_comment
comment|/* NHRP server re-registered */
end_comment

begin_define
define|#
directive|define
name|SCSP_NSTATE_DEL
value|2
end_define

begin_comment
comment|/* NHRP server data purged */
end_comment

begin_define
define|#
directive|define
name|SCSP_NSTATE_NSD
value|3
end_define

begin_comment
comment|/* NHRP no such data in server */
end_comment

begin_comment
comment|/*  * SCSP/server message header  */
end_comment

begin_struct
struct|struct
name|scsp_if_msg_hdr
block|{
name|u_char
name|sh_type
decl_stmt|;
comment|/* Message type */
name|u_char
name|sh_rc
decl_stmt|;
comment|/* Response code */
name|u_short
name|sh_proto
decl_stmt|;
comment|/* SCSP protocol ID */
name|int
name|sh_len
decl_stmt|;
comment|/* Length of message */
name|u_long
name|sh_tok
decl_stmt|;
comment|/* Token from SCSP daemon */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_if_msg_hdr
name|Scsp_if_msg_hdr
typedef|;
end_typedef

begin_comment
comment|/*  * SCSP-server message  */
end_comment

begin_struct
struct|struct
name|scsp_if_msg
block|{
name|Scsp_if_msg_hdr
name|si_hdr
decl_stmt|;
comment|/* Header fields */
union|union
block|{
name|Scsp_cfg_msg
name|siu_cfg
decl_stmt|;
comment|/* Config data */
name|Scsp_sum_msg
name|siu_sum
decl_stmt|;
comment|/* Cache summary */
name|Scsp_atmarp_msg
name|siu_atmarp
decl_stmt|;
comment|/* ATMARP update */
name|Scsp_nhrp_msg
name|siu_nhrp
decl_stmt|;
comment|/* NHRP update */
block|}
name|si_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_if_msg
name|Scsp_if_msg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|si_type
value|si_hdr.sh_type
end_define

begin_define
define|#
directive|define
name|si_rc
value|si_hdr.sh_rc
end_define

begin_define
define|#
directive|define
name|si_proto
value|si_hdr.sh_proto
end_define

begin_define
define|#
directive|define
name|si_len
value|si_hdr.sh_len
end_define

begin_define
define|#
directive|define
name|si_tok
value|si_hdr.sh_tok
end_define

begin_define
define|#
directive|define
name|si_cfg
value|si_u.siu_cfg
end_define

begin_define
define|#
directive|define
name|si_sum
value|si_u.siu_sum
end_define

begin_define
define|#
directive|define
name|si_atmarp
value|si_u.siu_atmarp
end_define

begin_define
define|#
directive|define
name|si_nhrp
value|si_u.siu_nhrp
end_define

begin_comment
comment|/*  * Message types  */
end_comment

begin_define
define|#
directive|define
name|SCSP_NOP_REQ
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_CFG_REQ
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_CFG_RSP
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CACHE_IND
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_CACHE_RSP
value|5
end_define

begin_define
define|#
directive|define
name|SCSP_SOLICIT_IND
value|6
end_define

begin_define
define|#
directive|define
name|SCSP_SOLICIT_RSP
value|7
end_define

begin_define
define|#
directive|define
name|SCSP_UPDATE_IND
value|8
end_define

begin_define
define|#
directive|define
name|SCSP_UPDATE_REQ
value|9
end_define

begin_define
define|#
directive|define
name|SCSP_UPDATE_RSP
value|10
end_define

begin_comment
comment|/*  * Response codes  */
end_comment

begin_define
define|#
directive|define
name|SCSP_RSP_OK
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_RSP_ERR
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_RSP_REJ
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_RSP_NOT_FOUND
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSP_SCSP_IF_H */
end_comment

end_unit

