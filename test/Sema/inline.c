begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=gnu89 -fsyntax-only -verify %s
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

begin_comment
comment|// PR5253
end_comment

begin_comment
comment|// GNU Extension: check that we can redefine an extern inline function
end_comment

begin_function
specifier|extern
specifier|inline
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|f
parameter_list|(
name|int
name|b
parameter_list|)
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_comment
comment|// And now check that we can't redefine a normal function
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|c
return|;
block|}
end_function

begin_comment
comment|// expected-error{{redefinition of 'f'}}
end_comment

begin_comment
comment|// Check that we can redefine an extern inline function as a static function
end_comment

begin_function
specifier|extern
specifier|inline
name|int
name|g
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|g
parameter_list|(
name|int
name|b
parameter_list|)
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// Check that we ensure the types of the two definitions are the same
end_comment

begin_function
specifier|extern
specifier|inline
name|int
name|h
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_function
name|int
name|h
parameter_list|(
name|short
name|b
parameter_list|)
block|{
return|return
name|b
return|;
block|}
end_function

begin_comment
comment|// expected-error{{conflicting types for 'h'}}
end_comment

end_unit

