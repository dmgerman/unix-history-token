begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * SCSP message formats  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSP_SCSP_MSG_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSP_SCSP_MSG_H
end_define

begin_comment
comment|/*  * ATMARP constants  */
end_comment

begin_define
define|#
directive|define
name|ARP_ATMFORUM
value|19
end_define

begin_define
define|#
directive|define
name|ARP_TL_TMASK
value|0x40
end_define

begin_comment
comment|/* Type mask */
end_comment

begin_define
define|#
directive|define
name|ARP_TL_NSAPA
value|0x00
end_define

begin_comment
comment|/* Type = ATM Forum NSAPA */
end_comment

begin_define
define|#
directive|define
name|ARP_TL_E164
value|0x40
end_define

begin_comment
comment|/* Type = E.164 */
end_comment

begin_define
define|#
directive|define
name|ARP_TL_LMASK
value|0x3f
end_define

begin_comment
comment|/* Length mask */
end_comment

begin_comment
comment|/*  * SCSP version number  */
end_comment

begin_define
define|#
directive|define
name|SCSP_VER_1
value|1
end_define

begin_comment
comment|/*  * SCSP message types  */
end_comment

begin_define
define|#
directive|define
name|SCSP_CA_MSG
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_CSU_REQ_MSG
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_CSU_REPLY_MSG
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_CSUS_MSG
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_HELLO_MSG
value|5
end_define

begin_comment
comment|/*  * SCSP Client Protocol IDs  */
end_comment

begin_define
define|#
directive|define
name|SCSP_PROTO_ATMARP
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_PROTO_NHRP
value|2
end_define

begin_define
define|#
directive|define
name|SCSP_PROTO_MARS
value|3
end_define

begin_define
define|#
directive|define
name|SCSP_PROTO_DHCP
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_PROTO_LNNI
value|5
end_define

begin_comment
comment|/*  * Extension types  */
end_comment

begin_define
define|#
directive|define
name|SCSP_EXT_END
value|0
end_define

begin_define
define|#
directive|define
name|SCSP_EXT_AUTH
value|1
end_define

begin_define
define|#
directive|define
name|SCSP_EXT_VENDOR
value|2
end_define

begin_comment
comment|/*  * Sequence number bounds  */
end_comment

begin_define
define|#
directive|define
name|SCSP_CSA_SEQ_MIN
value|0x80000001
end_define

begin_define
define|#
directive|define
name|SCSP_CSA_SEQ_MAX
value|0x7FFFFFFF
end_define

begin_comment
comment|/*  * Sender, Receiver, or Originator ID lengths  */
end_comment

begin_define
define|#
directive|define
name|SCSP_ATMARP_ID_LEN
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_NHRP_ID_LEN
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_MAX_ID_LEN
value|4
end_define

begin_comment
comment|/*  * Cache Key lengths  */
end_comment

begin_define
define|#
directive|define
name|SCSP_ATMARP_KEY_LEN
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_NHRP_KEY_LEN
value|4
end_define

begin_define
define|#
directive|define
name|SCSP_MAX_KEY_LEN
value|4
end_define

begin_comment
comment|/*  * Fixed header  */
end_comment

begin_struct
struct|struct
name|scsp_nhdr
block|{
name|u_char
name|sh_ver
decl_stmt|;
comment|/* SCSP version */
name|u_char
name|sh_type
decl_stmt|;
comment|/* Message type */
name|u_short
name|sh_len
decl_stmt|;
comment|/* Message length */
name|u_short
name|sh_checksum
decl_stmt|;
comment|/* IP checksum over message */
name|u_short
name|sh_ext_off
decl_stmt|;
comment|/* Offset of first extension */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mandatory common part  */
end_comment

begin_struct
struct|struct
name|scsp_nmcp
block|{
name|u_short
name|sm_pid
decl_stmt|;
comment|/* Protocol ID */
name|u_short
name|sm_sgid
decl_stmt|;
comment|/* Server group ID */
name|u_short
name|sm_fill_0
decl_stmt|;
comment|/* Unused */
name|u_short
name|sm_flags
decl_stmt|;
comment|/* Flags--see below */
name|u_char
name|sm_sid_len
decl_stmt|;
comment|/* Sender ID length */
name|u_char
name|sm_rid_len
decl_stmt|;
comment|/* Receiver ID length */
name|u_short
name|sm_rec_cnt
decl_stmt|;
comment|/* Number of records */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable length fields */
name|u_char
name|sm_sid
index|[]
decl_stmt|;
comment|/* Sender ID (variable) */
name|u_char
name|sm_rid
index|[]
decl_stmt|;
comment|/* Receiver ID (variable) */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Extensions part  */
end_comment

begin_struct
struct|struct
name|scsp_next
block|{
name|u_short
name|se_type
decl_stmt|;
comment|/* Extension type */
name|u_short
name|se_len
decl_stmt|;
comment|/* Length */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable length fields */
name|u_char
name|se_value
index|[]
decl_stmt|;
comment|/* Extension value */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cache State Advertisement record or  *    Cache State Advertisement Summary record  */
end_comment

begin_struct
struct|struct
name|scsp_ncsa
block|{
name|u_short
name|scs_hop_cnt
decl_stmt|;
comment|/* Hop count */
name|u_short
name|scs_len
decl_stmt|;
comment|/* Record length */
name|u_char
name|scs_ck_len
decl_stmt|;
comment|/* Cache key length */
name|u_char
name|scs_oid_len
decl_stmt|;
comment|/* Originator ID length */
name|u_short
name|scs_nfill
decl_stmt|;
comment|/* Null bit and filler */
name|long
name|scs_seq
decl_stmt|;
comment|/* Sequence number */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable length fields */
name|u_char
name|scs_ckey
index|[]
decl_stmt|;
comment|/* Cache key */
name|u_char
name|scs_oid
index|[]
decl_stmt|;
comment|/* Originator ID */
name|u_char
name|scs_proto
index|[]
decl_stmt|;
comment|/* Protocol-specific (in CSA) */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSP_CSAS_NULL
value|0x8000
end_define

begin_comment
comment|/*  * Cache Alignment message  */
end_comment

begin_struct
struct|struct
name|scsp_nca
block|{
name|long
name|sca_seq
decl_stmt|;
comment|/* Sequence number */
name|struct
name|scsp_nmcp
name|sca_mcp
decl_stmt|;
comment|/* Mandatory common */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable length fields */
name|struct
name|scsp_ncsa
name|sca_rec
index|[]
decl_stmt|;
comment|/* CSASs */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSP_CA_M
value|0x8000
end_define

begin_comment
comment|/* Master/Slave bit */
end_comment

begin_define
define|#
directive|define
name|SCSP_CA_I
value|0x4000
end_define

begin_comment
comment|/* Initialization bit */
end_comment

begin_define
define|#
directive|define
name|SCSP_CA_O
value|0x2000
end_define

begin_comment
comment|/* More bit */
end_comment

begin_comment
comment|/*  * Cache State Update Request, Cache State Update Reply, or  * Cache State Update Solicit message  */
end_comment

begin_struct
struct|struct
name|scsp_ncsu_msg
block|{
name|struct
name|scsp_nmcp
name|scr_mcp
decl_stmt|;
comment|/* Mandatory common */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable length fields */
name|struct
name|scsp_ncsa
name|scr_rec
index|[]
decl_stmt|;
comment|/* CSAs */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hello message  */
end_comment

begin_struct
struct|struct
name|scsp_nhello
block|{
name|u_short
name|sch_hi
decl_stmt|;
comment|/* Hello interval */
name|u_short
name|sch_df
decl_stmt|;
comment|/* Dead factor */
name|u_short
name|sch_fill_0
decl_stmt|;
comment|/* Unused */
name|u_short
name|sch_fid
decl_stmt|;
comment|/* Family ID */
name|struct
name|scsp_nmcp
name|sch_mcp
decl_stmt|;
comment|/* Mandatory common */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable-length fields */
name|struct
name|scsp_nrid
name|sch_rid
index|[]
decl_stmt|;
comment|/* Receiver IDs */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATMARP-specific Cache State Advertisement record  */
end_comment

begin_struct
struct|struct
name|scsp_atmarp_ncsa
block|{
name|u_short
name|sa_hrd
decl_stmt|;
comment|/* Hardware type -- 0x0013 */
name|u_short
name|sa_pro
decl_stmt|;
comment|/* Protocol type -- 0x0800 */
name|u_char
name|sa_shtl
decl_stmt|;
comment|/* Src ATM addr type/len */
name|u_char
name|sa_sstl
decl_stmt|;
comment|/* Src ATM subaddr type/len */
name|u_char
name|sa_state
decl_stmt|;
comment|/* State */
name|u_char
name|sa_fill1
decl_stmt|;
comment|/* Unused */
name|u_char
name|sa_spln
decl_stmt|;
comment|/* Src proto addr type */
name|u_char
name|sa_thtl
decl_stmt|;
comment|/* Tgt ATM addr type/len */
name|u_char
name|sa_tstl
decl_stmt|;
comment|/* Tgt ATM subaddr type/len */
name|u_char
name|sa_tpln
decl_stmt|;
comment|/* Tgt proto addr len */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable-length fields */
name|u_char
name|sa_sha
index|[]
decl_stmt|;
comment|/* Source ATM addr */
name|u_char
name|sa_ssa
index|[]
decl_stmt|;
comment|/* Source ATM subaddr */
name|u_char
name|sa_spa
index|[]
decl_stmt|;
comment|/* Source IP addr */
name|u_char
name|sa_tha
index|[]
decl_stmt|;
comment|/* Target ATM addr */
name|u_char
name|sa_tsa
index|[]
decl_stmt|;
comment|/* Target ATM subaddr */
name|u_char
name|sa_tpa
index|[]
decl_stmt|;
comment|/* Target IP addr */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * NHRP-specific Cache State Advertisement record  */
end_comment

begin_struct
struct|struct
name|scsp_nhrp_ncsa
block|{
name|u_short
name|sn_af
decl_stmt|;
comment|/* Address family */
name|u_short
name|sn_pro
decl_stmt|;
comment|/* NHRP protocol type */
name|u_char
name|sn_snap
index|[
literal|5
index|]
decl_stmt|;
comment|/* SNAP header */
name|u_char
name|sn_ver
decl_stmt|;
comment|/* NHRP version no. */
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
name|sn_pln
decl_stmt|;
comment|/* Prefix length */
name|u_short
name|sn_fill1
decl_stmt|;
comment|/* Unused */
name|u_short
name|sn_mtu
decl_stmt|;
comment|/* MTU */
name|u_short
name|sn_hold
decl_stmt|;
comment|/* Holding time */
name|u_char
name|sn_csatl
decl_stmt|;
comment|/* Client addr type/len */
name|u_char
name|sn_csstl
decl_stmt|;
comment|/* Client subaddr type/len */
name|u_char
name|sn_cpln
decl_stmt|;
comment|/* Client proto addr len */
name|u_char
name|sn_pref
decl_stmt|;
comment|/* Preference for next hop */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable-length fields */
name|u_char
name|sn_csa
index|[]
decl_stmt|;
comment|/* Client subnetwork addr */
name|u_char
name|sn_css
index|[]
decl_stmt|;
comment|/* Client subnetwork subaddr */
name|u_char
name|sn_cpa
index|[]
decl_stmt|;
comment|/* Client protocol addr */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSP messages in internal format  *  *  * Fixed message header  */
end_comment

begin_struct
struct|struct
name|scsp_hdr
block|{
name|u_char
name|msg_type
decl_stmt|;
comment|/* Message type */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_hdr
name|Scsp_hdr
typedef|;
end_typedef

begin_comment
comment|/*  * Sender or Receiver ID structure  */
end_comment

begin_struct
struct|struct
name|scsp_id
block|{
name|struct
name|scsp_id
modifier|*
name|next
decl_stmt|;
comment|/* Next ID */
name|u_char
name|id_len
decl_stmt|;
comment|/* ID length */
name|u_char
name|id
index|[
name|SCSP_MAX_ID_LEN
index|]
decl_stmt|;
comment|/* ID */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_id
name|Scsp_id
typedef|;
end_typedef

begin_comment
comment|/*  * Cacke Key structure  */
end_comment

begin_struct
struct|struct
name|scsp_ckey
block|{
name|u_char
name|key_len
decl_stmt|;
comment|/* Cache key length */
name|u_char
name|key
index|[
name|SCSP_MAX_KEY_LEN
index|]
decl_stmt|;
comment|/* Cache key */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_ckey
name|Scsp_ckey
typedef|;
end_typedef

begin_comment
comment|/*  * Mandatory  common part  */
end_comment

begin_struct
struct|struct
name|scsp_mcp
block|{
name|u_short
name|pid
decl_stmt|;
comment|/* Protocol ID */
name|u_short
name|sgid
decl_stmt|;
comment|/* Server group ID */
name|u_short
name|flags
decl_stmt|;
comment|/* Flags */
name|u_short
name|rec_cnt
decl_stmt|;
comment|/* No. of records attached */
name|Scsp_id
name|sid
decl_stmt|;
comment|/* Sender ID */
name|Scsp_id
name|rid
decl_stmt|;
comment|/* Receiver ID */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_mcp
name|Scsp_mcp
typedef|;
end_typedef

begin_comment
comment|/*  * Extensions part  */
end_comment

begin_struct
struct|struct
name|scsp_ext
block|{
name|struct
name|scsp_ext
modifier|*
name|next
decl_stmt|;
comment|/* Next extension */
name|u_short
name|type
decl_stmt|;
comment|/* Extension type */
name|u_short
name|len
decl_stmt|;
comment|/* Length */
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* Variable length fields */
name|u_char
name|value
index|[]
decl_stmt|;
comment|/* Extension value */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_ext
name|Scsp_ext
typedef|;
end_typedef

begin_comment
comment|/*  * Cache State Advertisement record or  *    Cache State Advertisement Summary record  */
end_comment

begin_struct
struct|struct
name|scsp_csa
block|{
name|struct
name|scsp_csa
modifier|*
name|next
decl_stmt|;
comment|/* Next CSAS record */
name|u_short
name|hops
decl_stmt|;
comment|/* Hop count */
name|u_char
name|null
decl_stmt|;
comment|/* Null flag */
name|u_long
name|seq
decl_stmt|;
comment|/* CSA seq. no. */
name|Scsp_ckey
name|key
decl_stmt|;
comment|/* Cache key */
name|Scsp_id
name|oid
decl_stmt|;
comment|/* Originator ID */
name|int
name|trans_ct
decl_stmt|;
comment|/* No. of times CSA sent */
name|struct
name|scsp_atmarp_csa
modifier|*
name|atmarp_data
decl_stmt|;
comment|/* ATMARP data */
ifdef|#
directive|ifdef
name|NOTDEF
name|struct
name|scsp_nhrp_csa
modifier|*
name|nhrp_data
decl_stmt|;
comment|/* NHRP data */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_csa
name|Scsp_csa
typedef|;
end_typedef

begin_comment
comment|/*  * Macro to free a CSA and any associated protocol-specific data  */
end_comment

begin_define
define|#
directive|define
name|SCSP_FREE_CSA
parameter_list|(
name|c
parameter_list|)
define|\
value|{								\ 	if ((c)->atmarp_data) {					\ 		UM_FREE((c)->atmarp_data);			\ 	}							\ 	UM_FREE((c));						\ }
end_define

begin_comment
comment|/*  * Cache Alignment message  */
end_comment

begin_struct
struct|struct
name|scsp_ca
block|{
name|long
name|ca_seq
decl_stmt|;
comment|/* CA msg sequence no. */
name|u_char
name|ca_m
decl_stmt|;
comment|/* Master/slave bit */
name|u_char
name|ca_i
decl_stmt|;
comment|/* Initialization bit */
name|u_char
name|ca_o
decl_stmt|;
comment|/* More bit */
name|Scsp_mcp
name|ca_mcp
decl_stmt|;
comment|/* Mandatory common part */
name|Scsp_csa
modifier|*
name|ca_csa_rec
decl_stmt|;
comment|/* Ptr. to CSAS records */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_ca
name|Scsp_ca
typedef|;
end_typedef

begin_comment
comment|/*  * Cache State Update Request, Cache State Update Reply, or  * Cache State Update Solicit message  */
end_comment

begin_struct
struct|struct
name|scsp_csu_msg
block|{
name|Scsp_mcp
name|csu_mcp
decl_stmt|;
comment|/* Mandatory common part */
name|Scsp_csa
modifier|*
name|csu_csa_rec
decl_stmt|;
comment|/* Ptr. to CSA records */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_csu_msg
name|Scsp_csu_msg
typedef|;
end_typedef

begin_comment
comment|/*  * Hello message  */
end_comment

begin_struct
struct|struct
name|scsp_hello
block|{
name|u_short
name|hello_int
decl_stmt|;
comment|/* Hello interval */
name|u_short
name|dead_factor
decl_stmt|;
comment|/* When is DCS dead? */
name|u_short
name|family_id
decl_stmt|;
comment|/* Family ID */
name|Scsp_mcp
name|hello_mcp
decl_stmt|;
comment|/* Mandatory common part */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_hello
name|Scsp_hello
typedef|;
end_typedef

begin_comment
comment|/*  * NHRP-specific Cache State Advertisement record  */
end_comment

begin_struct
struct|struct
name|scsp_nhrp_csa
block|{
name|u_char
name|req_id
decl_stmt|;
comment|/* Request ID */
name|u_char
name|state
decl_stmt|;
comment|/* State */
name|u_char
name|pref_len
decl_stmt|;
comment|/* Prefix length */
name|u_short
name|flags
decl_stmt|;
comment|/* See below */
name|u_short
name|mtu
decl_stmt|;
comment|/* Maximim transmission unit */
name|u_short
name|hold_time
decl_stmt|;
comment|/* Entry holding time */
name|u_char
name|caddr_tlen
decl_stmt|;
comment|/* Client addr type/length */
name|u_char
name|csaddr_tlen
decl_stmt|;
comment|/* Client subaddr type/length */
name|u_char
name|cproto_len
decl_stmt|;
comment|/* Client proto addr length */
name|u_char
name|pref
decl_stmt|;
comment|/* Preference */
name|Atm_addr
name|caddr
decl_stmt|;
comment|/* Client address */
name|Atm_addr
name|csaddr
decl_stmt|;
comment|/* Client subaddress */
name|struct
name|in_addr
name|cproto_addr
decl_stmt|;
comment|/* Client protocol address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_nhrp
name|Scsp_nhrp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCSP_NHRP_UNIQ
value|0x8000
end_define

begin_define
define|#
directive|define
name|SCSP_NHRP_ARP
value|0x4000
end_define

begin_comment
comment|/*  * ATMARP-specific Cache State Advertisement record  */
end_comment

begin_struct
struct|struct
name|scsp_atmarp_csa
block|{
name|u_char
name|sa_state
decl_stmt|;
comment|/* State */
name|Atm_addr
name|sa_sha
decl_stmt|;
comment|/* Source ATM addr */
name|Atm_addr
name|sa_ssa
decl_stmt|;
comment|/* Source ATM subaddr */
name|struct
name|in_addr
name|sa_spa
decl_stmt|;
comment|/* Source IP addr */
name|Atm_addr
name|sa_tha
decl_stmt|;
comment|/* Target ATM addr */
name|Atm_addr
name|sa_tsa
decl_stmt|;
comment|/* Target ATM subaddr */
name|struct
name|in_addr
name|sa_tpa
decl_stmt|;
comment|/* Target IP addr */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_atmarp_csa
name|Scsp_atmarp_csa
typedef|;
end_typedef

begin_comment
comment|/*  * SCSP message  */
end_comment

begin_struct
struct|struct
name|scsp_msg
block|{
name|Scsp_hdr
name|sc_hdr
decl_stmt|;
union|union
block|{
name|Scsp_ca
modifier|*
name|sc_u_ca
decl_stmt|;
name|Scsp_csu_msg
modifier|*
name|sc_u_csu_msg
decl_stmt|;
name|Scsp_hello
modifier|*
name|sc_u_hello
decl_stmt|;
block|}
name|sc_msg_u
union|;
name|Scsp_ext
modifier|*
name|sc_ext
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsp_msg
name|Scsp_msg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sc_msg_type
value|sc_hdr.msg_type
end_define

begin_define
define|#
directive|define
name|sc_ca
value|sc_msg_u.sc_u_ca
end_define

begin_define
define|#
directive|define
name|sc_csu_msg
value|sc_msg_u.sc_u_csu_msg
end_define

begin_define
define|#
directive|define
name|sc_hello
value|sc_msg_u.sc_u_hello
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSP_SCSP_MSG_H */
end_comment

end_unit

