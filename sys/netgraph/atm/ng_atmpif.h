begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Harti Brandt.  * Copyright (c) 2003 Vincent Jardin.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATM_NG_ATMPIF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATM_NG_ATMPIF_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_ATMPIF_NODE_TYPE
value|"atmpif"
end_define

begin_define
define|#
directive|define
name|NGM_ATMPIF_COOKIE
value|967239456
end_define

begin_comment
comment|/*  * Physical device name - used to configure HARP devices  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VATMPIF_DEV_NAME
end_ifndef

begin_define
define|#
directive|define
name|VATMPIF_DEV_NAME
value|"hva"
end_define

begin_comment
comment|/* HARP Virtual ATM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VATMPIF_MAX_VCI
value|65535
end_define

begin_define
define|#
directive|define
name|VATMPIF_MAX_VPI
value|255
end_define

begin_comment
comment|/* Hook name */
end_comment

begin_define
define|#
directive|define
name|NG_ATMPIF_HOOK_LINK
value|"link"
end_define

begin_comment
comment|/* virtual link hook */
end_comment

begin_comment
comment|/*  * Node configuration structure  */
end_comment

begin_struct
struct|struct
name|ng_vatmpif_config
block|{
name|uint8_t
name|debug
decl_stmt|;
comment|/* debug bit field (see below) */
name|uint32_t
name|pcr
decl_stmt|;
comment|/* peak cell rate */
name|Mac_addr
name|macaddr
decl_stmt|;
comment|/* Mac Address */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_ATMPIF_CONFIG_TYPE_INFO
value|{ 				\ 	{ "debug",&ng_parse_uint8_type	},	\ 	{ "pcr",&ng_parse_uint32_type	},	\ 	{ "macaddr",&ng_mac_addr_type	},	\ 	{ NULL }						\ }
end_define

begin_comment
comment|/*  * Debug bit-fields  */
end_comment

begin_define
define|#
directive|define
name|VATMPIF_DEBUG_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|VATMPIF_DEBUG_PACKET
value|0x01
end_define

begin_comment
comment|/* enable ng_atmpif debugging	 */
end_comment

begin_define
define|#
directive|define
name|IS_VATMPIF_DEBUG_PACKET
parameter_list|(
name|a
parameter_list|)
value|( (a)	\&&  ((a)->conf.debug& VATMPIF_DEBUG_PACKET)  )
end_define

begin_comment
comment|/*  * Statistics  */
end_comment

begin_struct
struct|struct
name|hva_stats_ng
block|{
name|uint32_t
name|ng_errseq
decl_stmt|;
comment|/* Duplicate or out of order */
name|uint32_t
name|ng_lostpdu
decl_stmt|;
comment|/* PDU lost detected */
name|uint32_t
name|ng_badpdu
decl_stmt|;
comment|/* Unknown PDU type */
name|uint32_t
name|ng_rx_novcc
decl_stmt|;
comment|/* Draining PDU on closed VCC */
name|uint32_t
name|ng_rx_iqfull
decl_stmt|;
comment|/* PDU drops, no room in atm_intrq */
name|uint32_t
name|ng_tx_rawcell
decl_stmt|;
comment|/* PDU raw cells transmitted */
name|uint32_t
name|ng_rx_rawcell
decl_stmt|;
comment|/* PDU raw cells received */
name|uint64_t
name|ng_tx_pdu
decl_stmt|;
comment|/* PDU transmitted */
name|uint64_t
name|ng_rx_pdu
decl_stmt|;
comment|/* PDU received */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hva_stats_ng
name|Hva_Stats_ng
typedef|;
end_typedef

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|HVA_STATS_NG_TYPE_INFO
define|\
value|{ "errSeqOrder",&ng_parse_uint32_type	},	\ 	{ "errLostPDU",&ng_parse_uint32_type	},	\ 	{ "recvBadPDU",&ng_parse_uint32_type	},	\ 	{ "ErrATMVC",&ng_parse_uint32_type	},	\ 	{ "ErrQfull",&ng_parse_uint32_type	},	\ 	{ "xmitRawCell",&ng_parse_uint32_type	},	\ 	{ "recvRawCell",&ng_parse_uint32_type	},	\ 	{ "xmitPDU",&ng_parse_uint64_type	},	\ 	{ "recvPDU",&ng_parse_uint64_type	},
end_define

begin_struct
struct|struct
name|hva_stats_atm
block|{
name|uint64_t
name|atm_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|uint64_t
name|atm_rcvd
decl_stmt|;
comment|/* Cells received */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hva_stats_atm
name|Hva_Stats_atm
typedef|;
end_typedef

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|HVA_STATS_ATM_NG_TYPE_INFO
define|\
value|{ "xmitATMCells",&ng_parse_uint64_type	},	\ 	{ "recvATMCells",&ng_parse_uint64_type	},
end_define

begin_struct
struct|struct
name|hva_stats_aal5
block|{
name|uint64_t
name|aal5_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|uint64_t
name|aal5_rcvd
decl_stmt|;
comment|/* Cells received */
name|uint32_t
name|aal5_crc_len
decl_stmt|;
comment|/* Cells with CRC/length errors */
name|uint32_t
name|aal5_drops
decl_stmt|;
comment|/* Cell drops */
name|uint64_t
name|aal5_pdu_xmit
decl_stmt|;
comment|/* CS PDUs transmitted */
name|uint64_t
name|aal5_pdu_rcvd
decl_stmt|;
comment|/* CS PDUs received */
name|uint32_t
name|aal5_pdu_crc
decl_stmt|;
comment|/* CS PDUs with CRC errors */
name|uint32_t
name|aal5_pdu_errs
decl_stmt|;
comment|/* CS layer protocol errors */
name|uint32_t
name|aal5_pdu_drops
decl_stmt|;
comment|/* CS PDUs dropped */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hva_stats_aal5
name|Hva_Stats_aal5
typedef|;
end_typedef

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|HVA_STATS_AAL5_NG_TYPE_INFO
define|\
value|{ "xmitAAL5Cells",&ng_parse_uint64_type	},	\ 	{ "recvAAL5Cells",&ng_parse_uint64_type	},	\ 	{ "AAL5ErrCRCCells",&ng_parse_uint32_type	},	\ 	{ "AAL5DropsCells",&ng_parse_uint32_type	},	\ 	{ "xmitAAL5PDU",&ng_parse_uint64_type	},	\ 	{ "recvAAL5PDU",&ng_parse_uint64_type	},	\ 	{ "AAL5CRCPDU",&ng_parse_uint32_type	},	\ 	{ "AAL5ErrPDU",&ng_parse_uint32_type	},	\ 	{ "AAL5DropsPDU",&ng_parse_uint32_type	},
end_define

begin_struct
struct|struct
name|vatmpif_stats
block|{
name|Hva_Stats_ng
name|hva_st_ng
decl_stmt|;
comment|/* Netgraph layer stats */
name|Hva_Stats_atm
name|hva_st_atm
decl_stmt|;
comment|/* ATM layer stats */
name|Hva_Stats_aal5
name|hva_st_aal5
decl_stmt|;
comment|/* AAL5 layer stats */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vatmpif_stats
name|Vatmpif_stats
typedef|;
end_typedef

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_ATMPIF_STATS_TYPE_INFO
value|{	\ 	HVA_STATS_NG_TYPE_INFO	 	\ 	HVA_STATS_ATM_NG_TYPE_INFO	\ 	HVA_STATS_AAL5_NG_TYPE_INFO	\ 	{ NULL }			\ }
end_define

begin_comment
comment|/* Structure returned by NGM_ATMPIF_GET_LINK_STATUS */
end_comment

begin_struct
struct|struct
name|ng_atmpif_link_status
block|{
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
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_ATMPIF_LINK_STATUS_TYPE_INFO
value|{		\ 	{ "InSeq",&ng_parse_uint32_type },	\ 	{ "OutSeq",&ng_parse_uint32_type },	\ 	{ "cur_pcr",&ng_parse_uint32_type },	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Netgraph control messages */
end_comment

begin_enum
enum|enum
block|{
name|NGM_ATMPIF_SET_CONFIG
init|=
literal|1
block|,
comment|/* set node configuration */
name|NGM_ATMPIF_GET_CONFIG
block|,
comment|/* get node configuration */
name|NGM_ATMPIF_GET_LINK_STATUS
block|,
comment|/* get link status */
name|NGM_ATMPIF_GET_STATS
block|,
comment|/* get link stats */
name|NGM_ATMPIF_CLR_STATS
block|,
comment|/* clear link stats */
name|NGM_ATMPIF_GETCLR_STATS
block|,
comment|/* atomically get& clear link stats */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_ATMPIF_H_ */
end_comment

end_unit

