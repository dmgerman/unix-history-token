begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_ether.h	4.1	82/12/16	*/
end_comment

begin_comment
comment|/*  * Structure of a 10Mb/s Ethernet header.  */
end_comment

begin_struct
struct|struct
name|eth_header
block|{
name|u_char
name|eth_dhost
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|eth_shost
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|eth_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ETHPUP_PUPTYPE
value|4
end_define

begin_comment
comment|/* PUP protocol */
end_comment

begin_define
define|#
directive|define
name|ETHPUP_IPTYPE
value|8
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_comment
comment|/*  * The ETHPUP_NTRAILER packet types starting at ETHPUP_TRAIL have  * (type-ETHPUP_TRAIL)*512 bytes of data followed  * by a PUP type (as given above) and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ETHPUP_TRAIL
value|16
end_define

begin_comment
comment|/* Trailer PUP */
end_comment

begin_define
define|#
directive|define
name|ETHPUP_NTRAILER
value|16
end_define

end_unit

