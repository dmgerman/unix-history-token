begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	udp.h	4.1	81/11/14	*/
end_comment

begin_struct
struct|struct
name|udpiphdr
block|{
name|struct
name|ipovly
name|u_ip
decl_stmt|;
name|struct
name|udpiphdr
modifier|*
name|u_x
index|[
literal|2
index|]
decl_stmt|;
comment|/* space holders */
name|u_char
name|u_x1
decl_stmt|;
comment|/* unused */
name|u_char
name|u_pr
decl_stmt|;
end_struct

begin_comment
comment|/* protocol */
end_comment

end_unit

