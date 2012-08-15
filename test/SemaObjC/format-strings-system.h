begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_decl_stmt
unit|@
name|class
name|NSString
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Do not emit warnings when using NSLocalizedString
end_comment

begin_function_decl
specifier|extern
name|NSString
modifier|*
name|GetLocalizedString
parameter_list|(
name|NSString
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NSLocalizedString
parameter_list|(
name|key
parameter_list|)
value|GetLocalizedString(key)
end_define

begin_define
define|#
directive|define
name|NSAssert
parameter_list|(
name|fmt
parameter_list|,
name|arg
parameter_list|)
value|NSLog(fmt, arg, 0, 0)
end_define

end_unit

