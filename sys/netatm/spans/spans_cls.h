begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * SPANS Signalling Manager  * ---------------------------  *  * SPANS Connectionless Datagram Service (CLS) control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPANS_SPANSCLS_H
end_ifndef

begin_define
define|#
directive|define
name|_SPANS_SPANSCLS_H
end_define

begin_comment
comment|/*  * Protocol constants  */
end_comment

begin_define
define|#
directive|define
name|SPANSARP_AGING
value|(60 * ATM_HZ)
end_define

begin_comment
comment|/* ARP aging timer */
end_comment

begin_define
define|#
directive|define
name|SPANSARP_RETRY
value|(3 * ATM_HZ)
end_define

begin_comment
comment|/* ARP retry timer */
end_comment

begin_define
define|#
directive|define
name|SPANSARP_MAXAGE
value|20
end_define

begin_comment
comment|/* Max ARP entry age (minutes)*/
end_comment

begin_define
define|#
directive|define
name|SPANSARP_HASHSIZ
value|19
end_define

begin_comment
comment|/* Hash table size */
end_comment

begin_comment
comment|/*  * SPANS CLS protocol structure.  There will be one such structure for   * each SPANS signalling instance.  */
end_comment

begin_struct
struct|struct
name|spanscls
block|{
name|struct
name|spanscls
modifier|*
name|cls_next
decl_stmt|;
comment|/* Next attached cls instance */
name|u_char
name|cls_state
decl_stmt|;
comment|/* Protocol state (see below) */
name|struct
name|spans
modifier|*
name|cls_spans
decl_stmt|;
comment|/* Spans signalling instance */
name|Atm_connection
modifier|*
name|cls_conn
decl_stmt|;
comment|/* Connection manager token */
name|struct
name|ip_nif
modifier|*
name|cls_ipnif
decl_stmt|;
comment|/* IP network interface */
block|}
struct|;
end_struct

begin_comment
comment|/*  * SPANS CLS Protocol States  */
end_comment

begin_define
define|#
directive|define
name|CLS_CLOSED
value|1
end_define

begin_comment
comment|/* CLS PVC is closed */
end_comment

begin_define
define|#
directive|define
name|CLS_OPEN
value|2
end_define

begin_comment
comment|/* CLS PVC is open */
end_comment

begin_comment
comment|/*  * Structure for SPANS ARP mappings.  Each of these structures will contain   * IP address to SPANS hardware address mappings.  There will be one such  * structure for each IP address currently in use.  */
end_comment

begin_struct
struct|struct
name|spansarp
block|{
name|struct
name|arpmap
name|sa_arpmap
decl_stmt|;
comment|/* Common entry header */
name|struct
name|spanscls
modifier|*
name|sa_cls
decl_stmt|;
comment|/* Interface where we learned answer */
name|struct
name|spansarp
modifier|*
name|sa_next
decl_stmt|;
comment|/* Hash chain */
name|struct
name|spansarp
modifier|*
name|sa_rnext
decl_stmt|;
comment|/* Retry chain */
name|u_char
name|sa_flags
decl_stmt|;
comment|/* Flags (see below) */
name|u_char
name|sa_origin
decl_stmt|;
comment|/* Origin (see below) */
name|u_short
name|sa_reftime
decl_stmt|;
comment|/* Entry reference time (minutes) */
name|struct
name|ipvcc
modifier|*
name|sa_ivp
decl_stmt|;
comment|/* IP VCCs waiting for answer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sa_dstip
value|sa_arpmap.am_dstip
end_define

begin_define
define|#
directive|define
name|sa_dstatm
value|sa_arpmap.am_dstatm
end_define

begin_define
define|#
directive|define
name|sa_dstatmsub
value|sa_arpmap.am_dstatmsub
end_define

begin_comment
comment|/*  * Entry Flags  */
end_comment

begin_define
define|#
directive|define
name|SAF_VALID
value|ARPF_VALID
end_define

begin_comment
comment|/* Entry is valid */
end_comment

begin_define
define|#
directive|define
name|SAF_REFRESH
value|ARPF_REFRESH
end_define

begin_comment
comment|/* Entry has been refreshed */
end_comment

begin_define
define|#
directive|define
name|SAF_LOCKED
value|0x04
end_define

begin_comment
comment|/* Entry is locked */
end_comment

begin_comment
comment|/*  * Entry Origin  */
end_comment

begin_define
define|#
directive|define
name|SAO_PERM
value|ARP_ORIG_PERM
end_define

begin_comment
comment|/* Entry is permanently installed */
end_comment

begin_define
define|#
directive|define
name|SAO_LOOKUP
value|20
end_define

begin_comment
comment|/* Learned via lookup */
end_comment

begin_comment
comment|/*  * SPANS CLS Packet Header  */
end_comment

begin_struct
struct|struct
name|spanscls_hdr
block|{
comment|/* IEEE 802.6 MAC header */
name|spans_addr
name|ch_dst
decl_stmt|;
comment|/* Destination SPANS address */
name|spans_addr
name|ch_src
decl_stmt|;
comment|/* Source SPANS address */
name|u_char
name|ch_proto
decl_stmt|;
comment|/* */
name|u_char
name|ch_extlen
decl_stmt|;
comment|/* */
name|u_short
name|ch_bridging
decl_stmt|;
comment|/* */
comment|/* LLC SNAP header */
name|u_char
name|ch_dsap
decl_stmt|;
comment|/* Destination SAP */
name|u_char
name|ch_ssap
decl_stmt|;
comment|/* Source SAP */
name|u_char
name|ch_ctl
decl_stmt|;
comment|/* Control field */
name|u_char
name|ch_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* Organizationally Unique Identifier */
name|u_short
name|ch_pid
decl_stmt|;
comment|/* Protocol Identifier */
block|}
struct|;
end_struct

begin_comment
comment|/*  * SPANS ARP Packet Format  */
end_comment

begin_struct
struct|struct
name|spansarp_hdr
block|{
name|u_short
name|ah_hrd
decl_stmt|;
comment|/* Hardware type (see below) */
name|u_short
name|ah_pro
decl_stmt|;
comment|/* Protocol type */
name|u_char
name|ah_hln
decl_stmt|;
comment|/* Length of hardware address */
name|u_char
name|ah_pln
decl_stmt|;
comment|/* Length of protocol address */
name|u_short
name|ah_op
decl_stmt|;
comment|/* Operation code (see below) */
name|spans_addr
name|ah_sha
decl_stmt|;
comment|/* Source hardware address */
name|u_char
name|ah_spa
index|[
literal|4
index|]
decl_stmt|;
comment|/* Source protocol address */
name|spans_addr
name|ah_tha
decl_stmt|;
comment|/* Target hardware address */
name|u_char
name|ah_tpa
index|[
literal|4
index|]
decl_stmt|;
comment|/* Target protocol address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hardware types  */
end_comment

begin_define
define|#
directive|define
name|ARP_SPANS
value|0x4040
end_define

begin_comment
comment|/*  * Operation types  */
end_comment

begin_define
define|#
directive|define
name|ARP_REQUEST
value|1
end_define

begin_comment
comment|/* SPANSARP request */
end_comment

begin_define
define|#
directive|define
name|ARP_REPLY
value|2
end_define

begin_comment
comment|/* SPANSARP response */
end_comment

begin_define
define|#
directive|define
name|ARP_PACKET_LEN
define|\
value|(sizeof(struct spanscls_hdr) + sizeof(struct spansarp_hdr))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Macros for manipulating SPANS ARP tables and entries  */
end_comment

begin_define
define|#
directive|define
name|SPANSARP_HASH
parameter_list|(
name|ip
parameter_list|)
value|((u_long)(ip) % SPANSARP_HASHSIZ)
end_define

begin_define
define|#
directive|define
name|SPANSARP_ADD
parameter_list|(
name|sa
parameter_list|)
define|\
value|{								\ 	struct spansarp	**h;					\ 	h =&spansarp_arptab[SPANSARP_HASH((sa)->sa_dstip.s_addr)];	\ 	LINK2TAIL((sa), struct spansarp, *h, sa_next);		\ }
end_define

begin_define
define|#
directive|define
name|SPANSARP_DELETE
parameter_list|(
name|sa
parameter_list|)
define|\
value|{								\ 	struct spansarp	**h;					\ 	h =&spansarp_arptab[SPANSARP_HASH((sa)->sa_dstip.s_addr)];	\ 	UNLINK((sa), struct spansarp, *h, sa_next);		\ }
end_define

begin_define
define|#
directive|define
name|SPANSARP_LOOKUP
parameter_list|(
name|ip
parameter_list|,
name|sa
parameter_list|)
define|\
value|{								\ 	for ((sa) = spansarp_arptab[SPANSARP_HASH(ip)];		\ 				(sa); (sa) = (sa)->sa_next) {	\ 		if ((sa)->sa_dstip.s_addr == (ip))		\ 			break;					\ 	}							\ }
end_define

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|spanscls
modifier|*
name|spanscls_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|spanscls_hdr
name|spanscls_hdr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPANS_SPANSCLS_H */
end_comment

end_unit

