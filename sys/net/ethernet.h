begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Fundamental constants relating to ethernet.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_ETHERNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_ETHERNET_H_
end_define

begin_comment
comment|/*  * The number of bytes in an ethernet (MAC) address.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_ADDR_LEN
value|6
end_define

begin_comment
comment|/*  * The number of bytes in the type field.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_TYPE_LEN
value|2
end_define

begin_comment
comment|/*  * The number of bytes in the trailing CRC field.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_CRC_LEN
value|4
end_define

begin_comment
comment|/*  * The length of the combined header.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_HDR_LEN
value|(ETHER_ADDR_LEN*2+ETHER_TYPE_LEN)
end_define

begin_comment
comment|/*  * The minimum packet length.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_MIN_LEN
value|64
end_define

begin_comment
comment|/*  * The maximum packet length.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAX_LEN
value|1518
end_define

begin_comment
comment|/*  * A macro to validate a length with  */
end_comment

begin_define
define|#
directive|define
name|ETHER_IS_VALID_LEN
parameter_list|(
name|foo
parameter_list|)
define|\
value|((foo)>= ETHER_MIN_LEN&& (foo)<= ETHER_MAX_LEN)
end_define

begin_comment
comment|/*  * Structure of a 10Mb/s Ethernet header.  */
end_comment

begin_struct
struct|struct
name|ether_header
block|{
name|u_char
name|ether_dhost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_char
name|ether_shost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_short
name|ether_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a 48-bit Ethernet address.  */
end_comment

begin_struct
struct|struct
name|ether_addr
block|{
name|u_char
name|octet
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ETHERTYPE_PUP
value|0x0200
end_define

begin_comment
comment|/* PUP protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IP
value|0x0800
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ARP
value|0x0806
end_define

begin_comment
comment|/* Addr. resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_REVARP
value|0x8035
end_define

begin_comment
comment|/* reverse Addr. resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VLAN
value|0x8100
end_define

begin_comment
comment|/* IEEE 802.1Q VLAN tagging */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LOOPBACK
value|0x9000
end_define

begin_comment
comment|/* used to test interfaces */
end_comment

begin_comment
comment|/* XXX - add more useful types here */
end_comment

begin_comment
comment|/*  * The ETHERTYPE_NTRAILER packet types starting at ETHERTYPE_TRAIL have  * (type-ETHERTYPE_TRAIL)*512 bytes of data followed  * by an ETHER type (as given above) and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer packet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NTRAILER
value|16
end_define

begin_define
define|#
directive|define
name|ETHERMTU
value|(ETHER_MAX_LEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|ETHERMIN
value|(ETHER_MIN_LEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Ethernet address conversion/parsing routines.  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|ether_addr
modifier|*
name|ether_aton
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ether_hostton
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|ether_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ether_line
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|ether_addr
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ether_ntoa
name|__P
argument_list|(
operator|(
expr|struct
name|ether_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ether_ntohost
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|ether_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_ETHERNET_H_ */
end_comment

end_unit

