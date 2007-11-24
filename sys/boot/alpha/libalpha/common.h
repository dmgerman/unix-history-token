begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  * From: $NetBSD: common.h,v 1.2 1998/01/05 07:02:48 perry Exp $	  */
end_comment

begin_function_decl
name|int
name|prom_open
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OSFpal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|prom_dispatch
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpu_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|switch_palcode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

