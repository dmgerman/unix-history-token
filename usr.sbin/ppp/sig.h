begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: $  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sig_type
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Call this instead of signal() */
end_comment

begin_function_decl
specifier|extern
name|sig_type
name|pending_signal
parameter_list|(
name|int
parameter_list|,
name|sig_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this when you want things to *actually* happen */
end_comment

begin_function_decl
specifier|extern
name|void
name|handle_signals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

