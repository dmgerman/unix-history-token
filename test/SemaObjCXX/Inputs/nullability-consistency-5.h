begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|SUPPRESS_NULLABILITY_WARNING
parameter_list|(
name|Type
parameter_list|)
define|\
value|_Pragma("clang diagnostic push")                                      \   _Pragma("clang diagnostic ignored \"-Wnullability-completeness\"")    \   Type                                                                  \   _Pragma("clang diagnostic pop")
end_define

begin_decl_stmt
name|void
name|suppress1
argument_list|(
name|SUPPRESS_NULLABILITY_WARNING
argument_list|(
argument|int *
argument_list|)
name|ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no warning
end_comment

begin_function_decl
name|void
name|shouldwarn5
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//expected-warning{{missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|trigger5
parameter_list|(
name|int
modifier|*
name|_Nonnull
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|suppress2
argument_list|(
name|SUPPRESS_NULLABILITY_WARNING
argument_list|(
argument|int *
argument_list|)
name|ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no warning
end_comment

end_unit

