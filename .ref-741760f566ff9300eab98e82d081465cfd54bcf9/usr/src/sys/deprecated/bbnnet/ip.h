begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|RCSIPHDR
value|"$Header: ip.h,v 1.4 85/07/31 09:31:22 walsh Exp $"
end_define

begin_struct
struct|struct
name|ip
block|{
comment|/* ip leader */
name|u_char
name|ip_hl
range|:
literal|4
decl_stmt|,
comment|/* header length */
define|#
directive|define
name|IP_HLSHIFT
value|2
name|ip_v
range|:
literal|4
decl_stmt|;
comment|/* version */
name|u_char
name|ip_tos
decl_stmt|;
comment|/* type of service */
define|#
directive|define
name|ip_mff
value|ip_tos
comment|/* more fragments flag (input) */
name|u_short
name|ip_len
decl_stmt|;
comment|/* total length */
name|u_short
name|ip_id
decl_stmt|;
comment|/* identification */
name|u_short
name|ip_off
decl_stmt|;
comment|/* fragment offset field */
define|#
directive|define
name|ip_df
value|0x4000
comment|/* dont fragment flag */
define|#
directive|define
name|ip_mf
value|0x2000
comment|/* more fragments flag (output) */
define|#
directive|define
name|IP_OFFSHIFT
value|3
name|u_char
name|ip_ttl
decl_stmt|;
comment|/* time to live */
name|u_char
name|ip_p
decl_stmt|;
comment|/* protocol */
name|u_short
name|ip_sum
decl_stmt|;
comment|/* checksum */
define|#
directive|define
name|ip_end
value|ip_sum
comment|/* fragment end */
union|union
block|{
name|struct
name|in_addr
name|ip_s
decl_stmt|;
comment|/* source address */
name|struct
name|ip
modifier|*
name|ip_nxt
decl_stmt|;
comment|/* ->next fragment */
block|}
name|I_sun
union|;
define|#
directive|define
name|ip_src
value|I_sun.ip_s
define|#
directive|define
name|ip_next
value|I_sun.ip_nxt
union|union
block|{
name|struct
name|in_addr
name|ip_d
decl_stmt|;
comment|/* destination address */
name|struct
name|ip
modifier|*
name|ip_prv
decl_stmt|;
comment|/* ->prev fragment */
block|}
name|I_dun
union|;
define|#
directive|define
name|ip_dst
value|I_dun.ip_d
define|#
directive|define
name|ip_prev
value|I_dun.ip_prv
block|}
struct|;
end_struct

begin_comment
comment|/* ip options */
end_comment

begin_define
define|#
directive|define
name|IP_OPT_COPY
value|0x80
end_define

begin_comment
comment|/* option copy type flag */
end_comment

begin_define
define|#
directive|define
name|IP_OPT_DEBUG
value|0x40
end_define

begin_comment
comment|/* option debug class (2) */
end_comment

begin_define
define|#
directive|define
name|IP_END_OPT
value|0
end_define

begin_comment
comment|/* end of option list */
end_comment

begin_define
define|#
directive|define
name|IP_NOP_OPT
value|1
end_define

begin_comment
comment|/* nop option */
end_comment

begin_define
define|#
directive|define
name|IP_SEC_OPT
value|(2+IP_OPT_COPY)
end_define

begin_comment
comment|/* security option */
end_comment

begin_define
define|#
directive|define
name|IP_SEC_OPTLEN
value|11
end_define

begin_comment
comment|/* length */
end_comment

begin_define
define|#
directive|define
name|IP_SEC_OPTHDR
value|((IP_SEC_OPT<<8)|IP_SEC_OPTLEN)
end_define

begin_comment
comment|/* opt/len */
end_comment

begin_define
define|#
directive|define
name|IP_LRTE_OPT
value|(3+IP_OPT_COPY)
end_define

begin_comment
comment|/* loose source and record route */
end_comment

begin_define
define|#
directive|define
name|IP_TIME_OPT
value|(4+IP_OPT_DEBUG)
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|IP_RRTE_OPT
value|7
end_define

begin_comment
comment|/* record route */
end_comment

begin_define
define|#
directive|define
name|IP_STRID_OPT
value|(8+IP_OPT_COPY)
end_define

begin_comment
comment|/* stream ID */
end_comment

begin_define
define|#
directive|define
name|IP_STRID_OPTLEN
value|4
end_define

begin_comment
comment|/* length */
end_comment

begin_define
define|#
directive|define
name|IP_STRID_OPTHDR
value|((IP_STRID_OPT<<8)|IP_STRID_OPTLEN)
end_define

begin_comment
comment|/* opt/len */
end_comment

begin_define
define|#
directive|define
name|IP_SRTE_OPT
value|(9+IP_OPT_COPY)
end_define

begin_comment
comment|/* strict source and record route */
end_comment

begin_struct
struct|struct
name|ipq
block|{
comment|/* ip reass.q header */
name|struct
name|ip
name|iqx
decl_stmt|;
comment|/* dummy ip element for top of list */
name|struct
name|ipq
modifier|*
name|iq_next
decl_stmt|;
comment|/* -> next chain on q */
name|struct
name|ipq
modifier|*
name|iq_prev
decl_stmt|;
comment|/* -> prev chain on q */
name|struct
name|ip
name|iqh
decl_stmt|;
comment|/* fragment header */
name|u_short
name|iq_size
comment|/* maximum fragment size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_comment
comment|/* internet protocol version number */
end_comment

begin_define
define|#
directive|define
name|IPMAX
value|576
end_define

begin_comment
comment|/* maximum spec ip packet length */
end_comment

begin_define
define|#
directive|define
name|MAXTTL
value|10
end_define

begin_comment
comment|/* maximum time to live (seconds) */
end_comment

begin_comment
comment|/*  * ip statistics structure  */
end_comment

begin_struct
struct|struct
name|ip_stat
block|{
name|struct
name|in_stat
name|ip_in
decl_stmt|;
define|#
directive|define
name|ip_total
value|ip_in.in_total
define|#
directive|define
name|ip_badsum
value|ip_in.in_badsum
define|#
directive|define
name|ip_tooshort
value|ip_in.in_tooshort
define|#
directive|define
name|ip_drops
value|ip_in.in_drops
name|int
name|ip_forwarded
decl_stmt|;
comment|/* #ip packets not addressed to us */
name|int
name|ip_broadcast
decl_stmt|;
comment|/* #broadcast packets received */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ip_stat
name|ipstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_stat
name|otherstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Enqueue a fragment on the reassembly chain.  * Can't use insque/remque since prev/next not at head of structure.  */
end_comment

begin_define
define|#
directive|define
name|ip_enq
parameter_list|(
name|p
parameter_list|,
name|prev
parameter_list|)
define|\
value|{	register struct ip *PREV = prev;				\ 									\ 	p->ip_prev = PREV;						\ 	p->ip_next = PREV->ip_next;					\ 	PREV->ip_next->ip_prev = p;					\ 	PREV->ip_next = p;						\ }
end_define

begin_comment
comment|/* Dequeue a fragment from reassembly chain.  */
end_comment

begin_define
define|#
directive|define
name|ip_deq
parameter_list|(
name|p
parameter_list|)
define|\
value|{									\ 	p->ip_prev->ip_next = p->ip_next;				\ 	p->ip_next->ip_prev = p->ip_prev;				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

