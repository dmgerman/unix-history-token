begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	decnet.h	1.3	82/10/09	*/
end_comment

begin_comment
comment|/*  * DECnet address (should be expanded for Phase 3E)  */
end_comment

begin_struct
struct|struct
name|dn_addr
block|{
name|u_short
name|s_host
decl_stmt|;
comment|/* remote host address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Socket address, DECnet style.  */
end_comment

begin_struct
struct|struct
name|sockaddr_dn
block|{
name|short
name|sdn_family
decl_stmt|;
comment|/* AF_DECNET */
name|u_short
name|sdn_port
decl_stmt|;
comment|/* local port number */
name|struct
name|dn_addr
name|sdn_addr
decl_stmt|;
comment|/* remote host/port address */
name|char
name|sdn_zero
index|[]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

