begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__IPF_LINUX_H__
end_ifndef

begin_define
define|#
directive|define
name|__IPF_LINUX_H__
end_define

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|18
argument_list|)
end_if

begin_include
include|#
directive|include
file|<linux/autoconf.h>
end_include

begin_include
include|#
directive|include
file|<linux/poll.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<linux/config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_NETFILTER
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_NETFILTER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|__irq_h
value|1
end_define

begin_comment
comment|/* stop it being included! */
end_comment

begin_include
include|#
directive|include
file|<linux/mtd/compatmac.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<linux/compatmac.h>
end_include

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/time.h>
end_include

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<linux/socket.h>
end_include

begin_include
include|#
directive|include
file|<linux/netdevice.h>
end_include

begin_include
include|#
directive|include
file|<linux/inetdevice.h>
end_include

begin_include
include|#
directive|include
file|<linux/skbuff.h>
end_include

begin_include
include|#
directive|include
file|<linux/in.h>
end_include

begin_include
include|#
directive|include
file|<linux/ip.h>
end_include

begin_include
include|#
directive|include
file|<net/ip.h>
end_include

begin_comment
comment|/* IP_DF */
end_comment

begin_include
include|#
directive|include
file|<linux/icmp.h>
end_include

begin_include
include|#
directive|include
file|<linux/rtnetlink.h>
end_include

begin_include
include|#
directive|include
file|<linux/netfilter.h>
end_include

begin_include
include|#
directive|include
file|<linux/netfilter_ipv4.h>
end_include

begin_include
include|#
directive|include
file|<linux/netfilter_ipv6.h>
end_include

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|0
argument_list|)
end_if

begin_include
include|#
directive|include
file|<asm/ioctls.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ipftcphdr
value|tcphdr
end_define

begin_define
define|#
directive|define
name|ipfudphdr
value|udphdr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ipftcphdr
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
name|__vax__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
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
struct|;
end_struct

begin_typedef
typedef|typedef
name|__u32
name|tcp_seq
typedef|;
end_typedef

begin_struct
struct|struct
name|ipfudphdr
block|{
name|__u16
name|uh_sport
decl_stmt|;
name|__u16
name|uh_dport
decl_stmt|;
name|__u16
name|uh_ulen
decl_stmt|;
name|__u16
name|uh_sum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ip
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
name|__vax__
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
name|ip_v
range|:
literal|4
decl_stmt|;
name|__u8
name|ip_hl
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
struct|;
end_struct

begin_comment
comment|/*  * Structure of an icmp header.  */
end_comment

begin_struct
struct|struct
name|icmp
block|{
name|__u8
name|icmp_type
decl_stmt|;
comment|/* type of message, see below */
name|__u8
name|icmp_code
decl_stmt|;
comment|/* type sub code */
name|__u16
name|icmp_cksum
decl_stmt|;
comment|/* ones complement cksum of struct */
union|union
block|{
name|__u8
name|ih_pptr
decl_stmt|;
comment|/* ICMP_PARAMPROB */
name|struct
name|in_addr
name|ih_gwaddr
decl_stmt|;
comment|/* ICMP_REDIRECT */
struct|struct
name|ih_idseq
block|{
name|__u16
name|icd_id
decl_stmt|;
name|__u16
name|icd_seq
decl_stmt|;
block|}
name|ih_idseq
struct|;
name|__u32
name|ih_void
decl_stmt|;
struct|struct
name|ih_pmtu
block|{
name|__u16
name|ipm_void
decl_stmt|;
name|__u16
name|ipm_nextmtu
decl_stmt|;
block|}
name|ih_pmtu
struct|;
block|}
name|icmp_hun
union|;
define|#
directive|define
name|icmp_pptr
value|icmp_hun.ih_pptr
define|#
directive|define
name|icmp_gwaddr
value|icmp_hun.ih_gwaddr
define|#
directive|define
name|icmp_id
value|icmp_hun.ih_idseq.icd_id
define|#
directive|define
name|icmp_seq
value|icmp_hun.ih_idseq.icd_seq
define|#
directive|define
name|icmp_void
value|icmp_hun.ih_void
define|#
directive|define
name|icmp_nextmtu
value|icmp_hun.ih_pmtu.ipm_nextmtu
union|union
block|{
struct|struct
name|id_ts
block|{
name|__u32
name|its_otime
decl_stmt|;
name|__u32
name|its_rtime
decl_stmt|;
name|__u32
name|its_ttime
decl_stmt|;
block|}
name|id_ts
struct|;
struct|struct
name|id_ip
block|{
name|struct
name|ip
name|idi_ip
decl_stmt|;
comment|/* options and then 64 bits of data */
block|}
name|id_ip
struct|;
name|u_long
name|id_mask
decl_stmt|;
name|char
name|id_data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|icmp_dun
union|;
define|#
directive|define
name|icmp_otime
value|icmp_dun.id_ts.its_otime
define|#
directive|define
name|icmp_rtime
value|icmp_dun.id_ts.its_rtime
define|#
directive|define
name|icmp_ttime
value|icmp_dun.id_ts.its_ttime
define|#
directive|define
name|icmp_ip
value|icmp_dun.id_ip.idi_ip
define|#
directive|define
name|icmp_mask
value|icmp_dun.id_mask
define|#
directive|define
name|icmp_data
value|icmp_dun.id_data
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_IPOVLY
end_ifndef

begin_define
define|#
directive|define
name|LINUX_IPOVLY
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ether_header
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
struct|;
end_struct

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|0
argument_list|)
end_if

begin_typedef
typedef|typedef
name|struct
name|ipftcphdr
name|tcphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ipfudphdr
name|udphdr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ip_compat.h"
end_include

begin_include
include|#
directive|include
file|"ip_fil.h"
end_include

begin_include
include|#
directive|include
file|"ip_auth.h"
end_include

begin_include
include|#
directive|include
file|"ip_state.h"
end_include

begin_include
include|#
directive|include
file|"ip_nat.h"
end_include

begin_include
include|#
directive|include
file|"ip_proxy.h"
end_include

begin_include
include|#
directive|include
file|"ip_sync.h"
end_include

begin_include
include|#
directive|include
file|"ip_frag.h"
end_include

begin_include
include|#
directive|include
file|"ip_lookup.h"
end_include

begin_include
include|#
directive|include
file|"ip_dstlist.h"
end_include

begin_include
include|#
directive|include
file|"ip_pool.h"
end_include

begin_include
include|#
directive|include
file|"ip_htable.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_SYNC
end_ifdef

begin_include
include|#
directive|include
file|"netinet/ip_sync.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_SCAN
end_ifdef

begin_include
include|#
directive|include
file|"netinet/ip_scan.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_COMPILED
end_ifdef

begin_include
include|#
directive|include
file|"netinet/ip_rules.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ipl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IPF_LINUX_H__ */
end_comment

end_unit

