begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	inet.h	4.1	83/05/28	*/
end_comment

begin_comment
comment|/*  * External definitions for  * functions in inet(3N)  */
end_comment

begin_function_decl
name|struct
name|in_addr
name|inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|inet_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|inet_network
parameter_list|()
function_decl|;
end_function_decl

end_unit

