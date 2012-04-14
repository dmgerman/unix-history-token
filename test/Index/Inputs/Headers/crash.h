begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Produce a crash if CRASH is defined.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRASH
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|__debug
name|crash
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|const
name|char
modifier|*
name|getCrashString
parameter_list|()
function_decl|;
end_function_decl

end_unit

