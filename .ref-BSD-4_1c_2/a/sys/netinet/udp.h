begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	udp.h	4.3	81/11/18	*/
end_comment

begin_comment
comment|/*  * Udp protocol header.  * Per RFC 768, September, 1981.  */
end_comment

begin_struct
struct|struct
name|udphdr
block|{
name|u_short
name|uh_sport
decl_stmt|;
comment|/* source port */
name|u_short
name|uh_dport
decl_stmt|;
comment|/* destination port */
name|short
name|uh_ulen
decl_stmt|;
comment|/* udp length */
name|u_short
name|uh_sum
decl_stmt|;
comment|/* udp checksum */
block|}
struct|;
end_struct

end_unit

