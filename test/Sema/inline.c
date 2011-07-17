begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Check that we don't allow illegal uses of inline
end_comment

begin_decl_stmt
specifier|inline
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'inline' can only appear on functions}}
end_comment

begin_typedef
typedef|typedef
specifier|inline
name|int
name|b
typedef|;
end_typedef

begin_comment
comment|// expected-error{{'inline' can only appear on functions}}
end_comment

begin_function_decl
name|int
name|d
parameter_list|(
specifier|inline
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'inline' can only appear on functions}}
end_comment

end_unit

