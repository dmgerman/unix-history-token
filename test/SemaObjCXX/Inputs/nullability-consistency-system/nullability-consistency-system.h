begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Simply marking this as "#pragma clang system_header" didn't tickle the bug, rdar://problem/21134250.
end_comment

begin_function_decl
name|void
name|system1
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|WARN_IN_SYSTEM_HEADERS
end_if

begin_comment
comment|// expected-warning@-2{{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-3 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-4 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|system2
parameter_list|(
name|int
modifier|*
name|_Nonnull
parameter_list|)
function_decl|;
end_function_decl

end_unit

