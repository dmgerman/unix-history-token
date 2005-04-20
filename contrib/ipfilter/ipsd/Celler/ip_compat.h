begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1995 by Darren Reed.  *  * This code may be freely distributed as long as it retains this notice  * and is not changed in any way.  The author accepts no responsibility  * for the use of this software.  I hate legaleese, don't you ?  *  * @(#)ip_compat.h	1.1 9/14/95  */
end_comment

begin_comment
comment|/*  * These #ifdef's are here mainly for linux, but who knows, they may  * not be in other places or maybe one day linux will grow up and some  * of these will turn up there too.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH
value|ICMP_DEST_UNREACH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_SOURCEQUENCH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_SOURCEQUENCH
value|ICMP_SOURCE_QUENCH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TIMXCEED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TIMXCEED
value|ICMP_TIME_EXCEEDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB
value|ICMP_PARAMETERPROB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPVERSION
end_ifndef

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_MINOFF
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_MINOFF
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_COPIED
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_COPIED
parameter_list|(
name|x
parameter_list|)
value|((x)&0x80)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_EOL
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_NOP
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_MF
end_ifndef

begin_define
define|#
directive|define
name|IP_MF
value|((u_short)0x2000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_IP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_IP
value|((u_short)0x0800)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_FIN
end_ifndef

begin_define
define|#
directive|define
name|TH_FIN
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_SYN
end_ifndef

begin_define
define|#
directive|define
name|TH_SYN
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_RST
end_ifndef

begin_define
define|#
directive|define
name|TH_RST
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_PUSH
end_ifndef

begin_define
define|#
directive|define
name|TH_PUSH
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_ACK
end_ifndef

begin_define
define|#
directive|define
name|TH_ACK
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_URG
end_ifndef

begin_define
define|#
directive|define
name|TH_URG
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_EOL
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_NOP
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_RR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_RR
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_TS
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_TS
value|68
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECURITY
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECURITY
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_LSRR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_LSRR
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SATID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SATID
value|136
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SSRR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SSRR
value|137
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_UNCLASS
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_UNCLASS
value|((u_short)0x0000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_CONFID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_CONFID
value|((u_short)0xf135)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_EFTO
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_EFTO
value|((u_short)0x789a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_MMMM
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_MMMM
value|((u_short)0xbc4d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_RESTR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_RESTR
value|((u_short)0xaf13)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_SECRET
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_SECRET
value|((u_short)0xd788)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_TOPSECRET
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_TOPSECRET
value|((u_short)0x6bc5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_define
define|#
directive|define
name|icmp
value|icmphdr
end_define

begin_define
define|#
directive|define
name|icmp_type
value|type
end_define

begin_define
define|#
directive|define
name|icmp_code
value|code
end_define

begin_comment
comment|/*  * From /usr/include/netinet/ip_var.h  * !%@#!$@# linux...  */
end_comment

begin_struct
struct|struct
name|ipovly
block|{
name|caddr_t
name|ih_next
decl_stmt|,
name|ih_prev
decl_stmt|;
comment|/* for protocol sequence q's */
name|u_char
name|ih_x1
decl_stmt|;
comment|/* (unused) */
name|u_char
name|ih_pr
decl_stmt|;
comment|/* protocol */
name|short
name|ih_len
decl_stmt|;
comment|/* protocol length */
name|struct
name|in_addr
name|ih_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|ih_dst
decl_stmt|;
comment|/* destination internet address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u16
name|th_sport
decl_stmt|;
name|__u16
name|th_dport
decl_stmt|;
name|__u32
name|th_seq
decl_stmt|;
name|__u32
name|th_ack
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|vax
argument_list|)
name|__u8
name|th_res
range|:
literal|4
decl_stmt|;
name|__u8
name|th_off
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|__u8
name|th_off
range|:
literal|4
decl_stmt|;
name|__u8
name|th_res
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__u8
name|th_flags
decl_stmt|;
name|__u16
name|th_win
decl_stmt|;
name|__u16
name|th_sum
decl_stmt|;
name|__u16
name|th_urp
decl_stmt|;
block|}
name|tcphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u16
name|uh_sport
decl_stmt|;
name|__u16
name|uh_dport
decl_stmt|;
name|__s16
name|uh_ulen
decl_stmt|;
name|__u16
name|uh_sum
decl_stmt|;
block|}
name|udphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|vax
argument_list|)
name|__u8
name|ip_hl
range|:
literal|4
decl_stmt|;
name|__u8
name|ip_v
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|__u8
name|ip_hl
range|:
literal|4
decl_stmt|;
name|__u8
name|ip_v
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__u8
name|ip_tos
decl_stmt|;
name|__u16
name|ip_len
decl_stmt|;
name|__u16
name|ip_id
decl_stmt|;
name|__u16
name|ip_off
decl_stmt|;
name|__u8
name|ip_ttl
decl_stmt|;
name|__u8
name|ip_p
decl_stmt|;
name|__u16
name|ip_sum
decl_stmt|;
name|struct
name|in_addr
name|ip_src
decl_stmt|;
name|struct
name|in_addr
name|ip_dst
decl_stmt|;
block|}
name|ip_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u8
name|ether_dhost
index|[
literal|6
index|]
decl_stmt|;
name|__u8
name|ether_shost
index|[
literal|6
index|]
decl_stmt|;
name|__u16
name|ether_type
decl_stmt|;
block|}
name|ether_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memmove(b,a,c)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp(a,b,c)
end_define

begin_define
define|#
directive|define
name|ifnet
value|device
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|udphdr
name|udphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tcphdr
name|tcphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ip
name|ip_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ether_header
name|ether_header_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|solaris
end_ifdef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memmove(b,a,c)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp(a,b,c)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset(a,0,b)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

