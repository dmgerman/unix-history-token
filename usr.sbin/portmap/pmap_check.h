begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) pmap_check.h 1.3 93/11/21 16:18:53 */
end_comment

begin_function_decl
specifier|extern
name|int
name|from_local
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_startup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_default
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_setunset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_privileged_port
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_callit
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|verboselog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|allow_severity
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|deny_severity
decl_stmt|;
end_decl_stmt

end_unit

