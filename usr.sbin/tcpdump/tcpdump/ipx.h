begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IPX protocol formats  *  * @(#) $FreeBSD$  */
end_comment

begin_comment
comment|/* well-known sockets */
end_comment

begin_define
define|#
directive|define
name|IPX_SKT_NCP
value|0x0451
end_define

begin_define
define|#
directive|define
name|IPX_SKT_SAP
value|0x0452
end_define

begin_define
define|#
directive|define
name|IPX_SKT_RIP
value|0x0453
end_define

begin_define
define|#
directive|define
name|IPX_SKT_NETBIOS
value|0x0455
end_define

begin_define
define|#
directive|define
name|IPX_SKT_DIAGNOSTICS
value|0x0456
end_define

begin_comment
comment|/* IPX transport header */
end_comment

begin_struct
struct|struct
name|ipxHdr
block|{
name|u_short
name|cksum
decl_stmt|;
comment|/* Checksum */
name|u_short
name|length
decl_stmt|;
comment|/* Length, in bytes, including header */
name|u_char
name|tCtl
decl_stmt|;
comment|/* Transport Control (i.e. hop count) */
name|u_char
name|pType
decl_stmt|;
comment|/* Packet Type (i.e. level 2 protocol) */
name|u_short
name|dstNet
index|[
literal|2
index|]
decl_stmt|;
comment|/* destination net */
name|u_char
name|dstNode
index|[
literal|6
index|]
decl_stmt|;
comment|/* destination node */
name|u_short
name|dstSkt
decl_stmt|;
comment|/* destination socket */
name|u_short
name|srcNet
index|[
literal|2
index|]
decl_stmt|;
comment|/* source net */
name|u_char
name|srcNode
index|[
literal|6
index|]
decl_stmt|;
comment|/* source node */
name|u_short
name|srcSkt
decl_stmt|;
comment|/* source socket */
block|}
name|ipx_hdr_t
struct|;
end_struct

begin_define
define|#
directive|define
name|ipxSize
value|30
end_define

end_unit

