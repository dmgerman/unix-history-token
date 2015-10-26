begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_lineedit.h - generic interface to various line editing libs  */
end_comment

begin_function_decl
name|int
name|ntp_readline_init
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntp_readline_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * strings returned by ntp_readline go home to free()  */
end_comment

begin_function_decl
name|char
modifier|*
name|ntp_readline
parameter_list|(
name|int
modifier|*
name|pcount
parameter_list|)
function_decl|;
end_function_decl

end_unit

