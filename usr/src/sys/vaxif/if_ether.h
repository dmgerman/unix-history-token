begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_ether.h	4.3	82/12/16	*/
end_comment

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
literal|6
index|]
decl_stmt|;
name|u_char
name|ether_shost
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|ether_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ETHERPUP_PUPTYPE
value|0x0400
end_define

begin_comment
comment|/* PUP protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERPUP_IPTYPE
value|0x0800
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_comment
comment|/*  * The ETHERPUP_NTRAILER packet types starting at ETHERPUP_TRAIL have  * (type-ETHERPUP_TRAIL)*512 bytes of data followed  * by a PUP type (as given above) and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ETHERPUP_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer PUP */
end_comment

begin_define
define|#
directive|define
name|ETHERPUP_NTRAILER
value|16
end_define

begin_define
define|#
directive|define
name|ETHERMTU
value|1500
end_define

begin_define
define|#
directive|define
name|ETHERMIN
value|(60-14)
end_define

end_unit

