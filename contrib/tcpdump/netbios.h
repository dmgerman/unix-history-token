begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * NETBIOS protocol formats  *  * @(#) $Header: /tcpdump/master/tcpdump/netbios.h,v 1.1.1.1 1999/10/07 23:47:10 mcr Exp $  */
end_comment

begin_struct
struct|struct
name|p8022Hdr
block|{
name|u_char
name|dsap
decl_stmt|;
name|u_char
name|ssap
decl_stmt|;
name|u_char
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|p8022Size
value|3
end_define

begin_comment
comment|/* min 802.2 header size */
end_comment

begin_define
define|#
directive|define
name|UI
value|0x03
end_define

begin_comment
comment|/* 802.2 flags */
end_comment

end_unit

