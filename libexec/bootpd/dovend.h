begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dovend.h */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_function_decl
specifier|extern
name|int
name|dovend_rfc1497
parameter_list|(
name|struct
name|host
modifier|*
name|hp
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|insert_ip
parameter_list|(
name|int
parameter_list|,
name|struct
name|in_addr_list
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insert_u_long
parameter_list|(
name|u_int32
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

