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

begin_endif
endif|#
directive|endif
end_endif

end_unit

