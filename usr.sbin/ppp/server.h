begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: $  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|server
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|ServerLocalOpen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ServerTcpOpen
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ServerClose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

