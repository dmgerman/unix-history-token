begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ** No copyright?! ** ** $FreeBSD$ */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|callback_t
function_decl|)
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|register_callback
parameter_list|(
name|u_long
name|vec
parameter_list|,
name|callback_t
name|func
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|callback_t
name|find_callback
parameter_list|(
name|u_long
name|vec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|insert_generic_trampoline
parameter_list|(
name|size_t
name|len
parameter_list|,
name|u_char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|insert_softint_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|insert_hardint_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|insert_null_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

