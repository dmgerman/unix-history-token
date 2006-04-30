begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* report.h */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_function_decl
specifier|extern
name|void
name|report_init
parameter_list|(
name|int
name|nolog
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|report
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|get_errmsg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

