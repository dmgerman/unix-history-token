begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Cisco IGRP definitions */
end_comment

begin_comment
comment|/* IGRP Header */
end_comment

begin_struct
struct|struct
name|igrphdr
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_char
name|ig_op
range|:
literal|4
decl_stmt|;
comment|/* opcode */
name|u_char
name|ig_v
range|:
literal|4
decl_stmt|;
comment|/* protocol version number */
else|#
directive|else
name|u_char
name|ig_v
range|:
literal|4
decl_stmt|;
comment|/* protocol version number */
name|u_char
name|ig_op
range|:
literal|4
decl_stmt|;
comment|/* opcode */
endif|#
directive|endif
name|u_char
name|ig_ed
decl_stmt|;
comment|/* edition number */
name|u_short
name|ig_as
decl_stmt|;
comment|/* autonomous system number */
name|u_short
name|ig_ni
decl_stmt|;
comment|/* number of subnet in local net */
name|u_short
name|ig_ns
decl_stmt|;
comment|/* number of networks in AS */
name|u_short
name|ig_nx
decl_stmt|;
comment|/* number of networks ouside AS */
name|u_short
name|ig_sum
decl_stmt|;
comment|/* checksum of IGRP header& data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IGRP_UPDATE
value|1
end_define

begin_define
define|#
directive|define
name|IGRP_REQUEST
value|2
end_define

begin_comment
comment|/* IGRP routing entry */
end_comment

begin_struct
struct|struct
name|igrprte
block|{
name|u_char
name|igr_net
index|[
literal|3
index|]
decl_stmt|;
comment|/* 3 significant octets of IP address */
name|u_char
name|igr_dly
index|[
literal|3
index|]
decl_stmt|;
comment|/* delay in tens of microseconds */
name|u_char
name|igr_bw
index|[
literal|3
index|]
decl_stmt|;
comment|/* bandwidth in units of 1 kb/s */
name|u_char
name|igr_mtu
index|[
literal|2
index|]
decl_stmt|;
comment|/* MTU in octets */
name|u_char
name|igr_rel
decl_stmt|;
comment|/* percent packets successfully tx/rx */
name|u_char
name|igr_ld
decl_stmt|;
comment|/* percent of channel occupied */
name|u_char
name|igr_hct
decl_stmt|;
comment|/* hop count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IGRP_RTE_SIZE
value|14
end_define

begin_comment
comment|/* don't believe sizeof ! */
end_comment

end_unit

