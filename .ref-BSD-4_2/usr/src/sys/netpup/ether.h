begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	%M%	%I%	%E%	*/
end_comment

begin_comment
comment|/*  * Sockaddr for raw 3Mb/s interface.  *  * The network is needed to locate an interface on output.  */
end_comment

begin_struct
struct|struct
name|sockaddr_en
block|{
name|short
name|sen_family
decl_stmt|;
name|short
name|sen_zero1
decl_stmt|;
name|u_int
name|sen_net
decl_stmt|;
name|u_char
name|sen_host
decl_stmt|;
name|u_char
name|sen_zero2
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

