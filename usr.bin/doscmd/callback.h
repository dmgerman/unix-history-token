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
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|register_callback
parameter_list|(
name|u_long
parameter_list|,
name|callback_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|callback_t
name|find_callback
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|insert_generic_trampoline
parameter_list|(
name|size_t
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|insert_softint_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|insert_hardint_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|insert_null_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

