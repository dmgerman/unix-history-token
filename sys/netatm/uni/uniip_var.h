begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * IP interface control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_UNIIP_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_UNIIP_VAR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * UNI IP network interface structure.  There will be one such structure for   * each IP network interface attached via a UNI signalling instance.  */
end_comment

begin_struct
struct|struct
name|uniip
block|{
name|struct
name|uniip
modifier|*
name|uip_next
decl_stmt|;
comment|/* Next attached IP interface */
name|struct
name|ip_nif
modifier|*
name|uip_ipnif
decl_stmt|;
comment|/* IP network interface */
name|u_char
name|uip_flags
decl_stmt|;
comment|/* Interface flags (see below) */
comment|/* ATMARP (RFC1577) */
name|u_char
name|uip_arpstate
decl_stmt|;
comment|/* ARP interface state (see below) */
name|struct
name|arpmap
name|uip_arpsvrmap
decl_stmt|;
comment|/* ATMARP server map info */
name|struct
name|ipvcc
modifier|*
name|uip_arpsvrvcc
decl_stmt|;
comment|/* ATMARP server's VCC */
name|int
name|uip_nprefix
decl_stmt|;
comment|/* Count of IP prefixes (server only) */
name|struct
name|uniarp_prf
modifier|*
name|uip_prefix
decl_stmt|;
comment|/* Array of IP prefixes (server only) */
name|struct
name|atm_time
name|uip_arptime
decl_stmt|;
comment|/* ARP timer controls */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|uip_arpsvrip
value|uip_arpsvrmap.am_dstip
end_define

begin_define
define|#
directive|define
name|uip_arpsvratm
value|uip_arpsvrmap.am_dstatm
end_define

begin_define
define|#
directive|define
name|uip_arpsvrsub
value|uip_arpsvrmap.am_dstatmsub
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_comment
comment|/*  * UNI Interface Flags  */
end_comment

begin_define
define|#
directive|define
name|UIF_IFADDR
value|0x01
end_define

begin_comment
comment|/* Interface address is set */
end_comment

begin_comment
comment|/*  * UNI ARP Interface States  */
end_comment

begin_define
define|#
directive|define
name|UIAS_NOTCONF
value|1
end_define

begin_comment
comment|/* Not configured */
end_comment

begin_define
define|#
directive|define
name|UIAS_SERVER_ACTIVE
value|2
end_define

begin_comment
comment|/* Server - active */
end_comment

begin_define
define|#
directive|define
name|UIAS_CLIENT_PADDR
value|3
end_define

begin_comment
comment|/* Client - pending ATM address */
end_comment

begin_define
define|#
directive|define
name|UIAS_CLIENT_POPEN
value|4
end_define

begin_comment
comment|/* Client - pending server vcc open */
end_comment

begin_define
define|#
directive|define
name|UIAS_CLIENT_REGISTER
value|5
end_define

begin_comment
comment|/* Client - registering with server */
end_comment

begin_define
define|#
directive|define
name|UIAS_CLIENT_ACTIVE
value|6
end_define

begin_comment
comment|/* Client - active */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure for allowable IP prefixes for ATMARP server registration  */
end_comment

begin_struct
struct|struct
name|uniarp_prf
block|{
name|struct
name|in_addr
name|upf_addr
decl_stmt|;
comment|/* Prefix address */
name|struct
name|in_addr
name|upf_mask
decl_stmt|;
comment|/* Prefix mask */
block|}
struct|;
end_struct

begin_comment
comment|/*  * UNI ARP protocol constants  */
end_comment

begin_define
define|#
directive|define
name|UNIARP_AGING
value|(60 * ATM_HZ)
end_define

begin_comment
comment|/* Aging timer tick */
end_comment

begin_define
define|#
directive|define
name|UNIARP_HASHSIZ
value|19
end_define

begin_comment
comment|/* Hash table size */
end_comment

begin_define
define|#
directive|define
name|UNIARP_REGIS_REFRESH
value|(15 * 60 * ATM_HZ)
end_define

begin_comment
comment|/* Client registration refresh timer */
end_comment

begin_define
define|#
directive|define
name|UNIARP_REGIS_RETRY
value|(60 * ATM_HZ)
end_define

begin_comment
comment|/* Client registration retry timer */
end_comment

begin_define
define|#
directive|define
name|UNIARP_ARP_RETRY
value|(3 * ATM_HZ)
end_define

begin_comment
comment|/* ARP command retry timer */
end_comment

begin_define
define|#
directive|define
name|UNIARP_CLIENT_AGE
value|12
end_define

begin_comment
comment|/* Client validation timeout */
end_comment

begin_define
define|#
directive|define
name|UNIARP_CLIENT_RETRY
value|3
end_define

begin_comment
comment|/* Client validation retrys */
end_comment

begin_define
define|#
directive|define
name|UNIARP_SERVER_AGE
value|17
end_define

begin_comment
comment|/* Server validation timeout */
end_comment

begin_define
define|#
directive|define
name|UNIARP_SERVER_RETRY
value|3
end_define

begin_comment
comment|/* Server validation retrys */
end_comment

begin_define
define|#
directive|define
name|UNIARP_RETRY_AGE
value|1
end_define

begin_comment
comment|/* Retry timeout */
end_comment

begin_define
define|#
directive|define
name|UNIARP_REVALID_AGE
value|2
end_define

begin_comment
comment|/* Revalidation timeout */
end_comment

begin_define
define|#
directive|define
name|UNIARP_MIN_REFRESH
value|10
end_define

begin_comment
comment|/* Minimum entry refresh time */
end_comment

begin_comment
comment|/*  * Structure for ATMARP mappings.  Each of these structures will contain  * IP address to ATM hardware address mappings.  There will be one such  * structure for each IP address and for each unresolved ATM address  * currently in use.  */
end_comment

begin_struct
struct|struct
name|uniarp
block|{
name|struct
name|arpmap
name|ua_arpmap
decl_stmt|;
comment|/* Common entry header */
name|struct
name|uniip
modifier|*
name|ua_intf
decl_stmt|;
comment|/* Interface where we learned answer */
name|struct
name|uniarp
modifier|*
name|ua_next
decl_stmt|;
comment|/* Hash chain link */
name|u_char
name|ua_flags
decl_stmt|;
comment|/* Flags (see below) */
name|u_char
name|ua_origin
decl_stmt|;
comment|/* Source of mapping (see below) */
name|u_char
name|ua_retry
decl_stmt|;
comment|/* Retry counter */
name|u_char
name|ua_aging
decl_stmt|;
comment|/* Aging timeout value (minutes) */
name|struct
name|ipvcc
modifier|*
name|ua_ivp
decl_stmt|;
comment|/* Head of IP VCC chain */
name|struct
name|atm_time
name|ua_time
decl_stmt|;
comment|/* Timer controls */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ua_dstip
value|ua_arpmap.am_dstip
end_define

begin_define
define|#
directive|define
name|ua_dstatm
value|ua_arpmap.am_dstatm
end_define

begin_define
define|#
directive|define
name|ua_dstatmsub
value|ua_arpmap.am_dstatmsub
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_comment
comment|/*  * UNIARP Entry Flags  */
end_comment

begin_define
define|#
directive|define
name|UAF_VALID
value|ARPF_VALID
end_define

begin_comment
comment|/* Entry is valid */
end_comment

begin_define
define|#
directive|define
name|UAF_REFRESH
value|ARPF_REFRESH
end_define

begin_comment
comment|/* Entry has been refreshed */
end_comment

begin_define
define|#
directive|define
name|UAF_LOCKED
value|0x04
end_define

begin_comment
comment|/* Entry is locked */
end_comment

begin_define
define|#
directive|define
name|UAF_USED
value|0x08
end_define

begin_comment
comment|/* Entry has been used recently */
end_comment

begin_comment
comment|/*  * UNIARP Entry Origin  *  * The origin values are ranked according to the source precedence.    * Larger values are more preferred.  */
end_comment

begin_define
define|#
directive|define
name|UAO_LOCAL
value|100
end_define

begin_comment
comment|/* Local address */
end_comment

begin_define
define|#
directive|define
name|UAO_PERM
value|ARP_ORIG_PERM
end_define

begin_comment
comment|/* Permanently installed */
end_comment

begin_define
define|#
directive|define
name|UAO_REGISTER
value|40
end_define

begin_comment
comment|/* Learned via client registration */
end_comment

begin_define
define|#
directive|define
name|UAO_SCSP
value|30
end_define

begin_comment
comment|/* Learned via SCSP */
end_comment

begin_define
define|#
directive|define
name|UAO_LOOKUP
value|20
end_define

begin_comment
comment|/* Learned via server lookup */
end_comment

begin_define
define|#
directive|define
name|UAO_PEER_RSP
value|15
end_define

begin_comment
comment|/* Learned from peer - inarp rsp */
end_comment

begin_define
define|#
directive|define
name|UAO_PEER_REQ
value|10
end_define

begin_comment
comment|/* Learned from peer - inarp req */
end_comment

begin_comment
comment|/*  * ATMARP/InATMARP Packet Format  */
end_comment

begin_struct
struct|struct
name|atmarp_hdr
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
name|ah_shtl
decl_stmt|;
comment|/* Type/len of source ATM address */
name|u_char
name|ah_sstl
decl_stmt|;
comment|/* Type/len of source ATM subaddress */
name|u_short
name|ah_op
decl_stmt|;
comment|/* Operation code (see below) */
name|u_char
name|ah_spln
decl_stmt|;
comment|/* Length of source protocol address */
name|u_char
name|ah_thtl
decl_stmt|;
comment|/* Type/len of target ATM address */
name|u_char
name|ah_tstl
decl_stmt|;
comment|/* Type/len of target ATM subaddress */
name|u_char
name|ah_tpln
decl_stmt|;
comment|/* Length of target protocol address */
ifdef|#
directive|ifdef
name|notdef
comment|/* Variable size fields */
name|u_char
name|ah_sha
index|[]
decl_stmt|;
comment|/* Source ATM address */
name|u_char
name|ah_ssa
index|[]
decl_stmt|;
comment|/* Source ATM subaddress */
name|u_char
name|ah_spa
index|[]
decl_stmt|;
comment|/* Source protocol address */
name|u_char
name|ah_tha
index|[]
decl_stmt|;
comment|/* Target ATM subaddress */
name|u_char
name|ah_tsa
index|[]
decl_stmt|;
comment|/* Target ATM address */
name|u_char
name|ah_tpa
index|[]
decl_stmt|;
comment|/* Target protocol subaddress */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hardware types  */
end_comment

begin_define
define|#
directive|define
name|ARP_ATMFORUM
value|19
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
comment|/* ATMARP request */
end_comment

begin_define
define|#
directive|define
name|ARP_REPLY
value|2
end_define

begin_comment
comment|/* ATMARP response */
end_comment

begin_define
define|#
directive|define
name|INARP_REQUEST
value|8
end_define

begin_comment
comment|/* InATMARP request */
end_comment

begin_define
define|#
directive|define
name|INARP_REPLY
value|9
end_define

begin_comment
comment|/* InATMARP response */
end_comment

begin_define
define|#
directive|define
name|ARP_NAK
value|10
end_define

begin_comment
comment|/* ATMARP negative ack */
end_comment

begin_comment
comment|/*  * Type/length fields  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Timer macros  */
end_comment

begin_define
define|#
directive|define
name|UNIIP_ARP_TIMER
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(s)->uip_arptime, (t), uniarp_iftimeout)
end_define

begin_define
define|#
directive|define
name|UNIIP_ARP_CANCEL
parameter_list|(
name|s
parameter_list|)
value|atm_untimeout(&(s)->uip_arptime)
end_define

begin_define
define|#
directive|define
name|UNIARP_TIMER
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(s)->ua_time, (t), uniarp_timeout)
end_define

begin_define
define|#
directive|define
name|UNIARP_CANCEL
parameter_list|(
name|s
parameter_list|)
value|atm_untimeout(&(s)->ua_time)
end_define

begin_comment
comment|/*  * Macros for manipulating UNIARP tables and entries  */
end_comment

begin_define
define|#
directive|define
name|UNIARP_HASH
parameter_list|(
name|ip
parameter_list|)
value|((u_long)(ip) % UNIARP_HASHSIZ)
end_define

begin_define
define|#
directive|define
name|UNIARP_ADD
parameter_list|(
name|ua
parameter_list|)
define|\
value|{								\ 	struct uniarp	**h;					\ 	h =&uniarp_arptab[UNIARP_HASH((ua)->ua_dstip.s_addr)];	\ 	LINK2TAIL((ua), struct uniarp, *h, ua_next);		\ }
end_define

begin_define
define|#
directive|define
name|UNIARP_DELETE
parameter_list|(
name|ua
parameter_list|)
define|\
value|{								\ 	struct uniarp	**h;					\ 	h =&uniarp_arptab[UNIARP_HASH((ua)->ua_dstip.s_addr)];	\ 	UNLINK((ua), struct uniarp, *h, ua_next);		\ }
end_define

begin_define
define|#
directive|define
name|UNIARP_LOOKUP
parameter_list|(
name|ip
parameter_list|,
name|ua
parameter_list|)
define|\
value|{								\ 	for ((ua) = uniarp_arptab[UNIARP_HASH(ip)];		\ 				(ua); (ua) = (ua)->ua_next) {	\ 		if ((ua)->ua_dstip.s_addr == (ip))		\ 			break;					\ 	}							\ }
end_define

begin_comment
comment|/*  * Global UNIARP Statistics  */
end_comment

begin_struct
struct|struct
name|uniarp_stat
block|{
name|u_long
name|uas_rcvdrop
decl_stmt|;
comment|/* Input packets dropped */
block|}
struct|;
end_struct

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|uniip
modifier|*
name|uniip_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ip_serv
name|uniip_ipserv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uniarp
modifier|*
name|uniarp_arptab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uniarp
modifier|*
name|uniarp_nomaptab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uniarp
modifier|*
name|uniarp_pvctab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|uniarp_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|atm_time
name|uniarp_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|uniarp_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atm_endpoint
name|uniarp_endpt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uniarp_stat
name|uniarp_stat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* uniarp.c */
end_comment

begin_decl_stmt
name|int
name|uniarp_start
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_stop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_ipact
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_ipdact
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_ifaddr
name|__P
argument_list|(
operator|(
expr|struct
name|siginst
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_iftimeout
name|__P
argument_list|(
operator|(
expr|struct
name|atm_time
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_ioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|caddr_t
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|uniarp_getname
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uniarp_cache.c */
end_comment

begin_decl_stmt
name|int
name|uniarp_cache_svc
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_cache_pvc
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_validate_ip
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uniarp_input.c */
end_comment

begin_decl_stmt
name|void
name|uniarp_cpcs_data
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|KBuffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_pdu_print
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uniarp_output.c */
end_comment

begin_decl_stmt
name|int
name|uniarp_arp_req
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_arp_rsp
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|,
expr|struct
name|arpmap
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_arp_nak
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|,
name|KBuffer
operator|*
operator|,
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_inarp_req
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_inarp_rsp
name|__P
argument_list|(
operator|(
expr|struct
name|uniip
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uniarp_timer.c */
end_comment

begin_decl_stmt
name|void
name|uniarp_timeout
name|__P
argument_list|(
operator|(
expr|struct
name|atm_time
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_aging
name|__P
argument_list|(
operator|(
expr|struct
name|atm_time
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uniarp_vcm.c */
end_comment

begin_decl_stmt
name|int
name|uniarp_pvcopen
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_svcout
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_svcin
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|,
name|Atm_addr
operator|*
operator|,
name|Atm_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniarp_svcactive
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_vcclose
name|__P
argument_list|(
operator|(
expr|struct
name|ipvcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_connected
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uniarp_cleared
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|t_atm_cause
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uniip.c */
end_comment

begin_decl_stmt
name|int
name|uniip_start
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uniip_stop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
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
comment|/* _UNI_UNIIP_VAR_H */
end_comment

end_unit

